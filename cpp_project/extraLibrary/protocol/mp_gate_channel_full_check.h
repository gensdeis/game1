#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_channel_full_check_cs : public BasePacket 	// (gate에서 삭제)
	{
	public:
		int32_t map_id{};
	public:
		uint16_t channel_id{};

	public:
		mp_gate_channel_full_check_cs() : BasePacket(mpe_cmd::gate_channel_full_check_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &map_id);
			protocol::SerializeType(pBuffer, &channel_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_channel_full_check_sc : public BasePacket 	// (gate에서 삭제)
	{
	public:
		int32_t result{};

	public:
		mp_gate_channel_full_check_sc() : BasePacket(mpe_cmd::gate_channel_full_check_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
