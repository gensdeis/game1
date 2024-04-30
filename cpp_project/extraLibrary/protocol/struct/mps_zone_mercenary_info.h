#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_zone_mercenary_info 
	{
	public:
		int32_t hp{};	// HP
	public:
		int32_t mhp{};	// maxHP
	public:
		uint8_t phase{};	// step hp

	public:
		mps_zone_mercenary_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &hp);
			protocol::SerializeType(pBuffer, &mhp);
			protocol::SerializeType(pBuffer, &phase);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
