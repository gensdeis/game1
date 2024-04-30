#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_seasonpass.h"
#include "struct/mps_seasonpass_challenge.h"
#include "struct/mps_update_goods.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_seasonpass_challenge_complet_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_seasonpass = false;
		mps_seasonpass seasonpass;
		mps_seasonpass* p_seasonpass = nullptr;
	public:
		bool has_seasonpass() const
		{
			return flag_seasonpass;
		}
		mps_seasonpass* alloc_seasonpass()
		{
			flag_seasonpass = true;
			return &seasonpass;
		}
		const mps_seasonpass* get_seasonpass() const
		{
			if (true == flag_seasonpass)
			{
				if (nullptr == p_seasonpass)
				{
					return &seasonpass;
				}
				return p_seasonpass;
			}
			return nullptr;
		}
		void set_seasonpass(mps_seasonpass* in_seasonpass)
		{
			if (nullptr == p_seasonpass)
			{
				p_seasonpass = in_seasonpass;
				flag_seasonpass = true;
			}
		}
	private:
		bool flag_challenge = false;
		mps_seasonpass_challenge challenge;
		mps_seasonpass_challenge* p_challenge = nullptr;
	public:
		bool has_challenge() const
		{
			return flag_challenge;
		}
		mps_seasonpass_challenge* alloc_challenge()
		{
			flag_challenge = true;
			return &challenge;
		}
		const mps_seasonpass_challenge* get_challenge() const
		{
			if (true == flag_challenge)
			{
				if (nullptr == p_challenge)
				{
					return &challenge;
				}
				return p_challenge;
			}
			return nullptr;
		}
		void set_challenge(mps_seasonpass_challenge* in_challenge)
		{
			if (nullptr == p_challenge)
			{
				p_challenge = in_challenge;
				flag_challenge = true;
			}
		}
	private:
		bool flag_goods = false;
		mps_update_goods goods;
		mps_update_goods* p_goods = nullptr;
	public:
		bool has_goods() const
		{
			return flag_goods;
		}
		mps_update_goods* alloc_goods()
		{
			flag_goods = true;
			return &goods;
		}
		const mps_update_goods* get_goods() const
		{
			if (true == flag_goods)
			{
				if (nullptr == p_goods)
				{
					return &goods;
				}
				return p_goods;
			}
			return nullptr;
		}
		void set_goods(mps_update_goods* in_goods)
		{
			if (nullptr == p_goods)
			{
				p_goods = in_goods;
				flag_goods = true;
			}
		}
	private:
		bool flag_item_add = false;
		mps_item_add item_add;
		mps_item_add* p_item_add = nullptr;
	public:
		bool has_item_add() const
		{
			return flag_item_add;
		}
		mps_item_add* alloc_item_add()
		{
			flag_item_add = true;
			return &item_add;
		}
		const mps_item_add* get_item_add() const
		{
			if (true == flag_item_add)
			{
				if (nullptr == p_item_add)
				{
					return &item_add;
				}
				return p_item_add;
			}
			return nullptr;
		}
		void set_item_add(mps_item_add* in_item_add)
		{
			if (nullptr == p_item_add)
			{
				p_item_add = in_item_add;
				flag_item_add = true;
			}
		}

	public:
		mrpc_seasonpass_challenge_complet_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::seasonpass_challenge_complet_cs, tag)
		{
		}
		mrpc_seasonpass_challenge_complet_cs() : RpcPacket(mpe_rpc_cmd::seasonpass_challenge_complet_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_seasonpass);
			if (true == flag_seasonpass)
			{
				if (nullptr != p_seasonpass)
					protocol::SerializeType(pBuffer, p_seasonpass);
				else
					protocol::SerializeType(pBuffer, &seasonpass);
			}
			protocol::SerializeType(pBuffer, &flag_challenge);
			if (true == flag_challenge)
			{
				if (nullptr != p_challenge)
					protocol::SerializeType(pBuffer, p_challenge);
				else
					protocol::SerializeType(pBuffer, &challenge);
			}
			protocol::SerializeType(pBuffer, &flag_goods);
			if (true == flag_goods)
			{
				if (nullptr != p_goods)
					protocol::SerializeType(pBuffer, p_goods);
				else
					protocol::SerializeType(pBuffer, &goods);
			}
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_seasonpass_challenge_complet_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_seasonpass_challenge_complet_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::seasonpass_challenge_complet_sc, tag)
		{
		}
		mrpc_seasonpass_challenge_complet_sc() : RpcPacket(mpe_rpc_cmd::seasonpass_challenge_complet_sc)
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
