#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mrpcs_castle_tax_value.h"

namespace mir3d
{
	class mrpc_item_sell_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
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
	private:
		bool flag_castle_tax = false;
		mrpcs_castle_tax_value castle_tax;
		mrpcs_castle_tax_value* p_castle_tax = nullptr;
	public:
		bool has_castle_tax() const
		{
			return flag_castle_tax;
		}
		mrpcs_castle_tax_value* alloc_castle_tax()
		{
			flag_castle_tax = true;
			return &castle_tax;
		}
		const mrpcs_castle_tax_value* get_castle_tax() const
		{
			if (true == flag_castle_tax)
			{
				if (nullptr == p_castle_tax)
				{
					return &castle_tax;
				}
				return p_castle_tax;
			}
			return nullptr;
		}
		void set_castle_tax(mrpcs_castle_tax_value* in_castle_tax)
		{
			if (nullptr == p_castle_tax)
			{
				p_castle_tax = in_castle_tax;
				flag_castle_tax = true;
			}
		}

	public:
		mrpc_item_sell_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::item_sell_cs, tag)
		{
		}
		mrpc_item_sell_cs() : RpcPacket(mpe_rpc_cmd::item_sell_cs)
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
			protocol::SerializeType(pBuffer, &flag_castle_tax);
			if (true == flag_castle_tax)
			{
				if (nullptr != p_castle_tax)
					protocol::SerializeType(pBuffer, p_castle_tax);
				else
					protocol::SerializeType(pBuffer, &castle_tax);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_item_sell_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_item_sell_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::item_sell_sc, tag)
		{
		}
		mrpc_item_sell_sc() : RpcPacket(mpe_rpc_cmd::item_sell_sc)
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
