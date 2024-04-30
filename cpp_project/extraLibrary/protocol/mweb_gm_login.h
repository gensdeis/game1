#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mgms_gmserver_info.h"

namespace mir3d
{
	class mweb_gm_login_cs : public WebBasePacket 
	{
	public:
		std::string id{};
	public:
		std::string pass{};
	public:
		mgme_login_type login_type{};

	public:
		mweb_gm_login_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &pass);
			protocol::SerializeEnum(pBuffer, &login_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_login_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	public:
		mgme_authority_type authority{};
	public:
		std::string access_token{};
	public:
		std::vector<mgms_gmserver_info> info{};

	public:
		mweb_gm_login_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeEnum(pBuffer, &authority);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
