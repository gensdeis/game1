#include "stdafx.h"
#include "AStarMap.h"

namespace CSCommon
{
	void FAStarMap::DestroyRegion()
	{
		if (Region_ != nullptr)
		{
			for (int i = 0; i < TotalRegionCountX_*TotalRegionCountY_; i++)
			{
				if (Region_[i].PathFlagIndex != nullptr)
				{
					delete[] Region_[i].PathFlagIndex;
					Region_[i].PathFlagIndex = nullptr;
				}

				if (Region_[i].PathFlags != nullptr)
				{
					//for (int j = 0; j < Region_[i].TotalPathFlags; j++)
					//{
					//	if (Region_[i].PathFlags[j].NeighborFlagIndexList != nullptr)
					//	{
					//		delete[] Region_[i].PathFlags[j].NeighborFlagIndexList;
					//		Region_[i].PathFlags[j].NeighborFlagIndexList = nullptr;
					//	}
					//	if (Region_[i].PathFlags[j].NeighborFlagList != nullptr)
					//	{
					//		delete[] Region_[i].PathFlags[j].NeighborFlagList;
					//		Region_[i].PathFlags[j].NeighborFlagList = nullptr;
					//	}
					//}

					delete[] Region_[i].PathFlags;
					Region_[i].PathFlags = nullptr;
				}
			}

			delete[] Region_;
			Region_ = nullptr;
		}

		// destroy path flag info
		if (PathFlagInfo_ != nullptr)
		{
			//for (int i = 0; i < TotalPathFlagInfo_; i++)
			//{
			//	if (PathFlagInfo_[i].ToPathList != nullptr)
			//	{
			//		delete[] PathFlagInfo_[i].ToPathList;
			//	}
			//}

			delete[] PathFlagInfo_;
			PathFlagInfo_ = nullptr;
		}

		// destroy path flag
		if (PathFlags_ != nullptr)
		{
			for (int i = 0; i < TotalPathFlags_; i++)
			{
				if (PathFlags_[i].NeighborFlagIndexList != nullptr)
				{
					delete[] PathFlags_[i].NeighborFlagIndexList;
					PathFlags_[i].NeighborFlagIndexList = nullptr;
				}
				if (PathFlags_[i].NeighborFlagList != nullptr)
				{
					delete[] PathFlags_[i].NeighborFlagList;
					PathFlags_[i].NeighborFlagList = nullptr;
				}
			}

			delete[] PathFlags_;
			PathFlags_ = nullptr;
		}

		TotalPathFlagInfo_ = 0;
		TotalPathFlags_ = 0;
		NextPathFlagInfoId_ = 0;
		TotalRegionCountX_ = 0;
		TotalRegionCountY_ = 0;

		REGION_SIZE_X_ = 0;
		REGION_SIZE_Y_ = 0;
	}

	int	FAStarMap::GetNextPathFlagIndex()
	{
		// find last index
		if (TotalPathFlags_ > 0)
		{
			return (PathFlags_[TotalPathFlags_ - 1].index + 1);
		}

		return 0;
	}

	bool FAStarMap::CreateRegion(const float* WorldSize, int RegionSizeX, int RegionSizeY)
	{
		// check requirement
		if (WorldSize[0] <= 0.0f || WorldSize[1] <= 0.0f ||
			RegionSizeX <= 0 || RegionSizeY <= 0)
		{
			return false;
		}

		// destroy exist
		DestroyRegion();

		// calculate total region count
		int sx = (int)(WorldSize[0] / (float)RegionSizeX) + 1;
		int sy = (int)(WorldSize[1] / (float)RegionSizeY) + 1;
		int total = sx * sy;

		// create memory and initialize
		Region_ = new FRegion[total];
		memset(Region_, 0, sizeof(FRegion)*total);

		TotalRegionCountX_ = sx;
		TotalRegionCountY_ = sy;
		REGION_SIZE_X_ = RegionSizeX;
		REGION_SIZE_Y_ = RegionSizeY;

		// initialize regions
		for (int i = 0; i < total; i++)
		{
			Region_[i].CenterPosition[0] = (float)((i % sx) * RegionSizeX) + (float)(RegionSizeX * 0.5f);
			Region_[i].CenterPosition[1] = (float)((i / sx) * RegionSizeY) + (float)(RegionSizeY * 0.5f);
			Region_[i].CenterPosition[2] = 0.0f;

			Region_[i].TotalPathFlags = 0;
			Region_[i].PathFlagIndex = nullptr;
			Region_[i].PathFlags = nullptr;
		}

		return true;
	}

	FRegion* FAStarMap::GetRegionPtr(int index)
	{
		if (index < 0 || index >= TotalRegionCountX_ * TotalRegionCountY_)
		{
			return nullptr;
		}

		return (Region_ + index);
	}

	FRegion* FAStarMap::GetRegionPtr(int region_x, int region_y)
	{
		int index = RegionPosToRegionIndex(region_x, region_y);
		if (index == INVALID_INDEX)
		{
			return nullptr;
		}

		return (Region_ + index);
	}

	FPathFlag* FAStarMap::GetPathFlagPtr(const float* Loc)
	{
		// get region by position
		int x = 0, y = 0;
		if (WorldPosToRegionPos(Loc, x, y) == false)
		{
			return nullptr;
		}

		//FRegion* region = GetRegionPtr(x, y);

		//for (int i = 0; i < region->TotalPathFlags; i++)
		//{
		//	if (region->PathFlags[i].Position[0] == Loc[0] &&
		//		region->PathFlags[i].Position[1] == Loc[1] &&
		//		region->PathFlags[i].Position[2] == Loc[2])
		//	{
		//		return (region->PathFlags + i);
		//	}
		//}

		for (int i = 0; i < TotalPathFlags_; i++)
		{
			if (PathFlags_[i].Position[0] == Loc[0] &&
				PathFlags_[i].Position[1] == Loc[1])
			{
				return (PathFlags_ + i);
			}
		}

		return nullptr;
	}

	FPathFlag* FAStarMap::GetPathFlagPtr(int index)
	{
		if (index < 0 || index >= TotalPathFlags_)
		{
			return nullptr;
		}

		return (PathFlags_ + index);
	}

	int FAStarMap::GetPathFlagIndex(const float* Loc)
	{
		for (int i = 0; i < TotalPathFlags_; i++)
		{
			if (PathFlags_[i].Position[0] == Loc[0] &&
				PathFlags_[i].Position[1] == Loc[1])
			{
				return PathFlags_[i].index;
			}
		}

		return INVALID_INDEX;
	}

	FPathFlagInfo* FAStarMap::GetPathFlagInfoPtr(int index)
	{
		if (index < 0 || index >= TotalPathFlagInfo_)
		{
			return nullptr;
		}

		return (PathFlagInfo_ + index);
	}

	FPathFlagInfo* FAStarMap::GetPathFlagInfoPtrById(int id)
	{
		for (int i = 0; i < TotalPathFlagInfo_; i++)
		{
			if (PathFlagInfo_[i].id == id)
			{
				return (PathFlagInfo_ + i);
			}
		}

		return nullptr;
	}

	FPathFlagInfo* FAStarMap::GetPathFlagInfoPtr(float* v1, float* v2)
	{
		for (int i = 0; i < TotalPathFlagInfo_; i++)
		{
			if (PathFlagInfo_[i].v1[0] == v1[0] &&
				PathFlagInfo_[i].v1[1] == v1[1] &&
				PathFlagInfo_[i].v2[0] == v2[0] &&
				PathFlagInfo_[i].v2[1] == v2[1])
			{
				return (PathFlagInfo_ + i);
			}

			if (PathFlagInfo_[i].v1[0] == v2[0] &&
				PathFlagInfo_[i].v1[1] == v2[1] &&
				PathFlagInfo_[i].v2[0] == v1[0] &&
				PathFlagInfo_[i].v2[1] == v1[1])
			{
				return (PathFlagInfo_ + i);
			}
		}

		return nullptr;
	}

	int FAStarMap::RegionPosToRegionIndex(int region_x, int region_y)
	{
		if (region_x < 0 || region_y < 0 ||
			region_x >= TotalRegionCountX_ || region_y >= TotalRegionCountY_)
		{
			return INVALID_INDEX;
		}

		int index = (region_y* TotalRegionCountX_) + region_x;
		return index;
	}

	bool FAStarMap::WorldPosToRegionPos(const float *Loc, int &out_region_x, int &out_region_y)
	{
		float x = Loc[0];
		float y = Loc[1];

		if (x < 0.0f || y < 0.0f || x >(float)(TotalRegionCountX_*REGION_SIZE_X_) || y >(float)(TotalRegionCountY_*REGION_SIZE_Y_))
		{
			return false;
		}

		out_region_x = (int)(x / (float)REGION_SIZE_X_);
		out_region_y = (int)(y / (float)REGION_SIZE_Y_);

		return true;
	}

	//int FAStarMap::AddPathFlagInfo(float* v1, float* v2, std::vector<FNodeCoordinate> &PathList, bool PathExpLeft[MAX_PATH_EXPANSION], bool PathExpRight[MAX_PATH_EXPANSION], int HalfWayPointIndex)
	//{
	//	return AddPathFlagInfo(v1, v2, CalculatePathListTotalCost(PathList));

	//	//// find already exist
	//	//FPathFlagInfo* ppfi = GetPathFlagInfoPtr(v1, v2);
	//	//if (ppfi != nullptr)
	//	//{
	//	//	return ppfi->id;
	//	//}

	//	//FPathFlagInfo pathflaginfo;
	//	//memset(&pathflaginfo, 0, sizeof(FPathFlagInfo));

	//	//// set info
	//	//pathflaginfo.id = ++NextPathFlagInfoId_;

	//	//pathflaginfo.v1[0] = v1[0];
	//	//pathflaginfo.v1[1] = v1[1];
	//	//pathflaginfo.v1[2] = v1[2];

	//	//pathflaginfo.v2[0] = v2[0];
	//	//pathflaginfo.v2[1] = v2[1];
	//	//pathflaginfo.v2[2] = v2[2];

	//	//memcpy(pathflaginfo.PathExpLeft, PathExpLeft, sizeof(bool)*MAX_PATH_EXPANSION);
	//	//memcpy(pathflaginfo.PathExpRight, PathExpRight, sizeof(bool)*MAX_PATH_EXPANSION);

	//	//pathflaginfo.HalfWayPointIndex = HalfWayPointIndex;

	//	//pathflaginfo.TotalPathList = (int)PathList.size();
	//	//if (pathflaginfo.TotalPathList > 0)
	//	//{
	//	//	pathflaginfo.ToPathList = new FNodeCoordinate[pathflaginfo.TotalPathList];
	//	//	for (int i = 0; i < pathflaginfo.TotalPathList; i++)
	//	//	{
	//	//		pathflaginfo.ToPathList[i] = PathList[i];
	//	//	}
	//	//}
	//	//else
	//	//{
	//	//	pathflaginfo.ToPathList = nullptr;
	//	//}

	//	//// copy to array
	//	//if (PathFlagInfo_ == nullptr)
	//	//{
	//	//	PathFlagInfo_ = new FPathFlagInfo;
	//	//	memcpy(PathFlagInfo_, &pathflaginfo, sizeof(FPathFlagInfo));
	//	//}
	//	//else
	//	//{
	//	//	FPathFlagInfo* newpathflaginfo = new FPathFlagInfo[TotalPathFlagInfo_ + 1];
	//	//	memcpy(newpathflaginfo, PathFlagInfo_, sizeof(FPathFlagInfo)*TotalPathFlagInfo_);
	//	//	memcpy(newpathflaginfo + TotalPathFlagInfo_, &pathflaginfo, sizeof(FPathFlagInfo));
	//	//	delete[] PathFlagInfo_;
	//	//	PathFlagInfo_ = newpathflaginfo;
	//	//}

	//	//TotalPathFlagInfo_++;

	//	//return pathflaginfo.id;
	//}

	//int FAStarMap::AddPathFlagInfo(float* v1, float* v2, std::vector<FNodeCoordinate> &PathList, int HalfWayPointIndex)
	//{
	//	bool PathExpLeft[MAX_PATH_EXPANSION];
	//	bool PathExpRight[MAX_PATH_EXPANSION];

	//	memset(PathExpLeft, 0, sizeof(bool)*MAX_PATH_EXPANSION);
	//	memset(PathExpRight, 0, sizeof(bool)*MAX_PATH_EXPANSION);

	//	return AddPathFlagInfo(v1, v2, PathList, PathExpLeft, PathExpRight, HalfWayPointIndex);
	//}

	int FAStarMap::AddPathFlagInfo(float* v1, float* v2, int Cost)
	{
		// find already exist
		FPathFlagInfo* ppfi = GetPathFlagInfoPtr(v1, v2);
		if (ppfi != nullptr)
		{
			return ppfi->id;
		}

		FPathFlagInfo pathflaginfo;
		memset(&pathflaginfo, 0, sizeof(FPathFlagInfo));

		// set info
		pathflaginfo.id = ++NextPathFlagInfoId_;

		pathflaginfo.v1[0] = v1[0];
		pathflaginfo.v1[1] = v1[1];
		pathflaginfo.v1[2] = v1[2];

		pathflaginfo.v2[0] = v2[0];
		pathflaginfo.v2[1] = v2[1];
		pathflaginfo.v2[2] = v2[2];

		pathflaginfo.Cost = Cost;

		// copy to array
		if (PathFlagInfo_ == nullptr)
		{
			PathFlagInfo_ = new FPathFlagInfo;
			memcpy(PathFlagInfo_, &pathflaginfo, sizeof(FPathFlagInfo));
		}
		else
		{
			FPathFlagInfo* newpathflaginfo = new FPathFlagInfo[TotalPathFlagInfo_ + 1];
			memcpy(newpathflaginfo, PathFlagInfo_, sizeof(FPathFlagInfo)*TotalPathFlagInfo_);
			memcpy(newpathflaginfo + TotalPathFlagInfo_, &pathflaginfo, sizeof(FPathFlagInfo));
			delete[] PathFlagInfo_;
			PathFlagInfo_ = newpathflaginfo;
		}

		TotalPathFlagInfo_++;

		return pathflaginfo.id;
	}

	bool FAStarMap::AddNeighborFlagInPathFlag(float* Loc, int PathFlagInfoId)
	{
		bool found = false;
		FPathFlag* pathflag = GetPathFlagPtr(Loc);
		if (pathflag == nullptr)
		{
			if (AddPathFlag(Loc) == false)
			{
				return false;
			}
			pathflag = GetPathFlagPtr(Loc);
			if (pathflag == nullptr)
			{
				return false;
			}
		}

		for (int i = 0; i < pathflag->TotalNeighborFlagList; i++)
		{
			//if (pathflag1->NeighborFlagList[i]->id == ppfi->id)
			if (pathflag->NeighborFlagIndexList[i] == PathFlagInfoId)
			{
				found = true;
				break;
			}
		}

		if (found == false)
		{
			//if (pathflag1->NeighborFlagList == nullptr)
			//{
			//	pathflag1->NeighborFlagList = new FPathFlagInfo*[1];
			//	pathflag1->NeighborFlagList[0] = ppfi;
			//}
			//else
			//{
			//	FPathFlagInfo** newppfi = new FPathFlagInfo*[pathflag1->TotalNeighborFlagList + 1];

			//	memcpy(newppfi, pathflag1->NeighborFlagList, sizeof(FPathFlagInfo*) * pathflag1->TotalNeighborFlagList);
			//	newppfi[pathflag1->TotalNeighborFlagList] = ppfi;

			//	delete[] pathflag1->NeighborFlagList;
			//	pathflag1->NeighborFlagList = newppfi;
			//}
			if (pathflag->NeighborFlagIndexList == nullptr)
			{
				pathflag->NeighborFlagIndexList = new int[1];
				pathflag->NeighborFlagIndexList[0] = PathFlagInfoId;
			}
			else
			{
				int* newIndexList = new int[pathflag->TotalNeighborFlagList + 1];

				// copy exist
				memcpy(newIndexList, pathflag->NeighborFlagIndexList, sizeof(int) * pathflag->TotalNeighborFlagList);

				// add new one to last
				newIndexList[pathflag->TotalNeighborFlagList] = PathFlagInfoId;

				delete[] pathflag->NeighborFlagIndexList;
				pathflag->NeighborFlagIndexList = newIndexList;
			}

			pathflag->TotalNeighborFlagList += 1;

			// path flag info pointer remapping required
			//RemapNeighborPathFlagInfo(pathflag);
		}

		return true;
	}

	bool FAStarMap::AddNeighborFlagInPathFlag(float* v1, float* v2)
	{
		bool found;

		// make path flag v1 v2
		FPathFlag* pathflagv1 = GetPathFlagPtr(v1);
		if (pathflagv1 == nullptr)
		{
			if (AddPathFlag(v1) == false)
			{
				return false;
			}
			pathflagv1 = GetPathFlagPtr(v1);
			if (pathflagv1 == nullptr)
			{
				return false;
			}
		}
		FPathFlag* pathflagv2 = GetPathFlagPtr(v2);
		if (pathflagv2 == nullptr)
		{
			if (AddPathFlag(v2) == false)
			{
				return false;
			}
			pathflagv2 = GetPathFlagPtr(v2);
			if (pathflagv2 == nullptr)
			{
				return false;
			}

			// get path flag v1 again (probably memory address changed)
			pathflagv1 = GetPathFlagPtr(v1);
			if (pathflagv1 == nullptr)
			{
				return false;
			}
		}

		// process v1 - check duplication
		found = false;
		for (int i = 0; i < pathflagv1->TotalNeighborFlagList; i++)
		{
			if (pathflagv1->NeighborFlagIndexList[i] == pathflagv1->index ||
				pathflagv1->NeighborFlagIndexList[i] == pathflagv2->index)
			{
				found = true;
				break;
			}
		}

		// process v1 - set neighbor index
		if (found == false)
		{
			if (pathflagv1->NeighborFlagIndexList == nullptr)
			{
				pathflagv1->NeighborFlagIndexList = new int[1];
				pathflagv1->NeighborFlagIndexList[0] = pathflagv2->index;
			}
			else
			{
				int* newIndexList = new int[pathflagv1->TotalNeighborFlagList + 1];

				// copy exist
				memcpy(newIndexList, pathflagv1->NeighborFlagIndexList, sizeof(int) * pathflagv1->TotalNeighborFlagList);

				// add new one to last
				newIndexList[pathflagv1->TotalNeighborFlagList] = pathflagv2->index;

				delete[] pathflagv1->NeighborFlagIndexList;
				pathflagv1->NeighborFlagIndexList = newIndexList;
			}

			pathflagv1->TotalNeighborFlagList += 1;
		}

		// process v2 - check duplication
		found = false;
		for (int i = 0; i < pathflagv2->TotalNeighborFlagList; i++)
		{
			if (pathflagv2->NeighborFlagIndexList[i] == pathflagv1->index ||
				pathflagv2->NeighborFlagIndexList[i] == pathflagv2->index)
			{
				found = true;
				break;
			}
		}

		// process v2 - set neighbor index
		if (found == false)
		{
			if (pathflagv2->NeighborFlagIndexList == nullptr)
			{
				pathflagv2->NeighborFlagIndexList = new int[1];
				pathflagv2->NeighborFlagIndexList[0] = pathflagv1->index;
			}
			else
			{
				int* newIndexList = new int[pathflagv2->TotalNeighborFlagList + 1];

				// copy exist
				memcpy(newIndexList, pathflagv2->NeighborFlagIndexList, sizeof(int) * pathflagv2->TotalNeighborFlagList);

				// add new one to last
				newIndexList[pathflagv2->TotalNeighborFlagList] = pathflagv1->index;

				delete[] pathflagv2->NeighborFlagIndexList;
				pathflagv2->NeighborFlagIndexList = newIndexList;
			}

			pathflagv2->TotalNeighborFlagList += 1;
		}

		return true;
	}

	bool FAStarMap::AddPathFlag(float* v1, float* v2, std::vector<FNodeCoordinate> &PathList)
	{
		// find already exist
		FPathFlagInfo* ppfi = GetPathFlagInfoPtr(v1, v2);
		if (ppfi == nullptr)
		{
			int cost = CalculatePathListTotalCost(PathList);
			AddPathFlagInfo(v1, v2, cost);
			ppfi = GetPathFlagInfoPtr(v1, v2);
			if (ppfi == nullptr)
			{
				return false;
			}
		}

		AddNeighborFlagInPathFlag(v1, v2);

		return true;
	}

	bool FAStarMap::AddPathFlag(float* v1, float* v2, int Cost)
	{
		// find already exist
		FPathFlagInfo* ppfi = GetPathFlagInfoPtr(v1, v2);
		if (ppfi == nullptr)
		{
			AddPathFlagInfo(v1, v2, Cost);
			ppfi = GetPathFlagInfoPtr(v1, v2);
			if (ppfi == nullptr)
			{
				return false;
			}
		}

		//AddNeighborFlagInPathFlag(v1, ppfi->id);
		//AddNeighborFlagInPathFlag(v2, ppfi->id);
		AddNeighborFlagInPathFlag(v1, v2);

		return true;
	}

	bool FAStarMap::AddPathFlag(float* Loc)
	{
		// get region by position
		int x = 0, y = 0;
		if (WorldPosToRegionPos(Loc, x, y) == false)
		{
			return false;
		}

		FRegion* region = GetRegionPtr(x, y);
		if (region == nullptr)
		{
			return false;
		}

		// find already exist
		if (GetPathFlagPtr(Loc) != nullptr)
		{
			return true;
		}

		// add new one
		FPathFlag pathflag;
		pathflag.index = GetNextPathFlagIndex();
		pathflag.Position[0] = Loc[0];
		pathflag.Position[1] = Loc[1];
		pathflag.Position[2] = Loc[2];
		pathflag.TotalNeighborFlagList = 0;
		pathflag.NeighborFlagIndexList = nullptr;
		pathflag.NeighborFlagList = nullptr;

		if (PathFlags_ == nullptr)
		{
			PathFlags_ = new FPathFlag;
			memcpy(PathFlags_, &pathflag, sizeof(FPathFlag));
		}
		else
		{
			FPathFlag* newpathflag = new FPathFlag[TotalPathFlags_ + 1];
			memcpy(newpathflag, PathFlags_, sizeof(FPathFlag) * TotalPathFlags_);
			memcpy(newpathflag + TotalPathFlags_, &pathflag, sizeof(FPathFlag));

			delete[] PathFlags_;
			PathFlags_ = newpathflag;
		}

		//// set pathflag to region
		//if (region->PathFlags == nullptr)
		//{
		//	region->PathFlags = new FPathFlag*;
		//	region->PathFlags[0] = PathFlags_ + TotalPathFlags_;
		//}
		//else
		//{
		//	FPathFlag** newpathflag = new FPathFlag*[region->TotalPathFlags + 1];
		//	memcpy(newpathflag, region->PathFlags, sizeof(FPathFlag*) * region->TotalPathFlags);
		//	newpathflag[region->TotalPathFlags] = PathFlags_ + TotalPathFlags_;

		//	delete[] region->PathFlags;
		//	region->PathFlags = newpathflag;
		//}

		if (region->TotalPathFlags == 0)
		{
			region->PathFlagIndex = new int[1];
			region->PathFlagIndex[0] = TotalPathFlags_;
		}
		else
		{
			int* newindex = new int[region->TotalPathFlags + 1];
			memcpy(newindex, region->PathFlagIndex, sizeof(int)*region->TotalPathFlags);
			newindex[region->TotalPathFlags] = TotalPathFlags_;

			delete[] region->PathFlagIndex;
			region->PathFlagIndex = newindex;
		}
		
		region->TotalPathFlags++;

		TotalPathFlags_++;

		RemapAllRegionPathFlag();

		return true;
	}

	void FAStarMap::RemoveAllErrorPathFlags()
	{
		if (TotalPathFlags_ <= 0)
		{
			return;
		}

		int TotalRemovedCount = 0;	// for debugging purpose

		// remove all stand-alone path flags
		for (int i = 0; i < TotalPathFlags_; i++)
		{
			if (PathFlags_[i].TotalNeighborFlagList == 0)
			{
				// remove this one
				FPathFlag* newpathflag = new FPathFlag[TotalPathFlags_ - 1];

				if (i == 0)
				{
					memcpy(newpathflag, (PathFlags_ + 1), sizeof(FPathFlag)*(TotalPathFlags_ - 1));
				}
				else if (i == TotalPathFlags_ - 1)
				{
					memcpy(newpathflag, PathFlags_, sizeof(FPathFlag)*(TotalPathFlags_ - 1));
				}
				else
				{
					memcpy(newpathflag, (PathFlags_), sizeof(FPathFlag)*(i));
					memcpy((newpathflag + i), (PathFlags_ + i + 1), sizeof(FPathFlag)*(TotalPathFlags_ - i - 1));
				}

				// replace existing one
				delete[] PathFlags_;
				PathFlags_ = newpathflag;

				TotalRemovedCount++;
				TotalPathFlags_--;
				i--;
			}
		}

		// experimental. remove error position path flag
		for (int i = 0; i < TotalPathFlags_; i++)
		{
			// error position detection failed.. 
			// how to detect these denomalized number ? (very close to zero)
			//1.640e-43#DEN
			//1.07935020e-31
			//1.640e-43#DEN

			int v1 = (int)PathFlags_[i].Position[0];
			int v2 = (int)PathFlags_[i].Position[1];
			int v3 = (int)PathFlags_[i].Position[2];

			if (v1 == 0 && v2 == 0 && v3 == 0)
			//if (PathFlags_[i].Position[0] == 0.0f && PathFlags_[i].Position[1] == 0.0f && PathFlags_[i].Position[2] == 0.0f)
			{
				// remove (i) index path flag info data
				for (int j = 0; j < TotalPathFlagInfo_; j++)
				{
					if (PathFlagInfo_[j].index_v1 == i || PathFlagInfo_[j].index_v2 == i)
					{
						// remove (i) path flag data
						FPathFlagInfo* newinfo = new FPathFlagInfo[TotalPathFlagInfo_ - 1];

						if (j == 0)
						{
							memcpy(newinfo, (PathFlagInfo_ + 1), sizeof(FPathFlagInfo)*(TotalPathFlagInfo_ - 1));
						}
						else if (j == TotalPathFlagInfo_ - 1)
						{
							memcpy(newinfo, PathFlagInfo_, sizeof(FPathFlagInfo)*(TotalPathFlagInfo_ - 1));
						}
						else
						{
							memcpy(newinfo, (PathFlagInfo_), sizeof(FPathFlagInfo)*(j));
							memcpy((newinfo + j), (PathFlagInfo_ + j + 1), sizeof(FPathFlagInfo)*(TotalPathFlagInfo_ - j - 1));
						}

						// replace existing one
						delete[] PathFlagInfo_;
						PathFlagInfo_ = newinfo;

						TotalPathFlagInfo_--;
						j--;
					}
				}

				// remove (i) path flag data
				FPathFlag* newpathflag = new FPathFlag[TotalPathFlags_ - 1];

				if (i == 0)
				{
					memcpy(newpathflag, (PathFlags_ + 1), sizeof(FPathFlag)*(TotalPathFlags_ - 1));
				}
				else if (i == TotalPathFlags_ - 1)
				{
					memcpy(newpathflag, PathFlags_, sizeof(FPathFlag)*(TotalPathFlags_ - 1));
				}
				else
				{
					memcpy(newpathflag, (PathFlags_), sizeof(FPathFlag)*(i));
					memcpy((newpathflag + i), (PathFlags_ + i + 1), sizeof(FPathFlag)*(TotalPathFlags_ - i - 1));
				}

				// replace existing one
				delete[] PathFlags_;
				PathFlags_ = newpathflag;

				TotalRemovedCount++;
				TotalPathFlags_--;
				i--;
			}
		}

		// experimental. remove zero cost in path flag info.
	}

	void FAStarMap::RemapNeighborPathFlagInfo(FPathFlag *PathFlag)
	{
		if (PathFlag->NeighborFlagIndexList == nullptr)
		{
			return;
		}

		// destroy exist
		if (PathFlag->NeighborFlagList != nullptr)
		{
			delete[] PathFlag->NeighborFlagList;
			PathFlag->NeighborFlagList = nullptr;
		}

		PathFlag->NeighborFlagList = new FPathFlagInfo*[PathFlag->TotalNeighborFlagList];
		for (int i = 0; i < PathFlag->TotalNeighborFlagList; i++)
		{
			PathFlag->NeighborFlagList[i] = GetPathFlagInfoPtrById(PathFlag->NeighborFlagIndexList[i]);
		}
	}

	void FAStarMap::RemapAllNeighborPathFlagInfo()
	{
		int total = TotalRegionCountX_ * TotalRegionCountY_;
		for (int i = 0; i < total; i++)
		{
			FRegion* region = (Region_ + i);

			for (int j = 0; j < region->TotalPathFlags; j++)
			{
				RemapNeighborPathFlagInfo(region->PathFlags[j]);
			}
		}
	}

	void FAStarMap::RemapAllPathFlagInfoVertexIndex()
	{
		if (PathFlagInfo_ == nullptr)
		{
			return;
		}

		FPathFlagInfo* PathFlagInfo;

		for (int i = 0; i < TotalPathFlagInfo_; i++)
		{
			PathFlagInfo = (PathFlagInfo_ + i);

			PathFlagInfo->index_v1 = GetPathFlagIndex(PathFlagInfo->v1);
			PathFlagInfo->index_v2 = GetPathFlagIndex(PathFlagInfo->v2);
		}
	}

	void FAStarMap::RemapAllRegionPathFlag()
	{
		for (int i = 0; i < GetTotalRegionCount(); i++)
		{
			FRegion* region = (Region_ + i);

			if (region->TotalPathFlags > 0)
			{
				if (region->PathFlags != nullptr)
				{
					delete[] region->PathFlags;
					region->PathFlags = nullptr;
				}

				region->PathFlags = new FPathFlag*[region->TotalPathFlags];
				for (int j = 0; j < region->TotalPathFlags; j++)
				{
					region->PathFlags[j] = (PathFlags_ + region->PathFlagIndex[j]);
				}
			}
		}
	}

	const int ASTARFLAGMAP_MAGIC = 'A' << 24 | 'F' << 16 | 'L' << 8 | 'G'; //'AFLG';
	//const int ASTARFLAGMAP_VERSION = 1;	// first release version
	//const int ASTARFLAGMAP_VERSION = 2;	// 2019/07/09 added Path Expansion Flag in FPathFlagInfo
	//const int ASTARFLAGMAP_VERSION = 3;	// 2019/08/06 removed path list data in FPathFlagInfo
	//const int ASTARFLAGMAP_VERSION = 4;	// 2019/08/07 all of FPathFlag data have merged
	const int ASTARFLAGMAP_VERSION = 5;		// 2019/11/20 save index of FPathFlag

	bool FAStarMap::ReadPathFlagInfoV1(FPathFlagInfo* PathFlagInfo, FILE *fp)
	{
		// read id
		fread(&(PathFlagInfo->id), sizeof(unsigned int), 1, fp);			// internal use (for load/save)

		// read path points
		fread(PathFlagInfo->v1, sizeof(float), 3, fp);
		fread(PathFlagInfo->v2, sizeof(float), 3, fp);

		// read total path list count as cost
		fread(&(PathFlagInfo->Cost), sizeof(int), 1, fp);

		// read v1 to v2 path list
		//fread(&(PathFlagInfo->TotalPathList), sizeof(int), 1, fp);
		//if (PathFlagInfo->TotalPathList > 0)
		if (PathFlagInfo->Cost > 0)
		{
			//PathFlagInfo->ToPathList = new FNodeCoordinate[PathFlagInfo->TotalPathList];
			//fread(PathFlagInfo->ToPathList, sizeof(FNodeCoordinate), PathFlagInfo->TotalPathList, fp);
			fseek(fp, sizeof(FNodeCoordinate)*PathFlagInfo->Cost, SEEK_CUR);
		}
		//else
		//{
		//	PathFlagInfo->ToPathList = nullptr;
		//}

		// set to unused
		//memset(PathFlagInfo->PathExpLeft, 0, sizeof(bool) * MAX_PATH_EXPANSION);
		//memset(PathFlagInfo->PathExpRight, 0, sizeof(bool) * MAX_PATH_EXPANSION);

		// read halfway point index - drop
		//fread(&(PathFlagInfo->HalfWayPointIndex), sizeof(int), 1, fp);
		//PathFlagInfo->HalfWayPointIndex = INVALID_INDEX;
		fseek(fp, sizeof(int), SEEK_CUR);

		return true;
	}

	bool FAStarMap::ReadPathFlagInfoV2(FPathFlagInfo* PathFlagInfo, FILE *fp)
	{
		// read id
		fread(&(PathFlagInfo->id), sizeof(unsigned int), 1, fp);			// internal use (for load/save)

		// read path points
		fread(PathFlagInfo->v1, sizeof(float), 3, fp);
		fread(PathFlagInfo->v2, sizeof(float), 3, fp);

		// read total path list count as cost
		fread(&(PathFlagInfo->Cost), sizeof(int), 1, fp);

		// read v1 to v2 path list
		//fread(&(PathFlagInfo->TotalPathList), sizeof(int), 1, fp);
		//if (PathFlagInfo->TotalPathList > 0)
		if (PathFlagInfo->Cost > 0)
		{
			//PathFlagInfo->ToPathList = new FNodeCoordinate[PathFlagInfo->TotalPathList];
			//fread(PathFlagInfo->ToPathList, sizeof(FNodeCoordinate), PathFlagInfo->TotalPathList, fp);
			fseek(fp, sizeof(FNodeCoordinate)*PathFlagInfo->Cost, SEEK_CUR);
		}
		//else
		//{
		//	PathFlagInfo->ToPathList = nullptr;
		//}

		// write path expansion flag 
		//fread(PathFlagInfo->PathExpLeft, sizeof(bool), MAX_PATH_EXPANSION, fp);
		fseek(fp, sizeof(bool)*MAX_PATH_EXPANSION, SEEK_CUR);
		//fread(PathFlagInfo->PathExpRight, sizeof(bool), MAX_PATH_EXPANSION, fp);
		fseek(fp, sizeof(bool)*MAX_PATH_EXPANSION, SEEK_CUR);

		// read halfway point index
		//fread(&(PathFlagInfo->HalfWayPointIndex), sizeof(int), 1, fp);
		//PathFlagInfo->HalfWayPointIndex = INVALID_INDEX;
		fseek(fp, sizeof(int), SEEK_CUR);

		return true;
	}

	bool FAStarMap::ReadPathFlagInfoV3(FPathFlagInfo* PathFlagInfo, FILE *fp)
	{
		// read id
		fread(&(PathFlagInfo->id), sizeof(unsigned int), 1, fp);			// internal use (for load/save)

		// read path points
		fread(PathFlagInfo->v1, sizeof(float), 3, fp);
		fread(PathFlagInfo->v2, sizeof(float), 3, fp);

		// read cost
		fread(&(PathFlagInfo->Cost), sizeof(int), 1, fp);

		// unused
		//PathFlagInfo->HalfWayPointIndex = INVALID_INDEX;

		return true;
	}

	bool FAStarMap::ReadPathFlagV3(FPathFlag* PathFlag, FILE *fp)
	{
		// read position
		fread(PathFlag->Position, sizeof(float), 3, fp);

		// read linked neighbor list
		fread(&(PathFlag->TotalNeighborFlagList), sizeof(int), 1, fp);

		if (PathFlag->TotalNeighborFlagList > 0)
		{
			PathFlag->NeighborFlagIndexList = new int[PathFlag->TotalNeighborFlagList];
			fread(PathFlag->NeighborFlagIndexList, sizeof(int), PathFlag->TotalNeighborFlagList, fp);

			RemapNeighborPathFlagInfo(PathFlag);
		}
		else
		{
			PathFlag->NeighborFlagIndexList = nullptr;
			PathFlag->NeighborFlagList = nullptr;
		}

		return true;
	}

	bool FAStarMap::ReadPathFlagV5(FPathFlag* PathFlag, FILE *fp)
	{
		// read index
		fread(&(PathFlag->index), sizeof(int), 1, fp);

		// read position
		fread(PathFlag->Position, sizeof(float), 3, fp);

		// read linked neighbor list
		fread(&(PathFlag->TotalNeighborFlagList), sizeof(int), 1, fp);

		if (PathFlag->TotalNeighborFlagList > 0)
		{
			PathFlag->NeighborFlagIndexList = new int[PathFlag->TotalNeighborFlagList];
			fread(PathFlag->NeighborFlagIndexList, sizeof(int), PathFlag->TotalNeighborFlagList, fp);

			RemapNeighborPathFlagInfo(PathFlag);
		}
		else
		{
			PathFlag->NeighborFlagIndexList = nullptr;
			PathFlag->NeighborFlagList = nullptr;
		}

		return true;
	}

	bool FAStarMap::ReadRegionV3(FRegion* Region, FILE* fp)
	{
		// read center position
		fread(&Region->CenterPosition, sizeof(float), 3, fp);

		// read flag data
		fread(&(Region->TotalPathFlags), sizeof(int), 1, fp);
		
		if (Region->TotalPathFlags > 0)
		{
			Region->PathFlags = new FPathFlag*[Region->TotalPathFlags];
			memset(Region->PathFlags, 0, sizeof(FPathFlag*)*Region->TotalPathFlags);

			// create / resize path flag array
			if (PathFlags_ == nullptr)
			{
				PathFlags_ = new FPathFlag[Region->TotalPathFlags];
				memset(PathFlags_, 0, sizeof(FPathFlag) * Region->TotalPathFlags);
			}
			else
			{
				FPathFlag* newpathflag = new FPathFlag[TotalPathFlags_ + Region->TotalPathFlags];
				memcpy(newpathflag, PathFlags_, sizeof(FPathFlag) * TotalPathFlags_);
				memset(newpathflag + TotalPathFlags_, 0, sizeof(FPathFlag) * Region->TotalPathFlags);

				delete[] PathFlags_;
				PathFlags_ = newpathflag;
			}

			int startindex = TotalPathFlags_;

			for (int i = 0; i < Region->TotalPathFlags; i++)
			{
				int index = startindex + i;

				ReadPathFlagV3(PathFlags_ + index, fp);

				// set index
				PathFlags_[index].index = index;

				Region->PathFlags[i] = (PathFlags_ + index);
			}

			TotalPathFlags_ += Region->TotalPathFlags;
		}

		return true;
	}

	bool FAStarMap::ReadRegionV4(FRegion* Region, FILE* fp)
	{
		// read center position
		fread(&Region->CenterPosition, sizeof(float), 3, fp);

		// read flag data
		fread(&(Region->TotalPathFlags), sizeof(int), 1, fp);

		if (Region->TotalPathFlags > 0)
		{
			Region->PathFlags = new FPathFlag*[Region->TotalPathFlags];
			Region->PathFlagIndex = new int[Region->TotalPathFlags];

			for (int i = 0; i < Region->TotalPathFlags; i++)
			{
				int index;
				// read path flag index
				fread(&(index), sizeof(int), 1, fp);
				
				Region->PathFlagIndex[i] = index;
				Region->PathFlags[i] = (PathFlags_ + index);
			}
		}

		return true;
	}

// #pragma region Old Version
	// unused - just for reference
	//bool FAStarMap::WritePathFlagInfoV2(FPathFlagInfo* PathFlagInfo, FILE *fp)
	//{
	//	// write id
	//	fwrite(&(PathFlagInfo->id), sizeof(unsigned int), 1, fp);			// internal use (for load/save)

	//	// write path points
	//	fwrite(PathFlagInfo->v1, sizeof(float), 3, fp);
	//	fwrite(PathFlagInfo->v2, sizeof(float), 3, fp);

	//	// write v1 to v2 path list
	//	fwrite(&(PathFlagInfo->TotalPathList), sizeof(int), 1, fp);
	//	if (PathFlagInfo->TotalPathList > 0)
	//	{
	//		fwrite(PathFlagInfo->ToPathList, sizeof(FNodeCoordinate), PathFlagInfo->TotalPathList, fp);
	//	}

	//	// write path expansion flag 
	//	fwrite(&(PathFlagInfo->PathExpLeft), sizeof(bool), MAX_PATH_EXPANSION, fp);
	//	fwrite(&(PathFlagInfo->PathExpRight), sizeof(bool), MAX_PATH_EXPANSION, fp);

	//	// write halfway point index
	//	fwrite(&(PathFlagInfo->HalfWayPointIndex), sizeof(int), 1, fp);

	//	return true;
	//}
// #pragma endregion Old Version

	bool FAStarMap::WritePathFlagInfo(FPathFlagInfo* PathFlagInfo, FILE *fp)
	{
		// write id
		fwrite(&(PathFlagInfo->id), sizeof(unsigned int), 1, fp);			// internal use (for load/save)

		// write path points
		fwrite(PathFlagInfo->v1, sizeof(float), 3, fp);
		fwrite(PathFlagInfo->v2, sizeof(float), 3, fp);

		// write cost
		fwrite(&(PathFlagInfo->Cost), sizeof(int), 1, fp);
		return true;
	}

	bool FAStarMap::WritePathFlag(FPathFlag* PathFlag, FILE *fp)
	{
		// write index
		fwrite(&(PathFlag->index), sizeof(int), 1, fp);

		// write position
		fwrite(PathFlag->Position, sizeof(float), 3, fp);

		// write linked neighbor list
		fwrite(&(PathFlag->TotalNeighborFlagList), sizeof(int), 1, fp);

		//for (int i = 0; i < PathFlag_->TotalNeighborFlagList; i++)
		//{
		//	// write path flag info index only
		//	fwrite(&(PathFlag_->NeighborFlagList[i]->id), sizeof(int), 1, fp);
		//}
		if (PathFlag->TotalNeighborFlagList > 0)
		{
			fwrite(PathFlag->NeighborFlagIndexList, sizeof(int), PathFlag->TotalNeighborFlagList, fp);
		}

		return true;
	}

	bool FAStarMap::WriteRegion(FRegion* Region, FILE* fp)
	{
		// write center position
		fwrite(&Region->CenterPosition, sizeof(float), 3, fp);

		// write flag data
		fwrite(&(Region->TotalPathFlags), sizeof(int), 1, fp);

		for (int i = 0; i < Region->TotalPathFlags; i++)
		{
			//WritePathFlag(&(Region->PathFlags[i]), fp);
			
			// write path flag index
			fwrite(&(Region->PathFlags[i]->index), sizeof(int), 1, fp);
		}

		return true;
	}

	bool FAStarMap::LoadRegion_Version1(FILE* fp)
	{
		DestroyRegion();

		fread(&TotalRegionCountX_, sizeof(int), 1, fp);
		fread(&TotalRegionCountY_, sizeof(int), 1, fp);
		int TotalRegion = TotalRegionCountX_ * TotalRegionCountY_;

		fread(&REGION_SIZE_X_, sizeof(int), 1, fp);
		fread(&REGION_SIZE_Y_, sizeof(int), 1, fp);

		// read chunk data - path flag info
		fread(&TotalPathFlagInfo_, sizeof(int), 1, fp);
		if (TotalPathFlagInfo_ > 0)
		{
			PathFlagInfo_ = new FPathFlagInfo[TotalPathFlagInfo_];
			memset(PathFlagInfo_, 0, sizeof(FPathFlagInfo)*TotalPathFlagInfo_);

			for (int i = 0; i < TotalPathFlagInfo_; i++)
			{
				ReadPathFlagInfoV1(PathFlagInfo_ + i, fp);
			}
		}

		// read chunk data - region
		if (TotalRegion > 0)
		{
			Region_ = new FRegion[TotalRegion];
			memset(Region_, 0, sizeof(FRegion)*TotalRegion);

			for (int i = 0; i < TotalRegion; i++)
			{
				ReadRegionV3(Region_ + i, fp);
			}
		}

		fclose(fp);

		return true;
	}

	bool FAStarMap::LoadRegion_Version2(FILE* fp)
	{
		DestroyRegion();

		fread(&TotalRegionCountX_, sizeof(int), 1, fp);
		fread(&TotalRegionCountY_, sizeof(int), 1, fp);
		int TotalRegion = TotalRegionCountX_ * TotalRegionCountY_;

		fread(&REGION_SIZE_X_, sizeof(int), 1, fp);
		fread(&REGION_SIZE_Y_, sizeof(int), 1, fp);

		// read chunk data - path flag info
		fread(&TotalPathFlagInfo_, sizeof(int), 1, fp);
		if (TotalPathFlagInfo_ > 0)
		{
			PathFlagInfo_ = new FPathFlagInfo[TotalPathFlagInfo_];
			memset(PathFlagInfo_, 0, sizeof(FPathFlagInfo)*TotalPathFlagInfo_);

			for (int i = 0; i < TotalPathFlagInfo_; i++)
			{
				ReadPathFlagInfoV2(PathFlagInfo_ + i, fp);
			}
		}

		// read chunk data - region
		if (TotalRegion > 0)
		{
			Region_ = new FRegion[TotalRegion];
			memset(Region_, 0, sizeof(FRegion)*TotalRegion);

			for (int i = 0; i < TotalRegion; i++)
			{
				ReadRegionV3(Region_ + i, fp);
			}
		}

		fclose(fp);

		return true;
	}

	bool FAStarMap::LoadRegion_Version3(FILE* fp)
	{
		DestroyRegion();

		fread(&TotalRegionCountX_, sizeof(int), 1, fp);
		fread(&TotalRegionCountY_, sizeof(int), 1, fp);
		int TotalRegion = TotalRegionCountX_ * TotalRegionCountY_;

		fread(&REGION_SIZE_X_, sizeof(int), 1, fp);
		fread(&REGION_SIZE_Y_, sizeof(int), 1, fp);

		// read chunk data - path flag info
		fread(&TotalPathFlagInfo_, sizeof(int), 1, fp);
		if (TotalPathFlagInfo_ > 0)
		{
			PathFlagInfo_ = new FPathFlagInfo[TotalPathFlagInfo_];
			memset(PathFlagInfo_, 0, sizeof(FPathFlagInfo)*TotalPathFlagInfo_);

			for (int i = 0; i < TotalPathFlagInfo_; i++)
			{
				ReadPathFlagInfoV3(PathFlagInfo_ + i, fp);
			}
		}

		// read chunk data - region
		if (TotalRegion > 0)
		{
			Region_ = new FRegion[TotalRegion];
			memset(Region_, 0, sizeof(FRegion)*TotalRegion);

			for (int i = 0; i < TotalRegion; i++)
			{
				ReadRegionV3(Region_ + i, fp);
			}
		}

		fclose(fp);

		return true;
	}

	bool FAStarMap::LoadRegion_Version4(FILE* fp)
	{
		DestroyRegion();

		fread(&TotalRegionCountX_, sizeof(int), 1, fp);
		fread(&TotalRegionCountY_, sizeof(int), 1, fp);
		int TotalRegion = TotalRegionCountX_ * TotalRegionCountY_;

		fread(&REGION_SIZE_X_, sizeof(int), 1, fp);
		fread(&REGION_SIZE_Y_, sizeof(int), 1, fp);

		// read chunk data - path flag
		fread(&TotalPathFlags_, sizeof(int), 1, fp);
		if (TotalPathFlags_ > 0)
		{
			PathFlags_ = new FPathFlag[TotalPathFlags_];
			memset(PathFlags_, 0, sizeof(FPathFlag)*TotalPathFlags_);

			for (int i = 0; i < TotalPathFlags_; i++)
			{
				ReadPathFlagV3(PathFlags_ + i, fp);

				// set index
				PathFlags_[i].index = i;
			}
		}

		// read chunk data - path flag info
		fread(&TotalPathFlagInfo_, sizeof(int), 1, fp);
		if (TotalPathFlagInfo_ > 0)
		{
			PathFlagInfo_ = new FPathFlagInfo[TotalPathFlagInfo_];
			memset(PathFlagInfo_, 0, sizeof(FPathFlagInfo)*TotalPathFlagInfo_);

			for (int i = 0; i < TotalPathFlagInfo_; i++)
			{
				ReadPathFlagInfoV3(PathFlagInfo_ + i, fp);
			}
		}

		// read chunk data - region
		if (TotalRegion > 0)
		{
			Region_ = new FRegion[TotalRegion];
			memset(Region_, 0, sizeof(FRegion)*TotalRegion);

			for (int i = 0; i < TotalRegion; i++)
			{
				ReadRegionV4(Region_ + i, fp);
			}
		}

		fclose(fp);

		return true;
	}

	bool FAStarMap::LoadRegion_Version5(FILE* fp)
	{
		DestroyRegion();

		fread(&TotalRegionCountX_, sizeof(int), 1, fp);
		fread(&TotalRegionCountY_, sizeof(int), 1, fp);
		int TotalRegion = TotalRegionCountX_ * TotalRegionCountY_;

		fread(&REGION_SIZE_X_, sizeof(int), 1, fp);
		fread(&REGION_SIZE_Y_, sizeof(int), 1, fp);

		// read chunk data - path flag
		fread(&TotalPathFlags_, sizeof(int), 1, fp);
		if (TotalPathFlags_ > 0)
		{
			PathFlags_ = new FPathFlag[TotalPathFlags_];
			memset(PathFlags_, 0, sizeof(FPathFlag)*TotalPathFlags_);

			for (int i = 0; i < TotalPathFlags_; i++)
			{
				ReadPathFlagV5(PathFlags_ + i, fp);
			}
		}

		// read chunk data - path flag info
		fread(&TotalPathFlagInfo_, sizeof(int), 1, fp);
		if (TotalPathFlagInfo_ > 0)
		{
			PathFlagInfo_ = new FPathFlagInfo[TotalPathFlagInfo_];
			memset(PathFlagInfo_, 0, sizeof(FPathFlagInfo)*TotalPathFlagInfo_);

			for (int i = 0; i < TotalPathFlagInfo_; i++)
			{
				ReadPathFlagInfoV3(PathFlagInfo_ + i, fp);
			}
		}

		// read chunk data - region
		if (TotalRegion > 0)
		{
			Region_ = new FRegion[TotalRegion];
			memset(Region_, 0, sizeof(FRegion)*TotalRegion);

			for (int i = 0; i < TotalRegion; i++)
			{
				ReadRegionV4(Region_ + i, fp);
			}
		}

		fclose(fp);

		return true;
	}

	bool FAStarMap::LoadRegion(const char* path)
	{
#ifdef _MSC_VER
		FILE* fp = nullptr;
		if (fopen_s(&fp, path, "rb") != 0)
		{
			fp = nullptr;
		}
#else
		FILE* fp = fopen(path, "rb");
#endif
		if (!fp)
		{
			return false;
		}

		int header;
		int version;

		// read header and check
		fread(&header, sizeof(int), 1, fp);
		if (header != ASTARFLAGMAP_MAGIC)
		{
			fclose(fp);
			return false;
		}

		fread(&version, sizeof(int), 1, fp);
		switch (version)
		{
		case 1:
			LoadRegion_Version1(fp);
			break;
		case 2:
			LoadRegion_Version2(fp);
			break;
		case 3:
			LoadRegion_Version3(fp);
			break;
		case 4:
			LoadRegion_Version4(fp);
			break;
		case 5:
			LoadRegion_Version5(fp);
			break;
		}
		RemapAllPathFlagInfoVertexIndex();
		MakePathPointCost();

		fclose(fp);
		return true;
	}

	bool FAStarMap::SaveRegion(const char* path)
	{
#ifdef _MSC_VER
		FILE* fp = nullptr;
		if (fopen_s(&fp, path, "wb") != 0)
		{
			fp = nullptr;
		}
#else
		FILE* fp = fopen(path, "wb");
#endif
		if (!fp)
		{
			return false;
		}

		// write header
		int header = ASTARFLAGMAP_MAGIC;
		int version = ASTARFLAGMAP_VERSION;

		// write body
		fwrite(&header, sizeof(int), 1, fp);
		fwrite(&version, sizeof(int), 1, fp);

		fwrite(&TotalRegionCountX_, sizeof(int), 1, fp);
		fwrite(&TotalRegionCountY_, sizeof(int), 1, fp);

		fwrite(&REGION_SIZE_X_, sizeof(int), 1, fp);
		fwrite(&REGION_SIZE_Y_, sizeof(int), 1, fp);

		// check path flag data integrity - remove all error path flag
		RemoveAllErrorPathFlags();
		
		// write chunk data - path flag
		fwrite(&TotalPathFlags_, sizeof(int), 1, fp);
		if (TotalPathFlags_ > 0)
		{
			for (int i = 0; i < TotalPathFlags_; i++)
			{
				WritePathFlag(PathFlags_ + i, fp);
			}
		}

		// write chunk data - path flag info
		fwrite(&TotalPathFlagInfo_, sizeof(int), 1, fp);
		for (int i = 0; i < TotalPathFlagInfo_; i++)
		{
			WritePathFlagInfo(PathFlagInfo_ + i, fp);
		}

		// write chunk data - region
		for (int i = 0; i < TotalRegionCountX_*TotalRegionCountY_; i++)
		{
			WriteRegion(Region_ + i, fp);
		}

		fclose(fp);
		return true;
	}

	bool FAStarMap::ReportRegionToText(const char* path)
	{
#ifdef _MSC_VER
		FILE* fp = nullptr;
		if (fopen_s(&fp, path, "wt") != 0)
		{
			fp = nullptr;
		}
#else
		FILE* fp = fopen(path, "wt");
#endif
		if (!fp)
		{
			return false;
		}

		fprintf(fp, "Total Path Flag Info : %d\n", TotalPathFlagInfo_);
		fprintf(fp, "Total Path Flags : %d\n\n", TotalPathFlags_);

		fprintf(fp, "TotalRegionCountX : %d, TotalRegionCountY : %d\n", TotalRegionCountX_, TotalRegionCountY_);
		fprintf(fp, "Region Size X : %d, Region Size Y : %d\n", REGION_SIZE_X_, REGION_SIZE_Y_);

		fprintf(fp, "\n");

		fprintf(fp, "Path Flag Info (%d) ========= \n", TotalPathFlagInfo_);
		for (int i = 0; i < TotalPathFlagInfo_; i++)
		{
			FPathFlagInfo *pathflaginfo = (PathFlagInfo_ + i);

			fprintf(fp, "id:%d, v1(%f, %f, %f), v2(%f, %f, %f), Cost:%d, v1:%d, v2:%d\n",
				pathflaginfo->id, 
				pathflaginfo->v1[0], pathflaginfo->v1[1], pathflaginfo->v1[2],
				pathflaginfo->v2[0], pathflaginfo->v2[1], pathflaginfo->v2[2],
				pathflaginfo->Cost,
				pathflaginfo->index_v1, pathflaginfo->index_v2
				);
		}

		fprintf(fp, "\n");

		fprintf(fp, "Path Flag (%d) ========= \n", TotalPathFlags_);
		for (int i = 0; i < TotalPathFlags_; i++)
		{
			FPathFlag *pathflag = (PathFlags_ + i);

			fprintf(fp, "id:%d, pos(%f, %f, %f), NeighborList:%d - ",
				pathflag->index,
				pathflag->Position[0], pathflag->Position[1], pathflag->Position[2],
				pathflag->TotalNeighborFlagList
			);

			for (int j = 0; j < pathflag->TotalNeighborFlagList; j++)
			{
				fprintf(fp, "%d ", pathflag->NeighborFlagIndexList[j]);
			}

			fprintf(fp, "\n");
		}

		fclose(fp);
		return true;
	}

	bool FAStarMap::ReportPathFlagConnectionToText(const char* path)
	{
#ifdef _MSC_VER
		FILE* fp = nullptr;
		if (fopen_s(&fp, path, "wt") != 0)
		{
			fp = nullptr;
		}
#else
		FILE* fp = fopen(path, "wt");
#endif
		if (!fp)
		{
			return false;
		}

		fprintf(fp, "Total Path Flags : %d\n\n", TotalPathFlags_);

		FPathFlag* StartFlag = nullptr;
		FPathFlag* DestFlag = nullptr;

		for (int s = 0; s < TotalPathFlags_; s++)
		{
			StartFlag = GetPathFlagPtr(s);
			if (StartFlag == nullptr)
			{
				continue;
			}

			for (int d = 0; d < TotalPathFlags_; d++)
			{
				if (s == d)
				{
					continue;
				}

				DestFlag = GetPathFlagPtr(d);
				if (DestFlag == nullptr)
				{
					continue;
				}
				FPathFindResult result;

				result = FindPathFlagPathList(*StartFlag, *DestFlag);
				if (result.Result == CSCommon::FR_Success)
				{
					fprintf(fp, "id:%d(%f, %f, %f) to id:%d(%f, %f, %f) : ",
						StartFlag->index,
						StartFlag->Position[0], StartFlag->Position[1], StartFlag->Position[2],
						DestFlag->index,
						DestFlag->Position[0], DestFlag->Position[1], DestFlag->Position[2]
					);

					for (int32_t i = 0; i < static_cast<int32_t>(result.PathFlagList.size()); i++)
					{
						fprintf(fp, "%d ", result.PathFlagList[i]->index);
					}

					fprintf(fp, "\n");
				}
				else
				{
					fprintf(fp, "ERROR!! id:%d(%f, %f, %f) to id:%d(%f, %f, %f) : Connection Failed\n",
						StartFlag->index,
						StartFlag->Position[0], StartFlag->Position[1], StartFlag->Position[2],
						DestFlag->index,
						DestFlag->Position[0], DestFlag->Position[1], DestFlag->Position[2]
					);
				}
			}
		}


		fclose(fp);
		return true;
	}

	// operation

	// how to find nearest path flag ?
	// 1. do make path flag samples in specfic range
	// 2. find shortest path distance in samples
	// consider :
	// how many samples do we use.
	FPathFlag* FAStarMap::FindNearestPathFlag(const float *Loc, ATTR BlockAttribute, float(*CalcDistanceFunc)(const float*, const float*))
	{
		int x, y;
		if (WorldPosToRegionPos(Loc, x, y) == false)
		{
			return nullptr;
		}

		FRegion* region = GetRegionPtr(x, y);
		if (region == nullptr)
		{
			return nullptr;
		}

		//FPathFlag* pflag = nullptr;
		//float lastdist = _MIRM_FLT_MAX;
		//float sqdist;

		//// v1. old logic
		//for (int i = 0; i < TotalPathFlags_; i++)
		//{
		//	sqdist = g_CalcDistSquared(PathFlags_[i].Position, Loc);
		//	if (sqdist < lastdist)
		//	{
		//		pflag = (PathFlags_ + i);
		//		lastdist = sqdist;
		//	}
		//}

		if (TotalPathFlags_ == 0)
		{
			return nullptr;
		}

		FNodeCoordinate StartPos;
		if (WorldPosToCellPos(Loc, StartPos) == false)
		{
			return nullptr;
		}
		int dist;

		std::vector<std::pair<int, FPathFlag*>> Samples;

		// calculate distance
		for (int i = 0; i < TotalPathFlags_; i++)
		{
			//sqdist = CalcDistanceFunc(PathFlags_[i].Position, Loc);

			FNodeCoordinate pfpos;
			if (WorldPosToCellPos(PathFlags_[i].Position, pfpos))
			{
				dist = g_CalcDistSquaredXY(StartPos.x, StartPos.y, pfpos.x, pfpos.y);
				if (dist < MAX_PATHFLAG_SEARCH_DISTANCE * MAX_PATHFLAG_SEARCH_DISTANCE)
				{
					Samples.push_back(std::make_pair(dist, &(PathFlags_[i])));
				}
			}
		}

		// sort
		std::sort(Samples.begin(), Samples.end());

		// phase 0. on the path flag ?
		if (Samples[0].first == 0)
		{
			return Samples[0].second;
		}

		bool bresult = false;
		
		// phase 1. find straight unblocked path in valid range - easy cost
		for (int i = 0; i < (int)Samples.size(); i++)
		{
			//if (Samples[i].first > MAX_PATHFLAG_SEARCH_DISTANCE * MAX_PATHFLAG_SEARCH_DISTANCE)
			//{
			//	break;
			//}

			if (CheckLine(Loc, Samples[i].second->Position, BlockAttribute, bresult) && !bresult)
			{
				return Samples[i].second;
			}
		}

		// phase 2. find path unblocked - high cost
		// experimental, limit to first 20 samples. lag in here
		int LimitCount = 10;	// down to 20 from 10. 2020.04.07, problem occured in Siege Warfare mode
		int processed = 0;
		bool IsLocPosInvalid = false;

		// check Loc's block attribute
		if (CheckAttribute(StartPos, ATTR_BLOCK, bresult) && bresult)
		{
			// Loc is blocked
			IsLocPosInvalid = true;
		}
		else
		{
			// Loc is invalid pos
			IsLocPosInvalid = true;
		}

		for (int i = 0; i < (int)Samples.size(); i++)
		{
			if (processed > LimitCount)
			{
				Samples.erase(Samples.begin() + i);
				i--;
				continue;
			}

			bool deletethis = false;
			{
				// find path
				FPathFindResult result;

				if (IsLocPosInvalid)
				{
					std::vector<FNodeCoordinate> dummy;
					result = FindNearestPath(Loc, Samples[i].second->Position, BlockAttribute, dummy, nullptr, nullptr, false, DEFAULT_PATHFIND_TIMEOUT);
				}
				else
				{
					result = FindPath(Loc, Samples[i].second->Position, BlockAttribute);
				}

				if (result.Result == FR_Success)
				{
					Samples[i].first = CalculatePathListTotalCost(result.PathList);
				}
				else
				{
					deletethis = false;
				}
			}

			if (deletethis)
			{
				Samples.erase(Samples.begin() + i);
				i--;
			}

			processed++;
		}

		if (Samples.size() > 0)
		{
			// sort and get first path flag
			std::sort(Samples.begin(), Samples.end());

			return Samples[0].second;
		}

		// found nothing
		return nullptr;
	}

	FPathFlag* FAStarMap::FindNearestPathFlag(const float *Loc, ATTR BlockAttribute)
	{
		return FindNearestPathFlag(Loc, BlockAttribute, g_CalcDistSquared);

	}

	FPathFlag* FAStarMap::FindNearestPathFlagXY(const float *Loc, ATTR BlockAttribute)
	{
		return FindNearestPathFlag(Loc, BlockAttribute, g_CalcDistSquaredXY);
	}

	/* old version
	FPathFindResult FAStarMap::FindPathFlagPathList(FPathFlag &StartPathFlag, FPathFlag &DestPathFlag)
	{
		FNodeCoordinate source;
		FNodeCoordinate target;

		// source
		if (WorldPosToRegionPos(StartPathFlag.Position, source.x, source.y) == false)
		{
			pathfindresult.Result = FR_Error;
			return pathfindresult;
		}
		// target
		if (WorldPosToRegionPos(DestPathFlag.Position, target.x, target.y) == false)
		{
			pathfindresult.Result = FR_Error;
			return pathfindresult;
		}

		// step	1.
		// find normal path
		FAStarNode* current = nullptr;
		std::set<FAStarNode*> openSet, closedSet;
		openSet.insert(new FAStarNode(source, &StartPathFlag));

		while (!openSet.empty())
		{
			current = *openSet.begin();
			for (auto node : openSet)
			{
				if (node->GetScore() <= current->GetScore())
				{
					current = node;
				}
			}

			if (current->cooridnates == target)
			{
				break;
			}

			closedSet.insert(current);
			openSet.erase(std::find(openSet.begin(), openSet.end(), current));

			for (int i = 0; i < g_FindDirections; i++)
			{
				FNodeCoordinate newcoordi =
				{
					current->cooridnates.x + g_Direction[i].x,
					current->cooridnates.y + g_Direction[i].y,
				};

				// check available region and path flag
				if (g_FindNodeOnList(closedSet, newcoordi))
				{
					continue;
				}

				FRegion* reg = GetRegionPtr(newcoordi.x, newcoordi.y);
				if (reg == nullptr)
				{
					continue;
				}
				if (reg->TotalPathFlags == 0)
				{
					continue;
				}

				// for debug check
				bool processed = false;

				// experimental. we add all flags
				// check connection	
				for (int p = 0; p < reg->TotalPathFlags; p++)
				{
					FPathFlag* pf = &(reg->PathFlags[p]);
					FPathFlagInfo* pfi = GetPathFlagInfoPtr(current->PathFlag->Position, pf->Position);
					if (pfi == nullptr)
					{
						continue;
					}

					// calculate cost by 4-way or 8-way movement
					int totalCost = current->G + ((i < 4) ? 10 : 14) + pfi->TotalPathList;

					//FAStarNode* successor = g_FindNodeOnList(openSet, newcoordi);
					FAStarNode* successor = g_FindNodeOnList(openSet, newcoordi, *pf);
					if (successor == nullptr)
					{
						successor = new FAStarNode(newcoordi, pf, current);
						successor->G = totalCost;
						successor->H = g_Heuristic(successor->cooridnates, target);
						openSet.insert(successor);
					}
					else if (totalCost < successor->G)
					{
						successor->parent = current;
						successor->G = totalCost;
					}

					processed = true;
				}

				if (processed == false)
				{
					// there's no connection detected in this region. may data problem.
					int justbreakhere = 0;
				}
			}
		}

		// step 2.
		// do we find destination's path flag exactly ?
		if (current != nullptr)
		{
			if (current->PathFlag == nullptr ||
				g_IsSamePosition(DestPathFlag.Position, current->PathFlag->Position) == false)
			{
				pathfindresult.Result = FR_Error;
				pathfindresult.PathList.empty();
				return pathfindresult;
			}

		}

		while (current != nullptr)
		{
			pathfindresult.PathFlagList.insert(pathfindresult.PathFlagList.begin(), current->PathFlag);
			current = current->parent;
		}

		g_ReleaseNodes(openSet);
		g_ReleaseNodes(closedSet);

		pathfindresult.Result = FR_Success;
		return pathfindresult;
	}*/

	FPathFindResult FAStarMap::FindPathFlagPathList(FPathFlag &StartPathFlag, FPathFlag &DestPathFlag)
	{
		const int INF = 0x7FFFFFFF;

		FPathFindResult pathfindresult;
		pathfindresult.Result = FR_Error;

		int StartIndex = StartPathFlag.index;
		int EndIndex = DestPathFlag.index;
		if (StartIndex == INVALID_INDEX || EndIndex == INVALID_INDEX || StartIndex == EndIndex)
		{
			return pathfindresult;
		}

		std::vector<int> dist(TotalPathFlags_, INF);
		std::priority_queue<std::pair<int, int>> PriorityQueue;
		std::map<int, std::pair<int, int>> Map;

		PriorityQueue.push(std::make_pair(0, StartIndex));
		dist[StartIndex] = 0;

		Map.insert(std::make_pair(StartIndex, std::make_pair(0, INF)));

		while (PriorityQueue.empty() == false)
		{
			//int cost = -PriorityQueue.top().first;
			int target = PriorityQueue.top().second;
			PriorityQueue.pop();

			for (int i = 0; i < (int)PathPointCost_[target].size(); i++)
			{
				int next = PathPointCost_[target][i].first;
				int nextcost = PathPointCost_[target][i].second;

				if (dist[next] > dist[target] + nextcost)
				{
					dist[next] = dist[target] + nextcost;
					PriorityQueue.push(std::make_pair(-dist[next], next));

					Map[next] = std::make_pair(dist[next], target);
				}
			}
		}

		// get result list
		if (dist[EndIndex] != INF)
		{
			int next = Map[EndIndex].second;
			while (next != INF)
			{
				pathfindresult.PathFlagList.insert(pathfindresult.PathFlagList.begin(), (PathFlags_ + next));
				next = Map[next].second;
			}

			// add last end index
			pathfindresult.PathFlagList.push_back((PathFlags_ + EndIndex));

			pathfindresult.Result = FR_Success;
		}

		return pathfindresult;
	}

	FPathFindResult FAStarMap::FindPathFlagPathList(const float *StartLoc, const float *EndLoc)
	{
		// const int INF = 0x7FFFFFFF;

		FPathFindResult pathfindresult;
		pathfindresult.Result = FR_Error;
		ATTR BlockAttribute = ATTR_BLOCK;

		FPathFlag* startpathflag = FindNearestPathFlag(StartLoc, BlockAttribute);
		if (startpathflag == nullptr)
		{
			return pathfindresult;
		}

		FPathFlag* endpathflag = FindNearestPathFlag(EndLoc, BlockAttribute);
		if (endpathflag == nullptr)
		{
			return pathfindresult;
		}

		return FindPathFlagPathList(*startpathflag, *endpathflag);
	}

	bool FAStarMap::FindExpandedPathList(std::vector<FNodeCoordinate>& BasePathList, std::vector<FNodeCoordinate>& ResultPathList, std::vector<FNodeCoordinate>& IgnorePathList, bool bUseRightDirection, int DistanceFromBasePath)
	{
		// exception handling code. skip calculation if distance is zero
		if (DistanceFromBasePath == 0)
		{
			ResultPathList.clear();

			for (int i = 0; i < (int)BasePathList.size(); i++)
			{
				ResultPathList.push_back(BasePathList[i]);
			}

			return true;
		}

		std::vector<FNodeCoordinate> remove_point_list;

		for (int i = 0; i < (int)BasePathList.size(); ++i)
		{
			std::vector<CSCommon::FNodeCoordinate> path_list;
			CSCommon::FNodeCoordinate pre_point;
			pre_point.x = 0;
			pre_point.y = 0;
			if (i > 0)
			{
				pre_point.x = BasePathList[i - 1].x;
				pre_point.y = BasePathList[i - 1].y;
			}
			path_list.push_back(pre_point);

			CSCommon::FNodeCoordinate cur_point;
			cur_point.x = BasePathList[i].x;
			cur_point.y = BasePathList[i].y;
			path_list.push_back(cur_point);

			if (i + 1 < (int)BasePathList.size())
			{
				CSCommon::FNodeCoordinate next_point;
				next_point.x = BasePathList[i + 1].x;
				next_point.y = BasePathList[i + 1].y;
				path_list.push_back(next_point);
			}

			std::vector<CSCommon::FNodeCoordinate> add;
			std::vector<CSCommon::FNodeCoordinate> remove;

			if (FindExpandedPathPoint(path_list, bUseRightDirection, ResultPathList, add, remove))
			{
				for (int j = 0; j < (int)add.size(); ++j)
				{
					if(std::find(ResultPathList.begin(), ResultPathList.end(), add[j]) == ResultPathList.end())
					{
						ResultPathList.push_back(add[j]);
					}
				}

				for (int j = 0; j < (int)remove.size(); ++j)
				{
					if (std::find(remove_point_list.begin(), remove_point_list.end(), remove[j]) == remove_point_list.end())
					{
						remove_point_list.push_back(remove[j]);
					}
				}
			}
			else
			{
				return false;
			}
		}

		for (int i = 0; i < (int)remove_point_list.size(); ++i)
		{
			std::vector<FNodeCoordinate>::iterator itor = std::find(ResultPathList.begin(), ResultPathList.end(), remove_point_list[i]);

			if (itor != ResultPathList.end())
			{
				ResultPathList.erase(itor);
			}
		}

		for (int i = 0; i < (int)IgnorePathList.size(); ++i)
		{
			std::vector<FNodeCoordinate>::iterator itor = std::find(ResultPathList.begin(), ResultPathList.end(), IgnorePathList[i]);

			if (itor != ResultPathList.end())
			{
				ResultPathList.erase(itor);
			}
		}

		// 2. add or remove
		int total_path_list = (int)ResultPathList.size();
		std::vector<FNodeCoordinate>::iterator path_itor;

		for (int i = 0; i < total_path_list - 1; ++i)
		{
			path_itor = ResultPathList.begin() + i;

			int size = std::abs(ResultPathList[i].x - ResultPathList[i + 1].x) + std::abs(ResultPathList[i].y - ResultPathList[i + 1].y);
			if (size > 3)
			{
				FNodeCoordinate cal_dir;
				cal_dir.x = 1;
				cal_dir.y = 1;
				if (ResultPathList[i].x > ResultPathList[i + 1].x)
				{
					cal_dir.x = -1;
				}
				if (ResultPathList[i].y > ResultPathList[i + 1].y)
				{
					cal_dir.y = -1;
				}

				cal_dir.x += ResultPathList[i].x;
				cal_dir.y += ResultPathList[i].y;

				ResultPathList.insert(path_itor + 1, cal_dir);
				total_path_list += 1;
			}

			if (std::find(BasePathList.begin(), BasePathList.end(), ResultPathList[i]) != BasePathList.end())
			{
				ResultPathList.erase(std::find(ResultPathList.begin(), ResultPathList.end(), ResultPathList[i]));
				--i;
				--total_path_list;
			}
		}

		if (DistanceFromBasePath > 1)
		{
			for (int i = 0; i < (int)BasePathList.size(); ++i)
			{
				IgnorePathList.push_back(BasePathList[i]);
			}

			std::vector<FNodeCoordinate> clone_base_path_list;

			for (int i = 0; i < (int)ResultPathList.size(); ++i)
			{
				clone_base_path_list.push_back(ResultPathList[i]);
			}
			ResultPathList.clear();

			FindExpandedPathList(clone_base_path_list, ResultPathList, IgnorePathList, bUseRightDirection, DistanceFromBasePath - 1);
		}

		return true;
	}

	bool FAStarMap::FindExpandedPathPoint(const std::vector<FNodeCoordinate>& PathList, bool bUseRightDirection, const std::vector<FNodeCoordinate>& ResultPathList, std::vector<FNodeCoordinate>& AddPoint, std::vector<FNodeCoordinate>& RemovePoint)
	{
		if (PathList.size() < 2)
		{
			return false;
		}

		FNodeCoordinate start_point = FNodeCoordinate();
		start_point.x = 0;
		start_point.y = 0;
		FNodeCoordinate end_point = FNodeCoordinate();
		end_point.x = 0;
		end_point.y = 0;
		bool is_end_point = false;

		if (PathList.size() == 3)
		{
			start_point = PathList[1];
			end_point = PathList[2];
		}
		else
		{
			start_point = PathList[0];
			end_point = PathList[1];
			is_end_point = true;
		}

		// int right = 0, left = 0, top = 0, bottom = 0;
		int sign = (bUseRightDirection == true) ? 1 : -1;

		if (start_point.x != end_point.x)
		{
			if (start_point.x < end_point.x)
			{
				// right
				// right = 1;

				FNodeCoordinate add_point = FNodeCoordinate();
				add_point.x = start_point.x;
				add_point.y = start_point.y + sign;

				AddPoint.push_back(add_point);

				FNodeCoordinate remove_point = FNodeCoordinate();
				remove_point.x = start_point.x;
				remove_point.y = start_point.y - sign;

				RemovePoint.push_back(remove_point);
			}
			else
			{
				// left
				// left = 1;

				FNodeCoordinate add_point = FNodeCoordinate();
				add_point.x = start_point.x;
				add_point.y = start_point.y - sign;

				AddPoint.push_back(add_point);

				FNodeCoordinate remove_point = FNodeCoordinate();
				remove_point.x = start_point.x;
				remove_point.y = start_point.y + sign;

				RemovePoint.push_back(remove_point);
			}
		}

		if (start_point.y != end_point.y)
		{
			if (start_point.y < end_point.y)
			{
				// bottom
				// bottom = 1;

				FNodeCoordinate add_point = FNodeCoordinate();
				add_point.x = start_point.x - sign;
				add_point.y = start_point.y;

				AddPoint.push_back(add_point);

				FNodeCoordinate remove_point = FNodeCoordinate();
				remove_point.x = start_point.x + sign;
				remove_point.y = start_point.y;

				RemovePoint.push_back(remove_point);
			}
			else
			{
				// top
				// top = 1;

				FNodeCoordinate add_point = FNodeCoordinate();
				add_point.x = start_point.x + sign;
				add_point.y = start_point.y;

				AddPoint.push_back(add_point);

				FNodeCoordinate remove_point = FNodeCoordinate();
				remove_point.x = start_point.x - sign;
				remove_point.y = start_point.y;

				RemovePoint.push_back(remove_point);
			}
		}

		// add endpoint
		if (is_end_point == true)
		{
			std::vector<FNodeCoordinate> add_end_point = std::vector<FNodeCoordinate>(AddPoint);
			std::vector<FNodeCoordinate> remove_end_point = std::vector<FNodeCoordinate>(RemovePoint);

			for (int i = 0; i < (int)add_end_point.size(); ++i)
			{
				add_end_point[i].x = add_end_point[i].x - start_point.x + end_point.x;
				add_end_point[i].y = add_end_point[i].y - start_point.y + end_point.y;
				remove_end_point[i].x = remove_end_point[i].x - start_point.x + end_point.x;
				remove_end_point[i].y = remove_end_point[i].y - start_point.y + end_point.y;

				AddPoint.push_back(add_end_point[i]);
				RemovePoint.push_back(remove_end_point[i]);
			}
		}

		if (ResultPathList.size() > 0 && AddPoint.size() > 1)
		{
			int last_index = (int)ResultPathList.size() - 1;

			int size = std::abs(AddPoint[0].x - ResultPathList[last_index].x) + std::abs(AddPoint[0].y - ResultPathList[last_index].y);
			if (size > 2)
			{
				std::vector<FNodeCoordinate> add_temp_point = std::vector<FNodeCoordinate>(AddPoint);
				AddPoint.clear();
				AddPoint.push_back(add_temp_point[1]);
				AddPoint.push_back(add_temp_point[0]);
			}
		}

		return true;
	}

	void FAStarMap::MakePathPointCost()
	{
		PathPointCost_.clear();
		if (TotalPathFlagInfo_ == 0 || TotalPathFlags_ == 0)
		{
			return;
		}
		//PathPointCost_.resize(TotalPathFlags_);
		PathPointCost_.resize(GetNextPathFlagIndex());

		for (int i = 0; i < TotalPathFlagInfo_; i++)
		{
			int index_v1, index_v2, cost;
			index_v1 = PathFlagInfo_[i].index_v1;
			index_v2 = PathFlagInfo_[i].index_v2;
			cost = PathFlagInfo_[i].Cost;

			if (index_v1 != INVALID_INDEX)
			{
				PathPointCost_[index_v1].push_back(std::make_pair(index_v2, cost));
			}
			if (index_v2 != INVALID_INDEX)
			{
				PathPointCost_[index_v2].push_back(std::make_pair(index_v1, cost));
			}
		}
	}

	int FAStarMap::CalculatePathFlagTotalCost(FPathFindResult Result)
	{
		int TotalCost = 0;

		if (Result.PathFlagList.size() > 1)
		{
			for (int i = 0; i < static_cast<int32_t>(Result.PathFlagList.size()) - 1; i++)
			{
				FPathFlagInfo* pinfo = GetPathFlagInfoPtr(Result.PathFlagList[i]->Position, Result.PathFlagList[i + 1]->Position);
				if (pinfo != nullptr)
				{
					TotalCost += pinfo->Cost;
				}
			}
		}

		return TotalCost;
	}

	FPathFindResult FAStarMap::GetFullPath(const float *StartLoc, const float *EndLoc)
	{
		FPathFindResult pathfindresult;
		FNodeCoordinate node;
		int TotalCost = 0;
		ATTR testAttribute = ATTR_BLOCK;

		// Step 1. skip if necessary
		CSCommon::FPathFlag *StartPathFlag = FindNearestPathFlag(StartLoc, testAttribute);
		CSCommon::FPathFlag *DestPathFlag = FindNearestPathFlag(EndLoc, testAttribute);
		if (StartPathFlag == nullptr || DestPathFlag == nullptr)
		{
			pathfindresult.Result = FR_Error;
		}
		else if (StartPathFlag->index == DestPathFlag->index)
		{
			pathfindresult.Result = FR_Error;
		}
		else
		{
			// Step 2. get path flag list
			pathfindresult = FindPathFlagPathList(*StartPathFlag, *DestPathFlag);

			if (pathfindresult.PathFlagList.size() == 1)
			{
				pathfindresult.Result = FR_Error;
			}
		}

		// Step 3. process error
		if (pathfindresult.Result == FR_Error)
		{
			// delete exist and set only start and end position
			pathfindresult.PathList.clear();

			FNodeCoordinate start;
			WorldPosToCellPos(StartLoc, start.x, start.y);
			pathfindresult.PathList.push_back(start);

			FNodeCoordinate end;
			WorldPosToCellPos(EndLoc, end.x, end.y);
			pathfindresult.PathList.push_back(end);

			return pathfindresult;
		}

		// Step 4. find shortcut at start position. first or second path flag
		int ErrorDist = 9999999;
		float* curpos;
		float* pos1 = pathfindresult.PathFlagList[0]->Position;
		float* pos2 = pathfindresult.PathFlagList[1]->Position;
		int dist1, dist2;
		ATTR attribute = ATTR_BLOCK;
		FPathFindResult result;

		// check start position is same with path flag position
		bool testresult = false;
		// this function always returns true.
		CheckIsSameCell(StartLoc, pos1, testresult);
		if (testresult == false)
		{
			// to pos 1
			result = FindPath(StartLoc, pos1, attribute);
			if (result.Result == FR_Error)
			{
				dist1 = ErrorDist;
			}
			else
			{
				dist1 = CalculatePathListTotalCost(result.PathList);//(int)result.PathList.size();

				// add pos1 to pos2 distance
				result = FindPath(pos1, pos2, attribute);
				if (result.Result == FR_Error)
				{
					dist1 += ErrorDist;
				}
				else
				{
					//dist1 += (int)result.PathList.size() - 1;
					dist1 += CalculatePathListTotalCost(result.PathList);
					dist1 -= CalculatePathDistance(result.PathList[result.PathList.size() - 2], result.PathList[result.PathList.size() - 1]);
				}
			}

			// to pos 2
			result = FindPath(StartLoc, pos2, attribute);
			if (result.Result == FR_Error)
			{
				dist2 = ErrorDist;
			}
			else
			{
				dist2 = CalculatePathListTotalCost(result.PathList);//(int)result.PathList.size();
			}

			if (dist1 >= dist2)
			{
				// we'd better to go pathflaglist[1] (pos2) directly
				// remove first path flag
				pathfindresult.PathFlagList.erase(pathfindresult.PathFlagList.begin());
				TotalCost += dist2;
			}
			else
			{
				TotalCost += dist1;
			}

			// set start path
			WorldPosToCellPos(StartLoc, node.x, node.y);
			pathfindresult.PathList.insert(pathfindresult.PathList.begin(), node);
		}

		// Step 5. find short at end position. last or last-1 path flag
		if (pathfindresult.PathFlagList.size() >= 2)
		{
			curpos = pathfindresult.PathFlagList[pathfindresult.PathFlagList.size() - 2]->Position;

			pos1 = pathfindresult.PathFlagList[pathfindresult.PathFlagList.size() - 1]->Position;
			pos2 = (float *)EndLoc;

			// this function always returns true.
			CheckIsSameCell(EndLoc, pos1, testresult);
			if (testresult == false)
			{
				result = FindPath(curpos, pos1, attribute);
				if (result.Result == CSCommon::FR_Error)
				{
					dist1 = ErrorDist;
				}
				else
				{
					dist1 = CalculatePathListTotalCost(result.PathList);//(int)result.PathList.size();

					// add pos1 to pos2 distance
					result = FindPath(pos1, pos2, attribute);
					if (result.Result == CSCommon::FR_Error)
					{
						dist1 += ErrorDist;
					}
					else
					{
						//dist1 += (int)result.PathList.size() - 1;
						dist1 += CalculatePathListTotalCost(result.PathList);
						dist1 -= CalculatePathDistance(result.PathList[result.PathList.size() - 2], result.PathList[result.PathList.size() - 1]);
					}
				}
				result = FindPath(curpos, pos2, attribute);
				if (result.Result == CSCommon::FR_Error)
				{
					dist2 = ErrorDist;
				}
				else
				{
					dist2 = CalculatePathListTotalCost(result.PathList);//(int)result.PathList.size();
				}

				if (dist1 > dist2)
				{
					// skip use last flag
					// we'd better to go goal dest directly.
					// remove lastflag
					pathfindresult.PathFlagList.pop_back();

					TotalCost += dist2;
				}
				else
				{
					TotalCost += dist1;
				}
			}
		}
		else
		{
			// TODO, go without using path flag point? check it
		}

		// Step 6. convert coordinate
		for (int i = 0; i < static_cast<int32_t>(pathfindresult.PathFlagList.size()); i++)
		{
			FNodeCoordinate point;
			WorldPosToCellPos(pathfindresult.PathFlagList[i]->Position, point.x, point.y);
			pathfindresult.PathList.push_back(point);

			if (i < static_cast<int32_t>(pathfindresult.PathFlagList.size()) - 1)
			{
				FPathFlagInfo* pinfo = GetPathFlagInfoPtr(pathfindresult.PathFlagList[i]->Position, pathfindresult.PathFlagList[i + 1]->Position);
				if (pinfo != nullptr)
				{
					TotalCost += pinfo->Cost;
				}
			}
		}

		pathfindresult.TotalCost = TotalCost;

		return pathfindresult;
	}
}
