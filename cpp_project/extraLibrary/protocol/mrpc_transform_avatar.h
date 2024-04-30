#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mrpc_transform_avatar_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t avatar_id{};
	private:
		bool flag_use_item = false;
		mps_item_count_update use_item;
		mps_item_count_update* p_use_item = nullptr;
	public:
		bool has_use_item() const
		{
			return flag_use_item;
		}
		mps_item_count_update* alloc_use_item()
		{
			flag_use_item = true;
			return &use_item;
		}
		const mps_item_count_update* get_use_item() const
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
		void set_use_item(mps_item_count_update* in_use_item)
		{
			if (nullptr == p_use_item)
			{
				p_use_item = in_use_item;
				flag_use_item = true;
			}
		}
	public:
		int32_t expire_time{};

	public:
		mrpc_transform_avatar_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::transform_avatar_cs, tag)
		{
		}
		mrpc_transform_avatar_cs() : RpcPacket(mpe_rpc_cmd::transform_avatar_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &avatar_id);
			protocol::SerializeType(pBuffer, &flag_use_item);
			if (true == flag_use_item)
			{
				if (nullptr != p_use_item)
					protocol::SerializeType(pBuffer, p_use_item);
				else
					protocol::SerializeType(pBuffer, &use_item);
			}
			protocol::SerializeType(pBuffer, &expire_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_transform_avatar_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_transform_avatar_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::transform_avatar_sc, tag)
		{
		}
		mrpc_transform_avatar_sc() : RpcPacket(mpe_rpc_cmd::transform_avatar_sc)
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
