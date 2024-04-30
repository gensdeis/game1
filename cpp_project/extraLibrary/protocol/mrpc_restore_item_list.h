#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_restore_item.h"

namespace mir3d
{
	class mrpc_restore_item_list_cs : public RpcPacket 	// 아이템 복구 리스트 조회 (type별로 호출)
	{
	public:
		mpe_restore_event_type type{};	// 복구 이벤트 타입
	public:
		int64_t key{};
	public:
		int64_t cuid{};

	public:
		mrpc_restore_item_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::restore_item_list_cs, tag)
		{
		}
		mrpc_restore_item_list_cs() : RpcPacket(mpe_rpc_cmd::restore_item_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_restore_item_list_sc : public RpcPacket 	// 아이템 복구 리스트 조회 (type별로 호출)
	{
	public:
		std::vector<mps_restore_item> list{};	// 복구 정보 리스트
	public:
		int64_t key{};
	public:
		mpe_restore_event_type type{};	// 복구 이벤트 타입

	public:
		mrpc_restore_item_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::restore_item_list_sc, tag)
		{
		}
		mrpc_restore_item_list_sc() : RpcPacket(mpe_rpc_cmd::restore_item_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
