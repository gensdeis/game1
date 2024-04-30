#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_server_relocation_cs : public BasePacket 
	{
	public:
		int64_t iuid{};	// 사용할 아이템 UID
	public:
		int32_t gid{};	// 이동할 서버 그룹 아이디

	public:
		mp_server_relocation_cs() : BasePacket(mpe_cmd::server_relocation_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_server_relocation_sc : public BasePacket 
	{
	public:
		bool is_success{};
	public:
		mpe_error result{};

	public:
		mp_server_relocation_sc() : BasePacket(mpe_cmd::server_relocation_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &is_success);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
