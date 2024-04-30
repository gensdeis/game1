#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_obtain_avatar.h"

namespace mir3d
{
	class mp_gm_avatar_get_cs : public BasePacket 
	{
	public:
		int32_t avatar_id{};
	public:
		int32_t count{};

	public:
		mp_gm_avatar_get_cs() : BasePacket(mpe_cmd::gm_avatar_get_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &avatar_id);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_avatar_get_sc : public BasePacket 
	{
	public:
		std::vector<mps_obtain_avatar> reward_avatar{};

	public:
		mp_gm_avatar_get_sc() : BasePacket(mpe_cmd::gm_avatar_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &reward_avatar);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
