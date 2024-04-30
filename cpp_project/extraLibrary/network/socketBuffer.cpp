#include "stdafx_net.h"
#include "socketBuffer.h"
#include <common/config.h>
#include <common/serverlogManager.h>

namespace mir3d
{
	CMemPool<read_buffer>* ReadBufferPool::_pool = nullptr;
	CMemPool<read_buffer>* ReadBufferPool::_pool_rpc = nullptr;
	CMemPool<SocketReadBuffer>* SocketReadBufferPool::_pool = nullptr;
	CMemPool<SocketReadBuffer>* SocketReadBufferPool::_pool_rpc = nullptr;


	//------------------------------------------------------------------------------------------
	// ReadBufferPool
	//------------------------------------------------------------------------------------------
	void ReadBufferPool::Initialize(const NetworkConfig::sPoolInfo* info, bool initialize_buffer)
	{
		_pool = new CMemPool<read_buffer>(info->default_size, info->create_size, info->name, OnMempoolAllocLogger);
		_pool_rpc = new CMemPool<read_buffer>(32, 4, "ReadBufferPool_RPC", OnMempoolAllocLogger);

		if (initialize_buffer)
		{
			for (int32_t i = 0; i < info->default_size; i++)
			{
				auto item = _pool->Pop();
				if (false == item->IsInitializeBuffer())
				{
					item->Initialize_buffer(MAX_CLIENT_READ_BUFFER_SIZE);
				}
				_pool->Push(item);
			}
			for (int32_t i = 0; i < 32; i++)
			{
				auto item = _pool_rpc->Pop();
				if (false == item->IsInitializeBuffer())
				{
					item->Initialize_buffer(MAX_SOCKET_BUFFER_SIZE);
				}
				_pool_rpc->Push(item);
			}
		}
	}

	void ReadBufferPool::Destroy(void)
	{
		SAFE_DELETE(_pool);
		SAFE_DELETE(_pool_rpc);
	}

	read_buffer* ReadBufferPool::Pop(void)
	{
		auto item = _pool->Pop();

		if (false == item->IsInitializeBuffer())
		{
			item->Initialize_buffer(MAX_CLIENT_READ_BUFFER_SIZE);
		}

		return item;
	}

	void ReadBufferPool::Push(read_buffer* item)
	{
		_pool->Push(item);
	}

	read_buffer* ReadBufferPool::PopRpc(void)
	{
		auto item = _pool_rpc->Pop();

		if (false == item->IsInitializeBuffer())
		{
			item->Initialize_buffer(MAX_SOCKET_BUFFER_SIZE);
		}

		return item;
	}

	void ReadBufferPool::PushRpc(read_buffer* item)
	{
		_pool_rpc->Push(item);
	}


	//------------------------------------------------------------------------------------------
	// SocketReadBuffer
	//------------------------------------------------------------------------------------------
	size_t SocketReadBuffer::GetReceiveBuffer(uint8_t*& buffer)
	{
		if (_data_size == _max_buffer_size)
		{
			return 0;
		}

		// 여기서 준만큼만 받기 때문에
		if (_end_pos == _max_buffer_size)
		{
			_end_pos = 0;
		}

		buffer = &_buffer[_end_pos];

		if (_end_pos >= _begin_pos)
		{	
			return std::min(_max_buffer_size, (_max_buffer_size - _end_pos));
		}
		else
		{
			return std::min(_max_buffer_size, (_begin_pos - _end_pos));
		}

		return 0;
	}

	// 완전한 패킷을 꺼낸다.
	int32_t SocketReadBuffer::GetPacket(bool& force_close, uint8_t*& packet_buffer)
	{
		packet_buffer = nullptr;

		if (PACKET_HEADER_SIZE > _data_size)
			return 0;

		size_t packet_size = static_cast<size_t>(GetPacketLength());

		if (packet_size > _data_size)
		{
			return 0;
		}
		else if (_max_buffer_size < packet_size)
		{
			force_close = true;

			SERVER_LOG(eServerLogType::eDebug, "SocketReadBuffer::GetPacket() - big size packet : %d", packet_size);
			return 0;
		}

		if (_max_buffer_size - _begin_pos > packet_size)
		{
			packet_buffer = &_buffer[_begin_pos];
			_begin_pos += packet_size;
		}
		// 데이터가 앞/뒤 에 나눠져 있다.
		else
		{
			size_t remain = _max_buffer_size - _begin_pos;

			if (0 < remain)
			{
				memcpy(_buffer_extend, &_buffer[_begin_pos], remain);
				memcpy(&_buffer_extend[remain], _buffer, packet_size - remain);

				packet_buffer = _buffer_extend;
				_begin_pos = packet_size - remain;
			}
			else
			{
				return 0;
			}
		}

		_data_size -= packet_size;

		return static_cast<int32_t>(packet_size);
	}

	bool SocketReadBuffer::PushRecvComplete(uint8_t* buffer, size_t bytes_transferred)
	{
		// buffer overflow
		if (_max_buffer_size < _data_size + bytes_transferred)
		{
			SERVER_LOG(eServerLogType::eWarning, "SocketReadBuffer::PushRecvComplete() buffer overflow, current data size : %d, send size : %d, max buffer size : %d", _data_size, bytes_transferred, _max_buffer_size);
			return false;
		}

		// 데이터가 앞/뒤 에 나눠진다.
		if (_max_buffer_size < _end_pos + bytes_transferred)
		{
			auto part = _max_buffer_size - _end_pos;
		
			if (0 < part)
			{
				memcpy(&_buffer[_end_pos], buffer, part);
				_end_pos = bytes_transferred - part;
				memcpy(_buffer, &buffer[part], _end_pos);
			}
			else
			{
				memcpy(_buffer, buffer, bytes_transferred);
				_end_pos = bytes_transferred;
			}

		}
		else
		{
			//한번에 복사
			memcpy(&_buffer[_end_pos], buffer, bytes_transferred);
			_end_pos += bytes_transferred;

		}

		_data_size += bytes_transferred;

		if (_end_pos >= _max_buffer_size)
			_end_pos = 0;

		return true;
	}

	int32_t SocketReadBuffer::GetBuffer(uint8_t*& buffer)
	{
		int32_t length = (int32_t)_max_buffer_size - (int32_t)_begin_pos;

		buffer = &_buffer[_begin_pos];

		return length;
	}

	bool SocketReadBuffer::RecvComplete(size_t bytes_transferred)
	{
		_end_pos += bytes_transferred;
		_data_size += bytes_transferred;

		if (PACKET_HEADER_SIZE <= _data_size)
		{
			if (_data_size >= static_cast<size_t>(GetPacketLength()))
			{
				return true;
			}
		}

		return false;
	}

	//------------------------------------------------------------------------------------------
	// SocketReadBufferPool
	//------------------------------------------------------------------------------------------
	void SocketReadBufferPool::Initialize(const NetworkConfig::sPoolInfo* info, bool initialize_buffer)
	{
		_pool = new CMemPool<SocketReadBuffer>(info->default_size, info->create_size, info->name, OnMempoolAllocLogger);
		_pool_rpc = new CMemPool<SocketReadBuffer>(32, 4, "SocketReadBufferPool_RPC", OnMempoolAllocLogger);

		if (initialize_buffer)
		{
			for (int32_t i = 0; i < info->default_size; i++)
			{
				auto item = _pool->Pop();

				if (false == item->InitializeBuffer())
				{
					item->Initialize(MAX_CLIENT_SOCKET_READ_BUFFER_SIZE);
				}
				_pool->Push(item);
			}
			for (int32_t i = 0; i < 32; i++)
			{
				auto item = _pool_rpc->Pop();
				if (false == item->InitializeBuffer())
				{
					item->Initialize(MAX_SOCKET_READ_BUFFER_SIZE);
				}
				_pool_rpc->Push(item);
			}
		}
	}

	void SocketReadBufferPool::Destroy(void)
	{
		SAFE_DELETE(_pool);

		SAFE_DELETE(_pool_rpc);
	}

	SocketReadBuffer* SocketReadBufferPool::Pop(void)
	{
		auto item = _pool->Pop();

		if (false == item->InitializeBuffer())
		{
			item->Initialize(MAX_CLIENT_SOCKET_READ_BUFFER_SIZE);
		}

		return item;
	}

	void SocketReadBufferPool::Push(SocketReadBuffer* item)
	{
		item->Release();
		_pool->Push(item);
	}

	SocketReadBuffer* SocketReadBufferPool::PopRpc(void)
	{
		auto item = _pool_rpc->Pop();

		if (false == item->InitializeBuffer())
		{
			item->Initialize(MAX_SOCKET_READ_BUFFER_SIZE);
		}

		return item;
	}

	void SocketReadBufferPool::PushRpc(SocketReadBuffer* item)
	{
		item->Release();
		_pool_rpc->Push(item);
	}
}	// namespace mir3d