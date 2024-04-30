#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_season_mandala_reward_update_cs : public RpcPacket 	// 시즌 만다라 보상정보 갱신
	{
	public:
		int64_t key{};	// 세션 아이디
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		int32_t table_id{};	// 보상 테이블 아이디
	public:
		int32_t season_id{};	// 시즌 아이디
	public:
		mpe_season_mandala_reward_receive_type receive_type{};	// 수령 타입(0:수령불가1:수령가능2:수령완료)
	public:
		int32_t receive_date{};	// 수령받은 날짜(utc+0)

	public:
		mrpc_season_mandala_reward_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::season_mandala_reward_update_cs, tag)
		{
		}
		mrpc_season_mandala_reward_update_cs() : RpcPacket(mpe_rpc_cmd::season_mandala_reward_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &season_id);
			protocol::SerializeEnum(pBuffer, &receive_type);
			protocol::SerializeType(pBuffer, &receive_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_season_mandala_reward_update_sc : public RpcPacket 	// 시즌 만다라 보상정보 갱신
	{
	public:
		int64_t key{};	// 세션 아이디
	public:
		int32_t table_id{};	// 보상 테이블 아이디
	public:
		int32_t season_id{};	// 시즌 아이디
	public:
		mpe_season_mandala_reward_receive_type receive_type{};	// 수령 타입(0:수령불가1:수령가능2:수령완료)
	public:
		int32_t receive_date{};	// 수령받은 날짜(utc+0)

	public:
		mrpc_season_mandala_reward_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::season_mandala_reward_update_sc, tag)
		{
		}
		mrpc_season_mandala_reward_update_sc() : RpcPacket(mpe_rpc_cmd::season_mandala_reward_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &season_id);
			protocol::SerializeEnum(pBuffer, &receive_type);
			protocol::SerializeType(pBuffer, &receive_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
