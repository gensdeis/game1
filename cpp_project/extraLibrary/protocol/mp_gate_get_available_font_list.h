#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_available_font.h"

namespace mir3d
{
	class mp_gate_get_available_font_list_cs : public BasePacket 	// (gate에서 삭제)
	{
	public:
		int32_t param{};

	public:
		mp_gate_get_available_font_list_cs() : BasePacket(mpe_cmd::gate_get_available_font_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &param);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_get_available_font_list_sc : public BasePacket 	// (gate에서 삭제)
	{
	public:
		std::vector<mps_available_font> list{};

	public:
		mp_gate_get_available_font_list_sc() : BasePacket(mpe_cmd::gate_get_available_font_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
