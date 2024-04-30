#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_town_work.h"

namespace mir3d
{
	class mp_castle_town_work_use_character_item_cs : public BasePacket 	// 장원 유저 개인 아이템 사용 처리 (self)
	{
	private:
		bool flag_work = false;
		mps_castle_town_work work;	// 장원 작업
		mps_castle_town_work* p_work = nullptr;
	public:
		bool has_work() const
		{
			return flag_work;
		}
		mps_castle_town_work* alloc_work()
		{
			flag_work = true;
			return &work;
		}
		const mps_castle_town_work* get_work() const
		{
			if (true == flag_work)
			{
				if (nullptr == p_work)
				{
					return &work;
				}
				return p_work;
			}
			return nullptr;
		}
		void set_work(mps_castle_town_work* in_work)
		{
			if (nullptr == p_work)
			{
				p_work = in_work;
				flag_work = true;
			}
		}

	public:
		mp_castle_town_work_use_character_item_cs() : BasePacket(mpe_cmd::castle_town_work_use_character_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_work);
			if (true == flag_work)
			{
				if (nullptr != p_work)
					protocol::SerializeType(pBuffer, p_work);
				else
					protocol::SerializeType(pBuffer, &work);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_castle_town_work_use_character_item_sc : public BasePacket 	// 장원 유저 개인 아이템 사용 처리 (self)
	{

	public:
		mp_castle_town_work_use_character_item_sc() : BasePacket(mpe_cmd::castle_town_work_use_character_item_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
