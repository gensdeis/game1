#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_town_dinner_work.h"

namespace mir3d
{
	class mp_castle_town_start_dinner_cs : public BasePacket 	// 장원 만찬 시작
	{
	public:
		int64_t nuid{};
	public:
		int32_t town_id{};
	public:
		int32_t dinner_table_id{};	// 만찬 테이블 아이디

	public:
		mp_castle_town_start_dinner_cs() : BasePacket(mpe_cmd::castle_town_start_dinner_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nuid);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeType(pBuffer, &dinner_table_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_castle_town_start_dinner_sc : public BasePacket 	// 장원 만찬 시작
	{
	private:
		bool flag_dinner_work = false;
		mps_castle_town_dinner_work dinner_work;
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
		mp_castle_town_start_dinner_sc() : BasePacket(mpe_cmd::castle_town_start_dinner_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_dinner_work);
			if (true == flag_dinner_work)
			{
				if (nullptr != p_dinner_work)
					protocol::SerializeType(pBuffer, p_dinner_work);
				else
					protocol::SerializeType(pBuffer, &dinner_work);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
