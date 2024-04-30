#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_iuid_list.h"
#include "struct/mps_item_count_update.h"
#include "struct/mps_update_goods.h"
#include "struct/mps_dictionary_info.h"
#include "struct/mps_dic_stat.h"

namespace mir3d
{
	class mp_dictionary_add_cs : public BasePacket 
	{
	public:
		int32_t category_id{};
	public:
		int32_t dic_id{};	// 도감 id
	public:
		int64_t consume_id{};	// "재료 id( 아이템 uid, tid, pet id )"
	public:
		int32_t count{};
	public:
		int32_t pos{};	// monster type일경우 -1
	public:
		mpe_dictionary_type type{};
	public:
		int64_t obj_uid{};
	public:
		std::vector<int32_t> list_tid{};
	private:
		bool flag_list_iuid = false;
		mps_item_iuid_list list_iuid;	// 요마 시공 채우기같은 동시 등록에서 사용
		mps_item_iuid_list* p_list_iuid = nullptr;
	public:
		bool has_list_iuid() const
		{
			return flag_list_iuid;
		}
		mps_item_iuid_list* alloc_list_iuid()
		{
			flag_list_iuid = true;
			return &list_iuid;
		}
		const mps_item_iuid_list* get_list_iuid() const
		{
			if (true == flag_list_iuid)
			{
				if (nullptr == p_list_iuid)
				{
					return &list_iuid;
				}
				return p_list_iuid;
			}
			return nullptr;
		}
		void set_list_iuid(mps_item_iuid_list* in_list_iuid)
		{
			if (nullptr == p_list_iuid)
			{
				p_list_iuid = in_list_iuid;
				flag_list_iuid = true;
			}
		}

	public:
		mp_dictionary_add_cs() : BasePacket(mpe_cmd::dictionary_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &category_id);
			protocol::SerializeType(pBuffer, &dic_id);
			protocol::SerializeType(pBuffer, &consume_id);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &pos);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &obj_uid);
			protocol::SerializeType(pBuffer, &list_tid);
			protocol::SerializeType(pBuffer, &flag_list_iuid);
			if (true == flag_list_iuid)
			{
				if (nullptr != p_list_iuid)
					protocol::SerializeType(pBuffer, p_list_iuid);
				else
					protocol::SerializeType(pBuffer, &list_iuid);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_dictionary_add_sc : public BasePacket 
	{
	public:
		std::vector<mps_item_count_update> item_info{};	// 소모된 아이템
	public:
		std::vector<mps_update_goods> update_goods{};	// 소모된 재화
	private:
		bool flag_dic_info = false;
		mps_dictionary_info dic_info;	// 갱신된 도감정보
		mps_dictionary_info* p_dic_info = nullptr;
	public:
		bool has_dic_info() const
		{
			return flag_dic_info;
		}
		mps_dictionary_info* alloc_dic_info()
		{
			flag_dic_info = true;
			return &dic_info;
		}
		const mps_dictionary_info* get_dic_info() const
		{
			if (true == flag_dic_info)
			{
				if (nullptr == p_dic_info)
				{
					return &dic_info;
				}
				return p_dic_info;
			}
			return nullptr;
		}
		void set_dic_info(mps_dictionary_info* in_dic_info)
		{
			if (nullptr == p_dic_info)
			{
				p_dic_info = in_dic_info;
				flag_dic_info = true;
			}
		}
	public:
		int32_t pet_id{};	// 펫 id
	public:
		int32_t keep_value{};	// 펫 소모 개수 / 몬스터 코어 총개수
	public:
		int32_t category_id{};
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
		int32_t total_count{};
	public:
		int32_t complet_count{};

	public:
		mp_dictionary_add_sc() : BasePacket(mpe_cmd::dictionary_add_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &item_info);
			protocol::SerializeType(pBuffer, &update_goods);
			protocol::SerializeType(pBuffer, &flag_dic_info);
			if (true == flag_dic_info)
			{
				if (nullptr != p_dic_info)
					protocol::SerializeType(pBuffer, p_dic_info);
				else
					protocol::SerializeType(pBuffer, &dic_info);
			}
			protocol::SerializeType(pBuffer, &pet_id);
			protocol::SerializeType(pBuffer, &keep_value);
			protocol::SerializeType(pBuffer, &category_id);
			protocol::SerializeType(pBuffer, &flag_stat);
			if (true == flag_stat)
			{
				if (nullptr != p_stat)
					protocol::SerializeType(pBuffer, p_stat);
				else
					protocol::SerializeType(pBuffer, &stat);
			}
			protocol::SerializeType(pBuffer, &total_count);
			protocol::SerializeType(pBuffer, &complet_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
