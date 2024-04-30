#pragma once

#include <common/mirapi.h>
#include <boost/thread/thread.hpp>
#include <boost/asio/io_service.hpp>
#if defined(_MULTI_CLIENT) || defined(_MULTI_STRESS)
namespace mir3d
{

	//
	// Functor 를 랩핑한다.
	//
	template< class task_t >
	struct task_wrapped
	{
	private:

		task_t m_task_unwrapped;

	public:

		explicit task_wrapped(const task_t& _task_unwrapped)
			: m_task_unwrapped(_task_unwrapped)
		{
			try
			{
				// 이곳을 인터럽트 포인트로 설정한다.
				boost::this_thread::interruption_point();
			}
			// 예외 처리
			catch (const boost::thread_interrupted&)
			{
			}

			try
			{
				// task functor 를 실행한다.
				m_task_unwrapped();
			}
			catch (const std::exception& e)
			{
				LOG(ERROR) << "task_wrapped : Exception: " << e.what() << '\n';
			}
			catch (const boost::thread_interrupted&)
			{
				LOG(ERROR) << "task_wrapped : Thread interrupted\n";
			}
			catch (...)
			{
				LOG(ERROR) << "task_wrapped : Unknown exception\n";
			}
		}

		void operator()() const
		{
			LOG(ERROR) << "task_wrapped :operator\n";
		}
	};

	//
	// task wrapped 를 생성한다.
	//
	template <class task_t>
	inline task_wrapped<task_t> make_task_wrapped(const task_t& _task_unwrapped)
	{
		return task_wrapped<task_t>(_task_unwrapped);
	}
		

	class tasks_processor //: private boost::noncopyable
	{
	protected:

		// boost io_service
		// 운영체제를 이용하여 작업을 처리하도록 도와주는
		// 가장 중요한놈
		boost::asio::io_service m_ios;

		// io_service 를 run 함수를 이용해 동작시킬 경우
		// 멈추지 않고 계속 run 을 실행할 수 있도록 해주는 놈
		typedef boost::shared_ptr< boost::asio::io_service::work > work_t;
		work_t m_work;

		// 스레드 그룹
		boost::thread_group m_thread_gp;

	protected:

		// constructor
		tasks_processor()
			: m_ios()
		{}

		~tasks_processor()
		{
			m_work.reset();

			m_thread_gp.join_all();
		}

	public:

		inline boost::asio::io_service& get_ios() { return m_ios; }

		//template< class task_wrapped_t >
		//inline void push_task(const task_wrapped_t& _task_wrapped)
		//{
		//	//m_ios.post(http_response(_task_wrapped));
		//}

		void run_through_thread()
		{
			m_thread_gp.create_thread(boost::bind(&boost::asio::io_service::run, &m_ios));
		}
		void run()
		{
			m_ios.run();
		}

		void stop()
		{
			m_ios.stop();
		}

		void reset()
		{
			m_ios.reset();
		}

		void poll()
		{
			m_ios.poll();
		}

		bool stopped()
		{
			return m_ios.stopped();
		}

	};

	
} // namespace mir3d
#endif