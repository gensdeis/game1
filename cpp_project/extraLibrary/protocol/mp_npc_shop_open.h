#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_npc_buy_count.h"

namespace mir3d
{
	class mp_npc_shop_open_cs : public BasePacket 
	{
	public:
		int32_t shop_group_id{};

	public:
		mp_npc_shop_open_cs() : BasePacket(mpe_cmd::npc_shop_open_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &shop_group_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_npc_shop_open_sc : public BasePacket 
	{
	public:
		std::vector<mps_npc_buy_count> list{};	// 제한타입이 있는 구매내역

	public:
		mp_npc_shop_open_sc() : BasePacket(mpe_cmd::npc_shop_open_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
