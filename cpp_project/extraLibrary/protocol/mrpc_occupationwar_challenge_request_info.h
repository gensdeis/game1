﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_occupationwar_challenge_request_info_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};

	public:
		mrpc_occupationwar_challenge_request_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::occupationwar_challenge_request_info_cs, tag)
		{
		}
		mrpc_occupationwar_challenge_request_info_cs() : RpcPacket(mpe_rpc_cmd::occupationwar_challenge_request_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_occupationwar_challenge_request_info_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		mpe_error result{};
	public:
		mpe_occupationwar_map_type map_type{};	// 비곡종류

	public:
		mrpc_occupationwar_challenge_request_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::occupationwar_challenge_request_info_sc, tag)
		{
		}
		mrpc_occupationwar_challenge_request_info_sc() : RpcPacket(mpe_rpc_cmd::occupationwar_challenge_request_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeEnum(pBuffer, &map_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}