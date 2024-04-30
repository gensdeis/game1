#include "stdafx_net.h"
#include "util.h"
#include <common/serverlogManager.h>

#ifdef _WINDOWS	
#include <Windows.h>
#endif

namespace mir3d
{
	namespace util
	{
		const int32_t DAY_IN_SEC = 24 * 60 * 60;
		const int32_t EVENT_LOGIN_TIME_MAX_SEC = EVENT_LOGIN_TIME_MAX * 60 * 1000;

		int64_t mirTime::_time_zone = 0;
		int32_t mirTime::_global_time_zone = 0;
//#if _USE_GLOBAL_SERVICE
		int64_t mirTime::_config_time_zone = 0;
		int32_t mirTime::_time_zone_value = 0;
//#endif // _USE_GLOBAL_SERVICE

		static long double MillisecondFreq = 0.0l;
		static long double MicrosecondFreq = 0.0l;
		static long double NanosecondFreq = 0.0l;


		CUidGenerate::CUidGenerate()
		{
			_list_uid.reserve(static_cast<int32_t>(eUid::max));
			_list_compare_uid.reserve(static_cast<int32_t>(eUid::max));

			for (int32_t i = 0; i < static_cast<int32_t>(eUid::max); i++)
			{
				_list_uid.emplace_back(new std::atomic<uint64_t>(0));
				_list_compare_uid.emplace_back(new std::atomic<uint64_t>(0));
			}


			std::time_t t = std::time(nullptr);

			// 기준 시간에서 현재 시간의 차이를 구한다.
			int64_t diff = t - static_cast<int64_t>(eUid::BASE_TIME);

			std::string diffSec = std::to_string(diff);
			std::string diffSeconds = std::string(9 - diffSec.size(), '0') + diffSec;


			_session_uid = new std::atomic<uint64_t>(0);

			(*_session_uid) = std::stoll(diffSeconds + "000000000");
		};

		CUidGenerate::~CUidGenerate()
		{
			Destroy();
		}

		bool CUidGenerate::Initialize(int32_t server_gid, int32_t server_index)
		{
			_base_key = std::to_string(server_gid * 100 + server_index);

			std::time_t t = std::time(nullptr);

			//// 기준 시간에서 현재 시간의 차이를 구한다.
			int64_t diff = t - static_cast<int64_t>(eUid::BASE_TIME);


			/* old 버전
			(*_list_uid[static_cast<int32_t>(eUid::player)]) = std::stoll(std::to_string(static_cast<int32_t>(eUid::player)) + std::to_string(server_index) + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::character)]) = std::stoll(std::to_string(static_cast<int32_t>(eUid::character)) + std::to_string(server_index) + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::guild)]) = std::stoll(std::to_string(static_cast<int32_t>(eUid::guild)) + std::to_string(server_index) + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::indun)]) = std::stoll(std::to_string(static_cast<int32_t>(eUid::indun)) + std::to_string(server_index) + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::zone)]) 	= std::stoll(std::to_string(static_cast<int32_t>(eUid::zone)) + std::to_string(server_index) + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::object)]) = std::stoll(std::to_string(static_cast<int32_t>(eUid::object)) + std::to_string(server_index) + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::item)]) = std::stoll(std::to_string(static_cast<int32_t>(eUid::item)) + std::to_string(server_index) + diffSeconds + "0000");	// inventory item 생성 시 사용

			(*_list_uid[static_cast<int32_t>(eUid::skill)]) = std::stoll(std::to_string(server_index) + diffSeconds + "00000");
			(*_list_uid[static_cast<int32_t>(eUid::mail)]) = std::stoll(std::to_string(server_index) + diffSeconds + "00000");
			(*_list_uid[static_cast<int32_t>(eUid::trade)]) = std::stoll(std::to_string(server_index) + diffSeconds + "00000");
			(*_list_uid[static_cast<int32_t>(eUid::pkrecord)]) = std::stoll(std::to_string(server_index) + diffSeconds + "00000");
			(*_list_uid[static_cast<int32_t>(eUid::reflection)]) = std::stoll(std::to_string(server_index) + diffSeconds + "00000");
			(*_list_uid[static_cast<int32_t>(eUid::party)]) = std::stoll(std::to_string(server_index) + diffSeconds + "00000");
			(*_list_uid[static_cast<int32_t>(eUid::pet)]) = std::stoll(std::to_string(server_index) + diffSeconds + "00000");
			*/


			/* new 버전 (2022-06-10)
			// [Global Unique UID]
			//
			// 글로벌+서버 유니크 해야 하는경우
			// 자릿수		9									10
			//				123456789   : 시간차이(unix현재)
			//			+    123456		: GID+INDEX
			//			=   123456789	: 결과					0000000000  : 나머지  ->    1357967890000000000 (순차증가)

			// 글로벌 유니크 해야 하는 경우
			// 자릿수		9									10
			//				123456789  : 시간차이(unix현재)
			//			+    1234		: GID
			//			=   135796789	: 결과					0000000000  : 나머지  ->    1357967890000000000 (순차증가)

			//  적용
			//	[ Global Unique UID ]
			//	GID            server_index		시간차이(unix현재)          나머지
			//	4              2                9							4
			*/

			std::string diffSec = std::to_string(diff);
			std::string diffSeconds = std::string(9 - diffSec.size(), '0') + diffSec;

			(*_list_uid[static_cast<int32_t>(eUid::player)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::character)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::guild)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::indun)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::zone)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::object)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::item)]) = std::stoll(_base_key + diffSeconds + "0000");	// inventory item 생성 시 사용

			(*_list_uid[static_cast<int32_t>(eUid::skill)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::mail)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::trade)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::pkrecord)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::reflection)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::party)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::pet)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::global_exchange)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_uid[static_cast<int32_t>(eUid::buff_chain_key)]) = std::stoll(_base_key + diffSeconds + "0000");

			(*_list_compare_uid[static_cast<int32_t>(eUid::player)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_compare_uid[static_cast<int32_t>(eUid::character)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_compare_uid[static_cast<int32_t>(eUid::guild)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_compare_uid[static_cast<int32_t>(eUid::indun)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_compare_uid[static_cast<int32_t>(eUid::zone)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_compare_uid[static_cast<int32_t>(eUid::object)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_compare_uid[static_cast<int32_t>(eUid::item)]) = std::stoll(_base_key + diffSeconds + "0000");	// inventory item 생성 시 사용

			(*_list_compare_uid[static_cast<int32_t>(eUid::skill)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_compare_uid[static_cast<int32_t>(eUid::mail)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_compare_uid[static_cast<int32_t>(eUid::trade)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_compare_uid[static_cast<int32_t>(eUid::pkrecord)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_compare_uid[static_cast<int32_t>(eUid::reflection)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_compare_uid[static_cast<int32_t>(eUid::party)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_compare_uid[static_cast<int32_t>(eUid::pet)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_compare_uid[static_cast<int32_t>(eUid::global_exchange)]) = std::stoll(_base_key + diffSeconds + "0000");
			(*_list_compare_uid[static_cast<int32_t>(eUid::buff_chain_key)]) = std::stoll(_base_key + diffSeconds + "0000");

			return true;
		}

		uint64_t CUidGenerate::Get(eUid type)
		{
			if (9000 > _list_compare_uid[static_cast<int32_t>(type)]->load() % 10000)
			{
				_list_compare_uid[static_cast<int32_t>(type)]->fetch_add(1);
				return _list_uid[static_cast<int32_t>(type)]->fetch_add(1);
			}
			else
			{
				std::lock_guard<std::mutex> lock(_lock);

				if (9000 > _list_compare_uid[static_cast<int32_t>(type)]->load() % 10000)
				{
					_list_compare_uid[static_cast<int32_t>(type)]->fetch_add(1);
					return _list_uid[static_cast<int32_t>(type)]->fetch_add(1);
				}

				std::time_t t = std::time(nullptr);
				int64_t diff = t - static_cast<int64_t>(eUid::BASE_TIME);
				std::string diffSec = std::to_string(diff);
				std::string diffSeconds = std::string(9 - diffSec.size(), '0') + diffSec;

				auto value = std::stoll(_base_key + diffSeconds + "0000");

				_list_compare_uid[static_cast<int32_t>(type)]->exchange(value);
				_list_uid[static_cast<int32_t>(type)]->exchange(value);

				_list_compare_uid[static_cast<int32_t>(type)]->fetch_add(1);
				return _list_uid[static_cast<int32_t>(type)]->fetch_add(1);
			}
		}

		uint64_t CUidGenerate::GetSessionId()
		{
			return _session_uid->fetch_add(1);
		}

		void CUidGenerate::Destroy(void)
		{
			for (size_t i = 0; i < _list_uid.size(); i++)
			{
				delete _list_uid[i];
			}

			delete _session_uid;
		}

		int64_t randomGenerator::GetUid(void)
		{
			static std::mt19937_64							_random_mt(std::random_device{} ());
			static std::uniform_int_distribution<int64_t>	_dist(0, MAX_INT64);

			return _dist(_random_mt);
		}

		bool mirTime::sInitializeFrequencies()
		{
#ifdef _WINDOWS	
			LARGE_INTEGER li;
			bool b = ::QueryPerformanceFrequency(&li);


			long double freq = static_cast<long double>(li.QuadPart);

			MillisecondFreq = 1000.0l / freq;
			MicrosecondFreq = 1000000.0l / freq;
			NanosecondFreq = 1000000000.0l / freq;
#endif
			return true;
		}

		void mirTime::InitializeFrequencies()
		{

			static bool initialized = false;
			if (!initialized)
			{
				initialized = sInitializeFrequencies();
			}

		}

		uint64_t mirTime::NowMSec()
		{
			struct timespec now;
#ifdef _WINDOWS			
			int ret = timespec_get(&now, TIME_UTC);
			if (ret == 0)
			{

			}

#else
			clock_gettime(CLOCK_MONOTONIC, &now);

#endif
			return (now.tv_sec * 1000 * 1000 + now.tv_nsec / 1000) / 1000;
		}

#ifdef _ORG_TIMER
		unsigned long int get_tick_count()
		{
			unsigned long int tick = 0ul;

#if defined(WIN32) || defined(WIN64)
			tick = GetTickCount();
#else
			struct timespec tp;
			clock_gettime(CLOCK_MONOTONIC, &tp);
			tick = (tp.tv_sec * 1000ul) + (tp.tv_nsec / 1000ul / 1000ul);
#endif
			return tick;
		}
		unsigned long long int get_tick_count64()
		{
			unsigned long long int tick = 0ull;

#if defined(WIN32) || defined(WIN64)
			tick = GetTickCount64();
#else
			struct timespec tp;

			clock_gettime(clock_monotonic, &tp);

			tick = (tp.tv_sec * 1000ull) + (tp.tv_nsec / 1000ull / 1000ull);
#endif
			return tick;
		}
#endif

		uint64_t mirTime::GetTickMilliCount()
		{
#ifdef _WINDOWS
			return GetTickCount64();
#else
			// 2023.07.01 gogoblue74  int32_t
			struct timespec tp;
			clock_gettime(CLOCK_MONOTONIC, &tp);
			return (tp.tv_sec * 1000ul) + (tp.tv_nsec / 1000ul / 1000ul);
			/*
			{
				struct timespec now;
				clock_gettime(CLOCK_MONOTONIC, &now);
				return (now.tv_sec * 1000 * 1000 + now.tv_nsec / 1000) / 1000;
			}
			*/
#endif
		}

#ifdef _WINDOWS
		uint64_t mirTime::GetTickMilliFreq()
		{
			InitializeFrequencies();
			LARGE_INTEGER li;
			bool b = ::QueryPerformanceCounter(&li);

			return static_cast<uint64_t>(MillisecondFreq * static_cast<long double>(li.QuadPart));
		}
#endif

		CTimeInterval::CTimeInterval(std::string log_name, bool send_counting)
		{
			_start_time = util::mirTime::NowMSec();
			_log = log_name;
			_send_count = 0;
			_send_counting = send_counting;

			SERVER_LOG(eServerLogType::eInfo, "Start %s, Time : %lld", _log.c_str(), util::mirTime::NowMSec() - _start_time);
		}

		CTimeInterval::~CTimeInterval()
		{
			if (false == _send_counting)
			{
				SERVER_LOG(eServerLogType::eInfo, "End %s, Time : %lld", _log.c_str(), util::mirTime::NowMSec() - _start_time);
			}
			else
			{
				SERVER_LOG(eServerLogType::eInfo, "End %s, Time : %lld, send_count : %lld", _log.c_str(), util::mirTime::NowMSec() - _start_time, _send_count);
			}
		}

		void CTimeInterval::SendCounting()
		{
			_send_count++;
		}
	};

	namespace enum_convert
	{
		mpe_good_pos itemtable_itemtype_to_goodspos(const mir3d::table::ITEM_MAINTYPE& type, const int32_t& key)
		{
			switch (type)
			{
			case mir3d::table::ITEM_MAINTYPE::GOODS:
				{
					table::GOODS_TYPE sub_type = static_cast<table::GOODS_TYPE>(key);

					switch (sub_type)
					{
					case table::GOODS_TYPE::EXP:				{ return mir3d::mpe_good_pos::exp; }	// ok
					case table::GOODS_TYPE::GOLD:				{ return mir3d::mpe_good_pos::gold; }
					case table::GOODS_TYPE::REPUTEPOINT:		{ return mir3d::mpe_good_pos::chao_point; }
					case table::GOODS_TYPE::GOLDINGOT:			{ return mpe_good_pos::goldingot; }
					case table::GOODS_TYPE::CONCENTRATION:		{ return mpe_good_pos::concentration; }
					case table::GOODS_TYPE::CONDITION:			{ return mpe_good_pos::condition; }
					case table::GOODS_TYPE::BLACKIRON:			{ return mpe_good_pos::black_iron; }
					case table::GOODS_TYPE::TREASUREBOXKEY:		{ return mpe_good_pos::treasurebox_key; }
					case table::GOODS_TYPE::GUILDPOINT:			{ return mpe_good_pos::guild_point; }
					case table::GOODS_TYPE::GUILDGOLD:			{ return mpe_good_pos::guid_gold; }
					case table::GOODS_TYPE::BOSS_POINT:			{ return mpe_good_pos::boss_point; }
					case table::GOODS_TYPE::FORCEEXP:			{ return mpe_good_pos::force_exp; }
					case table::GOODS_TYPE::PKPOINT:			{ return mpe_good_pos::pk_point; }
					case table::GOODS_TYPE::MENTORPOINT:		{ return mpe_good_pos::mentor_point; }
					case table::GOODS_TYPE::SEALTOWERCOIN:		{ return mpe_good_pos::seal_tower_coin; }
					case table::GOODS_TYPE::DEMONTOWERCOIN:		{ return mpe_good_pos::demon_tower_coin; }
					case table::GOODS_TYPE::MILEAGE:			{ return mpe_good_pos::mileage; }
					case table::GOODS_TYPE::ANCIENTRELIC_KEY:	{ return mpe_good_pos::ancientrelic_key; }
					case table::GOODS_TYPE::ADCOIN:				{ return mpe_good_pos::ad_coin; }
					case table::GOODS_TYPE::DUNGEONSEAL:		{ return mpe_good_pos::dungeon_seal; }
					case table::GOODS_TYPE::BLOODSTONE:			{ return mpe_good_pos::blood_stone; }
					case table::GOODS_TYPE::NELUMBOSTONE:		{ return mpe_good_pos::nelumbo_stone; }
					case table::GOODS_TYPE::DIMENSIONPIECE:		{ return mpe_good_pos::dimension_piece; }
					case table::GOODS_TYPE::NELUMBOSTONE_POINT: { return mpe_good_pos::nelumbo_stone_point;}
					case table::GOODS_TYPE::MONARCHPOINT:		{ return mpe_good_pos::monarch_point; }
					default:									{ return mpe_good_pos::max; }
					}
				}
			default:											{ return mpe_good_pos::max; }
			}
		}

		mpe_good_pos itemtable_itemtype_to_goodspos(int32_t key)
		{
			table::GOODS_TYPE sub_type = static_cast<table::GOODS_TYPE>(key);

			switch (sub_type)
			{
			case table::GOODS_TYPE::GOLD:				{ return mir3d::mpe_good_pos::gold; }
			case table::GOODS_TYPE::EXP:				{ return mir3d::mpe_good_pos::exp; }
			case table::GOODS_TYPE::GOLDINGOT:			{ return mpe_good_pos::goldingot; }
			case table::GOODS_TYPE::GUILDPOINT:			{ return mpe_good_pos::guild_point; }
			case table::GOODS_TYPE::MENTORPOINT:		{ return mpe_good_pos::mentor_point; }
			case table::GOODS_TYPE::BOSS_POINT:			{ return mpe_good_pos::boss_point; }
			case table::GOODS_TYPE::PKPOINT:			{ return mpe_good_pos::pk_point; }
			case table::GOODS_TYPE::TREASUREBOXKEY:		{ return mpe_good_pos::treasurebox_key; }
			case table::GOODS_TYPE::BLACKIRON:			{ return mpe_good_pos::black_iron; }
			case table::GOODS_TYPE::CONDITION:			{ return mpe_good_pos::condition; }
			case table::GOODS_TYPE::SEALTOWERCOIN:		{ return mpe_good_pos::seal_tower_coin; }
			case table::GOODS_TYPE::DEMONTOWERCOIN:		{ return mpe_good_pos::demon_tower_coin; }
			case table::GOODS_TYPE::MILEAGE:			{ return mpe_good_pos::mileage; }
			case table::GOODS_TYPE::ANCIENTRELIC_KEY:	{ return mpe_good_pos::ancientrelic_key; }
			case table::GOODS_TYPE::ADCOIN:				{ return mpe_good_pos::ad_coin; }
			case table::GOODS_TYPE::DUNGEONSEAL:		{ return mpe_good_pos::dungeon_seal; }
			case table::GOODS_TYPE::BLOODSTONE:			{ return mpe_good_pos::blood_stone; }
			case table::GOODS_TYPE::NELUMBOSTONE:		{ return mpe_good_pos::nelumbo_stone; }
			case table::GOODS_TYPE::DIMENSIONPIECE:		{ return mpe_good_pos::dimension_piece; }
			case table::GOODS_TYPE::NELUMBOSTONE_POINT: { return mpe_good_pos::nelumbo_stone_point;}
			case table::GOODS_TYPE::MONARCHPOINT:		{ return mpe_good_pos::monarch_point; }
			default:									{ return mpe_good_pos::max; }
			}
		}

		table::GOODS_TYPE itemtable_goodspos_to_itemtype(const mir3d::mpe_good_pos& pos)
		{
			switch (pos)
			{
			case mir3d::mpe_good_pos::gold:			{ return table::GOODS_TYPE::GOLD; }
			case mir3d::mpe_good_pos::exp:			{ return table::GOODS_TYPE::EXP; }
			case mpe_good_pos::goldingot:			{ return table::GOODS_TYPE::GOLDINGOT; }
			case mpe_good_pos::guild_point:			{ return table::GOODS_TYPE::GUILDPOINT; }
			case mpe_good_pos::mentor_point:		{ return table::GOODS_TYPE::MENTORPOINT; }
			case mpe_good_pos::boss_point:			{ return table::GOODS_TYPE::BOSS_POINT; }
			case mpe_good_pos::pk_point:			{ return table::GOODS_TYPE::PKPOINT; }
			case mpe_good_pos::treasurebox_key:		{ return table::GOODS_TYPE::TREASUREBOXKEY; }
			case mpe_good_pos::black_iron:			{ return table::GOODS_TYPE::BLACKIRON; }
			case mpe_good_pos::condition:			{ return table::GOODS_TYPE::CONDITION; }
			case mpe_good_pos::seal_tower_coin:		{ return table::GOODS_TYPE::SEALTOWERCOIN; }
			case mpe_good_pos::demon_tower_coin:	{ return table::GOODS_TYPE::DEMONTOWERCOIN; }
			case mpe_good_pos::mileage:				{ return table::GOODS_TYPE::MILEAGE; }
			case mpe_good_pos::ancientrelic_key:	{ return table::GOODS_TYPE::ANCIENTRELIC_KEY; }
			case mpe_good_pos::ad_coin:				{ return table::GOODS_TYPE::ADCOIN; }
			case mpe_good_pos::dungeon_seal:		{ return table::GOODS_TYPE::DUNGEONSEAL; }
			case mpe_good_pos::blood_stone:			{ return table::GOODS_TYPE::BLOODSTONE; }
			case mpe_good_pos::nelumbo_stone:		{ return table::GOODS_TYPE::NELUMBOSTONE; }
			case mpe_good_pos::dimension_piece:		{ return table::GOODS_TYPE::DIMENSIONPIECE; }
			case mpe_good_pos::nelumbo_stone_point: { return table::GOODS_TYPE::NELUMBOSTONE_POINT; }
			case mpe_good_pos::monarch_point:		{ return table::GOODS_TYPE::MONARCHPOINT; }
			default:								{ return table::GOODS_TYPE::MAX; }
			}
		}

		mpe_equip_pos itemtable_equiptype_to_eEquipPos(const int32_t& type)
		{
			switch (static_cast<table::EQUIPMENT_TYPE>(type))
			{
			case table::EQUIPMENT_TYPE::ARMOR:					{ return mpe_equip_pos::armor; }		// 옷
			//case table::EQUIPMENT_TYPE::						{ return mpe_equip_pos::sub_weapon; }	// 보조 무기
			case table::EQUIPMENT_TYPE::WING:					{ return mpe_equip_pos::wing; }			// 망토
			case table::EQUIPMENT_TYPE::WEAPON:					{ return mpe_equip_pos::weapon; }		// 무기
			case table::EQUIPMENT_TYPE::HELMET:					{ return mpe_equip_pos::helmet; }		// 투구
			case table::EQUIPMENT_TYPE::SHOES:					{ return mpe_equip_pos::shoes; }		// 신발
			case table::EQUIPMENT_TYPE::NECKLACE:				{ return mpe_equip_pos::necklace; }		// 목걸이
			case table::EQUIPMENT_TYPE::RINGS:					{ return mpe_equip_pos::ring_r; }		// 반지
			case table::EQUIPMENT_TYPE::BELT:					{ return mpe_equip_pos::belt; }			// 허리띠
			case table::EQUIPMENT_TYPE::BRACELET:				{ return mpe_equip_pos::bracelet_r; }	// 팔찌
			case table::EQUIPMENT_TYPE::COLLECT_MINING_PICKAXE: { return mpe_equip_pos::pickaxe; }		// 곡괭이
			case table::EQUIPMENT_TYPE::COLLECT_FELLING_AXE:	{ return mpe_equip_pos::axe; }			// 도끼
			case table::EQUIPMENT_TYPE::COLLECT_FISHING_ROD:	{ return mpe_equip_pos::rod; }			// 낚시대
			case table::EQUIPMENT_TYPE::BROOCH:					{ return mpe_equip_pos::brooch; }		// 용안석
			case table::EQUIPMENT_TYPE::DRAGONPLATE:			{ return mpe_equip_pos::dragonplate; }	// 용패
			case table::EQUIPMENT_TYPE::EARRING:				{ return mpe_equip_pos::earring; }		// 용루
			default:											{ return mpe_equip_pos::max; }
			}
		}

		mpe_equip_pos itemtable_costumetype_to_eEquipPos(const int32_t& type, const mir3d::table::GENDER_TYPE& gender_type)
		{
			switch (static_cast<table::COSTUME_TYPE>(type))
			{
			case table::COSTUME_TYPE::ARMS_COSTUME:		// 무기
				{
					return table::GENDER_TYPE::MALE == gender_type ? mpe_equip_pos::costume_weapon : mpe_equip_pos::costume_weapon_female;
				}
			case table::COSTUME_TYPE::BODY_COSTUME:		// 몸
				{
					return table::GENDER_TYPE::MALE == gender_type ? mpe_equip_pos::costume_armor : mpe_equip_pos::costume_armor_female;
				}
			case table::COSTUME_TYPE::CAP_COSTUME:		// 투구
				{
					return table::GENDER_TYPE::MALE == gender_type ? mpe_equip_pos::costume_helmet : mpe_equip_pos::costume_helmet_female;
				}
			default:
				{
					return mpe_equip_pos::max;
				}
			}

			return mpe_equip_pos::max;
		}

		mpe_equip_pos dropitem_equiptype_to_eEquipPos(const int32_t& type)
		{
			switch (static_cast<table::EQUIPMENT_TYPE>(type))
			{
			case table::EQUIPMENT_TYPE::ARMOR:					{ return mpe_equip_pos::armor; }		// 옷
			//case table::EQUIPMENT_TYPE:						{ return mpe_equip_pos::sub_weapon; }	// 보조 무기
			case table::EQUIPMENT_TYPE::WING:					{ return mpe_equip_pos::wing; }			// 망토
			case table::EQUIPMENT_TYPE::WEAPON:					{ return mpe_equip_pos::weapon; }		// 무기
			case table::EQUIPMENT_TYPE::HELMET:					{ return mpe_equip_pos::helmet; }		// 투구
			case table::EQUIPMENT_TYPE::SHOES:					{ return mpe_equip_pos::shoes; }		// 신발
			case table::EQUIPMENT_TYPE::NECKLACE:				{ return mpe_equip_pos::necklace; }		// 목걸이
			case table::EQUIPMENT_TYPE::RINGS:					{ return mpe_equip_pos::ring_r; }		// 반지
			case table::EQUIPMENT_TYPE::BELT:					{ return mpe_equip_pos::belt; }			// 허리띠
			case table::EQUIPMENT_TYPE::BRACELET:				{ return mpe_equip_pos::bracelet_r; }	// 팔찌
			// 장착중인 수확장비 아이템은 사망시 드랍에서 제외된다.
			case table::EQUIPMENT_TYPE::COLLECT_MINING_PICKAXE:		// 곡괭이
			case table::EQUIPMENT_TYPE::COLLECT_FELLING_AXE:		// 도끼
			case table::EQUIPMENT_TYPE::COLLECT_FISHING_ROD:		// 낚시대
			default:											{ return mpe_equip_pos::max; }
			}
		}

		table::CLASS_TYPE charactertable_id_to_class_type(const int32_t& id)
		{
			switch (id)
			{
			case 11:
			case 12:	{ return table::CLASS_TYPE::WARRIOR; }
			case 21:
			case 22:	{ return table::CLASS_TYPE::WIZARD; }
			case 31:
			case 32:	{ return table::CLASS_TYPE::TAOIST; }
			default:	{ return table::CLASS_TYPE::NONE; }
			}
		}

		bool is_available_item(table::CHARACTER_TYPE l_cttype, table::CLASS_TYPE l_ctype, table::GENDER_TYPE l_gtype, table::CHARACTER_TYPE r_cttype, table::CLASS_TYPE r_ctype, table::GENDER_TYPE r_gtype)
		{
			if (l_cttype == r_cttype)
			{
				if (table::CLASS_TYPE::ALL == l_ctype)
				{
					return true;
				}
				else if (l_ctype == r_ctype)
				{
					if (table::GENDER_TYPE::ALL == l_gtype)
					{
						return true;
					}
					else if (l_gtype == r_gtype)
					{
						return true;
					}
				}
			}

			return false;
		}

		mpe_good_pos itemtable_goodstype_to_goodspos(const table::GOODS_TYPE& type)
		{
			switch (type)
			{
			case table::GOODS_TYPE::GOLD:				{ return mpe_good_pos::gold; }
			case table::GOODS_TYPE::EXP:				{ return mir3d::mpe_good_pos::exp; }
			case table::GOODS_TYPE::GOLDINGOT:			{ return mpe_good_pos::goldingot; }
			case table::GOODS_TYPE::GUILDPOINT:			{ return mpe_good_pos::guild_point; }
			case table::GOODS_TYPE::CASH:				{ return mpe_good_pos::cash; }
			case table::GOODS_TYPE::BLACKIRON:			{ return mpe_good_pos::black_iron; }
			case table::GOODS_TYPE::MENTORPOINT:		{ return mpe_good_pos::mentor_point; }
			case table::GOODS_TYPE::BOSS_POINT:			{ return mpe_good_pos::boss_point; }
			case table::GOODS_TYPE::PKPOINT:			{ return mpe_good_pos::pk_point; }
			case table::GOODS_TYPE::TREASUREBOXKEY:		{ return mpe_good_pos::treasurebox_key; }
			case table::GOODS_TYPE::CONDITION:			{ return mpe_good_pos::condition; }
			case table::GOODS_TYPE::SEALTOWERCOIN:		{ return mpe_good_pos::seal_tower_coin; }
			case table::GOODS_TYPE::DEMONTOWERCOIN:		{ return mpe_good_pos::demon_tower_coin; }
			case table::GOODS_TYPE::MILEAGE:			{ return mpe_good_pos::mileage; }
			case table::GOODS_TYPE::ANCIENTRELIC_KEY:	{ return mpe_good_pos::ancientrelic_key; }
			case table::GOODS_TYPE::ADCOIN:				{ return mpe_good_pos::ad_coin; }
			case table::GOODS_TYPE::DUNGEONSEAL:		{ return mpe_good_pos::dungeon_seal; }
			case table::GOODS_TYPE::BLOODSTONE:			{ return mpe_good_pos::blood_stone; }
			case table::GOODS_TYPE::NELUMBOSTONE:		{ return mpe_good_pos::nelumbo_stone; }
			case table::GOODS_TYPE::DIMENSIONPIECE:		{ return mpe_good_pos::dimension_piece; }
			case table::GOODS_TYPE::NELUMBOSTONE_POINT: { return mpe_good_pos::nelumbo_stone_point; }
			case table::GOODS_TYPE::MONARCHPOINT:		{ return mpe_good_pos::monarch_point; }
			default:									{ return mpe_good_pos::max; }
			}

			return mpe_good_pos::max;
		}

		mir3d::table::SIEGE_TYPE ConvertFromMpeToTableSiegeType(mpe_siege_castle_type castle_type)
		{
			switch (castle_type)
			{
			case mpe_siege_castle_type::sabuk: { return mir3d::table::SIEGE_TYPE::SABUK; }
			default:
				break;
			}

			return mir3d::table::SIEGE_TYPE::NONE;
		}

		mpe_siege_castle_type ConvertFromTableToMpeSiegeType(const mir3d::table::SIEGE_TYPE& castle_type)
		{
			switch (castle_type)
			{
			case mir3d::table::SIEGE_TYPE::SABUK:
				return mpe_siege_castle_type::sabuk;
			default:
				break;
			}

			return mpe_siege_castle_type::none;
		}

		mir3d::table::TOWN_MENU ConvertFromTownDetailPosToTable(mpe_castle_town_detail_pos house_pos)
		{
			switch (house_pos)
			{
			case mir3d::mpe_castle_town_detail_pos::home:				{ return mir3d::table::TOWN_MENU::TOWN_HOME; }
			case mir3d::mpe_castle_town_detail_pos::dungeon:			{ return mir3d::table::TOWN_MENU::TOWN_DUNGEON; }
			case mir3d::mpe_castle_town_detail_pos::storage:			{ return mir3d::table::TOWN_MENU::TOWN_STORAGE; }
			case mir3d::mpe_castle_town_detail_pos::training_center:	{ return mir3d::table::TOWN_MENU::TRAININGCENTER; }
			case mir3d::mpe_castle_town_detail_pos::quest_office:		{ return mir3d::table::TOWN_MENU::QUEST_OFFICE; }
			case mir3d::mpe_castle_town_detail_pos::blacksmith:			{ return mir3d::table::TOWN_MENU::TOWN_BLACKSMITH; }
			case mir3d::mpe_castle_town_detail_pos::alchemy:			{ return mir3d::table::TOWN_MENU::TOWN_ALCHEMY; }
			case mir3d::mpe_castle_town_detail_pos::cooking:			{ return mir3d::table::TOWN_MENU::TOWN_COOKING; }
			case mir3d::mpe_castle_town_detail_pos::arsenal:			{ return mir3d::table::TOWN_MENU::TOWN_ARSENAL; }
			case mir3d::mpe_castle_town_detail_pos::orchard:			{ return mir3d::table::TOWN_MENU::TOWN_ORCHARD; }
			case mir3d::mpe_castle_town_detail_pos::grove:				{ return mir3d::table::TOWN_MENU::TOWN_GROVE; }
			case mir3d::mpe_castle_town_detail_pos::farm:				{ return mir3d::table::TOWN_MENU::TOWN_FARM; }
			case mir3d::mpe_castle_town_detail_pos::dinner:				{ return mir3d::table::TOWN_MENU::TOWN_DINNER; }
			default:													{ return mir3d::table::TOWN_MENU::NONE; }
			}
		}

		bool ConvertFromTableToTownDetailPos(const mir3d::table::TOWN_MENU town_menu, mpe_castle_town_detail_pos& val)
		{
			switch (town_menu)
			{
			case mir3d::table::TOWN_MENU::TOWN_HOME:			{ val = mpe_castle_town_detail_pos::home; }				break;
			case mir3d::table::TOWN_MENU::TOWN_DUNGEON:			{ val = mpe_castle_town_detail_pos::dungeon; }			break;
			case mir3d::table::TOWN_MENU::TOWN_STORAGE:			{ val = mpe_castle_town_detail_pos::storage; }			break;
			case mir3d::table::TOWN_MENU::TRAININGCENTER:		{ val = mpe_castle_town_detail_pos::training_center; }	break;
			case mir3d::table::TOWN_MENU::QUEST_OFFICE:			{ val = mpe_castle_town_detail_pos::quest_office; }		break;
			case mir3d::table::TOWN_MENU::TOWN_BLACKSMITH:		{ val = mpe_castle_town_detail_pos::blacksmith; }		break;
			case mir3d::table::TOWN_MENU::TOWN_ALCHEMY:			{ val = mpe_castle_town_detail_pos::blacksmith; }		break;
			case mir3d::table::TOWN_MENU::TOWN_COOKING:			{ val = mpe_castle_town_detail_pos::cooking; }			break;
			case mir3d::table::TOWN_MENU::TOWN_ARSENAL:			{ val = mpe_castle_town_detail_pos::arsenal; }			break;
			case mir3d::table::TOWN_MENU::TOWN_ORCHARD:			{ val = mpe_castle_town_detail_pos::orchard; }			break;
			case mir3d::table::TOWN_MENU::TOWN_GROVE:			{ val = mpe_castle_town_detail_pos::grove; }			break;
			case mir3d::table::TOWN_MENU::TOWN_FARM:			{ val = mpe_castle_town_detail_pos::farm; }				break;
			default: { return false; }
			}

			return true;
		}

		bool compare_equiptype_to_stonetype(int32_t equip_type, int32_t stone_type)
		{
			auto equip_stone = static_cast<table::EQUIPSTONE_TYPE>(stone_type);

			switch (static_cast<table::EQUIPMENT_TYPE>(equip_type))
			{
			case table::EQUIPMENT_TYPE::WEAPON:		// 무기
				{
					if (table::EQUIPSTONE_TYPE::WEAPONSTONE == equip_stone)
						return true;
					return false;
				}

			case table::EQUIPMENT_TYPE::WING:		// 망토
			case table::EQUIPMENT_TYPE::ARMOR:		// 옷
			case table::EQUIPMENT_TYPE::HELMET:		// 투구
			case table::EQUIPMENT_TYPE::SHOES:		// 신발
			case table::EQUIPMENT_TYPE::BELT:		// 허리띠
				{
					if (table::EQUIPSTONE_TYPE::ARMORSTONE == equip_stone)
						return true;
					return false;
				}

			case table::EQUIPMENT_TYPE::NECKLACE:	// 목걸이
			case table::EQUIPMENT_TYPE::RINGS:		// 반지
			case table::EQUIPMENT_TYPE::BRACELET:	// 팔찌
				{
					if (table::EQUIPSTONE_TYPE::ACCESSORYSTONE == equip_stone)
						return true;
					return false;
				}

			default:
				return false;
			}

			return false;
		}

		mrpce_log_item_update_type ConvertFromTableToLogUpdateType(const mir3d::table::DUNGEON_TYPE& dungeon_type)
		{
			switch (dungeon_type)
			{
			case table::DUNGEON_TYPE::BOSSDUNGEON:		{ return mrpce_log_item_update_type::party_dungeon_enter; }
			case table::DUNGEON_TYPE::ILLUSIONDUNGEON:	{ return mrpce_log_item_update_type::indun_illusion; }
			case table::DUNGEON_TYPE::MONARCHDUNGEON:	{ return mrpce_log_item_update_type::monarch_enter; }
			case table::DUNGEON_TYPE::SIEGE:			{ return mrpce_log_item_update_type::siegewar_enter; }
			case table::DUNGEON_TYPE::STORYDUNGEON:		{ return mrpce_log_item_update_type::indun_story; }
			case table::DUNGEON_TYPE::GUILDOFFICE:		{ return mrpce_log_item_update_type::castletown_enter; }
			case table::DUNGEON_TYPE::GUILDDUNGEON:		{ return mrpce_log_item_update_type::guild_dungeon_enter; }
			case table::DUNGEON_TYPE::CASTLEDUNGEON:	{ return mrpce_log_item_update_type::castle_dungeon_enter; }
			case table::DUNGEON_TYPE::GUILDSHIPWAR:		{ return mrpce_log_item_update_type::shipwar_enter; }
			case table::DUNGEON_TYPE::NONE:
			default:									{ return mrpce_log_item_update_type::character_use; }
			}
		}

		bool IsCollectEquipment(const table::ITEM_MAINTYPE& main_type, const int32_t& sub_type)
		{
			if (table::ITEM_MAINTYPE::EQUIPMENT != main_type)
				return false;

			auto item_sub_type = static_cast<table::EQUIPMENT_TYPE>(sub_type);

			if (table::EQUIPMENT_TYPE::COLLECT_FELLING_AXE == item_sub_type ||
				table::EQUIPMENT_TYPE::COLLECT_FISHING_ROD == item_sub_type ||
				table::EQUIPMENT_TYPE::COLLECT_MINING_PICKAXE == item_sub_type)
			{
				return true;
			}

			return false;
		}

		table::MAIL_TYPE ConvertEnumFromPacketToTable(const mpe_mail_type& mail_type)
		{
			switch (mail_type)
			{
			case mir3d::mpe_mail_type::mail_type_account:	{ return table::MAIL_TYPE::ACCOUNT; }
			case mir3d::mpe_mail_type::mail_type_character: { return table::MAIL_TYPE::CHARACTER; }
			case mir3d::mpe_mail_type::mail_type_server:	{ return table::MAIL_TYPE::SERVER; }
			default:										{ return table::MAIL_TYPE::EndEnum; }
			}
		}

		mpe_mail_type ConvertEnumFromTableToPacket(const table::MAIL_TYPE& mail_type)
		{
			switch (mail_type)
			{
			case table::MAIL_TYPE::ACCOUNT:		{ return mir3d::mpe_mail_type::mail_type_account; }
			case table::MAIL_TYPE::CHARACTER:	{ return mir3d::mpe_mail_type::mail_type_character; }
			case table::MAIL_TYPE::SERVER:		{ return mir3d::mpe_mail_type::mail_type_server; }
			default:							{ return mir3d::mpe_mail_type::mail_type_character; }
			}
		}

		mrpce_game_event ConvertEnumFromPacketToTable(const table::OPENDUNGEON_CONTENT_TYPE& content_type)
		{
			switch (content_type)
			{
			case table::OPENDUNGEON_CONTENT_TYPE::CASTLEDUNGEON:	{ return mrpce_game_event::castle_dungeon_reset_time; }
			case table::OPENDUNGEON_CONTENT_TYPE::PHANTOMDUNGEON:	{ return mrpce_game_event::phantom_dungeon_reset_time; }
			case table::OPENDUNGEON_CONTENT_TYPE::SEALTOWER:
			case table::OPENDUNGEON_CONTENT_TYPE::EVENT_DUNGEON:	{ return mrpce_game_event::seal_tower_reset_time; }
			case table::OPENDUNGEON_CONTENT_TYPE::DEMONTOWER:		{ return mrpce_game_event::demon_tower_reset_time; }
			case table::OPENDUNGEON_CONTENT_TYPE::UNKNOWNDUNGEON:	{ return mrpce_game_event::unknown_dungeon_reset_time; }
			case table::OPENDUNGEON_CONTENT_TYPE::DIMENSIONDUNGEON: { return mrpce_game_event::dimension_dungeon_reset_time; }
			default:												{ return mrpce_game_event::none; }
			}
		}

		mpe_ranking_type ConvertToMpeRankingType(const table::RANKING_TYPE& type)
		{
			switch (type)
			{
			case table::RANKING_TYPE::PERSONAL_LV:		{ return mpe_ranking_type::personal_level_total; }
			case table::RANKING_TYPE::PERSONAL_POWER:	{ return mpe_ranking_type::personal_power_total; }
			case table::RANKING_TYPE::GUILD:			{ return mpe_ranking_type::guild_all; }
			default:									{ return mpe_ranking_type::none; }
			}
		}

		mpe_ranking_type ConvertToMpeRankingType(const table::PROFESIONTYPE& type)
		{
			switch (type)
			{
			case table::PROFESIONTYPE::MINING:		{ return mpe_ranking_type::mining; }
			case table::PROFESIONTYPE::GATHER:		{ return mpe_ranking_type::gather; }
			case table::PROFESIONTYPE::FISHING:		{ return mpe_ranking_type::fishing; }
			case table::PROFESIONTYPE::BLACKSMITH:	{ return mpe_ranking_type::blacksmith; }
			case table::PROFESIONTYPE::ALCHEMY:		{ return mpe_ranking_type::alchemy; }
			case table::PROFESIONTYPE::HANDWORK:	{ return mpe_ranking_type::handwork; }
			case table::PROFESIONTYPE::REINFORCE:	{ return mpe_ranking_type::reinforce; }
			case table::PROFESIONTYPE::ENCHANT:		{ return mpe_ranking_type::enchant; }
			case table::PROFESIONTYPE::LUCK:		{ return mpe_ranking_type::luck; }
			default:								{ return mpe_ranking_type::none; }
			}
		}

		int32_t ConvertToIllustionType(const table::OPENDUNGEON_CONTENT_TYPE& dungeon_type)
		{
			//IllusionType - 환상비경 타입(1 : 봉인의 탑, 2 : 몽환비경, 3 : 사령의 탑, 4 : 미지의 비경, 5 : 성주비경, 6 : 차원 비경.)
			switch (dungeon_type)
			{
			case table::OPENDUNGEON_CONTENT_TYPE::SEALTOWER:		{ return 1; }
			case table::OPENDUNGEON_CONTENT_TYPE::DEMONTOWER:		{ return 3; }
			case table::OPENDUNGEON_CONTENT_TYPE::CASTLEDUNGEON:	{ return 5; }
			case table::OPENDUNGEON_CONTENT_TYPE::PHANTOMDUNGEON:	{ return 2; }
			case table::OPENDUNGEON_CONTENT_TYPE::DIMENSIONDUNGEON: { return 6; }
			case table::OPENDUNGEON_CONTENT_TYPE::UNKNOWNDUNGEON:	{ return 4; }
			case table::OPENDUNGEON_CONTENT_TYPE::SECRETVALLEY:
			case table::OPENDUNGEON_CONTENT_TYPE::NONE:
			case table::OPENDUNGEON_CONTENT_TYPE::EndEnum:
			default:												{ return 0; }
			}
		}
	};
}; // namespace mir3d
