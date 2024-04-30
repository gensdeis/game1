#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_gameitem_option_update.h"

namespace mir3d
{
	class mrpc_gameitem_option_update_cs : public RpcPacket 
	{

	public:
		mrpc_gameitem_option_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gameitem_option_update_cs, tag)
		{
		}
		mrpc_gameitem_option_update_cs() : RpcPacket(mpe_rpc_cmd::gameitem_option_update_cs)
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

	class mrpc_gameitem_option_update_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mrpcs_gameitem_option_update> info{};

	public:
		mrpc_gameitem_option_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gameitem_option_update_sc, tag)
		{
		}
		mrpc_gameitem_option_update_sc() : RpcPacket(mpe_rpc_cmd::gameitem_option_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
