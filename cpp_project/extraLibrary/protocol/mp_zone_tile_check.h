#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_zone_tile_check_cs : public BasePacket 
	{
	public:
		int32_t check_cell{};	// // 체크 할 타일

	public:
		mp_zone_tile_check_cs() : BasePacket(mpe_cmd::zone_tile_check_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &check_cell);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_zone_tile_check_sc : public BasePacket 
	{
	public:
		mpe_error error{};	// // 에러(mpe_error)
	public:
		int32_t curr_cell{};	// // 오류 시 서버의 현재 타일
	public:
		int64_t server_time{};	// // 서버 체크용 시간

	public:
		mp_zone_tile_check_sc() : BasePacket(mpe_cmd::zone_tile_check_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &error);
			protocol::SerializeType(pBuffer, &curr_cell);
			protocol::SerializeType(pBuffer, &server_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
