#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild.h"
#include "struct/mps_guild_member.h"
#include "struct/mps_item.h"
#include "struct/mps_item.h"
#include "struct/mps_item.h"
#include "struct/mps_guild_storage_treasure_auction.h"

namespace mir3d
{
	class mweb_gm_get_guild_info_cs : public WebBasePacket 
	{
	public:
		std::string access_token{};
	public:
		int32_t gid{};
	public:
		int64_t guid{};
	public:
		std::string guild_name{};

	public:
		mweb_gm_get_guild_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_get_guild_info_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	private:
		bool flag_guild = false;
		mps_guild guild;
		mps_guild* p_guild = nullptr;
	public:
		bool has_guild() const
		{
			return flag_guild;
		}
		mps_guild* alloc_guild()
		{
			flag_guild = true;
			return &guild;
		}
		const mps_guild* get_guild() const
		{
			if (true == flag_guild)
			{
				if (nullptr == p_guild)
				{
					return &guild;
				}
				return p_guild;
			}
			return nullptr;
		}
		void set_guild(mps_guild* in_guild)
		{
			if (nullptr == p_guild)
			{
				p_guild = in_guild;
				flag_guild = true;
			}
		}
	public:
		std::vector<mps_guild_member> list_guild_member{};
	public:
		std::vector<mps_item> list_storage_material_item{};
	public:
		std::vector<mps_item> list_storage_supply_item{};
	public:
		std::vector<mps_item> list_storage_share_item{};
	public:
		std::vector<mps_guild_storage_treasure_auction> list_storage_treasure_item{};

	public:
		mweb_gm_get_guild_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_guild);
			if (true == flag_guild)
			{
				if (nullptr != p_guild)
					protocol::SerializeType(pBuffer, p_guild);
				else
					protocol::SerializeType(pBuffer, &guild);
			}
			protocol::SerializeType(pBuffer, &list_guild_member);
			protocol::SerializeType(pBuffer, &list_storage_material_item);
			protocol::SerializeType(pBuffer, &list_storage_supply_item);
			protocol::SerializeType(pBuffer, &list_storage_share_item);
			protocol::SerializeType(pBuffer, &list_storage_treasure_item);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
