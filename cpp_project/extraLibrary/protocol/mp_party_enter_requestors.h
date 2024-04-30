#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_member_base.h"

namespace mir3d
{
	class mp_party_enter_requestors_cs : public BasePacket 
	{

	public:
		mp_party_enter_requestors_cs() : BasePacket(mpe_cmd::party_enter_requestors_cs)
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

	class mp_party_enter_requestors_sc : public BasePacket 
	{
	public:
		std::vector<mps_party_member_base> list{};

	public:
		mp_party_enter_requestors_sc() : BasePacket(mpe_cmd::party_enter_requestors_sc)
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
