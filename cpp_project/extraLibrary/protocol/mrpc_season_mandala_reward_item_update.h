#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_season_mandala_reward_item_update_cs : public RpcPacket 	// 시즌 만다라 보상 아이템정보 갱신
	{
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		int32_t table_id{};	// 보상 테이블 아이디
	public:
		int32_t season_id{};	// 시즌 아이디
	private:
		bool flag_item_add = false;
		mps_item_add item_add;	// 보상 아이템 정보
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
		mrpc_season_mandala_reward_item_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::season_mandala_reward_item_update_cs, tag)
		{
		}
		mrpc_season_mandala_reward_item_update_cs() : RpcPacket(mpe_rpc_cmd::season_mandala_reward_item_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &season_id);
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

	class mrpc_season_mandala_reward_item_update_sc : public RpcPacket 	// 시즌 만다라 보상 아이템정보 갱신
	{

	public:
		mrpc_season_mandala_reward_item_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::season_mandala_reward_item_update_sc, tag)
		{
		}
		mrpc_season_mandala_reward_item_update_sc() : RpcPacket(mpe_rpc_cmd::season_mandala_reward_item_update_sc)
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
