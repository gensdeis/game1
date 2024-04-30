#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_share_storage_log.h"

namespace mir3d
{
	class mweb_guild_share_storage_log_cs : public WebBasePacket 
	{
	public:
		int64_t guid{};
	public:
		int64_t last_time{};

	public:
		mweb_guild_share_storage_log_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &last_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_guild_share_storage_log_sc : public WebBasePacket 
	{
	public:
		std::vector<mps_guild_share_storage_log> log_list{};
	public:
		int64_t last_time{};

	public:
		mweb_guild_share_storage_log_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &log_list);
			protocol::SerializeType(pBuffer, &last_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
