#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_restore_compose_cs : public RpcPacket 	// 합성 실패 복구권 요청
	{
	public:
		int64_t ruid{};	// 복구할 정보
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_item_add = false;
		mps_item_add item_add;	// 갱신된 아이템 및 굿즈 정보
		mps_item_add* p_item_add = nullptr;
	public:
		bool has_item_add() const
		{
			return flag_item_add;
		}
		mps_item_add* alloc_item_add()
		{
			flag_item_add = true;
			return &item_add;
		}
		const mps_item_add* get_item_add() const
		{
			if (true == flag_item_add)
			{
				if (nullptr == p_item_add)
				{
					return &item_add;
				}
				return p_item_add;
			}
			return nullptr;
		}
		void set_item_add(mps_item_add* in_item_add)
		{
			if (nullptr == p_item_add)
			{
				p_item_add = in_item_add;
				flag_item_add = true;
			}
		}

	public:
		mrpc_restore_compose_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::restore_compose_cs, tag)
		{
		}
		mrpc_restore_compose_cs() : RpcPacket(mpe_rpc_cmd::restore_compose_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ruid);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_restore_compose_sc : public RpcPacket 	// 합성 실패 복구권 요청
	{
	public:
		int64_t key{};

	public:
		mrpc_restore_compose_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::restore_compose_sc, tag)
		{
		}
		mrpc_restore_compose_sc() : RpcPacket(mpe_rpc_cmd::restore_compose_sc)
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
