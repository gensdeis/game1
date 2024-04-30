#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_pre_verify_cs : public WebBasePacket 
	{
	public:
		std::string player_key{};
	public:
		int64_t account_uid{};
	public:
		std::string character_uid{};
	public:
		std::string user_agent{};
	public:
		std::string product_id{};
	public:
		std::string purchase_token{};

	public:
		mweb_pre_verify_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &player_key);
			protocol::SerializeType(pBuffer, &account_uid);
			protocol::SerializeType(pBuffer, &character_uid);
			protocol::SerializeType(pBuffer, &user_agent);
			protocol::SerializeType(pBuffer, &product_id);
			protocol::SerializeType(pBuffer, &purchase_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_pre_verify_sc : public WebBasePacket 
	{
	public:
		int32_t code{};
	public:
		int32_t result{};

	public:
		mweb_pre_verify_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &code);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
