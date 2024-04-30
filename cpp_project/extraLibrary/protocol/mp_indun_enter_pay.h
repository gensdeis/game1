#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_indun_enter_pay_cs : public BasePacket 
	{
	public:
		int32_t dungeon_group_id{};
	public:
		int64_t indun_uid{};
	public:
		int32_t server_index{};
	public:
		std::vector<int32_t> list_item_id{};
	public:
		mpe_siege_castle_type castle_type{};	// 입장성type
	public:
		int32_t castle_dungeon_entrance_fee{};

	public:
		mp_indun_enter_pay_cs() : BasePacket(mpe_cmd::indun_enter_pay_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &dungeon_group_id);
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeType(pBuffer, &list_item_id);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &castle_dungeon_entrance_fee);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_indun_enter_pay_sc : public BasePacket 
	{

	public:
		mp_indun_enter_pay_sc() : BasePacket(mpe_cmd::indun_enter_pay_sc)
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
