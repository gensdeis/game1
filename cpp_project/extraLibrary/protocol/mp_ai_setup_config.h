#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_ai_setup_config.h"

namespace mir3d
{
	class mp_ai_setup_config_cs : public BasePacket 
	{
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
		mp_ai_setup_config_cs() : BasePacket(mpe_cmd::ai_setup_config_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_config_data);
			if (true == flag_config_data)
			{
				if (nullptr != p_config_data)
					protocol::SerializeType(pBuffer, p_config_data);
				else
					protocol::SerializeType(pBuffer, &config_data);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_ai_setup_config_sc : public BasePacket 
	{

	public:
		mp_ai_setup_config_sc() : BasePacket(mpe_cmd::ai_setup_config_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
