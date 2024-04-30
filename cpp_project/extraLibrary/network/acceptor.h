#pragma once

#include "server.h"
#include "thread.h"

namespace mir3d
{
	class CAcceptor : public CServer, public CThread
	{
	public:
		CAcceptor() = delete;
		CAcceptor(const std::string& name, unsigned short port, int32_t session_count, int32_t worker_count);
		virtual ~CAcceptor();

	protected:
		virtual void Initialize();
		virtual void Start(void);
		virtual void Destroy(void);	

		virtual void PacketHookHandlerRegister(PacketHookHandler handler);
		virtual void SocketHandlerRegister(SocketOpenedHandler opened_handler, SocketConnectFailHandler failed_handler, SocketClosedHandler closed_handler);
		virtual void SessionHandlerRegister(SessionOpenedHandler opened_handler, SessionClosedHandler closed_handler);

		// Web Daemon 추가로 필요
	public:		
		int32_t GetConnectedSocketSize(void)	{ return CServer::GetConnectedSocketSize(); }
		int32_t GetWaitingSocketSize(void)		{ return CServer::GetWaitingSocketSize(); }

	private:
		virtual bool Run(int32_t thread_index);

	private:
		boost::asio::ip::tcp::acceptor*	_acceptor = nullptr;
		unsigned short					_port;
		
	private:
		CAcceptor(const CAcceptor&) = delete;
		CAcceptor& operator=(const CAcceptor&) = delete;
		CAcceptor(CAcceptor&&) = delete;
		CAcceptor& operator=(CAcceptor&&) = delete;
	};

}	// namespace mir3d