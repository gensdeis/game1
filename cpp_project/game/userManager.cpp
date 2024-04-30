#include "stdafx.h"
#include "userManager.h"
#include "user.h"
//#include <network/session.h>

namespace mir3d
{
	bool CUserManager::Initialize (int32_t defaultSize, int32_t createSize)
	{
		std::string name = "userManager";
		_pool = new CMemPool<CUser>(defaultSize, createSize, name, OnMempoolAllocLogger);

		return true;
	}

	void CUserManager::CreateUser(CSession* session)
	{

		if (nullptr == session)
		{
			SERVER_LOG(eServerLogType::eDebug, "########## UserManager : CreateUser Fail - session is null ");
			return;
		}
			
		// map 동일 아이디 체크
		// auto check_user = Get(session->GetID());
		// if (nullptr != check_user)
		if (_map.Exists(session->GetID()))
		{
			SERVER_LOG(eServerLogType::eDebug, "########## UserManager : CreateUser Fail - session id duplicate, %lld", session->GetID());
			return;
		}

		auto user = _pool->Pop();

		if (nullptr == user)
		{
			SERVER_LOG(eServerLogType::eDebug, "########## UserManager : CreateUser Fail - pool is empty !!!! ##################");
			return;
		}

		user->SetSession(session);

		user->SetConnectState(true);
		
		_map.Insert(session->GetID(), user);
	}

	void CUserManager::DestroyUser(CSession* session)
	{

		auto user = Get(session->GetID());

		if (nullptr != user)
		{
			user->Release();
			_pool->Push(user);
		}

		_map.Erase(session->GetID());
	}

	void CUserManager::ReconnectUser(CSession* session)
	{

		auto user = Get(session->GetID());

		if (nullptr != user)
		{
			user->SetConnectState(true);			
		}
	}

	CUser* CUserManager::Get(int64_t session_id)
	{
		return _map.Get(session_id);
	}

}	// namespace mir3d