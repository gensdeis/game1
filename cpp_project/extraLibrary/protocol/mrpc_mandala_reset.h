#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_mandala_layer_info.h"
#include "struct/mps_equip_info_list.h"

namespace mir3d
{
	class mrpc_mandala_reset_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		mpe_mandala_type mandala_type{};
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
		std::vector<mps_mandala_layer_info> list_layer{};
	private:
		bool flag_equip_info = false;
		mps_equip_info_list equip_info;
		mps_equip_info_list* p_equip_info = nullptr;
	public:
		bool has_equip_info() const
		{
			return flag_equip_info;
		}
		mps_equip_info_list* alloc_equip_info()
		{
			flag_equip_info = true;
			return &equip_info;
		}
		const mps_equip_info_list* get_equip_info() const
		{
			if (true == flag_equip_info)
			{
				if (nullptr == p_equip_info)
				{
					return &equip_info;
				}
				return p_equip_info;
			}
			return nullptr;
		}
		void set_equip_info(mps_equip_info_list* in_equip_info)
		{
			if (nullptr == p_equip_info)
			{
				p_equip_info = in_equip_info;
				flag_equip_info = true;
			}
		}

	public:
		mrpc_mandala_reset_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mandala_reset_cs, tag)
		{
		}
		mrpc_mandala_reset_cs() : RpcPacket(mpe_rpc_cmd::mandala_reset_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &mandala_type);
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
			protocol::SerializeType(pBuffer, &list_layer);
			protocol::SerializeType(pBuffer, &flag_equip_info);
			if (true == flag_equip_info)
			{
				if (nullptr != p_equip_info)
					protocol::SerializeType(pBuffer, p_equip_info);
				else
					protocol::SerializeType(pBuffer, &equip_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_mandala_reset_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_mandala_reset_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mandala_reset_sc, tag)
		{
		}
		mrpc_mandala_reset_sc() : RpcPacket(mpe_rpc_cmd::mandala_reset_sc)
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
