#pragma once

namespace mir3d
{
	class CThread
	{
	public:
		CThread() = delete;
		CThread(int32_t wait_time, const std::string& name);
		virtual ~CThread();

	protected:
		virtual void		Initialize(int32_t thread_count, bool suspend = true);
		virtual void		Start(void);
		virtual void		Destroy(void);
		
	private:
		virtual bool		Begin(void) = 0;				// 쓰레드 루틴 진입전 1회 동작
		virtual bool		Run(int32_t thread_index) = 0;			// 쓰레드 루틴( 쓰레드 갯수만큼 동작 )
		virtual bool		End(void) = 0;					// 쓰레드 루틴 끝난후 1회 동작

	private:
		void				PrepareDestroy(void);
		void				Worker(int32_t thread_index, bool suspend);

	private:		
		std::vector<std::thread*>	_list_thread;
		int32_t						_wait_msec = 0;
		bool						_loop_event = true;

		std::mutex					_mutex_suspend;
		std::condition_variable		_suspend_condition;
		bool						_suspend_flag = false;

	protected:
		std::string					_name;

	private:
		CThread(const CThread&) = delete;
		CThread& operator=(const CThread&) = delete;
		CThread(CThread&&) = delete;
		CThread& operator=(CThread&&) = delete;
	};

}	// namespace mir3d
