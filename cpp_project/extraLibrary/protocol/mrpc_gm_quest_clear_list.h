#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_quest_finish.h"

namespace mir3d
{
	class mrpc_gm_quest_clear_list_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		std::vector<uint16_t> list_tid{};
	private:
		bool flag_info = false;
		mrpcs_quest_finish info;
		mrpcs_quest_finish* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_quest_finish* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_quest_finish* get_info() const
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
		void set_info(mrpcs_quest_finish* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_gm_quest_clear_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_quest_clear_list_cs, tag)
		{
		}
		mrpc_gm_quest_clear_list_cs() : RpcPacket(mpe_rpc_cmd::gm_quest_clear_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &list_tid);
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

	class mrpc_gm_quest_clear_list_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		std::vector<uint16_t> list_tid{};

	public:
		mrpc_gm_quest_clear_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_quest_clear_list_sc, tag)
		{
		}
		mrpc_gm_quest_clear_list_sc() : RpcPacket(mpe_rpc_cmd::gm_quest_clear_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &list_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
