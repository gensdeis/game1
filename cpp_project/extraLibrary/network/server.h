#pragma once

#include "./serialize/serialize_buffer_pool.h"
#include "asioThread.h"
#include "socket.h"
#include "packetContext.h"

namespace mir3d
{
	class CSocket;
	class CSession;

	typedef void(*PacketHookHandler)(packetContext*);
	typedef void(*SocketOpenedHandler)(CSocket* const);
	typedef void(*SocketConnectFailHandler)(CSocket* const);
	typedef void(*SocketClosedHandler)(CSocket* const);
	typedef void(*SessionOpenedHandler)(CSession* const, const bool&);
	typedef void(*SessionClosedHandler)(CSession* const);

	typedef std::shared_ptr<boost::asio::io_service> shared_ptr_io_service;

	class CServer
	{

	public:
		CServer() = delete;
		CServer(const std::string& name, const int32_t& max_socket_count, const int32_t& worker_count);
		virtual ~CServer();
						
	protected:		
		virtual void Initialize();
		virtual void Start(void);
		virtual void Destroy(void);

		void PacketHookHandlerRegister(PacketHookHandler handler)
		{
			_packetHookHandler = handler;
		}

		void SocketHandlerRegister(SocketOpenedHandler opened_handler, SocketConnectFailHandler failed_handler, SocketClosedHandler closed_handler)
		{
			_socketOpenedHandler = opened_handler;
			_socketConnectFailHandler = failed_handler;
			_socketClosedHandler = closed_handler;
		}

		void SessionHandlerRegister(SessionOpenedHandler opened_handler, SessionClosedHandler closed_handler)
		{
			_sessionOpenedHandler = opened_handler;
			_sessionClosedHandler = closed_handler;
		}

	public:
		void ConnectedSocket(const int32_t& socket_id);
		void DisconnectedSocket(const int32_t& socket_id);

		//void SendAll(const char* data, const uint16_t size);

		void ProcessPacketHook(packetContext* context)				{ if (nullptr != _packetHookHandler)		{ _packetHookHandler(context); } }
		void SocketOpened(CSocket* socket)							{ if (nullptr != _socketOpenedHandler)		{ _socketOpenedHandler(socket); } }
		void SocketConnectFail(CSocket* socket)						{ if (nullptr != _socketConnectFailHandler) { _socketConnectFailHandler(socket); } }
		void SocketClosed(CSocket* socket)							{ if (nullptr != _socketClosedHandler)		{ _socketClosedHandler(socket); } }
		void SessionOpened(CSession* session, bool reconnect)		{ if (nullptr != _sessionOpenedHandler)		{ _sessionOpenedHandler(session, reconnect); } }
		void SessionClosed(CSession* session)						{ if (nullptr != _sessionClosedHandler)		{ _sessionClosedHandler(session); } }

	public:
		void Send(const int32_t socket_id, std::shared_ptr<CSocketWriteBuffer>& data);

		void SendAll(std::shared_ptr<CSocketWriteBuffer>& data);

		template<typename T> void SendAll(const T& packet)
		{
			auto data = std::make_shared<CSocketWriteBuffer>();
			if (nullptr != data->buffer)
			{
				protocol::SerializeType(data->buffer, &packet);
#ifdef _USE_PACKET_SERIALIZE_CHECK
				if (data->buffer->IsError())
				{
					SERVER_LOG(eServerLogType::eWarning, "protocol::Serialize() return false, CServer::SendAll(), cmd : [%d], size : [%d]", data->buffer->GetSerializeCommand(), data->buffer->GetErrorSerializeSize());
				}
				else
#endif
				{
					SendAll(data);
				}
			}
		}

	public:
		CSession* GetSession(int64_t session_id);
		bool SetSession(CSession* session);
	
#ifdef _USE_NEW_NOT_ALLOW_PACKET
		void SetNotAllowPacketInfo(std::vector<sNotAllowPacket>& list);		
		void UpdateNotAllowPacket(std::vector<std::vector<sSocketNotAllowPacket>>& list);
		void SetUpdateNotAllowPacket(void);

	private:
		void InitNotAllowPacketInfo(bool initialize = false);
#endif
	protected:
		CSocket* GetSocket(int32_t& socket_id);
		
		// Web Daemon 추가로 필요
	public:
		int32_t GetSocketSize(void) { return static_cast<int32_t>(_queue_socket_id.Size(true)); }
		int32_t GetConnectedSocketSize(void)
		{
			std::lock_guard<std::mutex> lock(_mutex_socket);
			{
				return static_cast<int32_t>(_map_socket.size());
			}
		}
		int32_t GetWaitingSocketSize(void)
		{
			int32_t size = 0;
			auto curr_time = util::mirTime::GetTickMilliCount();
			for (auto socket : _list_socket)
			{
				if (nullptr == socket)
					continue;

				if (mir3d::CSocket::eSocketState::connected == socket->GetConnectedState() && nullptr == socket->GetSession())
				{
					if (false == socket->IsRpc())
						socket->GhostSocketCheck(curr_time);

					size++;
				}
			}
			return size;
		}

	protected:
		boost::asio::io_service& get_io_service(void)
		{
			boost::asio::io_service& io_service = *_list_io_service[_next_io_service % _worker_count];
			++_next_io_service;
			return io_service;
		}

		std::vector<shared_ptr_io_service>		_list_io_service;
		uint64_t								_next_io_service = 0;

		CAsioThread*							_worker_thread = nullptr;

	private:		
		std::string								_name;
		std::vector<CSocket*>					_list_socket;
		CConcurrentQueue<int32_t>				_queue_socket_id;
		
		std::mutex								_mutex_socket;
		std::mutex								_mutex_session;
		std::unordered_map<int32_t, CSocket*>	_map_socket;
		std::unordered_map<int64_t, CSession*>	_map_session;

		int32_t									_worker_count = 0;
		int32_t									_max_socket_count = 0;

		PacketHookHandler						_packetHookHandler = nullptr;
		SocketOpenedHandler						_socketOpenedHandler = nullptr;
		SocketConnectFailHandler				_socketConnectFailHandler = nullptr;
		SocketClosedHandler						_socketClosedHandler = nullptr;
		SessionOpenedHandler					_sessionOpenedHandler = nullptr;
		SessionClosedHandler					_sessionClosedHandler = nullptr;

#ifdef _USE_NEW_NOT_ALLOW_PACKET
		std::vector<std::vector<sNotAllowPacket*>>		_list_not_allow_packet;
		int32_t											_list_not_allow_packet_index = -1;
		bool											_is_not_allow_packet_check = false;
#endif 

	private:
		CServer(const CServer&) = delete;
		CServer& operator=(const CServer&) = delete;
		CServer(CServer&&) = delete;
		CServer& operator=(CServer&&) = delete;
	};

}	// namespace mir3d