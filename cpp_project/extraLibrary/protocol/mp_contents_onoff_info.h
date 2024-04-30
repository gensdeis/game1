#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_contents_onoff_info.h"

namespace mir3d
{
	class mp_contents_onoff_info_cs : public BasePacket 	//  // 컨텐츠 온오프
	{
	public:
		std::vector<int32_t> contents_type{};

	public:
		mp_contents_onoff_info_cs() : BasePacket(mpe_cmd::contents_onoff_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &contents_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_contents_onoff_info_sc : public BasePacket 	//  // 컨텐츠 온오프
	{
	public:
		std::vector<mps_contents_onoff_info> contents_onoff_list{};

	public:
		mp_contents_onoff_info_sc() : BasePacket(mpe_cmd::contents_onoff_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &contents_onoff_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
