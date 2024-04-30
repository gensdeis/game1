#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_guild_quest_reward_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		bool master_order_quest{};
	public:
		uint16_t quest_tid{};
	public:
		std::vector<int32_t> list_guild_reward_tid{};
	private:
		bool flag_member_reward = false;
		mps_item_add member_reward;
		mps_item_add* p_member_reward = nullptr;
	public:
		bool has_member_reward() const
		{
			return flag_member_reward;
		}
		mps_item_add* alloc_member_reward()
		{
			flag_member_reward = true;
			return &member_reward;
		}
		const mps_item_add* get_member_reward() const
		{
			if (true == flag_member_reward)
			{
				if (nullptr == p_member_reward)
				{
					return &member_reward;
				}
				return p_member_reward;
			}
			return nullptr;
		}
		void set_member_reward(mps_item_add* in_member_reward)
		{
			if (nullptr == p_member_reward)
			{
				p_member_reward = in_member_reward;
				flag_member_reward = true;
			}
		}

	public:
		mrpc_guild_quest_reward_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_quest_reward_cs, tag)
		{
		}
		mrpc_guild_quest_reward_cs() : RpcPacket(mpe_rpc_cmd::guild_quest_reward_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &master_order_quest);
			protocol::SerializeType(pBuffer, &quest_tid);
			protocol::SerializeType(pBuffer, &list_guild_reward_tid);
			protocol::SerializeType(pBuffer, &flag_member_reward);
			if (true == flag_member_reward)
			{
				if (nullptr != p_member_reward)
					protocol::SerializeType(pBuffer, p_member_reward);
				else
					protocol::SerializeType(pBuffer, &member_reward);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_quest_reward_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		bool master_order_quest{};
	public:
		uint16_t quest_tid{};
	private:
		bool flag_member_reward = false;
		mps_item_add member_reward;
		mps_item_add* p_member_reward = nullptr;
	public:
		bool has_member_reward() const
		{
			return flag_member_reward;
		}
		mps_item_add* alloc_member_reward()
		{
			flag_member_reward = true;
			return &member_reward;
		}
		const mps_item_add* get_member_reward() const
		{
			if (true == flag_member_reward)
			{
				if (nullptr == p_member_reward)
				{
					return &member_reward;
				}
				return p_member_reward;
			}
			return nullptr;
		}
		void set_member_reward(mps_item_add* in_member_reward)
		{
			if (nullptr == p_member_reward)
			{
				p_member_reward = in_member_reward;
				flag_member_reward = true;
			}
		}

	public:
		mrpc_guild_quest_reward_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_quest_reward_sc, tag)
		{
		}
		mrpc_guild_quest_reward_sc() : RpcPacket(mpe_rpc_cmd::guild_quest_reward_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &master_order_quest);
			protocol::SerializeType(pBuffer, &quest_tid);
			protocol::SerializeType(pBuffer, &flag_member_reward);
			if (true == flag_member_reward)
			{
				if (nullptr != p_member_reward)
					protocol::SerializeType(pBuffer, p_member_reward);
				else
					protocol::SerializeType(pBuffer, &member_reward);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
