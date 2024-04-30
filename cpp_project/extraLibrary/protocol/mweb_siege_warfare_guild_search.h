#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_siege_warfare_alliance_info.h"

namespace mir3d
{
	class mweb_siege_warfare_guild_search_cs : public WebBasePacket 	// 공성문파검색
	{
	public:
		std::string search_name{};	// 검색 문파 이름
	public:
		int64_t siege_guid{};	// 공성입찰 1위 문파 guid

	public:
		mweb_siege_warfare_guild_search_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &search_name);
			protocol::SerializeType(pBuffer, &siege_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_siege_warfare_guild_search_sc : public WebBasePacket 	// 공성문파검색
	{
	private:
		bool flag_siege_guild = false;
		mps_siege_warfare_alliance_info siege_guild;	// 공성문파
		mps_siege_warfare_alliance_info* p_siege_guild = nullptr;
	public:
		bool has_siege_guild() const
		{
			return flag_siege_guild;
		}
		mps_siege_warfare_alliance_info* alloc_siege_guild()
		{
			flag_siege_guild = true;
			return &siege_guild;
		}
		const mps_siege_warfare_alliance_info* get_siege_guild() const
		{
			if (true == flag_siege_guild)
			{
				if (nullptr == p_siege_guild)
				{
					return &siege_guild;
				}
				return p_siege_guild;
			}
			return nullptr;
		}
		void set_siege_guild(mps_siege_warfare_alliance_info* in_siege_guild)
		{
			if (nullptr == p_siege_guild)
			{
				p_siege_guild = in_siege_guild;
				flag_siege_guild = true;
			}
		}

	public:
		mweb_siege_warfare_guild_search_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_siege_guild);
			if (true == flag_siege_guild)
			{
				if (nullptr != p_siege_guild)
					protocol::SerializeType(pBuffer, p_siege_guild);
				else
					protocol::SerializeType(pBuffer, &siege_guild);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
