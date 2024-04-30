﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_darksteel_storage_history_list.h"

namespace mir3d
{
	class mp_gate_darksteel_storage_history_cs : public BasePacket 	// 비곡창고 사용내역
	{
	public:
		mpe_occupationwar_map_type type{};
	public:
		int64_t guid{};

	public:
		mp_gate_darksteel_storage_history_cs() : BasePacket(mpe_cmd::gate_darksteel_storage_history_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_darksteel_storage_history_sc : public BasePacket 	// 비곡창고 사용내역
	{
	private:
		bool flag_info = false;
		mps_darksteel_storage_history_list info;
		mps_darksteel_storage_history_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_darksteel_storage_history_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_darksteel_storage_history_list* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mps_darksteel_storage_history_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_gate_darksteel_storage_history_sc() : BasePacket(mpe_cmd::gate_darksteel_storage_history_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
