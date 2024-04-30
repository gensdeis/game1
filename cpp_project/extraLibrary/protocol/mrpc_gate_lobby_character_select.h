#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_lobby_gameplayinfo.h"

namespace mir3d
{
	class mrpc_gate_lobby_character_select_cs : public RpcPacket 	// 캐릭터 선택 로비
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string access_token{};
	public:
		std::string ip_address{};

	public:
		mrpc_gate_lobby_character_select_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_lobby_character_select_cs, tag)
		{
		}
		mrpc_gate_lobby_character_select_cs() : RpcPacket(mpe_rpc_cmd::gate_lobby_character_select_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &ip_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_lobby_character_select_sc : public RpcPacket 	// 캐릭터 선택 로비
	{
	public:
		int64_t key{};
	public:
		int32_t result{};
	public:
		std::string access_token{};
	public:
		int64_t cuid{};
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
		mrpc_gate_lobby_character_select_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_lobby_character_select_sc, tag)
		{
		}
		mrpc_gate_lobby_character_select_sc() : RpcPacket(mpe_rpc_cmd::gate_lobby_character_select_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &cuid);
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
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
