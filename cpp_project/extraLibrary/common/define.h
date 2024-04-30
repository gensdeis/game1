#pragma once

#include "mirapi.h"
#include "../table/header/_common_enum.h"

namespace mir3d
{
#ifdef _WINDOWS
	#define DIRECTORY_SEPARATOR_STRING			"\\"

	//#if _MSC_VER >= 1800 // VS2013
	//#define UTIL_DECLARE_NOCOPY(ClassName) ClassName(const ClassName&) = delete; ClassName& operator=(const ClassName&) = delete
	//#endif	
#else
	#ifdef __GNUC__
	#define UTIL_GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
	#if UTIL_GCC_VERSION >= 40400 /* GCC 4.4+ */
	#define UTIL_DECLARE_NOCOPY(ClassName) ClassName(const ClassName&) = delete; ClassName& operator=(const ClassName&) = delete
	#endif
	#endif
	#define DIRECTORY_SEPARATOR_STRING			"/"
#endif

	#define _SIEGE_TEST
		
	const int32_t   ACTION_LOG_TEXT_SIZE = 1024;
	const int32_t	ACTION_LOG_BUNDLE_MAX = 20;

	/// 테이블 max 값 체크용
    // enchant option
	// 장비 감정 옵션 기본 최대 개수
    const int32_t   ENCHANT_OPTION_MAX = 4;
    const int32_t   ENCHANT_OPTION_GENERATE_MAX = 5;
	const int32_t   EQUIP_AWAKEN_UNIQUE_OPTION_MAX = 1;
	const int32_t   EQUIP_AWAKEN_OPTION_MAX = 2;
    // meridians 
    const int32_t   MERIDIANS_PAGE_MAX = 2;
    const int32_t   MERIDIANS_ACUPOINT_MAX = 5;
    const int32_t   MERIDIANS_MAX_LEVEL = 5;
    const int32_t   MERIDIANS_ACUPOINT_MAX_LEVEL = 5;

	const int32_t	MAX_REINFORCE_MATERIAL_COUNT = 5;

	const int32_t   MENTOR_LEVEL = 35;

	const int32_t	MAX_INVEN = 500;
	const int32_t	QUEST_HISTORY_MAX = 850;
	const int32_t	PET_COLLECT_MAX = 500;
	const int32_t	PK_RECORD_MAX = 20;
	const int32_t	PK_REVENGE_RECORE_MAX = 5;
	///

	// condition / condition_bag
	const int32_t	DAILY_RESET_HOUR = 0;
	const int32_t	CONDITION_MAP_REWARD_PROB = 500;	// 피로도 획득 맵 보상 확률(10000분율)
	const int32_t	CONDITION_MAP_REWARD_VALUE = 1;		// 피로도 획득 맵 보상 값

	// 용령석 슬롯 온오프
	const int32_t	ENCHANT_STONE_SLOT_LOCK = -1;		// -1 : 슬롯 잠금
	const int32_t	ENCHANT_STONE_SLOT_OPEN = 0;		// 0 : 슬롯 개방

	const int32_t	VECTOR_INDEX_INIT = -1;

	// 과몰입 일일 제한 시간 (단위 s)
	const int32_t	LIMIT_DAY_PLAYTIME = 90 * 60;		// 미성년 일일 90분 제한 (test 시간 : 10분)
	const int32_t	LIMIT_HOLIDAY_PLAYTIME = 300 * 60;	// 미성년 휴일 300분 제한 (test 시간 : 30분)
    		
	// 도감 진행 확률 10000 보정
	const float		DICTIONARY_MAX_RATE = 10000.0f;


	// 각도 계산 처리용
	const float RADIANS_TO_DEGREES = 57.2957f; //57.2957764; // (180.f / SHARE_PI)
	const float DEGREES_TO_RADIANS = 0.01745f; //0.0174532924;

	// 시즌패스 도전과제 키
	const int64_t	MAKE_CHALLENGE_KEY = 100000000;
	const int64_t	MAKE_CHALLENGE_SUB_KEY = 100000;

	const int32_t	EVENT_LOGIN_TIME_MAX = 180;

	const int32_t	DEFAULT_SPECIAL_MOVE_LEVEL = 1;		// 필살기 기본 레벨 

	const int32_t	CASH_SHOP_ITEM_TYPE = 17;			// 케쉬샵 현금 구매 아이템 타입

	const int64_t	Int64_MaxValue = 9223372036854775807;

	const uint64_t	UPDATE_RPCINFO_TIME = 3 * 1000;
	const uint64_t	UPDATE_CONTENTS_TIME = 10 * 1000;	// 게임 컨텐츠 기본 정보 업데이트
	const uint64_t  UPDATE_SEND_CHANNEL_CREATE_INFO = 3 * 1000;

}	// namespace mir3d
