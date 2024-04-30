#pragma once

#include <network/eventWorker.h>

namespace mir3d
{
	// network thread에서 건네 받은 패킷을 각 패킷 처리 함수로 이벤트 처리 방식으로 분기 하는 sample
	class CGameEventWorker : public CEventWorker, public CSingleton<CGameEventWorker>
	{
	public:
		CGameEventWorker() = delete;
		CGameEventWorker(int32_t worker_count) : CEventWorker(worker_count, 1) 
		{
			_list_event_timer.reserve(worker_count);

			for (int32_t i = 0; i < worker_count; i++)
			{
				_list_event_timer.push_back(nullptr);
			}
		}
		virtual ~CGameEventWorker() {}

	public:
		virtual void Initialize(bool suspend = true);
		virtual void Start(void);
		virtual void Destroy(void);		

	private:
		virtual bool Begin(void);
		virtual bool Run(int32_t index);
		virtual bool End(void);

	private:
		std::vector<EventTimer*>	_list_event_timer;

	private:
		CGameEventWorker(const CGameEventWorker&) = delete;
		CGameEventWorker& operator=(const CGameEventWorker&) = delete;
		CGameEventWorker(CGameEventWorker&&) = delete;
		CGameEventWorker& operator=(CGameEventWorker&&) = delete;
	};
	#define gameEventWorker CGameEventWorker::getInstance()

}	// namespace mir3d

