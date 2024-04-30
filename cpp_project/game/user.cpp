#include "stdafx.h"
#include "user.h"
#include <table/tableManager.h>
namespace mir3d
{
	void CUser::Release(void)
	{
//#if _DEBUG
//		SERVER_LOG(eServerLogType::eInfo, "user release :: cuid [" << (nullptr != _character ? _character->GetUid() : 0) << "]";
//#endif

		_session = nullptr;
		_character = nullptr;
		_thread_tag = 0;

		
	}

	void CUser::SetThreadTag(int32_t tag_index)
	{
		//auto tag = tableManager.mapTag.Get(zoneid);
		//if (nullptr != tag)
		//{
		//	_thread_tag = tag->tag;
		//}

		_thread_tag = tag_index;
	}

	void CUser::ForceDisconnect(const char* call_func)
	{
		auto session = GetSession();
		if (nullptr == session)
		{
			return;
		}

		session->ForceDisconnect(call_func);
	}
}	// namespace mir3d