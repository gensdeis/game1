#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_special_move_start_cs : public BasePacket 	// // 결과는 skill_start_result
	{
	public:
		mpe_direction skill_dir{};	// 스킬 방향
	public:
		int32_t target_tile_index{};	// 스킬 타겟 cell index

	public:
		mp_special_move_start_cs() : BasePacket(mpe_cmd::special_move_start_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &skill_dir);
			protocol::SerializeType(pBuffer, &target_tile_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_special_move_start_sc : public BasePacket 	// // 결과는 skill_start_result
	{

	public:
		mp_special_move_start_sc() : BasePacket(mpe_cmd::special_move_start_sc)
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

}
