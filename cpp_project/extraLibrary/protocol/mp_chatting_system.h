#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_chatting_system_cs : public BasePacket 	// 시스템채팅
	{

	public:
		mp_chatting_system_cs() : BasePacket(mpe_cmd::chatting_system_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_chatting_system_sc : public BasePacket 	// 시스템채팅
	{
	public:
		mpe_chat_system msg_type{};
	public:
		bool is_mymsg{};	// 나에게만
	public:
		std::string message{};	// 공지 
	public:
		int64_t s_uid{};	// 내가 흭득한거면 0이아님 
	public:
		int64_t k_uid{};	// 타유저/킬러 uid 0이아님
	public:
		std::string nickname{};	// 타유저/킬러 닉네임
	public:
		mpe_good_pos goods_type{};
	public:
		int64_t itemid{};
	public:
		int32_t param1{};	// "획득량, tid 등"
	public:
		int32_t param2{};	// "지역,endtime  등"

	public:
		mp_chatting_system_sc() : BasePacket(mpe_cmd::chatting_system_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
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
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
