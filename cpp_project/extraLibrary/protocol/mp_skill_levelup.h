#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_skill.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_skill_levelup_cs : public BasePacket 
	{
	public:
		int32_t tid{};	// // 무공서 ID
	public:
		int32_t count{};	// // 무공서 개수 (M3 : 레벨업에 필요한 무공서 개수는 테이블로 정의하기 때문에 필요 없음)

	public:
		mp_skill_levelup_cs() : BasePacket(mpe_cmd::skill_levelup_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_skill_levelup_sc : public BasePacket 
	{
	public:
		bool flag{};	// "// true : item 사용, false : 스킬 사용 레벨 업 (M3 : 스킬 사용할 때 레벨업 안함)"
	public:
		float weight{};
	private:
		bool flag_skill = false;
		mps_skill skill;	// // 변경되는 무공 정보
		mps_skill* p_skill = nullptr;
	public:
		bool has_skill() const
		{
			return flag_skill;
		}
		mps_skill* alloc_skill()
		{
			flag_skill = true;
			return &skill;
		}
		const mps_skill* get_skill() const
		{
			if (true == flag_skill)
			{
				if (nullptr == p_skill)
				{
					return &skill;
				}
				return p_skill;
			}
			return nullptr;
		}
		void set_skill(mps_skill* in_skill)
		{
			if (nullptr == p_skill)
			{
				p_skill = in_skill;
				flag_skill = true;
			}
		}
	private:
		bool flag_info = false;
		mps_item_add info;	// // 변경되는 아이템/재화 (M3 : 금전도 변경됨)
		mps_item_add* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_add* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_add* get_info() const
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
		void set_info(mps_item_add* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_skill_levelup_sc() : BasePacket(mpe_cmd::skill_levelup_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag);
			protocol::SerializeType(pBuffer, &weight);
			protocol::SerializeType(pBuffer, &flag_skill);
			if (true == flag_skill)
			{
				if (nullptr != p_skill)
					protocol::SerializeType(pBuffer, p_skill);
				else
					protocol::SerializeType(pBuffer, &skill);
			}
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
