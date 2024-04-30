﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_exchange_history.h"

namespace mir3d
{
	class mp_gate_world_exchange_history_cs : public BasePacket 
	{
	public:
		int64_t cuid{};

	public:
		mp_gate_world_exchange_history_cs() : BasePacket(mpe_cmd::gate_world_exchange_history_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_world_exchange_history_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_exchange_history info;
		mps_exchange_history* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_exchange_history* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_exchange_history* get_info() const
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
		void set_info(mps_exchange_history* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_gate_world_exchange_history_sc() : BasePacket(mpe_cmd::gate_world_exchange_history_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
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
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
