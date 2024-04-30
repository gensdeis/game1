#pragma once

namespace mir3d
{
	template <typename T> 
    class CConcurrentVector
	{
	public:
		CConcurrentVector() = default;
		~CConcurrentVector() = default;

    public:
        void Initialize(int32_t capacity)
        {
			_capacity = capacity;

			_vector.reserve(_capacity);

			for (int32_t i = _capacity - 1; i >= 0; i--)
			{
				_vector.push_back(nullptr);
				_stack.push(i);
			}
        }

        bool Insert(const T& item, int32_t& index)
        {
            std::lock_guard<std::mutex> lock(_mutex);

			if (not _stack.empty())
			{
				index = _stack.top();
				_stack.pop();

				_vector[index] = item;

				return true;
			}

			return false;
        }

		bool Get(T& item, const uint32_t index)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			if (_capacity > index)
			{
				item = _vector[index];
				_vector[index] = nullptr;

				_stack.push(index);

				return true;
			}

			return false;
		}

		void Release(const uint32_t index)
		{
			std::lock_guard<std::mutex> lock(_mutex);

			if (_capacity > index)
			{
				_stack.push(index);
			}
		}

    private:
		std::vector<T>				_vector;
		std::stack<int32_t>			_stack;
        std::mutex				    _mutex;
		
		uint32_t                    _capacity = 0;

	private:
		CConcurrentVector(const CConcurrentVector &) = delete;
		CConcurrentVector &operator=(const CConcurrentVector &) = delete;
		CConcurrentVector(CConcurrentVector&&) = delete;
		CConcurrentVector& operator=(CConcurrentVector&&) = delete;
	};

} // namespace mir3d
