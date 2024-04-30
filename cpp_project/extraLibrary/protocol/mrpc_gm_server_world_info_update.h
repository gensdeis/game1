﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_server_world_info_list.h"

namespace mir3d
{
	class mrpc_gm_server_world_info_update_cs : public RpcPacket 
	{

	public:
		mrpc_gm_server_world_info_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_server_world_info_update_cs, tag)
		{
		}
		mrpc_gm_server_world_info_update_cs() : RpcPacket(mpe_rpc_cmd::gm_server_world_info_update_cs)
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

	class mrpc_gm_server_world_info_update_sc : public RpcPacket 
	{
	private:
		bool flag_info = false;
		mrpcs_server_world_info_list info;
		mrpcs_server_world_info_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_server_world_info_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_server_world_info_list* get_info() const
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
		void set_info(mrpcs_server_world_info_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_gm_server_world_info_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_server_world_info_update_sc, tag)
		{
		}
		mrpc_gm_server_world_info_update_sc() : RpcPacket(mpe_rpc_cmd::gm_server_world_info_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
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

}