#pragma once

#include <common/serverLogManager.h>

namespace mir3d
{
	// 특수 용도에 마추어 만든 클래스 이다. 
	// 반드시 Reserve() 를 하고 사용하는 용도로만 쓴다. 고정크기 배열
	template <typename T>	
	class mVector
	{
	public:
		mVector()
		{
			// resize(1);
		}

		~mVector()
		{
			SAFE_DELETE(_data);
		}

		void Reserve(const int32_t size)
		{
			reserve(size);
		}

		void Clear() 
		{
			// resize(1, true);
			Reset();
		}

		void Push_back(const T& val, const char* function)
		{
			if (_size == _capacity)
			{
				// _capacity *= 2;
				// resize(_capacity);
				SERVER_LOG(eServerLogType::eDebug, "vector size full. %d function : %s", _capacity, function);
				return;
			}

			_data[_size++] = val;
		}
		
		void Push_back(T&& val, const char* function)
		{
			if (_size == _capacity)
			{
				// _capacity *= 2;
				// resize(_capacity);
				SERVER_LOG(eServerLogType::eDebug, "vector size full. %d function : %s", _capacity, function);
				_is_full = true;
				return;
			}
			else
			{
				_is_full = false;
				_data[_size++] = val;// std::move(val);
			}
		}		

		void Erase(const int32_t& index, const char* function)
		{
			if (0 > index || _size <= index)
			{
				// error	
				SERVER_LOG(eServerLogType::eDebug, "index fail. size : %d, index : %d  function : %s", _size, index, function);
				throw std::out_of_range("index of vector is out of range.");
			}
			
			// _data[index] = _data[_size];

			if (true == _is_full)
			{
				SERVER_LOG(eServerLogType::eDebug, "erase. size : %d, index : %d  function : %s", _size, index, function);
			}

			_size--;

			if (index < _size)
			{
				_data[index] = _data[_size];
				// _data[_size] = nullptr;
			}
		}

		void Reset()
		{
			_size = 0;
		}

		bool Move(mVector<T>* src_data)
		{
			int32_t copy_size = src_data->size();

			if (_size + copy_size > _capacity)
			{
				SERVER_LOG(eServerLogType::eDebug, "mVector::Move() size over. current size : %d, copy size : %d, _capacity : %d", _size, copy_size, _capacity);
				// throw std::out_of_range("mVector::Move() size over.");
				return false;
			}

			memcpy(&_data[_size], src_data->_data, sizeof(T) * copy_size);

			_size += copy_size;
			
			src_data->Reset();

			return true;
		}

	public:
		inline T& operator [] (const int32_t& index) const 
		{ 
			if (0 > index || _size <= index)
			{
				// error	
				SERVER_LOG(eServerLogType::eWarning, "index fail. size : %d, index : %d", _size, index);
				throw std::out_of_range("index of vector is out of range.");
			}
			
			return _data[index];
		}

		inline int32_t	size()		const		{ return _size; }
		inline int32_t	capacity()	const		{ return _capacity; }
		inline bool		empty()		const		{ return !_size; }

	private:
		void reserve(int32_t size)
		{
			_data = new T[size];
			_size = 0;
			_capacity = size;
		}

	private:
		T*		_data = nullptr;			// 저장소
		int32_t _capacity = 0;				// 저장소 크기
		int32_t _size = 0;					// 보관 개수
		bool	_is_full = false;			//full 체크

	private:		
		mVector(const mVector &) = delete;
		mVector& operator=(const mVector &) = delete;
		mVector(mVector&&) = delete;
		mVector& operator=(mVector&&) = delete;
	};

}	// namespace mir3d
