#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_gm_server_launcher_cs : public WebBasePacket 
	{
	public:
		mrpce_build_tool_command cmd{};
	public:
		std::string param1{};
	public:
		std::string param2{};
	public:
		std::string param3{};
	public:
		std::string param4{};
	public:
		std::string param5{};

	public:
		mweb_gm_server_launcher_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &cmd);
			protocol::SerializeType(pBuffer, &param1);
			protocol::SerializeType(pBuffer, &param2);
			protocol::SerializeType(pBuffer, &param3);
			protocol::SerializeType(pBuffer, &param4);
			protocol::SerializeType(pBuffer, &param5);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_server_launcher_sc : public WebBasePacket 
	{
	public:
		mrpce_build_tool_command cmd{};
	public:
		mpe_error result{};
	public:
		std::string output{};
	public:
		std::vector<std::string> list_filename{};
	public:
		std::vector<std::string> list_result{};

	public:
		mweb_gm_server_launcher_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &cmd);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &output);
			protocol::SerializeType(pBuffer, &list_filename);
			protocol::SerializeType(pBuffer, &list_result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
