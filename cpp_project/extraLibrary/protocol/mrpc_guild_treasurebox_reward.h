#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_guild_treasurebox_reward_item.h"

namespace mir3d
{
	class mrpc_guild_treasurebox_reward_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t treasure_box_id{};
	private:
		bool flag_add_item = false;
		mps_item_add add_item;
		mps_item_add* p_add_item = nullptr;
	public:
		bool has_add_item() const
		{
			return flag_add_item;
		}
		mps_item_add* alloc_add_item()
		{
			flag_add_item = true;
			return &add_item;
		}
		const mps_item_add* get_add_item() const
		{
			if (true == flag_add_item)
			{
				if (nullptr == p_add_item)
				{
					return &add_item;
				}
				return p_add_item;
			}
			return nullptr;
		}
		void set_add_item(mps_item_add* in_add_item)
		{
			if (nullptr == p_add_item)
			{
				p_add_item = in_add_item;
				flag_add_item = true;
			}
		}
	public:
		uint8_t reward_type{};	// table::GETREWARD

	public:
		mrpc_guild_treasurebox_reward_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_treasurebox_reward_cs, tag)
		{
		}
		mrpc_guild_treasurebox_reward_cs() : RpcPacket(mpe_rpc_cmd::guild_treasurebox_reward_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &treasure_box_id);
			protocol::SerializeType(pBuffer, &flag_add_item);
			if (true == flag_add_item)
			{
				if (nullptr != p_add_item)
					protocol::SerializeType(pBuffer, p_add_item);
				else
					protocol::SerializeType(pBuffer, &add_item);
			}
			protocol::SerializeType(pBuffer, &reward_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_treasurebox_reward_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		uint8_t reward_type{};
	public:
		std::vector<mps_guild_treasurebox_reward_item> reward_item{};

	public:
		mrpc_guild_treasurebox_reward_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_treasurebox_reward_sc, tag)
		{
		}
		mrpc_guild_treasurebox_reward_sc() : RpcPacket(mpe_rpc_cmd::guild_treasurebox_reward_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &reward_type);
			protocol::SerializeType(pBuffer, &reward_item);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
