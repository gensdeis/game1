#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_private_chatting_state_cs : public BasePacket 
	{
	public:
		bool is_update{};	// 갱신여부
	public:
		bool disable{};

	public:
		mp_gate_private_chatting_state_cs() : BasePacket(mpe_cmd::gate_private_chatting_state_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &is_update);
			protocol::SerializeType(pBuffer, &disable);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_private_chatting_state_sc : public BasePacket 
	{
	public:
		bool is_update{};
	public:
		bool disable{};	// 거부 상태인지 아닌지

	public:
		mp_gate_private_chatting_state_sc() : BasePacket(mpe_cmd::gate_private_chatting_state_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &is_update);
			protocol::SerializeType(pBuffer, &disable);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
