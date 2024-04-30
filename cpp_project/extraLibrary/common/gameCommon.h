#pragma once

#include <cstdint>

namespace mir3d
{
	#define CAST_INT(val)		static_cast<int32_t>(val)

	#define RPCTAG_STRING_LOBBY		"lobby"
	#define RPCTAG_STRING_MANAGER	"manager"
	#define RPCTAG_STRING_DATABASE	mrpce_server_type::database
	#define RPCTAG_STRING_EXCHANGE	"exchange"
	#define RPCTAG_PREFIX_GAME 		"g_"
	#define RPCTAG_PREFIX_INDUN 	"i_"

	#define SESSION_CONTEXT_KEY		"CUID"
	#define SESSION_ZONE_KEY		"ZONE_TAG"
	#define SESSION_PLAYER_KEY		"AUID"

	#define SHARE_PI				(3.1415926535897932f)
	//#define RADIANS_TO_DEGREES		(57.2957764) // (180.f / SHARE_PI)
	//#define DEGREES_TO_RADIANS		(0.0174532924) // (SHARE_PI / 180.f)
	#define SHARE_INV_PI			(0.31830988618f)
	#define SHARE_HALF_PI			(1.57079632679f)
	#define RADIANS_360				(6.28318548f)
	#define RADIANS_180				(3.14159274f)	

	#define RESERVE_SIZE_8				8
	#define RESERVE_SIZE_16				16
	#define	RESERVE_SIZE_64		        64
	#define RESERVE_SIZE_128			128
	#define RESERVE_SIZE_256			256
	#define	RESERVE_SIZE_512			512
	#define RESERVE_SIZE_1024			1024
	#define RESERVE_SIZE_5120			5120
	#define RESERVE_SIZE_10240			10240

	#define BROADCAST_COUNT				30
	
//	#define GAME_ZONE_SECTOR_SIZE	2300			// 섹터의 가로 세로 크기
//	#define INDUN_ZONE_SECTOR_SIZE	2400			// 섹터의 가로 세로 크기
	#define INVALID_SECTOR_INDEX	-1				// 잘못된 섹터 인덱스

	#define PLAYER_CHARACTER_EQUIP_ITEM	2

	#define CHAT_COMMAND_SEPERATOR ' '

#ifdef _USE_EVENT_LOG
	#define ZONE_TEST_COUNT				1
#endif

	//#define _MOVE_UPDATE_TIME					0.3f

	//#define FSM_SEARCH_DISTANCE		5			// 5 미터(임시)
	//#define FSM_TRACE_DISTANCE		10			// 10 미터(임시)
	//#define FSM_ATTACK_DISTANCE		1			// 1 미터(임시)

	// #define ITEM_USE_INDEX_COUNT		2			// 아이템 사용목록 저장소 갯수
	// #define ITEM_USE_LIST_MAX			16			// 저장소 크기
	// #define ITEM_USE_UPDATE_TIME		5.f			// database 로 업데이트 될 시간 ( test 5s )
	#define DATABASE_UPDATE_TIME		3 * 60 * 1000	// database 로 업데이트 될 시간

	#define QUICK_SLOT_MAX_COUNT		3			// hp, mp 슬롯 등록 최대 개수

	#define INIT_DAILY_CONTENT_VALUE	19000101

	//enum class eDirection  : int32_t
	//{
	//	/*
	//	7   0   1
	//	6  obj  2
	//	5   4   3
	//	*/
	//	nn = 0,		// 북북	0
	//	ne,			// 북동	1
	//	ee,			// 동동	2
	//	es,			// 동남	3
	//	ss,			// 남남	4
	//	sw,			// 남서	5
	//	ww,			// 서서	6
	//	wn,			// 서북	7
	//	max
	//};

	//enum class eCellDirection : int32_t
	//{
	//	ne = 0,			// 북동
	//	es = 1,			// 동남
	//	sw = 2,			// 남서
	//	wn = 3,			// 서북
	//	max
	//};

	// enum class eEquipPos : int32_t
	// {
	// 	weapon	= 0,		// 무기
	// 	sub_weapon,			// 보조무기
	// 	helmet,				// 투구
	// 	armor,				// 갑옷
	// 	necklace,			// 목걸이
	// 	braceletR,			// 팔찌 R
	// 	braceletL,			// 팔찌 L
	// 	ringR,				// 반지 R
	// 	ringL,				// 반지 L
	// 	belt,				// 허리띠
	// 	shoes,				// 신발
	// 	cape,				// 망토
	// 	vehicle,			// 탈것
	// 	max
	// };
	enum class Profesion_State : int8_t
	{
		Make = 0,
		Update = 1,
		Reset = 2,
	};
	// Map_Object_Data_Table.xlsx의 오브젝트 타입
	//enum class eMapObjectType : int32_t
	//{
	//	point				= 1,			// 포인트
	//	gate_pos			= 2,			// 게이트 위치
	//	npc					= 3,			// npc
	//	collect				= 4,			// 채집물
	//	monster_group_id	= 5,			// 몬스터 그룹(삭제 예정)
	//	monster				= 6,			// 몬스터
	//	fishing				= 8,			// 낚시터
	//	max
	//};

	// 서버에서 사용 할 Object Type
	//enum class mpe_object_type : int32_t
	//{
	//	character			= 0,			// 캐릭터
	//	monster				= 1,			// 몬스터
	//	drop_item			= 2,			// 드랍 아이템
	//	collect				= 3,			// 수집물(채광, 약초, 나무...)
	//	npc					= 4,			// npc
	//	character_minion	= 5,
	//	siege_weapon		= 6,
	//	fixed_object		= 7,
	//	mercenary			= 8,
	//	treasure_box		= 9,
	//	max = 10,
	//};

	enum class ePlayerStatus : int32_t
	{
		none				= 0,
		wait				= 1,
		enter				= 2,
		playing				= 3,
		change_zone			= 4,
		going_out			= 5,
		channel_move		= 6, 
		max
	};

	enum class eStatType : int32_t
	{
		base = 0,
		abs = 1,
		percent = 2,
		max
	};

	enum class eBuffCancelType : int32_t
	{
		none = 0,
		cancel_skill = 1,
	};

	//enum eAttribute
	//{
	//	attribute_none = 0,
	//	attribute_mhp = 1,
	//	attribute_mmp = 2,
	//	attribute_patk_min = 3,
	//	attribute_patk_max = 4,
	//	attribute_matk_min = 5,
	//	attribute_matk_max = 6,
	//	attribute_pdef_min = 7,
	//	attribute_pdef_max = 8,
	//	attribute_mdef_min = 9,
	//	attribute_mdef_max = 10,
	//	attribute_cri_rate = 11,
	//	attribute_cri_resist = 12,
	//	attribute_cc_rate = 13,
	//	attribute_cc_resist = 14,
	//	attribute_move_walk = 15,
	//	attribute_move_run = 16,
	//	attribute_accuracy = 17,
	//	attribute_evade = 18,
	//	attribute_patk_all = 19,
	//	attribute_matk_all = 20,
	//	attribute_pdef_all = 21,
	//	attribute_mdef_all = 22,
	//	attribute_hp = 23,
	//	attribute_mp = 24,
	//	attribute_invincibility = 25,
	//	attribute_noaction = 26,
	//	attribute_shield = 27,
	//	attribute_hide = 28,
	//	attribute_all_atk = 29,
	//	attribute_all_def = 30,
	//	attirbute_pentrate_rate = 31,
	//	attirbute_pentrate_value = 32,
	//	attirbute_luck = 33,
	//	attribute_superarmor = 34,
	//	attribute_hp_heal = 35,			// 치유 효과
	//	attribute_silence = 36,		// 침묵
	//	attribute_penetrate = 37,
	//	attribute_curse = 38,
	//	attribute_atk_max_rate = 39,
	//	attribute_atk_min_rate = 40,
	//	attribute_confusion = 41,
	//	attribute_zen = 42,
	//	attribute_atk_speed = 43,
	//	attribute_force = 44,		// 내력치 (내공스킬사용시 사용)
	//	attribute_max_force = 45,	// 내력 최대치 
	//	attribute_max,
	//};

	enum class eIndunPrepareState : uint8_t
	{
		none = 0,
		vote = 1,
		auto_matching = 2,
		redirecting = 3,
		in_room = 4,
		arena_matching = 5,
	};

	// 입찰금 index
	enum class eTenderType : uint8_t
	{
		default_min_tender = 0,  // 테이블 지정 최초 최소 입찰금
		default_max_tender = 1,	 // 테이블 지정 최초 최대 입찰금
		current_tender = 2,  // 현재 최대 입찰금
		next_min_tender = 3, // 다음 최소 입찰금
		next_max_tender = 4, // 다음 최대 입찰금
		max = 5
	};

	// pet open shop type
	enum class ePetOpenShopType : uint8_t
	{
		buy = 0,
		sell = 1,
		repair = 2
	};

	enum class eZoneCreateState : uint8_t
	{ 
		none = 0, 
		variable = 1, 
		tile = 2, 
		sector = 3, 
		pool = 4, 
		object = 5,
		complete = 6 
	};

	enum class eSpecialMoveOrder : uint8_t
	{
		Reflection = 0,
		Awake = 1,
	};

	// 일괄종료 대상이 되는 버프 구분자 현재는 신기쪽만 해당
	enum class eChainedBuffDelimiter : uint8_t
	{
		none = 0,
		expert_buff,
	};

} // namespace mir3d
