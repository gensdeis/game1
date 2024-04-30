#pragma once

#if __UNREAL__
#include "UnrealMemory.h"
#endif

namespace mir3d
{
	namespace protocol
	{
		enum EndianMode { cEndianModeNative };

		template<typename T> inline  bool IsSigned()
		{
			return std::numeric_limits<T>::is_signed;
		}
		inline bool IsBigEndian() { int x = 1; return(*(uint8_t*)&x == 0); }
		inline bool IsLittleEndian() { int x = 1; return(*(uint8_t*)&x != 0); }
		////////////////////////////////////////////////////////////////////////
		// low-level packing/unpacking functions
		////////////////////////////////////////////////////////////////////////
		template < typename T> inline int Pack64(uint8_t *buffer, T value)
		{

#if __UNREAL__
			FMemory::Memcpy(buffer, &value,sizeof(T));
#else
			std::memcpy(buffer, &value, sizeof(T));

#endif
			return(8);
		}

		template < typename T> inline int Pack32(uint8_t *buffer, T value)
		{
#if __UNREAL__
			FMemory::Memcpy(buffer, &value, sizeof(T));
#else
			std::memcpy(buffer, &value, sizeof(T));
#endif
			return(4);
		}

		template < typename T> inline int Pack16(uint8_t *buffer, T value)
		{
#if __UNREAL__
			FMemory::Memcpy(buffer, &value, sizeof(T));
#else
			std::memcpy(buffer, &value, sizeof(T));
#endif
			return(2);
		}

		template < typename T> inline int Pack8(uint8_t *buffer, T value)
		{
#if __UNREAL__
			FMemory::Memcpy(buffer, &value, sizeof(T));
#else
			std::memcpy(buffer, &value, sizeof(T));
#endif
			return(1);
		}

		inline int PackBool(uint8_t *buffer, bool value)
		{
			*buffer = (uint8_t)value;
			return(1);
		}

		inline int PackFloat(uint8_t *buffer, float value)
		{
			uint32_t hold;
			memcpy(&hold, &value, 4);
			return(Pack32(buffer, hold));
		}

		inline int PackDouble(uint8_t *buffer, double value)
		{
			uint64_t hold;
			memcpy(&hold, &value, 8);
			return(Pack64(buffer, hold));
		}

		//////////////////////////////////////
		// unpack 
		//////////////////////////////////////
		inline int UnpackBool(const uint8_t *buffer, bool *value)
		{
#if __UNREAL__
			FMemory::Memcpy(value, buffer, 1);
#else
			//*value = (*buffer != 0);
			std::memcpy(value, buffer, 1);
#endif
			return(1);
		}

		template < typename T>
		inline int Unpack8(const uint8_t *buffer, T *value)
		{
#if __UNREAL__
			FMemory::Memcpy(value, buffer, sizeof(T));
#else
			std::memcpy(value, buffer, sizeof(T));
#endif
			return(1);
		}

		template < typename T> inline int Unpack16(const uint8_t *buffer, T *value)
		{
#if __UNREAL__
			FMemory::Memcpy(value, buffer, sizeof(T));
#else
			std::memcpy(value, buffer, sizeof(T));
#endif
			return(2);
		}

		template < typename T> inline int Unpack32(const uint8_t *buffer, T *value)
		{
#if __UNREAL__
			FMemory::Memcpy(value, buffer, sizeof(T));
#else
			std::memcpy(value, buffer, sizeof(T));
#endif
			return(4);
		}

		template < typename T> inline int Unpack64(const uint8_t *buffer, T *value)
		{

#if __UNREAL__

			FMemory::Memcpy(value, buffer, sizeof(T));
#else
			std::memcpy(value, buffer, sizeof(T));
#endif

			return(8);
		}

		inline int UnpackFloat(const uint8_t *buffer, float *value)
		{
#if __UNREAL__
			Unpack32(buffer, value);
#else
			Unpack32(buffer, (uint32_t*)value);
#endif
			return(4);
		}

		inline int UnpackFloat(const uint8_t *buffer, double *value)
		{
			float hold;
			UnpackFloat(buffer, &hold);
			*value = hold;
			return(4);
		}

		inline int UnpackDouble(const uint8_t *buffer, double *value)
		{
#if __UNREAL__
			Unpack64(buffer, value);
#else
			Unpack64(buffer, (uint64_t*)value);
#endif
			return(8);
		}

		inline int UnpackDouble(const uint8_t *buffer, float *value)
		{
			double hold;
			UnpackDouble(buffer, &hold);
			*value = (float)hold;
			return(8);
		}

	}  // namespace
}
