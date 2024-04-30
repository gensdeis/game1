#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_zone_info.h"

namespace mir3d
{
	class mrpc_mentor_teleport_check_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t target_cuid{};

	public:
		mrpc_mentor_teleport_check_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mentor_teleport_check_cs, tag)
		{
		}
		mrpc_mentor_teleport_check_cs() : RpcPacket(mpe_rpc_cmd::mentor_teleport_check_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_mentor_teleport_check_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_zone_info = false;
		mps_zone_info zone_info;
		mps_zone_info* p_zone_info = nullptr;
	public:
		bool has_zone_info() const
		{
			return flag_zone_info;
		}
		mps_zone_info* alloc_zone_info()
		{
			flag_zone_info = true;
			return &zone_info;
		}
		const mps_zone_info* get_zone_info() const
		{
			if (true == flag_zone_info)
			{
				if (nullptr == p_zone_info)
				{
					return &zone_info;
				}
				return p_zone_info;
			}
			return nullptr;
		}
		void set_zone_info(mps_zone_info* in_zone_info)
		{
			if (nullptr == p_zone_info)
			{
				p_zone_info = in_zone_info;
				flag_zone_info = true;
			}
		}
	public:
		uint16_t channel_id{};

	public:
		mrpc_mentor_teleport_check_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mentor_teleport_check_sc, tag)
		{
		}
		mrpc_mentor_teleport_check_sc() : RpcPacket(mpe_rpc_cmd::mentor_teleport_check_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_zone_info);
			if (true == flag_zone_info)
			{
				if (nullptr != p_zone_info)
					protocol::SerializeType(pBuffer, p_zone_info);
				else
					protocol::SerializeType(pBuffer, &zone_info);
			}
			protocol::SerializeType(pBuffer, &channel_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
