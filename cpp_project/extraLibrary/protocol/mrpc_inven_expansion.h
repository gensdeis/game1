#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods_list.h"

namespace mir3d
{
	class mrpc_inven_expansion_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		mrpce_inven_expansion flag{};
	public:
		int32_t size{};
	private:
		bool flag_info = false;
		mps_update_goods_list info;
		mps_update_goods_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_update_goods_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_update_goods_list* get_info() const
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
		void set_info(mps_update_goods_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_inven_expansion_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::inven_expansion_cs, tag)
		{
		}
		mrpc_inven_expansion_cs() : RpcPacket(mpe_rpc_cmd::inven_expansion_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &flag);
			protocol::SerializeType(pBuffer, &size);
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
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_inven_expansion_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_inven_expansion_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::inven_expansion_sc, tag)
		{
		}
		mrpc_inven_expansion_sc() : RpcPacket(mpe_rpc_cmd::inven_expansion_sc)
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
