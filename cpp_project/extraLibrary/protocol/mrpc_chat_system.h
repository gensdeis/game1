#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_chat_system_cs : public RpcPacket 	// rpc시스템채팅
	{
	public:
		mpe_chat_system msg_type{};
	public:
		int32_t gid{};
	public:
		bool is_mymsg{};	// 나에게만
	public:
		std::string message{};	// 공지 
	public:
		int64_t s_uid{};	// 내가 흭득한거면 0이아님 
	public:
		int64_t k_uid{};	// 타유저/킬러 uid
	public:
		std::string nickname{};	// 타유저/킬러 닉네임
	public:
		mpe_good_pos goods_type{};
	public:
		int64_t itemid{};
	public:
		int32_t param1{};	// 획득량
	public:
		int32_t param2{};	// 지역  등
	public:
		int64_t exclude_channel_uid{};	// 제외채널

	public:
		mrpc_chat_system_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::chat_system_cs, tag)
		{
		}
		mrpc_chat_system_cs() : RpcPacket(mpe_rpc_cmd::chat_system_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &msg_type);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &is_mymsg);
			protocol::SerializeType(pBuffer, &message);
			protocol::SerializeType(pBuffer, &s_uid);
			protocol::SerializeType(pBuffer, &k_uid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeEnum(pBuffer, &goods_type);
			protocol::SerializeType(pBuffer, &itemid);
			protocol::SerializeType(pBuffer, &param1);
			protocol::SerializeType(pBuffer, &param2);
			protocol::SerializeType(pBuffer, &exclude_channel_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_chat_system_sc : public RpcPacket 	// rpc시스템채팅
	{
	public:
		mpe_chat_system msg_type{};
	public:
		int32_t gid{};
	public:
		bool is_mymsg{};	// 나에게만
	public:
		std::string message{};	// 공지 
	public:
		int64_t s_uid{};	// 내가 흭득한거면 0이아님 
	public:
		int64_t k_uid{};	// 타유저/킬러 uid
	public:
		std::string nickname{};	// 타유저/킬러 닉네임
	public:
		mpe_good_pos goods_type{};
	public:
		int64_t itemid{};
	public:
		int32_t param1{};	// 획득량
	public:
		int32_t param2{};	// 지역  등
	public:
		int64_t exclude_channel_uid{};	// 제외채널

	public:
		mrpc_chat_system_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::chat_system_sc, tag)
		{
		}
		mrpc_chat_system_sc() : RpcPacket(mpe_rpc_cmd::chat_system_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &msg_type);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &is_mymsg);
			protocol::SerializeType(pBuffer, &message);
			protocol::SerializeType(pBuffer, &s_uid);
			protocol::SerializeType(pBuffer, &k_uid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeEnum(pBuffer, &goods_type);
			protocol::SerializeType(pBuffer, &itemid);
			protocol::SerializeType(pBuffer, &param1);
			protocol::SerializeType(pBuffer, &param2);
			protocol::SerializeType(pBuffer, &exclude_channel_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
