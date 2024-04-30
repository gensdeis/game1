#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_seasonpass_challenge 
	{
	public:
		int32_t tid{};
	public:
		int32_t season_number{};	// 시즌 table id
	public:
		int32_t main_type{};
	public:
		int32_t sub_type{};
	public:
		int32_t count{};
	public:
		mpe_challenge_state state{};
	public:
		int32_t repeat_count{};

	public:
		mps_seasonpass_challenge()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &season_number);
			protocol::SerializeType(pBuffer, &main_type);
			protocol::SerializeType(pBuffer, &sub_type);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &repeat_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
