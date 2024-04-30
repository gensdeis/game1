#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_pk_alert_record_remove_cs : public RpcPacket 	// 캐릭터삭제pk삭제
	{

	public:
		mrpc_pk_alert_record_remove_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pk_alert_record_remove_cs, tag)
		{
		}
		mrpc_pk_alert_record_remove_cs() : RpcPacket(mpe_rpc_cmd::pk_alert_record_remove_cs)
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

	class mrpc_pk_alert_record_remove_sc : public RpcPacket 	// 캐릭터삭제pk삭제
	{
	public:
		std::vector<int64_t> list_cuid{};	// 패킷받아야할 대상
	public:
		int64_t cuid{};	// 삭제대상

	public:
		mrpc_pk_alert_record_remove_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pk_alert_record_remove_sc, tag)
		{
		}
		mrpc_pk_alert_record_remove_sc() : RpcPacket(mpe_rpc_cmd::pk_alert_record_remove_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
