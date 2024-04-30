﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_login_server_group_info.h"
#include "struct/mps_login_account.h"
#include "struct/mps_region_status_server.h"

namespace mir3d
{
	class mweb_server_list_cs : public WebBasePacket 
	{
	public:
		std::string player_key{};

	public:
		mweb_server_list_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &player_key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_server_list_sc : public WebBasePacket 
	{
	public:
		std::vector<mps_login_server_group_info> list_server{};
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
		std::vector<mps_region_status_server> list_region{};	// 리전별 ping 서버 정보

	public:
		mweb_server_list_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_server);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &list_region);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
