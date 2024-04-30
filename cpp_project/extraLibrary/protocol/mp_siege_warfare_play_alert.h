#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_siege_warfare_play_alert_cs : public BasePacket 
	{

	public:
		mp_siege_warfare_play_alert_cs() : BasePacket(mpe_cmd::siege_warfare_play_alert_cs)
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

	class mp_siege_warfare_play_alert_sc : public BasePacket 
	{
	public:
		int32_t object_index{};	// 오브젝트 index (위치를알기위한정보)
	public:
		int64_t object_uid{};	// 오브젝트 uid (고유id)
	public:
		int32_t message_string_id{};	// 메시지 id
	public:
		std::string guild_name{};	// 승리 문파 이름

	public:
		mp_siege_warfare_play_alert_sc() : BasePacket(mpe_cmd::siege_warfare_play_alert_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &object_index);
			protocol::SerializeType(pBuffer, &object_uid);
			protocol::SerializeType(pBuffer, &message_string_id);
			protocol::SerializeType(pBuffer, &guild_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
