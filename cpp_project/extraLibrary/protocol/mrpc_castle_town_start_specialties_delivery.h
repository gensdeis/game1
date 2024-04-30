#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_castle_town_start_specialties_delivery_cs : public RpcPacket 	// 장원 납품 시작
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
		mpe_castle_town_specialties_pos specialties_pos{};

	public:
		mrpc_castle_town_start_specialties_delivery_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_start_specialties_delivery_cs, tag)
		{
		}
		mrpc_castle_town_start_specialties_delivery_cs() : RpcPacket(mpe_rpc_cmd::castle_town_start_specialties_delivery_cs)
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
			protocol::SerializeEnum(pBuffer, &specialties_pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_castle_town_start_specialties_delivery_sc : public RpcPacket 	// 장원 납품 시작
	{
	public:
		int64_t key{};
	public:
		int32_t town_id{};
	public:
		mpe_castle_town_specialties_pos specialties_pos{};
	public:
		int64_t end_time{};

	public:
		mrpc_castle_town_start_specialties_delivery_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_start_specialties_delivery_sc, tag)
		{
		}
		mrpc_castle_town_start_specialties_delivery_sc() : RpcPacket(mpe_rpc_cmd::castle_town_start_specialties_delivery_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeEnum(pBuffer, &specialties_pos);
			protocol::SerializeType(pBuffer, &end_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
