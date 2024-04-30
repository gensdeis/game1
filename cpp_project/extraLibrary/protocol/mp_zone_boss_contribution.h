#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_boss_contribution.h"

namespace mir3d
{
	class mp_zone_boss_contribution_cs : public BasePacket 
	{

	public:
		mp_zone_boss_contribution_cs() : BasePacket(mpe_cmd::zone_boss_contribution_cs)
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

	class mp_zone_boss_contribution_sc : public BasePacket 
	{
	public:
		float total_contribution{};
	public:
		std::vector<mps_boss_contribution> list{};

	public:
		mp_zone_boss_contribution_sc() : BasePacket(mpe_cmd::zone_boss_contribution_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &total_contribution);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
