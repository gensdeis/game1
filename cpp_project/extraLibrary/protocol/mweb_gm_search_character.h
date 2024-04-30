#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mgms_lobby_character_info.h"

namespace mir3d
{
	class mweb_gm_search_character_cs : public WebBasePacket 
	{
	public:
		std::string access_token{};
	public:
		int32_t gid{};
	public:
		int64_t cuid{};
	public:
		std::string character_name{};

	public:
		mweb_gm_search_character_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &character_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_search_character_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	private:
		bool flag_character_info = false;
		mgms_lobby_character_info character_info;
		mgms_lobby_character_info* p_character_info = nullptr;
	public:
		bool has_character_info() const
		{
			return flag_character_info;
		}
		mgms_lobby_character_info* alloc_character_info()
		{
			flag_character_info = true;
			return &character_info;
		}
		const mgms_lobby_character_info* get_character_info() const
		{
			if (true == flag_character_info)
			{
				if (nullptr == p_character_info)
				{
					return &character_info;
				}
				return p_character_info;
			}
			return nullptr;
		}
		void set_character_info(mgms_lobby_character_info* in_character_info)
		{
			if (nullptr == p_character_info)
			{
				p_character_info = in_character_info;
				flag_character_info = true;
			}
		}

	public:
		mweb_gm_search_character_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_character_info);
			if (true == flag_character_info)
			{
				if (nullptr != p_character_info)
					protocol::SerializeType(pBuffer, p_character_info);
				else
					protocol::SerializeType(pBuffer, &character_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
