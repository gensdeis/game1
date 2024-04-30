﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_mail_clean_cs : public RpcPacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mrpc_mail_clean_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mail_clean_cs, tag)
		{
		}
		mrpc_mail_clean_cs() : RpcPacket(mpe_rpc_cmd::mail_clean_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_mail_clean_sc : public RpcPacket 
	{

	public:
		mrpc_mail_clean_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mail_clean_sc, tag)
		{
		}
		mrpc_mail_clean_sc() : RpcPacket(mpe_rpc_cmd::mail_clean_sc)
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