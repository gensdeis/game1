#include "stdafx_net.h"
#include "acceptor.h"
#include "session.h"
#include <common/serverlogManager.h>

namespace mir3d
{
	CAcceptor::CAcceptor(const std::string& name, unsigned short port, int32_t session_count, int32_t worker_count) : CServer(name, session_count, worker_count), CThread(1, name), _port(port)
	{
		// https://www.it-note.kr/189
		_acceptor = new boost::asio::ip::tcp::acceptor(get_io_service(), boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), _port));
	}

	CAcceptor::~CAcceptor()
	{
		//Destroy();
		SAFE_DELETE(_acceptor);		
	}

	void CAcceptor::Initialize()
	{
		CServer::Initialize();//CServer::Initialize(rpc_socket);

		CThread::Initialize(1, true);
	}

	void CAcceptor::Start(void)
	{
		CServer::Start();

		CThread::Start();
	}

	void CAcceptor::Destroy(void)
	{
		if (nullptr != _acceptor)
		{
			_acceptor->cancel();
			_acceptor->close();	
		}

		CThread::Destroy();

		CServer::Destroy();		
	}

	bool CAcceptor::Run(int32_t thread_index)
	{
		int32_t socket_id;
		auto socket = GetSocket(socket_id);

		if (nullptr == socket)
		{
			SERVER_LOG(eServerLogType::eWarning, "CAcceptor::Run() thread_index : %d, GetSocket() is nullptr return.", thread_index);
			return true;
		}
		
		boost::system::error_code error_code;
		_acceptor->accept(socket->Socket(), error_code);

		if (error_code)
		{
			SERVER_LOG(eServerLogType::eInfo, "CAcceptor::accept() - error No : %d, error Message : %s", error_code.value(), error_code.message().c_str());
			DisconnectedSocket(socket_id);
		}
		else
		{
			ConnectedSocket(socket_id);

			socket->PostReceive();
		}

		return true;
	}

	void CAcceptor::PacketHookHandlerRegister(PacketHookHandler handler)
	{
		CServer::PacketHookHandlerRegister(handler);
	}

	void CAcceptor::SocketHandlerRegister(SocketOpenedHandler opened_handler, SocketConnectFailHandler failed_handler, SocketClosedHandler closed_handler)
	{
		CServer::SocketHandlerRegister(opened_handler, failed_handler, closed_handler);
	}

	void CAcceptor::SessionHandlerRegister(SessionOpenedHandler opened_handler, SessionClosedHandler closed_handler)
	{
		CServer::SessionHandlerRegister(opened_handler, closed_handler);
	}

}	// namespace mir3d