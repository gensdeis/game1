#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_zone_info.h"
#include "struct/mps_character.h"
#include "struct/mps_buff.h"
#include "struct/mps_siege_warfare_time_info.h"
#include "struct/mps_simple_pk_revenge_info.h"

namespace mir3d
{
	class mp_test_game_login_cs : public BasePacket 	// test
	{
	public:
		int64_t auid{};
	public:
		int32_t id{};
	private:
		bool flag_map = false;
		mps_zone_info map;
		mps_zone_info* p_map = nullptr;
	public:
		bool has_map() const
		{
			return flag_map;
		}
		mps_zone_info* alloc_map()
		{
			flag_map = true;
			return &map;
		}
		const mps_zone_info* get_map() const
		{
			if (true == flag_map)
			{
				if (nullptr == p_map)
				{
					return &map;
				}
				return p_map;
			}
			return nullptr;
		}
		void set_map(mps_zone_info* in_map)
		{
			if (nullptr == p_map)
			{
				p_map = in_map;
				flag_map = true;
			}
		}
	public:
		bool is_skill_open{};

	public:
		mp_test_game_login_cs() : BasePacket(mpe_cmd::test_game_login_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &flag_map);
			if (true == flag_map)
			{
				if (nullptr != p_map)
					protocol::SerializeType(pBuffer, p_map);
				else
					protocol::SerializeType(pBuffer, &map);
			}
			protocol::SerializeType(pBuffer, &is_skill_open);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_test_game_login_sc : public BasePacket 	// test
	{
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
	public:
		int64_t now{};
	public:
		float atk_speed{};
	public:
		std::vector<mps_buff> buff_list{};
	public:
		std::vector<mps_siege_warfare_time_info> siege_time_info{};	// 공성전 시간
	public:
		std::vector<mps_simple_pk_revenge_info> pk_revenge_list{};	// pk 복수 유저

	public:
		mp_test_game_login_sc() : BasePacket(mpe_cmd::test_game_login_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_character);
			if (true == flag_character)
			{
				if (nullptr != p_character)
					protocol::SerializeType(pBuffer, p_character);
				else
					protocol::SerializeType(pBuffer, &character);
			}
			protocol::SerializeType(pBuffer, &now);
			protocol::SerializeType(pBuffer, &atk_speed);
			protocol::SerializeType(pBuffer, &buff_list);
			protocol::SerializeType(pBuffer, &siege_time_info);
			protocol::SerializeType(pBuffer, &pk_revenge_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
