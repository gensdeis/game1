#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_friend_data_set_cs : public BasePacket 	// 서버만 사용
	{
	public:
		std::vector<int64_t> friend_list{};

	public:
		mp_friend_data_set_cs() : BasePacket(mpe_cmd::friend_data_set_cs)
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

	class mp_friend_data_set_sc : public BasePacket 	// 서버만 사용
	{

	public:
		mp_friend_data_set_sc() : BasePacket(mpe_cmd::friend_data_set_sc)
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
