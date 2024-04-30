#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_trade_info.h"

namespace mir3d
{
	class mp_personal_trade_confirm_cs : public BasePacket 
	{
	public:
		int64_t ptuid{};	// // 거래 번호

	public:
		mp_personal_trade_confirm_cs() : BasePacket(mpe_cmd::personal_trade_confirm_cs)
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

	class mp_personal_trade_confirm_sc : public BasePacket 
	{
	public:
		int64_t uid{};	// // 거래 확인 신청자 오브젝트 uid
	public:
		bool all_confirm{};	// // 거래유저 전체 confirm 여부
	public:
		std::vector<mps_trade_info> info{};	// // 거래 결과

	public:
		mp_personal_trade_confirm_sc() : BasePacket(mpe_cmd::personal_trade_confirm_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &all_confirm);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
