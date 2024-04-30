#pragma once

namespace mir3d
{
	typedef void(*MempoolAllocLogger)(const char*, const int32_t&);

	template <typename T>
	class CMemPool
	{
	public:
		CMemPool(int32_t defaultSize, int32_t createSize, const std::string& creator, MempoolAllocLogger alloc_looger)
		{
			_createSize = createSize;
			_creator = creator;
			_alloc_logger = alloc_looger;

			Alloc(defaultSize, false);
		}

		virtual ~CMemPool()
		{
			for (size_t i = 0; i < _vector.size(); i++)
			{
				delete[] _vector[i];
			}
		}


	public:
		T* Pop(void)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			if (_queue.empty())
			{
				if (0 == _createSize)
				{
					return nullptr;
				}
				else
				{
					Alloc(_createSize);
				}
			}

			T* item = _queue.front();
			_queue.pop();

			return item;
		}

		virtual void Push(T* item)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			_queue.push(item);
		}

		bool Empty(void)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			return _queue.empty();
		}

		size_t Size(void)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			return _queue.size();
		}

	private :
		void Alloc(const int32_t& size, const bool& print_log = true)
		{
			T* buffer = new T[size];

			_vector.push_back(buffer);

			for (int32_t i = 0; i < size; i++)
			{
				_queue.push(&(buffer[i]));
			}

			_poolSize += size;

			if (print_log)
			{
				if (nullptr != _alloc_logger)
				{
					_alloc_logger(_creator.c_str(), _poolSize);
				}
			}
		}

	private:
		std::mutex					_mutex;
		std::vector<T*>				_vector;
		std::queue<T*>				_queue;

		int32_t						_createSize;
		std::string					_creator;

		int32_t						_poolSize = 0;

		MempoolAllocLogger			_alloc_logger = nullptr;

	private:
		CMemPool() = delete;
		CMemPool(const CMemPool &) = delete;
		CMemPool &operator=(const CMemPool &) = delete;
		CMemPool(CMemPool&&) = delete;
		CMemPool& operator=(CMemPool&&) = delete;
	};
} // namespace mir3d
