#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_db_buff.h"

namespace mir3d
{
	class mrpc_buff_insert_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_buff = false;
		mps_db_buff buff;
		mps_db_buff* p_buff = nullptr;
	public:
		bool has_buff() const
		{
			return flag_buff;
		}
		mps_db_buff* alloc_buff()
		{
			flag_buff = true;
			return &buff;
		}
		const mps_db_buff* get_buff() const
		{
			if (true == flag_buff)
			{
				if (nullptr == p_buff)
				{
					return &buff;
				}
				return p_buff;
			}
			return nullptr;
		}
		void set_buff(mps_db_buff* in_buff)
		{
			if (nullptr == p_buff)
			{
				p_buff = in_buff;
				flag_buff = true;
			}
		}

	public:
		mrpc_buff_insert_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::buff_insert_cs, tag)
		{
		}
		mrpc_buff_insert_cs() : RpcPacket(mpe_rpc_cmd::buff_insert_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_buff);
			if (true == flag_buff)
			{
				if (nullptr != p_buff)
					protocol::SerializeType(pBuffer, p_buff);
				else
					protocol::SerializeType(pBuffer, &buff);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_buff_insert_sc : public RpcPacket 
	{

	public:
		mrpc_buff_insert_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::buff_insert_sc, tag)
		{
		}
		mrpc_buff_insert_sc() : RpcPacket(mpe_rpc_cmd::buff_insert_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
