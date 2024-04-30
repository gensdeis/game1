#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_profesion.h"

namespace mir3d
{
	class mrpc_item_enchant_option_make_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		mpe_item_reinforce_position pos{};
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
	public:
		int32_t make_count{};
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

	public:
		mrpc_item_enchant_option_make_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::item_enchant_option_make_cs, tag)
		{
		}
		mrpc_item_enchant_option_make_cs() : RpcPacket(mpe_rpc_cmd::item_enchant_option_make_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &make_count);
			protocol::SerializeType(pBuffer, &flag_profesion_info);
			if (true == flag_profesion_info)
			{
				if (nullptr != p_profesion_info)
					protocol::SerializeType(pBuffer, p_profesion_info);
				else
					protocol::SerializeType(pBuffer, &profesion_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_item_enchant_option_make_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_item_enchant_option_make_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::item_enchant_option_make_sc, tag)
		{
		}
		mrpc_item_enchant_option_make_sc() : RpcPacket(mpe_rpc_cmd::item_enchant_option_make_sc)
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
