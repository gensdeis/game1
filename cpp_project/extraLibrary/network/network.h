#pragma once

#include "packetContextPool.h"
#include "sessionPool.h"
#include "sessionWorker.h"
#include "socketBuffer.h"
#include "networkConfig.h"

#ifdef _TP_USAGE
#include <concurrent_unordered_map.h>
#endif

namespace mir3d
{
#ifdef _TP_USAGE	
	using namespace concurrency;
#endif
	class CSocket;
	class CSession;

	class Network
	{
	public:
		static bool Initialize(const std::string& filename, const int32_t& network_worker_count);

		static void Initialize_heartbeat_pakcet(void);

		static void Destroy(void);

		
#ifdef _TP_USAGE
		static void ExecutionCountInc();

		static void PrintThreadExecutionCount();

		static void PrintProcessorExecutionCount();

		static void PrintThreadContextSwitchCount();
#endif

		static void SocketWriteCountInc();

		static void SocketWriteCallBackCountInc();

		static void PrintDiffWriteAndCallback(bool print);

		static std::shared_ptr<CSocketWriteBuffer> GetHeartbeatPacket(void);

	private:
		static bool					_initialize;
		static CSessionWorker*		_sessionWorker;
		
#ifdef _TP_USAGE
		
		static concurrent_unordered_map< std::thread::id, int>* _map_execution_count;
		static concurrent_unordered_map< int, int>* _map_processor_execution_count;
		static concurrent_unordered_map< std::thread::id, int>* _map_thread_matching_processor;
		static concurrent_unordered_map< std::thread::id, int>* _map_thread_context_switch;
#endif
		static std::atomic<int32_t>								_write_count;
		static std::atomic<int32_t>								_write_callback_count;
		static std::shared_ptr<CSocketWriteBuffer>				_heartbeat_cs_packet_buffer;		
	};

}	// namespace mir3d