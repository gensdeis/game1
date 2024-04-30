
// Author : choi kisoo 2018-10-18
#ifdef ENABLE_STOPWATCH
#pragma once
#include <common/mirapi.h>
#include <common/concurrentQueue.h>
#include <common/concurrentStack.h>
#include <common/concurrentMap.h>
#include <deque>
#include <string.h>
#include <boost/chrono.hpp>

//#define  SET_STOPWATCH(name, server_id, pc_count)	\
//mir3d::mirStopWatch sw;								\
//sw.start( name, server_id, pc_count );				\
//sw.lap( "001" );						\

//using namespace std;
//using namespace chrono;

namespace mir3d
{

	// 스톱 워치 클래스
	class mirCountWatch
	{
		typedef struct
		{			
			std::chrono::system_clock::time_point s_time;
			int64_t	latency;
			int64_t id;
			std::string memo;
		} lap_data;

		
		std::mutex		    _mutex;
		//CConcurrentStack<lap_data*>	_lap_stack;
		std::unordered_map<int64_t, lap_data*>	_lap_map;

		std::string m_name;
	public:
		mirCountWatch();
		~mirCountWatch();
		
		void Insert_map( int64_t key_,  lap_data *value_)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			_lap_map.insert(std::make_pair(key_, value_));
		}
		lap_data* Find_map(const int64_t key_)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			auto iter = _lap_map.find(key_);
			if (_lap_map.end() != iter)
			{
				return iter->second;
			}
			return nullptr;
		}
		int Size_map()
		{
			//std::lock_guard<std::mutex> lock(_mutex);
			return (int)_lap_map.size();
		}
		bool Clear_map()
		{
			std::lock_guard<std::mutex> lock(_mutex);
			for (const auto& iter : _lap_map)
			{
				lap_data* pdata = iter.second;
				SAFE_DELETE(pdata);
			}

			_lap_map.clear();
			return true;
		}

		size_t Get_map(std::vector<lap_data *>& list)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			auto iter = _lap_map.begin();
			while (_lap_map.end() != iter)
			{
				list.emplace_back(iter->second);
				++iter;
			}

			return _lap_map.size();
		}

		std::string getStringFormat(const char* fmt, ...);
		void start(int64_t id, std::string name);
		void recv_lap(int64_t id, std::string name);

		void show();
		void clear();
		//typedef std::chrono::duration<long long, std::milli> milliseconds;
		

	};
	// 스톱 워치 클래스
	class mirStopWatch
	{
		typedef struct
		{
			std::chrono::system_clock::time_point c_time;
			std::string name;
			int64_t	lap;
			std::string memo;
		} lap_data;

		//static const char* const    sm_pLogfile;
		//static int64_t m_swFrequency;
		std::chrono::system_clock::time_point _s_time; 
		
		int m_pc_count;
	public:
		mirStopWatch();
		~mirStopWatch();
		int m_serverId;
		
		std::string m_name;
		
		CConcurrentQueue<lap_data*>		_lap_que;
		std::string getStringFormat(const char* fmt, ...);
		void start(std::string name, int serverId, int pc_count);
		void lap(const char*, const char* fmt = NULL, ...);

		void show();
		void clear();

		
	};
}
#endif