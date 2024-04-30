#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_table_load_cs : public WebBasePacket 
	{
	public:
		int32_t load_index{};

	public:
		mweb_table_load_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &load_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_table_load_sc : public WebBasePacket 
	{
	public:
		int64_t uid{};
	public:
		int32_t total_index{};
	public:
		int32_t data_size{};
	public:
		int32_t load_index{};
	public:
		std::vector<uint8_t> data{};

	public:
		mweb_table_load_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &total_index);
			protocol::SerializeType(pBuffer, &data_size);
			protocol::SerializeType(pBuffer, &load_index);
			protocol::SerializeType(pBuffer, &data);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
