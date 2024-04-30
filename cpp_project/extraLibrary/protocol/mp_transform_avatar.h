#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_avatar_info.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mp_transform_avatar_cs : public BasePacket 	// 아바타 변신
	{
	public:
		int32_t avatar_id{};	// 아이템 아이디로 변환 예정 ?
	public:
		int64_t iuid{};

	public:
		mp_transform_avatar_cs() : BasePacket(mpe_cmd::transform_avatar_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &avatar_id);
			protocol::SerializeType(pBuffer, &iuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_transform_avatar_sc : public BasePacket 	// 아바타 변신
	{
	private:
		bool flag_avatar_info = false;
		mps_avatar_info avatar_info;
		mps_avatar_info* p_avatar_info = nullptr;
	public:
		bool has_avatar_info() const
		{
			return flag_avatar_info;
		}
		mps_avatar_info* alloc_avatar_info()
		{
			flag_avatar_info = true;
			return &avatar_info;
		}
		const mps_avatar_info* get_avatar_info() const
		{
			if (true == flag_avatar_info)
			{
				if (nullptr == p_avatar_info)
				{
					return &avatar_info;
				}
				return p_avatar_info;
			}
			return nullptr;
		}
		void set_avatar_info(mps_avatar_info* in_avatar_info)
		{
			if (nullptr == p_avatar_info)
			{
				p_avatar_info = in_avatar_info;
				flag_avatar_info = true;
			}
		}
	public:
		float atk_speed{};
	public:
		float run_speed{};	// 이동속도
	private:
		bool flag_use_item = false;
		mps_item_count_update use_item;	// 소모된 아이템
		mps_item_count_update* p_use_item = nullptr;
	public:
		bool has_use_item() const
		{
			return flag_use_item;
		}
		mps_item_count_update* alloc_use_item()
		{
			flag_use_item = true;
			return &use_item;
		}
		const mps_item_count_update* get_use_item() const
		{
			if (true == flag_use_item)
			{
				if (nullptr == p_use_item)
				{
					return &use_item;
				}
				return p_use_item;
			}
			return nullptr;
		}
		void set_use_item(mps_item_count_update* in_use_item)
		{
			if (nullptr == p_use_item)
			{
				p_use_item = in_use_item;
				flag_use_item = true;
			}
		}

	public:
		mp_transform_avatar_sc() : BasePacket(mpe_cmd::transform_avatar_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_avatar_info);
			if (true == flag_avatar_info)
			{
				if (nullptr != p_avatar_info)
					protocol::SerializeType(pBuffer, p_avatar_info);
				else
					protocol::SerializeType(pBuffer, &avatar_info);
			}
			protocol::SerializeType(pBuffer, &atk_speed);
			protocol::SerializeType(pBuffer, &run_speed);
			protocol::SerializeType(pBuffer, &flag_use_item);
			if (true == flag_use_item)
			{
				if (nullptr != p_use_item)
					protocol::SerializeType(pBuffer, p_use_item);
				else
					protocol::SerializeType(pBuffer, &use_item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
