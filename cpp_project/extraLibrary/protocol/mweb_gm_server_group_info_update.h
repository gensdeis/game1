#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_server_group_info.h"

namespace mir3d
{
	class mweb_gm_server_group_info_update_cs : public WebBasePacket 
	{
	private:
		bool flag_server_group_info = false;
		mrpcs_server_group_info server_group_info;
		mrpcs_server_group_info* p_server_group_info = nullptr;
	public:
		bool has_server_group_info() const
		{
			return flag_server_group_info;
		}
		mrpcs_server_group_info* alloc_server_group_info()
		{
			flag_server_group_info = true;
			return &server_group_info;
		}
		const mrpcs_server_group_info* get_server_group_info() const
		{
			if (true == flag_server_group_info)
			{
				if (nullptr == p_server_group_info)
				{
					return &server_group_info;
				}
				return p_server_group_info;
			}
			return nullptr;
		}
		void set_server_group_info(mrpcs_server_group_info* in_server_group_info)
		{
			if (nullptr == p_server_group_info)
			{
				p_server_group_info = in_server_group_info;
				flag_server_group_info = true;
			}
		}

	public:
		mweb_gm_server_group_info_update_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_server_group_info);
			if (true == flag_server_group_info)
			{
				if (nullptr != p_server_group_info)
					protocol::SerializeType(pBuffer, p_server_group_info);
				else
					protocol::SerializeType(pBuffer, &server_group_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_server_group_info_update_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_gm_server_group_info_update_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
