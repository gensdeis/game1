#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_street_stall_unmanned_cs : public BasePacket 	// // 개인 노점 무인 변경
	{
	public:
		bool is_unmanned{};	// "// true : 무인, false : 유인 으로 변경"
	public:
		mpe_direction direction{};

	public:
		mp_street_stall_unmanned_cs() : BasePacket(mpe_cmd::street_stall_unmanned_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &is_unmanned);
			protocol::SerializeEnum(pBuffer, &direction);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_street_stall_unmanned_sc : public BasePacket 	// // 개인 노점 무인 변경
	{
	public:
		int64_t suid{};	// // 개인 노점 uid
	public:
		int64_t cuid{};
	public:
		mpe_character_action action{};
	public:
		int32_t npc_info{};	// "// 0 : 유인, 1 : npc 사용 - 추후 npc 아이디(shop 어시스트) 값으로 변경할수 있음"

	public:
		mp_street_stall_unmanned_sc() : BasePacket(mpe_cmd::street_stall_unmanned_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &suid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &action);
			protocol::SerializeType(pBuffer, &npc_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
