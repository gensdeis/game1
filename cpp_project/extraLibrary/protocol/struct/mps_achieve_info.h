﻿#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_achieve_info 
	{
	public:
		int32_t gid{};
	public:
		int32_t index{};
	public:
		int32_t value{};

	public:
		mps_achieve_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}