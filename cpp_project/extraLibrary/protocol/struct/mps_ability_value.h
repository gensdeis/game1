#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_ability_value 
	{
	public:
		int32_t ability_list_id{};	// //table ABILITY_LIST enum
	public:
		int32_t value{};	// //버프/디버프 속성 값
	public:
		bool ability_type{};	// //버프 : true 디버프 : false
	public:
		int32_t result_value{};	// //버프/디버프 결과 값
	public:
		mpe_damage_type damage_type{};	// //데미지 타입

	public:
		mps_ability_value()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &ability_list_id);
			protocol::SerializeType(pBuffer, &value);
			protocol::SerializeType(pBuffer, &ability_type);
			protocol::SerializeType(pBuffer, &result_value);
			protocol::SerializeEnum(pBuffer, &damage_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
