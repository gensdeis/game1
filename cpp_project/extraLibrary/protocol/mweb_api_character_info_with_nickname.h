#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_character.h"

namespace mir3d
{
	class mweb_api_character_info_with_nickname_cs : public WebBasePacket 
	{
	public:
		std::string nickname{};

	public:
		mweb_api_character_info_with_nickname_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nickname);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_character_info_with_nickname_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	private:
		bool flag_character = false;
		mrpcs_character character;
		mrpcs_character* p_character = nullptr;
	public:
		bool has_character() const
		{
			return flag_character;
		}
		mrpcs_character* alloc_character()
		{
			flag_character = true;
			return &character;
		}
		const mrpcs_character* get_character() const
		{
			if (true == flag_character)
			{
				if (nullptr == p_character)
				{
					return &character;
				}
				return p_character;
			}
			return nullptr;
		}
		void set_character(mrpcs_character* in_character)
		{
			if (nullptr == p_character)
			{
				p_character = in_character;
				flag_character = true;
			}
		}
	public:
		int32_t last_login_time{};
	public:
		int32_t logout_time{};
	public:
		bool connect{};
	public:
		int32_t security_level{};

	public:
		mweb_api_character_info_with_nickname_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_character);
			if (true == flag_character)
			{
				if (nullptr != p_character)
					protocol::SerializeType(pBuffer, p_character);
				else
					protocol::SerializeType(pBuffer, &character);
			}
			protocol::SerializeType(pBuffer, &last_login_time);
			protocol::SerializeType(pBuffer, &logout_time);
			protocol::SerializeType(pBuffer, &connect);
			protocol::SerializeType(pBuffer, &security_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
