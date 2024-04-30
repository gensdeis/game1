#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_avatar.h"
#include "struct/mps_avatar.h"

namespace mir3d
{
	class mp_avatar_slot_set_cs : public BasePacket 
	{
	public:
		int32_t avatar_id{};
	public:
		mpe_avatar_pos pos{};	// max : 슬롯해제

	public:
		mp_avatar_slot_set_cs() : BasePacket(mpe_cmd::avatar_slot_set_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &avatar_id);
			protocol::SerializeEnum(pBuffer, &pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_avatar_slot_set_sc : public BasePacket 
	{
	private:
		bool flag_equip_avatar = false;
		mps_avatar equip_avatar;
		mps_avatar* p_equip_avatar = nullptr;
	public:
		bool has_equip_avatar() const
		{
			return flag_equip_avatar;
		}
		mps_avatar* alloc_equip_avatar()
		{
			flag_equip_avatar = true;
			return &equip_avatar;
		}
		const mps_avatar* get_equip_avatar() const
		{
			if (true == flag_equip_avatar)
			{
				if (nullptr == p_equip_avatar)
				{
					return &equip_avatar;
				}
				return p_equip_avatar;
			}
			return nullptr;
		}
		void set_equip_avatar(mps_avatar* in_equip_avatar)
		{
			if (nullptr == p_equip_avatar)
			{
				p_equip_avatar = in_equip_avatar;
				flag_equip_avatar = true;
			}
		}
	private:
		bool flag_release_avatar = false;
		mps_avatar release_avatar;
		mps_avatar* p_release_avatar = nullptr;
	public:
		bool has_release_avatar() const
		{
			return flag_release_avatar;
		}
		mps_avatar* alloc_release_avatar()
		{
			flag_release_avatar = true;
			return &release_avatar;
		}
		const mps_avatar* get_release_avatar() const
		{
			if (true == flag_release_avatar)
			{
				if (nullptr == p_release_avatar)
				{
					return &release_avatar;
				}
				return p_release_avatar;
			}
			return nullptr;
		}
		void set_release_avatar(mps_avatar* in_release_avatar)
		{
			if (nullptr == p_release_avatar)
			{
				p_release_avatar = in_release_avatar;
				flag_release_avatar = true;
			}
		}

	public:
		mp_avatar_slot_set_sc() : BasePacket(mpe_cmd::avatar_slot_set_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_equip_avatar);
			if (true == flag_equip_avatar)
			{
				if (nullptr != p_equip_avatar)
					protocol::SerializeType(pBuffer, p_equip_avatar);
				else
					protocol::SerializeType(pBuffer, &equip_avatar);
			}
			protocol::SerializeType(pBuffer, &flag_release_avatar);
			if (true == flag_release_avatar)
			{
				if (nullptr != p_release_avatar)
					protocol::SerializeType(pBuffer, p_release_avatar);
				else
					protocol::SerializeType(pBuffer, &release_avatar);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
