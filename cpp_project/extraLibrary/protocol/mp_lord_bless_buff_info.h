#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_lord_bless_buff.h"

namespace mir3d
{
	class mp_lord_bless_buff_info_cs : public BasePacket 	// 현재 걸린 축복버프정보만 보는 패킷(ui터치시보는정보)
	{

	public:
		mp_lord_bless_buff_info_cs() : BasePacket(mpe_cmd::lord_bless_buff_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_lord_bless_buff_info_sc : public BasePacket 	// 현재 걸린 축복버프정보만 보는 패킷(ui터치시보는정보)
	{
	public:
		std::vector<mps_lord_bless_buff> bless_buff_list{};	// 축복 버프리스트(모든성)

	public:
		mp_lord_bless_buff_info_sc() : BasePacket(mpe_cmd::lord_bless_buff_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &bless_buff_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
