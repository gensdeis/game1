#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_chat_system_cs : public WebBasePacket 	// rpc시스템채팅
	{
	public:
		mpe_chat_system msg_type{};
	public:
		bool is_mymsg{};
	public:
		std::string message{};	// 공지
	public:
		int64_t s_uid{};
	public:
		int64_t k_uid{};
	public:
		std::string nickname{};
	public:
		mpe_good_pos goods_type{};
	public:
		int64_t itemid{};
	public:
		int32_t param1{};
	public:
		int32_t param2{};

	public:
		mweb_chat_system_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &msg_type);
			protocol::SerializeType(pBuffer, &is_mymsg);
			protocol::SerializeType(pBuffer, &message);
			protocol::SerializeType(pBuffer, &s_uid);
			protocol::SerializeType(pBuffer, &k_uid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeEnum(pBuffer, &goods_type);
			protocol::SerializeType(pBuffer, &itemid);
			protocol::SerializeType(pBuffer, &param1);
			protocol::SerializeType(pBuffer, &param2);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_chat_system_sc : public WebBasePacket 	// rpc시스템채팅
	{
	public:
		bool success{};

	public:
		mweb_chat_system_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &success);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
