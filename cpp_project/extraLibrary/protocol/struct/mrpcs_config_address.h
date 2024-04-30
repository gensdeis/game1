﻿#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_config_address 
	{
	public:
		std::string ip{};
	public:
		int32_t port{};
	public:
		int32_t db{};

	public:
		mrpcs_config_address()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &ip);
			protocol::SerializeType(pBuffer, &port);
			protocol::SerializeType(pBuffer, &db);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}