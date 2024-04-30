#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_darksteel_storage_darksteel_pay_cs : public RpcPacket 	// 비곡창고 흑철지급
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		mpe_darksteel_storage_pay_type type{};
	public:
		std::vector<int64_t> list_uid{};	// 지급 대상 uid
	public:
		int32_t count{};

	public:
		mrpc_darksteel_storage_darksteel_pay_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::darksteel_storage_darksteel_pay_cs, tag)
		{
		}
		mrpc_darksteel_storage_darksteel_pay_cs() : RpcPacket(mpe_rpc_cmd::darksteel_storage_darksteel_pay_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &list_uid);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_darksteel_storage_darksteel_pay_sc : public RpcPacket 	// 비곡창고 흑철지급
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};	// CUID
	public:
		mpe_error result{};

	public:
		mrpc_darksteel_storage_darksteel_pay_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::darksteel_storage_darksteel_pay_sc, tag)
		{
		}
		mrpc_darksteel_storage_darksteel_pay_sc() : RpcPacket(mpe_rpc_cmd::darksteel_storage_darksteel_pay_sc)
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
