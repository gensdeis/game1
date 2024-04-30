#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_dungeon_info.h"

namespace mir3d
{
	class mrpc_guild_alert_dungeon_info_cs : public RpcPacket 	// 던전생성알림
	{

	public:
		mrpc_guild_alert_dungeon_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_dungeon_info_cs, tag)
		{
		}
		mrpc_guild_alert_dungeon_info_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_dungeon_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_alert_dungeon_info_sc : public RpcPacket 	// 던전생성알림
	{
	public:
		std::vector<int64_t> list_cuid{};	// 대상목록
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
		mrpc_guild_alert_dungeon_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_dungeon_info_sc, tag)
		{
		}
		mrpc_guild_alert_dungeon_info_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_dungeon_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
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
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
