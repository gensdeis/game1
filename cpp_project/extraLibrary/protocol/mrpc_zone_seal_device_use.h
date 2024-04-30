﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mrpc_zone_seal_device_use_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_info = false;
		mps_item_count_update info;	// 아이템 정보
		mps_item_count_update* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_count_update* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_count_update* get_info() const
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
		void set_info(mps_item_count_update* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_zone_seal_device_use_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::zone_seal_device_use_cs, tag)
		{
		}
		mrpc_zone_seal_device_use_cs() : RpcPacket(mpe_rpc_cmd::zone_seal_device_use_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
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

	class mrpc_zone_seal_device_use_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_zone_seal_device_use_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::zone_seal_device_use_sc, tag)
		{
		}
		mrpc_zone_seal_device_use_sc() : RpcPacket(mpe_rpc_cmd::zone_seal_device_use_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}