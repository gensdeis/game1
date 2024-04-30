#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_town_arsenal_work.h"
#include "struct/mps_castle_town_dinner_work.h"
#include "struct/mps_castle_town_specialties_work.h"
#include "struct/mps_castle_town_character_specialties_work.h"

namespace mir3d
{
	class mp_castle_town_hud_info_cs : public BasePacket 	// 장원 hud 전체 정보
	{
	public:
		int32_t town_id{};

	public:
		mp_castle_town_hud_info_cs() : BasePacket(mpe_cmd::castle_town_hud_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &town_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_castle_town_hud_info_sc : public BasePacket 	// 장원 hud 전체 정보
	{
	private:
		bool flag_arsenal_work = false;
		mps_castle_town_arsenal_work arsenal_work;	// 병기창
		mps_castle_town_arsenal_work* p_arsenal_work = nullptr;
	public:
		bool has_arsenal_work() const
		{
			return flag_arsenal_work;
		}
		mps_castle_town_arsenal_work* alloc_arsenal_work()
		{
			flag_arsenal_work = true;
			return &arsenal_work;
		}
		const mps_castle_town_arsenal_work* get_arsenal_work() const
		{
			if (true == flag_arsenal_work)
			{
				if (nullptr == p_arsenal_work)
				{
					return &arsenal_work;
				}
				return p_arsenal_work;
			}
			return nullptr;
		}
		void set_arsenal_work(mps_castle_town_arsenal_work* in_arsenal_work)
		{
			if (nullptr == p_arsenal_work)
			{
				p_arsenal_work = in_arsenal_work;
				flag_arsenal_work = true;
			}
		}
	private:
		bool flag_dinner_work = false;
		mps_castle_town_dinner_work dinner_work;	// 만찬
		mps_castle_town_dinner_work* p_dinner_work = nullptr;
	public:
		bool has_dinner_work() const
		{
			return flag_dinner_work;
		}
		mps_castle_town_dinner_work* alloc_dinner_work()
		{
			flag_dinner_work = true;
			return &dinner_work;
		}
		const mps_castle_town_dinner_work* get_dinner_work() const
		{
			if (true == flag_dinner_work)
			{
				if (nullptr == p_dinner_work)
				{
					return &dinner_work;
				}
				return p_dinner_work;
			}
			return nullptr;
		}
		void set_dinner_work(mps_castle_town_dinner_work* in_dinner_work)
		{
			if (nullptr == p_dinner_work)
			{
				p_dinner_work = in_dinner_work;
				flag_dinner_work = true;
			}
		}
	public:
		std::vector<mps_castle_town_specialties_work> specialties_work{};	// 특산품
	private:
		bool flag_character_specialties_work = false;
		mps_castle_town_character_specialties_work character_specialties_work;	// 특산품-개인
		mps_castle_town_character_specialties_work* p_character_specialties_work = nullptr;
	public:
		bool has_character_specialties_work() const
		{
			return flag_character_specialties_work;
		}
		mps_castle_town_character_specialties_work* alloc_character_specialties_work()
		{
			flag_character_specialties_work = true;
			return &character_specialties_work;
		}
		const mps_castle_town_character_specialties_work* get_character_specialties_work() const
		{
			if (true == flag_character_specialties_work)
			{
				if (nullptr == p_character_specialties_work)
				{
					return &character_specialties_work;
				}
				return p_character_specialties_work;
			}
			return nullptr;
		}
		void set_character_specialties_work(mps_castle_town_character_specialties_work* in_character_specialties_work)
		{
			if (nullptr == p_character_specialties_work)
			{
				p_character_specialties_work = in_character_specialties_work;
				flag_character_specialties_work = true;
			}
		}
	public:
		bool is_get_dinner_item{};	// 장원만찬 아이템 획득여부(참여여부)

	public:
		mp_castle_town_hud_info_sc() : BasePacket(mpe_cmd::castle_town_hud_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_arsenal_work);
			if (true == flag_arsenal_work)
			{
				if (nullptr != p_arsenal_work)
					protocol::SerializeType(pBuffer, p_arsenal_work);
				else
					protocol::SerializeType(pBuffer, &arsenal_work);
			}
			protocol::SerializeType(pBuffer, &flag_dinner_work);
			if (true == flag_dinner_work)
			{
				if (nullptr != p_dinner_work)
					protocol::SerializeType(pBuffer, p_dinner_work);
				else
					protocol::SerializeType(pBuffer, &dinner_work);
			}
			protocol::SerializeType(pBuffer, &specialties_work);
			protocol::SerializeType(pBuffer, &flag_character_specialties_work);
			if (true == flag_character_specialties_work)
			{
				if (nullptr != p_character_specialties_work)
					protocol::SerializeType(pBuffer, p_character_specialties_work);
				else
					protocol::SerializeType(pBuffer, &character_specialties_work);
			}
			protocol::SerializeType(pBuffer, &is_get_dinner_item);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
