#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item.h"

namespace mir3d
{
	class mrpc_item_enchant_option_select_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		mpe_item_reinforce_position pos{};
	private:
		bool flag_info = false;
		mps_item info;	// 수정 -> mps_item_add
		mps_item* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item* get_info() const
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
		void set_info(mps_item* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_item_enchant_option_select_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::item_enchant_option_select_cs, tag)
		{
		}
		mrpc_item_enchant_option_select_cs() : RpcPacket(mpe_rpc_cmd::item_enchant_option_select_cs)
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
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_item_enchant_option_select_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_item_enchant_option_select_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::item_enchant_option_select_sc, tag)
		{
		}
		mrpc_item_enchant_option_select_sc() : RpcPacket(mpe_rpc_cmd::item_enchant_option_select_sc)
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
