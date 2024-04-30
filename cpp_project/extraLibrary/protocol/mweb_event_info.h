#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_event_info.h"
#include "struct/mps_advertisement_event.h"

namespace mir3d
{
	class mweb_event_info_cs : public WebBasePacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t auid{};

	public:
		mweb_event_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_event_info_sc : public WebBasePacket 
	{
	public:
		int32_t result{};
	public:
		std::vector<mps_event_info> info{};
	public:
		int32_t create_time{};
	public:
		int32_t cumulative_connection_time{};
	public:
		std::vector<mps_advertisement_event>  advertisement_event_list{};
	public:
		mpe_account_category account_category{};	// 계정 카테고리(기존,복귀,신규)

	public:
		mweb_event_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &create_time);
			protocol::SerializeType(pBuffer, &cumulative_connection_time);
			protocol::SerializeType(pBuffer, & advertisement_event_list);
			protocol::SerializeEnum(pBuffer, &account_category);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
