#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_arena_battle_season_reward_cs : public BasePacket 
	{

	public:
		mp_arena_battle_season_reward_cs() : BasePacket(mpe_cmd::arena_battle_season_reward_cs)
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

	class mp_arena_battle_season_reward_sc : public BasePacket 
	{
	private:
		bool flag_season_reward_info = false;
		mps_item_add season_reward_info;
		mps_item_add* p_season_reward_info = nullptr;
	public:
		bool has_season_reward_info() const
		{
			return flag_season_reward_info;
		}
		mps_item_add* alloc_season_reward_info()
		{
			flag_season_reward_info = true;
			return &season_reward_info;
		}
		const mps_item_add* get_season_reward_info() const
		{
			if (true == flag_season_reward_info)
			{
				if (nullptr == p_season_reward_info)
				{
					return &season_reward_info;
				}
				return p_season_reward_info;
			}
			return nullptr;
		}
		void set_season_reward_info(mps_item_add* in_season_reward_info)
		{
			if (nullptr == p_season_reward_info)
			{
				p_season_reward_info = in_season_reward_info;
				flag_season_reward_info = true;
			}
		}

	public:
		mp_arena_battle_season_reward_sc() : BasePacket(mpe_cmd::arena_battle_season_reward_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_season_reward_info);
			if (true == flag_season_reward_info)
			{
				if (nullptr != p_season_reward_info)
					protocol::SerializeType(pBuffer, p_season_reward_info);
				else
					protocol::SerializeType(pBuffer, &season_reward_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
