#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_siege_warfare_info.h"

namespace mir3d
{
	class mrpc_siege_warfare_info_cs : public RpcPacket 	// 공성전 정보 요청
	{
	public:
		mpe_siege_castle_type castle_type{};	// 성 type

	public:
		mrpc_siege_warfare_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_info_cs, tag)
		{
		}
		mrpc_siege_warfare_info_cs() : RpcPacket(mpe_rpc_cmd::siege_warfare_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &castle_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_siege_warfare_info_sc : public RpcPacket 	// 공성전 정보 요청
	{
	private:
		bool flag_info = false;
		mps_siege_warfare_info info;	// 공성전 상태
		mps_siege_warfare_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_siege_warfare_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_siege_warfare_info* get_info() const
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
		void set_info(mps_siege_warfare_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_siege_warfare_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_info_sc, tag)
		{
		}
		mrpc_siege_warfare_info_sc() : RpcPacket(mpe_rpc_cmd::siege_warfare_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
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
