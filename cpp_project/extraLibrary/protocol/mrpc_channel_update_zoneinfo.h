#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_server_info_list.h"
#include "struct/mrpcs_config_address.h"

namespace mir3d
{
	class mrpc_channel_update_zoneinfo_cs : public RpcPacket 
	{
	private:
		bool flag_info_list = false;
		mrpcs_server_info_list info_list;
		mrpcs_server_info_list* p_info_list = nullptr;
	public:
		bool has_info_list() const
		{
			return flag_info_list;
		}
		mrpcs_server_info_list* alloc_info_list()
		{
			flag_info_list = true;
			return &info_list;
		}
		const mrpcs_server_info_list* get_info_list() const
		{
			if (true == flag_info_list)
			{
				if (nullptr == p_info_list)
				{
					return &info_list;
				}
				return p_info_list;
			}
			return nullptr;
		}
		void set_info_list(mrpcs_server_info_list* in_info_list)
		{
			if (nullptr == p_info_list)
			{
				p_info_list = in_info_list;
				flag_info_list = true;
			}
		}
	public:
		short max_play_user{};
	private:
		bool flag_service_info = false;
		mrpcs_config_address service_info;
		mrpcs_config_address* p_service_info = nullptr;
	public:
		bool has_service_info() const
		{
			return flag_service_info;
		}
		mrpcs_config_address* alloc_service_info()
		{
			flag_service_info = true;
			return &service_info;
		}
		const mrpcs_config_address* get_service_info() const
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
		void set_service_info(mrpcs_config_address* in_service_info)
		{
			if (nullptr == p_service_info)
			{
				p_service_info = in_service_info;
				flag_service_info = true;
			}
		}

	public:
		mrpc_channel_update_zoneinfo_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::channel_update_zoneinfo_cs, tag)
		{
		}
		mrpc_channel_update_zoneinfo_cs() : RpcPacket(mpe_rpc_cmd::channel_update_zoneinfo_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info_list);
			if (true == flag_info_list)
			{
				if (nullptr != p_info_list)
					protocol::SerializeType(pBuffer, p_info_list);
				else
					protocol::SerializeType(pBuffer, &info_list);
			}
			protocol::SerializeType(pBuffer, &max_play_user);
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
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_channel_update_zoneinfo_sc : public RpcPacket 
	{
	public:
		int64_t channel_uid{};
	public:
		uint16_t channel_id{};

	public:
		mrpc_channel_update_zoneinfo_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::channel_update_zoneinfo_sc, tag)
		{
		}
		mrpc_channel_update_zoneinfo_sc() : RpcPacket(mpe_rpc_cmd::channel_update_zoneinfo_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &channel_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
