#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_player_login_info.h"
#include "struct/mrpcs_login_account.h"

namespace mir3d
{
	class mweb_rpc_lobby_login_ex_cs : public WebBasePacket 	// 중복로그인 처리
	{
	public:
		std::string username{};
	public:
		std::string access_token{};
	public:
		bool quicklogin{};
	private:
		bool flag_info = false;
		mrpcs_player_login_info info;
		mrpcs_player_login_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_player_login_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_player_login_info* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mrpcs_player_login_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	private:
		bool flag_redis_account = false;
		mrpcs_login_account redis_account;
		mrpcs_login_account* p_redis_account = nullptr;
	public:
		bool has_redis_account() const
		{
			return flag_redis_account;
		}
		mrpcs_login_account* alloc_redis_account()
		{
			flag_redis_account = true;
			return &redis_account;
		}
		const mrpcs_login_account* get_redis_account() const
		{
			if (true == flag_redis_account)
			{
				if (nullptr == p_redis_account)
				{
					return &redis_account;
				}
				return p_redis_account;
			}
			return nullptr;
		}
		void set_redis_account(mrpcs_login_account* in_redis_account)
		{
			if (nullptr == p_redis_account)
			{
				p_redis_account = in_redis_account;
				flag_redis_account = true;
			}
		}

	public:
		mweb_rpc_lobby_login_ex_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &quicklogin);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_redis_account);
			if (true == flag_redis_account)
			{
				if (nullptr != p_redis_account)
					protocol::SerializeType(pBuffer, p_redis_account);
				else
					protocol::SerializeType(pBuffer, &redis_account);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_rpc_lobby_login_ex_sc : public WebBasePacket 	// 중복로그인 처리
	{

	public:
		mweb_rpc_lobby_login_ex_sc() : WebBasePacket()
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
