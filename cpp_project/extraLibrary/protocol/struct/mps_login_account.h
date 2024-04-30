#pragma once
#include <vector>
#include <string>
#include "mps_login_character.h"

namespace mir3d
{
	class mps_login_account 	// classloginaccount설명
	{
	public:
		std::string username{};
	public:
		int64_t auid{};
	public:
		int32_t lastgid{};
	public:
		int64_t lastcuid{};
	public:
		std::vector<mps_login_character> list_character{};
	public:
		mpe_adult_grade grade{};	// 과몰입등급
	public:
		std::string password{};
	public:
		int32_t lastlogin{};
	public:
		int32_t play_time{};	// 일일 접속 시간
	public:
		bool auth_lock{};	// 계정잠금
	public:
		std::string player_key{};
	public:
		mpe_os_type os_type{};
	public:
		mpe_channel_type channel_type{};
	public:
		mpe_store_type store_type{};
	public:
		std::string ip_address{};
	public:
		std::string unique_client_id{};
	public:
		int32_t lasttime{};
	public:
		std::vector<int64_t> list_select_cuid{};
	public:
		std::string wallet_address{};	// 월렛 주소

	public:
		mps_login_account()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &lastgid);
			protocol::SerializeType(pBuffer, &lastcuid);
			protocol::SerializeType(pBuffer, &list_character);
			protocol::SerializeEnum(pBuffer, &grade);
			protocol::SerializeType(pBuffer, &password);
			protocol::SerializeType(pBuffer, &lastlogin);
			protocol::SerializeType(pBuffer, &play_time);
			protocol::SerializeType(pBuffer, &auth_lock);
			protocol::SerializeType(pBuffer, &player_key);
			protocol::SerializeEnum(pBuffer, &os_type);
			protocol::SerializeEnum(pBuffer, &channel_type);
			protocol::SerializeEnum(pBuffer, &store_type);
			protocol::SerializeType(pBuffer, &ip_address);
			protocol::SerializeType(pBuffer, &unique_client_id);
			protocol::SerializeType(pBuffer, &lasttime);
			protocol::SerializeType(pBuffer, &list_select_cuid);
			protocol::SerializeType(pBuffer, &wallet_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
