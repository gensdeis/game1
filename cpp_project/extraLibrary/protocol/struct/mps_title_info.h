#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_title_info 
	{
	public:
		int32_t title_id{};
	public:
		std::string title_name{};	// "// 이름이 있는 칭호	"
	public:
		bool equip{};	// // 장착 여부
	public:
		int32_t end_time{};	// 0 : 무제한

	public:
		mps_title_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &title_id);
			protocol::SerializeType(pBuffer, &title_name);
			protocol::SerializeType(pBuffer, &equip);
			protocol::SerializeType(pBuffer, &end_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
