#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_occupationwar_challenge_guild_info.h"

namespace mir3d
{
	class mweb_occupationwar_challenge_request_list_cs : public WebBasePacket 	// 비곡점령전 신청 내역 조회
	{

	public:
		mweb_occupationwar_challenge_request_list_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_occupationwar_challenge_request_list_sc : public WebBasePacket 	// 비곡점령전 신청 내역 조회
	{
	public:
		std::vector<mps_occupationwar_challenge_guild_info> list{};

	public:
		mweb_occupationwar_challenge_request_list_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
