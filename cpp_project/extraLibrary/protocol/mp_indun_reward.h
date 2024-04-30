#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_indun_reward_cs : public BasePacket 
	{

	public:
		mp_indun_reward_cs() : BasePacket(mpe_cmd::indun_reward_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_indun_reward_sc : public BasePacket 
	{
	public:
		float weight{};
	private:
		bool flag_reward = false;
		mps_item_add reward;
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
		int32_t add_score{};	// 점수보상

	public:
		mp_indun_reward_sc() : BasePacket(mpe_cmd::indun_reward_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &weight);
			protocol::SerializeType(pBuffer, &flag_reward);
			if (true == flag_reward)
			{
				if (nullptr != p_reward)
					protocol::SerializeType(pBuffer, p_reward);
				else
					protocol::SerializeType(pBuffer, &reward);
			}
			protocol::SerializeType(pBuffer, &add_score);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
