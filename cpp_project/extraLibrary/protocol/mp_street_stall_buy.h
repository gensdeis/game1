#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_street_stall_item_reinforce.h"
#include "struct/mps_street_stall_item_luck_reinforce.h"
#include "struct/mps_street_stall_item_enchant_option_change.h"
#include "struct/mps_profesion_update.h"
#include "struct/mps_street_stall_item_reinforce_result.h"
#include "struct/mps_street_stall_item_luck_reinforce_result.h"
#include "struct/mps_street_stall_item_enchant_option_change_result.h"

namespace mir3d
{
	class mp_street_stall_buy_cs : public BasePacket 	// // 유인상점 시작시 보내주는 노점 정보
	{
	public:
		int64_t suid{};	// // 개인 노점 uid
	public:
		int32_t profesion_type{};	// // table enum ProfesionType
	public:
		int32_t profesion_make_id{};	// "// 제작은 레시피 아이디, 아닐 경우 0"
	private:
		bool flag_item_reinforce = false;
		mps_street_stall_item_reinforce item_reinforce;	// // 강화
		mps_street_stall_item_reinforce* p_item_reinforce = nullptr;
	public:
		bool has_item_reinforce() const
		{
			return flag_item_reinforce;
		}
		mps_street_stall_item_reinforce* alloc_item_reinforce()
		{
			flag_item_reinforce = true;
			return &item_reinforce;
		}
		const mps_street_stall_item_reinforce* get_item_reinforce() const
		{
			if (true == flag_item_reinforce)
			{
				if (nullptr == p_item_reinforce)
				{
					return &item_reinforce;
				}
				return p_item_reinforce;
			}
			return nullptr;
		}
		void set_item_reinforce(mps_street_stall_item_reinforce* in_item_reinforce)
		{
			if (nullptr == p_item_reinforce)
			{
				p_item_reinforce = in_item_reinforce;
				flag_item_reinforce = true;
			}
		}
	private:
		bool flag_item_luck_reinforce = false;
		mps_street_stall_item_luck_reinforce item_luck_reinforce;	// // 축복 강화
		mps_street_stall_item_luck_reinforce* p_item_luck_reinforce = nullptr;
	public:
		bool has_item_luck_reinforce() const
		{
			return flag_item_luck_reinforce;
		}
		mps_street_stall_item_luck_reinforce* alloc_item_luck_reinforce()
		{
			flag_item_luck_reinforce = true;
			return &item_luck_reinforce;
		}
		const mps_street_stall_item_luck_reinforce* get_item_luck_reinforce() const
		{
			if (true == flag_item_luck_reinforce)
			{
				if (nullptr == p_item_luck_reinforce)
				{
					return &item_luck_reinforce;
				}
				return p_item_luck_reinforce;
			}
			return nullptr;
		}
		void set_item_luck_reinforce(mps_street_stall_item_luck_reinforce* in_item_luck_reinforce)
		{
			if (nullptr == p_item_luck_reinforce)
			{
				p_item_luck_reinforce = in_item_luck_reinforce;
				flag_item_luck_reinforce = true;
			}
		}
	private:
		bool flag_item_enchant_option_change = false;
		mps_street_stall_item_enchant_option_change item_enchant_option_change;	// // 감정
		mps_street_stall_item_enchant_option_change* p_item_enchant_option_change = nullptr;
	public:
		bool has_item_enchant_option_change() const
		{
			return flag_item_enchant_option_change;
		}
		mps_street_stall_item_enchant_option_change* alloc_item_enchant_option_change()
		{
			flag_item_enchant_option_change = true;
			return &item_enchant_option_change;
		}
		const mps_street_stall_item_enchant_option_change* get_item_enchant_option_change() const
		{
			if (true == flag_item_enchant_option_change)
			{
				if (nullptr == p_item_enchant_option_change)
				{
					return &item_enchant_option_change;
				}
				return p_item_enchant_option_change;
			}
			return nullptr;
		}
		void set_item_enchant_option_change(mps_street_stall_item_enchant_option_change* in_item_enchant_option_change)
		{
			if (nullptr == p_item_enchant_option_change)
			{
				p_item_enchant_option_change = in_item_enchant_option_change;
				flag_item_enchant_option_change = true;
			}
		}

	public:
		mp_street_stall_buy_cs() : BasePacket(mpe_cmd::street_stall_buy_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &suid);
			protocol::SerializeType(pBuffer, &profesion_type);
			protocol::SerializeType(pBuffer, &profesion_make_id);
			protocol::SerializeType(pBuffer, &flag_item_reinforce);
			if (true == flag_item_reinforce)
			{
				if (nullptr != p_item_reinforce)
					protocol::SerializeType(pBuffer, p_item_reinforce);
				else
					protocol::SerializeType(pBuffer, &item_reinforce);
			}
			protocol::SerializeType(pBuffer, &flag_item_luck_reinforce);
			if (true == flag_item_luck_reinforce)
			{
				if (nullptr != p_item_luck_reinforce)
					protocol::SerializeType(pBuffer, p_item_luck_reinforce);
				else
					protocol::SerializeType(pBuffer, &item_luck_reinforce);
			}
			protocol::SerializeType(pBuffer, &flag_item_enchant_option_change);
			if (true == flag_item_enchant_option_change)
			{
				if (nullptr != p_item_enchant_option_change)
					protocol::SerializeType(pBuffer, p_item_enchant_option_change);
				else
					protocol::SerializeType(pBuffer, &item_enchant_option_change);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_street_stall_buy_sc : public BasePacket 	// // 유인상점 시작시 보내주는 노점 정보
	{
	public:
		int32_t profesion_type{};
	private:
		bool flag_profesion_make_result = false;
		mps_profesion_update profesion_make_result;
		mps_profesion_update* p_profesion_make_result = nullptr;
	public:
		bool has_profesion_make_result() const
		{
			return flag_profesion_make_result;
		}
		mps_profesion_update* alloc_profesion_make_result()
		{
			flag_profesion_make_result = true;
			return &profesion_make_result;
		}
		const mps_profesion_update* get_profesion_make_result() const
		{
			if (true == flag_profesion_make_result)
			{
				if (nullptr == p_profesion_make_result)
				{
					return &profesion_make_result;
				}
				return p_profesion_make_result;
			}
			return nullptr;
		}
		void set_profesion_make_result(mps_profesion_update* in_profesion_make_result)
		{
			if (nullptr == p_profesion_make_result)
			{
				p_profesion_make_result = in_profesion_make_result;
				flag_profesion_make_result = true;
			}
		}
	private:
		bool flag_item_reinforce_result = false;
		mps_street_stall_item_reinforce_result item_reinforce_result;
		mps_street_stall_item_reinforce_result* p_item_reinforce_result = nullptr;
	public:
		bool has_item_reinforce_result() const
		{
			return flag_item_reinforce_result;
		}
		mps_street_stall_item_reinforce_result* alloc_item_reinforce_result()
		{
			flag_item_reinforce_result = true;
			return &item_reinforce_result;
		}
		const mps_street_stall_item_reinforce_result* get_item_reinforce_result() const
		{
			if (true == flag_item_reinforce_result)
			{
				if (nullptr == p_item_reinforce_result)
				{
					return &item_reinforce_result;
				}
				return p_item_reinforce_result;
			}
			return nullptr;
		}
		void set_item_reinforce_result(mps_street_stall_item_reinforce_result* in_item_reinforce_result)
		{
			if (nullptr == p_item_reinforce_result)
			{
				p_item_reinforce_result = in_item_reinforce_result;
				flag_item_reinforce_result = true;
			}
		}
	private:
		bool flag_item_luck_reinforce_result = false;
		mps_street_stall_item_luck_reinforce_result item_luck_reinforce_result;
		mps_street_stall_item_luck_reinforce_result* p_item_luck_reinforce_result = nullptr;
	public:
		bool has_item_luck_reinforce_result() const
		{
			return flag_item_luck_reinforce_result;
		}
		mps_street_stall_item_luck_reinforce_result* alloc_item_luck_reinforce_result()
		{
			flag_item_luck_reinforce_result = true;
			return &item_luck_reinforce_result;
		}
		const mps_street_stall_item_luck_reinforce_result* get_item_luck_reinforce_result() const
		{
			if (true == flag_item_luck_reinforce_result)
			{
				if (nullptr == p_item_luck_reinforce_result)
				{
					return &item_luck_reinforce_result;
				}
				return p_item_luck_reinforce_result;
			}
			return nullptr;
		}
		void set_item_luck_reinforce_result(mps_street_stall_item_luck_reinforce_result* in_item_luck_reinforce_result)
		{
			if (nullptr == p_item_luck_reinforce_result)
			{
				p_item_luck_reinforce_result = in_item_luck_reinforce_result;
				flag_item_luck_reinforce_result = true;
			}
		}
	private:
		bool flag_item_enchant_option_change_result = false;
		mps_street_stall_item_enchant_option_change_result item_enchant_option_change_result;
		mps_street_stall_item_enchant_option_change_result* p_item_enchant_option_change_result = nullptr;
	public:
		bool has_item_enchant_option_change_result() const
		{
			return flag_item_enchant_option_change_result;
		}
		mps_street_stall_item_enchant_option_change_result* alloc_item_enchant_option_change_result()
		{
			flag_item_enchant_option_change_result = true;
			return &item_enchant_option_change_result;
		}
		const mps_street_stall_item_enchant_option_change_result* get_item_enchant_option_change_result() const
		{
			if (true == flag_item_enchant_option_change_result)
			{
				if (nullptr == p_item_enchant_option_change_result)
				{
					return &item_enchant_option_change_result;
				}
				return p_item_enchant_option_change_result;
			}
			return nullptr;
		}
		void set_item_enchant_option_change_result(mps_street_stall_item_enchant_option_change_result* in_item_enchant_option_change_result)
		{
			if (nullptr == p_item_enchant_option_change_result)
			{
				p_item_enchant_option_change_result = in_item_enchant_option_change_result;
				flag_item_enchant_option_change_result = true;
			}
		}
	public:
		int32_t use_count{};	// // 제작 가능 횟수

	public:
		mp_street_stall_buy_sc() : BasePacket(mpe_cmd::street_stall_buy_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &profesion_type);
			protocol::SerializeType(pBuffer, &flag_profesion_make_result);
			if (true == flag_profesion_make_result)
			{
				if (nullptr != p_profesion_make_result)
					protocol::SerializeType(pBuffer, p_profesion_make_result);
				else
					protocol::SerializeType(pBuffer, &profesion_make_result);
			}
			protocol::SerializeType(pBuffer, &flag_item_reinforce_result);
			if (true == flag_item_reinforce_result)
			{
				if (nullptr != p_item_reinforce_result)
					protocol::SerializeType(pBuffer, p_item_reinforce_result);
				else
					protocol::SerializeType(pBuffer, &item_reinforce_result);
			}
			protocol::SerializeType(pBuffer, &flag_item_luck_reinforce_result);
			if (true == flag_item_luck_reinforce_result)
			{
				if (nullptr != p_item_luck_reinforce_result)
					protocol::SerializeType(pBuffer, p_item_luck_reinforce_result);
				else
					protocol::SerializeType(pBuffer, &item_luck_reinforce_result);
			}
			protocol::SerializeType(pBuffer, &flag_item_enchant_option_change_result);
			if (true == flag_item_enchant_option_change_result)
			{
				if (nullptr != p_item_enchant_option_change_result)
					protocol::SerializeType(pBuffer, p_item_enchant_option_change_result);
				else
					protocol::SerializeType(pBuffer, &item_enchant_option_change_result);
			}
			protocol::SerializeType(pBuffer, &use_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
