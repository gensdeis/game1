#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods_list.h"

namespace mir3d
{
	class mp_treasureboxkey_charge_cs : public BasePacket 
	{

	public:
		mp_treasureboxkey_charge_cs() : BasePacket(mpe_cmd::treasureboxkey_charge_cs)
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

	class mp_treasureboxkey_charge_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_update_goods_list info;	// 변경된 재화
		mps_update_goods_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_update_goods_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_update_goods_list* get_info() const
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
		void set_info(mps_update_goods_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		uint16_t treasureboxkey_reset_count{};

	public:
		mp_treasureboxkey_charge_sc() : BasePacket(mpe_cmd::treasureboxkey_charge_sc)
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
			protocol::SerializeType(pBuffer, &treasureboxkey_reset_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
