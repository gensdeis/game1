#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_lobby_player_character_select_cs : public BasePacket 	// 서버통합
	{
	public:
		int64_t auid{};
	public:
		std::string access_token{};
	public:
		std::vector<int64_t> list{};	// 4개까지만 처리한다.

	public:
		mp_gate_lobby_player_character_select_cs() : BasePacket(mpe_cmd::gate_lobby_player_character_select_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_lobby_player_character_select_sc : public BasePacket 	// 서버통합
	{
	public:
		int32_t result{};

	public:
		mp_gate_lobby_player_character_select_sc() : BasePacket(mpe_cmd::gate_lobby_player_character_select_sc)
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
