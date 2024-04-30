#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_seasonpass_challenge.h"

namespace mir3d
{
	class mrpc_seasonpass_challenge_update_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t season_tid{};
	public:
		std::vector<mps_seasonpass_challenge> list_challenge{};

	public:
		mrpc_seasonpass_challenge_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::seasonpass_challenge_update_cs, tag)
		{
		}
		mrpc_seasonpass_challenge_update_cs() : RpcPacket(mpe_rpc_cmd::seasonpass_challenge_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &season_tid);
			protocol::SerializeType(pBuffer, &list_challenge);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_seasonpass_challenge_update_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		uint16_t channel_id{};

	public:
		mrpc_seasonpass_challenge_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::seasonpass_challenge_update_sc, tag)
		{
		}
		mrpc_seasonpass_challenge_update_sc() : RpcPacket(mpe_rpc_cmd::seasonpass_challenge_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &channel_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
