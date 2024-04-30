#pragma once

#include <table/header/_common_enum.h>

namespace mir3d
{
	namespace table
	{
		class Item_EquipStone_MaterialPoint_Table; 
	}

	class CMail;
	class CObject;
	class CItem;

	class ActionLogger
	{
	public:
		static void Initialize(void);

		static uint16_t getCommonLogText(char* stream);
		static uint16_t getCommonLogText(CObject* const obj, char* stream);
		static uint16_t getCommonLogText(const int64_t uid, char* stream);
		static uint16_t getCommonLogText(const int64_t uid, const int64_t& owner_auid, const std::string& owner_name, const int32_t& class_type, const int32_t& level, const int32_t& power, const int32_t& condition, char* stream);

		static void GameLogin(CObject* character, const int32_t& zone_id, const mpe_os_type& os_type, const std::string& ip, const int32_t& type);
		static void GameLogout(CObject* character, const int32_t& zone_id, const mpe_os_type& os_type, const std::string& ip);

	private:
		static bool _initialized;
	};
}
