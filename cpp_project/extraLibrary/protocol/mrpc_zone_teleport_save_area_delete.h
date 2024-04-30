#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_teleport_area.h"

namespace mir3d
{
	class mrpc_zone_teleport_save_area_delete_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_reg_tel_info = false;
		mps_teleport_area reg_tel_info;
		mps_teleport_area* p_reg_tel_info = nullptr;
	public:
		bool has_reg_tel_info() const
		{
			return flag_reg_tel_info;
		}
		mps_teleport_area* alloc_reg_tel_info()
		{
			flag_reg_tel_info = true;
			return &reg_tel_info;
		}
		const mps_teleport_area* get_reg_tel_info() const
		{
			if (true == flag_reg_tel_info)
			{
				if (nullptr == p_reg_tel_info)
				{
					return &reg_tel_info;
				}
				return p_reg_tel_info;
			}
			return nullptr;
		}
		void set_reg_tel_info(mps_teleport_area* in_reg_tel_info)
		{
			if (nullptr == p_reg_tel_info)
			{
				p_reg_tel_info = in_reg_tel_info;
				flag_reg_tel_info = true;
			}
		}

	public:
		mrpc_zone_teleport_save_area_delete_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::zone_teleport_save_area_delete_cs, tag)
		{
		}
		mrpc_zone_teleport_save_area_delete_cs() : RpcPacket(mpe_rpc_cmd::zone_teleport_save_area_delete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_reg_tel_info);
			if (true == flag_reg_tel_info)
			{
				if (nullptr != p_reg_tel_info)
					protocol::SerializeType(pBuffer, p_reg_tel_info);
				else
					protocol::SerializeType(pBuffer, &reg_tel_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_zone_teleport_save_area_delete_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_zone_teleport_save_area_delete_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::zone_teleport_save_area_delete_sc, tag)
		{
		}
		mrpc_zone_teleport_save_area_delete_sc() : RpcPacket(mpe_rpc_cmd::zone_teleport_save_area_delete_sc)
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
