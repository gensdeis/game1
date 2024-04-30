#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_cash_limit_product_noti_cs : public BasePacket 
	{

	public:
		mp_cash_limit_product_noti_cs() : BasePacket(mpe_cmd::cash_limit_product_noti_cs)
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

	class mp_cash_limit_product_noti_sc : public BasePacket 
	{
	public:
		int32_t last_logout{};

	public:
		mp_cash_limit_product_noti_sc() : BasePacket(mpe_cmd::cash_limit_product_noti_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &last_logout);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
