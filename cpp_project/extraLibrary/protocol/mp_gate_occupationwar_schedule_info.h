#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_occupationwar_schedule_view.h"

namespace mir3d
{
	class mp_gate_occupationwar_schedule_info_cs : public BasePacket 	// 비곡점령전 일정 정보 조회
	{

	public:
		mp_gate_occupationwar_schedule_info_cs() : BasePacket(mpe_cmd::gate_occupationwar_schedule_info_cs)
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

	class mp_gate_occupationwar_schedule_info_sc : public BasePacket 	// 비곡점령전 일정 정보 조회
	{
	private:
		bool flag_info = false;
		mps_occupationwar_schedule_view info;
		mps_occupationwar_schedule_view* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_occupationwar_schedule_view* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_occupationwar_schedule_view* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mps_occupationwar_schedule_view* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_gate_occupationwar_schedule_info_sc() : BasePacket(mpe_cmd::gate_occupationwar_schedule_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
