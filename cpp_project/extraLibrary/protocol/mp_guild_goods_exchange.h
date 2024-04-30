#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_goods.h"

namespace mir3d
{
	class mp_guild_goods_exchange_cs : public BasePacket 
	{
	public:
		int32_t goods_type{};
	public:
		int32_t goods_count{};

	public:
		mp_guild_goods_exchange_cs() : BasePacket(mpe_cmd::guild_goods_exchange_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &goods_type);
			protocol::SerializeType(pBuffer, &goods_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_goods_exchange_sc : public BasePacket 
	{
	public:
		mpe_error result{};
	public:
		std::vector<mps_guild_goods> list_guild_goods{};

	public:
		mp_guild_goods_exchange_sc() : BasePacket(mpe_cmd::guild_goods_exchange_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &list_guild_goods);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
