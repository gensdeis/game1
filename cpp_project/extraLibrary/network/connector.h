#pragma once

#include "server.h"

namespace mir3d
{
	class CSession;

	class CConnector : public CServer
	{
	public:
		CConnector() = delete;
		CConnector(const std::string& name, int32_t session_count, int32_t worker_count);
		virtual ~CConnector();

	protected:
		virtual void Initialize();
		virtual void Start(void);
		virtual void Destroy(void);

		virtual void PacketHookHandlerRegister(PacketHookHandler handler);
		virtual void SocketHandlerRegister(SocketOpenedHandler opened_handler, SocketConnectFailHandler failed_handler, SocketClosedHandler closed_handler);
		virtual void SessionHandlerRegister(SessionOpenedHandler opened_handler, SessionClosedHandler closed_handler);

	public:
		CSocket*	PostConnect(boost::asio::ip::tcp::endpoint& endpoint, const std::string& rpc_connect_fulltag);

	private:
		void callback_connect(CSocket* socket, const boost::system::error_code& error_code);

	private:
		boost::asio::ip::tcp::endpoint _connect_endpoint;

	private:
		CConnector(const CConnector&) = delete;
		CConnector& operator=(const CConnector&) = delete;
		CConnector(CConnector&&) = delete;
		CConnector& operator=(CConnector&&) = delete;
	};

}	// namespace mir3d