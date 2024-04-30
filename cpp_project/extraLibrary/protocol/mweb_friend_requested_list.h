#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_character_simple_info.h"

namespace mir3d
{
	class mweb_friend_requested_list_cs : public WebBasePacket 
	{
	public:
		int64_t cuid{};

	public:
		mweb_friend_requested_list_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_friend_requested_list_sc : public WebBasePacket 
	{
	public:
		std::vector<mps_character_simple_info> requested_list{};
	public:
		int32_t friend_count{};

	public:
		mweb_friend_requested_list_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &requested_list);
			protocol::SerializeType(pBuffer, &friend_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
