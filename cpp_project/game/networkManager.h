#pragma once

namespace mir3d
{
	class CSocket;
	class CSession;

	class CAcceptServer : public CAcceptor
	{
	public:
		CAcceptServer() = delete;
		CAcceptServer(unsigned short port, int32_t session_count, int32_t worker_count) : CAcceptor("networkManager.AcceptServer", port, session_count, worker_count) {}
		virtual ~CAcceptServer() {}

	public:
		virtual void Initialize(void);
		virtual void Start(void)		{ CAcceptor::Start(); }
		virtual void Destroy(void)		{ CAcceptor::Destroy(); }
		
	protected:
		virtual bool Begin(void)		{ return true; }
		virtual bool End(void)			{ return true; }
		
		// Web Daemon 추가로 필요
	public:		
		int32_t GetConnectedSocketSize(void)	{ return CAcceptor::GetConnectedSocketSize(); }
		int32_t GetWaitingSocketSize(void)		{ return CAcceptor::GetWaitingSocketSize(); }

	private:
		CAcceptServer(const CAcceptServer&) = delete;
		CAcceptServer& operator=(const CAcceptServer&) = delete;
		CAcceptServer(CAcceptServer&&) = delete;
		CAcceptServer& operator=(CAcceptServer&&) = delete;
	};
	void OnGamePacketHookHandler(packetContext* context);
	//void OnGameSocketOpened(CSocket* socket);
	void OnGameSocketClosed(CSocket* socket);
	void OnGameSessionOpened(CSession* session, const bool& reconnect);
	void OnGameSessionClosed(CSession* session);

	void OnGatePacketHookHandler(packetContext* context);
	void OnGateSocketOpened(CSocket* socket);
	void OnGateSocketClosed(CSocket* socket);
	void OnGateSessionOpened(CSession* session, const bool& reconnect);
	void OnGateSessionClosed(CSession* session);

#ifdef _USE_GATE_COMMUNITY
#else
	void OnCommunityPacketHookHandler(packetContext* context);
	void OnCommunitySocketOpened(CSocket* socket);
	void OnCommunitySocketClosed(CSocket* socket);
	void OnCommunitySessionOpened(CSession* session, const bool reconnect);
	void OnCommunitySessionClosed(CSession* session);
#endif

	class CNetworkManager : public CSingleton<CNetworkManager>
	{
	public:
		CNetworkManager() = default;
		CNetworkManager(unsigned short port, int32_t session_count, int32_t worker_count);
		virtual ~CNetworkManager() = default;

	public:
		bool Initialize(void);
		void Start(void);
		void Destroy(void);

	public:
		void SendErrorMessage(const mpe_cmd cmd, CSession* const session, const mpe_error error_code, bool reload = false, int64_t param1 = 0);
		template<typename T>
		void SendAll(const T& packet)
		{
			_acceptor.SendAll(packet);
		}

		void UpdateNotAllowPacket(void);

		// Web Daemon 추가로 필요
		int32_t GetConnectedSocketSize(void)	{ return _acceptor.GetConnectedSocketSize(); }
		int32_t GetWaitingSocketSize(void)		{ return _acceptor.GetWaitingSocketSize(); }

	private:
		CAcceptServer _acceptor;

	private:
		CNetworkManager(const CNetworkManager&) = delete;
		CNetworkManager& operator=(const CNetworkManager&) = delete;
		CNetworkManager(CNetworkManager&&) = delete;
		CNetworkManager& operator=(CNetworkManager&&) = delete;
	};
	#define networkManager CNetworkManager::getInstance()

}	// namespace mir3d
