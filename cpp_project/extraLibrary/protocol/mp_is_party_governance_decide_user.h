#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_is_party_governance_decide_user_cs : public BasePacket 	// 파티거버넌스 혜택자 여부==true
	{

	public:
		mp_is_party_governance_decide_user_cs() : BasePacket(mpe_cmd::is_party_governance_decide_user_cs)
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

	class mp_is_party_governance_decide_user_sc : public BasePacket 	// 파티거버넌스 혜택자 여부==true
	{
	public:
		bool is_governance_decided{};

	public:
		mp_is_party_governance_decide_user_sc() : BasePacket(mpe_cmd::is_party_governance_decide_user_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &is_governance_decided);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
