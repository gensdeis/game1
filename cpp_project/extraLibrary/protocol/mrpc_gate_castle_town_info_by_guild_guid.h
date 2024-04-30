#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_town_info_with_guild.h"

namespace mir3d
{
	class mrpc_gate_castle_town_info_by_guild_guid_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t guid{};

	public:
		mrpc_gate_castle_town_info_by_guild_guid_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_castle_town_info_by_guild_guid_cs, tag)
		{
		}
		mrpc_gate_castle_town_info_by_guild_guid_cs() : RpcPacket(mpe_rpc_cmd::gate_castle_town_info_by_guild_guid_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_castle_town_info_by_guild_guid_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_castle_town_info_with_guild> info{};
	public:
		bool exists_save_bag{};

	public:
		mrpc_gate_castle_town_info_by_guild_guid_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_castle_town_info_by_guild_guid_sc, tag)
		{
		}
		mrpc_gate_castle_town_info_by_guild_guid_sc() : RpcPacket(mpe_rpc_cmd::gate_castle_town_info_by_guild_guid_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &exists_save_bag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
