#pragma once

#include <network/session.h>

namespace mir3d
{
	class CSession;
	class mrpcs_redis_rpcinfo;

	class CRpc
	{
	public:
		CRpc();
		CRpc(const mrpcs_redis_rpcinfo& info);
		~CRpc();

	public:
		enum class eStep
		{
			ready,
			connected
		};
				
	public:
		const std::string& GetRemoteInfo(void);
		void ForceDisconnect(const char* call_func);

		inline bool GetSession(void)
		{
			return (nullptr != _session) ? true : false;
		}

		inline CSession* GetSessionPointer(void)
		{
			return _session;
		}

		inline void SetSession(CSession* session)
		{
			_session = session;
		}

		inline void SetGid(const int32_t& gid)
		{
			_gid = gid;
		}
		inline int32_t GetGid(void)
		{
			return _gid;
		}

		inline void SetType(const mrpce_server_type& type)
		{
			_type = type;
		}
		inline mrpce_server_type GetType(void)
		{
			return _type;
		}

		inline void SetIndex(const int32_t& index)
		{
			_index = index;
		}
		inline int32_t GetIndex(void)
		{
			return _index;
		}

		inline const std::string& GetFullTag(void)
		{
			return _full_tag;
		}

#ifdef _NOT_USE
		inline void SetUse(void)
		{
			_use_count.fetch_add(1);
		}

		inline bool GetUseState(void)
		{
			return 0 < _use_count ? true : false;
		}
#endif

		inline std::string GetIp(void)
		{
			return _ip;
		}

		inline uint16_t GetPort(void)
		{
			return _port;
		}

		inline int64_t GetHeartbeatUid(void)
		{
			return _heartbeat_uid;
		}

		inline int32_t GetHeartbeatCheckCount(void)
		{
			return _heartbeat_check_count;
		}
		
		inline void SetHeartbeatCheckCount(const bool& reset)
		{
			if (reset)
			{
				_heartbeat_check_count = 0;
			}
			else
			{
				_heartbeat_check_count++;
			}
		}

	private:
		CSession*							_session = nullptr;
		eStep								_step = eStep::ready;

		mrpce_server_type					_type = mrpce_server_type::none;
		int32_t								_index = 0;
		std::string							_ip;
		uint16_t							_port = 0;
		std::string							_full_tag;
		std::string							_temp_string;
#ifdef _NOT_USE
		std::atomic<int32_t>				_use_count;
#endif
		int32_t								_gid = 0;

		int64_t								_heartbeat_uid = 0;
		int32_t								_heartbeat_check_count = 0;

	public:
		void Send(std::shared_ptr<CSocketWriteBuffer>& data);
		template<typename T> void Send(const T& packet)
		{
			if (nullptr != _session)
			{
				_session->Send(packet);
			}
		}

	private:
		CRpc(const CRpc&) = delete;
		CRpc& operator=(const CRpc&) = delete;
		CRpc(CRpc&&) = delete;
		CRpc& operator=(CRpc&&) = delete;
	};

}	// namespace mir3d

