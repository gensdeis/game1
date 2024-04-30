#pragma once

#include "packetContext.h"
#include "socket.h"
#include "worker.h"

namespace mir3d
{
	class CPacketWorker : public CWorker
	{
	public:
		CPacketWorker() = delete;
		CPacketWorker(int32_t worker_count, int32_t wait_msec) : CWorker("PacketWorker", worker_count, wait_msec) {}
		virtual ~CPacketWorker() {}

	protected:
		virtual void Initialize(bool suspend = true)
		{
			for (int32_t i = 0; i < _worker_count; i++)
			{	
				_list_packet_switch.push_back(std::vector<CConcurrentQueue<packetContext*>*>());
				_list_packet_index_switch.push_back(new std::atomic<int32_t>(0));
				_list_packet.push_back(new CConcurrentQueue<packetContext*>());
				_list_packet_lockfree.push_back(new CConcurrentQueueLockFree<packetContext*>());

				for (int32_t j = 0; j < 2; j++)
					_list_packet_switch[i].push_back(new CConcurrentQueue<packetContext*>());
			}

			CThread::Initialize(_worker_count, suspend);
		}

		virtual void Destroy(void)
		{
			CThread::Destroy();

			for (auto item : _list_packet_switch)
			{
				for (auto item2 : item)
				{
					delete item2;
				}
			}

			for (auto item : _list_packet_index_switch)
			{
				delete item;
			}
		}
		
	public:
		/*
		void PushSwitchRpc(packetContext* context)
		{
			auto thread_index = context->session_id % _worker_count;			
			_list_packet_switch[thread_index][_list_packet_index_switch[thread_index]->load()]->Push(context);
		}
		*/
		inline void PushSwitch(packetContext* context)
		{
			auto thread_tag = context->session_id % _worker_count;
			_list_packet_switch[thread_tag][_list_packet_index_switch[thread_tag]->load()]->Push(context);
		}

		void PushSwitch(int32_t thread_tag, packetContext* context)
		{
			if (thread_tag >= _worker_count)
			{
				SERVER_LOG(eServerLogType::eWarning, "Packet TagId is Invalid!!  cmd : %u, tag : %u", context->cmd, thread_tag);
				return;
			}				

			_list_packet_switch[thread_tag][_list_packet_index_switch[thread_tag]->load()]->Push(context);
		}
		/*
		inline void Push(int32_t thread_index, packetContext* context)
		{
			if (thread_index >= _worker_count)
			{
				SERVER_LOG(eServerLogType::eWarning, "Packet TagId is Invalid!!  cmd : " << context->cmd << "tag : " << thread_index;
				return;
			}

			_list_packet_lockfree[thread_index]->Push(context);
		}

		inline void Push(packetContext* context)
		{
			auto index = context->session_id % _worker_count;
			_list_packet_lockfree[index]->Push(context);
		}
		*/
		void SwitchIndex(int32_t thread_index)
		{
			if (thread_index >= _worker_count)
			{
				SERVER_LOG(eServerLogType::eWarning, "Packet TagId is Invalid!!  tag : %d", thread_index);
				return;
			}

			if (false ==  _list_packet[thread_index]->IsEmpty(false))
				return;

			std::atomic<int32_t> index = _list_packet_index_switch[thread_index]->load();

			_list_packet_index_switch[thread_index]->exchange(index ^ 1);
			
			//_list_packet[thread_index] = _list_packet_switch[thread_index][index];// std::move(_list_packet_switch[thread_index][index]);			
			_list_packet[thread_index] = std::move(_list_packet_switch[thread_index][index]);
		}

		// socket receive에서 임시로 저장하는 공간, 처리에 시간제한이 있기 때문에 한곳에 모아 놔야 한다.
	protected:
		std::vector<CConcurrentQueue<packetContext*>*>				_list_packet;
		std::vector<std::vector<CConcurrentQueue<packetContext*>*>>	_list_packet_switch;		// 각 스레드별 패킷 임시 저장소
		std::vector<std::atomic<int32_t>*>							_list_packet_index_switch;
				
		std::vector<CConcurrentQueueLockFree<packetContext*>*>		_list_packet_lockfree;

	private:
		CPacketWorker(const CPacketWorker&) = delete;
		CPacketWorker& operator=(const CPacketWorker&) = delete;
		CPacketWorker(CPacketWorker&&) = delete;
		CPacketWorker& operator=(CPacketWorker&&) = delete;
	};

	class CPacketWorkerEx : public CWorker
	{
	public:
		CPacketWorkerEx() = delete;
		CPacketWorkerEx(int32_t worker_count, int32_t wait_msec) : CWorker("PacketWorkerEx", worker_count, wait_msec) {}
		virtual ~CPacketWorkerEx() {}

	protected:
		virtual void Initialize(bool suspend = true)
		{
			for (int32_t i = 0; i < _worker_count; i++)
			{		
				_list_packet.push_back(std::vector<std::queue<packetContext*>*>());
				_list_mutex_packet.push_back(new std::mutex());
			
				for (int32_t j = 0; j < 2; j++)
				{
					_list_packet[i].push_back(new std::queue<packetContext*>());
				}
			}			

			CThread::Initialize(_worker_count, suspend);
		}

		virtual void Destroy(void)
		{
			CThread::Destroy();

			for (auto iter : _list_packet)
			{
				for (auto item : iter)
				{
					delete item;
				}
			}

			for (auto iter : _list_mutex_packet)
			{
				delete iter;
			}
		}

	public:
		void Push(packetContext* context)
		{
			auto index = context->session_id % _worker_count;
			std::lock_guard<std::mutex> lock(*_list_mutex_packet[index]);
			{
				_list_packet[index][0]->push(context);
			}			
		}

		void Push(const int32_t& index, packetContext* context)
		{
			std::lock_guard<std::mutex> lock(*_list_mutex_packet[index]);
			{
				_list_packet[index][0]->push(context);
			}
		}
		
		void PushRandom(packetContext* context)
		{
			auto index = _list_index++ % _worker_count;
			std::lock_guard<std::mutex> lock(*_list_mutex_packet[index]);
			{
				_list_packet[index][0]->push(context);
			}
		}

		packetContext* Pop(const int32_t& index)
		{
			packetContext* context = nullptr;
			if (false == _list_packet[index][1]->empty())
			{
				context = _list_packet[index][1]->front();
				_list_packet[index][1]->pop();
			}
			return context;
		}

		bool PacketWorkerSwap(const int32_t& index)
		{
			std::lock_guard<std::mutex> lock(*_list_mutex_packet[index]);
			if (false == _list_packet[index][0]->empty())
			{
				auto temp = _list_packet[index][1];
				_list_packet[index][1] = _list_packet[index][0];
				_list_packet[index][0] = temp;
				return true;
			}
			return false;
		}

	protected:
		std::vector<std::vector<std::queue<packetContext*>*>>		_list_packet;
		std::vector<std::mutex*>									_list_mutex_packet;

		uint64_t													_list_index = 0;

	private:
		CPacketWorkerEx(const CPacketWorkerEx&) = delete;
		CPacketWorkerEx& operator=(const CPacketWorkerEx&) = delete;
		CPacketWorkerEx(CPacketWorkerEx&&) = delete;
		CPacketWorkerEx& operator=(CPacketWorkerEx&&) = delete;
	};

}	// namespace mir3d

