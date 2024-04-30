#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_character.h"
#include "struct/mrpcs_meridians.h"
#include "struct/mrpcs_enchant_stone_info.h"
#include "struct/mrpcs_pk_record_info.h"
#include "struct/mrpcs_character_ranking_info.h"

namespace mir3d
{
	class mweb_gm_get_character_info_cs : public WebBasePacket 
	{
	public:
		std::string access_token{};
	public:
		int32_t gid{};
	public:
		int64_t cuid{};

	public:
		mweb_gm_get_character_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_get_character_info_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	private:
		bool flag_character = false;
		mps_character character;
		mps_character* p_character = nullptr;
	public:
		bool has_character() const
		{
			return flag_character;
		}
		mps_character* alloc_character()
		{
			flag_character = true;
			return &character;
		}
		const mps_character* get_character() const
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
		void set_character(mps_character* in_character)
		{
			if (nullptr == p_character)
			{
				p_character = in_character;
				flag_character = true;
			}
		}
	private:
		bool flag_meridians = false;
		mrpcs_meridians meridians;
		mrpcs_meridians* p_meridians = nullptr;
	public:
		bool has_meridians() const
		{
			return flag_meridians;
		}
		mrpcs_meridians* alloc_meridians()
		{
			flag_meridians = true;
			return &meridians;
		}
		const mrpcs_meridians* get_meridians() const
		{
			if (true == flag_meridians)
			{
				if (nullptr == p_meridians)
				{
					return &meridians;
				}
				return p_meridians;
			}
			return nullptr;
		}
		void set_meridians(mrpcs_meridians* in_meridians)
		{
			if (nullptr == p_meridians)
			{
				p_meridians = in_meridians;
				flag_meridians = true;
			}
		}
	private:
		bool flag_enchant_stone_info = false;
		mrpcs_enchant_stone_info enchant_stone_info;
		mrpcs_enchant_stone_info* p_enchant_stone_info = nullptr;
	public:
		bool has_enchant_stone_info() const
		{
			return flag_enchant_stone_info;
		}
		mrpcs_enchant_stone_info* alloc_enchant_stone_info()
		{
			flag_enchant_stone_info = true;
			return &enchant_stone_info;
		}
		const mrpcs_enchant_stone_info* get_enchant_stone_info() const
		{
			if (true == flag_enchant_stone_info)
			{
				if (nullptr == p_enchant_stone_info)
				{
					return &enchant_stone_info;
				}
				return p_enchant_stone_info;
			}
			return nullptr;
		}
		void set_enchant_stone_info(mrpcs_enchant_stone_info* in_enchant_stone_info)
		{
			if (nullptr == p_enchant_stone_info)
			{
				p_enchant_stone_info = in_enchant_stone_info;
				flag_enchant_stone_info = true;
			}
		}
	private:
		bool flag_pk_record_info = false;
		mrpcs_pk_record_info pk_record_info;
		mrpcs_pk_record_info* p_pk_record_info = nullptr;
	public:
		bool has_pk_record_info() const
		{
			return flag_pk_record_info;
		}
		mrpcs_pk_record_info* alloc_pk_record_info()
		{
			flag_pk_record_info = true;
			return &pk_record_info;
		}
		const mrpcs_pk_record_info* get_pk_record_info() const
		{
			if (true == flag_pk_record_info)
			{
				if (nullptr == p_pk_record_info)
				{
					return &pk_record_info;
				}
				return p_pk_record_info;
			}
			return nullptr;
		}
		void set_pk_record_info(mrpcs_pk_record_info* in_pk_record_info)
		{
			if (nullptr == p_pk_record_info)
			{
				p_pk_record_info = in_pk_record_info;
				flag_pk_record_info = true;
			}
		}
	private:
		bool flag_ranking_info = false;
		mrpcs_character_ranking_info ranking_info;
		mrpcs_character_ranking_info* p_ranking_info = nullptr;
	public:
		bool has_ranking_info() const
		{
			return flag_ranking_info;
		}
		mrpcs_character_ranking_info* alloc_ranking_info()
		{
			flag_ranking_info = true;
			return &ranking_info;
		}
		const mrpcs_character_ranking_info* get_ranking_info() const
		{
			if (true == flag_ranking_info)
			{
				if (nullptr == p_ranking_info)
				{
					return &ranking_info;
				}
				return p_ranking_info;
			}
			return nullptr;
		}
		void set_ranking_info(mrpcs_character_ranking_info* in_ranking_info)
		{
			if (nullptr == p_ranking_info)
			{
				p_ranking_info = in_ranking_info;
				flag_ranking_info = true;
			}
		}
	public:
		uint8_t wanted_murder_grade{};	// 현상수배단계
	public:
		int32_t security_level{};

	public:
		mweb_gm_get_character_info_sc() : WebBasePacket()
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
			protocol::SerializeType(pBuffer, &flag_meridians);
			if (true == flag_meridians)
			{
				if (nullptr != p_meridians)
					protocol::SerializeType(pBuffer, p_meridians);
				else
					protocol::SerializeType(pBuffer, &meridians);
			}
			protocol::SerializeType(pBuffer, &flag_enchant_stone_info);
			if (true == flag_enchant_stone_info)
			{
				if (nullptr != p_enchant_stone_info)
					protocol::SerializeType(pBuffer, p_enchant_stone_info);
				else
					protocol::SerializeType(pBuffer, &enchant_stone_info);
			}
			protocol::SerializeType(pBuffer, &flag_pk_record_info);
			if (true == flag_pk_record_info)
			{
				if (nullptr != p_pk_record_info)
					protocol::SerializeType(pBuffer, p_pk_record_info);
				else
					protocol::SerializeType(pBuffer, &pk_record_info);
			}
			protocol::SerializeType(pBuffer, &flag_ranking_info);
			if (true == flag_ranking_info)
			{
				if (nullptr != p_ranking_info)
					protocol::SerializeType(pBuffer, p_ranking_info);
				else
					protocol::SerializeType(pBuffer, &ranking_info);
			}
			protocol::SerializeType(pBuffer, &wanted_murder_grade);
			protocol::SerializeType(pBuffer, &security_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
