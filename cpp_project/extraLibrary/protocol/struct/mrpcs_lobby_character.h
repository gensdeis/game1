#pragma once
#include <vector>
#include <string>
#include "mrpcs_player_login_info.h"
#include "mrpcs_account_ticket_item.h"

namespace mir3d
{
	class mrpcs_lobby_character 
	{
	public:
		std::string username{};
	public:
		std::string access_token{};
	public:
		bool quicklogin{};
	public:
		int64_t cuid{};
	public:
		mrpce_server_type server_type{};
	public:
		int32_t server_index{};
	public:
		int32_t zone_id{};
	public:
		int64_t channel_uid{};
	public:
		int32_t indun_id{};
	public:
		bool locked{};
	public:
		mpe_adult_grade adult_grade{};
	public:
		int32_t play_time{};
	public:
		int64_t guid{};
	public:
		std::string wallet_address{};	// 월렛 주소
	public:
		mpe_os_type os_type{};
	private:
		bool flag_login_info = false;
		mrpcs_player_login_info login_info;
		mrpcs_player_login_info* p_login_info = nullptr;
	public:
		bool has_login_info() const
		{
			return flag_login_info;
		}
		mrpcs_player_login_info* alloc_login_info()
		{
			flag_login_info = true;
			return &login_info;
		}
		const mrpcs_player_login_info* get_login_info() const
		{
			if (true == flag_login_info)
			{
				if (nullptr == p_login_info)
				{
					return &login_info;
				}
				return p_login_info;
			}
			return nullptr;
		}
		void set_login_info(mrpcs_player_login_info* in_login_info)
		{
			if (nullptr == p_login_info)
			{
				p_login_info = in_login_info;
				flag_login_info = true;
			}
		}
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
		bool private_chatting_disable{};
	public:
		uint8_t team_index{};

	public:
		mrpcs_lobby_character()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &quicklogin);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &indun_id);
			protocol::SerializeType(pBuffer, &locked);
			protocol::SerializeEnum(pBuffer, &adult_grade);
			protocol::SerializeType(pBuffer, &play_time);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &wallet_address);
			protocol::SerializeEnum(pBuffer, &os_type);
			protocol::SerializeType(pBuffer, &flag_login_info);
			if (true == flag_login_info)
			{
				if (nullptr != p_login_info)
					protocol::SerializeType(pBuffer, p_login_info);
				else
					protocol::SerializeType(pBuffer, &login_info);
			}
			protocol::SerializeType(pBuffer, &flag_account_ticket_item);
			if (true == flag_account_ticket_item)
			{
				if (nullptr != p_account_ticket_item)
					protocol::SerializeType(pBuffer, p_account_ticket_item);
				else
					protocol::SerializeType(pBuffer, &account_ticket_item);
			}
			protocol::SerializeType(pBuffer, &private_chatting_disable);
			protocol::SerializeType(pBuffer, &team_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
