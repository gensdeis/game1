#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_damage_result 
	{
	public:
		int32_t damage{};	// //데미지
	public:
		int32_t result_value{};	// //데미지 계산 후 결과
	public:
		mpe_damage_type damage_type{};	// //데미지 타입
	public:
		std::string log{};	// //로그

	public:
		mps_damage_result()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &damage);
			protocol::SerializeType(pBuffer, &result_value);
			protocol::SerializeEnum(pBuffer, &damage_type);
			protocol::SerializeType(pBuffer, &log);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
