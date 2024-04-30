#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_reward_info.h"

namespace mir3d
{
	class mrpc_npc_intimacy_reward_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t npc_id{};
	public:
		int32_t reward{};	// 정보 요청:-1
	private:
		bool flag_item_add = false;
		mps_item_add item_add;
		mps_item_add* p_item_add = nullptr;
	public:
		bool has_item_add() const
		{
			return flag_item_add;
		}
		mps_item_add* alloc_item_add()
		{
			flag_item_add = true;
			return &item_add;
		}
		const mps_item_add* get_item_add() const
		{
			if (true == flag_item_add)
			{
				if (nullptr == p_item_add)
				{
					return &item_add;
				}
				return p_item_add;
			}
			return nullptr;
		}
		void set_item_add(mps_item_add* in_item_add)
		{
			if (nullptr == p_item_add)
			{
				p_item_add = in_item_add;
				flag_item_add = true;
			}
		}

	public:
		mrpc_npc_intimacy_reward_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::npc_intimacy_reward_cs, tag)
		{
		}
		mrpc_npc_intimacy_reward_cs() : RpcPacket(mpe_rpc_cmd::npc_intimacy_reward_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &npc_id);
			protocol::SerializeType(pBuffer, &reward);
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_npc_intimacy_reward_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t npc_id{};
	public:
		std::vector<mps_reward_info> list_reward{};

	public:
		mrpc_npc_intimacy_reward_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::npc_intimacy_reward_sc, tag)
		{
		}
		mrpc_npc_intimacy_reward_sc() : RpcPacket(mpe_rpc_cmd::npc_intimacy_reward_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &npc_id);
			protocol::SerializeType(pBuffer, &list_reward);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
