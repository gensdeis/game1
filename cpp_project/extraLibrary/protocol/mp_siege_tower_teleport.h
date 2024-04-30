#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_vector2d.h"

namespace mir3d
{
	class mp_siege_tower_teleport_cs : public BasePacket 	// 공성차 텔레포트
	{
	public:
		int32_t gate_id{};	// 공성차 gate id

	public:
		mp_siege_tower_teleport_cs() : BasePacket(mpe_cmd::siege_tower_teleport_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gate_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_siege_tower_teleport_sc : public BasePacket 	// 공성차 텔레포트
	{
	public:
		int32_t map_id{};	// 공성전 map id
	private:
		bool flag_pos = false;
		mps_vector2d pos;	// "이동 위치 x,y"
		mps_vector2d* p_pos = nullptr;
	public:
		bool has_pos() const
		{
			return flag_pos;
		}
		mps_vector2d* alloc_pos()
		{
			flag_pos = true;
			return &pos;
		}
		const mps_vector2d* get_pos() const
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
		void set_pos(mps_vector2d* in_pos)
		{
			if (nullptr == p_pos)
			{
				p_pos = in_pos;
				flag_pos = true;
			}
		}

	public:
		mp_siege_tower_teleport_sc() : BasePacket(mpe_cmd::siege_tower_teleport_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &map_id);
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
