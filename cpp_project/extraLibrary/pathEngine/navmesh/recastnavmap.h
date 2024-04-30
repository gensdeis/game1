#pragma once

#ifndef _SERVER_VERSION
#include "Recast/ShareRecast.h"
#include "Detour/ShareDetourNavMesh.h"
#include "Detour/ShareDetourNavMeshQuery.h"
#else
#include "Recast/ShareRecast.h"
#include "Detour/ShareDetourNavMesh.h"
#include "Detour/ShareDetourNavMeshQuery.h"
#endif

#ifndef INVALID_NAVNODEREF
#define INVALID_NAVNODEREF (0)
#endif

#define RECAST_MAX_SEARCH_NODES		2048				// engine default value RecastNavMesh.h
#define RECAST_STRAIGHTPATH_OFFMESH_CONNECTION 0x04		// engine default value NavMeshPath.h
#define RECAST_DEFAULT_HEURISTIC_SCALE 0.999f			// engine default DetourNavMeshQuery.cpp

// NavigationTypes.h
#define DEFAULT_NAV_QUERY_EXTENT_HORIZONTAL 50.f
#define DEFAULT_NAV_QUERY_EXTENT_VERTICAL 250.f

#ifndef SHARED_FLT_MAX
#define SHARED_FLT_MAX          3.402823466e+38F        // max value
#endif

namespace CSCommon
{
	class FRecastNavMap;
#if defined(__LP64__)
// LP64 (Linux/OS X): UE4 will define its uint64 type as "unsigned long long" so we need to match this
	typedef unsigned long long NavNodeRef;
#else
	typedef uint64_t NavNodeRef;
#endif

	// default value from FNavDataConfig, NavigationTypes.cpp
	const float DefaultQueryExtent[3] = { DEFAULT_NAV_QUERY_EXTENT_HORIZONTAL, DEFAULT_NAV_QUERY_EXTENT_HORIZONTAL, DEFAULT_NAV_QUERY_EXTENT_VERTICAL };
	static const float InvalidLocation[3] = { SHARED_FLT_MAX, SHARED_FLT_MAX, SHARED_FLT_MAX };

	// NavigationTypes.cpp
	// these are totally arbitrary values, and it should haven happen these are ever used.
	// in any reasonable case UNavigationSystemV1::SupportedAgents should be filled in ini file
	// and only those values will be used
	const float FallbackAgentRadius = 35.f;
	const float FallbackAgentHeight = 144.f;

	// filter flags
	const uint8_t FILTER_FLAGS_NONE = 0x00;
	const uint8_t FILTER_FLAGS_WALK = 0x01;
	const uint8_t FILTER_FLAGS_BLOCK = 0x10;

	// from UE4 (partial)
	struct FNavLocation
	{
		/** location relative to path's base */
		float Location[3];

		/** node reference in navigation data */
		NavNodeRef NodeRef;

		FNavLocation() : Location{ 0.0f, 0.0f, 0.0f }, NodeRef(INVALID_NAVNODEREF) {}
		explicit FNavLocation(const float *InLocation, NavNodeRef InNodeRef = INVALID_NAVNODEREF)
			: Location{ InLocation[0], InLocation[1], InLocation[2] }, NodeRef(InNodeRef) {}

		/** checks if location has associated navigation node ref */
		inline bool HasNodeRef() const { return NodeRef != INVALID_NAVNODEREF; }
	};

	/** Describes node in navigation path */
	struct FNavPathPoint : public FNavLocation
	{
		/** extra node flags */
		uint32_t Flags;

		/** unique Id of custom navigation link starting at this point */
		uint32_t CustomLinkId;

		FNavPathPoint() : Flags(0), CustomLinkId(0) {}
		FNavPathPoint(const float *InLocation, NavNodeRef InNodeRef = INVALID_NAVNODEREF, uint32_t InFlags = 0)
			: FNavLocation(InLocation, InNodeRef), Flags(InFlags), CustomLinkId(0) {}
	};

	/** Helper to translate FNavPathPoint.Flags. */
	struct FNavMeshNodeFlags
	{
		/** Extra node information (like "path start", "off-mesh connection"). */
		uint8_t PathFlags;
		/** Area type after this node. */
		uint8_t Area;
		/** Area flags for this node. */
		uint16_t AreaFlags;

		FNavMeshNodeFlags() : PathFlags(0), Area(0), AreaFlags(0) {}
		FNavMeshNodeFlags(uint32_t Flags) : PathFlags(Flags), Area(Flags >> 8), AreaFlags(Flags >> 16) {}
		uint32_t Pack() const { return PathFlags | ((uint32_t)Area << 8) | ((uint32_t)AreaFlags << 16); }
		bool IsNavLink() const { return (PathFlags & RECAST_STRAIGHTPATH_OFFMESH_CONNECTION) != 0; }

		FNavMeshNodeFlags& AddAreaFlags(const uint16_t InAreaFlags)
		{
			AreaFlags = (AreaFlags | InAreaFlags);
			return *this;
		}
	};

	// from UE4 (partial)
	struct FNavMeshPath
	{
		FNavMeshPath();

		void SetWantsStringPulling(const bool bNewWantsStringPulling) { bWantsStringPulling = bNewWantsStringPulling; }
		bool WantsStringPulling() const { return bWantsStringPulling; }
		bool IsStringPulled() const { return bStringPulled; }

		/** find string pulled path from PathCorridor */
		void PerformStringPulling(FRecastNavMap *Owner, const float *StartLoc, const float *EndLoc);

		void SetWantsPathCorridor(const bool bNewWantsPathCorridor) { bWantsPathCorridor = bNewWantsPathCorridor; }
		bool WantsPathCorridor() const { return bWantsPathCorridor; }

		void OnPathCorridorUpdated() { bCorridorEdgesGenerated = false; }

		void ResetForRepath();

	private:
		void InternalResetNavMeshPath();

	public:
		std::vector<NavNodeRef>		PathCorridor;
		std::vector<float>			PathCorridorCost;
		std::vector<FNavPathPoint>	PathPoints;
		std::vector<uint32_t>		CustomLinkIds;

	private:
		/** sequence of FVector pairs where each pair represents navmesh portal edge between two polygons navigation corridor.
		*	Note, that it should always be accessed via GetPathCorridorEdges() since PathCorridorEdges content is generated
		*	on first access */
		//mutable TArray<FNavigationPortalEdge> PathCorridorEdges;

		/** transient variable indicating whether PathCorridorEdges contains up to date information */
		mutable uint32_t bCorridorEdgesGenerated : 1;

	protected:
		/** does this path contain string pulled path? If true then NumPathVerts > 0 and
		*	OutPathVerts contains valid data. If false there's only navigation corridor data
		*	available.*/
		uint32_t bStringPulled : 1;

		/** If set to true path instance will contain a string pulled version. Otherwise only
		*	navigation corridor will be available. Defaults to true */
		uint32_t bWantsStringPulling : 1;

		/** If set to true path instance will contain path corridor generated as a part
		*	pathfinding call (i.e. without the need to generate it with GeneratePathCorridorEdges */
		uint32_t bWantsPathCorridor : 1;
	};

	// from UE4 (partial) - 4.20+
	struct FNavigationPath
	{
		std::vector<FNavPathPoint>	PathPoints;

		const float* GetStartLocation()
		{
			return PathPoints.size() > 0 ? (PathPoints[0].Location + 0) : (InvalidLocation + 0 );
		}
		const float* GetEndLocation()
		{
			return PathPoints.size() > 0 ? (PathPoints.end()->Location + 0) : (InvalidLocation + 0);
		}

		std::vector<FNavPathPoint>& GetPathPoints()
		{
			return PathPoints;
		}
	};

	///** Helper to translate FNavPathPoint.Flags. */
	//struct FNavMeshNodeFlags
	//{
	//	/** Extra node information (like "path start", "off-mesh connection"). */
	//	unsigned char PathFlags;
	//	/** Area type after this node. */
	//	unsigned char Area;
	//	/** Area flags for this node. */
	//	uint16 AreaFlags;

	//	FNavMeshNodeFlags() : PathFlags(0), Area(0), AreaFlags(0) {}
	//	FNavMeshNodeFlags(uint32 Flags) : PathFlags(Flags), Area(Flags >> 8), AreaFlags(Flags >> 16) {}
	//	uint32 Pack() const { return PathFlags | ((uint32)Area << 8) | ((uint32)AreaFlags << 16); }
	//	bool IsNavLink() const { return (PathFlags & RECAST_STRAIGHTPATH_OFFMESH_CONNECTION) != 0; }

	//	FNavMeshNodeFlags& AddAreaFlags(const uint16 InAreaFlags)
	//	{
	//		AreaFlags = (AreaFlags | InAreaFlags);
	//		return *this;
	//	}
	//};

	// recast navigation for each map
	class FRecastNavMap
	{
	public:
		FRecastNavMap();
		virtual ~FRecastNavMap();

	private:
		// initialize
		dtNavMesh* createNavMesh(const char* path);

	public:
		// file handling
		bool	Load(const char* path);
		bool	Save(const char* path);

	public:
		// requested functions (server)

		// Extent Usuage { X, Y, Z } (Unreal Coordination)
		// nullptr will use default value

		// find path uses DefaultQueryExtent
		bool FindPath(const float *StartLoc, const float *EndLoc, FNavMeshPath &Path, const dtQueryFilter* QueryFilter = nullptr);
		bool FindPath(const float *StartLoc, const float *EndLoc, FNavMeshPath &Path, bool &bValidStartPosition, bool &bValidEndPosition, const dtQueryFilter* QueryFilter = nullptr);
		bool FindNearestPoint(const float *pos, float *outVector, const float *Extent = nullptr, const dtQueryFilter* QueryFilter = nullptr);
		bool GetRandomPointAroundCircle(const float *pos, float Radius, float *outVector, const float *Extent = nullptr, const dtQueryFilter* QueryFilter = nullptr);
		bool FindDestLine(const float* src, const float* dst, float* outResultDest, const float *Extent = nullptr, const dtQueryFilter* QueryFilter = nullptr);
		bool FindHeights(const float *Point, std::vector<FNavLocation>& Result, const float *Extent = nullptr, float MinZ = -1000, float MaxZ = 1000000, const dtQueryFilter* QueryFilter = nullptr);
		void GetBoundingBox(float *min, float *max);

		dtQueryFilter* GetAsDetourQueryFilter();

	protected:
		// internal navigation related
		void RecreateDefaultFilter();

		bool InitPathfinding(const float *UnrealStart, const float *UnrealEnd,
			const dtNavMeshQuery& Query, const dtQueryFilter* Filter,
			float *RecastStart, NavNodeRef& StartPoly, bool& bValidStartPosition,
			float *RecastEnd, NavNodeRef& EndPoly, bool& bValidEndPosition) const;

		float CalcSegmentCostOnPoly(NavNodeRef PolyID, const dtQueryFilter* Filter, const float *StartLoc, const float *EndLoc) const;

		void PostProcessPath(dtStatus FindPathStatus, FNavMeshPath& Path,
			const dtNavMeshQuery& NavQuery, const dtQueryFilter* Filter,
			NavNodeRef StartPolyID, NavNodeRef EndPolyID,
			const float *StartLoc, const float *EndLoc,
			float *RecastStartPos, float *RecastEndPos,
			dtQueryResult& PathResult) const;

	public:
		bool FindStraightPath(const float *StartLoc, const float *EndLoc,
			const std::vector<NavNodeRef>& PathCorridor, std::vector<FNavPathPoint>& PathPoints,
			std::vector<uint32_t>* CustomLinks);

	public:
		// experimental
		void SetDetourNavMesh(dtNavMesh* DetourNavMesh);

	private:
		dtNavMesh*		DetourNavMesh;
		dtNavMeshQuery	SharedNavQuery;
		dtQuerySpecialLinkFilter LinkFilter;		// how to use this ?
		dtQueryFilter	DefaultFilter;

		// important! recast coordination
		float RecastBBoxMin[3];
		float RecastBBoxMax[3];

		// unreal coordination
		float UnrealBBoxMin[3];
		float UnrealBBoxMax[3];
			
		// experimental
		bool IsOuterDetourNavMesh;
	};
}
