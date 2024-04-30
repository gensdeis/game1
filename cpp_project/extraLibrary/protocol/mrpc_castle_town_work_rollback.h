#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_town_work.h"

namespace mir3d
{
	class mrpc_castle_town_work_rollback_cs : public RpcPacket 	// 장원 작업 롤백 - 캐릭터 아이템 사용중 에러 발생시
	{
	private:
		bool flag_work = false;
		mps_castle_town_work work;
		mps_castle_town_work* p_work = nullptr;
	public:
		bool has_work() const
		{
			return flag_work;
		}
		mps_castle_town_work* alloc_work()
		{
			flag_work = true;
			return &work;
		}
		const mps_castle_town_work* get_work() const
		{
			if (true == flag_work)
			{
				if (nullptr == p_work)
				{
					return &work;
				}
				return p_work;
			}
			return nullptr;
		}
		void set_work(mps_castle_town_work* in_work)
		{
			if (nullptr == p_work)
			{
				p_work = in_work;
				flag_work = true;
			}
		}

	public:
		mrpc_castle_town_work_rollback_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_work_rollback_cs, tag)
		{
		}
		mrpc_castle_town_work_rollback_cs() : RpcPacket(mpe_rpc_cmd::castle_town_work_rollback_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_work);
			if (true == flag_work)
			{
				if (nullptr != p_work)
					protocol::SerializeType(pBuffer, p_work);
				else
					protocol::SerializeType(pBuffer, &work);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_castle_town_work_rollback_sc : public RpcPacket 	// 장원 작업 롤백 - 캐릭터 아이템 사용중 에러 발생시
	{

	public:
		mrpc_castle_town_work_rollback_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_work_rollback_sc, tag)
		{
		}
		mrpc_castle_town_work_rollback_sc() : RpcPacket(mpe_rpc_cmd::castle_town_work_rollback_sc)
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

}
