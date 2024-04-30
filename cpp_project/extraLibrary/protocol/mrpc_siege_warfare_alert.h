#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_siege_warfare_info_for_indun.h"

namespace mir3d
{
	class mrpc_siege_warfare_alert_cs : public RpcPacket 	// 공성전 정보 알림
	{
	public:
		mpe_siege_castle_type castle_type{};
	private:
		bool flag_info = false;
		mrpcs_siege_warfare_info_for_indun info;
		mrpcs_siege_warfare_info_for_indun* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_siege_warfare_info_for_indun* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_siege_warfare_info_for_indun* get_info() const
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
		void set_info(mrpcs_siege_warfare_info_for_indun* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_siege_warfare_alert_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_alert_cs, tag)
		{
		}
		mrpc_siege_warfare_alert_cs() : RpcPacket(mpe_rpc_cmd::siege_warfare_alert_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &castle_type);
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

	class mrpc_siege_warfare_alert_sc : public RpcPacket 	// 공성전 정보 알림
	{
	public:
		int64_t target_cuid{};	// 보낼유저아이디
	public:
		int64_t target_guid{};	// 보낼유저의길드
	public:
		int64_t alert_guid{};	// 보낸길드
	public:
		std::string alert_guild_name{};	// 보낸길드이름
	public:
		mpe_siege_alert_type alert_type{};	// 알림 타입

	public:
		mrpc_siege_warfare_alert_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_alert_sc, tag)
		{
		}
		mrpc_siege_warfare_alert_sc() : RpcPacket(mpe_rpc_cmd::siege_warfare_alert_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &target_guid);
			protocol::SerializeType(pBuffer, &alert_guid);
			protocol::SerializeType(pBuffer, &alert_guild_name);
			protocol::SerializeEnum(pBuffer, &alert_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
