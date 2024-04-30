#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_shipwar_match_complete_cs : public RpcPacket 	// 문파대전완료
	{
	public:
		bool schedule_match{};

	public:
		mrpc_guild_shipwar_match_complete_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_shipwar_match_complete_cs, tag)
		{
		}
		mrpc_guild_shipwar_match_complete_cs() : RpcPacket(mpe_rpc_cmd::guild_shipwar_match_complete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &schedule_match);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_shipwar_match_complete_sc : public RpcPacket 	// 문파대전완료
	{
	public:
		mpe_guild_shipwar_state state{};
	public:
		bool schedule_match{};

	public:
		mrpc_guild_shipwar_match_complete_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_shipwar_match_complete_sc, tag)
		{
		}
		mrpc_guild_shipwar_match_complete_sc() : RpcPacket(mpe_rpc_cmd::guild_shipwar_match_complete_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &schedule_match);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
