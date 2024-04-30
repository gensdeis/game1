#pragma once


namespace mir3d
{
	struct sGamelog
	{
		int32_t			type = 0;
		uint16_t		size = 0;
		char			text[ACTION_LOG_TEXT_SIZE];
		/*
		char* text = nullptr;

		sGamelog()
		{
			text = new char[ACTION_LOG_TEXT_SIZE];
		}

		~sGamelog()
		{
			delete[] text;
		}
		
	public:
		inline void reset(void)
		{
			size = 0;
		}
		*/
	};

	struct sGamelogBuffer
	{
		uint16_t	size = 0;
		char buffer[ACTION_LOG_TEXT_SIZE * ACTION_LOG_BUNDLE_MAX];

	public:
		inline void reset(void)
		{
			size = 0;
		}
	};

	class CGamelogManager : public CThread, public CSingleton<CGamelogManager>
	{
	public:
		CGamelogManager() = delete;
		CGamelogManager(const std::string& name, int32_t update_time = 1000);
		virtual ~CGamelogManager() {}

	public:
		virtual void Initialize(bool suspend = true);
		virtual void Start(void);
		virtual void Destroy(void);

	protected:
		virtual bool Begin(void);
		virtual bool Run(int32_t index);
		virtual bool End(void);

	public:
		sGamelog* Pop(void)
		{
			return _pool->Pop();
		}

		void Push(sGamelog* log)
		{
			// log->reset();
			_pool->Push(log);
		}

		void PushQueue(sGamelog* log)
		{
			_list_queue[_push_index]->Push(log);
		}

	private:
		CMemPool<sGamelog>*							_pool = nullptr;
		std::atomic<int32_t>						_push_index = 0;
		std::atomic<int32_t>						_update_index = 0;
		std::vector<CConcurrentQueue<sGamelog*>*>	_list_queue;
		sGamelogBuffer								_game_log_buffer;

		mrpc_action_log_cs							_packet_log;

	private:
		CGamelogManager(const CGamelogManager&) = delete;
		CGamelogManager& operator=(const CGamelogManager&) = delete;
		CGamelogManager(CGamelogManager&&) = delete;
		CGamelogManager& operator=(CGamelogManager&&) = delete;
	};
	#define gamelogManager CGamelogManager::getInstance()

	/*
	class CLogConnector : public CConnector
	{
	public:
		CLogConnector() = delete;
		CLogConnector(const std::string& name, int32_t session_count, int32_t worker_count) : CConnector(name, session_count, worker_count) {}
		virtual ~CLogConnector() {}

	public:
		virtual void Initialize(void);
		virtual void Start(void)		{ CConnector::Start(); }
		virtual void Destroy(void)		{ CConnector::Destroy(); }

	protected:
		virtual bool Begin(void)		{ return true; }
		virtual bool End(void)			{ return true; }
		
	private:
		CLogConnector(const CLogConnector&) = delete;
		CLogConnector& operator=(const CLogConnector&) = delete;
		CLogConnector(CLogConnector&&) = delete;
		CLogConnector& operator=(CLogConnector&&) = delete;
	};
	void OnLogConnectorSocketOpened(CSocket* socket);
	void OnLogConnectorSocketConnectFaild(CSocket* socket);
	void OnLogConnectorSocketClosed(CSocket* socket);
	void OnLogConnectorSessionOpened(CSession* session, const bool reconnect);
	void OnLogConnectorSessionClosed(CSession* session);
	
	class CGamelogManager : public CThread, public CSingleton<CGamelogManager>
	{
	public:
		CGamelogManager() = delete;
		CGamelogManager(const std::string& name, int32_t socket_count = 4, int32_t worker_count = 1, int32_t update_time = 1000);
		virtual ~CGamelogManager() {}

	public:
		virtual void Initialize(bool suspend = true);
		virtual void Start(void);
		virtual void Destroy(void);

	protected:
		virtual bool Begin(void);
		virtual bool Run(int32_t index);
		virtual bool End(void);
		
	public:
		void Connected(CSocket* socket);
		void ConnectFailed(CSocket* socket);
		void Disconnected(CSocket* socket, bool acceptor = false);
		
		void ConnectedSession(CSession* session, bool acceptor = false);
		void DisconnectedSession(CSession* session);

	private:
		void PostConnect(void);

	public:
		sGamelog* Pop(void)
		{
			return _pool->Pop();
		}

		void Push(sGamelog* log)
		{
			log->reset();

			_pool->Push(log);
		}

		void PushQueue(sGamelog* log)
		{
			_list_queue[_push_index]->Push(log);
		}

	private:
		CLogConnector								_connector;
		std::atomic<int32_t>						_try_connect_state = 0;
		CSocket*									_socket = nullptr;

		CMemPool<sGamelog>*							_pool = nullptr;
		std::atomic<int32_t>						_push_index = 0;
		std::atomic<int32_t>						_update_index = 0;
		std::vector<CConcurrentQueue<sGamelog*>*>	_list_queue;

		mrpc_action_log_cs							_packet_log;
		
	private:
		CGamelogManager(const CGamelogManager&) = delete;
		CGamelogManager& operator=(const CGamelogManager&) = delete;
		CGamelogManager(CGamelogManager&&) = delete;
		CGamelogManager& operator=(CGamelogManager&&) = delete;
	};
	#define gamelogManager CGamelogManager::getInstance()
	*/
}	// namespace mir3d

