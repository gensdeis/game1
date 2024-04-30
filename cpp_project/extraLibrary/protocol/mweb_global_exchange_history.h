﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_global_exchange_history.h"

namespace mir3d
{
	class mweb_global_exchange_history_cs : public WebBasePacket 
	{
	public:
		int64_t cuid{};
	public:
		mpe_exchange_type type{};

	public:
		mweb_global_exchange_history_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_global_exchange_history_sc : public WebBasePacket 
	{
	private:
		bool flag_info = false;
		mps_global_exchange_history info;
		mps_global_exchange_history* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_global_exchange_history* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_global_exchange_history* get_info() const
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
		void set_info(mps_global_exchange_history* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mweb_global_exchange_history_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
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
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
