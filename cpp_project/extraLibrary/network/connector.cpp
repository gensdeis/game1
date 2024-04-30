#include "stdafx_net.h"
#include "connector.h"
#include "session.h"
#include <common/serverlogManager.h>

namespace mir3d
{
	CConnector::CConnector(const std::string& name, int32_t session_count, int32_t worker_count) : CServer(name, session_count, worker_count)
	{
	}

	CConnector::~CConnector()
	{
		Destroy();
	}

	void CConnector::Initialize()
	{
		CServer::Initialize(); // CServer::Initialize(rpc_socket);
	}

	void CConnector::Start(void)
	{
		CServer::Start();
	}

	void CConnector::Destroy(void)
	{
		CServer::Destroy();
	}
	
	CSocket* CConnector::PostConnect(boost::asio::ip::tcp::endpoint& endpoint, const std::string& rpc_connect_fulltag)
	{
		int32_t socket_id;
		auto socket = GetSocket(socket_id);

		if (nullptr == socket)
		{
			SERVER_LOG(eServerLogType::eDebug, "socket is empty !!!");
			return nullptr;
		}

		socket->SetRpcFullTag(rpc_connect_fulltag);

		socket->SetConnecter();

		_connect_endpoint = endpoint;

		socket->Socket().async_connect(endpoint, boost::bind(&CConnector::callback_connect, this, socket, boost::asio::placeholders::error));

		return socket;
	}

	void CConnector::callback_connect(CSocket* socket, const boost::system::error_code& error_code)
	{
		if (error_code)
		{
			std::ostringstream str_addr;
			str_addr << _connect_endpoint.address() << ":" << _connect_endpoint.port();
			
			SERVER_LOG(eServerLogType::eDebug, "CConnector::callback_connect(), [%s], [%s] - error No: %d, error Message: %s", socket->GetRpcFullTag().c_str(), str_addr.str().c_str(), error_code.value(), error_code.message().c_str());

			SocketConnectFail(socket);

			DisconnectedSocket(socket->GetID());
		}
		else
		{
			ConnectedSocket(socket->GetID());

			socket->PostReceive();
		}
	}

	void CConnector::PacketHookHandlerRegister(PacketHookHandler handler)
	{
		CServer::PacketHookHandlerRegister(handler);
	}

	void CConnector::SocketHandlerRegister(SocketOpenedHandler opened_handler, SocketConnectFailHandler failed_handler, SocketClosedHandler closed_handler)
	{
		CServer::SocketHandlerRegister(opened_handler, failed_handler, closed_handler);
	}

	void CConnector::SessionHandlerRegister(SessionOpenedHandler opened_handler, SessionClosedHandler closed_handler)
	{
		CServer::SessionHandlerRegister(opened_handler, closed_handler);
	}

}	// namespace mir3d