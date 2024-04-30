#include "stdafx.h"
#include "AStarMap.h"
#include <chrono>

//#define SHOW_UDEBUG_ASTARMAP

#ifdef SHOW_UDEBUG_ASTARMAP
#include "MirLogManager.h"
#include "DrawDebugHelpers.h"
#endif


namespace CSCommon
{
	int g_FindDirections = 8;
	FNodeCoordinate g_Direction[] =
	{
		{ 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 },
		{ -1, -1 },{ 1, 1 },{ -1, 1 },{ 1, -1 }
	};

	FNodeCoordinate g_CWDirection4[] =
	{
		{ 0, -1 }, // N
		{ 1, 0 }, // E
		{ 0, 1 }, // S
		{ -1, 0 }, // W 
	};
	FNodeCoordinate g_CWDirection8[] =
	{
		{ 0, -1 }, // N
		{ 1, -1 }, // NE
		{ 1, 0 }, // E
		{ 1, 1 }, // SE
		{ 0, 1 }, // S
		{ -1, 1 }, // SW
		{ -1, 0 }, // W 
		{ -1, -1 }, // NW
	};
	FNodeCoordinate g_CWDirectionDiagonal[] =
	{
		{ 1, -1 }, // NE
		{ 1, 1 }, // SE
		{ -1, 1 }, // SW
		{ -1, -1 }, // NW
	};

	FNodeCoordinate* g_CWDirection = g_CWDirection8;

	std::function<int(FNodeCoordinate, FNodeCoordinate)> g_Heuristic = FHeuristic::euclidean;

	void g_SetDiagonalMovement(bool enable)
	{
		g_FindDirections = (enable) ? 8 : 4;
		g_CWDirection = (enable) ? g_CWDirection8 : g_CWDirection4;

		// remark. if you must recalculate neighbor distance to prevent memory access violation.
	}

	std::function<int(FNodeCoordinate, FNodeCoordinate)> g_GetHeuristic()
	{
		return g_Heuristic;
	}

	void g_SetHeuristic(std::function<int(FNodeCoordinate, FNodeCoordinate)> heuristic)
	{
		g_Heuristic = std::bind(heuristic, std::placeholders::_1, std::placeholders::_2);
	}

	int g_CalcDistSquaredXY(int x1, int y1, int x2, int y2)
	{
		return ((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	}

	float g_CalcDistSquaredXY(const float* v1, const float* v2)
	{
		return ((v2[0] - v1[0])*(v2[0] - v1[0]) +
			(v2[1] - v1[1])*(v2[1] - v1[1]));
	}

	float g_CalcDistSquared(const float* v1, const float* v2)
	{
		return ((v2[0] - v1[0])*(v2[0] - v1[0]) +
			(v2[1] - v1[1])*(v2[1] - v1[1]) +
			(v2[2] - v1[2])*(v2[2] - v1[2]));
	}

	bool g_IsSamePosition(const float* v1, const float* v2)
	{
		// we allow less than 0.1f error value
		if (g_CalcDistSquared(v1, v2) <= 0.1f)
		{
			return true;
		}

		return false;
	}

	bool g_IsSamePositionXY(const float* v1, const float* v2)
	{
		// we allow less than 0.1f error value
		if (g_CalcDistSquaredXY(v1, v2) <= 0.1f)
		{
			return true;
		}

		return false;
	}

	bool g_IsNeighbor(int sx, int sy, int dx, int dy)
	{
		FNodeCoordinate destcoordi = { dx, dy };

		for (int i = 0; i < g_FindDirections; i++)
		{
			FNodeCoordinate newcoordi =
			{
				sx + g_CWDirection[i].x,
				sy + g_CWDirection[i].y,
			};

			if (newcoordi == destcoordi)
			{
				return true;
			}
		}

		return false;
	}

	bool g_IsDiagonalNeighbor(int sx, int sy, int dx, int dy)
	{
		FNodeCoordinate destcoordi = { dx, dy };

		for (int i = 0; i < 4; i++)
		{
			FNodeCoordinate newcoordi =
			{
				sx + g_CWDirectionDiagonal[i].x,
				sy + g_CWDirectionDiagonal[i].y,
			};

			if (newcoordi == destcoordi)
			{
				return true;
			}
		}

		return false;
	}

	void g_InitializeAStarLib()
	{
		g_SetDiagonalMovement(true);
		//g_SetHeuristic(FHeuristic::chebyshev);
		g_SetHeuristic(FHeuristic::manhattan);
	}

	// from bresenham algorithm
	std::vector<FNodeCoordinate> g_GetLinePointList(FNodeCoordinate v1, FNodeCoordinate v2)
	{
		return g_GetLinePointList(v1.x, v1.y, v2.x, v2.y);
	}

	std::vector<FNodeCoordinate> g_GetLinePointList(int x1, int y1, int x2, int y2)
	{
		std::vector<FNodeCoordinate> path;
		path.clear();

		int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
		dx = x2 - x1;
		dy = y2 - y1;
		dx1 = abs(dx);
		dy1 = abs(dy);
		px = 2 * dy1 - dx1;
		py = 2 * dx1 - dy1;

		FNodeCoordinate pos;
		bool normaladd = true;

		if (dy1 <= dx1)
		{
			if (dx >= 0)
			{
				x = x1;
				y = y1;
				xe = x2;
				normaladd = true;
			}
			else
			{
				x = x2;
				y = y2;
				xe = x1;
				normaladd = false;
			}

			pos = { x, y };
			path.push_back(pos);

			for (i = 0; x < xe; i++)
			{
				x = x + 1;
				if (px < 0)
				{
					px = px + 2 * dy1;
				}
				else
				{
					if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
					{
						y = y + 1;
					}
					else
					{
						y = y - 1;
					}
					px = px + 2 * (dy1 - dx1);
				}

				pos = { x, y };
				if (normaladd)
				{
					path.push_back(pos);
				}
				else
				{
					path.insert(path.begin(), pos);
				}
			}
		}
		else
		{
			if (dy >= 0)
			{
				x = x1;
				y = y1;
				ye = y2;
				normaladd = true;
			}
			else
			{
				x = x2;
				y = y2;
				ye = y1;
				normaladd = false;
			}

			pos = { x, y };
			path.push_back(pos);

			for (i = 0; y < ye; i++)
			{
				y = y + 1;
				if (py <= 0)
				{
					py = py + 2 * dx1;
				}
				else
				{
					if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
					{
						x = x + 1;
					}
					else
					{
						x = x - 1;
					}
					py = py + 2 * (dx1 - dy1);
				}

				pos = { x, y };
				if (normaladd)
				{
					path.push_back(pos);
				}
				else
				{
					path.insert(path.begin(), pos);
				}
			}
		}

		return path;
	}

	//struct FAStarNode
	//{
	//	int G, H;
	//	FNodeCoordinate coordinates;

	//	FAStarNode* parent;

	//	FAStarNode(FNodeCoordinate coordi, FAStarNode *parent_ = nullptr);
	//	int GetScore();
	//};

	FAStarNode::FAStarNode(FNodeCoordinate coordi, FAStarNode *parent_)
	{
		coordinates = coordi;
		parent = parent_;
		G = 0;
		H = 0;
		PathFlag = nullptr;
	}

	FAStarNode::FAStarNode(FNodeCoordinate coordi, FPathFlag* PathFlag_, FAStarNode *parent_)
	{
		coordinates = coordi;
		parent = parent_;
		G = 0;
		H = 0;
		PathFlag = PathFlag_;
	}

	int FAStarNode::GetScore()
	{
		return G + H;
	}

	FAStarNode* g_FindNodeOnList(std::set<FAStarNode*>& Nodes, FNodeCoordinate coordi)
	{
		for (auto node : Nodes)
		{
			if (node->coordinates == coordi)
			{
				return node;
			}
		}

		return nullptr;
	}

	FAStarNode* g_FindNodeOnList(std::set<FAStarNode*>& Nodes, FNodeCoordinate coordi, FPathFlag &PathFlag)
	{
		for (auto node : Nodes)
		{
			if (node->coordinates == coordi)
			{
				if (node->PathFlag != nullptr)
				{
					if (g_IsSamePosition(node->PathFlag->Position, PathFlag.Position))
					{
						return node;
					}
				}
			}
		}

		return nullptr;
	}

	void g_ReleaseNodes(std::set<FAStarNode*>& Nodes)
	{
		for (auto it = Nodes.begin(); it != Nodes.end();)
		{
			delete *it;
			it = Nodes.erase(it);
		}
	}

	FNodeCoordinate FHeuristic::getDelta(FNodeCoordinate source_, FNodeCoordinate target_)
	{
		return{ abs(source_.x - target_.x),  abs(source_.y - target_.y) };
	}

	int FHeuristic::manhattan(FNodeCoordinate source_, FNodeCoordinate target_)
	{
		//auto delta = std::move(getDelta(source_, target_));
		FNodeCoordinate delta = getDelta(source_, target_);
		return static_cast<int>(10 * (delta.x + delta.y));
	}

	int FHeuristic::euclidean(FNodeCoordinate source_, FNodeCoordinate target_)
	{
		//auto delta = std::move(getDelta(source_, target_));
		FNodeCoordinate delta = getDelta(source_, target_);
		return static_cast<int>(10 * sqrt(pow(delta.x, 2) + pow(delta.y, 2)));
	}

	int FHeuristic::octagonal(FNodeCoordinate source_, FNodeCoordinate target_)
	{
		//auto delta = std::move(getDelta(source_, target_));
		FNodeCoordinate delta = getDelta(source_, target_);
		return 10 * (delta.x + delta.y) + (-6) * std::min(delta.x, delta.y);
	}

	int FHeuristic::chebyshev(FNodeCoordinate source_, FNodeCoordinate target_)
	{
		//auto delta = std::move(getDelta(source_, target_));
		FNodeCoordinate delta = getDelta(source_, target_);
		return static_cast<int>(10 * std::max(delta.x, delta.y));
	}

	FAStarMap::FAStarMap()
	{
#ifdef SERVER_USE
		InitServer();
#endif	// SERVER_USE

		WorldCell_ = nullptr;

		TotalCellCountX_ = 0;
		TotalCellCountY_ = 0;

		StartCellX_ = 0;
		StartCellY_ = 0;

		CELL_SIZE_X_ = 0;
		CELL_SIZE_Y_ = 0;

		NeighborDirCount_ = 0;

		PathFlagInfo_ = nullptr;
		PathFlags_ = nullptr;
		Region_ = nullptr;

		TotalPathFlagInfo_ = 0;
		NextPathFlagInfoId_ = 0;
		TotalRegionCountX_ = 0;
		TotalRegionCountY_ = 0;

		REGION_SIZE_X_ = 0;
		REGION_SIZE_Y_ = 0;
	}

	FAStarMap::~FAStarMap()
	{
		DestroyAll();
	}

	// initialize
	void FAStarMap::InitializeCell(FCell* Cell)
	{
		Cell->center_height = 0.0f;

		// set xy index
		Cell->coordinates.x = 0;
		Cell->coordinates.y = 0;
		Cell->IsValid = true;

		Cell->attr = ATTR_UNUSED;

		Cell->neighbor_distance = nullptr;
		Cell->GroundMaterialNum = ATTR_GNDMTRL_DEFAULT;
		Cell->BlockAttrList.clear();

		Cell->CameraDataType = CAMERATYPE_NONE;
		Cell->CameraData = nullptr;

		Cell->SWAreaNum = ATTR_SW_AREA_NONE;
		Cell->BlockAttrList.clear();
	}

	void FAStarMap::DestroyAll()
	{
		DestroyRegion();
		DestroyCell();

#ifdef SERVER_USE
		DestroyServer();
#endif	// SERVER_USE
	}

	void FAStarMap::DestroyCell()
	{
		if (WorldCell_ != nullptr)
		{
			FCell* cell;
			for (int i = 0; i < GetTotalCellCount(); i++)
			{
				cell = GetCellPtr(i);
				if (cell != nullptr)
				{
					DestroyCell(cell);
					delete cell;
				}
				else
				{
					// delete cell base pointer manually
					delete WorldCell_[i];
				}
			}

			delete[] WorldCell_;
			WorldCell_ = nullptr;
		}

		if (ReplacementCells_.size() > 0)
		{
			for (int i = 0; i < (int)ReplacementCells_.size(); i++)
			{
				for (int j = 0; j < (int)ReplacementCells_[i].size(); j++)
				{
					FCell* cell = &(ReplacementCells_[i][j]);
					DestroyCell(cell);
				}

				ReplacementCells_[i].clear();
			}

			ReplacementCells_.clear();
		}

		TotalCellCountX_ = 0;
		TotalCellCountY_ = 0;

		StartCellX_ = 0;
		StartCellY_ = 0;

		CELL_SIZE_X_ = 0;
		CELL_SIZE_Y_ = 0;
	}

	void FAStarMap::DestroyCell(FCell* Cell)
	{
		if (Cell->neighbor_distance != nullptr)
		{
			delete[] Cell->neighbor_distance;
			Cell->neighbor_distance = nullptr;
		}

		if (Cell->CameraData != nullptr)
		{
			delete Cell->CameraData;
			Cell->CameraData = nullptr;
		}

		Cell->BlockAttrList.clear();
	}

	bool FAStarMap::CreateMap(const float* WorldSize, int CellSizeX, int CellSizeY)
	{
		// check requirement
		if (WorldSize[0] <= 0.0f || WorldSize[1] <= 0.0f ||
			CellSizeX <= 0 || CellSizeY <= 0)
		{
			return false;
		}

		// destroy exist
		DestroyCell();

		// calculate total cell count
		int sx = (int)(WorldSize[0] / (float)CellSizeX) + 1;
		int sy = (int)(WorldSize[1] / (float)CellSizeY) + 1;
		int total = sx * sy;

		// create memory and initialize
		WorldCell_ = new FCellBase*[total];
		memset(WorldCell_, 0, sizeof(FCellBase*)*total);

		StartCellX_ = 0;
		StartCellY_ = 0;
		TotalCellCountX_ = sx;
		TotalCellCountY_ = sy;
		CELL_SIZE_X_ = CellSizeX;
		CELL_SIZE_Y_ = CellSizeY;

		// initialize cells
		for (int i = 0; i < total; i++)
		{
			FCell* cell = new FCell();
			InitializeCell(cell);

			// set xy index
			cell->coordinates.x = i % sx;
			cell->coordinates.y = i / sx;
			cell->IsValid = true;

			WorldCell_[i] = cell;
		}

		return true;
	}

	// attributes
	FCell* FAStarMap::GetCellPtr(int index)
	{
		if (index < 0 || index >= (TotalCellCountX_*TotalCellCountY_))
		{
			return nullptr;
		}

		if (WorldCell_[index]->IsValid == false)
		{
			return nullptr;
		}

		return (FCell *)(WorldCell_[index]);
	}

	FCell* FAStarMap::GetCellPtr(int x, int y)
	{
		int index = CellPosToIndex(x, y);
		if (index == INVALID_INDEX)
		{
			return nullptr;
		}

		if (WorldCell_[index]->IsValid == false)
		{
			return nullptr;
		}

		return (FCell *)(WorldCell_[index]);
	}

	FCell* FAStarMap::GetCellPtr(FNodeCoordinate &CellPos)
	{
		int index = CellPosToIndex(CellPos.x, CellPos.y);
		if (index == INVALID_INDEX)
		{
			return nullptr;
		}

		if (WorldCell_[index]->IsValid == false)
		{
			return nullptr;
		}

		return (FCell *)(WorldCell_[index]);
	}

	bool FAStarMap::UpdateCell(int cell_x, int cell_y, bool isValidate)
	{
		FNodeCoordinate cellpos = { cell_x, cell_y };
		return UpdateCell(cellpos, isValidate);
	}

	bool FAStarMap::UpdateCell(FNodeCoordinate &CellPos, bool isValidate)
	{
		int index = CellPosToIndex(CellPos.x, CellPos.y);
		if (index == INVALID_INDEX)
		{
			return false;
		}

		// skip if same status
		if (WorldCell_[index]->IsValid == isValidate)
		{
			return true;
		}

		if (isValidate)
		{
			// create new cell
			FCell* newCell = new FCell;
			InitializeCell(newCell);

			// get current cell
			FCellBase* baseCell = WorldCell_[index];

			newCell->coordinates = baseCell->coordinates;
			newCell->IsValid = true;

			// destroy exist base cell
			delete baseCell;

			// replace cell
			WorldCell_[index] = (FCellBase *)newCell;
		}
		else
		{
			// create new cell
			FCellBase* newCell = new FCellBase;

			// skip initialize

			// get current cell
			FCell* Cell = (FCell *)WorldCell_[index];

			newCell->coordinates = Cell->coordinates;
			newCell->IsValid = false;

			// destroy exist base cell
			DestroyCell(Cell);
			delete Cell;

			// replace cell
			WorldCell_[index] = newCell;
		}

		return true;
	}

	bool FAStarMap::WorldPosToCellPos(const float *Loc, int &out_cell_x, int &out_cell_y)
	{
		float x = Loc[0];
		float y = Loc[1];

		if (x < 0.0f || y < 0.0f || x >(float)(TotalCellCountX_*CELL_SIZE_X_) || y >(float)(TotalCellCountY_*CELL_SIZE_Y_))
		{
			return false;
		}

		out_cell_x = (int)(x / (float)CELL_SIZE_X_);
		out_cell_y = (int)(y / (float)CELL_SIZE_Y_);

		return true;
	}

	bool FAStarMap::WorldPosToCellPos(const float *Loc, FNodeCoordinate &CellPos)
	{
		return WorldPosToCellPos(Loc, CellPos.x, CellPos.y);
	}

	bool FAStarMap::WorldPosToWorldCellCenterPos(const float *Loc, float *outLoc)
	{
		int x, y;
		if (WorldPosToCellPos(Loc, x, y))
		{
			return CellPosToWorldPos(x, y, outLoc);
		}

		return false;
	}

	bool FAStarMap::CellPosToWorldPos(int cell_x, int cell_y, float *outLoc)
	{
		if (cell_x < 0 || cell_y < 0 || cell_x >(TotalCellCountX_*CELL_SIZE_X_) || cell_y >(TotalCellCountY_*CELL_SIZE_Y_))
		{
			return false;
		}

		float height;
		if (GetCenterHeight(cell_x, cell_y, height) == false)
		{
			return false;
		}

		// center coordinates

		// x
		outLoc[0] = (float)(cell_x * CELL_SIZE_X_) + (float)(CELL_SIZE_X_*0.5f);
		// y
		outLoc[1] = (float)(cell_y * CELL_SIZE_Y_) + (float)(CELL_SIZE_Y_*0.5f);
		// z
		outLoc[2] = height;

		return true;
	}

	bool FAStarMap::CellPosToWorldPos(FNodeCoordinate &CellPos, float *outLoc)
	{
		return CellPosToWorldPos(CellPos.x, CellPos.y, outLoc);
	}

	int FAStarMap::CellPosToIndex(int cell_x, int cell_y)
	{
		if (cell_x < StartCellX_ || cell_y < StartCellY_ ||
			cell_x >= StartCellX_ + TotalCellCountX_ || cell_y >= StartCellY_ + TotalCellCountY_)
		{
			return INVALID_INDEX;
		}

		int index = ((cell_y - StartCellY_) * TotalCellCountX_) + (cell_x - StartCellX_);

		return index;
	}

	int FAStarMap::CellPosToIndex(FNodeCoordinate &CellPos)
	{
		return CellPosToIndex(CellPos.x, CellPos.y);
	}

	bool FAStarMap::CellIndexToPos(int index, int &out_cell_x, int &out_cell_y)
	{
		FCell* CellPtr = GetCellPtr(index);
		if (CellPtr == nullptr)
		{
			return false;
		}

		out_cell_x = CellPtr->coordinates.x;
		out_cell_y = CellPtr->coordinates.y;

		return true;
	}

	bool FAStarMap::CellIndexToPos(int index, FNodeCoordinate &OutCellPos)
	{
		return CellIndexToPos(index, OutCellPos.x, OutCellPos.y);
	}

	bool FAStarMap::CellIndexToWorldPos(int index, float *outLoc)
	{
		FCell* CellPtr = GetCellPtr(index);
		if (CellPtr == nullptr)
		{
			return false;
		}

		// x
		outLoc[0] = (float)(CellPtr->coordinates.x * CELL_SIZE_X_) + (float)(CELL_SIZE_X_*0.5f);
		// y
		outLoc[1] = (float)(CellPtr->coordinates.y * CELL_SIZE_Y_) + (float)(CELL_SIZE_Y_*0.5f);
		// z
		outLoc[2] = CellPtr->center_height;

		return true;
	}

	bool FAStarMap::CheckIsSameCell(const float *v1, const float *v2, bool &result)
	{
		int cx1, cy1;
		int cx2, cy2;

		if (WorldPosToCellPos(v1, cx1, cy1) == false)
		{
			return false;
		}
		if (WorldPosToCellPos(v2, cx2, cy2) == false)
		{
			return false;
		}

		if (cx1 != cx2 || cy1 != cy2)
		{
			result = false;
		}
		else
		{
			result = true;
		}

		return true;
	}

	bool FAStarMap::CheckIsAttackableZone(const float *v1, const float *v2)
	{
		FNodeCoordinate cellpos1, cellpos2;

		if (WorldPosToCellPos(v1, cellpos1) == false)
		{
			return false;
		}
		if (WorldPosToCellPos(v2, cellpos2) == false)
		{
			return false;
		}

		return CheckIsAttackableZone(cellpos1, cellpos2);
	}

	bool FAStarMap::CheckIsAttackableZone(int cell_x1, int cell_y1, int cell_x2, int cell_y2)
	{
		int value1, value2;
		if (GetAttackZone(GetCellPtr(cell_x1, cell_y1), value1) && GetAttackZone(GetCellPtr(cell_x2, cell_y2), value2))
		{
			return CheckIsAttackableZone((ATTR_NUM)value1, (ATTR_NUM)value2);
		}

		return false;
	}

	bool FAStarMap::CheckIsAttackableZone(FNodeCoordinate &CellPos1, FNodeCoordinate &CellPos2)
	{
		int value1, value2;
		if (GetAttackZone(GetCellPtr(CellPos1), value1) && GetAttackZone(GetCellPtr(CellPos2), value2))
		{
			return CheckIsAttackableZone((ATTR_NUM)value1, (ATTR_NUM)value2);
		}

		return false;
	}

	bool FAStarMap::CheckIsAttackableZone(ATTR_NUM attr1, ATTR_NUM attr2)
	{
		// only non-alphabet zone could attack each other.
		if (attr1 == ATTR_ATTACK_ZONE_NONE || attr2 == ATTR_ATTACK_ZONE_NONE)
		{
			if (attr1 == ATTR_ATTACK_ZONE_NONE && attr2 == ATTR_ATTACK_ZONE_NONE)
			{
				return true;
			}
		}
		else if (abs(attr1 - attr2) <= 1)
		{
			return true;
		}

		return false;
	}

	bool FAStarMap::CheckIsAttackableZone(int cell_x1, int cell_y1, int attr2)
	{
		int value1;
		if (GetAttackZone(GetCellPtr(cell_x1, cell_y1), value1))
		{
			return CheckIsAttackableZone((ATTR_NUM)value1, (ATTR_NUM)attr2);
		}

		return false;
	}

	bool FAStarMap::CheckLine(const float *StartLoc, const float *EndLoc, ATTR BlockAttribute, bool &result)
	{
		FNodeCoordinate start;
		FNodeCoordinate end;

		if (WorldPosToCellPos(StartLoc, start) == false)
		{
			return false;
		}
		if (WorldPosToCellPos(EndLoc, end) == false)
		{
			return false;
		}

		return CheckLine(start, end, BlockAttribute, result);
	}

	bool FAStarMap::CheckLine(int StartCellX, int StartCellY, int EndCellX, int EndCellY, ATTR BlockAttribute, bool &result)
	{
		FNodeCoordinate start = { StartCellX, StartCellY };
		FNodeCoordinate end = { EndCellX, EndCellY };
		return CheckLine(start, end, BlockAttribute, result);
	}

	bool FAStarMap::CheckLine(FNodeCoordinate &StartCellPos, FNodeCoordinate &EndCellPos, ATTR BlockAttribute, bool &result)
	{
		result = false;

		// start and end isn't same
		if (StartCellPos != EndCellPos)
		{
			// find straight path by line algorithm
			std::vector<FNodeCoordinate> newlist = g_GetLinePointList(StartCellPos.x, StartCellPos.y, EndCellPos.x, EndCellPos.y);
			// find unblocked path from start location.
			bool isblocked = false;
			for (int32_t i = 0; i < static_cast<int32_t>(newlist.size()); i++)
			{
				if (CheckAttribute(newlist[i].x, newlist[i].y, BlockAttribute, isblocked) && isblocked == true)
				{
					result = true;
					break;
				}
			}
		}
		else
		{
			result = true;
		}

		return true;
	}

#ifdef SERVER_USE
#else
	bool FAStarMap::CheckLineWithMatchAttribute(const float* StartLoc, const float* EndLoc, ATTR Attribute, bool& result)
	{
		FNodeCoordinate start;
		FNodeCoordinate end;

		if (WorldPosToCellPos(StartLoc, start) == false)
		{
			return false;
		}
		if (WorldPosToCellPos(EndLoc, end) == false)
		{
			return false;
		}

		return CheckLineWithMatchAttribute(start, end, Attribute, result);
	}

	bool FAStarMap::CheckLineWithMatchAttribute(int StartCellX, int StartCellY, int EndCellX, int EndCellY, ATTR Attribute, bool& result)
	{
		FNodeCoordinate start = { StartCellX, StartCellY };
		FNodeCoordinate end = { EndCellX, EndCellY };
		return CheckLineWithMatchAttribute(start, end, Attribute, result);
	}

	bool FAStarMap::CheckLineWithMatchAttribute(FNodeCoordinate& StartCellPos, FNodeCoordinate& EndCellPos, ATTR Attribute, bool& result)
	{
		result = false;

		// start and end isn't same
		if (StartCellPos != EndCellPos)
		{
			// find straight path by line algorithm
			std::vector<FNodeCoordinate> newlist = g_GetLinePointList(StartCellPos.x, StartCellPos.y, EndCellPos.x, EndCellPos.y);
			// find attribute from start location.
			bool ischecked = false;
			for (int i = 0; i < newlist.size(); i++)
			{
				if (CheckMatchAttribute(newlist[i].x, newlist[i].y, Attribute, ischecked) && ischecked == true)
				{
					result = true;
					break;
				}
			}
		}
		else
		{
			result = true;
		}

		return true;
	}

	bool FAStarMap::CheckBlock(int cell_x, int cell_y, bool &result)
	{
		return CheckBlock(GetCellPtr(cell_x, cell_y), result);
	}

	bool FAStarMap::CheckBlock(FNodeCoordinate &CellPos, bool &result)
	{
		return CheckBlock(GetCellPtr(CellPos.x, CellPos.y), result);
	}

	bool FAStarMap::CheckBlock(FCell* CellPtr, bool &result)
	{
		return CheckAttribute(CellPtr, ATTR_BLOCK_ALL, result);
	}

	bool FAStarMap::CheckAttribute(int x, int y, ATTR Attribute, bool &result)
	{
		return CheckAttribute(GetCellPtr(x, y), Attribute, result);
	}

	bool FAStarMap::CheckAttribute(FNodeCoordinate &CellPos, ATTR Attribute, bool &result)
	{
		return CheckAttribute(GetCellPtr(CellPos), Attribute, result);
	}

	bool FAStarMap::CheckAttribute(FCell* CellPtr, ATTR Attribute, bool &result)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		result = (CellPtr->attr & Attribute) ? true : false;

		// check flexible block mask
		if (Attribute & ATTR_FLEXBLOCKMASK)
		{
			// find in block list
			for (int i = 0; i < CellPtr->BlockAttrList.size(); i++)
			{
				if (CellPtr->BlockAttrList[i].attr & Attribute)
				{
					result = true;
					break;
				}
			}
		}

		return true;

		//// perfect match only -> unused -> used in CheckMatchAttribute
		//result = ((CellPtr->attr & Attribute) == Attribute) ? true : false;
		//return true;
	}

	bool FAStarMap::CheckMatchAttribute(int x, int y, ATTR Attribute, bool& result)
	{
		return CheckMatchAttribute(GetCellPtr(x, y), Attribute, result);
	}

	bool FAStarMap::CheckMatchAttribute(FNodeCoordinate& CellPos, ATTR Attribute, bool& result)
	{
		return CheckMatchAttribute(GetCellPtr(CellPos), Attribute, result);
	}

	bool FAStarMap::CheckMatchAttribute(FCell* CellPtr, ATTR Attribute, bool& result)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		result = ((CellPtr->attr & Attribute) == Attribute) ? true : false;

		// check flexible block mask
		if (Attribute & ATTR_FLEXBLOCKMASK)
		{
			// find in block list
			for (int i = 0; i < CellPtr->BlockAttrList.size(); i++)
			{
				if ((CellPtr->BlockAttrList[i].attr & Attribute) == Attribute)
				{
					result = true;
					break;
				}
			}
		}

		return true;
	}


	bool FAStarMap::ClearAttribute(int cell_x, int cell_y)
	{
		return ClearAttribute(GetCellPtr(cell_x, cell_y));
	}

	bool FAStarMap::ClearAttribute(FNodeCoordinate &CellPos)
	{
		return ClearAttribute(GetCellPtr(CellPos));
	}

	bool FAStarMap::ClearAttribute(FCell* CellPtr)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		// add
		CellPtr->attr = 0;

		return true;
	}

	bool FAStarMap::ClearBlockAttributeListAll()
	{
		for (int i = 0; i < GetTotalCellCount(); i++)
		{
			if (WorldCell_[i]->IsValid)
			{
				ClearBlockAttributeList((FCell*)(WorldCell_[i]));
			}
		}

		return true;
	}

	bool FAStarMap::ClearBlockAttributeList(int cell_x, int cell_y)
	{
		return ClearBlockAttributeList(GetCellPtr(cell_x, cell_y));
	}

	bool FAStarMap::ClearBlockAttributeList(FNodeCoordinate &CellPos)
	{
		return ClearBlockAttributeList(GetCellPtr(CellPos));
	}

	bool FAStarMap::ClearBlockAttributeList(FCell* CellPtr)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		CellPtr->BlockAttrList.clear();

		return true;
	}

	bool FAStarMap::GetBlockAttributeList(int cell_x, int cell_y, ATTR Attribute, std::vector<int64_t> &outList)
	{
		return GetBlockAttributeList(GetCellPtr(cell_x, cell_y), Attribute, outList);
	}

	bool FAStarMap::GetBlockAttributeList(FNodeCoordinate &CellPos, ATTR Attribute, std::vector<int64_t> &outList)
	{
		return GetBlockAttributeList(GetCellPtr(CellPos), Attribute, outList);
	}

	bool FAStarMap::GetBlockAttributeList(FCell* CellPtr, ATTR Attribute, std::vector<int64_t> &outList)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		for (int i = 0; i < CellPtr->BlockAttrList.size(); i++)
		{
			if (CellPtr->BlockAttrList[i].attr == Attribute)
			{
				outList.push_back(CellPtr->BlockAttrList[i].uid);
			}
		}

		return true;
	}

	bool FAStarMap::GetAttribute(int cell_x, int cell_y, ATTR &Attribute)
	{
		return GetAttribute(GetCellPtr(cell_x, cell_y), Attribute);
	}

	bool FAStarMap::GetAttribute(FNodeCoordinate &CellPos, ATTR &Attribute)
	{
		return GetAttribute(GetCellPtr(CellPos), Attribute);
	}

	bool FAStarMap::GetAttribute(FCell* CellPtr, ATTR &Attribute)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		Attribute = CellPtr->attr;

		for (int i = 0; i < CellPtr->BlockAttrList.size(); i++)
		{
			if (CellPtr->BlockAttrList[i].attr & ATTR_FLEXBLOCKMASK)
			{
				Attribute |= CellPtr->BlockAttrList[i].attr;
			}
		}

		return true;
	}

	bool FAStarMap::SetAttribute(int cell_x, int cell_y, ATTR Attribute)
	{
		return SetAttribute(GetCellPtr(cell_x, cell_y), Attribute);
	}

	bool FAStarMap::SetAttribute(FNodeCoordinate &CellPos, ATTR Attribute)
	{
		return SetAttribute(GetCellPtr(CellPos), Attribute);
	}

	bool FAStarMap::SetAttribute(FCell* CellPtr, ATTR Attribute)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		CellPtr->attr = Attribute;

		return true;
	}

	bool FAStarMap::AddAttribute(int cell_x, int cell_y, ATTR Attribute)
	{
		return AddAttribute(GetCellPtr(cell_x, cell_y), Attribute);
	}

	bool FAStarMap::AddAttribute(FNodeCoordinate &CellPos, ATTR Attribute)
	{
		return AddAttribute(GetCellPtr(CellPos), Attribute);
	}

	bool FAStarMap::AddAttribute(FCell* CellPtr, ATTR Attribute)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		// add
		CellPtr->attr |= Attribute;

		return true;
	}

	bool FAStarMap::AddAttribute(int cell_x, int cell_y, ATTR Attribute, int64_t uid)
	{
		return AddAttribute(GetCellPtr(cell_x, cell_y), Attribute, uid);
	}

	bool FAStarMap::AddAttribute(FNodeCoordinate &CellPos, ATTR Attribute, int64_t uid)
	{
		return AddAttribute(GetCellPtr(CellPos), Attribute, uid);
	}

	bool FAStarMap::AddAttribute(FCell* CellPtr, ATTR Attribute, int64_t uid)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		// find exist
		for (int i = 0; i < CellPtr->BlockAttrList.size(); i++)
		{
			if (CellPtr->BlockAttrList[i].uid == uid)
			{
				// found. already exist
				return true;
			}
		}

		FCellAttribute ca = { (unsigned char)Attribute, uid };

		CellPtr->BlockAttrList.push_back(ca);

		return true;
	}

	bool FAStarMap::RemoveAttribute(int cell_x, int cell_y, ATTR Attribute)
	{
		return RemoveAttribute(GetCellPtr(cell_x, cell_y), Attribute);
	}

	bool FAStarMap::RemoveAttribute(FNodeCoordinate &CellPos, ATTR Attribute)
	{
		return RemoveAttribute(GetCellPtr(CellPos), Attribute);
	}

	bool FAStarMap::RemoveAttribute(FCell* CellPtr, ATTR Attribute)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		// remove
		CellPtr->attr &= ~Attribute;

		return true;
	}

	bool FAStarMap::RemoveAttributeByUID(int cell_x, int cell_y, int64_t uid)
	{
		return RemoveAttributeByUID(GetCellPtr(cell_x, cell_y), uid);
	}

	bool FAStarMap::RemoveAttributeByUID(FNodeCoordinate &CellPos, int64_t uid)
	{
		return RemoveAttributeByUID(GetCellPtr(CellPos), uid);
	}

	bool FAStarMap::RemoveAttributeByUID(FCell* CellPtr, int64_t uid)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		// remove
		for (int i = 0; i < CellPtr->BlockAttrList.size(); i++)
		{
			if (CellPtr->BlockAttrList[i].uid == uid)
			{
				CellPtr->BlockAttrList.erase(CellPtr->BlockAttrList.begin() + i);
				return true;
			}
		}

		return true;
	}

	bool FAStarMap::GetCenterHeight(int cell_x, int cell_y, float &height)
	{
		return GetCenterHeight(GetCellPtr(cell_x, cell_y), height);
	}

	bool FAStarMap::GetCenterHeight(FNodeCoordinate &CellPos, float &height)
	{
		return GetCenterHeight(GetCellPtr(CellPos), height);
	}

	bool FAStarMap::GetCenterHeight(FCell* CellPtr, float &height)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		height = CellPtr->center_height;

		return true;
	}

	bool FAStarMap::SetCenterHeight(int cell_x, int cell_y, float height)
	{
		return SetCenterHeight(GetCellPtr(cell_x, cell_y), height);
	}

	bool FAStarMap::SetCenterHeight(FNodeCoordinate &CellPos, float height)
	{
		return SetCenterHeight(GetCellPtr(CellPos), height);
	}

	bool FAStarMap::SetCenterHeight(FCell* CellPtr, float height)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		CellPtr->center_height = height;

		return true;
	}

	bool FAStarMap::GetGroundMaterial(int cell_x, int cell_y, int &material)
	{
		return GetGroundMaterial(GetCellPtr(cell_x, cell_y), material);
	}

	bool FAStarMap::GetGroundMaterial(FNodeCoordinate &CellPos, int &material)
	{
		return GetGroundMaterial(GetCellPtr(CellPos), material);
	}

	bool FAStarMap::GetGroundMaterial(FCell* CellPtr, int &material)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		material = CellPtr->GroundMaterialNum;

		return true;
	}

	bool FAStarMap::SetGroundMaterial(int cell_x, int cell_y, int material)
	{
		return SetGroundMaterial(GetCellPtr(cell_x, cell_y), material);
	}

	bool FAStarMap::SetGroundMaterial(FNodeCoordinate &CellPos, int material)
	{
		return SetGroundMaterial(GetCellPtr(CellPos), material);
	}

	bool FAStarMap::SetGroundMaterial(FCell* CellPtr, int material)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		CellPtr->GroundMaterialNum = (ATTR_NUM)material;

		return true;
	}

	bool FAStarMap::GetCameraData(int cell_x, int cell_y, float &outDistancePC, float &outDistanceMobile, float &outRotX, float &outRotY, int& outActionType, CAMERA_TYPE &outCameraType)
	{
		return GetCameraData(GetCellPtr(cell_x, cell_y), outDistancePC, outDistanceMobile, outRotX, outRotY, outActionType, outCameraType);
	}

	bool FAStarMap::GetCameraData(FNodeCoordinate &CellPos, float &outDistancePC, float &outDistanceMobile, float &outRotX, float &outRotY, int& outActionType, CAMERA_TYPE &outCameraType)
	{
		return GetCameraData(GetCellPtr(CellPos), outDistancePC, outDistanceMobile, outRotX, outRotY, outActionType, outCameraType);
	}

	bool FAStarMap::GetCameraData(FCell* CellPtr, float &outDistancePC, float &outDistanceMobile, float &outRotX, float &outRotY, int& outActionType, CAMERA_TYPE &outCameraType)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		outCameraType = CellPtr->CameraDataType;

		if (CellPtr->CameraDataType == CAMERATYPE_NONE || CellPtr->CameraData == nullptr)
		{
			return false;
		}

		outDistancePC = CellPtr->CameraData->tile_rotation_speed;
		outDistanceMobile = CellPtr->CameraData->tile_reset_time;

		outRotX = CellPtr->CameraData->rot[0];
		outRotY = CellPtr->CameraData->rot[1];

		outActionType = CellPtr->CameraData->action_type;

		return true;
	}

	bool FAStarMap::SetCameraData(int cell_x, int cell_y, float DistancePC, float DistanceMobile, float RotX, float RotY, int ActionType, CAMERA_TYPE CameraType)
	{
		return SetCameraData(GetCellPtr(cell_x, cell_y), DistancePC, DistanceMobile, RotX, RotY, ActionType, CameraType);
	}

	bool FAStarMap::SetCameraData(FNodeCoordinate &CellPos, float DistancePC, float DistanceMobile, float RotX, float RotY, int ActionType, CAMERA_TYPE CameraType)
	{
		return SetCameraData(GetCellPtr(CellPos), DistancePC, DistanceMobile, RotX, RotY, ActionType, CameraType);
	}

	bool FAStarMap::SetCameraData(FCell* CellPtr, float DistancePC, float DistanceMobile, float RotX, float RotY, int ActionType, CAMERA_TYPE CameraType)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		if (CellPtr->CameraData == nullptr)
		{
			// create new one
			CellPtr->CameraData = new FCellCameraData;
		}

		CellPtr->CameraDataType = CameraType;

		CellPtr->CameraData->tile_rotation_speed = DistancePC;
		CellPtr->CameraData->tile_reset_time = DistanceMobile;

		CellPtr->CameraData->rot[0] = RotX;
		CellPtr->CameraData->rot[1] = RotY;

		CellPtr->CameraData->action_type = ActionType;

		return true;
	}

	bool FAStarMap::GetCameraData(int cell_x, int cell_y, CAMERA_TYPE& outCameraDataType, FCellCameraData& outCameraData)
	{
		return GetCameraData(GetCellPtr(cell_x, cell_y), outCameraDataType, outCameraData);
	}

	bool FAStarMap::GetCameraData(FNodeCoordinate& CellPos, CAMERA_TYPE& outCameraDataType, FCellCameraData& outCameraData)
	{
		return GetCameraData(GetCellPtr(CellPos), outCameraDataType, outCameraData);
	}

	bool FAStarMap::GetCameraData(FCell* CellPtr, CAMERA_TYPE& outCameraDataType, FCellCameraData& outCameraData)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		outCameraDataType = CellPtr->CameraDataType;

		if (CellPtr->CameraDataType == CAMERATYPE_NONE || CellPtr->CameraData == nullptr)
		{
			return false;
		}

		outCameraData.tile_rotation_speed = CellPtr->CameraData->tile_rotation_speed;
		outCameraData.tile_reset_time = CellPtr->CameraData->tile_reset_time;

		outCameraData.rot[0] = CellPtr->CameraData->rot[0];
		outCameraData.rot[1] = CellPtr->CameraData->rot[1];

		outCameraData.action_type = CellPtr->CameraData->action_type;

		return true;
	}

	bool FAStarMap::SetCameraData(int cell_x, int cell_y, CAMERA_TYPE CameraDataType, FCellCameraData& CameraData)
	{
		return SetCameraData(GetCellPtr(cell_x, cell_y), CameraDataType, CameraData);
	}

	bool FAStarMap::SetCameraData(FNodeCoordinate& CellPos, CAMERA_TYPE CameraDataType, FCellCameraData& CameraData)
	{
		return SetCameraData(GetCellPtr(CellPos), CameraDataType, CameraData);
	}

	bool FAStarMap::SetCameraData(FCell* CellPtr, CAMERA_TYPE CameraDataType, FCellCameraData& CameraData)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		if (CellPtr->CameraData == nullptr)
		{
			// create new one
			CellPtr->CameraData = new FCellCameraData;
		}

		CellPtr->CameraDataType = CameraDataType;

		CellPtr->CameraData->tile_rotation_speed = CameraData.tile_rotation_speed;
		CellPtr->CameraData->tile_reset_time = CameraData.tile_reset_time;

		CellPtr->CameraData->rot[0] = CameraData.rot[0];
		CellPtr->CameraData->rot[1] = CameraData.rot[1];

		CellPtr->CameraData->action_type = CameraData.action_type;

		return true;
	}

	bool FAStarMap::RemoveCameraData(int cell_x, int cell_y)
	{
		return RemoveCameraData(GetCellPtr(cell_x, cell_y));
	}

	bool FAStarMap::RemoveCameraData(FNodeCoordinate &CellPos)
	{
		return RemoveCameraData(GetCellPtr(CellPos));
	}

	bool FAStarMap::RemoveCameraData(FCell* CellPtr)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		if (CellPtr->CameraData)
		{
			delete CellPtr->CameraData;
			CellPtr->CameraData = nullptr;
		}

		CellPtr->CameraDataType = CAMERATYPE_NONE;

		return true;
	}

	bool FAStarMap::GetAttackZone(int cell_x, int cell_y, int &zone)
	{
		return GetAttackZone(GetCellPtr(cell_x, cell_y), zone);
	}

	bool FAStarMap::GetAttackZone(FNodeCoordinate &CellPos, int &zone)
	{
		return GetAttackZone(GetCellPtr(CellPos), zone);
	}

	bool FAStarMap::GetAttackZone(FCell* CellPtr, int &zone)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		zone = (CellPtr->attr & ATTR_ATTACKZONEMASK) >> 16;

		return true;
	}

	bool FAStarMap::SetAttackZone(int cell_x, int cell_y, int zone)
	{
		return SetAttackZone(GetCellPtr(cell_x, cell_y), zone);
	}

	bool FAStarMap::SetAttackZone(FNodeCoordinate &CellPos, int zone)
	{
		return SetAttackZone(GetCellPtr(CellPos), zone);
	}

	bool FAStarMap::SetAttackZone(FCell* CellPtr, int zone)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		CellPtr->attr &= ~ATTR_ATTACKZONEMASK;		// clear exist
		CellPtr->attr |= ((zone & 0x0F) << 16);		// to protect cell attribute, we set masked value.

		return true;
	}

	bool FAStarMap::GetSWArea(int cell_x, int cell_y, int &area)
	{
		return GetSWArea(GetCellPtr(cell_x, cell_y), area);
	}

	bool FAStarMap::GetSWArea(FNodeCoordinate &CellPos, int &area)
	{
		return GetSWArea(GetCellPtr(CellPos), area);
	}

	bool FAStarMap::GetSWArea(FCell* CellPtr, int &area)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		area = CellPtr->SWAreaNum;

		return true;
	}

	bool FAStarMap::SetSWArea(int cell_x, int cell_y, int area)
	{
		return SetSWArea(GetCellPtr(cell_x, cell_y), area);
	}

	bool FAStarMap::SetSWArea(FNodeCoordinate &CellPos, int area)
	{
		return SetSWArea(GetCellPtr(CellPos), area);
	}

	bool FAStarMap::SetSWArea(FCell* CellPtr, int area)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		CellPtr->SWAreaNum = (ATTR_NUM)area;

		return true;
	}

#endif

	void FAStarMap::GetMapSize(int &sizex, int &sizey)
	{
		sizex = TotalCellCountX_ * CELL_SIZE_X_;
		sizey = TotalCellCountY_ * CELL_SIZE_Y_;
	}

	void FAStarMap::GetTotalCellCount(int &countx, int &county)
	{
		countx = TotalCellCountX_;
		county = TotalCellCountY_;
	}

	void FAStarMap::GetCellSize(int &sizex, int &sizey)
	{
		sizex = CELL_SIZE_X_;
		sizey = CELL_SIZE_Y_;
	}

	void FAStarMap::GetMapBoundBoxXY(float *min, float *max)
	{
		// x
		min[0] = (float)(StartCellX_ * CELL_SIZE_X_);
		// y
		min[1] = (float)(StartCellY_ * CELL_SIZE_Y_);

		// x
		max[0] = (float)((StartCellX_ + TotalCellCountX_) * CELL_SIZE_X_);
		// y
		max[1] = (float)((StartCellY_ + TotalCellCountY_) * CELL_SIZE_Y_);
	}

	void FAStarMap::GetMapBoundBoxXYZ(float *min, float *max)
	{
		GetMapBoundBoxXY(min, max);

		// find out min / max z
		float minz = 0, maxz = 0;

		int size = GetTotalCellCount();

		FCell* cell;
		bool isfirstadd = true;

		for (int i = 0; i < size; i++)
		{
			cell = GetCellPtr(i);
			if (cell == nullptr)
			{
				continue;
			}

			if (isfirstadd)
			{
				minz = cell->center_height;
				maxz = cell->center_height;
				isfirstadd = false;
			}
			else
			{
				if (maxz < cell->center_height)
				{
					maxz = cell->center_height;
				}
				if (minz > cell->center_height)
				{
					minz = cell->center_height;
				}
			}
		}

		min[2] = minz;
		max[2] = maxz;
	}

	// operations
	FPathFindResult FAStarMap::FindPath(const float *StartLoc, const float *EndLoc, ATTR BlockAttribute)
	{
		std::vector<FNodeCoordinate> dummy;
		return FindPath(StartLoc, EndLoc, BlockAttribute, dummy);
	}

	FPathFindResult FAStarMap::FindPath(int StartCellX, int StartCellY, int EndCellX, int EndCellY, ATTR BlockAttribute)
	{
		std::vector<FNodeCoordinate> dummy;
		return FindPath(StartCellX, StartCellY, EndCellX, EndCellY, BlockAttribute, dummy, nullptr, nullptr, true, DEFAULT_PATHFIND_TIMEOUT);
	}

	FPathFindResult FAStarMap::FindPath(FNodeCoordinate &StartCellPos, FNodeCoordinate &EndCellPos, ATTR BlockAttribute)
	{
		std::vector<FNodeCoordinate> dummy;
		return FindPath(StartCellPos, EndCellPos, BlockAttribute, dummy, nullptr, nullptr, true, DEFAULT_PATHFIND_TIMEOUT);
	}

	FPathFindResult FAStarMap::FindPath(const float *StartLoc, const float *EndLoc, ATTR BlockAttribute, std::vector<FNodeCoordinate> &History)
	{
		return FindPath(StartLoc, EndLoc, BlockAttribute, History, nullptr, nullptr, true, DEFAULT_PATHFIND_TIMEOUT);
	}

	// operations
	FPathFindResult FAStarMap::FindPath(const float *StartLoc, const float *EndLoc, ATTR BlockAttribute, std::vector<FNodeCoordinate> &History, const float* MinLoc, const float *MaxLoc, bool TryToFindPartialPath, float TimeOutSecond)
	{
		FPathFindResult pathfindresult;
		pathfindresult.Reason = FRR_None;

		FNodeCoordinate source;
		FNodeCoordinate target;
		// FNodeCoordinate min = { 0, 0 }, max = { 0, 0 };

		// step 0.
		// prerequisite
		// convert coordinates - start
		if (!WorldPosToCellPos(StartLoc, source.x, source.y))
		{
			pathfindresult.Result = FR_Error;
			return pathfindresult;
		}
		// convert coordinates - end
		if (!WorldPosToCellPos(EndLoc, target.x, target.y))
		{
			pathfindresult.Result = FR_Error;
			return pathfindresult;
		}

		return FindPath(source, target, BlockAttribute, History, MinLoc, MaxLoc, TryToFindPartialPath, TimeOutSecond);
	}

	FPathFindResult FAStarMap::FindPath(int StartCellX, int StartCellY, int EndCellX, int EndCellY, ATTR BlockAttribute, std::vector<FNodeCoordinate> &History, const float* MinLoc, const float *MaxLoc, bool TryToFindPartialPath, float TimeOutSecond)
	{
		FNodeCoordinate start = { StartCellX, StartCellY };
		FNodeCoordinate end = { EndCellX, EndCellY };
		return FindPath(start, end, BlockAttribute, History, MinLoc, MaxLoc, TryToFindPartialPath, TimeOutSecond);
	}

	FPathFindResult FAStarMap::FindPath(FNodeCoordinate &StartCellPos, FNodeCoordinate &EndCellPos, ATTR BlockAttribute, std::vector<FNodeCoordinate> &History, const float* MinLoc, const float *MaxLoc, bool TryToFindPartialPath, float TimeOutSecond)
	{
		FPathFindResult pathfindresult;
		pathfindresult.Reason = FRR_None;

		FNodeCoordinate source = StartCellPos;
		FNodeCoordinate target = EndCellPos;
		FNodeCoordinate min = { 0, 0 }, max = { 0, 0 };
		bool UseMinMaxRegion = false;

		// if both start and end cell positions are same. abort find path
		if (source == target)
		{
			pathfindresult.Result = FR_Error;
			return pathfindresult;
		}

		// convert coordinates - min/max region
		if (MinLoc != nullptr && MaxLoc != nullptr)
		{
			// convert coordinates - min
			if (!WorldPosToCellPos(MinLoc, min.x, min.y))
			{
				pathfindresult.Result = FR_Error;
				return pathfindresult;
			}
			// convert coordinates - max
			if (!WorldPosToCellPos(MaxLoc, max.x, max.y))
			{
				pathfindresult.Result = FR_Error;
				return pathfindresult;
			}
			UseMinMaxRegion = true;
		}

		bool result = false;
		bool useHistory = (History.size() > 0) ? true : false;

		//// step 0. -> experimental, only check block to avoid searching lack 2019/10/21
		//// can we go to the destination exactly ?
		//if (CheckAttribute(target.x, target.y, BlockAttribute, result) && result)
		//{
		//	// ok we'd better to find nearest path from destination
		//	return FindNearestPath(StartLoc, EndLoc, BlockAttribute, History, MinLoc, MaxLoc);
		//}
		if (TryToFindPartialPath)
		{
			ATTR expTestAttribute = (ATTR_BLOCK | ATTR_OBSTACLE);
			if (BlockAttribute & expTestAttribute)
			{
				if (CheckAttribute(target.x, target.y, expTestAttribute, result) && result)
				{
					// 2022.02.23 exception. ignore block attribute
					// reset result for next check
					bool extresult = false;
					if (CheckAttribute(target.x, target.y, ATTR_EXTBLOCK_ALLOW_PATHFIND, extresult) == false || extresult == false)
					{
						// Exception. 2021.08.30
						// Problem occured if collecting material on block attribute with curved findpath.
						result = false;
						if (CheckAttribute(target.x, target.y, ATTR_COLLECT_PLACEMENT, result) && result)
						{
							FNodeCoordinate newtarget;

							if (FindNearestNeighborCell(target, source, expTestAttribute, newtarget))
							{
								return FindPath(source, newtarget, BlockAttribute, History, MinLoc, MaxLoc, false, TimeOutSecond);
							}

							// failed. what can we do ?
							// TO DO HERE.
							// option 1. tuning more FindNearestNeighborCell
							// option 2. fail process
						}

						// ok we'd better to find nearest path from destination
						return FindNearestPath(source, target, BlockAttribute, History, MinLoc, MaxLoc, false, TimeOutSecond);
					}
				}
			}
		}

		// step	1.
		// find normal path
		FAStarNode* current = nullptr;
		std::set<FAStarNode*> openSet, closedSet;
		openSet.insert(new FAStarNode(source));

#ifdef SHOW_UDEBUG_ASTARMAP
		UMirLogManager::DebugLog(E_LOG_CATEGORY::MIR_CHARACTER, ELogVerbosity::Type::Error,
			FString::Printf(TEXT("Start!!!!!!! Start(%d, %d), Dest(%d, %d), Min(%d, %d), Max(%d, %d)"), source.x, source.y, target.x, target.y, min.x, min.y, max.x, max.y));

		int QueryCount = 0;
		int AreaRestrictCount = 0;
		int SkippingCount = 0;
#endif
		// set time stamp
		auto start_time = std::chrono::high_resolution_clock::now();

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

			if (current->coordinates == target)
			{
				break;
			}

			closedSet.insert(current);
			openSet.erase(std::find(openSet.begin(), openSet.end(), current));

#ifdef SHOW_UDEBUG_ASTARMAP
			UMirLogManager::DebugLog(E_LOG_CATEGORY::MIR_CHARACTER, ELogVerbosity::Type::Log,
				FString::Printf(TEXT("Finding (%d, %d) ####"), current->coordinates.x, current->coordinates.y));
#endif

			for (int i = 0; i < g_FindDirections; i++)
			{
#ifdef SHOW_UDEBUG_ASTARMAP
				QueryCount++;
#endif

				FNodeCoordinate newcoordi =
				{
					current->coordinates.x + g_Direction[i].x,
					current->coordinates.y + g_Direction[i].y,
				};

				// check min/max
				if (UseMinMaxRegion)
				{
					if (newcoordi.x < min.x || newcoordi.x > max.x ||
						newcoordi.y < min.y || newcoordi.y > max.y)
					{
#ifdef SHOW_UDEBUG_ASTARMAP
						UMirLogManager::DebugLog(E_LOG_CATEGORY::MIR_CHARACTER, ELogVerbosity::Type::Log,
							FString::Printf(TEXT("Q:%d Loc(%d, %d) - skipping limited area"), QueryCount, newcoordi.x, newcoordi.y));

						AreaRestrictCount++;
#endif
						continue;
					}
				}

				result = false;
				if (CheckAttribute(newcoordi.x, newcoordi.y, BlockAttribute, result) == false ||
					result || g_FindNodeOnList(closedSet, newcoordi))
				{
					// 2022.02.23 exception. ignore block attribute
					bool ignoreblock = false;

					if (result)
					{
						// reset result for next check
						bool extresult = false;
						if (CheckAttribute(newcoordi.x, newcoordi.y, ATTR_EXTBLOCK_ALLOW_PATHFIND, extresult) && extresult)
						{
							// ignore block attribute
							ignoreblock = true;
						}
					}

					if (ignoreblock == false)
					{
#ifdef SHOW_UDEBUG_ASTARMAP
						UMirLogManager::DebugLog(E_LOG_CATEGORY::MIR_CHARACTER, ELogVerbosity::Type::Log,
							FString::Printf(TEXT("Q:%d Loc(%d, %d) - skipping blocked or closed set"), QueryCount, newcoordi.x, newcoordi.y));

						SkippingCount++;
#endif
						// exceptional handling code 2019/10/21
						if (newcoordi == target)
						{
							// calculate cost by 4-way or 8-way movement
							int totalCost = current->G + ((i < 4) ? 10 : 14);

							FAStarNode* successor = g_FindNodeOnList(openSet, newcoordi);
							if (successor == nullptr)
							{
								successor = new FAStarNode(newcoordi, current);
								successor->G = totalCost;
								successor->H = g_Heuristic(successor->coordinates, target);
								openSet.insert(successor);
							}
							else if (totalCost < successor->G)
							{
								successor->parent = current;
								successor->G = totalCost;
							}
						}

						continue;
					}
				}

#ifdef SHOW_UDEBUG_ASTARMAP
				UMirLogManager::DebugLog(E_LOG_CATEGORY::MIR_CHARACTER, ELogVerbosity::Type::Log,
					FString::Printf(TEXT("Q:%d Loc(%d, %d)"), QueryCount, newcoordi.x, newcoordi.y));
#endif

				// calculate cost by 4-way or 8-way movement
				int totalCost = current->G + ((i < 4) ? 10 : 14);

				// find in history
				if (useHistory)
				{
					for (int h = 0; h < static_cast<int32_t>(History.size()); h++)
					{
						if (newcoordi.x == History[h].x && newcoordi.y == History[h].y)
						{
							totalCost -= 5;
							break;
						}
					}
				}

				FAStarNode* successor = g_FindNodeOnList(openSet, newcoordi);
				if (successor == nullptr)
				{
					successor = new FAStarNode(newcoordi, current);
					successor->G = totalCost;
					successor->H = g_Heuristic(successor->coordinates, target);
					openSet.insert(successor);
				}
				else if (totalCost < successor->G)
				{
					successor->parent = current;
					successor->G = totalCost;
				}
			}

			// check timeout
			auto elapsed = std::chrono::high_resolution_clock::now() - start_time;
			float seconds = (float)(std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() / 1000.0f);
			if (TimeOutSecond <= seconds)
			{
				// clean up and abort
				g_ReleaseNodes(openSet);
				g_ReleaseNodes(closedSet);

				pathfindresult.PathList.clear();
				pathfindresult.PathFlagList.clear();

				pathfindresult.Result = FR_Error;
				pathfindresult.Reason = FRR_PathFindTimeout;
				return pathfindresult;
			}
		}

#ifdef SHOW_UDEBUG_ASTARMAP
		UMirLogManager::DebugLog(E_LOG_CATEGORY::MIR_CHARACTER, ELogVerbosity::Type::Error,
			FString::Printf(TEXT("End!!!!!!! QueryCount:%d, AreaRestrictCount:%d, SkippingCount:%d"), QueryCount, AreaRestrictCount, SkippingCount));
#endif

		while (current != nullptr)
		{
			pathfindresult.PathList.insert(pathfindresult.PathList.begin(), current->coordinates);
			current = current->parent;
		}

		g_ReleaseNodes(openSet);
		g_ReleaseNodes(closedSet);

		// step 2.
		// do we find path to destination exactly ?
		if (pathfindresult.PathList.size() > 1)
		{
			// check result start and destination is same
			if (pathfindresult.PathList[0] != source ||
				pathfindresult.PathList[pathfindresult.PathList.size() - 1] != target)
			{
				// reset path (we can't use incorrect path list)
				pathfindresult.PathList.clear();

				// as result, we didn't reached to destination

				// find available path as near as we can 
				if (TryToFindPartialPath)
				{
					pathfindresult = FindNearestPath(source, target, BlockAttribute, History, MinLoc, MaxLoc, true, TimeOutSecond);
				}
				else
				{
					pathfindresult.Result = FR_Error;
				}

				return pathfindresult;
			}

			// exceptional handling code 2019/10/21
			if (CheckAttribute(pathfindresult.PathList[pathfindresult.PathList.size() - 1], BlockAttribute, result) && result)
			{
				// remove last path
				pathfindresult.PathList.pop_back();
			}

			// exceptional handling code 2021/04/12 - can't go any where. pathlist is only one. (processed from exceptional handling code 2019/10/21)
			if (pathfindresult.PathList.size() <= 1)
			{
				pathfindresult.PathList.clear();
				pathfindresult.Result = FR_Error;
				return pathfindresult;
			}
		}
		else
		{
			// if path list is only one, probably can't find cause of block cell is surrounded
			// reset path (we don't use irregular path list)
			pathfindresult.PathList.clear();
			pathfindresult.Result = FR_Error;
			return pathfindresult;
		}

		// completely success
		pathfindresult.Result = FR_Success;

		return pathfindresult;
	}

	FPathFindResult FAStarMap::FindPathWithOption(FNodeCoordinate& StartCellPos, FNodeCoordinate& EndCellPos, ATTR BlockAttribute, std::vector<FNodeCoordinate>& History, const float* MinLoc, const float* MaxLoc, float TimeOutSecond, FOPTION FindOption)
	{
		FPathFindResult pathfindresult;
		pathfindresult.Reason = FRR_None;

		FNodeCoordinate source = StartCellPos;
		FNodeCoordinate target = EndCellPos;
		FNodeCoordinate min = { 0, 0 }, max = { 0, 0 };
		bool UseMinMaxRegion = false;

		// if both start and end cell positions are same. abort find path
		if (source == target)
		{
			pathfindresult.Result = FR_Error;
			return pathfindresult;
		}

		// convert coordinates - min/max region
		if (MinLoc != nullptr && MaxLoc != nullptr)
		{
			// convert coordinates - min
			if (!WorldPosToCellPos(MinLoc, min.x, min.y))
			{
				pathfindresult.Result = FR_Error;
				return pathfindresult;
			}
			// convert coordinates - max
			if (!WorldPosToCellPos(MaxLoc, max.x, max.y))
			{
				pathfindresult.Result = FR_Error;
				return pathfindresult;
			}
			UseMinMaxRegion = true;
		}

		bool result = false;
		bool useHistory = (History.size() > 0) ? true : false;

		//// step 0. -> experimental, only check block to avoid searching lack 2019/10/21
		//// can we go to the destination exactly ?
		//if (CheckAttribute(target.x, target.y, BlockAttribute, result) && result)
		//{
		//	// ok we'd better to find nearest path from destination
		//	return FindNearestPath(StartLoc, EndLoc, BlockAttribute, History, MinLoc, MaxLoc);
		//}
		if (FindOption & FO_FIND_PARTIAL_PATH)
		{
			ATTR expTestAttribute = (ATTR_BLOCK | ATTR_OBSTACLE);
			if (BlockAttribute & expTestAttribute)
			{
				if (CheckAttribute(target.x, target.y, expTestAttribute, result) && result)
				{
					// 2022.02.23 exception. ignore block attribute
					// reset result for next check
					bool extresult = false;
					if (CheckAttribute(target.x, target.y, ATTR_EXTBLOCK_ALLOW_PATHFIND, extresult) == false || extresult == false)
					{
						// Exception. 2021.08.30
						// Problem occured if collecting material on block attribute with curved findpath.
						result = false;
						if (CheckAttribute(target.x, target.y, ATTR_COLLECT_PLACEMENT, result) && result)
						{
							FNodeCoordinate newtarget;

							if (FindNearestNeighborCell(target, source, expTestAttribute, newtarget))
							{
								return FindPathWithOption(source, newtarget, BlockAttribute, History, MinLoc, MaxLoc, TimeOutSecond, FindOption & ~FO_FIND_PARTIAL_PATH);
							}

							// failed. what can we do ?
							// TO DO HERE.
							// option 1. tuning more FindNearestNeighborCell
							// option 2. fail process
						}

						// ok we'd better to find nearest path from destination
						return FindNearestPathWithOption(source, target, BlockAttribute, History, MinLoc, MaxLoc, TimeOutSecond, FindOption & ~FO_FIND_PARTIAL_PATH);
					}
				}
			}
		}

		// step	1.
		// find normal path
		FAStarNode* current = nullptr;
		std::set<FAStarNode*> openSet, closedSet;
		openSet.insert(new FAStarNode(source));

#ifdef SHOW_UDEBUG_ASTARMAP
		UMirLogManager::DebugLog(E_LOG_CATEGORY::MIR_CHARACTER, ELogVerbosity::Type::Error,
			FString::Printf(TEXT("Start!!!!!!! Start(%d, %d), Dest(%d, %d), Min(%d, %d), Max(%d, %d)"), source.x, source.y, target.x, target.y, min.x, min.y, max.x, max.y));

		int QueryCount = 0;
		int AreaRestrictCount = 0;
		int SkippingCount = 0;
#endif
		// set time stamp
		auto start_time = std::chrono::high_resolution_clock::now();

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

			if (current->coordinates == target)
			{
				break;
			}

			closedSet.insert(current);
			openSet.erase(std::find(openSet.begin(), openSet.end(), current));

#ifdef SHOW_UDEBUG_ASTARMAP
			UMirLogManager::DebugLog(E_LOG_CATEGORY::MIR_CHARACTER, ELogVerbosity::Type::Log,
				FString::Printf(TEXT("Finding (%d, %d) ####"), current->coordinates.x, current->coordinates.y));
#endif

			for (int i = 0; i < g_FindDirections; i++)
			{
#ifdef SHOW_UDEBUG_ASTARMAP
				QueryCount++;
#endif

				FNodeCoordinate newcoordi =
				{
					current->coordinates.x + g_Direction[i].x,
					current->coordinates.y + g_Direction[i].y,
				};

				// check min/max
				if (UseMinMaxRegion)
				{
					if (newcoordi.x < min.x || newcoordi.x > max.x ||
						newcoordi.y < min.y || newcoordi.y > max.y)
					{
#ifdef SHOW_UDEBUG_ASTARMAP
						UMirLogManager::DebugLog(E_LOG_CATEGORY::MIR_CHARACTER, ELogVerbosity::Type::Log,
							FString::Printf(TEXT("Q:%d Loc(%d, %d) - skipping limited area"), QueryCount, newcoordi.x, newcoordi.y));

						AreaRestrictCount++;
#endif
						continue;
					}
				}

				result = false;
				if (CheckAttribute(newcoordi.x, newcoordi.y, BlockAttribute, result) == false ||
					result || g_FindNodeOnList(closedSet, newcoordi))
				{
					// 2022.02.23 exception. ignore block attribute
					bool ignoreblock = false;

					if (result)
					{
						// reset result for next check
						bool extresult = false;
						if (CheckAttribute(newcoordi.x, newcoordi.y, ATTR_EXTBLOCK_ALLOW_PATHFIND, extresult) && extresult)
						{
							// ignore block attribute
							ignoreblock = true;
						}
					}

					if (ignoreblock == false)
					{
#ifdef SHOW_UDEBUG_ASTARMAP
						UMirLogManager::DebugLog(E_LOG_CATEGORY::MIR_CHARACTER, ELogVerbosity::Type::Log,
							FString::Printf(TEXT("Q:%d Loc(%d, %d) - skipping blocked or closed set"), QueryCount, newcoordi.x, newcoordi.y));

						SkippingCount++;
#endif
						// exceptional handling code 2019/10/21
						if (newcoordi == target)
						{
							// calculate cost by 4-way or 8-way movement
							int totalCost = current->G + ((i < 4) ? 10 : 14);

							FAStarNode* successor = g_FindNodeOnList(openSet, newcoordi);
							if (successor == nullptr)
							{
								successor = new FAStarNode(newcoordi, current);
								successor->G = totalCost;
								successor->H = g_Heuristic(successor->coordinates, target);
								openSet.insert(successor);
							}
							else if (totalCost < successor->G)
							{
								successor->parent = current;
								successor->G = totalCost;
							}
						}

						continue;
					}
				}

#ifdef SHOW_UDEBUG_ASTARMAP
				UMirLogManager::DebugLog(E_LOG_CATEGORY::MIR_CHARACTER, ELogVerbosity::Type::Log,
					FString::Printf(TEXT("Q:%d Loc(%d, %d)"), QueryCount, newcoordi.x, newcoordi.y));
#endif

				// calculate cost by 4-way or 8-way movement
				int totalCost = current->G + ((i < 4) ? 10 : 14);

				// find in history
				if (useHistory)
				{
					for (int h = 0; h < static_cast<int32_t>(History.size()); h++)
					{
						if (newcoordi.x == History[h].x && newcoordi.y == History[h].y)
						{
							totalCost -= 5;
							break;
						}
					}
				}

				FAStarNode* successor = g_FindNodeOnList(openSet, newcoordi);
				if (successor == nullptr)
				{
					successor = new FAStarNode(newcoordi, current);
					successor->G = totalCost;
					successor->H = g_Heuristic(successor->coordinates, target);
					openSet.insert(successor);
				}
				else if (totalCost < successor->G)
				{
					successor->parent = current;
					successor->G = totalCost;
				}
			}

			// check timeout
			auto elapsed = std::chrono::high_resolution_clock::now() - start_time;
			float seconds = (float)(std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() / 1000.0f);
			if (TimeOutSecond <= seconds)
			{
				// clean up and abort
				g_ReleaseNodes(openSet);
				g_ReleaseNodes(closedSet);

				pathfindresult.PathList.clear();
				pathfindresult.PathFlagList.clear();

				pathfindresult.Result = FR_Error;
				pathfindresult.Reason = FRR_PathFindTimeout;
				return pathfindresult;
			}
		}

#ifdef SHOW_UDEBUG_ASTARMAP
		UMirLogManager::DebugLog(E_LOG_CATEGORY::MIR_CHARACTER, ELogVerbosity::Type::Error,
			FString::Printf(TEXT("End!!!!!!! QueryCount:%d, AreaRestrictCount:%d, SkippingCount:%d"), QueryCount, AreaRestrictCount, SkippingCount));
#endif

		while (current != nullptr)
		{
			pathfindresult.PathList.insert(pathfindresult.PathList.begin(), current->coordinates);
			current = current->parent;
		}

		g_ReleaseNodes(openSet);
		g_ReleaseNodes(closedSet);

		// step 2.
		// do we find path to destination exactly ?
		if (pathfindresult.PathList.size() > 1)
		{
			// check result start and destination is same
			if (pathfindresult.PathList[0] != source ||
				pathfindresult.PathList[pathfindresult.PathList.size() - 1] != target)
			{
				// reset path (we can't use incorrect path list)
				pathfindresult.PathList.clear();

				// as result, we didn't reached to destination

				// find available path as near as we can 
				if (FindOption & FO_FIND_PARTIAL_PATH)
				{
					pathfindresult = FindNearestPathWithOption(source, target, BlockAttribute, History, MinLoc, MaxLoc, TimeOutSecond, FindOption | FO_FIND_PARTIAL_PATH);
				}
				else
				{
					pathfindresult.Result = FR_Error;
				}

				return pathfindresult;
			}

			// exceptional handling code 2019/10/21
			if (CheckAttribute(pathfindresult.PathList[pathfindresult.PathList.size() - 1], BlockAttribute, result) && result)
			{
				// remove last path
				pathfindresult.PathList.pop_back();
			}

			// exceptional handling code 2021/04/12 - can't go any where. pathlist is only one. (processed from exceptional handling code 2019/10/21)
			if (pathfindresult.PathList.size() <= 1)
			{
				pathfindresult.PathList.clear();
				pathfindresult.Result = FR_Error;
				return pathfindresult;
			}
		}
		else
		{
			// if path list is only one, probably can't find cause of block cell is surrounded
			// reset path (we don't use irregular path list)
			pathfindresult.PathList.clear();
			pathfindresult.Result = FR_Error;
			return pathfindresult;
		}

		// completely success
		pathfindresult.Result = FR_Success;

		return pathfindresult;
	}


	FPathFindResult FAStarMap::FindNearestPath(const float *StartLoc, const float *EndLoc, ATTR BlockAttribute, std::vector<FNodeCoordinate> &History, const float* MinLoc, const float *MaxLoc, bool FindForward, float TimeOutSecond)
	{
		FPathFindResult pathfindresult;

		FNodeCoordinate source;
		FNodeCoordinate target;

		// step 0.
		// prerequisite
		// convert coordinates - start
		if (!WorldPosToCellPos(StartLoc, source.x, source.y))
		{
			pathfindresult.Result = FR_Error;
			pathfindresult.Reason = FRR_Invalid_Pos;
			return pathfindresult;
		}
		// convert coordinates - end
		if (!WorldPosToCellPos(EndLoc, target.x, target.y))
		{
			pathfindresult.Result = FR_Error;
			pathfindresult.Reason = FRR_Invalid_Pos;
			return pathfindresult;
		}

		return FindNearestPath(source, target, BlockAttribute, History, MinLoc, MaxLoc, FindForward, TimeOutSecond);
	}

	FPathFindResult FAStarMap::FindNearestPath(int StartCellX, int StartCellY, int EndCellX, int EndCellY, ATTR BlockAttribute, std::vector<FNodeCoordinate> &History, const float* MinLoc, const float *MaxLoc, bool FindForward, float TimeOutSecond)
	{
		FNodeCoordinate start = { StartCellX, StartCellY };
		FNodeCoordinate end = { EndCellX, EndCellY };
		return FindNearestPath(start, end, BlockAttribute, History, MinLoc, MaxLoc, FindForward, TimeOutSecond);
	}

	FPathFindResult FAStarMap::FindNearestPath(FNodeCoordinate &StartCellPos, FNodeCoordinate &EndCellPos, ATTR BlockAttribute, std::vector<FNodeCoordinate> &History, const float* MinLoc, const float *MaxLoc, bool FindForward, float TimeOutSecond)
	{
		FPathFindResult pathfindresult;
		pathfindresult.Reason = FRR_None;
		FNodeCoordinate source = StartCellPos;
		FNodeCoordinate target = EndCellPos;
		bool result = false;

		// find straight path by line algorithm
		std::vector<FNodeCoordinate> newlist = g_GetLinePointList(source.x, source.y, target.x, target.y);
		if (newlist.size() == 0)
		{
			// error or no need to move
			pathfindresult.Result = FR_Error;
			pathfindresult.Reason = FRR_Invalid_Pos;
			return pathfindresult;
		}
		else if (newlist.size() <= 2)
		{
			// can't move. next cell is blocked
			pathfindresult.Result = FR_Success;
			pathfindresult.PathList.push_back(newlist[0]);
			return pathfindresult;
		}

		// find unblocked path from start location.
		bool found = false;

		if (FindForward)
		{
			// find unblocked most far path from start location.
			for (int i = 1; i < static_cast<int32_t>(newlist.size()); i++)
			{
				if (CheckAttribute(newlist[i].x, newlist[i].y, BlockAttribute, result))
				{
					// 2022.02.23 exception. ignore block attribute
					bool ignoreblock = false;

					// reset result for next check
					bool extresult = false;
					if (CheckAttribute(newlist[i].x, newlist[i].y, ATTR_EXTBLOCK_ALLOW_PATHFIND, extresult) && extresult)
					{
						// ignore block attribute
						ignoreblock = true;
					}

					if (result == false || ignoreblock)
					{
						// ok we can go
						// update target destination
						target.x = newlist[i].x;
						target.y = newlist[i].y;
						found = true;
					}
					else
					{
						// path blocked. stop finding
						break;
					}
				}
			}
		}
		else
		{
			// find unblocked near path from end location.
			for (int i = (int)newlist.size() - 1; i > 1; i--)
			{
				if (CheckAttribute(newlist[i].x, newlist[i].y, BlockAttribute, result))
				{
					// 2022.02.23 exception. ignore block attribute
					bool ignoreblock = false;

					// reset result for next check
					bool extresult = false;
					if (CheckAttribute(newlist[i].x, newlist[i].y, ATTR_EXTBLOCK_ALLOW_PATHFIND, extresult) && extresult)
					{
						// ignore block attribute
						ignoreblock = true;
					}

					if (result == false || ignoreblock)
					{
						if (found == false)
						{
							// ok we can go
							// update target destination
							target.x = newlist[i].x;
							target.y = newlist[i].y;
							found = true;
							//break;
						}
					}
					else if (found)
					{
						break;
					}
				}
			}
		}

		if (found == false)
		{
			//// can't move. next cell is probably blocked
			//pathfindresult.Result = FR_Success;
			//pathfindresult.PathList.push_back(newlist[0]);
			//return pathfindresult;

			// 2020.06.01 processed to fail. problem with auto move if surrounded by block
			pathfindresult.Result = FR_Error;
			pathfindresult.PathList.clear();
			pathfindresult.Reason = FRR_Surround_Block;
			return pathfindresult;
		}

		// let's find new path again
		pathfindresult = FindPath(source, target, BlockAttribute, History, MinLoc, MaxLoc, false, TimeOutSecond);

		// change success type
		if (pathfindresult.Result == FR_Success)
		{
			pathfindresult.Result = FR_Partial;
		}

		return pathfindresult;
	}

	FPathFindResult FAStarMap::FindNearestPathWithOption(FNodeCoordinate& StartCellPos, FNodeCoordinate& EndCellPos, ATTR BlockAttribute, std::vector<FNodeCoordinate>& History, const float* MinLoc, const float* MaxLoc, float TimeOutSecond, FOPTION FindOption)
	{
		FPathFindResult pathfindresult;
		pathfindresult.Reason = FRR_None;
		FNodeCoordinate source = StartCellPos;
		FNodeCoordinate target = EndCellPos;
		bool result = false;

		// find straight path by line algorithm
		std::vector<FNodeCoordinate> newlist = g_GetLinePointList(source.x, source.y, target.x, target.y);
		if (newlist.size() == 0)
		{
			// error or no need to move
			pathfindresult.Result = FR_Error;
			pathfindresult.Reason = FRR_Invalid_Pos;
			return pathfindresult;
		}
		else if (newlist.size() <= 2)
		{
			// can't move. next cell is blocked
			pathfindresult.Result = FR_Success;
			pathfindresult.PathList.push_back(newlist[0]);
			return pathfindresult;
		}

		// find unblocked path from start location.
		bool found = false;

		if (FindOption & FO_FIND_FORWARD_PATH)
		{
			// find unblocked most far path from start location.
			for (int i = 1; i < static_cast<int32_t>(newlist.size()); i++)
			{
				if (CheckAttribute(newlist[i].x, newlist[i].y, BlockAttribute, result))
				{
					// 2022.02.23 exception. ignore block attribute
					bool ignoreblock = false;

					// reset result for next check
					bool extresult = false;
					if (CheckAttribute(newlist[i].x, newlist[i].y, ATTR_EXTBLOCK_ALLOW_PATHFIND, extresult) && extresult)
					{
						// ignore block attribute
						ignoreblock = true;
					}

					if (result == false || ignoreblock)
					{
						// ok we can go
						// update target destination
						target.x = newlist[i].x;
						target.y = newlist[i].y;
						found = true;
					}
					else
					{
						// path blocked. stop finding
						break;
					}
				}
			}
		}
		else
		{
			// find unblocked near path from end location.
			for (int i = (int)newlist.size() - 1; i > 1; i--)
			{
				if (CheckAttribute(newlist[i].x, newlist[i].y, BlockAttribute, result))
				{
					// 2022.02.23 exception. ignore block attribute
					bool ignoreblock = false;

					// reset result for next check
					bool extresult = false;
					if (CheckAttribute(newlist[i].x, newlist[i].y, ATTR_EXTBLOCK_ALLOW_PATHFIND, extresult) && extresult)
					{
						// ignore block attribute
						ignoreblock = true;
					}

					if (result == false || ignoreblock)
					{
						if (found == false)
						{
							// ok we can go
							// update target destination
							target.x = newlist[i].x;
							target.y = newlist[i].y;
							found = true;
							//break;
						}
					}
					else if (found)
					{
						break;
					}
				}
			}
		}

		if (found == false)
		{
			//// can't move. next cell is probably blocked
			//pathfindresult.Result = FR_Success;
			//pathfindresult.PathList.push_back(newlist[0]);
			//return pathfindresult;

			// 2020.06.01 processed to fail. problem with auto move if surrounded by block
			pathfindresult.Result = FR_Error;
			pathfindresult.PathList.clear();
			pathfindresult.Reason = FRR_Surround_Block;
			return pathfindresult;
		}

		// let's find new path again
		pathfindresult = FindPathWithOption(source, target, BlockAttribute, History, MinLoc, MaxLoc, TimeOutSecond, FindOption & ~FO_FIND_PARTIAL_PATH);

		// change success type
		if (pathfindresult.Result == FR_Success)
		{
			pathfindresult.Result = FR_Partial;
		}

		return pathfindresult;
	}

	const int ERROR_DISTANCE = 10000000;

	bool FAStarMap::FindNearestNeighborCell(const float *Loc, const float *FromLoc, ATTR BlockAttribute, int &outX, int &outY)
	{
		FNodeCoordinate pos = { 0, 0 };
		FNodeCoordinate from = { 0, 0 };
		bool hasFrom = false;
		int lastdistance = ERROR_DISTANCE;

		// step 0.
		// convert coordinates - pos
		if (!WorldPosToCellPos(Loc, pos.x, pos.y))
		{
			return false;
		}

		// convert coordinates - from
		if (FromLoc != nullptr)
		{
			if (WorldPosToCellPos(FromLoc, from.x, from.y))
			{
				hasFrom = true;
			}
			else
			{
				return false;
			}
		}

		for (int i = 0; i < g_FindDirections; i++)
		{
			int nx = pos.x + g_CWDirection[i].x;
			int ny = pos.y + g_CWDirection[i].y;

			bool result = false;
			if (CheckAttribute(nx, ny, BlockAttribute, result) && !result)
			{
				if (hasFrom)
				{
					// calculate distance
					int dist = g_CalcDistSquaredXY(nx, ny, from.x, from.y);
					if (dist < lastdistance)
					{
						outX = nx;
						outY = ny;
						lastdistance = dist;
					}
				}
				else
				{
					outX = nx;
					outY = ny;
					break;
				}
			}
		}

		if (lastdistance == ERROR_DISTANCE)
		{
			return false;
		}

		return true;
	}

	bool FAStarMap::FindNearestNeighborCell(FNodeCoordinate& DestCellPos, FNodeCoordinate& StartCellPos, ATTR BlockAttribute, FNodeCoordinate& OutNewDestCellPos)
	{
		FNodeCoordinate pos = DestCellPos;
		FNodeCoordinate from = StartCellPos;
		bool hasFrom = true;
		int lastdistance = ERROR_DISTANCE;

		for (int i = 0; i < g_FindDirections; i++)
		{
			int nx = pos.x + g_CWDirection[i].x;
			int ny = pos.y + g_CWDirection[i].y;

			bool result = false;
			if (CheckAttribute(nx, ny, BlockAttribute, result) && !result)
			{
				if (hasFrom)
				{
					// calculate distance
					int dist = g_CalcDistSquaredXY(nx, ny, from.x, from.y);
					if (dist < lastdistance)
					{
						OutNewDestCellPos.x = nx;
						OutNewDestCellPos.y = ny;
						lastdistance = dist;
					
					}
				}
				else
				{
					OutNewDestCellPos.x = nx;
					OutNewDestCellPos.y = ny;
					break;
				}
			}
		}

		if (lastdistance == ERROR_DISTANCE)
		{
			return false;
		}

		return true;
	}

	bool FAStarMap::FindAnyUnblockedNeighborCell(FNodeCoordinate& DestCellPos, ATTR BlockAttribute, FNodeCoordinate& OutNewDestCellPos)
	{
		FNodeCoordinate pos = DestCellPos;

		for (int i = 0; i < g_FindDirections; i++)
		{
			int nx = pos.x + g_CWDirection[i].x;
			int ny = pos.y + g_CWDirection[i].y;

			bool result = false;
			if (CheckAttribute(nx, ny, BlockAttribute, result) && !result)
			{
				OutNewDestCellPos.x = nx;
				OutNewDestCellPos.y = ny;
				return true;
			}
		}

		return false;
	}

	bool FAStarMap::DuplicateCell(FCell &Source, FCell &Target)
	{
		//// memcpy first - do not use mempcy if stl array(such as vector/map) exist in structure
		//memcpy(&Target, &Source, sizeof(FCell));

		// manual copy
		Target.coordinates = Source.coordinates;
		Target.IsValid = Source.IsValid;

		Target.attr = Source.attr;
		Target.center_height = Source.center_height;

		// duplicate camera data
		Target.CameraDataType = Source.CameraDataType;
		if (Source.CameraData)
		{
			if (Target.CameraData == nullptr)
			{
				Target.CameraData = new FCellCameraData;
			}
			memcpy(Target.CameraData, Source.CameraData, sizeof(FCellCameraData));
		}
		else
		{
			if (Target.CameraData != nullptr)
			{
				delete Target.CameraData;
				Target.CameraData = nullptr;
			}
		}

		// clear neighbor distance
		Target.neighbor_distance = nullptr;

		Target.GroundMaterialNum = Source.GroundMaterialNum;
		Target.SWAreaNum = Source.SWAreaNum;

		// remove blockattrlist
		Target.BlockAttrList.clear();

		return true;
	}

	int FAStarMap::CalculatePathListTotalCost(std::vector<FNodeCoordinate> &PathList)
	{
		int TotalCost = 0;

		for (int i = 0; i < (int)PathList.size() - 1; i++)
		{
			int cost = CalculatePathDistance(PathList[i], PathList[i + 1]);
			if (cost != -1)
			{
				TotalCost += cost;
			}
			else
			{
				// error handling code here
				;
			}
		}

		return TotalCost;
	}

	int FAStarMap::CalculatePathDistance(FNodeCoordinate &StartCellPos, FNodeCoordinate &EndCellPos)
	{
		for (int j = 0; j < 8; j++)
		{
			FNodeCoordinate node = { StartCellPos.x + g_Direction[j].x, StartCellPos.y + g_Direction[j].y };
			if (node == EndCellPos)
			{
				return (j < 4) ? 10 : 14;
			}
		}

		return -1;
	}

	void FAStarMap::Optimize(bool left, bool top, bool right, bool bottom)
	{
		// int startx, starty;

		if (left)
		{
			// startx = StartCellX_;
			// starty = StartCellY_;
			bool abort = false;
			ATTR attr;

			int sizex = StartCellX_ + TotalCellCountX_;
			for (int x = StartCellX_; x < sizex; x++)
			{
				// vertical scan
				int sizey = StartCellY_ + TotalCellCountY_;
				for (int y = StartCellY_; y < sizey; y++)
				{
					if (GetAttribute(x, y, attr))
					{
						if (attr != ATTR_UNUSED)
						{
							abort = true;
							break;
						}
					}
					else
					{
						// invalid position requested. skip entire process
						break;
					}

					// delete whole row
					if (y == (sizey - 1))
					{
						int newsize = (TotalCellCountX_ - 1)*TotalCellCountY_;
						FCellBase** newCell = new FCellBase*[newsize];

						// resize array
						for (int i = 0; i < TotalCellCountY_; i++)
						{
							memcpy(
								newCell + i * (TotalCellCountX_ - 1),
								WorldCell_ + i * TotalCellCountX_ + 1,
								sizeof(FCellBase*)*(TotalCellCountX_ - 1));
						}

						delete[] WorldCell_;
						WorldCell_ = newCell;

						StartCellX_++;
						TotalCellCountX_--;
					}
				}

				if (abort)
				{
					break;
				}
			}
		}

		if (right)
		{
			// startx = StartCellX_;
			// starty = StartCellY_;
			bool abort = false;
			ATTR attr;

			int sizex = StartCellX_ + TotalCellCountX_;
			for (int x = sizex - 1; x > StartCellX_; x--)
			{
				// vertical scan
				int sizey = StartCellY_ + TotalCellCountY_;
				for (int y = StartCellY_; y < sizey; y++)
				{
					if (GetAttribute(x, y, attr))
					{
						if (attr != ATTR_UNUSED)
						{
							abort = true;
							break;
						}
					}
					else
					{
						// invalid position requested. skip entire process
						break;
					}

					// delete whole row
					if (y == (sizey - 1))
					{
						int newsize = (TotalCellCountX_ - 1)*TotalCellCountY_;
						FCellBase** newCell = new FCellBase*[newsize];

						// resize array
						for (int i = 0; i < TotalCellCountY_; i++)
						{
							memcpy(
								newCell + i * (TotalCellCountX_ - 1),
								WorldCell_ + i * TotalCellCountX_,
								sizeof(FCellBase*)*(TotalCellCountX_ - 1));
						}

						delete[] WorldCell_;
						WorldCell_ = newCell;

						TotalCellCountX_--;
					}
				}

				if (abort)
				{
					break;
				}
			}
		}

		if (top)
		{
			// startx = StartCellX_;
			// starty = StartCellY_;
			bool abort = false;
			ATTR attr;

			int sizey = StartCellY_ + TotalCellCountY_;
			for (int y = StartCellY_; y < sizey; y++)
			{
				// horizontal scan
				int sizex = StartCellX_ + TotalCellCountX_;
				for (int x = StartCellX_; x < sizex; x++)
				{
					if (GetAttribute(x, y, attr))
					{
						if (attr != ATTR_UNUSED)
						{
							abort = true;
							break;
						}
					}
					else
					{
						// invalid position requested. skip entire process
						break;
					}

					// delete whole line
					if (x == (sizex - 1))
					{
						int newsize = TotalCellCountX_ * (TotalCellCountY_ - 1);
						FCellBase** newCell = new FCellBase*[newsize];

						// resize array
						memcpy(newCell, (WorldCell_ + TotalCellCountX_), sizeof(FCellBase*)*newsize);

						delete[] WorldCell_;
						WorldCell_ = newCell;

						StartCellY_++;
						TotalCellCountY_--;
					}
				}

				if (abort)
				{
					break;
				}
			}
		}
		if (bottom)
		{
			// startx = StartCellX_;
			// starty = StartCellY_;
			bool abort = false;
			ATTR attr;

			int sizey = StartCellY_ + TotalCellCountY_;
			for (int y = sizey - 1; y > StartCellY_; y--)
			{
				// horizontal scan
				int sizex = StartCellX_ + TotalCellCountX_;
				for (int x = StartCellX_; x < sizex; x++)
				{
					if (GetAttribute(x, y, attr))
					{
						if (attr != ATTR_UNUSED)
						{
							abort = true;
							break;
						}
					}
					else
					{
						// invalid position requested. skip entire process
						break;
					}

					// delete whole line
					if (x == (sizex - 1))
					{
						int newsize = TotalCellCountX_ * (TotalCellCountY_ - 1);
						FCellBase** newCell = new FCellBase*[newsize];

						// resize array
						memcpy(newCell, WorldCell_, sizeof(FCellBase*)*newsize);

						delete[] WorldCell_;
						WorldCell_ = newCell;

						TotalCellCountY_--;
					}
				}

				if (abort)
				{
					break;
				}
			}
		}

		// demote to FCellBase from FCell if unused data
		for (int i = 0; i < GetTotalCellCount(); i++)
		{
			// check is 
			FCell* Cell = GetCellPtr(i);
			if (Cell == nullptr)
			{
				// skip it. it's already marked unused
				continue;
			}

			if (Cell->attr == ATTR_UNUSED)
			{
				// process demote
				FCellBase* NewCell = new FCellBase();
				NewCell->coordinates = Cell->coordinates;
				NewCell->IsValid = false;

				// destroy exist
				delete Cell;

				// replace to demoted one
				WorldCell_[i] = NewCell;
			}
		}
	}

	int FAStarMap::CalculateCellDistance(const float *v1, const float *v2)
	{
		FNodeCoordinate source;
		FNodeCoordinate target;

		// step 0.
		// prerequisite
		// convert coordinates - start
		if (!WorldPosToCellPos(v1, source.x, source.y))
		{
			return -1;
		}
		// convert coordinates - end
		if (!WorldPosToCellPos(v2, target.x, target.y))
		{
			return -1;
		}

		if (source == target)
		{
			return 0;
		}

		std::vector<FNodeCoordinate> newlist = g_GetLinePointList(source.x, source.y, target.x, target.y);
		return ((int)(newlist.size()) - 1);
	}

	bool FAStarMap::GetNeighborDistance(int cell_x, int cell_y, int DirIndex, float &distance)
	{
		return GetNeighborDistance(GetCellPtr(cell_x, cell_y), DirIndex, distance);
	}

	bool FAStarMap::GetNeighborDistance(FNodeCoordinate &CellPos, int DirIndex, float &distance)
	{
		return GetNeighborDistance(GetCellPtr(CellPos), DirIndex, distance);
	}

	bool FAStarMap::GetNeighborDistance(FCell* CellPtr, int DirIndex, float &distance)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}
		if (CellPtr->neighbor_distance == nullptr)
		{
			return false;
		}

		if (DirIndex >= NeighborDirCount_)
		{
			return false;
		}

		distance = CellPtr->neighbor_distance[DirIndex];

		return true;
	}

	void FAStarMap::CalculateNeighborDistance()
	{
		int total = TotalCellCountX_ * TotalCellCountY_;
		NeighborDirCount_ = g_FindDirections;

		float curpos[3], destpos[3];
		FCell* curcell, *nextcell;
		for (int i = 0; i < total; i++)
		{
			curcell = GetCellPtr(i);
			if (curcell == nullptr)
			{
				continue;
			}
			CellPosToWorldPos(curcell->coordinates.x, curcell->coordinates.y, curpos);

			// create new
			if (curcell->neighbor_distance == nullptr)
			{
				curcell->neighbor_distance = new float[NeighborDirCount_];
			}

			for (int j = 0; j < NeighborDirCount_; j++)
			{
				int nx = curcell->coordinates.x + g_CWDirection[j].x;
				int ny = curcell->coordinates.y + g_CWDirection[j].y;

				nextcell = GetCellPtr(nx, ny);
				if (nextcell == nullptr)
				{
					curcell->neighbor_distance[j] = 0.0f;
				}
				else
				{
					// calculate distance
					float dx, dy, dz;

					CellPosToWorldPos(curcell->coordinates.x, curcell->coordinates.y, curpos);
					CellPosToWorldPos(nextcell->coordinates.x, nextcell->coordinates.y, destpos);

					dx = (curpos[0] - destpos[0])*(curpos[0] - destpos[0]);
					dy = (curpos[1] - destpos[1])*(curpos[1] - destpos[1]);
					dz = (curpos[2] - destpos[2])*(curpos[2] - destpos[2]);

					curcell->neighbor_distance[j] = (float)sqrt(dx + dy + dz);
				}
			}
		}
	}

	int FAStarMap::GetTotalReplacementCellGroup()
	{
		return (int)ReplacementCells_.size();
	}

	int FAStarMap::GetTotalReplacementCellInGroup(int GroupNum)
	{
		if (GroupNum < 0 || GroupNum >= static_cast<int32_t>(ReplacementCells_.size()))
		{
			return 0;
		}

		return (int)ReplacementCells_[GroupNum].size();
	}

	int FAStarMap::GetEmptyReplacemnetCellGroupNum()
	{
		for (int i = 0; i < (int)ReplacementCells_.size(); i++)
		{
			if (ReplacementCells_[i].size() == 0)
			{
				return i;
			}
		}

		// next add num
		return (int)ReplacementCells_.size();
	}

	bool FAStarMap::GetReplacementCellGroupData(int GroupNum, std::vector<FCell> &CellGroupList)
	{
		if (GroupNum < 0 || GroupNum >= static_cast<int32_t>(ReplacementCells_.size()))
		{
			return 0;
		}

		CellGroupList = ReplacementCells_[GroupNum];

		return true;
	}

	bool FAStarMap::AddReplacementCellData(int GroupNum, FCell &Data)
	{
		if (static_cast<int32_t>(ReplacementCells_.size()) <= GroupNum)
		{
			ReplacementCells_.resize(GroupNum + 1);
		}

		std::vector<FCell> &FCellGroup = ReplacementCells_[GroupNum];

		// duplicate cell 
		FCell newCell;
		InitializeCell(&newCell);
		DuplicateCell(Data, newCell);
		FCellGroup.push_back(newCell);

		return true;
	}

	bool FAStarMap::RemoveReplacementCellData(int GroupNum, int cell_x, int cell_y)
	{
		FNodeCoordinate CellPos = { cell_x, cell_y };

		return RemoveReplacementCellData(GroupNum, CellPos);
	}

	bool FAStarMap::RemoveReplacementCellData(int GroupNum, FNodeCoordinate &CellPos)
	{
		if (static_cast<int32_t>(ReplacementCells_.size()) <= GroupNum)
		{
			return false;
		}

		std::vector<FCell> &FCellGroup = ReplacementCells_[GroupNum];

		for (int i = 0; i < (int)FCellGroup.size(); i++)
		{
			if (FCellGroup[i].coordinates == CellPos)
			{
				DestroyCell(&FCellGroup[i]);

				FCellGroup.erase(FCellGroup.begin() + i);
				return true;
			}
		}

		return false;
	}

	bool FAStarMap::RemoveReplacementCellGroup(int GroupNum)
	{
		if (static_cast<int32_t>(ReplacementCells_.size()) <= GroupNum)
		{
			return false;
		}

		for (int i = 0; i < (int)ReplacementCells_[GroupNum].size(); i++)
		{
			DestroyCell(&(ReplacementCells_[GroupNum][i]));
		}

		ReplacementCells_[GroupNum].clear();

		return true;
	}

	bool FAStarMap::ReplaceCellByGroupNumber(int GroupNum)
	{
		if (GroupNum < 0 || GroupNum >= (int)ReplacementCells_.size())
		{
			return false;
		}

		bool RecalculateDistance = false;

		std::vector<FCell> CellList = ReplacementCells_[GroupNum];

		for (int i = 0; i < (int)CellList.size(); i++)
		{
			FCell &cell = CellList[i];

			// find exist cell
			FCell* curCell = GetCellPtr(cell.coordinates);
			if (curCell == nullptr)
			{
				continue;
			}

			// replace attribute except flexible data
			curCell->attr = (curCell->attr & ATTR_FLEXBLOCKMASK) | cell.attr;

			curCell->center_height = cell.center_height;

			// auto detect recalculate neighborhood distance if being used.
			if (curCell->neighbor_distance)
			{
				RecalculateDistance = true;
			}

			curCell->GroundMaterialNum = cell.GroundMaterialNum;

			// keep block attribute list

			// replace camera data
			curCell->CameraDataType = cell.CameraDataType;
			if (cell.CameraData != nullptr)
			{
				if (curCell->CameraData == nullptr)
				{
					// create new one
					curCell->CameraData = new FCellCameraData;
				}
				memcpy(curCell->CameraData, cell.CameraData, sizeof(FCellCameraData));
			}
			else
			{
				// destroy exist
				if (curCell->CameraData != nullptr)
				{
					delete curCell->CameraData;
					curCell->CameraData = nullptr;
				}
			}
		}

		// server use only.
		if (RecalculateDistance)
		{
			FCell* nextCell;
			float curpos[3], destpos[3];
			for (int i = 0; i < (int)CellList.size(); i++)
			{
				FCell &cell = CellList[i];

				// find exist cell
				FCell* curCell = GetCellPtr(cell.coordinates);
				if (curCell == nullptr)
				{
					continue;
				}
				CellPosToWorldPos(curCell->coordinates.x, curCell->coordinates.y, curpos);

				for (int j = 0; j < NeighborDirCount_; j++)
				{
					int nx = curCell->coordinates.x + g_CWDirection[j].x;
					int ny = curCell->coordinates.y + g_CWDirection[j].y;

					nextCell = GetCellPtr(nx, ny);
					if (nextCell == nullptr)
					{
						curCell->neighbor_distance[j] = 0.0f;
					}
					else
					{
						// calculate distance
						float dx, dy, dz;

						CellPosToWorldPos(nextCell->coordinates.x, nextCell->coordinates.y, destpos);

						dx = (curpos[0] - destpos[0])*(curpos[0] - destpos[0]);
						dy = (curpos[1] - destpos[1])*(curpos[1] - destpos[1]);
						dz = (curpos[2] - destpos[2])*(curpos[2] - destpos[2]);

						curCell->neighbor_distance[j] = (float)sqrt(dx + dy + dz);
					}
				}
			}
		}

		return true;
	}

	bool FAStarMap::UpdateReplacementCellGroup(int GroupNum)
	{
		if (GroupNum < 0 || GroupNum >= (int)ReplacementCells_.size())
		{
			return false;
		}

		std::vector<FCell>& CellList = ReplacementCells_[GroupNum];

		for (int i = 0; i < (int)CellList.size(); i++)
		{
			FCell& cell = CellList[i];

			// find exist cell
			FCell* curCell = GetCellPtr(cell.coordinates);
			if (curCell == nullptr)
			{
				continue;
			}

			DuplicateCell(*curCell, cell);
		}

		return true;
	}
}
