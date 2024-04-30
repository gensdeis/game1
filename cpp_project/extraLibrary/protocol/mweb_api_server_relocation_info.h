#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_api_server_relocation_info_cs : public WebBasePacket 
	{
	public:
		int64_t auid{};	// 계정 아이디
	public:
		int64_t cuid{};	// 캐릭터 아이디

	public:
		mweb_api_server_relocation_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_server_relocation_info_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};	// 응답 결과
	public:
		int64_t char_info_size{};	// 정보
	public:
		std::string nickname{};	// 닉네임
	public:
		uint8_t is_delete{};	// 캐릭터 상태
	public:
		int64_t server_relocation_time{};	// 표국통행 쿨타임

	public:
		mweb_api_server_relocation_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &char_info_size);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &is_delete);
			protocol::SerializeType(pBuffer, &server_relocation_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
