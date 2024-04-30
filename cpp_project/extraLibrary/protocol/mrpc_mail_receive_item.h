#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_item_add.h"
#include "struct/mrpcs_enchant_stone_info.h"

namespace mir3d
{
	class mrpc_mail_receive_item_cs : public RpcPacket 	// 메일 아이템 받기
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		mpe_mail_type mail_type{};
	public:
		std::vector<int64_t> muid{};
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
	public:
		mpe_mail_state state{};
	public:
		std::vector<int64_t> list_iuid{};
	public:
		mpe_error result_code{};

	public:
		mrpc_mail_receive_item_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mail_receive_item_cs, tag)
		{
		}
		mrpc_mail_receive_item_cs() : RpcPacket(mpe_rpc_cmd::mail_receive_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &mail_type);
			protocol::SerializeType(pBuffer, &muid);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &list_iuid);
			protocol::SerializeEnum(pBuffer, &result_code);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_mail_receive_item_sc : public RpcPacket 	// 메일 아이템 받기
	{
	public:
		int64_t key{};
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
	public:
		std::vector<int64_t> muid{};
	private:
		bool flag_enchant_stone_info = false;
		mrpcs_enchant_stone_info enchant_stone_info;
		mrpcs_enchant_stone_info* p_enchant_stone_info = nullptr;
	public:
		bool has_enchant_stone_info() const
		{
			return flag_enchant_stone_info;
		}
		mrpcs_enchant_stone_info* alloc_enchant_stone_info()
		{
			flag_enchant_stone_info = true;
			return &enchant_stone_info;
		}
		const mrpcs_enchant_stone_info* get_enchant_stone_info() const
		{
			if (true == flag_enchant_stone_info)
			{
				if (nullptr == p_enchant_stone_info)
				{
					return &enchant_stone_info;
				}
				return p_enchant_stone_info;
			}
			return nullptr;
		}
		void set_enchant_stone_info(mrpcs_enchant_stone_info* in_enchant_stone_info)
		{
			if (nullptr == p_enchant_stone_info)
			{
				p_enchant_stone_info = in_enchant_stone_info;
				flag_enchant_stone_info = true;
			}
		}
	public:
		std::vector<int64_t> list_iuid{};
	public:
		mpe_error result_code{};

	public:
		mrpc_mail_receive_item_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mail_receive_item_sc, tag)
		{
		}
		mrpc_mail_receive_item_sc() : RpcPacket(mpe_rpc_cmd::mail_receive_item_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &muid);
			protocol::SerializeType(pBuffer, &flag_enchant_stone_info);
			if (true == flag_enchant_stone_info)
			{
				if (nullptr != p_enchant_stone_info)
					protocol::SerializeType(pBuffer, p_enchant_stone_info);
				else
					protocol::SerializeType(pBuffer, &enchant_stone_info);
			}
			protocol::SerializeType(pBuffer, &list_iuid);
			protocol::SerializeEnum(pBuffer, &result_code);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
