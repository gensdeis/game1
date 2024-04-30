#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_town_arsenal_work.h"

namespace mir3d
{
	class mp_castle_town_arsenal_build_work_info_cs : public BasePacket 	// 병기창 작업 정보
	{
	public:
		int64_t nuid{};
	public:
		int32_t town_id{};

	public:
		mp_castle_town_arsenal_build_work_info_cs() : BasePacket(mpe_cmd::castle_town_arsenal_build_work_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nuid);
			protocol::SerializeType(pBuffer, &town_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_castle_town_arsenal_build_work_info_sc : public BasePacket 	// 병기창 작업 정보
	{
	private:
		bool flag_work_info = false;
		mps_castle_town_arsenal_work work_info;
		mps_castle_town_arsenal_work* p_work_info = nullptr;
	public:
		bool has_work_info() const
		{
			return flag_work_info;
		}
		mps_castle_town_arsenal_work* alloc_work_info()
		{
			flag_work_info = true;
			return &work_info;
		}
		const mps_castle_town_arsenal_work* get_work_info() const
		{
			if (true == flag_work_info)
			{
				if (nullptr == p_work_info)
				{
					return &work_info;
				}
				return p_work_info;
			}
			return nullptr;
		}
		void set_work_info(mps_castle_town_arsenal_work* in_work_info)
		{
			if (nullptr == p_work_info)
			{
				p_work_info = in_work_info;
				flag_work_info = true;
			}
		}

	public:
		mp_castle_town_arsenal_build_work_info_sc() : BasePacket(mpe_cmd::castle_town_arsenal_build_work_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_work_info);
			if (true == flag_work_info)
			{
				if (nullptr != p_work_info)
					protocol::SerializeType(pBuffer, p_work_info);
				else
					protocol::SerializeType(pBuffer, &work_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
