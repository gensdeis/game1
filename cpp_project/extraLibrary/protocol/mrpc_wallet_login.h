#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_account_ticket_item.h"

namespace mir3d
{
	class mrpc_wallet_login_cs : public RpcPacket 	// 지갑 로그인
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t server_gid{};
	public:
		int32_t server_index{};
	public:
		mrpce_server_type server_type{};
	public:
		uint8_t character_tid{};
	public:
		int32_t character_level{};
	public:
		int32_t character_power{};
	public:
		std::string nickname{};
	public:
		std::string token{};	// 클라이언트가 SDK로그인을 통해서 받은 정보
	public:
		std::string server_wallet{};	// 서버에저장된 월렛 주소
	public:
		std::string user_name{};	// 플랫폼 로그인시 받는 user_name
	private:
		bool flag_account_ticket_item = false;
		mrpcs_account_ticket_item account_ticket_item;
		mrpcs_account_ticket_item* p_account_ticket_item = nullptr;
	public:
		bool has_account_ticket_item() const
		{
			return flag_account_ticket_item;
		}
		mrpcs_account_ticket_item* alloc_account_ticket_item()
		{
			flag_account_ticket_item = true;
			return &account_ticket_item;
		}
		const mrpcs_account_ticket_item* get_account_ticket_item() const
		{
			if (true == flag_account_ticket_item)
			{
				if (nullptr == p_account_ticket_item)
				{
					return &account_ticket_item;
				}
				return p_account_ticket_item;
			}
			return nullptr;
		}
		void set_account_ticket_item(mrpcs_account_ticket_item* in_account_ticket_item)
		{
			if (nullptr == p_account_ticket_item)
			{
				p_account_ticket_item = in_account_ticket_item;
				flag_account_ticket_item = true;
			}
		}

	public:
		mrpc_wallet_login_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::wallet_login_cs, tag)
		{
		}
		mrpc_wallet_login_cs() : RpcPacket(mpe_rpc_cmd::wallet_login_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &server_gid);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &character_tid);
			protocol::SerializeType(pBuffer, &character_level);
			protocol::SerializeType(pBuffer, &character_power);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &token);
			protocol::SerializeType(pBuffer, &server_wallet);
			protocol::SerializeType(pBuffer, &user_name);
			protocol::SerializeType(pBuffer, &flag_account_ticket_item);
			if (true == flag_account_ticket_item)
			{
				if (nullptr != p_account_ticket_item)
					protocol::SerializeType(pBuffer, p_account_ticket_item);
				else
					protocol::SerializeType(pBuffer, &account_ticket_item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_wallet_login_sc : public RpcPacket 	// 지갑 로그인
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string wallet_address{};	// 유저 월렛 주소

	public:
		mrpc_wallet_login_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::wallet_login_sc, tag)
		{
		}
		mrpc_wallet_login_sc() : RpcPacket(mpe_rpc_cmd::wallet_login_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &wallet_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
