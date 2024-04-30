#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_list_dictionary_info.h"
#include "struct/mps_achieve_rate_info.h"

namespace mir3d
{
	class mrpc_gm_dictionary_add_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		short type{};
	public:
		std::vector<mps_list_dictionary_info> list_dic{};
	public:
		std::vector<mps_achieve_rate_info> list_rate{};

	public:
		mrpc_gm_dictionary_add_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_dictionary_add_cs, tag)
		{
		}
		mrpc_gm_dictionary_add_cs() : RpcPacket(mpe_rpc_cmd::gm_dictionary_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &list_dic);
			protocol::SerializeType(pBuffer, &list_rate);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_dictionary_add_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gm_dictionary_add_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_dictionary_add_sc, tag)
		{
		}
		mrpc_gm_dictionary_add_sc() : RpcPacket(mpe_rpc_cmd::gm_dictionary_add_sc)
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
