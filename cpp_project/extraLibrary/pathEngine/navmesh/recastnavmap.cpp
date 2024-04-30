#include "stdafx.h"
#ifndef _SERVER_VERSION
#include "recastnavmap.h"
#include "Detour/ShareDetourCommon.h"
#include "Detour/ShareDetourNavMesh.h"	
#else
#include "recastnavmap.h"
#include "Detour/ShareDetourCommon.h"
#include "Detour/ShareDetourNavMesh.h"
#endif

#define SHARE_BIT_CHECK(x, b)		(((x) & (b))? true : false)
#define SHARE_BIT_ADD(x,b)			((x) = ((x) | (b)))	
#define SHARE_BIT_REMOVE(x,b)		((x) = ((x) & ~(b)))

#define RECAST_MAX_AREAS			64
#define RECAST_DEFAULT_AREA			(RECAST_MAX_AREAS - 1)
#define RECAST_LOW_AREA				(RECAST_MAX_AREAS - 2)
#define RECAST_NULL_AREA			0
#define UNREAL_OBSTACLE_AREA		1

#define RECAST_UNWALKABLE_POLY_COST	SHARED_FLT_MAX

namespace CSCommon
{
	const int NAVMESHSET_MAGIC = 'N' << 24 | 'A' << 16 | 'V' << 8 | 'M'; //'NAVM';
	const int NAVMESHSET_VERSION = 1;
	const int MAX_AGENTS = 300;
	const int MAX_AGENT_RADIUS = 60;

	void UnrealToRecast(float* in, float* out)
	{
		out[0] = -in[0];
		out[1] = in[2];
		out[2] = -in[1];
	}

	void UnrealToRecast(const float* in, float* out)
	{
		out[0] = -in[0];
		out[1] = in[2];
		out[2] = -in[1];
	}

	void UnrealToRecastABS(float* in, float* out)
	{
		UnrealToRecast(in, out);
		out[0] = fabs(out[0]);
		out[1] = fabs(out[1]);
		out[2] = fabs(out[2]);
	}

	void UnrealToRecastABS(const float* in, float* out)
	{
		UnrealToRecast(in, out);
		out[0] = fabs(out[0]);
		out[1] = fabs(out[1]);
		out[2] = fabs(out[2]);
	}

	void RecastToUnreal(float* in, float* out)
	{
		out[0] = -in[0];
		out[1] = -in[2];
		out[2] = in[1];
	}

	void RecastToUnreal(const float* in, float* out)
	{
		out[0] = -in[0];
		out[1] = -in[2];
		out[2] = in[1];
	}

	static float frand()
	{
		return (float)rand() / (float)RAND_MAX;
	}

	struct NavMeshSetHeader
	{
		int magic;
		int version;
		int numTiles;
		dtNavMeshParams params;
	};

	struct NavMeshTileHeader
	{
		dtTileRef tileRef;
		int dataSize;
	};

	FNavMeshPath::FNavMeshPath()
		: bWantsStringPulling(true)
		, bWantsPathCorridor(false)
	{
		InternalResetNavMeshPath();
	}

	void FNavMeshPath::ResetForRepath()
	{
		InternalResetNavMeshPath();
	}

	void FNavMeshPath::InternalResetNavMeshPath()
	{
		PathCorridor.clear();
		PathCorridorCost.clear();
		PathPoints.clear();
		CustomLinkIds.clear();

		bCorridorEdgesGenerated = false;
		bStringPulled = 1;
	
		// keep:
		// - bWantsStringPulling
		// - bWantsPathCorridor	
	}

	void FNavMeshPath::PerformStringPulling(FRecastNavMap *MyOwner, const float *StartLoc, const float *EndLoc)
	{
		if (PathCorridor.size())
		{
			bStringPulled = MyOwner->FindStraightPath(StartLoc, EndLoc, PathCorridor, PathPoints, &CustomLinkIds);
		}
	}

	FRecastNavMap::FRecastNavMap() :
		DetourNavMesh(0), IsOuterDetourNavMesh(false)
	{
		RecreateDefaultFilter();
	}

	FRecastNavMap::~FRecastNavMap()
	{
		if (!IsOuterDetourNavMesh)
		{
			dtFreeNavMesh(DetourNavMesh);
		}
		DetourNavMesh = nullptr;
	}

	// -------------------------------------------------------------------------------------------------------------------------------------------
	// Initialize Handling Codes
	// -------------------------------------------------------------------------------------------------------------------------------------------

	dtNavMesh* FRecastNavMap::createNavMesh(const char* path)
	{
#ifdef _MSC_VER
		FILE* fp = nullptr;
		if (fopen_s(&fp, path, "rb") != 0)
			fp = nullptr;
#else
		FILE* fp = fopen(path, "rb");
#endif
		if (!fp) return 0;

		// Read header.
		NavMeshSetHeader header;
		fread(&header, sizeof(NavMeshSetHeader), 1, fp);
		if (header.magic != NAVMESHSET_MAGIC)
		{
			fclose(fp);
			return 0;
		}
		if (header.version != NAVMESHSET_VERSION)
		{
			fclose(fp);
			return 0;
		}

		dtNavMesh* mesh = dtAllocNavMesh();
		if (!mesh)
		{
			fclose(fp);
			return 0;
		}
		dtStatus status = mesh->init(&header.params);
		if (dtStatusFailed(status))
		{
			fclose(fp);
			return 0;
		}

		// Read tiles.
		for (int i = 0; i < header.numTiles; ++i)
		{
			NavMeshTileHeader tileHeader;
			fread(&tileHeader, sizeof(tileHeader), 1, fp);
			if (!tileHeader.tileRef || !tileHeader.dataSize)
				break;

			unsigned char* data = (unsigned char*)dtAlloc(tileHeader.dataSize, DT_ALLOC_PERM);
			if (!data) break;
			memset(data, 0, tileHeader.dataSize);
			fread(data, tileHeader.dataSize, 1, fp);

			mesh->addTile(data, tileHeader.dataSize, DT_TILE_FREE_DATA, tileHeader.tileRef, 0);
		}

		// read bounding box
		fread(RecastBBoxMin, sizeof(float), 3, fp);
		fread(RecastBBoxMax, sizeof(float), 3, fp);
		fread(UnrealBBoxMin, sizeof(float), 3, fp);
		fread(UnrealBBoxMax, sizeof(float), 3, fp);

		fclose(fp);

		return mesh;
	}

	bool FRecastNavMap::Load(const char* path)
	{
		if (DetourNavMesh && !IsOuterDetourNavMesh)
		{
			dtFreeNavMesh(DetourNavMesh);
		}

		DetourNavMesh = nullptr;

		DetourNavMesh = createNavMesh(path);
		if (DetourNavMesh == nullptr)
		{
			return false;
		}

		IsOuterDetourNavMesh = false;

		// get link filter
		//FRecastSpeciaLinkFilter LinkFilter(FNavigationSystem::GetCurrent<UNavigationSystemV1>(NavMeshOwner->GetWorld()), Owner);
		// create shared nav mesh query
		SharedNavQuery.init(DetourNavMesh, RECAST_MAX_SEARCH_NODES, &LinkFilter);

		return true;
	}

	bool FRecastNavMap::Save(const char* path)
	{
		const CSCommon::dtNavMesh* mesh = DetourNavMesh;
		if (mesh == NULL)
		{
			return false;
		}

#ifdef _MSC_VER
		FILE* fp = NULL;
		if (fopen_s(&fp, path, "wb") != 0)
			fp = NULL;
#else
		FILE* fp = fopen(path, "wb");
#endif
		if (!fp)
		{
			return false;
		}

		// Store header.
		NavMeshSetHeader header;
		header.magic = NAVMESHSET_MAGIC;
		header.version = NAVMESHSET_VERSION;
		header.numTiles = 0;
		for (int i = 0; i < mesh->getMaxTiles(); ++i)
		{
			const dtMeshTile* tile = mesh->getTile(i);
			if (!tile || !tile->header || !tile->dataSize)
			{
				continue;
			}
			header.numTiles++;
		}
		memcpy(&header.params, mesh->getParams(), sizeof(dtNavMeshParams));
		fwrite(&header, sizeof(NavMeshSetHeader), 1, fp);

		// boundingbox 2018/05/16
		float min[3];
		float max[3];
		bool init = false;

		float unrealmin[3];
		float unrealmax[3];
		bool unrealinit = false;

		// Store tiles.
		for (int i = 0; i < mesh->getMaxTiles(); ++i)
		{
			const dtMeshTile* tile = mesh->getTile(i);
			if (!tile || !tile->header || !tile->dataSize)
			{
				continue;
			}

			// find min/max bbox
			{
				for (int v = 0; v < tile->header->vertCount; v++)
				{
					float* vert = (tile->verts + v * 3);

					if (!init)
					{
						memcpy(min, vert, sizeof(float) * 3);
						memcpy(max, vert, sizeof(float) * 3);
						init = true;
					}
					else
					{
						// min x
						if (min[0] > vert[0])
						{
							min[0] = vert[0];
						}
						// min y
						if (min[1] > vert[1])
						{
							min[1] = vert[1];
						}
						// min z
						if (min[2] > vert[2])
						{
							min[2] = vert[2];
						}

						// max x
						if (max[0] < vert[0])
						{
							max[0] = vert[0];
						}
						// max y
						if (max[1] < vert[1])
						{
							max[1] = vert[1];
						}
						// max z
						if (max[2] < vert[2])
						{
							max[2] = vert[2];
						}
					}
				}
			}

			{
				for (int v = 0; v < tile->header->vertCount; v++)
				{
					float* orivert = (tile->verts + v * 3);
					float vert[3];
					RecastToUnreal(orivert, vert);

					if (!unrealinit)
					{
						memcpy(unrealmin, vert, sizeof(float) * 3);
						memcpy(unrealmax, vert, sizeof(float) * 3);
						unrealinit = true;
					}
					else
					{
						// min x
						if (unrealmin[0] > vert[0])
						{
							unrealmin[0] = vert[0];
						}
						// min y
						if (unrealmin[1] > vert[1])
						{
							unrealmin[1] = vert[1];
						}
						// min z
						if (unrealmin[2] > vert[2])
						{
							unrealmin[2] = vert[2];
						}

						// max x
						if (unrealmax[0] < vert[0])
						{
							unrealmax[0] = vert[0];
						}
						// max y
						if (unrealmax[1] < vert[1])
						{
							unrealmax[1] = vert[1];
						}
						// max z
						if (unrealmax[2] < vert[2])
						{
							unrealmax[2] = vert[2];
						}
					}
				}
			}

			NavMeshTileHeader tileHeader;
			tileHeader.tileRef = mesh->getTileRef(tile);
			tileHeader.dataSize = tile->dataSize;
			fwrite(&tileHeader, sizeof(tileHeader), 1, fp);

			// write tile data
			fwrite(tile->data, tile->dataSize, 1, fp);
		}

		fwrite(min, sizeof(float), 3, fp);
		fwrite(max, sizeof(float), 3, fp);

		// write bounding box - this uses unreal cooridinates system
		fwrite(unrealmin, sizeof(float), 3, fp);
		fwrite(unrealmax, sizeof(float), 3, fp);

		fclose(fp);
		return true;
	}

	// -------------------------------------------------------------------------------------------------------------------------------------------
	// Requested Functions (server)
	// -------------------------------------------------------------------------------------------------------------------------------------------

	bool FRecastNavMap::FindPath(const float *StartLoc, const float *EndLoc, FNavMeshPath &Path, const dtQueryFilter* QueryFilter)
	{
		if (DetourNavMesh == nullptr)
		{
			return false;
		}

		// AIBlueprintHelperLibrary.cpp
		//const ANavigationData* NavData = NavSys->GetNavDataForProps(Controller->GetNavAgentPropertiesRef());
		//if (NavData)
		//{
		//	FPathFindingQuery Query(Controller, *NavData, Controller->GetNavAgentLocation(), GoalLocation);
		//	FPathFindingResult Result = NavSys->FindPathSync(Query);
		//	if (Result.IsSuccessful())
		//	{
		//		PFollowComp->RequestMove(FAIMoveRequest(GoalLocation), Result.Path);
		//	}
		//	else if (PFollowComp->GetStatus() != EPathFollowingStatus::Idle)
		//	{
		//		PFollowComp->RequestMoveWithImmediateFinish(EPathFollowingResult::Invalid);
		//	}
		//}

		// PImplRecastNavMesh.cpp
		// ENavigationQueryResult::Type FPImplRecastNavMesh::FindPath(const FVector& StartLoc, const FVector& EndLoc, FNavMeshPath& Path, const FNavigationQueryFilter& InQueryFilter, const UObject* Owner) const

		// 4.20 code
		//const FRecastQueryFilter* FilterImplementation = (const FRecastQueryFilter*)(InQueryFilter.GetImplementation());
		//if (FilterImplementation == NULL)
		//{
		//	UE_VLOG(NavMeshOwner, LogNavigation, Error, TEXT("FPImplRecastNavMesh::FindPath failed due to passed filter having NULL implementation!"));
		//	return ENavigationQueryResult::Error;
		//}

		//const dtQueryFilter* QueryFilter = FilterImplementation->GetAsDetourQueryFilter();
		//if (QueryFilter == NULL)
		//{
		//	UE_VLOG(NavMeshOwner, LogNavigation, Warning, TEXT("FPImplRecastNavMesh::FindPath failing due to QueryFilter == NULL"));
		//	return ENavigationQueryResult::Error;
		//}
		const dtQueryFilter* QFilter = QueryFilter;
		if (QFilter == nullptr)
		{
			QFilter = GetAsDetourQueryFilter();
		}

		//FRecastSpeciaLinkFilter LinkFilter(FNavigationSystem::GetCurrent<UNavigationSystemV1>(NavMeshOwner->GetWorld()), Owner);

		//INITIALIZE_NAVQUERY(NavQuery, InQueryFilter.GetMaxSearchNodes(), LinkFilter);
		const dtNavMeshQuery &NavQuery = SharedNavQuery;
		//dtNavMeshQuery NavQuery;
		//NavQuery.init(DetourNavMesh, RECAST_MAX_SEARCH_NODES, &LinkFilter);

		float RecastStartPos[3], RecastEndPos[3];
		NavNodeRef StartPolyID, EndPolyID;

		bool bValidStartPosition, bValidEndPosition;

		const bool bCanSearch = InitPathfinding(StartLoc, EndLoc, NavQuery, QFilter, RecastStartPos, StartPolyID, bValidStartPosition, RecastEndPos, EndPolyID, bValidEndPosition);
		if (!bCanSearch)
		{
			//return ENavigationQueryResult::Error;
			return false;
		}

		// get path corridor
		dtQueryResult PathResult;
		const dtStatus FindPathStatus = NavQuery.findPath(StartPolyID, EndPolyID, RecastStartPos, RecastEndPos, QFilter, PathResult, 0);

		// check for special case, where path has not been found, and starting polygon
		// was the one closest to the target
		if (PathResult.size() == 1 && dtStatusDetail(FindPathStatus, DT_PARTIAL_RESULT))
		{
			// in this case we find a point on starting polygon, that's closest to destination
			// and store it as path end
			float RecastHandPlacedPathEnd[3];
			NavQuery.closestPointOnPolyBoundary(StartPolyID, RecastEndPos, RecastHandPlacedPathEnd);

			//new(Path.GetPathPoints()) FNavPathPoint(Recast2UnrVector(&RecastStartPos.X), StartPolyID);
			//new(Path.GetPathPoints()) FNavPathPoint(Recast2UnrVector(&RecastHandPlacedPathEnd.X), StartPolyID);
			float startpos[3];
			RecastToUnreal(RecastStartPos, startpos);
			Path.PathPoints.push_back(FNavPathPoint(startpos, StartPolyID));

			float handplacedpathend[3];
			RecastToUnreal(RecastHandPlacedPathEnd, handplacedpathend);
			Path.PathPoints.push_back(FNavPathPoint(handplacedpathend, StartPolyID));

			//Path.PathCorridor.Add(PathResult.getRef(0));
			//Path.PathCorridorCost.Add(CalcSegmentCostOnPoly(StartPolyID, QFilter, RecastHandPlacedPathEnd, RecastStartPos));
			Path.PathCorridor.push_back(PathResult.getRef(0));
			Path.PathCorridorCost.push_back(CalcSegmentCostOnPoly(StartPolyID, QFilter, RecastHandPlacedPathEnd, RecastStartPos));
		}
		else
		{
			//PostProcessPath(FindPathStatus, Path, NavQuery, QueryFilter,
			//	StartPolyID, EndPolyID, Recast2UnrVector(&RecastStartPos.X), Recast2UnrVector(&RecastEndPos.X), RecastStartPos, RecastEndPos,
			//	PathResult);
			float startpos[3];
			RecastToUnreal(RecastStartPos, startpos);
			float endpos[3];
			RecastToUnreal(RecastEndPos, endpos);

			PostProcessPath(FindPathStatus, Path, NavQuery, QFilter,
				StartPolyID, EndPolyID, startpos, endpos, RecastStartPos, RecastEndPos,
				PathResult);
		}

		//if (dtStatusDetail(FindPathStatus, DT_PARTIAL_RESULT))
		//{
		//	Path.SetIsPartial(true);
		//	// this means path finding algorithm reached the limit of InQueryFilter.GetMaxSearchNodes()
		//	// nodes in A* node pool. This can mean resulting path is way off.
		//	Path.SetSearchReachedLimit(dtStatusDetail(FindPathStatus, DT_OUT_OF_NODES));
		//}

//#if ENABLE_VISUAL_LOG
//		if (dtStatusDetail(FindPathStatus, DT_INVALID_CYCLE_PATH))
//		{
//			UE_VLOG(NavMeshOwner, LogNavigation, Error, TEXT("FPImplRecastNavMesh::FindPath resulted in a cyclic path!"));
//			FVisualLogEntry* Entry = FVisualLogger::Get().GetLastEntryForObject(NavMeshOwner);
//			if (Entry)
//			{
//				Path.DescribeSelfToVisLog(Entry);
//			}
//		}
//#endif // ENABLE_VISUAL_LOG
//
//		Path.MarkReady();
//
//		return DTStatusToNavQueryResult(FindPathStatus);
		return dtStatusSucceed(FindPathStatus);
	}

	bool FRecastNavMap::FindPath(const float * StartLoc, const float * EndLoc, FNavMeshPath & Path, bool & bValidStartPosition, bool & bValidEndPosition, const dtQueryFilter * QueryFilter)
	{
		if (DetourNavMesh == nullptr)
		{
			return false;
		}

		// AIBlueprintHelperLibrary.cpp
		//const ANavigationData* NavData = NavSys->GetNavDataForProps(Controller->GetNavAgentPropertiesRef());
		//if (NavData)
		//{
		//	FPathFindingQuery Query(Controller, *NavData, Controller->GetNavAgentLocation(), GoalLocation);
		//	FPathFindingResult Result = NavSys->FindPathSync(Query);
		//	if (Result.IsSuccessful())
		//	{
		//		PFollowComp->RequestMove(FAIMoveRequest(GoalLocation), Result.Path);
		//	}
		//	else if (PFollowComp->GetStatus() != EPathFollowingStatus::Idle)
		//	{
		//		PFollowComp->RequestMoveWithImmediateFinish(EPathFollowingResult::Invalid);
		//	}
		//}

		// PImplRecastNavMesh.cpp
		// ENavigationQueryResult::Type FPImplRecastNavMesh::FindPath(const FVector& StartLoc, const FVector& EndLoc, FNavMeshPath& Path, const FNavigationQueryFilter& InQueryFilter, const UObject* Owner) const

		// 4.20 code
		//const FRecastQueryFilter* FilterImplementation = (const FRecastQueryFilter*)(InQueryFilter.GetImplementation());
		//if (FilterImplementation == NULL)
		//{
		//	UE_VLOG(NavMeshOwner, LogNavigation, Error, TEXT("FPImplRecastNavMesh::FindPath failed due to passed filter having NULL implementation!"));
		//	return ENavigationQueryResult::Error;
		//}

		//const dtQueryFilter* QueryFilter = FilterImplementation->GetAsDetourQueryFilter();
		//if (QueryFilter == NULL)
		//{
		//	UE_VLOG(NavMeshOwner, LogNavigation, Warning, TEXT("FPImplRecastNavMesh::FindPath failing due to QueryFilter == NULL"));
		//	return ENavigationQueryResult::Error;
		//}
		const dtQueryFilter* QFilter = QueryFilter;
		if (QFilter == nullptr)
		{
			QFilter = GetAsDetourQueryFilter();
		}

		//FRecastSpeciaLinkFilter LinkFilter(FNavigationSystem::GetCurrent<UNavigationSystemV1>(NavMeshOwner->GetWorld()), Owner);

		//INITIALIZE_NAVQUERY(NavQuery, InQueryFilter.GetMaxSearchNodes(), LinkFilter);
		const dtNavMeshQuery &NavQuery = SharedNavQuery;
		//dtNavMeshQuery NavQuery;
		//NavQuery.init(DetourNavMesh, RECAST_MAX_SEARCH_NODES, &LinkFilter);

		float RecastStartPos[3], RecastEndPos[3];
		NavNodeRef StartPolyID, EndPolyID;

		const bool bCanSearch = InitPathfinding(StartLoc, EndLoc, NavQuery, QFilter, RecastStartPos, StartPolyID, bValidStartPosition, RecastEndPos, EndPolyID, bValidEndPosition);
		if (!bCanSearch)
		{
			//return ENavigationQueryResult::Error;
			return false;
		}

		// get path corridor
		dtQueryResult PathResult;
		const dtStatus FindPathStatus = NavQuery.findPath(StartPolyID, EndPolyID, RecastStartPos, RecastEndPos, QFilter, PathResult, 0);

		// check for special case, where path has not been found, and starting polygon
		// was the one closest to the target
		if (PathResult.size() == 1 && dtStatusDetail(FindPathStatus, DT_PARTIAL_RESULT))
		{
			// in this case we find a point on starting polygon, that's closest to destination
			// and store it as path end
			float RecastHandPlacedPathEnd[3];
			NavQuery.closestPointOnPolyBoundary(StartPolyID, RecastEndPos, RecastHandPlacedPathEnd);

			//new(Path.GetPathPoints()) FNavPathPoint(Recast2UnrVector(&RecastStartPos.X), StartPolyID);
			//new(Path.GetPathPoints()) FNavPathPoint(Recast2UnrVector(&RecastHandPlacedPathEnd.X), StartPolyID);
			float startpos[3];
			RecastToUnreal(RecastStartPos, startpos);
			Path.PathPoints.push_back(FNavPathPoint(startpos, StartPolyID));

			float handplacedpathend[3];
			RecastToUnreal(RecastHandPlacedPathEnd, handplacedpathend);
			Path.PathPoints.push_back(FNavPathPoint(handplacedpathend, StartPolyID));

			//Path.PathCorridor.Add(PathResult.getRef(0));
			//Path.PathCorridorCost.Add(CalcSegmentCostOnPoly(StartPolyID, QFilter, RecastHandPlacedPathEnd, RecastStartPos));
			Path.PathCorridor.push_back(PathResult.getRef(0));
			Path.PathCorridorCost.push_back(CalcSegmentCostOnPoly(StartPolyID, QFilter, RecastHandPlacedPathEnd, RecastStartPos));
		}
		else
		{
			//PostProcessPath(FindPathStatus, Path, NavQuery, QueryFilter,
			//	StartPolyID, EndPolyID, Recast2UnrVector(&RecastStartPos.X), Recast2UnrVector(&RecastEndPos.X), RecastStartPos, RecastEndPos,
			//	PathResult);
			float startpos[3];
			RecastToUnreal(RecastStartPos, startpos);
			float endpos[3];
			RecastToUnreal(RecastEndPos, endpos);

			PostProcessPath(FindPathStatus, Path, NavQuery, QFilter,
				StartPolyID, EndPolyID, startpos, endpos, RecastStartPos, RecastEndPos,
				PathResult);
		}

		//if (dtStatusDetail(FindPathStatus, DT_PARTIAL_RESULT))
		//{
		//	Path.SetIsPartial(true);
		//	// this means path finding algorithm reached the limit of InQueryFilter.GetMaxSearchNodes()
		//	// nodes in A* node pool. This can mean resulting path is way off.
		//	Path.SetSearchReachedLimit(dtStatusDetail(FindPathStatus, DT_OUT_OF_NODES));
		//}

		//#if ENABLE_VISUAL_LOG
		//		if (dtStatusDetail(FindPathStatus, DT_INVALID_CYCLE_PATH))
		//		{
		//			UE_VLOG(NavMeshOwner, LogNavigation, Error, TEXT("FPImplRecastNavMesh::FindPath resulted in a cyclic path!"));
		//			FVisualLogEntry* Entry = FVisualLogger::Get().GetLastEntryForObject(NavMeshOwner);
		//			if (Entry)
		//			{
		//				Path.DescribeSelfToVisLog(Entry);
		//			}
		//		}
		//#endif // ENABLE_VISUAL_LOG
		//
		//		Path.MarkReady();
		//
		//		return DTStatusToNavQueryResult(FindPathStatus);
		return dtStatusSucceed(FindPathStatus);
	}

	bool FRecastNavMap::FindNearestPoint(const float *pos, float *outVector, const float *Extent, const dtQueryFilter* QueryFilter)
	{
		float recastpos[3];
		UnrealToRecast(pos, recastpos);

		const dtQueryFilter* QFilter = QueryFilter;
		if (QFilter == nullptr)
		{
			QFilter = GetAsDetourQueryFilter();
		}

		const float* Ext = Extent;
		if (Ext == nullptr)
		{
			Ext = DefaultQueryExtent;
		}
		float RcExtent[3];
		UnrealToRecastABS(Ext, RcExtent);

		float resultpos[3];
		NavNodeRef PolyID = INVALID_NAVNODEREF;
		SharedNavQuery.findNearestPoly(recastpos, RcExtent, QFilter, &PolyID, resultpos);
		if (PolyID == INVALID_NAVNODEREF)
		{
			return false;
		}

		RecastToUnreal(resultpos, outVector);

		return true;
	}

	bool FRecastNavMap::GetRandomPointAroundCircle(const float *pos, float Radius, float *outVector, const float *Extent, const dtQueryFilter* QueryFilter)
	{
		float recastpos[3];
		UnrealToRecast(pos, recastpos);

		const dtQueryFilter* QFilter = QueryFilter;
		if (QFilter == nullptr)
		{
			QFilter = GetAsDetourQueryFilter();
		}

		const float* Ext = Extent;
		if (Ext == nullptr)
		{
			Ext = DefaultQueryExtent;
		}
		float RcExtent[3];
		UnrealToRecastABS(Ext, RcExtent);

		float resultpos[3];
		NavNodeRef PolyID = INVALID_NAVNODEREF;
		SharedNavQuery.findNearestPoly(recastpos, RcExtent, GetAsDetourQueryFilter(), &PolyID, resultpos);
		if (PolyID == INVALID_NAVNODEREF)
		{
			return false;
		}

		NavNodeRef RandomPolyID = INVALID_NAVNODEREF;
		SharedNavQuery.findRandomPointAroundCircle(PolyID, recastpos, Radius, QFilter, frand, &RandomPolyID, resultpos);
		if (RandomPolyID == INVALID_NAVNODEREF)
		{
			return false;
		}

		RecastToUnreal(resultpos, outVector);

		return true;
	}

	bool FRecastNavMap::FindDestLine(const float* src, const float* dst, float* outResultDest, const float *Extent, const dtQueryFilter* QueryFilter)
	{
		const dtNavMeshQuery &NavQuery = SharedNavQuery;
		const dtQueryFilter* QFilter = QueryFilter;
		if (QFilter == nullptr)
		{
			QFilter = GetAsDetourQueryFilter();
		}

		const float* Ext = Extent;
		if (Ext == nullptr)
		{
			Ext = DefaultQueryExtent;
		}
		float RcExtent[3];
		UnrealToRecastABS(Ext, RcExtent);

		float RecastStart[3];
		UnrealToRecast(src, RecastStart);
		float RecastEnd[3];
		UnrealToRecast(dst, RecastEnd);

		dtPolyRef srcRef = 0;
		//dtPolyRef dstRef = 0;
		float startPos[3];//, endPos[3];

		dtStatus status = NavQuery.findNearestPoly(RecastStart, RcExtent, QFilter, &srcRef, startPos);
		if (dtStatusSucceed(status) == false)
		{
			// if it failed to get start pos then return start pos as result
			dtVcopy(outResultDest, src);
			return false;
		}

		float t = 0;	// normalized value, if has an error then value set to _MIRM_FLT_MAX.
		int npolys;
		const int MAX_POLYS = 256;
		dtPolyRef polys[MAX_POLYS];
		float hitNormal[3];
		status = NavQuery.raycast(srcRef, RecastStart, RecastEnd, QFilter, &t, hitNormal, polys, &npolys, MAX_POLYS);
		if (dtStatusSucceed(status) == false)
		{
			// if failed to do raycast then returns start pos as result
			dtVcopy(outResultDest, src);
			return false;
		}

		// succeeded but there are some exception. (such as source to dest line is totally vertical)
		if (t > 1)
		{
			// experimental.
			dtVcopy(outResultDest, dst);
		}
		else
		{
			// z value must recalculated by height. may inaccurate if result position is more up or down geometry than start or dest position
			outResultDest[0] = src[0] + (dst[0] - src[0]) * t;
			outResultDest[1] = src[1] + (dst[1] - src[1]) * t;
			outResultDest[2] = src[2] + (dst[2] - src[2]) * t;
		}

		return true;
	}

	//bool FPImplRecastNavMesh::ProjectPointMulti(const FVector& Point, TArray<FNavLocation>& Result, const FVector& Extent,
	//	float MinZ, float MaxZ, const FNavigationQueryFilter& Filter, const UObject* Owner) const
	bool FRecastNavMap::FindHeights(const float *Point, std::vector<FNavLocation>& Result, const float *Extent,
		float MinZ, float MaxZ, const dtQueryFilter* QueryFilter)
	{
		const dtNavMeshQuery &NavQuery = SharedNavQuery;
		const dtQueryFilter* QFilter = QueryFilter;
		if (QFilter == nullptr)
		{
			QFilter = GetAsDetourQueryFilter();
		}

		bool bSuccess = false;

		if (QFilter)
		{
			//const FVector ModifiedExtent = NavMeshOwner->GetModifiedQueryExtent(Extent);
			//const FVector AdjustedPoint(Point.X, Point.Y, (MaxZ + MinZ) * 0.5f);
			//const FVector AdjustedExtent(ModifiedExtent.X, ModifiedExtent.Y, (MaxZ - MinZ) * 0.5f);
			float AdjustedPoint[3];
			AdjustedPoint[0] = Point[0];
			AdjustedPoint[1] = Point[1];
			AdjustedPoint[2] = (MaxZ + MinZ) * 0.5f;

			float AdjustedExtent[3];
			if (Extent != nullptr)
			{
				memcpy(AdjustedExtent, Extent, sizeof(float) * 2);
			}
			else
			{
				memcpy(AdjustedExtent, DefaultQueryExtent, sizeof(float) * 2);
			}
			AdjustedExtent[2] = (MaxZ - MinZ) * 0.5f;

			//const FVector RcPoint = Unreal2RecastPoint(AdjustedPoint);
			//const FVector RcExtent = Unreal2RecastPoint(AdjustedExtent).GetAbs();
			float RcPoint[3];
			UnrealToRecast(AdjustedPoint, RcPoint);
			float RcExtent[3];
			UnrealToRecastABS(AdjustedExtent, RcExtent);

			const int32_t MaxHitPolys = 256;
			dtPolyRef HitPolys[MaxHitPolys];
			int32_t NumHitPolys = 0;

			dtStatus status = NavQuery.queryPolygons(RcPoint, RcExtent, QFilter, HitPolys, &NumHitPolys, MaxHitPolys);
			if (dtStatusSucceed(status))
			{
				for (int32_t i = 0; i < NumHitPolys; i++)
				{
					float ClosestPoint[3];

					// check exact point
					//status = NavQuery.projectedPointOnPoly(HitPolys[i], RcPoint, ClosestPoint);
					// check closest point
					status = NavQuery.closestPointOnPoly(HitPolys[i], RcPoint, ClosestPoint);
					if (dtStatusSucceed(status))
					{
						float ExactZ = 0.0f;
						status = NavQuery.getPolyHeight(HitPolys[i], ClosestPoint, &ExactZ);
						if (dtStatusSucceed(status))
						{
							float hitpoint[3];
							RecastToUnreal(ClosestPoint, hitpoint);
							FNavLocation HitLocation(hitpoint, HitPolys[i]);
							//HitLocation.Location.Z = ExactZ;
							HitLocation.Location[2] = ExactZ;

							//ensure((HitLocation.Location - AdjustedPoint).SizeSquared2D() < KINDA_SMALL_NUMBER);

							// check xy position check
							//if (HitLocation.Location[0] == Point[0] && HitLocation.Location[1] == Point[1])

							const float dx = AdjustedPoint[0] - HitLocation.Location[0];
							const float dz = AdjustedPoint[1] - HitLocation.Location[1];

							// #define KINDA_SMALL_NUMBER	(1.e-4f)
							if(dx*dx + dz*dz < (1.e-4f))
							{
								//Result.Add(HitLocation);
								Result.push_back(HitLocation);
								bSuccess = true;
							}
						}
					}
				}
			}
		}

		return bSuccess;
	}

	void FRecastNavMap::GetBoundingBox(float *min, float *max)
	{
		memcpy(min, UnrealBBoxMin, sizeof(float) * 3);
		memcpy(max, UnrealBBoxMax, sizeof(float) * 3);
	}

	// -------------------------------------------------------------------------------------------------------------------------------------------
	// Internal Navigation Related Functions
	// -------------------------------------------------------------------------------------------------------------------------------------------

	struct NavArea
	{
		int		AreaID;
		float	DefaultCost;
		float	FixedAreaEnteringCost;
	};

	const NavArea kDefaultNavArea[] =
	{
		{ RECAST_DEFAULT_AREA, 1.0f, 0.0f },						// NavArea_Default
		{ RECAST_LOW_AREA, RECAST_UNWALKABLE_POLY_COST, 0.0f },		// NavArea_LowHeight
		{ RECAST_NULL_AREA, RECAST_UNWALKABLE_POLY_COST, 0.0f },	// NavArea_Null
		{ UNREAL_OBSTACLE_AREA, 1000000.0f, 0.0f },					// NavArea_Obstacle
	};

	void FRecastNavMap::RecreateDefaultFilter()
	{
		DefaultFilter.setExcludeFlags(FILTER_FLAGS_BLOCK);

		/** Euclidean distance heuristic scale used while pathfinding */
		//UPROPERTY(EditAnywhere, Category = Query, config, meta = (ClampMin = "0.1"))
		//float HeuristicScale;
		DefaultFilter.setHeuristicScale(RECAST_DEFAULT_HEURISTIC_SCALE);

		/** Indicates whether default navigation filters will use virtual functions. Defaults to true. */
		//UPROPERTY(config)
		//uint32 bUseVirtualFilters : 1;
		//DefaultFilter.setExcludeFlags(RECAST_NULL_AREA);
	
		// do we need this ?
		//for (int32 Idx = 0; Idx < SupportedAreas.Num(); Idx++)
		//{
		//	const FSupportedAreaData& AreaData = SupportedAreas[Idx];

		//	UNavArea* DefArea = nullptr;
		//	if (AreaData.AreaClass)
		//	{
		//		DefArea = ((UClass*)AreaData.AreaClass)->GetDefaultObject<UNavArea>();
		//	}

		//	if (DefArea)
		//	{
		//		DetourFilter->SetAreaCost(AreaData.AreaID, DefArea->DefaultCost);
		//		DetourFilter->SetFixedAreaEnteringCost(AreaData.AreaID, DefArea->GetFixedAreaEnteringCost());
		//	}
		//}
		
		int size = sizeof(kDefaultNavArea) / sizeof(NavArea);
		for (int i = 0; i < size; i++)
		{
			DefaultFilter.setAreaCost(kDefaultNavArea[i].AreaID, kDefaultNavArea[i].DefaultCost);
			DefaultFilter.setAreaFixedCost(kDefaultNavArea[i].AreaID, kDefaultNavArea[i].FixedAreaEnteringCost);
		}
	}

	dtQueryFilter* FRecastNavMap::GetAsDetourQueryFilter()
	{
		return &DefaultFilter;
	}

	bool FRecastNavMap::InitPathfinding(const float *UnrealStart, const float *UnrealEnd,
		const dtNavMeshQuery& Query, const dtQueryFilter* Filter,
		float *RecastStart, NavNodeRef& StartPoly, bool& bValidStartPosition,
		float *RecastEnd, NavNodeRef& EndPoly, bool& bValidEndPosition) const
	{
		bValidStartPosition = false;
		bValidEndPosition = false;

		//const FVector NavExtent = NavMeshOwner->GetModifiedQueryExtent(NavMeshOwner->GetDefaultQueryExtent());
		//const float Extent[3] = { NavExtent.X, NavExtent.Z, NavExtent.Y };
		const float Extent[3] = { DefaultQueryExtent[0], DefaultQueryExtent[2], DefaultQueryExtent[1] };

		//const FVector RecastStartToProject = Unreal2RecastPoint(UnrealStart);
		//const FVector RecastEndToProject = Unreal2RecastPoint(UnrealEnd);

		float RecastStartToProject[3];
		UnrealToRecast(UnrealStart, RecastStartToProject);
		float RecastEndToProject[3];
		UnrealToRecast(UnrealEnd, RecastEndToProject);

		StartPoly = INVALID_NAVNODEREF;
		Query.findNearestPoly(RecastStartToProject, Extent, Filter, &StartPoly, RecastStart);
		if (StartPoly != INVALID_NAVNODEREF)
		{
			bValidStartPosition = true;
		}

		EndPoly = INVALID_NAVNODEREF;
		Query.findNearestPoly(RecastEndToProject, Extent, Filter, &EndPoly, RecastEnd);
		if (EndPoly != INVALID_NAVNODEREF)
		{
			bValidEndPosition = true;
		}

		if (bValidStartPosition == false || bValidEndPosition == false)
		{
			return false;
		}

		return true;
	}

	float FRecastNavMap::CalcSegmentCostOnPoly(NavNodeRef PolyID, const dtQueryFilter* Filter, const float *StartLoc, const float *EndLoc) const
	{
		uint8_t AreaID = RECAST_DEFAULT_AREA;
		DetourNavMesh->getPolyArea(PolyID, &AreaID);

		const float AreaTravelCost = Filter->getAreaCost(AreaID);
		//return AreaTravelCost * (EndLoc - StartLoc).Size();
		float X = EndLoc[0] - StartLoc[0];
		float Y = EndLoc[1] - StartLoc[1];
		float Z = EndLoc[2] - StartLoc[2];
		float size = sqrtf(X*X + Y*Y + Z*Z);
		return AreaTravelCost * size;
	}

	void FRecastNavMap::PostProcessPath(dtStatus FindPathStatus, FNavMeshPath& Path,
		const dtNavMeshQuery& NavQuery, const dtQueryFilter* Filter,
		NavNodeRef StartPolyID, NavNodeRef EndPolyID,
		const float *StartLoc, const float *EndLoc,
		float *RecastStartPos, float *RecastEndPos,
		dtQueryResult& PathResult) const
	{
		// note that for recast partial path is successful, while we treat it as failed, just marking it as partial
		if (dtStatusSucceed(FindPathStatus))
		{
			// check if navlink poly at end of path is allowed
			int32_t PathSize = PathResult.size();

			// check this logic
			//if ((PathSize > 1) && NavMeshOwner && !NavMeshOwner->bAllowNavLinkAsPathEnd)
			//{
			//	uint16_t PolyFlags = 0;
			//	DetourNavMesh->getPolyFlags(PathResult.getRef(PathSize - 1), &PolyFlags);

			//	if (PolyFlags & ARecastNavMesh::GetNavLinkFlag())
			//	{
			//		PathSize--;
			//	}
			//}

			//Path.PathCorridorCost.AddUninitialized(PathSize);

			if (PathSize == 1)
			{
				// failsafe cost for single poly corridor
				//Path.PathCorridorCost[0] = CalcSegmentCostOnPoly(StartPolyID, Filter, EndLoc, StartLoc);
				Path.PathCorridorCost.push_back(CalcSegmentCostOnPoly(StartPolyID, Filter, EndLoc, StartLoc));
			}
			else
			{
				for (int32_t i = 0; i < PathSize; i++)
				{
					//Path.PathCorridorCost[i] = PathResult.getCost(i);
					Path.PathCorridorCost.push_back(PathResult.getCost(i));
				}
			}

			// copy over corridor poly data
			//Path.PathCorridor.AddUninitialized(PathSize);
			//NavNodeRef* DestCorridorPoly = Path.PathCorridor.GetData();
			//for (int i = 0; i < PathSize; ++i, ++DestCorridorPoly)
			//{
			//	*DestCorridorPoly = PathResult.getRef(i);
			//}
			for (int i = 0; i < PathSize; i++)
			{
				Path.PathCorridor.push_back(PathResult.getRef(i));
			}

			Path.OnPathCorridorUpdated();

//#if STATS
//			if (dtStatusDetail(FindPathStatus, DT_OUT_OF_NODES))
//			{
//				INC_DWORD_STAT(STAT_Navigation_OutOfNodesPath);
//			}
//
//			if (dtStatusDetail(FindPathStatus, DT_PARTIAL_RESULT))
//			{
//				INC_DWORD_STAT(STAT_Navigation_PartialPath);
//			}
//#endif

			if (Path.WantsStringPulling())
			{
				//FVector UseEndLoc = EndLoc;
				float UseEndLoc[3] = { EndLoc[0], EndLoc[1], EndLoc[2] };

				// if path is partial (path corridor doesn't contain EndPolyID), find new RecastEndPos on last poly in corridor
				if (dtStatusDetail(FindPathStatus, DT_PARTIAL_RESULT))
				{
					//NavNodeRef LastPolyID = Path.PathCorridor.Last();
					
					// to prevent crash. temp exception handing code 2019.03.22
					if (Path.PathCorridor.size() > 0)
					{
						//NavNodeRef LastPolyID = *(Path.PathCorridor.end());		<- crash occured
						NavNodeRef LastPolyID = Path.PathCorridor[Path.PathCorridor.size()-1];
						float NewEndPoint[3];

						const dtStatus NewEndPointStatus = NavQuery.closestPointOnPoly(LastPolyID, RecastEndPos, NewEndPoint);
						if (dtStatusSucceed(NewEndPointStatus))
						{
							//UseEndLoc = Recast2UnrealPoint(NewEndPoint);
							RecastToUnreal(NewEndPoint, UseEndLoc);
						}
					}
				}

				//Path.PerformStringPulling(StartLoc, UseEndLoc);
				Path.PerformStringPulling((FRecastNavMap *)this, StartLoc, UseEndLoc);
			}
			else
			{
				// make sure at least beginning and end of path are added
				//new(Path.GetPathPoints()) FNavPathPoint(StartLoc, StartPolyID);
				//new(Path.GetPathPoints()) FNavPathPoint(EndLoc, EndPolyID);
				Path.PathPoints.push_back(FNavPathPoint(StartLoc, StartPolyID));
				Path.PathPoints.push_back(FNavPathPoint(EndLoc, EndPolyID));

				// collect all custom links Ids
				for (size_t Idx = 0; Idx < Path.PathCorridor.size(); Idx++)
				{
					const dtOffMeshConnection* OffMeshCon = DetourNavMesh->getOffMeshConnectionByRef(Path.PathCorridor[Idx]);
					if (OffMeshCon)
					{
						Path.CustomLinkIds.push_back(OffMeshCon->userId);
					}
				}
			}

			// TODO HERE
			// we don't need this logic. but should check it later.
			if (Path.WantsPathCorridor())
			{
				//TArray<FNavigationPortalEdge> PathCorridorEdges;
				//GetEdgesForPathCorridorImpl(&Path.PathCorridor, &PathCorridorEdges, NavQuery);
				//Path.SetPathCorridorEdges(PathCorridorEdges);
			}
		}
	}

	bool FRecastNavMap::FindStraightPath(const float *StartLoc, const float *EndLoc,
		const std::vector<NavNodeRef>& PathCorridor, std::vector<FNavPathPoint>& PathPoints,
		std::vector<uint32_t>* CustomLinks)
	{
		//INITIALIZE_NAVQUERY_SIMPLE(NavQuery, RECAST_MAX_SEARCH_NODES);
		const dtNavMeshQuery &NavQuery = SharedNavQuery;
		//dtNavMeshQuery NavQuery;
		//NavQuery.init(DetourNavMesh, RECAST_MAX_SEARCH_NODES, &LinkFilter);

		//const FVector RecastStartPos = Unreal2RecastPoint(StartLoc);
		//const FVector RecastEndPos = Unreal2RecastPoint(EndLoc);
		float RecastStartPos[3];
		UnrealToRecast(StartLoc, RecastStartPos);
		float RecastEndPos[3];
		UnrealToRecast(EndLoc, RecastEndPos);
		bool bResult = false;

		dtQueryResult StringPullResult;
		const dtStatus StringPullStatus = NavQuery.findStraightPath(RecastStartPos, RecastEndPos,
			PathCorridor, (const int)(PathCorridor.size()), StringPullResult, DT_STRAIGHTPATH_AREA_CROSSINGS);

		//PathPoints.Reset();
		PathPoints.clear();
		if (dtStatusSucceed(StringPullStatus))
		{
			//PathPoints.AddZeroed(StringPullResult.size());

			// convert to desired format
			//FNavPathPoint* CurVert = PathPoints.GetData();

			for (int32_t VertIdx = 0; VertIdx < StringPullResult.size(); ++VertIdx)
			{
				FNavPathPoint CurVert;

				const float* CurRecastVert = StringPullResult.getPos(VertIdx);
				//CurVert->Location = Recast2UnrVector(CurRecastVert);
				RecastToUnreal(CurRecastVert, CurVert.Location);
				CurVert.NodeRef = StringPullResult.getRef(VertIdx);

				FNavMeshNodeFlags CurNodeFlags(0);
				CurNodeFlags.PathFlags = StringPullResult.getFlag(VertIdx);

				uint8_t AreaID = RECAST_DEFAULT_AREA;
				DetourNavMesh->getPolyArea(CurVert.NodeRef, &AreaID);
				CurNodeFlags.Area = AreaID;

				//const UClass* AreaClass = NavMeshOwner->GetAreaClass(AreaID);
				//const UNavArea* DefArea = AreaClass ? ((UClass*)AreaClass)->GetDefaultObject<UNavArea>() : NULL;
				//CurNodeFlags.AreaFlags = DefArea ? DefArea->GetAreaFlags() : 0;
				CurNodeFlags.AreaFlags = 1;	// default value ? (by debugging result)

				CurVert.Flags = CurNodeFlags.Pack();

				// include smart link data
				// if there will be more "edge types" we change this implementation to something more generic
				if (CustomLinks && (CurNodeFlags.PathFlags & DT_STRAIGHTPATH_OFFMESH_CONNECTION))
				{
					const dtOffMeshConnection* OffMeshCon = DetourNavMesh->getOffMeshConnectionByRef(CurVert.NodeRef);
					if (OffMeshCon)
					{
						CurVert.CustomLinkId = OffMeshCon->userId;
						CustomLinks->push_back(OffMeshCon->userId);
					}
				}

				//CurVert++;
				PathPoints.push_back(CurVert);
			}

			// findStraightPath returns 0 for polyId of last point for some reason, even though it knows the poly id.  We will fill that in correctly with the last poly id of the corridor.
			// @TODO shouldn't it be the same as EndPolyID? (nope, it could be partial path)
			//PathPoints.Last().NodeRef = PathCorridor.Last();
			//PathPoints.end()->NodeRef = *(PathCorridor.end());
			if (PathPoints.size() > 0 && PathCorridor.size() > 0)
			{
				PathPoints[PathPoints.size() - 1].NodeRef = PathCorridor[PathCorridor.size() - 1];
			}
			bResult = true;
		}

		return bResult;
	}

	void FRecastNavMap::SetDetourNavMesh(dtNavMesh* DetourNavMesh)
	{
		this->DetourNavMesh = DetourNavMesh;
		IsOuterDetourNavMesh = true;
	}
}
