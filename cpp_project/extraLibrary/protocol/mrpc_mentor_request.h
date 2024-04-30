#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_mentor_request_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		mpe_mentor_request_type request_type{};
	public:
		mpe_mentor_type mentor_type{};
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		int64_t target_cuid{};
	public:
		std::string nickname{};
	public:
		int32_t id{};
	public:
		int32_t level{};
	public:
		int32_t power{};
	public:
		bool disband_level{};

	public:
		mrpc_mentor_request_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mentor_request_cs, tag)
		{
		}
		mrpc_mentor_request_cs() : RpcPacket(mpe_rpc_cmd::mentor_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &request_type);
			protocol::SerializeEnum(pBuffer, &mentor_type);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &power);
			protocol::SerializeType(pBuffer, &disband_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_mentor_request_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t target_cuid{};
	public:
		std::string nickname{};
	public:
		mpe_mentor_type mentor_type{};
	public:
		mpe_mentor_request_type request_type{};
	public:
		int64_t mentor_next_available_join_time{};
	public:
		bool disband_level{};

	public:
		mrpc_mentor_request_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mentor_request_sc, tag)
		{
		}
		mrpc_mentor_request_sc() : RpcPacket(mpe_rpc_cmd::mentor_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeEnum(pBuffer, &mentor_type);
			protocol::SerializeEnum(pBuffer, &request_type);
			protocol::SerializeType(pBuffer, &mentor_next_available_join_time);
			protocol::SerializeType(pBuffer, &disband_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
