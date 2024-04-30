#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_drop_probalility_info_list.h"

namespace mir3d
{
	class mrpc_cheatkey_drop_probalility_cs : public RpcPacket 
	{

	public:
		mrpc_cheatkey_drop_probalility_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cheatkey_drop_probalility_cs, tag)
		{
		}
		mrpc_cheatkey_drop_probalility_cs() : RpcPacket(mpe_rpc_cmd::cheatkey_drop_probalility_cs)
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

	class mrpc_cheatkey_drop_probalility_sc : public RpcPacket 
	{
	public:
		mrpce_cheatkey_type type{};
	public:
		int32_t objectid{};
	public:
		int32_t repeat_count{};
	public:
		int32_t index{};
	public:
		int32_t total_index{};
	public:
		std::vector<mrpcs_drop_probalility_info_list> list_result{};

	public:
		mrpc_cheatkey_drop_probalility_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cheatkey_drop_probalility_sc, tag)
		{
		}
		mrpc_cheatkey_drop_probalility_sc() : RpcPacket(mpe_rpc_cmd::cheatkey_drop_probalility_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &objectid);
			protocol::SerializeType(pBuffer, &repeat_count);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &total_index);
			protocol::SerializeType(pBuffer, &list_result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
