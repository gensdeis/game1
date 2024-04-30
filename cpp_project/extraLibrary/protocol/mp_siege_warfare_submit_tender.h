#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_siege_warfare_submit_tender_cs : public BasePacket 	// 공성입찰
	{
	public:
		int64_t nuid{};	// npc아이디
	public:
		mpe_siege_castle_type castle_type{};	// 입찰 성 type
	public:
		int32_t tender_value{};	// 입찰금액

	public:
		mp_siege_warfare_submit_tender_cs() : BasePacket(mpe_cmd::siege_warfare_submit_tender_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nuid);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &tender_value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_siege_warfare_submit_tender_sc : public BasePacket 	// 공성입찰
	{
	public:
		mpe_siege_submit_tender_result result{};	// 결과 값

	public:
		mp_siege_warfare_submit_tender_sc() : BasePacket(mpe_cmd::siege_warfare_submit_tender_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
