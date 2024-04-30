#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_game_event.h"

namespace mir3d
{
	class mrpc_game_event_info_cs : public RpcPacket 
	{
	public:
		mrpce_game_event event_type{};

	public:
		mrpc_game_event_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::game_event_info_cs, tag)
		{
		}
		mrpc_game_event_info_cs() : RpcPacket(mpe_rpc_cmd::game_event_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &event_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_game_event_info_sc : public RpcPacket 
	{
	public:
		std::vector<mrpcs_game_event> list_info{};

	public:
		mrpc_game_event_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::game_event_info_sc, tag)
		{
		}
		mrpc_game_event_info_sc() : RpcPacket(mpe_rpc_cmd::game_event_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
