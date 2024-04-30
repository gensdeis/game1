#pragma once

namespace mir3d
{
	enum class mrpce_server_type;

	class mrpcs_contract_sector;
	class mrpcs_occupationwar_war_map_info;
	class mrpcs_occupationwar_server_info_total;

	class GameConfig
	{
	public:
		struct sVersion
		{
			int32_t				svn_revision_number;
			std::string			version_number;
			std::string			table_version_number;
		};

		struct sServer
		{
			int32_t				world_gid;
			int32_t				gid;
			int32_t				index;
			int32_t				state;
			mrpce_server_type	type;			
			std::string			log_path;
			bool				table_local_load;
			int32_t				thread_count;
			int32_t				eventthread_count;
			bool				encryption;
			bool				chat_command;
			bool				ranking_all;
			int32_t				time_zone;
		};

		struct sGame
		{
			std::string			map;
			int32_t				game_sector_size;
			int32_t				indun_sector_size;
			std::string			language;
			int32_t				max_play_user;
			bool				version_check;
			std::string			version;
			bool				database_state_check;
		};

		struct sAddress
		{
			std::string			ip;
			uint16_t			port;
			std::string			url;
		};

		struct sNetwork
		{
			sAddress			listen;
			int32_t				max_session;
			int32_t				thread_count;
			int32_t				update_sec;
		};

		struct sActionLog
		{
			bool				create;
			bool				console;
			std::string			path;
			int32_t				max_file_size;
			std::string			prefix;
			int32_t				user_count_sec;
		};

		struct sDump
		{
			bool				create;
			std::string			path;
			int32_t				type;
		};

		struct sUpdater
		{
			int32_t				msec;
			int32_t				respawn_msec;
			int32_t				fsm_msec;
			int32_t				channel_msec;
			int32_t				autosave_sec;
		};

		struct sPoolInfo
		{
			std::string			name;
			int32_t				default_size;
			int32_t				create_size;
		};

		struct sCommunity
		{
			std::string			name;
			int32_t				thread_count;
			int32_t				run_msec;
		};
			
		struct sOccupationwarBaseInfo
		{
			bool											initialize = false;
			int64_t											occupationwar_uid = 0;
			int32_t											week_number = 0;

		public:
			void Reset(void)
			{
				initialize = false;
				occupationwar_uid = 0;
				week_number = 0;
			}
		};
		struct sOccupationwarScheduleInfo
		{
			bool											initialize = false;
			std::vector<int32_t>							list_datetime;

		public:
			void Reset(void)
			{
				initialize = false;
				list_datetime.clear();
			}
		};
		struct sOccupationwarServerInfo
		{
			int32_t											gid = 0;
			bool											is_start_war = false;
			bool											decide = false;
			bool											staking_fail = false;
		};
		struct sWorldOccupationwarServerInfo
		{			
			int64_t											occupationwar_uid = 0;
			int32_t											week_number = 0;
			std::mutex										mutex;
			std::vector<sOccupationwarServerInfo>			list_server;
		};

		struct sWorldContractGovernanceInfo
		{
			int32_t											gid = 0;
			bool											is_governance = false;
			int32_t											sector_id = 0;

		public:
			void Reset(void)
			{
				gid = 0;
				is_governance = false;
				sector_id = 0;
			}
		};
		struct sContractGovernanceInfo
		{
			bool											initialize = false;
			std::vector<sWorldContractGovernanceInfo>		list;

		public:
			void Reset(void)
			{
				initialize = false;
				list.clear();
			}
		};		
		struct sOccupationwarGuildSkill
		{
			bool											initialize = false;
			std::vector<int64_t>							list;

		public:
			void Reset(void)
			{
				initialize = false;
				list.clear();
			}
		};

		struct sOccupationwarInfo
		{
			sOccupationwarBaseInfo							base_info;
			sWorldOccupationwarServerInfo					occupationwar_info;
			sOccupationwarScheduleInfo						schedule_info;
			sContractGovernanceInfo							governance_info;		
			sOccupationwarGuildSkill						guild_skill;	// 2023.08.31 gogoblue74 캐릭터가 비곡점령전 문파 스킬이 셋팅 안되는 현상 때문에 최악의 경우 사용하기 위해
			int32_t											war_end_time = 0;	
			bool											is_start_war = false;
		};

	public:
		static bool Initialize(const std::string& file_path);
		static bool SetSVNRevision(int32_t revision);
		static sPoolInfo* GetPoolInfo(const std::string& name);
		static sCommunity* GetCommunityInfo(const std::string& name);
		static std::vector<std::string> GetCreateMap();

		static inline const int32_t Version_Svn_Revision_Number()
		{
			return _version_info.svn_revision_number;
		}

		static inline const std::string& Version_Version_Number()
		{
			return _version_info.version_number;
		}

		static inline const std::string& Version_Table_Version_Number()
		{
			return _version_info.table_version_number;
		}

		// server_info
		static inline const int32_t CreateWorldGid(int32_t gid)
		{
			return static_cast<int32_t>( (trunc(gid / 10.0) * 10) );
		}

		static inline const int32_t World_Gid()
		{
			return _server_info.world_gid;
		}

		static inline const int32_t Server_Gid()
		{
			return _server_info.gid;
		}		
		
		static inline const int32_t Server_Index()
		{
			return _server_info.index;
		}

		static inline const int32_t Server_State()
		{
			return _server_info.state;
		}

		static inline const mrpce_server_type Server_Type()
		{
			return _server_info.type;
		}

		static inline const std::string& Server_LogPath()
		{
			return _server_info.log_path;
		}

		static inline const bool Server_TableLocalLoad()
		{
			return _server_info.table_local_load;
		}

		static inline const int32_t Server_ThreadCount()
		{
			return _server_info.thread_count;
		}

		static inline const int32_t Server_EventThreadCount()
		{
			return _server_info.eventthread_count;
		}

		static inline const bool Server_Encryption()
		{
			return _server_info.encryption;
		}

		static inline const bool Server_ChatCommand()
		{
			return _server_info.chat_command;
		}

		static inline const bool Server_RankingAll()
		{
			return _server_info.ranking_all;
		}

//#ifdef _USE_GLOBAL_SERVICE
		// dhlee : config_time_zone 적용
		static inline const int32_t Server_TimeZone()
		{
			return _server_info.time_zone;
		}
//#endif	// _USE_GLOBAL_SERVICE
		// game_info
		static inline const int32_t Game_GameSectorSize()
		{
			return _game_info.game_sector_size;
		}

		static inline const int32_t Game_IndunSectorSize()
		{
			return _game_info.indun_sector_size;
		}
		
		static inline const std::string& Game_Language()
		{
			return _game_info.language;
		}

		static inline const int32_t Game_MaxPlayUser()
		{
			return _game_info.max_play_user;
		}

		static inline const bool Game_VersionCheck()
		{
			return _game_info.version_check;
		}

		static inline const std::string& Game_Version()
		{
			return _game_info.version;
		}

		static inline const bool Game_DatabaseStateCheck()
		{
			return _game_info.database_state_check;
		}

		// network_info
		static inline const std::string& Network_ListenIp()
		{
			return _network_info.listen.ip;
		}

		static inline const int32_t Network_ListenPort()
		{
			return _network_info.listen.port;
		}

		static inline const int32_t Network_MaxSession()
		{
			return _network_info.max_session;
		}

		static inline const int32_t Network_ThreadCount()
		{
			return _network_info.thread_count;
		}	

		// dump_info
		static inline const bool Dump_Create()
		{
			return _dump_info.create;
		}

		static inline const std::string& Dump_Path()
		{
			return _dump_info.path;
		}

		static inline const int Dump_Type()
		{
			return _dump_info.type;
		}

		// observer_info
		static inline const GameConfig::sAddress* Observer_Info()
		{
			return &_observer_info;
		}

		// updater
		static inline const int32_t Updater_MSec()
		{
			return _updater.msec;
		}

		static inline const int32_t Updater_RespawnMSec()
		{
			return _updater.respawn_msec;
		}

		static inline const int32_t Updater_FsmMSec()
		{
			return _updater.fsm_msec;
		}		

		static inline const int32_t Updater_ChannelMSec()
		{
			return _updater.channel_msec;
		}

		static inline const int32_t Updater_AutosaveSec()
		{
			return _updater.autosave_sec;
		}		

		// rpc_info
		static inline const std::string& Rpc_ListenIp()
		{
			return _rpc_info.listen.ip;				
		}

		static inline const uint16_t Rpc_ListenPort()
		{
			return _rpc_info.listen.port;
		}

		static inline const int32_t Rpc_MaxSession()
		{
			return _rpc_info.max_session;
		}

		static inline const int32_t Rpc_ThreadCount()
		{
			return _rpc_info.thread_count;
		}

		static inline const int32_t Rpc_UpdateSec()
		{
			return _rpc_info.update_sec;
		}

		static inline const bool GetServiceState()
		{
			return _service_state;
		}

		static inline void SetServiceState()
		{
			_service_state = true;
		}

		// 비곡점령전 기본 정보
		static inline const bool OccupationwarBaseInfoInit()
		{
			return _occupateionwar_info.base_info.initialize;
		}

		static inline const int64_t OccupationwarUid()
		{
			return _occupateionwar_info.base_info.occupationwar_uid;
		}

		static inline const int32_t OccupationwarWeekNumber()
		{
			return _occupateionwar_info.base_info.week_number;
		}

		static void OccupationwarBaseInfoSet(int64_t occupationwar_uid, int32_t week_number);


		// 비곡점령전 일정정보
		static const bool OccupationwarScheduleInfoInit();

		static void OccupationwarScheduleInfoSet(std::vector<int32_t>& list_datetime);

		// 비곡점령전 서버결정 정보
		static void OccupationwarDecideServerSet(const int64_t& occupationwar_uid, const int32_t& week_number, const int32_t& rank, const bool& staking_fail);

#ifdef _USE_GLOBAL_SERVICE
		// 흑철상자 입금 시간 체크
		static mpe_error IsOccupationwarDarksteelboxDepositPossibleTime(const int32_t& gid);
		// 흑철상자 출금 시간 체크
		static mpe_error IsOccupationwarDarksteelboxWithdrawPossibleTime(const int32_t& gid);

		static void WroldGameOccupationwarDecideServerSet(const int64_t& occupationwar_uid, const int32_t& week_number, std::vector<mrpcs_occupationwar_server_info_total>& list_decide);
		static bool IsOccupationwarMinStakingFailServer(const int32_t& gid);

		static void SetOccupationwarDecideInfo(const int32_t& gid, mpe_secretvalley_state state, bool decide);	

		static void SetOccupationwarPlayState(const mpe_secretvalley_state& state);
		static bool GetOccupationwarPlayState(void);

		static bool IsOccupationwarDecideServer(const int32_t& gid);

		static bool CanOccupationwarEnter(const int32_t& gid);

		static const bool OccupationwarContractInfoInfoInit();

		static void SetOccupationwarContractInfo(const int32_t& sector_id);
		static void WorldGameSetOccupationwarContractInfo(std::vector<mrpcs_contract_sector>& list);

		static bool IsOccupationwarGovernance(const int32_t& gid);

#else	// _USE_GLOBAL_SERVICE

		static void SetOccupationwarDecideInfo(mpe_secretvalley_state state);

#endif	// !_USE_GLOBAL_SERVICE

		static void SetGuildOccupationwarSkill(std::vector<int64_t>& list);
		static void SetOccupationwarGuildSkill_Id(const int32_t& id);
		static bool HasGuildOccupationwarSkill(const int64_t& guid);
		static int32_t GetOccupationwarGuildSkill(void);

		static void SetWarEndTime(int32_t time);
		static int32_t GetWarEndTime(void);

		static void ResetOccupationwarDecideInfo(void);

		static bool IsOccupationwarWarProgress(const int32_t& gid);

	private:
		static bool OpenConfingFile(const std::string& filename);
		static bool OpenConfingEtcFile(const std::string& filename);

	private:
		static bool							_initialize;
		static std::vector<sPoolInfo>		_list_pool;

		static sVersion						_version_info;
		static sServer						_server_info;
		static sGame						_game_info;
		static sNetwork						_network_info;
		// static sActionLog					_actionlog_info;
		static sAddress						_logserver_info;
		static sDump						_dump_info;
		static sAddress						_observer_info;
		static sUpdater						_updater;
		static sNetwork						_rpc_info;
		static std::vector<sCommunity>		_list_community;
		static bool							_service_state;
		static sOccupationwarInfo			_occupateionwar_info;

		static int32_t						_occupationwar_guild_skill_id;
	};

}	// namespace mir3d