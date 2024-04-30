#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_castle_town_house_fire_cs : public RpcPacket 	// 장원 고용 해제
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t town_id{};
	public:
		mpe_castle_town_detail_pos house_pos{};

	public:
		mrpc_castle_town_house_fire_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_house_fire_cs, tag)
		{
		}
		mrpc_castle_town_house_fire_cs() : RpcPacket(mpe_rpc_cmd::castle_town_house_fire_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeEnum(pBuffer, &house_pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_castle_town_house_fire_sc : public RpcPacket 	// 장원 고용 해제
	{
	public:
		int64_t key{};
	public:
		int32_t town_id{};
	public:
		mpe_castle_town_detail_pos house_pos{};	// house 고용 타입
	public:
		int64_t end_time{};

	public:
		mrpc_castle_town_house_fire_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_house_fire_sc, tag)
		{
		}
		mrpc_castle_town_house_fire_sc() : RpcPacket(mpe_rpc_cmd::castle_town_house_fire_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeEnum(pBuffer, &house_pos);
			protocol::SerializeType(pBuffer, &end_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
