#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_lobby_player.h"
#include "struct/mps_lobby_gameplayinfo.h"

namespace mir3d
{
	class mweb_lobby_gameplaylogin_cs : public WebBasePacket 	// 로비 로그인(gate에서 삭제)
	{
	public:
		int64_t auid{};
	public:
		std::string access_token{};

	public:
		mweb_lobby_gameplaylogin_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &access_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_lobby_gameplaylogin_sc : public WebBasePacket 	// 로비 로그인(gate에서 삭제)
	{
	public:
		int32_t result{};
	public:
		uint8_t login_flag{};
	private:
		bool flag_player = false;
		mps_lobby_player player;
		mps_lobby_player* p_player = nullptr;
	public:
		bool has_player() const
		{
			return flag_player;
		}
		mps_lobby_player* alloc_player()
		{
			flag_player = true;
			return &player;
		}
		const mps_lobby_player* get_player() const
		{
			if (true == flag_player)
			{
				if (nullptr == p_player)
				{
					return &player;
				}
				return p_player;
			}
			return nullptr;
		}
		void set_player(mps_lobby_player* in_player)
		{
			if (nullptr == p_player)
			{
				p_player = in_player;
				flag_player = true;
			}
		}
	private:
		bool flag_gameinfo = false;
		mps_lobby_gameplayinfo gameinfo;
		mps_lobby_gameplayinfo* p_gameinfo = nullptr;
	public:
		bool has_gameinfo() const
		{
			return flag_gameinfo;
		}
		mps_lobby_gameplayinfo* alloc_gameinfo()
		{
			flag_gameinfo = true;
			return &gameinfo;
		}
		const mps_lobby_gameplayinfo* get_gameinfo() const
		{
			if (true == flag_gameinfo)
			{
				if (nullptr == p_gameinfo)
				{
					return &gameinfo;
				}
				return p_gameinfo;
			}
			return nullptr;
		}
		void set_gameinfo(mps_lobby_gameplayinfo* in_gameinfo)
		{
			if (nullptr == p_gameinfo)
			{
				p_gameinfo = in_gameinfo;
				flag_gameinfo = true;
			}
		}
	public:
		int32_t server_time{};
	public:
		int32_t time_zone{};

	public:
		mweb_lobby_gameplaylogin_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &login_flag);
			protocol::SerializeType(pBuffer, &flag_player);
			if (true == flag_player)
			{
				if (nullptr != p_player)
					protocol::SerializeType(pBuffer, p_player);
				else
					protocol::SerializeType(pBuffer, &player);
			}
			protocol::SerializeType(pBuffer, &flag_gameinfo);
			if (true == flag_gameinfo)
			{
				if (nullptr != p_gameinfo)
					protocol::SerializeType(pBuffer, p_gameinfo);
				else
					protocol::SerializeType(pBuffer, &gameinfo);
			}
			protocol::SerializeType(pBuffer, &server_time);
			protocol::SerializeType(pBuffer, &time_zone);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
