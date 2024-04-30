#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_equip_info_list.h"

namespace mir3d
{
	class mrpc_show_costume_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		uint8_t show_costume{};	// 코스튬 숨김 정보
	private:
		bool flag_look_info = false;
		mps_equip_info_list look_info;
		mps_equip_info_list* p_look_info = nullptr;
	public:
		bool has_look_info() const
		{
			return flag_look_info;
		}
		mps_equip_info_list* alloc_look_info()
		{
			flag_look_info = true;
			return &look_info;
		}
		const mps_equip_info_list* get_look_info() const
		{
			if (true == flag_look_info)
			{
				if (nullptr == p_look_info)
				{
					return &look_info;
				}
				return p_look_info;
			}
			return nullptr;
		}
		void set_look_info(mps_equip_info_list* in_look_info)
		{
			if (nullptr == p_look_info)
			{
				p_look_info = in_look_info;
				flag_look_info = true;
			}
		}
	public:
		int32_t reflection_id{};	// 화신정보
	public:
		uint16_t customizing_data{};

	public:
		mrpc_show_costume_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::show_costume_cs, tag)
		{
		}
		mrpc_show_costume_cs() : RpcPacket(mpe_rpc_cmd::show_costume_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &show_costume);
			protocol::SerializeType(pBuffer, &flag_look_info);
			if (true == flag_look_info)
			{
				if (nullptr != p_look_info)
					protocol::SerializeType(pBuffer, p_look_info);
				else
					protocol::SerializeType(pBuffer, &look_info);
			}
			protocol::SerializeType(pBuffer, &reflection_id);
			protocol::SerializeType(pBuffer, &customizing_data);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_show_costume_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_show_costume_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::show_costume_sc, tag)
		{
		}
		mrpc_show_costume_sc() : RpcPacket(mpe_rpc_cmd::show_costume_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
