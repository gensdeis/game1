#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_advertisement_exp_restore_cs : public RpcPacket 	// board->game sc요청
	{

	public:
		mrpc_advertisement_exp_restore_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::advertisement_exp_restore_cs, tag)
		{
		}
		mrpc_advertisement_exp_restore_cs() : RpcPacket(mpe_rpc_cmd::advertisement_exp_restore_cs)
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

	class mrpc_advertisement_exp_restore_sc : public RpcPacket 	// board->game sc요청
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		uint16_t revive_id{};

	public:
		mrpc_advertisement_exp_restore_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::advertisement_exp_restore_sc, tag)
		{
		}
		mrpc_advertisement_exp_restore_sc() : RpcPacket(mpe_rpc_cmd::advertisement_exp_restore_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &revive_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
