#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_season_mandala_info_open_cs : public BasePacket 	// 시즌 만다라 탭 클릭
	{
	public:
		int64_t cuid{};	// 캐릭터 아이디

	public:
		mp_season_mandala_info_open_cs() : BasePacket(mpe_cmd::season_mandala_info_open_cs)
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

	class mp_season_mandala_info_open_sc : public BasePacket 	// 시즌 만다라 탭 클릭
	{
	public:
		int32_t id{};	// 시즌 아이디
	public:
		int32_t end_date{};	// 시즌 종료 시간 (전역타임)

	public:
		mp_season_mandala_info_open_sc() : BasePacket(mpe_cmd::season_mandala_info_open_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &end_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
