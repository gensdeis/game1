#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_master_order_quest.h"

namespace mir3d
{
	class mp_guild_alert_register_master_order_quest_cs : public BasePacket 
	{

	public:
		mp_guild_alert_register_master_order_quest_cs() : BasePacket(mpe_cmd::guild_alert_register_master_order_quest_cs)
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

	class mp_guild_alert_register_master_order_quest_sc : public BasePacket 
	{
	private:
		bool flag_quest = false;
		mps_guild_master_order_quest quest;
		mps_guild_master_order_quest* p_quest = nullptr;
	public:
		bool has_quest() const
		{
			return flag_quest;
		}
		mps_guild_master_order_quest* alloc_quest()
		{
			flag_quest = true;
			return &quest;
		}
		const mps_guild_master_order_quest* get_quest() const
		{
			if (true == flag_quest)
			{
				if (nullptr == p_quest)
				{
					return &quest;
				}
				return p_quest;
			}
			return nullptr;
		}
		void set_quest(mps_guild_master_order_quest* in_quest)
		{
			if (nullptr == p_quest)
			{
				p_quest = in_quest;
				flag_quest = true;
			}
		}

	public:
		mp_guild_alert_register_master_order_quest_sc() : BasePacket(mpe_cmd::guild_alert_register_master_order_quest_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_quest);
			if (true == flag_quest)
			{
				if (nullptr != p_quest)
					protocol::SerializeType(pBuffer, p_quest);
				else
					protocol::SerializeType(pBuffer, &quest);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
