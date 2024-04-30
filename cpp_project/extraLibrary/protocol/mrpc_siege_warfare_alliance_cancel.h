﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_siege_warfare_alliance_cancel_cs : public RpcPacket 	// 공성 연합 신청 취소
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int64_t alliance_guid{};	// 연합취소 길드아이디
	public:
		mpe_siege_castle_type castle_type{};	// 성타입

	public:
		mrpc_siege_warfare_alliance_cancel_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_alliance_cancel_cs, tag)
		{
		}
		mrpc_siege_warfare_alliance_cancel_cs() : RpcPacket(mpe_rpc_cmd::siege_warfare_alliance_cancel_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &alliance_guid);
			protocol::SerializeEnum(pBuffer, &castle_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_siege_warfare_alliance_cancel_sc : public RpcPacket 	// 공성 연합 신청 취소
	{
	public:
		int64_t key{};
	public:
		mpe_siege_castle_type castle_type{};	// 성타입
	public:
		int64_t alliance_guid{};	// 연합취소 길드아이디

	public:
		mrpc_siege_warfare_alliance_cancel_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_alliance_cancel_sc, tag)
		{
		}
		mrpc_siege_warfare_alliance_cancel_sc() : RpcPacket(mpe_rpc_cmd::siege_warfare_alliance_cancel_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &alliance_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}