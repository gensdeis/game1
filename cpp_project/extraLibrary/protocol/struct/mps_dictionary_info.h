#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_dictionary_info 
	{
	public:
		int32_t tid{};
	public:
		mpe_dictionary_type type{};
	public:
		int32_t level{};
	public:
		int32_t category_id{};
	public:
		int32_t value{};
	public:
		int64_t end_date{};
	public:
		bool state{};	// "완료 상태( 완료 true, 진행중 false )"

	public:
		mps_dictionary_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &category_id);
			protocol::SerializeType(pBuffer, &value);
			protocol::SerializeType(pBuffer, &end_date);
			protocol::SerializeType(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
