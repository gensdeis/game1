#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_town_managing_info.h"

namespace mir3d
{
	class mp_gate_castle_town_single_managing_info_cs : public BasePacket 	// 장원 건물 1개 정보
	{
	public:
		int64_t guid{};
	public:
		int32_t town_id{};
	public:
		mpe_castle_town_detail_pos house_pos{};

	public:
		mp_gate_castle_town_single_managing_info_cs() : BasePacket(mpe_cmd::gate_castle_town_single_managing_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeEnum(pBuffer, &house_pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_castle_town_single_managing_info_sc : public BasePacket 	// 장원 건물 1개 정보
	{
	private:
		bool flag_info = false;
		mps_castle_town_managing_info info;
		mps_castle_town_managing_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_castle_town_managing_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_castle_town_managing_info* get_info() const
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
		void set_info(mps_castle_town_managing_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_gate_castle_town_single_managing_info_sc() : BasePacket(mpe_cmd::gate_castle_town_single_managing_info_sc)
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
