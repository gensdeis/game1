#include "stdafx.h"
#include "AStarMap.h"
#include "AStarMap_OldVersion.h"

namespace CSCommon
{
	// file handling
	const int ASTARMAP_MAGIC = 'A' << 24 | 'S' << 16 | 'T' << 8 | 'R'; //'ASTR';
	//const int ASTARMAP_VERSION = 1;	// first release version
	//const int ASTARMAP_VERSION = 2;	// 2019.06.05, to add support neighbor access data
	//const int ASTARMAP_VERSION = 1;	// 2019.06.17, to removed neighbor access data. version roll-back
	//const int ASTARMAP_VERSION = 3;	// 2019.07.02, FCell structure changed
	//const int ASTARMAP_VERSION = 4;	// 2019.10.15, FCell structure changed. added extra_data. moved ground material data to extra data
	//const int ASTARMAP_VERSION = 5;	// 2019.10.30, FCell structure changed. added camera data
	//const int ASTARMAP_VERSION = 6;		// 2019.11.04, FCell structure changed - added siege warfare area number, added Extra Cell Data for replacement
	//const int ASTARMAP_VERSION = 7;		// 2020.01.08, FCellCameraData structure changed - added and distance for mobile, changed distance to distance_pc
	const int ASTARMAP_VERSION = 8;		// 2021.12.16, FCellCameraData exclude from .nav file. save to seperate file (.cam)

	const int ASTARCAM_MAGIC = 'A' << 24 | 'C' << 16 | 'A' << 8 | 'M'; //'ACAM';
	//const int ASTARCAM_VERSION = 1;		// 2021.12.16, FCellCameraData exclude from .nav file. save to seperate file (.cam)
	const int ASTARCAM_VERSION = 2;		// 2021.12.17, added action_type

	const float ASTARCAM_DEFAULT_TILE_ROTATION_SPEED = 0.1f;
	const float ASTARCAM_DEFAULT_TILE_RESET_TIME = 2.0f;

	bool FAStarMap::ReadCell_V1(FILE* fp, FCellBase** Cell)
	{
		FCell_V1 cell;

		fread(&cell, sizeof(FCell_V1), 1, fp);

		FCell* ReadCell = new FCell();

		ReadCell->IsValid = true;
		ReadCell->attr = cell.attr;
		ReadCell->center_height = cell.center_height;
		ReadCell->coordinates = cell.coordinates;
		ReadCell->neighbor_distance = nullptr;
		ReadCell->BlockAttrList.clear();

		// convert to v4
		ReadCell->GroundMaterialNum = (cell.attr & ATTR_GNDMTRLMASK_OBSOLETED) >> 12;
		ReadCell->attr &= ~ATTR_GNDMTRLMASK_OBSOLETED;

		// convert to v5
		ReadCell->CameraDataType = CAMERATYPE_NONE;
		ReadCell->CameraData = nullptr;

		// convert to v6
		ReadCell->SWAreaNum = ATTR_SW_AREA_NONE;

		*Cell = ReadCell;

		return true;
	}

	bool FAStarMap::ReadCell_V2(FILE* fp, FCellBase** Cell)
	{
		FCellBase cell;

		fread(&(cell.coordinates), sizeof(FNodeCoordinate), 1, fp);
		fread(&(cell.IsValid), sizeof(bool), 1, fp);

		if (cell.IsValid)
		{
			FCell* ReadCell = new FCell();
			ReadCell->coordinates = cell.coordinates;
			ReadCell->IsValid = cell.IsValid;

			OLD_ATTR attr;
			fread(&attr, sizeof(OLD_ATTR), 1, fp);
			ReadCell->attr = attr;
			fread(&(ReadCell->center_height), sizeof(float), 1, fp);
			ReadCell->neighbor_distance = nullptr;

			// convert to v4
			ReadCell->GroundMaterialNum = (attr & ATTR_GNDMTRLMASK_OBSOLETED) >> 12;
			ReadCell->attr &= ~ATTR_GNDMTRLMASK_OBSOLETED;

			// convert to v5
			ReadCell->CameraDataType = CAMERATYPE_NONE;
			ReadCell->CameraData = nullptr;

			// convert to v6
			ReadCell->SWAreaNum = ATTR_SW_AREA_NONE;

			*Cell = ReadCell;
		}
		else
		{
			FCellBase* ReadCell = new FCellBase();
			ReadCell->coordinates = cell.coordinates;
			ReadCell->IsValid = cell.IsValid;
			*Cell = ReadCell;
		}

		return true;
	}


	bool FAStarMap::ReadCell_V4(FILE* fp, FCellBase** Cell)
	{
		FCellBase cell;

		fread(&(cell.coordinates), sizeof(FNodeCoordinate), 1, fp);
		fread(&(cell.IsValid), sizeof(bool), 1, fp);

		if (cell.IsValid)
		{
			FCell* ReadCell = new FCell();
			ReadCell->coordinates = cell.coordinates;
			ReadCell->IsValid = cell.IsValid;

			fread(&(ReadCell->attr), sizeof(ATTR), 1, fp);
			fread(&(ReadCell->center_height), sizeof(float), 1, fp);

			ReadCell->neighbor_distance = nullptr;

			fread(&(ReadCell->GroundMaterialNum), sizeof(ATTR_NUM), 1, fp);

			// convert to v5
			ReadCell->CameraDataType = CAMERATYPE_NONE;
			ReadCell->CameraData = nullptr;

			// convert to v6
			ReadCell->SWAreaNum = ATTR_SW_AREA_NONE;

			*Cell = ReadCell;
		}
		else
		{
			FCellBase* ReadCell = new FCellBase();
			ReadCell->coordinates = cell.coordinates;
			ReadCell->IsValid = cell.IsValid;
			*Cell = ReadCell;
		}

		return true;
	}

	bool FAStarMap::ReadCell_V5(FILE* fp, FCellBase** Cell)
	{
		FCellBase cell;

		fread(&(cell.coordinates), sizeof(FNodeCoordinate), 1, fp);
		fread(&(cell.IsValid), sizeof(bool), 1, fp);

		if (cell.IsValid)
		{
			FCell* ReadCell = new FCell();
			ReadCell->coordinates = cell.coordinates;
			ReadCell->IsValid = cell.IsValid;

			fread(&(ReadCell->attr), sizeof(ATTR), 1, fp);
			fread(&(ReadCell->center_height), sizeof(float), 1, fp);

			ReadCell->neighbor_distance = nullptr;

			fread(&(ReadCell->GroundMaterialNum), sizeof(ATTR_NUM), 1, fp);

			fread(&(ReadCell->CameraDataType), sizeof(CAMERA_TYPE), 1, fp);
			if (ReadCell->CameraDataType != CAMERATYPE_NONE)
			{
				ReadCell->CameraData = new FCellCameraData;
				//fread(ReadCell->CameraData, sizeof(FCellCameraData), 1, fp);

				FCellCameraData_V5 cameradata;
				fread(&cameradata, sizeof(FCellCameraData_V5), 1, fp);

				// convert v5 to v7
				ReadCell->CameraData->tile_rotation_speed = ASTARCAM_DEFAULT_TILE_ROTATION_SPEED;
				ReadCell->CameraData->tile_reset_time = ASTARCAM_DEFAULT_TILE_RESET_TIME;
				ReadCell->CameraData->rot[0] = cameradata.rot[0];
				ReadCell->CameraData->rot[1] = cameradata.rot[1];
				ReadCell->CameraData->action_type = 0;
			}
			else
			{
				ReadCell->CameraData = nullptr;
			}

			// convert to v6
			ReadCell->SWAreaNum = ATTR_SW_AREA_NONE;

			*Cell = ReadCell;
		}
		else
		{
			FCellBase* ReadCell = new FCellBase();
			ReadCell->coordinates = cell.coordinates;
			ReadCell->IsValid = cell.IsValid;
			*Cell = ReadCell;
		}

		return true;
	}

	bool FAStarMap::ReadCell_V6(FILE* fp, FCellBase** Cell)
	{
		FCellBase cell;

		fread(&(cell.coordinates), sizeof(FNodeCoordinate), 1, fp);
		fread(&(cell.IsValid), sizeof(bool), 1, fp);

		if (cell.IsValid)
		{
			FCell* ReadCell = new FCell();
			ReadCell->coordinates = cell.coordinates;
			ReadCell->IsValid = cell.IsValid;

			fread(&(ReadCell->attr), sizeof(ATTR), 1, fp);
			fread(&(ReadCell->center_height), sizeof(float), 1, fp);

			ReadCell->neighbor_distance = nullptr;

			fread(&(ReadCell->GroundMaterialNum), sizeof(ATTR_NUM), 1, fp);

			fread(&(ReadCell->CameraDataType), sizeof(CAMERA_TYPE), 1, fp);
			if (ReadCell->CameraDataType != CAMERATYPE_NONE)
			{
				ReadCell->CameraData = new FCellCameraData;
				//fread(ReadCell->CameraData, sizeof(FCellCameraData), 1, fp);

				FCellCameraData_V5 cameradata;
				fread(&cameradata, sizeof(FCellCameraData_V5), 1, fp);

				// convert v5 to v7
				ReadCell->CameraData->tile_rotation_speed = ASTARCAM_DEFAULT_TILE_ROTATION_SPEED;
				ReadCell->CameraData->tile_reset_time = ASTARCAM_DEFAULT_TILE_RESET_TIME;
				ReadCell->CameraData->rot[0] = cameradata.rot[0];
				ReadCell->CameraData->rot[1] = cameradata.rot[1];

				// v8
				ReadCell->CameraData->action_type = 0;
			}
			else
			{
				ReadCell->CameraData = nullptr;
			}

			fread(&(ReadCell->SWAreaNum), sizeof(ATTR_NUM), 1, fp);

			*Cell = ReadCell;
		}
		else
		{
			FCellBase* ReadCell = new FCellBase();
			ReadCell->coordinates = cell.coordinates;
			ReadCell->IsValid = cell.IsValid;
			*Cell = ReadCell;
		}

		return true;
	}

	bool FAStarMap::ReadCell_V7(FILE* fp, FCellBase** Cell)
	{
		FCellBase cell;

		fread(&(cell.coordinates), sizeof(FNodeCoordinate), 1, fp);
		fread(&(cell.IsValid), sizeof(bool), 1, fp);

		if (cell.IsValid)
		{
			FCell* ReadCell = new FCell();
			ReadCell->coordinates = cell.coordinates;
			ReadCell->IsValid = cell.IsValid;

			fread(&(ReadCell->attr), sizeof(ATTR), 1, fp);
			fread(&(ReadCell->center_height), sizeof(float), 1, fp);

			ReadCell->neighbor_distance = nullptr;

			fread(&(ReadCell->GroundMaterialNum), sizeof(ATTR_NUM), 1, fp);

			fread(&(ReadCell->CameraDataType), sizeof(CAMERA_TYPE), 1, fp);
			if (ReadCell->CameraDataType != CAMERATYPE_NONE)
			{
				ReadCell->CameraData = new FCellCameraData;
				fread(ReadCell->CameraData, sizeof(FCellCameraData_V7), 1, fp);

				// v8
				ReadCell->CameraData->action_type = 0;
			}
			else
			{
				ReadCell->CameraData = nullptr;
			}

			fread(&(ReadCell->SWAreaNum), sizeof(ATTR_NUM), 1, fp);

			*Cell = ReadCell;
		}
		else
		{
			FCellBase* ReadCell = new FCellBase();
			ReadCell->coordinates = cell.coordinates;
			ReadCell->IsValid = cell.IsValid;
			*Cell = ReadCell;
		}

		return true;
	}

	bool FAStarMap::ReadCell_V8(FILE* fp, FCellBase** Cell)
	{
		FCellBase cell;

		fread(&(cell.coordinates), sizeof(FNodeCoordinate), 1, fp);
		fread(&(cell.IsValid), sizeof(bool), 1, fp);

		if (cell.IsValid)
		{
			FCell* ReadCell = new FCell();
			ReadCell->coordinates = cell.coordinates;
			ReadCell->IsValid = cell.IsValid;

			fread(&(ReadCell->attr), sizeof(ATTR), 1, fp);
			fread(&(ReadCell->center_height), sizeof(float), 1, fp);

			ReadCell->neighbor_distance = nullptr;

			fread(&(ReadCell->GroundMaterialNum), sizeof(ATTR_NUM), 1, fp);

			// ignore current camera data type. set to none. data type updated when camera data is loaded
			fread(&(ReadCell->CameraDataType), sizeof(CAMERA_TYPE), 1, fp);
			ReadCell->CameraDataType = CAMERATYPE_NONE;

			fread(&(ReadCell->SWAreaNum), sizeof(ATTR_NUM), 1, fp);

			*Cell = ReadCell;
		}
		else
		{
			FCellBase* ReadCell = new FCellBase();
			ReadCell->coordinates = cell.coordinates;
			ReadCell->IsValid = cell.IsValid;
			*Cell = ReadCell;
		}

		return true;
	}

	bool FAStarMap::ReadCellExtraData_V6(FILE* fp, std::vector<std::vector<FCell>> &ExtraData)
	{
		ExtraData.clear();

		bool hasExtraData;
		fread(&hasExtraData, sizeof(bool), 1, fp);
		if (!hasExtraData)
		{
			return true;
		}

		int totalgroups;
		fread(&totalgroups, sizeof(int), 1, fp);
		ExtraData.resize(totalgroups);

		for (int i = 0; i < totalgroups; i++)
		{
			std::vector<FCell> &cells = ExtraData[i];

			// read total count
			int total;
			fread(&total, sizeof(int), 1, fp);
			for (int j = 0; j < total; j++)
			{
				FCellBase* ReadBaseCell;
				ReadCell_V6(fp, &ReadBaseCell);

				if (ReadBaseCell && ReadBaseCell->IsValid)
				{
					FCell* ReadCell = (FCell *)ReadBaseCell;
					FCell cell;
					InitializeCell(&cell);
					DuplicateCell(*ReadCell, cell);
					
					cells.push_back(cell);

					DestroyCell(ReadCell);
					delete ReadCell;
				}
				else
				{
					delete ReadBaseCell;
				}
			}
		}

		return true;
	}

	bool FAStarMap::ReadCellExtraData_V7(FILE* fp, std::vector<std::vector<FCell>> &ExtraData)
	{
		ExtraData.clear();

		bool hasExtraData;
		fread(&hasExtraData, sizeof(bool), 1, fp);
		if (!hasExtraData)
		{
			return true;
		}

		int totalgroups;
		fread(&totalgroups, sizeof(int), 1, fp);
		ExtraData.resize(totalgroups);

		for (int i = 0; i < totalgroups; i++)
		{
			std::vector<FCell> &cells = ExtraData[i];

			// read total count
			int total;
			fread(&total, sizeof(int), 1, fp);
			for (int j = 0; j < total; j++)
			{
				FCellBase* ReadBaseCell;
				ReadCell_V7(fp, &ReadBaseCell);

				if (ReadBaseCell && ReadBaseCell->IsValid)
				{
					FCell* ReadCell = (FCell *)ReadBaseCell;
					FCell cell;
					DuplicateCell(*ReadCell, cell);

					cells.push_back(cell);

					DestroyCell(ReadCell);
					delete ReadCell;
				}
				else
				{
					delete ReadBaseCell;
				}
			}
		}

		return true;
	}

	bool FAStarMap::ReadCellExtraData_V8(FILE* fp, std::vector<std::vector<FCell>>& ExtraData)
	{
		ExtraData.clear();

		bool hasExtraData;
		fread(&hasExtraData, sizeof(bool), 1, fp);
		if (!hasExtraData)
		{
			return true;
		}

		int totalgroups;
		fread(&totalgroups, sizeof(int), 1, fp);
		ExtraData.resize(totalgroups);

		for (int i = 0; i < totalgroups; i++)
		{
			std::vector<FCell>& cells = ExtraData[i];

			// read total count
			int total;
			fread(&total, sizeof(int), 1, fp);
			for (int j = 0; j < total; j++)
			{
				FCellBase* ReadBaseCell;
				ReadCell_V8(fp, &ReadBaseCell);

				if (ReadBaseCell && ReadBaseCell->IsValid)
				{
					FCell* ReadCell = (FCell*)ReadBaseCell;
					FCell cell;
					InitializeCell(&cell);
					DuplicateCell(*ReadCell, cell);

					cells.push_back(cell);

					DestroyCell(ReadCell);
					delete ReadCell;
				}
				else
				{
					delete ReadBaseCell;
				}
			}
		}

		return true;
	}

	bool FAStarMap::WriteCell(FILE* fp, FCellBase* Cell)
	{
		if (Cell->IsValid)
		{
			return WriteCell(fp, (FCell *)Cell);
		}

		fwrite(&(Cell->coordinates), sizeof(FNodeCoordinate), 1, fp);
		fwrite(&(Cell->IsValid), sizeof(bool), 1, fp);
		
		return true;
	}

	bool FAStarMap::WriteCell(FILE* fp, FCell* Cell)
	{
		fwrite(&(Cell->coordinates), sizeof(FNodeCoordinate), 1, fp);
		fwrite(&(Cell->IsValid), sizeof(bool), 1, fp);

		// check attribute integrity
		{
			// 1. ATTR_FORCEUSE_NORMALPATH always need ATTR_BLOCK attribute
			if (Cell->attr & ATTR_FORCEUSE_NORMALPATH)
			{
				if ((Cell->attr & ATTR_BLOCK) == 0x00)
				{
					// remove ATTR_FORCEUSE_NORMALPATH attribute
					Cell->attr &= ~ATTR_FORCEUSE_NORMALPATH;
				}
			}
		}

		fwrite(&(Cell->attr), sizeof(ATTR), 1, fp);
		fwrite(&(Cell->center_height), sizeof(float), 1, fp);

		fwrite(&(Cell->GroundMaterialNum), sizeof(ATTR_NUM), 1, fp);

		//fwrite(&(Cell->CameraDataType), sizeof(CAMERA_TYPE), 1, fp);
		CAMERA_TYPE CameraDataType = CAMERATYPE_NONE;
		fwrite(&CameraDataType, sizeof(CAMERA_TYPE), 1, fp);

		fwrite(&(Cell->SWAreaNum), sizeof(ATTR_NUM), 1, fp);

		return true;
	}

	bool FAStarMap::WriteCellExtraData(FILE* fp, std::vector<std::vector<FCell>> &ExtraData)
	{
		bool hasExtraData = (ExtraData.size() > 0) ? true : false;
		fwrite(&hasExtraData, sizeof(bool), 1, fp);
		if (hasExtraData == false)
		{
			return true;
		}

		// write group number and total count
		int totalgroups = (int)ExtraData.size();
		fwrite(&totalgroups, sizeof(int), 1, fp);

		for (int i = 0; i < totalgroups; i++)
		{
			std::vector<FCell> cells = ExtraData[i];

			// write total count
			int total = (int)cells.size();
			fwrite(&total, sizeof(int), 1, fp);

			for (int j = 0; j < total; j++)
			{
				WriteCell(fp, &(cells[j]));
			}
		}

		return true;
	}

	// first initial release version
	bool FAStarMap::Load_Version1(FILE* fp)
	{
		DestroyCell();

		fread(&TotalCellCountX_, sizeof(int), 1, fp);
		fread(&TotalCellCountY_, sizeof(int), 1, fp);

		fread(&StartCellX_, sizeof(int), 1, fp);
		fread(&StartCellY_, sizeof(int), 1, fp);

		fread(&CELL_SIZE_X_, sizeof(int), 1, fp);
		fread(&CELL_SIZE_Y_, sizeof(int), 1, fp);

		int total = TotalCellCountX_ * TotalCellCountY_;

		// create memory and initialize
		WorldCell_ = new FCellBase*[total];
		memset(WorldCell_, 0, sizeof(FCellBase*)*total);

		// read chunk data
		for (int i = 0; i < total; i++)
		{
			ReadCell_V1(fp, (WorldCell_ + i));
		}

		return true;
	}

	// add support neighbor access -> unused
	bool FAStarMap::Load_Version2(FILE* fp)
	{
		DestroyCell();

		fread(&TotalCellCountX_, sizeof(int), 1, fp);
		fread(&TotalCellCountY_, sizeof(int), 1, fp);

		fread(&StartCellX_, sizeof(int), 1, fp);
		fread(&StartCellY_, sizeof(int), 1, fp);

		fread(&CELL_SIZE_X_, sizeof(int), 1, fp);
		fread(&CELL_SIZE_Y_, sizeof(int), 1, fp);

		int total = TotalCellCountX_ * TotalCellCountY_;

		// create memory and initialize
		WorldCell_ = new FCellBase*[total];
		memset(WorldCell_, 0, sizeof(FCellBase*)*total);

		// read chunk data
		for (int i = 0; i < total; i++)
		{
			ReadCell_V1(fp, (WorldCell_ + i));
		}

		// read neighbor access data -> don't need to read
		//bool neighbor_access;
		//fread(&neighbor_access, sizeof(bool), 1, fp);

		//if (neighbor_access)
		//{
		//	// read total directions
		//	fread(&NeighborDirCount_, sizeof(int), 1, fp);

		//	for (int j = 0; j < total; j++)
		//	{
		//		WorldCell_[j].neighbor_access = new int[NeighborDirCount_];
		//		fread(WorldCell_[j].neighbor_access, sizeof(int), NeighborDirCount_, fp);
		//	}
		//}

		return true;
	}

	bool FAStarMap::Load_Version3(FILE* fp)
	{
		DestroyCell();

		fread(&TotalCellCountX_, sizeof(int), 1, fp);
		fread(&TotalCellCountY_, sizeof(int), 1, fp);

		fread(&StartCellX_, sizeof(int), 1, fp);
		fread(&StartCellY_, sizeof(int), 1, fp);

		fread(&CELL_SIZE_X_, sizeof(int), 1, fp);
		fread(&CELL_SIZE_Y_, sizeof(int), 1, fp);

		int total = TotalCellCountX_ * TotalCellCountY_;

		// create memory and initialize
		WorldCell_ = new FCellBase*[total];
		memset(WorldCell_, 0, sizeof(FCellBase*)*total);

		// read chunk data
		for (int i = 0; i < total; i++)
		{
			ReadCell_V2(fp, (WorldCell_ + i));
		}

		return true;
	}

	bool FAStarMap::Load_Version4(FILE* fp)
	{
		DestroyCell();

		fread(&TotalCellCountX_, sizeof(int), 1, fp);
		fread(&TotalCellCountY_, sizeof(int), 1, fp);

		fread(&StartCellX_, sizeof(int), 1, fp);
		fread(&StartCellY_, sizeof(int), 1, fp);

		fread(&CELL_SIZE_X_, sizeof(int), 1, fp);
		fread(&CELL_SIZE_Y_, sizeof(int), 1, fp);

		int total = TotalCellCountX_ * TotalCellCountY_;

		// create memory and initialize
		WorldCell_ = new FCellBase*[total];
		memset(WorldCell_, 0, sizeof(FCellBase*)*total);

		// read chunk data
		for (int i = 0; i < total; i++)
		{
			ReadCell_V4(fp, (WorldCell_ + i));
		}

		return true;
	}

	bool FAStarMap::Load_Version5(FILE* fp)
	{
		DestroyCell();

		fread(&TotalCellCountX_, sizeof(int), 1, fp);
		fread(&TotalCellCountY_, sizeof(int), 1, fp);

		fread(&StartCellX_, sizeof(int), 1, fp);
		fread(&StartCellY_, sizeof(int), 1, fp);

		fread(&CELL_SIZE_X_, sizeof(int), 1, fp);
		fread(&CELL_SIZE_Y_, sizeof(int), 1, fp);

		int total = TotalCellCountX_ * TotalCellCountY_;

		// create memory and initialize
		WorldCell_ = new FCellBase*[total];
		memset(WorldCell_, 0, sizeof(FCellBase*)*total);

		// read chunk data
		for (int i = 0; i < total; i++)
		{
			ReadCell_V5(fp, (WorldCell_ + i));
		}

		return true;
	}

	bool FAStarMap::Load_Version6(FILE* fp)
	{
		DestroyCell();

		fread(&TotalCellCountX_, sizeof(int), 1, fp);
		fread(&TotalCellCountY_, sizeof(int), 1, fp);

		fread(&StartCellX_, sizeof(int), 1, fp);
		fread(&StartCellY_, sizeof(int), 1, fp);

		fread(&CELL_SIZE_X_, sizeof(int), 1, fp);
		fread(&CELL_SIZE_Y_, sizeof(int), 1, fp);

		int total = TotalCellCountX_ * TotalCellCountY_;

		// create memory and initialize
		WorldCell_ = new FCellBase*[total];
		memset(WorldCell_, 0, sizeof(FCellBase*)*total);

		// read chunk data
		for (int i = 0; i < total; i++)
		{
			ReadCell_V6(fp, (WorldCell_ + i));
		}

		// read extra data
		ReadCellExtraData_V6(fp, ReplacementCells_);

		return true;
	}

	bool FAStarMap::Load_Version7(FILE* fp)
	{
		DestroyCell();

		fread(&TotalCellCountX_, sizeof(int), 1, fp);
		fread(&TotalCellCountY_, sizeof(int), 1, fp);

		fread(&StartCellX_, sizeof(int), 1, fp);
		fread(&StartCellY_, sizeof(int), 1, fp);

		fread(&CELL_SIZE_X_, sizeof(int), 1, fp);
		fread(&CELL_SIZE_Y_, sizeof(int), 1, fp);

		int total = TotalCellCountX_ * TotalCellCountY_;

		// create memory and initialize
		WorldCell_ = new FCellBase*[total];
		memset(WorldCell_, 0, sizeof(FCellBase*)*total);

		// read chunk data
		for (int i = 0; i < total; i++)
		{
			ReadCell_V7(fp, (WorldCell_ + i));
		}

		// read extra data
		ReadCellExtraData_V7(fp, ReplacementCells_);

		return true;
	}

	bool FAStarMap::Load_Version8(FILE* fp)
	{
		DestroyCell();

		fread(&TotalCellCountX_, sizeof(int), 1, fp);
		fread(&TotalCellCountY_, sizeof(int), 1, fp);

		fread(&StartCellX_, sizeof(int), 1, fp);
		fread(&StartCellY_, sizeof(int), 1, fp);

		fread(&CELL_SIZE_X_, sizeof(int), 1, fp);
		fread(&CELL_SIZE_Y_, sizeof(int), 1, fp);

		int total = TotalCellCountX_ * TotalCellCountY_;

		// create memory and initialize
		WorldCell_ = new FCellBase * [total];
		memset(WorldCell_, 0, sizeof(FCellBase*) * total);

		// read chunk data
		for (int i = 0; i < total; i++)
		{
			ReadCell_V8(fp, (WorldCell_ + i));
		}

		// read extra data
		ReadCellExtraData_V8(fp, ReplacementCells_);

		return true;
	}

	bool FAStarMap::ReadCellCamera_V1(FILE* fp)
	{
		FNodeCoordinate coordinates;

		fread(&(coordinates), sizeof(FNodeCoordinate), 1, fp);
		
		FCell* ReadCell = GetCellPtr(coordinates);
		if (ReadCell == nullptr)
		{
			// invalid cell found, skip current data
			fseek(fp, sizeof(CAMERA_TYPE), SEEK_CUR);
			fseek(fp, sizeof(FCellCameraData), SEEK_CUR);
			return false;
		}
		else
		{
			// destroy exist
			if (ReadCell->CameraData)
			{
				delete ReadCell->CameraData;
				ReadCell->CameraData = nullptr;
			}

			// load and apply camera data
			fread(&(ReadCell->CameraDataType), sizeof(CAMERA_TYPE), 1, fp);
			ReadCell->CameraData = new FCellCameraData;
			fread(ReadCell->CameraData, sizeof(FCellCameraData), 1, fp);
		}

		return true;
	}

	bool FAStarMap::WriteCellCamera(FILE* fp, FCellBase* Cell)
	{
		if (Cell->IsValid)
		{
			return WriteCellCamera(fp, (FCell*)Cell);
		}

		return true;
	}

	bool FAStarMap::WriteCellCamera(FILE* fp, FCell* Cell)
	{
		if (Cell->CameraDataType == CAMERATYPE_NONE)
		{
			return false;
		}

		fwrite(&(Cell->coordinates), sizeof(FNodeCoordinate), 1, fp);
		fwrite(&(Cell->CameraDataType), sizeof(CAMERA_TYPE), 1, fp);
		fwrite(Cell->CameraData, sizeof(FCellCameraData), 1, fp);

		return true;
	}

	bool FAStarMap::Load(const char* path)
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
		if (header != ASTARMAP_MAGIC)
		{
			fclose(fp);
			return false;
		}

		fread(&version, sizeof(int), 1, fp);
		switch (version)
		{
		case 1:
			Load_Version1(fp);
			break;
		case 2:
			Load_Version2(fp);
			break;
		case 3:
			Load_Version3(fp);
			break;
		case 4:
			Load_Version4(fp);
			break;
		case 5:
			Load_Version5(fp);
			break;
		case 6:
			Load_Version6(fp);
			break;
		case 7:
			Load_Version7(fp);
			break;
		case 8:
			Load_Version8(fp);
			break;
		default:
			DestroyCell();
			break;
		}

		fclose(fp);

#ifdef SERVER_USE
		LoadServerCell();
#endif	// SERVER_USE

		return true;
	}

	bool FAStarMap::Save(const char* path)
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
		int header = ASTARMAP_MAGIC;
		int version = ASTARMAP_VERSION;

		fwrite(&header, sizeof(int), 1, fp);
		fwrite(&version, sizeof(int), 1, fp);

		fwrite(&TotalCellCountX_, sizeof(int), 1, fp);
		fwrite(&TotalCellCountY_, sizeof(int), 1, fp);

		fwrite(&StartCellX_, sizeof(int), 1, fp);
		fwrite(&StartCellY_, sizeof(int), 1, fp);

		fwrite(&CELL_SIZE_X_, sizeof(int), 1, fp);
		fwrite(&CELL_SIZE_Y_, sizeof(int), 1, fp);

		// write cell data
		int total = TotalCellCountX_ * TotalCellCountY_;
		for (int i = 0; i < total; i++)
		{
			WriteCell(fp, WorldCell_[i]);
		}

		WriteCellExtraData(fp, ReplacementCells_);

		fclose(fp);

		return true;
	}

	bool FAStarMap::LoadCamera_Version1(FILE* fp)
	{
		int TotalCameraDataCount;

		fread(&TotalCameraDataCount, sizeof(int), 1, fp);

		for (int i = 0; i < TotalCameraDataCount; i++)
		{
			ReadCellCamera_V1(fp);
		}

		// replacement cell
		int totalgroups;
		fread(&totalgroups, sizeof(int), 1, fp);

		for (int i = 0; i < totalgroups; i++)
		{
			std::vector<FCell>& cells = ReplacementCells_[i];

			// read total count
			int totalreplacementcells;
			fread(&totalreplacementcells, sizeof(int), 1, fp);
			for (int j = 0; j < totalreplacementcells; j++)
			{
				CAMERA_TYPE CameraDataType;
				FCellCameraData* CameraData;
				FNodeCoordinate coordinates;

				// read and apply camera data
				fread(&(coordinates), sizeof(FNodeCoordinate), 1, fp);
				fread(&CameraDataType, sizeof(CAMERA_TYPE), 1, fp);

				// read v7 to v8
				FCellCameraData_V7 CameraDataV7;
				fread(&CameraDataV7, sizeof(FCellCameraData_V7), 1, fp);

				// convert v7 to v8
				CameraData = new FCellCameraData;
				CameraData->tile_rotation_speed = ASTARCAM_DEFAULT_TILE_ROTATION_SPEED;
				CameraData->tile_reset_time = ASTARCAM_DEFAULT_TILE_RESET_TIME;
				CameraData->rot[0] = CameraDataV7.rot[0];
				CameraData->rot[1] = CameraDataV7.rot[1];
				CameraData->action_type = 0;

				// find match camera data in array
				bool matchfound = false;
				for (int k = 0; k < (int)cells.size(); k++)
				{
					if (cells[k].coordinates == coordinates)
					{
						cells[k].CameraDataType = CameraDataType;
						if (cells[k].CameraData)
						{
							delete cells[k].CameraData;
						}
						cells[k].CameraData = CameraData;

						matchfound = true;
						break;
					}
				}

				if (matchfound == false)
				{
					delete CameraData;
					return false;
				}
			}
		}

		return true;
	}

	bool FAStarMap::LoadCamera_Version2(FILE* fp)
	{
		int TotalCameraDataCount;

		fread(&TotalCameraDataCount, sizeof(int), 1, fp);

		for (int i = 0; i < TotalCameraDataCount; i++)
		{
			ReadCellCamera_V1(fp);
		}

		// replacement cell
		int totalgroups;
		fread(&totalgroups, sizeof(int), 1, fp);

		for (int i = 0; i < totalgroups; i++)
		{
			std::vector<FCell>& cells = ReplacementCells_[i];

			// read total count
			int totalreplacementcells;
			fread(&totalreplacementcells, sizeof(int), 1, fp);
			for (int j = 0; j < totalreplacementcells; j++)
			{
				CAMERA_TYPE CameraDataType;
				FCellCameraData* CameraData;
				FNodeCoordinate coordinates;

				// read and apply camera data
				fread(&(coordinates), sizeof(FNodeCoordinate), 1, fp);
				fread(&CameraDataType, sizeof(CAMERA_TYPE), 1, fp);
				CameraData = new FCellCameraData;
				fread(CameraData, sizeof(FCellCameraData), 1, fp);

				// find match camera data in array
				bool matchfound = false;
				for (int k = 0; k < (int)cells.size(); k++)
				{
					if (cells[k].coordinates == coordinates)
					{
						cells[k].CameraDataType = CameraDataType;
						if (cells[k].CameraData)
						{
							delete cells[k].CameraData;
						}
						cells[k].CameraData = CameraData;

						matchfound = true;
						break;
					}
				}

				if (matchfound == false)
				{
					delete CameraData;
					return false;
				}
			}
		}

		return true;
	}

	bool FAStarMap::LoadCamera(const char* path)
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
		bool result = true;

		// read header and check
		fread(&header, sizeof(int), 1, fp);
		if (header != ASTARCAM_MAGIC)
		{
			fclose(fp);
			return false;
		}

		fread(&version, sizeof(int), 1, fp);
		switch (version)
		{
		case 1:
			result = LoadCamera_Version1(fp);
			break;
		case 2:
			result = LoadCamera_Version2(fp);
			break;
		}

		fclose(fp);

		return result;
	}

	bool FAStarMap::SaveCamera(const char* path)
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
		int header = ASTARCAM_MAGIC;
		int version = ASTARCAM_VERSION;

		fwrite(&header, sizeof(int), 1, fp);
		fwrite(&version, sizeof(int), 1, fp);

		int total = TotalCellCountX_ * TotalCellCountY_;

		// write total camera data count
		int TotalCameraDataCount = 0;

		// find out how many camera data were used
		for (int i = 0; i < total; i++)
		{
			if (WorldCell_[i]->IsValid)
			{
				FCell* Cell = (FCell*)WorldCell_[i];

				if (Cell->CameraDataType != CAMERATYPE_NONE)
				{
					TotalCameraDataCount++;
				}
			}
		}

		fwrite(&TotalCameraDataCount, sizeof(int), 1, fp);

		if (TotalCameraDataCount > 0)
		{
			for (int i = 0; i < total; i++)
			{
				WriteCellCamera(fp, WorldCell_[i]);
			}
		}

		// replacement cell
		int totalgroups = (int)ReplacementCells_.size();
		fwrite(&totalgroups, sizeof(int), 1, fp);

		for (int i = 0; i < totalgroups; i++)
		{
			std::vector<FCell>& cells = ReplacementCells_[i];

			// write total count
			int totalreplacementcells = 0;
			for (int j = 0; j < (int)cells.size(); j++)
			{
				if (cells[j].CameraDataType != CAMERATYPE_NONE)
				{
					totalreplacementcells++;
				}
			}

			fwrite(&totalreplacementcells, sizeof(int), 1, fp);
			for (int j = 0; j < (int)cells.size(); j++)
			{
				if (cells[j].CameraDataType != CAMERATYPE_NONE)
				{
					fwrite(&(cells[j].coordinates), sizeof(FNodeCoordinate), 1, fp);
					fwrite(&(cells[j].CameraDataType), sizeof(CAMERA_TYPE), 1, fp);
					fwrite(cells[j].CameraData, sizeof(FCellCameraData), 1, fp);
				}
			}
		}

		fclose(fp);

		return true;
	}

	bool FAStarMap::ReportCellToText(const char* path)
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

		int total = TotalCellCountX_ * TotalCellCountY_;

		fprintf(fp, "TotalCellCountX : %d, TotalCellCountY : %d\n", TotalCellCountX_, TotalCellCountY_);
		fprintf(fp, "Start Cell X : %d, Start Cell Y : %d\n", StartCellX_, StartCellY_);
		fprintf(fp, "Cell Size X : %d, Cell Size Y : %d\n", CELL_SIZE_X_, CELL_SIZE_Y_);

		fprintf(fp, "\n");

		fprintf(fp, "Cell Info (%d) ========= \n", total);
		for (int i = 0; i < total; i++)
		{
			FCellBase* base = WorldCell_[i];
			if (base->IsValid)
			{
				FCell* cell = (FCell *)WorldCell_[i];

				fprintf(fp, "n:%d idx:%d (x:%d, y:%d), attr:0x%08X, h:%f, GroundMtrl:%d",
					i, CellPosToIndex(base->coordinates), base->coordinates.x, base->coordinates.y,
					cell->attr, cell->center_height, cell->GroundMaterialNum
				);

				// v5
				fprintf(fp, " CameraType:%d", cell->CameraDataType);
				if (cell->CameraDataType != CAMERATYPE_NONE)
				{
					fprintf(fp, " CameraData: tile_rotation_speed(%f) tile_reset_time(%f) rot(x:%f, y:%f), action_type:%d", 
						cell->CameraData->tile_rotation_speed, cell->CameraData->tile_reset_time, cell->CameraData->rot[0], cell->CameraData->rot[1], cell->CameraData->action_type);
				}

				// v6
				fprintf(fp, " SWAreaNum:%d", cell->SWAreaNum);

				// extra cell distance
				if (cell->neighbor_distance)
				{
					fprintf(fp, " ndist:%d ( ", NeighborDirCount_);

					for (int nd = 0; nd < NeighborDirCount_; nd++)
					{
						fprintf(fp, "%d:%f ", nd, cell->neighbor_distance[nd]);
					}

					fprintf(fp, ")");
				}

				// end of line
				fprintf(fp, "\n");
			}
			else
			{
				fprintf(fp, "n:%d idx:%d, (x:%d, y:%d), no data\n",
					i, CellPosToIndex(base->coordinates), base->coordinates.x, base->coordinates.y
				);
			}
		}

		fprintf(fp, "\n");

		fprintf(fp, "Replacement Cell Info (%d Groups) ========= \n", (int)ReplacementCells_.size());
		for (int i = 0; i < static_cast<int32_t>(ReplacementCells_.size()); i++)
		{
			fprintf(fp, "Cell Group (%d - Total %d Cells) ========= \n", i, (int)ReplacementCells_[i].size());

			for (int j = 0; j < static_cast<int32_t>(ReplacementCells_[i].size()); j++)
			{
				FCell* cell = &(ReplacementCells_[i][j]);

				fprintf(fp, "n:%d idx:%d (x:%d, y:%d), attr:0x%08X, h:%f, GroundMtrl:%d",
					j, CellPosToIndex(cell->coordinates), cell->coordinates.x, cell->coordinates.y,
					cell->attr, cell->center_height, cell->GroundMaterialNum
				);

				// v5
				fprintf(fp, " CameraType:%d", cell->CameraDataType);
				if (cell->CameraDataType != CAMERATYPE_NONE)
				{
					fprintf(fp, " CameraData: tile_rotation_speed(%f) tile_reset_time(%f) rot(x:%f, y:%f)",
						cell->CameraData->tile_rotation_speed, cell->CameraData->tile_reset_time, cell->CameraData->rot[0], cell->CameraData->rot[1]);
				}

				// v6
				fprintf(fp, " SWAreaNum:%d", cell->SWAreaNum);

				// end of line
				fprintf(fp, "\n");
			}
		}

		fclose(fp);
		return true;
	}
}
