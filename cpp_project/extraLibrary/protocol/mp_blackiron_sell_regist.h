#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_blackiron_sell_regist_cs : public BasePacket 
	{
	public:
		int32_t blackiron_sell_count{};	// // 흑철 판매 개수
	public:
		int32_t blackiron_sell_price{};	// // 흑철 만개당 가격

	public:
		mp_blackiron_sell_regist_cs() : BasePacket(mpe_cmd::blackiron_sell_regist_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &blackiron_sell_count);
			protocol::SerializeType(pBuffer, &blackiron_sell_price);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_blackiron_sell_regist_sc : public BasePacket 
	{
	public:
		int32_t guild_blackiron_count{};	// // 갱신 후 남은 문파흑철개수

	public:
		mp_blackiron_sell_regist_sc() : BasePacket(mpe_cmd::blackiron_sell_regist_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guild_blackiron_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
