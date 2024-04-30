#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mandala_layer_info.h"
#include "struct/mps_mandala_node_info.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_mandala_rotation_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_mandala_layer_info> list_layer{};
	public:
		std::vector<mps_mandala_node_info> list_node{};
	private:
		bool flag_item_add = false;
		mps_item_add item_add;
		mps_item_add* p_item_add = nullptr;
	public:
		bool has_item_add() const
		{
			return flag_item_add;
		}
		mps_item_add* alloc_item_add()
		{
			flag_item_add = true;
			return &item_add;
		}
		const mps_item_add* get_item_add() const
		{
			if (true == flag_item_add)
			{
				if (nullptr == p_item_add)
				{
					return &item_add;
				}
				return p_item_add;
			}
			return nullptr;
		}
		void set_item_add(mps_item_add* in_item_add)
		{
			if (nullptr == p_item_add)
			{
				p_item_add = in_item_add;
				flag_item_add = true;
			}
		}
	public:
		mpe_mandala_type mandala_type{};

	public:
		mrpc_mandala_rotation_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mandala_rotation_cs, tag)
		{
		}
		mrpc_mandala_rotation_cs() : RpcPacket(mpe_rpc_cmd::mandala_rotation_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &list_layer);
			protocol::SerializeType(pBuffer, &list_node);
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
			protocol::SerializeEnum(pBuffer, &mandala_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_mandala_rotation_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_mandala_rotation_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mandala_rotation_sc, tag)
		{
		}
		mrpc_mandala_rotation_sc() : RpcPacket(mpe_rpc_cmd::mandala_rotation_sc)
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
