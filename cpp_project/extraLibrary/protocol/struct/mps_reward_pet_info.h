#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_reward_pet_info 	// 펫정보
	{
	public:
		int32_t tid{};
	public:
		uint16_t level{};
	public:
		int32_t exp{};
	public:
		std::vector<uint16_t> pos{};	// 팀별 위치
	public:
		uint16_t satiety{};	// 포만감
	public:
		int32_t keep_value{};	// 추가적으로 획득한 펫 숫자
	public:
		int64_t end_time{};	// 기간제 일 경우 0보다 큰값
	public:
		bool isNew{};	// "true:신규, false:기존"
	public:
		bool upgrade{};	// true : 등급업 / false : 동일등급
	public:
		int32_t add_count{};	// 추가로 획득한 펫 개수

	public:
		mps_reward_pet_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &exp);
			protocol::SerializeType(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &satiety);
			protocol::SerializeType(pBuffer, &keep_value);
			protocol::SerializeType(pBuffer, &end_time);
			protocol::SerializeType(pBuffer, &isNew);
			protocol::SerializeType(pBuffer, &upgrade);
			protocol::SerializeType(pBuffer, &add_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
