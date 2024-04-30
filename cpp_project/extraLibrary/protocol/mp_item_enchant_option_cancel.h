#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_item_enchant_option_cancel_cs : public BasePacket 
	{
	public:
		int64_t iuid{};
	public:
		mpe_item_reinforce_position pos{};

	public:
		mp_item_enchant_option_cancel_cs() : BasePacket(mpe_cmd::item_enchant_option_cancel_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_item_enchant_option_cancel_sc : public BasePacket 
	{
	public:
		mpe_reinforce_result result{};

	public:
		mp_item_enchant_option_cancel_sc() : BasePacket(mpe_cmd::item_enchant_option_cancel_sc)
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
