#pragma once

#include <chrono>
#include <protocol/base_protocol.h>
#include <protocol/rpc_protocol.h>

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-function"
#endif

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;


namespace mir3d
{
	const int64_t	MAX_INT64 = 0x7FFFFFFFFFFFFFFF;

	namespace util 
	{		
		const extern int32_t DAY_IN_SEC;
		const extern int32_t EVENT_LOGIN_TIME_MAX_SEC;
		
		class CUidGenerate final : public CSingleton<CUidGenerate>
		{
		public:
			CUidGenerate() ;
			virtual ~CUidGenerate();

		public:
			/*
			enum class eUid : int64_t
			{
				BASE_TIME = 1514732400,			// 기준 시간 "2018-01-01 00:00:00"
				player = 1,
				character = 2,
				guild = 3, 
				indun = 4, 
				zone = 5, 
				object = 6,
				item = 7,
				//exchange = 8,
				skill = 9,
				mail = 10,
				trade = 11,
				pkrecord = 12,
				reflection = 13,
				//gm = 14,
				//guild_storage_request = 15,
				//guild_storage_auction = 16,
				party = 17,
				//room = 18,
				//guild_shipwar = 19,
				//wanted_murder_reward = 20,
				//rpc_request_response = 21,	
				pet = 22,
				//guild_storage_history = 23,
				//world_exchange = 24,
				global_exchange = 25,
				max = 26
			};
			*/
			enum class eUid : int64_t
			{
				BASE_TIME = 1514732400,			// 기준 시간 "2018-01-01 00:00:00"
				player = 1,
				character = 2,
				guild = 3,
				indun = 4,
				zone = 5,
				object = 6,
				item = 7,
				skill = 8,
				mail = 9,
				trade = 10,
				pkrecord = 11,
				reflection = 12,
				party = 13,
				pet = 14,
				global_exchange = 15,
				buff_chain_key = 16,
				max = 17
			};
		public:
			bool Initialize(int32_t server_gid, int32_t server_index);
			uint64_t Get(eUid type);
			uint64_t GetSessionId();
			void Destroy(void);

		private:
			std::vector<std::atomic<uint64_t>*> _list_uid;
			std::atomic<uint64_t>* _session_uid;
			std::string _base_key;
			std::vector<std::atomic<uint64_t>*> _list_compare_uid;
			std::mutex _lock;

		private:
			CUidGenerate(const CUidGenerate&) = delete;
			CUidGenerate& operator=(const CUidGenerate&) = delete;
			CUidGenerate(CUidGenerate&&) = delete;
			CUidGenerate& operator=(CUidGenerate&&) = delete;
		};
		#define uidGenerate CUidGenerate::getInstance()

		class randomGenerator
		{
		public:
			static int64_t GetUid(void);
		};

		/*
		static thread_local bool random_initialize = false;
		class CMirRandom final : public CSingleton<CMirRandom>
		{
		public:
			
			CMirRandom() = default;
			virtual ~CMirRandom()
			{
				Destroy();
			}

		public:
			bool Initialize(uint32_t seed)
			{
				srand(seed);
				return true;
			}

			inline int32_t Get(int32_t min, int32_t max)
			{
				if (false == random_initialize)
				{
					Initialize(static_cast<uint32_t>(std::time(nullptr)));
					random_initialize = true;
				}

				if (min > max)
					return max;

//				int32_t r;
//#ifdef _WINDOWS
//				r = rand() << 15 | rand();
//#else
//				r = rand();
//#endif
//				return (r % ((max + 1) - min)) + min;
				
				return (int32_t)((((double)rand() / ((double)RAND_MAX + 1.f)) * ((max + 1) - min)) + min);
			}

			inline int32_t GetComparison(int32_t min, int32_t max)
			{
				if (min > max)
					std::swap(min, max);

				return (int32_t)((((double)rand() / ((double)RAND_MAX + 1.f)) * ((max + 1) - min)) + min);
			}

			inline float Get(float min, float max)
			{
				if (min > max)
					return max;

				return (float)((((float)rand() / ((float)RAND_MAX + 1.f)) * (max - min)) + min);
			}

			inline int32_t Rand()
			{
				return rand();
			}

		public:
			void Destroy(void) {}

		private:
			CMirRandom(const CMirRandom&) = delete;
			CMirRandom& operator=(const CMirRandom&) = delete;
			CMirRandom(CMirRandom&&) = delete;
			CMirRandom& operator=(CMirRandom&&) = delete;
		};
		#define mirRandomOld CMirRandom::getInstance()
		*/

		class CMirNewRandom final : public CSingleton<CMirNewRandom>
		{
		public:
			CMirNewRandom() = default;
			virtual ~CMirNewRandom()
			{
				Destroy();
			}

		public:
			template<class T> using uniform_distribution =
				typename std::conditional<std::is_floating_point<T>::value,
				std::uniform_real_distribution<T>,
				typename std::conditional<std::is_integral<T>::value,
				std::uniform_int_distribution<T>,
				void>::type>::type;

			template<typename T> T RNG(T min, T max)
			{
				if (min > max) return max;

				thread_local std::mt19937_64 _random_mt(std::random_device{} ());
				uniform_distribution<T> dist(min, max);
				return dist(_random_mt);
			}

			inline float Get(float min, float max)
			{
				if (min > max)
					return max;

				return RNG<float>(min, max);
			}

			inline int32_t Get(int32_t min, int32_t max)
			{
				if (min > max)
					return max;

				return RNG<int>(min, max);
			}

			inline int32_t Rand()
			{
				return RNG<int>(0, INT_MAX);
			}

			inline int64_t Rand64()
			{
				return RNG<int64_t>(0, LLONG_MAX);
			}

			inline int32_t GetComparison(int32_t min, int32_t max)
			{
				if (min > max)
					std::swap(min, max);

				return RNG<int>(min, max);
			}

			inline int32_t GetRandomIndex(size_t size)
			{
				if (size > static_cast<size_t>(std::numeric_limits<int32_t>::max())) {
					// 처리할 수 없는 크기의 배열입니다.
					// 예외 처리 또는 에러 처리를 추가하세요.
					return -1;  // 에러를 나타내는 값을 반환하거나 예외를 던질 수 있습니다.
				}

				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> distr(0, static_cast<int32_t>(size) - 1);

				return distr(gen);
			}

			inline int32_t GetRandomIndex(int32_t total_ratio, std::vector<int32_t> ratios)
			{
				int32_t idx = 0;

				int32_t randomValue = std::rand() % total_ratio;
				int32_t cumulativeRatio = 0;

				for (int32_t i = 0; i < static_cast<int32_t>(ratios.size()); ++i)
				{
					cumulativeRatio += ratios[i];
					if (randomValue < cumulativeRatio) {

						idx = i;
						break;
					}
				}

				return idx;
			}

			inline bool isSuccess(int32_t prob)
			{
				return RNG<int32_t>(1, 10000) <= prob;
			}

		public:
			void Destroy(void) {}

		private:
			CMirNewRandom(const CMirNewRandom&) = delete;
			CMirNewRandom& operator=(const CMirNewRandom&) = delete;
			CMirNewRandom(CMirNewRandom&&) = delete;
			CMirNewRandom& operator=(CMirNewRandom&&) = delete;
		};
		#define mirRandom CMirNewRandom::getInstance()

		class mirTime
		{
		public:
			enum class eDayOfWeek : int32_t
			{
				sunday = 0,
				monday = 1,
				tuesday = 2,
				wednesday = 3,
				thursday = 4,
				friday = 5,
				saturday = 6,
				count = 7
			};

			enum etimeZone : int32_t
			{
				utc_0 = 0,
				utc_8 = 8,
				utc_9 = 9,
			};

		public:
			static bool Initialize(int32_t time_zone = utc_9)
			{
				std::time_t now = std::time(nullptr);

#ifdef _WINDOWS
				struct tm date;

				if (0 != localtime_s(&date, &now))
					return false;
				
				std::time_t gmt = _mkgmtime(&date);

				// 한국 테스트 _time_zone :  -32400
				_time_zone = static_cast<int64_t>(now - gmt);

				// dhlee : config_time_zone 적용
				// 해당 장비가 타임존 설정이 UTC+0 이외 값으로 설정 되어 있다면
				// 기존과 같이 _time_zone 을 아니라면 _config_time_zone 을 사용
				if (_time_zone == 0)
				{
					if (time_zone < -12 || time_zone > 14)
						_time_zone_value = 0;
					else
						_time_zone_value = time_zone;

					_config_time_zone = static_cast<int64_t>(_time_zone_value * 60 * 60);

#ifdef _USE_GLOBAL_SERVICE
					// global time zone에 경우 UTC 8 
					_global_time_zone = static_cast<int64_t>(8 * 60 * 60);
#else
					_global_time_zone = static_cast<int64_t>(9 * 60 * 60);
#endif
				}
				else
				{
					// 현재 시간을 기준으로 UCT-0 의 타임스탬프를 현재 로컬의 타임스탬프에서 빼기
					// 때문에 +9 에서는 _time_zone 값은 -32400 이 나온다. 즉 계산 기준이 현재에서
					// 9시간을 빼야 UTC-0 라는 의미로 그런 것 같은데....내가 작업 한 것은 아니니...
					// 그래서 _time_zone 변수에서 타임존 값을 구하기 위해 -1을 곱한다.
					_time_zone_value = static_cast<int32_t>((_time_zone * -1) / (60 * 60));
					_config_time_zone = 0;
				}

				InitializeFrequencies();
#else
				std::time_t gmt = std::mktime(std::gmtime(&now));
				_time_zone = static_cast<int64_t>(gmt - now);
#endif

				return true;
			}

			static int32_t GetGlobalTimeZone()
			{
				return _global_time_zone;
			}

			static int32_t GetTimeZone()
			{
				return _time_zone_value;
			}

			static float GetDaltaTime(int64_t curr_time, int64_t prev_time)
			{
				return (float)(curr_time - prev_time) / 1000.f;
			}

			static int64_t NowUTC()
			{
				struct timespec now;
				timespec_get(&now, TIME_UTC);
				return (now.tv_sec * 1000 * 1000 + now.tv_nsec / 1000) / 1000;
			}

			static int64_t LocalTime()
			{
				std::time_t t = std::time(nullptr);

				if (_config_time_zone)
					t += _config_time_zone;

				return static_cast<int64_t>(t - _time_zone);
			}

			static int64_t GlobalTime()
			{
				std::time_t t = std::time(nullptr);
				t += _global_time_zone;
				return static_cast<int64_t>(t);
			}
			static int32_t GlobalTime32()
			{
				std::time_t t = std::time(nullptr);
				t += _global_time_zone;
				return static_cast<int32_t>(t);
			}

			// 결과는 NowSec() 와 같다 단지 LocalTime 과 대비되는 용도로 사용한다는 의미를 
			// 명확히 하기 위해 함수를 추가한다.
			// 위에 NowUTC 는 나노 sec 단위라 범용적으로 사용하기는 힘들고 NowSec() 는 NowLocalSec() 가
			// 있어서 혼돈의 여지가 있어 보인다.
			static int64_t UtcTime()
			{
				std::time_t t = std::time(nullptr);

				return static_cast<int64_t>(t - _time_zone);
			}

			// source_time 이 만들어진(mktime 등으로) 타임스탬프가 아닌, 
			// 현재 시간에 대한 타임스탬프여야 한다.
			static void ConvertToLocalTime(int64_t& source_time)
			{
				if (_config_time_zone)
					source_time += _config_time_zone;

				source_time -= _time_zone;
			}

			// source_time 이 만들어진(mktime 등으로) 타임스탬프가 아닌, 
			// 현재 시간에 대한 타임스탬프여야 한다.
			static void ConvertToLocalTime(int32_t& source_time)
			{
				if (_config_time_zone)
					source_time += static_cast<int32_t>(_config_time_zone);

				source_time -= static_cast<int32_t>(_time_zone);
			}

			static void ConvertToGlobalTime(int32_t& source_time)
			{
				source_time += static_cast<int32_t>(_global_time_zone);
			}

			// source_time 이 만들어진(mktime 등으로) 타임스탬프여야 한다.
			static void ConvertUtcToLocalTime(int32_t& source_time)
			{
				if (_config_time_zone)
					source_time += static_cast<int32_t>(_config_time_zone);;

				source_time += static_cast<int32_t>(_time_zone);
			}

			static int32_t YearMonthDay()
			{
#ifdef _WINDOWS
				std::time_t t = std::time(nullptr);
				if (_config_time_zone)
					t += _config_time_zone;

				struct tm date;

				if (0 != localtime_s(&date, &t))
					return false;

				return (date.tm_year + 1900) * 10000 + (date.tm_mon + 1) * 100 + date.tm_mday;
#else
				std::time_t t = std::time(nullptr);
				struct tm* date = std::localtime(&t);

				return (date->tm_year + 1900) * 10000 + (date->tm_mon + 1) * 100 + date->tm_mday;
#endif
			}

			static int64_t Now()
			{
				struct timespec now;
#ifdef _WINDOWS			
				timespec_get(&now, TIME_UTC); 
#else
				clock_gettime(CLOCK_MONOTONIC, &now);
#endif
				return now.tv_sec * 1000 * 1000 + now.tv_nsec / 1000;
			}

			static int64_t NowUtcMSec()
			{
				using namespace std::chrono;
				return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
			}

			static int32_t NowSec() noexcept
			{
				struct timespec now;
#ifdef _WINDOWS			
				timespec_get(&now, TIME_UTC); 
#else
				clock_gettime(CLOCK_MONOTONIC, &now);
#endif
				return static_cast<int32_t>(now.tv_sec);
			}

			static int32_t NowLocalSec() noexcept
			{
				struct timespec now;
#ifdef _WINDOWS			
				timespec_get(&now, TIME_UTC);

				if (_config_time_zone)
					now.tv_sec += _config_time_zone;
#else
				clock_gettime(CLOCK_MONOTONIC, &now);
#endif
				return static_cast<int32_t>(now.tv_sec - static_cast<int32_t>(_time_zone));
			}

			static int64_t NowLocalMSec() noexcept
			{
				struct timespec now;
#ifdef _WINDOWS			
				timespec_get(&now, TIME_UTC);
				if (_config_time_zone)
					now.tv_sec += _config_time_zone;
#else
				clock_gettime(CLOCK_MONOTONIC, &now);
#endif
				return static_cast<int64_t>((now.tv_sec - static_cast<int32_t>(_time_zone)) * 1000) + (now.tv_nsec / 1000000);
			}

			static int64_t ActionLogTime() noexcept
			{
				struct timespec now;
				timespec_get(&now, TIME_UTC);
				return static_cast<int64_t>((now.tv_sec - static_cast<int32_t>(_time_zone)) * 1000) + (now.tv_nsec / 1000000);
			}

			static bool sInitializeFrequencies();
			
			static void InitializeFrequencies();


			static uint64_t NowMSec();
#ifdef _WINDOWS
			static uint64_t GetTickMilliFreq();
#endif
			static uint64_t GetTickMilliCount();

			// return : utc
			// 매개변수가 해당 지역의 타임존에 맞게 설정된 값이어야 한다.
			static int64_t MakeDailyResetTime(int32_t hour, int32_t min, int32_t sec)
			{
#ifdef _WINDOWS	
				std::time_t t = std::time(nullptr);
				if (_config_time_zone)
					t += _config_time_zone;

				std::tm date;

				if (0 != localtime_s(&date, &t))
					return false;

				date.tm_hour = hour;
				date.tm_min = min;
				date.tm_sec = sec;
				time_t reset_t = std::mktime(&date);
#else
				std::time_t t = std::time(nullptr);
				struct tm date = *std::localtime(&t);

				date.tm_hour = hour;
				date.tm_min = min;
				date.tm_sec = sec;
				time_t reset_t = std::mktime(&date);
#endif
				int64_t ret = (t < reset_t) ? static_cast<int64_t>(reset_t) : static_cast<int64_t>(reset_t + (1 * 24 * 60 * 60));
				return ret;
			}

			// 매개변수가 해당 지역의 타임존에 맞게 설정된 값이어야 한다.
			static int32_t MakeDailyResetTime32(int32_t hour, int32_t min, int32_t sec)
			{
#ifdef _WINDOWS	
				std::time_t t = std::time(nullptr);

				if (_config_time_zone)
					t += _config_time_zone;

				std::tm date;

				if (0 != localtime_s(&date, &t))
					return false;

				date.tm_hour = hour;
				date.tm_min = min;
				date.tm_sec = sec;
				time_t reset_t = std::mktime(&date);
#else
				std::time_t t = std::time(nullptr);
				struct tm date = *std::localtime(&t);

				date.tm_hour = hour;
				date.tm_min = min;
				date.tm_sec = sec;
				time_t reset_t = std::mktime(&date);
#endif
				return (t < reset_t) ? static_cast<int32_t>(reset_t) : static_cast<int32_t>(reset_t + (1 * 24 * 60 * 60));
			}

			// return : utc
			// 매개변수가 해당 지역의 타임존에 맞게 설정된 값이어야 한다.
			static int64_t TodayResetTime(int32_t hour, int32_t min, int32_t sec)
			{
#ifdef _WINDOWS	
				std::time_t t = std::time(nullptr);

				if (_config_time_zone)
					t += _config_time_zone;

				std::tm date;

				if (0 != localtime_s(&date, &t))
					return false;

				date.tm_hour = hour;
				date.tm_min = min;
				date.tm_sec = sec;
				time_t reset_t = std::mktime(&date);
#else
				std::time_t t = std::time(nullptr);
				struct tm date = *std::localtime(&t);

				date.tm_hour = hour;
				date.tm_min = min;
				date.tm_sec = sec;
				time_t reset_t = std::mktime(&date);
#endif
				return static_cast<int64_t>(reset_t);
			}

			// 매개변수가 해당 지역의 타임존에 맞게 설정된 값이어야 한다.
			static int64_t GetTimeOfLastWeekDay(const eDayOfWeek day_of_week)
			{
				std::time_t t = std::time(nullptr);

				if (_config_time_zone)
					t += _config_time_zone;

#ifdef _WINDOWS	
				std::tm date;

				if (0 != localtime_s(&date, &t))
					return false;
#else
				struct tm date = *std::localtime(&t);
#endif
				int32_t interval_of_days = date.tm_wday - static_cast<int32_t>(day_of_week);

				if (interval_of_days < 0)
				{
					interval_of_days += static_cast<int32_t>(eDayOfWeek::count);
				}

				date.tm_hour = 0;
				date.tm_min = 0;
				date.tm_sec = 0;
				
				time_t today_midnight = std::mktime(&date);

				// const int32_t day_in_sec = 24 * 60 * 60;
				
				return today_midnight - (interval_of_days * DAY_IN_SEC);
			}

			static int64_t GetTimeOfNextWeekDay(const eDayOfWeek day_of_week, bool is_local = false)
			{
				std::time_t t = std::time(nullptr);

				if(true == is_local && _config_time_zone)
					t += _config_time_zone;

#ifdef _WINDOWS	
				std::tm date;

				if (0 != localtime_s(&date, &t))
					return false;
#else
				struct tm date = *std::localtime(&t);
#endif
				int32_t interval_of_days = date.tm_wday - static_cast<int32_t>(day_of_week);

				if (interval_of_days < 0)
				{
					interval_of_days += static_cast<int32_t>(eDayOfWeek::count);
				}

				date.tm_hour = 0;
				date.tm_min = 0;
				date.tm_sec = 0;

				time_t today_midnight = std::mktime(&date);

				return (today_midnight - (interval_of_days * DAY_IN_SEC)) + (7 * DAY_IN_SEC);
			}


			// 매개변수가 해당 지역의 타임존에 맞게 설정된 값이어야 한다.
			static int64_t GetTimeOfLastDayOfMonth(const int32_t day)
			{
				std::time_t t = std::time(nullptr);

				if (_config_time_zone)
					t += _config_time_zone;

#ifdef _WINDOWS	
				std::tm date;

				if (0 != localtime_s(&date, &t))
					return false;
#else
				struct tm date = *std::localtime(&t);
#endif
				if (date.tm_mday < day)
				{
					if (date.tm_mon > 0)
					{
						--date.tm_mon;
					}
					else
					{
						--date.tm_year;
						date.tm_mon = 11;
					}
				}

				date.tm_mday = day;
				date.tm_hour = 0;
				date.tm_min = 0;
				date.tm_sec = 0;

				return std::mktime(&date);
			}

			// 해당 지역의 타임존에 맞게 보정된 시간으로 표시한다.
			static std::string GetDateTimeToString()
			{
				std::time_t t = std::time(nullptr);

				if (_config_time_zone)
					t += _config_time_zone;

#ifdef _WINDOWS	
				std::tm date;

				if (0 != localtime_s(&date, &t))
					return "";
#else
				struct tm date = *std::localtime(&t);
#endif
						
				char szTemp[64] = { 0 };
				
				snprintf(szTemp, sizeof(szTemp), "%4d-%2d-%2d %2d:%2d:%2d", (date.tm_year + 1900), (date.tm_mon + 1), date.tm_mday, date.tm_hour, date.tm_min, date.tm_sec);
				return szTemp;
			}

			// 해당 지역의 타임존에 맞게 보정된 시간으로 표시한다.
			static std::string GetDateTimeToStringForActionLog()
			{
				std::time_t t = std::time(nullptr);

				if (_config_time_zone)
					t += _config_time_zone;

#ifdef _WINDOWS	
				std::tm date;

				if (0 != localtime_s(&date, &t))
					return "";
#else
				struct tm date = *std::localtime(&t);
#endif

				char szTemp[64] = { 0 };

				snprintf(szTemp, sizeof(szTemp), "%04d-%02d-%02d,%02d:%02d:%02d", (date.tm_year + 1900), (date.tm_mon + 1), date.tm_mday, date.tm_hour, date.tm_min, date.tm_sec);
				return szTemp;
			}

			// 매개변수가 해당 지역의 타임존에 맞게 설정된 값이어야 한다.
			static const int64_t GetLastDailyResetTime(const int32_t hour, const int32_t minute, const int32_t second)
			{
				return MakeDailyResetTime(hour, minute, second) - DAY_IN_SEC;
			}

			// 매개변수가 해당 지역의 타임존에 맞게 설정된 값이어야 한다.
			static const int32_t GetLastDailyResetTime32(const int32_t hour, const int32_t minute, const int32_t second)
			{				
				return MakeDailyResetTime32(hour, minute, second) - DAY_IN_SEC;
			}

			// Converts the given Monotonic clock value into timespec.
			static void ToTimespec(const int64_t& value, struct timespec* ret)
			{
				ret->tv_sec = value / (1000 * 1000);
				ret->tv_nsec = value % (1000 * 1000) * 1000;
			}

			// Converts sec value into Duration.
			static int64_t ConvertToSec(int64_t sec)
			{
				return sec * 1000 * 1000;
			}

			// Converts msec value into Duration.
			static int64_t ConvertToMsec(int64_t msec)
			{
				return msec * 1000;
			}

			// Converts usec value into Duration.
			static int64_t ConvertToUsec(int64_t usec)
			{
				return usec;
			}

			// 동일 요일검사
			static eDayOfWeek GetDayOfWeek(bool is_local = false)
			{
				std::time_t t = std::time(nullptr);

				if (true == is_local)
				{
					ConvertToLocalTime(t);
				}
#ifdef _WINDOWS	
				std::tm date;
				if (0 != localtime_s(&date, &t))
					return eDayOfWeek::count;

#else
				struct tm date = *std::localtime(&t);
#endif

				return static_cast<eDayOfWeek>(date.tm_wday);
			}

			//CompareSameDay는 다른곳에서 사용해서 Global은 따로 나눔
			// time 값이 sec 단위여야 함
			// time 이 만들어진(mktime 등으로) 타임스탬프가 아닌, 
			// 현재 시간에 대한 타임스탬프여야 한다.
			static bool CompareSameDayToGlobal(int64_t time)
			{
				std::time_t t = std::time(nullptr);

				t += _global_time_zone;

#ifdef _WINDOWS	
				std::tm date;
				if (0 != localtime_s(&date, &t))
					return false;

				std::tm compare_tm;
				if (0 != localtime_s(&compare_tm, &time))
					return false;
#else
				struct tm date = *std::localtime(&t);
				struct tm compare_tm = *std::localtime(&time);
#endif

				return (date.tm_year == compare_tm.tm_year && date.tm_mon == compare_tm.tm_mon && date.tm_mday == compare_tm.tm_mday);
			}
			// time 값이 sec 단위여야 함
			// time 이 만들어진(mktime 등으로) 타임스탬프가 아닌, 
			// 현재 시간에 대한 타임스탬프여야 한다.
			static bool CompareSameDay(int64_t time, bool is_local = false)
			{
				std::time_t t = std::time(nullptr);

				if (true == is_local)
				{
					ConvertToLocalTime(t);
					ConvertToLocalTime(time);
				}
#ifdef _WINDOWS	
				std::tm date;
				if (0 != localtime_s(&date, &t))
					return false;

				std::tm compare_tm;
				if (0 != localtime_s(&compare_tm, &time)) 
					return false;
#else
				struct tm date = *std::localtime(&t);
				struct tm compare_tm = *std::localtime(&time);
#endif

				return (date.tm_year == compare_tm.tm_year && date.tm_mon == compare_tm.tm_mon && date.tm_mday == compare_tm.tm_mday);
			}

			// time 값이 sec 단위여야 함
			// time 이 만들어진(mktime 등으로) 타임스탬프가 아닌, 
			// 현재 시간에 대한 타임스탬프여야 한다.
			static bool CompareSameDayToUtc(int64_t time)
			{			
				std::time_t t = std::time(nullptr);

				time += _time_zone;

#ifdef _WINDOWS	
				std::tm date;
				if (0 != localtime_s(&date, &t))
					return false;

				std::tm compare_tm;
				if (0 != localtime_s(&compare_tm, &time))
					return false;

				return (date.tm_year == compare_tm.tm_year && date.tm_mon == compare_tm.tm_mon && date.tm_mday == compare_tm.tm_mday);
#else
				std::tm* date = nullptr;
				date = localtime(&t);
				if (nullptr == date)
					return false;

				std::tm* compare_tm = nullptr;
				compare_tm = localtime(&time);
				if (nullptr == compare_tm)
					return false;

				return (date->tm_year == compare_tm->tm_year && date->tm_mon == compare_tm->tm_mon && date->tm_mday == compare_tm->tm_mday);
#endif
			}


			// time 값이 sec 단위여야 함
			// time 이 만들어진(mktime 등으로) 타임스탬프가 아닌, 
			// 현재 시간에 대한 타임스탬프여야 한다.
			static bool CompareSameWeek(int64_t time, bool is_local = false)
			{
				std::time_t t = std::time(nullptr);

				t += _global_time_zone;

				if (true == is_local)
				{
					ConvertToLocalTime(t);
					ConvertToLocalTime(time);
				}
#ifdef _WINDOWS	
				std::tm date;
				if (0 != localtime_s(&date, &t))
					return false;

				std::tm compare_tm;
				if (0 != localtime_s(&compare_tm, &time))
					return false;
#else
				struct tm date = *std::localtime(&t);
				struct tm compare_tm = *std::localtime(&time);
#endif

				if (date.tm_year != compare_tm.tm_year)
					return false;

				if (date.tm_mon == compare_tm.tm_mon && date.tm_mday == compare_tm.tm_mday)
					return true;

				int32_t day = 0 == date.tm_wday ? 7 : date.tm_wday;
				int32_t com_day = 0 == compare_tm.tm_wday ? 7 : compare_tm.tm_wday;

				if ((date.tm_yday - day) > (compare_tm.tm_yday - com_day))
					return false;

				return true;
			}

//#ifdef _USE_GLOBAL_SERVICE		
			// time 값은 해당 타임존에 맞게 보정된 시간이어야 한다.
			// time 이 만들어진(mktime 등으로) 타임스탬프가 아닌, 
			// 현재 시간에 대한 타임스탬프여야 한다.
			static bool CompareSameWeekFromLocal(int64_t time)
			{
				int64_t t = LocalTime();
				 
#ifdef _WINDOWS	
				std::tm date;
				if (0 != localtime_s(&date, &t))
					return false;

				std::tm compare_tm;
				if (0 != localtime_s(&compare_tm, &time))
					return false;


				if (date.tm_year != compare_tm.tm_year)
					return false;

				if (date.tm_mon == compare_tm.tm_mon && date.tm_mday == compare_tm.tm_mday)
					return true;

				if (date.tm_yday >= compare_tm.tm_yday + 7)
					return false;

				if (0 == compare_tm.tm_wday)
					return false;

				if (0 == date.tm_wday)
					return true;

				if (date.tm_wday > compare_tm.tm_wday)
					return false;
#else
				std::tm* date = nullptr;
				date = localtime(&t);
				if (nullptr == date)
					return false;

				std::tm* compare_tm = nullptr;
				compare_tm = localtime(&time);
				if (nullptr == compare_tm)
					return false;

				if (date->tm_year != compare_tm->tm_year)
					return false;

				if (date->tm_mon == compare_tm->tm_mon && date->tm_mday == compare_tm->tm_mday)
					return true;

				if (date->tm_yday >= compare_tm->tm_yday + 7)
					return false;

				if (0 == compare_tm->tm_wday)
					return false;

				if (0 == date->tm_wday)
					return true;

				if (date->tm_wday > compare_tm->tm_wday)
					return false;
#endif

				return true;
			}
//#else
//			// time 값이 sec 단위여야 함
//			static bool CompareSameWeek(int64_t time, bool is_local = false, bool is_year_same = true)
//			{
//				std::time_t t = std::time(nullptr);
//
//				if (true == is_local)
//				{
//					ConvertToLocalTime(t);
//					ConvertToLocalTime(time);
//				}
//#ifdef _WINDOWS	
//				std::tm date;
//				if (0 != localtime_s(&date, &t))
//					return false;
//
//				std::tm compare_tm;
//				if (0 != localtime_s(&compare_tm, &time))
//					return false;
//#else
//				struct tm date = *std::localtime(&t);
//				struct tm compare_tm = *std::localtime(&time);
//#endif
//
//				if (true == is_year_same && date.tm_year != compare_tm.tm_year)
//					return false;
//
//				if (date.tm_mon == compare_tm.tm_mon && date.tm_mday == compare_tm.tm_mday)
//					return true;
//
//				//if (date.tm_yday >= compare_tm.tm_yday + 7)
//				//	return false;
//
//		/*		if (0 == compare_tm.tm_wday)
//					return false;
//
//				if (0 == date.tm_wday)
//					return true;*/
//
//				int32_t day = 0 == date.tm_wday ? 7 : date.tm_wday;
//				int32_t com_day = 0 == compare_tm.tm_wday ? 7 : compare_tm.tm_wday;
//
//				if ((date.tm_yday - day) > (compare_tm.tm_yday - com_day))
//					return false;
//
//				//if (date.tm_wday > compare_tm.tm_wday)
//				//	return false;
//
//				return true;
//			}
//#endif	// !_USE_GLOBAL_SERVICE

			// time 값이 sec 단위여야 함
			// time 이 만들어진(mktime 등으로) 타임스탬프가 아닌, 
			// 현재 시간에 대한 타임스탬프여야 한다.
			static bool CompareSameMonth(int64_t time, bool is_local = false)
			{
				std::time_t t = std::time(nullptr);

				t += _global_time_zone;

				if (true == is_local)
				{
					ConvertToLocalTime(t);
					ConvertToLocalTime(time);
				}
#ifdef _WINDOWS	
				std::tm date;
				if (0 != localtime_s(&date, &t))
					return false;

				std::tm compare_tm;
				if (0 != localtime_s(&compare_tm, &time))
					return false;
#else
				struct tm date = *std::localtime(&t);
				struct tm compare_tm = *std::localtime(&time);
#endif

				return (date.tm_year == compare_tm.tm_year && date.tm_mon == compare_tm.tm_mon);
			}

			// time 이 만들어진(mktime 등으로) 타임스탬프가 아닌, 
			// 현재 시간에 대한 타임스탬프여야 한다.
			static bool CompareSameMonthFromLocal(int64_t time, bool is_local = false)
			{
				int64_t t = LocalTime();

#ifdef _WINDOWS	
				std::tm date;
				if (0 != localtime_s(&date, &t))
					return false;

				std::tm compare_tm;
				if (0 != localtime_s(&compare_tm, &time))
					return false;

				return (date.tm_year == compare_tm.tm_year && date.tm_mon == compare_tm.tm_mon);
#else
				std::tm* date = nullptr;
				date = localtime(&t);
				if (nullptr == date)
					return false;

				std::tm* compare_tm = nullptr;
				compare_tm = localtime(&time);
				if (nullptr == compare_tm)
					return false;

				return (date->tm_year == compare_tm->tm_year && date->tm_mon == compare_tm->tm_mon);
#endif
			}

			// time 값이 sec 단위여야 함
			// time 이 만들어진(mktime 등으로) 타임스탬프가 아닌, 
			// 현재 시간에 대한 타임스탬프여야 한다.
			static int32_t BetweenDays(int64_t time, bool is_local = false)
			{
				std::time_t t = std::time(nullptr);

				if (true == is_local)
				{
					ConvertToLocalTime(t);
					ConvertToLocalTime(time);
				}
#ifdef _WINDOWS	
				std::tm date;
				if (0 != localtime_s(&date, &t))
					return false;

				std::tm compare_tm;
				if (0 != localtime_s(&compare_tm, &time))
					return false;
#else
				struct tm date = *std::localtime(&t);
				struct tm compare_tm = *std::localtime(&time);
#endif
				return date.tm_yday - compare_tm.tm_yday;
			}

			static int64_t AddDays(int64_t time, int32_t days)
			{
				int64_t t = 24 * 60 * 60 * days;
				return time + t;
			}

			static int32_t AddDaysToSec(const int32_t days, bool is_local = false)
			{
				std::time_t t = std::time(nullptr);

				if (true == is_local)
				{
					ConvertToLocalTime(t);
				}

				t += 24 * 60 * 60  * days;
				
#ifdef _WINDOWS
				std::tm date;
				if (0 != localtime_s(&date, &t))
				{
					return -1;
				}

				date.tm_hour = 0;
				date.tm_min = 0;
				date.tm_sec = 0;

				return static_cast<int32_t>(std::mktime(&date));
#else
				std::tm* date;
				date = localtime(&t);

				date->tm_hour = 0;
				date->tm_min = 0;
				date->tm_sec = 0;
				
				return static_cast<int32_t>(std::mktime(date));
#endif							
			}

			// date_time 형태 값을 타임스탬프로 바꿀때는 무조건 MakeTime~ 함수를 사용하자
			static int32_t MakeTime(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t min, int32_t sec)
			{
				std::tm date;
				date.tm_year = year - 1900;
				date.tm_mon = month - 1;
				date.tm_mday = day;
				date.tm_hour = hour;
				date.tm_min = min;
				date.tm_sec = sec;
				date.tm_isdst = -1;

				return static_cast<int32_t>(std::mktime(&date));
			}

			static int32_t MakeTime(const int64_t org_datetime)
			{
				if (0 < org_datetime)
				{
					std::tm date;
					date.tm_year	= static_cast<int32_t>((org_datetime / 100000000 + 2000) - 1900);
					date.tm_mon		= static_cast<int32_t>(((org_datetime / 1000000) % 100) - 1);
					date.tm_mday	= static_cast<int32_t>((org_datetime / 10000) % 100);
					date.tm_hour	= static_cast<int32_t>((org_datetime / 100) % 100);
					date.tm_min		= static_cast<int32_t>(org_datetime % 100);
					date.tm_sec		= 0;
					date.tm_isdst	= -1;

					return static_cast<int32_t>(std::mktime(&date));
				}

				return 0;
			}

			static int32_t MakeTimeFromLocalTime(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t min, int32_t sec)
			{
				std::tm date;
				date.tm_year = year - 1900;
				date.tm_mon = month - 1;
				date.tm_mday = day;
				date.tm_hour = hour;
				date.tm_min = min;
				date.tm_sec = sec;
				date.tm_isdst = -1;

				int32_t time = static_cast<int32_t>(std::mktime(&date));

				if (_config_time_zone)
					time += static_cast<int32_t>(_config_time_zone);

				return time - static_cast<int32_t>(_time_zone);
			}

			/** 
			* 20230101 이런식으로 저장된 값을 unixtime으로 만드는것은 해당 datetime에 절대시간으로 만들어져야됨
			* time_zone과 global_timezone에 영향을 받지않고 unixtime값을 호출해야함
			*/
			static int32_t MakeTimeFromUTCTime(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t min, int32_t sec)
			{
				std::tm date;
				date.tm_year = year - 1900;
				date.tm_mon = month - 1;
				date.tm_mday = day;
				date.tm_hour = hour;
				date.tm_min = min;
				date.tm_sec = sec;
				date.tm_isdst = -1;

				int32_t time = static_cast<int32_t>(std::mktime(&date));
				return time;
			}

			static bool CheckGovernanceAvailableDateTime(int32_t table_data)
			{
				// 거버넌스 시작날짜 공통체크
				// 형식: 2023011700, 2023030600...
				auto start_date_table = std::to_string(table_data);
				auto year = start_date_table.substr(0, 4);
				auto month = start_date_table.substr(4, 2);
				auto day = start_date_table.substr(6, 2);
				auto hour = start_date_table.substr(8, 2);

				std::tm start_date = { 0, };
				start_date.tm_year = atoi(year.c_str()) - 1900;
				start_date.tm_mon = atoi(month.c_str()) > 0 ? atoi(month.c_str()) - 1 : 0;
				start_date.tm_mday = atoi(day.c_str());
				start_date.tm_hour = atoi(hour.c_str()) > 0 ? atoi(hour.c_str()) - 1 : 0;

				// 로컬 시간으로 비교 
				std::time_t start_date_conv = std::mktime(&start_date);
				auto local_time = mir3d::util::mirTime::LocalTime();

				return start_date_conv < local_time ? true : false;
			}

		private:
			static int64_t _time_zone;
			static int32_t _global_time_zone;
			static int64_t _config_time_zone;
			static int32_t _time_zone_value;
		};

		class CTimeInterval
		{
		public:
			CTimeInterval(std::string log_name, bool send_counting = true);
			virtual ~CTimeInterval();
			void SendCounting();

		private:
			int64_t _start_time;
			std::string _log;

			int64_t _send_count;
			bool _send_counting;
		};

		static int CheckNickName(std::string& nickname)
		{
			int count = 0;
			int i = 0;

			while (i < nickname.length())
			{
				// Check the leading byte of the UTF-8 character
				unsigned char lead = nickname[i];

				if ((lead & 0xE0) == 0xE0) {
					count++;
					i += 3;
				}
				else {
					count++;
					i++;
				}
			}

			return count;
		}

		static size_t SplitString(const char* sourceStr, std::vector<std::string>& vStrings, char sep)
		{
			std::istringstream f(sourceStr);
			std::string s;
			while (std::getline(f, s, sep))
				vStrings.push_back(s);

			return vStrings.size();
		}
	};

	namespace enum_convert
	{
		template <typename T>
		bool itemtable_check_main_sub_type(const table::ITEM_MAINTYPE main_type, const table::ITEM_MAINTYPE check_main, int32_t check_key, T check_type)
		{
			if (main_type == check_main)
			{
				T check_value = static_cast<T>(check_key);

				return (check_value == check_type);
			}

			return false;
		}

		extern mpe_good_pos itemtable_itemtype_to_goodspos(const mir3d::table::ITEM_MAINTYPE& type, const int32_t& key);
		extern mpe_good_pos itemtable_itemtype_to_goodspos(int32_t key);
		extern table::GOODS_TYPE itemtable_goodspos_to_itemtype(const mir3d::mpe_good_pos& pos);
		extern mpe_equip_pos itemtable_equiptype_to_eEquipPos(const int32_t& type);
		extern mpe_equip_pos itemtable_costumetype_to_eEquipPos(const int32_t& type, const mir3d::table::GENDER_TYPE& gender_type);
		extern mpe_equip_pos dropitem_equiptype_to_eEquipPos(const int32_t& type);
		extern table::CLASS_TYPE charactertable_id_to_class_type(const int32_t& id);
		extern bool is_available_item(table::CHARACTER_TYPE l_cttype, table::CLASS_TYPE l_ctype, table::GENDER_TYPE l_gtype, table::CHARACTER_TYPE r_cttype, table::CLASS_TYPE r_ctype, table::GENDER_TYPE r_gtype);
		extern mpe_good_pos itemtable_goodstype_to_goodspos(const table::GOODS_TYPE& type);
		extern mir3d::table::SIEGE_TYPE ConvertFromMpeToTableSiegeType(mpe_siege_castle_type castle_type);
		extern mpe_siege_castle_type ConvertFromTableToMpeSiegeType(const mir3d::table::SIEGE_TYPE& castle_type);
		extern mir3d::table::TOWN_MENU ConvertFromTownDetailPosToTable(mpe_castle_town_detail_pos house_pos);
		extern bool ConvertFromTableToTownDetailPos(const mir3d::table::TOWN_MENU town_menu, mpe_castle_town_detail_pos& val);
		extern bool compare_equiptype_to_stonetype(int32_t equip_type, int32_t stone_type);
		extern mrpce_log_item_update_type ConvertFromTableToLogUpdateType(const mir3d::table::DUNGEON_TYPE& dungeon_type);
		extern bool IsCollectEquipment(const table::ITEM_MAINTYPE& main_type, const int32_t& sub_type);
		extern table::MAIL_TYPE ConvertEnumFromPacketToTable(const mpe_mail_type& mail_type);
		extern mpe_mail_type ConvertEnumFromTableToPacket(const table::MAIL_TYPE& mail_type);
		extern mrpce_game_event ConvertEnumFromPacketToTable(const table::OPENDUNGEON_CONTENT_TYPE& content_type);
		extern mpe_ranking_type ConvertToMpeRankingType(const table::RANKING_TYPE& type);
		extern mpe_ranking_type ConvertToMpeRankingType(const table::PROFESIONTYPE& type);
		extern int32_t ConvertToIllustionType(const table::OPENDUNGEON_CONTENT_TYPE& dungeon_type);
	};
} // namespace mir3d
