#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_redis_server_group_state.h"

namespace mir3d
{
	class mweb_gm_server_group_info_select_cs : public WebBasePacket 
	{
	public:
		int32_t gid{};

	public:
		mweb_gm_server_group_info_select_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_server_group_info_select_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	private:
		bool flag_server_group_state = false;
		mrpcs_redis_server_group_state server_group_state;
		mrpcs_redis_server_group_state* p_server_group_state = nullptr;
	public:
		bool has_server_group_state() const
		{
			return flag_server_group_state;
		}
		mrpcs_redis_server_group_state* alloc_server_group_state()
		{
			flag_server_group_state = true;
			return &server_group_state;
		}
		const mrpcs_redis_server_group_state* get_server_group_state() const
		{
			if (true == flag_server_group_state)
			{
				if (nullptr == p_server_group_state)
				{
					return &server_group_state;
				}
				return p_server_group_state;
			}
			return nullptr;
		}
		void set_server_group_state(mrpcs_redis_server_group_state* in_server_group_state)
		{
			if (nullptr == p_server_group_state)
			{
				p_server_group_state = in_server_group_state;
				flag_server_group_state = true;
			}
		}

	public:
		mweb_gm_server_group_info_select_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_server_group_state);
			if (true == flag_server_group_state)
			{
				if (nullptr != p_server_group_state)
					protocol::SerializeType(pBuffer, p_server_group_state);
				else
					protocol::SerializeType(pBuffer, &server_group_state);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
