#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_occupationwar_darksteel_tax_log_info_list.h"

namespace mir3d
{
	class mweb_gm_occupationwar_darksteel_tax_log_cs : public WebBasePacket 
	{

	public:
		mweb_gm_occupationwar_darksteel_tax_log_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_occupationwar_darksteel_tax_log_sc : public WebBasePacket 
	{
	private:
		bool flag_info = false;
		mrpcs_occupationwar_darksteel_tax_log_info_list info;
		mrpcs_occupationwar_darksteel_tax_log_info_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_occupationwar_darksteel_tax_log_info_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_occupationwar_darksteel_tax_log_info_list* get_info() const
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
		void set_info(mrpcs_occupationwar_darksteel_tax_log_info_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mweb_gm_occupationwar_darksteel_tax_log_sc() : WebBasePacket()
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
