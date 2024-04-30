#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_server_managed_rpc_info.h"

namespace mir3d
{
	class mrpc_update_debug_print_rpcinfo_cs : public RpcPacket 
	{
	public:
		int32_t gid{};
	private:
		bool flag_info = false;
		mrpcs_server_managed_rpc_info info;
		mrpcs_server_managed_rpc_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_server_managed_rpc_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_server_managed_rpc_info* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mrpcs_server_managed_rpc_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_update_debug_print_rpcinfo_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::update_debug_print_rpcinfo_cs, tag)
		{
		}
		mrpc_update_debug_print_rpcinfo_cs() : RpcPacket(mpe_rpc_cmd::update_debug_print_rpcinfo_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_update_debug_print_rpcinfo_sc : public RpcPacket 
	{

	public:
		mrpc_update_debug_print_rpcinfo_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::update_debug_print_rpcinfo_sc, tag)
		{
		}
		mrpc_update_debug_print_rpcinfo_sc() : RpcPacket(mpe_rpc_cmd::update_debug_print_rpcinfo_sc)
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

}
