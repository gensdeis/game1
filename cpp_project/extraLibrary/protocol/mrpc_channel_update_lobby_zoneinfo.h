#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_server_info.h"
#include "struct/mrpcs_server_max_play_user.h"

namespace mir3d
{
	class mrpc_channel_update_lobby_zoneinfo_cs : public RpcPacket 
	{
	public:
		std::vector<mrpcs_server_info> info_list{};
	public:
		std::vector<int64_t> channel_uid_list{};
	public:
		std::vector<short> channel_use_count_list{};
	public:
		std::vector<mrpcs_server_max_play_user> server_max_play_user_list{};

	public:
		mrpc_channel_update_lobby_zoneinfo_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::channel_update_lobby_zoneinfo_cs, tag)
		{
		}
		mrpc_channel_update_lobby_zoneinfo_cs() : RpcPacket(mpe_rpc_cmd::channel_update_lobby_zoneinfo_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info_list);
			protocol::SerializeType(pBuffer, &channel_uid_list);
			protocol::SerializeType(pBuffer, &channel_use_count_list);
			protocol::SerializeType(pBuffer, &server_max_play_user_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_channel_update_lobby_zoneinfo_sc : public RpcPacket 
	{

	public:
		mrpc_channel_update_lobby_zoneinfo_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::channel_update_lobby_zoneinfo_sc, tag)
		{
		}
		mrpc_channel_update_lobby_zoneinfo_sc() : RpcPacket(mpe_rpc_cmd::channel_update_lobby_zoneinfo_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
