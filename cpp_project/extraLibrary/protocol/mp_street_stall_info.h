#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_street_stall_info.h"

namespace mir3d
{
	class mp_street_stall_info_cs : public BasePacket 	// // 개인 노점 정보
	{

	public:
		mp_street_stall_info_cs() : BasePacket(mpe_cmd::street_stall_info_cs)
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

	class mp_street_stall_info_sc : public BasePacket 	// // 개인 노점 정보
	{
	private:
		bool flag_street_stall_info = false;
		mps_street_stall_info street_stall_info;
		mps_street_stall_info* p_street_stall_info = nullptr;
	public:
		bool has_street_stall_info() const
		{
			return flag_street_stall_info;
		}
		mps_street_stall_info* alloc_street_stall_info()
		{
			flag_street_stall_info = true;
			return &street_stall_info;
		}
		const mps_street_stall_info* get_street_stall_info() const
		{
			if (true == flag_street_stall_info)
			{
				if (nullptr == p_street_stall_info)
				{
					return &street_stall_info;
				}
				return p_street_stall_info;
			}
			return nullptr;
		}
		void set_street_stall_info(mps_street_stall_info* in_street_stall_info)
		{
			if (nullptr == p_street_stall_info)
			{
				p_street_stall_info = in_street_stall_info;
				flag_street_stall_info = true;
			}
		}

	public:
		mp_street_stall_info_sc() : BasePacket(mpe_cmd::street_stall_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_street_stall_info);
			if (true == flag_street_stall_info)
			{
				if (nullptr != p_street_stall_info)
					protocol::SerializeType(pBuffer, p_street_stall_info);
				else
					protocol::SerializeType(pBuffer, &street_stall_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
