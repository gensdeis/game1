﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_lobby_character_delete_cancel_cs : public BasePacket 	// 캐릭터 삭제 취소 로비
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string access_token{};
	public:
		mpe_os_type os_type{};

	public:
		mp_gate_lobby_character_delete_cancel_cs() : BasePacket(mpe_cmd::gate_lobby_character_delete_cancel_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeEnum(pBuffer, &os_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_lobby_character_delete_cancel_sc : public BasePacket 	// 캐릭터 삭제 취소 로비
	{
	public:
		int32_t result{};

	public:
		mp_gate_lobby_character_delete_cancel_sc() : BasePacket(mpe_cmd::gate_lobby_character_delete_cancel_sc)
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