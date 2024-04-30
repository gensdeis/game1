#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_option_update.h"
#include "struct/mps_item_add.h"
#include "struct/mps_profesion.h"
#include "struct/mps_restore_item.h"

namespace mir3d
{
	class mrpc_item_acc_reinforce_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_item_option = false;
		mps_item_option_update item_option;
		mps_item_option_update* p_item_option = nullptr;
	public:
		bool has_item_option() const
		{
			return flag_item_option;
		}
		mps_item_option_update* alloc_item_option()
		{
			flag_item_option = true;
			return &item_option;
		}
		const mps_item_option_update* get_item_option() const
		{
			if (true == flag_item_option)
			{
				if (nullptr == p_item_option)
				{
					return &item_option;
				}
				return p_item_option;
			}
			return nullptr;
		}
		void set_item_option(mps_item_option_update* in_item_option)
		{
			if (nullptr == p_item_option)
			{
				p_item_option = in_item_option;
				flag_item_option = true;
			}
		}
	private:
		bool flag_info = false;
		mps_item_add info;
		mps_item_add* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_add* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_add* get_info() const
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
		void set_info(mps_item_add* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	private:
		bool flag_profesion_info = false;
		mps_profesion profesion_info;
		mps_profesion* p_profesion_info = nullptr;
	public:
		bool has_profesion_info() const
		{
			return flag_profesion_info;
		}
		mps_profesion* alloc_profesion_info()
		{
			flag_profesion_info = true;
			return &profesion_info;
		}
		const mps_profesion* get_profesion_info() const
		{
			if (true == flag_profesion_info)
			{
				if (nullptr == p_profesion_info)
				{
					return &profesion_info;
				}
				return p_profesion_info;
			}
			return nullptr;
		}
		void set_profesion_info(mps_profesion* in_profesion_info)
		{
			if (nullptr == p_profesion_info)
			{
				p_profesion_info = in_profesion_info;
				flag_profesion_info = true;
			}
		}
	private:
		bool flag_restore_info = false;
		mps_restore_item restore_info;
		mps_restore_item* p_restore_info = nullptr;
	public:
		bool has_restore_info() const
		{
			return flag_restore_info;
		}
		mps_restore_item* alloc_restore_info()
		{
			flag_restore_info = true;
			return &restore_info;
		}
		const mps_restore_item* get_restore_info() const
		{
			if (true == flag_restore_info)
			{
				if (nullptr == p_restore_info)
				{
					return &restore_info;
				}
				return p_restore_info;
			}
			return nullptr;
		}
		void set_restore_info(mps_restore_item* in_restore_info)
		{
			if (nullptr == p_restore_info)
			{
				p_restore_info = in_restore_info;
				flag_restore_info = true;
			}
		}

	public:
		mrpc_item_acc_reinforce_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::item_acc_reinforce_cs, tag)
		{
		}
		mrpc_item_acc_reinforce_cs() : RpcPacket(mpe_rpc_cmd::item_acc_reinforce_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_item_option);
			if (true == flag_item_option)
			{
				if (nullptr != p_item_option)
					protocol::SerializeType(pBuffer, p_item_option);
				else
					protocol::SerializeType(pBuffer, &item_option);
			}
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_profesion_info);
			if (true == flag_profesion_info)
			{
				if (nullptr != p_profesion_info)
					protocol::SerializeType(pBuffer, p_profesion_info);
				else
					protocol::SerializeType(pBuffer, &profesion_info);
			}
			protocol::SerializeType(pBuffer, &flag_restore_info);
			if (true == flag_restore_info)
			{
				if (nullptr != p_restore_info)
					protocol::SerializeType(pBuffer, p_restore_info);
				else
					protocol::SerializeType(pBuffer, &restore_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_item_acc_reinforce_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_item_acc_reinforce_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::item_acc_reinforce_sc, tag)
		{
		}
		mrpc_item_acc_reinforce_sc() : RpcPacket(mpe_rpc_cmd::item_acc_reinforce_sc)
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
