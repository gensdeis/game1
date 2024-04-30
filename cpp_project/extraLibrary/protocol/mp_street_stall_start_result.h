#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_street_stall_start_result_cs : public BasePacket 	// // 개인 노점 생성 - db저장 result
	{
	public:
		mpe_error error_code{};
	public:
		int64_t cuid{};
	public:
		int64_t suid{};
	private:
		bool flag_item_info = false;
		mps_item_add item_info;
		mps_item_add* p_item_info = nullptr;
	public:
		bool has_item_info() const
		{
			return flag_item_info;
		}
		mps_item_add* alloc_item_info()
		{
			flag_item_info = true;
			return &item_info;
		}
		const mps_item_add* get_item_info() const
		{
			if (true == flag_item_info)
			{
				if (nullptr == p_item_info)
				{
					return &item_info;
				}
				return p_item_info;
			}
			return nullptr;
		}
		void set_item_info(mps_item_add* in_item_info)
		{
			if (nullptr == p_item_info)
			{
				p_item_info = in_item_info;
				flag_item_info = true;
			}
		}

	public:
		mp_street_stall_start_result_cs() : BasePacket(mpe_cmd::street_stall_start_result_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &error_code);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &suid);
			protocol::SerializeType(pBuffer, &flag_item_info);
			if (true == flag_item_info)
			{
				if (nullptr != p_item_info)
					protocol::SerializeType(pBuffer, p_item_info);
				else
					protocol::SerializeType(pBuffer, &item_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_street_stall_start_result_sc : public BasePacket 	// // 개인 노점 생성 - db저장 result
	{

	public:
		mp_street_stall_start_result_sc() : BasePacket(mpe_cmd::street_stall_start_result_sc)
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

}
