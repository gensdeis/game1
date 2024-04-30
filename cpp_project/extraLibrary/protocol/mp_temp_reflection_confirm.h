#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_obtain_reflection.h"

namespace mir3d
{
	class mp_temp_reflection_confirm_cs : public BasePacket 
	{
	public:
		int64_t temp_uid{};

	public:
		mp_temp_reflection_confirm_cs() : BasePacket(mpe_cmd::temp_reflection_confirm_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &temp_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_temp_reflection_confirm_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_obtain_reflection info;
		mps_obtain_reflection* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_obtain_reflection* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_obtain_reflection* get_info() const
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
		void set_info(mps_obtain_reflection* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int64_t del_uid{};	// 보관함에서 삭제된 uid

	public:
		mp_temp_reflection_confirm_sc() : BasePacket(mpe_cmd::temp_reflection_confirm_sc)
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
			protocol::SerializeType(pBuffer, &del_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
