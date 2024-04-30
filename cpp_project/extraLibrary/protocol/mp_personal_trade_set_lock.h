#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_personal_trade_set_lock_cs : public BasePacket 
	{
	public:
		int64_t ptuid{};	// // 거래 번호

	public:
		mp_personal_trade_set_lock_cs() : BasePacket(mpe_cmd::personal_trade_set_lock_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ptuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_personal_trade_set_lock_sc : public BasePacket 
	{
	public:
		int64_t uid{};	// // lock 신청자 오브젝트 uid
	public:
		mpe_personal_trade_state state{};	// // lock 신청자 현재 상태
	public:
		bool all_lock{};	// // 거래유저 전체 lock 여부

	public:
		mp_personal_trade_set_lock_sc() : BasePacket(mpe_cmd::personal_trade_set_lock_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &all_lock);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
