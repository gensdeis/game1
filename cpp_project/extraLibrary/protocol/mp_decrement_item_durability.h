#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_decrement_item_durability.h"

namespace mir3d
{
	class mp_decrement_item_durability_cs : public BasePacket 
	{

	public:
		mp_decrement_item_durability_cs() : BasePacket(mpe_cmd::decrement_item_durability_cs)
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

	class mp_decrement_item_durability_sc : public BasePacket 
	{
	private:
		bool flag_durability_info = false;
		mps_decrement_item_durability durability_info;	// 아이템 내구도 감소
		mps_decrement_item_durability* p_durability_info = nullptr;
	public:
		bool has_durability_info() const
		{
			return flag_durability_info;
		}
		mps_decrement_item_durability* alloc_durability_info()
		{
			flag_durability_info = true;
			return &durability_info;
		}
		const mps_decrement_item_durability* get_durability_info() const
		{
			if (true == flag_durability_info)
			{
				if (nullptr == p_durability_info)
				{
					return &durability_info;
				}
				return p_durability_info;
			}
			return nullptr;
		}
		void set_durability_info(mps_decrement_item_durability* in_durability_info)
		{
			if (nullptr == p_durability_info)
			{
				p_durability_info = in_durability_info;
				flag_durability_info = true;
			}
		}

	public:
		mp_decrement_item_durability_sc() : BasePacket(mpe_cmd::decrement_item_durability_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_durability_info);
			if (true == flag_durability_info)
			{
				if (nullptr != p_durability_info)
					protocol::SerializeType(pBuffer, p_durability_info);
				else
					protocol::SerializeType(pBuffer, &durability_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
