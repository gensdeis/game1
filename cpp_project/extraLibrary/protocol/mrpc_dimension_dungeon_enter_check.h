#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_dimension_dungeon_enter_check_cs : public RpcPacket 	// 월드게임매니저에 차원비경 입장 가능 체크
	{
	public:
		int64_t key{};	// 유저세션
	public:
		int32_t view_point_id{};	// 거점아이디 - 응답시 필요
	public:
		mpe_teleport_type tel_type{};	// 텔레포트타입 - 응답시 필요

	public:
		mrpc_dimension_dungeon_enter_check_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dimension_dungeon_enter_check_cs, tag)
		{
		}
		mrpc_dimension_dungeon_enter_check_cs() : RpcPacket(mpe_rpc_cmd::dimension_dungeon_enter_check_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &view_point_id);
			protocol::SerializeEnum(pBuffer, &tel_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_dimension_dungeon_enter_check_sc : public RpcPacket 	// 월드게임매니저에 차원비경 입장 가능 체크
	{
	public:
		int64_t key{};	// 유저세션
	public:
		mpe_dimension_dungeon_schedule_type schedule_type{};	// 차원비경의 스케쥴 상태
	public:
		int32_t view_point_id{};	// 거점아이디 - 응답 전달
	public:
		mpe_teleport_type tel_type{};	// 텔레포트타입 - 응답 전달

	public:
		mrpc_dimension_dungeon_enter_check_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dimension_dungeon_enter_check_sc, tag)
		{
		}
		mrpc_dimension_dungeon_enter_check_sc() : RpcPacket(mpe_rpc_cmd::dimension_dungeon_enter_check_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &schedule_type);
			protocol::SerializeType(pBuffer, &view_point_id);
			protocol::SerializeEnum(pBuffer, &tel_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
