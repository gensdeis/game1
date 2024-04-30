#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_global_exchange_context.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_global_exchange_register_cs : public RpcPacket 	// 거래소 처리
	{
	private:
		bool flag_info = false;
		mrpcs_global_exchange_context info;
		mrpcs_global_exchange_context* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_global_exchange_context* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_global_exchange_context* get_info() const
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
		void set_info(mrpcs_global_exchange_context* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_global_exchange_register_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_exchange_register_cs, tag)
		{
		}
		mrpc_global_exchange_register_cs() : RpcPacket(mpe_rpc_cmd::global_exchange_register_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
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

	class mrpc_global_exchange_register_sc : public RpcPacket 	// 거래소 처리
	{
	public:
		int64_t key{};
	public:
		int64_t euid{};
	public:
		int64_t ruid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t server_gid{};
	public:
		bool new_item{};
	public:
		mpe_exchange_type type{};
	private:
		bool flag_info = false;
		mps_item_add info;	// "list_goods, list_update (등록한 아이템, total이 0이면 삭제, 아니면 update)"
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
		mrpc_global_exchange_register_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_exchange_register_sc, tag)
		{
		}
		mrpc_global_exchange_register_sc() : RpcPacket(mpe_rpc_cmd::global_exchange_register_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeType(pBuffer, &ruid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &server_gid);
			protocol::SerializeType(pBuffer, &new_item);
			protocol::SerializeEnum(pBuffer, &type);
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

}
