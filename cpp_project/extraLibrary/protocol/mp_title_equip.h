#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_title_send_info.h"

namespace mir3d
{
	class mp_title_equip_cs : public BasePacket 
	{
	public:
		int32_t tid{};	// 칭호 tid 0일경우 해제
	public:
		std::vector<int32_t> list_tid{};
	public:
		mpe_title_type title_type{};

	public:
		mp_title_equip_cs() : BasePacket(mpe_cmd::title_equip_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &list_tid);
			protocol::SerializeEnum(pBuffer, &title_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_title_equip_sc : public BasePacket 
	{
	public:
		int64_t cuid{};
	private:
		bool flag_title_info = false;
		mps_title_send_info title_info;
		mps_title_send_info* p_title_info = nullptr;
	public:
		bool has_title_info() const
		{
			return flag_title_info;
		}
		mps_title_send_info* alloc_title_info()
		{
			flag_title_info = true;
			return &title_info;
		}
		const mps_title_send_info* get_title_info() const
		{
			if (true == flag_title_info)
			{
				if (nullptr == p_title_info)
				{
					return &title_info;
				}
				return p_title_info;
			}
			return nullptr;
		}
		void set_title_info(mps_title_send_info* in_title_info)
		{
			if (nullptr == p_title_info)
			{
				p_title_info = in_title_info;
				flag_title_info = true;
			}
		}

	public:
		mp_title_equip_sc() : BasePacket(mpe_cmd::title_equip_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_title_info);
			if (true == flag_title_info)
			{
				if (nullptr != p_title_info)
					protocol::SerializeType(pBuffer, p_title_info);
				else
					protocol::SerializeType(pBuffer, &title_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
