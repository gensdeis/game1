#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_global_governance_context 
	{
	public:
		int64_t key{};	// 세션 아이디
	public:
		int64_t auid{};	// 계정 아이디
	public:
		int64_t cuid{};	// 캐릭터 아이디
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
		std::string wallet_address{};
	public:
		int32_t agenda_id{};	// Contract서버에서 관리하는 월드아이디
	public:
		int32_t sector_id{};	// Contract서버에서 관리하는 서버아이디
	public:
		short server_gid{};
	public:
		int32_t server_index{};
	public:
		mrpce_server_type server_type{};
	public:
		uint8_t character_tid{};
	public:
		short character_level{};
	public:
		int32_t character_power{};
	public:
		std::string username{};
	public:
		std::string nickname{};
	public:
		std::string guildname{};
	public:
		mpe_error contract_error_code{};
	public:
		mpe_global_party_governance_rank_type type{};
	public:
		uint8_t rank_page{};
	public:
		std::vector<uint8_t> guildmark{};	// 길드마크
	public:
		std::string min_staking_amount_realtime{};	// 실시간 최소 스테이킹 수치
	public:
		mrpce_global_governance_command_type command_type{};
	public:
		int32_t unstaking_time{};	// 언스테이킹 시간
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mrpcs_global_governance_context()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &amount);
			protocol::SerializeType(pBuffer, &contract);
			protocol::SerializeType(pBuffer, &user);
			protocol::SerializeType(pBuffer, &signature);
			protocol::SerializeType(pBuffer, &nonce);
			protocol::SerializeType(pBuffer, &column);
			protocol::SerializeType(pBuffer, &wallet_address);
			protocol::SerializeType(pBuffer, &agenda_id);
			protocol::SerializeType(pBuffer, &sector_id);
			protocol::SerializeType(pBuffer, &server_gid);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &character_tid);
			protocol::SerializeType(pBuffer, &character_level);
			protocol::SerializeType(pBuffer, &character_power);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &guildname);
			protocol::SerializeEnum(pBuffer, &contract_error_code);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &rank_page);
			protocol::SerializeType(pBuffer, &guildmark);
			protocol::SerializeType(pBuffer, &min_staking_amount_realtime);
			protocol::SerializeEnum(pBuffer, &command_type);
			protocol::SerializeType(pBuffer, &unstaking_time);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
