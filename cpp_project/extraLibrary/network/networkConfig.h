#pragma once

namespace mir3d
{
	class mrpc_update_not_allow_packet_cs;

	class NetworkConfig
	{
	public:
		struct sPoolInfo
		{
			std::string name;
			int32_t default_size;
			int32_t create_size;
			int32_t reserve_value;
		};

		struct sHeartbeat
		{
			bool check_heartbeat;
			int32_t check_time;
			int32_t interval;
			int32_t check_count;
			bool speed_hack_check;
			int32_t speed_hack_check_count;
		};

#ifdef _USE_NEW_NOT_ALLOW_PACKET
		struct sPakcetNotAllow
		{
			int32_t cmd;
			int32_t limit_time;

		};
		struct sPakcetNotAllowCheck
		{
			bool packet_check;
			std::vector<sPakcetNotAllow> list;
		};
#endif

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
		struct sDuplicationLogin
		{
			bool check_duplication_login;
			int32_t interval;
		};
#endif

		struct sRpcHeartbeat
		{
			bool use;
			int32_t keep_alive_interval;
			int32_t retry_limit_count;
			int64_t latency_check_time;
		};

	public:
		static bool Initialize(const std::string& filename);
		static void Destroy(void);

		static sPoolInfo* GetPoolInfo(const std::string& name);

		static int32_t		GetSocketReadPool(void)						{ return _socket_readpool; }
		static bool			GetHeartbeat_Check(void)					{ return _heartbeat_info.check_heartbeat; }
		static int32_t		GetHeartbeat_CheckTime(void)				{ return _heartbeat_info.check_time; }
		static int32_t		GetHeartbeat_Interval(void)					{ return _heartbeat_info.interval; }
		static int32_t		GetHeartbeat_CheckCount(void)				{ return _heartbeat_info.check_count; }
		
		static int32_t		GetReconnectTryCount(void)					{ return _reconnect_try_count; }

		static void			SetNetworkLogState(bool flag)				{ _is_show_networklog = flag;}
		static bool			GetNetworkLogState(void)					{ return _is_show_networklog; }

		static void			SetServerName(const std::string& name)		{ _server_name.assign(name); }
		static std::string&	GetServerName(void)							{ return _server_name; }

		static inline bool		GetHeartbeat_SpeedHackCheck(void)		{return _heartbeat_info.speed_hack_check;}
		static inline int32_t	GetHeartbeat_SpeedHackCheckCount(void)	{ return _heartbeat_info.speed_hack_check_count; }

#ifdef _USE_NEW_NOT_ALLOW_PACKET
		static inline bool	GetUpdate_NotAllowCheck(void)				{ return _update_packet_not_allow_check; }
		static void			SetUpdate_NotAllowCheck(void)				{ _update_packet_not_allow_check = false; }

		static bool			GetGame_PacketNotAllowCheck(void)			{ return _game_packet_not_allow_check.packet_check; }
		static bool			GetCommunity_PacketNotAllowCheck(void)		{ return _community_packet_not_allow_check.packet_check; }
		static const std::vector<sPakcetNotAllow>& GetGame_PacketNotAllowCheckInfo(void)
		{
			return _game_packet_not_allow_check.list;
		}
		static const std::vector<sPakcetNotAllow>& GetCommunity_PacketNotAllowCheckInfo(void)
		{
			return _community_packet_not_allow_check.list;
		}
#endif

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
		static inline bool	GetUseNotAllowDuplicationLogin(void)			{ return _use_not_allow_duplication_login.check_duplication_login; }
		static void			SetUseNotAllowDuplicationLogin(bool state)		{ _use_not_allow_duplication_login.check_duplication_login = state; }

		static int32_t		GetDuplicationLoginInterval(void)				{ return _use_not_allow_duplication_login.interval; }
#endif

		static bool			GetRpcSocketHeartbeat(void)						{ return _rpc_heartbeat_info.use; }
		static int32_t		GetRpcSocketHeartbeatKeepAliveInterval(void)	{ return _rpc_heartbeat_info.keep_alive_interval; }
		static int32_t		GetRpcSocketHeartbeatRetryLimitCount(void)		{ return _rpc_heartbeat_info.retry_limit_count; }
		static int64_t		GetRpcSocketHeartbeatLatencyCheckTime(void)		{ return _rpc_heartbeat_info.latency_check_time; }

	private:
		static bool OpenFile(const std::string& filename);
		static void WriteFile();

	public:
		static void UpdateSpeedHackCheck(bool check_state, int32_t check_count);
		static void UpdateNotAllowPacket(mir3d::mrpc_update_not_allow_packet_cs& packet);

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
		static void UpdateUseNotAllowDuplicationLogin(const bool& check_state);
#endif

	private:
		static bool							_initialize;
		static std::vector<sPoolInfo>*		_list_pool;
		static int32_t						_socket_readpool;
		static sHeartbeat					_heartbeat_info;
		static int32_t						_reconnect_try_count;

		static bool							_is_show_networklog;

		static std::string					_server_name;
		static std::string					_config_filename;
		static Json::Value					_config_json_root;

#ifdef _USE_NEW_NOT_ALLOW_PACKET
		static sPakcetNotAllowCheck			_game_packet_not_allow_check;
		static sPakcetNotAllowCheck			_community_packet_not_allow_check;

		static bool							_update_packet_not_allow_check;
#endif

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
		static sDuplicationLogin			_use_not_allow_duplication_login;
#endif

		static sRpcHeartbeat				_rpc_heartbeat_info;
	};

}	// namespace mir3d