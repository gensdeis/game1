#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_indun_prepare_enter_cs : public BasePacket 	// "// 인던 입장 투표 (바로시작)
	{
	public:
		mpe_indun_enter_type type{};	// "// 인던 입장 방식 별 투표 - 바로입장시, 매칭시"
	public:
		int32_t tid{};	// // dungeon constrol table id
	public:
		bool flag{};	// "// 수락, 거절"

	public:
		mp_indun_prepare_enter_cs() : BasePacket(mpe_cmd::indun_prepare_enter_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &flag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_indun_prepare_enter_sc : public BasePacket 	// "// 인던 입장 투표 (바로시작)
	{
	public:
		int32_t error_code{};
	public:
		int64_t cuid{};
	public:
		bool result{};	// // 투표 결과

	public:
		mp_indun_prepare_enter_sc() : BasePacket(mpe_cmd::indun_prepare_enter_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &error_code);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
