#pragma once
#include <ostream>
#include <protocol/base_protocol.h>
#include <protocol/rpc_protocol.h>

namespace mir3d
{
	static std::ostream& operator << (std::ostream& out, const mpe_rpc_cmd& value)
	{
		switch (value)
		{
		case mpe_rpc_cmd::none:
			out << "none"; 
			break;
		case mpe_rpc_cmd::table_load_cs:
			out << "table_load_cs"; 
			break;
		case mpe_rpc_cmd::table_load_sc:
			out << "table_load_sc"; 
			break;
		case mpe_rpc_cmd::table_reload_cs:
			out << "table_reload_cs"; 
			break;
		case mpe_rpc_cmd::table_reload_sc:
			out << "table_reload_sc"; 
			break;
		case mpe_rpc_cmd::update_redis_rpcinfo_cs:
			out << "update_redis_rpcinfo_cs"; 
			break;
		case mpe_rpc_cmd::update_redis_rpcinfo_sc:
			out << "update_redis_rpcinfo_sc"; 
			break;
		case mpe_rpc_cmd::get_redis_rpcinfo_cs:
			out << "get_redis_rpcinfo_cs"; 
			break;
		case mpe_rpc_cmd::get_redis_rpcinfo_sc:
			out << "get_redis_rpcinfo_sc"; 
			break;
		case mpe_rpc_cmd::update_redis_serverinfo_cs:
			out << "update_redis_serverinfo_cs"; 
			break;
		case mpe_rpc_cmd::update_redis_serverinfo_sc:
			out << "update_redis_serverinfo_sc"; 
			break;
		case mpe_rpc_cmd::server_patch_cs:
			out << "server_patch_cs"; 
			break;
		case mpe_rpc_cmd::server_patch_sc:
			out << "server_patch_sc"; 
			break;
		case mpe_rpc_cmd::server_control_cs:
			out << "server_control_cs"; 
			break;
		case mpe_rpc_cmd::server_control_sc:
			out << "server_control_sc"; 
			break;
		case mpe_rpc_cmd::connector_rpcinfo_cs:
			out << "connector_rpcinfo_cs"; 
			break;
		case mpe_rpc_cmd::connector_rpcinfo_sc:
			out << "connector_rpcinfo_sc"; 
			break;
		case mpe_rpc_cmd::action_log_cs:
			out << "action_log_cs"; 
			break;
		case mpe_rpc_cmd::action_log_sc:
			out << "action_log_sc"; 
			break;
		case mpe_rpc_cmd::heartbeat_check_cs:
			out << "heartbeat_check_cs"; 
			break;
		case mpe_rpc_cmd::heartbeat_check_sc:
			out << "heartbeat_check_sc"; 
			break;
		case mpe_rpc_cmd::cash_shop_item_list_cs:
			out << "cash_shop_item_list_cs"; 
			break;
		case mpe_rpc_cmd::cash_shop_item_list_sc:
			out << "cash_shop_item_list_sc"; 
			break;
		case mpe_rpc_cmd::websocket_session_certify_cs:
			out << "websocket_session_certify_cs"; 
			break;
		case mpe_rpc_cmd::websocket_session_certify_sc:
			out << "websocket_session_certify_sc"; 
			break;
		case mpe_rpc_cmd::websocket_update_gmserver_manage_info_cs:
			out << "websocket_update_gmserver_manage_info_cs"; 
			break;
		case mpe_rpc_cmd::websocket_update_gmserver_manage_info_sc:
			out << "websocket_update_gmserver_manage_info_sc"; 
			break;
		case mpe_rpc_cmd::websocket_get_gmserver_manage_info_cs:
			out << "websocket_get_gmserver_manage_info_cs"; 
			break;
		case mpe_rpc_cmd::websocket_get_gmserver_manage_info_sc:
			out << "websocket_get_gmserver_manage_info_sc"; 
			break;
		case mpe_rpc_cmd::update_gamemanger_to_gmserver_ccu_info_cs:
			out << "update_gamemanger_to_gmserver_ccu_info_cs"; 
			break;
		case mpe_rpc_cmd::update_gamemanger_to_gmserver_ccu_info_sc:
			out << "update_gamemanger_to_gmserver_ccu_info_sc"; 
			break;
		case mpe_rpc_cmd::websocket_update_gmserver_gmmanager_ccu_info_cs:
			out << "websocket_update_gmserver_gmmanager_ccu_info_cs"; 
			break;
		case mpe_rpc_cmd::websocket_update_gmserver_gmmanager_ccu_info_sc:
			out << "websocket_update_gmserver_gmmanager_ccu_info_sc"; 
			break;
		case mpe_rpc_cmd::websocket_get_server_ccu_info_cs:
			out << "websocket_get_server_ccu_info_cs"; 
			break;
		case mpe_rpc_cmd::websocket_get_server_ccu_info_sc:
			out << "websocket_get_server_ccu_info_sc"; 
			break;
		case mpe_rpc_cmd::update_speed_hack_check_cs:
			out << "update_speed_hack_check_cs"; 
			break;
		case mpe_rpc_cmd::update_speed_hack_check_sc:
			out << "update_speed_hack_check_sc"; 
			break;
		case mpe_rpc_cmd::update_not_allow_packet_cs:
			out << "update_not_allow_packet_cs"; 
			break;
		case mpe_rpc_cmd::update_not_allow_packet_sc:
			out << "update_not_allow_packet_sc"; 
			break;
		case mpe_rpc_cmd::player_connect_info_cs:
			out << "player_connect_info_cs"; 
			break;
		case mpe_rpc_cmd::player_connect_info_sc:
			out << "player_connect_info_sc"; 
			break;
		case mpe_rpc_cmd::update_use_not_allow_duplication_login_cs:
			out << "update_use_not_allow_duplication_login_cs"; 
			break;
		case mpe_rpc_cmd::update_use_not_allow_duplication_login_sc:
			out << "update_use_not_allow_duplication_login_sc"; 
			break;
		case mpe_rpc_cmd::lobby_login_cs:
			out << "lobby_login_cs"; 
			break;
		case mpe_rpc_cmd::lobby_login_sc:
			out << "lobby_login_sc"; 
			break;
		case mpe_rpc_cmd::lobby_duplicate_login_cs:
			out << "lobby_duplicate_login_cs"; 
			break;
		case mpe_rpc_cmd::lobby_duplicate_login_sc:
			out << "lobby_duplicate_login_sc"; 
			break;
		case mpe_rpc_cmd::player_server_change_cs:
			out << "player_server_change_cs"; 
			break;
		case mpe_rpc_cmd::player_server_change_sc:
			out << "player_server_change_sc"; 
			break;
		case mpe_rpc_cmd::player_game_login_cs:
			out << "player_game_login_cs"; 
			break;
		case mpe_rpc_cmd::player_game_login_sc:
			out << "player_game_login_sc"; 
			break;
		case mpe_rpc_cmd::game_balance_cs:
			out << "game_balance_cs"; 
			break;
		case mpe_rpc_cmd::game_balance_sc:
			out << "game_balance_sc"; 
			break;
		case mpe_rpc_cmd::server_redirect_cs:
			out << "server_redirect_cs"; 
			break;
		case mpe_rpc_cmd::server_redirect_sc:
			out << "server_redirect_sc"; 
			break;
		case mpe_rpc_cmd::indun_create_cs:
			out << "indun_create_cs"; 
			break;
		case mpe_rpc_cmd::indun_create_sc:
			out << "indun_create_sc"; 
			break;
		case mpe_rpc_cmd::community_info_cs:
			out << "community_info_cs"; 
			break;
		case mpe_rpc_cmd::community_info_sc:
			out << "community_info_sc"; 
			break;
		case mpe_rpc_cmd::community_info2_cs:
			out << "community_info2_cs"; 
			break;
		case mpe_rpc_cmd::community_info2_sc:
			out << "community_info2_sc"; 
			break;
		case mpe_rpc_cmd::game_event_info_cs:
			out << "game_event_info_cs"; 
			break;
		case mpe_rpc_cmd::game_event_info_sc:
			out << "game_event_info_sc"; 
			break;
		case mpe_rpc_cmd::indun_enter_complete_cs:
			out << "indun_enter_complete_cs"; 
			break;
		case mpe_rpc_cmd::indun_enter_complete_sc:
			out << "indun_enter_complete_sc"; 
			break;
		case mpe_rpc_cmd::indun_member_request_cs:
			out << "indun_member_request_cs"; 
			break;
		case mpe_rpc_cmd::indun_member_request_sc:
			out << "indun_member_request_sc"; 
			break;
		case mpe_rpc_cmd::indun_member_response_cs:
			out << "indun_member_response_cs"; 
			break;
		case mpe_rpc_cmd::indun_member_response_sc:
			out << "indun_member_response_sc"; 
			break;
		case mpe_rpc_cmd::character_enter_request_cs:
			out << "character_enter_request_cs"; 
			break;
		case mpe_rpc_cmd::character_enter_request_sc:
			out << "character_enter_request_sc"; 
			break;
		case mpe_rpc_cmd::character_enter_response_cs:
			out << "character_enter_response_cs"; 
			break;
		case mpe_rpc_cmd::character_enter_response_sc:
			out << "character_enter_response_sc"; 
			break;
		case mpe_rpc_cmd::nickname_create_cs:
			out << "nickname_create_cs"; 
			break;
		case mpe_rpc_cmd::nickname_create_sc:
			out << "nickname_create_sc"; 
			break;
		case mpe_rpc_cmd::character_create_cs:
			out << "character_create_cs"; 
			break;
		case mpe_rpc_cmd::character_create_sc:
			out << "character_create_sc"; 
			break;
		case mpe_rpc_cmd::character_select_cs:
			out << "character_select_cs"; 
			break;
		case mpe_rpc_cmd::character_select_sc:
			out << "character_select_sc"; 
			break;
		case mpe_rpc_cmd::character_autosave_cs:
			out << "character_autosave_cs"; 
			break;
		case mpe_rpc_cmd::character_autosave_sc:
			out << "character_autosave_sc"; 
			break;
		case mpe_rpc_cmd::character_search_cs:
			out << "character_search_cs"; 
			break;
		case mpe_rpc_cmd::character_search_sc:
			out << "character_search_sc"; 
			break;
		case mpe_rpc_cmd::character_redirect_cs:
			out << "character_redirect_cs"; 
			break;
		case mpe_rpc_cmd::character_redirect_sc:
			out << "character_redirect_sc"; 
			break;
		case mpe_rpc_cmd::inven_expansion_cs:
			out << "inven_expansion_cs"; 
			break;
		case mpe_rpc_cmd::inven_expansion_sc:
			out << "inven_expansion_sc"; 
			break;
		case mpe_rpc_cmd::inven_weight_expansion_cs:
			out << "inven_weight_expansion_cs"; 
			break;
		case mpe_rpc_cmd::inven_weight_expansion_sc:
			out << "inven_weight_expansion_sc"; 
			break;
		case mpe_rpc_cmd::item_buy_cs:
			out << "item_buy_cs"; 
			break;
		case mpe_rpc_cmd::item_buy_sc:
			out << "item_buy_sc"; 
			break;
		case mpe_rpc_cmd::item_sell_cs:
			out << "item_sell_cs"; 
			break;
		case mpe_rpc_cmd::item_sell_sc:
			out << "item_sell_sc"; 
			break;
		case mpe_rpc_cmd::item_equip_cs:
			out << "item_equip_cs"; 
			break;
		case mpe_rpc_cmd::item_equip_sc:
			out << "item_equip_sc"; 
			break;
		case mpe_rpc_cmd::item_use_cs:
			out << "item_use_cs"; 
			break;
		case mpe_rpc_cmd::item_use_sc:
			out << "item_use_sc"; 
			break;
		case mpe_rpc_cmd::item_reinforce_cs:
			out << "item_reinforce_cs"; 
			break;
		case mpe_rpc_cmd::item_reinforce_sc:
			out << "item_reinforce_sc"; 
			break;
		case mpe_rpc_cmd::item_make_cs:
			out << "item_make_cs"; 
			break;
		case mpe_rpc_cmd::item_make_sc:
			out << "item_make_sc"; 
			break;
		case mpe_rpc_cmd::item_drop_cs:
			out << "item_drop_cs"; 
			break;
		case mpe_rpc_cmd::item_drop_sc:
			out << "item_drop_sc"; 
			break;
		case mpe_rpc_cmd::item_destroy_cs:
			out << "item_destroy_cs"; 
			break;
		case mpe_rpc_cmd::item_destroy_sc:
			out << "item_destroy_sc"; 
			break;
		case mpe_rpc_cmd::item_luck_reinforce_cs:
			out << "item_luck_reinforce_cs"; 
			break;
		case mpe_rpc_cmd::item_luck_reinforce_sc:
			out << "item_luck_reinforce_sc"; 
			break;
		case mpe_rpc_cmd::item_enchant_option_make_cs:
			out << "item_enchant_option_make_cs"; 
			break;
		case mpe_rpc_cmd::item_enchant_option_make_sc:
			out << "item_enchant_option_make_sc"; 
			break;
		case mpe_rpc_cmd::item_enchant_option_select_cs:
			out << "item_enchant_option_select_cs"; 
			break;
		case mpe_rpc_cmd::item_enchant_option_select_sc:
			out << "item_enchant_option_select_sc"; 
			break;
		case mpe_rpc_cmd::item_decompose_cs:
			out << "item_decompose_cs"; 
			break;
		case mpe_rpc_cmd::item_decompose_sc:
			out << "item_decompose_sc"; 
			break;
		case mpe_rpc_cmd::quest_accept_cs:
			out << "quest_accept_cs"; 
			break;
		case mpe_rpc_cmd::quest_accept_sc:
			out << "quest_accept_sc"; 
			break;
		case mpe_rpc_cmd::quest_finish_cs:
			out << "quest_finish_cs"; 
			break;
		case mpe_rpc_cmd::quest_finish_sc:
			out << "quest_finish_sc"; 
			break;
		case mpe_rpc_cmd::quest_giveup_cs:
			out << "quest_giveup_cs"; 
			break;
		case mpe_rpc_cmd::quest_giveup_sc:
			out << "quest_giveup_sc"; 
			break;
		case mpe_rpc_cmd::quest_complete_cs:
			out << "quest_complete_cs"; 
			break;
		case mpe_rpc_cmd::quest_complete_sc:
			out << "quest_complete_sc"; 
			break;
		case mpe_rpc_cmd::repute_quest_get_list_cs:
			out << "repute_quest_get_list_cs"; 
			break;
		case mpe_rpc_cmd::repute_quest_get_list_sc:
			out << "repute_quest_get_list_sc"; 
			break;
		case mpe_rpc_cmd::repute_quest_refresh_list_cs:
			out << "repute_quest_refresh_list_cs"; 
			break;
		case mpe_rpc_cmd::repute_quest_refresh_list_sc:
			out << "repute_quest_refresh_list_sc"; 
			break;
		case mpe_rpc_cmd::gameitem_update_cs:
			out << "gameitem_update_cs"; 
			break;
		case mpe_rpc_cmd::gameitem_update_sc:
			out << "gameitem_update_sc"; 
			break;
		case mpe_rpc_cmd::zone_item_pickup_cs:
			out << "zone_item_pickup_cs"; 
			break;
		case mpe_rpc_cmd::zone_item_pickup_sc:
			out << "zone_item_pickup_sc"; 
			break;
		case mpe_rpc_cmd::zone_object_collect_cs:
			out << "zone_object_collect_cs"; 
			break;
		case mpe_rpc_cmd::zone_object_collect_sc:
			out << "zone_object_collect_sc"; 
			break;
		case mpe_rpc_cmd::zone_fish_cs:
			out << "zone_fish_cs"; 
			break;
		case mpe_rpc_cmd::zone_fish_sc:
			out << "zone_fish_sc"; 
			break;
		case mpe_rpc_cmd::pk_record_viewed_cs:
			out << "pk_record_viewed_cs"; 
			break;
		case mpe_rpc_cmd::pk_record_viewed_sc:
			out << "pk_record_viewed_sc"; 
			break;
		case mpe_rpc_cmd::mail_send_cs:
			out << "mail_send_cs"; 
			break;
		case mpe_rpc_cmd::mail_send_sc:
			out << "mail_send_sc"; 
			break;
		case mpe_rpc_cmd::mail_open_cs:
			out << "mail_open_cs"; 
			break;
		case mpe_rpc_cmd::mail_open_sc:
			out << "mail_open_sc"; 
			break;
		case mpe_rpc_cmd::mail_receive_item_cs:
			out << "mail_receive_item_cs"; 
			break;
		case mpe_rpc_cmd::mail_receive_item_sc:
			out << "mail_receive_item_sc"; 
			break;
		case mpe_rpc_cmd::mail_delete_cs:
			out << "mail_delete_cs"; 
			break;
		case mpe_rpc_cmd::mail_delete_sc:
			out << "mail_delete_sc"; 
			break;
		case mpe_rpc_cmd::profesion_make_cs:
			out << "profesion_make_cs"; 
			break;
		case mpe_rpc_cmd::profesion_make_sc:
			out << "profesion_make_sc"; 
			break;
		case mpe_rpc_cmd::profesion_upgrade_cs:
			out << "profesion_upgrade_cs"; 
			break;
		case mpe_rpc_cmd::profesion_upgrade_sc:
			out << "profesion_upgrade_sc"; 
			break;
		case mpe_rpc_cmd::profesion_reset_cs:
			out << "profesion_reset_cs"; 
			break;
		case mpe_rpc_cmd::profesion_reset_sc:
			out << "profesion_reset_sc"; 
			break;
		case mpe_rpc_cmd::meridians_levelup_cs:
			out << "meridians_levelup_cs"; 
			break;
		case mpe_rpc_cmd::meridians_levelup_sc:
			out << "meridians_levelup_sc"; 
			break;
		case mpe_rpc_cmd::acupoints_levelup_cs:
			out << "acupoints_levelup_cs"; 
			break;
		case mpe_rpc_cmd::acupoints_levelup_sc:
			out << "acupoints_levelup_sc"; 
			break;
		case mpe_rpc_cmd::exchange_register_cs:
			out << "exchange_register_cs"; 
			break;
		case mpe_rpc_cmd::exchange_register_sc:
			out << "exchange_register_sc"; 
			break;
		case mpe_rpc_cmd::exchange_register_cancel_cs:
			out << "exchange_register_cancel_cs"; 
			break;
		case mpe_rpc_cmd::exchange_register_cancel_sc:
			out << "exchange_register_cancel_sc"; 
			break;
		case mpe_rpc_cmd::exchange_buy_cs:
			out << "exchange_buy_cs"; 
			break;
		case mpe_rpc_cmd::exchange_buy_sc:
			out << "exchange_buy_sc"; 
			break;
		case mpe_rpc_cmd::exchange_gold_withdraw_cs:
			out << "exchange_gold_withdraw_cs"; 
			break;
		case mpe_rpc_cmd::exchange_gold_withdraw_sc:
			out << "exchange_gold_withdraw_sc"; 
			break;
		case mpe_rpc_cmd::exchange_item_withdraw_cs:
			out << "exchange_item_withdraw_cs"; 
			break;
		case mpe_rpc_cmd::exchange_item_withdraw_sc:
			out << "exchange_item_withdraw_sc"; 
			break;
		case mpe_rpc_cmd::game_setup_cs:
			out << "game_setup_cs"; 
			break;
		case mpe_rpc_cmd::game_setup_sc:
			out << "game_setup_sc"; 
			break;
		case mpe_rpc_cmd::pk_setup_cs:
			out << "pk_setup_cs"; 
			break;
		case mpe_rpc_cmd::pk_setup_sc:
			out << "pk_setup_sc"; 
			break;
		case mpe_rpc_cmd::character_power_cs:
			out << "character_power_cs"; 
			break;
		case mpe_rpc_cmd::character_power_sc:
			out << "character_power_sc"; 
			break;
		case mpe_rpc_cmd::test_game_login_cs:
			out << "test_game_login_cs"; 
			break;
		case mpe_rpc_cmd::test_game_login_sc:
			out << "test_game_login_sc"; 
			break;
		case mpe_rpc_cmd::test_character_create_cs:
			out << "test_character_create_cs"; 
			break;
		case mpe_rpc_cmd::test_character_create_sc:
			out << "test_character_create_sc"; 
			break;
		case mpe_rpc_cmd::test_character_select_cs:
			out << "test_character_select_cs"; 
			break;
		case mpe_rpc_cmd::test_character_select_sc:
			out << "test_character_select_sc"; 
			break;
		case mpe_rpc_cmd::cmd_user_lock_cs:
			out << "cmd_user_lock_cs"; 
			break;
		case mpe_rpc_cmd::cmd_user_lock_sc:
			out << "cmd_user_lock_sc"; 
			break;
		case mpe_rpc_cmd::cmd_invenclear_cs:
			out << "cmd_invenclear_cs"; 
			break;
		case mpe_rpc_cmd::cmd_invenclear_sc:
			out << "cmd_invenclear_sc"; 
			break;
		case mpe_rpc_cmd::cmd_quest_clear_cs:
			out << "cmd_quest_clear_cs"; 
			break;
		case mpe_rpc_cmd::cmd_quest_clear_sc:
			out << "cmd_quest_clear_sc"; 
			break;
		case mpe_rpc_cmd::cmd_gameshutdown_cs:
			out << "cmd_gameshutdown_cs"; 
			break;
		case mpe_rpc_cmd::cmd_gameshutdown_sc:
			out << "cmd_gameshutdown_sc"; 
			break;
		case mpe_rpc_cmd::map_discovery_info_cs:
			out << "map_discovery_info_cs"; 
			break;
		case mpe_rpc_cmd::map_discovery_info_sc:
			out << "map_discovery_info_sc"; 
			break;
		case mpe_rpc_cmd::map_discovery_update_cs:
			out << "map_discovery_update_cs"; 
			break;
		case mpe_rpc_cmd::map_discovery_update_sc:
			out << "map_discovery_update_sc"; 
			break;
		case mpe_rpc_cmd::game_login_cs:
			out << "game_login_cs"; 
			break;
		case mpe_rpc_cmd::game_login_sc:
			out << "game_login_sc"; 
			break;
		case mpe_rpc_cmd::server_redirect_response_cs:
			out << "server_redirect_response_cs"; 
			break;
		case mpe_rpc_cmd::server_redirect_response_sc:
			out << "server_redirect_response_sc"; 
			break;
		case mpe_rpc_cmd::server_redirect_request_cs:
			out << "server_redirect_request_cs"; 
			break;
		case mpe_rpc_cmd::server_redirect_request_sc:
			out << "server_redirect_request_sc"; 
			break;
		case mpe_rpc_cmd::exchange_gold_item_cs:
			out << "exchange_gold_item_cs"; 
			break;
		case mpe_rpc_cmd::exchange_gold_item_sc:
			out << "exchange_gold_item_sc"; 
			break;
		case mpe_rpc_cmd::party_create_cs:
			out << "party_create_cs"; 
			break;
		case mpe_rpc_cmd::party_create_sc:
			out << "party_create_sc"; 
			break;
		case mpe_rpc_cmd::party_destroy_cs:
			out << "party_destroy_cs"; 
			break;
		case mpe_rpc_cmd::party_destroy_sc:
			out << "party_destroy_sc"; 
			break;
		case mpe_rpc_cmd::party_info_cs:
			out << "party_info_cs"; 
			break;
		case mpe_rpc_cmd::party_info_sc:
			out << "party_info_sc"; 
			break;
		case mpe_rpc_cmd::party_member_cs:
			out << "party_member_cs"; 
			break;
		case mpe_rpc_cmd::party_member_sc:
			out << "party_member_sc"; 
			break;
		case mpe_rpc_cmd::party_setup_cs:
			out << "party_setup_cs"; 
			break;
		case mpe_rpc_cmd::party_setup_sc:
			out << "party_setup_sc"; 
			break;
		case mpe_rpc_cmd::party_enter_request_cs:
			out << "party_enter_request_cs"; 
			break;
		case mpe_rpc_cmd::party_enter_request_sc:
			out << "party_enter_request_sc"; 
			break;
		case mpe_rpc_cmd::party_enter_agree_cs:
			out << "party_enter_agree_cs"; 
			break;
		case mpe_rpc_cmd::party_enter_agree_sc:
			out << "party_enter_agree_sc"; 
			break;
		case mpe_rpc_cmd::party_enter_refuse_cs:
			out << "party_enter_refuse_cs"; 
			break;
		case mpe_rpc_cmd::party_enter_refuse_sc:
			out << "party_enter_refuse_sc"; 
			break;
		case mpe_rpc_cmd::party_enter_cancel_cs:
			out << "party_enter_cancel_cs"; 
			break;
		case mpe_rpc_cmd::party_enter_cancel_sc:
			out << "party_enter_cancel_sc"; 
			break;
		case mpe_rpc_cmd::party_invite_request_cs:
			out << "party_invite_request_cs"; 
			break;
		case mpe_rpc_cmd::party_invite_request_sc:
			out << "party_invite_request_sc"; 
			break;
		case mpe_rpc_cmd::party_invite_cancel_cs:
			out << "party_invite_cancel_cs"; 
			break;
		case mpe_rpc_cmd::party_invite_cancel_sc:
			out << "party_invite_cancel_sc"; 
			break;
		case mpe_rpc_cmd::party_invite_agree_cs:
			out << "party_invite_agree_cs"; 
			break;
		case mpe_rpc_cmd::party_invite_agree_sc:
			out << "party_invite_agree_sc"; 
			break;
		case mpe_rpc_cmd::party_invite_refuse_cs:
			out << "party_invite_refuse_cs"; 
			break;
		case mpe_rpc_cmd::party_invite_refuse_sc:
			out << "party_invite_refuse_sc"; 
			break;
		case mpe_rpc_cmd::party_leave_cs:
			out << "party_leave_cs"; 
			break;
		case mpe_rpc_cmd::party_leave_sc:
			out << "party_leave_sc"; 
			break;
		case mpe_rpc_cmd::party_member_ban_cs:
			out << "party_member_ban_cs"; 
			break;
		case mpe_rpc_cmd::party_member_ban_sc:
			out << "party_member_ban_sc"; 
			break;
		case mpe_rpc_cmd::party_owner_change_cs:
			out << "party_owner_change_cs"; 
			break;
		case mpe_rpc_cmd::party_owner_change_sc:
			out << "party_owner_change_sc"; 
			break;
		case mpe_rpc_cmd::party_enter_request_list_cs:
			out << "party_enter_request_list_cs"; 
			break;
		case mpe_rpc_cmd::party_enter_request_list_sc:
			out << "party_enter_request_list_sc"; 
			break;
		case mpe_rpc_cmd::party_enter_requestors_cs:
			out << "party_enter_requestors_cs"; 
			break;
		case mpe_rpc_cmd::party_enter_requestors_sc:
			out << "party_enter_requestors_sc"; 
			break;
		case mpe_rpc_cmd::party_info_update_cs:
			out << "party_info_update_cs"; 
			break;
		case mpe_rpc_cmd::party_info_update_sc:
			out << "party_info_update_sc"; 
			break;
		case mpe_rpc_cmd::guild_create_cs:
			out << "guild_create_cs"; 
			break;
		case mpe_rpc_cmd::guild_create_sc:
			out << "guild_create_sc"; 
			break;
		case mpe_rpc_cmd::guild_destroy_cs:
			out << "guild_destroy_cs"; 
			break;
		case mpe_rpc_cmd::guild_destroy_sc:
			out << "guild_destroy_sc"; 
			break;
		case mpe_rpc_cmd::guild_join_request_cs:
			out << "guild_join_request_cs"; 
			break;
		case mpe_rpc_cmd::guild_join_request_sc:
			out << "guild_join_request_sc"; 
			break;
		case mpe_rpc_cmd::guild_accept_member_cs:
			out << "guild_accept_member_cs"; 
			break;
		case mpe_rpc_cmd::guild_accept_member_sc:
			out << "guild_accept_member_sc"; 
			break;
		case mpe_rpc_cmd::guild_join_cancel_cs:
			out << "guild_join_cancel_cs"; 
			break;
		case mpe_rpc_cmd::guild_join_cancel_sc:
			out << "guild_join_cancel_sc"; 
			break;
		case mpe_rpc_cmd::guild_recommend_cs:
			out << "guild_recommend_cs"; 
			break;
		case mpe_rpc_cmd::guild_recommend_sc:
			out << "guild_recommend_sc"; 
			break;
		case mpe_rpc_cmd::guild_request_guild_list_cs:
			out << "guild_request_guild_list_cs"; 
			break;
		case mpe_rpc_cmd::guild_request_guild_list_sc:
			out << "guild_request_guild_list_sc"; 
			break;
		case mpe_rpc_cmd::guild_add_exp_cs:
			out << "guild_add_exp_cs"; 
			break;
		case mpe_rpc_cmd::guild_add_exp_sc:
			out << "guild_add_exp_sc"; 
			break;
		case mpe_rpc_cmd::guild_member_list_cs:
			out << "guild_member_list_cs"; 
			break;
		case mpe_rpc_cmd::guild_member_list_sc:
			out << "guild_member_list_sc"; 
			break;
		case mpe_rpc_cmd::guild_info_cs:
			out << "guild_info_cs"; 
			break;
		case mpe_rpc_cmd::guild_info_sc:
			out << "guild_info_sc"; 
			break;
		case mpe_rpc_cmd::guild_ban_cs:
			out << "guild_ban_cs"; 
			break;
		case mpe_rpc_cmd::guild_ban_sc:
			out << "guild_ban_sc"; 
			break;
		case mpe_rpc_cmd::guild_leave_cs:
			out << "guild_leave_cs"; 
			break;
		case mpe_rpc_cmd::guild_leave_sc:
			out << "guild_leave_sc"; 
			break;
		case mpe_rpc_cmd::guild_search_cs:
			out << "guild_search_cs"; 
			break;
		case mpe_rpc_cmd::guild_search_sc:
			out << "guild_search_sc"; 
			break;
		case mpe_rpc_cmd::guild_change_join_condition_cs:
			out << "guild_change_join_condition_cs"; 
			break;
		case mpe_rpc_cmd::guild_change_join_condition_sc:
			out << "guild_change_join_condition_sc"; 
			break;
		case mpe_rpc_cmd::guild_change_member_grade_cs:
			out << "guild_change_member_grade_cs"; 
			break;
		case mpe_rpc_cmd::guild_change_member_grade_sc:
			out << "guild_change_member_grade_sc"; 
			break;
		case mpe_rpc_cmd::skill_learn_cs:
			out << "skill_learn_cs"; 
			break;
		case mpe_rpc_cmd::skill_learn_sc:
			out << "skill_learn_sc"; 
			break;
		case mpe_rpc_cmd::skill_levelup_cs:
			out << "skill_levelup_cs"; 
			break;
		case mpe_rpc_cmd::skill_levelup_sc:
			out << "skill_levelup_sc"; 
			break;
		case mpe_rpc_cmd::zone_action_fish_cs:
			out << "zone_action_fish_cs"; 
			break;
		case mpe_rpc_cmd::zone_action_fish_sc:
			out << "zone_action_fish_sc"; 
			break;
		case mpe_rpc_cmd::party_member_update_cs:
			out << "party_member_update_cs"; 
			break;
		case mpe_rpc_cmd::party_member_update_sc:
			out << "party_member_update_sc"; 
			break;
		case mpe_rpc_cmd::buff_select_cs:
			out << "buff_select_cs"; 
			break;
		case mpe_rpc_cmd::buff_select_sc:
			out << "buff_select_sc"; 
			break;
		case mpe_rpc_cmd::buff_insert_cs:
			out << "buff_insert_cs"; 
			break;
		case mpe_rpc_cmd::buff_insert_sc:
			out << "buff_insert_sc"; 
			break;
		case mpe_rpc_cmd::buff_update_cs:
			out << "buff_update_cs"; 
			break;
		case mpe_rpc_cmd::buff_update_sc:
			out << "buff_update_sc"; 
			break;
		case mpe_rpc_cmd::buff_delete_cs:
			out << "buff_delete_cs"; 
			break;
		case mpe_rpc_cmd::buff_delete_sc:
			out << "buff_delete_sc"; 
			break;
		case mpe_rpc_cmd::guild_request_member_list_cs:
			out << "guild_request_member_list_cs"; 
			break;
		case mpe_rpc_cmd::guild_request_member_list_sc:
			out << "guild_request_member_list_sc"; 
			break;
		case mpe_rpc_cmd::guild_donation_cs:
			out << "guild_donation_cs"; 
			break;
		case mpe_rpc_cmd::guild_donation_sc:
			out << "guild_donation_sc"; 
			break;
		case mpe_rpc_cmd::repute_quest_finish_count_reset_cs:
			out << "repute_quest_finish_count_reset_cs"; 
			break;
		case mpe_rpc_cmd::repute_quest_finish_count_reset_sc:
			out << "repute_quest_finish_count_reset_sc"; 
			break;
		case mpe_rpc_cmd::guild_start_war_cs:
			out << "guild_start_war_cs"; 
			break;
		case mpe_rpc_cmd::guild_start_war_sc:
			out << "guild_start_war_sc"; 
			break;
		case mpe_rpc_cmd::guild_try_surrender_cs:
			out << "guild_try_surrender_cs"; 
			break;
		case mpe_rpc_cmd::guild_try_surrender_sc:
			out << "guild_try_surrender_sc"; 
			break;
		case mpe_rpc_cmd::guild_respond_surrender_cs:
			out << "guild_respond_surrender_cs"; 
			break;
		case mpe_rpc_cmd::guild_respond_surrender_sc:
			out << "guild_respond_surrender_sc"; 
			break;
		case mpe_rpc_cmd::storage_open_cs:
			out << "storage_open_cs"; 
			break;
		case mpe_rpc_cmd::storage_open_sc:
			out << "storage_open_sc"; 
			break;
		case mpe_rpc_cmd::storage_move_cs:
			out << "storage_move_cs"; 
			break;
		case mpe_rpc_cmd::storage_move_sc:
			out << "storage_move_sc"; 
			break;
		case mpe_rpc_cmd::account_storage_buy_cs:
			out << "account_storage_buy_cs"; 
			break;
		case mpe_rpc_cmd::account_storage_buy_sc:
			out << "account_storage_buy_sc"; 
			break;
		case mpe_rpc_cmd::storage_expand_cs:
			out << "storage_expand_cs"; 
			break;
		case mpe_rpc_cmd::storage_expand_sc:
			out << "storage_expand_sc"; 
			break;
		case mpe_rpc_cmd::storage_goods_move_cs:
			out << "storage_goods_move_cs"; 
			break;
		case mpe_rpc_cmd::storage_goods_move_sc:
			out << "storage_goods_move_sc"; 
			break;
		case mpe_rpc_cmd::indun_play_count_cs:
			out << "indun_play_count_cs"; 
			break;
		case mpe_rpc_cmd::indun_play_count_sc:
			out << "indun_play_count_sc"; 
			break;
		case mpe_rpc_cmd::indun_auto_matching_reg_cs:
			out << "indun_auto_matching_reg_cs"; 
			break;
		case mpe_rpc_cmd::indun_auto_matching_reg_sc:
			out << "indun_auto_matching_reg_sc"; 
			break;
		case mpe_rpc_cmd::indun_auto_matching_complete_cs:
			out << "indun_auto_matching_complete_cs"; 
			break;
		case mpe_rpc_cmd::indun_auto_matching_complete_sc:
			out << "indun_auto_matching_complete_sc"; 
			break;
		case mpe_rpc_cmd::personal_trade_confirm_cs:
			out << "personal_trade_confirm_cs"; 
			break;
		case mpe_rpc_cmd::personal_trade_confirm_sc:
			out << "personal_trade_confirm_sc"; 
			break;
		case mpe_rpc_cmd::party_vote_request_cs:
			out << "party_vote_request_cs"; 
			break;
		case mpe_rpc_cmd::party_vote_request_sc:
			out << "party_vote_request_sc"; 
			break;
		case mpe_rpc_cmd::party_vote_reply_cs:
			out << "party_vote_reply_cs"; 
			break;
		case mpe_rpc_cmd::party_vote_reply_sc:
			out << "party_vote_reply_sc"; 
			break;
		case mpe_rpc_cmd::party_vote_result_cs:
			out << "party_vote_result_cs"; 
			break;
		case mpe_rpc_cmd::party_vote_result_sc:
			out << "party_vote_result_sc"; 
			break;
		case mpe_rpc_cmd::guild_enemy_list_cs:
			out << "guild_enemy_list_cs"; 
			break;
		case mpe_rpc_cmd::guild_enemy_list_sc:
			out << "guild_enemy_list_sc"; 
			break;
		case mpe_rpc_cmd::guild_war_list_cs:
			out << "guild_war_list_cs"; 
			break;
		case mpe_rpc_cmd::guild_war_list_sc:
			out << "guild_war_list_sc"; 
			break;
		case mpe_rpc_cmd::indun_auto_matching_cancel_cs:
			out << "indun_auto_matching_cancel_cs"; 
			break;
		case mpe_rpc_cmd::indun_auto_matching_cancel_sc:
			out << "indun_auto_matching_cancel_sc"; 
			break;
		case mpe_rpc_cmd::item_repair_cs:
			out << "item_repair_cs"; 
			break;
		case mpe_rpc_cmd::item_repair_sc:
			out << "item_repair_sc"; 
			break;
		case mpe_rpc_cmd::goods_update_cs:
			out << "goods_update_cs"; 
			break;
		case mpe_rpc_cmd::goods_update_sc:
			out << "goods_update_sc"; 
			break;
		case mpe_rpc_cmd::skill_passive_levelup_cs:
			out << "skill_passive_levelup_cs"; 
			break;
		case mpe_rpc_cmd::skill_passive_levelup_sc:
			out << "skill_passive_levelup_sc"; 
			break;
		case mpe_rpc_cmd::game_logout_cs:
			out << "game_logout_cs"; 
			break;
		case mpe_rpc_cmd::game_logout_sc:
			out << "game_logout_sc"; 
			break;
		case mpe_rpc_cmd::character_zone_enter_cs:
			out << "character_zone_enter_cs"; 
			break;
		case mpe_rpc_cmd::character_zone_enter_sc:
			out << "character_zone_enter_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_start_war_cs:
			out << "guild_alert_start_war_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_start_war_sc:
			out << "guild_alert_start_war_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_end_war_cs:
			out << "guild_alert_end_war_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_end_war_sc:
			out << "guild_alert_end_war_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_reject_surrender_cs:
			out << "guild_alert_reject_surrender_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_reject_surrender_sc:
			out << "guild_alert_reject_surrender_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_surrender_cs:
			out << "guild_alert_surrender_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_surrender_sc:
			out << "guild_alert_surrender_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_join_request_cs:
			out << "guild_alert_join_request_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_join_request_sc:
			out << "guild_alert_join_request_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_join_request_cancel_cs:
			out << "guild_alert_join_request_cancel_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_join_request_cancel_sc:
			out << "guild_alert_join_request_cancel_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_join_cs:
			out << "guild_alert_join_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_join_sc:
			out << "guild_alert_join_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_join_request_result_cs:
			out << "guild_alert_join_request_result_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_join_request_result_sc:
			out << "guild_alert_join_request_result_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_leave_cs:
			out << "guild_alert_leave_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_leave_sc:
			out << "guild_alert_leave_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_ban_for_member_cs:
			out << "guild_alert_ban_for_member_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_ban_for_member_sc:
			out << "guild_alert_ban_for_member_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_ban_cs:
			out << "guild_alert_ban_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_ban_sc:
			out << "guild_alert_ban_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_change_grade_cs:
			out << "guild_alert_change_grade_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_change_grade_sc:
			out << "guild_alert_change_grade_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_change_master_cs:
			out << "guild_alert_change_master_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_change_master_sc:
			out << "guild_alert_change_master_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_add_exp_cs:
			out << "guild_alert_add_exp_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_add_exp_sc:
			out << "guild_alert_add_exp_sc"; 
			break;
		case mpe_rpc_cmd::party_teleport_cs:
			out << "party_teleport_cs"; 
			break;
		case mpe_rpc_cmd::party_teleport_sc:
			out << "party_teleport_sc"; 
			break;
		case mpe_rpc_cmd::guild_item_buy_cs:
			out << "guild_item_buy_cs"; 
			break;
		case mpe_rpc_cmd::guild_item_buy_sc:
			out << "guild_item_buy_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_info_cs:
			out << "siege_warfare_info_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_info_sc:
			out << "siege_warfare_info_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_all_info_cs:
			out << "siege_warfare_all_info_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_all_info_sc:
			out << "siege_warfare_all_info_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_submit_tender_cs:
			out << "siege_warfare_submit_tender_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_submit_tender_sc:
			out << "siege_warfare_submit_tender_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_alert_cs:
			out << "siege_warfare_alert_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_alert_sc:
			out << "siege_warfare_alert_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_alliance_request_cs:
			out << "siege_warfare_alliance_request_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_alliance_request_sc:
			out << "siege_warfare_alliance_request_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_alliance_cancel_cs:
			out << "siege_warfare_alliance_cancel_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_alliance_cancel_sc:
			out << "siege_warfare_alliance_cancel_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_alliance_response_cs:
			out << "siege_warfare_alliance_response_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_alliance_response_sc:
			out << "siege_warfare_alliance_response_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_alliance_kickout_cs:
			out << "siege_warfare_alliance_kickout_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_alliance_kickout_sc:
			out << "siege_warfare_alliance_kickout_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_alliance_withdrawal_cs:
			out << "siege_warfare_alliance_withdrawal_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_alliance_withdrawal_sc:
			out << "siege_warfare_alliance_withdrawal_sc"; 
			break;
		case mpe_rpc_cmd::castle_all_info_cs:
			out << "castle_all_info_cs"; 
			break;
		case mpe_rpc_cmd::castle_all_info_sc:
			out << "castle_all_info_sc"; 
			break;
		case mpe_rpc_cmd::castle_set_tax_rate_cs:
			out << "castle_set_tax_rate_cs"; 
			break;
		case mpe_rpc_cmd::castle_set_tax_rate_sc:
			out << "castle_set_tax_rate_sc"; 
			break;
		case mpe_rpc_cmd::castle_tax_refund_payment_time_cs:
			out << "castle_tax_refund_payment_time_cs"; 
			break;
		case mpe_rpc_cmd::castle_tax_refund_payment_time_sc:
			out << "castle_tax_refund_payment_time_sc"; 
			break;
		case mpe_rpc_cmd::castle_set_tax_distribution_cs:
			out << "castle_set_tax_distribution_cs"; 
			break;
		case mpe_rpc_cmd::castle_set_tax_distribution_sc:
			out << "castle_set_tax_distribution_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_atk_build_machine_cs:
			out << "siege_warfare_atk_build_machine_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_atk_build_machine_sc:
			out << "siege_warfare_atk_build_machine_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_def_build_machine_cs:
			out << "siege_warfare_def_build_machine_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_def_build_machine_sc:
			out << "siege_warfare_def_build_machine_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_atk_release_machine_cs:
			out << "siege_warfare_atk_release_machine_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_atk_release_machine_sc:
			out << "siege_warfare_atk_release_machine_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_def_release_machine_cs:
			out << "siege_warfare_def_release_machine_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_def_release_machine_sc:
			out << "siege_warfare_def_release_machine_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_battle_result_cs:
			out << "siege_warfare_battle_result_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_battle_result_sc:
			out << "siege_warfare_battle_result_sc"; 
			break;
		case mpe_rpc_cmd::guild_change_notice_cs:
			out << "guild_change_notice_cs"; 
			break;
		case mpe_rpc_cmd::guild_change_notice_sc:
			out << "guild_change_notice_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_change_notice_cs:
			out << "guild_alert_change_notice_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_change_notice_sc:
			out << "guild_alert_change_notice_sc"; 
			break;
		case mpe_rpc_cmd::guild_learn_skill_cs:
			out << "guild_learn_skill_cs"; 
			break;
		case mpe_rpc_cmd::guild_learn_skill_sc:
			out << "guild_learn_skill_sc"; 
			break;
		case mpe_rpc_cmd::guild_reset_skill_cs:
			out << "guild_reset_skill_cs"; 
			break;
		case mpe_rpc_cmd::guild_reset_skill_sc:
			out << "guild_reset_skill_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_learn_skill_cs:
			out << "guild_alert_learn_skill_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_learn_skill_sc:
			out << "guild_alert_learn_skill_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_reset_skill_cs:
			out << "guild_alert_reset_skill_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_reset_skill_sc:
			out << "guild_alert_reset_skill_sc"; 
			break;
		case mpe_rpc_cmd::guild_skill_list_cs:
			out << "guild_skill_list_cs"; 
			break;
		case mpe_rpc_cmd::guild_skill_list_sc:
			out << "guild_skill_list_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_donation_cs:
			out << "guild_alert_donation_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_donation_sc:
			out << "guild_alert_donation_sc"; 
			break;
		case mpe_rpc_cmd::indun_reward_cs:
			out << "indun_reward_cs"; 
			break;
		case mpe_rpc_cmd::indun_reward_sc:
			out << "indun_reward_sc"; 
			break;
		case mpe_rpc_cmd::castle_town_all_info_cs:
			out << "castle_town_all_info_cs"; 
			break;
		case mpe_rpc_cmd::castle_town_all_info_sc:
			out << "castle_town_all_info_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_all_info_for_indun_cs:
			out << "siege_warfare_all_info_for_indun_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_all_info_for_indun_sc:
			out << "siege_warfare_all_info_for_indun_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_material_list_cs:
			out << "guild_storage_material_list_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_material_list_sc:
			out << "guild_storage_material_list_sc"; 
			break;
		case mpe_rpc_cmd::guild_item_donation_cs:
			out << "guild_item_donation_cs"; 
			break;
		case mpe_rpc_cmd::guild_item_donation_sc:
			out << "guild_item_donation_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_supply_list_cs:
			out << "guild_storage_supply_list_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_supply_list_sc:
			out << "guild_storage_supply_list_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_supply_insert_item_cs:
			out << "guild_storage_supply_insert_item_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_supply_insert_item_sc:
			out << "guild_storage_supply_insert_item_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_supply_get_item_cs:
			out << "guild_storage_supply_get_item_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_supply_get_item_sc:
			out << "guild_storage_supply_get_item_sc"; 
			break;
		case mpe_rpc_cmd::castle_town_work_cs:
			out << "castle_town_work_cs"; 
			break;
		case mpe_rpc_cmd::castle_town_work_sc:
			out << "castle_town_work_sc"; 
			break;
		case mpe_rpc_cmd::chat_normal_cs:
			out << "chat_normal_cs"; 
			break;
		case mpe_rpc_cmd::chat_normal_sc:
			out << "chat_normal_sc"; 
			break;
		case mpe_rpc_cmd::chat_world_cs:
			out << "chat_world_cs"; 
			break;
		case mpe_rpc_cmd::chat_world_sc:
			out << "chat_world_sc"; 
			break;
		case mpe_rpc_cmd::chat_party_cs:
			out << "chat_party_cs"; 
			break;
		case mpe_rpc_cmd::chat_party_sc:
			out << "chat_party_sc"; 
			break;
		case mpe_rpc_cmd::chat_guild_cs:
			out << "chat_guild_cs"; 
			break;
		case mpe_rpc_cmd::chat_guild_sc:
			out << "chat_guild_sc"; 
			break;
		case mpe_rpc_cmd::chat_promotion_cs:
			out << "chat_promotion_cs"; 
			break;
		case mpe_rpc_cmd::chat_promotion_sc:
			out << "chat_promotion_sc"; 
			break;
		case mpe_rpc_cmd::chat_exchange_cs:
			out << "chat_exchange_cs"; 
			break;
		case mpe_rpc_cmd::chat_exchange_sc:
			out << "chat_exchange_sc"; 
			break;
		case mpe_rpc_cmd::chat_system_cs:
			out << "chat_system_cs"; 
			break;
		case mpe_rpc_cmd::chat_system_sc:
			out << "chat_system_sc"; 
			break;
		case mpe_rpc_cmd::chat_private_cs:
			out << "chat_private_cs"; 
			break;
		case mpe_rpc_cmd::chat_private_sc:
			out << "chat_private_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_list_cs:
			out << "guild_storage_share_list_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_list_sc:
			out << "guild_storage_share_list_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_insert_item_cs:
			out << "guild_storage_share_insert_item_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_insert_item_sc:
			out << "guild_storage_share_insert_item_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_request_get_item_cs:
			out << "guild_storage_share_request_get_item_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_request_get_item_sc:
			out << "guild_storage_share_request_get_item_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_alert_request_get_item_cs:
			out << "guild_storage_share_alert_request_get_item_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_alert_request_get_item_sc:
			out << "guild_storage_share_alert_request_get_item_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_result_get_item_cs:
			out << "guild_storage_share_result_get_item_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_result_get_item_sc:
			out << "guild_storage_share_result_get_item_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_extend_cs:
			out << "guild_storage_share_extend_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_extend_sc:
			out << "guild_storage_share_extend_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_request_get_item_list_cs:
			out << "guild_storage_share_request_get_item_list_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_request_get_item_list_sc:
			out << "guild_storage_share_request_get_item_list_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_master_get_item_cs:
			out << "guild_storage_share_master_get_item_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_share_master_get_item_sc:
			out << "guild_storage_share_master_get_item_sc"; 
			break;
		case mpe_rpc_cmd::castle_town_return_cs:
			out << "castle_town_return_cs"; 
			break;
		case mpe_rpc_cmd::castle_town_return_sc:
			out << "castle_town_return_sc"; 
			break;
		case mpe_rpc_cmd::enchant_stone_slot_open_cs:
			out << "enchant_stone_slot_open_cs"; 
			break;
		case mpe_rpc_cmd::enchant_stone_slot_open_sc:
			out << "enchant_stone_slot_open_sc"; 
			break;
		case mpe_rpc_cmd::enchant_stone_equip_cs:
			out << "enchant_stone_equip_cs"; 
			break;
		case mpe_rpc_cmd::enchant_stone_equip_sc:
			out << "enchant_stone_equip_sc"; 
			break;
		case mpe_rpc_cmd::enchant_stone_upgrade_cs:
			out << "enchant_stone_upgrade_cs"; 
			break;
		case mpe_rpc_cmd::enchant_stone_upgrade_sc:
			out << "enchant_stone_upgrade_sc"; 
			break;
		case mpe_rpc_cmd::enchant_stone_compose_cs:
			out << "enchant_stone_compose_cs"; 
			break;
		case mpe_rpc_cmd::enchant_stone_compose_sc:
			out << "enchant_stone_compose_sc"; 
			break;
		case mpe_rpc_cmd::castle_town_work_rollback_cs:
			out << "castle_town_work_rollback_cs"; 
			break;
		case mpe_rpc_cmd::castle_town_work_rollback_sc:
			out << "castle_town_work_rollback_sc"; 
			break;
		case mpe_rpc_cmd::castle_town_house_fire_cs:
			out << "castle_town_house_fire_cs"; 
			break;
		case mpe_rpc_cmd::castle_town_house_fire_sc:
			out << "castle_town_house_fire_sc"; 
			break;
		case mpe_rpc_cmd::gameitem_option_update_cs:
			out << "gameitem_option_update_cs"; 
			break;
		case mpe_rpc_cmd::gameitem_option_update_sc:
			out << "gameitem_option_update_sc"; 
			break;
		case mpe_rpc_cmd::dropitem_delete_cs:
			out << "dropitem_delete_cs"; 
			break;
		case mpe_rpc_cmd::dropitem_delete_sc:
			out << "dropitem_delete_sc"; 
			break;
		case mpe_rpc_cmd::castle_town_arsenal_build_cs:
			out << "castle_town_arsenal_build_cs"; 
			break;
		case mpe_rpc_cmd::castle_town_arsenal_build_sc:
			out << "castle_town_arsenal_build_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_treasure_list_cs:
			out << "guild_storage_treasure_list_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_treasure_list_sc:
			out << "guild_storage_treasure_list_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_treasure_alert_lost_top_request_cs:
			out << "guild_storage_treasure_alert_lost_top_request_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_treasure_alert_lost_top_request_sc:
			out << "guild_storage_treasure_alert_lost_top_request_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_treasure_alert_auction_finish_cs:
			out << "guild_storage_treasure_alert_auction_finish_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_treasure_alert_auction_finish_sc:
			out << "guild_storage_treasure_alert_auction_finish_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_treasure_get_auction_cs:
			out << "guild_storage_treasure_get_auction_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_treasure_get_auction_sc:
			out << "guild_storage_treasure_get_auction_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_treasure_request_cs:
			out << "guild_storage_treasure_request_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_treasure_request_sc:
			out << "guild_storage_treasure_request_sc"; 
			break;
		case mpe_rpc_cmd::guild_dungeon_prepare_create_cs:
			out << "guild_dungeon_prepare_create_cs"; 
			break;
		case mpe_rpc_cmd::guild_dungeon_prepare_create_sc:
			out << "guild_dungeon_prepare_create_sc"; 
			break;
		case mpe_rpc_cmd::guild_dungeon_create_cs:
			out << "guild_dungeon_create_cs"; 
			break;
		case mpe_rpc_cmd::guild_dungeon_create_sc:
			out << "guild_dungeon_create_sc"; 
			break;
		case mpe_rpc_cmd::guild_dungeon_clear_cs:
			out << "guild_dungeon_clear_cs"; 
			break;
		case mpe_rpc_cmd::guild_dungeon_clear_sc:
			out << "guild_dungeon_clear_sc"; 
			break;
		case mpe_rpc_cmd::guild_dungeon_update_cs:
			out << "guild_dungeon_update_cs"; 
			break;
		case mpe_rpc_cmd::guild_dungeon_update_sc:
			out << "guild_dungeon_update_sc"; 
			break;
		case mpe_rpc_cmd::guild_dungeon_damage_cs:
			out << "guild_dungeon_damage_cs"; 
			break;
		case mpe_rpc_cmd::guild_dungeon_damage_sc:
			out << "guild_dungeon_damage_sc"; 
			break;
		case mpe_rpc_cmd::castle_town_arsenal_build_donate_cs:
			out << "castle_town_arsenal_build_donate_cs"; 
			break;
		case mpe_rpc_cmd::castle_town_arsenal_build_donate_sc:
			out << "castle_town_arsenal_build_donate_sc"; 
			break;
		case mpe_rpc_cmd::castle_town_arsenal_build_end_cs:
			out << "castle_town_arsenal_build_end_cs"; 
			break;
		case mpe_rpc_cmd::castle_town_arsenal_build_end_sc:
			out << "castle_town_arsenal_build_end_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_treasure_confirm_auction_cs:
			out << "guild_storage_treasure_confirm_auction_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_treasure_confirm_auction_sc:
			out << "guild_storage_treasure_confirm_auction_sc"; 
			break;
		case mpe_rpc_cmd::castle_town_start_specialties_cs:
			out << "castle_town_start_specialties_cs"; 
			break;
		case mpe_rpc_cmd::castle_town_start_specialties_sc:
			out << "castle_town_start_specialties_sc"; 
			break;
		case mpe_rpc_cmd::castle_town_start_specialties_delivery_cs:
			out << "castle_town_start_specialties_delivery_cs"; 
			break;
		case mpe_rpc_cmd::castle_town_start_specialties_delivery_sc:
			out << "castle_town_start_specialties_delivery_sc"; 
			break;
		case mpe_rpc_cmd::castle_town_end_specialties_delivery_cs:
			out << "castle_town_end_specialties_delivery_cs"; 
			break;
		case mpe_rpc_cmd::castle_town_end_specialties_delivery_sc:
			out << "castle_town_end_specialties_delivery_sc"; 
			break;
		case mpe_rpc_cmd::castle_town_owner_update_cs:
			out << "castle_town_owner_update_cs"; 
			break;
		case mpe_rpc_cmd::castle_town_owner_update_sc:
			out << "castle_town_owner_update_sc"; 
			break;
		case mpe_rpc_cmd::castle_town_work_end_cs:
			out << "castle_town_work_end_cs"; 
			break;
		case mpe_rpc_cmd::castle_town_work_end_sc:
			out << "castle_town_work_end_sc"; 
			break;
		case mpe_rpc_cmd::guild_check_quest_condition_cs:
			out << "guild_check_quest_condition_cs"; 
			break;
		case mpe_rpc_cmd::guild_check_quest_condition_sc:
			out << "guild_check_quest_condition_sc"; 
			break;
		case mpe_rpc_cmd::guild_quest_reward_cs:
			out << "guild_quest_reward_cs"; 
			break;
		case mpe_rpc_cmd::guild_quest_reward_sc:
			out << "guild_quest_reward_sc"; 
			break;
		case mpe_rpc_cmd::guild_register_master_order_quest_cs:
			out << "guild_register_master_order_quest_cs"; 
			break;
		case mpe_rpc_cmd::guild_register_master_order_quest_sc:
			out << "guild_register_master_order_quest_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_register_master_order_quest_cs:
			out << "guild_alert_register_master_order_quest_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_register_master_order_quest_sc:
			out << "guild_alert_register_master_order_quest_sc"; 
			break;
		case mpe_rpc_cmd::guild_complete_master_order_quest_cs:
			out << "guild_complete_master_order_quest_cs"; 
			break;
		case mpe_rpc_cmd::guild_complete_master_order_quest_sc:
			out << "guild_complete_master_order_quest_sc"; 
			break;
		case mpe_rpc_cmd::guild_finish_master_order_quest_cs:
			out << "guild_finish_master_order_quest_cs"; 
			break;
		case mpe_rpc_cmd::guild_finish_master_order_quest_sc:
			out << "guild_finish_master_order_quest_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_finish_master_order_quest_cs:
			out << "guild_alert_finish_master_order_quest_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_finish_master_order_quest_sc:
			out << "guild_alert_finish_master_order_quest_sc"; 
			break;
		case mpe_rpc_cmd::castle_town_start_dinner_cs:
			out << "castle_town_start_dinner_cs"; 
			break;
		case mpe_rpc_cmd::castle_town_start_dinner_sc:
			out << "castle_town_start_dinner_sc"; 
			break;
		case mpe_rpc_cmd::castle_town_dinner_get_item_cs:
			out << "castle_town_dinner_get_item_cs"; 
			break;
		case mpe_rpc_cmd::castle_town_dinner_get_item_sc:
			out << "castle_town_dinner_get_item_sc"; 
			break;
		case mpe_rpc_cmd::vehicle_add_cs:
			out << "vehicle_add_cs"; 
			break;
		case mpe_rpc_cmd::vehicle_add_sc:
			out << "vehicle_add_sc"; 
			break;
		case mpe_rpc_cmd::vehicle_equip_cs:
			out << "vehicle_equip_cs"; 
			break;
		case mpe_rpc_cmd::vehicle_equip_sc:
			out << "vehicle_equip_sc"; 
			break;
		case mpe_rpc_cmd::vehicle_food_cs:
			out << "vehicle_food_cs"; 
			break;
		case mpe_rpc_cmd::vehicle_food_sc:
			out << "vehicle_food_sc"; 
			break;
		case mpe_rpc_cmd::vehicle_equip_item_cs:
			out << "vehicle_equip_item_cs"; 
			break;
		case mpe_rpc_cmd::vehicle_equip_item_sc:
			out << "vehicle_equip_item_sc"; 
			break;
		case mpe_rpc_cmd::vehicle_expire_cs:
			out << "vehicle_expire_cs"; 
			break;
		case mpe_rpc_cmd::vehicle_expire_sc:
			out << "vehicle_expire_sc"; 
			break;
		case mpe_rpc_cmd::randombox_open_cs:
			out << "randombox_open_cs"; 
			break;
		case mpe_rpc_cmd::randombox_open_sc:
			out << "randombox_open_sc"; 
			break;
		case mpe_rpc_cmd::zone_treasure_box_cs:
			out << "zone_treasure_box_cs"; 
			break;
		case mpe_rpc_cmd::zone_treasure_box_sc:
			out << "zone_treasure_box_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_create_dungeon_cs:
			out << "guild_alert_create_dungeon_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_create_dungeon_sc:
			out << "guild_alert_create_dungeon_sc"; 
			break;
		case mpe_rpc_cmd::guild_dungeon_member_damage_cs:
			out << "guild_dungeon_member_damage_cs"; 
			break;
		case mpe_rpc_cmd::guild_dungeon_member_damage_sc:
			out << "guild_dungeon_member_damage_sc"; 
			break;
		case mpe_rpc_cmd::castle_dungeon_entrance_fee_change_cs:
			out << "castle_dungeon_entrance_fee_change_cs"; 
			break;
		case mpe_rpc_cmd::castle_dungeon_entrance_fee_change_sc:
			out << "castle_dungeon_entrance_fee_change_sc"; 
			break;
		case mpe_rpc_cmd::game_world_boss_spawn_cs:
			out << "game_world_boss_spawn_cs"; 
			break;
		case mpe_rpc_cmd::game_world_boss_spawn_sc:
			out << "game_world_boss_spawn_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_observer_count_cs:
			out << "siege_warfare_observer_count_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_observer_count_sc:
			out << "siege_warfare_observer_count_sc"; 
			break;
		case mpe_rpc_cmd::pet_equip_cs:
			out << "pet_equip_cs"; 
			break;
		case mpe_rpc_cmd::pet_equip_sc:
			out << "pet_equip_sc"; 
			break;
		case mpe_rpc_cmd::pet_feed_cs:
			out << "pet_feed_cs"; 
			break;
		case mpe_rpc_cmd::pet_feed_sc:
			out << "pet_feed_sc"; 
			break;
		case mpe_rpc_cmd::pet_mix_cs:
			out << "pet_mix_cs"; 
			break;
		case mpe_rpc_cmd::pet_mix_sc:
			out << "pet_mix_sc"; 
			break;
		case mpe_rpc_cmd::castle_dungeon_entrance_fee_apply_cs:
			out << "castle_dungeon_entrance_fee_apply_cs"; 
			break;
		case mpe_rpc_cmd::castle_dungeon_entrance_fee_apply_sc:
			out << "castle_dungeon_entrance_fee_apply_sc"; 
			break;
		case mpe_rpc_cmd::castle_dungeon_entrance_fee_tax_update_cs:
			out << "castle_dungeon_entrance_fee_tax_update_cs"; 
			break;
		case mpe_rpc_cmd::castle_dungeon_entrance_fee_tax_update_sc:
			out << "castle_dungeon_entrance_fee_tax_update_sc"; 
			break;
		case mpe_rpc_cmd::guild_master_change_by_non_connected_cs:
			out << "guild_master_change_by_non_connected_cs"; 
			break;
		case mpe_rpc_cmd::guild_master_change_by_non_connected_sc:
			out << "guild_master_change_by_non_connected_sc"; 
			break;
		case mpe_rpc_cmd::chat_guild_ally_cs:
			out << "chat_guild_ally_cs"; 
			break;
		case mpe_rpc_cmd::chat_guild_ally_sc:
			out << "chat_guild_ally_sc"; 
			break;
		case mpe_rpc_cmd::pk_record_add_cs:
			out << "pk_record_add_cs"; 
			break;
		case mpe_rpc_cmd::pk_record_add_sc:
			out << "pk_record_add_sc"; 
			break;
		case mpe_rpc_cmd::pk_revenge_add_cs:
			out << "pk_revenge_add_cs"; 
			break;
		case mpe_rpc_cmd::pk_revenge_add_sc:
			out << "pk_revenge_add_sc"; 
			break;
		case mpe_rpc_cmd::pk_record_revenge_cs:
			out << "pk_record_revenge_cs"; 
			break;
		case mpe_rpc_cmd::pk_record_revenge_sc:
			out << "pk_record_revenge_sc"; 
			break;
		case mpe_rpc_cmd::pk_record_delete_cs:
			out << "pk_record_delete_cs"; 
			break;
		case mpe_rpc_cmd::pk_record_delete_sc:
			out << "pk_record_delete_sc"; 
			break;
		case mpe_rpc_cmd::pk_revenge_delete_cs:
			out << "pk_revenge_delete_cs"; 
			break;
		case mpe_rpc_cmd::pk_revenge_delete_sc:
			out << "pk_revenge_delete_sc"; 
			break;
		case mpe_rpc_cmd::siege_bot_create_cs:
			out << "siege_bot_create_cs"; 
			break;
		case mpe_rpc_cmd::siege_bot_create_sc:
			out << "siege_bot_create_sc"; 
			break;
		case mpe_rpc_cmd::pk_revenge_trace_cs:
			out << "pk_revenge_trace_cs"; 
			break;
		case mpe_rpc_cmd::pk_revenge_trace_sc:
			out << "pk_revenge_trace_sc"; 
			break;
		case mpe_rpc_cmd::friend_request_cs:
			out << "friend_request_cs"; 
			break;
		case mpe_rpc_cmd::friend_request_sc:
			out << "friend_request_sc"; 
			break;
		case mpe_rpc_cmd::friend_delete_cs:
			out << "friend_delete_cs"; 
			break;
		case mpe_rpc_cmd::friend_delete_sc:
			out << "friend_delete_sc"; 
			break;
		case mpe_rpc_cmd::friend_request_response_cs:
			out << "friend_request_response_cs"; 
			break;
		case mpe_rpc_cmd::friend_request_response_sc:
			out << "friend_request_response_sc"; 
			break;
		case mpe_rpc_cmd::ranking_save_info_cs:
			out << "ranking_save_info_cs"; 
			break;
		case mpe_rpc_cmd::ranking_save_info_sc:
			out << "ranking_save_info_sc"; 
			break;
		case mpe_rpc_cmd::friend_list_cs:
			out << "friend_list_cs"; 
			break;
		case mpe_rpc_cmd::friend_list_sc:
			out << "friend_list_sc"; 
			break;
		case mpe_rpc_cmd::mentor_register_cs:
			out << "mentor_register_cs"; 
			break;
		case mpe_rpc_cmd::mentor_register_sc:
			out << "mentor_register_sc"; 
			break;
		case mpe_rpc_cmd::mentor_request_cs:
			out << "mentor_request_cs"; 
			break;
		case mpe_rpc_cmd::mentor_request_sc:
			out << "mentor_request_sc"; 
			break;
		case mpe_rpc_cmd::mentor_buff_cs:
			out << "mentor_buff_cs"; 
			break;
		case mpe_rpc_cmd::mentor_buff_sc:
			out << "mentor_buff_sc"; 
			break;
		case mpe_rpc_cmd::mentor_buff_buy_cs:
			out << "mentor_buff_buy_cs"; 
			break;
		case mpe_rpc_cmd::mentor_buff_buy_sc:
			out << "mentor_buff_buy_sc"; 
			break;
		case mpe_rpc_cmd::guild_ranking_update_cs:
			out << "guild_ranking_update_cs"; 
			break;
		case mpe_rpc_cmd::guild_ranking_update_sc:
			out << "guild_ranking_update_sc"; 
			break;
		case mpe_rpc_cmd::title_add_cs:
			out << "title_add_cs"; 
			break;
		case mpe_rpc_cmd::title_add_sc:
			out << "title_add_sc"; 
			break;
		case mpe_rpc_cmd::title_equip_cs:
			out << "title_equip_cs"; 
			break;
		case mpe_rpc_cmd::title_equip_sc:
			out << "title_equip_sc"; 
			break;
		case mpe_rpc_cmd::dictionary_add_cs:
			out << "dictionary_add_cs"; 
			break;
		case mpe_rpc_cmd::dictionary_add_sc:
			out << "dictionary_add_sc"; 
			break;
		case mpe_rpc_cmd::dictionary_get_cs:
			out << "dictionary_get_cs"; 
			break;
		case mpe_rpc_cmd::dictionary_get_sc:
			out << "dictionary_get_sc"; 
			break;
		case mpe_rpc_cmd::ranking_reward_title_cs:
			out << "ranking_reward_title_cs"; 
			break;
		case mpe_rpc_cmd::ranking_reward_title_sc:
			out << "ranking_reward_title_sc"; 
			break;
		case mpe_rpc_cmd::wanted_murder_register_cs:
			out << "wanted_murder_register_cs"; 
			break;
		case mpe_rpc_cmd::wanted_murder_register_sc:
			out << "wanted_murder_register_sc"; 
			break;
		case mpe_rpc_cmd::empty1_cs:
			out << "empty1_cs"; 
			break;
		case mpe_rpc_cmd::empty1_sc:
			out << "empty1_sc"; 
			break;
		case mpe_rpc_cmd::empty2_cs:
			out << "empty2_cs"; 
			break;
		case mpe_rpc_cmd::empty2_sc:
			out << "empty2_sc"; 
			break;
		case mpe_rpc_cmd::wanted_murder_reward_cs:
			out << "wanted_murder_reward_cs"; 
			break;
		case mpe_rpc_cmd::wanted_murder_reward_sc:
			out << "wanted_murder_reward_sc"; 
			break;
		case mpe_rpc_cmd::zone_teleport_save_area_cs:
			out << "zone_teleport_save_area_cs"; 
			break;
		case mpe_rpc_cmd::zone_teleport_save_area_sc:
			out << "zone_teleport_save_area_sc"; 
			break;
		case mpe_rpc_cmd::show_costume_cs:
			out << "show_costume_cs"; 
			break;
		case mpe_rpc_cmd::show_costume_sc:
			out << "show_costume_sc"; 
			break;
		case mpe_rpc_cmd::wanted_murder_kill_cs:
			out << "wanted_murder_kill_cs"; 
			break;
		case mpe_rpc_cmd::wanted_murder_kill_sc:
			out << "wanted_murder_kill_sc"; 
			break;
		case mpe_rpc_cmd::wanted_murder_number_of_uses_cs:
			out << "wanted_murder_number_of_uses_cs"; 
			break;
		case mpe_rpc_cmd::wanted_murder_number_of_uses_sc:
			out << "wanted_murder_number_of_uses_sc"; 
			break;
		case mpe_rpc_cmd::wanted_murder_reward_check_cs:
			out << "wanted_murder_reward_check_cs"; 
			break;
		case mpe_rpc_cmd::wanted_murder_reward_check_sc:
			out << "wanted_murder_reward_check_sc"; 
			break;
		case mpe_rpc_cmd::guild_change_introduction_cs:
			out << "guild_change_introduction_cs"; 
			break;
		case mpe_rpc_cmd::guild_change_introduction_sc:
			out << "guild_change_introduction_sc"; 
			break;
		case mpe_rpc_cmd::guild_pr_cs:
			out << "guild_pr_cs"; 
			break;
		case mpe_rpc_cmd::guild_pr_sc:
			out << "guild_pr_sc"; 
			break;
		case mpe_rpc_cmd::guild_invite_cs:
			out << "guild_invite_cs"; 
			break;
		case mpe_rpc_cmd::guild_invite_sc:
			out << "guild_invite_sc"; 
			break;
		case mpe_rpc_cmd::guild_invite_accept_cs:
			out << "guild_invite_accept_cs"; 
			break;
		case mpe_rpc_cmd::guild_invite_accept_sc:
			out << "guild_invite_accept_sc"; 
			break;
		case mpe_rpc_cmd::guild_invite_refusal_cs:
			out << "guild_invite_refusal_cs"; 
			break;
		case mpe_rpc_cmd::guild_invite_refusal_sc:
			out << "guild_invite_refusal_sc"; 
			break;
		case mpe_rpc_cmd::guild_invite_notify_cs:
			out << "guild_invite_notify_cs"; 
			break;
		case mpe_rpc_cmd::guild_invite_notify_sc:
			out << "guild_invite_notify_sc"; 
			break;
		case mpe_rpc_cmd::guild_pr_notify_cs:
			out << "guild_pr_notify_cs"; 
			break;
		case mpe_rpc_cmd::guild_pr_notify_sc:
			out << "guild_pr_notify_sc"; 
			break;
		case mpe_rpc_cmd::empty3_check_cs:
			out << "empty3_check_cs"; 
			break;
		case mpe_rpc_cmd::empty3_check_sc:
			out << "empty3_check_sc"; 
			break;
		case mpe_rpc_cmd::zone_teleport_save_area_delete_cs:
			out << "zone_teleport_save_area_delete_cs"; 
			break;
		case mpe_rpc_cmd::zone_teleport_save_area_delete_sc:
			out << "zone_teleport_save_area_delete_sc"; 
			break;
		case mpe_rpc_cmd::dictionary_reward_get_cs:
			out << "dictionary_reward_get_cs"; 
			break;
		case mpe_rpc_cmd::dictionary_reward_get_sc:
			out << "dictionary_reward_get_sc"; 
			break;
		case mpe_rpc_cmd::dictionary_achieve_rate_get_cs:
			out << "dictionary_achieve_rate_get_cs"; 
			break;
		case mpe_rpc_cmd::dictionary_achieve_rate_get_sc:
			out << "dictionary_achieve_rate_get_sc"; 
			break;
		case mpe_rpc_cmd::tutorial_complete_cs:
			out << "tutorial_complete_cs"; 
			break;
		case mpe_rpc_cmd::tutorial_complete_sc:
			out << "tutorial_complete_sc"; 
			break;
		case mpe_rpc_cmd::indun_create_first_story_cs:
			out << "indun_create_first_story_cs"; 
			break;
		case mpe_rpc_cmd::indun_create_first_story_sc:
			out << "indun_create_first_story_sc"; 
			break;
		case mpe_rpc_cmd::dictionary_bookmark_get_cs:
			out << "dictionary_bookmark_get_cs"; 
			break;
		case mpe_rpc_cmd::dictionary_bookmark_get_sc:
			out << "dictionary_bookmark_get_sc"; 
			break;
		case mpe_rpc_cmd::paid_acc_reinforce_cs:
			out << "paid_acc_reinforce_cs"; 
			break;
		case mpe_rpc_cmd::paid_acc_reinforce_sc:
			out << "paid_acc_reinforce_sc"; 
			break;
		case mpe_rpc_cmd::friend_request_response_all_cs:
			out << "friend_request_response_all_cs"; 
			break;
		case mpe_rpc_cmd::friend_request_response_all_sc:
			out << "friend_request_response_all_sc"; 
			break;
		case mpe_rpc_cmd::start_ai_service_cs:
			out << "start_ai_service_cs"; 
			break;
		case mpe_rpc_cmd::start_ai_service_sc:
			out << "start_ai_service_sc"; 
			break;
		case mpe_rpc_cmd::logout_ai_service_cs:
			out << "logout_ai_service_cs"; 
			break;
		case mpe_rpc_cmd::logout_ai_service_sc:
			out << "logout_ai_service_sc"; 
			break;
		case mpe_rpc_cmd::community_zone_initialize_cs:
			out << "community_zone_initialize_cs"; 
			break;
		case mpe_rpc_cmd::community_zone_initialize_sc:
			out << "community_zone_initialize_sc"; 
			break;
		case mpe_rpc_cmd::community_zone_create_cs:
			out << "community_zone_create_cs"; 
			break;
		case mpe_rpc_cmd::community_zone_create_sc:
			out << "community_zone_create_sc"; 
			break;
		case mpe_rpc_cmd::community_game_login_cs:
			out << "community_game_login_cs"; 
			break;
		case mpe_rpc_cmd::community_game_login_sc:
			out << "community_game_login_sc"; 
			break;
		case mpe_rpc_cmd::community_zone_enter_cs:
			out << "community_zone_enter_cs"; 
			break;
		case mpe_rpc_cmd::community_zone_enter_sc:
			out << "community_zone_enter_sc"; 
			break;
		case mpe_rpc_cmd::dictionary_expire_cs:
			out << "dictionary_expire_cs"; 
			break;
		case mpe_rpc_cmd::dictionary_expire_sc:
			out << "dictionary_expire_sc"; 
			break;
		case mpe_rpc_cmd::community_guild_member_cs:
			out << "community_guild_member_cs"; 
			break;
		case mpe_rpc_cmd::community_guild_member_sc:
			out << "community_guild_member_sc"; 
			break;
		case mpe_rpc_cmd::community_party_member_cs:
			out << "community_party_member_cs"; 
			break;
		case mpe_rpc_cmd::community_party_member_sc:
			out << "community_party_member_sc"; 
			break;
		case mpe_rpc_cmd::item_acc_reinforce_cs:
			out << "item_acc_reinforce_cs"; 
			break;
		case mpe_rpc_cmd::item_acc_reinforce_sc:
			out << "item_acc_reinforce_sc"; 
			break;
		case mpe_rpc_cmd::cash_shop_info_cs:
			out << "cash_shop_info_cs"; 
			break;
		case mpe_rpc_cmd::cash_shop_info_sc:
			out << "cash_shop_info_sc"; 
			break;
		case mpe_rpc_cmd::cash_shop_cart_get_cs:
			out << "cash_shop_cart_get_cs"; 
			break;
		case mpe_rpc_cmd::cash_shop_cart_get_sc:
			out << "cash_shop_cart_get_sc"; 
			break;
		case mpe_rpc_cmd::cash_shop_buy_cs:
			out << "cash_shop_buy_cs"; 
			break;
		case mpe_rpc_cmd::cash_shop_buy_sc:
			out << "cash_shop_buy_sc"; 
			break;
		case mpe_rpc_cmd::mail_clean_cs:
			out << "mail_clean_cs"; 
			break;
		case mpe_rpc_cmd::mail_clean_sc:
			out << "mail_clean_sc"; 
			break;
		case mpe_rpc_cmd::mentor_levelup_reward_cs:
			out << "mentor_levelup_reward_cs"; 
			break;
		case mpe_rpc_cmd::mentor_levelup_reward_sc:
			out << "mentor_levelup_reward_sc"; 
			break;
		case mpe_rpc_cmd::channel_update_zoneinfo_cs:
			out << "channel_update_zoneinfo_cs"; 
			break;
		case mpe_rpc_cmd::channel_update_zoneinfo_sc:
			out << "channel_update_zoneinfo_sc"; 
			break;
		case mpe_rpc_cmd::ai_setup_config_cs:
			out << "ai_setup_config_cs"; 
			break;
		case mpe_rpc_cmd::ai_setup_config_sc:
			out << "ai_setup_config_sc"; 
			break;
		case mpe_rpc_cmd::server_info_cs:
			out << "server_info_cs"; 
			break;
		case mpe_rpc_cmd::server_info_sc:
			out << "server_info_sc"; 
			break;
		case mpe_rpc_cmd::cash_shop_exchange_reset_cs:
			out << "cash_shop_exchange_reset_cs"; 
			break;
		case mpe_rpc_cmd::cash_shop_exchange_reset_sc:
			out << "cash_shop_exchange_reset_sc"; 
			break;
		case mpe_rpc_cmd::cash_shop_limited_product_cs:
			out << "cash_shop_limited_product_cs"; 
			break;
		case mpe_rpc_cmd::cash_shop_limited_product_sc:
			out << "cash_shop_limited_product_sc"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_info_cs:
			out << "guild_shipwar_info_cs"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_info_sc:
			out << "guild_shipwar_info_sc"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_request_cs:
			out << "guild_shipwar_request_cs"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_request_sc:
			out << "guild_shipwar_request_sc"; 
			break;
		case mpe_rpc_cmd::channel_update_lobby_zoneinfo_cs:
			out << "channel_update_lobby_zoneinfo_cs"; 
			break;
		case mpe_rpc_cmd::channel_update_lobby_zoneinfo_sc:
			out << "channel_update_lobby_zoneinfo_sc"; 
			break;
		case mpe_rpc_cmd::server_use_count_cs:
			out << "server_use_count_cs"; 
			break;
		case mpe_rpc_cmd::server_use_count_sc:
			out << "server_use_count_sc"; 
			break;
		case mpe_rpc_cmd::channel_remove_cs:
			out << "channel_remove_cs"; 
			break;
		case mpe_rpc_cmd::channel_remove_sc:
			out << "channel_remove_sc"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_match_complete_cs:
			out << "guild_shipwar_match_complete_cs"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_match_complete_sc:
			out << "guild_shipwar_match_complete_sc"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_create_cs:
			out << "guild_shipwar_create_cs"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_create_sc:
			out << "guild_shipwar_create_sc"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_prepare_request_cs:
			out << "guild_shipwar_prepare_request_cs"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_prepare_request_sc:
			out << "guild_shipwar_prepare_request_sc"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_calculate_cs:
			out << "guild_shipwar_calculate_cs"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_calculate_sc:
			out << "guild_shipwar_calculate_sc"; 
			break;
		case mpe_rpc_cmd::community_social_motion_cs:
			out << "community_social_motion_cs"; 
			break;
		case mpe_rpc_cmd::community_social_motion_sc:
			out << "community_social_motion_sc"; 
			break;
		case mpe_rpc_cmd::red_dot_noti_cs:
			out << "red_dot_noti_cs"; 
			break;
		case mpe_rpc_cmd::red_dot_noti_sc:
			out << "red_dot_noti_sc"; 
			break;
		case mpe_rpc_cmd::private_chatting_disable_update_cs:
			out << "private_chatting_disable_update_cs"; 
			break;
		case mpe_rpc_cmd::private_chatting_disable_update_sc:
			out << "private_chatting_disable_update_sc"; 
			break;
		case mpe_rpc_cmd::cash_shop_daily_get_cs:
			out << "cash_shop_daily_get_cs"; 
			break;
		case mpe_rpc_cmd::cash_shop_daily_get_sc:
			out << "cash_shop_daily_get_sc"; 
			break;
		case mpe_rpc_cmd::town_rental_request_cs:
			out << "town_rental_request_cs"; 
			break;
		case mpe_rpc_cmd::town_rental_request_sc:
			out << "town_rental_request_sc"; 
			break;
		case mpe_rpc_cmd::town_create_cs:
			out << "town_create_cs"; 
			break;
		case mpe_rpc_cmd::town_create_sc:
			out << "town_create_sc"; 
			break;
		case mpe_rpc_cmd::town_alert_cs:
			out << "town_alert_cs"; 
			break;
		case mpe_rpc_cmd::town_alert_sc:
			out << "town_alert_sc"; 
			break;
		case mpe_rpc_cmd::town_rental_continuation_cs:
			out << "town_rental_continuation_cs"; 
			break;
		case mpe_rpc_cmd::town_rental_continuation_sc:
			out << "town_rental_continuation_sc"; 
			break;
		case mpe_rpc_cmd::schedule_info_list_cs:
			out << "schedule_info_list_cs"; 
			break;
		case mpe_rpc_cmd::schedule_info_list_sc:
			out << "schedule_info_list_sc"; 
			break;
		case mpe_rpc_cmd::town_indun_create_req_cs:
			out << "town_indun_create_req_cs"; 
			break;
		case mpe_rpc_cmd::town_indun_create_req_sc:
			out << "town_indun_create_req_sc"; 
			break;
		case mpe_rpc_cmd::ai_setup_config_select_cs:
			out << "ai_setup_config_select_cs"; 
			break;
		case mpe_rpc_cmd::ai_setup_config_select_sc:
			out << "ai_setup_config_select_sc"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_match_failed_cs:
			out << "guild_shipwar_match_failed_cs"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_match_failed_sc:
			out << "guild_shipwar_match_failed_sc"; 
			break;
		case mpe_rpc_cmd::subscription_add_cs:
			out << "subscription_add_cs"; 
			break;
		case mpe_rpc_cmd::subscription_add_sc:
			out << "subscription_add_sc"; 
			break;
		case mpe_rpc_cmd::subscription_info_cs:
			out << "subscription_info_cs"; 
			break;
		case mpe_rpc_cmd::subscription_info_sc:
			out << "subscription_info_sc"; 
			break;
		case mpe_rpc_cmd::subscription_del_cs:
			out << "subscription_del_cs"; 
			break;
		case mpe_rpc_cmd::subscription_del_sc:
			out << "subscription_del_sc"; 
			break;
		case mpe_rpc_cmd::transform_avatar_cs:
			out << "transform_avatar_cs"; 
			break;
		case mpe_rpc_cmd::transform_avatar_sc:
			out << "transform_avatar_sc"; 
			break;
		case mpe_rpc_cmd::mentor_party_buff_cs:
			out << "mentor_party_buff_cs"; 
			break;
		case mpe_rpc_cmd::mentor_party_buff_sc:
			out << "mentor_party_buff_sc"; 
			break;
		case mpe_rpc_cmd::dictionary_get_all_cs:
			out << "dictionary_get_all_cs"; 
			break;
		case mpe_rpc_cmd::dictionary_get_all_sc:
			out << "dictionary_get_all_sc"; 
			break;
		case mpe_rpc_cmd::channel_create_cs:
			out << "channel_create_cs"; 
			break;
		case mpe_rpc_cmd::channel_create_sc:
			out << "channel_create_sc"; 
			break;
		case mpe_rpc_cmd::siege_warfare_victory_character_info_cs:
			out << "siege_warfare_victory_character_info_cs"; 
			break;
		case mpe_rpc_cmd::siege_warfare_victory_character_info_sc:
			out << "siege_warfare_victory_character_info_sc"; 
			break;
		case mpe_rpc_cmd::channel_enable_cs:
			out << "channel_enable_cs"; 
			break;
		case mpe_rpc_cmd::channel_enable_sc:
			out << "channel_enable_sc"; 
			break;
		case mpe_rpc_cmd::npc_intimacy_reward_cs:
			out << "npc_intimacy_reward_cs"; 
			break;
		case mpe_rpc_cmd::npc_intimacy_reward_sc:
			out << "npc_intimacy_reward_sc"; 
			break;
		case mpe_rpc_cmd::slot_option_make_cs:
			out << "slot_option_make_cs"; 
			break;
		case mpe_rpc_cmd::slot_option_make_sc:
			out << "slot_option_make_sc"; 
			break;
		case mpe_rpc_cmd::slot_option_select_cs:
			out << "slot_option_select_cs"; 
			break;
		case mpe_rpc_cmd::slot_option_select_sc:
			out << "slot_option_select_sc"; 
			break;
		case mpe_rpc_cmd::slot_upgrade_cs:
			out << "slot_upgrade_cs"; 
			break;
		case mpe_rpc_cmd::slot_upgrade_sc:
			out << "slot_upgrade_sc"; 
			break;
		case mpe_rpc_cmd::npc_intimacy_reward_get_cs:
			out << "npc_intimacy_reward_get_cs"; 
			break;
		case mpe_rpc_cmd::npc_intimacy_reward_get_sc:
			out << "npc_intimacy_reward_get_sc"; 
			break;
		case mpe_rpc_cmd::treasureboxkey_update_cs:
			out << "treasureboxkey_update_cs"; 
			break;
		case mpe_rpc_cmd::treasureboxkey_update_sc:
			out << "treasureboxkey_update_sc"; 
			break;
		case mpe_rpc_cmd::change_pet_team_cs:
			out << "change_pet_team_cs"; 
			break;
		case mpe_rpc_cmd::change_pet_team_sc:
			out << "change_pet_team_sc"; 
			break;
		case mpe_rpc_cmd::guild_treasurebox_reward_cs:
			out << "guild_treasurebox_reward_cs"; 
			break;
		case mpe_rpc_cmd::guild_treasurebox_reward_sc:
			out << "guild_treasurebox_reward_sc"; 
			break;
		case mpe_rpc_cmd::channel_use_temp_count_cs:
			out << "channel_use_temp_count_cs"; 
			break;
		case mpe_rpc_cmd::channel_use_temp_count_sc:
			out << "channel_use_temp_count_sc"; 
			break;
		case mpe_rpc_cmd::wanted_murder_target_cs:
			out << "wanted_murder_target_cs"; 
			break;
		case mpe_rpc_cmd::wanted_murder_target_sc:
			out << "wanted_murder_target_sc"; 
			break;
		case mpe_rpc_cmd::wanted_murder_trace_cs:
			out << "wanted_murder_trace_cs"; 
			break;
		case mpe_rpc_cmd::wanted_murder_trace_sc:
			out << "wanted_murder_trace_sc"; 
			break;
		case mpe_rpc_cmd::seasonpass_change_cs:
			out << "seasonpass_change_cs"; 
			break;
		case mpe_rpc_cmd::seasonpass_change_sc:
			out << "seasonpass_change_sc"; 
			break;
		case mpe_rpc_cmd::seasonpass_unlock_cs:
			out << "seasonpass_unlock_cs"; 
			break;
		case mpe_rpc_cmd::seasonpass_unlock_sc:
			out << "seasonpass_unlock_sc"; 
			break;
		case mpe_rpc_cmd::seasonpass_reward_cs:
			out << "seasonpass_reward_cs"; 
			break;
		case mpe_rpc_cmd::seasonpass_reward_sc:
			out << "seasonpass_reward_sc"; 
			break;
		case mpe_rpc_cmd::seasonpass_challenge_complet_cs:
			out << "seasonpass_challenge_complet_cs"; 
			break;
		case mpe_rpc_cmd::seasonpass_challenge_complet_sc:
			out << "seasonpass_challenge_complet_sc"; 
			break;
		case mpe_rpc_cmd::seasonpass_challenge_update_cs:
			out << "seasonpass_challenge_update_cs"; 
			break;
		case mpe_rpc_cmd::seasonpass_challenge_update_sc:
			out << "seasonpass_challenge_update_sc"; 
			break;
		case mpe_rpc_cmd::channel_move_check_cs:
			out << "channel_move_check_cs"; 
			break;
		case mpe_rpc_cmd::channel_move_check_sc:
			out << "channel_move_check_sc"; 
			break;
		case mpe_rpc_cmd::pk_alert_record_remove_cs:
			out << "pk_alert_record_remove_cs"; 
			break;
		case mpe_rpc_cmd::pk_alert_record_remove_sc:
			out << "pk_alert_record_remove_sc"; 
			break;
		case mpe_rpc_cmd::wanted_murder_remove_cs:
			out << "wanted_murder_remove_cs"; 
			break;
		case mpe_rpc_cmd::wanted_murder_remove_sc:
			out << "wanted_murder_remove_sc"; 
			break;
		case mpe_rpc_cmd::character_delete_cancel_cs:
			out << "character_delete_cancel_cs"; 
			break;
		case mpe_rpc_cmd::character_delete_cancel_sc:
			out << "character_delete_cancel_sc"; 
			break;
		case mpe_rpc_cmd::character_delete_friend_delete_cs:
			out << "character_delete_friend_delete_cs"; 
			break;
		case mpe_rpc_cmd::character_delete_friend_delete_sc:
			out << "character_delete_friend_delete_sc"; 
			break;
		case mpe_rpc_cmd::avatar_mix_cs:
			out << "avatar_mix_cs"; 
			break;
		case mpe_rpc_cmd::avatar_mix_sc:
			out << "avatar_mix_sc"; 
			break;
		case mpe_rpc_cmd::avatar_slot_set_cs:
			out << "avatar_slot_set_cs"; 
			break;
		case mpe_rpc_cmd::avatar_slot_set_sc:
			out << "avatar_slot_set_sc"; 
			break;
		case mpe_rpc_cmd::guild_goods_update_cs:
			out << "guild_goods_update_cs"; 
			break;
		case mpe_rpc_cmd::guild_goods_update_sc:
			out << "guild_goods_update_sc"; 
			break;
		case mpe_rpc_cmd::guild_mark_change_cs:
			out << "guild_mark_change_cs"; 
			break;
		case mpe_rpc_cmd::guild_mark_change_sc:
			out << "guild_mark_change_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_change_mark_cs:
			out << "guild_alert_change_mark_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_change_mark_sc:
			out << "guild_alert_change_mark_sc"; 
			break;
		case mpe_rpc_cmd::guild_buff_buy_cs:
			out << "guild_buff_buy_cs"; 
			break;
		case mpe_rpc_cmd::guild_buff_buy_sc:
			out << "guild_buff_buy_sc"; 
			break;
		case mpe_rpc_cmd::ranking_character_delete_cs:
			out << "ranking_character_delete_cs"; 
			break;
		case mpe_rpc_cmd::ranking_character_delete_sc:
			out << "ranking_character_delete_sc"; 
			break;
		case mpe_rpc_cmd::guild_gold_alert_cs:
			out << "guild_gold_alert_cs"; 
			break;
		case mpe_rpc_cmd::guild_gold_alert_sc:
			out << "guild_gold_alert_sc"; 
			break;
		case mpe_rpc_cmd::castle_owner_change_mark_cs:
			out << "castle_owner_change_mark_cs"; 
			break;
		case mpe_rpc_cmd::castle_owner_change_mark_sc:
			out << "castle_owner_change_mark_sc"; 
			break;
		case mpe_rpc_cmd::mail_list_send_cs:
			out << "mail_list_send_cs"; 
			break;
		case mpe_rpc_cmd::mail_list_send_sc:
			out << "mail_list_send_sc"; 
			break;
		case mpe_rpc_cmd::event_reward_reset_cs:
			out << "event_reward_reset_cs"; 
			break;
		case mpe_rpc_cmd::event_reward_reset_sc:
			out << "event_reward_reset_sc"; 
			break;
		case mpe_rpc_cmd::item_lock_cs:
			out << "item_lock_cs"; 
			break;
		case mpe_rpc_cmd::item_lock_sc:
			out << "item_lock_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_storage_treasure_new_cs:
			out << "guild_alert_storage_treasure_new_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_storage_treasure_new_sc:
			out << "guild_alert_storage_treasure_new_sc"; 
			break;
		case mpe_rpc_cmd::lord_worship_cs:
			out << "lord_worship_cs"; 
			break;
		case mpe_rpc_cmd::lord_worship_sc:
			out << "lord_worship_sc"; 
			break;
		case mpe_rpc_cmd::lord_message_cs:
			out << "lord_message_cs"; 
			break;
		case mpe_rpc_cmd::lord_message_sc:
			out << "lord_message_sc"; 
			break;
		case mpe_rpc_cmd::lord_bless_buff_cs:
			out << "lord_bless_buff_cs"; 
			break;
		case mpe_rpc_cmd::lord_bless_buff_sc:
			out << "lord_bless_buff_sc"; 
			break;
		case mpe_rpc_cmd::revive_list_cs:
			out << "revive_list_cs"; 
			break;
		case mpe_rpc_cmd::revive_list_sc:
			out << "revive_list_sc"; 
			break;
		case mpe_rpc_cmd::recovery_exp_cs:
			out << "recovery_exp_cs"; 
			break;
		case mpe_rpc_cmd::recovery_exp_sc:
			out << "recovery_exp_sc"; 
			break;
		case mpe_rpc_cmd::get_revive_list_cs:
			out << "get_revive_list_cs"; 
			break;
		case mpe_rpc_cmd::get_revive_list_sc:
			out << "get_revive_list_sc"; 
			break;
		case mpe_rpc_cmd::secretvalley_state_cs:
			out << "secretvalley_state_cs"; 
			break;
		case mpe_rpc_cmd::secretvalley_state_sc:
			out << "secretvalley_state_sc"; 
			break;
		case mpe_rpc_cmd::siege_schedule_reload_cs:
			out << "siege_schedule_reload_cs"; 
			break;
		case mpe_rpc_cmd::siege_schedule_reload_sc:
			out << "siege_schedule_reload_sc"; 
			break;
		case mpe_rpc_cmd::illusion_dungeon_update_cs:
			out << "illusion_dungeon_update_cs"; 
			break;
		case mpe_rpc_cmd::illusion_dungeon_update_sc:
			out << "illusion_dungeon_update_sc"; 
			break;
		case mpe_rpc_cmd::illusion_dungeon_time_charge_cs:
			out << "illusion_dungeon_time_charge_cs"; 
			break;
		case mpe_rpc_cmd::illusion_dungeon_time_charge_sc:
			out << "illusion_dungeon_time_charge_sc"; 
			break;
		case mpe_rpc_cmd::zone_seal_device_use_cs:
			out << "zone_seal_device_use_cs"; 
			break;
		case mpe_rpc_cmd::zone_seal_device_use_sc:
			out << "zone_seal_device_use_sc"; 
			break;
		case mpe_rpc_cmd::reflection_equip_cs:
			out << "reflection_equip_cs"; 
			break;
		case mpe_rpc_cmd::reflection_equip_sc:
			out << "reflection_equip_sc"; 
			break;
		case mpe_rpc_cmd::reflection_mix_cs:
			out << "reflection_mix_cs"; 
			break;
		case mpe_rpc_cmd::reflection_mix_sc:
			out << "reflection_mix_sc"; 
			break;
		case mpe_rpc_cmd::customizing_save_cs:
			out << "customizing_save_cs"; 
			break;
		case mpe_rpc_cmd::customizing_save_sc:
			out << "customizing_save_sc"; 
			break;
		case mpe_rpc_cmd::blackiron_sell_regist_cs:
			out << "blackiron_sell_regist_cs"; 
			break;
		case mpe_rpc_cmd::blackiron_sell_regist_sc:
			out << "blackiron_sell_regist_sc"; 
			break;
		case mpe_rpc_cmd::guild_blackiron_alert_cs:
			out << "guild_blackiron_alert_cs"; 
			break;
		case mpe_rpc_cmd::guild_blackiron_alert_sc:
			out << "guild_blackiron_alert_sc"; 
			break;
		case mpe_rpc_cmd::blackiron_sell_info_cs:
			out << "blackiron_sell_info_cs"; 
			break;
		case mpe_rpc_cmd::blackiron_sell_info_sc:
			out << "blackiron_sell_info_sc"; 
			break;
		case mpe_rpc_cmd::blackiron_buy_cs:
			out << "blackiron_buy_cs"; 
			break;
		case mpe_rpc_cmd::blackiron_buy_sc:
			out << "blackiron_buy_sc"; 
			break;
		case mpe_rpc_cmd::secretvalley_set_owner_cs:
			out << "secretvalley_set_owner_cs"; 
			break;
		case mpe_rpc_cmd::secretvalley_set_owner_sc:
			out << "secretvalley_set_owner_sc"; 
			break;
		case mpe_rpc_cmd::secretvalley_set_owner_info_cs:
			out << "secretvalley_set_owner_info_cs"; 
			break;
		case mpe_rpc_cmd::secretvalley_set_owner_info_sc:
			out << "secretvalley_set_owner_info_sc"; 
			break;
		case mpe_rpc_cmd::blackiron_collect_tax_cs:
			out << "blackiron_collect_tax_cs"; 
			break;
		case mpe_rpc_cmd::blackiron_collect_tax_sc:
			out << "blackiron_collect_tax_sc"; 
			break;
		case mpe_rpc_cmd::temp_reflection_change_cs:
			out << "temp_reflection_change_cs"; 
			break;
		case mpe_rpc_cmd::temp_reflection_change_sc:
			out << "temp_reflection_change_sc"; 
			break;
		case mpe_rpc_cmd::temp_reflection_confirm_cs:
			out << "temp_reflection_confirm_cs"; 
			break;
		case mpe_rpc_cmd::temp_reflection_confirm_sc:
			out << "temp_reflection_confirm_sc"; 
			break;
		case mpe_rpc_cmd::temp_reflection_get_cs:
			out << "temp_reflection_get_cs"; 
			break;
		case mpe_rpc_cmd::temp_reflection_get_sc:
			out << "temp_reflection_get_sc"; 
			break;
		case mpe_rpc_cmd::arena_battle_match_regist_cs:
			out << "arena_battle_match_regist_cs"; 
			break;
		case mpe_rpc_cmd::arena_battle_match_regist_sc:
			out << "arena_battle_match_regist_sc"; 
			break;
		case mpe_rpc_cmd::arena_battle_match_regist_cancel_cs:
			out << "arena_battle_match_regist_cancel_cs"; 
			break;
		case mpe_rpc_cmd::arena_battle_match_regist_cancel_sc:
			out << "arena_battle_match_regist_cancel_sc"; 
			break;
		case mpe_rpc_cmd::arena_battle_create_cs:
			out << "arena_battle_create_cs"; 
			break;
		case mpe_rpc_cmd::arena_battle_create_sc:
			out << "arena_battle_create_sc"; 
			break;
		case mpe_rpc_cmd::arena_battle_add_score_cs:
			out << "arena_battle_add_score_cs"; 
			break;
		case mpe_rpc_cmd::arena_battle_add_score_sc:
			out << "arena_battle_add_score_sc"; 
			break;
		case mpe_rpc_cmd::arena_battle_season_reward_cs:
			out << "arena_battle_season_reward_cs"; 
			break;
		case mpe_rpc_cmd::arena_battle_season_reward_sc:
			out << "arena_battle_season_reward_sc"; 
			break;
		case mpe_rpc_cmd::skill_force_reinforce_cs:
			out << "skill_force_reinforce_cs"; 
			break;
		case mpe_rpc_cmd::skill_force_reinforce_sc:
			out << "skill_force_reinforce_sc"; 
			break;
		case mpe_rpc_cmd::mandala_node_add_cs:
			out << "mandala_node_add_cs"; 
			break;
		case mpe_rpc_cmd::mandala_node_add_sc:
			out << "mandala_node_add_sc"; 
			break;
		case mpe_rpc_cmd::mandala_rotation_cs:
			out << "mandala_rotation_cs"; 
			break;
		case mpe_rpc_cmd::mandala_rotation_sc:
			out << "mandala_rotation_sc"; 
			break;
		case mpe_rpc_cmd::mandala_reset_cs:
			out << "mandala_reset_cs"; 
			break;
		case mpe_rpc_cmd::mandala_reset_sc:
			out << "mandala_reset_sc"; 
			break;
		case mpe_rpc_cmd::mandala_node_levelup_cs:
			out << "mandala_node_levelup_cs"; 
			break;
		case mpe_rpc_cmd::mandala_node_levelup_sc:
			out << "mandala_node_levelup_sc"; 
			break;
		case mpe_rpc_cmd::mandala_node_equip_cs:
			out << "mandala_node_equip_cs"; 
			break;
		case mpe_rpc_cmd::mandala_node_equip_sc:
			out << "mandala_node_equip_sc"; 
			break;
		case mpe_rpc_cmd::mandala_stone_upgrade_cs:
			out << "mandala_stone_upgrade_cs"; 
			break;
		case mpe_rpc_cmd::mandala_stone_upgrade_sc:
			out << "mandala_stone_upgrade_sc"; 
			break;
		case mpe_rpc_cmd::auto_matching_state_cs:
			out << "auto_matching_state_cs"; 
			break;
		case mpe_rpc_cmd::auto_matching_state_sc:
			out << "auto_matching_state_sc"; 
			break;
		case mpe_rpc_cmd::party_pr_cs:
			out << "party_pr_cs"; 
			break;
		case mpe_rpc_cmd::party_pr_sc:
			out << "party_pr_sc"; 
			break;
		case mpe_rpc_cmd::secretvalley_info_cs:
			out << "secretvalley_info_cs"; 
			break;
		case mpe_rpc_cmd::secretvalley_info_sc:
			out << "secretvalley_info_sc"; 
			break;
		case mpe_rpc_cmd::street_stall_start_cs:
			out << "street_stall_start_cs"; 
			break;
		case mpe_rpc_cmd::street_stall_start_sc:
			out << "street_stall_start_sc"; 
			break;
		case mpe_rpc_cmd::street_stall_update_cs:
			out << "street_stall_update_cs"; 
			break;
		case mpe_rpc_cmd::street_stall_update_sc:
			out << "street_stall_update_sc"; 
			break;
		case mpe_rpc_cmd::street_stall_reset_time_update_cs:
			out << "street_stall_reset_time_update_cs"; 
			break;
		case mpe_rpc_cmd::street_stall_reset_time_update_sc:
			out << "street_stall_reset_time_update_sc"; 
			break;
		case mpe_rpc_cmd::street_stall_end_cs:
			out << "street_stall_end_cs"; 
			break;
		case mpe_rpc_cmd::street_stall_end_sc:
			out << "street_stall_end_sc"; 
			break;
		case mpe_rpc_cmd::community_object_run_time_update_cs:
			out << "community_object_run_time_update_cs"; 
			break;
		case mpe_rpc_cmd::community_object_run_time_update_sc:
			out << "community_object_run_time_update_sc"; 
			break;
		case mpe_rpc_cmd::community_object_message_cs:
			out << "community_object_message_cs"; 
			break;
		case mpe_rpc_cmd::community_object_message_sc:
			out << "community_object_message_sc"; 
			break;
		case mpe_rpc_cmd::contents_onoff_update_cs:
			out << "contents_onoff_update_cs"; 
			break;
		case mpe_rpc_cmd::contents_onoff_update_sc:
			out << "contents_onoff_update_sc"; 
			break;
		case mpe_rpc_cmd::achieve_reward_cs:
			out << "achieve_reward_cs"; 
			break;
		case mpe_rpc_cmd::achieve_reward_sc:
			out << "achieve_reward_sc"; 
			break;
		case mpe_rpc_cmd::ranking_reset_cs:
			out << "ranking_reset_cs"; 
			break;
		case mpe_rpc_cmd::ranking_reset_sc:
			out << "ranking_reset_sc"; 
			break;
		case mpe_rpc_cmd::ranking_update_cs:
			out << "ranking_update_cs"; 
			break;
		case mpe_rpc_cmd::ranking_update_sc:
			out << "ranking_update_sc"; 
			break;
		case mpe_rpc_cmd::cashshop_payment_cs:
			out << "cashshop_payment_cs"; 
			break;
		case mpe_rpc_cmd::cashshop_payment_sc:
			out << "cashshop_payment_sc"; 
			break;
		case mpe_rpc_cmd::achieve_add_cs:
			out << "achieve_add_cs"; 
			break;
		case mpe_rpc_cmd::achieve_add_sc:
			out << "achieve_add_sc"; 
			break;
		case mpe_rpc_cmd::skip_log_cs:
			out << "skip_log_cs"; 
			break;
		case mpe_rpc_cmd::skip_log_sc:
			out << "skip_log_sc"; 
			break;
		case mpe_rpc_cmd::send_nickname_disable_cs:
			out << "send_nickname_disable_cs"; 
			break;
		case mpe_rpc_cmd::send_nickname_disable_sc:
			out << "send_nickname_disable_sc"; 
			break;
		case mpe_rpc_cmd::quest_reward_change_cs:
			out << "quest_reward_change_cs"; 
			break;
		case mpe_rpc_cmd::quest_reward_change_sc:
			out << "quest_reward_change_sc"; 
			break;
		case mpe_rpc_cmd::arena_battle_matching_count_cs:
			out << "arena_battle_matching_count_cs"; 
			break;
		case mpe_rpc_cmd::arena_battle_matching_count_sc:
			out << "arena_battle_matching_count_sc"; 
			break;
		case mpe_rpc_cmd::cheatkey_drop_probalility_cs:
			out << "cheatkey_drop_probalility_cs"; 
			break;
		case mpe_rpc_cmd::cheatkey_drop_probalility_sc:
			out << "cheatkey_drop_probalility_sc"; 
			break;
		case mpe_rpc_cmd::red_dot_noti_server_cs:
			out << "red_dot_noti_server_cs"; 
			break;
		case mpe_rpc_cmd::red_dot_noti_server_sc:
			out << "red_dot_noti_server_sc"; 
			break;
		case mpe_rpc_cmd::character_guild_join_time_reset_cs:
			out << "character_guild_join_time_reset_cs"; 
			break;
		case mpe_rpc_cmd::character_guild_join_time_reset_sc:
			out << "character_guild_join_time_reset_sc"; 
			break;
		case mpe_rpc_cmd::guild_member_daily_reset_cs:
			out << "guild_member_daily_reset_cs"; 
			break;
		case mpe_rpc_cmd::guild_member_daily_reset_sc:
			out << "guild_member_daily_reset_sc"; 
			break;
		case mpe_rpc_cmd::cheatkey_mix_probalility_cs:
			out << "cheatkey_mix_probalility_cs"; 
			break;
		case mpe_rpc_cmd::cheatkey_mix_probalility_sc:
			out << "cheatkey_mix_probalility_sc"; 
			break;
		case mpe_rpc_cmd::blackiron_calc_tax_cs:
			out << "blackiron_calc_tax_cs"; 
			break;
		case mpe_rpc_cmd::blackiron_calc_tax_sc:
			out << "blackiron_calc_tax_sc"; 
			break;
		case mpe_rpc_cmd::guild_storage_material_add_cheat_cs:
			out << "guild_storage_material_add_cheat_cs"; 
			break;
		case mpe_rpc_cmd::guild_storage_material_add_cheat_sc:
			out << "guild_storage_material_add_cheat_sc"; 
			break;
		case mpe_rpc_cmd::item_enchant_option_change_cs:
			out << "item_enchant_option_change_cs"; 
			break;
		case mpe_rpc_cmd::item_enchant_option_change_sc:
			out << "item_enchant_option_change_sc"; 
			break;
		case mpe_rpc_cmd::arena_battle_result_cs:
			out << "arena_battle_result_cs"; 
			break;
		case mpe_rpc_cmd::arena_battle_result_sc:
			out << "arena_battle_result_sc"; 
			break;
		case mpe_rpc_cmd::guild_goods_exchange_cs:
			out << "guild_goods_exchange_cs"; 
			break;
		case mpe_rpc_cmd::guild_goods_exchange_sc:
			out << "guild_goods_exchange_sc"; 
			break;
		case mpe_rpc_cmd::fieldboss_spawn_regist_cs:
			out << "fieldboss_spawn_regist_cs"; 
			break;
		case mpe_rpc_cmd::fieldboss_spawn_regist_sc:
			out << "fieldboss_spawn_regist_sc"; 
			break;
		case mpe_rpc_cmd::field_boss_spawn_cs:
			out << "field_boss_spawn_cs"; 
			break;
		case mpe_rpc_cmd::field_boss_spawn_sc:
			out << "field_boss_spawn_sc"; 
			break;
		case mpe_rpc_cmd::guild_ranking_update_new_cs:
			out << "guild_ranking_update_new_cs"; 
			break;
		case mpe_rpc_cmd::guild_ranking_update_new_sc:
			out << "guild_ranking_update_new_sc"; 
			break;
		case mpe_rpc_cmd::community_character_levelup_cs:
			out << "community_character_levelup_cs"; 
			break;
		case mpe_rpc_cmd::community_character_levelup_sc:
			out << "community_character_levelup_sc"; 
			break;
		case mpe_rpc_cmd::ranking_buff_reset_cs:
			out << "ranking_buff_reset_cs"; 
			break;
		case mpe_rpc_cmd::ranking_buff_reset_sc:
			out << "ranking_buff_reset_sc"; 
			break;
		case mpe_rpc_cmd::ranking_data_update_cs:
			out << "ranking_data_update_cs"; 
			break;
		case mpe_rpc_cmd::ranking_data_update_sc:
			out << "ranking_data_update_sc"; 
			break;
		case mpe_rpc_cmd::guild_ranking_delete_cs:
			out << "guild_ranking_delete_cs"; 
			break;
		case mpe_rpc_cmd::guild_ranking_delete_sc:
			out << "guild_ranking_delete_sc"; 
			break;
		case mpe_rpc_cmd::guild_ranking_data_update_cs:
			out << "guild_ranking_data_update_cs"; 
			break;
		case mpe_rpc_cmd::guild_ranking_data_update_sc:
			out << "guild_ranking_data_update_sc"; 
			break;
		case mpe_rpc_cmd::community_character_level_info_cs:
			out << "community_character_level_info_cs"; 
			break;
		case mpe_rpc_cmd::community_character_level_info_sc:
			out << "community_character_level_info_sc"; 
			break;
		case mpe_rpc_cmd::shipwar_character_result_cs:
			out << "shipwar_character_result_cs"; 
			break;
		case mpe_rpc_cmd::shipwar_character_result_sc:
			out << "shipwar_character_result_sc"; 
			break;
		case mpe_rpc_cmd::mandala_node_reset_cs:
			out << "mandala_node_reset_cs"; 
			break;
		case mpe_rpc_cmd::mandala_node_reset_sc:
			out << "mandala_node_reset_sc"; 
			break;
		case mpe_rpc_cmd::street_stall_pr_cs:
			out << "street_stall_pr_cs"; 
			break;
		case mpe_rpc_cmd::street_stall_pr_sc:
			out << "street_stall_pr_sc"; 
			break;
		case mpe_rpc_cmd::mentor_teleport_check_cs:
			out << "mentor_teleport_check_cs"; 
			break;
		case mpe_rpc_cmd::mentor_teleport_check_sc:
			out << "mentor_teleport_check_sc"; 
			break;
		case mpe_rpc_cmd::npc_shop_open_cs:
			out << "npc_shop_open_cs"; 
			break;
		case mpe_rpc_cmd::npc_shop_open_sc:
			out << "npc_shop_open_sc"; 
			break;
		case mpe_rpc_cmd::guild_dungeon_enter_charge_cs:
			out << "guild_dungeon_enter_charge_cs"; 
			break;
		case mpe_rpc_cmd::guild_dungeon_enter_charge_sc:
			out << "guild_dungeon_enter_charge_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_dungeon_info_cs:
			out << "guild_alert_dungeon_info_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_dungeon_info_sc:
			out << "guild_alert_dungeon_info_sc"; 
			break;
		case mpe_rpc_cmd::cash_limit_product_noti_cs:
			out << "cash_limit_product_noti_cs"; 
			break;
		case mpe_rpc_cmd::cash_limit_product_noti_sc:
			out << "cash_limit_product_noti_sc"; 
			break;
		case mpe_rpc_cmd::cheatkey_stoneslotopen_probalility_cs:
			out << "cheatkey_stoneslotopen_probalility_cs"; 
			break;
		case mpe_rpc_cmd::cheatkey_stoneslotopen_probalility_sc:
			out << "cheatkey_stoneslotopen_probalility_sc"; 
			break;
		case mpe_rpc_cmd::cheatkey_stonecompose_probalility_cs:
			out << "cheatkey_stonecompose_probalility_cs"; 
			break;
		case mpe_rpc_cmd::cheatkey_stonecompose_probalility_sc:
			out << "cheatkey_stonecompose_probalility_sc"; 
			break;
		case mpe_rpc_cmd::contents_onoff_list_cs:
			out << "contents_onoff_list_cs"; 
			break;
		case mpe_rpc_cmd::contents_onoff_list_sc:
			out << "contents_onoff_list_sc"; 
			break;
		case mpe_rpc_cmd::item_restore_request_cs:
			out << "item_restore_request_cs"; 
			break;
		case mpe_rpc_cmd::item_restore_request_sc:
			out << "item_restore_request_sc"; 
			break;
		case mpe_rpc_cmd::debug_print_rpcinfo_cs:
			out << "debug_print_rpcinfo_cs"; 
			break;
		case mpe_rpc_cmd::debug_print_rpcinfo_sc:
			out << "debug_print_rpcinfo_sc"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_get_reward_cs:
			out << "guild_shipwar_get_reward_cs"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_get_reward_sc:
			out << "guild_shipwar_get_reward_sc"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_season_reward_cs:
			out << "guild_shipwar_season_reward_cs"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_season_reward_sc:
			out << "guild_shipwar_season_reward_sc"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_unearned_win_alarm_cs:
			out << "guild_shipwar_unearned_win_alarm_cs"; 
			break;
		case mpe_rpc_cmd::guild_shipwar_unearned_win_alarm_sc:
			out << "guild_shipwar_unearned_win_alarm_sc"; 
			break;
		case mpe_rpc_cmd::occupationwar_info_cs:
			out << "occupationwar_info_cs"; 
			break;
		case mpe_rpc_cmd::occupationwar_info_sc:
			out << "occupationwar_info_sc"; 
			break;
		case mpe_rpc_cmd::occupationwar_guild_info_cs:
			out << "occupationwar_guild_info_cs"; 
			break;
		case mpe_rpc_cmd::occupationwar_guild_info_sc:
			out << "occupationwar_guild_info_sc"; 
			break;
		case mpe_rpc_cmd::occupationwar_challenge_request_cs:
			out << "occupationwar_challenge_request_cs"; 
			break;
		case mpe_rpc_cmd::occupationwar_challenge_request_sc:
			out << "occupationwar_challenge_request_sc"; 
			break;
		case mpe_rpc_cmd::occupationwar_tender_total_info_cs:
			out << "occupationwar_tender_total_info_cs"; 
			break;
		case mpe_rpc_cmd::occupationwar_tender_total_info_sc:
			out << "occupationwar_tender_total_info_sc"; 
			break;
		case mpe_rpc_cmd::occupationwar_tender_deposit_cs:
			out << "occupationwar_tender_deposit_cs"; 
			break;
		case mpe_rpc_cmd::occupationwar_tender_deposit_sc:
			out << "occupationwar_tender_deposit_sc"; 
			break;
		case mpe_rpc_cmd::occupationwar_tender_withdraw_cs:
			out << "occupationwar_tender_withdraw_cs"; 
			break;
		case mpe_rpc_cmd::occupationwar_tender_withdraw_sc:
			out << "occupationwar_tender_withdraw_sc"; 
			break;
		case mpe_rpc_cmd::occupationwar_war_server_decide_cs:
			out << "occupationwar_war_server_decide_cs"; 
			break;
		case mpe_rpc_cmd::occupationwar_war_server_decide_sc:
			out << "occupationwar_war_server_decide_sc"; 
			break;
		case mpe_rpc_cmd::occupationwar_darksteel_pay_tax_cs:
			out << "occupationwar_darksteel_pay_tax_cs"; 
			break;
		case mpe_rpc_cmd::occupationwar_darksteel_pay_tax_sc:
			out << "occupationwar_darksteel_pay_tax_sc"; 
			break;
		case mpe_rpc_cmd::darksteel_storage_darksteel_pay_cs:
			out << "darksteel_storage_darksteel_pay_cs"; 
			break;
		case mpe_rpc_cmd::darksteel_storage_darksteel_pay_sc:
			out << "darksteel_storage_darksteel_pay_sc"; 
			break;
		case mpe_rpc_cmd::darksteel_storage_darksteel_sell_cs:
			out << "darksteel_storage_darksteel_sell_cs"; 
			break;
		case mpe_rpc_cmd::darksteel_storage_darksteel_sell_sc:
			out << "darksteel_storage_darksteel_sell_sc"; 
			break;
		case mpe_rpc_cmd::darksteel_storage_darksteel_withdraw_cs:
			out << "darksteel_storage_darksteel_withdraw_cs"; 
			break;
		case mpe_rpc_cmd::darksteel_storage_darksteel_withdraw_sc:
			out << "darksteel_storage_darksteel_withdraw_sc"; 
			break;
		case mpe_rpc_cmd::occupationwar_challenge_request_info_cs:
			out << "occupationwar_challenge_request_info_cs"; 
			break;
		case mpe_rpc_cmd::occupationwar_challenge_request_info_sc:
			out << "occupationwar_challenge_request_info_sc"; 
			break;
		case mpe_rpc_cmd::guild_search_custom_cs:
			out << "guild_search_custom_cs"; 
			break;
		case mpe_rpc_cmd::guild_search_custom_sc:
			out << "guild_search_custom_sc"; 
			break;
		case mpe_rpc_cmd::friend_target_delete_cs:
			out << "friend_target_delete_cs"; 
			break;
		case mpe_rpc_cmd::friend_target_delete_sc:
			out << "friend_target_delete_sc"; 
			break;
		case mpe_rpc_cmd::player_duplication_login_info_cs:
			out << "player_duplication_login_info_cs"; 
			break;
		case mpe_rpc_cmd::player_duplication_login_info_sc:
			out << "player_duplication_login_info_sc"; 
			break;
		case mpe_rpc_cmd::boss_governance_summon_boss_onoff_cs:
			out << "boss_governance_summon_boss_onoff_cs"; 
			break;
		case mpe_rpc_cmd::boss_governance_summon_boss_onoff_sc:
			out << "boss_governance_summon_boss_onoff_sc"; 
			break;
		case mpe_rpc_cmd::boss_governance_summon_boss_alarm_cs:
			out << "boss_governance_summon_boss_alarm_cs"; 
			break;
		case mpe_rpc_cmd::boss_governance_summon_boss_alarm_sc:
			out << "boss_governance_summon_boss_alarm_sc"; 
			break;
		case mpe_rpc_cmd::wallet_linked_account_cs:
			out << "wallet_linked_account_cs"; 
			break;
		case mpe_rpc_cmd::wallet_linked_account_sc:
			out << "wallet_linked_account_sc"; 
			break;
		case mpe_rpc_cmd::get_contract_address_cs:
			out << "get_contract_address_cs"; 
			break;
		case mpe_rpc_cmd::get_contract_address_sc:
			out << "get_contract_address_sc"; 
			break;
		case mpe_rpc_cmd::trade_darksteelbox_to_token_cs:
			out << "trade_darksteelbox_to_token_cs"; 
			break;
		case mpe_rpc_cmd::trade_darksteelbox_to_token_sc:
			out << "trade_darksteelbox_to_token_sc"; 
			break;
		case mpe_rpc_cmd::wallet_login_cs:
			out << "wallet_login_cs"; 
			break;
		case mpe_rpc_cmd::wallet_login_sc:
			out << "wallet_login_sc"; 
			break;
		case mpe_rpc_cmd::trade_token_to_darksteelbox_cs:
			out << "trade_token_to_darksteelbox_cs"; 
			break;
		case mpe_rpc_cmd::trade_token_to_darksteelbox_sc:
			out << "trade_token_to_darksteelbox_sc"; 
			break;
		case mpe_rpc_cmd::boss_governance_treasure_box_add_rate_cs:
			out << "boss_governance_treasure_box_add_rate_cs"; 
			break;
		case mpe_rpc_cmd::boss_governance_treasure_box_add_rate_sc:
			out << "boss_governance_treasure_box_add_rate_sc"; 
			break;
		case mpe_rpc_cmd::approve_make_transaction_cs:
			out << "approve_make_transaction_cs"; 
			break;
		case mpe_rpc_cmd::approve_make_transaction_sc:
			out << "approve_make_transaction_sc"; 
			break;
		case mpe_rpc_cmd::approve_send_transaction_cs:
			out << "approve_send_transaction_cs"; 
			break;
		case mpe_rpc_cmd::approve_send_transaction_sc:
			out << "approve_send_transaction_sc"; 
			break;
		case mpe_rpc_cmd::global_exchange_pre_register_cs:
			out << "global_exchange_pre_register_cs"; 
			break;
		case mpe_rpc_cmd::global_exchange_pre_register_sc:
			out << "global_exchange_pre_register_sc"; 
			break;
		case mpe_rpc_cmd::global_exchange_register_cs:
			out << "global_exchange_register_cs"; 
			break;
		case mpe_rpc_cmd::global_exchange_register_sc:
			out << "global_exchange_register_sc"; 
			break;
		case mpe_rpc_cmd::global_exchange_register_complete_cs:
			out << "global_exchange_register_complete_cs"; 
			break;
		case mpe_rpc_cmd::global_exchange_register_complete_sc:
			out << "global_exchange_register_complete_sc"; 
			break;
		case mpe_rpc_cmd::global_exchange_register_cancel_cs:
			out << "global_exchange_register_cancel_cs"; 
			break;
		case mpe_rpc_cmd::global_exchange_register_cancel_sc:
			out << "global_exchange_register_cancel_sc"; 
			break;
		case mpe_rpc_cmd::global_exchange_buy_cs:
			out << "global_exchange_buy_cs"; 
			break;
		case mpe_rpc_cmd::global_exchange_buy_sc:
			out << "global_exchange_buy_sc"; 
			break;
		case mpe_rpc_cmd::global_exchange_gold_withdraw_cs:
			out << "global_exchange_gold_withdraw_cs"; 
			break;
		case mpe_rpc_cmd::global_exchange_gold_withdraw_sc:
			out << "global_exchange_gold_withdraw_sc"; 
			break;
		case mpe_rpc_cmd::global_exchange_item_withdraw_cs:
			out << "global_exchange_item_withdraw_cs"; 
			break;
		case mpe_rpc_cmd::global_exchange_item_withdraw_sc:
			out << "global_exchange_item_withdraw_sc"; 
			break;
		case mpe_rpc_cmd::global_exchange_item_expire_noti_cs:
			out << "global_exchange_item_expire_noti_cs"; 
			break;
		case mpe_rpc_cmd::global_exchange_item_expire_noti_sc:
			out << "global_exchange_item_expire_noti_sc"; 
			break;
		case mpe_rpc_cmd::global_exchange_item_get_insert_cs:
			out << "global_exchange_item_get_insert_cs"; 
			break;
		case mpe_rpc_cmd::global_exchange_item_get_insert_sc:
			out << "global_exchange_item_get_insert_sc"; 
			break;
		case mpe_rpc_cmd::staking_make_tx_cs:
			out << "staking_make_tx_cs"; 
			break;
		case mpe_rpc_cmd::staking_make_tx_sc:
			out << "staking_make_tx_sc"; 
			break;
		case mpe_rpc_cmd::staking_send_tx_cs:
			out << "staking_send_tx_cs"; 
			break;
		case mpe_rpc_cmd::staking_send_tx_sc:
			out << "staking_send_tx_sc"; 
			break;
		case mpe_rpc_cmd::claim_make_tx_cs:
			out << "claim_make_tx_cs"; 
			break;
		case mpe_rpc_cmd::claim_make_tx_sc:
			out << "claim_make_tx_sc"; 
			break;
		case mpe_rpc_cmd::claim_send_tx_cs:
			out << "claim_send_tx_cs"; 
			break;
		case mpe_rpc_cmd::claim_send_tx_sc:
			out << "claim_send_tx_sc"; 
			break;
		case mpe_rpc_cmd::governance_staking_cs:
			out << "governance_staking_cs"; 
			break;
		case mpe_rpc_cmd::governance_staking_sc:
			out << "governance_staking_sc"; 
			break;
		case mpe_rpc_cmd::governance_unstaking_cs:
			out << "governance_unstaking_cs"; 
			break;
		case mpe_rpc_cmd::governance_unstaking_sc:
			out << "governance_unstaking_sc"; 
			break;
		case mpe_rpc_cmd::boss_governance_server_decide_process_cs:
			out << "boss_governance_server_decide_process_cs"; 
			break;
		case mpe_rpc_cmd::boss_governance_server_decide_process_sc:
			out << "boss_governance_server_decide_process_sc"; 
			break;
		case mpe_rpc_cmd::boss_governance_get_treasurebox_dbinfo_cs:
			out << "boss_governance_get_treasurebox_dbinfo_cs"; 
			break;
		case mpe_rpc_cmd::boss_governance_get_treasurebox_dbinfo_sc:
			out << "boss_governance_get_treasurebox_dbinfo_sc"; 
			break;
		case mpe_rpc_cmd::update_redis_server_info_cs:
			out << "update_redis_server_info_cs"; 
			break;
		case mpe_rpc_cmd::update_redis_server_info_sc:
			out << "update_redis_server_info_sc"; 
			break;
		case mpe_rpc_cmd::token_history_item_select_cs:
			out << "token_history_item_select_cs"; 
			break;
		case mpe_rpc_cmd::token_history_item_select_sc:
			out << "token_history_item_select_sc"; 
			break;
		case mpe_rpc_cmd::token_history_item_get_cs:
			out << "token_history_item_get_cs"; 
			break;
		case mpe_rpc_cmd::token_history_item_get_sc:
			out << "token_history_item_get_sc"; 
			break;
		case mpe_rpc_cmd::server_contract_agenda_info_cs:
			out << "server_contract_agenda_info_cs"; 
			break;
		case mpe_rpc_cmd::server_contract_agenda_info_sc:
			out << "server_contract_agenda_info_sc"; 
			break;
		case mpe_rpc_cmd::server_connected_info_cs:
			out << "server_connected_info_cs"; 
			break;
		case mpe_rpc_cmd::server_connected_info_sc:
			out << "server_connected_info_sc"; 
			break;
		case mpe_rpc_cmd::global_ccu_info_cs:
			out << "global_ccu_info_cs"; 
			break;
		case mpe_rpc_cmd::global_ccu_info_sc:
			out << "global_ccu_info_sc"; 
			break;
		case mpe_rpc_cmd::websocket_global_ccu_info_cs:
			out << "websocket_global_ccu_info_cs"; 
			break;
		case mpe_rpc_cmd::websocket_global_ccu_info_sc:
			out << "websocket_global_ccu_info_sc"; 
			break;
		case mpe_rpc_cmd::update_debug_print_rpcinfo_cs:
			out << "update_debug_print_rpcinfo_cs"; 
			break;
		case mpe_rpc_cmd::update_debug_print_rpcinfo_sc:
			out << "update_debug_print_rpcinfo_sc"; 
			break;
		case mpe_rpc_cmd::game_duplicate_login_cs:
			out << "game_duplicate_login_cs"; 
			break;
		case mpe_rpc_cmd::game_duplicate_login_sc:
			out << "game_duplicate_login_sc"; 
			break;
		case mpe_rpc_cmd::party_governance_staking_cs:
			out << "party_governance_staking_cs"; 
			break;
		case mpe_rpc_cmd::party_governance_staking_sc:
			out << "party_governance_staking_sc"; 
			break;
		case mpe_rpc_cmd::global_party_governance_staking_cs:
			out << "global_party_governance_staking_cs"; 
			break;
		case mpe_rpc_cmd::global_party_governance_staking_sc:
			out << "global_party_governance_staking_sc"; 
			break;
		case mpe_rpc_cmd::global_party_governance_unstaking_cs:
			out << "global_party_governance_unstaking_cs"; 
			break;
		case mpe_rpc_cmd::global_party_governance_unstaking_sc:
			out << "global_party_governance_unstaking_sc"; 
			break;
		case mpe_rpc_cmd::global_party_governance_decide_info_cs:
			out << "global_party_governance_decide_info_cs"; 
			break;
		case mpe_rpc_cmd::global_party_governance_decide_info_sc:
			out << "global_party_governance_decide_info_sc"; 
			break;
		case mpe_rpc_cmd::global_party_governance_rank_cs:
			out << "global_party_governance_rank_cs"; 
			break;
		case mpe_rpc_cmd::global_party_governance_rank_sc:
			out << "global_party_governance_rank_sc"; 
			break;
		case mpe_rpc_cmd::global_party_governance_update_guidname_cs:
			out << "global_party_governance_update_guidname_cs"; 
			break;
		case mpe_rpc_cmd::global_party_governance_update_guidname_sc:
			out << "global_party_governance_update_guidname_sc"; 
			break;
		case mpe_rpc_cmd::global_occupationwar_war_server_decide_cs:
			out << "global_occupationwar_war_server_decide_cs"; 
			break;
		case mpe_rpc_cmd::global_occupationwar_war_server_decide_sc:
			out << "global_occupationwar_war_server_decide_sc"; 
			break;
		case mpe_rpc_cmd::global_occupationwar_war_schedule_noti_cs:
			out << "global_occupationwar_war_schedule_noti_cs"; 
			break;
		case mpe_rpc_cmd::global_occupationwar_war_schedule_noti_sc:
			out << "global_occupationwar_war_schedule_noti_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_member_contribution_update_cs:
			out << "guild_alert_member_contribution_update_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_member_contribution_update_sc:
			out << "guild_alert_member_contribution_update_sc"; 
			break;
		case mpe_rpc_cmd::occupationwar_owner_guild_remove_cs:
			out << "occupationwar_owner_guild_remove_cs"; 
			break;
		case mpe_rpc_cmd::occupationwar_owner_guild_remove_sc:
			out << "occupationwar_owner_guild_remove_sc"; 
			break;
		case mpe_rpc_cmd::occupationwar_gameserver_log_cs:
			out << "occupationwar_gameserver_log_cs"; 
			break;
		case mpe_rpc_cmd::occupationwar_gameserver_log_sc:
			out << "occupationwar_gameserver_log_sc"; 
			break;
		case mpe_rpc_cmd::global_party_governance_account_staking_cs:
			out << "global_party_governance_account_staking_cs"; 
			break;
		case mpe_rpc_cmd::global_party_governance_account_staking_sc:
			out << "global_party_governance_account_staking_sc"; 
			break;
		case mpe_rpc_cmd::global_party_governance_token_history_cs:
			out << "global_party_governance_token_history_cs"; 
			break;
		case mpe_rpc_cmd::global_party_governance_token_history_sc:
			out << "global_party_governance_token_history_sc"; 
			break;
		case mpe_rpc_cmd::check_send_nickname_disable_cs:
			out << "check_send_nickname_disable_cs"; 
			break;
		case mpe_rpc_cmd::check_send_nickname_disable_sc:
			out << "check_send_nickname_disable_sc"; 
			break;
		case mpe_rpc_cmd::indun_party_finish_notify_cs:
			out << "indun_party_finish_notify_cs"; 
			break;
		case mpe_rpc_cmd::indun_party_finish_notify_sc:
			out << "indun_party_finish_notify_sc"; 
			break;
		case mpe_rpc_cmd::item_use_change_nickname_cs:
			out << "item_use_change_nickname_cs"; 
			break;
		case mpe_rpc_cmd::item_use_change_nickname_sc:
			out << "item_use_change_nickname_sc"; 
			break;
		case mpe_rpc_cmd::check_nickname_cs:
			out << "check_nickname_cs"; 
			break;
		case mpe_rpc_cmd::check_nickname_sc:
			out << "check_nickname_sc"; 
			break;
		case mpe_rpc_cmd::get_all_balance_swap_token_cs:
			out << "get_all_balance_swap_token_cs"; 
			break;
		case mpe_rpc_cmd::get_all_balance_swap_token_sc:
			out << "get_all_balance_swap_token_sc"; 
			break;
		case mpe_rpc_cmd::advertisement_reward_cs:
			out << "advertisement_reward_cs"; 
			break;
		case mpe_rpc_cmd::advertisement_reward_sc:
			out << "advertisement_reward_sc"; 
			break;
		case mpe_rpc_cmd::guild_alert_change_nickname_cs:
			out << "guild_alert_change_nickname_cs"; 
			break;
		case mpe_rpc_cmd::guild_alert_change_nickname_sc:
			out << "guild_alert_change_nickname_sc"; 
			break;
		case mpe_rpc_cmd::guild_change_nickname_cs:
			out << "guild_change_nickname_cs"; 
			break;
		case mpe_rpc_cmd::guild_change_nickname_sc:
			out << "guild_change_nickname_sc"; 
			break;
		case mpe_rpc_cmd::change_character_zone_info_cs:
			out << "change_character_zone_info_cs"; 
			break;
		case mpe_rpc_cmd::change_character_zone_info_sc:
			out << "change_character_zone_info_sc"; 
			break;
		case mpe_rpc_cmd::party_leave_by_invite_accept_cs:
			out << "party_leave_by_invite_accept_cs"; 
			break;
		case mpe_rpc_cmd::party_leave_by_invite_accept_sc:
			out << "party_leave_by_invite_accept_sc"; 
			break;
		case mpe_rpc_cmd::server_relocation_lock_cs:
			out << "server_relocation_lock_cs"; 
			break;
		case mpe_rpc_cmd::server_relocation_lock_sc:
			out << "server_relocation_lock_sc"; 
			break;
		case mpe_rpc_cmd::server_relocation_lock_slobby_to_global_cs:
			out << "server_relocation_lock_slobby_to_global_cs"; 
			break;
		case mpe_rpc_cmd::server_relocation_lock_slobby_to_global_sc:
			out << "server_relocation_lock_slobby_to_global_sc"; 
			break;
		case mpe_rpc_cmd::server_relocation_lock_global_to_tlobby_cs:
			out << "server_relocation_lock_global_to_tlobby_cs"; 
			break;
		case mpe_rpc_cmd::server_relocation_lock_global_to_tlobby_sc:
			out << "server_relocation_lock_global_to_tlobby_sc"; 
			break;
		case mpe_rpc_cmd::server_relocation_slobby_to_global_cs:
			out << "server_relocation_slobby_to_global_cs"; 
			break;
		case mpe_rpc_cmd::server_relocation_slobby_to_global_sc:
			out << "server_relocation_slobby_to_global_sc"; 
			break;
		case mpe_rpc_cmd::server_relocation_global_to_tlobby_cs:
			out << "server_relocation_global_to_tlobby_cs"; 
			break;
		case mpe_rpc_cmd::server_relocation_global_to_tlobby_sc:
			out << "server_relocation_global_to_tlobby_sc"; 
			break;
		case mpe_rpc_cmd::server_relocation_unlock_slobby_to_global_cs:
			out << "server_relocation_unlock_slobby_to_global_cs"; 
			break;
		case mpe_rpc_cmd::server_relocation_unlock_slobby_to_global_sc:
			out << "server_relocation_unlock_slobby_to_global_sc"; 
			break;
		case mpe_rpc_cmd::server_relocation_unlock_global_to_tlobby_cs:
			out << "server_relocation_unlock_global_to_tlobby_cs"; 
			break;
		case mpe_rpc_cmd::server_relocation_unlock_global_to_tlobby_sc:
			out << "server_relocation_unlock_global_to_tlobby_sc"; 
			break;
		case mpe_rpc_cmd::server_relocation_process_global_log_cs:
			out << "server_relocation_process_global_log_cs"; 
			break;
		case mpe_rpc_cmd::server_relocation_process_global_log_sc:
			out << "server_relocation_process_global_log_sc"; 
			break;
		case mpe_rpc_cmd::server_relocation_exception_process_cs:
			out << "server_relocation_exception_process_cs"; 
			break;
		case mpe_rpc_cmd::server_relocation_exception_process_sc:
			out << "server_relocation_exception_process_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_character_subscription_update_cs:
			out << "gm_api_character_subscription_update_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_character_subscription_update_sc:
			out << "gm_api_character_subscription_update_sc"; 
			break;
		case mpe_rpc_cmd::community_character_game_login_cs:
			out << "community_character_game_login_cs"; 
			break;
		case mpe_rpc_cmd::community_character_game_login_sc:
			out << "community_character_game_login_sc"; 
			break;
		case mpe_rpc_cmd::community_game_logoff_cs:
			out << "community_game_logoff_cs"; 
			break;
		case mpe_rpc_cmd::community_game_logoff_sc:
			out << "community_game_logoff_sc"; 
			break;
		case mpe_rpc_cmd::dimension_dungeon_contribution_cs:
			out << "dimension_dungeon_contribution_cs"; 
			break;
		case mpe_rpc_cmd::dimension_dungeon_contribution_sc:
			out << "dimension_dungeon_contribution_sc"; 
			break;
		case mpe_rpc_cmd::dimension_dungeon_contribution_item_history_cs:
			out << "dimension_dungeon_contribution_item_history_cs"; 
			break;
		case mpe_rpc_cmd::dimension_dungeon_contribution_item_history_sc:
			out << "dimension_dungeon_contribution_item_history_sc"; 
			break;
		case mpe_rpc_cmd::dimension_dungeon_state_cs:
			out << "dimension_dungeon_state_cs"; 
			break;
		case mpe_rpc_cmd::dimension_dungeon_state_sc:
			out << "dimension_dungeon_state_sc"; 
			break;
		case mpe_rpc_cmd::dimension_dungeon_contribution_daily_reset_cs:
			out << "dimension_dungeon_contribution_daily_reset_cs"; 
			break;
		case mpe_rpc_cmd::dimension_dungeon_contribution_daily_reset_sc:
			out << "dimension_dungeon_contribution_daily_reset_sc"; 
			break;
		case mpe_rpc_cmd::dimension_dungeon_enter_check_cs:
			out << "dimension_dungeon_enter_check_cs"; 
			break;
		case mpe_rpc_cmd::dimension_dungeon_enter_check_sc:
			out << "dimension_dungeon_enter_check_sc"; 
			break;
		case mpe_rpc_cmd::party_member_enter_status_cs:
			out << "party_member_enter_status_cs"; 
			break;
		case mpe_rpc_cmd::party_member_enter_status_sc:
			out << "party_member_enter_status_sc"; 
			break;
		case mpe_rpc_cmd::party_member_enter_status_relay_cs:
			out << "party_member_enter_status_relay_cs"; 
			break;
		case mpe_rpc_cmd::party_member_enter_status_relay_sc:
			out << "party_member_enter_status_relay_sc"; 
			break;
		case mpe_rpc_cmd::dimension_dungeon_contribution_buff_cs:
			out << "dimension_dungeon_contribution_buff_cs"; 
			break;
		case mpe_rpc_cmd::dimension_dungeon_contribution_buff_sc:
			out << "dimension_dungeon_contribution_buff_sc"; 
			break;
		case mpe_rpc_cmd::api_server_relocation_rollback_cs:
			out << "api_server_relocation_rollback_cs"; 
			break;
		case mpe_rpc_cmd::api_server_relocation_rollback_sc:
			out << "api_server_relocation_rollback_sc"; 
			break;
		case mpe_rpc_cmd::change_party_governance_gid_cs:
			out << "change_party_governance_gid_cs"; 
			break;
		case mpe_rpc_cmd::change_party_governance_gid_sc:
			out << "change_party_governance_gid_sc"; 
			break;
		case mpe_rpc_cmd::temp_pet_change_cs:
			out << "temp_pet_change_cs"; 
			break;
		case mpe_rpc_cmd::temp_pet_change_sc:
			out << "temp_pet_change_sc"; 
			break;
		case mpe_rpc_cmd::temp_pet_confirm_cs:
			out << "temp_pet_confirm_cs"; 
			break;
		case mpe_rpc_cmd::temp_pet_confirm_sc:
			out << "temp_pet_confirm_sc"; 
			break;
		case mpe_rpc_cmd::temp_pet_get_cs:
			out << "temp_pet_get_cs"; 
			break;
		case mpe_rpc_cmd::temp_pet_get_sc:
			out << "temp_pet_get_sc"; 
			break;
		case mpe_rpc_cmd::advertisement_exp_restore_cs:
			out << "advertisement_exp_restore_cs"; 
			break;
		case mpe_rpc_cmd::advertisement_exp_restore_sc:
			out << "advertisement_exp_restore_sc"; 
			break;
		case mpe_rpc_cmd::recovery_exp_ad_cs:
			out << "recovery_exp_ad_cs"; 
			break;
		case mpe_rpc_cmd::recovery_exp_ad_sc:
			out << "recovery_exp_ad_sc"; 
			break;
		case mpe_rpc_cmd::reward_ad_cs:
			out << "reward_ad_cs"; 
			break;
		case mpe_rpc_cmd::reward_ad_sc:
			out << "reward_ad_sc"; 
			break;
		case mpe_rpc_cmd::advertisement_event_reward_cs:
			out << "advertisement_event_reward_cs"; 
			break;
		case mpe_rpc_cmd::advertisement_event_reward_sc:
			out << "advertisement_event_reward_sc"; 
			break;
		case mpe_rpc_cmd::blood_dedicate_worldboss_summon_cs:
			out << "blood_dedicate_worldboss_summon_cs"; 
			break;
		case mpe_rpc_cmd::blood_dedicate_worldboss_summon_sc:
			out << "blood_dedicate_worldboss_summon_sc"; 
			break;
		case mpe_rpc_cmd::blood_dedicate_reward_change_cs:
			out << "blood_dedicate_reward_change_cs"; 
			break;
		case mpe_rpc_cmd::blood_dedicate_reward_change_sc:
			out << "blood_dedicate_reward_change_sc"; 
			break;
		case mpe_rpc_cmd::blood_dedicate_status_cs:
			out << "blood_dedicate_status_cs"; 
			break;
		case mpe_rpc_cmd::blood_dedicate_status_sc:
			out << "blood_dedicate_status_sc"; 
			break;
		case mpe_rpc_cmd::blood_dedicate_worldboss_init_cs:
			out << "blood_dedicate_worldboss_init_cs"; 
			break;
		case mpe_rpc_cmd::blood_dedicate_worldboss_init_sc:
			out << "blood_dedicate_worldboss_init_sc"; 
			break;
		case mpe_rpc_cmd::save_ranking_score_cs:
			out << "save_ranking_score_cs"; 
			break;
		case mpe_rpc_cmd::save_ranking_score_sc:
			out << "save_ranking_score_sc"; 
			break;
		case mpe_rpc_cmd::blood_dedicate_worldboss_summon_state_cs:
			out << "blood_dedicate_worldboss_summon_state_cs"; 
			break;
		case mpe_rpc_cmd::blood_dedicate_worldboss_summon_state_sc:
			out << "blood_dedicate_worldboss_summon_state_sc"; 
			break;
		case mpe_rpc_cmd::blood_dedicate_worldboss_notify_cs:
			out << "blood_dedicate_worldboss_notify_cs"; 
			break;
		case mpe_rpc_cmd::blood_dedicate_worldboss_notify_sc:
			out << "blood_dedicate_worldboss_notify_sc"; 
			break;
		case mpe_rpc_cmd::refresh_character_ranking_info_cs:
			out << "refresh_character_ranking_info_cs"; 
			break;
		case mpe_rpc_cmd::refresh_character_ranking_info_sc:
			out << "refresh_character_ranking_info_sc"; 
			break;
		case mpe_rpc_cmd::reinitialize_ranking_info_cs:
			out << "reinitialize_ranking_info_cs"; 
			break;
		case mpe_rpc_cmd::reinitialize_ranking_info_sc:
			out << "reinitialize_ranking_info_sc"; 
			break;
		case mpe_rpc_cmd::check_ranking_season_reward_cs:
			out << "check_ranking_season_reward_cs"; 
			break;
		case mpe_rpc_cmd::check_ranking_season_reward_sc:
			out << "check_ranking_season_reward_sc"; 
			break;
		case mpe_rpc_cmd::gm_server_relocation_set_user_cnt_cs:
			out << "gm_server_relocation_set_user_cnt_cs"; 
			break;
		case mpe_rpc_cmd::gm_server_relocation_set_user_cnt_sc:
			out << "gm_server_relocation_set_user_cnt_sc"; 
			break;
		case mpe_rpc_cmd::server_relocation_current_user_cnt_update_cs:
			out << "server_relocation_current_user_cnt_update_cs"; 
			break;
		case mpe_rpc_cmd::server_relocation_current_user_cnt_update_sc:
			out << "server_relocation_current_user_cnt_update_sc"; 
			break;
		case mpe_rpc_cmd::expert_equipment_get_info_cs:
			out << "expert_equipment_get_info_cs"; 
			break;
		case mpe_rpc_cmd::expert_equipment_get_info_sc:
			out << "expert_equipment_get_info_sc"; 
			break;
		case mpe_rpc_cmd::expert_equipment_enchant_stone_equip_cs:
			out << "expert_equipment_enchant_stone_equip_cs"; 
			break;
		case mpe_rpc_cmd::expert_equipment_enchant_stone_equip_sc:
			out << "expert_equipment_enchant_stone_equip_sc"; 
			break;
		case mpe_rpc_cmd::expert_equipment_equip_cs:
			out << "expert_equipment_equip_cs"; 
			break;
		case mpe_rpc_cmd::expert_equipment_equip_sc:
			out << "expert_equipment_equip_sc"; 
			break;
		case mpe_rpc_cmd::expert_equipment_reinforce_cs:
			out << "expert_equipment_reinforce_cs"; 
			break;
		case mpe_rpc_cmd::expert_equipment_reinforce_sc:
			out << "expert_equipment_reinforce_sc"; 
			break;
		case mpe_rpc_cmd::expert_equipment_create_cs:
			out << "expert_equipment_create_cs"; 
			break;
		case mpe_rpc_cmd::expert_equipment_create_sc:
			out << "expert_equipment_create_sc"; 
			break;
		case mpe_rpc_cmd::server_relocate_profesion_ranking_update_cs:
			out << "server_relocate_profesion_ranking_update_cs"; 
			break;
		case mpe_rpc_cmd::server_relocate_profesion_ranking_update_sc:
			out << "server_relocate_profesion_ranking_update_sc"; 
			break;
		case mpe_rpc_cmd::expert_run_cs:
			out << "expert_run_cs"; 
			break;
		case mpe_rpc_cmd::expert_run_sc:
			out << "expert_run_sc"; 
			break;
		case mpe_rpc_cmd::server_relocate_mentor_remove_cs:
			out << "server_relocate_mentor_remove_cs"; 
			break;
		case mpe_rpc_cmd::server_relocate_mentor_remove_sc:
			out << "server_relocate_mentor_remove_sc"; 
			break;
		case mpe_rpc_cmd::gm_server_relocation_init_user_cnt_cs:
			out << "gm_server_relocation_init_user_cnt_cs"; 
			break;
		case mpe_rpc_cmd::gm_server_relocation_init_user_cnt_sc:
			out << "gm_server_relocation_init_user_cnt_sc"; 
			break;
		case mpe_rpc_cmd::server_relocation_recovery_item_cs:
			out << "server_relocation_recovery_item_cs"; 
			break;
		case mpe_rpc_cmd::server_relocation_recovery_item_sc:
			out << "server_relocation_recovery_item_sc"; 
			break;
		case mpe_rpc_cmd::server_relocation_data_remove_cs:
			out << "server_relocation_data_remove_cs"; 
			break;
		case mpe_rpc_cmd::server_relocation_data_remove_sc:
			out << "server_relocation_data_remove_sc"; 
			break;
		case mpe_rpc_cmd::expert_equipment_enchant_stone_upgrade_cs:
			out << "expert_equipment_enchant_stone_upgrade_cs"; 
			break;
		case mpe_rpc_cmd::expert_equipment_enchant_stone_upgrade_sc:
			out << "expert_equipment_enchant_stone_upgrade_sc"; 
			break;
		case mpe_rpc_cmd::boss_dungeon_clear_cs:
			out << "boss_dungeon_clear_cs"; 
			break;
		case mpe_rpc_cmd::boss_dungeon_clear_sc:
			out << "boss_dungeon_clear_sc"; 
			break;
		case mpe_rpc_cmd::expert_equipment_reinforce_cheat_cs:
			out << "expert_equipment_reinforce_cheat_cs"; 
			break;
		case mpe_rpc_cmd::expert_equipment_reinforce_cheat_sc:
			out << "expert_equipment_reinforce_cheat_sc"; 
			break;
		case mpe_rpc_cmd::gm_guild_war_delete_cs:
			out << "gm_guild_war_delete_cs"; 
			break;
		case mpe_rpc_cmd::gm_guild_war_delete_sc:
			out << "gm_guild_war_delete_sc"; 
			break;
		case mpe_rpc_cmd::guild_member_pvp_update_notify_cs:
			out << "guild_member_pvp_update_notify_cs"; 
			break;
		case mpe_rpc_cmd::guild_member_pvp_update_notify_sc:
			out << "guild_member_pvp_update_notify_sc"; 
			break;
		case mpe_rpc_cmd::equipment_awaken_cs:
			out << "equipment_awaken_cs"; 
			break;
		case mpe_rpc_cmd::equipment_awaken_sc:
			out << "equipment_awaken_sc"; 
			break;
		case mpe_rpc_cmd::equipment_awaken_option_confirmed_cs:
			out << "equipment_awaken_option_confirmed_cs"; 
			break;
		case mpe_rpc_cmd::equipment_awaken_option_confirmed_sc:
			out << "equipment_awaken_option_confirmed_sc"; 
			break;
		case mpe_rpc_cmd::guild_member_pvp_info_cs:
			out << "guild_member_pvp_info_cs"; 
			break;
		case mpe_rpc_cmd::guild_member_pvp_info_sc:
			out << "guild_member_pvp_info_sc"; 
			break;
		case mpe_rpc_cmd::guild_ally_request_accept_cs:
			out << "guild_ally_request_accept_cs"; 
			break;
		case mpe_rpc_cmd::guild_ally_request_accept_sc:
			out << "guild_ally_request_accept_sc"; 
			break;
		case mpe_rpc_cmd::boss_dungeon_ranking_refresh_cs:
			out << "boss_dungeon_ranking_refresh_cs"; 
			break;
		case mpe_rpc_cmd::boss_dungeon_ranking_refresh_sc:
			out << "boss_dungeon_ranking_refresh_sc"; 
			break;
		case mpe_rpc_cmd::guild_ally_request_deny_cs:
			out << "guild_ally_request_deny_cs"; 
			break;
		case mpe_rpc_cmd::guild_ally_request_deny_sc:
			out << "guild_ally_request_deny_sc"; 
			break;
		case mpe_rpc_cmd::guild_ally_request_regist_cs:
			out << "guild_ally_request_regist_cs"; 
			break;
		case mpe_rpc_cmd::guild_ally_request_regist_sc:
			out << "guild_ally_request_regist_sc"; 
			break;
		case mpe_rpc_cmd::guild_ally_list_cs:
			out << "guild_ally_list_cs"; 
			break;
		case mpe_rpc_cmd::guild_ally_list_sc:
			out << "guild_ally_list_sc"; 
			break;
		case mpe_rpc_cmd::guild_ally_request_list_cs:
			out << "guild_ally_request_list_cs"; 
			break;
		case mpe_rpc_cmd::guild_ally_request_list_sc:
			out << "guild_ally_request_list_sc"; 
			break;
		case mpe_rpc_cmd::guild_search_by_guid_cs:
			out << "guild_search_by_guid_cs"; 
			break;
		case mpe_rpc_cmd::guild_search_by_guid_sc:
			out << "guild_search_by_guid_sc"; 
			break;
		case mpe_rpc_cmd::guild_ally_cancel_cs:
			out << "guild_ally_cancel_cs"; 
			break;
		case mpe_rpc_cmd::guild_ally_cancel_sc:
			out << "guild_ally_cancel_sc"; 
			break;
		case mpe_rpc_cmd::guild_ally_alert_cs:
			out << "guild_ally_alert_cs"; 
			break;
		case mpe_rpc_cmd::guild_ally_alert_sc:
			out << "guild_ally_alert_sc"; 
			break;
		case mpe_rpc_cmd::guild_ally_detail_info_cs:
			out << "guild_ally_detail_info_cs"; 
			break;
		case mpe_rpc_cmd::guild_ally_detail_info_sc:
			out << "guild_ally_detail_info_sc"; 
			break;
		case mpe_rpc_cmd::restore_item_list_cs:
			out << "restore_item_list_cs"; 
			break;
		case mpe_rpc_cmd::restore_item_list_sc:
			out << "restore_item_list_sc"; 
			break;
		case mpe_rpc_cmd::restore_compose_list_cs:
			out << "restore_compose_list_cs"; 
			break;
		case mpe_rpc_cmd::restore_compose_list_sc:
			out << "restore_compose_list_sc"; 
			break;
		case mpe_rpc_cmd::restore_item_cs:
			out << "restore_item_cs"; 
			break;
		case mpe_rpc_cmd::restore_item_sc:
			out << "restore_item_sc"; 
			break;
		case mpe_rpc_cmd::restore_compose_cs:
			out << "restore_compose_cs"; 
			break;
		case mpe_rpc_cmd::restore_compose_sc:
			out << "restore_compose_sc"; 
			break;
		case mpe_rpc_cmd::restore_event_noti_cs:
			out << "restore_event_noti_cs"; 
			break;
		case mpe_rpc_cmd::restore_event_noti_sc:
			out << "restore_event_noti_sc"; 
			break;
		case mpe_rpc_cmd::season_mandala_info_get_cs:
			out << "season_mandala_info_get_cs"; 
			break;
		case mpe_rpc_cmd::season_mandala_info_get_sc:
			out << "season_mandala_info_get_sc"; 
			break;
		case mpe_rpc_cmd::season_mandala_info_update_cs:
			out << "season_mandala_info_update_cs"; 
			break;
		case mpe_rpc_cmd::season_mandala_info_update_sc:
			out << "season_mandala_info_update_sc"; 
			break;
		case mpe_rpc_cmd::season_mandala_reward_update_cs:
			out << "season_mandala_reward_update_cs"; 
			break;
		case mpe_rpc_cmd::season_mandala_reward_update_sc:
			out << "season_mandala_reward_update_sc"; 
			break;
		case mpe_rpc_cmd::season_mandala_reward_delete_all_cs:
			out << "season_mandala_reward_delete_all_cs"; 
			break;
		case mpe_rpc_cmd::season_mandala_reward_delete_all_sc:
			out << "season_mandala_reward_delete_all_sc"; 
			break;
		case mpe_rpc_cmd::guild_member_location_cs:
			out << "guild_member_location_cs"; 
			break;
		case mpe_rpc_cmd::guild_member_location_sc:
			out << "guild_member_location_sc"; 
			break;
		case mpe_rpc_cmd::guild_member_pk_death_alert_cs:
			out << "guild_member_pk_death_alert_cs"; 
			break;
		case mpe_rpc_cmd::guild_member_pk_death_alert_sc:
			out << "guild_member_pk_death_alert_sc"; 
			break;
		case mpe_rpc_cmd::world_ranking_refresh_cs:
			out << "world_ranking_refresh_cs"; 
			break;
		case mpe_rpc_cmd::world_ranking_refresh_sc:
			out << "world_ranking_refresh_sc"; 
			break;
		case mpe_rpc_cmd::season_mandala_reward_delete_cs:
			out << "season_mandala_reward_delete_cs"; 
			break;
		case mpe_rpc_cmd::season_mandala_reward_delete_sc:
			out << "season_mandala_reward_delete_sc"; 
			break;
		case mpe_rpc_cmd::party_leave_alert_by_indun_kick_cs:
			out << "party_leave_alert_by_indun_kick_cs"; 
			break;
		case mpe_rpc_cmd::party_leave_alert_by_indun_kick_sc:
			out << "party_leave_alert_by_indun_kick_sc"; 
			break;
		case mpe_rpc_cmd::season_mandala_reward_item_update_cs:
			out << "season_mandala_reward_item_update_cs"; 
			break;
		case mpe_rpc_cmd::season_mandala_reward_item_update_sc:
			out << "season_mandala_reward_item_update_sc"; 
			break;
		case mpe_rpc_cmd::gate_castle_dungeon_info_cs:
			out << "gate_castle_dungeon_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_castle_dungeon_info_sc:
			out << "gate_castle_dungeon_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_castle_view_owner_info_cs:
			out << "gate_castle_view_owner_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_castle_view_owner_info_sc:
			out << "gate_castle_view_owner_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_castle_tax_with_member_info_cs:
			out << "gate_castle_tax_with_member_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_castle_tax_with_member_info_sc:
			out << "gate_castle_tax_with_member_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_castle_town_info_by_guild_guid_cs:
			out << "gate_castle_town_info_by_guild_guid_cs"; 
			break;
		case mpe_rpc_cmd::gate_castle_town_info_by_guild_guid_sc:
			out << "gate_castle_town_info_by_guild_guid_sc"; 
			break;
		case mpe_rpc_cmd::gate_castle_town_managing_info_cs:
			out << "gate_castle_town_managing_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_castle_town_managing_info_sc:
			out << "gate_castle_town_managing_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_castle_town_single_managing_info_cs:
			out << "gate_castle_town_single_managing_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_castle_town_single_managing_info_sc:
			out << "gate_castle_town_single_managing_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_castle_town_save_bag_info_cs:
			out << "gate_castle_town_save_bag_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_castle_town_save_bag_info_sc:
			out << "gate_castle_town_save_bag_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_castle_town_log_cs:
			out << "gate_castle_town_log_cs"; 
			break;
		case mpe_rpc_cmd::gate_castle_town_log_sc:
			out << "gate_castle_town_log_sc"; 
			break;
		case mpe_rpc_cmd::gate_character_info_view_cs:
			out << "gate_character_info_view_cs"; 
			break;
		case mpe_rpc_cmd::gate_character_info_view_sc:
			out << "gate_character_info_view_sc"; 
			break;
		case mpe_rpc_cmd::gate_token_history_info_get_cs:
			out << "gate_token_history_info_get_cs"; 
			break;
		case mpe_rpc_cmd::gate_token_history_info_get_sc:
			out << "gate_token_history_info_get_sc"; 
			break;
		case mpe_rpc_cmd::gate_community_server_getinfo_cs:
			out << "gate_community_server_getinfo_cs"; 
			break;
		case mpe_rpc_cmd::gate_community_server_getinfo_sc:
			out << "gate_community_server_getinfo_sc"; 
			break;
		case mpe_rpc_cmd::gate_contract_get_nonce_cs:
			out << "gate_contract_get_nonce_cs"; 
			break;
		case mpe_rpc_cmd::gate_contract_get_nonce_sc:
			out << "gate_contract_get_nonce_sc"; 
			break;
		case mpe_rpc_cmd::gate_contract_get_address_cs:
			out << "gate_contract_get_address_cs"; 
			break;
		case mpe_rpc_cmd::gate_contract_get_address_sc:
			out << "gate_contract_get_address_sc"; 
			break;
		case mpe_rpc_cmd::gate_contract_get_balance_cs:
			out << "gate_contract_get_balance_cs"; 
			break;
		case mpe_rpc_cmd::gate_contract_get_balance_sc:
			out << "gate_contract_get_balance_sc"; 
			break;
		case mpe_rpc_cmd::gate_contract_token_allowance_cs:
			out << "gate_contract_token_allowance_cs"; 
			break;
		case mpe_rpc_cmd::gate_contract_token_allowance_sc:
			out << "gate_contract_token_allowance_sc"; 
			break;
		case mpe_rpc_cmd::gate_contract_get_limit_cs:
			out << "gate_contract_get_limit_cs"; 
			break;
		case mpe_rpc_cmd::gate_contract_get_limit_sc:
			out << "gate_contract_get_limit_sc"; 
			break;
		case mpe_rpc_cmd::gate_contract_get_staking_info_cs:
			out << "gate_contract_get_staking_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_contract_get_staking_info_sc:
			out << "gate_contract_get_staking_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_contract_get_balance_to_wdoller_cs:
			out << "gate_contract_get_balance_to_wdoller_cs"; 
			break;
		case mpe_rpc_cmd::gate_contract_get_balance_to_wdoller_sc:
			out << "gate_contract_get_balance_to_wdoller_sc"; 
			break;
		case mpe_rpc_cmd::gate_world_boss_statking_player_info_cs:
			out << "gate_world_boss_statking_player_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_world_boss_statking_player_info_sc:
			out << "gate_world_boss_statking_player_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_coupon_use_cs:
			out << "gate_coupon_use_cs"; 
			break;
		case mpe_rpc_cmd::gate_coupon_use_sc:
			out << "gate_coupon_use_sc"; 
			break;
		case mpe_rpc_cmd::gate_friend_list_cs:
			out << "gate_friend_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_friend_list_sc:
			out << "gate_friend_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_mentor_position_cs:
			out << "gate_mentor_position_cs"; 
			break;
		case mpe_rpc_cmd::gate_mentor_position_sc:
			out << "gate_mentor_position_sc"; 
			break;
		case mpe_rpc_cmd::gate_friend_request_count_cs:
			out << "gate_friend_request_count_cs"; 
			break;
		case mpe_rpc_cmd::gate_friend_request_count_sc:
			out << "gate_friend_request_count_sc"; 
			break;
		case mpe_rpc_cmd::gate_friend_requested_list_cs:
			out << "gate_friend_requested_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_friend_requested_list_sc:
			out << "gate_friend_requested_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_game_option_save_cs:
			out << "gate_game_option_save_cs"; 
			break;
		case mpe_rpc_cmd::gate_game_option_save_sc:
			out << "gate_game_option_save_sc"; 
			break;
		case mpe_rpc_cmd::gate_game_option_select_cs:
			out << "gate_game_option_select_cs"; 
			break;
		case mpe_rpc_cmd::gate_game_option_select_sc:
			out << "gate_game_option_select_sc"; 
			break;
		case mpe_rpc_cmd::gate_game_setup_hash_select_cs:
			out << "gate_game_setup_hash_select_cs"; 
			break;
		case mpe_rpc_cmd::gate_game_setup_hash_select_sc:
			out << "gate_game_setup_hash_select_sc"; 
			break;
		case mpe_rpc_cmd::gate_game_setup_save_cs:
			out << "gate_game_setup_save_cs"; 
			break;
		case mpe_rpc_cmd::gate_game_setup_save_sc:
			out << "gate_game_setup_save_sc"; 
			break;
		case mpe_rpc_cmd::gate_game_setup_select_cs:
			out << "gate_game_setup_select_cs"; 
			break;
		case mpe_rpc_cmd::gate_game_setup_select_sc:
			out << "gate_game_setup_select_sc"; 
			break;
		case mpe_rpc_cmd::gate_guild_dungeon_member_damage_cs:
			out << "gate_guild_dungeon_member_damage_cs"; 
			break;
		case mpe_rpc_cmd::gate_guild_dungeon_member_damage_sc:
			out << "gate_guild_dungeon_member_damage_sc"; 
			break;
		case mpe_rpc_cmd::gate_guild_dungeon_goods_cs:
			out << "gate_guild_dungeon_goods_cs"; 
			break;
		case mpe_rpc_cmd::gate_guild_dungeon_goods_sc:
			out << "gate_guild_dungeon_goods_sc"; 
			break;
		case mpe_rpc_cmd::gate_guild_skill_goods_cs:
			out << "gate_guild_skill_goods_cs"; 
			break;
		case mpe_rpc_cmd::gate_guild_skill_goods_sc:
			out << "gate_guild_skill_goods_sc"; 
			break;
		case mpe_rpc_cmd::gate_guild_share_storage_log_cs:
			out << "gate_guild_share_storage_log_cs"; 
			break;
		case mpe_rpc_cmd::gate_guild_share_storage_log_sc:
			out << "gate_guild_share_storage_log_sc"; 
			break;
		case mpe_rpc_cmd::gate_secretvalley_owner_info_cs:
			out << "gate_secretvalley_owner_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_secretvalley_owner_info_sc:
			out << "gate_secretvalley_owner_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_guild_league_rank_cs:
			out << "gate_guild_league_rank_cs"; 
			break;
		case mpe_rpc_cmd::gate_guild_league_rank_sc:
			out << "gate_guild_league_rank_sc"; 
			break;
		case mpe_rpc_cmd::gate_guild_storage_history_cs:
			out << "gate_guild_storage_history_cs"; 
			break;
		case mpe_rpc_cmd::gate_guild_storage_history_sc:
			out << "gate_guild_storage_history_sc"; 
			break;
		case mpe_rpc_cmd::gate_mail_check_cs:
			out << "gate_mail_check_cs"; 
			break;
		case mpe_rpc_cmd::gate_mail_check_sc:
			out << "gate_mail_check_sc"; 
			break;
		case mpe_rpc_cmd::gate_mail_list_cs:
			out << "gate_mail_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_mail_list_sc:
			out << "gate_mail_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_mentor_info_cs:
			out << "gate_mentor_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_mentor_info_sc:
			out << "gate_mentor_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_mentor_list_cs:
			out << "gate_mentor_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_mentor_list_sc:
			out << "gate_mentor_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_mentor_rev_req_list_cs:
			out << "gate_mentor_rev_req_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_mentor_rev_req_list_sc:
			out << "gate_mentor_rev_req_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_occupationwar_tender_history_cs:
			out << "gate_occupationwar_tender_history_cs"; 
			break;
		case mpe_rpc_cmd::gate_occupationwar_tender_history_sc:
			out << "gate_occupationwar_tender_history_sc"; 
			break;
		case mpe_rpc_cmd::gate_darksteel_storage_info_cs:
			out << "gate_darksteel_storage_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_darksteel_storage_info_sc:
			out << "gate_darksteel_storage_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_darksteel_storage_history_cs:
			out << "gate_darksteel_storage_history_cs"; 
			break;
		case mpe_rpc_cmd::gate_darksteel_storage_history_sc:
			out << "gate_darksteel_storage_history_sc"; 
			break;
		case mpe_rpc_cmd::gate_darksteel_storage_darksteel_daily_pay_cs:
			out << "gate_darksteel_storage_darksteel_daily_pay_cs"; 
			break;
		case mpe_rpc_cmd::gate_darksteel_storage_darksteel_daily_pay_sc:
			out << "gate_darksteel_storage_darksteel_daily_pay_sc"; 
			break;
		case mpe_rpc_cmd::gate_occupationwar_challenge_request_list_cs:
			out << "gate_occupationwar_challenge_request_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_occupationwar_challenge_request_list_sc:
			out << "gate_occupationwar_challenge_request_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_ranking_info_cs:
			out << "gate_ranking_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_ranking_info_sc:
			out << "gate_ranking_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_ranking_info_new_cs:
			out << "gate_ranking_info_new_cs"; 
			break;
		case mpe_rpc_cmd::gate_ranking_info_new_sc:
			out << "gate_ranking_info_new_sc"; 
			break;
		case mpe_rpc_cmd::gate_refinery_exchange_limit_check_cs:
			out << "gate_refinery_exchange_limit_check_cs"; 
			break;
		case mpe_rpc_cmd::gate_refinery_exchange_limit_check_sc:
			out << "gate_refinery_exchange_limit_check_sc"; 
			break;
		case mpe_rpc_cmd::gate_search_around_party_cs:
			out << "gate_search_around_party_cs"; 
			break;
		case mpe_rpc_cmd::gate_search_around_party_sc:
			out << "gate_search_around_party_sc"; 
			break;
		case mpe_rpc_cmd::gate_search_category_party_cs:
			out << "gate_search_category_party_cs"; 
			break;
		case mpe_rpc_cmd::gate_search_category_party_sc:
			out << "gate_search_category_party_sc"; 
			break;
		case mpe_rpc_cmd::gate_search_user_cs:
			out << "gate_search_user_cs"; 
			break;
		case mpe_rpc_cmd::gate_search_user_sc:
			out << "gate_search_user_sc"; 
			break;
		case mpe_rpc_cmd::gate_shipwar_result_list_cs:
			out << "gate_shipwar_result_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_shipwar_result_list_sc:
			out << "gate_shipwar_result_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_shipwar_result_cs:
			out << "gate_shipwar_result_cs"; 
			break;
		case mpe_rpc_cmd::gate_shipwar_result_sc:
			out << "gate_shipwar_result_sc"; 
			break;
		case mpe_rpc_cmd::gate_siege_warfare_alliance_list_cs:
			out << "gate_siege_warfare_alliance_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_siege_warfare_alliance_list_sc:
			out << "gate_siege_warfare_alliance_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_siege_warfare_alliance_receive_list_cs:
			out << "gate_siege_warfare_alliance_receive_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_siege_warfare_alliance_receive_list_sc:
			out << "gate_siege_warfare_alliance_receive_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_siege_warfare_atk_machine_info_cs:
			out << "gate_siege_warfare_atk_machine_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_siege_warfare_atk_machine_info_sc:
			out << "gate_siege_warfare_atk_machine_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_siege_warfare_guild_search_cs:
			out << "gate_siege_warfare_guild_search_cs"; 
			break;
		case mpe_rpc_cmd::gate_siege_warfare_guild_search_sc:
			out << "gate_siege_warfare_guild_search_sc"; 
			break;
		case mpe_rpc_cmd::gate_siegewarfare_observer_count_cs:
			out << "gate_siegewarfare_observer_count_cs"; 
			break;
		case mpe_rpc_cmd::gate_siegewarfare_observer_count_sc:
			out << "gate_siegewarfare_observer_count_sc"; 
			break;
		case mpe_rpc_cmd::gate_siege_warfare_tender_info_cs:
			out << "gate_siege_warfare_tender_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_siege_warfare_tender_info_sc:
			out << "gate_siege_warfare_tender_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_street_stall_sell_info_cs:
			out << "gate_street_stall_sell_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_street_stall_sell_info_sc:
			out << "gate_street_stall_sell_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_wanted_murder_list_cs:
			out << "gate_wanted_murder_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_wanted_murder_list_sc:
			out << "gate_wanted_murder_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_wanted_murder_register_list_cs:
			out << "gate_wanted_murder_register_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_wanted_murder_register_list_sc:
			out << "gate_wanted_murder_register_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_wanted_murder_reward_list_cs:
			out << "gate_wanted_murder_reward_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_wanted_murder_reward_list_sc:
			out << "gate_wanted_murder_reward_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_exchange_buybag_info_cs:
			out << "gate_exchange_buybag_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_exchange_buybag_info_sc:
			out << "gate_exchange_buybag_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_exchange_history_cs:
			out << "gate_exchange_history_cs"; 
			break;
		case mpe_rpc_cmd::gate_exchange_history_sc:
			out << "gate_exchange_history_sc"; 
			break;
		case mpe_rpc_cmd::gate_exchange_itemcount_all_cs:
			out << "gate_exchange_itemcount_all_cs"; 
			break;
		case mpe_rpc_cmd::gate_exchange_itemcount_all_sc:
			out << "gate_exchange_itemcount_all_sc"; 
			break;
		case mpe_rpc_cmd::gate_exchange_itemcount_type_cs:
			out << "gate_exchange_itemcount_type_cs"; 
			break;
		case mpe_rpc_cmd::gate_exchange_itemcount_type_sc:
			out << "gate_exchange_itemcount_type_sc"; 
			break;
		case mpe_rpc_cmd::gate_exchange_item_detail_cs:
			out << "gate_exchange_item_detail_cs"; 
			break;
		case mpe_rpc_cmd::gate_exchange_item_detail_sc:
			out << "gate_exchange_item_detail_sc"; 
			break;
		case mpe_rpc_cmd::gate_exchange_itemid_reg_count_lists_cs:
			out << "gate_exchange_itemid_reg_count_lists_cs"; 
			break;
		case mpe_rpc_cmd::gate_exchange_itemid_reg_count_lists_sc:
			out << "gate_exchange_itemid_reg_count_lists_sc"; 
			break;
		case mpe_rpc_cmd::gate_exchange_itemid_lists_cs:
			out << "gate_exchange_itemid_lists_cs"; 
			break;
		case mpe_rpc_cmd::gate_exchange_itemid_lists_sc:
			out << "gate_exchange_itemid_lists_sc"; 
			break;
		case mpe_rpc_cmd::gate_exchange_itemid_reinforce_count_cs:
			out << "gate_exchange_itemid_reinforce_count_cs"; 
			break;
		case mpe_rpc_cmd::gate_exchange_itemid_reinforce_count_sc:
			out << "gate_exchange_itemid_reinforce_count_sc"; 
			break;
		case mpe_rpc_cmd::gate_exchange_itemid_reinforce_list_cs:
			out << "gate_exchange_itemid_reinforce_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_exchange_itemid_reinforce_list_sc:
			out << "gate_exchange_itemid_reinforce_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_exchange_itemtype_count_cs:
			out << "gate_exchange_itemtype_count_cs"; 
			break;
		case mpe_rpc_cmd::gate_exchange_itemtype_count_sc:
			out << "gate_exchange_itemtype_count_sc"; 
			break;
		case mpe_rpc_cmd::gate_exchange_marketprice_cs:
			out << "gate_exchange_marketprice_cs"; 
			break;
		case mpe_rpc_cmd::gate_exchange_marketprice_sc:
			out << "gate_exchange_marketprice_sc"; 
			break;
		case mpe_rpc_cmd::gate_exchange_registrant_info_cs:
			out << "gate_exchange_registrant_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_exchange_registrant_info_sc:
			out << "gate_exchange_registrant_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_field_boss_regist_info_cs:
			out << "gate_field_boss_regist_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_field_boss_regist_info_sc:
			out << "gate_field_boss_regist_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_event_info_cs:
			out << "gate_event_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_event_info_sc:
			out << "gate_event_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_event_reward_cs:
			out << "gate_event_reward_cs"; 
			break;
		case mpe_rpc_cmd::gate_event_reward_sc:
			out << "gate_event_reward_sc"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_buybag_info_cs:
			out << "gate_global_exchange_buybag_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_buybag_info_sc:
			out << "gate_global_exchange_buybag_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_history_cs:
			out << "gate_global_exchange_history_cs"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_history_sc:
			out << "gate_global_exchange_history_sc"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_itemcount_all_cs:
			out << "gate_global_exchange_itemcount_all_cs"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_itemcount_all_sc:
			out << "gate_global_exchange_itemcount_all_sc"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_itemcount_type_cs:
			out << "gate_global_exchange_itemcount_type_cs"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_itemcount_type_sc:
			out << "gate_global_exchange_itemcount_type_sc"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_item_detail_cs:
			out << "gate_global_exchange_item_detail_cs"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_item_detail_sc:
			out << "gate_global_exchange_item_detail_sc"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_itemid_reg_count_lists_cs:
			out << "gate_global_exchange_itemid_reg_count_lists_cs"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_itemid_reg_count_lists_sc:
			out << "gate_global_exchange_itemid_reg_count_lists_sc"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_itemid_lists_cs:
			out << "gate_global_exchange_itemid_lists_cs"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_itemid_lists_sc:
			out << "gate_global_exchange_itemid_lists_sc"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_itemid_reinforce_count_cs:
			out << "gate_global_exchange_itemid_reinforce_count_cs"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_itemid_reinforce_count_sc:
			out << "gate_global_exchange_itemid_reinforce_count_sc"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_itemid_reinforce_list_cs:
			out << "gate_global_exchange_itemid_reinforce_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_itemid_reinforce_list_sc:
			out << "gate_global_exchange_itemid_reinforce_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_itemtype_count_cs:
			out << "gate_global_exchange_itemtype_count_cs"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_itemtype_count_sc:
			out << "gate_global_exchange_itemtype_count_sc"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_marketprice_cs:
			out << "gate_global_exchange_marketprice_cs"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_marketprice_sc:
			out << "gate_global_exchange_marketprice_sc"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_registrant_info_cs:
			out << "gate_global_exchange_registrant_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_global_exchange_registrant_info_sc:
			out << "gate_global_exchange_registrant_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_cash_shop_info_cs:
			out << "gate_cash_shop_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_cash_shop_info_sc:
			out << "gate_cash_shop_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_contents_onoff_list_cs:
			out << "gate_contents_onoff_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_contents_onoff_list_sc:
			out << "gate_contents_onoff_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_pay_start_cs:
			out << "gate_pay_start_cs"; 
			break;
		case mpe_rpc_cmd::gate_pay_start_sc:
			out << "gate_pay_start_sc"; 
			break;
		case mpe_rpc_cmd::gate_pay_verify_cs:
			out << "gate_pay_verify_cs"; 
			break;
		case mpe_rpc_cmd::gate_pay_verify_sc:
			out << "gate_pay_verify_sc"; 
			break;
		case mpe_rpc_cmd::gate_pre_verify_cs:
			out << "gate_pre_verify_cs"; 
			break;
		case mpe_rpc_cmd::gate_pre_verify_sc:
			out << "gate_pre_verify_sc"; 
			break;
		case mpe_rpc_cmd::gate_promo_verify_cs:
			out << "gate_promo_verify_cs"; 
			break;
		case mpe_rpc_cmd::gate_promo_verify_sc:
			out << "gate_promo_verify_sc"; 
			break;
		case mpe_rpc_cmd::gate_cash_shop_item_list_cs:
			out << "gate_cash_shop_item_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_cash_shop_item_list_sc:
			out << "gate_cash_shop_item_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_lobby_character_create_cs:
			out << "gate_lobby_character_create_cs"; 
			break;
		case mpe_rpc_cmd::gate_lobby_character_create_sc:
			out << "gate_lobby_character_create_sc"; 
			break;
		case mpe_rpc_cmd::gate_lobby_character_delete_cs:
			out << "gate_lobby_character_delete_cs"; 
			break;
		case mpe_rpc_cmd::gate_lobby_character_delete_sc:
			out << "gate_lobby_character_delete_sc"; 
			break;
		case mpe_rpc_cmd::gate_lobby_character_delete_cancel_cs:
			out << "gate_lobby_character_delete_cancel_cs"; 
			break;
		case mpe_rpc_cmd::gate_lobby_character_delete_cancel_sc:
			out << "gate_lobby_character_delete_cancel_sc"; 
			break;
		case mpe_rpc_cmd::gate_lobby_character_select_cs:
			out << "gate_lobby_character_select_cs"; 
			break;
		case mpe_rpc_cmd::gate_lobby_character_select_sc:
			out << "gate_lobby_character_select_sc"; 
			break;
		case mpe_rpc_cmd::gate_lobby_gameplaylogin_cs:
			out << "gate_lobby_gameplaylogin_cs"; 
			break;
		case mpe_rpc_cmd::gate_lobby_gameplaylogin_sc:
			out << "gate_lobby_gameplaylogin_sc"; 
			break;
		case mpe_rpc_cmd::gate_lobby_gamelogin_await_cancel_cs:
			out << "gate_lobby_gamelogin_await_cancel_cs"; 
			break;
		case mpe_rpc_cmd::gate_lobby_gamelogin_await_cancel_sc:
			out << "gate_lobby_gamelogin_await_cancel_sc"; 
			break;
		case mpe_rpc_cmd::gate_get_available_font_list_cs:
			out << "gate_get_available_font_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_get_available_font_list_sc:
			out << "gate_get_available_font_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_channel_status_cs:
			out << "gate_channel_status_cs"; 
			break;
		case mpe_rpc_cmd::gate_channel_status_sc:
			out << "gate_channel_status_sc"; 
			break;
		case mpe_rpc_cmd::gate_channel_full_check_cs:
			out << "gate_channel_full_check_cs"; 
			break;
		case mpe_rpc_cmd::gate_channel_full_check_sc:
			out << "gate_channel_full_check_sc"; 
			break;
		case mpe_rpc_cmd::gate_loginserver_lobby_login_cs:
			out << "gate_loginserver_lobby_login_cs"; 
			break;
		case mpe_rpc_cmd::gate_loginserver_lobby_login_sc:
			out << "gate_loginserver_lobby_login_sc"; 
			break;
		case mpe_rpc_cmd::gate_loginserver_duplicate_login_cs:
			out << "gate_loginserver_duplicate_login_cs"; 
			break;
		case mpe_rpc_cmd::gate_loginserver_duplicate_login_sc:
			out << "gate_loginserver_duplicate_login_sc"; 
			break;
		case mpe_rpc_cmd::gate_arena_battle_ranking_cs:
			out << "gate_arena_battle_ranking_cs"; 
			break;
		case mpe_rpc_cmd::gate_arena_battle_ranking_sc:
			out << "gate_arena_battle_ranking_sc"; 
			break;
		case mpe_rpc_cmd::gate_arena_battle_info_cs:
			out << "gate_arena_battle_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_arena_battle_info_sc:
			out << "gate_arena_battle_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_arena_battle_result_list_cs:
			out << "gate_arena_battle_result_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_arena_battle_result_list_sc:
			out << "gate_arena_battle_result_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_arena_battle_result_cs:
			out << "gate_arena_battle_result_cs"; 
			break;
		case mpe_rpc_cmd::gate_arena_battle_result_sc:
			out << "gate_arena_battle_result_sc"; 
			break;
		case mpe_rpc_cmd::gate_guildshipwar_season_reward_cs:
			out << "gate_guildshipwar_season_reward_cs"; 
			break;
		case mpe_rpc_cmd::gate_guildshipwar_season_reward_sc:
			out << "gate_guildshipwar_season_reward_sc"; 
			break;
		case mpe_rpc_cmd::gate_world_boss_statking_board_info_cs:
			out << "gate_world_boss_statking_board_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_world_boss_statking_board_info_sc:
			out << "gate_world_boss_statking_board_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_occupationwar_statking_board_info_cs:
			out << "gate_occupationwar_statking_board_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_occupationwar_statking_board_info_sc:
			out << "gate_occupationwar_statking_board_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_occupationwar_schedule_info_cs:
			out << "gate_occupationwar_schedule_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_occupationwar_schedule_info_sc:
			out << "gate_occupationwar_schedule_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_world_boss_linked_wallet_info_cs:
			out << "gate_world_boss_linked_wallet_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_world_boss_linked_wallet_info_sc:
			out << "gate_world_boss_linked_wallet_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_worldboard_guild_league_rank_cs:
			out << "gate_worldboard_guild_league_rank_cs"; 
			break;
		case mpe_rpc_cmd::gate_worldboard_guild_league_rank_sc:
			out << "gate_worldboard_guild_league_rank_sc"; 
			break;
		case mpe_rpc_cmd::gate_worldboard_shipwar_result_list_cs:
			out << "gate_worldboard_shipwar_result_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_worldboard_shipwar_result_list_sc:
			out << "gate_worldboard_shipwar_result_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_worldboard_shipwar_result_cs:
			out << "gate_worldboard_shipwar_result_cs"; 
			break;
		case mpe_rpc_cmd::gate_worldboard_shipwar_result_sc:
			out << "gate_worldboard_shipwar_result_sc"; 
			break;
		case mpe_rpc_cmd::gate_wemix_pay_start_cs:
			out << "gate_wemix_pay_start_cs"; 
			break;
		case mpe_rpc_cmd::gate_wemix_pay_start_sc:
			out << "gate_wemix_pay_start_sc"; 
			break;
		case mpe_rpc_cmd::gate_wemix_pay_end_cs:
			out << "gate_wemix_pay_end_cs"; 
			break;
		case mpe_rpc_cmd::gate_wemix_pay_end_sc:
			out << "gate_wemix_pay_end_sc"; 
			break;
		case mpe_rpc_cmd::gate_get_wemix_amount_cs:
			out << "gate_get_wemix_amount_cs"; 
			break;
		case mpe_rpc_cmd::gate_get_wemix_amount_sc:
			out << "gate_get_wemix_amount_sc"; 
			break;
		case mpe_rpc_cmd::gate_get_wemix_history_cs:
			out << "gate_get_wemix_history_cs"; 
			break;
		case mpe_rpc_cmd::gate_get_wemix_history_sc:
			out << "gate_get_wemix_history_sc"; 
			break;
		case mpe_rpc_cmd::gate_advertisement_exp_restore_cs:
			out << "gate_advertisement_exp_restore_cs"; 
			break;
		case mpe_rpc_cmd::gate_advertisement_exp_restore_sc:
			out << "gate_advertisement_exp_restore_sc"; 
			break;
		case mpe_rpc_cmd::gate_advertisement_reward_cs:
			out << "gate_advertisement_reward_cs"; 
			break;
		case mpe_rpc_cmd::gate_advertisement_reward_sc:
			out << "gate_advertisement_reward_sc"; 
			break;
		case mpe_rpc_cmd::gate_advertisement_event_reward_cs:
			out << "gate_advertisement_event_reward_cs"; 
			break;
		case mpe_rpc_cmd::gate_advertisement_event_reward_sc:
			out << "gate_advertisement_event_reward_sc"; 
			break;
		case mpe_rpc_cmd::gate_get_all_balance_swap_token_cs:
			out << "gate_get_all_balance_swap_token_cs"; 
			break;
		case mpe_rpc_cmd::gate_get_all_balance_swap_token_sc:
			out << "gate_get_all_balance_swap_token_sc"; 
			break;
		case mpe_rpc_cmd::gate_advertisement_info_cs:
			out << "gate_advertisement_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_advertisement_info_sc:
			out << "gate_advertisement_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_client_session_open_cs:
			out << "gate_client_session_open_cs"; 
			break;
		case mpe_rpc_cmd::gate_client_session_open_sc:
			out << "gate_client_session_open_sc"; 
			break;
		case mpe_rpc_cmd::gate_client_session_closed_cs:
			out << "gate_client_session_closed_cs"; 
			break;
		case mpe_rpc_cmd::gate_client_session_closed_sc:
			out << "gate_client_session_closed_sc"; 
			break;
		case mpe_rpc_cmd::gate_rpc_chatting_cs:
			out << "gate_rpc_chatting_cs"; 
			break;
		case mpe_rpc_cmd::gate_rpc_chatting_sc:
			out << "gate_rpc_chatting_sc"; 
			break;
		case mpe_rpc_cmd::gate_community_login_cs:
			out << "gate_community_login_cs"; 
			break;
		case mpe_rpc_cmd::gate_community_login_sc:
			out << "gate_community_login_sc"; 
			break;
		case mpe_rpc_cmd::gate_chatting_cs:
			out << "gate_chatting_cs"; 
			break;
		case mpe_rpc_cmd::gate_chatting_sc:
			out << "gate_chatting_sc"; 
			break;
		case mpe_rpc_cmd::gate_chatting_block_cs:
			out << "gate_chatting_block_cs"; 
			break;
		case mpe_rpc_cmd::gate_chatting_block_sc:
			out << "gate_chatting_block_sc"; 
			break;
		case mpe_rpc_cmd::gate_chatting_block_list_cs:
			out << "gate_chatting_block_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_chatting_block_list_sc:
			out << "gate_chatting_block_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_private_chatting_state_cs:
			out << "gate_private_chatting_state_cs"; 
			break;
		case mpe_rpc_cmd::gate_private_chatting_state_sc:
			out << "gate_private_chatting_state_sc"; 
			break;
		case mpe_rpc_cmd::gate_server_relocation_list_cs:
			out << "gate_server_relocation_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_server_relocation_list_sc:
			out << "gate_server_relocation_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_dogma_pay_start_cs:
			out << "gate_dogma_pay_start_cs"; 
			break;
		case mpe_rpc_cmd::gate_dogma_pay_start_sc:
			out << "gate_dogma_pay_start_sc"; 
			break;
		case mpe_rpc_cmd::gate_dogma_pay_end_cs:
			out << "gate_dogma_pay_end_cs"; 
			break;
		case mpe_rpc_cmd::gate_dogma_pay_end_sc:
			out << "gate_dogma_pay_end_sc"; 
			break;
		case mpe_rpc_cmd::gate_dogma_get_oracle_cs:
			out << "gate_dogma_get_oracle_cs"; 
			break;
		case mpe_rpc_cmd::gate_dogma_get_oracle_sc:
			out << "gate_dogma_get_oracle_sc"; 
			break;
		case mpe_rpc_cmd::gate_dimension_dungeon_schedule_cs:
			out << "gate_dimension_dungeon_schedule_cs"; 
			break;
		case mpe_rpc_cmd::gate_dimension_dungeon_schedule_sc:
			out << "gate_dimension_dungeon_schedule_sc"; 
			break;
		case mpe_rpc_cmd::gate_lobby_player_character_select_cs:
			out << "gate_lobby_player_character_select_cs"; 
			break;
		case mpe_rpc_cmd::gate_lobby_player_character_select_sc:
			out << "gate_lobby_player_character_select_sc"; 
			break;
		case mpe_rpc_cmd::gate_lobby_player_character_delete_cs:
			out << "gate_lobby_player_character_delete_cs"; 
			break;
		case mpe_rpc_cmd::gate_lobby_player_character_delete_sc:
			out << "gate_lobby_player_character_delete_sc"; 
			break;
		case mpe_rpc_cmd::gate_lobby_character_socket_reconnect_cs:
			out << "gate_lobby_character_socket_reconnect_cs"; 
			break;
		case mpe_rpc_cmd::gate_lobby_character_socket_reconnect_sc:
			out << "gate_lobby_character_socket_reconnect_sc"; 
			break;
		case mpe_rpc_cmd::community_secretvalley_alert_cs:
			out << "community_secretvalley_alert_cs"; 
			break;
		case mpe_rpc_cmd::community_secretvalley_alert_sc:
			out << "community_secretvalley_alert_sc"; 
			break;
		case mpe_rpc_cmd::community_secretvalley_info_cs:
			out << "community_secretvalley_info_cs"; 
			break;
		case mpe_rpc_cmd::community_secretvalley_info_sc:
			out << "community_secretvalley_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_occupationwar_tender_board_cs:
			out << "gate_occupationwar_tender_board_cs"; 
			break;
		case mpe_rpc_cmd::gate_occupationwar_tender_board_sc:
			out << "gate_occupationwar_tender_board_sc"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_buybag_info_cs:
			out << "gate_world_exchange_buybag_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_buybag_info_sc:
			out << "gate_world_exchange_buybag_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_history_cs:
			out << "gate_world_exchange_history_cs"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_history_sc:
			out << "gate_world_exchange_history_sc"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_itemcount_all_cs:
			out << "gate_world_exchange_itemcount_all_cs"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_itemcount_all_sc:
			out << "gate_world_exchange_itemcount_all_sc"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_itemcount_type_cs:
			out << "gate_world_exchange_itemcount_type_cs"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_itemcount_type_sc:
			out << "gate_world_exchange_itemcount_type_sc"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_item_detail_cs:
			out << "gate_world_exchange_item_detail_cs"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_item_detail_sc:
			out << "gate_world_exchange_item_detail_sc"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_itemid_reg_count_lists_cs:
			out << "gate_world_exchange_itemid_reg_count_lists_cs"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_itemid_reg_count_lists_sc:
			out << "gate_world_exchange_itemid_reg_count_lists_sc"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_itemid_lists_cs:
			out << "gate_world_exchange_itemid_lists_cs"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_itemid_lists_sc:
			out << "gate_world_exchange_itemid_lists_sc"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_itemid_reinforce_count_cs:
			out << "gate_world_exchange_itemid_reinforce_count_cs"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_itemid_reinforce_count_sc:
			out << "gate_world_exchange_itemid_reinforce_count_sc"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_itemid_reinforce_list_cs:
			out << "gate_world_exchange_itemid_reinforce_list_cs"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_itemid_reinforce_list_sc:
			out << "gate_world_exchange_itemid_reinforce_list_sc"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_itemtype_count_cs:
			out << "gate_world_exchange_itemtype_count_cs"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_itemtype_count_sc:
			out << "gate_world_exchange_itemtype_count_sc"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_marketprice_cs:
			out << "gate_world_exchange_marketprice_cs"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_marketprice_sc:
			out << "gate_world_exchange_marketprice_sc"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_registrant_info_cs:
			out << "gate_world_exchange_registrant_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_world_exchange_registrant_info_sc:
			out << "gate_world_exchange_registrant_info_sc"; 
			break;
		case mpe_rpc_cmd::gate_blood_dedicate_worldboss_status_cs:
			out << "gate_blood_dedicate_worldboss_status_cs"; 
			break;
		case mpe_rpc_cmd::gate_blood_dedicate_worldboss_status_sc:
			out << "gate_blood_dedicate_worldboss_status_sc"; 
			break;
		case mpe_rpc_cmd::gate_dungeon_ranking_info_cs:
			out << "gate_dungeon_ranking_info_cs"; 
			break;
		case mpe_rpc_cmd::gate_dungeon_ranking_info_sc:
			out << "gate_dungeon_ranking_info_sc"; 
			break;
		case mpe_rpc_cmd::gm_notice_cs:
			out << "gm_notice_cs"; 
			break;
		case mpe_rpc_cmd::gm_notice_sc:
			out << "gm_notice_sc"; 
			break;
		case mpe_rpc_cmd::gm_cash_shop_item_update_cs:
			out << "gm_cash_shop_item_update_cs"; 
			break;
		case mpe_rpc_cmd::gm_cash_shop_item_update_sc:
			out << "gm_cash_shop_item_update_sc"; 
			break;
		case mpe_rpc_cmd::gm_add_exp_cs:
			out << "gm_add_exp_cs"; 
			break;
		case mpe_rpc_cmd::gm_add_exp_sc:
			out << "gm_add_exp_sc"; 
			break;
		case mpe_rpc_cmd::gm_getitem_cs:
			out << "gm_getitem_cs"; 
			break;
		case mpe_rpc_cmd::gm_getitem_sc:
			out << "gm_getitem_sc"; 
			break;
		case mpe_rpc_cmd::gm_skill_all_learn_cs:
			out << "gm_skill_all_learn_cs"; 
			break;
		case mpe_rpc_cmd::gm_skill_all_learn_sc:
			out << "gm_skill_all_learn_sc"; 
			break;
		case mpe_rpc_cmd::gm_table_patch_cs:
			out << "gm_table_patch_cs"; 
			break;
		case mpe_rpc_cmd::gm_table_patch_sc:
			out << "gm_table_patch_sc"; 
			break;
		case mpe_rpc_cmd::gm_guild_storage_treasure_insert_item_cs:
			out << "gm_guild_storage_treasure_insert_item_cs"; 
			break;
		case mpe_rpc_cmd::gm_guild_storage_treasure_insert_item_sc:
			out << "gm_guild_storage_treasure_insert_item_sc"; 
			break;
		case mpe_rpc_cmd::gm_quest_clear_cs:
			out << "gm_quest_clear_cs"; 
			break;
		case mpe_rpc_cmd::gm_quest_clear_sc:
			out << "gm_quest_clear_sc"; 
			break;
		case mpe_rpc_cmd::gm_quest_clear_list_cs:
			out << "gm_quest_clear_list_cs"; 
			break;
		case mpe_rpc_cmd::gm_quest_clear_list_sc:
			out << "gm_quest_clear_list_sc"; 
			break;
		case mpe_rpc_cmd::gm_quest_accept_cs:
			out << "gm_quest_accept_cs"; 
			break;
		case mpe_rpc_cmd::gm_quest_accept_sc:
			out << "gm_quest_accept_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_gold_edit_cs:
			out << "gm_api_guild_gold_edit_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_gold_edit_sc:
			out << "gm_api_guild_gold_edit_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_black_iron_edit_cs:
			out << "gm_api_guild_black_iron_edit_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_black_iron_edit_sc:
			out << "gm_api_guild_black_iron_edit_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_level_edit_cs:
			out << "gm_api_guild_level_edit_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_level_edit_sc:
			out << "gm_api_guild_level_edit_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_member_point_edit_cs:
			out << "gm_api_guild_member_point_edit_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_member_point_edit_sc:
			out << "gm_api_guild_member_point_edit_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_storage_material_add_cs:
			out << "gm_api_guild_storage_material_add_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_storage_material_add_sc:
			out << "gm_api_guild_storage_material_add_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_storage_supply_add_cs:
			out << "gm_api_guild_storage_supply_add_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_storage_supply_add_sc:
			out << "gm_api_guild_storage_supply_add_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_storage_share_add_cs:
			out << "gm_api_guild_storage_share_add_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_storage_share_add_sc:
			out << "gm_api_guild_storage_share_add_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_storage_treasure_add_cs:
			out << "gm_api_guild_storage_treasure_add_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_storage_treasure_add_sc:
			out << "gm_api_guild_storage_treasure_add_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_user_lock_cs:
			out << "gm_api_user_lock_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_user_lock_sc:
			out << "gm_api_user_lock_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_user_unlock_cs:
			out << "gm_api_user_unlock_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_user_unlock_sc:
			out << "gm_api_user_unlock_sc"; 
			break;
		case mpe_rpc_cmd::gm_profesion_update_cs:
			out << "gm_profesion_update_cs"; 
			break;
		case mpe_rpc_cmd::gm_profesion_update_sc:
			out << "gm_profesion_update_sc"; 
			break;
		case mpe_rpc_cmd::gm_skill_expup_cs:
			out << "gm_skill_expup_cs"; 
			break;
		case mpe_rpc_cmd::gm_skill_expup_sc:
			out << "gm_skill_expup_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_edit_item_cs:
			out << "gm_tool_edit_item_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_edit_item_sc:
			out << "gm_tool_edit_item_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_edit_profession_cs:
			out << "gm_tool_edit_profession_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_edit_profession_sc:
			out << "gm_tool_edit_profession_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_edit_guild_member_point_cs:
			out << "gm_tool_edit_guild_member_point_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_edit_guild_member_point_sc:
			out << "gm_tool_edit_guild_member_point_sc"; 
			break;
		case mpe_rpc_cmd::gm_guild_shipwar_state_cs:
			out << "gm_guild_shipwar_state_cs"; 
			break;
		case mpe_rpc_cmd::gm_guild_shipwar_state_sc:
			out << "gm_guild_shipwar_state_sc"; 
			break;
		case mpe_rpc_cmd::gm_siege_state_cs:
			out << "gm_siege_state_cs"; 
			break;
		case mpe_rpc_cmd::gm_siege_state_sc:
			out << "gm_siege_state_sc"; 
			break;
		case mpe_rpc_cmd::gm_add_title_cs:
			out << "gm_add_title_cs"; 
			break;
		case mpe_rpc_cmd::gm_add_title_sc:
			out << "gm_add_title_sc"; 
			break;
		case mpe_rpc_cmd::gm_lobby_enable_cs:
			out << "gm_lobby_enable_cs"; 
			break;
		case mpe_rpc_cmd::gm_lobby_enable_sc:
			out << "gm_lobby_enable_sc"; 
			break;
		case mpe_rpc_cmd::gm_create_bot_cs:
			out << "gm_create_bot_cs"; 
			break;
		case mpe_rpc_cmd::gm_create_bot_sc:
			out << "gm_create_bot_sc"; 
			break;
		case mpe_rpc_cmd::gm_avatar_get_cs:
			out << "gm_avatar_get_cs"; 
			break;
		case mpe_rpc_cmd::gm_avatar_get_sc:
			out << "gm_avatar_get_sc"; 
			break;
		case mpe_rpc_cmd::gm_reflection_add_cs:
			out << "gm_reflection_add_cs"; 
			break;
		case mpe_rpc_cmd::gm_reflection_add_sc:
			out << "gm_reflection_add_sc"; 
			break;
		case mpe_rpc_cmd::gm_add_guild_goods_cs:
			out << "gm_add_guild_goods_cs"; 
			break;
		case mpe_rpc_cmd::gm_add_guild_goods_sc:
			out << "gm_add_guild_goods_sc"; 
			break;
		case mpe_rpc_cmd::gm_arena_battle_start_cs:
			out << "gm_arena_battle_start_cs"; 
			break;
		case mpe_rpc_cmd::gm_arena_battle_start_sc:
			out << "gm_arena_battle_start_sc"; 
			break;
		case mpe_rpc_cmd::gm_quest_finish_cs:
			out << "gm_quest_finish_cs"; 
			break;
		case mpe_rpc_cmd::gm_quest_finish_sc:
			out << "gm_quest_finish_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_user_kick_cs:
			out << "gm_api_user_kick_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_user_kick_sc:
			out << "gm_api_user_kick_sc"; 
			break;
		case mpe_rpc_cmd::gm_get_vehicle_cs:
			out << "gm_get_vehicle_cs"; 
			break;
		case mpe_rpc_cmd::gm_get_vehicle_sc:
			out << "gm_get_vehicle_sc"; 
			break;
		case mpe_rpc_cmd::gm_get_pet_cs:
			out << "gm_get_pet_cs"; 
			break;
		case mpe_rpc_cmd::gm_get_pet_sc:
			out << "gm_get_pet_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_add_exp_cs:
			out << "gm_tool_add_exp_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_add_exp_sc:
			out << "gm_tool_add_exp_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_add_item_cs:
			out << "gm_tool_add_item_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_add_item_sc:
			out << "gm_tool_add_item_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_skill_update_cs:
			out << "gm_tool_skill_update_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_skill_update_sc:
			out << "gm_tool_skill_update_sc"; 
			break;
		case mpe_rpc_cmd::gm_user_lock_cs:
			out << "gm_user_lock_cs"; 
			break;
		case mpe_rpc_cmd::gm_user_lock_sc:
			out << "gm_user_lock_sc"; 
			break;
		case mpe_rpc_cmd::gm_user_unlock_cs:
			out << "gm_user_unlock_cs"; 
			break;
		case mpe_rpc_cmd::gm_user_unlock_sc:
			out << "gm_user_unlock_sc"; 
			break;
		case mpe_rpc_cmd::gm_dictionary_add_cs:
			out << "gm_dictionary_add_cs"; 
			break;
		case mpe_rpc_cmd::gm_dictionary_add_sc:
			out << "gm_dictionary_add_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_edit_character_goods_cs:
			out << "gm_tool_edit_character_goods_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_edit_character_goods_sc:
			out << "gm_tool_edit_character_goods_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_skill_learn_cs:
			out << "gm_tool_skill_learn_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_skill_learn_sc:
			out << "gm_tool_skill_learn_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_skill_delete_cs:
			out << "gm_tool_skill_delete_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_skill_delete_sc:
			out << "gm_tool_skill_delete_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_add_guild_exp_cs:
			out << "gm_tool_add_guild_exp_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_add_guild_exp_sc:
			out << "gm_tool_add_guild_exp_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_edit_guild_gold_cs:
			out << "gm_tool_edit_guild_gold_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_edit_guild_gold_sc:
			out << "gm_tool_edit_guild_gold_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_add_guild_storage_material_cs:
			out << "gm_tool_add_guild_storage_material_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_add_guild_storage_material_sc:
			out << "gm_tool_add_guild_storage_material_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_add_guild_storage_supply_cs:
			out << "gm_tool_add_guild_storage_supply_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_add_guild_storage_supply_sc:
			out << "gm_tool_add_guild_storage_supply_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_add_guild_storage_share_cs:
			out << "gm_tool_add_guild_storage_share_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_add_guild_storage_share_sc:
			out << "gm_tool_add_guild_storage_share_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_add_guild_storage_treasure_cs:
			out << "gm_tool_add_guild_storage_treasure_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_add_guild_storage_treasure_sc:
			out << "gm_tool_add_guild_storage_treasure_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_remove_guild_storage_material_cs:
			out << "gm_tool_remove_guild_storage_material_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_remove_guild_storage_material_sc:
			out << "gm_tool_remove_guild_storage_material_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_remove_guild_storage_supply_cs:
			out << "gm_tool_remove_guild_storage_supply_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_remove_guild_storage_supply_sc:
			out << "gm_tool_remove_guild_storage_supply_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_remove_guild_storage_share_cs:
			out << "gm_tool_remove_guild_storage_share_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_remove_guild_storage_share_sc:
			out << "gm_tool_remove_guild_storage_share_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_remove_guild_storage_treasure_cs:
			out << "gm_tool_remove_guild_storage_treasure_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_remove_guild_storage_treasure_sc:
			out << "gm_tool_remove_guild_storage_treasure_sc"; 
			break;
		case mpe_rpc_cmd::gm_quest_initialization_cs:
			out << "gm_quest_initialization_cs"; 
			break;
		case mpe_rpc_cmd::gm_quest_initialization_sc:
			out << "gm_quest_initialization_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_edit_quest_cs:
			out << "gm_tool_edit_quest_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_edit_quest_sc:
			out << "gm_tool_edit_quest_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_finish_multiple_quest_cs:
			out << "gm_tool_finish_multiple_quest_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_finish_multiple_quest_sc:
			out << "gm_tool_finish_multiple_quest_sc"; 
			break;
		case mpe_rpc_cmd::gm_tool_remove_quest_info_cs:
			out << "gm_tool_remove_quest_info_cs"; 
			break;
		case mpe_rpc_cmd::gm_tool_remove_quest_info_sc:
			out << "gm_tool_remove_quest_info_sc"; 
			break;
		case mpe_rpc_cmd::gm_guild_add_exp_cs:
			out << "gm_guild_add_exp_cs"; 
			break;
		case mpe_rpc_cmd::gm_guild_add_exp_sc:
			out << "gm_guild_add_exp_sc"; 
			break;
		case mpe_rpc_cmd::gm_achieve_all_get_cs:
			out << "gm_achieve_all_get_cs"; 
			break;
		case mpe_rpc_cmd::gm_achieve_all_get_sc:
			out << "gm_achieve_all_get_sc"; 
			break;
		case mpe_rpc_cmd::gm_levelup_cs:
			out << "gm_levelup_cs"; 
			break;
		case mpe_rpc_cmd::gm_levelup_sc:
			out << "gm_levelup_sc"; 
			break;
		case mpe_rpc_cmd::gm_server_world_info_update_cs:
			out << "gm_server_world_info_update_cs"; 
			break;
		case mpe_rpc_cmd::gm_server_world_info_update_sc:
			out << "gm_server_world_info_update_sc"; 
			break;
		case mpe_rpc_cmd::gm_server_world_info_get_cs:
			out << "gm_server_world_info_get_cs"; 
			break;
		case mpe_rpc_cmd::gm_server_world_info_get_sc:
			out << "gm_server_world_info_get_sc"; 
			break;
		case mpe_rpc_cmd::gm_governance_info_update_cs:
			out << "gm_governance_info_update_cs"; 
			break;
		case mpe_rpc_cmd::gm_governance_info_update_sc:
			out << "gm_governance_info_update_sc"; 
			break;
		case mpe_rpc_cmd::gm_governance_info_get_cs:
			out << "gm_governance_info_get_cs"; 
			break;
		case mpe_rpc_cmd::gm_governance_info_get_sc:
			out << "gm_governance_info_get_sc"; 
			break;
		case mpe_rpc_cmd::gm_boss_governance_spawn_cs:
			out << "gm_boss_governance_spawn_cs"; 
			break;
		case mpe_rpc_cmd::gm_boss_governance_spawn_sc:
			out << "gm_boss_governance_spawn_sc"; 
			break;
		case mpe_rpc_cmd::gm_scheduler_contents_initialize_cs:
			out << "gm_scheduler_contents_initialize_cs"; 
			break;
		case mpe_rpc_cmd::gm_scheduler_contents_initialize_sc:
			out << "gm_scheduler_contents_initialize_sc"; 
			break;
		case mpe_rpc_cmd::gm_scheduler_contents_info_cs:
			out << "gm_scheduler_contents_info_cs"; 
			break;
		case mpe_rpc_cmd::gm_scheduler_contents_info_sc:
			out << "gm_scheduler_contents_info_sc"; 
			break;
		case mpe_rpc_cmd::gm_mandala_node_add_cs:
			out << "gm_mandala_node_add_cs"; 
			break;
		case mpe_rpc_cmd::gm_mandala_node_add_sc:
			out << "gm_mandala_node_add_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_goldingot_edit_cs:
			out << "gm_api_guild_goldingot_edit_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_goldingot_edit_sc:
			out << "gm_api_guild_goldingot_edit_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_user_kick_cuid_cs:
			out << "gm_api_user_kick_cuid_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_user_kick_cuid_sc:
			out << "gm_api_user_kick_cuid_sc"; 
			break;
		case mpe_rpc_cmd::gm_skill_force_edit_cs:
			out << "gm_skill_force_edit_cs"; 
			break;
		case mpe_rpc_cmd::gm_skill_force_edit_sc:
			out << "gm_skill_force_edit_sc"; 
			break;
		case mpe_rpc_cmd::gm_illusion_dungeon_update_cs:
			out << "gm_illusion_dungeon_update_cs"; 
			break;
		case mpe_rpc_cmd::gm_illusion_dungeon_update_sc:
			out << "gm_illusion_dungeon_update_sc"; 
			break;
		case mpe_rpc_cmd::gm_guild_shipwar_league_update_cs:
			out << "gm_guild_shipwar_league_update_cs"; 
			break;
		case mpe_rpc_cmd::gm_guild_shipwar_league_update_sc:
			out << "gm_guild_shipwar_league_update_sc"; 
			break;
		case mpe_rpc_cmd::gm_guild_dungeon_reset_cs:
			out << "gm_guild_dungeon_reset_cs"; 
			break;
		case mpe_rpc_cmd::gm_guild_dungeon_reset_sc:
			out << "gm_guild_dungeon_reset_sc"; 
			break;
		case mpe_rpc_cmd::gm_channel_add_cs:
			out << "gm_channel_add_cs"; 
			break;
		case mpe_rpc_cmd::gm_channel_add_sc:
			out << "gm_channel_add_sc"; 
			break;
		case mpe_rpc_cmd::gm_channel_list_get_cs:
			out << "gm_channel_list_get_cs"; 
			break;
		case mpe_rpc_cmd::gm_channel_list_get_sc:
			out << "gm_channel_list_get_sc"; 
			break;
		case mpe_rpc_cmd::gm_server_group_info_cs:
			out << "gm_server_group_info_cs"; 
			break;
		case mpe_rpc_cmd::gm_server_group_info_sc:
			out << "gm_server_group_info_sc"; 
			break;
		case mpe_rpc_cmd::gm_arena_calculate_season_ranking_cs:
			out << "gm_arena_calculate_season_ranking_cs"; 
			break;
		case mpe_rpc_cmd::gm_arena_calculate_season_ranking_sc:
			out << "gm_arena_calculate_season_ranking_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_kick_all_cs:
			out << "gm_api_kick_all_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_kick_all_sc:
			out << "gm_api_kick_all_sc"; 
			break;
		case mpe_rpc_cmd::gm_update_security_level_cs:
			out << "gm_update_security_level_cs"; 
			break;
		case mpe_rpc_cmd::gm_update_security_level_sc:
			out << "gm_update_security_level_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_introduction_change_cs:
			out << "gm_api_guild_introduction_change_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_introduction_change_sc:
			out << "gm_api_guild_introduction_change_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_notice_change_cs:
			out << "gm_api_guild_notice_change_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_notice_change_sc:
			out << "gm_api_guild_notice_change_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_character_item_delete_cs:
			out << "gm_api_character_item_delete_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_character_item_delete_sc:
			out << "gm_api_character_item_delete_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_skill_edit_cs:
			out << "gm_api_guild_skill_edit_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_skill_edit_sc:
			out << "gm_api_guild_skill_edit_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_war_end_cs:
			out << "gm_api_guild_war_end_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_guild_war_end_sc:
			out << "gm_api_guild_war_end_sc"; 
			break;
		case mpe_rpc_cmd::gm_global_governance_decide_cs:
			out << "gm_global_governance_decide_cs"; 
			break;
		case mpe_rpc_cmd::gm_global_governance_decide_sc:
			out << "gm_global_governance_decide_sc"; 
			break;
		case mpe_rpc_cmd::gm_exchange_item_minprice_update_cs:
			out << "gm_exchange_item_minprice_update_cs"; 
			break;
		case mpe_rpc_cmd::gm_exchange_item_minprice_update_sc:
			out << "gm_exchange_item_minprice_update_sc"; 
			break;
		case mpe_rpc_cmd::gm_occupationwar_darksteelstorage_set_cs:
			out << "gm_occupationwar_darksteelstorage_set_cs"; 
			break;
		case mpe_rpc_cmd::gm_occupationwar_darksteelstorage_set_sc:
			out << "gm_occupationwar_darksteelstorage_set_sc"; 
			break;
		case mpe_rpc_cmd::gm_dimension_dungeon_cmd_cs:
			out << "gm_dimension_dungeon_cmd_cs"; 
			break;
		case mpe_rpc_cmd::gm_dimension_dungeon_cmd_sc:
			out << "gm_dimension_dungeon_cmd_sc"; 
			break;
		case mpe_rpc_cmd::gm_dimension_dungeon_crack_cmd_cs:
			out << "gm_dimension_dungeon_crack_cmd_cs"; 
			break;
		case mpe_rpc_cmd::gm_dimension_dungeon_crack_cmd_sc:
			out << "gm_dimension_dungeon_crack_cmd_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_dimension_dungeon_contribution_rank_reset_cs:
			out << "gm_api_dimension_dungeon_contribution_rank_reset_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_dimension_dungeon_contribution_rank_reset_sc:
			out << "gm_api_dimension_dungeon_contribution_rank_reset_sc"; 
			break;
		case mpe_rpc_cmd::gm_exchange_set_reg_latency_cs:
			out << "gm_exchange_set_reg_latency_cs"; 
			break;
		case mpe_rpc_cmd::gm_exchange_set_reg_latency_sc:
			out << "gm_exchange_set_reg_latency_sc"; 
			break;
		case mpe_rpc_cmd::gm_global_governance_command_cs:
			out << "gm_global_governance_command_cs"; 
			break;
		case mpe_rpc_cmd::gm_global_governance_command_sc:
			out << "gm_global_governance_command_sc"; 
			break;
		case mpe_rpc_cmd::gm_exchange_set_manual_latency_cs:
			out << "gm_exchange_set_manual_latency_cs"; 
			break;
		case mpe_rpc_cmd::gm_exchange_set_manual_latency_sc:
			out << "gm_exchange_set_manual_latency_sc"; 
			break;
		case mpe_rpc_cmd::gm_server_relocation_list_set_cs:
			out << "gm_server_relocation_list_set_cs"; 
			break;
		case mpe_rpc_cmd::gm_server_relocation_list_set_sc:
			out << "gm_server_relocation_list_set_sc"; 
			break;
		case mpe_rpc_cmd::gm_server_relocation_list_get_cs:
			out << "gm_server_relocation_list_get_cs"; 
			break;
		case mpe_rpc_cmd::gm_server_relocation_list_get_sc:
			out << "gm_server_relocation_list_get_sc"; 
			break;
		case mpe_rpc_cmd::gm_maintenance_set_cs:
			out << "gm_maintenance_set_cs"; 
			break;
		case mpe_rpc_cmd::gm_maintenance_set_sc:
			out << "gm_maintenance_set_sc"; 
			break;
		case mpe_rpc_cmd::gm_monster_spawn_cs:
			out << "gm_monster_spawn_cs"; 
			break;
		case mpe_rpc_cmd::gm_monster_spawn_sc:
			out << "gm_monster_spawn_sc"; 
			break;
		case mpe_rpc_cmd::gm_change_occupation_war_state_cs:
			out << "gm_change_occupation_war_state_cs"; 
			break;
		case mpe_rpc_cmd::gm_change_occupation_war_state_sc:
			out << "gm_change_occupation_war_state_sc"; 
			break;
		case mpe_rpc_cmd::gm_blood_dedicate_worldboss_cs:
			out << "gm_blood_dedicate_worldboss_cs"; 
			break;
		case mpe_rpc_cmd::gm_blood_dedicate_worldboss_sc:
			out << "gm_blood_dedicate_worldboss_sc"; 
			break;
		case mpe_rpc_cmd::gm_api_blood_dedicate_worldboss_spawn_cs:
			out << "gm_api_blood_dedicate_worldboss_spawn_cs"; 
			break;
		case mpe_rpc_cmd::gm_api_blood_dedicate_worldboss_spawn_sc:
			out << "gm_api_blood_dedicate_worldboss_spawn_sc"; 
			break;
		case mpe_rpc_cmd::gm_global_exchange_change_state_cs:
			out << "gm_global_exchange_change_state_cs"; 
			break;
		case mpe_rpc_cmd::gm_global_exchange_change_state_sc:
			out << "gm_global_exchange_change_state_sc"; 
			break;
		case mpe_rpc_cmd::gm_guild_ally_delete_cs:
			out << "gm_guild_ally_delete_cs"; 
			break;
		case mpe_rpc_cmd::gm_guild_ally_delete_sc:
			out << "gm_guild_ally_delete_sc"; 
			break;
		case mpe_rpc_cmd::gm_character_last_time_change_cs:
			out << "gm_character_last_time_change_cs"; 
			break;
		case mpe_rpc_cmd::gm_character_last_time_change_sc:
			out << "gm_character_last_time_change_sc"; 
			break;
		case mpe_rpc_cmd::build_tool_server_info_cs:
			out << "build_tool_server_info_cs"; 
			break;
		case mpe_rpc_cmd::build_tool_server_info_sc:
			out << "build_tool_server_info_sc"; 
			break;
		case mpe_rpc_cmd::build_tool_server_state_cs:
			out << "build_tool_server_state_cs"; 
			break;
		case mpe_rpc_cmd::build_tool_server_state_sc:
			out << "build_tool_server_state_sc"; 
			break;
		case mpe_rpc_cmd::build_tool_server_command_cs:
			out << "build_tool_server_command_cs"; 
			break;
		case mpe_rpc_cmd::build_tool_server_command_sc:
			out << "build_tool_server_command_sc"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_server_type& value)
	{
		switch (value)
		{
		case mrpce_server_type::none:
			out << "none"; 
			break;
		case mrpce_server_type::gmmanager:
			out << "gmmanager"; 
			break;
		case mrpce_server_type::gmserver:
			out << "gmserver"; 
			break;
		case mrpce_server_type::gmobserver:
			out << "gmobserver"; 
			break;
		case mrpce_server_type::login:
			out << "login"; 
			break;
		case mrpce_server_type::lobby:
			out << "lobby"; 
			break;
		case mrpce_server_type::board:
			out << "board"; 
			break;
		case mrpce_server_type::database:
			out << "database"; 
			break;
		case mrpce_server_type::exchange:
			out << "exchange"; 
			break;
		case mrpce_server_type::gamemanager:
			out << "gamemanager"; 
			break;
		case mrpce_server_type::guildmanager:
			out << "guildmanager"; 
			break;
		case mrpce_server_type::socialmanager:
			out << "socialmanager"; 
			break;
		case mrpce_server_type::contract:
			out << "contract"; 
			break;
		case mrpce_server_type::game:
			out << "game"; 
			break;
		case mrpce_server_type::indun:
			out << "indun"; 
			break;
		case mrpce_server_type::community:
			out << "community"; 
			break;
		case mrpce_server_type::gate:
			out << "gate"; 
			break;
		case mrpce_server_type::logreceive:
			out << "logreceive"; 
			break;
		case mrpce_server_type::world_board:
			out << "world_board"; 
			break;
		case mrpce_server_type::world_exchange:
			out << "world_exchange"; 
			break;
		case mrpce_server_type::world_game_manager:
			out << "world_game_manager"; 
			break;
		case mrpce_server_type::world_indun:
			out << "world_indun"; 
			break;
		case mrpce_server_type::world_game:
			out << "world_game"; 
			break;
		case mrpce_server_type::world_community:
			out << "world_community"; 
			break;
		case mrpce_server_type::global_board:
			out << "global_board"; 
			break;
		case mrpce_server_type::global_exchange:
			out << "global_exchange"; 
			break;
		case mrpce_server_type::global_gold_exchange:
			out << "global_gold_exchange"; 
			break;
		case mrpce_server_type::global_governance:
			out << "global_governance"; 
			break;
		case mrpce_server_type::global_web_server:
			out << "global_web_server"; 
			break;
		case mrpce_server_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_service_type& value)
	{
		switch (value)
		{
		case mrpce_service_type::none:
			out << "none"; 
			break;
		case mrpce_service_type::gm:
			out << "gm"; 
			break;
		case mrpce_service_type::web:
			out << "web"; 
			break;
		case mrpce_service_type::manager:
			out << "manager"; 
			break;
		case mrpce_service_type::game:
			out << "game"; 
			break;
		case mrpce_service_type::indun:
			out << "indun"; 
			break;
		case mrpce_service_type::count:
			out << "count"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_login_character_flag& value)
	{
		switch (value)
		{
		case mrpce_login_character_flag::create :
			out << "create "; 
			break;
		case mrpce_login_character_flag::select :
			out << "select "; 
			break;
		case mrpce_login_character_flag::levelup:
			out << "levelup"; 
			break;
		case mrpce_login_character_flag::del:
			out << "del"; 
			break;
		case mrpce_login_character_flag::logout:
			out << "logout"; 
			break;
		case mrpce_login_character_flag::enabled:
			out << "enabled"; 
			break;
		case mrpce_login_character_flag::enable_delete:
			out << "enable_delete"; 
			break;
		case mrpce_login_character_flag::expert_level:
			out << "expert_level"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_player_equipitem& value)
	{
		switch (value)
		{
		case mrpce_player_equipitem::weapon:
			out << "weapon"; 
			break;
		case mrpce_player_equipitem::armor :
			out << "armor "; 
			break;
		case mrpce_player_equipitem::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_character_autosave& value)
	{
		switch (value)
		{
		case mrpce_character_autosave::none:
			out << "none"; 
			break;
		case mrpce_character_autosave::zone:
			out << "zone"; 
			break;
		case mrpce_character_autosave::goods:
			out << "goods"; 
			break;
		case mrpce_character_autosave::skill:
			out << "skill"; 
			break;
		case mrpce_character_autosave::daily_content:
			out << "daily_content"; 
			break;
		case mrpce_character_autosave::quest:
			out << "quest"; 
			break;
		case mrpce_character_autosave::ticket_dungeon:
			out << "ticket_dungeon"; 
			break;
		case mrpce_character_autosave::item_durability:
			out << "item_durability"; 
			break;
		case mrpce_character_autosave::pet_flag:
			out << "pet_flag"; 
			break;
		case mrpce_character_autosave::special_move:
			out << "special_move"; 
			break;
		case mrpce_character_autosave::buff:
			out << "buff"; 
			break;
		case mrpce_character_autosave::vehicle:
			out << "vehicle"; 
			break;
		case mrpce_character_autosave::guild_dungeon_damage:
			out << "guild_dungeon_damage"; 
			break;
		case mrpce_character_autosave::character_power_ranking:
			out << "character_power_ranking"; 
			break;
		case mrpce_character_autosave::character_level_ranking:
			out << "character_level_ranking"; 
			break;
		case mrpce_character_autosave::profesion_ranking:
			out << "profesion_ranking"; 
			break;
		case mrpce_character_autosave::title:
			out << "title"; 
			break;
		case mrpce_character_autosave::auto_battle:
			out << "auto_battle"; 
			break;
		case mrpce_character_autosave::seasonpass_challenge:
			out << "seasonpass_challenge"; 
			break;
		case mrpce_character_autosave::cumulative_connection_time:
			out << "cumulative_connection_time"; 
			break;
		case mrpce_character_autosave::worship_point:
			out << "worship_point"; 
			break;
		case mrpce_character_autosave::illusion_dungeon:
			out << "illusion_dungeon"; 
			break;
		case mrpce_character_autosave::quest_accept_condition:
			out << "quest_accept_condition"; 
			break;
		case mrpce_character_autosave::exp:
			out << "exp"; 
			break;
		case mrpce_character_autosave::blood_stone:
			out << "blood_stone"; 
			break;
		case mrpce_character_autosave::blood_dedicate:
			out << "blood_dedicate"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_inven_expansion& value)
	{
		switch (value)
		{
		case mrpce_inven_expansion::slot:
			out << "slot"; 
			break;
		case mrpce_inven_expansion::weight:
			out << "weight"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_community_update_type& value)
	{
		switch (value)
		{
		case mrpce_community_update_type::server_type:
			out << "server_type"; 
			break;
		case mrpce_community_update_type::server_index:
			out << "server_index"; 
			break;
		case mrpce_community_update_type::level:
			out << "level"; 
			break;
		case mrpce_community_update_type::equip:
			out << "equip"; 
			break;
		case mrpce_community_update_type::power:
			out << "power"; 
			break;
		case mrpce_community_update_type::puid:
			out << "puid"; 
			break;
		case mrpce_community_update_type::connection:
			out << "connection"; 
			break;
		case mrpce_community_update_type::nickname:
			out << "nickname"; 
			break;
		case mrpce_community_update_type::guild_uid:
			out << "guild_uid"; 
			break;
		case mrpce_community_update_type::zone_id:
			out << "zone_id"; 
			break;
		case mrpce_community_update_type::prev_zone_change:
			out << "prev_zone_change"; 
			break;
		case mrpce_community_update_type::expert_level:
			out << "expert_level"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_guild_request_type& value)
	{
		switch (value)
		{
		case mrpce_guild_request_type::none:
			out << "none"; 
			break;
		case mrpce_guild_request_type::alert_start_war:
			out << "alert_start_war"; 
			break;
		case mrpce_guild_request_type::alert_end_war:
			out << "alert_end_war"; 
			break;
		case mrpce_guild_request_type::alert_reject_surrender:
			out << "alert_reject_surrender"; 
			break;
		case mrpce_guild_request_type::alert_surrender:
			out << "alert_surrender"; 
			break;
		case mrpce_guild_request_type::alert_join_request:
			out << "alert_join_request"; 
			break;
		case mrpce_guild_request_type::alert_siege_warfare_return_tender:
			out << "alert_siege_warfare_return_tender"; 
			break;
		case mrpce_guild_request_type::alert_siege_warfare_divide_tender:
			out << "alert_siege_warfare_divide_tender"; 
			break;
		case mrpce_guild_request_type::change_member_online_state:
			out << "change_member_online_state"; 
			break;
		case mrpce_guild_request_type::member_max_power_update:
			out << "member_max_power_update"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_guild_reset_type& value)
	{
		switch (value)
		{
		case mrpce_guild_reset_type::none:
			out << "none"; 
			break;
		case mrpce_guild_reset_type::donation_count_reset:
			out << "donation_count_reset"; 
			break;
		case mrpce_guild_reset_type::blackiron_donation_count_reset:
			out << "blackiron_donation_count_reset"; 
			break;
		case mrpce_guild_reset_type::goldingot_donation_count_reset:
			out << "goldingot_donation_count_reset"; 
			break;
		case mrpce_guild_reset_type::item_donation_count_reset:
			out << "item_donation_count_reset"; 
			break;
		case mrpce_guild_reset_type::quest_object_count_reset:
			out << "quest_object_count_reset"; 
			break;
		case mrpce_guild_reset_type::get_item_request_count_storage_share_reset:
			out << "get_item_request_count_storage_share_reset"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_game_event& value)
	{
		switch (value)
		{
		case mrpce_game_event::none:
			out << "none"; 
			break;
		case mrpce_game_event::repute_quest_reset:
			out << "repute_quest_reset"; 
			break;
		case mrpce_game_event::condition_reset:
			out << "condition_reset"; 
			break;
		case mrpce_game_event::siege_warfare_auction:
			out << "siege_warfare_auction"; 
			break;
		case mrpce_game_event::siege_warfare:
			out << "siege_warfare"; 
			break;
		case mrpce_game_event::area_quest_reset:
			out << "area_quest_reset"; 
			break;
		case mrpce_game_event::guild_quest_reset:
			out << "guild_quest_reset"; 
			break;
		case mrpce_game_event::wanted_murder_reset:
			out << "wanted_murder_reset"; 
			break;
		case mrpce_game_event::adult_lock_time:
			out << "adult_lock_time"; 
			break;
		case mrpce_game_event::adult_unlock_time:
			out << "adult_unlock_time"; 
			break;
		case mrpce_game_event::holiday_time:
			out << "holiday_time"; 
			break;
		case mrpce_game_event::boss_dungeon_time:
			out << "boss_dungeon_time"; 
			break;
		case mrpce_game_event::illusion_dungeon_time:
			out << "illusion_dungeon_time"; 
			break;
		case mrpce_game_event::monarch_dungeon_time:
			out << "monarch_dungeon_time"; 
			break;
		case mrpce_game_event::cash_shop_daily_reset_time:
			out << "cash_shop_daily_reset_time"; 
			break;
		case mrpce_game_event::guildshipwar_start_date:
			out << "guildshipwar_start_date"; 
			break;
		case mrpce_game_event::guildshipwar_match_date:
			out << "guildshipwar_match_date"; 
			break;
		case mrpce_game_event::guildshipwar_into_date:
			out << "guildshipwar_into_date"; 
			break;
		case mrpce_game_event::guildshipwar_start_war_time:
			out << "guildshipwar_start_war_time"; 
			break;
		case mrpce_game_event::guildshipwar_end_date:
			out << "guildshipwar_end_date"; 
			break;
		case mrpce_game_event::teasureboxkey_reset:
			out << "teasureboxkey_reset"; 
			break;
		case mrpce_game_event::castle_dungeon_reset_time:
			out << "castle_dungeon_reset_time"; 
			break;
		case mrpce_game_event::phantom_dungeon_reset_time:
			out << "phantom_dungeon_reset_time"; 
			break;
		case mrpce_game_event::seal_tower_reset_time:
			out << "seal_tower_reset_time"; 
			break;
		case mrpce_game_event::demon_tower_reset_time:
			out << "demon_tower_reset_time"; 
			break;
		case mrpce_game_event::quest_profession_reset_time:
			out << "quest_profession_reset_time"; 
			break;
		case mrpce_game_event::street_stall_count_reset_time:
			out << "street_stall_count_reset_time"; 
			break;
		case mrpce_game_event::cash_shop_exchange_reset_time:
			out << "cash_shop_exchange_reset_time"; 
			break;
		case mrpce_game_event::cash_shop_exchange_daily_reset_time:
			out << "cash_shop_exchange_daily_reset_time"; 
			break;
		case mrpce_game_event::unknown_dungeon_reset_time:
			out << "unknown_dungeon_reset_time"; 
			break;
		case mrpce_game_event::exp_restore_free_count_reset_time:
			out << "exp_restore_free_count_reset_time"; 
			break;
		case mrpce_game_event::trade_darksteelbox_to_token:
			out << "trade_darksteelbox_to_token"; 
			break;
		case mrpce_game_event::event_dungeon_reset_time:
			out << "event_dungeon_reset_time"; 
			break;
		case mrpce_game_event::advertisement_reset_time:
			out << "advertisement_reset_time"; 
			break;
		case mrpce_game_event::dimension_dungeon_reset_time:
			out << "dimension_dungeon_reset_time"; 
			break;
		case mrpce_game_event::cashshop_exchange_resettime_week:
			out << "cashshop_exchange_resettime_week"; 
			break;
		case mrpce_game_event::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_daily_event_reset_type& value)
	{
		switch (value)
		{
		case mrpce_daily_event_reset_type::none:
			out << "none"; 
			break;
		case mrpce_daily_event_reset_type::global_reset:
			out << "global_reset"; 
			break;
		case mrpce_daily_event_reset_type::local_reset:
			out << "local_reset"; 
			break;
		case mrpce_daily_event_reset_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_siege_warfare_battle_result& value)
	{
		switch (value)
		{
		case mrpce_siege_warfare_battle_result::defense_success:
			out << "defense_success"; 
			break;
		case mrpce_siege_warfare_battle_result::defense_fail:
			out << "defense_fail"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mgme_login_type& value)
	{
		switch (value)
		{
		case mgme_login_type::normal:
			out << "normal"; 
			break;
		case mgme_login_type::ldap:
			out << "ldap"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mgme_authority_type& value)
	{
		switch (value)
		{
		case mgme_authority_type::none:
			out << "none"; 
			break;
		case mgme_authority_type::server:
			out << "server"; 
			break;
		case mgme_authority_type::table:
			out << "table"; 
			break;
		case mgme_authority_type::gm:
			out << "gm"; 
			break;
		case mgme_authority_type::data:
			out << "data"; 
			break;
		case mgme_authority_type::statistics:
			out << "statistics"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mgme_patch_search_type& value)
	{
		switch (value)
		{
		case mgme_patch_search_type::week:
			out << "week"; 
			break;
		case mgme_patch_search_type::month:
			out << "month"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mgme_edit_type& value)
	{
		switch (value)
		{
		case mgme_edit_type::edit_insert:
			out << "edit_insert"; 
			break;
		case mgme_edit_type::edit_update:
			out << "edit_update"; 
			break;
		case mgme_edit_type::edit_delete:
			out << "edit_delete"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_server_state& value)
	{
		switch (value)
		{
		case mrpce_server_state::under_maintenance:
			out << "under_maintenance"; 
			break;
		case mrpce_server_state::free:
			out << "free"; 
			break;
		case mrpce_server_state::busy:
			out << "busy"; 
			break;
		case mrpce_server_state::full:
			out << "full"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_guild_add_exp_type& value)
	{
		switch (value)
		{
		case mrpce_guild_add_exp_type::guild_exp_item:
			out << "guild_exp_item"; 
			break;
		case mrpce_guild_add_exp_type::guild_dungeon:
			out << "guild_dungeon"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_server_control_type& value)
	{
		switch (value)
		{
		case mrpce_server_control_type::stop:
			out << "stop"; 
			break;
		case mrpce_server_control_type::stop_now:
			out << "stop_now"; 
			break;
		case mrpce_server_control_type::stopall:
			out << "stopall"; 
			break;
		case mrpce_server_control_type::start:
			out << "start"; 
			break;
		case mrpce_server_control_type::restart:
			out << "restart"; 
			break;
		case mrpce_server_control_type::restartall:
			out << "restartall"; 
			break;
		case mrpce_server_control_type::reboot:
			out << "reboot"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_gm_notice_type& value)
	{
		switch (value)
		{
		case mrpce_gm_notice_type::none:
			out << "none"; 
			break;
		case mrpce_gm_notice_type::inspection_60sec:
			out << "inspection_60sec"; 
			break;
		case mrpce_gm_notice_type::inspection_30sec:
			out << "inspection_30sec"; 
			break;
		case mrpce_gm_notice_type::inspection_10sec:
			out << "inspection_10sec"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_title_send_type& value)
	{
		switch (value)
		{
		case mrpce_title_send_type::none:
			out << "none"; 
			break;
		case mrpce_title_send_type::database:
			out << "database"; 
			break;
		case mrpce_title_send_type::all:
			out << "all"; 
			break;
		case mrpce_title_send_type::autosave:
			out << "autosave"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_group_type& value)
	{
		switch (value)
		{
		case mrpce_group_type::single_5:
			out << "single_5"; 
			break;
		case mrpce_group_type::single_15:
			out << "single_15"; 
			break;
		case mrpce_group_type::party_5:
			out << "party_5"; 
			break;
		case mrpce_group_type::party_15:
			out << "party_15"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_mail_check_type& value)
	{
		switch (value)
		{
		case mrpce_mail_check_type::receive_item_check:
			out << "receive_item_check"; 
			break;
		case mrpce_mail_check_type::delete_check:
			out << "delete_check"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_gm_remove_quest_info_type& value)
	{
		switch (value)
		{
		case mrpce_gm_remove_quest_info_type::empty:
			out << "empty"; 
			break;
		case mrpce_gm_remove_quest_info_type::main_quest:
			out << "main_quest"; 
			break;
		case mrpce_gm_remove_quest_info_type::other_quest:
			out << "other_quest"; 
			break;
		case mrpce_gm_remove_quest_info_type::repute:
			out << "repute"; 
			break;
		case mrpce_gm_remove_quest_info_type::area:
			out << "area"; 
			break;
		case mrpce_gm_remove_quest_info_type::guild:
			out << "guild"; 
			break;
		case mrpce_gm_remove_quest_info_type::guild_office:
			out << "guild_office"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_league_match_state& value)
	{
		switch (value)
		{
		case mrpce_league_match_state::request:
			out << "request"; 
			break;
		case mrpce_league_match_state::match:
			out << "match"; 
			break;
		case mrpce_league_match_state::wait:
			out << "wait"; 
			break;
		case mrpce_league_match_state::complete:
			out << "complete"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_actionlog& value)
	{
		switch (value)
		{
		case mpe_actionlog::none:
			out << "none"; 
			break;
		case mpe_actionlog::server_start:
			out << "server_start"; 
			break;
		case mpe_actionlog::server_shut_down:
			out << "server_shut_down"; 
			break;
		case mpe_actionlog::abnormal_server_shut_down:
			out << "abnormal_server_shut_down"; 
			break;
		case mpe_actionlog::concurrently_user_count:
			out << "concurrently_user_count"; 
			break;
		case mpe_actionlog::queue_happen:
			out << "queue_happen"; 
			break;
		case mpe_actionlog::create_account:
			out << "create_account"; 
			break;
		case mpe_actionlog::connect_account:
			out << "connect_account"; 
			break;
		case mpe_actionlog::disconnect_account:
			out << "disconnect_account"; 
			break;
		case mpe_actionlog::account_select_server:
			out << "account_select_server"; 
			break;
		case mpe_actionlog::create_character:
			out << "create_character"; 
			break;
		case mpe_actionlog::delete_character:
			out << "delete_character"; 
			break;
		case mpe_actionlog::delete_character_cancel:
			out << "delete_character_cancel"; 
			break;
		case mpe_actionlog::connect_character:
			out << "connect_character"; 
			break;
		case mpe_actionlog::logout_character:
			out << "logout_character"; 
			break;
		case mpe_actionlog::invalid_packet:
			out << "invalid_packet"; 
			break;
		case mpe_actionlog::bad_client:
			out << "bad_client"; 
			break;
		case mpe_actionlog::change_nickname:
			out << "change_nickname"; 
			break;
		case mpe_actionlog::character_level_up:
			out << "character_level_up"; 
			break;
		case mpe_actionlog::add_exp:
			out << "add_exp"; 
			break;
		case mpe_actionlog::decrease_exp:
			out << "decrease_exp"; 
			break;
		case mpe_actionlog::character_expert_level_up:
			out << "character_expert_level_up"; 
			break;
		case mpe_actionlog::add_expert_exp:
			out << "add_expert_exp"; 
			break;
		case mpe_actionlog::character_dead:
			out << "character_dead"; 
			break;
		case mpe_actionlog::character_revive:
			out << "character_revive"; 
			break;
		case mpe_actionlog::skill_force_level_up:
			out << "skill_force_level_up"; 
			break;
		case mpe_actionlog::skill_learn:
			out << "skill_learn"; 
			break;
		case mpe_actionlog::skill_level_up:
			out << "skill_level_up"; 
			break;
		case mpe_actionlog::mandala_activation:
			out << "mandala_activation"; 
			break;
		case mpe_actionlog::mandala_level_up:
			out << "mandala_level_up"; 
			break;
		case mpe_actionlog::mandala_initialization:
			out << "mandala_initialization"; 
			break;
		case mpe_actionlog::mandala_rotation:
			out << "mandala_rotation"; 
			break;
		case mpe_actionlog::mandala_fail:
			out << "mandala_fail"; 
			break;
		case mpe_actionlog::mandala_activation_fail:
			out << "mandala_activation_fail"; 
			break;
		case mpe_actionlog::mandala_node_initialization:
			out << "mandala_node_initialization"; 
			break;
		case mpe_actionlog::season_mandala_character_reward:
			out << "season_mandala_character_reward"; 
			break;
		case mpe_actionlog::season_mandala_season_info:
			out << "season_mandala_season_info"; 
			break;
		case mpe_actionlog::character_pk:
			out << "character_pk"; 
			break;
		case mpe_actionlog::character_pk_decrese:
			out << "character_pk_decrese"; 
			break;
		case mpe_actionlog::character_pk_mode_change:
			out << "character_pk_mode_change"; 
			break;
		case mpe_actionlog::character_buy_guard_pass:
			out << "character_buy_guard_pass"; 
			break;
		case mpe_actionlog::wantedmurder_registration:
			out << "wantedmurder_registration"; 
			break;
		case mpe_actionlog::wantedmurder_acquire:
			out << "wantedmurder_acquire"; 
			break;
		case mpe_actionlog::wantedmurder_reg_cancel:
			out << "wantedmurder_reg_cancel"; 
			break;
		case mpe_actionlog::wantedmurder_reward:
			out << "wantedmurder_reward"; 
			break;
		case mpe_actionlog::wantedmurder_kill:
			out << "wantedmurder_kill"; 
			break;
		case mpe_actionlog::dictionary_reg:
			out << "dictionary_reg"; 
			break;
		case mpe_actionlog::dictionary_achievement:
			out << "dictionary_achievement"; 
			break;
		case mpe_actionlog::collection_reg:
			out << "collection_reg"; 
			break;
		case mpe_actionlog::collection_complet:
			out << "collection_complet"; 
			break;
		case mpe_actionlog::dictionary_monster_reg:
			out << "dictionary_monster_reg"; 
			break;
		case mpe_actionlog::dictionary_monster_complet:
			out << "dictionary_monster_complet"; 
			break;
		case mpe_actionlog::profesion_level_up:
			out << "profesion_level_up"; 
			break;
		case mpe_actionlog::profesion_add_exp:
			out << "profesion_add_exp"; 
			break;
		case mpe_actionlog::profesion_advancement:
			out << "profesion_advancement"; 
			break;
		case mpe_actionlog::achieve_add:
			out << "achieve_add"; 
			break;
		case mpe_actionlog::achieve_reward:
			out << "achieve_reward"; 
			break;
		case mpe_actionlog::title_equip:
			out << "title_equip"; 
			break;
		case mpe_actionlog::title_release:
			out << "title_release"; 
			break;
		case mpe_actionlog::title_add:
			out << "title_add"; 
			break;
		case mpe_actionlog::monarch_timespace_select:
			out << "monarch_timespace_select"; 
			break;
		case mpe_actionlog::monarch_timespace_fill:
			out << "monarch_timespace_fill"; 
			break;
		case mpe_actionlog::expert_run:
			out << "expert_run"; 
			break;
		case mpe_actionlog::expert_equipment_unlock:
			out << "expert_equipment_unlock"; 
			break;
		case mpe_actionlog::expert_equipment_reinforce_success:
			out << "expert_equipment_reinforce_success"; 
			break;
		case mpe_actionlog::expert_equipment_reinforce_fail:
			out << "expert_equipment_reinforce_fail"; 
			break;
		case mpe_actionlog::character_goods_increase:
			out << "character_goods_increase"; 
			break;
		case mpe_actionlog::character_goods_decrease:
			out << "character_goods_decrease"; 
			break;
		case mpe_actionlog::guild_goods_increase:
			out << "guild_goods_increase"; 
			break;
		case mpe_actionlog::guild_goods_decrease:
			out << "guild_goods_decrease"; 
			break;
		case mpe_actionlog::guild_item_add:
			out << "guild_item_add"; 
			break;
		case mpe_actionlog::guild_item_use:
			out << "guild_item_use"; 
			break;
		case mpe_actionlog::darksteel_storage_darksteel_inc:
			out << "darksteel_storage_darksteel_inc"; 
			break;
		case mpe_actionlog::darksteel_storage_darksteel_dec:
			out << "darksteel_storage_darksteel_dec"; 
			break;
		case mpe_actionlog::blood_dedicate_process_complete:
			out << "blood_dedicate_process_complete"; 
			break;
		case mpe_actionlog::item_add:
			out << "item_add"; 
			break;
		case mpe_actionlog::item_use:
			out << "item_use"; 
			break;
		case mpe_actionlog::item_buy:
			out << "item_buy"; 
			break;
		case mpe_actionlog::item_sell:
			out << "item_sell"; 
			break;
		case mpe_actionlog::item_delete:
			out << "item_delete"; 
			break;
		case mpe_actionlog::item_decomposition:
			out << "item_decomposition"; 
			break;
		case mpe_actionlog::item_repair:
			out << "item_repair"; 
			break;
		case mpe_actionlog::character_subscription_item_use:
			out << "character_subscription_item_use"; 
			break;
		case mpe_actionlog::item_reinforce:
			out << "item_reinforce"; 
			break;
		case mpe_actionlog::item_reinforce_fail:
			out << "item_reinforce_fail"; 
			break;
		case mpe_actionlog::item_echance_apply:
			out << "item_echance_apply"; 
			break;
		case mpe_actionlog::item_luck_reinforce:
			out << "item_luck_reinforce"; 
			break;
		case mpe_actionlog::item_luck_reinforce_fail:
			out << "item_luck_reinforce_fail"; 
			break;
		case mpe_actionlog::item_reinforce_fail_destruction:
			out << "item_reinforce_fail_destruction"; 
			break;
		case mpe_actionlog::enchant_stone_equip:
			out << "enchant_stone_equip"; 
			break;
		case mpe_actionlog::enchant_stone_unequip:
			out << "enchant_stone_unequip"; 
			break;
		case mpe_actionlog::item_make_success:
			out << "item_make_success"; 
			break;
		case mpe_actionlog::item_make_great_success:
			out << "item_make_great_success"; 
			break;
		case mpe_actionlog::item_make_failed:
			out << "item_make_failed"; 
			break;
		case mpe_actionlog::pet_mix:
			out << "pet_mix"; 
			break;
		case mpe_actionlog::reflection_mix:
			out << "reflection_mix"; 
			break;
		case mpe_actionlog::enchantstone_mix:
			out << "enchantstone_mix"; 
			break;
		case mpe_actionlog::reflection_get:
			out << "reflection_get"; 
			break;
		case mpe_actionlog::pet_get:
			out << "pet_get"; 
			break;
		case mpe_actionlog::vehicle_get:
			out << "vehicle_get"; 
			break;
		case mpe_actionlog::expert_equipment_equip:
			out << "expert_equipment_equip"; 
			break;
		case mpe_actionlog::expert_equipment_unequip:
			out << "expert_equipment_unequip"; 
			break;
		case mpe_actionlog::equipment_awaken:
			out << "equipment_awaken"; 
			break;
		case mpe_actionlog::guild_join_request:
			out << "guild_join_request"; 
			break;
		case mpe_actionlog::guild_join_request_cancel:
			out << "guild_join_request_cancel"; 
			break;
		case mpe_actionlog::guild_join_request_accept:
			out << "guild_join_request_accept"; 
			break;
		case mpe_actionlog::guild_join_request_refusal:
			out << "guild_join_request_refusal"; 
			break;
		case mpe_actionlog::guild_change_grade:
			out << "guild_change_grade"; 
			break;
		case mpe_actionlog::guild_withdrawal:
			out << "guild_withdrawal"; 
			break;
		case mpe_actionlog::guild_ban:
			out << "guild_ban"; 
			break;
		case mpe_actionlog::guild_disperse:
			out << "guild_disperse"; 
			break;
		case mpe_actionlog::guild_create:
			out << "guild_create"; 
			break;
		case mpe_actionlog::guild_donation:
			out << "guild_donation"; 
			break;
		case mpe_actionlog::guild_item_donation:
			out << "guild_item_donation"; 
			break;
		case mpe_actionlog::guild_join:
			out << "guild_join"; 
			break;
		case mpe_actionlog::guild_invite:
			out << "guild_invite"; 
			break;
		case mpe_actionlog::guild_invite_refusal:
			out << "guild_invite_refusal"; 
			break;
		case mpe_actionlog::guild_war_declare:
			out << "guild_war_declare"; 
			break;
		case mpe_actionlog::guild_war_surrender_request:
			out << "guild_war_surrender_request"; 
			break;
		case mpe_actionlog::guild_war_surrender_accept:
			out << "guild_war_surrender_accept"; 
			break;
		case mpe_actionlog::guild_war_surrender_refusal:
			out << "guild_war_surrender_refusal"; 
			break;
		case mpe_actionlog::guild_add_exp:
			out << "guild_add_exp"; 
			break;
		case mpe_actionlog::guild_level_up:
			out << "guild_level_up"; 
			break;
		case mpe_actionlog::guild_contribution_increse:
			out << "guild_contribution_increse"; 
			break;
		case mpe_actionlog::guild_skill_learn:
			out << "guild_skill_learn"; 
			break;
		case mpe_actionlog::guild_skill_level_up:
			out << "guild_skill_level_up"; 
			break;
		case mpe_actionlog::guild_shop_buy:
			out << "guild_shop_buy"; 
			break;
		case mpe_actionlog::guild_warehouse_share_request:
			out << "guild_warehouse_share_request"; 
			break;
		case mpe_actionlog::guild_warehouse_share_accept:
			out << "guild_warehouse_share_accept"; 
			break;
		case mpe_actionlog::guild_warehouse_share_refusal:
			out << "guild_warehouse_share_refusal"; 
			break;
		case mpe_actionlog::guild_treasure_auction_bidding:
			out << "guild_treasure_auction_bidding"; 
			break;
		case mpe_actionlog::guild_treasure_auction_successful_bid:
			out << "guild_treasure_auction_successful_bid"; 
			break;
		case mpe_actionlog::guild_treasure_auction_failure:
			out << "guild_treasure_auction_failure"; 
			break;
		case mpe_actionlog::town_rental:
			out << "town_rental"; 
			break;
		case mpe_actionlog::town_rental_end:
			out << "town_rental_end"; 
			break;
		case mpe_actionlog::town_rental_extension:
			out << "town_rental_extension"; 
			break;
		case mpe_actionlog::town_return:
			out << "town_return"; 
			break;
		case mpe_actionlog::secretvalley_start:
			out << "secretvalley_start"; 
			break;
		case mpe_actionlog::secretvalley_end:
			out << "secretvalley_end"; 
			break;
		case mpe_actionlog::secretvalley_tower_destroy:
			out << "secretvalley_tower_destroy"; 
			break;
		case mpe_actionlog::secretvalley_tower_owner_change:
			out << "secretvalley_tower_owner_change"; 
			break;
		case mpe_actionlog::occupationwar_tender_deposit:
			out << "occupationwar_tender_deposit"; 
			break;
		case mpe_actionlog::occupationwar_tender_withdraw:
			out << "occupationwar_tender_withdraw"; 
			break;
		case mpe_actionlog::occupationwar_tender_successful:
			out << "occupationwar_tender_successful"; 
			break;
		case mpe_actionlog::occupationwar_challenge_request:
			out << "occupationwar_challenge_request"; 
			break;
		case mpe_actionlog::occupationwar_challenge_cancel:
			out << "occupationwar_challenge_cancel"; 
			break;
		case mpe_actionlog::occupationwar_war_finish:
			out << "occupationwar_war_finish"; 
			break;
		case mpe_actionlog::darksteel_storage_darksteel_tax_pay:
			out << "darksteel_storage_darksteel_tax_pay"; 
			break;
		case mpe_actionlog::darksteel_storage_darksteel_pay_character:
			out << "darksteel_storage_darksteel_pay_character"; 
			break;
		case mpe_actionlog::darksteel_storage_darksteel_pay_giuld:
			out << "darksteel_storage_darksteel_pay_giuld"; 
			break;
		case mpe_actionlog::darksteel_storage_darksteel_pay_penalty:
			out << "darksteel_storage_darksteel_pay_penalty"; 
			break;
		case mpe_actionlog::siege_bidding:
			out << "siege_bidding"; 
			break;
		case mpe_actionlog::siege_successful_bid:
			out << "siege_successful_bid"; 
			break;
		case mpe_actionlog::siege_action_end:
			out << "siege_action_end"; 
			break;
		case mpe_actionlog::siege_enter:
			out << "siege_enter"; 
			break;
		case mpe_actionlog::siege_watch:
			out << "siege_watch"; 
			break;
		case mpe_actionlog::siege_weapon_installation:
			out << "siege_weapon_installation"; 
			break;
		case mpe_actionlog::siege_weapon_destroy:
			out << "siege_weapon_destroy"; 
			break;
		case mpe_actionlog::siege_win:
			out << "siege_win"; 
			break;
		case mpe_actionlog::siege_lose:
			out << "siege_lose"; 
			break;
		case mpe_actionlog::shipwar_request:
			out << "shipwar_request"; 
			break;
		case mpe_actionlog::shipwar_request_cancel:
			out << "shipwar_request_cancel"; 
			break;
		case mpe_actionlog::shipwar_match_success:
			out << "shipwar_match_success"; 
			break;
		case mpe_actionlog::shipwar_match_failed:
			out << "shipwar_match_failed"; 
			break;
		case mpe_actionlog::shipwar_flag_destroy:
			out << "shipwar_flag_destroy"; 
			break;
		case mpe_actionlog::shipwar_win:
			out << "shipwar_win"; 
			break;
		case mpe_actionlog::shipwar_lose:
			out << "shipwar_lose"; 
			break;
		case mpe_actionlog::shipwar_enter:
			out << "shipwar_enter"; 
			break;
		case mpe_actionlog::shipwar_exit:
			out << "shipwar_exit"; 
			break;
		case mpe_actionlog::shipwar_unearned_win:
			out << "shipwar_unearned_win"; 
			break;
		case mpe_actionlog::siege_tax_change:
			out << "siege_tax_change"; 
			break;
		case mpe_actionlog::siege_dungeon_enter_fees_change:
			out << "siege_dungeon_enter_fees_change"; 
			break;
		case mpe_actionlog::bless_activation:
			out << "bless_activation"; 
			break;
		case mpe_actionlog::blackiron_sell_start:
			out << "blackiron_sell_start"; 
			break;
		case mpe_actionlog::blackiron_sell_end:
			out << "blackiron_sell_end"; 
			break;
		case mpe_actionlog::town_npc_employment:
			out << "town_npc_employment"; 
			break;
		case mpe_actionlog::town_npc_intimacy_increse:
			out << "town_npc_intimacy_increse"; 
			break;
		case mpe_actionlog::town_npc_dismissal:
			out << "town_npc_dismissal"; 
			break;
		case mpe_actionlog::guild_dungeon_create:
			out << "guild_dungeon_create"; 
			break;
		case mpe_actionlog::party_create:
			out << "party_create"; 
			break;
		case mpe_actionlog::party_join:
			out << "party_join"; 
			break;
		case mpe_actionlog::party_withdrawal:
			out << "party_withdrawal"; 
			break;
		case mpe_actionlog::party_ban:
			out << "party_ban"; 
			break;
		case mpe_actionlog::party_owner_change:
			out << "party_owner_change"; 
			break;
		case mpe_actionlog::party_invite:
			out << "party_invite"; 
			break;
		case mpe_actionlog::party_invite_accept:
			out << "party_invite_accept"; 
			break;
		case mpe_actionlog::party_invite_refusal:
			out << "party_invite_refusal"; 
			break;
		case mpe_actionlog::friend_request:
			out << "friend_request"; 
			break;
		case mpe_actionlog::friend_add:
			out << "friend_add"; 
			break;
		case mpe_actionlog::friend_del:
			out << "friend_del"; 
			break;
		case mpe_actionlog::frend_refusal:
			out << "frend_refusal"; 
			break;
		case mpe_actionlog::mentor_request:
			out << "mentor_request"; 
			break;
		case mpe_actionlog::mentor_accept:
			out << "mentor_accept"; 
			break;
		case mpe_actionlog::mentor_refusal:
			out << "mentor_refusal"; 
			break;
		case mpe_actionlog::mentor_terminate:
			out << "mentor_terminate"; 
			break;
		case mpe_actionlog::mentor_registration:
			out << "mentor_registration"; 
			break;
		case mpe_actionlog::mentor_request_cancel:
			out << "mentor_request_cancel"; 
			break;
		case mpe_actionlog::mentor_buff_buy:
			out << "mentor_buff_buy"; 
			break;
		case mpe_actionlog::street_stall_start:
			out << "street_stall_start"; 
			break;
		case mpe_actionlog::street_stall_end:
			out << "street_stall_end"; 
			break;
		case mpe_actionlog::street_stall_cancel:
			out << "street_stall_cancel"; 
			break;
		case mpe_actionlog::street_stall_unmanned:
			out << "street_stall_unmanned"; 
			break;
		case mpe_actionlog::street_stall_buy:
			out << "street_stall_buy"; 
			break;
		case mpe_actionlog::street_stall_fees:
			out << "street_stall_fees"; 
			break;
		case mpe_actionlog::zone_enter:
			out << "zone_enter"; 
			break;
		case mpe_actionlog::zone_leave:
			out << "zone_leave"; 
			break;
		case mpe_actionlog::quest_accept:
			out << "quest_accept"; 
			break;
		case mpe_actionlog::quest_giveup:
			out << "quest_giveup"; 
			break;
		case mpe_actionlog::quest_clear:
			out << "quest_clear"; 
			break;
		case mpe_actionlog::quest_failed:
			out << "quest_failed"; 
			break;
		case mpe_actionlog::dungeon_clear:
			out << "dungeon_clear"; 
			break;
		case mpe_actionlog::dungeon_failed:
			out << "dungeon_failed"; 
			break;
		case mpe_actionlog::dungeon_boss_kill:
			out << "dungeon_boss_kill"; 
			break;
		case mpe_actionlog::illusion_time_chage:
			out << "illusion_time_chage"; 
			break;
		case mpe_actionlog::monarch_spawn:
			out << "monarch_spawn"; 
			break;
		case mpe_actionlog::indun_enter:
			out << "indun_enter"; 
			break;
		case mpe_actionlog::indun_leave:
			out << "indun_leave"; 
			break;
		case mpe_actionlog::npc_intimacy_increse:
			out << "npc_intimacy_increse"; 
			break;
		case mpe_actionlog::mirpass_challenge_complete:
			out << "mirpass_challenge_complete"; 
			break;
		case mpe_actionlog::mirpass_buy:
			out << "mirpass_buy"; 
			break;
		case mpe_actionlog::mirpass_waiting_time_clear:
			out << "mirpass_waiting_time_clear"; 
			break;
		case mpe_actionlog::mirpass_challenge_add:
			out << "mirpass_challenge_add"; 
			break;
		case mpe_actionlog::boss_respawn:
			out << "boss_respawn"; 
			break;
		case mpe_actionlog::boss_dead:
			out << "boss_dead"; 
			break;
		case mpe_actionlog::boss_run:
			out << "boss_run"; 
			break;
		case mpe_actionlog::worship_try:
			out << "worship_try"; 
			break;
		case mpe_actionlog::worship_failed:
			out << "worship_failed"; 
			break;
		case mpe_actionlog::worship_character_reward:
			out << "worship_character_reward"; 
			break;
		case mpe_actionlog::worship_world_reward:
			out << "worship_world_reward"; 
			break;
		case mpe_actionlog::secretvalley_request:
			out << "secretvalley_request"; 
			break;
		case mpe_actionlog::secretvalley_request_cancel:
			out << "secretvalley_request_cancel"; 
			break;
		case mpe_actionlog::secretvalley_matching_success:
			out << "secretvalley_matching_success"; 
			break;
		case mpe_actionlog::secretvalley_matching_failed:
			out << "secretvalley_matching_failed"; 
			break;
		case mpe_actionlog::secretvalley_win:
			out << "secretvalley_win"; 
			break;
		case mpe_actionlog::secretvalley_lose:
			out << "secretvalley_lose"; 
			break;
		case mpe_actionlog::damage:
			out << "damage"; 
			break;
		case mpe_actionlog::shot:
			out << "shot"; 
			break;
		case mpe_actionlog::recovery:
			out << "recovery"; 
			break;
		case mpe_actionlog::save_area_add:
			out << "save_area_add"; 
			break;
		case mpe_actionlog::save_area_delete:
			out << "save_area_delete"; 
			break;
		case mpe_actionlog::view_point_active:
			out << "view_point_active"; 
			break;
		case mpe_actionlog::relocate_server_success:
			out << "relocate_server_success"; 
			break;
		case mpe_actionlog::relocate_server_fail:
			out << "relocate_server_fail"; 
			break;
		case mpe_actionlog::mail_select:
			out << "mail_select"; 
			break;
		case mpe_actionlog::mail_open:
			out << "mail_open"; 
			break;
		case mpe_actionlog::mail_delete:
			out << "mail_delete"; 
			break;
		case mpe_actionlog::mail_item_receive:
			out << "mail_item_receive"; 
			break;
		case mpe_actionlog::mail_send:
			out << "mail_send"; 
			break;
		case mpe_actionlog::event_achievement:
			out << "event_achievement"; 
			break;
		case mpe_actionlog::event_reward:
			out << "event_reward"; 
			break;
		case mpe_actionlog::cheat_use:
			out << "cheat_use"; 
			break;
		case mpe_actionlog::ad_verify:
			out << "ad_verify"; 
			break;
		case mpe_actionlog::ad_end:
			out << "ad_end"; 
			break;
		case mpe_actionlog::try_captcha:
			out << "try_captcha"; 
			break;
		case mpe_actionlog::succeed_captcha:
			out << "succeed_captcha"; 
			break;
		case mpe_actionlog::fail_captcha:
			out << "fail_captcha"; 
			break;
		case mpe_actionlog::ranking_calculation:
			out << "ranking_calculation"; 
			break;
		case mpe_actionlog::pay_try:
			out << "pay_try"; 
			break;
		case mpe_actionlog::pay_receipt_check:
			out << "pay_receipt_check"; 
			break;
		case mpe_actionlog::pay_result:
			out << "pay_result"; 
			break;
		case mpe_actionlog::pay_failed:
			out << "pay_failed"; 
			break;
		case mpe_actionlog::cash_shop_buy:
			out << "cash_shop_buy"; 
			break;
		case mpe_actionlog::cash_buy_success:
			out << "cash_buy_success"; 
			break;
		case mpe_actionlog::cash_buy_failed:
			out << "cash_buy_failed"; 
			break;
		case mpe_actionlog::coin_change:
			out << "coin_change"; 
			break;
		case mpe_actionlog::cash_shop_cart_get:
			out << "cash_shop_cart_get"; 
			break;
		case mpe_actionlog::gm_cash_shop_cart_del:
			out << "gm_cash_shop_cart_del"; 
			break;
		case mpe_actionlog::cash_shop_cart_set:
			out << "cash_shop_cart_set"; 
			break;
		case mpe_actionlog::exchange_reg:
			out << "exchange_reg"; 
			break;
		case mpe_actionlog::exchange_reg_cancel:
			out << "exchange_reg_cancel"; 
			break;
		case mpe_actionlog::exchange_calculate:
			out << "exchange_calculate"; 
			break;
		case mpe_actionlog::exchange_buy:
			out << "exchange_buy"; 
			break;
		case mpe_actionlog::exchange_item_receive:
			out << "exchange_item_receive"; 
			break;
		case mpe_actionlog::exchange_buyitem_expire:
			out << "exchange_buyitem_expire"; 
			break;
		case mpe_actionlog::exchange_buyitem_system:
			out << "exchange_buyitem_system"; 
			break;
		case mpe_actionlog::world_exchange_reg:
			out << "world_exchange_reg"; 
			break;
		case mpe_actionlog::world_exchange_reg_cancel:
			out << "world_exchange_reg_cancel"; 
			break;
		case mpe_actionlog::world_exchange_calculate:
			out << "world_exchange_calculate"; 
			break;
		case mpe_actionlog::world_exchange_buy:
			out << "world_exchange_buy"; 
			break;
		case mpe_actionlog::world_exchange_item_receive:
			out << "world_exchange_item_receive"; 
			break;
		case mpe_actionlog::world_exchange_buyitem_expire:
			out << "world_exchange_buyitem_expire"; 
			break;
		case mpe_actionlog::global_exchange_reg:
			out << "global_exchange_reg"; 
			break;
		case mpe_actionlog::global_exchange_reg_cancel:
			out << "global_exchange_reg_cancel"; 
			break;
		case mpe_actionlog::global_exchange_calculate_try:
			out << "global_exchange_calculate_try"; 
			break;
		case mpe_actionlog::global_exchange_calculate_failed:
			out << "global_exchange_calculate_failed"; 
			break;
		case mpe_actionlog::global_exchange_calculate_success:
			out << "global_exchange_calculate_success"; 
			break;
		case mpe_actionlog::global_exchange_buy_try:
			out << "global_exchange_buy_try"; 
			break;
		case mpe_actionlog::global_exchange_buy_failed:
			out << "global_exchange_buy_failed"; 
			break;
		case mpe_actionlog::global_exchange_buy_success:
			out << "global_exchange_buy_success"; 
			break;
		case mpe_actionlog::global_exchange_item_receive:
			out << "global_exchange_item_receive"; 
			break;
		case mpe_actionlog::global_exchange_buyitem_expire:
			out << "global_exchange_buyitem_expire"; 
			break;
		case mpe_actionlog::wemix_wallet_login:
			out << "wemix_wallet_login"; 
			break;
		case mpe_actionlog::wemix_wallet_linked:
			out << "wemix_wallet_linked"; 
			break;
		case mpe_actionlog::divine_staking_try:
			out << "divine_staking_try"; 
			break;
		case mpe_actionlog::divine_staking_failed:
			out << "divine_staking_failed"; 
			break;
		case mpe_actionlog::divine_staking_success:
			out << "divine_staking_success"; 
			break;
		case mpe_actionlog::divine_compensation_claim:
			out << "divine_compensation_claim"; 
			break;
		case mpe_actionlog::divine_compensation_fail:
			out << "divine_compensation_fail"; 
			break;
		case mpe_actionlog::divine_compensation_pre:
			out << "divine_compensation_pre"; 
			break;
		case mpe_actionlog::divine_staking_compensation:
			out << "divine_staking_compensation"; 
			break;
		case mpe_actionlog::governance_staking_occupationwar_try:
			out << "governance_staking_occupationwar_try"; 
			break;
		case mpe_actionlog::governance_staking_occupationwar_failed:
			out << "governance_staking_occupationwar_failed"; 
			break;
		case mpe_actionlog::governance_staking_occupationwar_success:
			out << "governance_staking_occupationwar_success"; 
			break;
		case mpe_actionlog::governance_unstaking_occupationwar_try:
			out << "governance_unstaking_occupationwar_try"; 
			break;
		case mpe_actionlog::governance_unstaking_occupationwar_failed:
			out << "governance_unstaking_occupationwar_failed"; 
			break;
		case mpe_actionlog::governance_unstaking_occupationwar_success:
			out << "governance_unstaking_occupationwar_success"; 
			break;
		case mpe_actionlog::governance_staking_boss_try:
			out << "governance_staking_boss_try"; 
			break;
		case mpe_actionlog::governance_staking_boss_failed:
			out << "governance_staking_boss_failed"; 
			break;
		case mpe_actionlog::governance_staking_boss_success:
			out << "governance_staking_boss_success"; 
			break;
		case mpe_actionlog::governance_unstaking_boss_try:
			out << "governance_unstaking_boss_try"; 
			break;
		case mpe_actionlog::governance_unstaking_boss_failed:
			out << "governance_unstaking_boss_failed"; 
			break;
		case mpe_actionlog::governance_unstaking_boss_success:
			out << "governance_unstaking_boss_success"; 
			break;
		case mpe_actionlog::smelt_darksteelbox_to_drone_try:
			out << "smelt_darksteelbox_to_drone_try"; 
			break;
		case mpe_actionlog::smelt_darksteelbox_to_drone_failed:
			out << "smelt_darksteelbox_to_drone_failed"; 
			break;
		case mpe_actionlog::smelt_darksteelbox_to_drone_success:
			out << "smelt_darksteelbox_to_drone_success"; 
			break;
		case mpe_actionlog::smelt_drone_to_darksteelbox_try:
			out << "smelt_drone_to_darksteelbox_try"; 
			break;
		case mpe_actionlog::smelt_drone_to_darksteelbox_failed:
			out << "smelt_drone_to_darksteelbox_failed"; 
			break;
		case mpe_actionlog::smelt_drone_to_darksteelbox_success:
			out << "smelt_drone_to_darksteelbox_success"; 
			break;
		case mpe_actionlog::governance_staking_party_try:
			out << "governance_staking_party_try"; 
			break;
		case mpe_actionlog::governance_staking_party_failed:
			out << "governance_staking_party_failed"; 
			break;
		case mpe_actionlog::governance_staking_party_success:
			out << "governance_staking_party_success"; 
			break;
		case mpe_actionlog::governance_unstaking_party_try:
			out << "governance_unstaking_party_try"; 
			break;
		case mpe_actionlog::governance_unstaking_party_failed:
			out << "governance_unstaking_party_failed"; 
			break;
		case mpe_actionlog::governance_unstaking_party_success:
			out << "governance_unstaking_party_success"; 
			break;
		case mpe_actionlog::exploration_log_reg:
			out << "exploration_log_reg"; 
			break;
		case mpe_actionlog::exploration_log_achievement:
			out << "exploration_log_achievement"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_log_item_update_type& value)
	{
		switch (value)
		{
		case mrpce_log_item_update_type::rollback:
			out << "rollback"; 
			break;
		case mrpce_log_item_update_type::buy:
			out << "buy"; 
			break;
		case mrpce_log_item_update_type::use:
			out << "use"; 
			break;
		case mrpce_log_item_update_type::pickup:
			out << "pickup"; 
			break;
		case mrpce_log_item_update_type::make:
			out << "make"; 
			break;
		case mrpce_log_item_update_type::storage:
			out << "storage"; 
			break;
		case mrpce_log_item_update_type::reward:
			out << "reward"; 
			break;
		case mrpce_log_item_update_type::mail:
			out << "mail"; 
			break;
		case mrpce_log_item_update_type::gm:
			out << "gm"; 
			break;
		case mrpce_log_item_update_type::collect:
			out << "collect"; 
			break;
		case mrpce_log_item_update_type::sell:
			out << "sell"; 
			break;
		case mrpce_log_item_update_type::drop:
			out << "drop"; 
			break;
		case mrpce_log_item_update_type::exchange:
			out << "exchange"; 
			break;
		case mrpce_log_item_update_type::destroy:
			out << "destroy"; 
			break;
		case mrpce_log_item_update_type::decompose:
			out << "decompose"; 
			break;
		case mrpce_log_item_update_type::cashshop:
			out << "cashshop"; 
			break;
		case mrpce_log_item_update_type::indun:
			out << "indun"; 
			break;
		case mrpce_log_item_update_type::indun_boss:
			out << "indun_boss"; 
			break;
		case mrpce_log_item_update_type::indun_illusion:
			out << "indun_illusion"; 
			break;
		case mrpce_log_item_update_type::indun_monarch:
			out << "indun_monarch"; 
			break;
		case mrpce_log_item_update_type::indun_siege:
			out << "indun_siege"; 
			break;
		case mrpce_log_item_update_type::indun_story:
			out << "indun_story"; 
			break;
		case mrpce_log_item_update_type::indun_guildoffice:
			out << "indun_guildoffice"; 
			break;
		case mrpce_log_item_update_type::indun_guild:
			out << "indun_guild"; 
			break;
		case mrpce_log_item_update_type::indun_castle:
			out << "indun_castle"; 
			break;
		case mrpce_log_item_update_type::indun_guildshipwar:
			out << "indun_guildshipwar"; 
			break;
		case mrpce_log_item_update_type::reset:
			out << "reset"; 
			break;
		case mrpce_log_item_update_type::charge:
			out << "charge"; 
			break;
		case mrpce_log_item_update_type::pk_guard_pass_buy:
			out << "pk_guard_pass_buy"; 
			break;
		case mrpce_log_item_update_type::worship:
			out << "worship"; 
			break;
		case mrpce_log_item_update_type::item_reinforce_org:
			out << "item_reinforce_org"; 
			break;
		case mrpce_log_item_update_type::quest_accept:
			out << "quest_accept"; 
			break;
		case mrpce_log_item_update_type::quest_finish:
			out << "quest_finish"; 
			break;
		case mrpce_log_item_update_type::field_drop:
			out << "field_drop"; 
			break;
		case mrpce_log_item_update_type::object_drop:
			out << "object_drop"; 
			break;
		case mrpce_log_item_update_type::monster_drop:
			out << "monster_drop"; 
			break;
		case mrpce_log_item_update_type::worldboss_drop:
			out << "worldboss_drop"; 
			break;
		case mrpce_log_item_update_type::explosion_drop:
			out << "explosion_drop"; 
			break;
		case mrpce_log_item_update_type::gold_explosion_drop:
			out << "gold_explosion_drop"; 
			break;
		case mrpce_log_item_update_type::monster_firstkill_reward:
			out << "monster_firstkill_reward"; 
			break;
		case mrpce_log_item_update_type::pk_reward:
			out << "pk_reward"; 
			break;
		case mrpce_log_item_update_type::pk_register:
			out << "pk_register"; 
			break;
		case mrpce_log_item_update_type::exp_recovery:
			out << "exp_recovery"; 
			break;
		case mrpce_log_item_update_type::pk_penelty:
			out << "pk_penelty"; 
			break;
		case mrpce_log_item_update_type::pk_get:
			out << "pk_get"; 
			break;
		case mrpce_log_item_update_type::exp_loss:
			out << "exp_loss"; 
			break;
		case mrpce_log_item_update_type::revive_auto:
			out << "revive_auto"; 
			break;
		case mrpce_log_item_update_type::revive_point:
			out << "revive_point"; 
			break;
		case mrpce_log_item_update_type::revive_skill:
			out << "revive_skill"; 
			break;
		case mrpce_log_item_update_type::revive_village:
			out << "revive_village"; 
			break;
		case mrpce_log_item_update_type::character_pk_update:
			out << "character_pk_update"; 
			break;
		case mrpce_log_item_update_type::character_pk_update_by_monster:
			out << "character_pk_update_by_monster"; 
			break;
		case mrpce_log_item_update_type::character_pk_manual_change:
			out << "character_pk_manual_change"; 
			break;
		case mrpce_log_item_update_type::character_pk_auto_change:
			out << "character_pk_auto_change"; 
			break;
		case mrpce_log_item_update_type::mining_get:
			out << "mining_get"; 
			break;
		case mrpce_log_item_update_type::fish_get:
			out << "fish_get"; 
			break;
		case mrpce_log_item_update_type::gather_get:
			out << "gather_get"; 
			break;
		case mrpce_log_item_update_type::skill_get:
			out << "skill_get"; 
			break;
		case mrpce_log_item_update_type::skill_levelup:
			out << "skill_levelup"; 
			break;
		case mrpce_log_item_update_type::force_get:
			out << "force_get"; 
			break;
		case mrpce_log_item_update_type::force_levelup:
			out << "force_levelup"; 
			break;
		case mrpce_log_item_update_type::mandala_active:
			out << "mandala_active"; 
			break;
		case mrpce_log_item_update_type::mandala_levelup:
			out << "mandala_levelup"; 
			break;
		case mrpce_log_item_update_type::mandala_reset:
			out << "mandala_reset"; 
			break;
		case mrpce_log_item_update_type::player_levelup:
			out << "player_levelup"; 
			break;
		case mrpce_log_item_update_type::equipment_attach:
			out << "equipment_attach"; 
			break;
		case mrpce_log_item_update_type::equipment_release:
			out << "equipment_release"; 
			break;
		case mrpce_log_item_update_type::vehicle_item_equip:
			out << "vehicle_item_equip"; 
			break;
		case mrpce_log_item_update_type::vehicle_item_release:
			out << "vehicle_item_release"; 
			break;
		case mrpce_log_item_update_type::mandala_rotate:
			out << "mandala_rotate"; 
			break;
		case mrpce_log_item_update_type::mandala_node_reset:
			out << "mandala_node_reset"; 
			break;
		case mrpce_log_item_update_type::expert_run:
			out << "expert_run"; 
			break;
		case mrpce_log_item_update_type::expert_equipment_unlock:
			out << "expert_equipment_unlock"; 
			break;
		case mrpce_log_item_update_type::expert_equipment_reinforce:
			out << "expert_equipment_reinforce"; 
			break;
		case mrpce_log_item_update_type::vehicle_get:
			out << "vehicle_get"; 
			break;
		case mrpce_log_item_update_type::vehicle_mix:
			out << "vehicle_mix"; 
			break;
		case mrpce_log_item_update_type::pet_get:
			out << "pet_get"; 
			break;
		case mrpce_log_item_update_type::pet_mix:
			out << "pet_mix"; 
			break;
		case mrpce_log_item_update_type::pet_confirm:
			out << "pet_confirm"; 
			break;
		case mrpce_log_item_update_type::pet_change:
			out << "pet_change"; 
			break;
		case mrpce_log_item_update_type::reflection_get:
			out << "reflection_get"; 
			break;
		case mrpce_log_item_update_type::reflection_mix:
			out << "reflection_mix"; 
			break;
		case mrpce_log_item_update_type::reflection_confirm:
			out << "reflection_confirm"; 
			break;
		case mrpce_log_item_update_type::reflection_change:
			out << "reflection_change"; 
			break;
		case mrpce_log_item_update_type::costume_hair_change:
			out << "costume_hair_change"; 
			break;
		case mrpce_log_item_update_type::costume_face_change:
			out << "costume_face_change"; 
			break;
		case mrpce_log_item_update_type::costume_color_change:
			out << "costume_color_change"; 
			break;
		case mrpce_log_item_update_type::potal_move:
			out << "potal_move"; 
			break;
		case mrpce_log_item_update_type::dead_move:
			out << "dead_move"; 
			break;
		case mrpce_log_item_update_type::sroll_use_move:
			out << "sroll_use_move"; 
			break;
		case mrpce_log_item_update_type::teleport_item_move:
			out << "teleport_item_move"; 
			break;
		case mrpce_log_item_update_type::save_area:
			out << "save_area"; 
			break;
		case mrpce_log_item_update_type::teleport_goods_move:
			out << "teleport_goods_move"; 
			break;
		case mrpce_log_item_update_type::teleport_channel_move:
			out << "teleport_channel_move"; 
			break;
		case mrpce_log_item_update_type::mentor_reg:
			out << "mentor_reg"; 
			break;
		case mrpce_log_item_update_type::mentee_reg:
			out << "mentee_reg"; 
			break;
		case mrpce_log_item_update_type::mentor_ter:
			out << "mentor_ter"; 
			break;
		case mrpce_log_item_update_type::mentee_ter:
			out << "mentee_ter"; 
			break;
		case mrpce_log_item_update_type::mentee_lv_ter:
			out << "mentee_lv_ter"; 
			break;
		case mrpce_log_item_update_type::item_reinforce:
			out << "item_reinforce"; 
			break;
		case mrpce_log_item_update_type::item_enchant:
			out << "item_enchant"; 
			break;
		case mrpce_log_item_update_type::item_luck:
			out << "item_luck"; 
			break;
		case mrpce_log_item_update_type::item_repair:
			out << "item_repair"; 
			break;
		case mrpce_log_item_update_type::self_try:
			out << "self_try"; 
			break;
		case mrpce_log_item_update_type::street_stall_try:
			out << "street_stall_try"; 
			break;
		case mrpce_log_item_update_type::street_stall_start:
			out << "street_stall_start"; 
			break;
		case mrpce_log_item_update_type::position_save:
			out << "position_save"; 
			break;
		case mrpce_log_item_update_type::tonic_charging:
			out << "tonic_charging"; 
			break;
		case mrpce_log_item_update_type::tonic_auto_town_charging:
			out << "tonic_auto_town_charging"; 
			break;
		case mrpce_log_item_update_type::street_stall_npc_try:
			out << "street_stall_npc_try"; 
			break;
		case mrpce_log_item_update_type::equipment_awaken_try:
			out << "equipment_awaken_try"; 
			break;
		case mrpce_log_item_update_type::make_success:
			out << "make_success"; 
			break;
		case mrpce_log_item_update_type::make_big_success:
			out << "make_big_success"; 
			break;
		case mrpce_log_item_update_type::make_fail:
			out << "make_fail"; 
			break;
		case mrpce_log_item_update_type::mix_success:
			out << "mix_success"; 
			break;
		case mrpce_log_item_update_type::mix_fail:
			out << "mix_fail"; 
			break;
		case mrpce_log_item_update_type::profession_blacksmith:
			out << "profession_blacksmith"; 
			break;
		case mrpce_log_item_update_type::profession_alchemy:
			out << "profession_alchemy"; 
			break;
		case mrpce_log_item_update_type::profession_handwork:
			out << "profession_handwork"; 
			break;
		case mrpce_log_item_update_type::npc_make:
			out << "npc_make"; 
			break;
		case mrpce_log_item_update_type::mix_all:
			out << "mix_all"; 
			break;
		case mrpce_log_item_update_type::mix_one:
			out << "mix_one"; 
			break;
		case mrpce_log_item_update_type::skill_force_make:
			out << "skill_force_make"; 
			break;
		case mrpce_log_item_update_type::profession_event:
			out << "profession_event"; 
			break;
		case mrpce_log_item_update_type::character_use:
			out << "character_use"; 
			break;
		case mrpce_log_item_update_type::inventory_weight_expand:
			out << "inventory_weight_expand"; 
			break;
		case mrpce_log_item_update_type::inventory_size_expand:
			out << "inventory_size_expand"; 
			break;
		case mrpce_log_item_update_type::guild_inven_expand:
			out << "guild_inven_expand"; 
			break;
		case mrpce_log_item_update_type::chao_pass_buy:
			out << "chao_pass_buy"; 
			break;
		case mrpce_log_item_update_type::package_box:
			out << "package_box"; 
			break;
		case mrpce_log_item_update_type::randombox:
			out << "randombox"; 
			break;
		case mrpce_log_item_update_type::field_box:
			out << "field_box"; 
			break;
		case mrpce_log_item_update_type::spawn_dungeon_box:
			out << "spawn_dungeon_box"; 
			break;
		case mrpce_log_item_update_type::field_boss_box:
			out << "field_boss_box"; 
			break;
		case mrpce_log_item_update_type::arena_box:
			out << "arena_box"; 
			break;
		case mrpce_log_item_update_type::exchange_register:
			out << "exchange_register"; 
			break;
		case mrpce_log_item_update_type::exchange_register_cancel:
			out << "exchange_register_cancel"; 
			break;
		case mrpce_log_item_update_type::exchange_buy:
			out << "exchange_buy"; 
			break;
		case mrpce_log_item_update_type::exchange_sell:
			out << "exchange_sell"; 
			break;
		case mrpce_log_item_update_type::world_exchange_register:
			out << "world_exchange_register"; 
			break;
		case mrpce_log_item_update_type::world_exchange_register_cancel:
			out << "world_exchange_register_cancel"; 
			break;
		case mrpce_log_item_update_type::world_exchange_buy:
			out << "world_exchange_buy"; 
			break;
		case mrpce_log_item_update_type::world_exchange_sell:
			out << "world_exchange_sell"; 
			break;
		case mrpce_log_item_update_type::world_gold_exchange_register:
			out << "world_gold_exchange_register"; 
			break;
		case mrpce_log_item_update_type::world_gold_exchange_register_cancel:
			out << "world_gold_exchange_register_cancel"; 
			break;
		case mrpce_log_item_update_type::world_gold_exchange_buy:
			out << "world_gold_exchange_buy"; 
			break;
		case mrpce_log_item_update_type::world_gold_exchange_sell:
			out << "world_gold_exchange_sell"; 
			break;
		case mrpce_log_item_update_type::event_reward_get:
			out << "event_reward_get"; 
			break;
		case mrpce_log_item_update_type::push_reward_get:
			out << "push_reward_get"; 
			break;
		case mrpce_log_item_update_type::coupon_reward_get:
			out << "coupon_reward_get"; 
			break;
		case mrpce_log_item_update_type::private_storage_get:
			out << "private_storage_get"; 
			break;
		case mrpce_log_item_update_type::mento_connect:
			out << "mento_connect"; 
			break;
		case mrpce_log_item_update_type::mentee_levelup:
			out << "mentee_levelup"; 
			break;
		case mrpce_log_item_update_type::mentee_end:
			out << "mentee_end"; 
			break;
		case mrpce_log_item_update_type::siegeward_win_reward:
			out << "siegeward_win_reward"; 
			break;
		case mrpce_log_item_update_type::mix:
			out << "mix"; 
			break;
		case mrpce_log_item_update_type::exchange_calc:
			out << "exchange_calc"; 
			break;
		case mrpce_log_item_update_type::dictionary_complete_reward:
			out << "dictionary_complete_reward"; 
			break;
		case mrpce_log_item_update_type::goldin_got_spawn:
			out << "goldin_got_spawn"; 
			break;
		case mrpce_log_item_update_type::item_spawn:
			out << "item_spawn"; 
			break;
		case mrpce_log_item_update_type::package_get:
			out << "package_get"; 
			break;
		case mrpce_log_item_update_type::dungeon_clear_reward:
			out << "dungeon_clear_reward"; 
			break;
		case mrpce_log_item_update_type::quest_reward:
			out << "quest_reward"; 
			break;
		case mrpce_log_item_update_type::castletown_build_expire:
			out << "castletown_build_expire"; 
			break;
		case mrpce_log_item_update_type::castletown_friendly_cancel:
			out << "castletown_friendly_cancel"; 
			break;
		case mrpce_log_item_update_type::dropbox_get:
			out << "dropbox_get"; 
			break;
		case mrpce_log_item_update_type::achieve_reward:
			out << "achieve_reward"; 
			break;
		case mrpce_log_item_update_type::quest_reward_blackiron:
			out << "quest_reward_blackiron"; 
			break;
		case mrpce_log_item_update_type::server_storage_get:
			out << "server_storage_get"; 
			break;
		case mrpce_log_item_update_type::random_use:
			out << "random_use"; 
			break;
		case mrpce_log_item_update_type::item_random_use:
			out << "item_random_use"; 
			break;
		case mrpce_log_item_update_type::private_storage_add:
			out << "private_storage_add"; 
			break;
		case mrpce_log_item_update_type::enchantstone_slot_open:
			out << "enchantstone_slot_open"; 
			break;
		case mrpce_log_item_update_type::enchantstone_equip:
			out << "enchantstone_equip"; 
			break;
		case mrpce_log_item_update_type::enchantstone_upgrade:
			out << "enchantstone_upgrade"; 
			break;
		case mrpce_log_item_update_type::vehicle_equip:
			out << "vehicle_equip"; 
			break;
		case mrpce_log_item_update_type::private_storage_buy:
			out << "private_storage_buy"; 
			break;
		case mrpce_log_item_update_type::account_storage_buy:
			out << "account_storage_buy"; 
			break;
		case mrpce_log_item_update_type::guild_skill_get:
			out << "guild_skill_get"; 
			break;
		case mrpce_log_item_update_type::item_destory:
			out << "item_destory"; 
			break;
		case mrpce_log_item_update_type::castle_town_employ:
			out << "castle_town_employ"; 
			break;
		case mrpce_log_item_update_type::castle_town_build_up:
			out << "castle_town_build_up"; 
			break;
		case mrpce_log_item_update_type::use_by_mix:
			out << "use_by_mix"; 
			break;
		case mrpce_log_item_update_type::enchantstone_mix:
			out << "enchantstone_mix"; 
			break;
		case mrpce_log_item_update_type::item_decompose:
			out << "item_decompose"; 
			break;
		case mrpce_log_item_update_type::dungeon_free:
			out << "dungeon_free"; 
			break;
		case mrpce_log_item_update_type::ticket_use:
			out << "ticket_use"; 
			break;
		case mrpce_log_item_update_type::quest_reward_change:
			out << "quest_reward_change"; 
			break;
		case mrpce_log_item_update_type::gold_gacha:
			out << "gold_gacha"; 
			break;
		case mrpce_log_item_update_type::storage_move:
			out << "storage_move"; 
			break;
		case mrpce_log_item_update_type::contents_reset:
			out << "contents_reset"; 
			break;
		case mrpce_log_item_update_type::quest_use:
			out << "quest_use"; 
			break;
		case mrpce_log_item_update_type::enchant_stone_release:
			out << "enchant_stone_release"; 
			break;
		case mrpce_log_item_update_type::character_pk_item:
			out << "character_pk_item"; 
			break;
		case mrpce_log_item_update_type::server_storage_set:
			out << "server_storage_set"; 
			break;
		case mrpce_log_item_update_type::exchange1_reset:
			out << "exchange1_reset"; 
			break;
		case mrpce_log_item_update_type::exchange2_reset:
			out << "exchange2_reset"; 
			break;
		case mrpce_log_item_update_type::enchantstone_mix_success:
			out << "enchantstone_mix_success"; 
			break;
		case mrpce_log_item_update_type::enchantstone_mix_fail:
			out << "enchantstone_mix_fail"; 
			break;
		case mrpce_log_item_update_type::party_dungeon_enter:
			out << "party_dungeon_enter"; 
			break;
		case mrpce_log_item_update_type::party_dungeon_exit:
			out << "party_dungeon_exit"; 
			break;
		case mrpce_log_item_update_type::seal_tower_enter:
			out << "seal_tower_enter"; 
			break;
		case mrpce_log_item_update_type::seal_tower_exit:
			out << "seal_tower_exit"; 
			break;
		case mrpce_log_item_update_type::dream_tower_enter:
			out << "dream_tower_enter"; 
			break;
		case mrpce_log_item_update_type::dream_tower_exit:
			out << "dream_tower_exit"; 
			break;
		case mrpce_log_item_update_type::demon_tower_enter:
			out << "demon_tower_enter"; 
			break;
		case mrpce_log_item_update_type::demon_tower_exit:
			out << "demon_tower_exit"; 
			break;
		case mrpce_log_item_update_type::castle_dungeon_enter:
			out << "castle_dungeon_enter"; 
			break;
		case mrpce_log_item_update_type::castle_dungeon_exit:
			out << "castle_dungeon_exit"; 
			break;
		case mrpce_log_item_update_type::guild_dungeon_enter:
			out << "guild_dungeon_enter"; 
			break;
		case mrpce_log_item_update_type::guild_dungeon_exit:
			out << "guild_dungeon_exit"; 
			break;
		case mrpce_log_item_update_type::castletown_enter:
			out << "castletown_enter"; 
			break;
		case mrpce_log_item_update_type::casteltown_exit:
			out << "casteltown_exit"; 
			break;
		case mrpce_log_item_update_type::arena_enter:
			out << "arena_enter"; 
			break;
		case mrpce_log_item_update_type::arena_exit:
			out << "arena_exit"; 
			break;
		case mrpce_log_item_update_type::siegewar_enter:
			out << "siegewar_enter"; 
			break;
		case mrpce_log_item_update_type::siegewar_exit:
			out << "siegewar_exit"; 
			break;
		case mrpce_log_item_update_type::shipwar_enter:
			out << "shipwar_enter"; 
			break;
		case mrpce_log_item_update_type::shipwar_exit:
			out << "shipwar_exit"; 
			break;
		case mrpce_log_item_update_type::territorial_war_enter:
			out << "territorial_war_enter"; 
			break;
		case mrpce_log_item_update_type::territorial_war_exit:
			out << "territorial_war_exit"; 
			break;
		case mrpce_log_item_update_type::monarch_enter:
			out << "monarch_enter"; 
			break;
		case mrpce_log_item_update_type::monarch_exit:
			out << "monarch_exit"; 
			break;
		case mrpce_log_item_update_type::event_dungeon_enter:
			out << "event_dungeon_enter"; 
			break;
		case mrpce_log_item_update_type::event_dungeon_exit:
			out << "event_dungeon_exit"; 
			break;
		case mrpce_log_item_update_type::unknown_dungeon_enter:
			out << "unknown_dungeon_enter"; 
			break;
		case mrpce_log_item_update_type::unknown_dungeon_exit:
			out << "unknown_dungeon_exit"; 
			break;
		case mrpce_log_item_update_type::dimension_dungeon_enter:
			out << "dimension_dungeon_enter"; 
			break;
		case mrpce_log_item_update_type::dimension_dungeon_exit:
			out << "dimension_dungeon_exit"; 
			break;
		case mrpce_log_item_update_type::mail_base:
			out << "mail_base"; 
			break;
		case mrpce_log_item_update_type::regular_mail_reward:
			out << "regular_mail_reward"; 
			break;
		case mrpce_log_item_update_type::temp_mail_reward:
			out << "temp_mail_reward"; 
			break;
		case mrpce_log_item_update_type::inventory_size_empty:
			out << "inventory_size_empty"; 
			break;
		case mrpce_log_item_update_type::baseguild_rewad:
			out << "baseguild_rewad"; 
			break;
		case mrpce_log_item_update_type::illusion_dungeon_mail_reward:
			out << "illusion_dungeon_mail_reward"; 
			break;
		case mrpce_log_item_update_type::monarch_dugeon_mail_reward:
			out << "monarch_dugeon_mail_reward"; 
			break;
		case mrpce_log_item_update_type::dungeon_clear_mail_reward:
			out << "dungeon_clear_mail_reward"; 
			break;
		case mrpce_log_item_update_type::worldboss_mail_reward:
			out << "worldboss_mail_reward"; 
			break;
		case mrpce_log_item_update_type::fieldboss_mail_reward:
			out << "fieldboss_mail_reward"; 
			break;
		case mrpce_log_item_update_type::guilddungeon_mail_rewad:
			out << "guilddungeon_mail_rewad"; 
			break;
		case mrpce_log_item_update_type::guilddungeon_demage_mail_reward:
			out << "guilddungeon_demage_mail_reward"; 
			break;
		case mrpce_log_item_update_type::siegewar_win_mail_reward:
			out << "siegewar_win_mail_reward"; 
			break;
		case mrpce_log_item_update_type::siegewar_lose_mail_reward:
			out << "siegewar_lose_mail_reward"; 
			break;
		case mrpce_log_item_update_type::siegewar_enter_mail_reward:
			out << "siegewar_enter_mail_reward"; 
			break;
		case mrpce_log_item_update_type::guild_quest_personal_mail_reward:
			out << "guild_quest_personal_mail_reward"; 
			break;
		case mrpce_log_item_update_type::mento_levelup_mail_reward:
			out << "mento_levelup_mail_reward"; 
			break;
		case mrpce_log_item_update_type::party_dungeon_clear_reward:
			out << "party_dungeon_clear_reward"; 
			break;
		case mrpce_log_item_update_type::party_dungeon_fail_reward:
			out << "party_dungeon_fail_reward"; 
			break;
		case mrpce_log_item_update_type::sealtower_sealmechine:
			out << "sealtower_sealmechine"; 
			break;
		case mrpce_log_item_update_type::illusion_boss_kill:
			out << "illusion_boss_kill"; 
			break;
		case mrpce_log_item_update_type::demon_boss_kill:
			out << "demon_boss_kill"; 
			break;
		case mrpce_log_item_update_type::spawn_dungeon_clear:
			out << "spawn_dungeon_clear"; 
			break;
		case mrpce_log_item_update_type::spawn_dungeon_fail:
			out << "spawn_dungeon_fail"; 
			break;
		case mrpce_log_item_update_type::castledugeon_spawn_register:
			out << "castledugeon_spawn_register"; 
			break;
		case mrpce_log_item_update_type::castledugeon_spawn_boss:
			out << "castledugeon_spawn_boss"; 
			break;
		case mrpce_log_item_update_type::castledugeon_time_out:
			out << "castledugeon_time_out"; 
			break;
		case mrpce_log_item_update_type::castledugeon_clear:
			out << "castledugeon_clear"; 
			break;
		case mrpce_log_item_update_type::guild_dugeon_clear:
			out << "guild_dugeon_clear"; 
			break;
		case mrpce_log_item_update_type::guild_dugeon_fail:
			out << "guild_dugeon_fail"; 
			break;
		case mrpce_log_item_update_type::collection_register:
			out << "collection_register"; 
			break;
		case mrpce_log_item_update_type::collection_complete:
			out << "collection_complete"; 
			break;
		case mrpce_log_item_update_type::dictionary_register:
			out << "dictionary_register"; 
			break;
		case mrpce_log_item_update_type::dictionary_complete:
			out << "dictionary_complete"; 
			break;
		case mrpce_log_item_update_type::monarch_timespace_essence:
			out << "monarch_timespace_essence"; 
			break;
		case mrpce_log_item_update_type::monarch_timespace_core:
			out << "monarch_timespace_core"; 
			break;
		case mrpce_log_item_update_type::quest_reward_main:
			out << "quest_reward_main"; 
			break;
		case mrpce_log_item_update_type::quest_reward_sub:
			out << "quest_reward_sub"; 
			break;
		case mrpce_log_item_update_type::quest_reward_zone:
			out << "quest_reward_zone"; 
			break;
		case mrpce_log_item_update_type::quest_reward_repute:
			out << "quest_reward_repute"; 
			break;
		case mrpce_log_item_update_type::quest_reward_guild:
			out << "quest_reward_guild"; 
			break;
		case mrpce_log_item_update_type::quest_reward_study:
			out << "quest_reward_study"; 
			break;
		case mrpce_log_item_update_type::quest_reward_:
			out << "quest_reward_"; 
			break;
		case mrpce_log_item_update_type::quest_reward_manor:
			out << "quest_reward_manor"; 
			break;
		case mrpce_log_item_update_type::quest_reward_stroy:
			out << "quest_reward_stroy"; 
			break;
		case mrpce_log_item_update_type::quest_reward_projesion:
			out << "quest_reward_projesion"; 
			break;
		case mrpce_log_item_update_type::siegewar_reward:
			out << "siegewar_reward"; 
			break;
		case mrpce_log_item_update_type::siegewar_atk_machine_build:
			out << "siegewar_atk_machine_build"; 
			break;
		case mrpce_log_item_update_type::siegewar_def_machine_build:
			out << "siegewar_def_machine_build"; 
			break;
		case mrpce_log_item_update_type::shipwar_reward:
			out << "shipwar_reward"; 
			break;
		case mrpce_log_item_update_type::flag_object_reward:
			out << "flag_object_reward"; 
			break;
		case mrpce_log_item_update_type::arena_win_reward:
			out << "arena_win_reward"; 
			break;
		case mrpce_log_item_update_type::arena_lose_reward:
			out << "arena_lose_reward"; 
			break;
		case mrpce_log_item_update_type::valley_tax_reward:
			out << "valley_tax_reward"; 
			break;
		case mrpce_log_item_update_type::shipwar_win:
			out << "shipwar_win"; 
			break;
		case mrpce_log_item_update_type::shipwar_lose:
			out << "shipwar_lose"; 
			break;
		case mrpce_log_item_update_type::shipwar_flag_all:
			out << "shipwar_flag_all"; 
			break;
		case mrpce_log_item_update_type::shipwar_draw:
			out << "shipwar_draw"; 
			break;
		case mrpce_log_item_update_type::shipwar_win_reward:
			out << "shipwar_win_reward"; 
			break;
		case mrpce_log_item_update_type::shipwar_lose_reward:
			out << "shipwar_lose_reward"; 
			break;
		case mrpce_log_item_update_type::shipwar_season_reward:
			out << "shipwar_season_reward"; 
			break;
		case mrpce_log_item_update_type::occupationwar_tender_deposit:
			out << "occupationwar_tender_deposit"; 
			break;
		case mrpce_log_item_update_type::occupationwar_tender_withdraw:
			out << "occupationwar_tender_withdraw"; 
			break;
		case mrpce_log_item_update_type::occupationwar_war_start:
			out << "occupationwar_war_start"; 
			break;
		case mrpce_log_item_update_type::occupationwar_war_finish:
			out << "occupationwar_war_finish"; 
			break;
		case mrpce_log_item_update_type::occupationwar_war_1:
			out << "occupationwar_war_1"; 
			break;
		case mrpce_log_item_update_type::occupationwar_war_2:
			out << "occupationwar_war_2"; 
			break;
		case mrpce_log_item_update_type::occupationwar_war_win_reward:
			out << "occupationwar_war_win_reward"; 
			break;
		case mrpce_log_item_update_type::occupationwar_war_3:
			out << "occupationwar_war_3"; 
			break;
		case mrpce_log_item_update_type::occupationwar_war_mvp_reward:
			out << "occupationwar_war_mvp_reward"; 
			break;
		case mrpce_log_item_update_type::darksteel_storage_darksteel_buy:
			out << "darksteel_storage_darksteel_buy"; 
			break;
		case mrpce_log_item_update_type::darksteel_storage_darksteel_sell:
			out << "darksteel_storage_darksteel_sell"; 
			break;
		case mrpce_log_item_update_type::darksteel_storage_tax_calculate:
			out << "darksteel_storage_tax_calculate"; 
			break;
		case mrpce_log_item_update_type::darksteel_storage_darksteel_pay:
			out << "darksteel_storage_darksteel_pay"; 
			break;
		case mrpce_log_item_update_type::darksteel_storage_darksteel_withdraw:
			out << "darksteel_storage_darksteel_withdraw"; 
			break;
		case mrpce_log_item_update_type::darksteel_storage_darksteel_reg:
			out << "darksteel_storage_darksteel_reg"; 
			break;
		case mrpce_log_item_update_type::occupationwar_tower_war_occupation:
			out << "occupationwar_tower_war_occupation"; 
			break;
		case mrpce_log_item_update_type::occupationwar_war_4:
			out << "occupationwar_war_4"; 
			break;
		case mrpce_log_item_update_type::occupationwar_war_5:
			out << "occupationwar_war_5"; 
			break;
		case mrpce_log_item_update_type::occupationwar_war_6:
			out << "occupationwar_war_6"; 
			break;
		case mrpce_log_item_update_type::occupationwar_war_7:
			out << "occupationwar_war_7"; 
			break;
		case mrpce_log_item_update_type::occupationwar_server_decide:
			out << "occupationwar_server_decide"; 
			break;
		case mrpce_log_item_update_type::occupationwar_server_decide_out:
			out << "occupationwar_server_decide_out"; 
			break;
		case mrpce_log_item_update_type::darksteel_storage_darksteel_pay_character:
			out << "darksteel_storage_darksteel_pay_character"; 
			break;
		case mrpce_log_item_update_type::darksteel_storage_darksteel_pay_guild:
			out << "darksteel_storage_darksteel_pay_guild"; 
			break;
		case mrpce_log_item_update_type::darksteel_storage_darksteel_pay_penalty:
			out << "darksteel_storage_darksteel_pay_penalty"; 
			break;
		case mrpce_log_item_update_type::darksteel_refinery_exchange:
			out << "darksteel_refinery_exchange"; 
			break;
		case mrpce_log_item_update_type::guild_create:
			out << "guild_create"; 
			break;
		case mrpce_log_item_update_type::guild_donation:
			out << "guild_donation"; 
			break;
		case mrpce_log_item_update_type::guild_war_call:
			out << "guild_war_call"; 
			break;
		case mrpce_log_item_update_type::guild_name_change:
			out << "guild_name_change"; 
			break;
		case mrpce_log_item_update_type::guild_mark_change:
			out << "guild_mark_change"; 
			break;
		case mrpce_log_item_update_type::guild_guild_skill_get:
			out << "guild_guild_skill_get"; 
			break;
		case mrpce_log_item_update_type::guild_skill_up:
			out << "guild_skill_up"; 
			break;
		case mrpce_log_item_update_type::guild_skill_use:
			out << "guild_skill_use"; 
			break;
		case mrpce_log_item_update_type::guild_dungeon_open:
			out << "guild_dungeon_open"; 
			break;
		case mrpce_log_item_update_type::guild_storage_material_add:
			out << "guild_storage_material_add"; 
			break;
		case mrpce_log_item_update_type::guild_storage_material_get:
			out << "guild_storage_material_get"; 
			break;
		case mrpce_log_item_update_type::guild_storage_treasure_add:
			out << "guild_storage_treasure_add"; 
			break;
		case mrpce_log_item_update_type::guild_storage_treasure_exchange_tender:
			out << "guild_storage_treasure_exchange_tender"; 
			break;
		case mrpce_log_item_update_type::guild_storage_treasure_exchange_tender_finish:
			out << "guild_storage_treasure_exchange_tender_finish"; 
			break;
		case mrpce_log_item_update_type::guild_storage_treasure_exchange_tender_fial:
			out << "guild_storage_treasure_exchange_tender_fial"; 
			break;
		case mrpce_log_item_update_type::guild_guilddungeon_clear:
			out << "guild_guilddungeon_clear"; 
			break;
		case mrpce_log_item_update_type::guild_guilddungeon_fail:
			out << "guild_guilddungeon_fail"; 
			break;
		case mrpce_log_item_update_type::guild_base_reward:
			out << "guild_base_reward"; 
			break;
		case mrpce_log_item_update_type::guild_bonus_reward:
			out << "guild_bonus_reward"; 
			break;
		case mrpce_log_item_update_type::guild_quest_reward:
			out << "guild_quest_reward"; 
			break;
		case mrpce_log_item_update_type::guild_blackiron_shop_open:
			out << "guild_blackiron_shop_open"; 
			break;
		case mrpce_log_item_update_type::guild_blackiron_shop_close:
			out << "guild_blackiron_shop_close"; 
			break;
		case mrpce_log_item_update_type::guild_blackiron_shop_return:
			out << "guild_blackiron_shop_return"; 
			break;
		case mrpce_log_item_update_type::guild_blackiron_shop_buy:
			out << "guild_blackiron_shop_buy"; 
			break;
		case mrpce_log_item_update_type::guildshop_buy:
			out << "guildshop_buy"; 
			break;
		case mrpce_log_item_update_type::guild_need_use_item:
			out << "guild_need_use_item"; 
			break;
		case mrpce_log_item_update_type::guild_enter_item:
			out << "guild_enter_item"; 
			break;
		case mrpce_log_item_update_type::guild_chanage_mark:
			out << "guild_chanage_mark"; 
			break;
		case mrpce_log_item_update_type::guild_war_surrender:
			out << "guild_war_surrender"; 
			break;
		case mrpce_log_item_update_type::guild_storage_shared_extend:
			out << "guild_storage_shared_extend"; 
			break;
		case mrpce_log_item_update_type::guild_item_use_exp:
			out << "guild_item_use_exp"; 
			break;
		case mrpce_log_item_update_type::guild_dungeon_exp:
			out << "guild_dungeon_exp"; 
			break;
		case mrpce_log_item_update_type::guild_war_declare:
			out << "guild_war_declare"; 
			break;
		case mrpce_log_item_update_type::guild_dungeon_open_count_charge:
			out << "guild_dungeon_open_count_charge"; 
			break;
		case mrpce_log_item_update_type::guild_dungeon_open_count_charge_item:
			out << "guild_dungeon_open_count_charge_item"; 
			break;
		case mrpce_log_item_update_type::guild_storage_treasure_exchange_tender_fial_confirm:
			out << "guild_storage_treasure_exchange_tender_fial_confirm"; 
			break;
		case mrpce_log_item_update_type::guild_war_accept_surrender:
			out << "guild_war_accept_surrender"; 
			break;
		case mrpce_log_item_update_type::castle_town_tender:
			out << "castle_town_tender"; 
			break;
		case mrpce_log_item_update_type::castle_town_tender_success_bid:
			out << "castle_town_tender_success_bid"; 
			break;
		case mrpce_log_item_update_type::castle_town_tender_fail_bid:
			out << "castle_town_tender_fail_bid"; 
			break;
		case mrpce_log_item_update_type::castle_town_build_employ:
			out << "castle_town_build_employ"; 
			break;
		case mrpce_log_item_update_type::castle_town_build_promp_employ:
			out << "castle_town_build_promp_employ"; 
			break;
		case mrpce_log_item_update_type::castle_town_build_employ_cancel:
			out << "castle_town_build_employ_cancel"; 
			break;
		case mrpce_log_item_update_type::castle_town_build_expire:
			out << "castle_town_build_expire"; 
			break;
		case mrpce_log_item_update_type::castle_town_build_friendly_up:
			out << "castle_town_build_friendly_up"; 
			break;
		case mrpce_log_item_update_type::castle_town_build_promp_friendly_up:
			out << "castle_town_build_promp_friendly_up"; 
			break;
		case mrpce_log_item_update_type::castle_town_build_friendly_cancel:
			out << "castle_town_build_friendly_cancel"; 
			break;
		case mrpce_log_item_update_type::castle_town_rental:
			out << "castle_town_rental"; 
			break;
		case mrpce_log_item_update_type::bless_try:
			out << "bless_try"; 
			break;
		case mrpce_log_item_update_type::bless_personal_reward:
			out << "bless_personal_reward"; 
			break;
		case mrpce_log_item_update_type::bless_global_reward:
			out << "bless_global_reward"; 
			break;
		case mrpce_log_item_update_type::personal_cri_reward_get:
			out << "personal_cri_reward_get"; 
			break;
		case mrpce_log_item_update_type::shop_game_buy:
			out << "shop_game_buy"; 
			break;
		case mrpce_log_item_update_type::shop_package_get:
			out << "shop_package_get"; 
			break;
		case mrpce_log_item_update_type::shop_cart_get:
			out << "shop_cart_get"; 
			break;
		case mrpce_log_item_update_type::shop_package2_buy:
			out << "shop_package2_buy"; 
			break;
		case mrpce_log_item_update_type::shop_random_buy:
			out << "shop_random_buy"; 
			break;
		case mrpce_log_item_update_type::shop_mileage_buy:
			out << "shop_mileage_buy"; 
			break;
		case mrpce_log_item_update_type::shop_costume_buy:
			out << "shop_costume_buy"; 
			break;
		case mrpce_log_item_update_type::shop_cart_withdraw:
			out << "shop_cart_withdraw"; 
			break;
		case mrpce_log_item_update_type::shop_npc_buy:
			out << "shop_npc_buy"; 
			break;
		case mrpce_log_item_update_type::shop_npc_sell:
			out << "shop_npc_sell"; 
			break;
		case mrpce_log_item_update_type::shop_npc_prise:
			out << "shop_npc_prise"; 
			break;
		case mrpce_log_item_update_type::npc_quest_initmacy:
			out << "npc_quest_initmacy"; 
			break;
		case mrpce_log_item_update_type::mirpass_unlock:
			out << "mirpass_unlock"; 
			break;
		case mrpce_log_item_update_type::mirpass_buy_unlock:
			out << "mirpass_buy_unlock"; 
			break;
		case mrpce_log_item_update_type::mirpass_free_reward:
			out << "mirpass_free_reward"; 
			break;
		case mrpce_log_item_update_type::mirpass_buy_reward:
			out << "mirpass_buy_reward"; 
			break;
		case mrpce_log_item_update_type::mirpass_promp_complete:
			out << "mirpass_promp_complete"; 
			break;
		case mrpce_log_item_update_type::mirpass_challenge:
			out << "mirpass_challenge"; 
			break;
		case mrpce_log_item_update_type::mirpass_challenge_complete:
			out << "mirpass_challenge_complete"; 
			break;
		case mrpce_log_item_update_type::ad_reward:
			out << "ad_reward"; 
			break;
		case mrpce_log_item_update_type::ad_event_reward:
			out << "ad_event_reward"; 
			break;
		case mrpce_log_item_update_type::ad_exp_restore:
			out << "ad_exp_restore"; 
			break;
		case mrpce_log_item_update_type::gmcommand:
			out << "gmcommand"; 
			break;
		case mrpce_log_item_update_type::street_stall_auto_end:
			out << "street_stall_auto_end"; 
			break;
		case mrpce_log_item_update_type::street_stall_count_end:
			out << "street_stall_count_end"; 
			break;
		case mrpce_log_item_update_type::street_stall_player_end:
			out << "street_stall_player_end"; 
			break;
		case mrpce_log_item_update_type::street_stall_fees:
			out << "street_stall_fees"; 
			break;
		case mrpce_log_item_update_type::token_history_item_get:
			out << "token_history_item_get"; 
			break;
		case mrpce_log_item_update_type::gm_cart_withdraw:
			out << "gm_cart_withdraw"; 
			break;
		case mrpce_log_item_update_type::gm_item_add:
			out << "gm_item_add"; 
			break;
		case mrpce_log_item_update_type::gm_item_del:
			out << "gm_item_del"; 
			break;
		case mrpce_log_item_update_type::gm_goods_add:
			out << "gm_goods_add"; 
			break;
		case mrpce_log_item_update_type::gm_goods_withdraw:
			out << "gm_goods_withdraw"; 
			break;
		case mrpce_log_item_update_type::gm_goods_mail_send:
			out << "gm_goods_mail_send"; 
			break;
		case mrpce_log_item_update_type::gm_goods_mail_del:
			out << "gm_goods_mail_del"; 
			break;
		case mrpce_log_item_update_type::gm_edit:
			out << "gm_edit"; 
			break;
		case mrpce_log_item_update_type::gm_guild_goods_add:
			out << "gm_guild_goods_add"; 
			break;
		case mrpce_log_item_update_type::gm_guild_goods_withdraw:
			out << "gm_guild_goods_withdraw"; 
			break;
		case mrpce_log_item_update_type::gm_guild_goods_add_2:
			out << "gm_guild_goods_add_2"; 
			break;
		case mrpce_log_item_update_type::gm_guild_goods_withdraw_2:
			out << "gm_guild_goods_withdraw_2"; 
			break;
		case mrpce_log_item_update_type::item_rollback:
			out << "item_rollback"; 
			break;
		case mrpce_log_item_update_type::blood_dedicate_goods_reward_change_complete:
			out << "blood_dedicate_goods_reward_change_complete"; 
			break;
		case mrpce_log_item_update_type::blood_dedicate_item_reward_change_complete:
			out << "blood_dedicate_item_reward_change_complete"; 
			break;
		case mrpce_log_item_update_type::blood_dedicate_item_use:
			out << "blood_dedicate_item_use"; 
			break;
		case mrpce_log_item_update_type::blood_dedicate_goods_use:
			out << "blood_dedicate_goods_use"; 
			break;
		case mrpce_log_item_update_type::blood_dedicate_nelumbostone_point:
			out << "blood_dedicate_nelumbostone_point"; 
			break;
		case mrpce_log_item_update_type::season_mandala_item_reward_change_complete:
			out << "season_mandala_item_reward_change_complete"; 
			break;
		case mrpce_log_item_update_type::smelt_darksteel_to_drone:
			out << "smelt_darksteel_to_drone"; 
			break;
		case mrpce_log_item_update_type::smelt_darksteel_to_drone_failed:
			out << "smelt_darksteel_to_drone_failed"; 
			break;
		case mrpce_log_item_update_type::smelt_drone_to_darksteel:
			out << "smelt_drone_to_darksteel"; 
			break;
		case mrpce_log_item_update_type::smelt_count_lack_failed:
			out << "smelt_count_lack_failed"; 
			break;
		case mrpce_log_item_update_type::smelt_low_balance_failed:
			out << "smelt_low_balance_failed"; 
			break;
		case mrpce_log_item_update_type::smelt_low_darksteelbox_failed:
			out << "smelt_low_darksteelbox_failed"; 
			break;
		case mrpce_log_item_update_type::divine_staking:
			out << "divine_staking"; 
			break;
		case mrpce_log_item_update_type::divine_staking_failed:
			out << "divine_staking_failed"; 
			break;
		case mrpce_log_item_update_type::occupationwar_staking:
			out << "occupationwar_staking"; 
			break;
		case mrpce_log_item_update_type::occupationwar_unstaking:
			out << "occupationwar_unstaking"; 
			break;
		case mrpce_log_item_update_type::occupationwar_staking_failed:
			out << "occupationwar_staking_failed"; 
			break;
		case mrpce_log_item_update_type::boss_staking:
			out << "boss_staking"; 
			break;
		case mrpce_log_item_update_type::boss_unstaking:
			out << "boss_unstaking"; 
			break;
		case mrpce_log_item_update_type::boss_staking_failed:
			out << "boss_staking_failed"; 
			break;
		case mrpce_log_item_update_type::governance_party_staking:
			out << "governance_party_staking"; 
			break;
		case mrpce_log_item_update_type::governance_party_unstaking:
			out << "governance_party_unstaking"; 
			break;
		case mrpce_log_item_update_type::governance_party_staking_fail:
			out << "governance_party_staking_fail"; 
			break;
		case mrpce_log_item_update_type::restore_event:
			out << "restore_event"; 
			break;
		case mrpce_log_item_update_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_log_guild_history_type& value)
	{
		switch (value)
		{
		case mrpce_log_guild_history_type::join:
			out << "join"; 
			break;
		case mrpce_log_guild_history_type::approval:
			out << "approval"; 
			break;
		case mrpce_log_guild_history_type::refusal:
			out << "refusal"; 
			break;
		case mrpce_log_guild_history_type::invite:
			out << "invite"; 
			break;
		case mrpce_log_guild_history_type::leave:
			out << "leave"; 
			break;
		case mrpce_log_guild_history_type::ban:
			out << "ban"; 
			break;
		case mrpce_log_guild_history_type::beginner:
			out << "beginner"; 
			break;
		case mrpce_log_guild_history_type::delete_guild:
			out << "delete_guild"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_send_packet_type& value)
	{
		switch (value)
		{
		case mrpce_send_packet_type::none:
			out << "none"; 
			break;
		case mrpce_send_packet_type::database:
			out << "database"; 
			break;
		case mrpce_send_packet_type::all:
			out << "all"; 
			break;
		case mrpce_send_packet_type::autosave:
			out << "autosave"; 
			break;
		case mrpce_send_packet_type::client:
			out << "client"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_character_delete_progress& value)
	{
		switch (value)
		{
		case mrpce_character_delete_progress::none:
			out << "none"; 
			break;
		case mrpce_character_delete_progress::delete_wait:
			out << "delete_wait"; 
			break;
		case mrpce_character_delete_progress::delete_start:
			out << "delete_start"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_quest_type& value)
	{
		switch (value)
		{
		case mrpce_quest_type::main:
			out << "main"; 
			break;
		case mrpce_quest_type::sub:
			out << "sub"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_auto_matching_type& value)
	{
		switch (value)
		{
		case mrpce_auto_matching_type::boss_dungeon:
			out << "boss_dungeon"; 
			break;
		case mrpce_auto_matching_type::arena_battle:
			out << "arena_battle"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_reserved_mail_state_type& value)
	{
		switch (value)
		{
		case mrpce_reserved_mail_state_type::wait:
			out << "wait"; 
			break;
		case mrpce_reserved_mail_state_type::complete:
			out << "complete"; 
			break;
		case mrpce_reserved_mail_state_type::cancel:
			out << "cancel"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_community_object_message_type& value)
	{
		switch (value)
		{
		case mrpce_community_object_message_type::none:
			out << "none"; 
			break;
		case mrpce_community_object_message_type::street_stall_end_req:
			out << "street_stall_end_req"; 
			break;
		case mrpce_community_object_message_type::street_stall_end_res:
			out << "street_stall_end_res"; 
			break;
		case mrpce_community_object_message_type::update_chracter_street_stall_reset_time:
			out << "update_chracter_street_stall_reset_time"; 
			break;
		case mrpce_community_object_message_type::add_zone_party_member:
			out << "add_zone_party_member"; 
			break;
		case mrpce_community_object_message_type::del_zone_party_member:
			out << "del_zone_party_member"; 
			break;
		case mrpce_community_object_message_type::event_ingame:
			out << "event_ingame"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_security_level& value)
	{
		switch (value)
		{
		case mrpce_security_level::ban:
			out << "ban"; 
			break;
		case mrpce_security_level::player:
			out << "player"; 
			break;
		case mrpce_security_level::moderator:
			out << "moderator"; 
			break;
		case mrpce_security_level::gamemaster:
			out << "gamemaster"; 
			break;
		case mrpce_security_level::administrator:
			out << "administrator"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_cheatkey_type& value)
	{
		switch (value)
		{
		case mrpce_cheatkey_type::monster_drop:
			out << "monster_drop"; 
			break;
		case mrpce_cheatkey_type::random_box:
			out << "random_box"; 
			break;
		case mrpce_cheatkey_type::reflection_mix:
			out << "reflection_mix"; 
			break;
		case mrpce_cheatkey_type::pet_mix:
			out << "pet_mix"; 
			break;
		case mrpce_cheatkey_type::stone_slot_open:
			out << "stone_slot_open"; 
			break;
		case mrpce_cheatkey_type::stone_compose:
			out << "stone_compose"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_occupationwar_info_type& value)
	{
		switch (value)
		{
		case mrpce_occupationwar_info_type::none:
			out << "none"; 
			break;
		case mrpce_occupationwar_info_type::initialize:
			out << "initialize"; 
			break;
		case mrpce_occupationwar_info_type::next_league:
			out << "next_league"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_occupationwar_war_schedule_noti_type& value)
	{
		switch (value)
		{
		case mrpce_occupationwar_war_schedule_noti_type::none:
			out << "none"; 
			break;
		case mrpce_occupationwar_war_schedule_noti_type::noti:
			out << "noti"; 
			break;
		case mrpce_occupationwar_war_schedule_noti_type::count:
			out << "count"; 
			break;
		case mrpce_occupationwar_war_schedule_noti_type::start:
			out << "start"; 
			break;
		case mrpce_occupationwar_war_schedule_noti_type::finish:
			out << "finish"; 
			break;
		case mrpce_occupationwar_war_schedule_noti_type::next:
			out << "next"; 
			break;
		case mrpce_occupationwar_war_schedule_noti_type::challenge_start:
			out << "challenge_start"; 
			break;
		case mrpce_occupationwar_war_schedule_noti_type::challenge_open:
			out << "challenge_open"; 
			break;
		case mrpce_occupationwar_war_schedule_noti_type::governance:
			out << "governance"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_exchange_sell_state& value)
	{
		switch (value)
		{
		case mrpce_exchange_sell_state::standby:
			out << "standby"; 
			break;
		case mrpce_exchange_sell_state::sale:
			out << "sale"; 
			break;
		case mrpce_exchange_sell_state::completed:
			out << "completed"; 
			break;
		case mrpce_exchange_sell_state::expire:
			out << "expire"; 
			break;
		case mrpce_exchange_sell_state::cancel:
			out << "cancel"; 
			break;
		case mrpce_exchange_sell_state::contract_buy:
			out << "contract_buy"; 
			break;
		case mrpce_exchange_sell_state::contract_gold:
			out << "contract_gold"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_exchange_contract_log_state& value)
	{
		switch (value)
		{
		case mrpce_exchange_contract_log_state::request:
			out << "request"; 
			break;
		case mrpce_exchange_contract_log_state::completed_contaract:
			out << "completed_contaract"; 
			break;
		case mrpce_exchange_contract_log_state::failed_contaract:
			out << "failed_contaract"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_token_type& value)
	{
		switch (value)
		{
		case mrpce_token_type::none:
			out << "none"; 
			break;
		case mrpce_token_type::drone:
			out << "drone"; 
			break;
		case mrpce_token_type::hydra:
			out << "hydra"; 
			break;
		case mrpce_token_type::dogma:
			out << "dogma"; 
			break;
		case mrpce_token_type::wemix_doller:
			out << "wemix_doller"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_contract_type& value)
	{
		switch (value)
		{
		case mrpce_contract_type::none:
			out << "none"; 
			break;
		case mrpce_contract_type::drone:
			out << "drone"; 
			break;
		case mrpce_contract_type::hydra:
			out << "hydra"; 
			break;
		case mrpce_contract_type::divine:
			out << "divine"; 
			break;
		case mrpce_contract_type::governance:
			out << "governance"; 
			break;
		case mrpce_contract_type::exchange:
			out << "exchange"; 
			break;
		case mrpce_contract_type::swap:
			out << "swap"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_contract_all_votes_type& value)
	{
		switch (value)
		{
		case mrpce_contract_all_votes_type::purposes:
			out << "purposes"; 
			break;
		case mrpce_contract_all_votes_type::votes:
			out << "votes"; 
			break;
		case mrpce_contract_all_votes_type::vote_time:
			out << "vote_time"; 
			break;
		case mrpce_contract_all_votes_type::cancel_time:
			out << "cancel_time"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_contract_user_vote_type& value)
	{
		switch (value)
		{
		case mrpce_contract_user_vote_type::vote:
			out << "vote"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_global_ccu_type& value)
	{
		switch (value)
		{
		case mrpce_global_ccu_type::game:
			out << "game"; 
			break;
		case mrpce_global_ccu_type::inden:
			out << "inden"; 
			break;
		case mrpce_global_ccu_type::lobby:
			out << "lobby"; 
			break;
		case mrpce_global_ccu_type::total:
			out << "total"; 
			break;
		case mrpce_global_ccu_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_token_type_client& value)
	{
		switch (value)
		{
		case mrpce_token_type_client::none:
			out << "none"; 
			break;
		case mrpce_token_type_client::drone:
			out << "drone"; 
			break;
		case mrpce_token_type_client::hydra:
			out << "hydra"; 
			break;
		case mrpce_token_type_client::dogma:
			out << "dogma"; 
			break;
		case mrpce_token_type_client::wemix_doller:
			out << "wemix_doller"; 
			break;
		case mrpce_token_type_client::swap_range_start:
			out << "swap_range_start"; 
			break;
		case mrpce_token_type_client::w_flero:
			out << "w_flero"; 
			break;
		case mrpce_token_type_client::w_sloco:
			out << "w_sloco"; 
			break;
		case mrpce_token_type_client::w_lordcoin:
			out << "w_lordcoin"; 
			break;
		case mrpce_token_type_client::w_herco:
			out << "w_herco"; 
			break;
		case mrpce_token_type_client::w_gbmilico:
			out << "w_gbmilico"; 
			break;
		case mrpce_token_type_client::w_mco:
			out << "w_mco"; 
			break;
		case mrpce_token_type_client::w_tornado_token:
			out << "w_tornado_token"; 
			break;
		case mrpce_token_type_client::w_tig:
			out << "w_tig"; 
			break;
		case mrpce_token_type_client::w_stc:
			out << "w_stc"; 
			break;
		case mrpce_token_type_client::w_ros_silthereum:
			out << "w_ros_silthereum"; 
			break;
		case mrpce_token_type_client::w_ranaia_ria:
			out << "w_ranaia_ria"; 
			break;
		case mrpce_token_type_client::w_reflect_token:
			out << "w_reflect_token"; 
			break;
		case mrpce_token_type_client::w_wemix_token_away:
			out << "w_wemix_token_away"; 
			break;
		case mrpce_token_type_client::w_four_gods_lux:
			out << "w_four_gods_lux"; 
			break;
		case mrpce_token_type_client::w_incar:
			out << "w_incar"; 
			break;
		case mrpce_token_type_client::w_mir4_hydra:
			out << "w_mir4_hydra"; 
			break;
		case mrpce_token_type_client::w_honco:
			out << "w_honco"; 
			break;
		case mrpce_token_type_client::w_drone:
			out << "w_drone"; 
			break;
		case mrpce_token_type_client::w_mir4_darksteel:
			out << "w_mir4_darksteel"; 
			break;
		case mrpce_token_type_client::w_dogma:
			out << "w_dogma"; 
			break;
		case mrpce_token_type_client::w_darkeden_mdebco:
			out << "w_darkeden_mdebco"; 
			break;
		case mrpce_token_type_client::w_cqb:
			out << "w_cqb"; 
			break;
		case mrpce_token_type_client::w_blz:
			out << "w_blz"; 
			break;
		case mrpce_token_type_client::w_asu_anitas:
			out << "w_asu_anitas"; 
			break;
		case mrpce_token_type_client::w_abyco:
			out << "w_abyco"; 
			break;
		case mrpce_token_type_client::w_myrtle:
			out << "w_myrtle"; 
			break;
		case mrpce_token_type_client::w_bluepaw:
			out << "w_bluepaw"; 
			break;
		case mrpce_token_type_client::w_zuanshi:
			out << "w_zuanshi"; 
			break;
		case mrpce_token_type_client::swap_range_end:
			out << "swap_range_end"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_scheduler_contents_type& value)
	{
		switch (value)
		{
		case mrpce_scheduler_contents_type::none:
			out << "none"; 
			break;
		case mrpce_scheduler_contents_type::arena_battle:
			out << "arena_battle"; 
			break;
		case mrpce_scheduler_contents_type::guild_battle:
			out << "guild_battle"; 
			break;
		case mrpce_scheduler_contents_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_contents_ticket_type& value)
	{
		switch (value)
		{
		case mrpce_contents_ticket_type::none:
			out << "none"; 
			break;
		case mrpce_contents_ticket_type::darksteel_mining_bicheon:
			out << "darksteel_mining_bicheon"; 
			break;
		case mrpce_contents_ticket_type::darksteel_mining_snakevalley:
			out << "darksteel_mining_snakevalley"; 
			break;
		case mrpce_contents_ticket_type::darksteel_mining_mongchon:
			out << "darksteel_mining_mongchon"; 
			break;
		case mrpce_contents_ticket_type::darksteel_mining_reserve_1:
			out << "darksteel_mining_reserve_1"; 
			break;
		case mrpce_contents_ticket_type::darksteel_mining_reserve_2:
			out << "darksteel_mining_reserve_2"; 
			break;
		case mrpce_contents_ticket_type::exchange_certificate:
			out << "exchange_certificate"; 
			break;
		case mrpce_contents_ticket_type::exchange_gold_certificate:
			out << "exchange_gold_certificate"; 
			break;
		case mrpce_contents_ticket_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_darksteel_mining_type& value)
	{
		switch (value)
		{
		case mrpce_darksteel_mining_type::none:
			out << "none"; 
			break;
		case mrpce_darksteel_mining_type::bicheon:
			out << "bicheon"; 
			break;
		case mrpce_darksteel_mining_type::snakevalley:
			out << "snakevalley"; 
			break;
		case mrpce_darksteel_mining_type::mongchon:
			out << "mongchon"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_darksteel_mining_bit_value& value)
	{
		switch (value)
		{
		case mrpce_darksteel_mining_bit_value::none:
			out << "none"; 
			break;
		case mrpce_darksteel_mining_bit_value::bicheon:
			out << "bicheon"; 
			break;
		case mrpce_darksteel_mining_bit_value::snakevalley:
			out << "snakevalley"; 
			break;
		case mrpce_darksteel_mining_bit_value::mongchon:
			out << "mongchon"; 
			break;
		case mrpce_darksteel_mining_bit_value::reserve:
			out << "reserve"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_global_governance_command_type& value)
	{
		switch (value)
		{
		case mrpce_global_governance_command_type::none:
			out << "none"; 
			break;
		case mrpce_global_governance_command_type::governance_execute:
			out << "governance_execute"; 
			break;
		case mrpce_global_governance_command_type::governance_db_reload:
			out << "governance_db_reload"; 
			break;
		case mrpce_global_governance_command_type::governance_result_broadcast:
			out << "governance_result_broadcast"; 
			break;
		case mrpce_global_governance_command_type::governance_result_request:
			out << "governance_result_request"; 
			break;
		case mrpce_global_governance_command_type::staking:
			out << "staking"; 
			break;
		case mrpce_global_governance_command_type::unstaking:
			out << "unstaking"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_inventory_pocket_type& value)
	{
		switch (value)
		{
		case mpe_inventory_pocket_type::none:
			out << "none"; 
			break;
		case mpe_inventory_pocket_type::main:
			out << "main"; 
			break;
		case mpe_inventory_pocket_type::stone:
			out << "stone"; 
			break;
		case mpe_inventory_pocket_type::essence:
			out << "essence"; 
			break;
		case mpe_inventory_pocket_type::costume:
			out << "costume"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_gm_subscription_day_type& value)
	{
		switch (value)
		{
		case mrpce_gm_subscription_day_type::none:
			out << "none"; 
			break;
		case mrpce_gm_subscription_day_type::day_week:
			out << "day_week"; 
			break;
		case mrpce_gm_subscription_day_type::day_month:
			out << "day_month"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_dimension_dungeon_state_type& value)
	{
		switch (value)
		{
		case mrpce_dimension_dungeon_state_type::none:
			out << "none"; 
			break;
		case mrpce_dimension_dungeon_state_type::open:
			out << "open"; 
			break;
		case mrpce_dimension_dungeon_state_type::close:
			out << "close"; 
			break;
		case mrpce_dimension_dungeon_state_type::standby:
			out << "standby"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_ranking_update_type& value)
	{
		switch (value)
		{
		case mrpce_ranking_update_type::upsert:
			out << "upsert"; 
			break;
		case mrpce_ranking_update_type::increase:
			out << "increase"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_build_tool_type& value)
	{
		switch (value)
		{
		case mrpce_build_tool_type::none:
			out << "none"; 
			break;
		case mrpce_build_tool_type::client:
			out << "client"; 
			break;
		case mrpce_build_tool_type::builder:
			out << "builder"; 
			break;
		case mrpce_build_tool_type::launcher:
			out << "launcher"; 
			break;
		case mrpce_build_tool_type::normal:
			out << "normal"; 
			break;
		case mrpce_build_tool_type::developer:
			out << "developer"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_build_tool_command& value)
	{
		switch (value)
		{
		case mrpce_build_tool_command::none:
			out << "none"; 
			break;
		case mrpce_build_tool_command::build_create:
			out << "build_create"; 
			break;
		case mrpce_build_tool_command::build_process:
			out << "build_process"; 
			break;
		case mrpce_build_tool_command::build_result:
			out << "build_result"; 
			break;
		case mrpce_build_tool_command::build_table:
			out << "build_table"; 
			break;
		case mrpce_build_tool_command::build_meta:
			out << "build_meta"; 
			break;
		case mrpce_build_tool_command::server_control_unzip:
			out << "server_control_unzip"; 
			break;
		case mrpce_build_tool_command::server_control_start:
			out << "server_control_start"; 
			break;
		case mrpce_build_tool_command::server_control_kill:
			out << "server_control_kill"; 
			break;
		case mrpce_build_tool_command::server_control_config:
			out << "server_control_config"; 
			break;
		case mrpce_build_tool_command::server_control_ssdt:
			out << "server_control_ssdt"; 
			break;
		case mrpce_build_tool_command::server_control_time_edit:
			out << "server_control_time_edit"; 
			break;
		case mrpce_build_tool_command::server_control_time_sync_info:
			out << "server_control_time_sync_info"; 
			break;
		case mrpce_build_tool_command::file_upload:
			out << "file_upload"; 
			break;
		case mrpce_build_tool_command::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mrpce_build_tool_command_state& value)
	{
		switch (value)
		{
		case mrpce_build_tool_command_state::none:
			out << "none"; 
			break;
		case mrpce_build_tool_command_state::start:
			out << "start"; 
			break;
		case mrpce_build_tool_command_state::progress:
			out << "progress"; 
			break;
		case mrpce_build_tool_command_state::finish:
			out << "finish"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

}
