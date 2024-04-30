#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_api_character_quest_reset_cs : public WebBasePacket 
	{
	public:
		int64_t cuid{};
	public:
		bool main_quest{};
	public:
		bool quest{};
	public:
		bool repute_quest{};
	public:
		bool guild_quest{};
	public:
		bool guild_office_quest{};

	public:
		mweb_api_character_quest_reset_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &main_quest);
			protocol::SerializeType(pBuffer, &quest);
			protocol::SerializeType(pBuffer, &repute_quest);
			protocol::SerializeType(pBuffer, &guild_quest);
			protocol::SerializeType(pBuffer, &guild_office_quest);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_character_quest_reset_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_api_character_quest_reset_sc() : WebBasePacket()
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
