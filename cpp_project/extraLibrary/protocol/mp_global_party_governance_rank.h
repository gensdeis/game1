#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_governance_rank.h"
#include "struct/mps_party_governance_rank.h"

namespace mir3d
{
	class mp_global_party_governance_rank_cs : public BasePacket 
	{
	public:
		mpe_global_party_governance_rank_type type{};
	public:
		uint8_t page{};

	public:
		mp_global_party_governance_rank_cs() : BasePacket(mpe_cmd::global_party_governance_rank_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &page);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_global_party_governance_rank_sc : public BasePacket 
	{
	public:
		mpe_global_party_governance_rank_type type{};
	public:
		uint8_t cur_page{};
	public:
		uint8_t max_page{};
	public:
		std::vector<mps_party_governance_rank> list{};
	private:
		bool flag_myinfo = false;
		mps_party_governance_rank myinfo;
		mps_party_governance_rank* p_myinfo = nullptr;
	public:
		bool has_myinfo() const
		{
			return flag_myinfo;
		}
		mps_party_governance_rank* alloc_myinfo()
		{
			flag_myinfo = true;
			return &myinfo;
		}
		const mps_party_governance_rank* get_myinfo() const
		{
			if (true == flag_myinfo)
			{
				if (nullptr == p_myinfo)
				{
					return &myinfo;
				}
				return p_myinfo;
			}
			return nullptr;
		}
		void set_myinfo(mps_party_governance_rank* in_myinfo)
		{
			if (nullptr == p_myinfo)
			{
				p_myinfo = in_myinfo;
				flag_myinfo = true;
			}
		}

	public:
		mp_global_party_governance_rank_sc() : BasePacket(mpe_cmd::global_party_governance_rank_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &cur_page);
			protocol::SerializeType(pBuffer, &max_page);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &flag_myinfo);
			if (true == flag_myinfo)
			{
				if (nullptr != p_myinfo)
					protocol::SerializeType(pBuffer, p_myinfo);
				else
					protocol::SerializeType(pBuffer, &myinfo);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
