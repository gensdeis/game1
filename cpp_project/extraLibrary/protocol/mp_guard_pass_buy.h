#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods.h"

namespace mir3d
{
	class mp_guard_pass_buy_cs : public BasePacket 
	{

	public:
		mp_guard_pass_buy_cs() : BasePacket(mpe_cmd::guard_pass_buy_cs)
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

	class mp_guard_pass_buy_sc : public BasePacket 
	{
	private:
		bool flag_update_goods = false;
		mps_update_goods update_goods;
		mps_update_goods* p_update_goods = nullptr;
	public:
		bool has_update_goods() const
		{
			return flag_update_goods;
		}
		mps_update_goods* alloc_update_goods()
		{
			flag_update_goods = true;
			return &update_goods;
		}
		const mps_update_goods* get_update_goods() const
		{
			if (true == flag_update_goods)
			{
				if (nullptr == p_update_goods)
				{
					return &update_goods;
				}
				return p_update_goods;
			}
			return nullptr;
		}
		void set_update_goods(mps_update_goods* in_update_goods)
		{
			if (nullptr == p_update_goods)
			{
				p_update_goods = in_update_goods;
				flag_update_goods = true;
			}
		}

	public:
		mp_guard_pass_buy_sc() : BasePacket(mpe_cmd::guard_pass_buy_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_update_goods);
			if (true == flag_update_goods)
			{
				if (nullptr != p_update_goods)
					protocol::SerializeType(pBuffer, p_update_goods);
				else
					protocol::SerializeType(pBuffer, &update_goods);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
