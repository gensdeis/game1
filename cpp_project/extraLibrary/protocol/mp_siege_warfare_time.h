#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_siege_warfare_time_info.h"

namespace mir3d
{
	class mp_siege_warfare_time_cs : public BasePacket 	// 공성전 날짜 요청
	{
	public:
		mpe_siege_castle_type castle_type{};	// 성 type

	public:
		mp_siege_warfare_time_cs() : BasePacket(mpe_cmd::siege_warfare_time_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &castle_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_siege_warfare_time_sc : public BasePacket 	// 공성전 날짜 요청
	{
	public:
		mpe_siege_castle_type castle_type{};
	private:
		bool flag_time_info = false;
		mps_siege_warfare_time_info time_info;
		mps_siege_warfare_time_info* p_time_info = nullptr;
	public:
		bool has_time_info() const
		{
			return flag_time_info;
		}
		mps_siege_warfare_time_info* alloc_time_info()
		{
			flag_time_info = true;
			return &time_info;
		}
		const mps_siege_warfare_time_info* get_time_info() const
		{
			if (true == flag_time_info)
			{
				if (nullptr == p_time_info)
				{
					return &time_info;
				}
				return p_time_info;
			}
			return nullptr;
		}
		void set_time_info(mps_siege_warfare_time_info* in_time_info)
		{
			if (nullptr == p_time_info)
			{
				p_time_info = in_time_info;
				flag_time_info = true;
			}
		}

	public:
		mp_siege_warfare_time_sc() : BasePacket(mpe_cmd::siege_warfare_time_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &flag_time_info);
			if (true == flag_time_info)
			{
				if (nullptr != p_time_info)
					protocol::SerializeType(pBuffer, p_time_info);
				else
					protocol::SerializeType(pBuffer, &time_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
