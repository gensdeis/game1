#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_view_owner_info.h"

namespace mir3d
{
	class mp_gate_castle_view_owner_info_cs : public BasePacket 
	{

	public:
		mp_gate_castle_view_owner_info_cs() : BasePacket(mpe_cmd::gate_castle_view_owner_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_castle_view_owner_info_sc : public BasePacket 
	{
	public:
		std::vector<mps_castle_view_owner_info> info{};	// 성주 정보

	public:
		mp_gate_castle_view_owner_info_sc() : BasePacket(mpe_cmd::gate_castle_view_owner_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
