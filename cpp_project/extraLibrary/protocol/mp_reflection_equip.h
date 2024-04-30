#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_reflection.h"
#include "struct/mps_reflection.h"
#include "struct/mps_reflection_change_skill.h"

namespace mir3d
{
	class mp_reflection_equip_cs : public BasePacket 
	{
	public:
		int32_t tid{};	// reflection table id

	public:
		mp_reflection_equip_cs() : BasePacket(mpe_cmd::reflection_equip_cs)
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

	class mp_reflection_equip_sc : public BasePacket 
	{
	private:
		bool flag_equip_info = false;
		mps_reflection equip_info;
		mps_reflection* p_equip_info = nullptr;
	public:
		bool has_equip_info() const
		{
			return flag_equip_info;
		}
		mps_reflection* alloc_equip_info()
		{
			flag_equip_info = true;
			return &equip_info;
		}
		const mps_reflection* get_equip_info() const
		{
			if (true == flag_equip_info)
			{
				if (nullptr == p_equip_info)
				{
					return &equip_info;
				}
				return p_equip_info;
			}
			return nullptr;
		}
		void set_equip_info(mps_reflection* in_equip_info)
		{
			if (nullptr == p_equip_info)
			{
				p_equip_info = in_equip_info;
				flag_equip_info = true;
			}
		}
	private:
		bool flag_release_info = false;
		mps_reflection release_info;
		mps_reflection* p_release_info = nullptr;
	public:
		bool has_release_info() const
		{
			return flag_release_info;
		}
		mps_reflection* alloc_release_info()
		{
			flag_release_info = true;
			return &release_info;
		}
		const mps_reflection* get_release_info() const
		{
			if (true == flag_release_info)
			{
				if (nullptr == p_release_info)
				{
					return &release_info;
				}
				return p_release_info;
			}
			return nullptr;
		}
		void set_release_info(mps_reflection* in_release_info)
		{
			if (nullptr == p_release_info)
			{
				p_release_info = in_release_info;
				flag_release_info = true;
			}
		}
	public:
		float atk_speed{};
	public:
		float run_speed{};
	public:
		int32_t reflection_cool_time{};
	public:
		std::vector<mps_reflection_change_skill> list_skill{};
	public:
		std::vector<int32_t> list_special_move_slot{};	// 필살기 슬롯

	public:
		mp_reflection_equip_sc() : BasePacket(mpe_cmd::reflection_equip_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_equip_info);
			if (true == flag_equip_info)
			{
				if (nullptr != p_equip_info)
					protocol::SerializeType(pBuffer, p_equip_info);
				else
					protocol::SerializeType(pBuffer, &equip_info);
			}
			protocol::SerializeType(pBuffer, &flag_release_info);
			if (true == flag_release_info)
			{
				if (nullptr != p_release_info)
					protocol::SerializeType(pBuffer, p_release_info);
				else
					protocol::SerializeType(pBuffer, &release_info);
			}
			protocol::SerializeType(pBuffer, &atk_speed);
			protocol::SerializeType(pBuffer, &run_speed);
			protocol::SerializeType(pBuffer, &reflection_cool_time);
			protocol::SerializeType(pBuffer, &list_skill);
			protocol::SerializeType(pBuffer, &list_special_move_slot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
