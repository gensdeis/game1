#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_vector.h"

namespace mir3d
{
	class mp_zone_teleport_exit_cs : public BasePacket 	// 대형몬스터에 끼었을경우 텔레포트 처리
	{
	public:
		int32_t tile_index{};	// 텔포포트 타일 위치

	public:
		mp_zone_teleport_exit_cs() : BasePacket(mpe_cmd::zone_teleport_exit_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tile_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_zone_teleport_exit_sc : public BasePacket 	// 대형몬스터에 끼었을경우 텔레포트 처리
	{
	private:
		bool flag_pos = false;
		mps_vector pos;
		mps_vector* p_pos = nullptr;
	public:
		bool has_pos() const
		{
			return flag_pos;
		}
		mps_vector* alloc_pos()
		{
			flag_pos = true;
			return &pos;
		}
		const mps_vector* get_pos() const
		{
			if (true == flag_pos)
			{
				if (nullptr == p_pos)
				{
					return &pos;
				}
				return p_pos;
			}
			return nullptr;
		}
		void set_pos(mps_vector* in_pos)
		{
			if (nullptr == p_pos)
			{
				p_pos = in_pos;
				flag_pos = true;
			}
		}

	public:
		mp_zone_teleport_exit_sc() : BasePacket(mpe_cmd::zone_teleport_exit_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_pos);
			if (true == flag_pos)
			{
				if (nullptr != p_pos)
					protocol::SerializeType(pBuffer, p_pos);
				else
					protocol::SerializeType(pBuffer, &pos);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
