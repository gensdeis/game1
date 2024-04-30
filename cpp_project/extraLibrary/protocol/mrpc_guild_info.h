#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild.h"
#include "struct/mps_guild_member.h"
#include "struct/mps_guild_member.h"
#include "struct/mps_guild_member.h"

namespace mir3d
{
	class mrpc_guild_info_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};

	public:
		mrpc_guild_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_info_cs, tag)
		{
		}
		mrpc_guild_info_cs() : RpcPacket(mpe_rpc_cmd::guild_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_info_sc : public RpcPacket 
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
	private:
		bool flag_master_info = false;
		mps_guild_member master_info;
		mps_guild_member* p_master_info = nullptr;
	public:
		bool has_master_info() const
		{
			return flag_master_info;
		}
		mps_guild_member* alloc_master_info()
		{
			flag_master_info = true;
			return &master_info;
		}
		const mps_guild_member* get_master_info() const
		{
			if (true == flag_master_info)
			{
				if (nullptr == p_master_info)
				{
					return &master_info;
				}
				return p_master_info;
			}
			return nullptr;
		}
		void set_master_info(mps_guild_member* in_master_info)
		{
			if (nullptr == p_master_info)
			{
				p_master_info = in_master_info;
				flag_master_info = true;
			}
		}
	private:
		bool flag_submaster_info = false;
		mps_guild_member submaster_info;
		mps_guild_member* p_submaster_info = nullptr;
	public:
		bool has_submaster_info() const
		{
			return flag_submaster_info;
		}
		mps_guild_member* alloc_submaster_info()
		{
			flag_submaster_info = true;
			return &submaster_info;
		}
		const mps_guild_member* get_submaster_info() const
		{
			if (true == flag_submaster_info)
			{
				if (nullptr == p_submaster_info)
				{
					return &submaster_info;
				}
				return p_submaster_info;
			}
			return nullptr;
		}
		void set_submaster_info(mps_guild_member* in_submaster_info)
		{
			if (nullptr == p_submaster_info)
			{
				p_submaster_info = in_submaster_info;
				flag_submaster_info = true;
			}
		}

	public:
		mrpc_guild_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_info_sc, tag)
		{
		}
		mrpc_guild_info_sc() : RpcPacket(mpe_rpc_cmd::guild_info_sc)
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
			protocol::SerializeType(pBuffer, &flag_my_info);
			if (true == flag_my_info)
			{
				if (nullptr != p_my_info)
					protocol::SerializeType(pBuffer, p_my_info);
				else
					protocol::SerializeType(pBuffer, &my_info);
			}
			protocol::SerializeType(pBuffer, &flag_master_info);
			if (true == flag_master_info)
			{
				if (nullptr != p_master_info)
					protocol::SerializeType(pBuffer, p_master_info);
				else
					protocol::SerializeType(pBuffer, &master_info);
			}
			protocol::SerializeType(pBuffer, &flag_submaster_info);
			if (true == flag_submaster_info)
			{
				if (nullptr != p_submaster_info)
					protocol::SerializeType(pBuffer, p_submaster_info);
				else
					protocol::SerializeType(pBuffer, &submaster_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
