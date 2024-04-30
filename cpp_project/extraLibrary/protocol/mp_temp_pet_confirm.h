#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_obtain_pet_info.h"

namespace mir3d
{
	class mp_temp_pet_confirm_cs : public BasePacket 
	{
	public:
		int64_t uid{};	// 보관함uid

	public:
		mp_temp_pet_confirm_cs() : BasePacket(mpe_cmd::temp_pet_confirm_cs)
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

	class mp_temp_pet_confirm_sc : public BasePacket 
	{
	private:
		bool flag_pet_info = false;
		mps_obtain_pet_info pet_info;
		mps_obtain_pet_info* p_pet_info = nullptr;
	public:
		bool has_pet_info() const
		{
			return flag_pet_info;
		}
		mps_obtain_pet_info* alloc_pet_info()
		{
			flag_pet_info = true;
			return &pet_info;
		}
		const mps_obtain_pet_info* get_pet_info() const
		{
			if (true == flag_pet_info)
			{
				if (nullptr == p_pet_info)
				{
					return &pet_info;
				}
				return p_pet_info;
			}
			return nullptr;
		}
		void set_pet_info(mps_obtain_pet_info* in_pet_info)
		{
			if (nullptr == p_pet_info)
			{
				p_pet_info = in_pet_info;
				flag_pet_info = true;
			}
		}
	public:
		int64_t del_uid{};	// 보관함에서 삭제된 uid

	public:
		mp_temp_pet_confirm_sc() : BasePacket(mpe_cmd::temp_pet_confirm_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_pet_info);
			if (true == flag_pet_info)
			{
				if (nullptr != p_pet_info)
					protocol::SerializeType(pBuffer, p_pet_info);
				else
					protocol::SerializeType(pBuffer, &pet_info);
			}
			protocol::SerializeType(pBuffer, &del_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
