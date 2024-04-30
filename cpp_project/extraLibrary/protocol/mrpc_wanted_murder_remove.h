#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_wanted_murder_remove_cs : public RpcPacket 	// 캐릭터삭제pk삭제
	{
	public:
		int64_t target_cuid{};

	public:
		mrpc_wanted_murder_remove_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::wanted_murder_remove_cs, tag)
		{
		}
		mrpc_wanted_murder_remove_cs() : RpcPacket(mpe_rpc_cmd::wanted_murder_remove_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_wanted_murder_remove_sc : public RpcPacket 	// 캐릭터삭제pk삭제
	{

	public:
		mrpc_wanted_murder_remove_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::wanted_murder_remove_sc, tag)
		{
		}
		mrpc_wanted_murder_remove_sc() : RpcPacket(mpe_rpc_cmd::wanted_murder_remove_sc)
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
