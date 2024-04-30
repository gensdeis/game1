#include "stdafx.h"
#include "action_logger.h"
#include <common/config.h>
#include <../game/gamelogManager.h>

namespace mir3d
{
	bool ActionLogger::_initialized = false;

	void ActionLogger::Initialize(void)
	{
		_initialized = true;
	}

	uint16_t ActionLogger::getCommonLogText(char* stream)
	{
		return (uint16_t)snprintf(stream, ACTION_LOG_TEXT_SIZE, "%lld,%d,%d,%d,0,0,system,0,0,0,0", mir3d::util::mirTime::ActionLogTime(),
			GameConfig::Server_Gid(), GameConfig::Server_Index(), GameConfig::Server_Type());
	}

	uint16_t ActionLogger::getCommonLogText(const int64_t uid, char* stream)
	{
		return (uint16_t)snprintf(stream, ACTION_LOG_TEXT_SIZE, "%lld,%d,%d,%d,%lld,%lld,%s,%d,%d,%d,%d", mir3d::util::mirTime::ActionLogTime(),
			GameConfig::Server_Gid(), GameConfig::Server_Index(), GameConfig::Server_Type(), (int64_t)0, uid, "", 0, 0, 0, 0);
	}

	uint16_t ActionLogger::getCommonLogText(const int64_t uid, const int64_t& owner_auid, const std::string& owner_name, const int32_t& class_type, const int32_t& level, const int32_t& power, const int32_t& condition, char* stream)
	{
		return (uint16_t)snprintf(stream, ACTION_LOG_TEXT_SIZE, "%lld,%d,%d,%d,%lld,%lld,%s,%d,%d,%d,%d", mir3d::util::mirTime::ActionLogTime(),
			GameConfig::Server_Gid(), GameConfig::Server_Index(), GameConfig::Server_Type(), owner_auid, uid, owner_name.c_str(), class_type, level, power, condition);
	}
// #pragma endregion
}