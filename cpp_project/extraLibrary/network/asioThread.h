#pragma once

namespace mir3d
{
	class CAsioThread
	{
	public:
		CAsioThread() = delete;
		CAsioThread(std::vector<std::shared_ptr<boost::asio::io_service>>& list_io_service);
		virtual ~CAsioThread()
		{
			Destroy();
		}

	public:

		void Create(const std::string& name);
		void Destroy(void);

	public:
		//template <class T>
		//void Post(T t)
		//{
		//	_io_service.post(t);
		//}

	private:

		std::vector<std::shared_ptr<boost::asio::io_service>>			_list_io_service;
		std::vector<std::shared_ptr<boost::asio::io_service::work>>		_list_io_worker;
		std::vector<std::shared_ptr<std::thread>>						_list_threads;


	private:
		CAsioThread(const CAsioThread&) = delete;
		CAsioThread& operator=(const CAsioThread&) = delete;
		CAsioThread(CAsioThread&&) = delete;
		CAsioThread& operator=(CAsioThread&&) = delete;
	};


}	// namespace mir3d
