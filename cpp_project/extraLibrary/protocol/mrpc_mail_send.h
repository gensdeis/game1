#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mail_item.h"

namespace mir3d
{
	class mrpc_mail_send_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t uid{};
	public:
		int64_t muid{};
	public:
		mpe_mail_type mail_type{};
	public:
		int32_t tid{};
	public:
		int32_t expir_date{};
	public:
		std::vector<mps_mail_item> info{};

	public:
		mrpc_mail_send_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mail_send_cs, tag)
		{
		}
		mrpc_mail_send_cs() : RpcPacket(mpe_rpc_cmd::mail_send_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &muid);
			protocol::SerializeEnum(pBuffer, &mail_type);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &expir_date);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_mail_send_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_mail_send_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mail_send_sc, tag)
		{
		}
		mrpc_mail_send_sc() : RpcPacket(mpe_rpc_cmd::mail_send_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
