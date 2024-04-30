#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_gm_occupationwar_darksteelstorage_set_cs : public WebBasePacket 
	{
	public:
		mpe_occupationwar_map_type type{};
	public:
		int64_t darksteel{};
	public:
		int32_t set_type{};	// 1 - 지급, 2 - 차감

	public:
		mweb_gm_occupationwar_darksteelstorage_set_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &darksteel);
			protocol::SerializeType(pBuffer, &set_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_occupationwar_darksteelstorage_set_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_gm_occupationwar_darksteelstorage_set_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
