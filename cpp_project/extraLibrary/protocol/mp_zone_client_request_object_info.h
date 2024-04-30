#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_zone_object_info.h"

namespace mir3d
{
	class mp_zone_client_request_object_info_cs : public BasePacket 
	{
	public:
		std::vector<int64_t> uid{};	// object uid

	public:
		mp_zone_client_request_object_info_cs() : BasePacket(mpe_cmd::zone_client_request_object_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_zone_client_request_object_info_sc : public BasePacket 
	{
	public:
		std::vector<mps_zone_object_info> object_info{};

	public:
		mp_zone_client_request_object_info_sc() : BasePacket(mpe_cmd::zone_client_request_object_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &object_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
