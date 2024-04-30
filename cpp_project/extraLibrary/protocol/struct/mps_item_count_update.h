#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_item_count_update 
	{
	public:
		int64_t iuid{};
	public:
		int32_t update{};	// //변경된수치
	public:
		int32_t total{};	// //최종수치
	public:
		mpe_item_delete_cause delete_cause{};	// //0 이상이면 복구 대상(서버만사용 디비저장용)

	public:
		mps_item_count_update()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &update);
			protocol::SerializeType(pBuffer, &total);
			protocol::SerializeEnum(pBuffer, &delete_cause);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
