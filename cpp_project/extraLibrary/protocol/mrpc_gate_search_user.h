#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_character_simple_info.h"

namespace mir3d
{
	class mrpc_gate_search_user_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::string nickname{};
	public:
		int64_t cuid{};	// 자신의 cuid

	public:
		mrpc_gate_search_user_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_search_user_cs, tag)
		{
		}
		mrpc_gate_search_user_cs() : RpcPacket(mpe_rpc_cmd::gate_search_user_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_search_user_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_user_info = false;
		mps_character_simple_info user_info;
		mps_character_simple_info* p_user_info = nullptr;
	public:
		bool has_user_info() const
		{
			return flag_user_info;
		}
		mps_character_simple_info* alloc_user_info()
		{
			flag_user_info = true;
			return &user_info;
		}
		const mps_character_simple_info* get_user_info() const
		{
			if (true == flag_user_info)
			{
				if (nullptr == p_user_info)
				{
					return &user_info;
				}
				return p_user_info;
			}
			return nullptr;
		}
		void set_user_info(mps_character_simple_info* in_user_info)
		{
			if (nullptr == p_user_info)
			{
				p_user_info = in_user_info;
				flag_user_info = true;
			}
		}

	public:
		mrpc_gate_search_user_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_search_user_sc, tag)
		{
		}
		mrpc_gate_search_user_sc() : RpcPacket(mpe_rpc_cmd::gate_search_user_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_user_info);
			if (true == flag_user_info)
			{
				if (nullptr != p_user_info)
					protocol::SerializeType(pBuffer, p_user_info);
				else
					protocol::SerializeType(pBuffer, &user_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
