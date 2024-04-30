#pragma once

#include "worker.h"

namespace mir3d
{
#define EVENT_MAX_COUNT 1000000

	typedef boost::function<void()> EventFunction;

	struct EventTimer
	{
		uint64_t	time = 0;
		int64_t		uid = 0;
		int32_t		tag = 0;

	public:
		EventTimer()
		{
		}

		EventTimer(uint64_t time_, int64_t uid_, int32_t tag_)
		{
			time = time_;
			uid = uid_;
			tag = tag_;
		}
	};

	class CEventWorker : public CWorker
	{
	public:
		CEventWorker() = delete;
		CEventWorker(int32_t worker_count, int32_t wait_msec) : CWorker("EventWorker", worker_count, wait_msec) {}
		virtual ~CEventWorker()
		{
			Release();
		}

	protected:
		virtual void Initialize(bool suspend = true)
		{
			for (int32_t i = 0; i < _worker_count; i++)
			{	
				_list_event.push_back(std::vector<CConcurrentQueue<EventFunction>*>());
				_list_event_index.push_back(new std::atomic<int32_t>(0));
				_list_map_timer.push_back(std::vector<std::unordered_map<int64_t, int64_t>>());
				_list_map_instant.push_back(std::vector<std::unordered_map<int64_t, int64_t>>());

				std::vector<mVector<EventTimer>*> list_timer;
				std::vector<mVector<int64_t>*> list_instant;
				for (int32_t j = 0; j < 2; j++)
				{
					_list_event[i].push_back(new CConcurrentQueue<EventFunction>());
					_list_map_timer[i].push_back(std::unordered_map<int64_t, int64_t>());
					_list_map_instant[i].push_back(std::unordered_map<int64_t, int64_t>());

					list_timer.push_back(new mVector<EventTimer>());
					list_timer[j]->Reserve(EVENT_MAX_COUNT);

					list_instant.push_back(new mVector<int64_t>());
					list_instant[j]->Reserve(EVENT_MAX_COUNT);					
				}

				_list_timer_add.push_back(list_timer);
				_list_instant_add.push_back(list_instant);

				_list_timer_update.push_back(new mVector<EventTimer>());
				_list_timer_update[i]->Reserve(EVENT_MAX_COUNT);

				_list_instant_update.push_back(new mVector<int64_t>());
				_list_instant_update[i]->Reserve(EVENT_MAX_COUNT);

				_list_mutex_timer.push_back(new std::mutex());
				_list_mutex_instant.push_back(new std::mutex());

				/*
				std::vector<mVector<EventTimer>*> list;
				for (int32_t j = 0; j < 2; j++)
				{
					mVector<EventTimer>* timer_event = new mVector<EventTimer>();
					timer_event->Reserve(10000);
					list.push_back(timer_event);
				}
				_list_timer_add.push_back(list);
				
				mVector<EventTimer>* _update_timer_event = new mVector<EventTimer>();
				_update_timer_event->Reserve(10000);
				_list_timer_update.push_back(_update_timer_event);

				std::vector<mVector<int64_t>*> instant_list;
				for (int32_t j = 0; j < 2; j++)
				{
					mVector<int64_t>* instant_event = new mVector<int64_t>();
					instant_event->Reserve(10000);
					instant_list.push_back(instant_event);
				}
				_list_instant_add.push_back(instant_list);
				
				mVector<int64_t>* _update_instant_event = new mVector<int64_t>();
				_update_instant_event->Reserve(10000);
				_list_instant_update.push_back(_update_instant_event);

				_list_event_index.push_back(new std::atomic<int32_t>(0));
				*/

				
			}

			CWorker::Initialize(_worker_count, suspend);
		}

		virtual void Destroy(void)
		{
			CWorker::Destroy();
		}

		void Release(void)
		{
			for (auto item : _list_event)
			{
				for (auto item2 : item)
				{
					delete item2;
				}
			}

			for (auto item : _list_event_index)
			{
				delete item;
			}

			for (auto list : _list_timer_add)
			{
				for (auto item : list)
				{
					delete item;
				}
			}

			for (auto item : _list_timer_update)
			{
				delete item;
			}

			for (auto list : _list_instant_add)
			{
				for (auto item : list)
				{
					delete item;
				}
			}

			for (auto item : _list_instant_update)
			{
				delete item;
			}
		}

	public:		
		inline void EventInvoke(const EventFunction& function)
		{
			_list_event[0][*_list_event_index[0]]->Push(function);
		}

		inline void EventInvoke(const EventFunction& function, const int32_t event_tag)
		{
			_list_event[event_tag % _worker_count][*_list_event_index[event_tag]]->Push(function);
		}

		/*
		inline void TimerInvoke(const int32_t event_tag, const int64_t time, const int64_t uid)
		{
			std::unique_lock<std::mutex> lock(_list_mutex_timer[event_tag]);
			auto event_timer = _list_timer_add[event_tag % _worker_count][*(_list_event_index[event_tag % _worker_count])];
			for (int i = 0; i < event_timer->size(); i++)
			{
				if (uid == (*event_timer)[i].uid)
				{
					return;
				}
			}
			_list_timer_add[event_tag % _worker_count][*(_list_event_index[event_tag % _worker_count])]->Push_back(EventTimer(time, uid));
		}

		inline void InstantInvoke(const int32_t event_tag, int64_t uid)
		{
			std::unique_lock<std::mutex> lock(_list_mutex_timer[event_tag]);
			auto event_timer = _list_instant_add[event_tag % _worker_count][*(_list_event_index[event_tag % _worker_count])];
			for (int i = 0; i < event_timer->size(); i++)
			{
				if (uid == (*event_timer)[i])
				{
					return;
				}
			}
			_list_instant_add[event_tag % _worker_count][*(_list_event_index[event_tag % _worker_count])]->Push_back(uid);
		}
		*/
		inline bool SwitchEventIndex(int32_t thread_index)
		{
			int32_t event_index = *_list_event_index[thread_index] ^ 1;
			bool result = true;

			// todo - lock 처리 확인 필요	
			{
				std::unique_lock<std::mutex> lock(*_list_mutex_timer[thread_index]);

				// timer event copy
				{
					if (0 < _list_timer_add[thread_index][event_index]->size())
					{
						result = _list_timer_update[thread_index]->Move(_list_timer_add[thread_index][event_index]);
					}

					_list_map_timer[thread_index][event_index].clear();
				}
			}
			
			// todo - lock 처리 확인 필요	
			{
				std::unique_lock<std::mutex> lock(*_list_mutex_instant[thread_index]);

				// instant event copy
				{
					if (0 < _list_instant_add[thread_index][event_index]->size())
					{
						result = _list_instant_update[thread_index]->Move(_list_instant_add[thread_index][event_index]);
					}

					_list_map_instant[thread_index][event_index].clear();
				}
			}

			_list_event_index[thread_index]->exchange(event_index);

			return result;
		}

		inline void TimerInvoke(const int32_t& event_tag, const int64_t& time, const int64_t& uid)
		{
			auto thread_index = event_tag % _worker_count;
			int32_t current_index = _list_event_index[thread_index]->load();

			std::unique_lock<std::mutex> lock(*_list_mutex_timer[thread_index]);
			auto event_timer = _list_timer_add[thread_index][current_index];

			// 요걸 써야할지 for 문을 써야 할지 고민이다.
			auto iter = _list_map_timer[thread_index][current_index].find(uid);
			if (_list_map_timer[thread_index][current_index].end() != iter)
			{
				return;
			}
			_list_map_timer[thread_index][current_index].insert(std::make_pair(uid, 0));
			/*
			for (int i = 0; i < event_timer->size(); i++)
			{
				if (uid == (*event_timer)[i].uid)
				{
					return;
				}
			}
			*/

			//event_timer->Push_back(EventTimer(time, uid));
			event_timer->Push_back(EventTimer(time, uid, event_tag), __func__);
		}

		inline void InstantInvoke(const int32_t& event_tag, const int64_t& uid)
		{
			auto thread_index = event_tag % _worker_count;
			int32_t current_index = _list_event_index[thread_index]->load();

			std::unique_lock<std::mutex> lock(*_list_mutex_instant[thread_index]);
			auto event_instant = _list_instant_add[thread_index][current_index];
			
			auto iter = _list_map_instant[thread_index][current_index].find(uid);
			if (_list_map_instant[thread_index][current_index].end() != iter)
			{
				return;
			}
			_list_map_instant[thread_index][current_index].insert(std::make_pair(uid, 0));
			/*
			for (int i = 0; i < event_instant->size(); i++)
			{
				if (uid == (*event_instant)[i])
				{
					return;
				}
			}
			*/

			event_instant->Push_back(uid, __func__);
		}

	protected:		
		std::vector<std::vector<CConcurrentQueue<EventFunction>*>>		_list_event;

		std::vector<mVector<EventTimer>*>								_list_timer_update;
		std::vector<std::vector<mVector<EventTimer>*>>					_list_timer_add;
		std::vector<std::mutex*>										_list_mutex_timer;
		std::vector<std::vector<std::unordered_map<int64_t, int64_t>>>	_list_map_timer;

		std::vector<mVector<int64_t>*>									_list_instant_update;
		std::vector<std::vector<mVector<int64_t>*>>						_list_instant_add;
		std::vector<std::mutex*>										_list_mutex_instant;
		std::vector<std::vector<std::unordered_map<int64_t, int64_t>>>	_list_map_instant;

		std::vector<std::atomic<int32_t>*>								_list_event_index;

	private:
		CEventWorker(const CEventWorker&) = delete;
		CEventWorker& operator=(const CEventWorker&) = delete;
		CEventWorker(CEventWorker&&) = delete;
		CEventWorker& operator=(CEventWorker&&) = delete;
	};

}	// namespace mir3d

