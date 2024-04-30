#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_dungeon_info.h"

namespace mir3d
{
	class mp_guild_alert_dungeon_info_cs : public BasePacket 	// 던전충전알림
	{

	public:
		mp_guild_alert_dungeon_info_cs() : BasePacket(mpe_cmd::guild_alert_dungeon_info_cs)
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

	class mp_guild_alert_dungeon_info_sc : public BasePacket 	// 던전충전알림
	{
	private:
		bool flag_info = false;
		mps_guild_dungeon_info info;	// 길드던전정보
		mps_guild_dungeon_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_guild_dungeon_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_guild_dungeon_info* get_info() const
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
		void set_info(mps_guild_dungeon_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_guild_alert_dungeon_info_sc() : BasePacket(mpe_cmd::guild_alert_dungeon_info_sc)
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
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
