#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_pet_info.h"
#include "struct/mps_pet_info.h"

namespace mir3d
{
	class mrpc_pet_equip_cs : public RpcPacket 	// 펫 장착
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_pet_info> equip_pet{};	// 장착펫 index = pet_pos
	public:
		std::vector<mps_pet_info> release_pet{};	// 해제펫 index = pet_pos

	public:
		mrpc_pet_equip_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pet_equip_cs, tag)
		{
		}
		mrpc_pet_equip_cs() : RpcPacket(mpe_rpc_cmd::pet_equip_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &equip_pet);
			protocol::SerializeType(pBuffer, &release_pet);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_pet_equip_sc : public RpcPacket 	// 펫 장착
	{
	public:
		int64_t key{};

	public:
		mrpc_pet_equip_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pet_equip_sc, tag)
		{
		}
		mrpc_pet_equip_sc() : RpcPacket(mpe_rpc_cmd::pet_equip_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
