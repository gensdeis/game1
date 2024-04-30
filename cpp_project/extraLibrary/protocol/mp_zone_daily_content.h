#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_zone_daily_content_cs : public BasePacket 
	{
	public:
		int32_t npc_id{};
	public:
		mpe_daily_content_pos pos{};	// 일별 컨텐츠 정보

	public:
		mp_zone_daily_content_cs() : BasePacket(mpe_cmd::zone_daily_content_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &npc_id);
			protocol::SerializeEnum(pBuffer, &pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_zone_daily_content_sc : public BasePacket 
	{
	public:
		mpe_daily_content_pos pos{};	// 일별 컨텐츠 정보
	public:
		int32_t date{};	// 갱신된 시간
	public:
		int32_t value{};	// 업데이트 값

	public:
		mp_zone_daily_content_sc() : BasePacket(mpe_cmd::zone_daily_content_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &date);
			protocol::SerializeType(pBuffer, &value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
