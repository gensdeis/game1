#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_game_option_save_cs : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		mpe_clinet_platform platform{};
	public:
		std::vector<uint8_t> option_data{};
	public:
		std::string option_hash{};

	public:
		mp_gate_game_option_save_cs() : BasePacket(mpe_cmd::gate_game_option_save_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &platform);
			protocol::SerializeType(pBuffer, &option_data);
			protocol::SerializeType(pBuffer, &option_hash);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_game_option_save_sc : public BasePacket 
	{

	public:
		mp_gate_game_option_save_sc() : BasePacket(mpe_cmd::gate_game_option_save_sc)
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
