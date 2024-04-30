#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_server_relocation_recovery_item_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};	// 캐릭터UID
	private:
		bool flag_info = false;
		mps_item_add info;	// 표국통행 사용된 아이템 복구 정보
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
		mrpc_server_relocation_recovery_item_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_relocation_recovery_item_cs, tag)
		{
		}
		mrpc_server_relocation_recovery_item_cs() : RpcPacket(mpe_rpc_cmd::server_relocation_recovery_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
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

	class mrpc_server_relocation_recovery_item_sc : public RpcPacket 
	{

	public:
		mrpc_server_relocation_recovery_item_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_relocation_recovery_item_sc, tag)
		{
		}
		mrpc_server_relocation_recovery_item_sc() : RpcPacket(mpe_rpc_cmd::server_relocation_recovery_item_sc)
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
