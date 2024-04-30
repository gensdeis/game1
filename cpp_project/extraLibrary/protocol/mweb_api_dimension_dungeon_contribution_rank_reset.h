#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_api_dimension_dungeon_contribution_rank_reset_cs : public WebBasePacket 	// MPBS를 통한 차원비경 기여도랭킹 리셋
	{
	public:
		int32_t world_gid{};	// 월드 gid

	public:
		mweb_api_dimension_dungeon_contribution_rank_reset_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &world_gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_dimension_dungeon_contribution_rank_reset_sc : public WebBasePacket 	// MPBS를 통한 차원비경 기여도랭킹 리셋
	{
	public:
		mpe_error result{};	// 응답 결과

	public:
		mweb_api_dimension_dungeon_contribution_rank_reset_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
