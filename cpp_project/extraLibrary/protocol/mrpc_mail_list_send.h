#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_mail.h"

namespace mir3d
{
	class mrpc_mail_list_send_cs : public RpcPacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::vector<mrpcs_mail> info{};

	public:
		mrpc_mail_list_send_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mail_list_send_cs, tag)
		{
		}
		mrpc_mail_list_send_cs() : RpcPacket(mpe_rpc_cmd::mail_list_send_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_mail_list_send_sc : public RpcPacket 
	{

	public:
		mrpc_mail_list_send_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mail_list_send_sc, tag)
		{
		}
		mrpc_mail_list_send_sc() : RpcPacket(mpe_rpc_cmd::mail_list_send_sc)
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
