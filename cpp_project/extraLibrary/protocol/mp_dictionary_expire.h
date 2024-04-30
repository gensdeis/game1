#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_dic_stat.h"

namespace mir3d
{
	class mp_dictionary_expire_cs : public BasePacket 
	{
	public:
		mpe_dictionary_type type{};
	public:
		int32_t category_id{};
	public:
		int32_t tid{};	// 만료 tid

	public:
		mp_dictionary_expire_cs() : BasePacket(mpe_cmd::dictionary_expire_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &category_id);
			protocol::SerializeType(pBuffer, &tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_dictionary_expire_sc : public BasePacket 
	{
	public:
		mpe_dictionary_type type{};
	public:
		int32_t category_id{};
	public:
		int32_t total_count{};	// 진행중
	public:
		int32_t complet_count{};	// 완료
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
		int32_t tid{};	// 삭제된 tid

	public:
		mp_dictionary_expire_sc() : BasePacket(mpe_cmd::dictionary_expire_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
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
			protocol::SerializeType(pBuffer, &tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
