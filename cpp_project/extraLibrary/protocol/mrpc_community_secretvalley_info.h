#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_community_secretvalley_info_cs : public RpcPacket 	// 비곡점령전정보
	{

	public:
		mrpc_community_secretvalley_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_secretvalley_info_cs, tag)
		{
		}
		mrpc_community_secretvalley_info_cs() : RpcPacket(mpe_rpc_cmd::community_secretvalley_info_cs)
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

	class mrpc_community_secretvalley_info_sc : public RpcPacket 	// 비곡점령전정보
	{
	public:
		int32_t gid{};
	public:
		int32_t hp{};	// 점령석 hp
	public:
		int32_t max_hp{};	// 최대hp
	public:
		std::string guild_name{};	// 점령중인문파이름
	public:
		int64_t guild_uid{};	// 점령문파uid
	public:
		std::vector<uint8_t> guild_mark{};	// 점령중인문파문장
	public:
		int32_t occupation_count{};	// 점령 횟수
	public:
		mpe_occupation_state secretvalley_object_state{};	// 점령석 상태
	public:
		int32_t end_time{};	// 점령전 종료 시간
	public:
		int32_t occupation_immune_end_time{};	// 무적 종료 시간

	public:
		mrpc_community_secretvalley_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_secretvalley_info_sc, tag)
		{
		}
		mrpc_community_secretvalley_info_sc() : RpcPacket(mpe_rpc_cmd::community_secretvalley_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &hp);
			protocol::SerializeType(pBuffer, &max_hp);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &guild_uid);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &occupation_count);
			protocol::SerializeEnum(pBuffer, &secretvalley_object_state);
			protocol::SerializeType(pBuffer, &end_time);
			protocol::SerializeType(pBuffer, &occupation_immune_end_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
