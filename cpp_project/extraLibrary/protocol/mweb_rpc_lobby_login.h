#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_rpc_lobby_login_cs : public WebBasePacket 	// class login account
	{
	public:
		std::string username{};
	public:
		std::string access_token{};
	public:
		int64_t auid{};
	public:
		bool quicklogin{};
	public:
		mpe_adult_grade adult_grade{};
	public:
		int32_t play_time{};

	public:
		mweb_rpc_lobby_login_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &quicklogin);
			protocol::SerializeEnum(pBuffer, &adult_grade);
			protocol::SerializeType(pBuffer, &play_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_rpc_lobby_login_sc : public WebBasePacket 	// class login account
	{

	public:
		mweb_rpc_lobby_login_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
