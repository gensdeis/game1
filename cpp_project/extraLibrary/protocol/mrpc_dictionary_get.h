#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_list_dictionary_info.h"
#include "struct/mps_achieve_rate_info.h"

namespace mir3d
{
	class mrpc_dictionary_get_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t category{};
	public:
		mpe_dictionary_type type{};

	public:
		mrpc_dictionary_get_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dictionary_get_cs, tag)
		{
		}
		mrpc_dictionary_get_cs() : RpcPacket(mpe_rpc_cmd::dictionary_get_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &category);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_dictionary_get_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_list_dictionary_info> list{};
	public:
		int32_t category{};
	public:
		mpe_dictionary_type type{};
	public:
		std::vector<mps_achieve_rate_info> list_rate{};

	public:
		mrpc_dictionary_get_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dictionary_get_sc, tag)
		{
		}
		mrpc_dictionary_get_sc() : RpcPacket(mpe_rpc_cmd::dictionary_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &category);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &list_rate);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
