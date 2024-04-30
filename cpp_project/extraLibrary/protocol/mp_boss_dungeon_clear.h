#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_boss_dungeon_record.h"
#include "struct/mps_item_add.h"
#include "struct/mps_boss_dungeon_reward.h"

namespace mir3d
{
	class mp_boss_dungeon_clear_cs : public BasePacket 	// 보스던전 클리어 패킷 (indun_finish 와 다른정보임)
	{

	public:
		mp_boss_dungeon_clear_cs() : BasePacket(mpe_cmd::boss_dungeon_clear_cs)
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

	class mp_boss_dungeon_clear_sc : public BasePacket 	// 보스던전 클리어 패킷 (indun_finish 와 다른정보임)
	{
	private:
		bool flag_record = false;
		mps_boss_dungeon_record record;	// 총 클리어 시간
		mps_boss_dungeon_record* p_record = nullptr;
	public:
		bool has_record() const
		{
			return flag_record;
		}
		mps_boss_dungeon_record* alloc_record()
		{
			flag_record = true;
			return &record;
		}
		const mps_boss_dungeon_record* get_record() const
		{
			if (true == flag_record)
			{
				if (nullptr == p_record)
				{
					return &record;
				}
				return p_record;
			}
			return nullptr;
		}
		void set_record(mps_boss_dungeon_record* in_record)
		{
			if (nullptr == p_record)
			{
				p_record = in_record;
				flag_record = true;
			}
		}
	private:
		bool flag_info = false;
		mps_item_add info;
		mps_item_add* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_add* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_add* get_info() const
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
		void set_info(mps_item_add* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		std::vector<mps_boss_dungeon_reward> reward_list{};	// UI표시용 reward list

	public:
		mp_boss_dungeon_clear_sc() : BasePacket(mpe_cmd::boss_dungeon_clear_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_record);
			if (true == flag_record)
			{
				if (nullptr != p_record)
					protocol::SerializeType(pBuffer, p_record);
				else
					protocol::SerializeType(pBuffer, &record);
			}
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &reward_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
