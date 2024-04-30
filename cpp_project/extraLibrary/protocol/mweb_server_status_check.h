#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_server_status_check_cs : public WebBasePacket 	// (gate에서 삭제)
	{
	public:
		int64_t value1{};
	public:
		int64_t value2{};

	public:
		mweb_server_status_check_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &value1);
			protocol::SerializeType(pBuffer, &value2);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_server_status_check_sc : public WebBasePacket 	// (gate에서 삭제)
	{
	public:
		int64_t value1{};
	public:
		int64_t value2{};

	public:
		mweb_server_status_check_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &value1);
			protocol::SerializeType(pBuffer, &value2);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
