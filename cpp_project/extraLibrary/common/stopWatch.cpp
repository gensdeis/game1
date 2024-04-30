#include "stdafx_net.h"

#ifdef ENABLE_STOPWATCH
#include "stopWatch.h"
#include <boost/format.hpp>
#if defined(_WIN32)
#include <windows.h>
#include <time.h>
#include <stdarg.h>

#elif defined(__linux__) || defined (__APPLE__)
#include <stdarg.h>
#include <sys/time.h>
#include <boost/format.hpp>

#endif


#define MAX_CHECK_COUNT 50

namespace mir3d
{
	//const char* const mirStopWatch::sm_pLogfile = "StopWatchLog";
	//int64_t mirStopWatch::m_swFrequency = 0;
	mirCountWatch::mirCountWatch()
	{
		
		m_name = "";
		
#if defined(_WIN32)
		//QueryPerformanceFrequency((LARGE_INTEGER*)&m_cwFrequency);
#elif defined(__linux__) || defined (__APPLE__)

#endif
	}
	/**
	*/
	mirCountWatch::~mirCountWatch()
	{
#ifdef ENABLE_STOPWATCH
		show();
		clear();

#endif
	}

	/**

	*/
	void mirCountWatch::clear()
	{
#ifdef ENABLE_STOPWATCH
		Clear_map();
		m_name = "";

#endif
	}

	std::string mirCountWatch::getStringFormat(const char* fmt, ...)
	{

		std::string message = "";
		va_list args;
		char* va_buff = nullptr;
#if defined(_WIN32)

		int required = 0;
		if (fmt)
		{
			va_start(args, fmt);
			required = _vscprintf(fmt, args);
			required = required + 10;
			va_buff = new char[required + 1];
			vsnprintf(va_buff, required, fmt, args);
			va_end(args);

			va_buff[required] = '\0';
			if (va_buff != nullptr)
				message = va_buff;
			delete[] va_buff;
		}
#elif defined(__linux__) || defined (__APPLE__)

		if (fmt)
		{
			va_start(args, fmt);
			vasprintf(&va_buff, fmt, args);
			va_end(args);


			if (va_buff != nullptr)
				message = va_buff;

			free(va_buff);
		}
#endif
		return message;
	}

	/**

	*/
	void mirCountWatch::start(int64_t id, std::string name)
	{
#ifdef ENABLE_STOPWATCH
			
		if(m_name == "")
			m_name = name.c_str();//(boost::format("%1%_START") % name ).str();
		
		{
			lap_data* pdata = new lap_data();
			
			pdata->s_time = std::chrono::system_clock::now();
			pdata->id = (id == 0) ?(int64)Size_map() + 1 : id;
			pdata->latency = 0 ;
			pdata->memo = "";
			Insert_map(pdata->id, pdata);
			//_lap_map.insert(std::make_pair(id, pdata));
		}

#endif
	}

	/**

	*/
	void mirCountWatch::recv_lap(int64_t id, std::string name)
	{
#ifdef ENABLE_STOPWATCH
		
		{	
			
			if (id == 0)
			{
				id = Size_map();
			}
		
			
			//auto iter = _lap_map.find(id);
			//if (_lap_map.end() != iter)
			//{
			lap_data* olddata = Find_map(id);
			if(olddata != nullptr)
			{
				std::chrono::system_clock::time_point e_time = std::chrono::system_clock::now();

				std::chrono::milliseconds mill = std::chrono::duration_cast<std::chrono::milliseconds>(e_time - olddata->s_time);

				olddata->latency = mill.count();

				if(name != "")
					olddata->memo = name.c_str();
			}
				
			//}
			
	
			if (MAX_CHECK_COUNT <= Size_map())
			{
				show();
				clear();
			}
		}

#endif
	}

	/**

	*/
	void mirCountWatch::show()
	{
#ifdef ENABLE_STOPWATCH
				
		{
			std::string startMsg = "";
			std::string endMsg = "";
			std::vector<std::string> lapMsg;


			bool bLogfile = false;
			int64_t latency_total = 0;

			int size = (int)Size_map();
			int count = 0;
			std::vector< lap_data*> lap_list;
			Get_map(lap_list);

			for (const auto& iter : lap_list)
			{
				//lap_data* pdata = iter.second;
				if (nullptr != iter)
				{
					if ((iter->latency) > 50)
					{
						latency_total += iter->latency;
						bLogfile = true;
						count++;

						if (!iter->memo.empty())
						{
							lapMsg.push_back(getStringFormat("[id:%d][%s] %ld ms ", iter->id, iter->memo.c_str(), int64_t(iter->latency)));
							bLogfile = true;
						}
						else
						{
							lapMsg.push_back((getStringFormat("[id:%d] %ld ms ", iter->id, int64_t(iter->latency))));
							bLogfile = true;
						}

					}
					//delete pdata;
				}
			}
			lap_list.clear();
			startMsg = (getStringFormat("[START][%6s][packet total:%d ][count:%d] >>>>>>>>", m_name.c_str(),size, count));

			if ((count) > 0 || bLogfile)
			{
				int64_t latency_avr = latency_total / count;
				endMsg = (getStringFormat("[END][%6s][avrage:%ld ms] <<<<<<<<", m_name.c_str(), latency_avr));
				bLogfile = true;

			}

			if (bLogfile)
			{
				// filename m_ServerName
				//
				LOG(WARNING) << startMsg;
				for (auto str : lapMsg)
				{
					LOG(WARNING) << str;
				}
				LOG(WARNING) << endMsg;
			}
		}


#endif
	}

	mirStopWatch::mirStopWatch()
	{
		m_pc_count = 0;
		m_name = "";
		_s_time = std::chrono::system_clock::now();
		m_serverId = 0;
#if defined(_WIN32)
		//QueryPerformanceFrequency((LARGE_INTEGER*)&mirStopWatch::m_swFrequency);

#elif defined(__linux__) || defined (__APPLE__)

#endif
	}

	/**

	*/
	mirStopWatch::~mirStopWatch()
	{
#ifdef ENABLE_STOPWATCH
		show();
		clear();

#endif
	}

	/**

	*/
	void mirStopWatch::clear()
	{
#ifdef ENABLE_STOPWATCH
	
		while (true)
		{
			lap_data *pdata;
			if (false == _lap_que.Pop(pdata))
			{
				break;
			}
			delete pdata;
		}
		_s_time = std::chrono::system_clock::now();
		//m_startTime = 0;
		//m_endTime = 0;
		m_name = "";



#endif
	}

	std::string mirStopWatch::getStringFormat(const char* fmt, ...)
	{

		std::string message = "";
		va_list args;
		char* va_buff = nullptr;
#if defined(_WIN32)

		int required = 0;
		if (fmt)
		{
			va_start(args, fmt);
			required = _vscprintf(fmt, args);
			va_buff = new char[required + 1];
			vsnprintf(va_buff, required, fmt, args);
			va_end(args);

			va_buff[required] = '\0';
			if (va_buff != nullptr)
				message = va_buff;
			delete[] va_buff;
		}
#elif defined(__linux__) || defined (__APPLE__)


		if (fmt)
		{

			va_start(args, fmt);
			vasprintf(&va_buff, fmt, args);
			va_end(args);


			if (va_buff != nullptr)
				message = va_buff;

			free(va_buff);
		}
#endif
	
		return message;
	}

	/**

	*/
	void mirStopWatch::start(std::string name, int serverId, int pc_count )
	{
#ifdef ENABLE_STOPWATCH
		m_serverId = serverId;
		m_pc_count = pc_count;
		m_name = name;

		//m_ServerName = (boost::format("%1%_serverId_%2%.log") % sm_pLogfile % serverId).str();

#if defined(_WIN32)

		if (m_pc_count > 0)
		{
			_s_time = std::chrono::system_clock::now();
			//QueryPerformanceCounter((LARGE_INTEGER*)&m_startTime);
		}
#elif defined(__linux__) || defined (__APPLE__)

		struct timeval begin_time;
		gettimeofday(&begin_time, NULL);
		m_startTime = (int64_t)(begin_time.tv_sec * 1000) + (int64_t)(begin_time.tv_usec * 0.001);
#endif

#endif
	}

	/**

	*/
	void mirStopWatch::lap( const char* name, const char* fmt, ... )
	{
#ifdef ENABLE_STOPWATCH
		

		if (m_pc_count > 0)
		{
			lap_data * pdata = new lap_data();

			if (name != nullptr)
				pdata->name = name;

			va_list args;
			char* va_buff = nullptr;
#if defined(_WIN32)

			//QueryPerformanceCounter((LARGE_INTEGER*)&m_endTime);
			//밀리세컨드로
			//int64_t timeDiff = (int64_t)(((m_endTime - m_startTime) * 1000000) / mirStopWatch::m_swFrequency);
			//pdata->lap = (int64_t)(timeDiff * 0.001f);
			//m_startTime = m_endTime;
			//1000 밀리세컨드 ms 1000000 마이크로세컨드 us
			//data.lap = (int64_t)((m_endTime - m_startTime) / StopWatch::m_swFrequency) * 1000;

			std::chrono::system_clock::time_point e_time = std::chrono::system_clock::now();
			//QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);

			//int64_t timeDiff = (int64_t)(e_time - olddata->s_time);
			std::chrono::milliseconds mill = std::chrono::duration_cast<std::chrono::milliseconds>(e_time - _s_time);
			//duration<int64_t> sec = e_time - olddata->s_time;
			pdata->lap = mill.count();
			_s_time = e_time;

			int required = 0;
			if (fmt)
			{
				va_start(args, fmt);
				required = _vscprintf(fmt, args);
				va_buff = new char[required + 1];
				vsnprintf(va_buff, required, fmt, args);
				va_end(args);

				va_buff[required] = '\0';
				if (va_buff != nullptr)
					pdata->memo = va_buff;
				delete[] va_buff;
			}

#elif defined(__linux__) || defined (__APPLE__)

			struct timeval lap_time;
			gettimeofday(&lap_time, NULL);
			pdata->lap = (int64_t)(lap_time.tv_sec * 1000) + (int64_t)(lap_time.tv_usec * 0.001) - m_startTime;

			if (fmt)
			{

				va_start(args, fmt);
				vasprintf(&va_buff, fmt, args);
				va_end(args);

				if (va_buff != nullptr)
					pdata->memo = va_buff;

				free(buf);

			}
#endif
			
			_lap_que.Push(pdata);
		}

#endif
	}

	/**
	//cks 소멸될때 호출 자동으로 큐에 쌓인 만큼 가져와 로그를 남긴다.
	*/
	void mirStopWatch::show()
	{
#ifdef ENABLE_STOPWATCH

		if ( m_pc_count > 0 )
		{
			std::string startMsg = "";
			std::string endMsg = "";
			std::vector<std::string> lapMsg;

			if ( m_name.empty() )
			{
				startMsg = ("[SW:START] >>>");
			}
			else
			{
				startMsg = (getStringFormat("[SW:START][%12s][id:%d][pc:%d] >>>>>>>>", this->m_name.c_str(),m_serverId, m_pc_count));
				//message.append((boost::format("[SW:START][%12s][pc:%d] >>>>>>>>\n")%this->m_name % m_pc_count).str());
			}

			bool bLogfile = false;
			int64_t lap_before = 0;
			lap_data * pdata = nullptr;


			int count = 0;
			int64_t gap = 50;
			int64_t lap_total = 0;
			while (true)
			{
				if (_lap_que.Front(pdata))
				{
					if ((pdata->lap ) >= gap)
					{
						if (!pdata->memo.empty())
						{
							lapMsg.push_back((getStringFormat("[%0s] %ld ms : [%s]", pdata->name.c_str(), int64_t(pdata->lap),  pdata->memo.c_str())));
							bLogfile = true;
						}
						else
						{
							lapMsg.push_back((getStringFormat("[%10s] %ld ms : ", pdata->name.c_str(), int64_t(pdata->lap))));
							bLogfile = true;
						}

						
					}
					lap_total += pdata->lap;
					count++;
					

					delete pdata;
					_lap_que.FrontErase();
				}
				else
					break;
				
			}
			
			
#if defined(_WIN32)
			//int64_t m_currentTime;
			//QueryPerformanceCounter((LARGE_INTEGER*)&m_currentTime);
			//밀리세컨드로
			//int64_t timeDiff = (int64_t)(((m_currentTime - m_startTime) * 1000000) / mirStopWatch::m_swFrequency);
			//lap_total = (int64_t)(timeDiff * 0.001f);
#else
			struct timeval lap_time;
			gettimeofday(&lap_time, NULL);

			lap_total = (int64_t)(lap_time.tv_sec * 1000) + (int64_t)(lap_time.tv_usec * 0.001) - m_startTime;
#endif
			if ((lap_total) >= 70 || bLogfile)
			{
				if ( !this->m_name.empty() )
				{					
					endMsg = (getStringFormat("[SW:END] [%12s] total = %ldms lap count = %ld <<<<<<<<\n",this->m_name.c_str(), lap_total, count));
					bLogfile = true;
				}
				else
				{
					endMsg =("[SW:END] <<<<<<<<");
					bLogfile = true;
				}
				
			}
		
			if (bLogfile)
			{
				// filename m_ServerName
				//
				LOG(WARNING) << startMsg;
				for (auto str : lapMsg)
				{
					LOG(WARNING) << str;
				}
				LOG(WARNING) << endMsg;
			}
		}


#endif
	}
}
#endif