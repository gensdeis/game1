#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_contents_onoff_info.h"

namespace mir3d
{
	class mrpc_contents_onoff_list_cs : public RpcPacket 
	{
	public:
		mrpce_server_type type{};
	public:
		int32_t index{};

	public:
		mrpc_contents_onoff_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::contents_onoff_list_cs, tag)
		{
		}
		mrpc_contents_onoff_list_cs() : RpcPacket(mpe_rpc_cmd::contents_onoff_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_contents_onoff_list_sc : public RpcPacket 
	{
	public:
		mrpce_server_type type{};
	public:
		int32_t index{};
	public:
		std::vector<mrpcs_contents_onoff_info> list{};

	public:
		mrpc_contents_onoff_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::contents_onoff_list_sc, tag)
		{
		}
		mrpc_contents_onoff_list_sc() : RpcPacket(mpe_rpc_cmd::contents_onoff_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
