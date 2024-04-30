#include "stdafx_net.h"
#include "serverlogManager.h"
#include <common/config.h>

#define MAX_SERVER_LOGQUEUE	2
#define _USE_CONSOLE_LOG 1
#define _SORT_LOG_MAX_SIZE 8192 * 10

namespace mir3d
{
	bool compare(sServerlog* a, sServerlog* b)
	{
		return a->number < b->number;
	}

	CServerlogManager::CServerlogManager(const std::string& base_path, const std::string& log_prefix, const int64_t rotate_time, const std::string& name, int32_t update_time) : CThread(update_time, name), _base_path(base_path), _log_prefix(log_prefix), _rotate_time(rotate_time)
	{
		_max_pool_count = GameConfig::Server_ThreadCount();

		for (int32_t i = 0; i < _max_pool_count; i++)
		{
			auto item = new CMemPool<sServerlog>(1024, 32, name + "_" + std::to_string(i), nullptr);
			_list_pool.push_back(item);
		}

		for (int32_t i = 0; i <= MAX_SERVER_LOGQUEUE; i++)
		{
			std::vector<CConcurrentQueue<sServerlog*>*> list;
			for (int32_t i = 0; i < _max_pool_count; i++)
			{
				auto item = new CConcurrentQueue<sServerlog*>();
				list.push_back(item);
			}

			_list_queue.push_back(list);
		}
				
		for (int32_t i = 0; i < static_cast<int32_t>(eServerLogType::eMax); i++)
		{
			_list_log_flag.push_back(false);
			_list_log_file_handle.push_back(nullptr);
			_list_log_file_create_time.push_back(0);

			auto item = new std::atomic<uint64_t>();
			item->exchange(0);
			_list_log_number.push_back(item);
		}

		for (int32_t i = 0; i < static_cast<int32_t>(eServerLogType::eMax); i++)
		{
			CreateLogFile(static_cast<eServerLogType>(i));
		}

		for (int32_t i = 0; i < static_cast<int32_t>(eServerLogType::eMax); i++)
		{
			std::vector<sServerlog*> vector;
			vector.reserve(_SORT_LOG_MAX_SIZE + 1);
			for (int32_t j = 0; j < _SORT_LOG_MAX_SIZE + 1; j++)
			{
				vector.push_back(nullptr);
			}
			_list_log_sort.push_back(vector);

			_list_log_sort_index.push_back(0);
		}

		_push_index = 0;
		_update_index = MAX_SERVER_LOGQUEUE - 1;
	}

	void CServerlogManager::Initialize(bool suspend)
	{
		CThread::Initialize(1, suspend);
	}

	void CServerlogManager::Start(void)
	{
		CThread::Start();
	}

	void CServerlogManager::Destroy(void)
	{
		CThread::Destroy();

		for (size_t i = 0; i < _list_log_file_handle.size(); i++)
		{
			if (_list_log_file_handle[i]->is_open())
			{
				CreateLogFile(static_cast<eServerLogType>(i));
			}
		}
		_list_log_file_handle.clear();

		for (int32_t i = 0; i <= MAX_SERVER_LOGQUEUE; i++)
		{
			for (size_t j = 0; j < _list_queue[i].size(); j++)
			{
				SAFE_DELETE(_list_queue[i][j]);
			}
		}

		for (int32_t i = 0; i < static_cast<int32_t>(_list_pool.size()); i++)
		{
			SAFE_DELETE(_list_pool[i]);
		}
	}

	bool CServerlogManager::Begin(void)
	{
		return true;
	}

	bool CServerlogManager::Run(int32_t index)
	{
		if (MAX_SERVER_LOGQUEUE == _push_index) _push_index.exchange(0);
		else _push_index.fetch_add(1);

		if (MAX_SERVER_LOGQUEUE == _update_index) _update_index.exchange(0);
		else _update_index.fetch_add(1);
		
		sServerlog* item = nullptr;

#ifdef _OLD_NO_SORT_LOG_VERSION
		for (int32_t i = 0; i < _max_pool_count; i++)
		{
			if (false == _list_queue[_update_index][i]->IsEmpty(false))
			{
				while (_list_queue[_update_index][i]->Pop(item))
				{
					if (nullptr != _list_log_file_handle[static_cast<int32_t>(item->type)].get())
					{
						*(_list_log_file_handle[static_cast<int32_t>(item->type)].get()) << item->text << "\n";// << std::flush;

						_list_log_flag[static_cast<int32_t>(item->type)] = true;

#ifdef _USE_CONSOLE_LOG
						if (eServerLogType::eAction != item->type)
						{
							ConsoleOutput(item);
						}
#endif
					}

					Push(item);
				}
			}
		}
#endif

		for (int32_t i = 0; i < _max_pool_count; i++)
		{
			if (false == _list_queue[_update_index][i]->IsEmpty(false))
			{
				while (_list_queue[_update_index][i]->Pop(item))
				{
					if (_list_log_sort_index[static_cast<int32_t>(item->type)] < _SORT_LOG_MAX_SIZE)
					{
						_list_log_sort[static_cast<int32_t>(item->type)][_list_log_sort_index[static_cast<int32_t>(item->type)]++] = item;
					}
				}
			}
		}

		for (int32_t i = 0; i < static_cast<int32_t>(eServerLogType::eMax); i++)
		{
			if (0 < _list_log_sort_index[i])
			{
				auto handle = _list_log_file_handle[i].get();

				if (nullptr != handle)
				{
					auto iter = _list_log_sort[i].begin();

					std::sort(iter, iter + _list_log_sort_index[i], compare);

					for (int32_t j = 0; j < _list_log_sort_index[i]; j++)
					{
						*(handle) << _list_log_sort[i][j]->text << "\n";// << std::flush;

#ifdef _USE_CONSOLE_LOG
						if (eServerLogType::eAction != _list_log_sort[i][j]->type)
						{
							ConsoleOutput(_list_log_sort[i][j]);
						}
#endif
						Push(_list_log_sort[i][j]);
					}

					_list_log_flag[i] = true;
				}
				else
				{
					for (int32_t j = 0; j < _list_log_sort_index[i]; j++)
					{
						Push(_list_log_sort[i][j]);
					}
				}
			}

			_list_log_sort_index[i] = 0;
		}

		
		for (int32_t i = 0; i < static_cast<int32_t>(eServerLogType::eMax); i++)
		{
			if (true == _list_log_flag[i])
			{
				if (nullptr != _list_log_file_handle[i])
				{
					*(_list_log_file_handle[i].get()) << std::flush;

					if (true == CheckFileRotateAndTimeUpdate(static_cast<eServerLogType>(i)))
					{
						if (_list_log_file_handle[i]->is_open())
						{
							_list_log_file_handle[i]->close();

							CreateLogFile(static_cast<eServerLogType>(i));
						}
					}
				}
			}

			_list_log_flag[i] = false;
		}

		return true;
	}

	bool CServerlogManager::End(void)
	{
		return true;
	}

	void CServerlogManager::CreateLogFile(const eServerLogType type)
	{
		std::string level;

		switch (type)
		{
		case eServerLogType::eDebug:	level = "DEBUG";		break;
		case eServerLogType::eInfo:		level = "INFO";			break;
		case eServerLogType::eWarning:	level = "WARNING";		break;
		case eServerLogType::eAction:	level = "ACTION";		break;
		case eServerLogType::eFatal:	level = "FATAL";		break;
		default: break;
		}

		std::string level_path = _base_path + level;

		if (false == boost::filesystem::exists(level_path))
		{
			boost::filesystem::create_directories(level_path);
		}

		std::stringstream oss_name;
		oss_name << _log_prefix << level << "_";
		
		auto now = std::chrono::system_clock::now();
		auto time = std::chrono::system_clock::to_time_t(now);
		std::tm tm; localtime_s(&tm, &time);

		oss_name << std::put_time(&tm, "%Y-%m-%d_%T") << ".log";

		std::string file_name = oss_name.str();
		auto log_file_with_path = pathSanityFix(level_path, file_name);
		std::unique_ptr<std::ofstream> outptr = createFile(log_file_with_path);

		if (!outptr)
		{
			std::cerr << "Cannot write log file to location, attempting current directory" << std::endl;
			log_file_with_path = "./" + file_name;
			outptr = createFile(log_file_with_path);
		}	

		_list_log_file_handle[static_cast<int32_t>(type)] = std::move(outptr);
		_list_log_file_create_time[static_cast<int32_t>(type)] = util::mirTime::GetTickMilliCount();
	}

	std::string CServerlogManager::pathSanityFix(std::string path, std::string file_name)
	{
		// Unify the delimeters,. maybe sketchy solution but it seems to work
		// on at least win7 + ubuntu. All bets are off for older windows
		std::replace(path.begin(), path.end(), '\\', '/');

		// clean up in case of multiples
		auto contains_end = [&](std::string& in) -> bool {
			size_t size = in.size();
			if (!size) return false;
			char end = in[size - 1];
			return (end == '/' || end == ' ');
		};

		while (contains_end(path)) {
			path.erase(path.size() - 1);
		}

		if (!path.empty()) {
			path.insert(path.end(), '\\');
		}

		std::replace(file_name.begin(), file_name.end(), ':', '_');

		path.insert(path.size(), file_name);
		return path;
	}

	std::unique_ptr<std::ofstream> CServerlogManager::createFile(const std::string& file_with_full_path)
	{
		std::unique_ptr<std::ofstream> out(new std::ofstream);
		std::ofstream& stream(*(out.get()));
		bool success_with_open_file = openLogFile(file_with_full_path, stream);
		if (false == success_with_open_file) 
		{
			out.release();
		}
		return out;
	}

	bool CServerlogManager::openLogFile(const std::string& complete_file_with_path, std::ofstream& outstream)
	{
		std::ios_base::openmode mode = std::ios_base::out; // for clarity: it's really overkill since it's an ofstream
		mode |= std::ios_base::trunc;
		outstream.open(complete_file_with_path, mode);
		if (!outstream.is_open()) 
		{
			std::ostringstream ss_error;
			ss_error << "FILE ERROR:  could not open log file:[" << complete_file_with_path << "]";
			ss_error << "\n\t\t std::ios_base state = " << outstream.rdstate();
			std::cerr << ss_error.str().c_str() << std::endl;
			outstream.close();
			return false;
		}
		return true;
	}

	bool CServerlogManager::CheckFileRotateAndTimeUpdate(const eServerLogType type)
	{
		if (_list_log_file_create_time[static_cast<int32_t>(type)] + _rotate_time < util::mirTime::GetTickMilliCount())
		{
			return true;
		}

		return false;
	}

	void CServerlogManager::ConsoleOutput(sServerlog* log)
	{
		switch (log->type)
		{
		case eServerLogType::eDebug:	
#ifdef _DEBUG
			std::cout << CONSOLE_COLOR_GREEN << log->text << CONSOLE_COLOR_RESET << std::endl;
#endif // _DEBUG
			break;
		case eServerLogType::eWarning:
			std::cout << CONSOLE_COLOR_RED << log->text << CONSOLE_COLOR_RESET << std::endl;
			break;
		case eServerLogType::eInfo:	
#ifdef _DEBUG
			std::cout << log->text << std::endl;
#endif // _DEBUG
			break;
		case eServerLogType::eFatal:
			std::cout << CONSOLE_COLOR_YELLOW << log->text << CONSOLE_COLOR_RESET << std::endl;
			break; 
		default: break;
		}
	}

	void OnMempoolAllocLogger(const char* creator, const int32_t& size)
	{
		SERVER_LOG(eServerLogType::eInfo, "CMemPool.Alloc() name : %s, size : %d", creator, size);
	}

}	// namespace mir3d