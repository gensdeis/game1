#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_gm_server_relocation_set_user_cnt_cs : public WebBasePacket 
	{
	public:
		int32_t gid{};	// gid
	public:
		int32_t max_user_count{};	// 이동 가능한 유저 수

	public:
		mweb_gm_server_relocation_set_user_cnt_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &max_user_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_server_relocation_set_user_cnt_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};	// 응답 결과

	public:
		mweb_gm_server_relocation_set_user_cnt_sc() : WebBasePacket()
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
