#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_party_owner_change_cs : public BasePacket 
	{
	public:
		int64_t cuid{};

	public:
		mp_party_owner_change_cs() : BasePacket(mpe_cmd::party_owner_change_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_party_owner_change_sc : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		bool auto_start{};	// //파티던전거버넌스 때문에 추가.(클라요청)
	public:
		int32_t governance_rank{};	// //파티던전거버넌스 랭킹

	public:
		mp_party_owner_change_sc() : BasePacket(mpe_cmd::party_owner_change_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auto_start);
			protocol::SerializeType(pBuffer, &governance_rank);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
