#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mandala_layer_info.h"
#include "struct/mps_mandala_node_info.h"
#include "struct/mps_mandala_layer_info.h"
#include "struct/mps_mandala_node_info.h"
#include "struct/mps_mandala_layer_info.h"
#include "struct/mps_mandala_node_info.h"

namespace mir3d
{
	class mp_game_login_mandala_cs : public BasePacket 
	{

	public:
		mp_game_login_mandala_cs() : BasePacket(mpe_cmd::game_login_mandala_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_game_login_mandala_sc : public BasePacket 
	{
	public:
		std::vector<mps_mandala_layer_info> list_layer{};	// 만다라 레이어
	public:
		std::vector<mps_mandala_node_info> list_node{};	// 만다라 노드
	public:
		std::vector<mps_mandala_layer_info> list_master_layer{};	// 장인만다라 레이어
	public:
		std::vector<mps_mandala_node_info> list_master_node{};	// 장인만다라 노드
	public:
		std::vector<mps_mandala_layer_info> list_season_layer{};	// 시즌만다라 레이어
	public:
		std::vector<mps_mandala_node_info> list_season_node{};	// 시즌만다라 노드

	public:
		mp_game_login_mandala_sc() : BasePacket(mpe_cmd::game_login_mandala_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_layer);
			protocol::SerializeType(pBuffer, &list_node);
			protocol::SerializeType(pBuffer, &list_master_layer);
			protocol::SerializeType(pBuffer, &list_master_node);
			protocol::SerializeType(pBuffer, &list_season_layer);
			protocol::SerializeType(pBuffer, &list_season_node);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
