#pragma once

#include "./serialize/serialize_buffer.h"
#include "./serialize/serialize_buffer_pool.h"
#include "networkConfig.h"

#ifdef _DEBUG
#ifdef _WINDOWS
#include <common/call_stack.h>
#endif
#endif

namespace mir3d
{
	struct read_buffer
	{
	public:
		read_buffer() {}

		~read_buffer()
		{
			SAFE_DELETE_ARRAY(buffer);
		}

		void Initialize_buffer(int32_t buffer_size)
		{
			buffer = new char[buffer_size];
			_size = buffer_size;
			_buffer_size = buffer_size;
			_initialize = true;
		}

		bool IsInitializeBuffer(void)
		{
			return _initialize;
		}

		int32_t size(void)
		{
			return _size;
		}

		void set_size(size_t& size)
		{
			_size = static_cast<int32_t>(size);
		}

		void reset()
		{
			_size = _buffer_size;
		}

	public:		
		char*	buffer = nullptr;		

	private:
		int32_t	_size = 0;
		int32_t	_buffer_size = 0;
		bool    _initialize = false;
	};


	class ReadBufferPool
	{
	public:
		static void Initialize(const NetworkConfig::sPoolInfo* info, bool initialize_buffer = true);
		static void Destroy(void);

	public:
		static read_buffer* Pop(void);
		static void	Push(read_buffer* item);
		static read_buffer* PopRpc(void);
		static void	PushRpc(read_buffer* item);

	private:
		static CMemPool<read_buffer>* _pool;
		static CMemPool<read_buffer>* _pool_rpc;
	};

	class SocketReadBuffer
	{
	public:
		SocketReadBuffer() = default;
		~SocketReadBuffer() = default;

	public:
		void Initialize(size_t alloc_size)
		{
			if (nullptr == _buffer && 0 != alloc_size)
			{
				_max_buffer_size = alloc_size;

				_buffer = new uint8_t[alloc_size + alloc_size];

				_buffer_extend = &_buffer[alloc_size];

				_initialize_buffer = true;
			}
		}

		bool InitializeBuffer(void)
		{
			return _initialize_buffer;
		}

		void Release(void)
		{
			_begin_pos = 0;
			_end_pos = 0;
			_data_size = 0;
		}

		void Destroy(void)
		{
			SAFE_DELETE(_buffer);
		}

		size_t GetMaxBufferSize(void)
		{
			return _max_buffer_size;
		}

	public:
		size_t			GetReceiveBuffer(uint8_t*& buffer);
		int32_t			GetPacket(bool& force_close, uint8_t*& packet_buffer);
		bool			RecvComplete(size_t bytes_transferred);

		bool			PushRecvComplete(uint8_t* buffer, size_t bytes_transferred);

		int32_t			GetBuffer(uint8_t*& buffer);
		uint8_t*		GetFirstBuffer() { return &_buffer[0]; }

		size_t			GetDataSize() { return _data_size; }

	private:
		inline int32_t	GetPacketLength(void)
		{
			int32_t length = (int32_t)_max_buffer_size - (int32_t)_begin_pos;

			switch (length)
			{
			case 0:
				length = 0;
				break;
			case 1:
				length = MAKE_INT32(_buffer[_begin_pos], _buffer[0], _buffer[1], _buffer[2]); 
				break;
			case 2:
				length = MAKE_INT32(_buffer[_begin_pos], _buffer[_begin_pos + 1], _buffer[0], _buffer[1]); 
				break;
			case 3:
				length = MAKE_INT32(_buffer[_begin_pos], _buffer[_begin_pos + 1], _buffer[_begin_pos + 2], _buffer[0]);
				break;
			default:
				length = MAKE_INT32(_buffer[_begin_pos], _buffer[_begin_pos + 1], _buffer[_begin_pos + 2], _buffer[_begin_pos + 3]);
			}

			return length;
		}

	private:
		size_t		_begin_pos = 0;				// packet 시작 위치
		size_t		_end_pos = 0;				// 마지막 위치
		size_t		_data_size = 0;				// 현재 버퍼 안에 있는 데이터 크기
		size_t		_max_buffer_size = 0;		// 할당된 버퍼의 크기
				
		uint8_t*	_buffer = nullptr;
		uint8_t*	_buffer_extend = nullptr;

		bool		_initialize_buffer = false;

	private:
		SocketReadBuffer(const SocketReadBuffer&) = delete;
		SocketReadBuffer& operator=(const SocketReadBuffer&) = delete;
		SocketReadBuffer(SocketReadBuffer&&) = delete;
		SocketReadBuffer& operator=(SocketReadBuffer&&) = delete;
	};

	class SocketReadBufferPool
	{
	public:
		static void Initialize(const NetworkConfig::sPoolInfo* info, bool initialize_buffer = true);
		static void Destroy(void);

	public:
		static SocketReadBuffer* Pop(void);
		static void	Push(SocketReadBuffer* item);
		static SocketReadBuffer* PopRpc(void);
		static void	PushRpc(SocketReadBuffer* item);

	private:
		static CMemPool<SocketReadBuffer>* _pool;
		static CMemPool<SocketReadBuffer>* _pool_rpc;
	};
	
	class CSocketWriteBuffer
	{
	public:
		CSocketWriteBuffer()
		{
			buffer = mir3d::serializeBufferPool.Pop();
			buffer->Reset();
		}

		~CSocketWriteBuffer()
		{
			mir3d::serializeBufferPool.Push(buffer);
		}

	public:
		protocol::SerializeBufferNative* buffer;

	private:
		CSocketWriteBuffer(const CSocketWriteBuffer&) = delete;
		CSocketWriteBuffer& operator=(const CSocketWriteBuffer&) = delete;
		CSocketWriteBuffer(CSocketWriteBuffer&&) = delete;
		CSocketWriteBuffer& operator=(CSocketWriteBuffer&&) = delete;
	};

}	// namespace mir3d


