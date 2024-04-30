#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_friend_target_delete_cs : public RpcPacket 	// 친구삭제 리뉴얼(상대방의 나에대한 친구삭제)
	{

	public:
		mrpc_friend_target_delete_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::friend_target_delete_cs, tag)
		{
		}
		mrpc_friend_target_delete_cs() : RpcPacket(mpe_rpc_cmd::friend_target_delete_cs)
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

	class mrpc_friend_target_delete_sc : public RpcPacket 	// 친구삭제 리뉴얼(상대방의 나에대한 친구삭제)
	{
	public:
		int64_t cuid{};	// 삭제대상이 되는 상대방 아이디
	public:
		int64_t target_cuid{};	// 자신의 아이디

	public:
		mrpc_friend_target_delete_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::friend_target_delete_sc, tag)
		{
		}
		mrpc_friend_target_delete_sc() : RpcPacket(mpe_rpc_cmd::friend_target_delete_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
