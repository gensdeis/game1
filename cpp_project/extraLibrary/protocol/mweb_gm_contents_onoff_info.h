#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_redis_contents_onoff_info.h"

namespace mir3d
{
	class mweb_gm_contents_onoff_info_cs : public WebBasePacket 
	{
	public:
		int32_t gid{};
	public:
		int32_t contents_type{};

	public:
		mweb_gm_contents_onoff_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &contents_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_contents_onoff_info_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	private:
		bool flag_onoff_info = false;
		mrpcs_redis_contents_onoff_info onoff_info;
		mrpcs_redis_contents_onoff_info* p_onoff_info = nullptr;
	public:
		bool has_onoff_info() const
		{
			return flag_onoff_info;
		}
		mrpcs_redis_contents_onoff_info* alloc_onoff_info()
		{
			flag_onoff_info = true;
			return &onoff_info;
		}
		const mrpcs_redis_contents_onoff_info* get_onoff_info() const
		{
			if (true == flag_onoff_info)
			{
				if (nullptr == p_onoff_info)
				{
					return &onoff_info;
				}
				return p_onoff_info;
			}
			return nullptr;
		}
		void set_onoff_info(mrpcs_redis_contents_onoff_info* in_onoff_info)
		{
			if (nullptr == p_onoff_info)
			{
				p_onoff_info = in_onoff_info;
				flag_onoff_info = true;
			}
		}

	public:
		mweb_gm_contents_onoff_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_onoff_info);
			if (true == flag_onoff_info)
			{
				if (nullptr != p_onoff_info)
					protocol::SerializeType(pBuffer, p_onoff_info);
				else
					protocol::SerializeType(pBuffer, &onoff_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
