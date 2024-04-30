#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_siege_warfare_tender_info_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		mpe_siege_castle_type castle_type{};	// 공성전 성 타입
	public:
		int64_t guid{};	// 내 길드 아이디

	public:
		mrpc_gate_siege_warfare_tender_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_siege_warfare_tender_info_cs, tag)
		{
		}
		mrpc_gate_siege_warfare_tender_info_cs() : RpcPacket(mpe_rpc_cmd::gate_siege_warfare_tender_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_siege_warfare_tender_info_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t id{};	// 공성전 아이디
	public:
		int32_t tender{};	// 1위입찰금
	public:
		int64_t guid{};	// 1위길드 아이디
	public:
		std::string name{};	// 1위길드 이름
	public:
		int64_t master_cuid{};	// 1위길드 문파장아이디
	public:
		std::string master_name{};	// 1위길드 문파장이름
	public:
		int32_t tender_count{};	// 입찰길드수
	public:
		bool is_enter{};	// 참여여부
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t master_class{};

	public:
		mrpc_gate_siege_warfare_tender_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_siege_warfare_tender_info_sc, tag)
		{
		}
		mrpc_gate_siege_warfare_tender_info_sc() : RpcPacket(mpe_rpc_cmd::gate_siege_warfare_tender_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &tender);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &master_cuid);
			protocol::SerializeType(pBuffer, &master_name);
			protocol::SerializeType(pBuffer, &tender_count);
			protocol::SerializeType(pBuffer, &is_enter);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &master_class);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
