#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mgms_base_guild_info.h"

namespace mir3d
{
	class mweb_gm_search_guild_cs : public WebBasePacket 
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
		mweb_gm_search_guild_cs() : WebBasePacket()
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

	class mweb_gm_search_guild_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	private:
		bool flag_guild_info = false;
		mgms_base_guild_info guild_info;
		mgms_base_guild_info* p_guild_info = nullptr;
	public:
		bool has_guild_info() const
		{
			return flag_guild_info;
		}
		mgms_base_guild_info* alloc_guild_info()
		{
			flag_guild_info = true;
			return &guild_info;
		}
		const mgms_base_guild_info* get_guild_info() const
		{
			if (true == flag_guild_info)
			{
				if (nullptr == p_guild_info)
				{
					return &guild_info;
				}
				return p_guild_info;
			}
			return nullptr;
		}
		void set_guild_info(mgms_base_guild_info* in_guild_info)
		{
			if (nullptr == p_guild_info)
			{
				p_guild_info = in_guild_info;
				flag_guild_info = true;
			}
		}

	public:
		mweb_gm_search_guild_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_guild_info);
			if (true == flag_guild_info)
			{
				if (nullptr != p_guild_info)
					protocol::SerializeType(pBuffer, p_guild_info);
				else
					protocol::SerializeType(pBuffer, &guild_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
