#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_member_look_info.h"

namespace mir3d
{
	class mrpc_siege_warfare_victory_character_info_cs : public RpcPacket 
	{
	public:
		int64_t guid{};
	public:
		int64_t cuid{};

	public:
		mrpc_siege_warfare_victory_character_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_victory_character_info_cs, tag)
		{
		}
		mrpc_siege_warfare_victory_character_info_cs() : RpcPacket(mpe_rpc_cmd::siege_warfare_victory_character_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_siege_warfare_victory_character_info_sc : public RpcPacket 
	{
	public:
		std::vector<mps_guild_member_look_info> guild_member_look_list{};
	public:
		int64_t guid{};
	public:
		int64_t cuid{};

	public:
		mrpc_siege_warfare_victory_character_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_victory_character_info_sc, tag)
		{
		}
		mrpc_siege_warfare_victory_character_info_sc() : RpcPacket(mpe_rpc_cmd::siege_warfare_victory_character_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guild_member_look_list);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
