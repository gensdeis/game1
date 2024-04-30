#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_darksteel_storage_darksteel_withdraw_cs : public RpcPacket 	// 비곡창고 흑철회수
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};	// CUID
	public:
		int64_t guid{};	// GUID
	public:
		int64_t count{};	// 수량

	public:
		mrpc_darksteel_storage_darksteel_withdraw_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::darksteel_storage_darksteel_withdraw_cs, tag)
		{
		}
		mrpc_darksteel_storage_darksteel_withdraw_cs() : RpcPacket(mpe_rpc_cmd::darksteel_storage_darksteel_withdraw_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_darksteel_storage_darksteel_withdraw_sc : public RpcPacket 	// 비곡창고 흑철회수
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};	// CUID
	public:
		mpe_error result{};

	public:
		mrpc_darksteel_storage_darksteel_withdraw_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::darksteel_storage_darksteel_withdraw_sc, tag)
		{
		}
		mrpc_darksteel_storage_darksteel_withdraw_sc() : RpcPacket(mpe_rpc_cmd::darksteel_storage_darksteel_withdraw_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
