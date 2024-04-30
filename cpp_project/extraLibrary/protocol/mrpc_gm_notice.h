#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_notice_cs : public RpcPacket 
	{
	public:
		mrpce_gm_notice_type type{};

	public:
		mrpc_gm_notice_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_notice_cs, tag)
		{
		}
		mrpc_gm_notice_cs() : RpcPacket(mpe_rpc_cmd::gm_notice_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_notice_sc : public RpcPacket 
	{
	public:
		mpe_error result{};
	public:
		mrpce_gm_notice_type type{};

	public:
		mrpc_gm_notice_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_notice_sc, tag)
		{
		}
		mrpc_gm_notice_sc() : RpcPacket(mpe_rpc_cmd::gm_notice_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
