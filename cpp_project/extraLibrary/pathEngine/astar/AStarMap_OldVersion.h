#pragma once

// A-Star Library Old Version classes / structures 

#include "AStarMap.h"

namespace CSCommon
{
	// added 2019/10/29
	struct FCellCameraData_V5
	{
		float distance;		// camera distance
		float rot[2];		// camera rotation x / y
	};

	struct FCellCameraData_V7
	{
		float distance_pc;		// camera distance
		float distance_mobile;	// mobile camera distance
		float rot[2];			// camera rotation x / y
	};
	
	// 2022/01/21 variable naming change
	struct FCellCameraData_UNION
	{
		union
		{
			float distance_pc;
			float tile_rotation_speed;
		};

		union
		{
			float distance_mobile;
			float tile_reset_time;
		};

		float rot[2];			// camera rotation x / y

		int action_type;		// action type (2021.12.17)
	};

	struct FCellCameraData_V8_1
	{
		float distance_pc;		// camera distance
		float distance_mobile;	// mobile camera distance

		float rot[2];			// camera rotation x / y

		int action_type;		// action type (2021.12.17)
	};

	struct FCell_V1
	{
		OLD_ATTR attr;					// attribute
		float center_height;			// center height
		FNodeCoordinate coordinates;	// coordinate

		union
		{
			// distance value current cetner from neighborhood.
			// value is zero if neighborhood does not exist
			float* neighbor_distance;	// Clock Wise (N/NE/E/SE/S/SW/W/NW)
			//int* neighbor_access;		// Clock Wise (N/NE/E/SE/S/SW/W/NW)	// unused 2019.06.17
		};
	};

	struct FCell_V2 : public FCellBase
	{
		OLD_ATTR attr;						// attribute
		float center_height;			// center height

		union
		{
			// distance value current cetner from neighborhood.
			// value is zero if neighborhood does not exist
			// server use only
			float* neighbor_distance;	// Clock Wise (N/NE/E/SE/S/SW/W/NW)
		};

		// client use only
		std::vector<FCellAttribute> BlockAttrList;
	};

	struct FCell_V4 : public FCellBase
	{
		ATTR attr;						// attribute
		float center_height;			// center height

		// distance value current cetner from neighborhood.
		// value is zero if neighborhood does not exist
		// server use only - 8 bytes
		float* neighbor_distance;	// Clock Wise (N/NE/E/SE/S/SW/W/NW)

		// ground material number
		// client use only - 2 bytes
		ATTR_NUM GroundMaterialNum;

		// client use only
		std::vector<FCellAttribute> BlockAttrList;
		std::vector<int64_t> DropItemList;
	};

	struct FCell_V5 : public FCellBase
	{
		ATTR attr;						// attribute
		float center_height;			// center height

		// distance value current cetner from neighborhood.
		// value is zero if neighborhood does not exist
		// server use only - 8 bytes
		float* neighbor_distance;	// Clock Wise (N/NE/E/SE/S/SW/W/NW)

		// ground material number
		// client use only - 2 bytes
		ATTR_NUM GroundMaterialNum;

		// client use only - v5
		CAMERA_TYPE CameraDataType;
		FCellCameraData_V5* CameraData;

		// client use only - unsaved data
		std::vector<FCellAttribute> BlockAttrList;
		std::vector<int64_t> DropItemList;
	};

	struct FCell_V6 : public FCellBase
	{
		ATTR attr;						// attribute
		float center_height;			// center height

		// distance value current cetner from neighborhood.
		// value is zero if neighborhood does not exist
		// server use only - 8 bytes
		float* neighbor_distance;	// Clock Wise (N/NE/E/SE/S/SW/W/NW)

		// ground material number
		// client use only - 2 bytes
		ATTR_NUM GroundMaterialNum;

		// client use only - v5
		CAMERA_TYPE CameraDataType;
		FCellCameraData_V5* CameraData;

		// client use only - v6
		ATTR_NUM SWAreaNum;

		// client use only - unsaved data
		std::vector<FCellAttribute> BlockAttrList;
		std::vector<int64_t> DropItemList;
	};

	struct FPathFlagInfo_V2
	{
		unsigned int id;			// internal use (for load/save)

		float v1[3];
		float v2[3];

		int TotalPathList;
		FNodeCoordinate* ToPathList;

		// halfway point index of ToPathList(boundary point)
		// unused : INVALID_INDEX (-1)
		int HalfWayPointIndex;

		// path expansion flag
		bool PathExpLeft[MAX_PATH_EXPANSION];
		bool PathExpRight[MAX_PATH_EXPANSION];
	};

	struct FPathFlag_V1
	{
		int index;

		float Position[3];		// world coordinates

		int TotalNeighborFlagList;
		int* NeighborFlagIndexList;
		FPathFlagInfo** NeighborFlagList;	// linked neighbor list

		int GetNeighborFlagIndex(float* pos, bool &IsReverse)
		{
			if (NeighborFlagList == nullptr)
			{
				return INVALID_INDEX;
			}

			for (int i = 0; i < TotalNeighborFlagList; i++)
			{
				if (g_IsSamePosition(NeighborFlagList[i]->v1, pos))
				{
					IsReverse = true;
					return i;
				}

				if (g_IsSamePosition(NeighborFlagList[i]->v2, pos))
				{
					IsReverse = false;
					return i;
				}
			}

			return INVALID_INDEX;
		}
	};
}
