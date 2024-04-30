#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_wanted_murder_number_of_uses_cs : public BasePacket 
	{

	public:
		mp_wanted_murder_number_of_uses_cs() : BasePacket(mpe_cmd::wanted_murder_number_of_uses_cs)
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

	class mp_wanted_murder_number_of_uses_sc : public BasePacket 
	{
	public:
		int32_t wanted_murder_reg_count{};
	public:
		int32_t wanted_murder_accept_count{};
	public:
		int64_t wanted_murder_reset_time{};

	public:
		mp_wanted_murder_number_of_uses_sc() : BasePacket(mpe_cmd::wanted_murder_number_of_uses_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &wanted_murder_reg_count);
			protocol::SerializeType(pBuffer, &wanted_murder_accept_count);
			protocol::SerializeType(pBuffer, &wanted_murder_reset_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
