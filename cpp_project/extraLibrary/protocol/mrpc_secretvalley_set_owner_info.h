#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_secretvalley_owner_info.h"

namespace mir3d
{
	class mrpc_secretvalley_set_owner_info_cs : public RpcPacket 
	{
	public:
		uint8_t valley_type{};
	public:
		int64_t key{};
	public:
		int64_t channel_uid{};
	public:
		std::vector<int32_t> broadcast_zone_id_list{};

	public:
		mrpc_secretvalley_set_owner_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::secretvalley_set_owner_info_cs, tag)
		{
		}
		mrpc_secretvalley_set_owner_info_cs() : RpcPacket(mpe_rpc_cmd::secretvalley_set_owner_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &valley_type);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &broadcast_zone_id_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_secretvalley_set_owner_info_sc : public RpcPacket 
	{
	private:
		bool flag_owner_info = false;
		mps_secretvalley_owner_info owner_info;
		mps_secretvalley_owner_info* p_owner_info = nullptr;
	public:
		bool has_owner_info() const
		{
			return flag_owner_info;
		}
		mps_secretvalley_owner_info* alloc_owner_info()
		{
			flag_owner_info = true;
			return &owner_info;
		}
		const mps_secretvalley_owner_info* get_owner_info() const
		{
			if (true == flag_owner_info)
			{
				if (nullptr == p_owner_info)
				{
					return &owner_info;
				}
				return p_owner_info;
			}
			return nullptr;
		}
		void set_owner_info(mps_secretvalley_owner_info* in_owner_info)
		{
			if (nullptr == p_owner_info)
			{
				p_owner_info = in_owner_info;
				flag_owner_info = true;
			}
		}
	public:
		int64_t key{};
	public:
		int64_t channel_uid{};
	public:
		int32_t zone_id{};
	public:
		std::vector<int32_t> broadcast_zone_id_list{};

	public:
		mrpc_secretvalley_set_owner_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::secretvalley_set_owner_info_sc, tag)
		{
		}
		mrpc_secretvalley_set_owner_info_sc() : RpcPacket(mpe_rpc_cmd::secretvalley_set_owner_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_owner_info);
			if (true == flag_owner_info)
			{
				if (nullptr != p_owner_info)
					protocol::SerializeType(pBuffer, p_owner_info);
				else
					protocol::SerializeType(pBuffer, &owner_info);
			}
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &broadcast_zone_id_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
