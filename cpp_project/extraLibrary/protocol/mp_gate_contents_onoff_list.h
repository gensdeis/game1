#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_contents_onoff_list.h"

namespace mir3d
{
	class mp_gate_contents_onoff_list_cs : public BasePacket 
	{
	public:
		std::vector<int32_t> list_type{};	// List<mpe_contents_onoff_type>

	public:
		mp_gate_contents_onoff_list_cs() : BasePacket(mpe_cmd::gate_contents_onoff_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_contents_onoff_list_sc : public BasePacket 
	{
	public:
		std::vector<mps_contents_onoff_list> list{};
	public:
		int32_t result{};

	public:
		mp_gate_contents_onoff_list_sc() : BasePacket(mpe_cmd::gate_contents_onoff_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
