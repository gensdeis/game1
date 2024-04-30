#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_dimension_dungeon_contribution_buff_cs : public RpcPacket 
	{

	public:
		mrpc_dimension_dungeon_contribution_buff_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_buff_cs, tag)
		{
		}
		mrpc_dimension_dungeon_contribution_buff_cs() : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_buff_cs)
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

	class mrpc_dimension_dungeon_contribution_buff_sc : public RpcPacket 
	{
	public:
		int32_t rank{};	// 기여도 랭킹
	public:
		bool on_off{};	// 버프 적용 유무
	public:
		int32_t map_tag{};	// zone 스레드 인덱스

	public:
		mrpc_dimension_dungeon_contribution_buff_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_buff_sc, tag)
		{
		}
		mrpc_dimension_dungeon_contribution_buff_sc() : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_buff_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &on_off);
			protocol::SerializeType(pBuffer, &map_tag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
