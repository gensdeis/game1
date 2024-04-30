#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_siege_warfare_alliance_request_cs : public BasePacket 	// 문파 연합 요청
	{
	public:
		int64_t nuid{};
	public:
		mpe_siege_castle_type castle_type{};	// 입찰 성 type
	public:
		int64_t alliance_guid{};	// 연합요청할 길드아이디

	public:
		mp_siege_warfare_alliance_request_cs() : BasePacket(mpe_cmd::siege_warfare_alliance_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nuid);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &alliance_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_siege_warfare_alliance_request_sc : public BasePacket 	// 문파 연합 요청
	{
	public:
		int64_t alliance_guid{};	// 연합요청할 길드아이디
	public:
		std::string alliance_name{};	// 연합요청할 길드이름
	public:
		int32_t alliance_level{};	// 연합요청할 길드레벨
	public:
		int32_t alliance_member_cnt{};	// 연합요청할 길드원수

	public:
		mp_siege_warfare_alliance_request_sc() : BasePacket(mpe_cmd::siege_warfare_alliance_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &alliance_guid);
			protocol::SerializeType(pBuffer, &alliance_name);
			protocol::SerializeType(pBuffer, &alliance_level);
			protocol::SerializeType(pBuffer, &alliance_member_cnt);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
