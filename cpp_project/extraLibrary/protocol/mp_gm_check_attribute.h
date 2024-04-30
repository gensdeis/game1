#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_object_list.h"

namespace mir3d
{
	class mp_gm_check_attribute_cs : public BasePacket 
	{
	public:
		int32_t cell_index{};

	public:
		mp_gm_check_attribute_cs() : BasePacket(mpe_cmd::gm_check_attribute_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cell_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_check_attribute_sc : public BasePacket 
	{
	public:
		int32_t cell_index{};
	public:
		int32_t table_attr{};
	public:
		int32_t server_attr{};
	private:
		bool flag_object_list = false;
		mps_object_list object_list;
		mps_object_list* p_object_list = nullptr;
	public:
		bool has_object_list() const
		{
			return flag_object_list;
		}
		mps_object_list* alloc_object_list()
		{
			flag_object_list = true;
			return &object_list;
		}
		const mps_object_list* get_object_list() const
		{
			if (true == flag_object_list)
			{
				if (nullptr == p_object_list)
				{
					return &object_list;
				}
				return p_object_list;
			}
			return nullptr;
		}
		void set_object_list(mps_object_list* in_object_list)
		{
			if (nullptr == p_object_list)
			{
				p_object_list = in_object_list;
				flag_object_list = true;
			}
		}

	public:
		mp_gm_check_attribute_sc() : BasePacket(mpe_cmd::gm_check_attribute_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cell_index);
			protocol::SerializeType(pBuffer, &table_attr);
			protocol::SerializeType(pBuffer, &server_attr);
			protocol::SerializeType(pBuffer, &flag_object_list);
			if (true == flag_object_list)
			{
				if (nullptr != p_object_list)
					protocol::SerializeType(pBuffer, p_object_list);
				else
					protocol::SerializeType(pBuffer, &object_list);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
