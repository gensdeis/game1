#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_dungeon_create_cs : public RpcPacket 	// 문파던전
	{
	public:
		int64_t cuid{};	// 인던 생성 요청 character_uid
	public:
		int32_t gid{};
	public:
		int64_t guid{};	// 인던 생성 요청 guild_uid
	public:
		int32_t tid{};	// indun table id
	public:
		std::vector<int64_t> member{};

	public:
		mrpc_guild_dungeon_create_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_dungeon_create_cs, tag)
		{
		}
		mrpc_guild_dungeon_create_cs() : RpcPacket(mpe_rpc_cmd::guild_dungeon_create_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &member);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_dungeon_create_sc : public RpcPacket 	// 문파던전
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};	// 인던 생성 요청 guild_uid
	public:
		mpe_error error{};
	public:
		int32_t index{};	// indun server index
	public:
		int64_t indun_uid{};
	public:
		int32_t tid{};	// indun table id
	public:
		std::vector<int64_t> member{};

	public:
		mrpc_guild_dungeon_create_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_dungeon_create_sc, tag)
		{
		}
		mrpc_guild_dungeon_create_sc() : RpcPacket(mpe_rpc_cmd::guild_dungeon_create_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &error);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &member);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
