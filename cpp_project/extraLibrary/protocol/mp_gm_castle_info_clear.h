#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gm_castle_info_clear_cs : public BasePacket 	// 성주 정보 삭제
	{
	public:
		int32_t castle_id{};	// 삭제할 성 siege_type

	public:
		mp_gm_castle_info_clear_cs() : BasePacket(mpe_cmd::gm_castle_info_clear_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &castle_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_castle_info_clear_sc : public BasePacket 	// 성주 정보 삭제
	{

	public:
		mp_gm_castle_info_clear_sc() : BasePacket(mpe_cmd::gm_castle_info_clear_sc)
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
