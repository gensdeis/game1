﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_siege_warfare_alliance_kickout_cs : public RpcPacket 	// 공성연합 추방
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int64_t alliance_guid{};	// 연합추방 길드아이디
	public:
		mpe_siege_castle_type castle_type{};	// 성타입

	public:
		mrpc_siege_warfare_alliance_kickout_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_alliance_kickout_cs, tag)
		{
		}
		mrpc_siege_warfare_alliance_kickout_cs() : RpcPacket(mpe_rpc_cmd::siege_warfare_alliance_kickout_cs)
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

	class mrpc_siege_warfare_alliance_kickout_sc : public RpcPacket 	// 공성연합 추방
	{
	public:
		int64_t key{};
	public:
		mpe_siege_castle_type castle_type{};	// 성타입
	public:
		int64_t alliance_guid{};	// 연합추방 길드아이디
	public:
		std::string alliance_guild_name{};	// 연합추방 길드이름

	public:
		mrpc_siege_warfare_alliance_kickout_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_alliance_kickout_sc, tag)
		{
		}
		mrpc_siege_warfare_alliance_kickout_sc() : RpcPacket(mpe_rpc_cmd::siege_warfare_alliance_kickout_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &alliance_guid);
			protocol::SerializeType(pBuffer, &alliance_guild_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
