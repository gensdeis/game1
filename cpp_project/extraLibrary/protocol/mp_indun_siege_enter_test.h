#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_indun_siege_enter_test_cs : public BasePacket 	// // 공성전 공성수성 동시입장 테스트 패킷
	{
	public:
		int32_t tid{};	// // dungeon constrol table id
	public:
		mpe_indun_enter_type type{};	// // 인던 입장 방식 

	public:
		mp_indun_siege_enter_test_cs() : BasePacket(mpe_cmd::indun_siege_enter_test_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_indun_siege_enter_test_sc : public BasePacket 	// // 공성전 공성수성 동시입장 테스트 패킷
	{
	public:
		int32_t tid{};	// // dungeon constrol table id

	public:
		mp_indun_siege_enter_test_sc() : BasePacket(mpe_cmd::indun_siege_enter_test_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
