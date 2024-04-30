#include "stdafx_net.h"
#include "sessionWaitPool.h"
#include "sessionPool.h"
#include "session.h"
#include <common/config.h>
#include <common/serverlogManager.h>

namespace mir3d
{
	CMemPool<SessionWaitPool::waitItem>*    			SessionWaitPool::_pool = nullptr;
	CConcurrentQueue<SessionWaitPool::waitItem*>*		SessionWaitPool::_queue = nullptr;
	uint64_t											SessionWaitPool::_limit_time = 0;
	updateFuntionHandler								SessionWaitPool::_func = nullptr;

	CConcurrentQueue<SessionWaitPool::waitItem*>*		SessionWaitPool::_queue_disconnect = nullptr;


	void SessionWaitPool::Initialize(const NetworkConfig::sPoolInfo* info)
	{
		_pool = new CMemPool<waitItem>(info->default_size, info->create_size, info->name, OnMempoolAllocLogger);
		_queue = new CConcurrentQueue<waitItem*>();

		_limit_time = static_cast<uint64_t>(info->reserve_value) * 1000;

		_func = nullptr;

		_queue_disconnect = new CConcurrentQueue<waitItem*>();
	}

	void SessionWaitPool::Destroy(void)
	{
		SAFE_DELETE(_pool);
		SAFE_DELETE(_queue);

		SAFE_DELETE(_queue_disconnect);
	}

	void SessionWaitPool::Push(const int64_t session_id)
	{
		auto item = _pool->Pop();

		item->expire_time = mir3d::util::mirTime::GetTickMilliCount() + _limit_time;
		item->session_id = session_id;

		_queue->Push(item);
	}

	void SessionWaitPool::PushDisconnect(const int64_t session_id)
	{
		auto item = _pool->Pop();

		item->expire_time = mir3d::util::mirTime::GetTickMilliCount() + (_limit_time / 2);	// time temp.
		item->session_id = session_id;

		_queue_disconnect->Push(item);
	}

	void SessionWaitPool::Update(void)
	{
		waitItem* item = nullptr;

		auto now = mir3d::util::mirTime::GetTickMilliCount();

		while (true)
		{
			if (nullptr != _func)
			{
				_func(now);
			}

			if (_queue_disconnect->Front(item))
			{
				if (now > item->expire_time)
				{
					auto session = SessionPool::PopWaitDisconnect(item->session_id);					
					if (nullptr != session)
					{
						if (CSocket::eSocketState::connected == session->GetSocket()->ConnectState())
						{
							session->ForceDisconnect(__func__);
						}
						else
						{
							session->Destroy();
						}
					}
					_queue_disconnect->FrontErase();

					SERVER_LOG(eServerLogType::eDebug, "SessionWaitPool::Update:: _queue_disconnect size :: %d, expire_time delay :: %lld", _queue_disconnect->Size(true), static_cast<int64_t>(now - item->expire_time));

					item->reset();
					_pool->Push(item);

				}
			}

			if (_queue->Front(item))
			{
				if (now > item->expire_time)
				{
					// wait session delete
					auto session = SessionPool::PopWait(item->session_id);

					if (nullptr != session)
					{
						session->Destroy();
						SessionPool::Push(session);		// gogoblue74 - 2022.06.13
					}
					_queue->FrontErase();

					SERVER_LOG(eServerLogType::eDebug, "SessionWaitPool::Update:: _queue size :: %d, expire_time delay :: %lld", _queue->Size(true), static_cast<int64_t>(now - item->expire_time));

					item->reset();
					_pool->Push(item);

				}
				else
				{
					// queue 이기때문에 front 가 처리 안되면 다음꺼 처리 할 필요가 없다
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

	void SessionWaitPool::UpdateFunction(void (*func)(const uint64_t& now_time))
	{
		_func = func;
	}

	// Web Daemon 추가로 필요
	int32_t SessionWaitPool::GetWaitingSeesionPoolSize()
	{
		return static_cast<int32_t>(_queue->Size(true));
	}

	int32_t SessionWaitPool::GetDisconnectSeesionPoolSize()
	{
		return static_cast<int32_t>(_queue_disconnect->Size(true));
	}

}	// namespace mir3d