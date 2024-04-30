#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gm_quest_clear_list_cs : public BasePacket 
	{
	public:
		uint16_t start_tid{};
	public:
		int32_t end_tid{};

	public:
		mp_gm_quest_clear_list_cs() : BasePacket(mpe_cmd::gm_quest_clear_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &start_tid);
			protocol::SerializeType(pBuffer, &end_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_quest_clear_list_sc : public BasePacket 
	{
	public:
		std::vector<int32_t> list_tid{};

	public:
		mp_gm_quest_clear_list_sc() : BasePacket(mpe_cmd::gm_quest_clear_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
