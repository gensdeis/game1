#pragma once

namespace mir3d
{
	class CUser;
	class CSession;

	class CUserManager : public CSingleton<CUserManager>
	{
	public:
		CUserManager() = default;
		virtual ~CUserManager() = default;
		
		bool Initialize(int32_t defaultSize, int32_t createSize);

	public:
		void CreateUser(CSession* session);
		void DestroyUser(CSession* session);
		void ReconnectUser(CSession* session);

		int32_t GetUserCount() { return static_cast<int32_t>(_map.Size()); }

	public:
		CUser*		Get(int64_t session_id);

	private:
		CMemPool<CUser>*    				_pool = nullptr;
		CConcurrentMap<int64_t, CUser*>		_map;

	private:
		CUserManager(const CUserManager&) = delete;
		CUserManager& operator=(const CUserManager&) = delete;
		CUserManager(CUserManager&&) = delete;
		CUserManager& operator=(CUserManager&&) = delete;
	};
	#define userManager CUserManager::getInstance()

}	// namespace mir3d