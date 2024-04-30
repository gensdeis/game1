#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_party_owner_change_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t puid{};
	public:
		int64_t target_cuid{};

	public:
		mrpc_party_owner_change_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_owner_change_cs, tag)
		{
		}
		mrpc_party_owner_change_cs() : RpcPacket(mpe_rpc_cmd::party_owner_change_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &target_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_owner_change_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t puid{};
	public:
		bool auto_start{};	// //파티던전거버넌스 때문에 추가.(클라요청)
	public:
		int32_t governance_rank{};	// 파티 거버넌스 랭킹

	public:
		mrpc_party_owner_change_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_owner_change_sc, tag)
		{
		}
		mrpc_party_owner_change_sc() : RpcPacket(mpe_rpc_cmd::party_owner_change_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &auto_start);
			protocol::SerializeType(pBuffer, &governance_rank);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
