#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_alert_change_master_cs : public RpcPacket 	// // 문주 변경 알림 패킷
	{

	public:
		mrpc_guild_alert_change_master_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_change_master_cs, tag)
		{
		}
		mrpc_guild_alert_change_master_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_change_master_cs)
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

	class mrpc_guild_alert_change_master_sc : public RpcPacket 	// // 문주 변경 알림 패킷
	{
	public:
		std::vector<int64_t> list_cuid{};	// // 패킷받아야할 대상
	public:
		int64_t old_master_cuid{};	// // 이전 문주 ID
	public:
		std::string old_master_name{};	// // 이전 문주명
	public:
		mpe_guild_member_grade old_master_new_grade{};	// // 이전 문주의 변경된 계급
	public:
		int64_t new_master_cuid{};	// // 새 문주 ID
	public:
		std::string new_master_name{};	// // 새 문주명

	public:
		mrpc_guild_alert_change_master_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_change_master_sc, tag)
		{
		}
		mrpc_guild_alert_change_master_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_change_master_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &old_master_cuid);
			protocol::SerializeType(pBuffer, &old_master_name);
			protocol::SerializeEnum(pBuffer, &old_master_new_grade);
			protocol::SerializeType(pBuffer, &new_master_cuid);
			protocol::SerializeType(pBuffer, &new_master_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
