#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_option_update.h"
#include "struct/mps_restore_item.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_paid_acc_reinforce_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_item_option_update> list_item_option{};	// "옵션 목록"
	public:
		std::vector<mps_restore_item> list_restore_info{};	// "아이템 복구 정보 목록"
	private:
		bool flag_info = false;
		mps_item_add info;	// "강화석 차감, 파괴아이템 제거 정보"
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
		mrpc_paid_acc_reinforce_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::paid_acc_reinforce_cs, tag)
		{
		}
		mrpc_paid_acc_reinforce_cs() : RpcPacket(mpe_rpc_cmd::paid_acc_reinforce_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &list_item_option);
			protocol::SerializeType(pBuffer, &list_restore_info);
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

	class mrpc_paid_acc_reinforce_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_paid_acc_reinforce_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::paid_acc_reinforce_sc, tag)
		{
		}
		mrpc_paid_acc_reinforce_sc() : RpcPacket(mpe_rpc_cmd::paid_acc_reinforce_sc)
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
