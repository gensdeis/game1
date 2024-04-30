#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_dual_long 
	{
	public:
		int64_t uid1{};
	public:
		int64_t uid2{};

	public:
		mrpcs_dual_long()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &uid1);
			protocol::SerializeType(pBuffer, &uid2);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
