#pragma once

namespace mir3d
{
	template <typename T> 
    class CConcurrentStack
	{
	public:
		CConcurrentStack() = default;
		~CConcurrentStack() = default;

    public:
        void Push(const T& item)
        {
			std::lock_guard<std::mutex> lock(_mutex);

			_stack.push(item);
        }

		bool Top(T& item)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			if (false == _stack.empty())
			{
				item = _stack.top();
				return true;
			}

			return false;
		}

		bool Pop(T& item)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			if (false == _stack.empty())
			{
				item = _stack.top();
				_stack.pop();
				return true;
			}

			return false;
		}

		size_t Size(void)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			return _stack.size();
		}

		bool Empty(void)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			return _stack.empty();
		}

    private:
		std::stack<T>		_stack;
        std::mutex		    _mutex;

	private:
		CConcurrentStack(const CConcurrentStack &) = delete;
		CConcurrentStack &operator=(const CConcurrentStack &) = delete;
		CConcurrentStack(CConcurrentStack&&) = delete;
		CConcurrentStack& operator=(CConcurrentStack&&) = delete;
	};

} // namespace mir3d
