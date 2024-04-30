#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_update_exp 
	{
	public:
		int64_t update{};	// 변경된경험치수치
	public:
		int64_t total{};	// //최종경험치수치
	public:
		int64_t expert_update{};	// //변경된전직경험치수치
	public:
		int64_t expert_total{};	// //최종전직경험치수치

	public:
		mps_update_exp()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &update);
			protocol::SerializeType(pBuffer, &total);
			protocol::SerializeType(pBuffer, &expert_update);
			protocol::SerializeType(pBuffer, &expert_total);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
