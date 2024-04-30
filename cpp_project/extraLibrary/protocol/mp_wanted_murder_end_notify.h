#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_wanted_murder_end_notify_cs : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		std::string target_nick_name{};
	public:
		bool result{};	// 실패0,완료1

	public:
		mp_wanted_murder_end_notify_cs() : BasePacket(mpe_cmd::wanted_murder_end_notify_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_nick_name);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_wanted_murder_end_notify_sc : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		std::string target_nick_name{};
	public:
		bool result{};	// 실패0,완료1

	public:
		mp_wanted_murder_end_notify_sc() : BasePacket(mpe_cmd::wanted_murder_end_notify_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_nick_name);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
