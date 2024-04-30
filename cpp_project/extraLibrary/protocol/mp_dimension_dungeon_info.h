#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_zone_object_info.h"

namespace mir3d
{
	class mp_dimension_dungeon_info_cs : public BasePacket 
	{

	public:
		mp_dimension_dungeon_info_cs() : BasePacket(mpe_cmd::dimension_dungeon_info_cs)
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

	class mp_dimension_dungeon_info_sc : public BasePacket 
	{
	public:
		mpe_dimension_dungeon_gate_state_type state{};	// 차원문 상태
	private:
		bool flag_gate_info = false;
		mps_zone_object_info gate_info;	// 차원문의 소환 정보
		mps_zone_object_info* p_gate_info = nullptr;
	public:
		bool has_gate_info() const
		{
			return flag_gate_info;
		}
		mps_zone_object_info* alloc_gate_info()
		{
			flag_gate_info = true;
			return &gate_info;
		}
		const mps_zone_object_info* get_gate_info() const
		{
			if (true == flag_gate_info)
			{
				if (nullptr == p_gate_info)
				{
					return &gate_info;
				}
				return p_gate_info;
			}
			return nullptr;
		}
		void set_gate_info(mps_zone_object_info* in_gate_info)
		{
			if (nullptr == p_gate_info)
			{
				p_gate_info = in_gate_info;
				flag_gate_info = true;
			}
		}

	public:
		mp_dimension_dungeon_info_sc() : BasePacket(mpe_cmd::dimension_dungeon_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &flag_gate_info);
			if (true == flag_gate_info)
			{
				if (nullptr != p_gate_info)
					protocol::SerializeType(pBuffer, p_gate_info);
				else
					protocol::SerializeType(pBuffer, &gate_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
