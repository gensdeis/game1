#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_enter_character.h"

namespace mir3d
{
	class mrpc_character_enter_request_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t from_index{};
	public:
		int32_t to_index{};
	private:
		bool flag_info = false;
		mps_enter_character info;
		mps_enter_character* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_enter_character* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_enter_character* get_info() const
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
		void set_info(mps_enter_character* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_character_enter_request_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_enter_request_cs, tag)
		{
		}
		mrpc_character_enter_request_cs() : RpcPacket(mpe_rpc_cmd::character_enter_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &from_index);
			protocol::SerializeType(pBuffer, &to_index);
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

	class mrpc_character_enter_request_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		mpe_error error{};

	public:
		mrpc_character_enter_request_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_enter_request_sc, tag)
		{
		}
		mrpc_character_enter_request_sc() : RpcPacket(mpe_rpc_cmd::character_enter_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &error);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
