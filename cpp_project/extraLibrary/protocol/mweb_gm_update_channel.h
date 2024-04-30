#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_server_info.h"

namespace mir3d
{
	class mweb_gm_update_channel_cs : public WebBasePacket 
	{
	public:
		std::string access_token{};
	public:
		int32_t gid{};
	private:
		bool flag_channel = false;
		mrpcs_server_info channel;
		mrpcs_server_info* p_channel = nullptr;
	public:
		bool has_channel() const
		{
			return flag_channel;
		}
		mrpcs_server_info* alloc_channel()
		{
			flag_channel = true;
			return &channel;
		}
		const mrpcs_server_info* get_channel() const
		{
			if (true == flag_channel)
			{
				if (nullptr == p_channel)
				{
					return &channel;
				}
				return p_channel;
			}
			return nullptr;
		}
		void set_channel(mrpcs_server_info* in_channel)
		{
			if (nullptr == p_channel)
			{
				p_channel = in_channel;
				flag_channel = true;
			}
		}

	public:
		mweb_gm_update_channel_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &flag_channel);
			if (true == flag_channel)
			{
				if (nullptr != p_channel)
					protocol::SerializeType(pBuffer, p_channel);
				else
					protocol::SerializeType(pBuffer, &channel);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_update_channel_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_gm_update_channel_sc() : WebBasePacket()
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
