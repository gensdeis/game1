#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_town_managing_info.h"

namespace mir3d
{
	class mweb_castle_town_single_managing_info_cs : public WebBasePacket 	// 장원 건물 1개 정보
	{
	public:
		int64_t guid{};
	public:
		int32_t town_id{};
	public:
		mpe_castle_town_detail_pos house_pos{};

	public:
		mweb_castle_town_single_managing_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeEnum(pBuffer, &house_pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_castle_town_single_managing_info_sc : public WebBasePacket 	// 장원 건물 1개 정보
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
		mweb_castle_town_single_managing_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
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
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
