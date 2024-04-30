#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_mandala_layer_info.h"

namespace mir3d
{
	class mp_mandala_reset_cs : public BasePacket 
	{
	public:
		mpe_mandala_type mandala_type{};	// 만다라 타입(1:전투2:장인3:시즌)

	public:
		mp_mandala_reset_cs() : BasePacket(mpe_cmd::mandala_reset_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &mandala_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_mandala_reset_sc : public BasePacket 
	{
	private:
		bool flag_item_add = false;
		mps_item_add item_add;
		mps_item_add* p_item_add = nullptr;
	public:
		bool has_item_add() const
		{
			return flag_item_add;
		}
		mps_item_add* alloc_item_add()
		{
			flag_item_add = true;
			return &item_add;
		}
		const mps_item_add* get_item_add() const
		{
			if (true == flag_item_add)
			{
				if (nullptr == p_item_add)
				{
					return &item_add;
				}
				return p_item_add;
			}
			return nullptr;
		}
		void set_item_add(mps_item_add* in_item_add)
		{
			if (nullptr == p_item_add)
			{
				p_item_add = in_item_add;
				flag_item_add = true;
			}
		}
	public:
		std::vector<mps_mandala_layer_info> layer_info{};
	public:
		mpe_mandala_type mandala_type{};	// 만다라 타입(1:전투2:장인3:시즌)

	public:
		mp_mandala_reset_sc() : BasePacket(mpe_cmd::mandala_reset_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
			protocol::SerializeType(pBuffer, &layer_info);
			protocol::SerializeEnum(pBuffer, &mandala_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
