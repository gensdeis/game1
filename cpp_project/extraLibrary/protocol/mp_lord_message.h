#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_lord_message_cs : public BasePacket 	// 성주교령저장요청
	{
	public:
		std::string message{};	// 갱신할메시지
	public:
		int32_t castle_id{};	// 어느 성인지

	public:
		mp_lord_message_cs() : BasePacket(mpe_cmd::lord_message_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &message);
			protocol::SerializeType(pBuffer, &castle_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_lord_message_sc : public BasePacket 	// 성주교령저장요청
	{

	public:
		mp_lord_message_sc() : BasePacket(mpe_cmd::lord_message_sc)
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

}
