#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_reward_info.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_npc_intimacy_reward_cs : public BasePacket 
	{
	public:
		int64_t npc_uid{};
	public:
		int32_t reward_index{};	// 정보요청 : -1 / 보상받을 인덱스

	public:
		mp_npc_intimacy_reward_cs() : BasePacket(mpe_cmd::npc_intimacy_reward_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &npc_uid);
			protocol::SerializeType(pBuffer, &reward_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_npc_intimacy_reward_sc : public BasePacket 
	{
	public:
		int64_t npc_uid{};
	private:
		bool flag_reward_info = false;
		mps_reward_info reward_info;
		mps_reward_info* p_reward_info = nullptr;
	public:
		bool has_reward_info() const
		{
			return flag_reward_info;
		}
		mps_reward_info* alloc_reward_info()
		{
			flag_reward_info = true;
			return &reward_info;
		}
		const mps_reward_info* get_reward_info() const
		{
			if (true == flag_reward_info)
			{
				if (nullptr == p_reward_info)
				{
					return &reward_info;
				}
				return p_reward_info;
			}
			return nullptr;
		}
		void set_reward_info(mps_reward_info* in_reward_info)
		{
			if (nullptr == p_reward_info)
			{
				p_reward_info = in_reward_info;
				flag_reward_info = true;
			}
		}
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
		mp_npc_intimacy_reward_sc() : BasePacket(mpe_cmd::npc_intimacy_reward_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &npc_uid);
			protocol::SerializeType(pBuffer, &flag_reward_info);
			if (true == flag_reward_info)
			{
				if (nullptr != p_reward_info)
					protocol::SerializeType(pBuffer, p_reward_info);
				else
					protocol::SerializeType(pBuffer, &reward_info);
			}
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
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
