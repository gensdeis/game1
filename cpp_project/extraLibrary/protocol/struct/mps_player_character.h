#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_player_character 
	{
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		int32_t level{};
	public:
		int32_t id{};
	public:
		int32_t zone_id{};
	public:
		int32_t power{};
	public:
		int32_t lasttime{};	// lastselecttime
	public:
		int32_t equip_0{};	// 룩적용중인아이템0:무기
	public:
		int32_t equip_1{};	// 룩적용중인아이템1:의상
	public:
		int32_t equip_2{};	// 룩적용중인아이템2:투구

	public:
		mps_player_character()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &power);
			protocol::SerializeType(pBuffer, &lasttime);
			protocol::SerializeType(pBuffer, &equip_0);
			protocol::SerializeType(pBuffer, &equip_1);
			protocol::SerializeType(pBuffer, &equip_2);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
