#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_chatting_cs : public BasePacket 	// 채팅
	{
	public:
		mpe_chatting type{};
	public:
		std::string nickname{};
	public:
		std::string message{};
	public:
		std::string link{};

	public:
		mp_chatting_cs() : BasePacket(mpe_cmd::chatting_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &message);
			protocol::SerializeType(pBuffer, &link);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_chatting_sc : public BasePacket 	// 채팅
	{
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
		mp_chatting_sc() : BasePacket(mpe_cmd::chatting_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
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
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
