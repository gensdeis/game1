#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_member_enter_state.h"

namespace mir3d
{
	class mp_party_member_enter_state_cs : public BasePacket 
	{

	public:
		mp_party_member_enter_state_cs() : BasePacket(mpe_cmd::party_member_enter_state_cs)
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

	class mp_party_member_enter_state_sc : public BasePacket 
	{
	public:
		std::vector<mps_party_member_enter_state> list{};	// "파티원목록"

	public:
		mp_party_member_enter_state_sc() : BasePacket(mpe_cmd::party_member_enter_state_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
