#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_personal_trade_accept_cs : public BasePacket 
	{
	public:
		int64_t apply_uid{};	// // 거래 상대의 오브젝트 uid
	public:
		int64_t ptuid{};	// // 거래 번호

	public:
		mp_personal_trade_accept_cs() : BasePacket(mpe_cmd::personal_trade_accept_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &apply_uid);
			protocol::SerializeType(pBuffer, &ptuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_personal_trade_accept_sc : public BasePacket 
	{

	public:
		mp_personal_trade_accept_sc() : BasePacket(mpe_cmd::personal_trade_accept_sc)
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
