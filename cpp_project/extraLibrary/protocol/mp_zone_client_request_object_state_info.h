#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_zone_client_request_object_state_info_cs : public BasePacket 
	{
	public:
		int64_t uid{};

	public:
		mp_zone_client_request_object_state_info_cs() : BasePacket(mpe_cmd::zone_client_request_object_state_info_cs)
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

	class mp_zone_client_request_object_state_info_sc : public BasePacket 
	{
	public:
		int64_t uid{};
	public:
		int32_t cell_index{};
	public:
		int32_t hp{};

	public:
		mp_zone_client_request_object_state_info_sc() : BasePacket(mpe_cmd::zone_client_request_object_state_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &cell_index);
			protocol::SerializeType(pBuffer, &hp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
