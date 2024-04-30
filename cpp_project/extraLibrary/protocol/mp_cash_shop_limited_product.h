#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_cash_limited_product.h"

namespace mir3d
{
	class mp_cash_shop_limited_product_cs : public BasePacket 
	{
	public:
		uint16_t limited_type{};	// 한정패키지 상품 타입
	public:
		int32_t value{};	// 한정패키지 활성 조건값

	public:
		mp_cash_shop_limited_product_cs() : BasePacket(mpe_cmd::cash_shop_limited_product_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &limited_type);
			protocol::SerializeType(pBuffer, &value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_cash_shop_limited_product_sc : public BasePacket 
	{
	public:
		std::vector<mps_cash_limited_product> info{};

	public:
		mp_cash_shop_limited_product_sc() : BasePacket(mpe_cmd::cash_shop_limited_product_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
