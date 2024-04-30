#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_chatting_cs : public RpcPacket 	// 채팅
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		mpe_chatting type{};
	public:
		std::string nickname{};
	public:
		std::string message{};
	public:
		std::string link{};
	public:
		int64_t recv_uid{};	// "수신자uid 문파동맹 때문에 추가함"

	public:
		mrpc_gate_chatting_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_chatting_cs, tag)
		{
		}
		mrpc_gate_chatting_cs() : RpcPacket(mpe_rpc_cmd::gate_chatting_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &message);
			protocol::SerializeType(pBuffer, &link);
			protocol::SerializeType(pBuffer, &recv_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_chatting_sc : public RpcPacket 	// 채팅
	{
	public:
		int64_t key{};
	public:
		int64_t send_uid{};	// 보내는 유저 
	public:
		mpe_chatting type{};
	public:
		int32_t tid{};	// type이 chat_system 일경우 mpe_notice_type 참조
	public:
		std::string send_nick{};
	public:
		std::string message{};
	public:
		std::string link{};
	public:
		int64_t recv_uid{};	// 받는 유저
	public:
		std::string recv_nick{};
	public:
		mpe_error result{};

	public:
		mrpc_gate_chatting_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_chatting_sc, tag)
		{
		}
		mrpc_gate_chatting_sc() : RpcPacket(mpe_rpc_cmd::gate_chatting_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &send_uid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &send_nick);
			protocol::SerializeType(pBuffer, &message);
			protocol::SerializeType(pBuffer, &link);
			protocol::SerializeType(pBuffer, &recv_uid);
			protocol::SerializeType(pBuffer, &recv_nick);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
