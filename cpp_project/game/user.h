#pragma once

#include <network/session.h>

namespace mir3d
{
	class CCharacter;

	class CUser
	{
	friend class CCharacter;

	public:
		CUser() = default;
		virtual ~CUser() = default;

	public:
		void		Release(void);

	public:
		void		SetSession(CSession* session)		{ _session = session; }
		CSession*	GetSession(void)					{ return _session; }
		int64_t		GetSessionId(void)					{ if (nullptr != _session) { return _session->GetID(); } return 0; };

		void		SetConnectState(bool state)			{ _connect_state = state; }
		bool		GetConnectState(void)				{ return _connect_state; }

		void		SetThreadTag(int32_t tag_index);
		void		InitThreadTag(void) { _thread_tag = 0; };
		int			GetThreadTag(void) { return _thread_tag; }

		void		ForceDisconnect(const char* call_func);

		template<typename T>
		void Send(const T& packet)
		{
			if (nullptr != _session)
			{
				_session->Send(packet);
			}
		}

		inline std::string GetRemoteInfo() { if (nullptr == _session) return ""; return _session->GetRemoteInfo(); }

	private:
		CSession*			_session;
		CCharacter*			_character = nullptr;
		bool				_connect_state = false;
		int					_thread_tag = 0;

	public:
		int64_t				_cuid = 0;
	private:
		CUser(const CUser&) = delete;
		CUser& operator=(const CUser&) = delete;
		CUser(CUser&&) = delete;
		CUser& operator=(CUser&&) = delete;
	};

}	// namespace mir3d