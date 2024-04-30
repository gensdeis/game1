#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_ai_setup_config.h"

namespace mir3d
{
	class mrpc_start_ai_service_cs : public RpcPacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string user_name{};
	public:
		int32_t object_map_id{};

	public:
		mrpc_start_ai_service_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::start_ai_service_cs, tag)
		{
		}
		mrpc_start_ai_service_cs() : RpcPacket(mpe_rpc_cmd::start_ai_service_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &user_name);
			protocol::SerializeType(pBuffer, &object_map_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_start_ai_service_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		std::string user_name{};
	private:
		bool flag_config_data = false;
		mps_ai_setup_config config_data;
		mps_ai_setup_config* p_config_data = nullptr;
	public:
		bool has_config_data() const
		{
			return flag_config_data;
		}
		mps_ai_setup_config* alloc_config_data()
		{
			flag_config_data = true;
			return &config_data;
		}
		const mps_ai_setup_config* get_config_data() const
		{
			if (true == flag_config_data)
			{
				if (nullptr == p_config_data)
				{
					return &config_data;
				}
				return p_config_data;
			}
			return nullptr;
		}
		void set_config_data(mps_ai_setup_config* in_config_data)
		{
			if (nullptr == p_config_data)
			{
				p_config_data = in_config_data;
				flag_config_data = true;
			}
		}
	public:
		int32_t object_map_id{};

	public:
		mrpc_start_ai_service_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::start_ai_service_sc, tag)
		{
		}
		mrpc_start_ai_service_sc() : RpcPacket(mpe_rpc_cmd::start_ai_service_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &user_name);
			protocol::SerializeType(pBuffer, &flag_config_data);
			if (true == flag_config_data)
			{
				if (nullptr != p_config_data)
					protocol::SerializeType(pBuffer, p_config_data);
				else
					protocol::SerializeType(pBuffer, &config_data);
			}
			protocol::SerializeType(pBuffer, &object_map_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
