#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_boss_governance_deposit_withdraw_history 
	{
	public:
		mpe_coin_staking_type type{};
	public:
		int32_t gid{};
	public:
		std::string amount{};
	public:
		std::string logdate{};

	public:
		mps_boss_governance_deposit_withdraw_history()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &amount);
			protocol::SerializeType(pBuffer, &logdate);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
