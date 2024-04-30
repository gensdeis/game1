#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_logout_ai_service_cs : public RpcPacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t server_index{};
	public:
		int64_t login_time{};
	public:
		int64_t auto_battle_free_time{};
	public:
		int64_t auto_battle_pay_time{};
	public:
		int32_t accumulate_exp{};
	public:
		uint8_t subscription_id{};

	public:
		mrpc_logout_ai_service_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::logout_ai_service_cs, tag)
		{
		}
		mrpc_logout_ai_service_cs() : RpcPacket(mpe_rpc_cmd::logout_ai_service_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeType(pBuffer, &login_time);
			protocol::SerializeType(pBuffer, &auto_battle_free_time);
			protocol::SerializeType(pBuffer, &auto_battle_pay_time);
			protocol::SerializeType(pBuffer, &accumulate_exp);
			protocol::SerializeType(pBuffer, &subscription_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_logout_ai_service_sc : public RpcPacket 
	{

	public:
		mrpc_logout_ai_service_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::logout_ai_service_sc, tag)
		{
		}
		mrpc_logout_ai_service_sc() : RpcPacket(mpe_rpc_cmd::logout_ai_service_sc)
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

}
