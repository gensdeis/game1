#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_iuid_list.h"
#include "struct/mps_item_update.h"

namespace mir3d
{
	class mp_item_destroy_cs : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_item_iuid_list info;
		mps_item_iuid_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_iuid_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_iuid_list* get_info() const
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
		void set_info(mps_item_iuid_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_item_destroy_cs() : BasePacket(mpe_cmd::item_destroy_cs)
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
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_item_destroy_sc : public BasePacket 
	{
	public:
		float weight{};
	private:
		bool flag_info = false;
		mps_item_update info;	// 수정 -> mps_item_add
		mps_item_update* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_update* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_update* get_info() const
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
		void set_info(mps_item_update* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_item_destroy_sc() : BasePacket(mpe_cmd::item_destroy_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
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
