#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_shipwar_create_cs : public RpcPacket 	// 문파대전
	{
	public:
		int64_t match_uid{};
	public:
		int64_t guid_A{};
	public:
		std::string guild_name_A{};
	public:
		int32_t guid_rank_A{};
	public:
		std::vector<uint8_t> guild_mark_A{};	// 문파 문장
	public:
		int32_t guild_gid_A{};
	public:
		int32_t guild_rank_score_A{};
	public:
		int64_t guid_B{};
	public:
		std::string guild_name_B{};
	public:
		int32_t guid_rank_B{};
	public:
		std::vector<uint8_t> guild_mark_B{};	// 문파 문장
	public:
		int32_t guild_gid_B{};
	public:
		int32_t guild_rank_score_B{};
	public:
		int32_t tid{};
	public:
		int64_t enter_time{};

	public:
		mrpc_guild_shipwar_create_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_shipwar_create_cs, tag)
		{
		}
		mrpc_guild_shipwar_create_cs() : RpcPacket(mpe_rpc_cmd::guild_shipwar_create_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &match_uid);
			protocol::SerializeType(pBuffer, &guid_A);
			protocol::SerializeType(pBuffer, &guild_name_A);
			protocol::SerializeType(pBuffer, &guid_rank_A);
			protocol::SerializeType(pBuffer, &guild_mark_A);
			protocol::SerializeType(pBuffer, &guild_gid_A);
			protocol::SerializeType(pBuffer, &guild_rank_score_A);
			protocol::SerializeType(pBuffer, &guid_B);
			protocol::SerializeType(pBuffer, &guild_name_B);
			protocol::SerializeType(pBuffer, &guid_rank_B);
			protocol::SerializeType(pBuffer, &guild_mark_B);
			protocol::SerializeType(pBuffer, &guild_gid_B);
			protocol::SerializeType(pBuffer, &guild_rank_score_B);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &enter_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_shipwar_create_sc : public RpcPacket 	// 문파대전
	{
	public:
		int64_t match_uid{};
	public:
		mpe_error error{};
	public:
		int64_t guid_a{};
	public:
		int32_t index{};	// indun server index
	public:
		int64_t indun_uid{};
	public:
		int32_t tid{};	// indun table id
	public:
		int64_t guid_b{};

	public:
		mrpc_guild_shipwar_create_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_shipwar_create_sc, tag)
		{
		}
		mrpc_guild_shipwar_create_sc() : RpcPacket(mpe_rpc_cmd::guild_shipwar_create_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &match_uid);
			protocol::SerializeEnum(pBuffer, &error);
			protocol::SerializeType(pBuffer, &guid_a);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &guid_b);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
