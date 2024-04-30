#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_title.h"

namespace mir3d
{
	class mrpc_gm_add_title_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_title> list_title{};

	public:
		mrpc_gm_add_title_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_add_title_cs, tag)
		{
		}
		mrpc_gm_add_title_cs() : RpcPacket(mpe_rpc_cmd::gm_add_title_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &list_title);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_add_title_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gm_add_title_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_add_title_sc, tag)
		{
		}
		mrpc_gm_add_title_sc() : RpcPacket(mpe_rpc_cmd::gm_add_title_sc)
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
