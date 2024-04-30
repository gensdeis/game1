#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_siege_warfare_submit_tender_cs : public RpcPacket 	// 공성전 입찰 제출
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		mpe_siege_castle_type castle_type{};	// 성타입
	public:
		int32_t tender_value{};	// 입찰금액

	public:
		mrpc_siege_warfare_submit_tender_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_submit_tender_cs, tag)
		{
		}
		mrpc_siege_warfare_submit_tender_cs() : RpcPacket(mpe_rpc_cmd::siege_warfare_submit_tender_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &tender_value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_siege_warfare_submit_tender_sc : public RpcPacket 	// 공성전 입찰 제출
	{
	public:
		int64_t key{};
	public:
		mpe_siege_castle_type castle_type{};	// 성타입
	public:
		int64_t first_guild{};	// 1위 길드
	public:
		int32_t current_tender{};	// 1위 금액
	public:
		int32_t next_min_tender{};	// 다음 최소입찰금
	public:
		int32_t next_max_tender{};	// 다음 최대입찰금
	public:
		mpe_siege_submit_tender_result result{};	// 결과 값

	public:
		mrpc_siege_warfare_submit_tender_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_submit_tender_sc, tag)
		{
		}
		mrpc_siege_warfare_submit_tender_sc() : RpcPacket(mpe_rpc_cmd::siege_warfare_submit_tender_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &first_guild);
			protocol::SerializeType(pBuffer, &current_tender);
			protocol::SerializeType(pBuffer, &next_min_tender);
			protocol::SerializeType(pBuffer, &next_max_tender);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
