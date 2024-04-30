#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_chatting_block_cs : public BasePacket 
	{
	public:
		std::string nickname{};
	public:
		bool is_block{};	// 차단 or 해제

	public:
		mp_chatting_block_cs() : BasePacket(mpe_cmd::chatting_block_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &is_block);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_chatting_block_sc : public BasePacket 
	{
	public:
		mpe_error result{};
	public:
		bool is_block{};	// 차단 or 해제
	public:
		std::string nickname{};

	public:
		mp_chatting_block_sc() : BasePacket(mpe_cmd::chatting_block_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &is_block);
			protocol::SerializeType(pBuffer, &nickname);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
