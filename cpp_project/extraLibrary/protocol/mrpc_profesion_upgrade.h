﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_profesion_update.h"

namespace mir3d
{
	class mrpc_profesion_upgrade_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_info = false;
		mps_profesion_update info;	// 대가정보
		mps_profesion_update* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_profesion_update* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_profesion_update* get_info() const
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
		void set_info(mps_profesion_update* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_profesion_upgrade_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::profesion_upgrade_cs, tag)
		{
		}
		mrpc_profesion_upgrade_cs() : RpcPacket(mpe_rpc_cmd::profesion_upgrade_cs)
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

	class mrpc_profesion_upgrade_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_profesion_upgrade_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::profesion_upgrade_sc, tag)
		{
		}
		mrpc_profesion_upgrade_sc() : RpcPacket(mpe_rpc_cmd::profesion_upgrade_sc)
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
