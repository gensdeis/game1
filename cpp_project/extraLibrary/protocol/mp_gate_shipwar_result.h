#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_shipwar_character.h"

namespace mir3d
{
	class mp_gate_shipwar_result_cs : public BasePacket 
	{
	public:
		int64_t guid{};
	public:
		int64_t battle_uid{};
	public:
		int32_t season_round{};

	public:
		mp_gate_shipwar_result_cs() : BasePacket(mpe_cmd::gate_shipwar_result_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &battle_uid);
			protocol::SerializeType(pBuffer, &season_round);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_shipwar_result_sc : public BasePacket 
	{
	public:
		std::vector<mps_shipwar_character> list_info{};

	public:
		mp_gate_shipwar_result_sc() : BasePacket(mpe_cmd::gate_shipwar_result_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
