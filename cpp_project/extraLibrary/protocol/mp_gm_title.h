#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gm_title_cs : public BasePacket 
	{
	public:
		int32_t title_gid{};	// 칭호 그룹아이디
	public:
		int32_t count{};

	public:
		mp_gm_title_cs() : BasePacket(mpe_cmd::gm_title_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &title_gid);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_title_sc : public BasePacket 
	{

	public:
		mp_gm_title_sc() : BasePacket(mpe_cmd::gm_title_sc)
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
