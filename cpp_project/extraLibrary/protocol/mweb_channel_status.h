#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_channel_status_info.h"

namespace mir3d
{
	class mweb_channel_status_cs : public WebBasePacket 	// (gate에서 삭제)
	{
	public:
		int32_t map_id{};

	public:
		mweb_channel_status_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &map_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_channel_status_sc : public WebBasePacket 	// (gate에서 삭제)
	{
	public:
		int32_t result{};
	public:
		std::vector<mps_channel_status_info> channel_info_list{};

	public:
		mweb_channel_status_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &channel_info_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
