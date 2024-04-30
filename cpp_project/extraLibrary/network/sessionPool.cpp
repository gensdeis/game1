#include "stdafx_net.h"
#include "sessionPool.h"
#include <common/serverlogManager.h>

namespace mir3d
{
	CMemPool<CSession>*									SessionPool::_pool = nullptr;
	CConcurrentMap<int64_t, CSession*>*					SessionPool::_map_wait = nullptr;
	CConcurrentMap<int64_t, CSession*>*					SessionPool::_map_wait_disconnect = nullptr;
	

	void SessionPool::Initialize(const NetworkConfig::sPoolInfo* info)
	{
		_pool = new CMemPool<CSession>(info->default_size, info->create_size, info->name, OnMempoolAllocLogger);
		_map_wait = new CConcurrentMap<int64_t, CSession*>();
		_map_wait_disconnect = new CConcurrentMap<int64_t, CSession*>();
	}

	void SessionPool::Destroy(void)
	{
		if (nullptr == _pool)
			delete _pool;

		if (nullptr == _map_wait)
			delete _map_wait;

		SAFE_DELETE(_map_wait_disconnect);
	}

	CSession* SessionPool::Pop(void)
	{
		return _pool->Pop();
	}

	void SessionPool::Push(CSession* item)
	{
		item->Release();
		_pool->Push(item);
	}

	CSession* SessionPool::PopWait(int64_t session_id)
	{
		CSession* session = nullptr;
		_map_wait->GetErase(session_id, session);
		return session;
	}

	CSession* SessionPool::PopWaitDisconnect(int64_t session_id)
	{
		CSession* session = nullptr;
		_map_wait_disconnect->GetErase(session_id, session);
		return session;
	}

	void SessionPool::PushWait(CSession* session)
	{
		if (false == _map_wait->Exists(session->GetID()))	// gogoblue74 - 2022.06.12   _map_wait_disconnect -> _map_wait
		{
			SessionWaitPool::Push(session->GetID());

			_map_wait->Insert(session->GetID(), session);
		}
	}

	void SessionPool::PushDisconnect(CSession* const session)
	{
		SessionWaitPool::PushDisconnect(session->GetID());

		_map_wait_disconnect->Insert(session->GetID(), session);
	}
}	// namespace mir3d