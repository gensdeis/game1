#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_boss_governance_server_info_total 
	{
	public:
		int32_t gid{};
	public:
		std::string total{};
	public:
		uint8_t rank{};

	public:
		mps_boss_governance_server_info_total()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &total);
			protocol::SerializeType(pBuffer, &rank);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
