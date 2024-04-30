#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_castle_town_info_detail 	// 장원 상세정보
	{
	public:
		bool home{};	// 회관 고용 여부
	public:
		int32_t home_lv{};
	public:
		bool dungeon{};	// 던전 고용 여부
	public:
		int32_t dungeon_lv{};
	public:
		bool storage{};	// 창고 고용 여부
	public:
		int32_t storage_lv{};
	public:
		bool training_center{};	// 훈련소 고용 여부
	public:
		int32_t training_center_lv{};
	public:
		bool quest_office{};	// 연락소 고용 여부
	public:
		int32_t quest_office_lv{};
	public:
		bool blacksmith{};	// 대장간 고용 여부
	public:
		int32_t blacksmith_lv{};
	public:
		bool alchemy{};	// 제작소 고용 여부
	public:
		int32_t alchemy_lv{};
	public:
		bool cooking{};	// 푸줏간 고용 여부
	public:
		int32_t cooking_lv{};
	public:
		bool arsenal{};	// 병기창 고용 여부
	public:
		int32_t arsenal_lv{};
	public:
		bool orchard{};	// 과수원 고용 여부
	public:
		int32_t orchard_lv{};
	public:
		bool grove{};	// 밭 고용 여부
	public:
		int32_t grove_lv{};
	public:
		bool farm{};	// 목장 고용 여부
	public:
		int32_t farm_lv{};

	public:
		mps_castle_town_info_detail()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &home);
			protocol::SerializeType(pBuffer, &home_lv);
			protocol::SerializeType(pBuffer, &dungeon);
			protocol::SerializeType(pBuffer, &dungeon_lv);
			protocol::SerializeType(pBuffer, &storage);
			protocol::SerializeType(pBuffer, &storage_lv);
			protocol::SerializeType(pBuffer, &training_center);
			protocol::SerializeType(pBuffer, &training_center_lv);
			protocol::SerializeType(pBuffer, &quest_office);
			protocol::SerializeType(pBuffer, &quest_office_lv);
			protocol::SerializeType(pBuffer, &blacksmith);
			protocol::SerializeType(pBuffer, &blacksmith_lv);
			protocol::SerializeType(pBuffer, &alchemy);
			protocol::SerializeType(pBuffer, &alchemy_lv);
			protocol::SerializeType(pBuffer, &cooking);
			protocol::SerializeType(pBuffer, &cooking_lv);
			protocol::SerializeType(pBuffer, &arsenal);
			protocol::SerializeType(pBuffer, &arsenal_lv);
			protocol::SerializeType(pBuffer, &orchard);
			protocol::SerializeType(pBuffer, &orchard_lv);
			protocol::SerializeType(pBuffer, &grove);
			protocol::SerializeType(pBuffer, &grove_lv);
			protocol::SerializeType(pBuffer, &farm);
			protocol::SerializeType(pBuffer, &farm_lv);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
