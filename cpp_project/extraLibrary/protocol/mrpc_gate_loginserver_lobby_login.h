#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_player_login_info.h"
#include "struct/mps_login_account.h"

namespace mir3d
{
	class mrpc_gate_loginserver_lobby_login_cs : public RpcPacket 	// 중복로그인 처리
	{
	public:
		int64_t key{};
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
		bool flag_login_account = false;
		mps_login_account login_account;
		mps_login_account* p_login_account = nullptr;
	public:
		bool has_login_account() const
		{
			return flag_login_account;
		}
		mps_login_account* alloc_login_account()
		{
			flag_login_account = true;
			return &login_account;
		}
		const mps_login_account* get_login_account() const
		{
			if (true == flag_login_account)
			{
				if (nullptr == p_login_account)
				{
					return &login_account;
				}
				return p_login_account;
			}
			return nullptr;
		}
		void set_login_account(mps_login_account* in_login_account)
		{
			if (nullptr == p_login_account)
			{
				p_login_account = in_login_account;
				flag_login_account = true;
			}
		}

	public:
		mrpc_gate_loginserver_lobby_login_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_loginserver_lobby_login_cs, tag)
		{
		}
		mrpc_gate_loginserver_lobby_login_cs() : RpcPacket(mpe_rpc_cmd::gate_loginserver_lobby_login_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &quicklogin);
			protocol::SerializeEnum(pBuffer, &adult_grade);
			protocol::SerializeType(pBuffer, &play_time);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_login_account);
			if (true == flag_login_account)
			{
				if (nullptr != p_login_account)
					protocol::SerializeType(pBuffer, p_login_account);
				else
					protocol::SerializeType(pBuffer, &login_account);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_loginserver_lobby_login_sc : public RpcPacket 	// 중복로그인 처리
	{
	public:
		int64_t key{};

	public:
		mrpc_gate_loginserver_lobby_login_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_loginserver_lobby_login_sc, tag)
		{
		}
		mrpc_gate_loginserver_lobby_login_sc() : RpcPacket(mpe_rpc_cmd::gate_loginserver_lobby_login_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
