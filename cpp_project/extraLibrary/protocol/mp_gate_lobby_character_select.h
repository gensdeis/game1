#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_lobby_gameplayinfo.h"

namespace mir3d
{
	class mp_gate_lobby_character_select_cs : public BasePacket 	// 캐릭터 선택 로비-(gate에서 삭제)
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string access_token{};

	public:
		mp_gate_lobby_character_select_cs() : BasePacket(mpe_cmd::gate_lobby_character_select_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &access_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_lobby_character_select_sc : public BasePacket 	// 캐릭터 선택 로비-(gate에서 삭제)
	{
	public:
		int32_t result{};
	public:
		std::string access_token{};
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
		mp_gate_lobby_character_select_sc() : BasePacket(mpe_cmd::gate_lobby_character_select_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &flag_gameinfo);
			if (true == flag_gameinfo)
			{
				if (nullptr != p_gameinfo)
					protocol::SerializeType(pBuffer, p_gameinfo);
				else
					protocol::SerializeType(pBuffer, &gameinfo);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
