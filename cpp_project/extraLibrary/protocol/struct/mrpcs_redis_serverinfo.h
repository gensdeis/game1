#pragma once
#include <vector>
#include <string>
#include "mrpcs_redis_rpcinfo.h"
#include "mrpcs_redis_rpcinfo.h"

namespace mir3d
{
	class mrpcs_redis_serverinfo 
	{
	private:
		bool flag_rpc_info = false;
		mrpcs_redis_rpcinfo rpc_info;
		mrpcs_redis_rpcinfo* p_rpc_info = nullptr;
	public:
		bool has_rpc_info() const
		{
			return flag_rpc_info;
		}
		mrpcs_redis_rpcinfo* alloc_rpc_info()
		{
			flag_rpc_info = true;
			return &rpc_info;
		}
		const mrpcs_redis_rpcinfo* get_rpc_info() const
		{
			if (true == flag_rpc_info)
			{
				if (nullptr == p_rpc_info)
				{
					return &rpc_info;
				}
				return p_rpc_info;
			}
			return nullptr;
		}
		void set_rpc_info(mrpcs_redis_rpcinfo* in_rpc_info)
		{
			if (nullptr == p_rpc_info)
			{
				p_rpc_info = in_rpc_info;
				flag_rpc_info = true;
			}
		}
	private:
		bool flag_service_info = false;
		mrpcs_redis_rpcinfo service_info;
		mrpcs_redis_rpcinfo* p_service_info = nullptr;
	public:
		bool has_service_info() const
		{
			return flag_service_info;
		}
		mrpcs_redis_rpcinfo* alloc_service_info()
		{
			flag_service_info = true;
			return &service_info;
		}
		const mrpcs_redis_rpcinfo* get_service_info() const
		{
			if (true == flag_service_info)
			{
				if (nullptr == p_service_info)
				{
					return &service_info;
				}
				return p_service_info;
			}
			return nullptr;
		}
		void set_service_info(mrpcs_redis_rpcinfo* in_service_info)
		{
			if (nullptr == p_service_info)
			{
				p_service_info = in_service_info;
				flag_service_info = true;
			}
		}

	public:
		mrpcs_redis_serverinfo()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &flag_rpc_info);
			if (true == flag_rpc_info)
			{
				if (nullptr != p_rpc_info)
					protocol::SerializeType(pBuffer, p_rpc_info);
				else
					protocol::SerializeType(pBuffer, &rpc_info);
			}
			protocol::SerializeType(pBuffer, &flag_service_info);
			if (true == flag_service_info)
			{
				if (nullptr != p_service_info)
					protocol::SerializeType(pBuffer, p_service_info);
				else
					protocol::SerializeType(pBuffer, &service_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
