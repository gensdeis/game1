#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_community_character_level_info_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};

	public:
		mrpc_community_character_level_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_character_level_info_cs, tag)
		{
		}
		mrpc_community_character_level_info_cs() : RpcPacket(mpe_rpc_cmd::community_character_level_info_cs)
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

	class mrpc_community_character_level_info_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int32_t level{};

	public:
		mrpc_community_character_level_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_character_level_info_sc, tag)
		{
		}
		mrpc_community_character_level_info_sc() : RpcPacket(mpe_rpc_cmd::community_character_level_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
