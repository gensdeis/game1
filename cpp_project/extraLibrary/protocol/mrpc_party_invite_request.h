#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_party_invite_request_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t puid{};
	public:
		int64_t cuid{};
	public:
		int64_t target_cuid{};

	public:
		mrpc_party_invite_request_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_invite_request_cs, tag)
		{
		}
		mrpc_party_invite_request_cs() : RpcPacket(mpe_rpc_cmd::party_invite_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_invite_request_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t puid{};
	public:
		int64_t target_cuid{};
	public:
		std::string owner_name{};
	public:
		int64_t owner_cuid{};
	public:
		int32_t category{};

	public:
		mrpc_party_invite_request_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_invite_request_sc, tag)
		{
		}
		mrpc_party_invite_request_sc() : RpcPacket(mpe_rpc_cmd::party_invite_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &owner_name);
			protocol::SerializeType(pBuffer, &owner_cuid);
			protocol::SerializeType(pBuffer, &category);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
