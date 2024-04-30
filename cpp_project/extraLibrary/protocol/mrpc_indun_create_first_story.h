#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_indun_create_first_story_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int32_t lobby_server_index{};
	public:
		int32_t dungeon_id{};

	public:
		mrpc_indun_create_first_story_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::indun_create_first_story_cs, tag)
		{
		}
		mrpc_indun_create_first_story_cs() : RpcPacket(mpe_rpc_cmd::indun_create_first_story_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &lobby_server_index);
			protocol::SerializeType(pBuffer, &dungeon_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_indun_create_first_story_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int32_t lobby_server_index{};
	public:
		int32_t indun_server_index{};
	public:
		int64_t indun_uid{};

	public:
		mrpc_indun_create_first_story_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::indun_create_first_story_sc, tag)
		{
		}
		mrpc_indun_create_first_story_sc() : RpcPacket(mpe_rpc_cmd::indun_create_first_story_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &lobby_server_index);
			protocol::SerializeType(pBuffer, &indun_server_index);
			protocol::SerializeType(pBuffer, &indun_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
