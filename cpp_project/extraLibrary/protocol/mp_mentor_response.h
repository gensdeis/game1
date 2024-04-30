#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_mentor_response_cs : public BasePacket 
	{
	public:
		mpe_mentor_request_type request_type{};
	public:
		int64_t cuid{};
	public:
		int64_t target_cuid{};
	public:
		std::string nick_name{};
	public:
		mpe_mentor_type mentor_type{};
	public:
		int64_t mentor_next_available_join_time{};
	public:
		bool disband_level{};

	public:
		mp_mentor_response_cs() : BasePacket(mpe_cmd::mentor_response_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &request_type);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &nick_name);
			protocol::SerializeEnum(pBuffer, &mentor_type);
			protocol::SerializeType(pBuffer, &mentor_next_available_join_time);
			protocol::SerializeType(pBuffer, &disband_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_mentor_response_sc : public BasePacket 
	{
	public:
		mpe_mentor_request_type request_type{};
	public:
		int64_t target_cuid{};
	public:
		std::string nick_name{};
	public:
		mpe_mentor_type mentor_type{};
	public:
		int64_t mentor_next_available_join_time{};
	public:
		bool disband_level{};

	public:
		mp_mentor_response_sc() : BasePacket(mpe_cmd::mentor_response_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &request_type);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &nick_name);
			protocol::SerializeEnum(pBuffer, &mentor_type);
			protocol::SerializeType(pBuffer, &mentor_next_available_join_time);
			protocol::SerializeType(pBuffer, &disband_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
