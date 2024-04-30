#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_character_autosave.h"

namespace mir3d
{
	class mrpc_character_autosave_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		int32_t flag{};
	public:
		mrpce_server_type server_type{};
	public:
		int32_t server_index{};
	private:
		bool flag_info = false;
		mrpcs_character_autosave info;
		mrpcs_character_autosave* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_character_autosave* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_character_autosave* get_info() const
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
		void set_info(mrpcs_character_autosave* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_character_autosave_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_autosave_cs, tag)
		{
		}
		mrpc_character_autosave_cs() : RpcPacket(mpe_rpc_cmd::character_autosave_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &flag);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &server_index);
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

	class mrpc_character_autosave_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t auid{};

	public:
		mrpc_character_autosave_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_autosave_sc, tag)
		{
		}
		mrpc_character_autosave_sc() : RpcPacket(mpe_rpc_cmd::character_autosave_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
