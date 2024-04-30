#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_mentor_request_cs : public BasePacket 
	{
	public:
		int64_t target_cuid{};
	public:
		std::string nickname{};
	public:
		mpe_mentor_request_type request_type{};
	public:
		mpe_mentor_type mentor_type{};

	public:
		mp_mentor_request_cs() : BasePacket(mpe_cmd::mentor_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeEnum(pBuffer, &request_type);
			protocol::SerializeEnum(pBuffer, &mentor_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_mentor_request_sc : public BasePacket 
	{
	public:
		int64_t target_cuid{};
	public:
		std::string nick_name{};
	public:
		mpe_mentor_request_type request_type{};

	public:
		mp_mentor_request_sc() : BasePacket(mpe_cmd::mentor_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &nick_name);
			protocol::SerializeEnum(pBuffer, &request_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
