#include "stdafx_net.h"
#include "network.h"
#include <protocol/mp_heartbeat_check.h>

namespace mir3d
{
	bool				 Network::_initialize = false;
	CSessionWorker*		 Network::_sessionWorker = nullptr;
#ifdef _TP_USAGE
	concurrent_unordered_map< std::thread::id, int>* Network::_map_execution_count = nullptr;
	concurrent_unordered_map< int, int>* Network::_map_processor_execution_count = nullptr;
	concurrent_unordered_map< std::thread::id, int>* Network::_map_thread_matching_processor = nullptr;
	concurrent_unordered_map< std::thread::id, int>* Network::_map_thread_context_switch = nullptr;
#endif
	std::atomic<int32_t>					Network::_write_count = 0;
	std::atomic<int32_t>					Network::_write_callback_count = 0;
	std::shared_ptr<CSocketWriteBuffer>		Network::_heartbeat_cs_packet_buffer;


	bool Network::Initialize(const std::string& filename, const int32_t& network_worker_count)
	{
		if (false == _initialize)
		{
			_initialize = true;

			if (false == NetworkConfig::Initialize(filename))
			{
				return false;
			}

			{
				auto poolinfo = NetworkConfig::GetPoolInfo("packet_context");
				if (nullptr == poolinfo) return false;
				PacketContextPool::Initialize(poolinfo, network_worker_count);
			}
			{
				auto poolinfo = NetworkConfig::GetPoolInfo("seesion");
				if (nullptr == poolinfo) return false;
				SessionPool::Initialize(poolinfo);
			}
			{
				auto poolinfo = NetworkConfig::GetPoolInfo("session_wait");
				if (nullptr == poolinfo) return false;
				SessionWaitPool::Initialize(poolinfo);
			}
			{
				auto poolinfo = NetworkConfig::GetPoolInfo("socket_buffer");
				if (nullptr == poolinfo) return false;
				ReadBufferPool::Initialize(poolinfo);
			}
			{
				auto poolinfo = NetworkConfig::GetPoolInfo("socket_buffer");
				if (nullptr == poolinfo) return false;
				SocketReadBufferPool::Initialize(poolinfo);
			}

			_sessionWorker = new CSessionWorker(1, 1);
			_sessionWorker->Initialize();
			_sessionWorker->Start();
#ifdef _TP_USAGE
			_map_execution_count = new concurrent_unordered_map< std::thread::id, int>();
			_map_processor_execution_count = new concurrent_unordered_map< int, int>();
			_map_thread_matching_processor = new concurrent_unordered_map< std::thread::id, int>();
			_map_thread_context_switch = new concurrent_unordered_map< std::thread::id, int>();
#endif
			_write_count = 0;
			_write_callback_count = 0;
		}

		return true;
	}

	void Network::Initialize_heartbeat_pakcet(void)
	{
		// _heartbeat_cs_packet_buffer
		{
			_heartbeat_cs_packet_buffer = std::make_shared<CSocketWriteBuffer>();
			if (_heartbeat_cs_packet_buffer->buffer)
			{
				mp_heartbeat_check_cs packet;
				packet.temp = 0;
				protocol::SerializeType(_heartbeat_cs_packet_buffer->buffer, &packet);
			}
		}
	}

	void Network::Destroy(void)
	{
		if (nullptr != _sessionWorker)
		{
			_sessionWorker->Destroy();

			delete _sessionWorker;
			_sessionWorker = nullptr;
		}

		PacketContextPool::Destroy();
		SessionPool::Destroy();
		ReadBufferPool::Destroy();
	}


#ifdef _TP_USAGE
	void Network::ExecutionCountInc()
	{
		std::thread::id curr_thread_id = std::this_thread::get_id();
		auto find = _map_execution_count->find(curr_thread_id);
		if (_map_execution_count->end() != find)
		{
			find->second++;
		}
		else
		{
			_map_execution_count->insert(std::pair<std::thread::id, int>(curr_thread_id, 1));
		}

		int processor_id = GetCurrentProcessorNumber();
		auto processor_find = _map_processor_execution_count->find(processor_id);
		if (_map_processor_execution_count->end() != processor_find)
		{
			processor_find->second++;
		}
		else
		{
			_map_processor_execution_count->insert(std::pair<int, int>(processor_id, 1));
		}

		auto tp_find = _map_thread_matching_processor->find(curr_thread_id);
		if (_map_thread_matching_processor->end() != tp_find)
		{
			if (processor_id != tp_find->second)
			{
				tp_find->second = processor_id;
				auto find = _map_thread_context_switch->find(curr_thread_id);
				if (_map_thread_context_switch->end() != find)
				{
					find->second++;
				}
				else
				{
					_map_thread_context_switch->insert(std::pair<std::thread::id, int>(curr_thread_id, 1));
				}
			}
		}
		else
		{
			_map_thread_matching_processor->insert(std::pair<std::thread::id, int>(curr_thread_id, processor_id));
		}
	}

	void Network::PrintThreadExecutionCount()
	{
		for (auto item : *_map_execution_count)
		{
			auto thread_id = item.first;
			auto exec_count = item.second;
			SERVER_LOG(eServerLogType::eDebug, "Thread id : " << thread_id << " exe_count : " << exec_count;
		}
	}

	void Network::PrintProcessorExecutionCount()
	{
		for (auto item : *_map_processor_execution_count)
		{
			auto processor_id = item.first;
			auto exec_count = item.second;
			SERVER_LOG(eServerLogType::eDebug, "Processor id : " << processor_id << " exe_count : " << exec_count;
		}
	}

	void Network::PrintThreadContextSwitchCount()
	{
		for (auto item : *_map_thread_context_switch)
		{
			auto thread_id = item.first;
			auto switch_count = item.second;
			SERVER_LOG(eServerLogType::eDebug, "Thread id : " << thread_id << " switch_count : " << switch_count;
		}
	}
#endif

	void Network::SocketWriteCountInc()
	{
		_write_count++;
	}

	void Network::SocketWriteCallBackCountInc()
	{
		_write_callback_count++;
	}

	void Network::PrintDiffWriteAndCallback(bool print)
	{
		int32_t diff_count = _write_count - _write_callback_count;
		if (true == print || 10000 == diff_count)
		{
			int32_t write_count = _write_count;
			int32_t write_callback_count = _write_callback_count;
			SERVER_LOG(eServerLogType::eDebug, "Write : %d, CallBack : %d, Diff Count : %d", write_count, write_callback_count, diff_count);
		}
	}

	std::shared_ptr<CSocketWriteBuffer> Network::GetHeartbeatPacket(void)
	{
		return _heartbeat_cs_packet_buffer;
	}

}	// namespace mir3d