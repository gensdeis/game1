#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_summon_recall_cs : public BasePacket 
	{

	public:
		mp_summon_recall_cs() : BasePacket(mpe_cmd::summon_recall_cs)
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

	class mp_summon_recall_sc : public BasePacket 
	{
	public:
		int64_t uid{};
	public:
		int32_t cell_index{};

	public:
		mp_summon_recall_sc() : BasePacket(mpe_cmd::summon_recall_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &cell_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
