#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_ranking_buff_reset_cs : public BasePacket 
	{
	public:
		mpe_ranking_type rank_type{};	// 랭킹타입
	public:
		int32_t rank{};	// 랭킹

	public:
		mp_ranking_buff_reset_cs() : BasePacket(mpe_cmd::ranking_buff_reset_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &rank_type);
			protocol::SerializeType(pBuffer, &rank);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_ranking_buff_reset_sc : public BasePacket 
	{

	public:
		mp_ranking_buff_reset_sc() : BasePacket(mpe_cmd::ranking_buff_reset_sc)
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
