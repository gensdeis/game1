#include "stdafx.h"
#include "gamelogManager.h"
#include <common/config.h>
#include "rpcManager.h"

#define MAX_LOGQUEUE	2
#define MAX_LOG_BUNDLE	20

namespace mir3d
{
	CGamelogManager::CGamelogManager(const std::string& name, int32_t update_time) : CThread(update_time, name)
	{
		_pool = new CMemPool<sGamelog>(4096, 32, name, OnMempoolAllocLogger);

		_list_queue.reserve(MAX_LOGQUEUE + 1);

		for (int32_t i = 0; i <= MAX_LOGQUEUE; i++)
		{
			_list_queue.push_back(new CConcurrentQueue<sGamelog*>());
		}

		_push_index = 0;
		_update_index = MAX_LOGQUEUE - 1;
	}

	void CGamelogManager::Initialize(bool suspend)
	{
		CThread::Initialize(1, suspend);
	}

	void CGamelogManager::Start(void)
	{
		CThread::Start();
	}

	void CGamelogManager::Destroy(void)
	{
		CThread::Destroy();

		for (auto item : _list_queue)
		{
			SAFE_DELETE(item);
		}

		SAFE_DELETE(_pool);
	}

	bool CGamelogManager::Begin(void)
	{
		return true;
	}

	bool CGamelogManager::Run(int32_t index)
	{
		if (MAX_LOGQUEUE == _push_index) _push_index.exchange(0);
		else _push_index.fetch_add(1);

		if (MAX_LOGQUEUE == _update_index) _update_index.exchange(0);
		else _update_index.fetch_add(1);

		if (false == _list_queue[_update_index]->IsEmpty(true))
		{
			bool loop_flag = false;
			int32_t count = 0;
			sGamelog* item = nullptr;

			int32_t buffer_max_size = ACTION_LOG_TEXT_SIZE * ACTION_LOG_BUNDLE_MAX;

			while (true)
			{
				loop_flag = _list_queue[_update_index]->Pop(item);

				if (loop_flag)
				{
					count++;

					if (_game_log_buffer.size + item->size >= buffer_max_size)
					{
						count = ACTION_LOG_BUNDLE_MAX;

						_list_queue[_update_index]->Push(item);	// 다음에 처리 하기 위해 다시 반환.
					}
					else 
					{
						_packet_log.list_type.push_back(item->type);
						_packet_log.list_size.push_back(item->size);
						// _packet_log.log.append(item->text, item->size);
						std::memcpy(&_game_log_buffer.buffer[_game_log_buffer.size], item->text, item->size);
						_game_log_buffer.size += item->size;

						Push(item);
					}					
				}

				if (ACTION_LOG_BUNDLE_MAX == count || false == loop_flag)
				{
					if (0 < count)
					{
						auto data = std::make_shared<CSocketWriteBuffer>();
						if (nullptr != data->buffer)
						{
							_packet_log.log.append(_game_log_buffer.buffer, _game_log_buffer.size);

							protocol::SerializeType(data->buffer, &_packet_log);

#ifdef _USE_PACKET_SERIALIZE_CHECK
							if (data->buffer->IsError())
							{
								SERVER_LOG(eServerLogType::eWarning, "protocol::Serialize() return false, CGamelogManager::Run(), cmd : [%d], size : [%d]", data->buffer->GetSerializeCommand(), data->buffer->GetErrorSerializeSize());
							}
							else
#endif
							{
								auto rpc = rpcManager.GetRpc(mrpce_server_type::logreceive);
								if (nullptr != rpc && rpc->GetSession())
								{
									rpc->Send(data);
								}
							}
						}

						count = 0;

						_packet_log.list_type.clear();
						_packet_log.list_size.clear();
						_packet_log.log.clear();
						_game_log_buffer.reset();
					}

					if (false == loop_flag)
					{
						break;
					}
				}
			}
		}

		return true;
	}

	bool CGamelogManager::End(void)
	{
		return true;
	}
}	// namespace mir3d