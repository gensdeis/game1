#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_character_data.h"
#include "struct/mrpcs_subscription_info.h"

namespace mir3d
{
	class mrpc_game_login_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		uint16_t server_index{};
	public:
		mrpce_server_type server_type{};
	public:
		int64_t auid{};
	public:
		std::string access_token{};
	public:
		int64_t auto_battle_login_time{};
	public:
		int64_t socket_access_token{};

	public:
		mrpc_game_login_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::game_login_cs, tag)
		{
		}
		mrpc_game_login_cs() : RpcPacket(mpe_rpc_cmd::game_login_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &auto_battle_login_time);
			protocol::SerializeType(pBuffer, &socket_access_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_game_login_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_data = false;
		mrpcs_character_data data;
		mrpcs_character_data* p_data = nullptr;
	public:
		bool has_data() const
		{
			return flag_data;
		}
		mrpcs_character_data* alloc_data()
		{
			flag_data = true;
			return &data;
		}
		const mrpcs_character_data* get_data() const
		{
			if (true == flag_data)
			{
				if (nullptr == p_data)
				{
					return &data;
				}
				return p_data;
			}
			return nullptr;
		}
		void set_data(mrpcs_character_data* in_data)
		{
			if (nullptr == p_data)
			{
				p_data = in_data;
				flag_data = true;
			}
		}
	public:
		std::vector<mrpcs_subscription_info> subscription_info_list{};	// 캐릭터 구독서비스 정보리스트

	public:
		mrpc_game_login_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::game_login_sc, tag)
		{
		}
		mrpc_game_login_sc() : RpcPacket(mpe_rpc_cmd::game_login_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_data);
			if (true == flag_data)
			{
				if (nullptr != p_data)
					protocol::SerializeType(pBuffer, p_data);
				else
					protocol::SerializeType(pBuffer, &data);
			}
			protocol::SerializeType(pBuffer, &subscription_info_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
