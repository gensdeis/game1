#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mp_zone_seal_device_use_cs : public BasePacket 
	{
	public:
		int64_t ouid{};	// object uid
	public:
		mpe_object_collect_flag flag{};	// 상태
	public:
		int64_t iuid{};

	public:
		mp_zone_seal_device_use_cs() : BasePacket(mpe_cmd::zone_seal_device_use_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ouid);
			protocol::SerializeEnum(pBuffer, &flag);
			protocol::SerializeType(pBuffer, &iuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_zone_seal_device_use_sc : public BasePacket 
	{
	public:
		int64_t cuid{};	// 캐릭터 uid
	public:
		int64_t ouid{};	// object uid
	public:
		mpe_object_collect_flag flag{};	// 상태
	public:
		mpe_character_action action{};	// 액션 상태
	private:
		bool flag_item_info = false;
		mps_item_count_update item_info;	// 아이템 소모 정보
		mps_item_count_update* p_item_info = nullptr;
	public:
		bool has_item_info() const
		{
			return flag_item_info;
		}
		mps_item_count_update* alloc_item_info()
		{
			flag_item_info = true;
			return &item_info;
		}
		const mps_item_count_update* get_item_info() const
		{
			if (true == flag_item_info)
			{
				if (nullptr == p_item_info)
				{
					return &item_info;
				}
				return p_item_info;
			}
			return nullptr;
		}
		void set_item_info(mps_item_count_update* in_item_info)
		{
			if (nullptr == p_item_info)
			{
				p_item_info = in_item_info;
				flag_item_info = true;
			}
		}

	public:
		mp_zone_seal_device_use_sc() : BasePacket(mpe_cmd::zone_seal_device_use_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &ouid);
			protocol::SerializeEnum(pBuffer, &flag);
			protocol::SerializeEnum(pBuffer, &action);
			protocol::SerializeType(pBuffer, &flag_item_info);
			if (true == flag_item_info)
			{
				if (nullptr != p_item_info)
					protocol::SerializeType(pBuffer, p_item_info);
				else
					protocol::SerializeType(pBuffer, &item_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
