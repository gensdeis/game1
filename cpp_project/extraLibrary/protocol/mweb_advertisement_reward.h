﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_advertisement.h"

namespace mir3d
{
	class mweb_advertisement_reward_cs : public WebBasePacket 	// 광고 시청 보상
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string client_guid{};	// WMM Client GUID
	public:
		std::string player_key{};	// WMM Client Key

	public:
		mweb_advertisement_reward_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &client_guid);
			protocol::SerializeType(pBuffer, &player_key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_advertisement_reward_sc : public WebBasePacket 	// 광고 시청 보상
	{
	public:
		int32_t result{};
	private:
		bool flag_advertisement = false;
		mps_advertisement advertisement;
		mps_advertisement* p_advertisement = nullptr;
	public:
		bool has_advertisement() const
		{
			return flag_advertisement;
		}
		mps_advertisement* alloc_advertisement()
		{
			flag_advertisement = true;
			return &advertisement;
		}
		const mps_advertisement* get_advertisement() const
		{
			if (true == flag_advertisement)
			{
				if (nullptr == p_advertisement)
				{
					return &advertisement;
				}
				return p_advertisement;
			}
			return nullptr;
		}
		void set_advertisement(mps_advertisement* in_advertisement)
		{
			if (nullptr == p_advertisement)
			{
				p_advertisement = in_advertisement;
				flag_advertisement = true;
			}
		}
	public:
		int32_t api_code{};	// API CODE

	public:
		mweb_advertisement_reward_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_advertisement);
			if (true == flag_advertisement)
			{
				if (nullptr != p_advertisement)
					protocol::SerializeType(pBuffer, p_advertisement);
				else
					protocol::SerializeType(pBuffer, &advertisement);
			}
			protocol::SerializeType(pBuffer, &api_code);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
