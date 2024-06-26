﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_exchange_market_price.h"

namespace mir3d
{
	class mp_gate_exchange_marketprice_cs : public BasePacket 
	{
	public:
		uint16_t id{};

	public:
		mp_gate_exchange_marketprice_cs() : BasePacket(mpe_cmd::gate_exchange_marketprice_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_exchange_marketprice_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_exchange_market_price info;
		mps_exchange_market_price* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_exchange_market_price* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_exchange_market_price* get_info() const
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
		void set_info(mps_exchange_market_price* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_gate_exchange_marketprice_sc() : BasePacket(mpe_cmd::gate_exchange_marketprice_sc)
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
