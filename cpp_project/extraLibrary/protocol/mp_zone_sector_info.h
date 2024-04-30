#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_sector_info.h"
#include "struct/mps_sector_info.h"

namespace mir3d
{
	class mp_zone_sector_info_cs : public BasePacket 	// 인원정보
	{

	public:
		mp_zone_sector_info_cs() : BasePacket(mpe_cmd::zone_sector_info_cs)
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

	class mp_zone_sector_info_sc : public BasePacket 	// 인원정보
	{
	public:
		std::vector<mps_sector_info> atk_info{};
	public:
		std::vector<mps_sector_info> def_info{};

	public:
		mp_zone_sector_info_sc() : BasePacket(mpe_cmd::zone_sector_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &atk_info);
			protocol::SerializeType(pBuffer, &def_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
