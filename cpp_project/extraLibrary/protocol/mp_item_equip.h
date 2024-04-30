#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_equip_info_list.h"
#include "struct/mps_equip_info_list.h"

namespace mir3d
{
	class mp_item_equip_cs : public BasePacket 
	{
	public:
		mpe_equip_flag flag{};	// [default = equip];
	private:
		bool flag_info = false;
		mps_equip_info_list info;
		mps_equip_info_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_equip_info_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_equip_info_list* get_info() const
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
		void set_info(mps_equip_info_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_item_equip_cs() : BasePacket(mpe_cmd::item_equip_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &flag);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_item_equip_sc : public BasePacket 
	{
	public:
		mpe_equip_flag flag{};
	public:
		float weight{};
	private:
		bool flag_info = false;
		mps_equip_info_list info;
		mps_equip_info_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_equip_info_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_equip_info_list* get_info() const
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
		void set_info(mps_equip_info_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_item_equip_sc() : BasePacket(mpe_cmd::item_equip_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &flag);
			protocol::SerializeType(pBuffer, &weight);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
