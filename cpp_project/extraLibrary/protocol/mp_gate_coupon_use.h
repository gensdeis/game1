#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_coupon_use_cs : public BasePacket 
	{
	public:
		int64_t auid{};
	public:
		std::string player_key{};
	public:
		int64_t cuid{};
	public:
		mpe_coupon_type coupon_type{};
	public:
		std::string coupon_code{};

	public:
		mp_gate_coupon_use_cs() : BasePacket(mpe_cmd::gate_coupon_use_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &player_key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &coupon_type);
			protocol::SerializeType(pBuffer, &coupon_code);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_coupon_use_sc : public BasePacket 
	{
	public:
		int32_t result_code{};
	public:
		int32_t result{};

	public:
		mp_gate_coupon_use_sc() : BasePacket(mpe_cmd::gate_coupon_use_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result_code);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
