#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_revive.h"

namespace mir3d
{
	class mp_revive_list_cs : public BasePacket 
	{

	public:
		mp_revive_list_cs() : BasePacket(mpe_cmd::revive_list_cs)
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

	class mp_revive_list_sc : public BasePacket 
	{
	public:
		std::vector<mps_revive> list{};

	public:
		mp_revive_list_sc() : BasePacket(mpe_cmd::revive_list_sc)
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
