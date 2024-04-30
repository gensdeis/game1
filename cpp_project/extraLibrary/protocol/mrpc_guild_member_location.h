#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_vector.h"
#include "struct/mps_vector.h"

namespace mir3d
{
	class mrpc_guild_member_location_cs : public RpcPacket 	// "길드멤버에 내 위치 공유"
	{
	public:
		int64_t s_cuid{};	// "발송자 cuid"
	public:
		int64_t guid{};	// "길드 uid"
	public:
		std::string s_nick{};	// "발송자 닉네임"
	public:
		int32_t zone_id{};
	private:
		bool flag_pos = false;
		mps_vector pos;	// "위치"
		mps_vector* p_pos = nullptr;
	public:
		bool has_pos() const
		{
			return flag_pos;
		}
		mps_vector* alloc_pos()
		{
			flag_pos = true;
			return &pos;
		}
		const mps_vector* get_pos() const
		{
			if (true == flag_pos)
			{
				if (nullptr == p_pos)
				{
					return &pos;
				}
				return p_pos;
			}
			return nullptr;
		}
		void set_pos(mps_vector* in_pos)
		{
			if (nullptr == p_pos)
			{
				p_pos = in_pos;
				flag_pos = true;
			}
		}

	public:
		mrpc_guild_member_location_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_member_location_cs, tag)
		{
		}
		mrpc_guild_member_location_cs() : RpcPacket(mpe_rpc_cmd::guild_member_location_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &s_cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &s_nick);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &flag_pos);
			if (true == flag_pos)
			{
				if (nullptr != p_pos)
					protocol::SerializeType(pBuffer, p_pos);
				else
					protocol::SerializeType(pBuffer, &pos);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_member_location_sc : public RpcPacket 	// "길드멤버에 내 위치 공유"
	{
	public:
		std::vector<int64_t> list_cuid{};	// "패킷받아야할 대상"
	public:
		int64_t s_cuid{};	// "발송자 cuid"
	public:
		std::string s_nick{};	// "발송자 닉네임"
	public:
		short ch_id{};	// "채널id"
	public:
		int32_t zone_id{};
	private:
		bool flag_pos = false;
		mps_vector pos;	// "위치"
		mps_vector* p_pos = nullptr;
	public:
		bool has_pos() const
		{
			return flag_pos;
		}
		mps_vector* alloc_pos()
		{
			flag_pos = true;
			return &pos;
		}
		const mps_vector* get_pos() const
		{
			if (true == flag_pos)
			{
				if (nullptr == p_pos)
				{
					return &pos;
				}
				return p_pos;
			}
			return nullptr;
		}
		void set_pos(mps_vector* in_pos)
		{
			if (nullptr == p_pos)
			{
				p_pos = in_pos;
				flag_pos = true;
			}
		}

	public:
		mrpc_guild_member_location_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_member_location_sc, tag)
		{
		}
		mrpc_guild_member_location_sc() : RpcPacket(mpe_rpc_cmd::guild_member_location_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &s_cuid);
			protocol::SerializeType(pBuffer, &s_nick);
			protocol::SerializeType(pBuffer, &ch_id);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &flag_pos);
			if (true == flag_pos)
			{
				if (nullptr != p_pos)
					protocol::SerializeType(pBuffer, p_pos);
				else
					protocol::SerializeType(pBuffer, &pos);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
