#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_zone_info.h"

namespace mir3d
{
	class mp_ai_game_login_cs : public BasePacket 	// 게임 서버 접속
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
		bool is_siege_bot{};
	public:
		bool is_test_bot{};
	public:
		int32_t ai_service_index{};
	private:
		bool flag_start_position = false;
		mps_zone_info start_position;
		mps_zone_info* p_start_position = nullptr;
	public:
		bool has_start_position() const
		{
			return flag_start_position;
		}
		mps_zone_info* alloc_start_position()
		{
			flag_start_position = true;
			return &start_position;
		}
		const mps_zone_info* get_start_position() const
		{
			if (true == flag_start_position)
			{
				if (nullptr == p_start_position)
				{
					return &start_position;
				}
				return p_start_position;
			}
			return nullptr;
		}
		void set_start_position(mps_zone_info* in_start_position)
		{
			if (nullptr == p_start_position)
			{
				p_start_position = in_start_position;
				flag_start_position = true;
			}
		}
	public:
		int64_t start_channel_uid{};

	public:
		mp_ai_game_login_cs() : BasePacket(mpe_cmd::ai_game_login_cs)
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
			protocol::SerializeType(pBuffer, &is_siege_bot);
			protocol::SerializeType(pBuffer, &is_test_bot);
			protocol::SerializeType(pBuffer, &ai_service_index);
			protocol::SerializeType(pBuffer, &flag_start_position);
			if (true == flag_start_position)
			{
				if (nullptr != p_start_position)
					protocol::SerializeType(pBuffer, p_start_position);
				else
					protocol::SerializeType(pBuffer, &start_position);
			}
			protocol::SerializeType(pBuffer, &start_channel_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_ai_game_login_sc : public BasePacket 	// 게임 서버 접속
	{

	public:
		mp_ai_game_login_sc() : BasePacket(mpe_cmd::ai_game_login_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
