#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_trade_darksteelbox_to_token_cs : public BasePacket 	// 제련소 흑철상자를 코인으로 바꿔
	{
	public:
		int64_t item_uid{};	// 흑철상자 아이템 아이디
	public:
		std::string conteact_address{};
	public:
		std::string signature{};	// 유저 사인값
	public:
		std::string contract{};	// contract address 정보 요청한 값
	public:
		std::string user{};	// 유저 wallet id
	public:
		std::string nonce{};	// 컨트랙트 서버에서 조회한 nonce 값
	public:
		std::string column{};	// 액션에 대한 bytes32 값
	public:
		std::string amount{};	// 교환 수량

	public:
		mp_trade_darksteelbox_to_token_cs() : BasePacket(mpe_cmd::trade_darksteelbox_to_token_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &item_uid);
			protocol::SerializeType(pBuffer, &conteact_address);
			protocol::SerializeType(pBuffer, &signature);
			protocol::SerializeType(pBuffer, &contract);
			protocol::SerializeType(pBuffer, &user);
			protocol::SerializeType(pBuffer, &nonce);
			protocol::SerializeType(pBuffer, &column);
			protocol::SerializeType(pBuffer, &amount);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_trade_darksteelbox_to_token_sc : public BasePacket 	// 제련소 흑철상자를 코인으로 바꿔
	{
	public:
		mpe_error result{};
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
		mp_trade_darksteelbox_to_token_sc() : BasePacket(mpe_cmd::trade_darksteelbox_to_token_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
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
