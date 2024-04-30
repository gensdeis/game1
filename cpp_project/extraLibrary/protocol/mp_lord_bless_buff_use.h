#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_lord_bless_buff.h"

namespace mir3d
{
	class mp_lord_bless_buff_use_cs : public BasePacket 	// 성주 축복 사용
	{
	public:
		int32_t bless_buff_id{};	// 어느 축복인지
	public:
		int32_t castle_id{};	// 어느 성인지,f

	public:
		mp_lord_bless_buff_use_cs() : BasePacket(mpe_cmd::lord_bless_buff_use_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &bless_buff_id);
			protocol::SerializeType(pBuffer, &castle_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_lord_bless_buff_use_sc : public BasePacket 	// 성주 축복 사용
	{
	public:
		int32_t remain_bless_point{};	// 축복 사용후 남은 축복포인트
	private:
		bool flag_bless_buff = false;
		mps_lord_bless_buff bless_buff;	// 축복 버프정보
		mps_lord_bless_buff* p_bless_buff = nullptr;
	public:
		bool has_bless_buff() const
		{
			return flag_bless_buff;
		}
		mps_lord_bless_buff* alloc_bless_buff()
		{
			flag_bless_buff = true;
			return &bless_buff;
		}
		const mps_lord_bless_buff* get_bless_buff() const
		{
			if (true == flag_bless_buff)
			{
				if (nullptr == p_bless_buff)
				{
					return &bless_buff;
				}
				return p_bless_buff;
			}
			return nullptr;
		}
		void set_bless_buff(mps_lord_bless_buff* in_bless_buff)
		{
			if (nullptr == p_bless_buff)
			{
				p_bless_buff = in_bless_buff;
				flag_bless_buff = true;
			}
		}

	public:
		mp_lord_bless_buff_use_sc() : BasePacket(mpe_cmd::lord_bless_buff_use_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &remain_bless_point);
			protocol::SerializeType(pBuffer, &flag_bless_buff);
			if (true == flag_bless_buff)
			{
				if (nullptr != p_bless_buff)
					protocol::SerializeType(pBuffer, p_bless_buff);
				else
					protocol::SerializeType(pBuffer, &bless_buff);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
