#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_combo_ability.h"

namespace mir3d
{
	class mrpc_slot_option_select_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
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
		mrpc_slot_option_select_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::slot_option_select_cs, tag)
		{
		}
		mrpc_slot_option_select_cs() : RpcPacket(mpe_rpc_cmd::slot_option_select_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
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
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_slot_option_select_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_slot_option_select_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::slot_option_select_sc, tag)
		{
		}
		mrpc_slot_option_select_sc() : RpcPacket(mpe_rpc_cmd::slot_option_select_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
