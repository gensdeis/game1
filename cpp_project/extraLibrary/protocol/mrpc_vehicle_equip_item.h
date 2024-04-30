#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_list_vehicle_equip_item.h"

namespace mir3d
{
	class mrpc_vehicle_equip_item_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t vehicle_tid{};
	private:
		bool flag_info = false;
		mps_list_vehicle_equip_item info;
		mps_list_vehicle_equip_item* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_list_vehicle_equip_item* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_list_vehicle_equip_item* get_info() const
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
		void set_info(mps_list_vehicle_equip_item* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_vehicle_equip_item_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::vehicle_equip_item_cs, tag)
		{
		}
		mrpc_vehicle_equip_item_cs() : RpcPacket(mpe_rpc_cmd::vehicle_equip_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &vehicle_tid);
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

	class mrpc_vehicle_equip_item_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_vehicle_equip_item_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::vehicle_equip_item_sc, tag)
		{
		}
		mrpc_vehicle_equip_item_sc() : RpcPacket(mpe_rpc_cmd::vehicle_equip_item_sc)
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
