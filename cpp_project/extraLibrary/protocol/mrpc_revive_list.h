#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_revive.h"

namespace mir3d
{
	class mrpc_revive_list_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_info = false;
		mps_revive info;
		mps_revive* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_revive* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_revive* get_info() const
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
		void set_info(mps_revive* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		std::vector<int32_t> remove_id{};

	public:
		mrpc_revive_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::revive_list_cs, tag)
		{
		}
		mrpc_revive_list_cs() : RpcPacket(mpe_rpc_cmd::revive_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &remove_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_revive_list_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_revive_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::revive_list_sc, tag)
		{
		}
		mrpc_revive_list_sc() : RpcPacket(mpe_rpc_cmd::revive_list_sc)
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
