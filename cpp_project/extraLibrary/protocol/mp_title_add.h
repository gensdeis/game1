#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_title_info.h"
#include "struct/mps_item_update.h"

namespace mir3d
{
	class mp_title_add_cs : public BasePacket 
	{
	public:
		int32_t title_id{};	// 칭호 id
	public:
		int64_t iuid{};	// 아이템uid

	public:
		mp_title_add_cs() : BasePacket(mpe_cmd::title_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &title_id);
			protocol::SerializeType(pBuffer, &iuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_title_add_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_title_info info;	// 획득 칭호 정보
		mps_title_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_title_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_title_info* get_info() const
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
		void set_info(mps_title_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int32_t tid{};	// 칭호 tid
	private:
		bool flag_item_update = false;
		mps_item_update item_update;	// 사용 아이템
		mps_item_update* p_item_update = nullptr;
	public:
		bool has_item_update() const
		{
			return flag_item_update;
		}
		mps_item_update* alloc_item_update()
		{
			flag_item_update = true;
			return &item_update;
		}
		const mps_item_update* get_item_update() const
		{
			if (true == flag_item_update)
			{
				if (nullptr == p_item_update)
				{
					return &item_update;
				}
				return p_item_update;
			}
			return nullptr;
		}
		void set_item_update(mps_item_update* in_item_update)
		{
			if (nullptr == p_item_update)
			{
				p_item_update = in_item_update;
				flag_item_update = true;
			}
		}

	public:
		mp_title_add_sc() : BasePacket(mpe_cmd::title_add_sc)
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
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &flag_item_update);
			if (true == flag_item_update)
			{
				if (nullptr != p_item_update)
					protocol::SerializeType(pBuffer, p_item_update);
				else
					protocol::SerializeType(pBuffer, &item_update);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
