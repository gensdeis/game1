#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_indun_auto_matching_rematch_cs : public BasePacket 	// // 인던 자동 매칭 후 거절되어 다시 매칭해야 할때 알림용
	{

	public:
		mp_indun_auto_matching_rematch_cs() : BasePacket(mpe_cmd::indun_auto_matching_rematch_cs)
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

	class mp_indun_auto_matching_rematch_sc : public BasePacket 	// // 인던 자동 매칭 후 거절되어 다시 매칭해야 할때 알림용
	{

	public:
		mp_indun_auto_matching_rematch_sc() : BasePacket(mpe_cmd::indun_auto_matching_rematch_sc)
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
