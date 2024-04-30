#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_dimension_dungeon_contribution_status.h"

namespace mir3d
{
	class mrpc_dimension_dungeon_contribution_item_history_cs : public RpcPacket 	//  WG -> WGM 실시간 차원조각 수급량 전송
	{
	private:
		bool flag_status = false;
		mrpcs_dimension_dungeon_contribution_status status;	// 차원조각 수급량 정보
		mrpcs_dimension_dungeon_contribution_status* p_status = nullptr;
	public:
		bool has_status() const
		{
			return flag_status;
		}
		mrpcs_dimension_dungeon_contribution_status* alloc_status()
		{
			flag_status = true;
			return &status;
		}
		const mrpcs_dimension_dungeon_contribution_status* get_status() const
		{
			if (true == flag_status)
			{
				if (nullptr == p_status)
				{
					return &status;
				}
				return p_status;
			}
			return nullptr;
		}
		void set_status(mrpcs_dimension_dungeon_contribution_status* in_status)
		{
			if (nullptr == p_status)
			{
				p_status = in_status;
				flag_status = true;
			}
		}

	public:
		mrpc_dimension_dungeon_contribution_item_history_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_item_history_cs, tag)
		{
		}
		mrpc_dimension_dungeon_contribution_item_history_cs() : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_item_history_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_status);
			if (true == flag_status)
			{
				if (nullptr != p_status)
					protocol::SerializeType(pBuffer, p_status);
				else
					protocol::SerializeType(pBuffer, &status);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_dimension_dungeon_contribution_item_history_sc : public RpcPacket 	//  WG -> WGM 실시간 차원조각 수급량 전송
	{

	public:
		mrpc_dimension_dungeon_contribution_item_history_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_item_history_sc, tag)
		{
		}
		mrpc_dimension_dungeon_contribution_item_history_sc() : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_item_history_sc)
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
