#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_gm_create_character_cs : public WebBasePacket 
	{
	public:
		std::string access_token{};
	public:
		int64_t auid{};
	public:
		std::string username{};
	public:
		std::string warrior_nickname{};
	public:
		std::string taoist_nickname{};
	public:
		std::string wizard_nickname{};

	public:
		mweb_gm_create_character_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &warrior_nickname);
			protocol::SerializeType(pBuffer, &taoist_nickname);
			protocol::SerializeType(pBuffer, &wizard_nickname);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_create_character_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	public:
		std::vector<int64_t> list_cuid{};

	public:
		mweb_gm_create_character_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &list_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
