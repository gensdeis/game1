#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_tax_member.h"

namespace mir3d
{
	class mweb_castle_tax_with_member_info_cs : public WebBasePacket 	// 성관리-세율관리 정보
	{
	public:
		int64_t guid{};
	public:
		mpe_siege_castle_type castle_type{};

	public:
		mweb_castle_tax_with_member_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &castle_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_castle_tax_with_member_info_sc : public WebBasePacket 	// 성관리-세율관리 정보
	{
	public:
		int32_t tax_rate{};	// 세율
	public:
		int32_t tax_value{};	// 징수세금
	public:
		mpe_castle_tax_distribution tax_distribution{};	// 분배방식
	public:
		int64_t tax_rate_reg_time{};	// 세금변경날짜
	public:
		std::vector<mps_castle_tax_member> members{};	// 길드원

	public:
		mweb_castle_tax_with_member_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tax_rate);
			protocol::SerializeType(pBuffer, &tax_value);
			protocol::SerializeEnum(pBuffer, &tax_distribution);
			protocol::SerializeType(pBuffer, &tax_rate_reg_time);
			protocol::SerializeType(pBuffer, &members);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
