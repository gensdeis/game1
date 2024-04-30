#pragma once

#include <network/acceptor.h>
#include <network/connector.h>
#include <common/config.h>
#include <common/serverlogManager.h>
#include <protocol/mrpc_update_redis_serverinfo.h>
#include <protocol/mrpc_channel_update_zoneinfo.h>
#include <protocol/mrpc_occupationwar_gameserver_log.h>
#include "rpc.h"

namespace mir3d
{
	class CSession;

	class CRpcAcceptor : public CAcceptor
	{
	public:
		CRpcAcceptor() = delete;
		CRpcAcceptor(unsigned short port, int32_t session_count, int32_t worker_count) : CAcceptor("rpcManager.RpcAcceptor", port, session_count, worker_count) {}
		virtual ~CRpcAcceptor() {}

	public:
		virtual void Initialize(void);
		virtual void Start(void)		{ CAcceptor::Start(); }
		virtual void Destroy(void)		{ CAcceptor::Destroy(); }

	protected:
		virtual bool Begin(void)		{ return true;}
		virtual bool End(void)			{ return true;}

	private:
		CRpcAcceptor(const CRpcAcceptor&) = delete;
		CRpcAcceptor& operator=(const CRpcAcceptor&) = delete;
		CRpcAcceptor(CRpcAcceptor&&) = delete;
		CRpcAcceptor& operator=(CRpcAcceptor&&) = delete;
	};

	void OnGameRpcAcceptorHookHandler(packetContext* context);
	void OnGateRpcAcceptorHookHandler(packetContext* context);
	void OnCommunityRpcAcceptorHookHandler(packetContext* context);

	void OnRpcAcceptorSocketOpened(CSocket* socket);
	void OnRpcAcceptorSocketClosed(CSocket* socket);
	void OnRpcAcceptorSessionOpened(CSession* session, const bool& reconnect);
	void OnRpcAcceptorSessionClosed(CSession* session);
	
	class CRpcConnector : public CConnector
	{
	public:
		CRpcConnector() = delete;
		CRpcConnector(const std::string& name, int32_t session_count, int32_t worker_count) : CConnector(name, session_count, worker_count) {}
		virtual ~CRpcConnector() {}

	public:
		virtual void Initialize(void);
		virtual void Start(void)		{ CConnector::Start(); }
		virtual void Destroy(void)		{ CConnector::Destroy(); }

	protected:
		virtual bool Begin(void)		{ return true; }
		virtual bool End(void)			{ return true; }
		
	private:
		CRpcConnector(const CRpcConnector&) = delete;
		CRpcConnector& operator=(const CRpcConnector&) = delete;
		CRpcConnector(CRpcConnector&&) = delete;
		CRpcConnector& operator=(CRpcConnector&&) = delete;
	};

	void OnGameRpcConnectorHookHandler(packetContext* context);
	void OnGateRpcConnectorHookHandler(packetContext* context);
	void OnCommunityRpcConnectorHookHandler(packetContext* context);

	void OnRpcConnectorSocketOpened(CSocket* socket);
	void OnRpcConnectorSocketConnectFaild(CSocket* socket);
	void OnRpcConnectorSocketClosed(CSocket* socket);
	void OnRpcConnectorSessionOpened(CSession* session, const bool& reconnect);
	void OnRpcConnectorSessionClosed(CSession* session);
	

	class CRpcManager : public CThread, public CSingleton<CRpcManager>
	{
	public:
		CRpcManager() = delete;
		CRpcManager(unsigned short port, int32_t socket_count, int32_t worker_count, int32_t rpc_update_time);
		virtual ~CRpcManager() {}

	public:
		virtual void Initialize(bool suspend = true);
		virtual void Start(void);
		virtual void Destroy(void);

	protected:
		virtual bool Begin(void);
		virtual bool Run(int32_t index);
		virtual bool End(void);

	public:
		inline std::string& GetFulltag(void)		{ return _rpc_fulltag_string; }
		inline bool ConnectedObserver(void)			{ return _observer_connected; }
		inline bool CommunityZoneInitialize(void)	{ return _community_zone_initialize; }
		inline void ResetChannelZoneList(void)		{}
		
	public:		
		CRpc* GetRpc(CSocket* socket);
		CRpc* GetRpc(const mrpce_server_type& server_type);
		CRpc* GetRpc(const mrpce_server_type& server_type, const int32_t& index);
		CRpc* GetRpc(const int32_t& gid, const mrpce_server_type& server_type, const int32_t& index);
		void  GetAllRpc(const mrpce_server_type& server_type, std::vector<CRpc*>& list_server);
		CRpc* GetRpcByGid(const mrpce_server_type& server_type, const int32_t& gid);
		CRpc* GetRpcWorld(const mrpce_server_type& server_type, const int32_t& gid);		

		void ConnectRpcServer(mrpcs_redis_rpcinfo rpcinfo);
		void ConnectRpcServer(std::vector<mrpcs_redis_rpcinfo>& list);

		void UpdateConnectorRpcInfo(CSocket* const socket, const std::string& name, const int32_t& gid, const mrpce_server_type& type, const int32_t& index);

		void Connected(CSocket* socket);
		void ConnectFailed(CSocket* socket);
		void Disconnected(CSocket* socket, bool acceptor = false);

		void ConnectedSession(CSession* session, bool acceptor = false);
		void DisconnectedSession(CSession* session);

		void GetRpcList(std::string& strRpcList);

		template<typename T> bool RpcSend(const mrpce_server_type& type, const T& packet)
		{
			auto rpc = GetRpc(type);
			if (nullptr != rpc && rpc->GetSession())
			{
				rpc->Send(packet);
			}
			return false;
		}

		template<typename T> void RpcSendAll(const mrpce_server_type& type, const T& packet)
		{
			if (0 != _map_maintag.size())
			{
				auto data = std::make_shared<CSocketWriteBuffer>();
				if (nullptr != data->buffer)
				{
					protocol::SerializeType(data->buffer, &packet);
#ifdef _USE_PACKET_SERIALIZE_CHECK
					if (data->buffer->IsError())
					{
						SERVER_LOG(eServerLogType::eWarning, "protocol::Serialize() return false, CRpcManager::RpcSendAll(), cmd : [%d], size : [%d]", data->buffer->GetSerializeCommand(), data->buffer->GetErrorSerializeSize());
						return;
					}
#endif
					std::lock_guard<std::mutex> lock(_mutex_maintag);
					{
						auto list = _map_maintag.find(type);

						if (_map_maintag.end() != list)
						{
							for (size_t i = 0; i < static_cast<int32_t>(list->second.size()); i++)
							{
								if (nullptr != list->second[i] && list->second[i]->GetSession())
								{
									list->second[i]->Send(data);
								}
							}
						}
					}
				}
			}
		}

		// 2023.06.06 gogoblue74
		// 채팅서버를 통한 system message 전송
		// mentor / system 두 가지로 분류된다.
		// mentor는 받는 캐릭터가 어디에 있는지 몰라서 둘다 전송
		// system은 해당 communinty에 전송하고 gate에서 전체에 전송한다.
		template<typename T> void SendCommunityMessage(const T& packet, const bool& sendall = false)
		{
			if (0 != _map_maintag.size())
			{
				auto data = std::make_shared<CSocketWriteBuffer>();
				if (nullptr != data->buffer)
				{
					protocol::SerializeType(data->buffer, &packet);
#ifdef _USE_PACKET_SERIALIZE_CHECK
					if (data->buffer->IsError())
					{
						SERVER_LOG(eServerLogType::eWarning, "protocol::Serialize() return false, CRpcManager::SendCommunityMessage(), cmd : [%d], size : [%d]", data->buffer->GetSerializeCommand(), data->buffer->GetErrorSerializeSize());
						return;
					}
#endif
					if (true == sendall)
					{
						{
							auto rpc = GetRpc(mrpce_server_type::community);
							if (nullptr != rpc && true == rpc->GetSession())
							{
								rpc->Send(data);
							}
						}
						{
							auto rpc = GetRpc(mrpce_server_type::world_community);
							if (nullptr != rpc && true == rpc->GetSession())
							{
								rpc->Send(data);
							}
						}
					}
					else
					{
						auto rpc = GetRpc((mir3d::mrpce_server_type::world_game == mir3d::GameConfig::Server_Type()) ? mrpce_server_type::world_community : mrpce_server_type::community);
						if (nullptr != rpc && true == rpc->GetSession())
						{
							rpc->Send(data);
						}
					}
				}
			}
		}

		template<typename T> void SendCommunityGateMessage(const T& packet, const int32_t& gid)
		{
			if (0 != _map_maintag.size())
			{
				auto data = std::make_shared<CSocketWriteBuffer>();
				if (nullptr != data->buffer)
				{
					protocol::SerializeType(data->buffer, &packet);
#ifdef _USE_PACKET_SERIALIZE_CHECK
					if (data->buffer->IsError())
					{
						SERVER_LOG(eServerLogType::eWarning, "protocol::Serialize() return false, CRpcManager::SendCommunityGateMessage(), cmd : [%d], size : [%d]", data->buffer->GetSerializeCommand(), data->buffer->GetErrorSerializeSize());
						return;
					}
#endif

					if (mrpce_server_type::community == mir3d::GameConfig::Server_Type())
					{
						auto rpc = GetRpc(mrpce_server_type::gate);
						if (nullptr != rpc && false != rpc->GetSession())
						{
							rpc->Send(data);
						}
					}
					else if (mrpce_server_type::world_community == mir3d::GameConfig::Server_Type())
					{
						if (0 < gid)
						{
							auto rpc = GetRpcByGid(mrpce_server_type::gate, gid);
							if (nullptr != rpc && false != rpc->GetSession())
							{
								rpc->Send(data);
							}
						}
						else
						{
							std::lock_guard<std::mutex> lock(_mutex_maintag);
							{
								auto list = _map_maintag.find(mrpce_server_type::gate);

								if (_map_maintag.end() != list)
								{
									for (size_t i = 0; i < list->second.size(); i++)
									{
										if (nullptr != list->second[i] && list->second[i]->GetSession())
										{
											list->second[i]->Send(data);
										}
									}
								}
							}
						}
					}
				}
			}
		}

		void SendTableLoad(int index);
		void SetCommunityZoneInitialize(void);
		void SetServerInitilizeComplete(bool complete);
		bool GetServerInitilizeComplete();
		void SetServerInfoComplete(bool complete);
		bool GetServerInfoComplete();
		void SetSendChannelUpdate(bool send);
		bool GetSendChannelUpdate();
		void SetChannelInitializeComplete(bool send);
		bool GetSendChannelInitializeComplete();
		void SetReconnectComplete(bool send);
		bool GetReconnectComplete();
		void SendChannelCreateInfo(bool is_first = true);
		void SendChannelUpdateInfo(int64_t channel_uid, int16_t user_count);

		void PrintRpcInfo(void);
		void OnRpcHeartbeatResponse(const int64_t& uid, const int64_t& param);
		void SendOccupationwarGameserverLog(mrpc_occupationwar_gameserver_log_sc& log);

	private:
		void PostConnect(const mrpcs_redis_rpcinfo& rpcinfo);
		void Update(void);
		void UpdateRpcInfo(CRpc* const observer, const uint64_t& current_time);
		void UpdateContentsInfo(const uint64_t& current_time);
		void UpdateRpcHeartbeat(const uint64_t& current_time);

	private:
		CRpcAcceptor					_acceptor;
		CRpcConnector					_connector;
		bool							_observer_connected = false;
		bool							_community_zone_initialize = false;
		mrpc_update_redis_serverinfo_cs	_update_redis_serverinfo_cs;
		mrpcs_redis_rpcinfo				_observer_connect_info;
		
		mrpc_channel_update_zoneinfo_cs	_channel_update_zoneinfo_cs;		//게임매니저에게 존 상태을 알려준다.

		std::string						_rpc_fulltag_string;

		uint64_t						_update_rpcinfo_time = 0;
		uint64_t						_update_occupationwar_info = 0;
		uint64_t						_update_send_channel_create_info = 0;
		uint64_t						_update_rpc_heartbeat_time = 0;

	private:
		std::mutex			_mutex_send_channel_update;
		bool				_send_channel_update = false;

		std::mutex			_mutex_init;
		bool				_server_initilize_complete = false;
		std::mutex			_mutex_server_info;
		bool				_server_info_complete = false;

		std::mutex			_mutex_channel_initialize_complate;
		bool				_channel_initialize_complate = false;

		std::mutex			_mutex_reconnect_complete;
		bool				_reconnect_complete = false;

		std::mutex													_mutex_tryconnet;
		std::unordered_map<std::string, CRpc*>						_map_tryconnet;
		
		std::mutex													_mutex_maintag;
		std::unordered_map<mrpce_server_type, std::vector<CRpc*>>	_map_maintag;

		std::mutex													_mutex_fulltag;
		std::unordered_map<std::string, CRpc*>						_map_fulltag;

		std::mutex													_mutex_socket;
		std::unordered_map<CSocket*, CRpc*>							_map_socket;

		std::mutex													_mutex_socket_heartbeat;
		std::unordered_map<int64_t, CRpc*>							_map_socket_heartbeat;

	private:
		CRpcManager(const CRpcManager&) = delete;
		CRpcManager& operator=(const CRpcManager&) = delete;
		CRpcManager(CRpcManager&&) = delete;
		CRpcManager& operator=(CRpcManager&&) = delete;
	};
	#define rpcManager CRpcManager::getInstance()

}	// namespace mir3d

