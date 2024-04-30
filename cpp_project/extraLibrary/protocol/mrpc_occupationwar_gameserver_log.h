#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_contents_onoff_info.h"
#include "struct/mrpcs_occupationwar_base_info.h"
#include "struct/mps_occupationwar_schedule_info.h"
#include "struct/mrpcs_occupationwar_server_info_total.h"
#include "struct/mrpcs_occupationwar_schedule_noti.h"
#include "struct/mrpcs_occupationwar_game_info.h"

namespace mir3d
{
	class mrpc_occupationwar_gameserver_log_cs : public RpcPacket 
	{

	public:
		mrpc_occupationwar_gameserver_log_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::occupationwar_gameserver_log_cs, tag)
		{
		}
		mrpc_occupationwar_gameserver_log_cs() : RpcPacket(mpe_rpc_cmd::occupationwar_gameserver_log_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_occupationwar_gameserver_log_sc : public RpcPacket 
	{
	public:
		int32_t gid{};
	public:
		int32_t index{};
	public:
		int32_t time_zone{};
	private:
		bool flag_contents = false;
		mrpcs_contents_onoff_info contents;
		mrpcs_contents_onoff_info* p_contents = nullptr;
	public:
		bool has_contents() const
		{
			return flag_contents;
		}
		mrpcs_contents_onoff_info* alloc_contents()
		{
			flag_contents = true;
			return &contents;
		}
		const mrpcs_contents_onoff_info* get_contents() const
		{
			if (true == flag_contents)
			{
				if (nullptr == p_contents)
				{
					return &contents;
				}
				return p_contents;
			}
			return nullptr;
		}
		void set_contents(mrpcs_contents_onoff_info* in_contents)
		{
			if (nullptr == p_contents)
			{
				p_contents = in_contents;
				flag_contents = true;
			}
		}
	private:
		bool flag_base_info = false;
		mrpcs_occupationwar_base_info base_info;
		mrpcs_occupationwar_base_info* p_base_info = nullptr;
	public:
		bool has_base_info() const
		{
			return flag_base_info;
		}
		mrpcs_occupationwar_base_info* alloc_base_info()
		{
			flag_base_info = true;
			return &base_info;
		}
		const mrpcs_occupationwar_base_info* get_base_info() const
		{
			if (true == flag_base_info)
			{
				if (nullptr == p_base_info)
				{
					return &base_info;
				}
				return p_base_info;
			}
			return nullptr;
		}
		void set_base_info(mrpcs_occupationwar_base_info* in_base_info)
		{
			if (nullptr == p_base_info)
			{
				p_base_info = in_base_info;
				flag_base_info = true;
			}
		}
	private:
		bool flag_schedule = false;
		mps_occupationwar_schedule_info schedule;
		mps_occupationwar_schedule_info* p_schedule = nullptr;
	public:
		bool has_schedule() const
		{
			return flag_schedule;
		}
		mps_occupationwar_schedule_info* alloc_schedule()
		{
			flag_schedule = true;
			return &schedule;
		}
		const mps_occupationwar_schedule_info* get_schedule() const
		{
			if (true == flag_schedule)
			{
				if (nullptr == p_schedule)
				{
					return &schedule;
				}
				return p_schedule;
			}
			return nullptr;
		}
		void set_schedule(mps_occupationwar_schedule_info* in_schedule)
		{
			if (nullptr == p_schedule)
			{
				p_schedule = in_schedule;
				flag_schedule = true;
			}
		}
	public:
		std::vector<mrpcs_occupationwar_server_info_total> list_decide{};
	private:
		bool flag_schedule_noti = false;
		mrpcs_occupationwar_schedule_noti schedule_noti;
		mrpcs_occupationwar_schedule_noti* p_schedule_noti = nullptr;
	public:
		bool has_schedule_noti() const
		{
			return flag_schedule_noti;
		}
		mrpcs_occupationwar_schedule_noti* alloc_schedule_noti()
		{
			flag_schedule_noti = true;
			return &schedule_noti;
		}
		const mrpcs_occupationwar_schedule_noti* get_schedule_noti() const
		{
			if (true == flag_schedule_noti)
			{
				if (nullptr == p_schedule_noti)
				{
					return &schedule_noti;
				}
				return p_schedule_noti;
			}
			return nullptr;
		}
		void set_schedule_noti(mrpcs_occupationwar_schedule_noti* in_schedule_noti)
		{
			if (nullptr == p_schedule_noti)
			{
				p_schedule_noti = in_schedule_noti;
				flag_schedule_noti = true;
			}
		}
	private:
		bool flag_game_info = false;
		mrpcs_occupationwar_game_info game_info;
		mrpcs_occupationwar_game_info* p_game_info = nullptr;
	public:
		bool has_game_info() const
		{
			return flag_game_info;
		}
		mrpcs_occupationwar_game_info* alloc_game_info()
		{
			flag_game_info = true;
			return &game_info;
		}
		const mrpcs_occupationwar_game_info* get_game_info() const
		{
			if (true == flag_game_info)
			{
				if (nullptr == p_game_info)
				{
					return &game_info;
				}
				return p_game_info;
			}
			return nullptr;
		}
		void set_game_info(mrpcs_occupationwar_game_info* in_game_info)
		{
			if (nullptr == p_game_info)
			{
				p_game_info = in_game_info;
				flag_game_info = true;
			}
		}

	public:
		mrpc_occupationwar_gameserver_log_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::occupationwar_gameserver_log_sc, tag)
		{
		}
		mrpc_occupationwar_gameserver_log_sc() : RpcPacket(mpe_rpc_cmd::occupationwar_gameserver_log_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &time_zone);
			protocol::SerializeType(pBuffer, &flag_contents);
			if (true == flag_contents)
			{
				if (nullptr != p_contents)
					protocol::SerializeType(pBuffer, p_contents);
				else
					protocol::SerializeType(pBuffer, &contents);
			}
			protocol::SerializeType(pBuffer, &flag_base_info);
			if (true == flag_base_info)
			{
				if (nullptr != p_base_info)
					protocol::SerializeType(pBuffer, p_base_info);
				else
					protocol::SerializeType(pBuffer, &base_info);
			}
			protocol::SerializeType(pBuffer, &flag_schedule);
			if (true == flag_schedule)
			{
				if (nullptr != p_schedule)
					protocol::SerializeType(pBuffer, p_schedule);
				else
					protocol::SerializeType(pBuffer, &schedule);
			}
			protocol::SerializeType(pBuffer, &list_decide);
			protocol::SerializeType(pBuffer, &flag_schedule_noti);
			if (true == flag_schedule_noti)
			{
				if (nullptr != p_schedule_noti)
					protocol::SerializeType(pBuffer, p_schedule_noti);
				else
					protocol::SerializeType(pBuffer, &schedule_noti);
			}
			protocol::SerializeType(pBuffer, &flag_game_info);
			if (true == flag_game_info)
			{
				if (nullptr != p_game_info)
					protocol::SerializeType(pBuffer, p_game_info);
				else
					protocol::SerializeType(pBuffer, &game_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
