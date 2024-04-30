#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_lord_bless_info.h"

namespace mir3d
{
	class mp_lord_bless_info_cs : public BasePacket 	// 경배 페이지 열때 정보 요청하는 패킷
	{
	public:
		int32_t castle_id{};	// 어느 성의 정보 요청인지 알수 있게

	public:
		mp_lord_bless_info_cs() : BasePacket(mpe_cmd::lord_bless_info_cs)
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

	class mp_lord_bless_info_sc : public BasePacket 	// 경배 페이지 열때 정보 요청하는 패킷
	{
	private:
		bool flag_bless_info = false;
		mps_lord_bless_info bless_info;	// 축복정보 (성주가 건 축복 정보)
		mps_lord_bless_info* p_bless_info = nullptr;
	public:
		bool has_bless_info() const
		{
			return flag_bless_info;
		}
		mps_lord_bless_info* alloc_bless_info()
		{
			flag_bless_info = true;
			return &bless_info;
		}
		const mps_lord_bless_info* get_bless_info() const
		{
			if (true == flag_bless_info)
			{
				if (nullptr == p_bless_info)
				{
					return &bless_info;
				}
				return p_bless_info;
			}
			return nullptr;
		}
		void set_bless_info(mps_lord_bless_info* in_bless_info)
		{
			if (nullptr == p_bless_info)
			{
				p_bless_info = in_bless_info;
				flag_bless_info = true;
			}
		}
	public:
		int32_t recharge_time{};	// 마지막 충전 시간(자신)
	public:
		int32_t remain_worship_count{};	// 현재 남은 경배 횟수(자신)

	public:
		mp_lord_bless_info_sc() : BasePacket(mpe_cmd::lord_bless_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_bless_info);
			if (true == flag_bless_info)
			{
				if (nullptr != p_bless_info)
					protocol::SerializeType(pBuffer, p_bless_info);
				else
					protocol::SerializeType(pBuffer, &bless_info);
			}
			protocol::SerializeType(pBuffer, &recharge_time);
			protocol::SerializeType(pBuffer, &remain_worship_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
