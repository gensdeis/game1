#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_darksteel_storage_info.h"

namespace mir3d
{
	class mrpc_gate_darksteel_storage_info_cs : public RpcPacket 	// 비곡창고 정보
	{
	public:
		int64_t key{};
	public:
		mpe_occupationwar_map_type type{};
	public:
		int64_t guid{};

	public:
		mrpc_gate_darksteel_storage_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_darksteel_storage_info_cs, tag)
		{
		}
		mrpc_gate_darksteel_storage_info_cs() : RpcPacket(mpe_rpc_cmd::gate_darksteel_storage_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_darksteel_storage_info_sc : public RpcPacket 	// 비곡창고 정보
	{
	public:
		int64_t key{};
	private:
		bool flag_info = false;
		mps_darksteel_storage_info info;
		mps_darksteel_storage_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_darksteel_storage_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_darksteel_storage_info* get_info() const
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
		void set_info(mps_darksteel_storage_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_gate_darksteel_storage_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_darksteel_storage_info_sc, tag)
		{
		}
		mrpc_gate_darksteel_storage_info_sc() : RpcPacket(mpe_rpc_cmd::gate_darksteel_storage_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
