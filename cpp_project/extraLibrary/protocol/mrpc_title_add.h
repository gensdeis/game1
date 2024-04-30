#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_update.h"
#include "struct/mps_title_info.h"
#include "struct/mps_item_update.h"
#include "struct/mps_title_info.h"

namespace mir3d
{
	class mrpc_title_add_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_item_update = false;
		mps_item_update item_update;
		mps_item_update* p_item_update = nullptr;
	public:
		bool has_item_update() const
		{
			return flag_item_update;
		}
		mps_item_update* alloc_item_update()
		{
			flag_item_update = true;
			return &item_update;
		}
		const mps_item_update* get_item_update() const
		{
			if (true == flag_item_update)
			{
				if (nullptr == p_item_update)
				{
					return &item_update;
				}
				return p_item_update;
			}
			return nullptr;
		}
		void set_item_update(mps_item_update* in_item_update)
		{
			if (nullptr == p_item_update)
			{
				p_item_update = in_item_update;
				flag_item_update = true;
			}
		}
	private:
		bool flag_title_info = false;
		mps_title_info title_info;
		mps_title_info* p_title_info = nullptr;
	public:
		bool has_title_info() const
		{
			return flag_title_info;
		}
		mps_title_info* alloc_title_info()
		{
			flag_title_info = true;
			return &title_info;
		}
		const mps_title_info* get_title_info() const
		{
			if (true == flag_title_info)
			{
				if (nullptr == p_title_info)
				{
					return &title_info;
				}
				return p_title_info;
			}
			return nullptr;
		}
		void set_title_info(mps_title_info* in_title_info)
		{
			if (nullptr == p_title_info)
			{
				p_title_info = in_title_info;
				flag_title_info = true;
			}
		}

	public:
		mrpc_title_add_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::title_add_cs, tag)
		{
		}
		mrpc_title_add_cs() : RpcPacket(mpe_rpc_cmd::title_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_item_update);
			if (true == flag_item_update)
			{
				if (nullptr != p_item_update)
					protocol::SerializeType(pBuffer, p_item_update);
				else
					protocol::SerializeType(pBuffer, &item_update);
			}
			protocol::SerializeType(pBuffer, &flag_title_info);
			if (true == flag_title_info)
			{
				if (nullptr != p_title_info)
					protocol::SerializeType(pBuffer, p_title_info);
				else
					protocol::SerializeType(pBuffer, &title_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_title_add_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_item_update = false;
		mps_item_update item_update;
		mps_item_update* p_item_update = nullptr;
	public:
		bool has_item_update() const
		{
			return flag_item_update;
		}
		mps_item_update* alloc_item_update()
		{
			flag_item_update = true;
			return &item_update;
		}
		const mps_item_update* get_item_update() const
		{
			if (true == flag_item_update)
			{
				if (nullptr == p_item_update)
				{
					return &item_update;
				}
				return p_item_update;
			}
			return nullptr;
		}
		void set_item_update(mps_item_update* in_item_update)
		{
			if (nullptr == p_item_update)
			{
				p_item_update = in_item_update;
				flag_item_update = true;
			}
		}
	private:
		bool flag_title_info = false;
		mps_title_info title_info;
		mps_title_info* p_title_info = nullptr;
	public:
		bool has_title_info() const
		{
			return flag_title_info;
		}
		mps_title_info* alloc_title_info()
		{
			flag_title_info = true;
			return &title_info;
		}
		const mps_title_info* get_title_info() const
		{
			if (true == flag_title_info)
			{
				if (nullptr == p_title_info)
				{
					return &title_info;
				}
				return p_title_info;
			}
			return nullptr;
		}
		void set_title_info(mps_title_info* in_title_info)
		{
			if (nullptr == p_title_info)
			{
				p_title_info = in_title_info;
				flag_title_info = true;
			}
		}

	public:
		mrpc_title_add_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::title_add_sc, tag)
		{
		}
		mrpc_title_add_sc() : RpcPacket(mpe_rpc_cmd::title_add_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_item_update);
			if (true == flag_item_update)
			{
				if (nullptr != p_item_update)
					protocol::SerializeType(pBuffer, p_item_update);
				else
					protocol::SerializeType(pBuffer, &item_update);
			}
			protocol::SerializeType(pBuffer, &flag_title_info);
			if (true == flag_title_info)
			{
				if (nullptr != p_title_info)
					protocol::SerializeType(pBuffer, p_title_info);
				else
					protocol::SerializeType(pBuffer, &title_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
