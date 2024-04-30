#pragma once

#include "user.h"
#include "rpc.h"

namespace mir3d
{
	struct UPDATE_INFO
	{
		uint64_t	process_time;
		int32_t		packet_count;
		UPDATE_INFO()
		{
			process_time = 0;
			packet_count = 0;
		}
	};

	class CGamePacketWorker : public CPacketWorker, public CSingleton<CGamePacketWorker>
	{
	public:
		CGamePacketWorker() = delete;
		CGamePacketWorker(int32_t worker_count/*int32_t logic_count, int32_t rpc_count*/) : CPacketWorker(worker_count, 1) {}
		virtual ~CGamePacketWorker() {}

	public:
		//void		RegisterHandlers();
		void		packetProcess(CUser* user, packetContext* context);
		void		rpcPacketProcess(/*CRpc* sender,*/ packetContext* context, int index);

	public:
		virtual void Initialize(bool suspend = true);
		virtual void Start(void);
		virtual void Destroy(void);

	private:
		virtual bool Begin(void);
		virtual bool Run(int32_t index);
		virtual bool End(void);

	private:
		typedef void (CGamePacketWorker::* funcPacketHandler)(CUser*, const char*, const int32_t&);
		std::unordered_map<uint16_t, funcPacketHandler> _map_packet_handler;

		typedef void (CGamePacketWorker::* funcRpcPacketHandler)(CSocket*,/*CRpc*,*/ const char*, const int32_t&);
		std::unordered_map<uint16_t, funcRpcPacketHandler> _map_rpc_packet_handler;

		template <typename T>
		inline mpe_error prepare_packet_process(CUser* const user, const char* pData, const int32_t& dataLength, T& packet, CCharacter** character)
		{
			if (pData == nullptr || dataLength < 0)
			{
				return mpe_error::invalid_packet;
			}

			if (false == mir3d::protocol::UnSerializeNative((uint8_t*)pData, dataLength, &packet))
			{
				return mpe_error::packet_error;
			}

			return mpe_error::error_none;
		}

	private:		
		std::vector<uint64_t> _next_update_tick;
		std::vector<uint64_t> _next_fsm_tick;
		std::vector<uint64_t> _next_zone_create_or_delete_tick;
		int64_t _updater_fsm_msec = 0;		

		std::vector<uint64_t> _process_interval;
	
	private:
		CGamePacketWorker(const CGamePacketWorker&) = delete;
		CGamePacketWorker& operator=(const CGamePacketWorker&) = delete;
		CGamePacketWorker(CGamePacketWorker&&) = delete;
		CGamePacketWorker& operator=(CGamePacketWorker&&) = delete;
	};
	#define gamePacketWorker CGamePacketWorker::getInstance()

}	// namespace mir3d

