#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_api_character_quest_accept_cs : public WebBasePacket 
	{
	public:
		int64_t cuid{};
	public:
		uint16_t id{};
	public:
		int32_t state{};
	public:
		int32_t object_count{};
	public:
		int32_t area_id{};
	public:
		uint8_t sequence{};

	public:
		mweb_api_character_quest_accept_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &state);
			protocol::SerializeType(pBuffer, &object_count);
			protocol::SerializeType(pBuffer, &area_id);
			protocol::SerializeType(pBuffer, &sequence);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_character_quest_accept_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_api_character_quest_accept_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
