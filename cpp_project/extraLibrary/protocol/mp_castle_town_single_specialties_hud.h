#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_town_specialties_work.h"

namespace mir3d
{
	class mp_castle_town_single_specialties_hud_cs : public BasePacket 	// 장원 hud  정보
	{
	public:
		int32_t town_id{};
	public:
		mpe_castle_town_specialties_pos specialties_pos{};

	public:
		mp_castle_town_single_specialties_hud_cs() : BasePacket(mpe_cmd::castle_town_single_specialties_hud_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeEnum(pBuffer, &specialties_pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_castle_town_single_specialties_hud_sc : public BasePacket 	// 장원 hud  정보
	{
	private:
		bool flag_specialties_work = false;
		mps_castle_town_specialties_work specialties_work;	// 특산품
		mps_castle_town_specialties_work* p_specialties_work = nullptr;
	public:
		bool has_specialties_work() const
		{
			return flag_specialties_work;
		}
		mps_castle_town_specialties_work* alloc_specialties_work()
		{
			flag_specialties_work = true;
			return &specialties_work;
		}
		const mps_castle_town_specialties_work* get_specialties_work() const
		{
			if (true == flag_specialties_work)
			{
				if (nullptr == p_specialties_work)
				{
					return &specialties_work;
				}
				return p_specialties_work;
			}
			return nullptr;
		}
		void set_specialties_work(mps_castle_town_specialties_work* in_specialties_work)
		{
			if (nullptr == p_specialties_work)
			{
				p_specialties_work = in_specialties_work;
				flag_specialties_work = true;
			}
		}

	public:
		mp_castle_town_single_specialties_hud_sc() : BasePacket(mpe_cmd::castle_town_single_specialties_hud_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_specialties_work);
			if (true == flag_specialties_work)
			{
				if (nullptr != p_specialties_work)
					protocol::SerializeType(pBuffer, p_specialties_work);
				else
					protocol::SerializeType(pBuffer, &specialties_work);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
