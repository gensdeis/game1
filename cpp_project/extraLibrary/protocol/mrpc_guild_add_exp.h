#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_guild_add_exp_cs : public RpcPacket 	// // 문파 경험치 증가
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		mrpce_guild_add_exp_type type{};
	private:
		bool flag_use_item = false;
		mps_item use_item;
		mps_item* p_use_item = nullptr;
	public:
		bool has_use_item() const
		{
			return flag_use_item;
		}
		mps_item* alloc_use_item()
		{
			flag_use_item = true;
			return &use_item;
		}
		const mps_item* get_use_item() const
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
		void set_use_item(mps_item* in_use_item)
		{
			if (nullptr == p_use_item)
			{
				p_use_item = in_use_item;
				flag_use_item = true;
			}
		}
	public:
		int32_t reward_exp{};

	public:
		mrpc_guild_add_exp_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_add_exp_cs, tag)
		{
		}
		mrpc_guild_add_exp_cs() : RpcPacket(mpe_rpc_cmd::guild_add_exp_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &flag_use_item);
			if (true == flag_use_item)
			{
				if (nullptr != p_use_item)
					protocol::SerializeType(pBuffer, p_use_item);
				else
					protocol::SerializeType(pBuffer, &use_item);
			}
			protocol::SerializeType(pBuffer, &reward_exp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_add_exp_sc : public RpcPacket 	// // 문파 경험치 증가
	{
	public:
		int64_t cuid{};	// // 아이템 사용한 유저 id
	public:
		int32_t level{};	// // 문파 레벨
	public:
		int32_t exp{};	// // 문파 경험치
	public:
		int32_t max_member_count{};	// // 최대 문파 인원수
	public:
		int32_t max_elder_count{};	// // 최대 장로 인원수
	public:
		int32_t guild_gold{};	// // 문파 금전
	public:
		int32_t add_contribution_point{};	// // 얻은 공헌도
	public:
		int32_t contribution_weekly_point{};	// // 주간 공헌도
	public:
		int32_t contribution_accumulated_point{};	// // 누적 공헌도
	private:
		bool flag_use_item = false;
		mps_item_add use_item;	// // 사용된 공헌도 item정보
		mps_item_add* p_use_item = nullptr;
	public:
		bool has_use_item() const
		{
			return flag_use_item;
		}
		mps_item_add* alloc_use_item()
		{
			flag_use_item = true;
			return &use_item;
		}
		const mps_item_add* get_use_item() const
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
		void set_use_item(mps_item_add* in_use_item)
		{
			if (nullptr == p_use_item)
			{
				p_use_item = in_use_item;
				flag_use_item = true;
			}
		}

	public:
		mrpc_guild_add_exp_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_add_exp_sc, tag)
		{
		}
		mrpc_guild_add_exp_sc() : RpcPacket(mpe_rpc_cmd::guild_add_exp_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &exp);
			protocol::SerializeType(pBuffer, &max_member_count);
			protocol::SerializeType(pBuffer, &max_elder_count);
			protocol::SerializeType(pBuffer, &guild_gold);
			protocol::SerializeType(pBuffer, &add_contribution_point);
			protocol::SerializeType(pBuffer, &contribution_weekly_point);
			protocol::SerializeType(pBuffer, &contribution_accumulated_point);
			protocol::SerializeType(pBuffer, &flag_use_item);
			if (true == flag_use_item)
			{
				if (nullptr != p_use_item)
					protocol::SerializeType(pBuffer, p_use_item);
				else
					protocol::SerializeType(pBuffer, &use_item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
