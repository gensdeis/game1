#include "stdafx.h"
#include "gameEventWorker.h"

namespace mir3d
{
	void CGameEventWorker::Initialize(bool suspend)
	{
		CEventWorker::Initialize(suspend);
	}

	void CGameEventWorker::Start(void)
	{
		CEventWorker::Start();
	}

	void CGameEventWorker::Destroy(void)
	{
		CEventWorker::Destroy();
	}	

	bool CGameEventWorker::Begin(void)
	{
		return true;
	}

	bool CGameEventWorker::Run(int32_t index)
	{
		if (false == SwitchEventIndex(index))
		{
			return true;
		}

		uint64_t now = util::mirTime::GetTickMilliCount();
		int32_t k = 0;
		bool instant_flag = false;
		int32_t timer_list_size = _list_timer_update[index]->size();
		int32_t instant_list_size = _list_instant_update[index]->size();

		for (int32_t i = 0; i < timer_list_size; )
		{
			//auto ptr_event_timer = _list_timer_update[index]->operator[](i);			
			const auto& ptr_event_timer = _list_timer_update[index]->operator[](i);

			for (k = 0; k < instant_list_size; k++)
			{
				if (ptr_event_timer.uid == _list_instant_update[index]->operator[](k))
				{
					instant_flag = true;
					break;
				}
			}

			if (ptr_event_timer.time > now && false == instant_flag)
			{
				i++;
			}
			else
			{
				if (true == instant_flag)
				{
					instant_flag = false;
					_list_instant_update[index]->Erase(k, __func__);
					instant_list_size--;
				}

				_list_timer_update[index]->Erase(i, __func__);
				timer_list_size--;
			}
		}

		_list_instant_update[index]->Clear();

		/*
		int32_t curr_index = *_list_event_index[index];

		_list_event_index[index]->exchange(curr_index ^ 1);

		auto update_timer_list = _list_timer_update[index];
		if (nullptr == update_timer_list) 
		{
			return true;
		}

		auto update_instant_list = _list_instant_update[index];
		if (nullptr == update_instant_list) 
		{
			return true;
		}

		std::unique_lock<std::mutex> lock(_list_mutex_timer[index]);
		mVector<EventTimer>* timer_list = _list_timer_add[index][curr_index];
		if (0 < timer_list->size())
		{
			if (false == update_timer_list->Copy(timer_list))
			{
				return true;
			}
		}
		lock.unlock();


		if (0 == update_timer_list->size())
		{
			return true;
		}

		lock.lock();
		mVector<int64_t>* instant_list = _list_instant_add[index][curr_index];
		if (0 < instant_list->size())
		{
			if (false == update_instant_list->Copy(instant_list))
			{
				return true;
			}
		}
		lock.unlock();


		uint64_t now = util::mirTime::GetTickMilliCount();
		int32_t k = 0;
		bool instant_flag = false;
		int32_t timer_list_size = update_timer_list->size();
		int32_t instant_list_size = update_instant_list->size();

		for (int32_t i = 0; i < timer_list_size; )
		{			
			auto ptr_event_timer = update_timer_list->operator[](i);
			
			for (k = 0; k < instant_list_size; k++)
			{
				if (ptr_event_timer.uid == update_instant_list->operator[](k))
				{
					instant_flag = true;
					break;
				}
			}

			if (ptr_event_timer.time > now && false == instant_flag)
			{
				i++;
				continue;
			}

			if (true == instant_flag)
			{
				instant_flag = false;
				update_instant_list->Erase(k);
				instant_list_size--;
			}

			// gamePacketWorker 에 다시 object 반환
			objectManager.InsertUpdateList(ptr_event_timer.uid);
			update_timer_list->Erase(i);
			timer_list_size--;
		}

		update_instant_list->Clear();
		*/

		/*
		EventFunction func;

		SwitchEventIndex(index);

		auto current_index = *_list_event_index[index] ^ 1;
		while (_list_event[index][current_index]->Pop(func))
		{
			func();
		}
		*/

		return true;
	}

	bool CGameEventWorker::End(void)
	{
		return true;
	}

}	// namespace mir3d

