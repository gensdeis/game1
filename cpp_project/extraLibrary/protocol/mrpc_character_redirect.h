#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_character_data.h"

namespace mir3d
{
	class mrpc_character_redirect_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		mrpce_server_type type{};
	public:
		int32_t index{};
	public:
		int64_t indun_uid{};
	public:
		int64_t socket_access_token{};

	public:
		mrpc_character_redirect_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_redirect_cs, tag)
		{
		}
		mrpc_character_redirect_cs() : RpcPacket(mpe_rpc_cmd::character_redirect_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeType(pBuffer, &socket_access_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_character_redirect_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_data = false;
		mrpcs_character_data data;
		mrpcs_character_data* p_data = nullptr;
	public:
		bool has_data() const
		{
			return flag_data;
		}
		mrpcs_character_data* alloc_data()
		{
			flag_data = true;
			return &data;
		}
		const mrpcs_character_data* get_data() const
		{
			if (true == flag_data)
			{
				if (nullptr == p_data)
				{
					return &data;
				}
				return p_data;
			}
			return nullptr;
		}
		void set_data(mrpcs_character_data* in_data)
		{
			if (nullptr == p_data)
			{
				p_data = in_data;
				flag_data = true;
			}
		}

	public:
		mrpc_character_redirect_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_redirect_sc, tag)
		{
		}
		mrpc_character_redirect_sc() : RpcPacket(mpe_rpc_cmd::character_redirect_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_data);
			if (true == flag_data)
			{
				if (nullptr != p_data)
					protocol::SerializeType(pBuffer, p_data);
				else
					protocol::SerializeType(pBuffer, &data);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
