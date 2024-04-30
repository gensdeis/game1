#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_dictionary_reward_get_cs : public BasePacket 
	{
	public:
		int32_t collection_id{};
	public:
		int32_t pos{};

	public:
		mp_dictionary_reward_get_cs() : BasePacket(mpe_cmd::dictionary_reward_get_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &collection_id);
			protocol::SerializeType(pBuffer, &pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_dictionary_reward_get_sc : public BasePacket 
	{
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
		mp_dictionary_reward_get_sc() : BasePacket(mpe_cmd::dictionary_reward_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_reward);
			if (true == flag_reward)
			{
				if (nullptr != p_reward)
					protocol::SerializeType(pBuffer, p_reward);
				else
					protocol::SerializeType(pBuffer, &reward);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
