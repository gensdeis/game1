#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_restore_compose.h"

namespace mir3d
{
	class mrpc_restore_compose_list_cs : public RpcPacket 	// 합성 실패 이력 조회 (일괄조회)
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};

	public:
		mrpc_restore_compose_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::restore_compose_list_cs, tag)
		{
		}
		mrpc_restore_compose_list_cs() : RpcPacket(mpe_rpc_cmd::restore_compose_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_restore_compose_list_sc : public RpcPacket 	// 합성 실패 이력 조회 (일괄조회)
	{
	public:
		std::vector<mps_restore_compose> list{};	// 복구 정보 리스트 (화신/영물 타입별 grade와 복구여부)
	public:
		int64_t key{};

	public:
		mrpc_restore_compose_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::restore_compose_list_sc, tag)
		{
		}
		mrpc_restore_compose_list_sc() : RpcPacket(mpe_rpc_cmd::restore_compose_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
