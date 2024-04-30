#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_siege_warfare_alliance_response_cs : public RpcPacket 	// 공성 연합 승인/거절
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int64_t request_guid{};	// 연합신청 길드아이디
	public:
		mpe_siege_castle_type castle_type{};	// 성타입
	public:
		bool accept{};	// 승인/거절

	public:
		mrpc_siege_warfare_alliance_response_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_alliance_response_cs, tag)
		{
		}
		mrpc_siege_warfare_alliance_response_cs() : RpcPacket(mpe_rpc_cmd::siege_warfare_alliance_response_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &request_guid);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &accept);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_siege_warfare_alliance_response_sc : public RpcPacket 	// 공성 연합 승인/거절
	{
	public:
		int64_t key{};
	public:
		mpe_siege_castle_type castle_type{};	// 성타입
	public:
		int64_t alliance_guid{};	// 연합취소 길드아이디
	public:
		bool accept{};	// 승인/거절

	public:
		mrpc_siege_warfare_alliance_response_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_alliance_response_sc, tag)
		{
		}
		mrpc_siege_warfare_alliance_response_sc() : RpcPacket(mpe_rpc_cmd::siege_warfare_alliance_response_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &alliance_guid);
			protocol::SerializeType(pBuffer, &accept);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
