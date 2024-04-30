#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_restore_item.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_restore_item_cs : public BasePacket 	// 강화 실패 아이템 복구
	{
	private:
		bool flag_restore_info = false;
		mps_restore_item restore_info;	// 복구할 정보
		mps_restore_item* p_restore_info = nullptr;
	public:
		bool has_restore_info() const
		{
			return flag_restore_info;
		}
		mps_restore_item* alloc_restore_info()
		{
			flag_restore_info = true;
			return &restore_info;
		}
		const mps_restore_item* get_restore_info() const
		{
			if (true == flag_restore_info)
			{
				if (nullptr == p_restore_info)
				{
					return &restore_info;
				}
				return p_restore_info;
			}
			return nullptr;
		}
		void set_restore_info(mps_restore_item* in_restore_info)
		{
			if (nullptr == p_restore_info)
			{
				p_restore_info = in_restore_info;
				flag_restore_info = true;
			}
		}

	public:
		mp_restore_item_cs() : BasePacket(mpe_cmd::restore_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_restore_info);
			if (true == flag_restore_info)
			{
				if (nullptr != p_restore_info)
					protocol::SerializeType(pBuffer, p_restore_info);
				else
					protocol::SerializeType(pBuffer, &restore_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_restore_item_sc : public BasePacket 	// 강화 실패 아이템 복구
	{
	private:
		bool flag_item_add = false;
		mps_item_add item_add;	// 갱신된 아이템 및 굿즈 정보
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
		mp_restore_item_sc() : BasePacket(mpe_cmd::restore_item_sc)
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
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
