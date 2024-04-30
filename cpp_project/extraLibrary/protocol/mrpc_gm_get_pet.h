#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_pet_info.h"
#include "struct/mps_temp_pet.h"
#include "struct/mps_dictionary_info.h"

namespace mir3d
{
	class mrpc_gm_get_pet_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_pet_info> pet_info{};
	public:
		std::vector<mps_temp_pet> list_temp_pet{};
	public:
		std::vector<mps_dictionary_info> list_dic{};

	public:
		mrpc_gm_get_pet_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_get_pet_cs, tag)
		{
		}
		mrpc_gm_get_pet_cs() : RpcPacket(mpe_rpc_cmd::gm_get_pet_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &pet_info);
			protocol::SerializeType(pBuffer, &list_temp_pet);
			protocol::SerializeType(pBuffer, &list_dic);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_get_pet_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gm_get_pet_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_get_pet_sc, tag)
		{
		}
		mrpc_gm_get_pet_sc() : RpcPacket(mpe_rpc_cmd::gm_get_pet_sc)
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
