#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_dimension_dungeon_piece_info.h"

namespace mir3d
{
	class mp_dimension_dungeon_piece_cs : public BasePacket 
	{

	public:
		mp_dimension_dungeon_piece_cs() : BasePacket(mpe_cmd::dimension_dungeon_piece_cs)
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

	class mp_dimension_dungeon_piece_sc : public BasePacket 
	{
	public:
		std::vector<mps_dimension_dungeon_piece_info> piece_list{};	// 서버별 차원조각 개수 정보

	public:
		mp_dimension_dungeon_piece_sc() : BasePacket(mpe_cmd::dimension_dungeon_piece_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &piece_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
