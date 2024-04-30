#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_obtain_pet_info.h"
#include "struct/mps_dictionary_info.h"

namespace mir3d
{
	class mrpc_temp_pet_confirm_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<int64_t> del_temp_uid{};
	public:
		std::vector<mps_obtain_pet_info> info{};
	public:
		std::vector<mps_dictionary_info> list_dic{};

	public:
		mrpc_temp_pet_confirm_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::temp_pet_confirm_cs, tag)
		{
		}
		mrpc_temp_pet_confirm_cs() : RpcPacket(mpe_rpc_cmd::temp_pet_confirm_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &del_temp_uid);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &list_dic);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_temp_pet_confirm_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_temp_pet_confirm_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::temp_pet_confirm_sc, tag)
		{
		}
		mrpc_temp_pet_confirm_sc() : RpcPacket(mpe_rpc_cmd::temp_pet_confirm_sc)
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
