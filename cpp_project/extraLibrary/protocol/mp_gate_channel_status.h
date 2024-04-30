#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_channel_status_info.h"

namespace mir3d
{
	class mp_gate_channel_status_cs : public BasePacket 	// (gate에서 삭제)
	{
	public:
		int32_t map_id{};

	public:
		mp_gate_channel_status_cs() : BasePacket(mpe_cmd::gate_channel_status_cs)
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

	class mp_gate_channel_status_sc : public BasePacket 	// (gate에서 삭제)
	{
	public:
		int32_t result{};
	public:
		std::vector<mps_channel_status_info> channel_info_list{};

	public:
		mp_gate_channel_status_sc() : BasePacket(mpe_cmd::gate_channel_status_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &channel_info_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
