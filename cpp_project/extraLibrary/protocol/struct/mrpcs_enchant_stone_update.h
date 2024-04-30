#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_enchant_stone_update 
	{
	public:
		int64_t iuid{};
	public:
		int32_t index{};
	public:
		int64_t stone_uid{};

	public:
		mrpcs_enchant_stone_update()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &stone_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
