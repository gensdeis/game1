#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods_list.h"
#include "struct/mps_quest_reward.h"

namespace mir3d
{
	class mp_quest_reward_change_cs : public BasePacket 
	{
	public:
		uint16_t quest_id{};

	public:
		mp_quest_reward_change_cs() : BasePacket(mpe_cmd::quest_reward_change_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &quest_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_quest_reward_change_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_update_goods_list info;	// 변경된 재화
		mps_update_goods_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_update_goods_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_update_goods_list* get_info() const
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
		void set_info(mps_update_goods_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	private:
		bool flag_quest_reward = false;
		mps_quest_reward quest_reward;
		mps_quest_reward* p_quest_reward = nullptr;
	public:
		bool has_quest_reward() const
		{
			return flag_quest_reward;
		}
		mps_quest_reward* alloc_quest_reward()
		{
			flag_quest_reward = true;
			return &quest_reward;
		}
		const mps_quest_reward* get_quest_reward() const
		{
			if (true == flag_quest_reward)
			{
				if (nullptr == p_quest_reward)
				{
					return &quest_reward;
				}
				return p_quest_reward;
			}
			return nullptr;
		}
		void set_quest_reward(mps_quest_reward* in_quest_reward)
		{
			if (nullptr == p_quest_reward)
			{
				p_quest_reward = in_quest_reward;
				flag_quest_reward = true;
			}
		}

	public:
		mp_quest_reward_change_sc() : BasePacket(mpe_cmd::quest_reward_change_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_quest_reward);
			if (true == flag_quest_reward)
			{
				if (nullptr != p_quest_reward)
					protocol::SerializeType(pBuffer, p_quest_reward);
				else
					protocol::SerializeType(pBuffer, &quest_reward);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
