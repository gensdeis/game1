#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_darksteel_box_keep_list.h"

namespace mir3d
{
	class mweb_occupationwar_tender_history_cs : public WebBasePacket 	// 개인 보관 히스토리
	{
	public:
		int64_t cuid{};

	public:
		mweb_occupationwar_tender_history_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_occupationwar_tender_history_sc : public WebBasePacket 	// 개인 보관 히스토리
	{
	private:
		bool flag_info = false;
		mps_darksteel_box_keep_list info;
		mps_darksteel_box_keep_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_darksteel_box_keep_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_darksteel_box_keep_list* get_info() const
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
		void set_info(mps_darksteel_box_keep_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mweb_occupationwar_tender_history_sc() : WebBasePacket()
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
