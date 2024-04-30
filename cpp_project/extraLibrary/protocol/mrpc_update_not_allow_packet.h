#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_not_allow_packet_list.h"

namespace mir3d
{
	class mrpc_update_not_allow_packet_cs : public RpcPacket 
	{
	public:
		int32_t flag{};	// 0 : game 1 : community
	public:
		bool check_state{};
	private:
		bool flag_info = false;
		mrpcs_not_allow_packet_list info;
		mrpcs_not_allow_packet_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_not_allow_packet_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_not_allow_packet_list* get_info() const
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
		void set_info(mrpcs_not_allow_packet_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_update_not_allow_packet_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::update_not_allow_packet_cs, tag)
		{
		}
		mrpc_update_not_allow_packet_cs() : RpcPacket(mpe_rpc_cmd::update_not_allow_packet_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag);
			protocol::SerializeType(pBuffer, &check_state);
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

	class mrpc_update_not_allow_packet_sc : public RpcPacket 
	{

	public:
		mrpc_update_not_allow_packet_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::update_not_allow_packet_sc, tag)
		{
		}
		mrpc_update_not_allow_packet_sc() : RpcPacket(mpe_rpc_cmd::update_not_allow_packet_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
