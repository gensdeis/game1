#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods.h"

namespace mir3d
{
	class mrpc_storage_expand_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		uint16_t type{};
	private:
		bool flag_info = false;
		mps_update_goods info;
		mps_update_goods* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_update_goods* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_update_goods* get_info() const
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
		void set_info(mps_update_goods* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int32_t slot_size{};

	public:
		mrpc_storage_expand_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::storage_expand_cs, tag)
		{
		}
		mrpc_storage_expand_cs() : RpcPacket(mpe_rpc_cmd::storage_expand_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &slot_size);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_storage_expand_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_storage_expand_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::storage_expand_sc, tag)
		{
		}
		mrpc_storage_expand_sc() : RpcPacket(mpe_rpc_cmd::storage_expand_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
