#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_siege_warfare_alliance_info.h"
#include "struct/mps_siege_warfare_request_alliance_info.h"
#include "struct/mps_siege_warfare_alliance_info.h"

namespace mir3d
{
	class mweb_siege_warfare_alliance_list_cs : public WebBasePacket 	// 연합 리스트 정보
	{
	public:
		int64_t guid{};
	public:
		mpe_siege_castle_type castle_type{};

	public:
		mweb_siege_warfare_alliance_list_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &castle_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_siege_warfare_alliance_list_sc : public WebBasePacket 	// 연합 리스트 정보
	{
	public:
		std::vector<mps_siege_warfare_alliance_info> info{};	// 문파리스트
	public:
		std::vector<mps_siege_warfare_request_alliance_info> alliance_info{};	// 연합문파정보
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
		mweb_siege_warfare_alliance_list_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &alliance_info);
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
