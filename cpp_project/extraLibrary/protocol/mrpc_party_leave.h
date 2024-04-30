#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_party_leave_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t puid{};
	public:
		bool is_force{};	// // 강제 탈퇴 여부
	public:
		bool is_indun_out{};	// // 인던 나갈지 여부

	public:
		mrpc_party_leave_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_leave_cs, tag)
		{
		}
		mrpc_party_leave_cs() : RpcPacket(mpe_rpc_cmd::party_leave_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &is_force);
			protocol::SerializeType(pBuffer, &is_indun_out);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_leave_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t puid{};
	public:
		bool is_indun_out{};	// // 인던 나갈지 여부

	public:
		mrpc_party_leave_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_leave_sc, tag)
		{
		}
		mrpc_party_leave_sc() : RpcPacket(mpe_rpc_cmd::party_leave_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &is_indun_out);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
