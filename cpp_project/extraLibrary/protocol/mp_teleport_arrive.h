#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_teleport_arrive_cs : public BasePacket 
	{

	public:
		mp_teleport_arrive_cs() : BasePacket(mpe_cmd::teleport_arrive_cs)
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

	class mp_teleport_arrive_sc : public BasePacket 
	{
	public:
		std::string guild_name{};
	public:
		int32_t member_count{};
	public:
		int32_t max_member_count{};

	public:
		mp_teleport_arrive_sc() : BasePacket(mpe_cmd::teleport_arrive_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &member_count);
			protocol::SerializeType(pBuffer, &max_member_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
