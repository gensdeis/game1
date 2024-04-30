#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_seasonpass.h"

namespace mir3d
{
	class mp_seasonpass_change_cs : public BasePacket 
	{
	public:
		bool reload{};	// 시즌변경시

	public:
		mp_seasonpass_change_cs() : BasePacket(mpe_cmd::seasonpass_change_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &reload);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_seasonpass_change_sc : public BasePacket 
	{
	public:
		std::vector<mps_seasonpass> info{};	// 시즌패스 정보

	public:
		mp_seasonpass_change_sc() : BasePacket(mpe_cmd::seasonpass_change_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
