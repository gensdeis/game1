#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_character_info_view.h"

namespace mir3d
{
	class mrpc_gate_character_info_view_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t target_cuid{};

	public:
		mrpc_gate_character_info_view_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_character_info_view_cs, tag)
		{
		}
		mrpc_gate_character_info_view_cs() : RpcPacket(mpe_rpc_cmd::gate_character_info_view_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &target_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_character_info_view_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_info = false;
		mps_character_info_view info;
		mps_character_info_view* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_character_info_view* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_character_info_view* get_info() const
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
		void set_info(mps_character_info_view* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_gate_character_info_view_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_character_info_view_sc, tag)
		{
		}
		mrpc_gate_character_info_view_sc() : RpcPacket(mpe_rpc_cmd::gate_character_info_view_sc)
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
