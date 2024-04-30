﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_dropitem_delete_cs : public RpcPacket 	// 유저가 떨군 아이템이 필드에서 소멸시 itemtable 에서 삭제
	{
	public:
		std::vector<int64_t> iuid{};

	public:
		mrpc_dropitem_delete_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dropitem_delete_cs, tag)
		{
		}
		mrpc_dropitem_delete_cs() : RpcPacket(mpe_rpc_cmd::dropitem_delete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_dropitem_delete_sc : public RpcPacket 	// 유저가 떨군 아이템이 필드에서 소멸시 itemtable 에서 삭제
	{

	public:
		mrpc_dropitem_delete_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dropitem_delete_sc, tag)
		{
		}
		mrpc_dropitem_delete_sc() : RpcPacket(mpe_rpc_cmd::dropitem_delete_sc)
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