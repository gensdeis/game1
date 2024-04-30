﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_redis_server_info.h"

namespace mir3d
{
	class mrpc_update_redis_server_info_cs : public RpcPacket 
	{
	private:
		bool flag_info = false;
		mrpcs_redis_server_info info;
		mrpcs_redis_server_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_redis_server_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_redis_server_info* get_info() const
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
		void set_info(mrpcs_redis_server_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_update_redis_server_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::update_redis_server_info_cs, tag)
		{
		}
		mrpc_update_redis_server_info_cs() : RpcPacket(mpe_rpc_cmd::update_redis_server_info_cs)
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

	class mrpc_update_redis_server_info_sc : public RpcPacket 
	{

	public:
		mrpc_update_redis_server_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::update_redis_server_info_sc, tag)
		{
		}
		mrpc_update_redis_server_info_sc() : RpcPacket(mpe_rpc_cmd::update_redis_server_info_sc)
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
