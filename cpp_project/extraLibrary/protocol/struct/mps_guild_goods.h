#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_goods 
	{
	public:
		mpe_guild_goods type{};
	public:
		int32_t update{};
	public:
		int32_t total{};

	public:
		mps_guild_goods()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &update);
			protocol::SerializeType(pBuffer, &total);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
