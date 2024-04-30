#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_field_boss.h"

namespace mir3d
{
	class mp_zone_fieldboss_info_cs : public BasePacket 	// 필드보스
	{

	public:
		mp_zone_fieldboss_info_cs() : BasePacket(mpe_cmd::zone_fieldboss_info_cs)
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

	class mp_zone_fieldboss_info_sc : public BasePacket 	// 필드보스
	{
	public:
		std::vector<mps_field_boss> list{};	// 필드 보스 정보 리스트
	public:
		int64_t server_time{};

	public:
		mp_zone_fieldboss_info_sc() : BasePacket(mpe_cmd::zone_fieldboss_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &server_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
