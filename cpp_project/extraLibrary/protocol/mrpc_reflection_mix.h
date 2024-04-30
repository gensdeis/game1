#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_obtain_reflection.h"
#include "struct/mps_reflection.h"
#include "struct/mps_temp_reflection.h"
#include "struct/mps_restore_compose.h"

namespace mir3d
{
	class mrpc_reflection_mix_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_obtain_reflection> reward_reflection{};
	public:
		std::vector<mps_reflection> use_reflection{};
	public:
		std::vector<mps_temp_reflection> temp_reflection{};
	private:
		bool flag_restore_info = false;
		mps_restore_compose restore_info;
		mps_restore_compose* p_restore_info = nullptr;
	public:
		bool has_restore_info() const
		{
			return flag_restore_info;
		}
		mps_restore_compose* alloc_restore_info()
		{
			flag_restore_info = true;
			return &restore_info;
		}
		const mps_restore_compose* get_restore_info() const
		{
			if (true == flag_restore_info)
			{
				if (nullptr == p_restore_info)
				{
					return &restore_info;
				}
				return p_restore_info;
			}
			return nullptr;
		}
		void set_restore_info(mps_restore_compose* in_restore_info)
		{
			if (nullptr == p_restore_info)
			{
				p_restore_info = in_restore_info;
				flag_restore_info = true;
			}
		}

	public:
		mrpc_reflection_mix_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::reflection_mix_cs, tag)
		{
		}
		mrpc_reflection_mix_cs() : RpcPacket(mpe_rpc_cmd::reflection_mix_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &reward_reflection);
			protocol::SerializeType(pBuffer, &use_reflection);
			protocol::SerializeType(pBuffer, &temp_reflection);
			protocol::SerializeType(pBuffer, &flag_restore_info);
			if (true == flag_restore_info)
			{
				if (nullptr != p_restore_info)
					protocol::SerializeType(pBuffer, p_restore_info);
				else
					protocol::SerializeType(pBuffer, &restore_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_reflection_mix_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_reflection_mix_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::reflection_mix_sc, tag)
		{
		}
		mrpc_reflection_mix_sc() : RpcPacket(mpe_rpc_cmd::reflection_mix_sc)
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

}
