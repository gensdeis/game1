#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_server_info.h"
#include "struct/mrpcs_server_info.h"

namespace mir3d
{
	class mweb_gm_get_channel_list_cs : public WebBasePacket 
	{
	public:
		std::string access_token{};
	public:
		int32_t gid{};

	public:
		mweb_gm_get_channel_list_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_get_channel_list_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	public:
		std::vector<mrpcs_server_info> list_server{};
	public:
		std::vector<mrpcs_server_info> list_all_channel{};

	public:
		mweb_gm_get_channel_list_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &list_server);
			protocol::SerializeType(pBuffer, &list_all_channel);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
