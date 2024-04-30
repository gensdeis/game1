﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_character_delete_friend_delete_cs : public RpcPacket 	// 캐릭터삭제친구삭제
	{
	public:
		std::vector<int64_t> list_friend_cuid{};
	public:
		int64_t delete_cuid{};

	public:
		mrpc_character_delete_friend_delete_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_delete_friend_delete_cs, tag)
		{
		}
		mrpc_character_delete_friend_delete_cs() : RpcPacket(mpe_rpc_cmd::character_delete_friend_delete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_friend_cuid);
			protocol::SerializeType(pBuffer, &delete_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_character_delete_friend_delete_sc : public RpcPacket 	// 캐릭터삭제친구삭제
	{

	public:
		mrpc_character_delete_friend_delete_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_delete_friend_delete_sc, tag)
		{
		}
		mrpc_character_delete_friend_delete_sc() : RpcPacket(mpe_rpc_cmd::character_delete_friend_delete_sc)
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