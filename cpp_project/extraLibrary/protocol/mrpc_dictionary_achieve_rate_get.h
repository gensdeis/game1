#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_achieve_rate_info.h"

namespace mir3d
{
	class mrpc_dictionary_achieve_rate_get_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t collection_id{};

	public:
		mrpc_dictionary_achieve_rate_get_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dictionary_achieve_rate_get_cs, tag)
		{
		}
		mrpc_dictionary_achieve_rate_get_cs() : RpcPacket(mpe_rpc_cmd::dictionary_achieve_rate_get_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &collection_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_dictionary_achieve_rate_get_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t collection_id{};
	public:
		std::vector<mps_achieve_rate_info> list_info{};

	public:
		mrpc_dictionary_achieve_rate_get_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dictionary_achieve_rate_get_sc, tag)
		{
		}
		mrpc_dictionary_achieve_rate_get_sc() : RpcPacket(mpe_rpc_cmd::dictionary_achieve_rate_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &collection_id);
			protocol::SerializeType(pBuffer, &list_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
