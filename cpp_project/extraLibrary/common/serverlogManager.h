#pragma once

#include <network/thread.h>
#include <common/singleton.hpp>
#include <common/concurrentMemPool.hpp>
#include <common/concurrentQueue.hpp>

namespace mir3d
{
	#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

	#define SERVER_LOG(type, msg, ...) \
			mir3d::serverlogManager.ServerLogPush(__FILENAME__, __LINE__, type, msg, ##__VA_ARGS__);

	#define ACTION_LOG(type, msg) \
			mir3d::serverlogManager.ActionLogPush(type, msg);

	#define LOG_TEXT_LENGTH 2048
	
	
	#define CONSOLE_COLOR_RESET   	"\033[0m"
	#define CONSOLE_COLOR_BLACK   	"\033[30m"      	/* Black */
	#define CONSOLE_COLOR_RED     	"\033[31m"      	/* Red */
	#define CONSOLE_COLOR_GREEN   	"\033[32m"      	/* Green */
	#define CONSOLE_COLOR_YELLOW  	"\033[33m"      	/* Yellow */
	#define CONSOLE_COLOR_BLUE    	"\033[34m"      	/* Blue */
	#define CONSOLE_COLOR_MAGENTA 	"\033[35m"      	/* Magenta */
	#define CONSOLE_COLOR_CYAN    	"\033[36m"      	/* Cyan */
	#define CONSOLE_COLOR_WHITE   	"\033[37m"      	/* White */
	#define CONSOLE_COLOR_BOLDBLACK   "\033[1m\033[30m"   /* Bold Black */
	// std::cout << "\033[32;1mThis text will be green\033[0m\n";

	enum class eServerLogType
	{
		eDebug		= 0, // 100,	// g3::kDebugValue,
		eInfo		= 1, // 200,	// g3::kInfoValue,
		eWarning	= 2, // 500,	// g3::kWarningValue,
		eAction		= 3,
		eFatal		= 4, // 1000	// g3::kFatalValue		
		eMax		= 5
	};

	struct sServerlog
	{
		eServerLogType		type = eServerLogType::eDebug;
		uint16_t			size = 0;
		uint16_t			index = 0;
		uint64_t			number = 0;
		char				text[LOG_TEXT_LENGTH] = { '\0' };
		
		void Reset()
		{
			type = eServerLogType::eDebug;
			size = 0;
			index = 0;
			number = 0;
			memset(text, '\0', sizeof(text));
		}
	};

	class CServerlogManager : public CThread, public CSingleton<CServerlogManager>
	{
	public:
		CServerlogManager() = delete;
		CServerlogManager(const std::string& base_path, const std::string& log_prefix, const int64_t rotate_time, const std::string& name, int32_t update_time = 100);
		virtual ~CServerlogManager() 
		{
			Destroy();
		}

	public:
		virtual void Initialize(bool suspend = true);
		virtual void Start(void);
		virtual void Destroy(void);

	protected:
		virtual bool Begin(void);
		virtual bool Run(int32_t index);
		virtual bool End(void);

	private:
		void CreateLogFile(const eServerLogType type);
		std::string pathSanityFix(std::string path, std::string file_name);
		std::unique_ptr<std::ofstream> createFile(const std::string& file_with_full_path);
		bool openLogFile(const std::string& complete_file_with_path, std::ofstream& outstream);
		bool CheckFileRotateAndTimeUpdate(const eServerLogType type);

		sServerlog* Pop(void)
		{
			int32_t index = 0;
			if (LLONG_MAX > _list_pool_index.load())
			{
				index = _list_pool_index.fetch_add(1) % _max_pool_count;
			}
			else
			{
				_list_pool_index.exchange(0);
			}

			auto item = _list_pool[index]->Pop();
			item->index = index;
			return item;
		}

		void Push(sServerlog* log)
		{
			_list_pool[log->index]->Push(log);
		}

		void ConsoleOutput(sServerlog* log);

	public:
		void ServerLogPush(const char* filename, int32_t line, eServerLogType type, const char* fmt, ...)
		{
			auto log = Pop();

			log->number = _list_log_number[static_cast<int32_t>(type)]->fetch_add(1);

			if (ULLONG_MAX == log->number)
			{
				_list_log_number[static_cast<int32_t>(type)]->exchange(0);
				log->number = 0;
			}

			std::stringstream	thead_id;
			std::stringstream	date_time;

			{
				auto now = std::chrono::system_clock::now();
				auto time = std::chrono::system_clock::to_time_t(now);			
				auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

#ifdef _WINDOWS
				std::tm tm; 
				localtime_s(&tm, &time);
				date_time << std::put_time(&tm, "%Y-%m-%d %T.") << std::setfill('0') << std::setw(3) << ms %1000;
#else
				std::tm* tm; 
				tm = localtime(&time);
				date_time << std::put_time(tm, "%Y-%m-%d %T.") << std::setfill('0') << std::setw(3) << ms %1000;
#endif				
			}			

			thead_id << std::this_thread::get_id();
#ifdef _WINDOWS				
			log->size = (uint16_t)snprintf(log->text, LOG_TEXT_LENGTH, "[%I64u][%s][%s][%s : %d] ", log->number, date_time.str().c_str(), thead_id.str().c_str(), filename, line);
#else
			log->size = (uint16_t)snprintf(log->text, LOG_TEXT_LENGTH, "[%lu][%s][%s][%s : %d] ", log->number, date_time.str().c_str(), thead_id.str().c_str(), filename, line);
#endif
			
			log->type = type;

			va_list args;
			va_start(args, fmt);
			{
#ifdef _WINDOWS				
				log->size += _vsnprintf_s(&log->text[log->size], LOG_TEXT_LENGTH - log->size, _TRUNCATE, fmt, args);
#else
				log->size += snprintf(&log->text[log->size], LOG_TEXT_LENGTH - log->size, fmt, args);
#endif
			}
			va_end(args);

			_list_queue[_push_index][log->index]->Push(log);
		}

		void ActionLogPush(int32_t type, const char* text)
		{
			auto log = Pop();

			log->size = (uint16_t)snprintf(log->text, LOG_TEXT_LENGTH, "%d,%s", type, text);	
			log->type = eServerLogType::eAction;

			_list_queue[_push_index][log->index]->Push(log);
		}

	private:
		std::string													_base_path;
		std::string													_log_prefix;
		std::string													_file_name_time_formatted = "%Y%m%d-%H%M%S";
		uint64_t													_rotate_time = 0;

	private:
		std::vector<CMemPool<sServerlog>*>							_list_pool;
		std::atomic<int64_t>										_list_pool_index = 0;
		int32_t														_max_pool_count = 0;

		std::atomic<int32_t>										_push_index = 0;
		std::atomic<int32_t>										_update_index = 0;
		std::vector<std::vector<CConcurrentQueue<sServerlog*>*>>	_list_queue;
				
		std::vector<std::atomic<uint64_t>*>							_list_log_number;

		std::vector<uint64_t>										_list_log_file_create_time;
		std::vector<std::unique_ptr<std::ofstream>>					_list_log_file_handle;
		std::vector<bool>											_list_log_flag;
		std::vector<std::vector<sServerlog*>>						_list_log_sort;		
		std::vector<int32_t>										_list_log_sort_index;

		bool														_is_initialized = false;
	public:
		bool isLoggingInitialized() { return _is_initialized; }

	private:
		CServerlogManager(const CServerlogManager&) = delete;
		CServerlogManager& operator=(const CServerlogManager&) = delete;
		CServerlogManager(CServerlogManager&&) = delete;
		CServerlogManager& operator=(CServerlogManager&&) = delete;
	};
	#define serverlogManager CServerlogManager::getInstance()

	void OnMempoolAllocLogger(const char* creator, const int32_t& size);
}	// namespace mir3d

