#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_combo_ability.h"

namespace mir3d
{
	class mp_slot_option_select_cs : public BasePacket 
	{
	public:
		int32_t select_index{};	// 취소 : -1
	public:
		uint16_t slot_index{};

	public:
		mp_slot_option_select_cs() : BasePacket(mpe_cmd::slot_option_select_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &select_index);
			protocol::SerializeType(pBuffer, &slot_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_slot_option_select_sc : public BasePacket 
	{
	public:
		uint16_t slot_index{};
	private:
		bool flag_ability = false;
		mps_combo_ability ability;
		mps_combo_ability* p_ability = nullptr;
	public:
		bool has_ability() const
		{
			return flag_ability;
		}
		mps_combo_ability* alloc_ability()
		{
			flag_ability = true;
			return &ability;
		}
		const mps_combo_ability* get_ability() const
		{
			if (true == flag_ability)
			{
				if (nullptr == p_ability)
				{
					return &ability;
				}
				return p_ability;
			}
			return nullptr;
		}
		void set_ability(mps_combo_ability* in_ability)
		{
			if (nullptr == p_ability)
			{
				p_ability = in_ability;
				flag_ability = true;
			}
		}

	public:
		mp_slot_option_select_sc() : BasePacket(mpe_cmd::slot_option_select_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &slot_index);
			protocol::SerializeType(pBuffer, &flag_ability);
			if (true == flag_ability)
			{
				if (nullptr != p_ability)
					protocol::SerializeType(pBuffer, p_ability);
				else
					protocol::SerializeType(pBuffer, &ability);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
