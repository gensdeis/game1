#include "stdafx.h"
#include "AStarMap.h"
//#define SHOW_UDEBUG_ASTARMAP
typedef signed int int32;

#ifdef SHOW_UDEBUG_ASTARMAP
#include "MirLogManager.h"
#include "DrawDebugHelpers.h"
#endif

namespace CSCommon
{
#ifdef SERVER_USE
	void FAStarMap::InitServer()
	{
		Cell_Attr = nullptr;
	}

	void FAStarMap::DestroyServer()
	{
		if (nullptr != Cell_Attr)
		{
			delete[] Cell_Attr;
		}
	}

	void FAStarMap::LoadServerCell()
	{
		TotalCellCount = TotalCellCountX_ * TotalCellCountY_;

		// server tile setting
		Cell_Attr = new ATTR[TotalCellCount];
		for (int i = 0; i < TotalCellCount; i++)
		{
			Cell_Attr[i] = 0;
		}
	}

	bool FAStarMap::IndexToWorldPos(int index, float *outLoc)
	{
		if (0 > index || TotalCellCount <= index)
			return false;

		int x = index % TotalCellCountX_;
		int y = index / TotalCellCountX_;

		if (false == CellPosToWorldPos(x, y, outLoc))
		{
			return false;
		}

		return true;
	}

	int FAStarMap::WorldPosToIndex(const float *Loc)
	{
		int x, y;
		if (false == WorldPosToCellPos(Loc, x, y))
			return INVALID_INDEX;

		return CellPosToIndex(x, y);
	}

	bool FAStarMap::CheckBlock(int cell_x, int cell_y, int32_t &result)
	{
		int index = CellPosToIndex(cell_x, cell_y);

		if (INVALID_INDEX == index)
			return false;

		return CheckAttribute(index, ATTR_BLOCK_ALL, result);
	}

	bool FAStarMap::CheckBlock(int index, int32_t &result)
	{
		return CheckAttribute(index, ATTR_BLOCK_ALL, result);
	}

	bool FAStarMap::CheckAttribute(int cell_x, int cell_y, ATTR Attribute, int32_t &result)
	{
		int index = CellPosToIndex(cell_x, cell_y);

		if (INVALID_INDEX == index)
			return false;

		return CheckAttribute(index, Attribute, result);
	}

	bool FAStarMap::CheckAttribute(int cell_x, int cell_y, ATTR Attribute, bool &result)
	{
		int index = CellPosToIndex(cell_x, cell_y);

		if (INVALID_INDEX == index)
			return false;

		FCell* CellPtr = GetCellPtr(index);
		if (CellPtr == nullptr)
		{
			return false;
		}

		int32_t ret = 0;

		if (ATTR_OVERLAP == (CellPtr->attr & ATTR_OVERLAP))
		{
			ret = (CellPtr->attr & Attribute) ? 1 : 0;
		}
		else
		{
			ret = (CellPtr->attr & Attribute) ? 1 : 0;
			if (0 == ret)
			{
				ret = (Cell_Attr[index] & Attribute) ? 2 : 0;
			}
		}

		result = (ret > 0) ? true : false;

		// check flexible block mask
		//if (Attribute & ATTR_FLEXBLOCKMASK)
		//{
		//	// find in block list
		//	for (int i = 0; i < CellPtr->BlockAttrList.size(); i++)
		//	{
		//		if (CellPtr->BlockAttrList[i].attr & Attribute)
		//		{
		//			result = true;
		//			break;
		//		}
		//	}
		//}

		return true;
	}

	bool FAStarMap::CheckAttribute(FNodeCoordinate& CellPos, ATTR Attribute, bool& result)
	{
		return CheckAttribute(CellPos.x, CellPos.y, Attribute, result);
	}

	bool FAStarMap::CheckAttribute(int index, ATTR Attribute, int32_t &result)
	{
		if (0 > index || TotalCellCount <= index)
			return false;

		FCell* CellPtr = GetCellPtr(index);
		if (CellPtr == nullptr)
		{
			return false;
		}

		if (ATTR_OVERLAP == (CellPtr->attr & ATTR_OVERLAP))
		{
			result = (CellPtr->attr & Attribute) ? 1 : 0;
		}
		else
		{
			result = (CellPtr->attr & Attribute) ? 1 : 0;
			if (0 == result)
			{
				result = (Cell_Attr[index] & Attribute) ? 2 : 0;
			}
		}

		// check flexible block mask
		//if (Attribute & ATTR_FLEXBLOCKMASK)
		//{
		//	// find in block list
		//	for (int i = 0; i < CellPtr->BlockAttrList.size(); i++)
		//	{
		//		if (CellPtr->BlockAttrList[i].attr & Attribute)
		//		{
		//			result = true;
		//			break;
		//		}
		//	}
		//}

		return true;
	}

	bool FAStarMap::CheckAttributeOverlap(int cell_x, int cell_y, ATTR Attribute, int32_t &result)
	{
		int index = CellPosToIndex(cell_x, cell_y);

		if (INVALID_INDEX == index)
			return false;

		return CheckAttributeOverlap(index, Attribute, result);
	}

	bool FAStarMap::CheckAttributeOverlap(int index, ATTR Attribute, int32_t &result)
	{
		if (0 > index || TotalCellCount <= index)
			return false;

		FCell* CellPtr = GetCellPtr(index);
		if (CellPtr == nullptr)
		{
			return false;
		}

		result = ((Cell_Attr[index] | CellPtr->attr) & Attribute) ? 1 : 0;

		// check flexible block mask
		//if (Attribute & ATTR_FLEXBLOCKMASK)
		//{
		//	// find in block list
		//	for (int i = 0; i < CellPtr->BlockAttrList.size(); i++)
		//	{
		//		if (CellPtr->BlockAttrList[i].attr & Attribute)
		//		{
		//			result = true;
		//			break;
		//		}
		//	}
		//}

		return true;
	}

	bool FAStarMap::CheckPathAttribute(int cell_x, int cell_y, ATTR Attribute, int32_t &result)
	{
		int index = CellPosToIndex(cell_x, cell_y);

		if (INVALID_INDEX == index)
			return false;

		return CheckPathAttribute(index, Attribute, result);
	}

	bool FAStarMap::CheckPathAttribute(int index, ATTR Attribute, int32_t &result)
	{
		if (0 > index || TotalCellCount <= index)
			return false;

		FCell* CellPtr = GetCellPtr(index);
		if (CellPtr == nullptr)
		{
			return false;
		}

		result = (CellPtr->attr & Attribute) ? 1 : 0;

		return true;
	}

	bool FAStarMap::ClearAttribute(int cell_x, int cell_y)
	{
		int index = CellPosToIndex(cell_x, cell_y);

		if (INVALID_INDEX == index)
			return false;

		return ClearAttribute(index);
	}

	bool FAStarMap::ClearAttribute(int index)
	{
		if (0 > index || TotalCellCount <= index)
			return false;

		Cell_Attr[index] = 0;

#ifdef _MOVE_LOG
		SERVER_LOG(eServerLogType::eInfo, "ClearAttribute : %d, attr : %d", index, Cell_Attr[index]);
#endif

		return true;
	}

	bool FAStarMap::GetAttribute(int cell_x, int cell_y, ATTR &Attribute, bool IncludeMaterial)
	{
		int index = CellPosToIndex(cell_x, cell_y);

		if (INVALID_INDEX == index)
			return false;

		return GetAttribute(index, Attribute);
	}

	bool FAStarMap::GetAttribute(int index, ATTR &Attribute, bool IncludeMaterial)
	{
		if (0 > index || TotalCellCount <= index)
			return false;

		FCell* CellPtr = GetCellPtr(index);
		if (CellPtr == nullptr)
		{
			return false;
		}

		Attribute = (CellPtr->attr | Cell_Attr[index]);

		return true;
	}

	bool FAStarMap::SetAttribute(int cell_x, int cell_y, ATTR Attribute, bool IncludeMaterial)
	{
		int index = CellPosToIndex(cell_x, cell_y);

		if (INVALID_INDEX == index)
			return false;

		return SetAttribute(index, Attribute);
	}

	bool FAStarMap::SetAttribute(int index, ATTR Attribute, bool IncludeMaterial)
	{
		if (0 > index || TotalCellCount <= index)
			return false;

		FCell* CellPtr = GetCellPtr(index);
		if (CellPtr == nullptr)
		{
			return false;
		}

		Cell_Attr[index] = Attribute;

		return true;
	}

	bool FAStarMap::AddAttribute(int cell_x, int cell_y, ATTR Attribute)
	{
		int index = CellPosToIndex(cell_x, cell_y);

		if (INVALID_INDEX == index)
			return false;

		return AddAttribute(index, Attribute);
	}

	bool FAStarMap::AddAttribute(int index, ATTR Attribute)
	{
		if (0 > index || TotalCellCount <= index)
			return false;

		// add
		Cell_Attr[index] |= Attribute;

#ifdef _MOVE_LOG
		SERVER_LOG(eServerLogType::eInfo, "AddAttribute : %d,  attr : %d", index, Cell_Attr[index]);
#endif

		return true;
	}

	bool FAStarMap::RemoveAttribute(int cell_x, int cell_y, ATTR Attribute)
	{
		int index = CellPosToIndex(cell_x, cell_y);

		if (INVALID_INDEX == index)
			return false;

		return RemoveAttribute(index, Attribute);
	}

	bool FAStarMap::RemoveAttribute(int index, ATTR Attribute)
	{
		if (0 > index || TotalCellCount <= index)
			return false;

		// remove
		Cell_Attr[index] &= ~Attribute;

#ifdef _MOVE_LOG
		SERVER_LOG(eServerLogType::eInfo, "RemoveAttribute : %d, attr : %d", index, Cell_Attr[index]);
#endif

		return true;
	}

	bool FAStarMap::GetCenterHeight(int cell_x, int cell_y, float &height)
	{
		int index = CellPosToIndex(cell_x, cell_y);

		if (INVALID_INDEX == index)
			return false;

		return GetCenterHeight(index, height);
	}

	bool FAStarMap::GetCenterHeight(int index, float &height)
	{
		if (0 > index || TotalCellCount <= index)
			return false;

		FCell* CellPtr = GetCellPtr(index);
		if (CellPtr == nullptr)
		{
			return false;
		}

		height = CellPtr->center_height;

		return true;
	}

	bool FAStarMap::SetCenterHeight(int cell_x, int cell_y, float height)
	{
		int index = CellPosToIndex(cell_x, cell_y);

		if (INVALID_INDEX == index)
			return false;

		return SetCenterHeight(index, height);
	}

	bool FAStarMap::SetCenterHeight(int index, float height)
	{
		if (0 > index || TotalCellCount <= index)
			return false;

		FCell* CellPtr = GetCellPtr(index);
		if (CellPtr == nullptr)
		{
			return false;
		}

		CellPtr->center_height = height;

		return true;
	}

	bool FAStarMap::GetGroundMaterial(int cell_x, int cell_y, int &material)
	{
		int index = CellPosToIndex(cell_x, cell_y);

		if (INVALID_INDEX == index)
			return false;

		return GetGroundMaterial(index, material);
	}

	bool FAStarMap::GetGroundMaterial(int index, int &material)
	{
		if (0 > index || TotalCellCount <= index)
			return false;

		FCell* CellPtr = GetCellPtr(index);
		if (CellPtr == nullptr)
		{
			return false;
		}

		material = CellPtr->GroundMaterialNum;

		return true;
	}

	bool FAStarMap::SetGroundMaterial(int cell_x, int cell_y, int material)
	{
		int index = CellPosToIndex(cell_x, cell_y);

		if (INVALID_INDEX == index)
			return false;

		return SetGroundMaterial(index, material);
	}

	bool FAStarMap::SetGroundMaterial(int index, int material)
	{
		if (0 > index || TotalCellCount <= index)
			return false;

		FCell* CellPtr = GetCellPtr(index);
		if (CellPtr == nullptr)
		{
			return false;
		}

		CellPtr->GroundMaterialNum = (ATTR_NUM)material;

		return true;
	}

	bool FAStarMap::GetAttackZone(FCell* CellPtr, int& zone)
	{
		if (CellPtr == nullptr)
		{
			return false;
		}

		zone = (CellPtr->attr & ATTR_ATTACKZONEMASK) >> 16;

		return true;
	}


	// from bresenham algorithm
	std::vector<FNodeCoordinate> GetLinePointList(int x1, int y1, int x2, int y2)
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

	void GetLinePointList(int x1, int y1, int x2, int y2, std::vector<FNodeCoordinate>& path)
	{
		int x, y, dx, dy, dx1, dy1, px, py, xe, ye; //, i;
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

			//for (i = 0; x < xe; i++)
			for( ; x < xe ; )
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

			//for (i = 0; y < ye; i++)
			for( ; y < ye ; )
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
	}

	std::vector<FNodeCoordinate> FAStarMap::FindPathServer(const float* StartLoc, const float* EndLoc, ATTR BlockAttribute, bool object_check, bool trace_flag)
	{
		std::vector<FNodeCoordinate> path;
		FNodeCoordinate source;		
		if (!WorldPosToCellPos(StartLoc, source.x, source.y))
		{
			return path;
		}

		FNodeCoordinate target;
		if (!WorldPosToCellPos(EndLoc, target.x, target.y))
		{
			return path;
		}

		if (source == target)
		{
			return path;
		}

		int32_t range_x = source.x - target.x;
		int32_t range_y = source.y - target.y;
		int32_t /*direction = -1,*/ abs_x = 0, abs_y = 0;

		if (5 < std::abs(range_x) || 5 < std::abs(range_y))
		{
			if (0 < range_x)
			{
				abs_x = -1;			
			}
			else if (0 > range_x)
			{
				abs_x = 1;
			}

			if (0 < range_y)
			{
				abs_y = -1;
			}
			else if (0 > range_y)
			{
				abs_y = 1;
			}

			if (5 < range_x)
			{
				range_x = 5;
				target.x = source.x - range_x;
			}
			else if (-5 > range_x)
			{
				range_x = -5;
				target.x = source.x - range_x;
			}

			if (5 < range_y)
			{
				range_y = 5;
				target.y = source.y - range_y;
			}
			else if (-5 > range_y)
			{
				range_y = -5;
				target.y = source.y - range_y;
			}
		}

		int32_t result = 0;
		if (false == CheckPathAttribute(target.x, target.y, BlockAttribute, result) || 0 != result)
		{
			if (0 != abs_x || 0 != abs_y)
			{
				int32 new_x = source.x, new_y = source.y, add_x = abs_x, add_y = abs_y;
				bool flag = false;

				for (int32_t i = 1; i < 6; i++)
				{
					if (add_x != 0)
					{
						new_x = source.x + (i * add_x);
						if (false == CheckPathAttribute(new_x, new_y, BlockAttribute, result) || 0 != result)
						{
							new_x = new_x - add_x;
							add_x = 0;
							continue;
						}
					}
					if (add_y != 0)
					{
						new_y = source.y + (i * add_y);
						if (false == CheckPathAttribute(new_x, new_y, BlockAttribute, result) || 0 != result)
						{
							new_y = new_y - add_y;
							add_y = 0;
							continue;
						}
					}

					if (source.x == new_x && source.y == new_y)
					{
						break;
					}

					if (true == CheckPathAttribute(new_x, new_y, BlockAttribute, result) && 0 == result)
					{
						target.x = new_x;
						target.y = new_y;

						range_x = source.x - target.x;
						range_y = source.y - target.y;

						flag = true;
					}

					if (0 == add_x && 0 == add_y)
					{
						break;
					}
				}

				if (false == flag)
				{
					new_x = target.x;
					new_y = target.y;
					add_x = abs_x;
					add_y = abs_y;

					for (int32_t x = 0; x < 11; x++)
					{
						for (int32_t y = 0; y < 11; y++)
						{
							if (add_x != 0)
							{
								new_x = target.x + (x * add_x);
							}

							if (add_y != 0)
							{
								new_y = target.y + (y * add_y);
							}

							if (true == CheckPathAttribute(new_x, new_y, BlockAttribute, result) && 0 == result)
							{
								flag = true;
								target.x = new_x;
								target.y = new_y;
								break;
							}
						}
					}

					if (true == flag)
					{
						range_x = source.x - target.x;
						range_y = source.y - target.y;
					}
				}

				if (source == target)
				{
					return path;
				}
			}
			else
			{
				return path;
			}
		}

		// find straight path 
		{
			// trace_flag 가 true 일 경우에는 해당 로직을 돌려도 처리 되지 않아 pass 처리 - 20201008
			if (false == trace_flag) 
			{
				std::vector<FNodeCoordinate> newlist; GetLinePointList(source.x, source.y, target.x, target.y, newlist);
				int32_t newlist_size = static_cast<int32_t>(newlist.size());

				if (0 < newlist_size) 
				{
					for (int32_t i = 0; i < newlist_size; i++)
					{
						if (0 != i)
						{
							if (true == object_check)
							{
								if (false == CheckAttributeOverlap(newlist[i].x, newlist[i].y, BlockAttribute, result) || 0 != result)
								{
									break;
								}
							}
							else
							{
								if (false == CheckPathAttribute(newlist[i].x, newlist[i].y, BlockAttribute, result) || 0 != result)
								{
									break;
								}
							}
						}

						FNodeCoordinate newcoordi =
						{
							newlist[i].x,
							newlist[i].y,
						};

						path.push_back(newcoordi);
					}

					if (newlist_size == static_cast<int32_t>(path.size()))
					{
						return path;
					}
				}
			}

			path.clear();
		}

		////std::vector<FNodeCoordinate> newlist = GetLinePointList(source.x, source.y, target.x, target.y);
		//std::vector<FNodeCoordinate> newlist; GetLinePointList(source.x, source.y, target.x, target.y, newlist);
		//int32_t newlist_size = static_cast<int32_t>(newlist.size());

		//if(0 < newlist_size)
		//{		
		//	for (int32_t i = 0; i < newlist_size; i++)
		//	{		
		//		if (0 != i && 2 < newlist_size)
		//		{			
		//			if (true == trace_flag && (newlist_size - 1) == i)
		//			{
		//				continue;
		//			}

		//			if (true == object_check)
		//			{
		//				if (false == CheckAttributeOverlap(newlist[i].x, newlist[i].y, BlockAttribute, result) || 0 != result)
		//				{
		//					break;
		//				}
		//			}
		//			else
		//			{
		//				if (false == CheckPathAttribute(newlist[i].x, newlist[i].y, BlockAttribute, result) || 0 != result)
		//				{
		//					break;
		//				}
		//			}
		//		}

		//		FNodeCoordinate newcoordi =
		//		{
		//			newlist[i].x,
		//			newlist[i].y,
		//		};

		//		//path.insert(path.end(), newcoordi);
		//		path.push_back(newcoordi);
		//	}

		//	/*if (true == trace_flag) 
		//	{
		//		if (newlist_size == (path.size() + 1))
		//		{
		//			return path;
		//		}
		//	}
		//	else 
		//	{
		//		if (newlist_size == path.size())
		//		{
		//			return path;
		//		}
		//	}*/
		//	if (newlist_size == path.size())
		//	{
		//		return path;
		//	}
		//}

		//path.clear();

		// find complex path
		FAStarNode* current = nullptr;
		//std::set<FAStarNode*> openSet, closedSet;
		//openSet.insert(new FAStarNode(source));

		std::set<FAStarNode*> openSet;
		openSet.emplace(new FAStarNode(source));
		//std::unordered_map<int32_t, std::vector<FAStarNode*>> closedSet;
		std::unordered_map<int32_t, std::vector<FAStarNode*>> closedSet;
		int32_t closedSetCount = 0;
		


		while (false == openSet.empty())
		{
			current = *openSet.begin();

			for (auto& node : openSet)
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
			
			//if (0 == closedSet.count(current->cooridnates.x)) 
			if(closedSet.end() == closedSet.find(current->coordinates.x))
			{
				closedSet.emplace(current->coordinates.x, std::vector<FAStarNode*>{current});
			}
			else 
			{
				closedSet[current->coordinates.x].push_back(current);
			}
			closedSetCount++;
			
			openSet.erase(std::find(openSet.begin(), openSet.end(), current));		

			for (int i = 0; i < g_FindDirections; i++)
			{
				FNodeCoordinate newcoordi =
				{
					current->coordinates.x + g_Direction[i].x,
					current->coordinates.y + g_Direction[i].y,
				};

				// 타겟지점이 더 작은경우
				if (range_x > 0)
				{
					if (newcoordi.x > source.x + (range_x * 3) + 5 || newcoordi.x < source.x - (range_x * 3) - 5)
					{
						continue;
					}
				}
				else
				{
					if (newcoordi.x < target.x + (range_x * 3) - 5 || newcoordi.x > target.x - (range_x * 3) + 5)
					{
						continue;
					}
				}

				// 타겟지점이 더 작은경우
				if (range_y > 0)
				{
					if (newcoordi.y > source.y + (range_y * 3) + 5 || newcoordi.y < source.y - (range_y * 3) - 5)
					{
						continue;
					}
				}
				else
				{
					if (newcoordi.y < target.y + (range_y * 3) - 5 || newcoordi.y > target.y - (range_y * 3) + 5)
					{
						continue;
					}
				}

				if (true == trace_flag)
				{
					if ((newcoordi.x != source.x || newcoordi.y != source.y)
						&& (newcoordi.x != target.x || newcoordi.y != target.y))
					{
						if (true == object_check)
						{
							if (CheckAttributeOverlap(newcoordi.x, newcoordi.y, BlockAttribute, result) == false || result)
							{
								continue;
							}

							/*if (true == FindNodeOnList(closedSet, newcoordi))
							{
								continue;
							}*/

							auto iter = closedSet.find(newcoordi.x);
							if (closedSet.end() != iter)
							{
								bool is_continue = false;
								for (auto node : iter->second)
								{
									if (node->coordinates == newcoordi)
									{
										is_continue = true;
										break;
									}
								}

								if (true == is_continue) 
								{
									continue;
								}
							}
						}
						else
						{
							if (CheckPathAttribute(newcoordi.x, newcoordi.y, BlockAttribute, result) == false || result)
							{
								continue;
							}

							/*if (true == FindNodeOnList(closedSet, newcoordi))
							{
								continue;
							}*/

							auto iter = closedSet.find(newcoordi.x);
							if (closedSet.end() != iter)
							{
								bool is_continue = false;
								for (auto node : iter->second)
								{
									if (node->coordinates == newcoordi)
									{
										is_continue = true;
										break;
									}
								}

								if (true == is_continue)
								{
									continue;
								}
							}
						}
					}
				}
				else
				{
					if (true == object_check)
					{
						if (CheckAttribute(newcoordi.x, newcoordi.y, BlockAttribute, result) == false || result)
						{
							continue;
						}

						/*if (true == FindNodeOnList(closedSet, newcoordi))
						{
							continue;
						}*/

						auto iter = closedSet.find(newcoordi.x);
						if (closedSet.end() != iter)
						{
							bool is_continue = false;
							for (auto node : iter->second)
							{
								if (node->coordinates == newcoordi)
								{
									is_continue = true;
									break;
								}
							}

							if (true == is_continue)
							{
								continue;
							}
						}
					}
					else
					{						
						if (CheckPathAttribute(newcoordi.x, newcoordi.y, BlockAttribute, result) == false || result)
						{
							continue;
						}

						/*if (true == FindNodeOnList(closedSet, newcoordi)) 
						{
							continue;
						}*/

						auto iter = closedSet.find(newcoordi.x);
						if (closedSet.end() != iter)
						{
							bool is_continue = false;
							for (auto node : iter->second)
							{
								if (node->coordinates == newcoordi)
								{
									is_continue = true;
									break;
								}
							}

							if (true == is_continue)
							{
								continue;
							}
						}
					}
				}

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
		}

		if (2 > closedSetCount)
		{
			g_ReleaseNodes(openSet);
			//g_ReleaseNodes(closedSet);
			ReleaseNodesServer(closedSet);

			return path;
		}

		while (current != nullptr)
		{
			path.insert(path.begin(), current->coordinates);
			FNodeCoordinate old_cooridnates = current->coordinates;
			current = current->parent;
			if (current != nullptr)
			{
				FNodeCoordinate new_cooridnates = current->coordinates;
				int32_t diff_x = std::abs(old_cooridnates.x - new_cooridnates.x);
				int32_t diff_y = std::abs(old_cooridnates.y - new_cooridnates.y);
				if (diff_x > 1 || diff_y > 1)
				{
					path.clear();
					break;
				}
			}
		}

		int32_t check_x = std::abs(target.x - source.x);
		int32_t check_y = std::abs(target.y - source.y);
		FNodeCoordinate end_path = path[path.size() - 1];
		if (target.x + check_x < end_path.x || target.x - check_x > end_path.x
			|| target.y + check_y < end_path.y || target.y - check_y > end_path.y)
		{
			path.clear();
		}

		if (path.size() > 49)
		{
			//path.clear();
		}

		g_ReleaseNodes(openSet);
		//g_ReleaseNodes(closedSet);
		ReleaseNodesServer(closedSet);		
		
		return path;
	}

	bool FAStarMap::TargetPathCheck(const float* CheckLoc, ATTR BlockAttribute)
	{
		FNodeCoordinate target;

		if (false == WorldPosToCellPos(CheckLoc, target.x, target.y))
			return false;

		for (int i = 0; i < g_FindDirections; i++)
		{
			FNodeCoordinate newcoordi =
			{
				target.x + g_Direction[i].x,
				target.y + g_Direction[i].y,
			};

			int32_t result = 0;
			if (true == CheckAttributeOverlap(newcoordi.x, newcoordi.y, BlockAttribute, result) && 0 == result)
			{			
				return true;
			}
		}

		return false;
	}

	void FAStarMap::FindPathServer(const float* StartLoc, const float* EndLoc, ATTR BlockAttribute, bool object_check, bool trace_flag, std::vector<FNodeCoordinate>& path, const int32_t check_target_range)
	{		
		path.clear();

		FNodeCoordinate source;
		if (!WorldPosToCellPos(StartLoc, source.x, source.y))
			return;

		FNodeCoordinate target;
		if (!WorldPosToCellPos(EndLoc, target.x, target.y))
			return;

		if (source == target)
			return;

		int32_t range_x = source.x - target.x;
		int32_t range_y = source.y - target.y;
		int32_t /*direction = -1,*/ abs_x = 0, abs_y = 0;

		if (check_target_range < std::abs(range_x) || check_target_range < std::abs(range_y))
		{
			if (0 < range_x)
			{
				abs_x = -1;
			}
			else if (0 > range_x)
			{
				abs_x = 1;
			}

			if (0 < range_y)
			{
				abs_y = -1;
			}
			else if (0 > range_y)
			{
				abs_y = 1;
			}

			if (check_target_range < range_x)
			{
				range_x = check_target_range;
				target.x = source.x - range_x;
			}
			else if (-check_target_range > range_x)
			{
				range_x = -check_target_range;
				target.x = source.x - range_x;
			}

			if (check_target_range < range_y)
			{
				range_y = check_target_range;
				target.y = source.y - range_y;
			}
			else if (-check_target_range > range_y)
			{
				range_y = -check_target_range;
				target.y = source.y - range_y;
			}
		}

		int32_t result = 0;
		if (false == CheckPathAttribute(target.x, target.y, BlockAttribute, result) || 0 != result)
		{
			if (0 != abs_x || 0 != abs_y)
			{
				int32 new_x = source.x, new_y = source.y, add_x = abs_x, add_y = abs_y;
				bool flag = false;

				for (int32_t i = 1; i < 6; i++)
				{
					if (add_x != 0)
					{
						new_x = source.x + (i * add_x);
						if (false == CheckPathAttribute(new_x, new_y, BlockAttribute, result) || 0 != result)
						{
							new_x = new_x - add_x;
							add_x = 0;
							continue;
						}
					}
					if (add_y != 0)
					{
						new_y = source.y + (i * add_y);
						if (false == CheckPathAttribute(new_x, new_y, BlockAttribute, result) || 0 != result)
						{
							new_y = new_y - add_y;
							add_y = 0;
							continue;
						}
					}

					if (source.x == new_x && source.y == new_y)
					{
						break;
					}

					if (true == CheckPathAttribute(new_x, new_y, BlockAttribute, result) && 0 == result)
					{
						target.x = new_x;
						target.y = new_y;

						range_x = source.x - target.x;
						range_y = source.y - target.y;

						flag = true;
					}

					if (0 == add_x && 0 == add_y)
					{
						break;
					}
				}

				if (false == flag)
				{
					new_x = target.x;
					new_y = target.y;
					add_x = abs_x;
					add_y = abs_y;

					for (int32_t x = 0; x < 11; x++)
					{
						for (int32_t y = 0; y < 11; y++)
						{
							if (add_x != 0)
							{
								new_x = target.x + (x * add_x);
							}

							if (add_y != 0)
							{
								new_y = target.y + (y * add_y);
							}

							if (true == CheckPathAttribute(new_x, new_y, BlockAttribute, result) && 0 == result)
							{
								flag = true;
								target.x = new_x;
								target.y = new_y;
								break;
							}
						}
					}

					if (true == flag)
					{
						range_x = source.x - target.x;
						range_y = source.y - target.y;
					}
				}

				if (source == target)
				{
					return;
				}
			}
			else
			{
				return;
			}
		}

		// find straight path 
		if (false == trace_flag)
		{
			std::vector<FNodeCoordinate> newlist;
			GetLinePointList(source.x, source.y, target.x, target.y, newlist);
			int32_t newlist_size = static_cast<int32_t>(newlist.size());
			if (0 < newlist_size)
			{
				for (int32_t i = 0; i < newlist_size; i++)
				{
					if (0 != i && 2 < newlist_size)
					{
						if (true == object_check)
						{
							if (false == CheckAttributeOverlap(newlist[i].x, newlist[i].y, BlockAttribute, result) || 0 != result)
								break;
						}
						else
						{
							if (false == CheckPathAttribute(newlist[i].x, newlist[i].y, BlockAttribute, result) || 0 != result)
								break;
						}
					}

					path.push_back(FNodeCoordinate{ newlist[i].x , newlist[i].y });
				}

				if (newlist_size == static_cast<int32_t>(path.size()))
				{
					return;
				}
			}

			path.clear();
		}

		// find complex path
		FAStarNode* current = nullptr;
		
		std::unordered_map<int64_t, FAStarNode*> map_open_set;
		int32_t open_set_index_key = CellPosToIndex(source.x, source.y);
		map_open_set.emplace(open_set_index_key, new FAStarNode(source));

		std::unordered_map<int32_t, FAStarNode*> map_closed_set;
		int32_t closedSetCount = 0;
		FAStarNode* last_cur = nullptr;

		while (false == map_open_set.empty())
		{
			if (closedSetCount > 360) // 8 * 3 * 15
			//if (map_closed_set.size() > 360) // 8 * 3 * 15
			{
#ifdef _DEBUG
				SERVER_LOG(mir3d::eServerLogType::eInfo, "FindPathServer closed set count over 360, mpe_open_set count : %d", map_open_set.size());
#endif
				current = nullptr;
				break;
			}

			if (nullptr == last_cur)
			{
				current = map_open_set.begin()->second;
				for (const auto& node : map_open_set)
				{
					if (node.second->GetScore() <= current->GetScore())
					{
						current = node.second;
					}
				}
			}
			else 
			{
				current = last_cur;
			}

			last_cur = nullptr;

			if (current->coordinates == target)
			{
				break;
			}
			
			open_set_index_key = CellPosToIndex(current->coordinates.x, current->coordinates.y);
			if (map_closed_set.end() == map_closed_set.find(open_set_index_key))
			{
				map_closed_set.emplace(open_set_index_key, current);
			}

			closedSetCount++;

			map_open_set.erase(open_set_index_key);
			
			for (int i = 0; i < g_FindDirections; i++)
			{
				FNodeCoordinate newcoordi =
				{
					current->coordinates.x + g_Direction[i].x,
					current->coordinates.y + g_Direction[i].y,
				};

				/*open_set_index_key = CellPosToIndex(newcoordi.x, newcoordi.y);

				if (map_closed_set.end() != map_closed_set.find(open_set_index_key))
				{
					continue;
				}*/
				
				// 타겟지점이 더 작은경우
				if (range_x > 0)
				{
					if (newcoordi.x > source.x + (range_x * 3) + 5 || newcoordi.x < source.x - (range_x * 3) - 5)
					{
						//map_closed_set.emplace(open_set_index_key, nullptr);
						continue;
					}
				}
				else
				{
					if (newcoordi.x < target.x + (range_x * 3) - 5 || newcoordi.x > target.x - (range_x * 3) + 5)
					{
						//map_closed_set.emplace(open_set_index_key, nullptr);
						continue;
					}
				}

				// 타겟지점이 더 작은경우
				if (range_y > 0)
				{
					if (newcoordi.y > source.y + (range_y * 3) + 5 || newcoordi.y < source.y - (range_y * 3) - 5)
					{
						//map_closed_set.emplace(open_set_index_key, nullptr);
						continue;
					}
				}
				else
				{
					if (newcoordi.y < target.y + (range_y * 3) - 5 || newcoordi.y > target.y - (range_y * 3) + 5)
					{
						//map_closed_set.emplace(open_set_index_key, nullptr);
						continue;
					}
				}

				open_set_index_key = CellPosToIndex(newcoordi.x, newcoordi.y);

				if (map_closed_set.end() != map_closed_set.find(open_set_index_key))
				{
					continue;
				}

				if (true == trace_flag)
				{
					if ((newcoordi.x != source.x || newcoordi.y != source.y)
						&& (newcoordi.x != target.x || newcoordi.y != target.y))
					{
						if (true == object_check)
						{
							if (CheckAttributeOverlap(open_set_index_key, BlockAttribute, result) == false || result)
							{
								//map_closed_set.emplace(open_set_index_key, nullptr);
								continue;
							}
						}
						else
						{	
							if (CheckPathAttribute(open_set_index_key, BlockAttribute, result) == false || result)
							{
								//map_closed_set.emplace(open_set_index_key, nullptr);
								continue;
							}
						}

						/*if (closedSet.end() != closedSet.find(open_set_index_key))
						{
							continue;
						}*/
					}
				}
				else
				{
					if (true == object_check)
					{
						if (CheckAttribute(open_set_index_key, BlockAttribute, result) == false || result)
						{
							//map_closed_set.emplace(open_set_index_key, nullptr);
							continue;
						}
					}
					else
					{
						if (CheckPathAttribute(open_set_index_key, BlockAttribute, result) == false || result)
						{
							//map_closed_set.emplace(open_set_index_key, nullptr);
							continue;
						}
					}

					/*if (closedSet.end() != closedSet.find(open_set_index_key))
					{
						continue;
					}*/
				}

				// calculate cost by 4-way or 8-way movement
				int totalCost = current->G + ((i < 4) ? 10 : 14);
				FAStarNode* successor = nullptr;
				auto before_successor = map_open_set.find(open_set_index_key);
				if (map_open_set.end() != before_successor)
				{
					successor = before_successor->second;
				}

				if (successor == nullptr)				
				{
					successor = new FAStarNode(newcoordi, current);
					successor->G = totalCost;
					successor->H = g_Heuristic(successor->coordinates, target);
					map_open_set.emplace(open_set_index_key, successor);
				}
				else if (totalCost < successor->G)
				{
					successor->parent = current;
					successor->G = totalCost;
				}

				if (nullptr == last_cur || last_cur->GetScore() >= successor->GetScore())
				{
					last_cur = successor;
				}

				// target 까지 왔으면 멈춤 처리.
				if (last_cur->coordinates == target)
				{
					break;
				}
			}
		}

		if (2 < check_target_range && 2 > closedSetCount)
		{
			current = nullptr;
		}		

		// 첫번째값 > 마지막경로 : 해당 값이 도착지 인지 먼저 확인
		if (nullptr != current)
		{
			int32_t check_x = std::abs(target.x - source.x);
			int32_t check_y = std::abs(target.y - source.y);
			if (target.x + check_x < current->coordinates.x ||
				target.x - check_x > current->coordinates.x ||
				target.y + check_y < current->coordinates.y ||
				target.y - check_y > current->coordinates.y)
			{
				current = nullptr;
			}

			while (current != nullptr)
			{				
				FNodeCoordinate& old_cooridnates = current->coordinates;
				current = current->parent;
				if (current != nullptr)
				{
					if (std::abs(old_cooridnates.x - current->coordinates.x) > 1 ||
						std::abs(old_cooridnates.y - current->coordinates.y) > 1)
					{
						path.clear();
						break;
					}
				}
				path.insert(path.begin(), old_cooridnates);
			}
		}
		
		/*if (false == path.empty())
		{
			int32_t check_x = std::abs(target.x - source.x);
			int32_t check_y = std::abs(target.y - source.y);
			FNodeCoordinate& end_path = path[path.size() - 1];
			if (target.x + check_x < end_path.x || 
				target.x - check_x > end_path.x || 
				target.y + check_y < end_path.y || 
				target.y - check_y > end_path.y)
			{
				path.clear();
			}
		}*/

		for (auto& item : map_open_set)
		{
			SAFE_DELETE(item.second);
		}
		map_open_set.clear();

		for (auto& item : map_closed_set)
		{
			SAFE_DELETE(item.second);
		}
		map_closed_set.clear();
	}

	std::vector<FNodeCoordinate> FAStarMap::FindPathDirectServer(const float* StartLoc, const float* EndLoc)
	{
		std::vector<FNodeCoordinate> path;
		FNodeCoordinate source;
		if (!WorldPosToCellPos(StartLoc, source.x, source.y))
		{
			return path;
		}

		FNodeCoordinate target;
		if (!WorldPosToCellPos(EndLoc, target.x, target.y))
		{
			return path;
		}

		if (source == target)
		{
			return path;
		}

		// find straight path 
		{
			std::vector<FNodeCoordinate> newlist; 
			GetLinePointList(source.x, source.y, target.x, target.y, newlist);
			
			return newlist;
		}

	}

	void ReleaseNodesServer(std::unordered_map<int32_t, std::vector<FAStarNode*>>& nodes)
	{
		for (auto it = nodes.begin(); it != nodes.end();)
		{
			for (auto& del : it->second)
			{
				delete del;
			}
			it->second.clear();
			it = nodes.erase(it);
		}
		nodes.clear();
	}

	bool FindNodeOnList(std::unordered_map<int32_t, std::vector<FAStarNode*>>& nodes, FNodeCoordinate& coordi) 
	{
		auto iter = nodes.find(coordi.x);
		if (nodes.end() != iter)
		{
			for (auto node : iter->second)
			{
				if (node->coordinates == coordi)
				{
					return true;
				}
			}
		}

		return false;
	}

	//std::vector<FNodeCoordinate> FAStarMap::FindPathServer(const float *StartLoc, const float *EndLoc, ATTR BlockAttribute, bool object_check, bool trace_flag)
	//{
	//	auto start = mir3d::util::mirTime::GetTickMilliCount();
	//	
	//	std::vector<FNodeCoordinate> path;
	//	// path.empty();

	//	FNodeCoordinate source;
	//	FNodeCoordinate target;

	//	if (!WorldPosToCellPos(StartLoc, source.x, source.y))
	//	{
	//		return path;
	//	}

	//	if (!WorldPosToCellPos(EndLoc, target.x, target.y))
	//	{
	//		return path;
	//	}

	//	if (source == target)
	//	{
	//		return path;
	//	}

	//	int32_t range_x = source.x - target.x;
	//	int32_t range_y = source.y - target.y;
	//	int32_t direction = -1;
	//	int32_t abs_x = 0;
	//	int32_t abs_y = 0;
	//	
	//	if (5 < std::abs(range_x) || 5 < std::abs(range_y))
	//	{
	//		if (0 < range_x)
	//		{
	//			abs_x = -1;
	//			if (0 < range_y)
	//			{
	//				abs_y = -1;
	//			}
	//			else if (0 > range_y)
	//			{
	//				abs_y = 1;
	//			}
	//		}
	//		else if (0 > range_x)
	//		{
	//			abs_x = 1;
	//			if (0 < range_y)
	//			{
	//				abs_y = -1;
	//			}
	//			else if (0 > range_y)
	//			{
	//				abs_y = 1;
	//			}
	//		}
	//		else
	//		{
	//			if (0 < range_y)
	//			{
	//				abs_y = -1;
	//			}
	//			else if (0 > range_y)
	//			{
	//				abs_y = 1;
	//			}
	//		}

	//		if (5 < range_x)
	//		{
	//			range_x = 5;
	//			target.x = source.x - range_x;
	//		}
	//		else if (-5 > range_x)
	//		{
	//			range_x = -5;
	//			target.x = source.x - range_x;
	//		}

	//		if (5 < range_y)
	//		{
	//			range_y = 5;
	//			target.y = source.y - range_y;
	//		}
	//		else if (-5 > range_y)
	//		{
	//			range_y = -5;
	//			target.y = source.y - range_y;
	//		}
	//	}

	//	int32_t result = 0;
	//	if (false == CheckPathAttribute(target.x, target.y, BlockAttribute, result) || 0 != result)
	//	{
	//		if (0 != abs_x|| 0 != abs_y)
	//		{
	//			int32 new_x = source.x;
	//			int32 new_y = source.y;
	//			int32 add_x = abs_x;
	//			int32 add_y = abs_y;
	//			bool flag = false;

	//			for (int32_t i = 1; i < 6; i++)
	//			{
	//				if (add_x != 0)
	//				{
	//					new_x = source.x + (i * add_x);
	//					if (false == CheckPathAttribute(new_x, new_y, BlockAttribute, result) || 0 != result)
	//					{
	//						new_x = new_x - add_x;
	//						add_x = 0;
	//						continue;
	//					}
	//				}
	//				if (add_y != 0)
	//				{
	//					new_y = source.y + (i * add_y);
	//					if (false == CheckPathAttribute(new_x, new_y, BlockAttribute, result) || 0 != result)
	//					{
	//						new_y = new_y - add_y;
	//						add_y = 0;
	//						continue;
	//					}
	//				}

	//				if (source.x == new_x && source.y == new_y)
	//				{
	//					break;
	//				}

	//				if (true == CheckPathAttribute(new_x, new_y, BlockAttribute, result) && 0 == result)
	//				{
	//					target.x = new_x;
	//					target.y = new_y;

	//					range_x = source.x - target.x;
	//					range_y = source.y - target.y;

	//					flag = true;
	//				}

	//				if (0 == add_x && 0 == add_y)
	//				{
	//					break;
	//				}
	//			}

	//			if (false == flag)
	//			{
	//				new_x = target.x;
	//				new_y = target.y;
	//				add_x = abs_x;
	//				add_y = abs_y;

	//				for (int32_t x = 0; x < 11; x++)
	//				{
	//					for (int32_t y = 0; y < 11; y++)
	//					{
	//						if (add_x != 0)
	//						{
	//							new_x = target.x + (x * add_x);
	//						}

	//						if (add_y != 0)
	//						{
	//							new_y = target.y + (y * add_y);
	//						}

	//						if (true == CheckPathAttribute(new_x, new_y, BlockAttribute, result) && 0 == result)
	//						{
	//							flag = true;
	//							target.x = new_x;
	//							target.y = new_y;
	//							break;
	//						}
	//					}
	//				}

	//				if (true == flag)
	//				{
	//					range_x = source.x - target.x;
	//					range_y = source.y - target.y;
	//				}
	//			}

	//			if (source == target)
	//			{
	//				//SERVER_LOG(eServerLogType::eInfo, "FAStarMap::FindPathServer direction CheckPathAttribute error !! x : " << target.x << " y : " << target.y;
	//				return path;
	//			}
	//		}
	//		else
	//		{
	//			//SERVER_LOG(eServerLogType::eInfo, "FAStarMap::FindPathServer CheckPathAttribute error !! x : " << target.x << " y : " << target.y;
	//			return path;
	//		}
	//	}

	//	// find straight path 
	//	std::vector<FNodeCoordinate> newlist = GetLinePointList(source.x, source.y, target.x, target.y);
	//	if (0 < newlist.size())
	//	{
	//		for (int i = 0; i < newlist.size(); i++)
	//		{
	//			if (2 < newlist.size() && 0 != i)
	//			{
	//				if (true == trace_flag && (newlist.size() - 1) == i)
	//				{
	//					continue;
	//				}

	//				if (true == object_check)
	//				{
	//					if (false == CheckAttributeOverlap(newlist[i].x, newlist[i].y, BlockAttribute, result) || 0 != result)
	//					{
	//						break;
	//					}
	//				}
	//				else
	//				{
	//					if (false == CheckPathAttribute(newlist[i].x, newlist[i].y, BlockAttribute, result) || 0 != result)
	//					{
	//						break;
	//					}
	//				}
	//			}

	//			FNodeCoordinate newcoordi =
	//			{
	//				newlist[i].x,
	//				newlist[i].y,
	//			};

	//			path.insert(path.end(), newcoordi);
	//		}

	//		if (newlist.size() == path.size())
	//		{
	//			return path;
	//		}
	//	}

	//	path.clear();

	//	// find complex path
	//	FAStarNode* current = nullptr;
	//	std::set<FAStarNode*> openSet, closedSet;
	//	openSet.insert(new FAStarNode(source));

	//	while (!openSet.empty())
	//	{
	//		current = *openSet.begin();
	//		for (auto node : openSet)
	//		{
	//			if (node->GetScore() <= current->GetScore())
	//			{
	//				current = node;
	//			}
	//		}

	//		if (current->cooridnates == target)
	//		{
	//			break;
	//		}

	//		closedSet.insert(current);
	//		openSet.erase(std::find(openSet.begin(), openSet.end(), current));

	//		for (int i = 0; i < g_FindDirections; i++)
	//		{
	//			FNodeCoordinate newcoordi =
	//			{
	//				current->cooridnates.x + g_Direction[i].x,
	//				current->cooridnates.y + g_Direction[i].y,
	//			};

	//			// 타겟지점이 더 작은경우
	//			if (range_x > 0)
	//			{
	//				if (newcoordi.x > source.x + (range_x * 3) + 5 || newcoordi.x < source.x - (range_x * 3) - 5)
	//				{
	//					continue;
	//				}
	//			}
	//			else
	//			{
	//				if (newcoordi.x < target.x + (range_x * 3) - 5 || newcoordi.x > target.x - (range_x * 3) + 5)
	//				{
	//					continue;
	//				}
	//			}

	//			// 타겟지점이 더 작은경우
	//			if (range_y > 0)
	//			{
	//				if (newcoordi.y > source.y + (range_y * 3) + 5 || newcoordi.y < source.y - (range_y * 3) - 5)
	//				{
	//					continue;
	//				}
	//			}
	//			else
	//			{
	//				if (newcoordi.y < target.y + (range_y * 3) - 5 || newcoordi.y > target.y - (range_y * 3) + 5)
	//				{
	//					continue;
	//				}
	//			}

	//			if (true == trace_flag)
	//			{
	//				if ((newcoordi.x != source.x || newcoordi.y != source.y)
	//					&& (newcoordi.x != target.x || newcoordi.y != target.y))
	//				{
	//					if (true == object_check)
	//					{
	//						if (CheckAttributeOverlap(newcoordi.x, newcoordi.y, BlockAttribute, result) == false ||
	//							result || g_FindNodeOnList(closedSet, newcoordi))
	//						{
	//							continue;
	//						}
	//					}
	//					else
	//					{
	//						if (CheckPathAttribute(newcoordi.x, newcoordi.y, BlockAttribute, result) == false ||
	//							result || g_FindNodeOnList(closedSet, newcoordi))
	//						{
	//							continue;
	//						}
	//					}
	//				}
	//			}
	//			else
	//			{
	//				if (true == object_check)
	//				{
	//					if (CheckAttribute(newcoordi.x, newcoordi.y, BlockAttribute, result) == false ||
	//						result || g_FindNodeOnList(closedSet, newcoordi))
	//					{
	//						continue;
	//					}
	//				}
	//				else
	//				{
	//					if (CheckPathAttribute(newcoordi.x, newcoordi.y, BlockAttribute, result) == false ||
	//						result || g_FindNodeOnList(closedSet, newcoordi))
	//					{
	//						continue;
	//					}
	//				}
	//			}

	//			// calculate cost by 4-way or 8-way movement
	//			int totalCost = current->G + ((i < 4) ? 10 : 14);

	//			FAStarNode* successor = g_FindNodeOnList(openSet, newcoordi);
	//			if (successor == nullptr)
	//			{
	//				successor = new FAStarNode(newcoordi, current);
	//				successor->G = totalCost;
	//				successor->H = g_Heuristic(successor->cooridnates, target);
	//				openSet.insert(successor);
	//			}
	//			else if (totalCost < successor->G)
	//			{
	//				successor->parent = current;
	//				successor->G = totalCost;
	//			}
	//		}
	//	}

	//	if (2 > closedSet.size())
	//	{
	//		g_ReleaseNodes(openSet);
	//		g_ReleaseNodes(closedSet);

	//		auto end = mir3d::util::mirTime::GetTickMilliCount();
	//		auto d = end - start;
	//		if (d > 1)
	//		{
	//			SERVER_LOG(eServerLogType::eInfo, "22222 :::::: " << d;
	//		}
	//		

	//		return path;
	//	}

	//	while (current != nullptr)
	//	{
	//		path.insert(path.begin(), current->cooridnates);
	//		FNodeCoordinate old_cooridnates = current->cooridnates;
	//		current = current->parent;
	//		if (current != nullptr)
	//		{
	//			FNodeCoordinate new_cooridnates = current->cooridnates;
	//			int32_t diff_x = std::abs(old_cooridnates.x - new_cooridnates.x);
	//			int32_t diff_y = std::abs(old_cooridnates.y - new_cooridnates.y);
	//			if (diff_x > 1 || diff_y > 1)
	//			{
	//				path.clear();
	//				break;
	//			}
	//		}
	//	}

	//	int32_t check_x = std::abs(target.x - source.x);
	//	int32_t check_y = std::abs(target.y - source.y);
	//	FNodeCoordinate end_path = path[path.size() - 1];
	//	if (target.x + check_x < end_path.x || target.x - check_x > end_path.x
	//		|| target.y + check_y < end_path.y || target.y - check_y > end_path.y)
	//	{
	//		path.clear();
	//	}

	//	if (path.size() > 49)
	//	{
	//		path.clear();
	//	}

	//	g_ReleaseNodes(openSet);
	//	g_ReleaseNodes(closedSet);

	//	auto end = mir3d::util::mirTime::GetTickMilliCount();
	//	auto d = end - start;
	//	if (d > 1) 
	//	{
	//		SERVER_LOG(eServerLogType::eInfo, "33333 :::::: " << d;
	//	}

	//	return path;
	//}

	/*std::vector<int32_t> FAStarMap::GetSkillArea(const float *StartLoc, std::vector<mir3d::table::vector_2d>* list)
	{
		std::vector<int32_t> out_list;
		int32_t center_index = WorldPosToIndex(StartLoc);
		if (INVALID_INDEX == center_index)
		{
			return out_list;
		}

		for (auto item : *list)
		{
			std::vector<float> target_pos;
			target_pos.emplace_back(StartLoc[0]);
			target_pos.emplace_back(StartLoc[1]);
			target_pos[0] += item.x * GetCellSizeX();
			target_pos[1] += item.y * GetCellSizeY();

			int32_t target_index = WorldPosToIndex(target_pos.data());
			out_list.emplace_back(target_index);
		}

		return out_list;
	}*/
#endif
}

