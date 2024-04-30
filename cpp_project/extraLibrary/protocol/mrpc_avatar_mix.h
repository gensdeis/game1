#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_obtain_avatar.h"
#include "struct/mps_avatar.h"

namespace mir3d
{
	class mrpc_avatar_mix_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_obtain_avatar> reward_avatar{};
	public:
		std::vector<mps_avatar> use_avatar{};

	public:
		mrpc_avatar_mix_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::avatar_mix_cs, tag)
		{
		}
		mrpc_avatar_mix_cs() : RpcPacket(mpe_rpc_cmd::avatar_mix_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &reward_avatar);
			protocol::SerializeType(pBuffer, &use_avatar);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_avatar_mix_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_avatar_mix_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::avatar_mix_sc, tag)
		{
		}
		mrpc_avatar_mix_sc() : RpcPacket(mpe_rpc_cmd::avatar_mix_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
