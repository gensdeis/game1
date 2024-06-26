﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_item_use_change_nickname_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int64_t iuid{};
	public:
		int64_t puid{};
	public:
		std::string new_nickname{};
	public:
		std::string old_nickname{};
	private:
		bool flag_info = false;
		mps_item_add info;
		mps_item_add* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_add* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_add* get_info() const
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
		void set_info(mps_item_add* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		mpe_update_type update_type{};
	public:
		int32_t update_value{};

	public:
		mrpc_item_use_change_nickname_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::item_use_change_nickname_cs, tag)
		{
		}
		mrpc_item_use_change_nickname_cs() : RpcPacket(mpe_rpc_cmd::item_use_change_nickname_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &new_nickname);
			protocol::SerializeType(pBuffer, &old_nickname);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeEnum(pBuffer, &update_type);
			protocol::SerializeType(pBuffer, &update_value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_item_use_change_nickname_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_item_use_change_nickname_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::item_use_change_nickname_sc, tag)
		{
		}
		mrpc_item_use_change_nickname_sc() : RpcPacket(mpe_rpc_cmd::item_use_change_nickname_sc)
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
