#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mgms_comm_character.h"

namespace mir3d
{
	class mrpc_character_search_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::string nickname{};

	public:
		mrpc_character_search_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_search_cs, tag)
		{
		}
		mrpc_character_search_cs() : RpcPacket(mpe_rpc_cmd::character_search_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &nickname);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_character_search_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_character_info = false;
		mgms_comm_character character_info;
		mgms_comm_character* p_character_info = nullptr;
	public:
		bool has_character_info() const
		{
			return flag_character_info;
		}
		mgms_comm_character* alloc_character_info()
		{
			flag_character_info = true;
			return &character_info;
		}
		const mgms_comm_character* get_character_info() const
		{
			if (true == flag_character_info)
			{
				if (nullptr == p_character_info)
				{
					return &character_info;
				}
				return p_character_info;
			}
			return nullptr;
		}
		void set_character_info(mgms_comm_character* in_character_info)
		{
			if (nullptr == p_character_info)
			{
				p_character_info = in_character_info;
				flag_character_info = true;
			}
		}

	public:
		mrpc_character_search_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_search_sc, tag)
		{
		}
		mrpc_character_search_sc() : RpcPacket(mpe_rpc_cmd::character_search_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_character_info);
			if (true == flag_character_info)
			{
				if (nullptr != p_character_info)
					protocol::SerializeType(pBuffer, p_character_info);
				else
					protocol::SerializeType(pBuffer, &character_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
