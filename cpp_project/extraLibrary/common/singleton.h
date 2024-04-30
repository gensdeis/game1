#pragma once

#include <cstdint>

namespace mir3d
{
	/*
	once_ ~ 를 쓰던지 해도 되지만.
	불편하지만.
	속도를 최우선으로 하자.
	Singleton으로 사용할 것들은 main() 에서 생성해서 사용하는 방식으로 하자.
	*/
	template <typename T> class CSingleton
	{
	private:
		static T* m_instance;

	public:
		static T& getInstance(void)		{ return *m_instance; }
		static T* getInstancePrt(void)  { return m_instance; }

	public:
		CSingleton()
		{
			int64_t offset = (int64_t)(T*)1 - (int64_t)(CSingleton <T>*)(T*)1;
			m_instance = (T*)((int64_t)this + offset);
		}

		~ CSingleton()
		{
			m_instance = nullptr;
		}

	private:
		CSingleton(const CSingleton &) = delete;
		CSingleton &operator=(const CSingleton &) = delete;
		CSingleton(CSingleton&&) = delete;
		CSingleton& operator=(CSingleton&&) = delete;
	};

	template <typename T> T* CSingleton <T>::m_instance = nullptr;

} // namespace mir3d
