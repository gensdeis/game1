#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_town_info_with_guild.h"

namespace mir3d
{
	class mweb_castle_town_info_by_guild_guid_cs : public WebBasePacket 
	{
	public:
		int64_t guid{};

	public:
		mweb_castle_town_info_by_guild_guid_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_castle_town_info_by_guild_guid_sc : public WebBasePacket 
	{
	public:
		std::vector<mps_castle_town_info_with_guild> info{};
	public:
		bool exists_save_bag{};

	public:
		mweb_castle_town_info_by_guild_guid_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &exists_save_bag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
