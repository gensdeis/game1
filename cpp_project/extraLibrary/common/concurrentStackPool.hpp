#pragma once

#include <common/serverlogManager.h>

namespace mir3d
{
	template <typename T>
	class CStackPool
	{
	public:
		CStackPool(int32_t defaultSize, int32_t createSize, const std::string& creator)
		{
			_createSize = createSize;
			_creator = creator;

			Alloc(defaultSize);
		}

		virtual ~CStackPool()
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

			if (_stack.empty())
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

			T* item = _stack.top();
			_stack.pop();

			return item;
		}

		void Push(T* item)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			_stack.push(item);
		}

		bool Empty(void)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			return _stack.empty();
		}

		size_t Size(void)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			return _stack.size();
		}

	private:
		void Alloc(int32_t size)
		{
			T* buffer = new T[size];

			_vector.push_back(buffer);

			for (int32_t i = 0; i < size; i++)
			{
				_stack.push(&(buffer[i]));
			}

			_poolSize += size;

			SERVER_LOG(eServerLogType::eDebug, "CStackPool.Alloc() creator : %s, pool size : %d", _creator.c_str(), _poolSize);
		}

	private:
		std::mutex			     _mutex;
		std::vector<T*>          _vector;
		std::stack<T*>           _stack;

		int32_t                  _createSize;
		std::string              _creator;

		int32_t                  _poolSize = 0;

	private:
		CStackPool() = delete;
		CStackPool(const CStackPool&) = delete;
		CStackPool&operator=(const CStackPool&) = delete;
		CStackPool(CStackPool&&) = delete;
		CStackPool& operator=(CStackPool&&) = delete;
	};

} // namespace mir3d
