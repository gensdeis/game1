#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_login_account.h"
#include "struct/mps_login_server_group_info.h"
#include "struct/mps_server_inspection.h"
#include "struct/mps_region_status_server.h"

namespace mir3d
{
	class mweb_login_loginauth_cs : public WebBasePacket 	// 로그인 서버 인증
	{
	public:
		std::string username{};
	public:
		std::string password{};
	public:
		bool isCertification{};	// 판호:true / 기존:false
	public:
		std::string device_id{};
	public:
		mpe_os_type os_type{};
	public:
		mpe_channel_type channel_type{};
	public:
		mpe_store_type store_type{};
	public:
		std::string player_key{};
	public:
		std::string token_id{};
	public:
		std::string ip_address{};
	public:
		std::string mac_addr{};

	public:
		mweb_login_loginauth_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &password);
			protocol::SerializeType(pBuffer, &isCertification);
			protocol::SerializeType(pBuffer, &device_id);
			protocol::SerializeEnum(pBuffer, &os_type);
			protocol::SerializeEnum(pBuffer, &channel_type);
			protocol::SerializeEnum(pBuffer, &store_type);
			protocol::SerializeType(pBuffer, &player_key);
			protocol::SerializeType(pBuffer, &token_id);
			protocol::SerializeType(pBuffer, &ip_address);
			protocol::SerializeType(pBuffer, &mac_addr);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_login_loginauth_sc : public WebBasePacket 	// 로그인 서버 인증
	{
	public:
		int32_t result{};
	private:
		bool flag_info = false;
		mps_login_account info;
		mps_login_account* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_login_account* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_login_account* get_info() const
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
		void set_info(mps_login_account* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		std::vector<mps_login_server_group_info> list_server{};	// lobby server 목록
	public:
		std::string block_msg{};
	public:
		int64_t block_start_date{};
	public:
		int64_t block_end_date{};
	private:
		bool flag_server_inspection = false;
		mps_server_inspection server_inspection;
		mps_server_inspection* p_server_inspection = nullptr;
	public:
		bool has_server_inspection() const
		{
			return flag_server_inspection;
		}
		mps_server_inspection* alloc_server_inspection()
		{
			flag_server_inspection = true;
			return &server_inspection;
		}
		const mps_server_inspection* get_server_inspection() const
		{
			if (true == flag_server_inspection)
			{
				if (nullptr == p_server_inspection)
				{
					return &server_inspection;
				}
				return p_server_inspection;
			}
			return nullptr;
		}
		void set_server_inspection(mps_server_inspection* in_server_inspection)
		{
			if (nullptr == p_server_inspection)
			{
				p_server_inspection = in_server_inspection;
				flag_server_inspection = true;
			}
		}
	public:
		std::string seed_uncheater{};
	public:
		std::vector<mps_region_status_server> list_region{};	// 리전별 ping 서버 정보
	public:
		int32_t server_time{};

	public:
		mweb_login_loginauth_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &list_server);
			protocol::SerializeType(pBuffer, &block_msg);
			protocol::SerializeType(pBuffer, &block_start_date);
			protocol::SerializeType(pBuffer, &block_end_date);
			protocol::SerializeType(pBuffer, &flag_server_inspection);
			if (true == flag_server_inspection)
			{
				if (nullptr != p_server_inspection)
					protocol::SerializeType(pBuffer, p_server_inspection);
				else
					protocol::SerializeType(pBuffer, &server_inspection);
			}
			protocol::SerializeType(pBuffer, &seed_uncheater);
			protocol::SerializeType(pBuffer, &list_region);
			protocol::SerializeType(pBuffer, &server_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
