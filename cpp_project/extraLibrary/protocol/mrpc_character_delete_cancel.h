#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_character_delete_cancel_cs : public RpcPacket 	// 캐릭터삭제취소
	{
	public:
		int64_t cuid{};

	public:
		mrpc_character_delete_cancel_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_delete_cancel_cs, tag)
		{
		}
		mrpc_character_delete_cancel_cs() : RpcPacket(mpe_rpc_cmd::character_delete_cancel_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_character_delete_cancel_sc : public RpcPacket 	// 캐릭터삭제취소
	{

	public:
		mrpc_character_delete_cancel_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_delete_cancel_sc, tag)
		{
		}
		mrpc_character_delete_cancel_sc() : RpcPacket(mpe_rpc_cmd::character_delete_cancel_sc)
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
