#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_enchant_stone_update_pos 
	{
	public:
		int64_t iuid{};	// 용령석 iuid
	public:
		int32_t pos{};	// 변경 위치

	public:
		mrpcs_enchant_stone_update_pos()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
