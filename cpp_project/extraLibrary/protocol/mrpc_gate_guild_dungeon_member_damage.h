#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_dungeon_member_damage_info.h"

namespace mir3d
{
	class mrpc_gate_guild_dungeon_member_damage_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t guid{};

	public:
		mrpc_gate_guild_dungeon_member_damage_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_guild_dungeon_member_damage_cs, tag)
		{
		}
		mrpc_gate_guild_dungeon_member_damage_cs() : RpcPacket(mpe_rpc_cmd::gate_guild_dungeon_member_damage_cs)
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

	class mrpc_gate_guild_dungeon_member_damage_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_info = false;
		mps_guild_dungeon_member_damage_info info;
		mps_guild_dungeon_member_damage_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_guild_dungeon_member_damage_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_guild_dungeon_member_damage_info* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mps_guild_dungeon_member_damage_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_gate_guild_dungeon_member_damage_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_guild_dungeon_member_damage_sc, tag)
		{
		}
		mrpc_gate_guild_dungeon_member_damage_sc() : RpcPacket(mpe_rpc_cmd::gate_guild_dungeon_member_damage_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
