#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_iuid_list.h"
#include "struct/mps_storage_move.h"

namespace mir3d
{
	class mp_storage_move_cs : public BasePacket 
	{
	public:
		uint16_t cur_type{};	// 아이템 현재 위치
	public:
		uint16_t target_type{};	// 들어갈 창고 위치
	private:
		bool flag_info = false;
		mps_item_iuid_list info;	// 이동할 아이템
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
		int64_t npc_uid{};	// 창고 npc uid

	public:
		mp_storage_move_cs() : BasePacket(mpe_cmd::storage_move_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cur_type);
			protocol::SerializeType(pBuffer, &target_type);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &npc_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_storage_move_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_storage_move info;	// 변경 정보
		mps_storage_move* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_storage_move* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_storage_move* get_info() const
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
		void set_info(mps_storage_move* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_storage_move_sc() : BasePacket(mpe_cmd::storage_move_sc)
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

}
