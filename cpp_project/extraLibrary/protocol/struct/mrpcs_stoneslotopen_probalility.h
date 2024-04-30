#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_stoneslotopen_probalility 
	{
	public:
		uint16_t prob{};
	public:
		bool open{};

	public:
		mrpcs_stoneslotopen_probalility()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &prob);
			protocol::SerializeType(pBuffer, &open);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
