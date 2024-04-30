#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_party_base 
	{
	public:
		int64_t puid{};
	public:
		int64_t owner_uid{};
	public:
		int32_t category{};
	public:
		int32_t need_level_min{};
	public:
		int32_t need_level_max{};
	public:
		mpe_party_loot loot{};
	public:
		mpe_party_join join{};
	public:
		std::string party_name{};
	public:
		uint8_t auto_start{};	// "자동 시작 여부(0 : off, 1: on)"
	public:
		bool is_public{};	// "공개파티여부."
	public:
		int32_t governance_rank{};	// 파티 거버넌스 랭킹

	public:
		mps_party_base()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &owner_uid);
			protocol::SerializeType(pBuffer, &category);
			protocol::SerializeType(pBuffer, &need_level_min);
			protocol::SerializeType(pBuffer, &need_level_max);
			protocol::SerializeEnum(pBuffer, &loot);
			protocol::SerializeEnum(pBuffer, &join);
			protocol::SerializeType(pBuffer, &party_name);
			protocol::SerializeType(pBuffer, &auto_start);
			protocol::SerializeType(pBuffer, &is_public);
			protocol::SerializeType(pBuffer, &governance_rank);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
