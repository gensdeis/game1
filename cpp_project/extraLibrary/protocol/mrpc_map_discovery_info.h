#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_map_discovery.h"

namespace mir3d
{
	class mrpc_map_discovery_info_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t map_id{};

	public:
		mrpc_map_discovery_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::map_discovery_info_cs, tag)
		{
		}
		mrpc_map_discovery_info_cs() : RpcPacket(mpe_rpc_cmd::map_discovery_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &map_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_map_discovery_info_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_map_discovery> map_discovery_info{};

	public:
		mrpc_map_discovery_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::map_discovery_info_sc, tag)
		{
		}
		mrpc_map_discovery_info_sc() : RpcPacket(mpe_rpc_cmd::map_discovery_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &map_discovery_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
