#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_mentor_register_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		int32_t id{};
	public:
		int32_t level{};
	public:
		int32_t power{};
	public:
		mpe_mentor_type mentor_type{};
	public:
		std::string guild_name{};
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		bool is_remove{};	// 등록 제거 여부
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mrpc_mentor_register_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mentor_register_cs, tag)
		{
		}
		mrpc_mentor_register_cs() : RpcPacket(mpe_rpc_cmd::mentor_register_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &power);
			protocol::SerializeEnum(pBuffer, &mentor_type);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &is_remove);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_mentor_register_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t reg_date{};

	public:
		mrpc_mentor_register_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mentor_register_sc, tag)
		{
		}
		mrpc_mentor_register_sc() : RpcPacket(mpe_rpc_cmd::mentor_register_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &reg_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
