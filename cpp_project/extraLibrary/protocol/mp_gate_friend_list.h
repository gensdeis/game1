#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_friend_info.h"

namespace mir3d
{
	class mp_gate_friend_list_cs : public BasePacket 
	{
	public:
		int64_t cuid{};

	public:
		mp_gate_friend_list_cs() : BasePacket(mpe_cmd::gate_friend_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_friend_list_sc : public BasePacket 
	{
	public:
		std::vector<mps_friend_info> friend_list{};

	public:
		mp_gate_friend_list_sc() : BasePacket(mpe_cmd::gate_friend_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &friend_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
