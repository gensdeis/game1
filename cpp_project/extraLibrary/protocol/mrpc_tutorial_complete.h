#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_tutorial_complete_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<uint8_t> list_tutorial{};

	public:
		mrpc_tutorial_complete_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::tutorial_complete_cs, tag)
		{
		}
		mrpc_tutorial_complete_cs() : RpcPacket(mpe_rpc_cmd::tutorial_complete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &list_tutorial);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_tutorial_complete_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_tutorial_complete_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::tutorial_complete_sc, tag)
		{
		}
		mrpc_tutorial_complete_sc() : RpcPacket(mpe_rpc_cmd::tutorial_complete_sc)
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
