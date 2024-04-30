#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_member_base.h"

namespace mir3d
{
	class mrpc_party_enter_requestors_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t puid{};

	public:
		mrpc_party_enter_requestors_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_enter_requestors_cs, tag)
		{
		}
		mrpc_party_enter_requestors_cs() : RpcPacket(mpe_rpc_cmd::party_enter_requestors_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &puid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_enter_requestors_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_party_member_base> member_list{};

	public:
		mrpc_party_enter_requestors_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_enter_requestors_sc, tag)
		{
		}
		mrpc_party_enter_requestors_sc() : RpcPacket(mpe_rpc_cmd::party_enter_requestors_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &member_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
