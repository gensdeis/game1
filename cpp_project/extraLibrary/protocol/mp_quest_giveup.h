#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_quest_giveup_cs : public BasePacket 
	{
	public:
		uint16_t id{};

	public:
		mp_quest_giveup_cs() : BasePacket(mpe_cmd::quest_giveup_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_quest_giveup_sc : public BasePacket 
	{
	public:
		uint16_t id{};
	public:
		float weight{};
	private:
		bool flag_reward = false;
		mps_item_add reward;	// 수정 체크 필요
		mps_item_add* p_reward = nullptr;
	public:
		bool has_reward() const
		{
			return flag_reward;
		}
		mps_item_add* alloc_reward()
		{
			flag_reward = true;
			return &reward;
		}
		const mps_item_add* get_reward() const
		{
			if (true == flag_reward)
			{
				if (nullptr == p_reward)
				{
					return &reward;
				}
				return p_reward;
			}
			return nullptr;
		}
		void set_reward(mps_item_add* in_reward)
		{
			if (nullptr == p_reward)
			{
				p_reward = in_reward;
				flag_reward = true;
			}
		}
	public:
		int32_t repute_quest_index{};
	public:
		uint16_t repute_quest_id{};

	public:
		mp_quest_giveup_sc() : BasePacket(mpe_cmd::quest_giveup_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &weight);
			protocol::SerializeType(pBuffer, &flag_reward);
			if (true == flag_reward)
			{
				if (nullptr != p_reward)
					protocol::SerializeType(pBuffer, p_reward);
				else
					protocol::SerializeType(pBuffer, &reward);
			}
			protocol::SerializeType(pBuffer, &repute_quest_index);
			protocol::SerializeType(pBuffer, &repute_quest_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
