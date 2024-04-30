#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_darksteel_storage_daily_pay_info_list.h"

namespace mir3d
{
	class mweb_darksteel_storage_darksteel_daily_pay_cs : public WebBasePacket 	// 비곡창고 일 지급 정보
	{
	public:
		mpe_occupationwar_map_type type{};
	public:
		int64_t guid{};

	public:
		mweb_darksteel_storage_darksteel_daily_pay_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_darksteel_storage_darksteel_daily_pay_sc : public WebBasePacket 	// 비곡창고 일 지급 정보
	{
	private:
		bool flag_info = false;
		mps_darksteel_storage_daily_pay_info_list info;
		mps_darksteel_storage_daily_pay_info_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_darksteel_storage_daily_pay_info_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_darksteel_storage_daily_pay_info_list* get_info() const
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
		void set_info(mps_darksteel_storage_daily_pay_info_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mweb_darksteel_storage_darksteel_daily_pay_sc() : WebBasePacket()
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
