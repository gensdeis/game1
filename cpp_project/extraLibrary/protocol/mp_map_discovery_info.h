#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_map_discovery.h"

namespace mir3d
{
	class mp_map_discovery_info_cs : public BasePacket 
	{
	public:
		int32_t map_id{};

	public:
		mp_map_discovery_info_cs() : BasePacket(mpe_cmd::map_discovery_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &map_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_map_discovery_info_sc : public BasePacket 
	{
	public:
		std::vector<mps_map_discovery> area_info{};

	public:
		mp_map_discovery_info_sc() : BasePacket(mpe_cmd::map_discovery_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &area_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
