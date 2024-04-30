#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_meridians.h"
#include "struct/mps_item_add.h"
#include "struct/mps_skill.h"

namespace mir3d
{
	class mp_meridians_levelup_cs : public BasePacket 	// 경락 levelup
	{
	public:
		int32_t meridians_id{};

	public:
		mp_meridians_levelup_cs() : BasePacket(mpe_cmd::meridians_levelup_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &meridians_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_meridians_levelup_sc : public BasePacket 	// 경락 levelup
	{
	private:
		bool flag_meridians = false;
		mps_meridians meridians;
		mps_meridians* p_meridians = nullptr;
	public:
		bool has_meridians() const
		{
			return flag_meridians;
		}
		mps_meridians* alloc_meridians()
		{
			flag_meridians = true;
			return &meridians;
		}
		const mps_meridians* get_meridians() const
		{
			if (true == flag_meridians)
			{
				if (nullptr == p_meridians)
				{
					return &meridians;
				}
				return p_meridians;
			}
			return nullptr;
		}
		void set_meridians(mps_meridians* in_meridians)
		{
			if (nullptr == p_meridians)
			{
				p_meridians = in_meridians;
				flag_meridians = true;
			}
		}
	private:
		bool flag_info = false;
		mps_item_add info;
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
	private:
		bool flag_learn_skill = false;
		mps_skill learn_skill;
		mps_skill* p_learn_skill = nullptr;
	public:
		bool has_learn_skill() const
		{
			return flag_learn_skill;
		}
		mps_skill* alloc_learn_skill()
		{
			flag_learn_skill = true;
			return &learn_skill;
		}
		const mps_skill* get_learn_skill() const
		{
			if (true == flag_learn_skill)
			{
				if (nullptr == p_learn_skill)
				{
					return &learn_skill;
				}
				return p_learn_skill;
			}
			return nullptr;
		}
		void set_learn_skill(mps_skill* in_learn_skill)
		{
			if (nullptr == p_learn_skill)
			{
				p_learn_skill = in_learn_skill;
				flag_learn_skill = true;
			}
		}

	public:
		mp_meridians_levelup_sc() : BasePacket(mpe_cmd::meridians_levelup_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_meridians);
			if (true == flag_meridians)
			{
				if (nullptr != p_meridians)
					protocol::SerializeType(pBuffer, p_meridians);
				else
					protocol::SerializeType(pBuffer, &meridians);
			}
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_learn_skill);
			if (true == flag_learn_skill)
			{
				if (nullptr != p_learn_skill)
					protocol::SerializeType(pBuffer, p_learn_skill);
				else
					protocol::SerializeType(pBuffer, &learn_skill);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
