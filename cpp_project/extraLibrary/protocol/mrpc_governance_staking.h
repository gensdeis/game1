#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_governance_staking_cs : public RpcPacket 	// 보스거버넌스 스테이킹
	{
	public:
		int64_t auid{};	// 계정 아이디
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		int64_t key{};	// 세션 아이디
	public:
		std::string amount{};	// 스테이킹량
	public:
		std::string contract{};	// contract address 값
	public:
		std::string user{};	// 유저 wallet id
	public:
		std::string signature{};	// 유저 사인값
	public:
		std::string nonce{};	// 컨트랙트 서버에서 조회한 nonce 값
	public:
		std::string column{};	// 액션에 대한 bytes32 값
	public:
		int32_t agenda_id{};	// Contract서버에서 관리하는 월드아이디
	public:
		int32_t sector_id{};	// Contract서버에서 관리하는 서버아이디
	public:
		mpe_governance_contents_type contents_type{};	// 거버넌스 콘텐츠 타입(0:없음 1:보스 2:비곡점령전 3:공성전 4:파티)
	public:
		int32_t server_gid{};
	public:
		int32_t server_index{};
	public:
		mrpce_server_type server_type{};
	public:
		uint8_t character_tid{};
	public:
		int32_t character_level{};
	public:
		int32_t character_power{};
	public:
		std::string nickname{};
	public:
		std::string wallet_address{};

	public:
		mrpc_governance_staking_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::governance_staking_cs, tag)
		{
		}
		mrpc_governance_staking_cs() : RpcPacket(mpe_rpc_cmd::governance_staking_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &amount);
			protocol::SerializeType(pBuffer, &contract);
			protocol::SerializeType(pBuffer, &user);
			protocol::SerializeType(pBuffer, &signature);
			protocol::SerializeType(pBuffer, &nonce);
			protocol::SerializeType(pBuffer, &column);
			protocol::SerializeType(pBuffer, &agenda_id);
			protocol::SerializeType(pBuffer, &sector_id);
			protocol::SerializeEnum(pBuffer, &contents_type);
			protocol::SerializeType(pBuffer, &server_gid);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &character_tid);
			protocol::SerializeType(pBuffer, &character_level);
			protocol::SerializeType(pBuffer, &character_power);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &wallet_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_governance_staking_sc : public RpcPacket 	// 보스거버넌스 스테이킹
	{
	public:
		int64_t auid{};	// 계정 아이디
	public:
		int64_t key{};	// 세션 아이디
	public:
		int32_t gid{};	// 서버 아이디
	public:
		std::string amount{};	// 스테이킹량
	public:
		mpe_governance_contents_type contents_type{};	// 거버넌스 콘텐츠 타입(0:없음 1:보스 2:비곡점령전 3:공성전 4:파티)
	public:
		mpe_error result{};	// 결과

	public:
		mrpc_governance_staking_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::governance_staking_sc, tag)
		{
		}
		mrpc_governance_staking_sc() : RpcPacket(mpe_rpc_cmd::governance_staking_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &amount);
			protocol::SerializeEnum(pBuffer, &contents_type);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
