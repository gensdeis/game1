#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_contents_onoff_info.h"

namespace mir3d
{
	class mrpc_contents_onoff_update_cs : public RpcPacket 
	{
	public:
		mpe_error result{};

	public:
		mrpc_contents_onoff_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::contents_onoff_update_cs, tag)
		{
		}
		mrpc_contents_onoff_update_cs() : RpcPacket(mpe_rpc_cmd::contents_onoff_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_contents_onoff_update_sc : public RpcPacket 
	{
	private:
		bool flag_info = false;
		mrpcs_contents_onoff_info info;
		mrpcs_contents_onoff_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_contents_onoff_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_contents_onoff_info* get_info() const
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
		void set_info(mrpcs_contents_onoff_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_contents_onoff_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::contents_onoff_update_sc, tag)
		{
		}
		mrpc_contents_onoff_update_sc() : RpcPacket(mpe_rpc_cmd::contents_onoff_update_sc)
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
