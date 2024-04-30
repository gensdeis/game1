#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_guild_context.h"
#include "struct/mps_guild.h"
#include "struct/mps_item_add.h"
#include "struct/mps_guild_member.h"

namespace mir3d
{
	class mrpc_guild_create_cs : public RpcPacket 
	{
	private:
		bool flag_guild_context = false;
		mrpcs_guild_context guild_context;
		mrpcs_guild_context* p_guild_context = nullptr;
	public:
		bool has_guild_context() const
		{
			return flag_guild_context;
		}
		mrpcs_guild_context* alloc_guild_context()
		{
			flag_guild_context = true;
			return &guild_context;
		}
		const mrpcs_guild_context* get_guild_context() const
		{
			if (true == flag_guild_context)
			{
				if (nullptr == p_guild_context)
				{
					return &guild_context;
				}
				return p_guild_context;
			}
			return nullptr;
		}
		void set_guild_context(mrpcs_guild_context* in_guild_context)
		{
			if (nullptr == p_guild_context)
			{
				p_guild_context = in_guild_context;
				flag_guild_context = true;
			}
		}

	public:
		mrpc_guild_create_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_create_cs, tag)
		{
		}
		mrpc_guild_create_cs() : RpcPacket(mpe_rpc_cmd::guild_create_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_guild_context);
			if (true == flag_guild_context)
			{
				if (nullptr != p_guild_context)
					protocol::SerializeType(pBuffer, p_guild_context);
				else
					protocol::SerializeType(pBuffer, &guild_context);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_create_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_guild = false;
		mps_guild guild;
		mps_guild* p_guild = nullptr;
	public:
		bool has_guild() const
		{
			return flag_guild;
		}
		mps_guild* alloc_guild()
		{
			flag_guild = true;
			return &guild;
		}
		const mps_guild* get_guild() const
		{
			if (true == flag_guild)
			{
				if (nullptr == p_guild)
				{
					return &guild;
				}
				return p_guild;
			}
			return nullptr;
		}
		void set_guild(mps_guild* in_guild)
		{
			if (nullptr == p_guild)
			{
				p_guild = in_guild;
				flag_guild = true;
			}
		}
	private:
		bool flag_use_item = false;
		mps_item_add use_item;
		mps_item_add* p_use_item = nullptr;
	public:
		bool has_use_item() const
		{
			return flag_use_item;
		}
		mps_item_add* alloc_use_item()
		{
			flag_use_item = true;
			return &use_item;
		}
		const mps_item_add* get_use_item() const
		{
			if (true == flag_use_item)
			{
				if (nullptr == p_use_item)
				{
					return &use_item;
				}
				return p_use_item;
			}
			return nullptr;
		}
		void set_use_item(mps_item_add* in_use_item)
		{
			if (nullptr == p_use_item)
			{
				p_use_item = in_use_item;
				flag_use_item = true;
			}
		}
	private:
		bool flag_my_info = false;
		mps_guild_member my_info;
		mps_guild_member* p_my_info = nullptr;
	public:
		bool has_my_info() const
		{
			return flag_my_info;
		}
		mps_guild_member* alloc_my_info()
		{
			flag_my_info = true;
			return &my_info;
		}
		const mps_guild_member* get_my_info() const
		{
			if (true == flag_my_info)
			{
				if (nullptr == p_my_info)
				{
					return &my_info;
				}
				return p_my_info;
			}
			return nullptr;
		}
		void set_my_info(mps_guild_member* in_my_info)
		{
			if (nullptr == p_my_info)
			{
				p_my_info = in_my_info;
				flag_my_info = true;
			}
		}

	public:
		mrpc_guild_create_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_create_sc, tag)
		{
		}
		mrpc_guild_create_sc() : RpcPacket(mpe_rpc_cmd::guild_create_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_guild);
			if (true == flag_guild)
			{
				if (nullptr != p_guild)
					protocol::SerializeType(pBuffer, p_guild);
				else
					protocol::SerializeType(pBuffer, &guild);
			}
			protocol::SerializeType(pBuffer, &flag_use_item);
			if (true == flag_use_item)
			{
				if (nullptr != p_use_item)
					protocol::SerializeType(pBuffer, p_use_item);
				else
					protocol::SerializeType(pBuffer, &use_item);
			}
			protocol::SerializeType(pBuffer, &flag_my_info);
			if (true == flag_my_info)
			{
				if (nullptr != p_my_info)
					protocol::SerializeType(pBuffer, p_my_info);
				else
					protocol::SerializeType(pBuffer, &my_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
