#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gm_fsminfo_cs : public BasePacket 
	{
	public:
		int64_t uid{};

	public:
		mp_gm_fsminfo_cs() : BasePacket(mpe_cmd::gm_fsminfo_cs)
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

	class mp_gm_fsminfo_sc : public BasePacket 
	{
	public:
		int64_t uid{};
	public:
		int32_t state{};
	public:
		mpe_move_type move_type{};
	public:
		int32_t cell_index{};
	public:
		int32_t hp{};
	public:
		int32_t mp{};

	public:
		mp_gm_fsminfo_sc() : BasePacket(mpe_cmd::gm_fsminfo_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &state);
			protocol::SerializeEnum(pBuffer, &move_type);
			protocol::SerializeType(pBuffer, &cell_index);
			protocol::SerializeType(pBuffer, &hp);
			protocol::SerializeType(pBuffer, &mp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
