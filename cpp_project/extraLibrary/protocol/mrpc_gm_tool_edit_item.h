#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item.h"

namespace mir3d
{
	class mrpc_gm_tool_edit_item_cs : public RpcPacket 
	{
	public:
		int64_t owner_auid{};
	public:
		int64_t owner_cuid{};
	private:
		bool flag_item = false;
		mps_item item;
		mps_item* p_item = nullptr;
	public:
		bool has_item() const
		{
			return flag_item;
		}
		mps_item* alloc_item()
		{
			flag_item = true;
			return &item;
		}
		const mps_item* get_item() const
		{
			if (true == flag_item)
			{
				if (nullptr == p_item)
				{
					return &item;
				}
				return p_item;
			}
			return nullptr;
		}
		void set_item(mps_item* in_item)
		{
			if (nullptr == p_item)
			{
				p_item = in_item;
				flag_item = true;
			}
		}

	public:
		mrpc_gm_tool_edit_item_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_tool_edit_item_cs, tag)
		{
		}
		mrpc_gm_tool_edit_item_cs() : RpcPacket(mpe_rpc_cmd::gm_tool_edit_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &owner_auid);
			protocol::SerializeType(pBuffer, &owner_cuid);
			protocol::SerializeType(pBuffer, &flag_item);
			if (true == flag_item)
			{
				if (nullptr != p_item)
					protocol::SerializeType(pBuffer, p_item);
				else
					protocol::SerializeType(pBuffer, &item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_tool_edit_item_sc : public RpcPacket 
	{

	public:
		mrpc_gm_tool_edit_item_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_tool_edit_item_sc, tag)
		{
		}
		mrpc_gm_tool_edit_item_sc() : RpcPacket(mpe_rpc_cmd::gm_tool_edit_item_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
