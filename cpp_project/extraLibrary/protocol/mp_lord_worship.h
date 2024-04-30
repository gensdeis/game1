#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_lord_worship_cs : public BasePacket 	// 경배 요청
	{
	public:
		int32_t castle_id{};	// 어느 성인지

	public:
		mp_lord_worship_cs() : BasePacket(mpe_cmd::lord_worship_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &castle_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_lord_worship_sc : public BasePacket 	// 경배 요청
	{
	public:
		int32_t remain_worship_count{};	// 경배 후 남은 횟수
	public:
		uint8_t lucky{};	// "몇배수값인지(1,2,3)"
	public:
		int32_t total_bless_point{};	// 경배 후 최신 축복포인트값
	public:
		int32_t castle_id{};	// 어느 성인지
	private:
		bool flag_info = false;
		mps_item_add info;	// 변경된재화or아이템
		mps_item_add* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_add* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_add* get_info() const
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
		void set_info(mps_item_add* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_lord_worship_sc() : BasePacket(mpe_cmd::lord_worship_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &remain_worship_count);
			protocol::SerializeType(pBuffer, &lucky);
			protocol::SerializeType(pBuffer, &total_bless_point);
			protocol::SerializeType(pBuffer, &castle_id);
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
