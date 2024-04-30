#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_character.h"
#include "struct/mps_buff.h"
#include "struct/mps_siege_warfare_time_info.h"
#include "struct/mps_simple_pk_revenge_info.h"
#include "struct/mps_pickup_info.h"

namespace mir3d
{
	class mp_game_login_cs : public BasePacket 	// 게임 서버 접속
	{
	public:
		int64_t auid{};
	public:
		int64_t indun_uid{};
	public:
		std::string access_token{};
	public:
		std::string version{};

	public:
		mp_game_login_cs() : BasePacket(mpe_cmd::game_login_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &version);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_game_login_sc : public BasePacket 	// 게임 서버 접속
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
		float atk_speed{};
	public:
		int64_t now{};
	public:
		std::vector<mps_buff> buff_list{};
	public:
		std::vector<mps_siege_warfare_time_info> siege_time_info{};	// 공성전 시간
	public:
		std::vector<mps_simple_pk_revenge_info> pk_revenge_list{};	// pk 복수 유저
	public:
		float run_speed{};	// 이동속도
	public:
		std::vector<mps_pickup_info> auto_battle_pickup_list{};
	public:
		uint8_t wanted_murder_grade{};	// 현상수배단계
	public:
		int32_t time_zone{};	// 서버의타임존
	public:
		int32_t gid{};	// 본인 서버 gid

	public:
		mp_game_login_sc() : BasePacket(mpe_cmd::game_login_sc)
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
			protocol::SerializeType(pBuffer, &atk_speed);
			protocol::SerializeType(pBuffer, &now);
			protocol::SerializeType(pBuffer, &buff_list);
			protocol::SerializeType(pBuffer, &siege_time_info);
			protocol::SerializeType(pBuffer, &pk_revenge_list);
			protocol::SerializeType(pBuffer, &run_speed);
			protocol::SerializeType(pBuffer, &auto_battle_pickup_list);
			protocol::SerializeType(pBuffer, &wanted_murder_grade);
			protocol::SerializeType(pBuffer, &time_zone);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
