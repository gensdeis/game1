#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_show_aggro_info.h"

namespace mir3d
{
	class mp_gm_show_aggro_info_cs : public BasePacket 
	{
	public:
		int64_t uid{};

	public:
		mp_gm_show_aggro_info_cs() : BasePacket(mpe_cmd::gm_show_aggro_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_show_aggro_info_sc : public BasePacket 
	{
	public:
		int64_t uid{};
	public:
		std::vector<mps_show_aggro_info> info{};

	public:
		mp_gm_show_aggro_info_sc() : BasePacket(mpe_cmd::gm_show_aggro_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
