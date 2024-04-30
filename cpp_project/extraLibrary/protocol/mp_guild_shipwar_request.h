#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_shipwar_request_cs : public BasePacket 
	{
	public:
		bool isJoin{};	// true - 신청 / false - 신청취소

	public:
		mp_guild_shipwar_request_cs() : BasePacket(mpe_cmd::guild_shipwar_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &isJoin);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_shipwar_request_sc : public BasePacket 
	{
	public:
		mpe_guild_shipwar_state state{};
	public:
		mpe_error result{};

	public:
		mp_guild_shipwar_request_sc() : BasePacket(mpe_cmd::guild_shipwar_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
