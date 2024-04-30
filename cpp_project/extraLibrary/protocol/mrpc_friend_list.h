#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_friend_list_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};

	public:
		mrpc_friend_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::friend_list_cs, tag)
		{
		}
		mrpc_friend_list_cs() : RpcPacket(mpe_rpc_cmd::friend_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_friend_list_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		std::vector<int64_t> friend_id_list{};

	public:
		mrpc_friend_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::friend_list_sc, tag)
		{
		}
		mrpc_friend_list_sc() : RpcPacket(mpe_rpc_cmd::friend_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &friend_id_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
