#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_game_setup_save_cs : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		uint16_t version{};
	public:
		std::vector<uint8_t> data{};
	public:
		std::string data_hash{};

	public:
		mp_gate_game_setup_save_cs() : BasePacket(mpe_cmd::gate_game_setup_save_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &version);
			protocol::SerializeType(pBuffer, &data);
			protocol::SerializeType(pBuffer, &data_hash);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_game_setup_save_sc : public BasePacket 
	{

	public:
		mp_gate_game_setup_save_sc() : BasePacket(mpe_cmd::gate_game_setup_save_sc)
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

}
