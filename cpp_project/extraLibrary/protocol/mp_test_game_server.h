#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_test_game_server_cs : public BasePacket 	// server test 용
	{
	public:
		int64_t uid{};
	public:
		int32_t test_type{};
	public:
		int64_t send_time{};
	public:
		int64_t recv_time{};
	public:
		std::string buffer{};
	public:
		int32_t count{};
	public:
		int32_t thread_id{};

	public:
		mp_test_game_server_cs() : BasePacket(mpe_cmd::test_game_server_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &test_type);
			protocol::SerializeType(pBuffer, &send_time);
			protocol::SerializeType(pBuffer, &recv_time);
			protocol::SerializeType(pBuffer, &buffer);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &thread_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_test_game_server_sc : public BasePacket 	// server test 용
	{
	public:
		int64_t uid{};
	public:
		int32_t test_type{};
	public:
		int32_t latency{};
	public:
		int64_t send_time{};
	public:
		std::string buffer{};
	public:
		int32_t count{};
	public:
		int32_t thread_id{};
	public:
		int32_t connections{};
	public:
		int64_t fps{};
	public:
		int64_t use_mem{};
	public:
		int64_t use_cpu{};

	public:
		mp_test_game_server_sc() : BasePacket(mpe_cmd::test_game_server_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &test_type);
			protocol::SerializeType(pBuffer, &latency);
			protocol::SerializeType(pBuffer, &send_time);
			protocol::SerializeType(pBuffer, &buffer);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &thread_id);
			protocol::SerializeType(pBuffer, &connections);
			protocol::SerializeType(pBuffer, &fps);
			protocol::SerializeType(pBuffer, &use_mem);
			protocol::SerializeType(pBuffer, &use_cpu);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
