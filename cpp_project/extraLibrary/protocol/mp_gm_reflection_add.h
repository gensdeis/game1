#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_reflection.h"

namespace mir3d
{
	class mp_gm_reflection_add_cs : public BasePacket 
	{
	public:
		int32_t tid{};	// reflection table id

	public:
		mp_gm_reflection_add_cs() : BasePacket(mpe_cmd::gm_reflection_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_reflection_add_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_reflection info;
		mps_reflection* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_reflection* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_reflection* get_info() const
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
		void set_info(mps_reflection* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_gm_reflection_add_sc() : BasePacket(mpe_cmd::gm_reflection_add_sc)
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
