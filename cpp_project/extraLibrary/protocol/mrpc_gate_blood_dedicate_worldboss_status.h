#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_blood_dedicate_worldboss_info.h"

namespace mir3d
{
	class mrpc_gate_blood_dedicate_worldboss_status_cs : public RpcPacket 	// 봉혈 월드보스 UI
	{
	public:
		int64_t key{};	// 유저 세션정보

	public:
		mrpc_gate_blood_dedicate_worldboss_status_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_blood_dedicate_worldboss_status_cs, tag)
		{
		}
		mrpc_gate_blood_dedicate_worldboss_status_cs() : RpcPacket(mpe_rpc_cmd::gate_blood_dedicate_worldboss_status_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_blood_dedicate_worldboss_status_sc : public RpcPacket 	// 봉혈 월드보스 UI
	{
	private:
		bool flag_info = false;
		mps_blood_dedicate_worldboss_info info;	// 봉혈 월드보스 정보
		mps_blood_dedicate_worldboss_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_blood_dedicate_worldboss_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_blood_dedicate_worldboss_info* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mps_blood_dedicate_worldboss_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int64_t key{};	// 유저 세션정보

	public:
		mrpc_gate_blood_dedicate_worldboss_status_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_blood_dedicate_worldboss_status_sc, tag)
		{
		}
		mrpc_gate_blood_dedicate_worldboss_status_sc() : RpcPacket(mpe_rpc_cmd::gate_blood_dedicate_worldboss_status_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
