#pragma once

// https://github.com/daancode/a-star
// based on this A-Star Library on github

#define SERVER_USE



#ifdef SERVER_USE

#include "../../table/header/_common.h"
#define _MIRM_FLT_MAX          3.402823466e+38F        // max value

#endif

namespace CSCommon
{

	typedef unsigned short OLD_ATTR;	// bit attribute	// old 2 bytes
	typedef unsigned int ATTR;			// bit attribute		4 bytes
	typedef unsigned short ATTR_NUM;	// number attribute		2 bytes
	typedef unsigned char CAMERA_TYPE;	// camera type			1 bytes

	const ATTR ATTR_BLOCKMASK = 0x700000FF;				// mask use only. not for checking. use ATTR_BLOCK_ALL instead
	const ATTR ATTR_STATIC_BLOCKMASK = 0x00000007;		// static block mask, except ATTR_BLOCK_BOUNDRY = 0x00000008
	const ATTR ATTR_FLEXBLOCKMASK = 0x000000F8;			// flexible block mask (deprecated)
	const ATTR ATTR_FLEXIBLE_BLOCKMASK = 0x000000F0;	// flexible block mask (new naming)
	const ATTR ATTR_EXTENDED_BLOCKMASK = 0xF0000000;	// extended block mask
	const ATTR ATTR_ATTRMASK = 0x00000F00;				// cell attribute mask
	const ATTR ATTR_GNDMTRLMASK_OBSOLETED = 0x0000F000;	// cell ground material mask -> obsoleted
	const ATTR ATTR_ATTACKZONEMASK = 0x000F0000;		// attack zone mask (used to attack correlation)
	const ATTR ATTR_SW_CELL_MASK = 0x00F00000;			// warfare cell mask

	// block static value - 0x0000000F
	const ATTR ATTR_MOVE = 0x00000000;				// can move
	const ATTR ATTR_BLOCK = 0x00000001;				// such as walls, blocking volumes, no one can go.
	const ATTR ATTR_ATTACKABLE_BLOCK = 0x00000002;	// block but allow attack
	const ATTR ATTR_OBSTACLE = 0x00000002;			// obstacle. value is same as ATTR_ATTACKABLE_BLOCK
	const ATTR ATTR_ERROR_BLOCK = 0x00000004;		// error block
	const ATTR ATTR_BLOCK_BOUNDRY = 0x00000008;		// block, sub attribute, boundry for huge monster

	// block flexible value (can be re-writable) - 0x000000F0
	const ATTR ATTR_BLOCK_PLAYER = 0x00000010;
	const ATTR ATTR_BLOCK_MONSTER = 0x00000020;
	const ATTR ATTR_BLOCK_NPC = 0x00000040;
	const ATTR ATTR_BLOCK_OBJECT = 0x00000080;		// added flexible block object (can be moved or destroyed)

	// attribute static value - 0x00000F00
	const ATTR ATTR_SAFETYZONE = 0x00000100;	// safety zone
	const ATTR ATTR_OVERLAP = 0x00000200;		// allow objects(monster, npc) overlap each other. players are still blocked each other
	const ATTR ATTR_BORDER = 0x00000400;		// *UNUSED* border, beside the wall
	const ATTR ATTR_PK_NO_PENALTY = 0x00000400;	// 2022.05.09 NO PK Pentalty zone. (allow pk without penalty)
	const ATTR ATTR_PATHFLAG = 0x00000800;		// path point flag (experimental)

	// collect - 0x0000F000 - previously used to ground material
	const ATTR ATTR_COLLECT_FISHING = 0x00001000;		// fishing area 2019.12.19
	const ATTR ATTR_COLLECT_PLACEMENT = 0x00002000;		// block check attribute for the collect. 2021.08.30 
	const ATTR ATTR_COLLECT_RESERVED3 = 0x00004000;
	const ATTR ATTR_COLLECT_RESERVED4 = 0x00008000;

	// attack zone value - 0x000F0000 (note : 1 byte data) - 15 is MAX
	const ATTR_NUM ATTR_ATTACK_ZONE_NONE = 0;	// can't attack alphabet attributes
	const ATTR_NUM ATTR_ATTACK_ZONE_A = 1;
	const ATTR_NUM ATTR_ATTACK_ZONE_B = 2;
	const ATTR_NUM ATTR_ATTACK_ZONE_C = 3;
	const ATTR_NUM ATTR_ATTACK_ZONE_D = 4;
	const ATTR_NUM ATTR_ATTACK_ZONE_E = 5;
	const ATTR_NUM ATTR_ATTACK_ZONE_F = 6;
	const ATTR_NUM ATTR_ATTACK_ZONE_G = 7;
	const ATTR_NUM ATTR_ATTACK_ZONE_H = 8;
	const ATTR_NUM ATTR_ATTACK_ZONE_I = 9;

	// siege warfare cell value - 0x00F00000
	const ATTR ATTR_SW_MOVE_CELL_OFFENCE = 0x00100000;
	const ATTR ATTR_SW_MOVE_CELL_DEFENCE = 0x00200000;
	const ATTR ATTR_SW_MOVE_CELL_RESERVED3 = 0x00400000;
	const ATTR ATTR_SW_MOVE_CELL_RESERVED4 = 0x00800000;

	// extended attribute - 0x0F000000 -> changed from client use only
	const ATTR ATTR_FORCEUSE_NORMALPATH = 0x01000000;	// check attribute for not to use path flag movement
	const ATTR ATTR_NO_MOVEMENTS = 0x02000000;		// 2020.03.30 warns if enter this cell
	//const ATTR ATTR_PREVENT_TARGETING = 0x04000000;	// 2020.05.15 prevent to target pick (e.g over the wall) - unused
	const ATTR ATTR_PREVENT_AUTOMOVE = 0x04000000;	// 2020.05.15 temporary block attribute while auto movement
	const ATTR ATTR_TOWN = 0x08000000;	// 2020.05.21 town

	// extended block attribute value - 0xF0000000
	const ATTR ATTR_EXTBLOCK_BOSSPLACE = 0x10000000;	// block attribute for boss placement
	const ATTR ATTR_EXTBLOCK_ALLOW_PATHFIND = 0x20000000; // 2022.02.23, exceptional flag, allow find path. means ignore block attribute while finding path
	const ATTR ATTR_EXTBLOCK_RESERVED2 = 0x20000000;
	const ATTR ATTR_EXTBLOCK_RESERVED3 = 0x40000000;
	const ATTR ATTR_EXTBLOCK_DO_NOT_USE = 0x80000000;	// DO NOT USE THIS BIT. may confused with ATTR_UNUSED

	// ====== USED BITS (F is used) ====== 
	// 0x1F3F FFFF

	// Independent Data - (Not used in ATTR bit)
	// siege warfare - area value (note : 2 byte data)
	const ATTR_NUM ATTR_SW_AREA_NONE = 0;
	const ATTR_NUM ATTR_SW_AREA_CASTLE_WALL = 1;
	const ATTR_NUM ATTR_SW_AREA_INNER_CASTLE = 2;
	const ATTR_NUM ATTR_SW_AREA_OUTER_CASTLE = 3;
	const ATTR_NUM ATTR_SW_AREA_INNER_TARGET = 4;
	const ATTR_NUM ATTR_SW_AREA_OUTER_TARGET = 5;
	const ATTR_NUM ATTR_SW_AREA_HIDDEN_PATH = 6;

	// ground material value
	const ATTR_NUM ATTR_GNDMTRL_DEFAULT = 0;
	const ATTR_NUM ATTR_GNDMTRL_SOIL = 1;
	const ATTR_NUM ATTR_GNDMTRL_WATER = 2;
	const ATTR_NUM ATTR_GNDMTRL_GRASS = 3;
	const ATTR_NUM ATTR_GNDMTRL_STONE = 4;
	const ATTR_NUM ATTR_GNDMTRL_WOOD = 5;
	const ATTR_NUM ATTR_GNDMTRL_SNOW = 6;
	const ATTR_NUM ATTR_GNDMTRL_FIRE = 7;
	const ATTR_NUM ATTR_GNDMTRL_SWAMP = 8;
	const ATTR_NUM ATTR_GNDMTRL_MAX = 9;

	const ATTR ATTR_NONE = 0x00000000;
	const ATTR ATTR_UNUSED = 0xFFFFFFFF;

	// attribute combinations
	const ATTR ATTR_BLOCK_ALL = (ATTR_BLOCK | ATTR_BLOCK_PLAYER | ATTR_BLOCK_MONSTER | ATTR_BLOCK_NPC | ATTR_BLOCK_OBJECT | ATTR_ATTACKABLE_BLOCK | ATTR_ERROR_BLOCK | ATTR_EXTENDED_BLOCKMASK);
	const ATTR ATTR_BLOCK_OFFENCE = (ATTR_BLOCK | ATTR_BLOCK_PLAYER | ATTR_BLOCK_MONSTER | ATTR_BLOCK_NPC | ATTR_BLOCK_OBJECT | ATTR_ATTACKABLE_BLOCK | ATTR_ERROR_BLOCK | ATTR_SW_MOVE_CELL_DEFENCE | ATTR_EXTENDED_BLOCKMASK);
	const ATTR ATTR_BLOCK_DEFENCE = (ATTR_BLOCK | ATTR_BLOCK_PLAYER | ATTR_BLOCK_MONSTER | ATTR_BLOCK_NPC | ATTR_BLOCK_OBJECT | ATTR_ATTACKABLE_BLOCK | ATTR_ERROR_BLOCK | ATTR_SW_MOVE_CELL_OFFENCE | ATTR_EXTENDED_BLOCKMASK);

	const CAMERA_TYPE CAMERATYPE_NONE = 0;

	const int INVALID_INDEX = -1;
	const float INVALID_HEIGHT = 0.0f;

	const int DEFAULT_CELL_SIZE_X = 140;
	const int DEFAULT_CELL_SIZE_Y = 140;

	const int DEFAULT_REGION_SIZE_X = 9 * 6 * DEFAULT_CELL_SIZE_X;
	const int DEFAULT_REGION_SIZE_Y = 9 * 6 * DEFAULT_CELL_SIZE_Y;

	const int MAX_PATH_EXPANSION = 2;

	const int MAX_PATHFLAG_SEARCH_DISTANCE = 600;	// 200 is too short

	// FindResult definition
	const int FR_Error = 0;		// we can't find path
	const int FR_Success = 1;	// we found complete path
	const int FR_Partial = 2;	// find but incomplete path

	// FindResult reason
	const int FRR_None = 0;				// no reason
	const int FRR_Invalid_Pos = 0;		// invalid pos
	const int FRR_PathFindTimeout = 1;	// timeout occured while path finding
	const int FRR_Surround_Block = 2;	// blocked by surround

	const float DEFAULT_PATHFIND_TIMEOUT = 5.0f; // default time out value

	// find options		(added 2022.05.09)
	typedef unsigned char FOPTION;
	const FOPTION FO_NONE = 0x00;
	const FOPTION FO_FIND_PARTIAL_PATH = 0x01;
	const FOPTION FO_FIND_FORWARD_PATH = 0x02;
	const FOPTION FO_USE_EXTBLOCK_ALLOW_PATHFIND = 0x10;	// use ATTR_EXTBLOCK_ALLOW_PATHFIND attribute

	// global functions
	struct FNodeCoordinate;

	void g_InitializeAStarLib();
	void g_SetDiagonalMovement(bool enable);
	void g_SetHeuristic(std::function<int(FNodeCoordinate, FNodeCoordinate)> heuristic);

	int g_CalcDistSquaredXY(int x1, int y1, int x2, int y2);
	float g_CalcDistSquaredXY(const float* v1, const float* v2);
	float g_CalcDistSquared(const float* v1, const float* v2);
	bool g_IsSamePositionXY(const float* v1, const float* v2);
	bool g_IsSamePosition(const float* v1, const float* v2);
	bool g_IsNeighbor(int sx, int sy, int dx, int dy);
	bool g_IsDiagonalNeighbor(int sx, int sy, int dx, int dy);

	std::vector<FNodeCoordinate> g_GetLinePointList(FNodeCoordinate v1, FNodeCoordinate v2);
	std::vector<FNodeCoordinate> g_GetLinePointList(int x1, int y1, int x2, int y2);

	// structures
	struct FNodeCoordinate
	{
		int x, y;

		bool operator == (const FNodeCoordinate& coordi)
		{
			return (x == coordi.x && y == coordi.y);
		}
		bool operator != (const FNodeCoordinate& coordi)
		{
			return (x != coordi.x || y != coordi.y);
		}
	};

	struct FCellAttribute
	{
		unsigned char attr;
		int64_t uid;
	};

	// 2022/05/09 removed union
	struct FCellCameraData
	{
		float tile_rotation_speed;
		float tile_reset_time;

		float rot[2];			// camera rotation x / y

		int action_type;		// action type (2021.12.17)
	};

	typedef FCellCameraData FCellCameraData_V8;

	struct FCellBase
	{
		FNodeCoordinate coordinates;
		bool			IsValid;
	};

#ifdef SERVER_USE

	const ATTR ATTR_BLOCK_SKILL_ACTION = (ATTR_BLOCK | ATTR_ATTACKABLE_BLOCK);
	const ATTR ATTR_BLOCK_DROP = (ATTR_BLOCK | ATTR_BLOCK_MONSTER | ATTR_BLOCK_NPC | ATTR_BLOCK_OBJECT | ATTR_ATTACKABLE_BLOCK | ATTR_ERROR_BLOCK);
	const ATTR ATTR_BLOCK_ALL_EXT = (ATTR_BLOCK_ALL | ATTR_EXTBLOCK_BOSSPLACE);

	std::vector<FNodeCoordinate> GetLinePointList(int x1, int y1, int x2, int y2);
	void GetLinePointList(int x1, int y1, int x2, int y2, std::vector<FNodeCoordinate>&);
	struct FAStarNode;
#endif

	struct FCell : public FCellBase
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

		// client use only - v7/v8
		CAMERA_TYPE CameraDataType;
		FCellCameraData* CameraData;

		// client use only - v6
		ATTR_NUM SWAreaNum;

		// client use only - unsaved data
		std::vector<FCellAttribute> BlockAttrList;
	};

	typedef FCell FCell_V7;
	typedef FCell FCell_V8;

	struct FPathFlagInfo
	{
		int id;						// internal use (for load/save) - type changed 

		float v1[3];
		float v2[3];

		int Cost;					// atcual each cell distance. 10 (horz/vert) / 14 (diagonal)

		int index_v1;				// index for v1 in FPathFlag internal use (not for load/save)
		int index_v2;				// index for v2 in FPathFlag internal use (not for load/save)
	};

	typedef FPathFlagInfo FPathFlagInfo_V3;

	struct FPathFlag
	{
		int index;

		float Position[3];		// world coordinates

		int TotalNeighborFlagList;
		int* NeighborFlagIndexList;
		FPathFlagInfo** NeighborFlagList;	// linked neighbor list
	};

	typedef FPathFlag FPathFlag_V4;

	struct FRegion
	{
		float CenterPosition[3];

		int TotalPathFlags;
		int* PathFlagIndex;
		FPathFlag** PathFlags;
	};

	typedef FRegion FRegion_V1;

	struct FPathFindResult
	{
		int Result;
		std::vector<FNodeCoordinate> PathList;
		std::vector<FPathFlag*> PathFlagList;

		int TotalCost;	// only works by calling GetFullPath

		int Reason;	// result reason
	};

	// classes

	class FHeuristic
	{
		static FNodeCoordinate getDelta(FNodeCoordinate source_, FNodeCoordinate target_);

	public:
		static int manhattan(FNodeCoordinate source_, FNodeCoordinate target_);
		static int euclidean(FNodeCoordinate source_, FNodeCoordinate target_);
		static int octagonal(FNodeCoordinate source_, FNodeCoordinate target_);
		static int chebyshev(FNodeCoordinate source_, FNodeCoordinate target_);
	};

	class FAStarMap
	{
	public:
		FAStarMap();
		virtual ~FAStarMap();

	private:
		// initialize
		virtual void	InitializeCell(FCell* Cell);	// do not call used fcell. pointer will not deleted. just clear
		virtual void	DestroyAll();
		virtual void	DestroyRegion();
		virtual void	DestroyCell();
		virtual void	DestroyCell(FCell* Cell);

	public:
		int GetTotalCellCount() { return TotalCellCountX_ * TotalCellCountY_; }
		int GetTotalCellCountX() { return TotalCellCountX_; }
		int GetTotalCellCountY() { return TotalCellCountY_; }

		int GetStartCellX() { return StartCellX_; }
		int GetStartCellY() { return StartCellY_; }

		int GetCellSizeX() { return CELL_SIZE_X_; }
		int GetCellSizeY() { return CELL_SIZE_Y_; }

		// used only path point map or neighbor distance
		int GetNeighborDirCount() { return NeighborDirCount_; }

	public:
		// this map creates calculate cells (0,0) to (WorldSize[0], WorldSize[1])
		bool	CreateMap(const float* WorldSize, int CellSizeX = DEFAULT_CELL_SIZE_X, int CellSizeY = DEFAULT_CELL_SIZE_Y);

	protected:
		bool	ReadCell_V1(FILE* fp, FCellBase** Cell);
		bool	ReadCell_V2(FILE* fp, FCellBase** Cell);
		bool	ReadCell_V4(FILE* fp, FCellBase** Cell);
		bool	ReadCell_V5(FILE* fp, FCellBase** Cell);
		bool	ReadCell_V6(FILE* fp, FCellBase** Cell);
		bool	ReadCell_V7(FILE* fp, FCellBase** Cell);
		bool	ReadCell_V8(FILE* fp, FCellBase** Cell);

		bool	ReadCellExtraData_V6(FILE* fp, std::vector<std::vector<FCell>>& ExtraData);
		bool	ReadCellExtraData_V7(FILE* fp, std::vector<std::vector<FCell>>& ExtraData);
		bool	ReadCellExtraData_V8(FILE* fp, std::vector<std::vector<FCell>>& ExtraData);

		bool	WriteCell(FILE* fp, FCellBase* Cell);
		bool	WriteCell(FILE* fp, FCell* Cell);

		bool	WriteCellExtraData(FILE* fp, std::vector<std::vector<FCell>>& ExtraData);

		bool	Load_Version1(FILE* fp);
		bool	Load_Version2(FILE* fp);
		bool	Load_Version3(FILE* fp);
		bool	Load_Version4(FILE* fp);
		bool	Load_Version5(FILE* fp);
		bool	Load_Version6(FILE* fp);
		bool	Load_Version7(FILE* fp);
		bool	Load_Version8(FILE* fp);

		bool	ReadCellCamera_V1(FILE* fp);
		bool	WriteCellCamera(FILE* fp, FCellBase* Cell);
		bool	WriteCellCamera(FILE* fp, FCell* Cell);

		bool	LoadCamera_Version1(FILE* fp);
		bool	LoadCamera_Version2(FILE* fp);

	public:
		// file handling
		bool	Load(const char* path);
		bool	Save(const char* path);

		bool	LoadCamera(const char* path);
		bool	SaveCamera(const char* path);

		// for debug check
		bool	ReportCellToText(const char* path);

	public:
		// NOTE : function returns true if executed successfully. 
		//        but it returns false if invalid xy position requested.

		// attributes
		FCell* GetCellPtr(int index);
		FCell* GetCellPtr(int cell_x, int cell_y);
		FCell* GetCellPtr(FNodeCoordinate& CellPos);

		bool	UpdateCell(int cell_x, int cell_y, bool isValidate);
		bool	UpdateCell(FNodeCoordinate& CellPos, bool isValidate);

		bool	WorldPosToCellPos(const float* Loc, int& out_cell_x, int& out_cell_y);
		bool	WorldPosToCellPos(const float* Loc, FNodeCoordinate& CellPos);
		bool	WorldPosToWorldCellCenterPos(const float* Loc, float* outLoc);
		bool	CellPosToWorldPos(int cell_x, int cell_y, float* outLoc);
		bool	CellPosToWorldPos(FNodeCoordinate& CellPos, float* outLoc);
		int		CellPosToIndex(int cell_x, int cell_y);
		int		CellPosToIndex(FNodeCoordinate& CellPos);
		bool	CellIndexToPos(int index, int& out_cell_x, int& out_cell_y);
		bool	CellIndexToPos(int index, FNodeCoordinate& OutCellPos);
		bool	CellIndexToWorldPos(int index, float* outLoc);

		bool	CheckIsSameCell(const float* v1, const float* v2, bool& result);

		bool	CheckIsAttackableZone(const float* v1, const float* v2);
		bool	CheckIsAttackableZone(int cell_x1, int cell_y1, int cell_x2, int cell_y2);
		bool	CheckIsAttackableZone(FNodeCoordinate& CellPos1, FNodeCoordinate& CellPos2);
		bool	CheckIsAttackableZone(ATTR_NUM attr1, ATTR_NUM attr2);

		// [2020-01-31] krseong (This function is for checking siegewarfare fixed-object)
		bool	CheckIsAttackableZone(int cell_x1, int cell_y1, int attr2);

		// check includes both start and end position
		bool	CheckLine(const float* StartLoc, const float* EndLoc, ATTR BlockAttribute, bool& result);
		bool	CheckLine(int StartCellX, int StartCellY, int EndCellX, int EndCellY, ATTR BlockAttribute, bool& result);
		bool	CheckLine(FNodeCoordinate& StartCellPos, FNodeCoordinate& EndCellPos, ATTR BlockAttribute, bool& result);

		bool	CheckLineWithMatchAttribute(const float* StartLoc, const float* EndLoc, ATTR Attribute, bool& result);
		bool	CheckLineWithMatchAttribute(int StartCellX, int StartCellY, int EndCellX, int EndCellY, ATTR Attribute, bool& result);
		bool	CheckLineWithMatchAttribute(FNodeCoordinate& StartCellPos, FNodeCoordinate& EndCellPos, ATTR Attribute, bool& result);

#ifdef SERVER_USE

		bool	IndexToWorldPos(int index, float* outLoc);
		int		WorldPosToIndex(const float* Loc);

		bool	CheckBlock(int cell_x, int cell_y, int32_t& result);
		bool	CheckBlock(int index, int32_t& result);

		bool	CheckAttribute(FNodeCoordinate& CellPos, ATTR Attribute, bool& result);
		bool	CheckAttribute(int cell_x, int cell_y, ATTR Attribute, bool& result);
		bool	CheckAttribute(int cell_x, int cell_y, ATTR Attribute, int32_t& result);
		bool	CheckAttribute(int index, ATTR Attribute, int32_t& result);

		bool	CheckAttributeOverlap(int cell_x, int cell_y, ATTR Attribute, int32_t& result);
		bool	CheckAttributeOverlap(int index, ATTR Attribute, int32_t& result);
		bool	CheckPathAttribute(int cell_x, int cell_y, ATTR Attribute, int32_t& result);
		bool	CheckPathAttribute(int index, ATTR Attribute, int32_t& result);

		bool	ClearAttribute(int cell_x, int cell_y);
		bool	ClearAttribute(int index);

		bool	GetAttribute(int cell_x, int cell_y, ATTR& Attribute, bool IncludeMaterial = false);
		bool	GetAttribute(int index, ATTR& Attribute, bool IncludeMaterial = false);
		bool	SetAttribute(int cell_x, int cell_y, ATTR Attribute, bool IncludeMaterial = false);
		bool	SetAttribute(int index, ATTR Attribute, bool IncludeMaterial = false);

		bool	AddAttribute(int cell_x, int cell_y, ATTR Attribute);
		bool	AddAttribute(int index, ATTR Attribute);
		bool	RemoveAttribute(int cell_x, int cell_y, ATTR Attribute);
		bool	RemoveAttribute(int index, ATTR Attribute);

		bool	GetCenterHeight(int cell_x, int cell_y, float& height);
		bool	GetCenterHeight(int index, float& height);
		bool	SetCenterHeight(int cell_x, int cell_y, float height);
		bool	SetCenterHeight(int index, float height);

		bool	GetGroundMaterial(int cell_x, int cell_y, int& material);
		bool	GetGroundMaterial(int index, int& material);
		bool	SetGroundMaterial(int cell_x, int cell_y, int material);
		bool	SetGroundMaterial(int index, int material);

		bool	GetAttackZone(FCell* CellPtr, int& zone);

		std::vector<FNodeCoordinate> FindPathServer(const float* StartLoc, const float* EndLoc, ATTR BlockAttribute, bool object_check, bool trace_flag);
		void FindPathServer(const float* StartLoc, const float* EndLoc, ATTR BlockAttribute, bool object_check, bool trace_flag, std::vector<FNodeCoordinate>& path, const int32_t check_target_range = 5);
		bool TargetPathCheck(const float* CheckLoc, ATTR BlockAttribute);
		//void FindPathServer(const float* StartLoc, const float* EndLoc, ATTR BlockAttribute, bool object_check, bool trace_flag, std::vector<FNodeCoordinate>& path, int32_t pool_index);
		std::vector<FNodeCoordinate> FindPathDirectServer(const float* StartLoc, const float* EndLoc);
		std::vector<FNodeCoordinate> FindPathBot(const float* StartLoc, const float* EndLoc, ATTR BlockAttribute, bool object_check, bool trace_flag, std::unordered_map<int32_t, int32_t>& map_tile_info, bool full_pathfind = false);
		void FindPathBot(const float* StartLoc, const float* EndLoc, ATTR BlockAttribute, bool object_check, bool trace_flag, std::vector<FNodeCoordinate>& path, std::unordered_map<int32_t, int32_t>& map_tile_info, bool full_pathfind = false);
		inline int32_t		GetCellAttrServer(int32_t index) { return Cell_Attr[index]; };
		bool CheckTile(int32_t index, std::unordered_map<int32_t, int32_t>& map_tile_info);

		FAStarNode* PopFindPathNode(int pool_index, FNodeCoordinate& coordi, FAStarNode* const parent = nullptr);
		void PushFindPathNode(int pool_index, FAStarNode* node);
		bool CheckTileInfo(int x, int y, std::unordered_map<int32_t, int32_t>& map_tile_info);

#else

		// result true if any block attribute has checked
		bool	CheckBlock(int cell_x, int cell_y, bool& result);
		bool	CheckBlock(FNodeCoordinate& CellPos, bool& result);
		bool	CheckBlock(FCell* CellPtr, bool& result);

		// this check returns true if at least one Attribute is check. (Attribute & CellAttribute) != 0;
		bool	CheckAttribute(int cell_x, int cell_y, ATTR Attribute, bool& result);
		bool	CheckAttribute(FNodeCoordinate& CellPos, ATTR Attribute, bool& result);
		bool	CheckAttribute(FCell* CellPtr, ATTR Attribute, bool& result);

		// this check returns true if all Attributes are check. (Attribute & CellAttribute) == Attribute;
		bool	CheckMatchAttribute(int cell_x, int cell_y, ATTR Attribute, bool& result);
		bool	CheckMatchAttribute(FNodeCoordinate& CellPos, ATTR Attribute, bool& result);
		bool	CheckMatchAttribute(FCell* CellPtr, ATTR Attribute, bool& result);

		bool	ClearAttribute(int cell_x, int cell_y);
		bool	ClearAttribute(FNodeCoordinate& CellPos);
		bool	ClearAttribute(FCell* CellPtr);

		bool	ClearBlockAttributeListAll();
		bool	ClearBlockAttributeList(int cell_x, int cell_y);
		bool	ClearBlockAttributeList(FNodeCoordinate& CellPos);
		bool	ClearBlockAttributeList(FCell* CellPtr);

		bool	GetBlockAttributeList(int cell_x, int cell_y, ATTR Attribute, std::vector<int64_t>& outList);
		bool	GetBlockAttributeList(FNodeCoordinate& CellPos, ATTR Attribute, std::vector<int64_t>& outList);
		bool	GetBlockAttributeList(FCell* CellPtr, ATTR Attribute, std::vector<int64_t>& outList);

		bool	GetAttribute(int cell_x, int cell_y, ATTR& Attribute);
		bool	GetAttribute(FNodeCoordinate& CellPos, ATTR& Attribute);
		bool	GetAttribute(FCell* CellPtr, ATTR& Attribute);
		bool	SetAttribute(int cell_x, int cell_y, ATTR Attribute);
		bool	SetAttribute(FNodeCoordinate& CellPos, ATTR Attribute);
		bool	SetAttribute(FCell* CellPtr, ATTR Attribute);

		bool	AddAttribute(int cell_x, int cell_y, ATTR Attribute);
		bool	AddAttribute(FNodeCoordinate& CellPos, ATTR Attribute);
		bool	AddAttribute(FCell* CellPtr, ATTR Attribute);
		bool	AddAttribute(int cell_x, int cell_y, ATTR Attribute, int64_t uid);
		bool	AddAttribute(FNodeCoordinate& CellPos, ATTR Attribute, int64_t uid);
		bool	AddAttribute(FCell* CellPtr, ATTR Attribute, int64_t uid);
		bool	RemoveAttribute(int cell_x, int cell_y, ATTR Attribute);
		bool	RemoveAttribute(FNodeCoordinate& CellPos, ATTR Attribute);
		bool	RemoveAttribute(FCell* CellPtr, ATTR Attribute);
		bool	RemoveAttributeByUID(int cell_x, int cell_y, int64_t uid);
		bool	RemoveAttributeByUID(FNodeCoordinate& CellPos, int64_t uid);
		bool	RemoveAttributeByUID(FCell* CellPtr, int64_t uid);

		bool	GetCenterHeight(int cell_x, int cell_y, float& height);
		bool	GetCenterHeight(FNodeCoordinate& CellPos, float& height);
		bool	GetCenterHeight(FCell* CellPtr, float& height);
		bool	SetCenterHeight(int cell_x, int cell_y, float height);
		bool	SetCenterHeight(FNodeCoordinate& CellPos, float height);
		bool	SetCenterHeight(FCell* CellPtr, float height);

		bool	GetGroundMaterial(int cell_x, int cell_y, int& material);
		bool	GetGroundMaterial(FNodeCoordinate& CellPos, int& material);
		bool	GetGroundMaterial(FCell* CellPtr, int& material);
		bool	SetGroundMaterial(int cell_x, int cell_y, int material);
		bool	SetGroundMaterial(FNodeCoordinate& CellPos, int material);
		bool	SetGroundMaterial(FCell* CellPtr, int material);

		bool	GetCameraData(int cell_x, int cell_y, float& outTileRotationSpeed, float& outTileResetTime, float& outRotX, float& outRotY, int& outActionType, CAMERA_TYPE& outCameraDataType);
		bool	GetCameraData(FNodeCoordinate& CellPos, float& outTileRotationSpeed, float& outTileResetTime, float& outRotX, float& outRotY, int& outActionType, CAMERA_TYPE& outCameraDataType);
		bool	GetCameraData(FCell* CellPtr, float& outTileRotationSpeed, float& outTileResetTime, float& outRotX, float& outRotY, int& outActionType, CAMERA_TYPE& outCameraDataType);
		bool	SetCameraData(int cell_x, int cell_y, float TileRotationSpeed, float TileResetTime, float RotX, float RotY, int ActionType, CAMERA_TYPE CameraDataType);
		bool	SetCameraData(FNodeCoordinate& CellPos, float TileRotationSpeed, float TileResetTime, float RotX, float RotY, int ActionType, CAMERA_TYPE CameraDataType);
		bool	SetCameraData(FCell* CellPtr, float TileRotationSpeed, float TileResetTime, float RotX, float RotY, int ActionType, CAMERA_TYPE CameraDataType);

		bool	GetCameraData(int cell_x, int cell_y, CAMERA_TYPE& outCameraDataType, FCellCameraData& outCameraData);
		bool	GetCameraData(FNodeCoordinate& CellPos, CAMERA_TYPE& outCameraDataType, FCellCameraData& outCameraData);
		bool	GetCameraData(FCell* CellPtr, CAMERA_TYPE& outCameraDataType, FCellCameraData& outCameraData);
		bool	SetCameraData(int cell_x, int cell_y, CAMERA_TYPE CameraDataType, FCellCameraData& CameraData);
		bool	SetCameraData(FNodeCoordinate& CellPos, CAMERA_TYPE CameraDataType, FCellCameraData& CameraData);
		bool	SetCameraData(FCell* CellPtr, CAMERA_TYPE CameraDataType, FCellCameraData& CameraData);

		bool	RemoveCameraData(int cell_x, int cell_y);
		bool	RemoveCameraData(FNodeCoordinate& CellPos);
		bool	RemoveCameraData(FCell* CellPtr);

		bool	GetAttackZone(int cell_x, int cell_y, int& zone);
		bool	GetAttackZone(FNodeCoordinate& CellPos, int& zone);
		bool	GetAttackZone(FCell* CellPtr, int& zone);
		bool	SetAttackZone(int cell_x, int cell_y, int zone);
		bool	SetAttackZone(FNodeCoordinate& CellPos, int zone);
		bool	SetAttackZone(FCell* CellPtr, int zone);

		bool	GetSWArea(int cell_x, int cell_y, int& area);
		bool	GetSWArea(FNodeCoordinate& CellPos, int& area);
		bool	GetSWArea(FCell* CellPtr, int& area);
		bool	SetSWArea(int cell_x, int cell_y, int area);
		bool	SetSWArea(FNodeCoordinate& CellPos, int area);
		bool	SetSWArea(FCell* CellPtr, int area);

#endif	// SERVER_USE

		void	GetMapSize(int& sizex, int& sizey);
		void	GetTotalCellCount(int& countx, int& county);
		void	GetCellSize(int& sizex, int& sizey);
		void	GetMapBoundBoxXY(float* min, float* max);		// we do not use z 
		void	GetMapBoundBoxXYZ(float* min, float* max);		// we do not use z 

	public:
		// operations

		// find path entire map. (warning. may very slow if path not found or long distance)
		FPathFindResult FindPath(const float* StartLoc, const float* EndLoc, ATTR BlockAttribute);
		FPathFindResult FindPath(int StartCellX, int StartCellY, int EndCellX, int EndCellY, ATTR BlockAttribute);
		FPathFindResult FindPath(FNodeCoordinate& StartCellPos, FNodeCoordinate& EndCellPos, ATTR BlockAttribute);

		// find path by previous history. (warning. may very slow if path not found or long distance)
		FPathFindResult FindPath(const float* StartLoc, const float* EndLoc, ATTR BlockAttribute, std::vector<FNodeCoordinate>& History);

		// find path with limited area (includes both start and end point in result if unblocked)
		FPathFindResult FindPath(const float* StartLoc, const float* EndLoc, ATTR BlockAttribute, std::vector<FNodeCoordinate>& History,
			const float* MinLoc, const float* MaxLoc, bool TryToFindPartialPath, float TimeOutSecond);
		FPathFindResult FindPath(int StartCellX, int StartCellY, int EndCellX, int EndCellY, ATTR BlockAttribute, std::vector<FNodeCoordinate>& History,
			const float* MinLoc, const float* MaxLoc, bool TryToFindPartialPath, float TimeOutSecond);
		FPathFindResult FindPath(FNodeCoordinate& StartCellPos, FNodeCoordinate& EndCellPos, ATTR BlockAttribute, std::vector<FNodeCoordinate>& History,
			const float* MinLoc, const float* MaxLoc, bool TryToFindPartialPath, float TimeOutSecond);

		FPathFindResult FindPathWithOption(FNodeCoordinate& StartCellPos, FNodeCoordinate& EndCellPos, ATTR BlockAttribute, std::vector<FNodeCoordinate>& History,
			const float* MinLoc, const float* MaxLoc, float TimeOutSecond, FOPTION FindOption);

		// used when end location is blocked
		FPathFindResult FindNearestPath(const float* StartLoc, const float* EndLoc, ATTR BlockAttribute, std::vector<FNodeCoordinate>& History,
			const float* MinLoc, const float* MaxLoc, bool FindForward, float TimeOutSecond);
		FPathFindResult FindNearestPath(int StartCellX, int StartCellY, int EndCellX, int EndCellY, ATTR BlockAttribute, std::vector<FNodeCoordinate>& History,
			const float* MinLoc, const float* MaxLoc, bool FindForward, float TimeOutSecond);
		FPathFindResult FindNearestPath(FNodeCoordinate& StartCellPos, FNodeCoordinate& EndCellPos, ATTR BlockAttribute, std::vector<FNodeCoordinate>& History,
			const float* MinLoc, const float* MaxLoc, bool FindForward, float TimeOutSecond);

		FPathFindResult FindNearestPathWithOption(FNodeCoordinate& StartCellPos, FNodeCoordinate& EndCellPos, ATTR BlockAttribute, std::vector<FNodeCoordinate>& History,
			const float* MinLoc, const float* MaxLoc, float TimeOutSecond, FOPTION FindOption);

		bool FindNearestNeighborCell(const float* Loc, const float* FromLoc, ATTR BlockAttribute, int& outX, int& outY);
		bool FindNearestNeighborCell(FNodeCoordinate& DestCellPos, FNodeCoordinate& StartCellPos, ATTR BlockAttribute, FNodeCoordinate& OutNewDestCellPos);
		bool FindAnyUnblockedNeighborCell(FNodeCoordinate& DestCellPos, ATTR BlockAttribute, FNodeCoordinate& OutNewDestCellPos);

		bool DuplicateCell(FCell& Source, FCell& Target);

		int CalculatePathListTotalCost(std::vector<FNodeCoordinate>& PathList);
		int CalculatePathDistance(FNodeCoordinate& StartCellPos, FNodeCoordinate& EndCellPos);

	public:
		void	Optimize(bool left, bool top, bool right, bool bottom);

		// cell distance related
	public:
		int		CalculateCellDistance(const float* v1, const float* v2);
		bool	GetNeighborDistance(int cell_x, int cell_y, int DirIndex, float& distance);
		bool	GetNeighborDistance(FNodeCoordinate& CellPos, int DirIndex, float& distance);
		bool	GetNeighborDistance(FCell* CellPtr, int DirIndex, float& distance);
		void	CalculateNeighborDistance();

		// replacement cell data related
	public:
		int		GetTotalReplacementCellGroup();
		int		GetTotalReplacementCellInGroup(int GroupNum);
		int		GetEmptyReplacemnetCellGroupNum();
		bool	GetReplacementCellGroupData(int GroupNum, std::vector<FCell>& CellGroupList);

		bool	AddReplacementCellData(int GroupNum, FCell& Data);
		bool	RemoveReplacementCellData(int GroupNum, int cell_x, int cell_y);
		bool	RemoveReplacementCellData(int GroupNum, FNodeCoordinate& CellPos);
		bool	RemoveReplacementCellGroup(int GroupNum);

		bool	ReplaceCellByGroupNumber(int GroupNum);

		bool	UpdateReplacementCellGroup(int GroupNum);	// update all from current cell data

		// region related
	public:
		int		GetTotalRegionCount() { return TotalRegionCountX_ * TotalRegionCountY_; }
		int		GetTotalRegionCountX() { return TotalRegionCountX_; }
		int		GetTotalRegionCountY() { return TotalRegionCountY_; }
		int		GetRegionSizeX() { return REGION_SIZE_X_; }
		int		GetRegionSizeY() { return REGION_SIZE_Y_; }
		int		GetTotalPathFlagInfo() { return TotalPathFlagInfo_; }
		int		GetNextPathFlagIndex();

	public:
		bool	CreateRegion(const float* WorldSize, int RegionSizeX = DEFAULT_REGION_SIZE_X, int RegionSizeY = DEFAULT_REGION_SIZE_Y);

	protected:
		bool	ReadPathFlagInfoV1(FPathFlagInfo* PathFlagInfo, FILE* fp);
		bool	ReadPathFlagInfoV2(FPathFlagInfo* PathFlagInfo, FILE* fp);
		bool	ReadPathFlagInfoV3(FPathFlagInfo* PathFlagInfo, FILE* fp);

		bool	ReadPathFlagV3(FPathFlag* PathFlag, FILE* fp);
		bool	ReadPathFlagV5(FPathFlag* PathFlag, FILE* fp);

		bool	ReadRegionV3(FRegion* Region, FILE* fp);
		bool	ReadRegionV4(FRegion* Region, FILE* fp);

		bool	WritePathFlagInfo(FPathFlagInfo* PathFlagInfo, FILE* fp);
		bool	WritePathFlag(FPathFlag* PathFlag, FILE* fp);
		bool	WriteRegion(FRegion* Region, FILE* fp);

		bool	LoadRegion_Version1(FILE* fp);
		bool	LoadRegion_Version2(FILE* fp);
		bool	LoadRegion_Version3(FILE* fp);
		bool	LoadRegion_Version4(FILE* fp);
		bool	LoadRegion_Version5(FILE* fp);

	public:
		bool	LoadRegion(const char* path);
		bool	SaveRegion(const char* path);

		// for debug check
		bool	ReportRegionToText(const char* path);
		bool	ReportPathFlagConnectionToText(const char* path);

	public:
		// WE DO NOT COMPARE Vector "Z" but data is needed.
		FRegion* GetRegionPtr(int index);
		FRegion* GetRegionPtr(int region_x, int region_y);

		FPathFlag* GetPathFlagPtr(const float* Loc);
		FPathFlag* GetPathFlagPtr(int index);
		int		GetPathFlagIndex(const float* Loc);
		int		GetTotalPathFlag() { return TotalPathFlags_; }

		FPathFlagInfo* GetPathFlagInfoPtr(int index);
		FPathFlagInfo* GetPathFlagInfoPtrById(int id);
		FPathFlagInfo* GetPathFlagInfoPtr(float* v1, float* v2);

		int		RegionPosToRegionIndex(int region_x, int region_y);
		bool	WorldPosToRegionPos(const float* Loc, int& out_region_x, int& out_region_y);

		bool	AddNeighborFlagInPathFlag(float* Loc, int PathFlagInfoId);
		bool	AddNeighborFlagInPathFlag(float* v1, float* v2);

		//int		AddPathFlagInfo(float* v1, float* v2, std::vector<FNodeCoordinate> &PathList);
		//int		AddPathFlagInfo(float* v1, float* v2, std::vector<FNodeCoordinate> &PathList, int HalfWayPointIndex = INVALID_INDEX);
		int		AddPathFlagInfo(float* v1, float* v2, int Cost);

		bool	AddPathFlag(float* v1, float* v2, std::vector<FNodeCoordinate>& PathList);
		bool	AddPathFlag(float* v1, float* v2, int Cost);
		bool	AddPathFlag(float* Loc);

		void	RemoveAllErrorPathFlags();
		void	RemapNeighborPathFlagInfo(FPathFlag* PathFlag);
		void	RemapAllNeighborPathFlagInfo();
		void	RemapAllPathFlagInfoVertexIndex();
		void	RemapAllRegionPathFlag();

	public:
		// operation
		FPathFlag* FindNearestPathFlag(const float* Loc, ATTR BlockAttribute, float(*CalcDistanceFunc)(const float*, const float*));
		FPathFlag* FindNearestPathFlag(const float* Loc, ATTR BlockAttribute);
		FPathFlag* FindNearestPathFlagXY(const float* Loc, ATTR BlockAttribute);
		FPathFindResult FindPathFlagPathList(FPathFlag& StartPathFlag, FPathFlag& DestPathFlag);
		FPathFindResult FindPathFlagPathList(const float* StartLoc, const float* EndLoc);

		bool FindExpandedPathList(std::vector<FNodeCoordinate>& BasePathList, std::vector<FNodeCoordinate>& ResultPathList, std::vector<FNodeCoordinate>& IgnorePathList, bool bUseRightDirection, int DistanceFromBasePath = 1);
		bool FindExpandedPathPoint(const std::vector<FNodeCoordinate>& PathList, bool bUseRightDirection, const std::vector<FNodeCoordinate>& ResultPathList, std::vector<FNodeCoordinate>& AddPoint, std::vector<FNodeCoordinate>& RemovePoint);

		void MakePathPointCost();
		int CalculatePathFlagTotalCost(FPathFindResult Result);

		// used when long distance minimap. returns only each path flag points
		FPathFindResult GetFullPath(const float* StartLoc, const float* EndLoc);

#ifdef SERVER_USE
	protected:
		void	InitServer();
		void	DestroyServer();

		void	LoadServerCell();

		ATTR* Cell_Attr;
		int TotalCellCount;
		std::map<int, std::queue<FAStarNode*>> _node_pool;
#endif

	protected:
		// world cell reated
		FCellBase** WorldCell_;

		int TotalCellCountX_;
		int TotalCellCountY_;

		int StartCellX_, StartCellY_;

		int CELL_SIZE_X_;
		int CELL_SIZE_Y_;

		// used only path point map or neighbor distance
		int NeighborDirCount_;

		// extra data
		std::vector<std::vector<FCell>> ReplacementCells_;

		// region related
		std::vector<std::vector<std::pair<int, int>>> PathPointCost_;
		FPathFlagInfo* PathFlagInfo_;
		FPathFlag* PathFlags_;
		FRegion* Region_;

		int TotalPathFlagInfo_;
		int TotalPathFlags_;

		int NextPathFlagInfoId_;
		int TotalRegionCountX_;
		int TotalRegionCountY_;

		int REGION_SIZE_X_;
		int REGION_SIZE_Y_;
	};

	// internal use only
	extern int g_FindDirections;
	extern FNodeCoordinate g_Direction[];
	extern FNodeCoordinate* g_CWDirection;
	extern std::function<int(FNodeCoordinate, FNodeCoordinate)> g_Heuristic;

	struct FAStarNode
	{
		int G, H;
		FNodeCoordinate coordinates;

		FRegion* Region;
		FPathFlag* PathFlag;

		FAStarNode* parent;

		FAStarNode(FNodeCoordinate coordi, FAStarNode* parent_ = nullptr);
		FAStarNode(FNodeCoordinate coordi, FPathFlag* PathFlag_, FAStarNode* parent_ = nullptr);
		int GetScore();

#ifdef SERVER_USE
		void Initialize(FNodeCoordinate coordi, FAStarNode* parent_ = nullptr);
		void Release();
#endif
	};

	FAStarNode* g_FindNodeOnList(std::set<FAStarNode*>& Nodes, FNodeCoordinate coordi);
	FAStarNode* g_FindNodeOnList(std::set<FAStarNode*>& Nodes, FNodeCoordinate coordi, FPathFlag& PathFlag);
	void g_ReleaseNodes(std::set<FAStarNode*>& Nodes);

#ifdef SERVER_USE
	bool FindNodeOnList(std::unordered_map<int32_t, std::vector<FAStarNode*>>& nodes, FNodeCoordinate& coordi);
	void ReleaseNodesServer(std::unordered_map<int32_t, std::vector<FAStarNode*>>&);
#endif
}
