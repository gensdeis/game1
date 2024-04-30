#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_zone_move_error_cs : public BasePacket 
	{

	public:
		mp_zone_move_error_cs() : BasePacket(mpe_cmd::zone_move_error_cs)
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

	class mp_zone_move_error_sc : public BasePacket 
	{
	public:
		int32_t curr_cell{};
	public:
		mpe_direction direction{};
	public:
		mpe_move_type type{};
	public:
		int32_t server_curr_cell{};
	public:
		int32_t server_next_cell{};
	public:
		mpe_error error_code{};

	public:
		mp_zone_move_error_sc() : BasePacket(mpe_cmd::zone_move_error_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &curr_cell);
			protocol::SerializeEnum(pBuffer, &direction);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &server_curr_cell);
			protocol::SerializeType(pBuffer, &server_next_cell);
			protocol::SerializeEnum(pBuffer, &error_code);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
