#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_goods_info 
	{
	public:
		mpe_guild_goods pos{};
	public:
		int32_t value{};

	public:
		mps_guild_goods_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
