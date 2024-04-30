#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_ai_setup_config 
	{
	public:
		std::vector<int32_t> list_ai_config{};
	public:
		int32_t hp_potion_quantity{};
	public:
		int32_t mp_potion_quantity{};
	public:
		int32_t pickup_item_grade{};
	public:
		int32_t town_return_count{};
	public:
		float potion_use_hp_ratio{};
	public:
		float potion_use_mp_ratio{};

	public:
		mps_ai_setup_config()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list_ai_config);
			protocol::SerializeType(pBuffer, &hp_potion_quantity);
			protocol::SerializeType(pBuffer, &mp_potion_quantity);
			protocol::SerializeType(pBuffer, &pickup_item_grade);
			protocol::SerializeType(pBuffer, &town_return_count);
			protocol::SerializeType(pBuffer, &potion_use_hp_ratio);
			protocol::SerializeType(pBuffer, &potion_use_mp_ratio);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
