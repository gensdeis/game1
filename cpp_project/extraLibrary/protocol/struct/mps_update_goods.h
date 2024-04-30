#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_update_goods 
	{
	public:
		mpe_good_pos pos{};	// //재화(enummps_good_pos)
	public:
		int32_t update{};	// //변경된수치
	public:
		int32_t total{};	// //최종수치

	public:
		mps_update_goods()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &update);
			protocol::SerializeType(pBuffer, &total);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
