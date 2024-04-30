#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_trade_token_to_darksteelbox_cs : public RpcPacket 	// 토큰을 제련소 흑철상자를 바꿈
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string signature{};	// 유저 사인값
	public:
		std::string contract{};	// contract address 값
	public:
		std::string user{};	// 유저 wallet id
	public:
		std::string nonce{};	// 컨트랙트 서버에서 조회한 nonce 값
	public:
		std::string column{};	// 액션에 대한 bytes32 값
	public:
		std::string amount{};	// 교환 수량 
	public:
		int64_t item_idx{};	// 흑철상자 아이템 idx
	public:
		int64_t item_uid{};	// 흑철상자 아이템 아이디
	private:
		bool flag_info = false;
		mps_item_add info;	// 흑철상자 아이템 정보
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
		int32_t server_gid{};
	public:
		int32_t server_index{};
	public:
		mrpce_server_type server_type{};
	public:
		uint8_t character_tid{};
	public:
		int32_t character_level{};
	public:
		int32_t character_power{};
	public:
		std::string nickname{};

	public:
		mrpc_trade_token_to_darksteelbox_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::trade_token_to_darksteelbox_cs, tag)
		{
		}
		mrpc_trade_token_to_darksteelbox_cs() : RpcPacket(mpe_rpc_cmd::trade_token_to_darksteelbox_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &signature);
			protocol::SerializeType(pBuffer, &contract);
			protocol::SerializeType(pBuffer, &user);
			protocol::SerializeType(pBuffer, &nonce);
			protocol::SerializeType(pBuffer, &column);
			protocol::SerializeType(pBuffer, &amount);
			protocol::SerializeType(pBuffer, &item_idx);
			protocol::SerializeType(pBuffer, &item_uid);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &server_gid);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &character_tid);
			protocol::SerializeType(pBuffer, &character_level);
			protocol::SerializeType(pBuffer, &character_power);
			protocol::SerializeType(pBuffer, &nickname);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_trade_token_to_darksteelbox_sc : public RpcPacket 	// 토큰을 제련소 흑철상자를 바꿈
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t count{};

	public:
		mrpc_trade_token_to_darksteelbox_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::trade_token_to_darksteelbox_sc, tag)
		{
		}
		mrpc_trade_token_to_darksteelbox_sc() : RpcPacket(mpe_rpc_cmd::trade_token_to_darksteelbox_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
