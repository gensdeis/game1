#pragma once

#include <boost/lockfree/queue.hpp>

namespace mir3d
{
	template <typename T> 
    class CConcurrentQueue
	{
	public:
		CConcurrentQueue() = default;
		~CConcurrentQueue() = default;

    public:
		size_t Push(const T& item)
        {
			std::lock_guard<std::mutex> lock(_mutex);

			_queue.push(item);
			
			return _queue.size();
        }

		bool Front(T& item)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			if (false == _queue.empty())
			{
				item = _queue.front();
				return true;
			}

			return false;
		}

		size_t FrontErase(void)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			if (false == _queue.empty())
			{
				_queue.pop();
			}

			return _queue.size();
		}

		bool Pop(T& item)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			if (false == _queue.empty())
			{
				item = _queue.front();
				_queue.pop();
				return true;
			}

			return false;
		}

		size_t Size(bool is_lock)
		{
			if(true == is_lock)
				std::lock_guard<std::mutex> lock(_mutex);

			return _queue.size();
		}

		bool IsEmpty(bool is_lock)
		{
			if (true == is_lock)
				std::lock_guard<std::mutex> lock(_mutex);
			
			return _queue.empty();
		}

		void Move(std::queue<T>& queue)
		{
			std::lock_guard<std::mutex> lock(_mutex);
			
			while (false == _queue.empty())
			{
				queue.push(_queue.front());
				_queue.pop();
			}
		}

		size_t PushNoLock(const T& item)
		{
			_queue.push(item);

			return _queue.size();
		}

		bool PopNoLock(T& item)
		{
			if (false == _queue.empty())
			{
				item = _queue.front();
				_queue.pop();
				return true;
			}

			return false;
		}

		
    private:
		std::queue<T>		_queue;
        std::mutex		    _mutex;

	private:
		CConcurrentQueue(const CConcurrentQueue &) = delete;
		CConcurrentQueue &operator=(const CConcurrentQueue &) = delete;
		CConcurrentQueue(CConcurrentQueue&&) = delete;
		CConcurrentQueue& operator=(CConcurrentQueue&&) = delete;
	};


	template <typename T>
	class CConcurrentQueueLockFree
	{
	public:
		CConcurrentQueueLockFree() :_queue(2048) {}
		~CConcurrentQueueLockFree() = default;

	public:
		bool Push(T const& item)
		{
			return _queue.push(item);
		}

		bool Pop(T& item)
		{
			if (false == _queue.empty())
			{
				return _queue.pop(item);
			}

			return false;
		}

		bool IsEmpty(void)
		{
			return _queue.empty();
		}

	private:
		boost::lockfree::queue<T> _queue;

	private:
		CConcurrentQueueLockFree(const CConcurrentQueueLockFree&) = delete;
		CConcurrentQueueLockFree& operator=(const CConcurrentQueueLockFree&) = delete;
		CConcurrentQueueLockFree(CConcurrentQueueLockFree&&) = delete;
		CConcurrentQueueLockFree& operator=(CConcurrentQueueLockFree&&) = delete;
	};

} // namespace mir3d
