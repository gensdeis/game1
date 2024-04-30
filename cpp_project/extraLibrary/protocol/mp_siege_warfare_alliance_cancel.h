#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_siege_warfare_alliance_cancel_cs : public BasePacket 	// 문파 연합 취소
	{
	public:
		int64_t nuid{};
	public:
		mpe_siege_castle_type castle_type{};	// 입찰 성 type
	public:
		int64_t alliance_guid{};	// 연합요청 취소할 길드아이디

	public:
		mp_siege_warfare_alliance_cancel_cs() : BasePacket(mpe_cmd::siege_warfare_alliance_cancel_cs)
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

	class mp_siege_warfare_alliance_cancel_sc : public BasePacket 	// 문파 연합 취소
	{

	public:
		mp_siege_warfare_alliance_cancel_sc() : BasePacket(mpe_cmd::siege_warfare_alliance_cancel_sc)
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
