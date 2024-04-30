#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_server_maintenance_store_info.h"

namespace mir3d
{
	class mweb_gm_maintenance_store_update_cs : public WebBasePacket 
	{
	public:
		int32_t gid{};
	private:
		bool flag_server_maintenance_store_info = false;
		mrpcs_server_maintenance_store_info server_maintenance_store_info;
		mrpcs_server_maintenance_store_info* p_server_maintenance_store_info = nullptr;
	public:
		bool has_server_maintenance_store_info() const
		{
			return flag_server_maintenance_store_info;
		}
		mrpcs_server_maintenance_store_info* alloc_server_maintenance_store_info()
		{
			flag_server_maintenance_store_info = true;
			return &server_maintenance_store_info;
		}
		const mrpcs_server_maintenance_store_info* get_server_maintenance_store_info() const
		{
			if (true == flag_server_maintenance_store_info)
			{
				if (nullptr == p_server_maintenance_store_info)
				{
					return &server_maintenance_store_info;
				}
				return p_server_maintenance_store_info;
			}
			return nullptr;
		}
		void set_server_maintenance_store_info(mrpcs_server_maintenance_store_info* in_server_maintenance_store_info)
		{
			if (nullptr == p_server_maintenance_store_info)
			{
				p_server_maintenance_store_info = in_server_maintenance_store_info;
				flag_server_maintenance_store_info = true;
			}
		}

	public:
		mweb_gm_maintenance_store_update_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &flag_server_maintenance_store_info);
			if (true == flag_server_maintenance_store_info)
			{
				if (nullptr != p_server_maintenance_store_info)
					protocol::SerializeType(pBuffer, p_server_maintenance_store_info);
				else
					protocol::SerializeType(pBuffer, &server_maintenance_store_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_maintenance_store_update_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_gm_maintenance_store_update_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
