#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_profesion.h"

namespace mir3d
{
	class mp_quest_finish_cs : public BasePacket 
	{
	public:
		uint16_t id{};

	public:
		mp_quest_finish_cs() : BasePacket(mpe_cmd::quest_finish_cs)
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

	class mp_quest_finish_sc : public BasePacket 
	{
	public:
		std::vector<uint16_t> list_quest_id{};
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
		int32_t repute_quest_finish_count{};
	public:
		int32_t area_quest_finish_count{};
	public:
		uint8_t reward_index{};
	public:
		int32_t reward_count{};
	public:
		int32_t reward_id{};
	private:
		bool flag_profesion = false;
		mps_profesion profesion;	// 승급 퀘스트 보상
		mps_profesion* p_profesion = nullptr;
	public:
		bool has_profesion() const
		{
			return flag_profesion;
		}
		mps_profesion* alloc_profesion()
		{
			flag_profesion = true;
			return &profesion;
		}
		const mps_profesion* get_profesion() const
		{
			if (true == flag_profesion)
			{
				if (nullptr == p_profesion)
				{
					return &profesion;
				}
				return p_profesion;
			}
			return nullptr;
		}
		void set_profesion(mps_profesion* in_profesion)
		{
			if (nullptr == p_profesion)
			{
				p_profesion = in_profesion;
				flag_profesion = true;
			}
		}

	public:
		mp_quest_finish_sc() : BasePacket(mpe_cmd::quest_finish_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_quest_id);
			protocol::SerializeType(pBuffer, &weight);
			protocol::SerializeType(pBuffer, &flag_reward);
			if (true == flag_reward)
			{
				if (nullptr != p_reward)
					protocol::SerializeType(pBuffer, p_reward);
				else
					protocol::SerializeType(pBuffer, &reward);
			}
			protocol::SerializeType(pBuffer, &repute_quest_finish_count);
			protocol::SerializeType(pBuffer, &area_quest_finish_count);
			protocol::SerializeType(pBuffer, &reward_index);
			protocol::SerializeType(pBuffer, &reward_count);
			protocol::SerializeType(pBuffer, &reward_id);
			protocol::SerializeType(pBuffer, &flag_profesion);
			if (true == flag_profesion)
			{
				if (nullptr != p_profesion)
					protocol::SerializeType(pBuffer, p_profesion);
				else
					protocol::SerializeType(pBuffer, &profesion);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
