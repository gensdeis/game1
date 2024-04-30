#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_dictionary_info.h"
#include "struct/mps_dic_stat.h"

namespace mir3d
{
	class mp_dictionary_get_cs : public BasePacket 
	{
	public:
		int32_t category{};
	public:
		mpe_dictionary_type type{};

	public:
		mp_dictionary_get_cs() : BasePacket(mpe_cmd::dictionary_get_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &category);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_dictionary_get_sc : public BasePacket 
	{
	public:
		std::vector<mps_dictionary_info> list{};
	public:
		mpe_dictionary_type type{};
	public:
		int32_t category_id{};
	public:
		int32_t total_count{};	// "아이템, 펫 타입일 경우 진행개수"
	public:
		int32_t complet_count{};	// "아이템, 펫 타입일 경우 완료개수"
	private:
		bool flag_stat = false;
		mps_dic_stat stat;
		mps_dic_stat* p_stat = nullptr;
	public:
		bool has_stat() const
		{
			return flag_stat;
		}
		mps_dic_stat* alloc_stat()
		{
			flag_stat = true;
			return &stat;
		}
		const mps_dic_stat* get_stat() const
		{
			if (true == flag_stat)
			{
				if (nullptr == p_stat)
				{
					return &stat;
				}
				return p_stat;
			}
			return nullptr;
		}
		void set_stat(mps_dic_stat* in_stat)
		{
			if (nullptr == p_stat)
			{
				p_stat = in_stat;
				flag_stat = true;
			}
		}

	public:
		mp_dictionary_get_sc() : BasePacket(mpe_cmd::dictionary_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &category_id);
			protocol::SerializeType(pBuffer, &total_count);
			protocol::SerializeType(pBuffer, &complet_count);
			protocol::SerializeType(pBuffer, &flag_stat);
			if (true == flag_stat)
			{
				if (nullptr != p_stat)
					protocol::SerializeType(pBuffer, p_stat);
				else
					protocol::SerializeType(pBuffer, &stat);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
