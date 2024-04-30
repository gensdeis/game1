#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_lord_bless_buff.h"
#include "struct/mps_lord_bless_buff.h"

namespace mir3d
{
	class mrpc_lord_bless_buff_cs : public RpcPacket 
	{
	public:
		int32_t castle_id{};
	private:
		bool flag_buff_use = false;
		mps_lord_bless_buff buff_use;
		mps_lord_bless_buff* p_buff_use = nullptr;
	public:
		bool has_buff_use() const
		{
			return flag_buff_use;
		}
		mps_lord_bless_buff* alloc_buff_use()
		{
			flag_buff_use = true;
			return &buff_use;
		}
		const mps_lord_bless_buff* get_buff_use() const
		{
			if (true == flag_buff_use)
			{
				if (nullptr == p_buff_use)
				{
					return &buff_use;
				}
				return p_buff_use;
			}
			return nullptr;
		}
		void set_buff_use(mps_lord_bless_buff* in_buff_use)
		{
			if (nullptr == p_buff_use)
			{
				p_buff_use = in_buff_use;
				flag_buff_use = true;
			}
		}
	public:
		int32_t use_bless_point{};

	public:
		mrpc_lord_bless_buff_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::lord_bless_buff_cs, tag)
		{
		}
		mrpc_lord_bless_buff_cs() : RpcPacket(mpe_rpc_cmd::lord_bless_buff_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &castle_id);
			protocol::SerializeType(pBuffer, &flag_buff_use);
			if (true == flag_buff_use)
			{
				if (nullptr != p_buff_use)
					protocol::SerializeType(pBuffer, p_buff_use);
				else
					protocol::SerializeType(pBuffer, &buff_use);
			}
			protocol::SerializeType(pBuffer, &use_bless_point);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_lord_bless_buff_sc : public RpcPacket 
	{
	public:
		int32_t castle_id{};
	private:
		bool flag_buff_use = false;
		mps_lord_bless_buff buff_use;
		mps_lord_bless_buff* p_buff_use = nullptr;
	public:
		bool has_buff_use() const
		{
			return flag_buff_use;
		}
		mps_lord_bless_buff* alloc_buff_use()
		{
			flag_buff_use = true;
			return &buff_use;
		}
		const mps_lord_bless_buff* get_buff_use() const
		{
			if (true == flag_buff_use)
			{
				if (nullptr == p_buff_use)
				{
					return &buff_use;
				}
				return p_buff_use;
			}
			return nullptr;
		}
		void set_buff_use(mps_lord_bless_buff* in_buff_use)
		{
			if (nullptr == p_buff_use)
			{
				p_buff_use = in_buff_use;
				flag_buff_use = true;
			}
		}
	public:
		int32_t total_bless_point{};

	public:
		mrpc_lord_bless_buff_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::lord_bless_buff_sc, tag)
		{
		}
		mrpc_lord_bless_buff_sc() : RpcPacket(mpe_rpc_cmd::lord_bless_buff_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &castle_id);
			protocol::SerializeType(pBuffer, &flag_buff_use);
			if (true == flag_buff_use)
			{
				if (nullptr != p_buff_use)
					protocol::SerializeType(pBuffer, p_buff_use);
				else
					protocol::SerializeType(pBuffer, &buff_use);
			}
			protocol::SerializeType(pBuffer, &total_bless_point);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
