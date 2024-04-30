#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods.h"

namespace mir3d
{
	class mp_storage_expand_cs : public BasePacket 
	{
	public:
		uint16_t storage_type{};	// 확장할 창고 타입
	public:
		uint16_t count{};	// 구매개수
	public:
		int64_t npc_uid{};	// 창고 npc uid

	public:
		mp_storage_expand_cs() : BasePacket(mpe_cmd::storage_expand_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &storage_type);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &npc_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_storage_expand_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_update_goods info;	// 변경된 재화
		mps_update_goods* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_update_goods* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_update_goods* get_info() const
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
		void set_info(mps_update_goods* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		uint16_t size{};	// 변경된 사이즈
	public:
		uint16_t pos{};	// 확장된 창고 위치

	public:
		mp_storage_expand_sc() : BasePacket(mpe_cmd::storage_expand_sc)
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
			protocol::SerializeType(pBuffer, &size);
			protocol::SerializeType(pBuffer, &pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
