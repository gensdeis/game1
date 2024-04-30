#include "stdafx.h"
#include "gamePacketWorker.h"
#include "networkManager.h"
#include "rpcManager.h"
#include <network/session.h>
#include <network/socket.h>
#include <network/packetContextPool.h>
#include <common/config.h>
#include "userManager.h"
#include <network/network.h>
#include <protocol/base_protocol.h>

namespace mir3d
{
	void CGamePacketWorker::Initialize(bool suspend)
	{
		CPacketWorker::Initialize(suspend);

		for (int32_t i = 0; i < _worker_count; i++)
		{
			_next_update_tick.push_back(util::mirTime::GetTickMilliCount());
			_next_fsm_tick.push_back(util::mirTime::GetTickMilliCount());
			_next_zone_create_or_delete_tick.push_back(util::mirTime::GetTickMilliCount());
			_process_interval.push_back(util::mirTime::GetTickMilliCount());
		}

		//_update_tick = 0;

		//_updater_fsm_msec = static_cast<int64_t>(GameConfig::Updater_FsmMSec() * 1000.f);
		_updater_fsm_msec = static_cast<int64_t>(GameConfig::Updater_FsmMSec());
	}

	void CGamePacketWorker::Start(void)
	{
		CPacketWorker::Start();
		//RegisterHandlers();
	}

	void CGamePacketWorker::Destroy(void)
	{
		CPacketWorker::Destroy();
	}

	bool CGamePacketWorker::Begin(void)
	{
		return true;
	}

	bool CGamePacketWorker::Run(int32_t thread_index)
	{
		uint64_t nowMSec = util::mirTime::GetTickMilliCount();

		uint64_t update_interval = 0;

		if (0 == thread_index)
		{
			if (_next_zone_create_or_delete_tick[thread_index] < nowMSec)
			{
				_next_zone_create_or_delete_tick[thread_index] = nowMSec + GameConfig::Updater_ChannelMSec();
			}

			if (_next_update_tick[thread_index] < nowMSec)
			{
				_next_update_tick[thread_index] = nowMSec + GameConfig::Updater_MSec();
			}
		}
		else
		{
			int8_t update_type = 0;

			if (_next_fsm_tick[thread_index] < nowMSec)
			{
				//_next_fsm_tick[thread_index] = nowMSec + (int64_t)(GameConfig::Updater_FsmMSec() * 1000.f);
				_next_fsm_tick[thread_index] = nowMSec + _updater_fsm_msec;

				update_type = 1 << 1;
			}

			if (_next_update_tick[thread_index] < nowMSec)
			{
				_next_update_tick[thread_index] = nowMSec + GameConfig::Updater_MSec();

				update_type = update_type | (1 << 2);
			}

			/*
			if (_next_zone_create_or_delete_tick[thread_index] < nowMSec)
			{
				_next_zone_create_or_delete_tick[thread_index] = nowMSec + GameConfig::Updater_ChannelMSec(); // 변경 하는게 좋을듯 (자주 할 필요 없음)

				update_type = update_type | (1 << 3);
			}
			*/

			if (mrpce_server_type::game == GameConfig::Server_Type() || mrpce_server_type::world_game == GameConfig::Server_Type())
			{
				auto check_time = util::mirTime::GetTickMilliCount();
				{
					check_time = util::mirTime::GetTickMilliCount() - check_time;
					if (100 < check_time)
					{
						SERVER_LOG(eServerLogType::eWarning, "Time Check ( 100 ) - CGamePacketWorker::Run() - zoneManager.AlwaysUpdate , Update Time : %lld, thread_index : %d", check_time, thread_index);
					}
				}
			}


			if (0 != update_type)
			{
				if (mrpce_server_type::game == GameConfig::Server_Type() || mrpce_server_type::world_game == GameConfig::Server_Type())
				{
					auto check_time = util::mirTime::GetTickMilliCount();

					{
						check_time = util::mirTime::GetTickMilliCount() - check_time;
						if (100 < check_time)
						{
							SERVER_LOG(eServerLogType::eWarning, "Time Check ( 100 ) - CGamePacketWorker::Run() - zoneManager.Update , Update Time : %lld, thread_index : %d", check_time, thread_index);
						}
					}
				}

				return true;
			}

			auto check_time = util::mirTime::GetTickMilliCount();

			{
				check_time = util::mirTime::GetTickMilliCount() - check_time;
				if (100 < check_time)
				{
					SERVER_LOG(eServerLogType::eWarning, "Time Check ( 100 ) - CGamePacketWorker::Run() - objectManager.Update , Update Time : %lld, thread_index : %d", check_time, thread_index);
				}
			}
		}

		//update delay
		update_interval = util::mirTime::GetTickMilliCount() - nowMSec;

		if (_process_interval[thread_index] < nowMSec)
		{
			SERVER_LOG(eServerLogType::eWarning, "CGamePacketWorker::Run() process interval is over!!!!!!!!!!");
		}

		_process_interval[thread_index] = nowMSec + 5000;



		// packet process
		{
			uint64_t packet_total_time = 0, game_total_time = 0, rpc_total_time = 0;
			packet_total_time = util::mirTime::GetTickMilliCount();
			packetContext* context = nullptr;
			int32_t game_packet_count = 0;
			int32_t rpc_packet_count = 0;
			std::map<int32_t, UPDATE_INFO> map_game_process_time_info;
			std::map<int32_t, UPDATE_INFO> map_rpc_process_time_info;

			SwitchIndex(thread_index);
			while (_list_packet[thread_index]->Pop(context))
			{
				if (false == context->socket->IsRpc())
				{
					auto user = userManager.Get(context->session_id);

					if (nullptr != user)
					{
						if (user->GetThreadTag() != thread_index)
						{
							SERVER_LOG(eServerLogType::eWarning, "thread diff thread_index : %d, Thread Tag : %d, cmd : %d", thread_index, user->GetThreadTag(), context->cmd);
						}
						else
						{
							uint64_t start_process_time = util::mirTime::GetTickMilliCount();

							packetProcess(user, context);

							uint64_t process_time = util::mirTime::GetTickMilliCount() - start_process_time;
							game_total_time = game_total_time + process_time;

							auto iter = map_game_process_time_info.find(context->cmd);
							if (iter == map_game_process_time_info.end())
							{
								UPDATE_INFO info;
								info.process_time += process_time;
								info.packet_count++;
								map_game_process_time_info.insert(std::make_pair(context->cmd, info));
							}
							else
							{
								iter->second.process_time += process_time;
								iter->second.packet_count++;
							}

							game_packet_count++;
						}
					}
					else
					{
						SERVER_LOG(eServerLogType::eWarning, "CGamePacketWorker::Run() not found user. session id : %lld", context->session_id);
					}
				}
				else
				{
					//auto rpc = rpcManager.GetRpc(context->socket);

					//if (nullptr != rpc)
					//{
						uint64_t start_process_time = util::mirTime::GetTickMilliCount();

						rpcPacketProcess(/*rpc,*/ context, thread_index);

						uint64_t process_time = util::mirTime::GetTickMilliCount() - start_process_time;
						rpc_total_time = rpc_total_time + process_time;

						auto iter = map_rpc_process_time_info.find(context->cmd);
						if (iter == map_rpc_process_time_info.end())
						{
							UPDATE_INFO info;
							info.process_time += process_time;
							info.packet_count++;
							map_rpc_process_time_info.insert(std::make_pair(context->cmd, info));
						}
						else
						{
							iter->second.process_time += process_time;
							iter->second.packet_count++;
						}

						rpc_packet_count++;
					/*}
					else
					{
						SERVER_LOG(eServerLogType::eWarning, "CGamePacketWorker::Run() not found rpc.";
					}*/
				}

				/*auto packet_all_done_time = util::mirTime::GetTickMilliCount() - context->pop_time;
				if (packet_all_done_time > 1000)
				{
					SERVER_LOG(eServerLogType::eWarning, "packet all done time is Too many thread_index : " << thread_index << " session id : " << context->session_id << " total time : " << packet_all_done_time << " cmd : " << context->cmd;
				}*/

				PacketContextPool::Push(context);
			}

			if (GameConfig::Updater_MSec() <= static_cast<int32_t>(util::mirTime::GetTickMilliCount() - nowMSec))
			{
				packet_total_time = util::mirTime::GetTickMilliCount() - packet_total_time;
				SERVER_LOG(eServerLogType::eWarning, "time over. thread_index : %d, size processed packet game count : %d, rpc count : %d, update total time : %lld, packet total time : %lld, game total time : %lld, rpc total time : %lld", 
																																				thread_index, game_packet_count, rpc_packet_count, update_interval, packet_total_time, game_total_time, rpc_total_time);

				if (map_game_process_time_info.size() > 0)
				{
					for (const auto& context : map_game_process_time_info)
					{
						SERVER_LOG(eServerLogType::eWarning, "game process cmd : %d, total time : %lld, count : %d", context.first, context.second.process_time, context.second.packet_count);
					}
				}
				if (map_rpc_process_time_info.size() > 0)
				{
					for (const auto& context : map_rpc_process_time_info)
					{
						SERVER_LOG(eServerLogType::eWarning, "rpc process cmd : %d, total time : %lld, count : %d", context.first, context.second.process_time, context.second.packet_count);
					}
				}
			}
		}

		if (0 == thread_index && NetworkConfig::GetUpdate_NotAllowCheck())
		{
			networkManager.UpdateNotAllowPacket();
		}

		return true;
	}

	bool CGamePacketWorker::End(void)
	{
		return true;
	}

	void CGamePacketWorker::packetProcess(CUser* user, packetContext* context)
	{
		auto iter = _map_packet_handler.find(context->cmd);
		if (_map_packet_handler.end() == iter)
		{
			// 등록된 메시지가 아니다
			SERVER_LOG(eServerLogType::eWarning, "packetProcess() unregistered pakcet, cmd : %d", context->cmd);
			return;
		}

		// check packet (contents onoff)

		try
		{
#if _DEBUG
			// SERVER_LOG(eServerLogType::eWarning, "CONTEXT => %d", context->cmd);
#endif
			// 메시지 핸들러를 실행
			// (this->*_map_packet_handler[context->cmd])(user, context->buffer, context->size);
			(this->*iter->second)(user, context->buffer, context->size);
		}
		catch (std::exception& e)
		{
			// 에러
			SERVER_LOG(eServerLogType::eWarning, "ERROR CGamePacketWorker::  ===  %s", e.what());
		}
	}

	void CGamePacketWorker::rpcPacketProcess(/*CRpc* sender, */packetContext* context, int index)
	{
		auto iter = _map_rpc_packet_handler.find(context->cmd);
		if (_map_rpc_packet_handler.end() == iter)
		{
			// 등록된 메시지가 아니다
			SERVER_LOG(eServerLogType::eWarning, "rpcPacketProcess() unregistered pakcet, cmd : %d", context->cmd);
			return;
		}

		try
		{
			(this->*iter->second)(context->socket, /*sender, */context->buffer, context->size);
		}
		catch (std::exception& e)
		{
			// 에러
			SERVER_LOG(eServerLogType::eWarning, "ERROR CGamePacketWorker::rpcPacketProcess === %s, $$$ cmd : %d", e.what(), context->cmd);
		}
	}
}	// namespace mir3d

