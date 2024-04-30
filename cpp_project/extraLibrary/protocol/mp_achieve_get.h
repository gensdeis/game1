#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_achieve_info.h"

namespace mir3d
{
	class mp_achieve_get_cs : public BasePacket 
	{
	public:
		int32_t achieve_type{};

	public:
		mp_achieve_get_cs() : BasePacket(mpe_cmd::achieve_get_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &achieve_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_achieve_get_sc : public BasePacket 
	{
	public:
		int32_t achieve_type{};
	public:
		std::vector<mps_achieve_info> list{};

	public:
		mp_achieve_get_sc() : BasePacket(mpe_cmd::achieve_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &achieve_type);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
