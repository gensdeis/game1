#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_lord_statue_info 
	{
	public:
		mpe_siege_castle_type castle_type{};
	public:
		int32_t tid{};
	public:
		int32_t customizing_data{};
	public:
		int32_t equip_weapon{};
	public:
		int32_t equip_armor{};
	public:
		int32_t equip_helmet{};
	public:
		int32_t reflection_id{};

	public:
		mps_lord_statue_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &customizing_data);
			protocol::SerializeType(pBuffer, &equip_weapon);
			protocol::SerializeType(pBuffer, &equip_armor);
			protocol::SerializeType(pBuffer, &equip_helmet);
			protocol::SerializeType(pBuffer, &reflection_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
