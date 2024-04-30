#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mentor.h"

namespace mir3d
{
	class mp_gate_mentor_info_cs : public BasePacket 
	{
	public:
		int64_t cuid{};

	public:
		mp_gate_mentor_info_cs() : BasePacket(mpe_cmd::gate_mentor_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_mentor_info_sc : public BasePacket 
	{
	private:
		bool flag_mentor_info = false;
		mps_mentor mentor_info;
		mps_mentor* p_mentor_info = nullptr;
	public:
		bool has_mentor_info() const
		{
			return flag_mentor_info;
		}
		mps_mentor* alloc_mentor_info()
		{
			flag_mentor_info = true;
			return &mentor_info;
		}
		const mps_mentor* get_mentor_info() const
		{
			if (true == flag_mentor_info)
			{
				if (nullptr == p_mentor_info)
				{
					return &mentor_info;
				}
				return p_mentor_info;
			}
			return nullptr;
		}
		void set_mentor_info(mps_mentor* in_mentor_info)
		{
			if (nullptr == p_mentor_info)
			{
				p_mentor_info = in_mentor_info;
				flag_mentor_info = true;
			}
		}
	public:
		mpe_mentor_type mentor_type{};
	public:
		int64_t last_online_time{};

	public:
		mp_gate_mentor_info_sc() : BasePacket(mpe_cmd::gate_mentor_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_mentor_info);
			if (true == flag_mentor_info)
			{
				if (nullptr != p_mentor_info)
					protocol::SerializeType(pBuffer, p_mentor_info);
				else
					protocol::SerializeType(pBuffer, &mentor_info);
			}
			protocol::SerializeEnum(pBuffer, &mentor_type);
			protocol::SerializeType(pBuffer, &last_online_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
