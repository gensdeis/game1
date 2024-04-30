#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_other_guild_info.h"

namespace mir3d
{
	class mp_guild_search_by_guid_cs : public BasePacket 	// guid로 문파 검색 요청
	{
	public:
		int64_t target_guid{};	// 문파 UID

	public:
		mp_guild_search_by_guid_cs() : BasePacket(mpe_cmd::guild_search_by_guid_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_search_by_guid_sc : public BasePacket 	// guid로 문파 검색 요청
	{
	public:
		mpe_error error{};
	private:
		bool flag_guild = false;
		mps_other_guild_info guild;	// "타 길드 정보"
		mps_other_guild_info* p_guild = nullptr;
	public:
		bool has_guild() const
		{
			return flag_guild;
		}
		mps_other_guild_info* alloc_guild()
		{
			flag_guild = true;
			return &guild;
		}
		const mps_other_guild_info* get_guild() const
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
		void set_guild(mps_other_guild_info* in_guild)
		{
			if (nullptr == p_guild)
			{
				p_guild = in_guild;
				flag_guild = true;
			}
		}

	public:
		mp_guild_search_by_guid_sc() : BasePacket(mpe_cmd::guild_search_by_guid_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &error);
			protocol::SerializeType(pBuffer, &flag_guild);
			if (true == flag_guild)
			{
				if (nullptr != p_guild)
					protocol::SerializeType(pBuffer, p_guild);
				else
					protocol::SerializeType(pBuffer, &guild);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
