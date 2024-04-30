#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_global_ccu_info 
	{
	public:
		int32_t gid{};
	public:
		std::vector<int32_t> ccu{};

	public:
		mrpcs_global_ccu_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &ccu);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
