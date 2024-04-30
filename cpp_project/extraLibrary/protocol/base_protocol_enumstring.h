#pragma once
#include <ostream>
#include <protocol/base_protocol.h>
#include <protocol/rpc_protocol.h>

namespace mir3d
{
	static std::ostream& operator << (std::ostream& out, const mpe_cmd& value)
	{
		switch (value)
		{
		case mpe_cmd::none:
			out << "none"; 
			break;
		case mpe_cmd::login_gamelogin_cs:
			out << "login_gamelogin_cs"; 
			break;
		case mpe_cmd::login_gamelogin_sc:
			out << "login_gamelogin_sc"; 
			break;
		case mpe_cmd::game_login_cs:
			out << "game_login_cs"; 
			break;
		case mpe_cmd::game_login_sc:
			out << "game_login_sc"; 
			break;
		case mpe_cmd::session_certify_cs:
			out << "session_certify_cs"; 
			break;
		case mpe_cmd::session_certify_sc:
			out << "session_certify_sc"; 
			break;
		case mpe_cmd::session_open_cs:
			out << "session_open_cs"; 
			break;
		case mpe_cmd::session_open_sc:
			out << "session_open_sc"; 
			break;
		case mpe_cmd::zone_enter_cs:
			out << "zone_enter_cs"; 
			break;
		case mpe_cmd::zone_enter_sc:
			out << "zone_enter_sc"; 
			break;
		case mpe_cmd::zone_enter_ready_cs:
			out << "zone_enter_ready_cs"; 
			break;
		case mpe_cmd::zone_enter_ready_sc:
			out << "zone_enter_ready_sc"; 
			break;
		case mpe_cmd::zone_object_loding_cs:
			out << "zone_object_loding_cs"; 
			break;
		case mpe_cmd::zone_object_loding_sc:
			out << "zone_object_loding_sc"; 
			break;
		case mpe_cmd::zone_leave_cs:
			out << "zone_leave_cs"; 
			break;
		case mpe_cmd::zone_leave_sc:
			out << "zone_leave_sc"; 
			break;
		case mpe_cmd::zone_move_cs:
			out << "zone_move_cs"; 
			break;
		case mpe_cmd::zone_move_sc:
			out << "zone_move_sc"; 
			break;
		case mpe_cmd::zone_tile_check_cs:
			out << "zone_tile_check_cs"; 
			break;
		case mpe_cmd::zone_tile_check_sc:
			out << "zone_tile_check_sc"; 
			break;
		case mpe_cmd::zone_object_move_cs:
			out << "zone_object_move_cs"; 
			break;
		case mpe_cmd::zone_object_move_sc:
			out << "zone_object_move_sc"; 
			break;
		case mpe_cmd::skill_start_cs:
			out << "skill_start_cs"; 
			break;
		case mpe_cmd::skill_start_sc:
			out << "skill_start_sc"; 
			break;
		case mpe_cmd::skill_damage_result_cs:
			out << "skill_damage_result_cs"; 
			break;
		case mpe_cmd::skill_damage_result_sc:
			out << "skill_damage_result_sc"; 
			break;
		case mpe_cmd::error_message_cs:
			out << "error_message_cs"; 
			break;
		case mpe_cmd::error_message_sc:
			out << "error_message_sc"; 
			break;
		case mpe_cmd::character_behavior_cs:
			out << "character_behavior_cs"; 
			break;
		case mpe_cmd::character_behavior_sc:
			out << "character_behavior_sc"; 
			break;
		case mpe_cmd::character_pk_color_cs:
			out << "character_pk_color_cs"; 
			break;
		case mpe_cmd::character_pk_color_sc:
			out << "character_pk_color_sc"; 
			break;
		case mpe_cmd::character_power_cs:
			out << "character_power_cs"; 
			break;
		case mpe_cmd::character_power_sc:
			out << "character_power_sc"; 
			break;
		case mpe_cmd::gameitem_update_cs:
			out << "gameitem_update_cs"; 
			break;
		case mpe_cmd::gameitem_update_sc:
			out << "gameitem_update_sc"; 
			break;
		case mpe_cmd::goods_update_cs:
			out << "goods_update_cs"; 
			break;
		case mpe_cmd::goods_update_sc:
			out << "goods_update_sc"; 
			break;
		case mpe_cmd::indun_enter_cs:
			out << "indun_enter_cs"; 
			break;
		case mpe_cmd::indun_enter_sc:
			out << "indun_enter_sc"; 
			break;
		case mpe_cmd::indun_enter_complete_cs:
			out << "indun_enter_complete_cs"; 
			break;
		case mpe_cmd::indun_enter_complete_sc:
			out << "indun_enter_complete_sc"; 
			break;
		case mpe_cmd::inven_expansion_cs:
			out << "inven_expansion_cs"; 
			break;
		case mpe_cmd::inven_expansion_sc:
			out << "inven_expansion_sc"; 
			break;
		case mpe_cmd::inven_weight_expansion_cs:
			out << "inven_weight_expansion_cs"; 
			break;
		case mpe_cmd::inven_weight_expansion_sc:
			out << "inven_weight_expansion_sc"; 
			break;
		case mpe_cmd::item_buy_cs:
			out << "item_buy_cs"; 
			break;
		case mpe_cmd::item_buy_sc:
			out << "item_buy_sc"; 
			break;
		case mpe_cmd::item_enchant_option_make_cs:
			out << "item_enchant_option_make_cs"; 
			break;
		case mpe_cmd::item_enchant_option_make_sc:
			out << "item_enchant_option_make_sc"; 
			break;
		case mpe_cmd::item_enchant_option_select_cs:
			out << "item_enchant_option_select_cs"; 
			break;
		case mpe_cmd::item_enchant_option_select_sc:
			out << "item_enchant_option_select_sc"; 
			break;
		case mpe_cmd::item_decompose_cs:
			out << "item_decompose_cs"; 
			break;
		case mpe_cmd::item_decompose_sc:
			out << "item_decompose_sc"; 
			break;
		case mpe_cmd::item_destroy_cs:
			out << "item_destroy_cs"; 
			break;
		case mpe_cmd::item_destroy_sc:
			out << "item_destroy_sc"; 
			break;
		case mpe_cmd::item_enchant_option_cancel_cs:
			out << "item_enchant_option_cancel_cs"; 
			break;
		case mpe_cmd::item_enchant_option_cancel_sc:
			out << "item_enchant_option_cancel_sc"; 
			break;
		case mpe_cmd::item_equip_cs:
			out << "item_equip_cs"; 
			break;
		case mpe_cmd::item_equip_sc:
			out << "item_equip_sc"; 
			break;
		case mpe_cmd::item_luck_reinforce_cs:
			out << "item_luck_reinforce_cs"; 
			break;
		case mpe_cmd::item_luck_reinforce_sc:
			out << "item_luck_reinforce_sc"; 
			break;
		case mpe_cmd::item_make_cs:
			out << "item_make_cs"; 
			break;
		case mpe_cmd::item_make_sc:
			out << "item_make_sc"; 
			break;
		case mpe_cmd::item_reinforce_cs:
			out << "item_reinforce_cs"; 
			break;
		case mpe_cmd::item_reinforce_sc:
			out << "item_reinforce_sc"; 
			break;
		case mpe_cmd::item_sell_cs:
			out << "item_sell_cs"; 
			break;
		case mpe_cmd::item_sell_sc:
			out << "item_sell_sc"; 
			break;
		case mpe_cmd::item_use_cs:
			out << "item_use_cs"; 
			break;
		case mpe_cmd::item_use_sc:
			out << "item_use_sc"; 
			break;
		case mpe_cmd::map_discovery_info_cs:
			out << "map_discovery_info_cs"; 
			break;
		case mpe_cmd::map_discovery_info_sc:
			out << "map_discovery_info_sc"; 
			break;
		case mpe_cmd::map_discovery_update_cs:
			out << "map_discovery_update_cs"; 
			break;
		case mpe_cmd::map_discovery_update_sc:
			out << "map_discovery_update_sc"; 
			break;
		case mpe_cmd::profesion_make_cs:
			out << "profesion_make_cs"; 
			break;
		case mpe_cmd::profesion_make_sc:
			out << "profesion_make_sc"; 
			break;
		case mpe_cmd::profesion_reset_cs:
			out << "profesion_reset_cs"; 
			break;
		case mpe_cmd::profesion_reset_sc:
			out << "profesion_reset_sc"; 
			break;
		case mpe_cmd::profesion_upgrade_cs:
			out << "profesion_upgrade_cs"; 
			break;
		case mpe_cmd::profesion_upgrade_sc:
			out << "profesion_upgrade_sc"; 
			break;
		case mpe_cmd::redirect_notify_cs:
			out << "redirect_notify_cs"; 
			break;
		case mpe_cmd::redirect_notify_sc:
			out << "redirect_notify_sc"; 
			break;
		case mpe_cmd::redirect_request_cs:
			out << "redirect_request_cs"; 
			break;
		case mpe_cmd::redirect_request_sc:
			out << "redirect_request_sc"; 
			break;
		case mpe_cmd::test_game_login_cs:
			out << "test_game_login_cs"; 
			break;
		case mpe_cmd::test_game_login_sc:
			out << "test_game_login_sc"; 
			break;
		case mpe_cmd::zone_change_enter_cs:
			out << "zone_change_enter_cs"; 
			break;
		case mpe_cmd::zone_change_enter_sc:
			out << "zone_change_enter_sc"; 
			break;
		case mpe_cmd::zone_character_drop_cs:
			out << "zone_character_drop_cs"; 
			break;
		case mpe_cmd::zone_character_drop_sc:
			out << "zone_character_drop_sc"; 
			break;
		case mpe_cmd::zone_character_item_equip_cs:
			out << "zone_character_item_equip_cs"; 
			break;
		case mpe_cmd::zone_character_item_equip_sc:
			out << "zone_character_item_equip_sc"; 
			break;
		case mpe_cmd::zone_character_minion_info_cs:
			out << "zone_character_minion_info_cs"; 
			break;
		case mpe_cmd::zone_character_minion_info_sc:
			out << "zone_character_minion_info_sc"; 
			break;
		case mpe_cmd::zone_collect_info_cs:
			out << "zone_collect_info_cs"; 
			break;
		case mpe_cmd::zone_collect_info_sc:
			out << "zone_collect_info_sc"; 
			break;
		case mpe_cmd::zone_dropitem_remove_cs:
			out << "zone_dropitem_remove_cs"; 
			break;
		case mpe_cmd::zone_dropitem_remove_sc:
			out << "zone_dropitem_remove_sc"; 
			break;
		case mpe_cmd::zone_drop_item_info_cs:
			out << "zone_drop_item_info_cs"; 
			break;
		case mpe_cmd::zone_drop_item_info_sc:
			out << "zone_drop_item_info_sc"; 
			break;
		case mpe_cmd::zone_item_pickup_cs:
			out << "zone_item_pickup_cs"; 
			break;
		case mpe_cmd::zone_item_pickup_sc:
			out << "zone_item_pickup_sc"; 
			break;
		case mpe_cmd::zone_monster_info_cs:
			out << "zone_monster_info_cs"; 
			break;
		case mpe_cmd::zone_monster_info_sc:
			out << "zone_monster_info_sc"; 
			break;
		case mpe_cmd::zone_npc_info_cs:
			out << "zone_npc_info_cs"; 
			break;
		case mpe_cmd::zone_npc_info_sc:
			out << "zone_npc_info_sc"; 
			break;
		case mpe_cmd::zone_object_collect_cs:
			out << "zone_object_collect_cs"; 
			break;
		case mpe_cmd::zone_object_collect_sc:
			out << "zone_object_collect_sc"; 
			break;
		case mpe_cmd::zone_object_dead_cs:
			out << "zone_object_dead_cs"; 
			break;
		case mpe_cmd::zone_object_dead_sc:
			out << "zone_object_dead_sc"; 
			break;
		case mpe_cmd::zone_player_info_cs:
			out << "zone_player_info_cs"; 
			break;
		case mpe_cmd::zone_player_info_sc:
			out << "zone_player_info_sc"; 
			break;
		case mpe_cmd::zone_revive_cs:
			out << "zone_revive_cs"; 
			break;
		case mpe_cmd::zone_revive_sc:
			out << "zone_revive_sc"; 
			break;
		case mpe_cmd::zone_teleport_cs:
			out << "zone_teleport_cs"; 
			break;
		case mpe_cmd::zone_teleport_sc:
			out << "zone_teleport_sc"; 
			break;
		case mpe_cmd::zone_safety_state_cs:
			out << "zone_safety_state_cs"; 
			break;
		case mpe_cmd::zone_safety_state_sc:
			out << "zone_safety_state_sc"; 
			break;
		case mpe_cmd::guild_create_cs:
			out << "guild_create_cs"; 
			break;
		case mpe_cmd::guild_create_sc:
			out << "guild_create_sc"; 
			break;
		case mpe_cmd::guild_join_request_cs:
			out << "guild_join_request_cs"; 
			break;
		case mpe_cmd::guild_join_request_sc:
			out << "guild_join_request_sc"; 
			break;
		case mpe_cmd::guild_accept_member_cs:
			out << "guild_accept_member_cs"; 
			break;
		case mpe_cmd::guild_accept_member_sc:
			out << "guild_accept_member_sc"; 
			break;
		case mpe_cmd::guild_join_cancel_cs:
			out << "guild_join_cancel_cs"; 
			break;
		case mpe_cmd::guild_join_cancel_sc:
			out << "guild_join_cancel_sc"; 
			break;
		case mpe_cmd::guild_recommend_cs:
			out << "guild_recommend_cs"; 
			break;
		case mpe_cmd::guild_recommend_sc:
			out << "guild_recommend_sc"; 
			break;
		case mpe_cmd::guild_request_guild_list_cs:
			out << "guild_request_guild_list_cs"; 
			break;
		case mpe_cmd::guild_request_guild_list_sc:
			out << "guild_request_guild_list_sc"; 
			break;
		case mpe_cmd::guild_add_exp_cs:
			out << "guild_add_exp_cs"; 
			break;
		case mpe_cmd::guild_add_exp_sc:
			out << "guild_add_exp_sc"; 
			break;
		case mpe_cmd::guild_member_list_cs:
			out << "guild_member_list_cs"; 
			break;
		case mpe_cmd::guild_member_list_sc:
			out << "guild_member_list_sc"; 
			break;
		case mpe_cmd::guild_info_cs:
			out << "guild_info_cs"; 
			break;
		case mpe_cmd::guild_info_sc:
			out << "guild_info_sc"; 
			break;
		case mpe_cmd::guild_ban_cs:
			out << "guild_ban_cs"; 
			break;
		case mpe_cmd::guild_ban_sc:
			out << "guild_ban_sc"; 
			break;
		case mpe_cmd::guild_leave_cs:
			out << "guild_leave_cs"; 
			break;
		case mpe_cmd::guild_leave_sc:
			out << "guild_leave_sc"; 
			break;
		case mpe_cmd::guild_search_cs:
			out << "guild_search_cs"; 
			break;
		case mpe_cmd::guild_search_sc:
			out << "guild_search_sc"; 
			break;
		case mpe_cmd::guild_change_join_condition_cs:
			out << "guild_change_join_condition_cs"; 
			break;
		case mpe_cmd::guild_change_join_condition_sc:
			out << "guild_change_join_condition_sc"; 
			break;
		case mpe_cmd::guild_change_member_grade_cs:
			out << "guild_change_member_grade_cs"; 
			break;
		case mpe_cmd::guild_change_member_grade_sc:
			out << "guild_change_member_grade_sc"; 
			break;
		case mpe_cmd::party_create_cs:
			out << "party_create_cs"; 
			break;
		case mpe_cmd::party_create_sc:
			out << "party_create_sc"; 
			break;
		case mpe_cmd::party_info_cs:
			out << "party_info_cs"; 
			break;
		case mpe_cmd::party_info_sc:
			out << "party_info_sc"; 
			break;
		case mpe_cmd::party_invite_request_cs:
			out << "party_invite_request_cs"; 
			break;
		case mpe_cmd::party_invite_request_sc:
			out << "party_invite_request_sc"; 
			break;
		case mpe_cmd::party_invite_agree_cs:
			out << "party_invite_agree_cs"; 
			break;
		case mpe_cmd::party_invite_agree_sc:
			out << "party_invite_agree_sc"; 
			break;
		case mpe_cmd::party_invite_cancel_cs:
			out << "party_invite_cancel_cs"; 
			break;
		case mpe_cmd::party_invite_cancel_sc:
			out << "party_invite_cancel_sc"; 
			break;
		case mpe_cmd::party_invite_refuse_cs:
			out << "party_invite_refuse_cs"; 
			break;
		case mpe_cmd::party_invite_refuse_sc:
			out << "party_invite_refuse_sc"; 
			break;
		case mpe_cmd::party_enter_request_cs:
			out << "party_enter_request_cs"; 
			break;
		case mpe_cmd::party_enter_request_sc:
			out << "party_enter_request_sc"; 
			break;
		case mpe_cmd::party_enter_cancel_cs:
			out << "party_enter_cancel_cs"; 
			break;
		case mpe_cmd::party_enter_cancel_sc:
			out << "party_enter_cancel_sc"; 
			break;
		case mpe_cmd::party_enter_agree_sc:
			out << "party_enter_agree_sc"; 
			break;
		case mpe_cmd::party_enter_agree_cs:
			out << "party_enter_agree_cs"; 
			break;
		case mpe_cmd::party_enter_refuse_cs:
			out << "party_enter_refuse_cs"; 
			break;
		case mpe_cmd::party_enter_refuse_sc:
			out << "party_enter_refuse_sc"; 
			break;
		case mpe_cmd::party_destroy_cs:
			out << "party_destroy_cs"; 
			break;
		case mpe_cmd::party_destroy_sc:
			out << "party_destroy_sc"; 
			break;
		case mpe_cmd::party_pr_cs:
			out << "party_pr_cs"; 
			break;
		case mpe_cmd::party_pr_sc:
			out << "party_pr_sc"; 
			break;
		case mpe_cmd::party_leave_cs:
			out << "party_leave_cs"; 
			break;
		case mpe_cmd::party_leave_sc:
			out << "party_leave_sc"; 
			break;
		case mpe_cmd::party_member_ban_cs:
			out << "party_member_ban_cs"; 
			break;
		case mpe_cmd::party_member_ban_sc:
			out << "party_member_ban_sc"; 
			break;
		case mpe_cmd::party_owner_change_cs:
			out << "party_owner_change_cs"; 
			break;
		case mpe_cmd::party_owner_change_sc:
			out << "party_owner_change_sc"; 
			break;
		case mpe_cmd::party_enter_request_list_cs:
			out << "party_enter_request_list_cs"; 
			break;
		case mpe_cmd::party_enter_request_list_sc:
			out << "party_enter_request_list_sc"; 
			break;
		case mpe_cmd::party_enter_requestors_cs:
			out << "party_enter_requestors_cs"; 
			break;
		case mpe_cmd::party_enter_requestors_sc:
			out << "party_enter_requestors_sc"; 
			break;
		case mpe_cmd::party_setup_cs:
			out << "party_setup_cs"; 
			break;
		case mpe_cmd::party_setup_sc:
			out << "party_setup_sc"; 
			break;
		case mpe_cmd::indun_prepare_request_cs:
			out << "indun_prepare_request_cs"; 
			break;
		case mpe_cmd::indun_prepare_request_sc:
			out << "indun_prepare_request_sc"; 
			break;
		case mpe_cmd::indun_prepare_enter_cs:
			out << "indun_prepare_enter_cs"; 
			break;
		case mpe_cmd::indun_prepare_enter_sc:
			out << "indun_prepare_enter_sc"; 
			break;
		case mpe_cmd::indun_stage_cs:
			out << "indun_stage_cs"; 
			break;
		case mpe_cmd::indun_stage_sc:
			out << "indun_stage_sc"; 
			break;
		case mpe_cmd::indun_leave_cs:
			out << "indun_leave_cs"; 
			break;
		case mpe_cmd::indun_leave_sc:
			out << "indun_leave_sc"; 
			break;
		case mpe_cmd::indun_reward_cs:
			out << "indun_reward_cs"; 
			break;
		case mpe_cmd::indun_reward_sc:
			out << "indun_reward_sc"; 
			break;
		case mpe_cmd::indun_finish_cs:
			out << "indun_finish_cs"; 
			break;
		case mpe_cmd::indun_finish_sc:
			out << "indun_finish_sc"; 
			break;
		case mpe_cmd::indun_stage_count_cs:
			out << "indun_stage_count_cs"; 
			break;
		case mpe_cmd::indun_stage_count_sc:
			out << "indun_stage_count_sc"; 
			break;
		case mpe_cmd::indun_stage_complete_cs:
			out << "indun_stage_complete_cs"; 
			break;
		case mpe_cmd::indun_stage_complete_sc:
			out << "indun_stage_complete_sc"; 
			break;
		case mpe_cmd::zone_object_update_stat_cs:
			out << "zone_object_update_stat_cs"; 
			break;
		case mpe_cmd::zone_object_update_stat_sc:
			out << "zone_object_update_stat_sc"; 
			break;
		case mpe_cmd::zone_delete_buff_debuff_cs:
			out << "zone_delete_buff_debuff_cs"; 
			break;
		case mpe_cmd::zone_delete_buff_debuff_sc:
			out << "zone_delete_buff_debuff_sc"; 
			break;
		case mpe_cmd::zone_vehicle_cs:
			out << "zone_vehicle_cs"; 
			break;
		case mpe_cmd::zone_vehicle_sc:
			out << "zone_vehicle_sc"; 
			break;
		case mpe_cmd::zone_vehicle_state_cs:
			out << "zone_vehicle_state_cs"; 
			break;
		case mpe_cmd::zone_vehicle_state_sc:
			out << "zone_vehicle_state_sc"; 
			break;
		case mpe_cmd::zone_character_level_up_cs:
			out << "zone_character_level_up_cs"; 
			break;
		case mpe_cmd::zone_character_level_up_sc:
			out << "zone_character_level_up_sc"; 
			break;
		case mpe_cmd::zone_character_expert_level_up_cs:
			out << "zone_character_expert_level_up_cs"; 
			break;
		case mpe_cmd::zone_character_expert_level_up_sc:
			out << "zone_character_expert_level_up_sc"; 
			break;
		case mpe_cmd::skill_learn_cs:
			out << "skill_learn_cs"; 
			break;
		case mpe_cmd::skill_learn_sc:
			out << "skill_learn_sc"; 
			break;
		case mpe_cmd::skill_levelup_cs:
			out << "skill_levelup_cs"; 
			break;
		case mpe_cmd::skill_levelup_sc:
			out << "skill_levelup_sc"; 
			break;
		case mpe_cmd::game_logout_cs:
			out << "game_logout_cs"; 
			break;
		case mpe_cmd::game_logout_sc:
			out << "game_logout_sc"; 
			break;
		case mpe_cmd::quest_accept_cs:
			out << "quest_accept_cs"; 
			break;
		case mpe_cmd::quest_accept_sc:
			out << "quest_accept_sc"; 
			break;
		case mpe_cmd::quest_complete_cs:
			out << "quest_complete_cs"; 
			break;
		case mpe_cmd::quest_complete_sc:
			out << "quest_complete_sc"; 
			break;
		case mpe_cmd::quest_giveup_cs:
			out << "quest_giveup_cs"; 
			break;
		case mpe_cmd::quest_giveup_sc:
			out << "quest_giveup_sc"; 
			break;
		case mpe_cmd::quest_finish_cs:
			out << "quest_finish_cs"; 
			break;
		case mpe_cmd::quest_finish_sc:
			out << "quest_finish_sc"; 
			break;
		case mpe_cmd::server_change_cs:
			out << "server_change_cs"; 
			break;
		case mpe_cmd::server_change_sc:
			out << "server_change_sc"; 
			break;
		case mpe_cmd::redirect_complete_cs:
			out << "redirect_complete_cs"; 
			break;
		case mpe_cmd::redirect_complete_sc:
			out << "redirect_complete_sc"; 
			break;
		case mpe_cmd::zone_fish_cs:
			out << "zone_fish_cs"; 
			break;
		case mpe_cmd::zone_fish_sc:
			out << "zone_fish_sc"; 
			break;
		case mpe_cmd::zone_action_fish_cs:
			out << "zone_action_fish_cs"; 
			break;
		case mpe_cmd::zone_action_fish_sc:
			out << "zone_action_fish_sc"; 
			break;
		case mpe_cmd::zone_daily_content_cs:
			out << "zone_daily_content_cs"; 
			break;
		case mpe_cmd::zone_daily_content_sc:
			out << "zone_daily_content_sc"; 
			break;
		case mpe_cmd::zone_action_state_cs:
			out << "zone_action_state_cs"; 
			break;
		case mpe_cmd::zone_action_state_sc:
			out << "zone_action_state_sc"; 
			break;
		case mpe_cmd::zone_fieldboss_info_cs:
			out << "zone_fieldboss_info_cs"; 
			break;
		case mpe_cmd::zone_fieldboss_info_sc:
			out << "zone_fieldboss_info_sc"; 
			break;
		case mpe_cmd::zone_boss_contribution_cs:
			out << "zone_boss_contribution_cs"; 
			break;
		case mpe_cmd::zone_boss_contribution_sc:
			out << "zone_boss_contribution_sc"; 
			break;
		case mpe_cmd::zone_boss_dead_cs:
			out << "zone_boss_dead_cs"; 
			break;
		case mpe_cmd::zone_boss_dead_sc:
			out << "zone_boss_dead_sc"; 
			break;
		case mpe_cmd::zone_trigger_cs:
			out << "zone_trigger_cs"; 
			break;
		case mpe_cmd::zone_trigger_sc:
			out << "zone_trigger_sc"; 
			break;
		case mpe_cmd::game_setup_cs:
			out << "game_setup_cs"; 
			break;
		case mpe_cmd::game_setup_sc:
			out << "game_setup_sc"; 
			break;
		case mpe_cmd::exchange_register_cs:
			out << "exchange_register_cs"; 
			break;
		case mpe_cmd::exchange_register_sc:
			out << "exchange_register_sc"; 
			break;
		case mpe_cmd::exchange_register_cancel_cs:
			out << "exchange_register_cancel_cs"; 
			break;
		case mpe_cmd::exchange_register_cancel_sc:
			out << "exchange_register_cancel_sc"; 
			break;
		case mpe_cmd::exchange_gold_withdraw_cs:
			out << "exchange_gold_withdraw_cs"; 
			break;
		case mpe_cmd::exchange_gold_withdraw_sc:
			out << "exchange_gold_withdraw_sc"; 
			break;
		case mpe_cmd::exchange_buy_cs:
			out << "exchange_buy_cs"; 
			break;
		case mpe_cmd::exchange_buy_sc:
			out << "exchange_buy_sc"; 
			break;
		case mpe_cmd::exchange_item_withdraw_cs:
			out << "exchange_item_withdraw_cs"; 
			break;
		case mpe_cmd::exchange_item_withdraw_sc:
			out << "exchange_item_withdraw_sc"; 
			break;
		case mpe_cmd::chatting_cs:
			out << "chatting_cs"; 
			break;
		case mpe_cmd::chatting_sc:
			out << "chatting_sc"; 
			break;
		case mpe_cmd::pk_setup_cs:
			out << "pk_setup_cs"; 
			break;
		case mpe_cmd::pk_setup_sc:
			out << "pk_setup_sc"; 
			break;
		case mpe_cmd::mail_open_cs:
			out << "mail_open_cs"; 
			break;
		case mpe_cmd::mail_open_sc:
			out << "mail_open_sc"; 
			break;
		case mpe_cmd::mail_receive_item_cs:
			out << "mail_receive_item_cs"; 
			break;
		case mpe_cmd::mail_receive_item_sc:
			out << "mail_receive_item_sc"; 
			break;
		case mpe_cmd::mail_delete_cs:
			out << "mail_delete_cs"; 
			break;
		case mpe_cmd::mail_delete_sc:
			out << "mail_delete_sc"; 
			break;
		case mpe_cmd::mail_send_cs:
			out << "mail_send_cs"; 
			break;
		case mpe_cmd::mail_send_sc:
			out << "mail_send_sc"; 
			break;
		case mpe_cmd::meridians_levelup_cs:
			out << "meridians_levelup_cs"; 
			break;
		case mpe_cmd::meridians_levelup_sc:
			out << "meridians_levelup_sc"; 
			break;
		case mpe_cmd::acupoints_levelup_cs:
			out << "acupoints_levelup_cs"; 
			break;
		case mpe_cmd::acupoints_levelup_sc:
			out << "acupoints_levelup_sc"; 
			break;
		case mpe_cmd::zone_move_error_cs:
			out << "zone_move_error_cs"; 
			break;
		case mpe_cmd::zone_move_error_sc:
			out << "zone_move_error_sc"; 
			break;
		case mpe_cmd::zone_object_return_cs:
			out << "zone_object_return_cs"; 
			break;
		case mpe_cmd::zone_object_return_sc:
			out << "zone_object_return_sc"; 
			break;
		case mpe_cmd::guild_destroy_cs:
			out << "guild_destroy_cs"; 
			break;
		case mpe_cmd::guild_destroy_sc:
			out << "guild_destroy_sc"; 
			break;
		case mpe_cmd::guild_request_member_list_cs:
			out << "guild_request_member_list_cs"; 
			break;
		case mpe_cmd::guild_request_member_list_sc:
			out << "guild_request_member_list_sc"; 
			break;
		case mpe_cmd::guild_donation_cs:
			out << "guild_donation_cs"; 
			break;
		case mpe_cmd::guild_donation_sc:
			out << "guild_donation_sc"; 
			break;
		case mpe_cmd::repute_quest_finish_count_reset_cs:
			out << "repute_quest_finish_count_reset_cs"; 
			break;
		case mpe_cmd::repute_quest_finish_count_reset_sc:
			out << "repute_quest_finish_count_reset_sc"; 
			break;
		case mpe_cmd::guild_start_war_cs:
			out << "guild_start_war_cs"; 
			break;
		case mpe_cmd::guild_start_war_sc:
			out << "guild_start_war_sc"; 
			break;
		case mpe_cmd::guild_try_surrender_cs:
			out << "guild_try_surrender_cs"; 
			break;
		case mpe_cmd::guild_try_surrender_sc:
			out << "guild_try_surrender_sc"; 
			break;
		case mpe_cmd::guild_respond_surrender_cs:
			out << "guild_respond_surrender_cs"; 
			break;
		case mpe_cmd::guild_respond_surrender_sc:
			out << "guild_respond_surrender_sc"; 
			break;
		case mpe_cmd::storage_open_cs:
			out << "storage_open_cs"; 
			break;
		case mpe_cmd::storage_open_sc:
			out << "storage_open_sc"; 
			break;
		case mpe_cmd::storage_move_cs:
			out << "storage_move_cs"; 
			break;
		case mpe_cmd::storage_move_sc:
			out << "storage_move_sc"; 
			break;
		case mpe_cmd::account_storage_buy_cs:
			out << "account_storage_buy_cs"; 
			break;
		case mpe_cmd::account_storage_buy_sc:
			out << "account_storage_buy_sc"; 
			break;
		case mpe_cmd::storage_expand_cs:
			out << "storage_expand_cs"; 
			break;
		case mpe_cmd::storage_expand_sc:
			out << "storage_expand_sc"; 
			break;
		case mpe_cmd::storage_goods_move_cs:
			out << "storage_goods_move_cs"; 
			break;
		case mpe_cmd::storage_goods_move_sc:
			out << "storage_goods_move_sc"; 
			break;
		case mpe_cmd::attack_speed_cs:
			out << "attack_speed_cs"; 
			break;
		case mpe_cmd::attack_speed_sc:
			out << "attack_speed_sc"; 
			break;
		case mpe_cmd::indun_play_count_request_cs:
			out << "indun_play_count_request_cs"; 
			break;
		case mpe_cmd::indun_play_count_request_sc:
			out << "indun_play_count_request_sc"; 
			break;
		case mpe_cmd::indun_auto_matching_complete_cs:
			out << "indun_auto_matching_complete_cs"; 
			break;
		case mpe_cmd::indun_auto_matching_complete_sc:
			out << "indun_auto_matching_complete_sc"; 
			break;
		case mpe_cmd::personal_trade_apply_cs:
			out << "personal_trade_apply_cs"; 
			break;
		case mpe_cmd::personal_trade_apply_sc:
			out << "personal_trade_apply_sc"; 
			break;
		case mpe_cmd::personal_trade_accept_cs:
			out << "personal_trade_accept_cs"; 
			break;
		case mpe_cmd::personal_trade_accept_sc:
			out << "personal_trade_accept_sc"; 
			break;
		case mpe_cmd::personal_trade_refuse_cs:
			out << "personal_trade_refuse_cs"; 
			break;
		case mpe_cmd::personal_trade_refuse_sc:
			out << "personal_trade_refuse_sc"; 
			break;
		case mpe_cmd::personal_trade_start_cs:
			out << "personal_trade_start_cs"; 
			break;
		case mpe_cmd::personal_trade_start_sc:
			out << "personal_trade_start_sc"; 
			break;
		case mpe_cmd::personal_trade_item_register_cs:
			out << "personal_trade_item_register_cs"; 
			break;
		case mpe_cmd::personal_trade_item_register_sc:
			out << "personal_trade_item_register_sc"; 
			break;
		case mpe_cmd::personal_trade_item_remove_cs:
			out << "personal_trade_item_remove_cs"; 
			break;
		case mpe_cmd::personal_trade_item_remove_sc:
			out << "personal_trade_item_remove_sc"; 
			break;
		case mpe_cmd::personal_trade_set_lock_cs:
			out << "personal_trade_set_lock_cs"; 
			break;
		case mpe_cmd::personal_trade_set_lock_sc:
			out << "personal_trade_set_lock_sc"; 
			break;
		case mpe_cmd::personal_trade_cancel_cs:
			out << "personal_trade_cancel_cs"; 
			break;
		case mpe_cmd::personal_trade_cancel_sc:
			out << "personal_trade_cancel_sc"; 
			break;
		case mpe_cmd::personal_trade_confirm_cs:
			out << "personal_trade_confirm_cs"; 
			break;
		case mpe_cmd::personal_trade_confirm_sc:
			out << "personal_trade_confirm_sc"; 
			break;
		case mpe_cmd::party_vote_request_cs:
			out << "party_vote_request_cs"; 
			break;
		case mpe_cmd::party_vote_request_sc:
			out << "party_vote_request_sc"; 
			break;
		case mpe_cmd::party_vote_reply_cs:
			out << "party_vote_reply_cs"; 
			break;
		case mpe_cmd::party_vote_reply_sc:
			out << "party_vote_reply_sc"; 
			break;
		case mpe_cmd::party_vote_result_cs:
			out << "party_vote_result_cs"; 
			break;
		case mpe_cmd::party_vote_result_sc:
			out << "party_vote_result_sc"; 
			break;
		case mpe_cmd::guild_storage_material_list_cs:
			out << "guild_storage_material_list_cs"; 
			break;
		case mpe_cmd::guild_storage_material_list_sc:
			out << "guild_storage_material_list_sc"; 
			break;
		case mpe_cmd::guild_war_list_cs:
			out << "guild_war_list_cs"; 
			break;
		case mpe_cmd::guild_war_list_sc:
			out << "guild_war_list_sc"; 
			break;
		case mpe_cmd::indun_auto_matching_cancel_cs:
			out << "indun_auto_matching_cancel_cs"; 
			break;
		case mpe_cmd::indun_auto_matching_cancel_sc:
			out << "indun_auto_matching_cancel_sc"; 
			break;
		case mpe_cmd::item_repair_cs:
			out << "item_repair_cs"; 
			break;
		case mpe_cmd::item_repair_sc:
			out << "item_repair_sc"; 
			break;
		case mpe_cmd::decrement_item_durability_cs:
			out << "decrement_item_durability_cs"; 
			break;
		case mpe_cmd::decrement_item_durability_sc:
			out << "decrement_item_durability_sc"; 
			break;
		case mpe_cmd::guild_item_donation_cs:
			out << "guild_item_donation_cs"; 
			break;
		case mpe_cmd::guild_item_donation_sc:
			out << "guild_item_donation_sc"; 
			break;
		case mpe_cmd::skill_passive_levelup_cs:
			out << "skill_passive_levelup_cs"; 
			break;
		case mpe_cmd::skill_passive_levelup_sc:
			out << "skill_passive_levelup_sc"; 
			break;
		case mpe_cmd::force_recovery_cs:
			out << "force_recovery_cs"; 
			break;
		case mpe_cmd::force_recovery_sc:
			out << "force_recovery_sc"; 
			break;
		case mpe_cmd::guild_alert_surrender_cs:
			out << "guild_alert_surrender_cs"; 
			break;
		case mpe_cmd::guild_alert_surrender_sc:
			out << "guild_alert_surrender_sc"; 
			break;
		case mpe_cmd::guild_alert_start_war_cs:
			out << "guild_alert_start_war_cs"; 
			break;
		case mpe_cmd::guild_alert_start_war_sc:
			out << "guild_alert_start_war_sc"; 
			break;
		case mpe_cmd::zone_verify_move_cs:
			out << "zone_verify_move_cs"; 
			break;
		case mpe_cmd::zone_verify_move_sc:
			out << "zone_verify_move_sc"; 
			break;
		case mpe_cmd::guild_alert_reject_surrender_cs:
			out << "guild_alert_reject_surrender_cs"; 
			break;
		case mpe_cmd::guild_alert_reject_surrender_sc:
			out << "guild_alert_reject_surrender_sc"; 
			break;
		case mpe_cmd::guild_alert_join_request_cs:
			out << "guild_alert_join_request_cs"; 
			break;
		case mpe_cmd::guild_alert_join_request_sc:
			out << "guild_alert_join_request_sc"; 
			break;
		case mpe_cmd::guild_alert_join_request_cancel_cs:
			out << "guild_alert_join_request_cancel_cs"; 
			break;
		case mpe_cmd::guild_alert_join_request_cancel_sc:
			out << "guild_alert_join_request_cancel_sc"; 
			break;
		case mpe_cmd::guild_alert_join_cs:
			out << "guild_alert_join_cs"; 
			break;
		case mpe_cmd::guild_alert_join_sc:
			out << "guild_alert_join_sc"; 
			break;
		case mpe_cmd::guild_alert_join_request_result_cs:
			out << "guild_alert_join_request_result_cs"; 
			break;
		case mpe_cmd::guild_alert_join_request_result_sc:
			out << "guild_alert_join_request_result_sc"; 
			break;
		case mpe_cmd::guild_alert_leave_cs:
			out << "guild_alert_leave_cs"; 
			break;
		case mpe_cmd::guild_alert_leave_sc:
			out << "guild_alert_leave_sc"; 
			break;
		case mpe_cmd::guild_alert_ban_for_member_cs:
			out << "guild_alert_ban_for_member_cs"; 
			break;
		case mpe_cmd::guild_alert_ban_for_member_sc:
			out << "guild_alert_ban_for_member_sc"; 
			break;
		case mpe_cmd::guild_alert_ban_cs:
			out << "guild_alert_ban_cs"; 
			break;
		case mpe_cmd::guild_alert_ban_sc:
			out << "guild_alert_ban_sc"; 
			break;
		case mpe_cmd::guild_alert_change_grade_cs:
			out << "guild_alert_change_grade_cs"; 
			break;
		case mpe_cmd::guild_alert_change_grade_sc:
			out << "guild_alert_change_grade_sc"; 
			break;
		case mpe_cmd::guild_alert_end_war_cs:
			out << "guild_alert_end_war_cs"; 
			break;
		case mpe_cmd::guild_alert_end_war_sc:
			out << "guild_alert_end_war_sc"; 
			break;
		case mpe_cmd::guild_alert_add_exp_cs:
			out << "guild_alert_add_exp_cs"; 
			break;
		case mpe_cmd::guild_alert_add_exp_sc:
			out << "guild_alert_add_exp_sc"; 
			break;
		case mpe_cmd::condition_refill_cs:
			out << "condition_refill_cs"; 
			break;
		case mpe_cmd::condition_refill_sc:
			out << "condition_refill_sc"; 
			break;
		case mpe_cmd::party_teleport_cs:
			out << "party_teleport_cs"; 
			break;
		case mpe_cmd::party_teleport_sc:
			out << "party_teleport_sc"; 
			break;
		case mpe_cmd::party_teleport_reply_cs:
			out << "party_teleport_reply_cs"; 
			break;
		case mpe_cmd::party_teleport_reply_sc:
			out << "party_teleport_reply_sc"; 
			break;
		case mpe_cmd::check_indun_enter_condition_cs:
			out << "check_indun_enter_condition_cs"; 
			break;
		case mpe_cmd::check_indun_enter_condition_sc:
			out << "check_indun_enter_condition_sc"; 
			break;
		case mpe_cmd::indun_enter_pay_cs:
			out << "indun_enter_pay_cs"; 
			break;
		case mpe_cmd::indun_enter_pay_sc:
			out << "indun_enter_pay_sc"; 
			break;
		case mpe_cmd::summon_recall_cs:
			out << "summon_recall_cs"; 
			break;
		case mpe_cmd::summon_recall_sc:
			out << "summon_recall_sc"; 
			break;
		case mpe_cmd::siege_warfare_submit_tender_cs:
			out << "siege_warfare_submit_tender_cs"; 
			break;
		case mpe_cmd::siege_warfare_submit_tender_sc:
			out << "siege_warfare_submit_tender_sc"; 
			break;
		case mpe_cmd::siege_warfare_alert_cs:
			out << "siege_warfare_alert_cs"; 
			break;
		case mpe_cmd::siege_warfare_alert_sc:
			out << "siege_warfare_alert_sc"; 
			break;
		case mpe_cmd::siege_warfare_alliance_request_cs:
			out << "siege_warfare_alliance_request_cs"; 
			break;
		case mpe_cmd::siege_warfare_alliance_request_sc:
			out << "siege_warfare_alliance_request_sc"; 
			break;
		case mpe_cmd::siege_warfare_alliance_cancel_cs:
			out << "siege_warfare_alliance_cancel_cs"; 
			break;
		case mpe_cmd::siege_warfare_alliance_cancel_sc:
			out << "siege_warfare_alliance_cancel_sc"; 
			break;
		case mpe_cmd::siege_warfare_alliance_response_cs:
			out << "siege_warfare_alliance_response_cs"; 
			break;
		case mpe_cmd::siege_warfare_alliance_response_sc:
			out << "siege_warfare_alliance_response_sc"; 
			break;
		case mpe_cmd::siege_warfare_alliance_kickout_cs:
			out << "siege_warfare_alliance_kickout_cs"; 
			break;
		case mpe_cmd::siege_warfare_alliance_kickout_sc:
			out << "siege_warfare_alliance_kickout_sc"; 
			break;
		case mpe_cmd::siege_warfare_alliance_withdrawal_cs:
			out << "siege_warfare_alliance_withdrawal_cs"; 
			break;
		case mpe_cmd::siege_warfare_alliance_withdrawal_sc:
			out << "siege_warfare_alliance_withdrawal_sc"; 
			break;
		case mpe_cmd::castle_set_tax_rate_cs:
			out << "castle_set_tax_rate_cs"; 
			break;
		case mpe_cmd::castle_set_tax_rate_sc:
			out << "castle_set_tax_rate_sc"; 
			break;
		case mpe_cmd::castle_set_tax_distribution_cs:
			out << "castle_set_tax_distribution_cs"; 
			break;
		case mpe_cmd::castle_set_tax_distribution_sc:
			out << "castle_set_tax_distribution_sc"; 
			break;
		case mpe_cmd::siege_warfare_atk_build_machine_cs:
			out << "siege_warfare_atk_build_machine_cs"; 
			break;
		case mpe_cmd::siege_warfare_atk_build_machine_sc:
			out << "siege_warfare_atk_build_machine_sc"; 
			break;
		case mpe_cmd::siege_warfare_def_build_machine_cs:
			out << "siege_warfare_def_build_machine_cs"; 
			break;
		case mpe_cmd::siege_warfare_def_build_machine_sc:
			out << "siege_warfare_def_build_machine_sc"; 
			break;
		case mpe_cmd::siege_warfare_atk_release_machine_cs:
			out << "siege_warfare_atk_release_machine_cs"; 
			break;
		case mpe_cmd::siege_warfare_atk_release_machine_sc:
			out << "siege_warfare_atk_release_machine_sc"; 
			break;
		case mpe_cmd::siege_warfare_def_release_machine_cs:
			out << "siege_warfare_def_release_machine_cs"; 
			break;
		case mpe_cmd::siege_warfare_def_release_machine_sc:
			out << "siege_warfare_def_release_machine_sc"; 
			break;
		case mpe_cmd::special_move_set_cs:
			out << "special_move_set_cs"; 
			break;
		case mpe_cmd::special_move_set_sc:
			out << "special_move_set_sc"; 
			break;
		case mpe_cmd::skill_use_cs:
			out << "skill_use_cs"; 
			break;
		case mpe_cmd::skill_use_sc:
			out << "skill_use_sc"; 
			break;
		case mpe_cmd::special_move_start_cs:
			out << "special_move_start_cs"; 
			break;
		case mpe_cmd::special_move_start_sc:
			out << "special_move_start_sc"; 
			break;
		case mpe_cmd::guild_change_notice_cs:
			out << "guild_change_notice_cs"; 
			break;
		case mpe_cmd::guild_change_notice_sc:
			out << "guild_change_notice_sc"; 
			break;
		case mpe_cmd::guild_alert_change_notice_cs:
			out << "guild_alert_change_notice_cs"; 
			break;
		case mpe_cmd::guild_alert_change_notice_sc:
			out << "guild_alert_change_notice_sc"; 
			break;
		case mpe_cmd::indun_auto_matching_rematch_cs:
			out << "indun_auto_matching_rematch_cs"; 
			break;
		case mpe_cmd::indun_auto_matching_rematch_sc:
			out << "indun_auto_matching_rematch_sc"; 
			break;
		case mpe_cmd::siege_warfare_time_cs:
			out << "siege_warfare_time_cs"; 
			break;
		case mpe_cmd::siege_warfare_time_sc:
			out << "siege_warfare_time_sc"; 
			break;
		case mpe_cmd::guild_learn_skill_cs:
			out << "guild_learn_skill_cs"; 
			break;
		case mpe_cmd::guild_learn_skill_sc:
			out << "guild_learn_skill_sc"; 
			break;
		case mpe_cmd::guild_reset_skill_cs:
			out << "guild_reset_skill_cs"; 
			break;
		case mpe_cmd::guild_reset_skill_sc:
			out << "guild_reset_skill_sc"; 
			break;
		case mpe_cmd::guild_alert_learn_skill_cs:
			out << "guild_alert_learn_skill_cs"; 
			break;
		case mpe_cmd::guild_alert_learn_skill_sc:
			out << "guild_alert_learn_skill_sc"; 
			break;
		case mpe_cmd::guild_alert_reset_skill_cs:
			out << "guild_alert_reset_skill_cs"; 
			break;
		case mpe_cmd::guild_alert_reset_skill_sc:
			out << "guild_alert_reset_skill_sc"; 
			break;
		case mpe_cmd::guild_skill_list_cs:
			out << "guild_skill_list_cs"; 
			break;
		case mpe_cmd::guild_skill_list_sc:
			out << "guild_skill_list_sc"; 
			break;
		case mpe_cmd::guild_alert_donation_cs:
			out << "guild_alert_donation_cs"; 
			break;
		case mpe_cmd::guild_alert_donation_sc:
			out << "guild_alert_donation_sc"; 
			break;
		case mpe_cmd::indun_stage_start_cs:
			out << "indun_stage_start_cs"; 
			break;
		case mpe_cmd::indun_stage_start_sc:
			out << "indun_stage_start_sc"; 
			break;
		case mpe_cmd::guild_storage_supply_list_cs:
			out << "guild_storage_supply_list_cs"; 
			break;
		case mpe_cmd::guild_storage_supply_list_sc:
			out << "guild_storage_supply_list_sc"; 
			break;
		case mpe_cmd::guild_storage_supply_insert_item_cs:
			out << "guild_storage_supply_insert_item_cs"; 
			break;
		case mpe_cmd::guild_storage_supply_insert_item_sc:
			out << "guild_storage_supply_insert_item_sc"; 
			break;
		case mpe_cmd::guild_storage_supply_get_item_cs:
			out << "guild_storage_supply_get_item_cs"; 
			break;
		case mpe_cmd::guild_storage_supply_get_item_sc:
			out << "guild_storage_supply_get_item_sc"; 
			break;
		case mpe_cmd::chatting_system_cs:
			out << "chatting_system_cs"; 
			break;
		case mpe_cmd::chatting_system_sc:
			out << "chatting_system_sc"; 
			break;
		case mpe_cmd::guild_master_change_by_non_connected_cs:
			out << "guild_master_change_by_non_connected_cs"; 
			break;
		case mpe_cmd::guild_master_change_by_non_connected_sc:
			out << "guild_master_change_by_non_connected_sc"; 
			break;
		case mpe_cmd::guild_storage_share_list_cs:
			out << "guild_storage_share_list_cs"; 
			break;
		case mpe_cmd::guild_storage_share_list_sc:
			out << "guild_storage_share_list_sc"; 
			break;
		case mpe_cmd::guild_storage_share_insert_item_cs:
			out << "guild_storage_share_insert_item_cs"; 
			break;
		case mpe_cmd::guild_storage_share_insert_item_sc:
			out << "guild_storage_share_insert_item_sc"; 
			break;
		case mpe_cmd::guild_storage_share_request_get_item_cs:
			out << "guild_storage_share_request_get_item_cs"; 
			break;
		case mpe_cmd::guild_storage_share_request_get_item_sc:
			out << "guild_storage_share_request_get_item_sc"; 
			break;
		case mpe_cmd::guild_storage_share_alert_request_get_item_cs:
			out << "guild_storage_share_alert_request_get_item_cs"; 
			break;
		case mpe_cmd::guild_storage_share_alert_request_get_item_sc:
			out << "guild_storage_share_alert_request_get_item_sc"; 
			break;
		case mpe_cmd::guild_storage_share_result_get_item_cs:
			out << "guild_storage_share_result_get_item_cs"; 
			break;
		case mpe_cmd::guild_storage_share_result_get_item_sc:
			out << "guild_storage_share_result_get_item_sc"; 
			break;
		case mpe_cmd::guild_storage_share_extend_cs:
			out << "guild_storage_share_extend_cs"; 
			break;
		case mpe_cmd::guild_storage_share_extend_sc:
			out << "guild_storage_share_extend_sc"; 
			break;
		case mpe_cmd::guild_storage_share_request_get_item_list_cs:
			out << "guild_storage_share_request_get_item_list_cs"; 
			break;
		case mpe_cmd::guild_storage_share_request_get_item_list_sc:
			out << "guild_storage_share_request_get_item_list_sc"; 
			break;
		case mpe_cmd::guild_storage_share_master_get_item_cs:
			out << "guild_storage_share_master_get_item_cs"; 
			break;
		case mpe_cmd::guild_storage_share_master_get_item_sc:
			out << "guild_storage_share_master_get_item_sc"; 
			break;
		case mpe_cmd::castle_town_return_cs:
			out << "castle_town_return_cs"; 
			break;
		case mpe_cmd::castle_town_return_sc:
			out << "castle_town_return_sc"; 
			break;
		case mpe_cmd::siege_tower_teleport_cs:
			out << "siege_tower_teleport_cs"; 
			break;
		case mpe_cmd::siege_tower_teleport_sc:
			out << "siege_tower_teleport_sc"; 
			break;
		case mpe_cmd::enchant_stone_slot_open_cs:
			out << "enchant_stone_slot_open_cs"; 
			break;
		case mpe_cmd::enchant_stone_slot_open_sc:
			out << "enchant_stone_slot_open_sc"; 
			break;
		case mpe_cmd::enchant_stone_equip_cs:
			out << "enchant_stone_equip_cs"; 
			break;
		case mpe_cmd::enchant_stone_equip_sc:
			out << "enchant_stone_equip_sc"; 
			break;
		case mpe_cmd::enchant_stone_upgrade_cs:
			out << "enchant_stone_upgrade_cs"; 
			break;
		case mpe_cmd::enchant_stone_upgrade_sc:
			out << "enchant_stone_upgrade_sc"; 
			break;
		case mpe_cmd::enchant_stone_compose_cs:
			out << "enchant_stone_compose_cs"; 
			break;
		case mpe_cmd::enchant_stone_compose_sc:
			out << "enchant_stone_compose_sc"; 
			break;
		case mpe_cmd::zone_siege_weapon_info_cs:
			out << "zone_siege_weapon_info_cs"; 
			break;
		case mpe_cmd::zone_siege_weapon_info_sc:
			out << "zone_siege_weapon_info_sc"; 
			break;
		case mpe_cmd::zone_fixed_object_info_cs:
			out << "zone_fixed_object_info_cs"; 
			break;
		case mpe_cmd::zone_fixed_object_info_sc:
			out << "zone_fixed_object_info_sc"; 
			break;
		case mpe_cmd::zone_mercenary_info_cs:
			out << "zone_mercenary_info_cs"; 
			break;
		case mpe_cmd::zone_mercenary_info_sc:
			out << "zone_mercenary_info_sc"; 
			break;
		case mpe_cmd::castle_town_work_use_character_item_cs:
			out << "castle_town_work_use_character_item_cs"; 
			break;
		case mpe_cmd::castle_town_work_use_character_item_sc:
			out << "castle_town_work_use_character_item_sc"; 
			break;
		case mpe_cmd::zone_siege_object_all_cs:
			out << "zone_siege_object_all_cs"; 
			break;
		case mpe_cmd::zone_siege_object_all_sc:
			out << "zone_siege_object_all_sc"; 
			break;
		case mpe_cmd::castle_town_work_cs:
			out << "castle_town_work_cs"; 
			break;
		case mpe_cmd::castle_town_work_sc:
			out << "castle_town_work_sc"; 
			break;
		case mpe_cmd::castle_town_house_fire_cs:
			out << "castle_town_house_fire_cs"; 
			break;
		case mpe_cmd::castle_town_house_fire_sc:
			out << "castle_town_house_fire_sc"; 
			break;
		case mpe_cmd::castle_town_arsenal_build_cs:
			out << "castle_town_arsenal_build_cs"; 
			break;
		case mpe_cmd::castle_town_arsenal_build_sc:
			out << "castle_town_arsenal_build_sc"; 
			break;
		case mpe_cmd::castle_town_arsenal_build_donate_cs:
			out << "castle_town_arsenal_build_donate_cs"; 
			break;
		case mpe_cmd::castle_town_arsenal_build_donate_sc:
			out << "castle_town_arsenal_build_donate_sc"; 
			break;
		case mpe_cmd::guild_storage_treasure_list_cs:
			out << "guild_storage_treasure_list_cs"; 
			break;
		case mpe_cmd::guild_storage_treasure_list_sc:
			out << "guild_storage_treasure_list_sc"; 
			break;
		case mpe_cmd::guild_storage_treasure_alert_lost_top_request_cs:
			out << "guild_storage_treasure_alert_lost_top_request_cs"; 
			break;
		case mpe_cmd::guild_storage_treasure_alert_lost_top_request_sc:
			out << "guild_storage_treasure_alert_lost_top_request_sc"; 
			break;
		case mpe_cmd::guild_storage_treasure_alert_auction_finish_cs:
			out << "guild_storage_treasure_alert_auction_finish_cs"; 
			break;
		case mpe_cmd::guild_storage_treasure_alert_auction_finish_sc:
			out << "guild_storage_treasure_alert_auction_finish_sc"; 
			break;
		case mpe_cmd::guild_storage_treasure_get_auction_cs:
			out << "guild_storage_treasure_get_auction_cs"; 
			break;
		case mpe_cmd::guild_storage_treasure_get_auction_sc:
			out << "guild_storage_treasure_get_auction_sc"; 
			break;
		case mpe_cmd::guild_storage_treasure_request_cs:
			out << "guild_storage_treasure_request_cs"; 
			break;
		case mpe_cmd::guild_storage_treasure_request_sc:
			out << "guild_storage_treasure_request_sc"; 
			break;
		case mpe_cmd::guild_dungeon_create_cs:
			out << "guild_dungeon_create_cs"; 
			break;
		case mpe_cmd::guild_dungeon_create_sc:
			out << "guild_dungeon_create_sc"; 
			break;
		case mpe_cmd::indun_siege_enter_test_cs:
			out << "indun_siege_enter_test_cs"; 
			break;
		case mpe_cmd::indun_siege_enter_test_sc:
			out << "indun_siege_enter_test_sc"; 
			break;
		case mpe_cmd::siege_object_phase_cs:
			out << "siege_object_phase_cs"; 
			break;
		case mpe_cmd::siege_object_phase_sc:
			out << "siege_object_phase_sc"; 
			break;
		case mpe_cmd::castle_town_arsenal_build_work_info_cs:
			out << "castle_town_arsenal_build_work_info_cs"; 
			break;
		case mpe_cmd::castle_town_arsenal_build_work_info_sc:
			out << "castle_town_arsenal_build_work_info_sc"; 
			break;
		case mpe_cmd::castle_town_arsenal_build_end_cs:
			out << "castle_town_arsenal_build_end_cs"; 
			break;
		case mpe_cmd::castle_town_arsenal_build_end_sc:
			out << "castle_town_arsenal_build_end_sc"; 
			break;
		case mpe_cmd::guild_storage_treasure_confirm_auction_cs:
			out << "guild_storage_treasure_confirm_auction_cs"; 
			break;
		case mpe_cmd::guild_storage_treasure_confirm_auction_sc:
			out << "guild_storage_treasure_confirm_auction_sc"; 
			break;
		case mpe_cmd::castle_town_start_specialties_cs:
			out << "castle_town_start_specialties_cs"; 
			break;
		case mpe_cmd::castle_town_start_specialties_sc:
			out << "castle_town_start_specialties_sc"; 
			break;
		case mpe_cmd::castle_town_start_specialties_delivery_cs:
			out << "castle_town_start_specialties_delivery_cs"; 
			break;
		case mpe_cmd::castle_town_start_specialties_delivery_sc:
			out << "castle_town_start_specialties_delivery_sc"; 
			break;
		case mpe_cmd::guild_enemy_list_cs:
			out << "guild_enemy_list_cs"; 
			break;
		case mpe_cmd::guild_enemy_list_sc:
			out << "guild_enemy_list_sc"; 
			break;
		case mpe_cmd::game_reconnect_cs:
			out << "game_reconnect_cs"; 
			break;
		case mpe_cmd::game_reconnect_sc:
			out << "game_reconnect_sc"; 
			break;
		case mpe_cmd::guild_register_master_order_quest_cs:
			out << "guild_register_master_order_quest_cs"; 
			break;
		case mpe_cmd::guild_register_master_order_quest_sc:
			out << "guild_register_master_order_quest_sc"; 
			break;
		case mpe_cmd::guild_alert_register_master_order_quest_cs:
			out << "guild_alert_register_master_order_quest_cs"; 
			break;
		case mpe_cmd::guild_alert_register_master_order_quest_sc:
			out << "guild_alert_register_master_order_quest_sc"; 
			break;
		case mpe_cmd::guild_alert_finish_master_order_quest_cs:
			out << "guild_alert_finish_master_order_quest_cs"; 
			break;
		case mpe_cmd::guild_alert_finish_master_order_quest_sc:
			out << "guild_alert_finish_master_order_quest_sc"; 
			break;
		case mpe_cmd::guild_town_boss_summon_cs:
			out << "guild_town_boss_summon_cs"; 
			break;
		case mpe_cmd::guild_town_boss_summon_sc:
			out << "guild_town_boss_summon_sc"; 
			break;
		case mpe_cmd::zone_treasure_box_info_cs:
			out << "zone_treasure_box_info_cs"; 
			break;
		case mpe_cmd::zone_treasure_box_info_sc:
			out << "zone_treasure_box_info_sc"; 
			break;
		case mpe_cmd::zone_treasure_box_open_cs:
			out << "zone_treasure_box_open_cs"; 
			break;
		case mpe_cmd::zone_treasure_box_open_sc:
			out << "zone_treasure_box_open_sc"; 
			break;
		case mpe_cmd::zone_gold_treasure_box_info_cs:
			out << "zone_gold_treasure_box_info_cs"; 
			break;
		case mpe_cmd::zone_gold_treasure_box_info_sc:
			out << "zone_gold_treasure_box_info_sc"; 
			break;
		case mpe_cmd::castle_town_start_dinner_cs:
			out << "castle_town_start_dinner_cs"; 
			break;
		case mpe_cmd::castle_town_start_dinner_sc:
			out << "castle_town_start_dinner_sc"; 
			break;
		case mpe_cmd::castle_town_dinner_get_item_cs:
			out << "castle_town_dinner_get_item_cs"; 
			break;
		case mpe_cmd::castle_town_dinner_get_item_sc:
			out << "castle_town_dinner_get_item_sc"; 
			break;
		case mpe_cmd::castle_town_hud_info_cs:
			out << "castle_town_hud_info_cs"; 
			break;
		case mpe_cmd::castle_town_hud_info_sc:
			out << "castle_town_hud_info_sc"; 
			break;
		case mpe_cmd::pet_equip_cs:
			out << "pet_equip_cs"; 
			break;
		case mpe_cmd::pet_equip_sc:
			out << "pet_equip_sc"; 
			break;
		case mpe_cmd::pet_feed_cs:
			out << "pet_feed_cs"; 
			break;
		case mpe_cmd::pet_feed_sc:
			out << "pet_feed_sc"; 
			break;
		case mpe_cmd::zone_monster_respawn_cs:
			out << "zone_monster_respawn_cs"; 
			break;
		case mpe_cmd::zone_monster_respawn_sc:
			out << "zone_monster_respawn_sc"; 
			break;
		case mpe_cmd::vehicle_add_cs:
			out << "vehicle_add_cs"; 
			break;
		case mpe_cmd::vehicle_add_sc:
			out << "vehicle_add_sc"; 
			break;
		case mpe_cmd::vehicle_equip_cs:
			out << "vehicle_equip_cs"; 
			break;
		case mpe_cmd::vehicle_equip_sc:
			out << "vehicle_equip_sc"; 
			break;
		case mpe_cmd::vehicle_food_cs:
			out << "vehicle_food_cs"; 
			break;
		case mpe_cmd::vehicle_food_sc:
			out << "vehicle_food_sc"; 
			break;
		case mpe_cmd::vehicle_equip_item_cs:
			out << "vehicle_equip_item_cs"; 
			break;
		case mpe_cmd::vehicle_equip_item_sc:
			out << "vehicle_equip_item_sc"; 
			break;
		case mpe_cmd::vehicle_expire_cs:
			out << "vehicle_expire_cs"; 
			break;
		case mpe_cmd::vehicle_expire_sc:
			out << "vehicle_expire_sc"; 
			break;
		case mpe_cmd::randombox_open_cs:
			out << "randombox_open_cs"; 
			break;
		case mpe_cmd::randombox_open_sc:
			out << "randombox_open_sc"; 
			break;
		case mpe_cmd::zone_sector_move_cs:
			out << "zone_sector_move_cs"; 
			break;
		case mpe_cmd::zone_sector_move_sc:
			out << "zone_sector_move_sc"; 
			break;
		case mpe_cmd::zone_sector_teleport_cs:
			out << "zone_sector_teleport_cs"; 
			break;
		case mpe_cmd::zone_sector_teleport_sc:
			out << "zone_sector_teleport_sc"; 
			break;
		case mpe_cmd::castle_dungeon_entrance_fee_change_cs:
			out << "castle_dungeon_entrance_fee_change_cs"; 
			break;
		case mpe_cmd::castle_dungeon_entrance_fee_change_sc:
			out << "castle_dungeon_entrance_fee_change_sc"; 
			break;
		case mpe_cmd::guild_alert_create_dungeon_cs:
			out << "guild_alert_create_dungeon_cs"; 
			break;
		case mpe_cmd::guild_alert_create_dungeon_sc:
			out << "guild_alert_create_dungeon_sc"; 
			break;
		case mpe_cmd::monster_run_away_cs:
			out << "monster_run_away_cs"; 
			break;
		case mpe_cmd::monster_run_away_sc:
			out << "monster_run_away_sc"; 
			break;
		case mpe_cmd::guild_alert_dungeon_enter_cs:
			out << "guild_alert_dungeon_enter_cs"; 
			break;
		case mpe_cmd::guild_alert_dungeon_enter_sc:
			out << "guild_alert_dungeon_enter_sc"; 
			break;
		case mpe_cmd::title_equip_cs:
			out << "title_equip_cs"; 
			break;
		case mpe_cmd::title_equip_sc:
			out << "title_equip_sc"; 
			break;
		case mpe_cmd::pet_mix_cs:
			out << "pet_mix_cs"; 
			break;
		case mpe_cmd::pet_mix_sc:
			out << "pet_mix_sc"; 
			break;
		case mpe_cmd::castle_town_single_specialties_hud_cs:
			out << "castle_town_single_specialties_hud_cs"; 
			break;
		case mpe_cmd::castle_town_single_specialties_hud_sc:
			out << "castle_town_single_specialties_hud_sc"; 
			break;
		case mpe_cmd::test_game_server_cs:
			out << "test_game_server_cs"; 
			break;
		case mpe_cmd::test_game_server_sc:
			out << "test_game_server_sc"; 
			break;
		case mpe_cmd::pet_equip_broad_cs:
			out << "pet_equip_broad_cs"; 
			break;
		case mpe_cmd::pet_equip_broad_sc:
			out << "pet_equip_broad_sc"; 
			break;
		case mpe_cmd::zone_object_return_teleport_cs:
			out << "zone_object_return_teleport_cs"; 
			break;
		case mpe_cmd::zone_object_return_teleport_sc:
			out << "zone_object_return_teleport_sc"; 
			break;
		case mpe_cmd::guild_office_boss_summon_info_cs:
			out << "guild_office_boss_summon_info_cs"; 
			break;
		case mpe_cmd::guild_office_boss_summon_info_sc:
			out << "guild_office_boss_summon_info_sc"; 
			break;
		case mpe_cmd::siege_warfare_occupation_cs:
			out << "siege_warfare_occupation_cs"; 
			break;
		case mpe_cmd::siege_warfare_occupation_sc:
			out << "siege_warfare_occupation_sc"; 
			break;
		case mpe_cmd::siege_warfare_play_alert_cs:
			out << "siege_warfare_play_alert_cs"; 
			break;
		case mpe_cmd::siege_warfare_play_alert_sc:
			out << "siege_warfare_play_alert_sc"; 
			break;
		case mpe_cmd::pk_revenge_add_cs:
			out << "pk_revenge_add_cs"; 
			break;
		case mpe_cmd::pk_revenge_add_sc:
			out << "pk_revenge_add_sc"; 
			break;
		case mpe_cmd::pk_record_delete_cs:
			out << "pk_record_delete_cs"; 
			break;
		case mpe_cmd::pk_record_delete_sc:
			out << "pk_record_delete_sc"; 
			break;
		case mpe_cmd::pk_revenge_delete_cs:
			out << "pk_revenge_delete_cs"; 
			break;
		case mpe_cmd::pk_revenge_delete_sc:
			out << "pk_revenge_delete_sc"; 
			break;
		case mpe_cmd::pk_revenge_trace_cs:
			out << "pk_revenge_trace_cs"; 
			break;
		case mpe_cmd::pk_revenge_trace_sc:
			out << "pk_revenge_trace_sc"; 
			break;
		case mpe_cmd::pk_record_list_get_cs:
			out << "pk_record_list_get_cs"; 
			break;
		case mpe_cmd::pk_record_list_get_sc:
			out << "pk_record_list_get_sc"; 
			break;
		case mpe_cmd::friend_request_cs:
			out << "friend_request_cs"; 
			break;
		case mpe_cmd::friend_request_sc:
			out << "friend_request_sc"; 
			break;
		case mpe_cmd::friend_delete_cs:
			out << "friend_delete_cs"; 
			break;
		case mpe_cmd::friend_delete_sc:
			out << "friend_delete_sc"; 
			break;
		case mpe_cmd::friend_request_response_cs:
			out << "friend_request_response_cs"; 
			break;
		case mpe_cmd::friend_request_response_sc:
			out << "friend_request_response_sc"; 
			break;
		case mpe_cmd::friend_request_response_all_cs:
			out << "friend_request_response_all_cs"; 
			break;
		case mpe_cmd::friend_request_response_all_sc:
			out << "friend_request_response_all_sc"; 
			break;
		case mpe_cmd::pet_release_summon_broad_cs:
			out << "pet_release_summon_broad_cs"; 
			break;
		case mpe_cmd::pet_release_summon_broad_sc:
			out << "pet_release_summon_broad_sc"; 
			break;
		case mpe_cmd::mentor_register_cs:
			out << "mentor_register_cs"; 
			break;
		case mpe_cmd::mentor_register_sc:
			out << "mentor_register_sc"; 
			break;
		case mpe_cmd::mentor_request_cs:
			out << "mentor_request_cs"; 
			break;
		case mpe_cmd::mentor_request_sc:
			out << "mentor_request_sc"; 
			break;
		case mpe_cmd::mentor_buff_buy_cs:
			out << "mentor_buff_buy_cs"; 
			break;
		case mpe_cmd::mentor_buff_buy_sc:
			out << "mentor_buff_buy_sc"; 
			break;
		case mpe_cmd::mentor_buff_cs:
			out << "mentor_buff_cs"; 
			break;
		case mpe_cmd::mentor_buff_sc:
			out << "mentor_buff_sc"; 
			break;
		case mpe_cmd::mentor_response_cs:
			out << "mentor_response_cs"; 
			break;
		case mpe_cmd::mentor_response_sc:
			out << "mentor_response_sc"; 
			break;
		case mpe_cmd::friend_data_set_cs:
			out << "friend_data_set_cs"; 
			break;
		case mpe_cmd::friend_data_set_sc:
			out << "friend_data_set_sc"; 
			break;
		case mpe_cmd::title_add_cs:
			out << "title_add_cs"; 
			break;
		case mpe_cmd::title_add_sc:
			out << "title_add_sc"; 
			break;
		case mpe_cmd::dictionary_add_cs:
			out << "dictionary_add_cs"; 
			break;
		case mpe_cmd::dictionary_add_sc:
			out << "dictionary_add_sc"; 
			break;
		case mpe_cmd::dictionary_get_cs:
			out << "dictionary_get_cs"; 
			break;
		case mpe_cmd::dictionary_get_sc:
			out << "dictionary_get_sc"; 
			break;
		case mpe_cmd::character_expand_stat_add_attribute_cs:
			out << "character_expand_stat_add_attribute_cs"; 
			break;
		case mpe_cmd::character_expand_stat_add_attribute_sc:
			out << "character_expand_stat_add_attribute_sc"; 
			break;
		case mpe_cmd::wanted_murder_register_cs:
			out << "wanted_murder_register_cs"; 
			break;
		case mpe_cmd::wanted_murder_register_sc:
			out << "wanted_murder_register_sc"; 
			break;
		case mpe_cmd::empty1_cs:
			out << "empty1_cs"; 
			break;
		case mpe_cmd::empty1_sc:
			out << "empty1_sc"; 
			break;
		case mpe_cmd::empty2_cs:
			out << "empty2_cs"; 
			break;
		case mpe_cmd::empty2_sc:
			out << "empty2_sc"; 
			break;
		case mpe_cmd::wanted_murder_reward_cs:
			out << "wanted_murder_reward_cs"; 
			break;
		case mpe_cmd::wanted_murder_reward_sc:
			out << "wanted_murder_reward_sc"; 
			break;
		case mpe_cmd::wanted_murder_end_notify_cs:
			out << "wanted_murder_end_notify_cs"; 
			break;
		case mpe_cmd::wanted_murder_end_notify_sc:
			out << "wanted_murder_end_notify_sc"; 
			break;
		case mpe_cmd::zone_teleport_save_area_cs:
			out << "zone_teleport_save_area_cs"; 
			break;
		case mpe_cmd::zone_teleport_save_area_sc:
			out << "zone_teleport_save_area_sc"; 
			break;
		case mpe_cmd::zone_teleport_save_area_delete_cs:
			out << "zone_teleport_save_area_delete_cs"; 
			break;
		case mpe_cmd::zone_teleport_save_area_delete_sc:
			out << "zone_teleport_save_area_delete_sc"; 
			break;
		case mpe_cmd::zone_teleport_to_saved_area_cs:
			out << "zone_teleport_to_saved_area_cs"; 
			break;
		case mpe_cmd::zone_teleport_to_saved_area_sc:
			out << "zone_teleport_to_saved_area_sc"; 
			break;
		case mpe_cmd::zone_teleport_fixed_point_cs:
			out << "zone_teleport_fixed_point_cs"; 
			break;
		case mpe_cmd::zone_teleport_fixed_point_sc:
			out << "zone_teleport_fixed_point_sc"; 
			break;
		case mpe_cmd::zone_teleport_view_point_cs:
			out << "zone_teleport_view_point_cs"; 
			break;
		case mpe_cmd::zone_teleport_view_point_sc:
			out << "zone_teleport_view_point_sc"; 
			break;
		case mpe_cmd::show_costume_cs:
			out << "show_costume_cs"; 
			break;
		case mpe_cmd::show_costume_sc:
			out << "show_costume_sc"; 
			break;
		case mpe_cmd::pk_revenge_result_cs:
			out << "pk_revenge_result_cs"; 
			break;
		case mpe_cmd::pk_revenge_result_sc:
			out << "pk_revenge_result_sc"; 
			break;
		case mpe_cmd::wanted_murder_number_of_uses_cs:
			out << "wanted_murder_number_of_uses_cs"; 
			break;
		case mpe_cmd::wanted_murder_number_of_uses_sc:
			out << "wanted_murder_number_of_uses_sc"; 
			break;
		case mpe_cmd::guild_change_introduction_cs:
			out << "guild_change_introduction_cs"; 
			break;
		case mpe_cmd::guild_change_introduction_sc:
			out << "guild_change_introduction_sc"; 
			break;
		case mpe_cmd::guild_pr_cs:
			out << "guild_pr_cs"; 
			break;
		case mpe_cmd::guild_pr_sc:
			out << "guild_pr_sc"; 
			break;
		case mpe_cmd::tutorial_complete_cs:
			out << "tutorial_complete_cs"; 
			break;
		case mpe_cmd::tutorial_complete_sc:
			out << "tutorial_complete_sc"; 
			break;
		case mpe_cmd::guild_invite_cs:
			out << "guild_invite_cs"; 
			break;
		case mpe_cmd::guild_invite_sc:
			out << "guild_invite_sc"; 
			break;
		case mpe_cmd::guild_invite_accept_cs:
			out << "guild_invite_accept_cs"; 
			break;
		case mpe_cmd::guild_invite_accept_sc:
			out << "guild_invite_accept_sc"; 
			break;
		case mpe_cmd::guild_invite_refusal_cs:
			out << "guild_invite_refusal_cs"; 
			break;
		case mpe_cmd::guild_invite_refusal_sc:
			out << "guild_invite_refusal_sc"; 
			break;
		case mpe_cmd::guild_pr_notify_cs:
			out << "guild_pr_notify_cs"; 
			break;
		case mpe_cmd::guild_pr_notify_sc:
			out << "guild_pr_notify_sc"; 
			break;
		case mpe_cmd::guild_invite_notify_cs:
			out << "guild_invite_notify_cs"; 
			break;
		case mpe_cmd::guild_invite_notify_sc:
			out << "guild_invite_notify_sc"; 
			break;
		case mpe_cmd::teleport_arrive_cs:
			out << "teleport_arrive_cs"; 
			break;
		case mpe_cmd::teleport_arrive_sc:
			out << "teleport_arrive_sc"; 
			break;
		case mpe_cmd::dictionary_reward_get_cs:
			out << "dictionary_reward_get_cs"; 
			break;
		case mpe_cmd::dictionary_reward_get_sc:
			out << "dictionary_reward_get_sc"; 
			break;
		case mpe_cmd::dictionary_achieve_rate_get_cs:
			out << "dictionary_achieve_rate_get_cs"; 
			break;
		case mpe_cmd::dictionary_achieve_rate_get_sc:
			out << "dictionary_achieve_rate_get_sc"; 
			break;
		case mpe_cmd::dictionary_bookmark_get_cs:
			out << "dictionary_bookmark_get_cs"; 
			break;
		case mpe_cmd::dictionary_bookmark_get_sc:
			out << "dictionary_bookmark_get_sc"; 
			break;
		case mpe_cmd::dictionary_per_get_cs:
			out << "dictionary_per_get_cs"; 
			break;
		case mpe_cmd::dictionary_per_get_sc:
			out << "dictionary_per_get_sc"; 
			break;
		case mpe_cmd::achieve_get_cs:
			out << "achieve_get_cs"; 
			break;
		case mpe_cmd::achieve_get_sc:
			out << "achieve_get_sc"; 
			break;
		case mpe_cmd::dictionary_expire_cs:
			out << "dictionary_expire_cs"; 
			break;
		case mpe_cmd::dictionary_expire_sc:
			out << "dictionary_expire_sc"; 
			break;
		case mpe_cmd::paid_acc_reinforce_cs:
			out << "paid_acc_reinforce_cs"; 
			break;
		case mpe_cmd::paid_acc_reinforce_sc:
			out << "paid_acc_reinforce_sc"; 
			break;
		case mpe_cmd::ai_game_login_cs:
			out << "ai_game_login_cs"; 
			break;
		case mpe_cmd::ai_game_login_sc:
			out << "ai_game_login_sc"; 
			break;
		case mpe_cmd::ai_service_start_cs:
			out << "ai_service_start_cs"; 
			break;
		case mpe_cmd::ai_service_start_sc:
			out << "ai_service_start_sc"; 
			break;
		case mpe_cmd::community_login_cs:
			out << "community_login_cs"; 
			break;
		case mpe_cmd::community_login_sc:
			out << "community_login_sc"; 
			break;
		case mpe_cmd::zone_teleport_ai_return_cs:
			out << "zone_teleport_ai_return_cs"; 
			break;
		case mpe_cmd::zone_teleport_ai_return_sc:
			out << "zone_teleport_ai_return_sc"; 
			break;
		case mpe_cmd::cash_shop_buy_cs:
			out << "cash_shop_buy_cs"; 
			break;
		case mpe_cmd::cash_shop_buy_sc:
			out << "cash_shop_buy_sc"; 
			break;
		case mpe_cmd::cash_shop_info_cs:
			out << "cash_shop_info_cs"; 
			break;
		case mpe_cmd::cash_shop_info_sc:
			out << "cash_shop_info_sc"; 
			break;
		case mpe_cmd::cash_shop_cart_get_cs:
			out << "cash_shop_cart_get_cs"; 
			break;
		case mpe_cmd::cash_shop_cart_get_sc:
			out << "cash_shop_cart_get_sc"; 
			break;
		case mpe_cmd::server_time_cs:
			out << "server_time_cs"; 
			break;
		case mpe_cmd::server_time_sc:
			out << "server_time_sc"; 
			break;
		case mpe_cmd::ai_setup_config_cs:
			out << "ai_setup_config_cs"; 
			break;
		case mpe_cmd::ai_setup_config_sc:
			out << "ai_setup_config_sc"; 
			break;
		case mpe_cmd::cash_shop_exchange_reset_cs:
			out << "cash_shop_exchange_reset_cs"; 
			break;
		case mpe_cmd::cash_shop_exchange_reset_sc:
			out << "cash_shop_exchange_reset_sc"; 
			break;
		case mpe_cmd::cash_shop_limited_product_cs:
			out << "cash_shop_limited_product_cs"; 
			break;
		case mpe_cmd::cash_shop_limited_product_sc:
			out << "cash_shop_limited_product_sc"; 
			break;
		case mpe_cmd::indun_step_skip_cs:
			out << "indun_step_skip_cs"; 
			break;
		case mpe_cmd::indun_step_skip_sc:
			out << "indun_step_skip_sc"; 
			break;
		case mpe_cmd::indun_alert_skip_cs:
			out << "indun_alert_skip_cs"; 
			break;
		case mpe_cmd::indun_alert_skip_sc:
			out << "indun_alert_skip_sc"; 
			break;
		case mpe_cmd::guild_shipwar_info_cs:
			out << "guild_shipwar_info_cs"; 
			break;
		case mpe_cmd::guild_shipwar_info_sc:
			out << "guild_shipwar_info_sc"; 
			break;
		case mpe_cmd::guild_shipwar_request_cs:
			out << "guild_shipwar_request_cs"; 
			break;
		case mpe_cmd::guild_shipwar_request_sc:
			out << "guild_shipwar_request_sc"; 
			break;
		case mpe_cmd::guild_shipwar_flag_notify_cs:
			out << "guild_shipwar_flag_notify_cs"; 
			break;
		case mpe_cmd::guild_shipwar_flag_notify_sc:
			out << "guild_shipwar_flag_notify_sc"; 
			break;
		case mpe_cmd::guild_shipwar_situation_cs:
			out << "guild_shipwar_situation_cs"; 
			break;
		case mpe_cmd::guild_shipwar_situation_sc:
			out << "guild_shipwar_situation_sc"; 
			break;
		case mpe_cmd::guild_shipwar_team_info_cs:
			out << "guild_shipwar_team_info_cs"; 
			break;
		case mpe_cmd::guild_shipwar_team_info_sc:
			out << "guild_shipwar_team_info_sc"; 
			break;
		case mpe_cmd::guild_shipwar_play_notify_cs:
			out << "guild_shipwar_play_notify_cs"; 
			break;
		case mpe_cmd::guild_shipwar_play_notify_sc:
			out << "guild_shipwar_play_notify_sc"; 
			break;
		case mpe_cmd::red_dot_noti_cs:
			out << "red_dot_noti_cs"; 
			break;
		case mpe_cmd::red_dot_noti_sc:
			out << "red_dot_noti_sc"; 
			break;
		case mpe_cmd::chatting_block_cs:
			out << "chatting_block_cs"; 
			break;
		case mpe_cmd::chatting_block_sc:
			out << "chatting_block_sc"; 
			break;
		case mpe_cmd::chatting_block_list_cs:
			out << "chatting_block_list_cs"; 
			break;
		case mpe_cmd::chatting_block_list_sc:
			out << "chatting_block_list_sc"; 
			break;
		case mpe_cmd::private_chatting_state_cs:
			out << "private_chatting_state_cs"; 
			break;
		case mpe_cmd::private_chatting_state_sc:
			out << "private_chatting_state_sc"; 
			break;
		case mpe_cmd::cash_shop_daily_get_cs:
			out << "cash_shop_daily_get_cs"; 
			break;
		case mpe_cmd::cash_shop_daily_get_sc:
			out << "cash_shop_daily_get_sc"; 
			break;
		case mpe_cmd::town_rental_request_cs:
			out << "town_rental_request_cs"; 
			break;
		case mpe_cmd::town_rental_request_sc:
			out << "town_rental_request_sc"; 
			break;
		case mpe_cmd::town_alert_cs:
			out << "town_alert_cs"; 
			break;
		case mpe_cmd::town_alert_sc:
			out << "town_alert_sc"; 
			break;
		case mpe_cmd::town_rental_continuation_cs:
			out << "town_rental_continuation_cs"; 
			break;
		case mpe_cmd::town_rental_continuation_sc:
			out << "town_rental_continuation_sc"; 
			break;
		case mpe_cmd::schedule_info_list_cs:
			out << "schedule_info_list_cs"; 
			break;
		case mpe_cmd::schedule_info_list_sc:
			out << "schedule_info_list_sc"; 
			break;
		case mpe_cmd::transform_avatar_cs:
			out << "transform_avatar_cs"; 
			break;
		case mpe_cmd::transform_avatar_sc:
			out << "transform_avatar_sc"; 
			break;
		case mpe_cmd::release_avatar_cs:
			out << "release_avatar_cs"; 
			break;
		case mpe_cmd::release_avatar_sc:
			out << "release_avatar_sc"; 
			break;
		case mpe_cmd::mentor_party_buff_cs:
			out << "mentor_party_buff_cs"; 
			break;
		case mpe_cmd::mentor_party_buff_sc:
			out << "mentor_party_buff_sc"; 
			break;
		case mpe_cmd::guild_shipwar_match_failed_cs:
			out << "guild_shipwar_match_failed_cs"; 
			break;
		case mpe_cmd::guild_shipwar_match_failed_sc:
			out << "guild_shipwar_match_failed_sc"; 
			break;
		case mpe_cmd::subscription_info_cs:
			out << "subscription_info_cs"; 
			break;
		case mpe_cmd::subscription_info_sc:
			out << "subscription_info_sc"; 
			break;
		case mpe_cmd::dictionary_get_all_cs:
			out << "dictionary_get_all_cs"; 
			break;
		case mpe_cmd::dictionary_get_all_sc:
			out << "dictionary_get_all_sc"; 
			break;
		case mpe_cmd::npc_intimacy_add_cs:
			out << "npc_intimacy_add_cs"; 
			break;
		case mpe_cmd::npc_intimacy_add_sc:
			out << "npc_intimacy_add_sc"; 
			break;
		case mpe_cmd::reset_treasurebox_owner_cs:
			out << "reset_treasurebox_owner_cs"; 
			break;
		case mpe_cmd::reset_treasurebox_owner_sc:
			out << "reset_treasurebox_owner_sc"; 
			break;
		case mpe_cmd::revive_limit_cs:
			out << "revive_limit_cs"; 
			break;
		case mpe_cmd::revive_limit_sc:
			out << "revive_limit_sc"; 
			break;
		case mpe_cmd::zone_sector_info_cs:
			out << "zone_sector_info_cs"; 
			break;
		case mpe_cmd::zone_sector_info_sc:
			out << "zone_sector_info_sc"; 
			break;
		case mpe_cmd::summon_pet_cs:
			out << "summon_pet_cs"; 
			break;
		case mpe_cmd::summon_pet_sc:
			out << "summon_pet_sc"; 
			break;
		case mpe_cmd::summon_pet_broad_cs:
			out << "summon_pet_broad_cs"; 
			break;
		case mpe_cmd::summon_pet_broad_sc:
			out << "summon_pet_broad_sc"; 
			break;
		case mpe_cmd::ai_setup_config_info_cs:
			out << "ai_setup_config_info_cs"; 
			break;
		case mpe_cmd::ai_setup_config_info_sc:
			out << "ai_setup_config_info_sc"; 
			break;
		case mpe_cmd::empty3_cs:
			out << "empty3_cs"; 
			break;
		case mpe_cmd::empty3_sc:
			out << "empty3_sc"; 
			break;
		case mpe_cmd::zone_teleport_exit_cs:
			out << "zone_teleport_exit_cs"; 
			break;
		case mpe_cmd::zone_teleport_exit_sc:
			out << "zone_teleport_exit_sc"; 
			break;
		case mpe_cmd::siege_warfare_victory_character_info_cs:
			out << "siege_warfare_victory_character_info_cs"; 
			break;
		case mpe_cmd::siege_warfare_victory_character_info_sc:
			out << "siege_warfare_victory_character_info_sc"; 
			break;
		case mpe_cmd::siege_kill_death_cs:
			out << "siege_kill_death_cs"; 
			break;
		case mpe_cmd::siege_kill_death_sc:
			out << "siege_kill_death_sc"; 
			break;
		case mpe_cmd::zone_call_point_cs:
			out << "zone_call_point_cs"; 
			break;
		case mpe_cmd::zone_call_point_sc:
			out << "zone_call_point_sc"; 
			break;
		case mpe_cmd::special_move_gage_cs:
			out << "special_move_gage_cs"; 
			break;
		case mpe_cmd::special_move_gage_sc:
			out << "special_move_gage_sc"; 
			break;
		case mpe_cmd::enter_story_dungeon_cs:
			out << "enter_story_dungeon_cs"; 
			break;
		case mpe_cmd::enter_story_dungeon_sc:
			out << "enter_story_dungeon_sc"; 
			break;
		case mpe_cmd::leave_story_dungeon_cs:
			out << "leave_story_dungeon_cs"; 
			break;
		case mpe_cmd::leave_story_dungeon_sc:
			out << "leave_story_dungeon_sc"; 
			break;
		case mpe_cmd::trigger_story_dungeon_cs:
			out << "trigger_story_dungeon_cs"; 
			break;
		case mpe_cmd::trigger_story_dungeon_sc:
			out << "trigger_story_dungeon_sc"; 
			break;
		case mpe_cmd::move_story_dungeon_cs:
			out << "move_story_dungeon_cs"; 
			break;
		case mpe_cmd::move_story_dungeon_sc:
			out << "move_story_dungeon_sc"; 
			break;
		case mpe_cmd::npc_intimacy_reward_cs:
			out << "npc_intimacy_reward_cs"; 
			break;
		case mpe_cmd::npc_intimacy_reward_sc:
			out << "npc_intimacy_reward_sc"; 
			break;
		case mpe_cmd::skill_start_story_dungeon_cs:
			out << "skill_start_story_dungeon_cs"; 
			break;
		case mpe_cmd::skill_start_story_dungeon_sc:
			out << "skill_start_story_dungeon_sc"; 
			break;
		case mpe_cmd::object_state_story_dungeon_cs:
			out << "object_state_story_dungeon_cs"; 
			break;
		case mpe_cmd::object_state_story_dungeon_sc:
			out << "object_state_story_dungeon_sc"; 
			break;
		case mpe_cmd::zone_teleport_channel_move_cs:
			out << "zone_teleport_channel_move_cs"; 
			break;
		case mpe_cmd::zone_teleport_channel_move_sc:
			out << "zone_teleport_channel_move_sc"; 
			break;
		case mpe_cmd::slot_option_make_cs:
			out << "slot_option_make_cs"; 
			break;
		case mpe_cmd::slot_option_make_sc:
			out << "slot_option_make_sc"; 
			break;
		case mpe_cmd::slot_option_select_cs:
			out << "slot_option_select_cs"; 
			break;
		case mpe_cmd::slot_option_select_sc:
			out << "slot_option_select_sc"; 
			break;
		case mpe_cmd::slot_upgrade_cs:
			out << "slot_upgrade_cs"; 
			break;
		case mpe_cmd::slot_upgrade_sc:
			out << "slot_upgrade_sc"; 
			break;
		case mpe_cmd::npc_intimacy_reward_get_cs:
			out << "npc_intimacy_reward_get_cs"; 
			break;
		case mpe_cmd::npc_intimacy_reward_get_sc:
			out << "npc_intimacy_reward_get_sc"; 
			break;
		case mpe_cmd::friend_teleport_cs:
			out << "friend_teleport_cs"; 
			break;
		case mpe_cmd::friend_teleport_sc:
			out << "friend_teleport_sc"; 
			break;
		case mpe_cmd::treasureboxkey_charge_cs:
			out << "treasureboxkey_charge_cs"; 
			break;
		case mpe_cmd::treasureboxkey_charge_sc:
			out << "treasureboxkey_charge_sc"; 
			break;
		case mpe_cmd::skill_damage_story_dungeon_cs:
			out << "skill_damage_story_dungeon_cs"; 
			break;
		case mpe_cmd::skill_damage_story_dungeon_sc:
			out << "skill_damage_story_dungeon_sc"; 
			break;
		case mpe_cmd::change_pet_team_cs:
			out << "change_pet_team_cs"; 
			break;
		case mpe_cmd::change_pet_team_sc:
			out << "change_pet_team_sc"; 
			break;
		case mpe_cmd::guild_treasurebox_reward_cs:
			out << "guild_treasurebox_reward_cs"; 
			break;
		case mpe_cmd::guild_treasurebox_reward_sc:
			out << "guild_treasurebox_reward_sc"; 
			break;
		case mpe_cmd::wanted_murder_target_cs:
			out << "wanted_murder_target_cs"; 
			break;
		case mpe_cmd::wanted_murder_target_sc:
			out << "wanted_murder_target_sc"; 
			break;
		case mpe_cmd::wanted_murder_trace_cs:
			out << "wanted_murder_trace_cs"; 
			break;
		case mpe_cmd::wanted_murder_trace_sc:
			out << "wanted_murder_trace_sc"; 
			break;
		case mpe_cmd::heartbeat_check_cs:
			out << "heartbeat_check_cs"; 
			break;
		case mpe_cmd::heartbeat_check_sc:
			out << "heartbeat_check_sc"; 
			break;
		case mpe_cmd::seasonpass_change_cs:
			out << "seasonpass_change_cs"; 
			break;
		case mpe_cmd::seasonpass_change_sc:
			out << "seasonpass_change_sc"; 
			break;
		case mpe_cmd::seasonpass_unlock_cs:
			out << "seasonpass_unlock_cs"; 
			break;
		case mpe_cmd::seasonpass_unlock_sc:
			out << "seasonpass_unlock_sc"; 
			break;
		case mpe_cmd::seasonpass_reward_cs:
			out << "seasonpass_reward_cs"; 
			break;
		case mpe_cmd::seasonpass_reward_sc:
			out << "seasonpass_reward_sc"; 
			break;
		case mpe_cmd::seasonpass_challenge_complet_cs:
			out << "seasonpass_challenge_complet_cs"; 
			break;
		case mpe_cmd::seasonpass_challenge_complet_sc:
			out << "seasonpass_challenge_complet_sc"; 
			break;
		case mpe_cmd::seasonpass_challenge_update_cs:
			out << "seasonpass_challenge_update_cs"; 
			break;
		case mpe_cmd::seasonpass_challenge_update_sc:
			out << "seasonpass_challenge_update_sc"; 
			break;
		case mpe_cmd::guard_pass_buy_cs:
			out << "guard_pass_buy_cs"; 
			break;
		case mpe_cmd::guard_pass_buy_sc:
			out << "guard_pass_buy_sc"; 
			break;
		case mpe_cmd::pk_alert_record_remove_cs:
			out << "pk_alert_record_remove_cs"; 
			break;
		case mpe_cmd::pk_alert_record_remove_sc:
			out << "pk_alert_record_remove_sc"; 
			break;
		case mpe_cmd::avatar_mix_cs:
			out << "avatar_mix_cs"; 
			break;
		case mpe_cmd::avatar_mix_sc:
			out << "avatar_mix_sc"; 
			break;
		case mpe_cmd::avatar_slot_set_cs:
			out << "avatar_slot_set_cs"; 
			break;
		case mpe_cmd::avatar_slot_set_sc:
			out << "avatar_slot_set_sc"; 
			break;
		case mpe_cmd::castle_owner_info_cs:
			out << "castle_owner_info_cs"; 
			break;
		case mpe_cmd::castle_owner_info_sc:
			out << "castle_owner_info_sc"; 
			break;
		case mpe_cmd::guild_mark_change_cs:
			out << "guild_mark_change_cs"; 
			break;
		case mpe_cmd::guild_mark_change_sc:
			out << "guild_mark_change_sc"; 
			break;
		case mpe_cmd::guild_alert_change_mark_cs:
			out << "guild_alert_change_mark_cs"; 
			break;
		case mpe_cmd::guild_alert_change_mark_sc:
			out << "guild_alert_change_mark_sc"; 
			break;
		case mpe_cmd::avatar_cool_time_cs:
			out << "avatar_cool_time_cs"; 
			break;
		case mpe_cmd::avatar_cool_time_sc:
			out << "avatar_cool_time_sc"; 
			break;
		case mpe_cmd::guild_buff_buy_cs:
			out << "guild_buff_buy_cs"; 
			break;
		case mpe_cmd::guild_buff_buy_sc:
			out << "guild_buff_buy_sc"; 
			break;
		case mpe_cmd::guild_gold_alert_cs:
			out << "guild_gold_alert_cs"; 
			break;
		case mpe_cmd::guild_gold_alert_sc:
			out << "guild_gold_alert_sc"; 
			break;
		case mpe_cmd::guild_dungeon_cumulative_damage_cs:
			out << "guild_dungeon_cumulative_damage_cs"; 
			break;
		case mpe_cmd::guild_dungeon_cumulative_damage_sc:
			out << "guild_dungeon_cumulative_damage_sc"; 
			break;
		case mpe_cmd::mail_received_cs:
			out << "mail_received_cs"; 
			break;
		case mpe_cmd::mail_received_sc:
			out << "mail_received_sc"; 
			break;
		case mpe_cmd::item_lock_cs:
			out << "item_lock_cs"; 
			break;
		case mpe_cmd::item_lock_sc:
			out << "item_lock_sc"; 
			break;
		case mpe_cmd::lord_bless_info_cs:
			out << "lord_bless_info_cs"; 
			break;
		case mpe_cmd::lord_bless_info_sc:
			out << "lord_bless_info_sc"; 
			break;
		case mpe_cmd::lord_message_cs:
			out << "lord_message_cs"; 
			break;
		case mpe_cmd::lord_message_sc:
			out << "lord_message_sc"; 
			break;
		case mpe_cmd::lord_worship_cs:
			out << "lord_worship_cs"; 
			break;
		case mpe_cmd::lord_worship_sc:
			out << "lord_worship_sc"; 
			break;
		case mpe_cmd::lord_bless_buff_use_cs:
			out << "lord_bless_buff_use_cs"; 
			break;
		case mpe_cmd::lord_bless_buff_use_sc:
			out << "lord_bless_buff_use_sc"; 
			break;
		case mpe_cmd::lord_bless_buff_info_cs:
			out << "lord_bless_buff_info_cs"; 
			break;
		case mpe_cmd::lord_bless_buff_info_sc:
			out << "lord_bless_buff_info_sc"; 
			break;
		case mpe_cmd::illusion_dungeon_time_charge_cs:
			out << "illusion_dungeon_time_charge_cs"; 
			break;
		case mpe_cmd::illusion_dungeon_time_charge_sc:
			out << "illusion_dungeon_time_charge_sc"; 
			break;
		case mpe_cmd::secretvalley_alert_cs:
			out << "secretvalley_alert_cs"; 
			break;
		case mpe_cmd::secretvalley_alert_sc:
			out << "secretvalley_alert_sc"; 
			break;
		case mpe_cmd::secretvalley_info_cs:
			out << "secretvalley_info_cs"; 
			break;
		case mpe_cmd::secretvalley_info_sc:
			out << "secretvalley_info_sc"; 
			break;
		case mpe_cmd::revive_list_cs:
			out << "revive_list_cs"; 
			break;
		case mpe_cmd::revive_list_sc:
			out << "revive_list_sc"; 
			break;
		case mpe_cmd::recovery_exp_cs:
			out << "recovery_exp_cs"; 
			break;
		case mpe_cmd::recovery_exp_sc:
			out << "recovery_exp_sc"; 
			break;
		case mpe_cmd::reflection_equip_cs:
			out << "reflection_equip_cs"; 
			break;
		case mpe_cmd::reflection_equip_sc:
			out << "reflection_equip_sc"; 
			break;
		case mpe_cmd::reflection_mix_cs:
			out << "reflection_mix_cs"; 
			break;
		case mpe_cmd::reflection_mix_sc:
			out << "reflection_mix_sc"; 
			break;
		case mpe_cmd::revive_request_cs:
			out << "revive_request_cs"; 
			break;
		case mpe_cmd::revive_request_sc:
			out << "revive_request_sc"; 
			break;
		case mpe_cmd::lord_bless_end_time_cs:
			out << "lord_bless_end_time_cs"; 
			break;
		case mpe_cmd::lord_bless_end_time_sc:
			out << "lord_bless_end_time_sc"; 
			break;
		case mpe_cmd::zone_seal_device_use_cs:
			out << "zone_seal_device_use_cs"; 
			break;
		case mpe_cmd::zone_seal_device_use_sc:
			out << "zone_seal_device_use_sc"; 
			break;
		case mpe_cmd::zone_seal_device_info_cs:
			out << "zone_seal_device_info_cs"; 
			break;
		case mpe_cmd::zone_seal_device_info_sc:
			out << "zone_seal_device_info_sc"; 
			break;
		case mpe_cmd::blackiron_sell_regist_cs:
			out << "blackiron_sell_regist_cs"; 
			break;
		case mpe_cmd::blackiron_sell_regist_sc:
			out << "blackiron_sell_regist_sc"; 
			break;
		case mpe_cmd::blackiron_sell_info_cs:
			out << "blackiron_sell_info_cs"; 
			break;
		case mpe_cmd::blackiron_sell_info_sc:
			out << "blackiron_sell_info_sc"; 
			break;
		case mpe_cmd::demon_tower_info_cs:
			out << "demon_tower_info_cs"; 
			break;
		case mpe_cmd::demon_tower_info_sc:
			out << "demon_tower_info_sc"; 
			break;
		case mpe_cmd::demon_summon_info_cs:
			out << "demon_summon_info_cs"; 
			break;
		case mpe_cmd::demon_summon_info_sc:
			out << "demon_summon_info_sc"; 
			break;
		case mpe_cmd::customizing_save_cs:
			out << "customizing_save_cs"; 
			break;
		case mpe_cmd::customizing_save_sc:
			out << "customizing_save_sc"; 
			break;
		case mpe_cmd::guild_blackiron_alert_cs:
			out << "guild_blackiron_alert_cs"; 
			break;
		case mpe_cmd::guild_blackiron_alert_sc:
			out << "guild_blackiron_alert_sc"; 
			break;
		case mpe_cmd::illusion_dungeon_time_out_cs:
			out << "illusion_dungeon_time_out_cs"; 
			break;
		case mpe_cmd::illusion_dungeon_time_out_sc:
			out << "illusion_dungeon_time_out_sc"; 
			break;
		case mpe_cmd::temp_reflection_change_cs:
			out << "temp_reflection_change_cs"; 
			break;
		case mpe_cmd::temp_reflection_change_sc:
			out << "temp_reflection_change_sc"; 
			break;
		case mpe_cmd::temp_reflection_confirm_cs:
			out << "temp_reflection_confirm_cs"; 
			break;
		case mpe_cmd::temp_reflection_confirm_sc:
			out << "temp_reflection_confirm_sc"; 
			break;
		case mpe_cmd::temp_reflection_get_cs:
			out << "temp_reflection_get_cs"; 
			break;
		case mpe_cmd::temp_reflection_get_sc:
			out << "temp_reflection_get_sc"; 
			break;
		case mpe_cmd::monster_phase_change_cs:
			out << "monster_phase_change_cs"; 
			break;
		case mpe_cmd::monster_phase_change_sc:
			out << "monster_phase_change_sc"; 
			break;
		case mpe_cmd::zone_observer_mode_cs:
			out << "zone_observer_mode_cs"; 
			break;
		case mpe_cmd::zone_observer_mode_sc:
			out << "zone_observer_mode_sc"; 
			break;
		case mpe_cmd::arena_battle_match_regist_cs:
			out << "arena_battle_match_regist_cs"; 
			break;
		case mpe_cmd::arena_battle_match_regist_sc:
			out << "arena_battle_match_regist_sc"; 
			break;
		case mpe_cmd::arena_battle_match_regist_cancel_cs:
			out << "arena_battle_match_regist_cancel_cs"; 
			break;
		case mpe_cmd::arena_battle_match_regist_cancel_sc:
			out << "arena_battle_match_regist_cancel_sc"; 
			break;
		case mpe_cmd::arena_battle_score_board_cs:
			out << "arena_battle_score_board_cs"; 
			break;
		case mpe_cmd::arena_battle_score_board_sc:
			out << "arena_battle_score_board_sc"; 
			break;
		case mpe_cmd::arena_battle_alert_cs:
			out << "arena_battle_alert_cs"; 
			break;
		case mpe_cmd::arena_battle_alert_sc:
			out << "arena_battle_alert_sc"; 
			break;
		case mpe_cmd::arena_battle_season_reward_cs:
			out << "arena_battle_season_reward_cs"; 
			break;
		case mpe_cmd::arena_battle_season_reward_sc:
			out << "arena_battle_season_reward_sc"; 
			break;
		case mpe_cmd::skill_force_reinforce_cs:
			out << "skill_force_reinforce_cs"; 
			break;
		case mpe_cmd::skill_force_reinforce_sc:
			out << "skill_force_reinforce_sc"; 
			break;
		case mpe_cmd::mandala_node_add_cs:
			out << "mandala_node_add_cs"; 
			break;
		case mpe_cmd::mandala_node_add_sc:
			out << "mandala_node_add_sc"; 
			break;
		case mpe_cmd::mandala_rotation_cs:
			out << "mandala_rotation_cs"; 
			break;
		case mpe_cmd::mandala_rotation_sc:
			out << "mandala_rotation_sc"; 
			break;
		case mpe_cmd::mandala_reset_cs:
			out << "mandala_reset_cs"; 
			break;
		case mpe_cmd::mandala_reset_sc:
			out << "mandala_reset_sc"; 
			break;
		case mpe_cmd::mandala_node_levelup_cs:
			out << "mandala_node_levelup_cs"; 
			break;
		case mpe_cmd::mandala_node_levelup_sc:
			out << "mandala_node_levelup_sc"; 
			break;
		case mpe_cmd::mandala_node_equip_cs:
			out << "mandala_node_equip_cs"; 
			break;
		case mpe_cmd::mandala_node_equip_sc:
			out << "mandala_node_equip_sc"; 
			break;
		case mpe_cmd::mandala_stone_upgrade_cs:
			out << "mandala_stone_upgrade_cs"; 
			break;
		case mpe_cmd::mandala_stone_upgrade_sc:
			out << "mandala_stone_upgrade_sc"; 
			break;
		case mpe_cmd::indun_monarch_item_regist_cs:
			out << "indun_monarch_item_regist_cs"; 
			break;
		case mpe_cmd::indun_monarch_item_regist_sc:
			out << "indun_monarch_item_regist_sc"; 
			break;
		case mpe_cmd::indun_monarch_state_alert_cs:
			out << "indun_monarch_state_alert_cs"; 
			break;
		case mpe_cmd::indun_monarch_state_alert_sc:
			out << "indun_monarch_state_alert_sc"; 
			break;
		case mpe_cmd::guild_goods_update_cs:
			out << "guild_goods_update_cs"; 
			break;
		case mpe_cmd::guild_goods_update_sc:
			out << "guild_goods_update_sc"; 
			break;
		case mpe_cmd::indun_monarch_spawn_mob_info_cs:
			out << "indun_monarch_spawn_mob_info_cs"; 
			break;
		case mpe_cmd::indun_monarch_spawn_mob_info_sc:
			out << "indun_monarch_spawn_mob_info_sc"; 
			break;
		case mpe_cmd::guild_alert_member_contribution_update_cs:
			out << "guild_alert_member_contribution_update_cs"; 
			break;
		case mpe_cmd::guild_alert_member_contribution_update_sc:
			out << "guild_alert_member_contribution_update_sc"; 
			break;
		case mpe_cmd::street_stall_create_cs:
			out << "street_stall_create_cs"; 
			break;
		case mpe_cmd::street_stall_create_sc:
			out << "street_stall_create_sc"; 
			break;
		case mpe_cmd::street_stall_create_cancel_cs:
			out << "street_stall_create_cancel_cs"; 
			break;
		case mpe_cmd::street_stall_create_cancel_sc:
			out << "street_stall_create_cancel_sc"; 
			break;
		case mpe_cmd::street_stall_start_cs:
			out << "street_stall_start_cs"; 
			break;
		case mpe_cmd::street_stall_start_sc:
			out << "street_stall_start_sc"; 
			break;
		case mpe_cmd::street_stall_start_result_cs:
			out << "street_stall_start_result_cs"; 
			break;
		case mpe_cmd::street_stall_start_result_sc:
			out << "street_stall_start_result_sc"; 
			break;
		case mpe_cmd::street_stall_stop_cs:
			out << "street_stall_stop_cs"; 
			break;
		case mpe_cmd::street_stall_stop_sc:
			out << "street_stall_stop_sc"; 
			break;
		case mpe_cmd::street_stall_unmanned_cs:
			out << "street_stall_unmanned_cs"; 
			break;
		case mpe_cmd::street_stall_unmanned_sc:
			out << "street_stall_unmanned_sc"; 
			break;
		case mpe_cmd::street_stall_info_cs:
			out << "street_stall_info_cs"; 
			break;
		case mpe_cmd::street_stall_info_sc:
			out << "street_stall_info_sc"; 
			break;
		case mpe_cmd::guild_mark_alert_cs:
			out << "guild_mark_alert_cs"; 
			break;
		case mpe_cmd::guild_mark_alert_sc:
			out << "guild_mark_alert_sc"; 
			break;
		case mpe_cmd::party_auto_target_set_cs:
			out << "party_auto_target_set_cs"; 
			break;
		case mpe_cmd::party_auto_target_set_sc:
			out << "party_auto_target_set_sc"; 
			break;
		case mpe_cmd::party_auto_target_uid_cs:
			out << "party_auto_target_uid_cs"; 
			break;
		case mpe_cmd::party_auto_target_uid_sc:
			out << "party_auto_target_uid_sc"; 
			break;
		case mpe_cmd::contents_onoff_info_cs:
			out << "contents_onoff_info_cs"; 
			break;
		case mpe_cmd::contents_onoff_info_sc:
			out << "contents_onoff_info_sc"; 
			break;
		case mpe_cmd::street_stall_sell_info_cs:
			out << "street_stall_sell_info_cs"; 
			break;
		case mpe_cmd::street_stall_sell_info_sc:
			out << "street_stall_sell_info_sc"; 
			break;
		case mpe_cmd::street_stall_enter_info_cs:
			out << "street_stall_enter_info_cs"; 
			break;
		case mpe_cmd::street_stall_enter_info_sc:
			out << "street_stall_enter_info_sc"; 
			break;
		case mpe_cmd::illusion_dungeon_info_cs:
			out << "illusion_dungeon_info_cs"; 
			break;
		case mpe_cmd::illusion_dungeon_info_sc:
			out << "illusion_dungeon_info_sc"; 
			break;
		case mpe_cmd::street_stall_buy_open_cs:
			out << "street_stall_buy_open_cs"; 
			break;
		case mpe_cmd::street_stall_buy_open_sc:
			out << "street_stall_buy_open_sc"; 
			break;
		case mpe_cmd::street_stall_buy_cs:
			out << "street_stall_buy_cs"; 
			break;
		case mpe_cmd::street_stall_buy_sc:
			out << "street_stall_buy_sc"; 
			break;
		case mpe_cmd::street_stall_get_use_count_cs:
			out << "street_stall_get_use_count_cs"; 
			break;
		case mpe_cmd::street_stall_get_use_count_sc:
			out << "street_stall_get_use_count_sc"; 
			break;
		case mpe_cmd::title_reward_cs:
			out << "title_reward_cs"; 
			break;
		case mpe_cmd::title_reward_sc:
			out << "title_reward_sc"; 
			break;
		case mpe_cmd::update_max_hp_mp_cs:
			out << "update_max_hp_mp_cs"; 
			break;
		case mpe_cmd::update_max_hp_mp_sc:
			out << "update_max_hp_mp_sc"; 
			break;
		case mpe_cmd::chat_command_cs:
			out << "chat_command_cs"; 
			break;
		case mpe_cmd::chat_command_sc:
			out << "chat_command_sc"; 
			break;
		case mpe_cmd::illusion_dungeon_info_get_cs:
			out << "illusion_dungeon_info_get_cs"; 
			break;
		case mpe_cmd::illusion_dungeon_info_get_sc:
			out << "illusion_dungeon_info_get_sc"; 
			break;
		case mpe_cmd::field_boss_kill_cs:
			out << "field_boss_kill_cs"; 
			break;
		case mpe_cmd::field_boss_kill_sc:
			out << "field_boss_kill_sc"; 
			break;
		case mpe_cmd::character_fixed_battle_cs:
			out << "character_fixed_battle_cs"; 
			break;
		case mpe_cmd::character_fixed_battle_sc:
			out << "character_fixed_battle_sc"; 
			break;
		case mpe_cmd::auth_check_cs:
			out << "auth_check_cs"; 
			break;
		case mpe_cmd::auth_check_sc:
			out << "auth_check_sc"; 
			break;
		case mpe_cmd::session_auth_cs:
			out << "session_auth_cs"; 
			break;
		case mpe_cmd::session_auth_sc:
			out << "session_auth_sc"; 
			break;
		case mpe_cmd::achieve_add_cs:
			out << "achieve_add_cs"; 
			break;
		case mpe_cmd::achieve_add_sc:
			out << "achieve_add_sc"; 
			break;
		case mpe_cmd::achieve_reward_cs:
			out << "achieve_reward_cs"; 
			break;
		case mpe_cmd::achieve_reward_sc:
			out << "achieve_reward_sc"; 
			break;
		case mpe_cmd::arena_join_cs:
			out << "arena_join_cs"; 
			break;
		case mpe_cmd::arena_join_sc:
			out << "arena_join_sc"; 
			break;
		case mpe_cmd::send_nickname_disable_cs:
			out << "send_nickname_disable_cs"; 
			break;
		case mpe_cmd::send_nickname_disable_sc:
			out << "send_nickname_disable_sc"; 
			break;
		case mpe_cmd::quest_reward_change_cs:
			out << "quest_reward_change_cs"; 
			break;
		case mpe_cmd::quest_reward_change_sc:
			out << "quest_reward_change_sc"; 
			break;
		case mpe_cmd::arena_battle_matching_count_cs:
			out << "arena_battle_matching_count_cs"; 
			break;
		case mpe_cmd::arena_battle_matching_count_sc:
			out << "arena_battle_matching_count_sc"; 
			break;
		case mpe_cmd::session_type_cs:
			out << "session_type_cs"; 
			break;
		case mpe_cmd::session_type_sc:
			out << "session_type_sc"; 
			break;
		case mpe_cmd::item_enchant_option_change_cs:
			out << "item_enchant_option_change_cs"; 
			break;
		case mpe_cmd::item_enchant_option_change_sc:
			out << "item_enchant_option_change_sc"; 
			break;
		case mpe_cmd::indun_remaining_time_cs:
			out << "indun_remaining_time_cs"; 
			break;
		case mpe_cmd::indun_remaining_time_sc:
			out << "indun_remaining_time_sc"; 
			break;
		case mpe_cmd::arena_battle_revive_count_cs:
			out << "arena_battle_revive_count_cs"; 
			break;
		case mpe_cmd::arena_battle_revive_count_sc:
			out << "arena_battle_revive_count_sc"; 
			break;
		case mpe_cmd::guild_goods_exchange_cs:
			out << "guild_goods_exchange_cs"; 
			break;
		case mpe_cmd::guild_goods_exchange_sc:
			out << "guild_goods_exchange_sc"; 
			break;
		case mpe_cmd::temp_pet_change_cs:
			out << "temp_pet_change_cs"; 
			break;
		case mpe_cmd::temp_pet_change_sc:
			out << "temp_pet_change_sc"; 
			break;
		case mpe_cmd::temp_pet_confirm_cs:
			out << "temp_pet_confirm_cs"; 
			break;
		case mpe_cmd::temp_pet_confirm_sc:
			out << "temp_pet_confirm_sc"; 
			break;
		case mpe_cmd::temp_pet_get_cs:
			out << "temp_pet_get_cs"; 
			break;
		case mpe_cmd::temp_pet_get_sc:
			out << "temp_pet_get_sc"; 
			break;
		case mpe_cmd::zone_client_request_object_info_cs:
			out << "zone_client_request_object_info_cs"; 
			break;
		case mpe_cmd::zone_client_request_object_info_sc:
			out << "zone_client_request_object_info_sc"; 
			break;
		case mpe_cmd::tonic_charge_cs:
			out << "tonic_charge_cs"; 
			break;
		case mpe_cmd::tonic_charge_sc:
			out << "tonic_charge_sc"; 
			break;
		case mpe_cmd::inven_size_change_cs:
			out << "inven_size_change_cs"; 
			break;
		case mpe_cmd::inven_size_change_sc:
			out << "inven_size_change_sc"; 
			break;
		case mpe_cmd::eclipse_center_cs:
			out << "eclipse_center_cs"; 
			break;
		case mpe_cmd::eclipse_center_sc:
			out << "eclipse_center_sc"; 
			break;
		case mpe_cmd::ranking_buff_reset_cs:
			out << "ranking_buff_reset_cs"; 
			break;
		case mpe_cmd::ranking_buff_reset_sc:
			out << "ranking_buff_reset_sc"; 
			break;
		case mpe_cmd::mandala_node_reset_cs:
			out << "mandala_node_reset_cs"; 
			break;
		case mpe_cmd::mandala_node_reset_sc:
			out << "mandala_node_reset_sc"; 
			break;
		case mpe_cmd::street_stall_pr_cs:
			out << "street_stall_pr_cs"; 
			break;
		case mpe_cmd::street_stall_pr_sc:
			out << "street_stall_pr_sc"; 
			break;
		case mpe_cmd::street_stall_teleport_cs:
			out << "street_stall_teleport_cs"; 
			break;
		case mpe_cmd::street_stall_teleport_sc:
			out << "street_stall_teleport_sc"; 
			break;
		case mpe_cmd::game_login_inven_cs:
			out << "game_login_inven_cs"; 
			break;
		case mpe_cmd::game_login_inven_sc:
			out << "game_login_inven_sc"; 
			break;
		case mpe_cmd::game_login_mandala_cs:
			out << "game_login_mandala_cs"; 
			break;
		case mpe_cmd::game_login_mandala_sc:
			out << "game_login_mandala_sc"; 
			break;
		case mpe_cmd::game_login_inven_stone_cs:
			out << "game_login_inven_stone_cs"; 
			break;
		case mpe_cmd::game_login_inven_stone_sc:
			out << "game_login_inven_stone_sc"; 
			break;
		case mpe_cmd::npc_shop_open_cs:
			out << "npc_shop_open_cs"; 
			break;
		case mpe_cmd::npc_shop_open_sc:
			out << "npc_shop_open_sc"; 
			break;
		case mpe_cmd::guild_dungeon_enter_charge_cs:
			out << "guild_dungeon_enter_charge_cs"; 
			break;
		case mpe_cmd::guild_dungeon_enter_charge_sc:
			out << "guild_dungeon_enter_charge_sc"; 
			break;
		case mpe_cmd::guild_alert_dungeon_info_cs:
			out << "guild_alert_dungeon_info_cs"; 
			break;
		case mpe_cmd::guild_alert_dungeon_info_sc:
			out << "guild_alert_dungeon_info_sc"; 
			break;
		case mpe_cmd::cash_limit_product_noti_cs:
			out << "cash_limit_product_noti_cs"; 
			break;
		case mpe_cmd::cash_limit_product_noti_sc:
			out << "cash_limit_product_noti_sc"; 
			break;
		case mpe_cmd::item_restore_request_cs:
			out << "item_restore_request_cs"; 
			break;
		case mpe_cmd::item_restore_request_sc:
			out << "item_restore_request_sc"; 
			break;
		case mpe_cmd::zone_client_request_object_state_info_cs:
			out << "zone_client_request_object_state_info_cs"; 
			break;
		case mpe_cmd::zone_client_request_object_state_info_sc:
			out << "zone_client_request_object_state_info_sc"; 
			break;
		case mpe_cmd::zone_client_option_setup_cs:
			out << "zone_client_option_setup_cs"; 
			break;
		case mpe_cmd::zone_client_option_setup_sc:
			out << "zone_client_option_setup_sc"; 
			break;
		case mpe_cmd::guild_shipwar_season_reward_cs:
			out << "guild_shipwar_season_reward_cs"; 
			break;
		case mpe_cmd::guild_shipwar_season_reward_sc:
			out << "guild_shipwar_season_reward_sc"; 
			break;
		case mpe_cmd::guild_shipwar_unearned_win_alarm_cs:
			out << "guild_shipwar_unearned_win_alarm_cs"; 
			break;
		case mpe_cmd::guild_shipwar_unearned_win_alarm_sc:
			out << "guild_shipwar_unearned_win_alarm_sc"; 
			break;
		case mpe_cmd::occupationwar_info_cs:
			out << "occupationwar_info_cs"; 
			break;
		case mpe_cmd::occupationwar_info_sc:
			out << "occupationwar_info_sc"; 
			break;
		case mpe_cmd::occupationwar_tender_deposit_cs:
			out << "occupationwar_tender_deposit_cs"; 
			break;
		case mpe_cmd::occupationwar_tender_deposit_sc:
			out << "occupationwar_tender_deposit_sc"; 
			break;
		case mpe_cmd::occupationwar_tender_withdraw_cs:
			out << "occupationwar_tender_withdraw_cs"; 
			break;
		case mpe_cmd::occupationwar_tender_withdraw_sc:
			out << "occupationwar_tender_withdraw_sc"; 
			break;
		case mpe_cmd::occupationwar_request_info_cs:
			out << "occupationwar_request_info_cs"; 
			break;
		case mpe_cmd::occupationwar_request_info_sc:
			out << "occupationwar_request_info_sc"; 
			break;
		case mpe_cmd::occupationwar_challenge_request_info_cs:
			out << "occupationwar_challenge_request_info_cs"; 
			break;
		case mpe_cmd::occupationwar_challenge_request_info_sc:
			out << "occupationwar_challenge_request_info_sc"; 
			break;
		case mpe_cmd::occupationwar_challenge_request_cs:
			out << "occupationwar_challenge_request_cs"; 
			break;
		case mpe_cmd::occupationwar_challenge_request_sc:
			out << "occupationwar_challenge_request_sc"; 
			break;
		case mpe_cmd::occupationwar_guild_info_cs:
			out << "occupationwar_guild_info_cs"; 
			break;
		case mpe_cmd::occupationwar_guild_info_sc:
			out << "occupationwar_guild_info_sc"; 
			break;
		case mpe_cmd::darksteel_storage_darksteel_pay_cs:
			out << "darksteel_storage_darksteel_pay_cs"; 
			break;
		case mpe_cmd::darksteel_storage_darksteel_pay_sc:
			out << "darksteel_storage_darksteel_pay_sc"; 
			break;
		case mpe_cmd::darksteel_storage_darksteel_sell_cs:
			out << "darksteel_storage_darksteel_sell_cs"; 
			break;
		case mpe_cmd::darksteel_storage_darksteel_sell_sc:
			out << "darksteel_storage_darksteel_sell_sc"; 
			break;
		case mpe_cmd::darksteel_storage_darksteel_withdraw_cs:
			out << "darksteel_storage_darksteel_withdraw_cs"; 
			break;
		case mpe_cmd::darksteel_storage_darksteel_withdraw_sc:
			out << "darksteel_storage_darksteel_withdraw_sc"; 
			break;
		case mpe_cmd::guild_search_custom_cs:
			out << "guild_search_custom_cs"; 
			break;
		case mpe_cmd::guild_search_custom_sc:
			out << "guild_search_custom_sc"; 
			break;
		case mpe_cmd::wallet_login_cs:
			out << "wallet_login_cs"; 
			break;
		case mpe_cmd::wallet_login_sc:
			out << "wallet_login_sc"; 
			break;
		case mpe_cmd::wallet_linked_account_cs:
			out << "wallet_linked_account_cs"; 
			break;
		case mpe_cmd::wallet_linked_account_sc:
			out << "wallet_linked_account_sc"; 
			break;
		case mpe_cmd::get_contract_address_cs:
			out << "get_contract_address_cs"; 
			break;
		case mpe_cmd::get_contract_address_sc:
			out << "get_contract_address_sc"; 
			break;
		case mpe_cmd::trade_darksteelbox_to_token_cs:
			out << "trade_darksteelbox_to_token_cs"; 
			break;
		case mpe_cmd::trade_darksteelbox_to_token_sc:
			out << "trade_darksteelbox_to_token_sc"; 
			break;
		case mpe_cmd::trade_token_to_darksteelbox_cs:
			out << "trade_token_to_darksteelbox_cs"; 
			break;
		case mpe_cmd::trade_token_to_darksteelbox_sc:
			out << "trade_token_to_darksteelbox_sc"; 
			break;
		case mpe_cmd::approve_make_transaction_cs:
			out << "approve_make_transaction_cs"; 
			break;
		case mpe_cmd::approve_make_transaction_sc:
			out << "approve_make_transaction_sc"; 
			break;
		case mpe_cmd::approve_send_transaction_cs:
			out << "approve_send_transaction_cs"; 
			break;
		case mpe_cmd::approve_send_transaction_sc:
			out << "approve_send_transaction_sc"; 
			break;
		case mpe_cmd::global_exchange_register_cs:
			out << "global_exchange_register_cs"; 
			break;
		case mpe_cmd::global_exchange_register_sc:
			out << "global_exchange_register_sc"; 
			break;
		case mpe_cmd::global_exchange_register_cancel_cs:
			out << "global_exchange_register_cancel_cs"; 
			break;
		case mpe_cmd::global_exchange_register_cancel_sc:
			out << "global_exchange_register_cancel_sc"; 
			break;
		case mpe_cmd::global_exchange_buy_cs:
			out << "global_exchange_buy_cs"; 
			break;
		case mpe_cmd::global_exchange_buy_sc:
			out << "global_exchange_buy_sc"; 
			break;
		case mpe_cmd::global_exchange_gold_withdraw_cs:
			out << "global_exchange_gold_withdraw_cs"; 
			break;
		case mpe_cmd::global_exchange_gold_withdraw_sc:
			out << "global_exchange_gold_withdraw_sc"; 
			break;
		case mpe_cmd::global_exchange_item_withdraw_cs:
			out << "global_exchange_item_withdraw_cs"; 
			break;
		case mpe_cmd::global_exchange_item_withdraw_sc:
			out << "global_exchange_item_withdraw_sc"; 
			break;
		case mpe_cmd::staking_make_tx_cs:
			out << "staking_make_tx_cs"; 
			break;
		case mpe_cmd::staking_make_tx_sc:
			out << "staking_make_tx_sc"; 
			break;
		case mpe_cmd::staking_send_tx_cs:
			out << "staking_send_tx_cs"; 
			break;
		case mpe_cmd::staking_send_tx_sc:
			out << "staking_send_tx_sc"; 
			break;
		case mpe_cmd::claim_make_tx_cs:
			out << "claim_make_tx_cs"; 
			break;
		case mpe_cmd::claim_make_tx_sc:
			out << "claim_make_tx_sc"; 
			break;
		case mpe_cmd::claim_send_tx_cs:
			out << "claim_send_tx_cs"; 
			break;
		case mpe_cmd::claim_send_tx_sc:
			out << "claim_send_tx_sc"; 
			break;
		case mpe_cmd::governance_staking_cs:
			out << "governance_staking_cs"; 
			break;
		case mpe_cmd::governance_staking_sc:
			out << "governance_staking_sc"; 
			break;
		case mpe_cmd::governance_unstaking_cs:
			out << "governance_unstaking_cs"; 
			break;
		case mpe_cmd::governance_unstaking_sc:
			out << "governance_unstaking_sc"; 
			break;
		case mpe_cmd::token_history_item_get_cs:
			out << "token_history_item_get_cs"; 
			break;
		case mpe_cmd::token_history_item_get_sc:
			out << "token_history_item_get_sc"; 
			break;
		case mpe_cmd::global_party_governance_rank_cs:
			out << "global_party_governance_rank_cs"; 
			break;
		case mpe_cmd::global_party_governance_rank_sc:
			out << "global_party_governance_rank_sc"; 
			break;
		case mpe_cmd::is_party_governance_decide_user_cs:
			out << "is_party_governance_decide_user_cs"; 
			break;
		case mpe_cmd::is_party_governance_decide_user_sc:
			out << "is_party_governance_decide_user_sc"; 
			break;
		case mpe_cmd::global_party_governance_account_staking_cs:
			out << "global_party_governance_account_staking_cs"; 
			break;
		case mpe_cmd::global_party_governance_account_staking_sc:
			out << "global_party_governance_account_staking_sc"; 
			break;
		case mpe_cmd::check_send_nickname_disable_cs:
			out << "check_send_nickname_disable_cs"; 
			break;
		case mpe_cmd::check_send_nickname_disable_sc:
			out << "check_send_nickname_disable_sc"; 
			break;
		case mpe_cmd::item_use_change_nickname_cs:
			out << "item_use_change_nickname_cs"; 
			break;
		case mpe_cmd::item_use_change_nickname_sc:
			out << "item_use_change_nickname_sc"; 
			break;
		case mpe_cmd::check_nickname_cs:
			out << "check_nickname_cs"; 
			break;
		case mpe_cmd::check_nickname_sc:
			out << "check_nickname_sc"; 
			break;
		case mpe_cmd::guild_alert_change_nickname_cs:
			out << "guild_alert_change_nickname_cs"; 
			break;
		case mpe_cmd::guild_alert_change_nickname_sc:
			out << "guild_alert_change_nickname_sc"; 
			break;
		case mpe_cmd::guild_change_nickname_cs:
			out << "guild_change_nickname_cs"; 
			break;
		case mpe_cmd::guild_change_nickname_sc:
			out << "guild_change_nickname_sc"; 
			break;
		case mpe_cmd::enchant_stone_mix_cs:
			out << "enchant_stone_mix_cs"; 
			break;
		case mpe_cmd::enchant_stone_mix_sc:
			out << "enchant_stone_mix_sc"; 
			break;
		case mpe_cmd::reward_ad_cs:
			out << "reward_ad_cs"; 
			break;
		case mpe_cmd::reward_ad_sc:
			out << "reward_ad_sc"; 
			break;
		case mpe_cmd::advertisement_reward_cs:
			out << "advertisement_reward_cs"; 
			break;
		case mpe_cmd::advertisement_reward_sc:
			out << "advertisement_reward_sc"; 
			break;
		case mpe_cmd::game_login_inven_essence_cs:
			out << "game_login_inven_essence_cs"; 
			break;
		case mpe_cmd::game_login_inven_essence_sc:
			out << "game_login_inven_essence_sc"; 
			break;
		case mpe_cmd::server_relocation_cs:
			out << "server_relocation_cs"; 
			break;
		case mpe_cmd::server_relocation_sc:
			out << "server_relocation_sc"; 
			break;
		case mpe_cmd::indun_monarch_giveup_cs:
			out << "indun_monarch_giveup_cs"; 
			break;
		case mpe_cmd::indun_monarch_giveup_sc:
			out << "indun_monarch_giveup_sc"; 
			break;
		case mpe_cmd::dimension_dungeon_piece_cs:
			out << "dimension_dungeon_piece_cs"; 
			break;
		case mpe_cmd::dimension_dungeon_piece_sc:
			out << "dimension_dungeon_piece_sc"; 
			break;
		case mpe_cmd::dimension_dungeon_info_cs:
			out << "dimension_dungeon_info_cs"; 
			break;
		case mpe_cmd::dimension_dungeon_info_sc:
			out << "dimension_dungeon_info_sc"; 
			break;
		case mpe_cmd::get_character_rank_cs:
			out << "get_character_rank_cs"; 
			break;
		case mpe_cmd::get_character_rank_sc:
			out << "get_character_rank_sc"; 
			break;
		case mpe_cmd::party_member_enter_state_cs:
			out << "party_member_enter_state_cs"; 
			break;
		case mpe_cmd::party_member_enter_state_sc:
			out << "party_member_enter_state_sc"; 
			break;
		case mpe_cmd::expert_request_cs:
			out << "expert_request_cs"; 
			break;
		case mpe_cmd::expert_request_sc:
			out << "expert_request_sc"; 
			break;
		case mpe_cmd::expert_equipment_info_cs:
			out << "expert_equipment_info_cs"; 
			break;
		case mpe_cmd::expert_equipment_info_sc:
			out << "expert_equipment_info_sc"; 
			break;
		case mpe_cmd::expert_equipment_unlock_cs:
			out << "expert_equipment_unlock_cs"; 
			break;
		case mpe_cmd::expert_equipment_unlock_sc:
			out << "expert_equipment_unlock_sc"; 
			break;
		case mpe_cmd::expert_equipment_equip_cs:
			out << "expert_equipment_equip_cs"; 
			break;
		case mpe_cmd::expert_equipment_equip_sc:
			out << "expert_equipment_equip_sc"; 
			break;
		case mpe_cmd::expert_equipment_unequip_cs:
			out << "expert_equipment_unequip_cs"; 
			break;
		case mpe_cmd::expert_equipment_unequip_sc:
			out << "expert_equipment_unequip_sc"; 
			break;
		case mpe_cmd::expert_equipment_reinforce_cs:
			out << "expert_equipment_reinforce_cs"; 
			break;
		case mpe_cmd::expert_equipment_reinforce_sc:
			out << "expert_equipment_reinforce_sc"; 
			break;
		case mpe_cmd::expert_equipment_enchant_stone_equip_cs:
			out << "expert_equipment_enchant_stone_equip_cs"; 
			break;
		case mpe_cmd::expert_equipment_enchant_stone_equip_sc:
			out << "expert_equipment_enchant_stone_equip_sc"; 
			break;
		case mpe_cmd::expert_equipment_enchant_stone_unequip_cs:
			out << "expert_equipment_enchant_stone_unequip_cs"; 
			break;
		case mpe_cmd::expert_equipment_enchant_stone_unequip_sc:
			out << "expert_equipment_enchant_stone_unequip_sc"; 
			break;
		case mpe_cmd::blood_dedicate_reward_change_cs:
			out << "blood_dedicate_reward_change_cs"; 
			break;
		case mpe_cmd::blood_dedicate_reward_change_sc:
			out << "blood_dedicate_reward_change_sc"; 
			break;
		case mpe_cmd::blood_dedicate_status_cs:
			out << "blood_dedicate_status_cs"; 
			break;
		case mpe_cmd::blood_dedicate_status_sc:
			out << "blood_dedicate_status_sc"; 
			break;
		case mpe_cmd::blood_dedicate_zone_chatting_cs:
			out << "blood_dedicate_zone_chatting_cs"; 
			break;
		case mpe_cmd::blood_dedicate_zone_chatting_sc:
			out << "blood_dedicate_zone_chatting_sc"; 
			break;
		case mpe_cmd::blood_dedicate_worldboss_notify_cs:
			out << "blood_dedicate_worldboss_notify_cs"; 
			break;
		case mpe_cmd::blood_dedicate_worldboss_notify_sc:
			out << "blood_dedicate_worldboss_notify_sc"; 
			break;
		case mpe_cmd::expert_equipment_enchant_stone_upgrade_cs:
			out << "expert_equipment_enchant_stone_upgrade_cs"; 
			break;
		case mpe_cmd::expert_equipment_enchant_stone_upgrade_sc:
			out << "expert_equipment_enchant_stone_upgrade_sc"; 
			break;
		case mpe_cmd::boss_dungeon_clear_cs:
			out << "boss_dungeon_clear_cs"; 
			break;
		case mpe_cmd::boss_dungeon_clear_sc:
			out << "boss_dungeon_clear_sc"; 
			break;
		case mpe_cmd::boss_dungeon_record_cs:
			out << "boss_dungeon_record_cs"; 
			break;
		case mpe_cmd::boss_dungeon_record_sc:
			out << "boss_dungeon_record_sc"; 
			break;
		case mpe_cmd::mail_list_cs:
			out << "mail_list_cs"; 
			break;
		case mpe_cmd::mail_list_sc:
			out << "mail_list_sc"; 
			break;
		case mpe_cmd::expert_equipment_ability_ready_cs:
			out << "expert_equipment_ability_ready_cs"; 
			break;
		case mpe_cmd::expert_equipment_ability_ready_sc:
			out << "expert_equipment_ability_ready_sc"; 
			break;
		case mpe_cmd::guild_member_pvp_info_cs:
			out << "guild_member_pvp_info_cs"; 
			break;
		case mpe_cmd::guild_member_pvp_info_sc:
			out << "guild_member_pvp_info_sc"; 
			break;
		case mpe_cmd::guild_ally_request_accept_cs:
			out << "guild_ally_request_accept_cs"; 
			break;
		case mpe_cmd::guild_ally_request_accept_sc:
			out << "guild_ally_request_accept_sc"; 
			break;
		case mpe_cmd::boss_dungeon_start_time_cs:
			out << "boss_dungeon_start_time_cs"; 
			break;
		case mpe_cmd::boss_dungeon_start_time_sc:
			out << "boss_dungeon_start_time_sc"; 
			break;
		case mpe_cmd::guild_ally_request_deny_cs:
			out << "guild_ally_request_deny_cs"; 
			break;
		case mpe_cmd::guild_ally_request_deny_sc:
			out << "guild_ally_request_deny_sc"; 
			break;
		case mpe_cmd::guild_ally_request_regist_cs:
			out << "guild_ally_request_regist_cs"; 
			break;
		case mpe_cmd::guild_ally_request_regist_sc:
			out << "guild_ally_request_regist_sc"; 
			break;
		case mpe_cmd::guild_ally_list_cs:
			out << "guild_ally_list_cs"; 
			break;
		case mpe_cmd::guild_ally_list_sc:
			out << "guild_ally_list_sc"; 
			break;
		case mpe_cmd::guild_ally_request_list_cs:
			out << "guild_ally_request_list_cs"; 
			break;
		case mpe_cmd::guild_ally_request_list_sc:
			out << "guild_ally_request_list_sc"; 
			break;
		case mpe_cmd::guild_search_by_guid_cs:
			out << "guild_search_by_guid_cs"; 
			break;
		case mpe_cmd::guild_search_by_guid_sc:
			out << "guild_search_by_guid_sc"; 
			break;
		case mpe_cmd::guild_ally_cancel_cs:
			out << "guild_ally_cancel_cs"; 
			break;
		case mpe_cmd::guild_ally_cancel_sc:
			out << "guild_ally_cancel_sc"; 
			break;
		case mpe_cmd::guild_ally_alert_cs:
			out << "guild_ally_alert_cs"; 
			break;
		case mpe_cmd::guild_ally_alert_sc:
			out << "guild_ally_alert_sc"; 
			break;
		case mpe_cmd::guild_ally_detail_info_cs:
			out << "guild_ally_detail_info_cs"; 
			break;
		case mpe_cmd::guild_ally_detail_info_sc:
			out << "guild_ally_detail_info_sc"; 
			break;
		case mpe_cmd::restore_item_list_cs:
			out << "restore_item_list_cs"; 
			break;
		case mpe_cmd::restore_item_list_sc:
			out << "restore_item_list_sc"; 
			break;
		case mpe_cmd::restore_compose_list_cs:
			out << "restore_compose_list_cs"; 
			break;
		case mpe_cmd::restore_compose_list_sc:
			out << "restore_compose_list_sc"; 
			break;
		case mpe_cmd::restore_item_cs:
			out << "restore_item_cs"; 
			break;
		case mpe_cmd::restore_item_sc:
			out << "restore_item_sc"; 
			break;
		case mpe_cmd::restore_compose_cs:
			out << "restore_compose_cs"; 
			break;
		case mpe_cmd::restore_compose_sc:
			out << "restore_compose_sc"; 
			break;
		case mpe_cmd::restore_event_noti_cs:
			out << "restore_event_noti_cs"; 
			break;
		case mpe_cmd::restore_event_noti_sc:
			out << "restore_event_noti_sc"; 
			break;
		case mpe_cmd::season_mandala_info_open_cs:
			out << "season_mandala_info_open_cs"; 
			break;
		case mpe_cmd::season_mandala_info_open_sc:
			out << "season_mandala_info_open_sc"; 
			break;
		case mpe_cmd::season_mandala_reward_get_cs:
			out << "season_mandala_reward_get_cs"; 
			break;
		case mpe_cmd::season_mandala_reward_get_sc:
			out << "season_mandala_reward_get_sc"; 
			break;
		case mpe_cmd::season_mandala_reward_notify_cs:
			out << "season_mandala_reward_notify_cs"; 
			break;
		case mpe_cmd::season_mandala_reward_notify_sc:
			out << "season_mandala_reward_notify_sc"; 
			break;
		case mpe_cmd::guild_member_location_cs:
			out << "guild_member_location_cs"; 
			break;
		case mpe_cmd::guild_member_location_sc:
			out << "guild_member_location_sc"; 
			break;
		case mpe_cmd::guild_member_pk_death_alert_cs:
			out << "guild_member_pk_death_alert_cs"; 
			break;
		case mpe_cmd::guild_member_pk_death_alert_sc:
			out << "guild_member_pk_death_alert_sc"; 
			break;
		case mpe_cmd::equipment_awaken_cs:
			out << "equipment_awaken_cs"; 
			break;
		case mpe_cmd::equipment_awaken_sc:
			out << "equipment_awaken_sc"; 
			break;
		case mpe_cmd::equipment_awaken_option_confirmed_cs:
			out << "equipment_awaken_option_confirmed_cs"; 
			break;
		case mpe_cmd::equipment_awaken_option_confirmed_sc:
			out << "equipment_awaken_option_confirmed_sc"; 
			break;
		case mpe_cmd::party_leave_alert_by_indun_kick_cs:
			out << "party_leave_alert_by_indun_kick_cs"; 
			break;
		case mpe_cmd::party_leave_alert_by_indun_kick_sc:
			out << "party_leave_alert_by_indun_kick_sc"; 
			break;
		case mpe_cmd::pet_team_equip_cs:
			out << "pet_team_equip_cs"; 
			break;
		case mpe_cmd::pet_team_equip_sc:
			out << "pet_team_equip_sc"; 
			break;
		case mpe_cmd::gm_fsminfo_cs:
			out << "gm_fsminfo_cs"; 
			break;
		case mpe_cmd::gm_fsminfo_sc:
			out << "gm_fsminfo_sc"; 
			break;
		case mpe_cmd::gm_invincibility_cs:
			out << "gm_invincibility_cs"; 
			break;
		case mpe_cmd::gm_invincibility_sc:
			out << "gm_invincibility_sc"; 
			break;
		case mpe_cmd::gm_skillopen_cs:
			out << "gm_skillopen_cs"; 
			break;
		case mpe_cmd::gm_skillopen_sc:
			out << "gm_skillopen_sc"; 
			break;
		case mpe_cmd::gm_spawn_monster_cs:
			out << "gm_spawn_monster_cs"; 
			break;
		case mpe_cmd::gm_spawn_monster_sc:
			out << "gm_spawn_monster_sc"; 
			break;
		case mpe_cmd::gm_add_exp_cs:
			out << "gm_add_exp_cs"; 
			break;
		case mpe_cmd::gm_add_exp_sc:
			out << "gm_add_exp_sc"; 
			break;
		case mpe_cmd::gm_getitem_cs:
			out << "gm_getitem_cs"; 
			break;
		case mpe_cmd::gm_getitem_sc:
			out << "gm_getitem_sc"; 
			break;
		case mpe_cmd::gm_kill_monster_cs:
			out << "gm_kill_monster_cs"; 
			break;
		case mpe_cmd::gm_kill_monster_sc:
			out << "gm_kill_monster_sc"; 
			break;
		case mpe_cmd::gm_check_attribute_cs:
			out << "gm_check_attribute_cs"; 
			break;
		case mpe_cmd::gm_check_attribute_sc:
			out << "gm_check_attribute_sc"; 
			break;
		case mpe_cmd::gm_damage_monster_cs:
			out << "gm_damage_monster_cs"; 
			break;
		case mpe_cmd::gm_damage_monster_sc:
			out << "gm_damage_monster_sc"; 
			break;
		case mpe_cmd::gm_siege_object_spawn_cs:
			out << "gm_siege_object_spawn_cs"; 
			break;
		case mpe_cmd::gm_siege_object_spawn_sc:
			out << "gm_siege_object_spawn_sc"; 
			break;
		case mpe_cmd::gm_object_skill_start_cs:
			out << "gm_object_skill_start_cs"; 
			break;
		case mpe_cmd::gm_object_skill_start_sc:
			out << "gm_object_skill_start_sc"; 
			break;
		case mpe_cmd::gm_siege_warfare_change_state_cs:
			out << "gm_siege_warfare_change_state_cs"; 
			break;
		case mpe_cmd::gm_siege_warfare_change_state_sc:
			out << "gm_siege_warfare_change_state_sc"; 
			break;
		case mpe_cmd::gm_guild_storage_treasure_insert_item_cs:
			out << "gm_guild_storage_treasure_insert_item_cs"; 
			break;
		case mpe_cmd::gm_guild_storage_treasure_insert_item_sc:
			out << "gm_guild_storage_treasure_insert_item_sc"; 
			break;
		case mpe_cmd::gm_quest_clear_cs:
			out << "gm_quest_clear_cs"; 
			break;
		case mpe_cmd::gm_quest_clear_sc:
			out << "gm_quest_clear_sc"; 
			break;
		case mpe_cmd::gm_quest_clear_list_cs:
			out << "gm_quest_clear_list_cs"; 
			break;
		case mpe_cmd::gm_quest_clear_list_sc:
			out << "gm_quest_clear_list_sc"; 
			break;
		case mpe_cmd::gm_quest_accept_cs:
			out << "gm_quest_accept_cs"; 
			break;
		case mpe_cmd::gm_quest_accept_sc:
			out << "gm_quest_accept_sc"; 
			break;
		case mpe_cmd::gm_get_pet_cs:
			out << "gm_get_pet_cs"; 
			break;
		case mpe_cmd::gm_get_pet_sc:
			out << "gm_get_pet_sc"; 
			break;
		case mpe_cmd::gm_siege_indun_create_cs:
			out << "gm_siege_indun_create_cs"; 
			break;
		case mpe_cmd::gm_siege_indun_create_sc:
			out << "gm_siege_indun_create_sc"; 
			break;
		case mpe_cmd::gm_spawn_treasurebox_cs:
			out << "gm_spawn_treasurebox_cs"; 
			break;
		case mpe_cmd::gm_spawn_treasurebox_sc:
			out << "gm_spawn_treasurebox_sc"; 
			break;
		case mpe_cmd::gm_title_cs:
			out << "gm_title_cs"; 
			break;
		case mpe_cmd::gm_title_sc:
			out << "gm_title_sc"; 
			break;
		case mpe_cmd::gm_dictionary_add_cs:
			out << "gm_dictionary_add_cs"; 
			break;
		case mpe_cmd::gm_dictionary_add_sc:
			out << "gm_dictionary_add_sc"; 
			break;
		case mpe_cmd::gm_quest_initialization_cs:
			out << "gm_quest_initialization_cs"; 
			break;
		case mpe_cmd::gm_quest_initialization_sc:
			out << "gm_quest_initialization_sc"; 
			break;
		case mpe_cmd::gm_guild_add_exp_cs:
			out << "gm_guild_add_exp_cs"; 
			break;
		case mpe_cmd::gm_guild_add_exp_sc:
			out << "gm_guild_add_exp_sc"; 
			break;
		case mpe_cmd::gm_achieve_all_get_cs:
			out << "gm_achieve_all_get_cs"; 
			break;
		case mpe_cmd::gm_achieve_all_get_sc:
			out << "gm_achieve_all_get_sc"; 
			break;
		case mpe_cmd::gm_levelup_cs:
			out << "gm_levelup_cs"; 
			break;
		case mpe_cmd::gm_levelup_sc:
			out << "gm_levelup_sc"; 
			break;
		case mpe_cmd::gm_story_indun_clear_cs:
			out << "gm_story_indun_clear_cs"; 
			break;
		case mpe_cmd::gm_story_indun_clear_sc:
			out << "gm_story_indun_clear_sc"; 
			break;
		case mpe_cmd::gm_skill_expup_cs:
			out << "gm_skill_expup_cs"; 
			break;
		case mpe_cmd::gm_skill_expup_sc:
			out << "gm_skill_expup_sc"; 
			break;
		case mpe_cmd::gm_guild_shipwar_state_cs:
			out << "gm_guild_shipwar_state_cs"; 
			break;
		case mpe_cmd::gm_guild_shipwar_state_sc:
			out << "gm_guild_shipwar_state_sc"; 
			break;
		case mpe_cmd::gm_siege_state_cs:
			out << "gm_siege_state_cs"; 
			break;
		case mpe_cmd::gm_siege_state_sc:
			out << "gm_siege_state_sc"; 
			break;
		case mpe_cmd::gm_guild_shipwar_indun_create_cs:
			out << "gm_guild_shipwar_indun_create_cs"; 
			break;
		case mpe_cmd::gm_guild_shipwar_indun_create_sc:
			out << "gm_guild_shipwar_indun_create_sc"; 
			break;
		case mpe_cmd::gm_super_armor_cs:
			out << "gm_super_armor_cs"; 
			break;
		case mpe_cmd::gm_super_armor_sc:
			out << "gm_super_armor_sc"; 
			break;
		case mpe_cmd::gm_guild_shipwar_play_start_cs:
			out << "gm_guild_shipwar_play_start_cs"; 
			break;
		case mpe_cmd::gm_guild_shipwar_play_start_sc:
			out << "gm_guild_shipwar_play_start_sc"; 
			break;
		case mpe_cmd::gm_create_bot_cs:
			out << "gm_create_bot_cs"; 
			break;
		case mpe_cmd::gm_create_bot_sc:
			out << "gm_create_bot_sc"; 
			break;
		case mpe_cmd::gm_avatar_get_cs:
			out << "gm_avatar_get_cs"; 
			break;
		case mpe_cmd::gm_avatar_get_sc:
			out << "gm_avatar_get_sc"; 
			break;
		case mpe_cmd::gm_show_aggro_cs:
			out << "gm_show_aggro_cs"; 
			break;
		case mpe_cmd::gm_show_aggro_sc:
			out << "gm_show_aggro_sc"; 
			break;
		case mpe_cmd::gm_show_aggro_info_cs:
			out << "gm_show_aggro_info_cs"; 
			break;
		case mpe_cmd::gm_show_aggro_info_sc:
			out << "gm_show_aggro_info_sc"; 
			break;
		case mpe_cmd::gm_speed_attribute_cs:
			out << "gm_speed_attribute_cs"; 
			break;
		case mpe_cmd::gm_speed_attribute_sc:
			out << "gm_speed_attribute_sc"; 
			break;
		case mpe_cmd::gm_castle_info_clear_cs:
			out << "gm_castle_info_clear_cs"; 
			break;
		case mpe_cmd::gm_castle_info_clear_sc:
			out << "gm_castle_info_clear_sc"; 
			break;
		case mpe_cmd::gm_secretvalley_state_cs:
			out << "gm_secretvalley_state_cs"; 
			break;
		case mpe_cmd::gm_secretvalley_state_sc:
			out << "gm_secretvalley_state_sc"; 
			break;
		case mpe_cmd::gm_reflection_add_cs:
			out << "gm_reflection_add_cs"; 
			break;
		case mpe_cmd::gm_reflection_add_sc:
			out << "gm_reflection_add_sc"; 
			break;
		case mpe_cmd::gm_seal_device_reset_cs:
			out << "gm_seal_device_reset_cs"; 
			break;
		case mpe_cmd::gm_seal_device_reset_sc:
			out << "gm_seal_device_reset_sc"; 
			break;
		case mpe_cmd::gm_demon_tower_spawn_cs:
			out << "gm_demon_tower_spawn_cs"; 
			break;
		case mpe_cmd::gm_demon_tower_spawn_sc:
			out << "gm_demon_tower_spawn_sc"; 
			break;
		case mpe_cmd::gm_add_guild_goods_cs:
			out << "gm_add_guild_goods_cs"; 
			break;
		case mpe_cmd::gm_add_guild_goods_sc:
			out << "gm_add_guild_goods_sc"; 
			break;
		case mpe_cmd::gm_arena_battle_start_cs:
			out << "gm_arena_battle_start_cs"; 
			break;
		case mpe_cmd::gm_arena_battle_start_sc:
			out << "gm_arena_battle_start_sc"; 
			break;
		case mpe_cmd::gm_zone_all_mode_cs:
			out << "gm_zone_all_mode_cs"; 
			break;
		case mpe_cmd::gm_zone_all_mode_sc:
			out << "gm_zone_all_mode_sc"; 
			break;
		case mpe_cmd::gm_profesion_update_cs:
			out << "gm_profesion_update_cs"; 
			break;
		case mpe_cmd::gm_profesion_update_sc:
			out << "gm_profesion_update_sc"; 
			break;
		case mpe_cmd::gm_get_vehicle_cs:
			out << "gm_get_vehicle_cs"; 
			break;
		case mpe_cmd::gm_get_vehicle_sc:
			out << "gm_get_vehicle_sc"; 
			break;
		case mpe_cmd::gm_add_expert_exp_cs:
			out << "gm_add_expert_exp_cs"; 
			break;
		case mpe_cmd::gm_add_expert_exp_sc:
			out << "gm_add_expert_exp_sc"; 
			break;
		case mpe_cmd::gate_castle_dungeon_info_cs:
			out << "gate_castle_dungeon_info_cs"; 
			break;
		case mpe_cmd::gate_castle_dungeon_info_sc:
			out << "gate_castle_dungeon_info_sc"; 
			break;
		case mpe_cmd::gate_castle_view_owner_info_cs:
			out << "gate_castle_view_owner_info_cs"; 
			break;
		case mpe_cmd::gate_castle_view_owner_info_sc:
			out << "gate_castle_view_owner_info_sc"; 
			break;
		case mpe_cmd::gate_castle_tax_with_member_info_cs:
			out << "gate_castle_tax_with_member_info_cs"; 
			break;
		case mpe_cmd::gate_castle_tax_with_member_info_sc:
			out << "gate_castle_tax_with_member_info_sc"; 
			break;
		case mpe_cmd::gate_castle_town_info_by_guild_guid_cs:
			out << "gate_castle_town_info_by_guild_guid_cs"; 
			break;
		case mpe_cmd::gate_castle_town_info_by_guild_guid_sc:
			out << "gate_castle_town_info_by_guild_guid_sc"; 
			break;
		case mpe_cmd::gate_castle_town_managing_info_cs:
			out << "gate_castle_town_managing_info_cs"; 
			break;
		case mpe_cmd::gate_castle_town_managing_info_sc:
			out << "gate_castle_town_managing_info_sc"; 
			break;
		case mpe_cmd::gate_castle_town_single_managing_info_cs:
			out << "gate_castle_town_single_managing_info_cs"; 
			break;
		case mpe_cmd::gate_castle_town_single_managing_info_sc:
			out << "gate_castle_town_single_managing_info_sc"; 
			break;
		case mpe_cmd::gate_castle_town_save_bag_info_cs:
			out << "gate_castle_town_save_bag_info_cs"; 
			break;
		case mpe_cmd::gate_castle_town_save_bag_info_sc:
			out << "gate_castle_town_save_bag_info_sc"; 
			break;
		case mpe_cmd::gate_castle_town_log_cs:
			out << "gate_castle_town_log_cs"; 
			break;
		case mpe_cmd::gate_castle_town_log_sc:
			out << "gate_castle_town_log_sc"; 
			break;
		case mpe_cmd::gate_character_info_view_cs:
			out << "gate_character_info_view_cs"; 
			break;
		case mpe_cmd::gate_character_info_view_sc:
			out << "gate_character_info_view_sc"; 
			break;
		case mpe_cmd::gate_token_history_info_get_cs:
			out << "gate_token_history_info_get_cs"; 
			break;
		case mpe_cmd::gate_token_history_info_get_sc:
			out << "gate_token_history_info_get_sc"; 
			break;
		case mpe_cmd::gate_community_server_getinfo_cs:
			out << "gate_community_server_getinfo_cs"; 
			break;
		case mpe_cmd::gate_community_server_getinfo_sc:
			out << "gate_community_server_getinfo_sc"; 
			break;
		case mpe_cmd::gate_contract_get_nonce_cs:
			out << "gate_contract_get_nonce_cs"; 
			break;
		case mpe_cmd::gate_contract_get_nonce_sc:
			out << "gate_contract_get_nonce_sc"; 
			break;
		case mpe_cmd::gate_contract_get_address_cs:
			out << "gate_contract_get_address_cs"; 
			break;
		case mpe_cmd::gate_contract_get_address_sc:
			out << "gate_contract_get_address_sc"; 
			break;
		case mpe_cmd::gate_contract_get_balance_cs:
			out << "gate_contract_get_balance_cs"; 
			break;
		case mpe_cmd::gate_contract_get_balance_sc:
			out << "gate_contract_get_balance_sc"; 
			break;
		case mpe_cmd::gate_contract_token_allowance_cs:
			out << "gate_contract_token_allowance_cs"; 
			break;
		case mpe_cmd::gate_contract_token_allowance_sc:
			out << "gate_contract_token_allowance_sc"; 
			break;
		case mpe_cmd::gate_contract_get_limit_cs:
			out << "gate_contract_get_limit_cs"; 
			break;
		case mpe_cmd::gate_contract_get_limit_sc:
			out << "gate_contract_get_limit_sc"; 
			break;
		case mpe_cmd::gate_contract_get_staking_info_cs:
			out << "gate_contract_get_staking_info_cs"; 
			break;
		case mpe_cmd::gate_contract_get_staking_info_sc:
			out << "gate_contract_get_staking_info_sc"; 
			break;
		case mpe_cmd::gate_contract_get_balance_to_wdoller_cs:
			out << "gate_contract_get_balance_to_wdoller_cs"; 
			break;
		case mpe_cmd::gate_contract_get_balance_to_wdoller_sc:
			out << "gate_contract_get_balance_to_wdoller_sc"; 
			break;
		case mpe_cmd::gate_world_boss_statking_player_info_cs:
			out << "gate_world_boss_statking_player_info_cs"; 
			break;
		case mpe_cmd::gate_world_boss_statking_player_info_sc:
			out << "gate_world_boss_statking_player_info_sc"; 
			break;
		case mpe_cmd::gate_coupon_use_cs:
			out << "gate_coupon_use_cs"; 
			break;
		case mpe_cmd::gate_coupon_use_sc:
			out << "gate_coupon_use_sc"; 
			break;
		case mpe_cmd::gate_friend_list_cs:
			out << "gate_friend_list_cs"; 
			break;
		case mpe_cmd::gate_friend_list_sc:
			out << "gate_friend_list_sc"; 
			break;
		case mpe_cmd::gate_mentor_position_cs:
			out << "gate_mentor_position_cs"; 
			break;
		case mpe_cmd::gate_mentor_position_sc:
			out << "gate_mentor_position_sc"; 
			break;
		case mpe_cmd::gate_friend_request_count_cs:
			out << "gate_friend_request_count_cs"; 
			break;
		case mpe_cmd::gate_friend_request_count_sc:
			out << "gate_friend_request_count_sc"; 
			break;
		case mpe_cmd::gate_friend_requested_list_cs:
			out << "gate_friend_requested_list_cs"; 
			break;
		case mpe_cmd::gate_friend_requested_list_sc:
			out << "gate_friend_requested_list_sc"; 
			break;
		case mpe_cmd::gate_game_option_save_cs:
			out << "gate_game_option_save_cs"; 
			break;
		case mpe_cmd::gate_game_option_save_sc:
			out << "gate_game_option_save_sc"; 
			break;
		case mpe_cmd::gate_game_option_select_cs:
			out << "gate_game_option_select_cs"; 
			break;
		case mpe_cmd::gate_game_option_select_sc:
			out << "gate_game_option_select_sc"; 
			break;
		case mpe_cmd::gate_game_setup_hash_select_cs:
			out << "gate_game_setup_hash_select_cs"; 
			break;
		case mpe_cmd::gate_game_setup_hash_select_sc:
			out << "gate_game_setup_hash_select_sc"; 
			break;
		case mpe_cmd::gate_game_setup_save_cs:
			out << "gate_game_setup_save_cs"; 
			break;
		case mpe_cmd::gate_game_setup_save_sc:
			out << "gate_game_setup_save_sc"; 
			break;
		case mpe_cmd::gate_game_setup_select_cs:
			out << "gate_game_setup_select_cs"; 
			break;
		case mpe_cmd::gate_game_setup_select_sc:
			out << "gate_game_setup_select_sc"; 
			break;
		case mpe_cmd::gate_guild_dungeon_member_damage_cs:
			out << "gate_guild_dungeon_member_damage_cs"; 
			break;
		case mpe_cmd::gate_guild_dungeon_member_damage_sc:
			out << "gate_guild_dungeon_member_damage_sc"; 
			break;
		case mpe_cmd::gate_guild_dungeon_goods_cs:
			out << "gate_guild_dungeon_goods_cs"; 
			break;
		case mpe_cmd::gate_guild_dungeon_goods_sc:
			out << "gate_guild_dungeon_goods_sc"; 
			break;
		case mpe_cmd::gate_guild_skill_goods_cs:
			out << "gate_guild_skill_goods_cs"; 
			break;
		case mpe_cmd::gate_guild_skill_goods_sc:
			out << "gate_guild_skill_goods_sc"; 
			break;
		case mpe_cmd::gate_guild_share_storage_log_cs:
			out << "gate_guild_share_storage_log_cs"; 
			break;
		case mpe_cmd::gate_guild_share_storage_log_sc:
			out << "gate_guild_share_storage_log_sc"; 
			break;
		case mpe_cmd::gate_secretvalley_owner_info_cs:
			out << "gate_secretvalley_owner_info_cs"; 
			break;
		case mpe_cmd::gate_secretvalley_owner_info_sc:
			out << "gate_secretvalley_owner_info_sc"; 
			break;
		case mpe_cmd::gate_guild_league_rank_cs:
			out << "gate_guild_league_rank_cs"; 
			break;
		case mpe_cmd::gate_guild_league_rank_sc:
			out << "gate_guild_league_rank_sc"; 
			break;
		case mpe_cmd::gate_guild_storage_history_cs:
			out << "gate_guild_storage_history_cs"; 
			break;
		case mpe_cmd::gate_guild_storage_history_sc:
			out << "gate_guild_storage_history_sc"; 
			break;
		case mpe_cmd::gate_mail_check_cs:
			out << "gate_mail_check_cs"; 
			break;
		case mpe_cmd::gate_mail_check_sc:
			out << "gate_mail_check_sc"; 
			break;
		case mpe_cmd::gate_mail_list_cs:
			out << "gate_mail_list_cs"; 
			break;
		case mpe_cmd::gate_mail_list_sc:
			out << "gate_mail_list_sc"; 
			break;
		case mpe_cmd::gate_mentor_info_cs:
			out << "gate_mentor_info_cs"; 
			break;
		case mpe_cmd::gate_mentor_info_sc:
			out << "gate_mentor_info_sc"; 
			break;
		case mpe_cmd::gate_mentor_list_cs:
			out << "gate_mentor_list_cs"; 
			break;
		case mpe_cmd::gate_mentor_list_sc:
			out << "gate_mentor_list_sc"; 
			break;
		case mpe_cmd::gate_mentor_rev_req_list_cs:
			out << "gate_mentor_rev_req_list_cs"; 
			break;
		case mpe_cmd::gate_mentor_rev_req_list_sc:
			out << "gate_mentor_rev_req_list_sc"; 
			break;
		case mpe_cmd::gate_occupationwar_tender_history_cs:
			out << "gate_occupationwar_tender_history_cs"; 
			break;
		case mpe_cmd::gate_occupationwar_tender_history_sc:
			out << "gate_occupationwar_tender_history_sc"; 
			break;
		case mpe_cmd::gate_darksteel_storage_info_cs:
			out << "gate_darksteel_storage_info_cs"; 
			break;
		case mpe_cmd::gate_darksteel_storage_info_sc:
			out << "gate_darksteel_storage_info_sc"; 
			break;
		case mpe_cmd::gate_darksteel_storage_history_cs:
			out << "gate_darksteel_storage_history_cs"; 
			break;
		case mpe_cmd::gate_darksteel_storage_history_sc:
			out << "gate_darksteel_storage_history_sc"; 
			break;
		case mpe_cmd::gate_darksteel_storage_darksteel_daily_pay_cs:
			out << "gate_darksteel_storage_darksteel_daily_pay_cs"; 
			break;
		case mpe_cmd::gate_darksteel_storage_darksteel_daily_pay_sc:
			out << "gate_darksteel_storage_darksteel_daily_pay_sc"; 
			break;
		case mpe_cmd::gate_occupationwar_challenge_request_list_cs:
			out << "gate_occupationwar_challenge_request_list_cs"; 
			break;
		case mpe_cmd::gate_occupationwar_challenge_request_list_sc:
			out << "gate_occupationwar_challenge_request_list_sc"; 
			break;
		case mpe_cmd::gate_ranking_info_cs:
			out << "gate_ranking_info_cs"; 
			break;
		case mpe_cmd::gate_ranking_info_sc:
			out << "gate_ranking_info_sc"; 
			break;
		case mpe_cmd::gate_ranking_info_new_cs:
			out << "gate_ranking_info_new_cs"; 
			break;
		case mpe_cmd::gate_ranking_info_new_sc:
			out << "gate_ranking_info_new_sc"; 
			break;
		case mpe_cmd::gate_refinery_exchange_limit_check_cs:
			out << "gate_refinery_exchange_limit_check_cs"; 
			break;
		case mpe_cmd::gate_refinery_exchange_limit_check_sc:
			out << "gate_refinery_exchange_limit_check_sc"; 
			break;
		case mpe_cmd::gate_search_around_party_cs:
			out << "gate_search_around_party_cs"; 
			break;
		case mpe_cmd::gate_search_around_party_sc:
			out << "gate_search_around_party_sc"; 
			break;
		case mpe_cmd::gate_search_category_party_cs:
			out << "gate_search_category_party_cs"; 
			break;
		case mpe_cmd::gate_search_category_party_sc:
			out << "gate_search_category_party_sc"; 
			break;
		case mpe_cmd::gate_search_user_cs:
			out << "gate_search_user_cs"; 
			break;
		case mpe_cmd::gate_search_user_sc:
			out << "gate_search_user_sc"; 
			break;
		case mpe_cmd::gate_shipwar_result_list_cs:
			out << "gate_shipwar_result_list_cs"; 
			break;
		case mpe_cmd::gate_shipwar_result_list_sc:
			out << "gate_shipwar_result_list_sc"; 
			break;
		case mpe_cmd::gate_shipwar_result_cs:
			out << "gate_shipwar_result_cs"; 
			break;
		case mpe_cmd::gate_shipwar_result_sc:
			out << "gate_shipwar_result_sc"; 
			break;
		case mpe_cmd::gate_siege_warfare_alliance_list_cs:
			out << "gate_siege_warfare_alliance_list_cs"; 
			break;
		case mpe_cmd::gate_siege_warfare_alliance_list_sc:
			out << "gate_siege_warfare_alliance_list_sc"; 
			break;
		case mpe_cmd::gate_siege_warfare_alliance_receive_list_cs:
			out << "gate_siege_warfare_alliance_receive_list_cs"; 
			break;
		case mpe_cmd::gate_siege_warfare_alliance_receive_list_sc:
			out << "gate_siege_warfare_alliance_receive_list_sc"; 
			break;
		case mpe_cmd::gate_siege_warfare_atk_machine_info_cs:
			out << "gate_siege_warfare_atk_machine_info_cs"; 
			break;
		case mpe_cmd::gate_siege_warfare_atk_machine_info_sc:
			out << "gate_siege_warfare_atk_machine_info_sc"; 
			break;
		case mpe_cmd::gate_siege_warfare_guild_search_cs:
			out << "gate_siege_warfare_guild_search_cs"; 
			break;
		case mpe_cmd::gate_siege_warfare_guild_search_sc:
			out << "gate_siege_warfare_guild_search_sc"; 
			break;
		case mpe_cmd::gate_siegewarfare_observer_count_cs:
			out << "gate_siegewarfare_observer_count_cs"; 
			break;
		case mpe_cmd::gate_siegewarfare_observer_count_sc:
			out << "gate_siegewarfare_observer_count_sc"; 
			break;
		case mpe_cmd::gate_siege_warfare_tender_info_cs:
			out << "gate_siege_warfare_tender_info_cs"; 
			break;
		case mpe_cmd::gate_siege_warfare_tender_info_sc:
			out << "gate_siege_warfare_tender_info_sc"; 
			break;
		case mpe_cmd::gate_street_stall_sell_info_cs:
			out << "gate_street_stall_sell_info_cs"; 
			break;
		case mpe_cmd::gate_street_stall_sell_info_sc:
			out << "gate_street_stall_sell_info_sc"; 
			break;
		case mpe_cmd::gate_wanted_murder_list_cs:
			out << "gate_wanted_murder_list_cs"; 
			break;
		case mpe_cmd::gate_wanted_murder_list_sc:
			out << "gate_wanted_murder_list_sc"; 
			break;
		case mpe_cmd::gate_wanted_murder_register_list_cs:
			out << "gate_wanted_murder_register_list_cs"; 
			break;
		case mpe_cmd::gate_wanted_murder_register_list_sc:
			out << "gate_wanted_murder_register_list_sc"; 
			break;
		case mpe_cmd::gate_wanted_murder_reward_list_cs:
			out << "gate_wanted_murder_reward_list_cs"; 
			break;
		case mpe_cmd::gate_wanted_murder_reward_list_sc:
			out << "gate_wanted_murder_reward_list_sc"; 
			break;
		case mpe_cmd::gate_exchange_buybag_info_cs:
			out << "gate_exchange_buybag_info_cs"; 
			break;
		case mpe_cmd::gate_exchange_buybag_info_sc:
			out << "gate_exchange_buybag_info_sc"; 
			break;
		case mpe_cmd::gate_exchange_history_cs:
			out << "gate_exchange_history_cs"; 
			break;
		case mpe_cmd::gate_exchange_history_sc:
			out << "gate_exchange_history_sc"; 
			break;
		case mpe_cmd::gate_exchange_itemcount_all_cs:
			out << "gate_exchange_itemcount_all_cs"; 
			break;
		case mpe_cmd::gate_exchange_itemcount_all_sc:
			out << "gate_exchange_itemcount_all_sc"; 
			break;
		case mpe_cmd::gate_exchange_itemcount_type_cs:
			out << "gate_exchange_itemcount_type_cs"; 
			break;
		case mpe_cmd::gate_exchange_itemcount_type_sc:
			out << "gate_exchange_itemcount_type_sc"; 
			break;
		case mpe_cmd::gate_exchange_item_detail_cs:
			out << "gate_exchange_item_detail_cs"; 
			break;
		case mpe_cmd::gate_exchange_item_detail_sc:
			out << "gate_exchange_item_detail_sc"; 
			break;
		case mpe_cmd::gate_exchange_itemid_reg_count_lists_cs:
			out << "gate_exchange_itemid_reg_count_lists_cs"; 
			break;
		case mpe_cmd::gate_exchange_itemid_reg_count_lists_sc:
			out << "gate_exchange_itemid_reg_count_lists_sc"; 
			break;
		case mpe_cmd::gate_exchange_itemid_lists_cs:
			out << "gate_exchange_itemid_lists_cs"; 
			break;
		case mpe_cmd::gate_exchange_itemid_lists_sc:
			out << "gate_exchange_itemid_lists_sc"; 
			break;
		case mpe_cmd::gate_exchange_itemid_reinforce_count_cs:
			out << "gate_exchange_itemid_reinforce_count_cs"; 
			break;
		case mpe_cmd::gate_exchange_itemid_reinforce_count_sc:
			out << "gate_exchange_itemid_reinforce_count_sc"; 
			break;
		case mpe_cmd::gate_exchange_itemid_reinforce_list_cs:
			out << "gate_exchange_itemid_reinforce_list_cs"; 
			break;
		case mpe_cmd::gate_exchange_itemid_reinforce_list_sc:
			out << "gate_exchange_itemid_reinforce_list_sc"; 
			break;
		case mpe_cmd::gate_exchange_itemtype_count_cs:
			out << "gate_exchange_itemtype_count_cs"; 
			break;
		case mpe_cmd::gate_exchange_itemtype_count_sc:
			out << "gate_exchange_itemtype_count_sc"; 
			break;
		case mpe_cmd::gate_exchange_marketprice_cs:
			out << "gate_exchange_marketprice_cs"; 
			break;
		case mpe_cmd::gate_exchange_marketprice_sc:
			out << "gate_exchange_marketprice_sc"; 
			break;
		case mpe_cmd::gate_exchange_registrant_info_cs:
			out << "gate_exchange_registrant_info_cs"; 
			break;
		case mpe_cmd::gate_exchange_registrant_info_sc:
			out << "gate_exchange_registrant_info_sc"; 
			break;
		case mpe_cmd::gate_field_boss_regist_info_cs:
			out << "gate_field_boss_regist_info_cs"; 
			break;
		case mpe_cmd::gate_field_boss_regist_info_sc:
			out << "gate_field_boss_regist_info_sc"; 
			break;
		case mpe_cmd::gate_event_info_cs:
			out << "gate_event_info_cs"; 
			break;
		case mpe_cmd::gate_event_info_sc:
			out << "gate_event_info_sc"; 
			break;
		case mpe_cmd::gate_event_reward_cs:
			out << "gate_event_reward_cs"; 
			break;
		case mpe_cmd::gate_event_reward_sc:
			out << "gate_event_reward_sc"; 
			break;
		case mpe_cmd::gate_global_exchange_buybag_info_cs:
			out << "gate_global_exchange_buybag_info_cs"; 
			break;
		case mpe_cmd::gate_global_exchange_buybag_info_sc:
			out << "gate_global_exchange_buybag_info_sc"; 
			break;
		case mpe_cmd::gate_global_exchange_history_cs:
			out << "gate_global_exchange_history_cs"; 
			break;
		case mpe_cmd::gate_global_exchange_history_sc:
			out << "gate_global_exchange_history_sc"; 
			break;
		case mpe_cmd::gate_global_exchange_itemcount_all_cs:
			out << "gate_global_exchange_itemcount_all_cs"; 
			break;
		case mpe_cmd::gate_global_exchange_itemcount_all_sc:
			out << "gate_global_exchange_itemcount_all_sc"; 
			break;
		case mpe_cmd::gate_global_exchange_itemcount_type_cs:
			out << "gate_global_exchange_itemcount_type_cs"; 
			break;
		case mpe_cmd::gate_global_exchange_itemcount_type_sc:
			out << "gate_global_exchange_itemcount_type_sc"; 
			break;
		case mpe_cmd::gate_global_exchange_item_detail_cs:
			out << "gate_global_exchange_item_detail_cs"; 
			break;
		case mpe_cmd::gate_global_exchange_item_detail_sc:
			out << "gate_global_exchange_item_detail_sc"; 
			break;
		case mpe_cmd::gate_global_exchange_itemid_reg_count_lists_cs:
			out << "gate_global_exchange_itemid_reg_count_lists_cs"; 
			break;
		case mpe_cmd::gate_global_exchange_itemid_reg_count_lists_sc:
			out << "gate_global_exchange_itemid_reg_count_lists_sc"; 
			break;
		case mpe_cmd::gate_global_exchange_itemid_lists_cs:
			out << "gate_global_exchange_itemid_lists_cs"; 
			break;
		case mpe_cmd::gate_global_exchange_itemid_lists_sc:
			out << "gate_global_exchange_itemid_lists_sc"; 
			break;
		case mpe_cmd::gate_global_exchange_itemid_reinforce_count_cs:
			out << "gate_global_exchange_itemid_reinforce_count_cs"; 
			break;
		case mpe_cmd::gate_global_exchange_itemid_reinforce_count_sc:
			out << "gate_global_exchange_itemid_reinforce_count_sc"; 
			break;
		case mpe_cmd::gate_global_exchange_itemid_reinforce_list_cs:
			out << "gate_global_exchange_itemid_reinforce_list_cs"; 
			break;
		case mpe_cmd::gate_global_exchange_itemid_reinforce_list_sc:
			out << "gate_global_exchange_itemid_reinforce_list_sc"; 
			break;
		case mpe_cmd::gate_global_exchange_itemtype_count_cs:
			out << "gate_global_exchange_itemtype_count_cs"; 
			break;
		case mpe_cmd::gate_global_exchange_itemtype_count_sc:
			out << "gate_global_exchange_itemtype_count_sc"; 
			break;
		case mpe_cmd::gate_global_exchange_marketprice_cs:
			out << "gate_global_exchange_marketprice_cs"; 
			break;
		case mpe_cmd::gate_global_exchange_marketprice_sc:
			out << "gate_global_exchange_marketprice_sc"; 
			break;
		case mpe_cmd::gate_global_exchange_registrant_info_cs:
			out << "gate_global_exchange_registrant_info_cs"; 
			break;
		case mpe_cmd::gate_global_exchange_registrant_info_sc:
			out << "gate_global_exchange_registrant_info_sc"; 
			break;
		case mpe_cmd::gate_cash_shop_info_cs:
			out << "gate_cash_shop_info_cs"; 
			break;
		case mpe_cmd::gate_cash_shop_info_sc:
			out << "gate_cash_shop_info_sc"; 
			break;
		case mpe_cmd::gate_contents_onoff_list_cs:
			out << "gate_contents_onoff_list_cs"; 
			break;
		case mpe_cmd::gate_contents_onoff_list_sc:
			out << "gate_contents_onoff_list_sc"; 
			break;
		case mpe_cmd::gate_pay_start_cs:
			out << "gate_pay_start_cs"; 
			break;
		case mpe_cmd::gate_pay_start_sc:
			out << "gate_pay_start_sc"; 
			break;
		case mpe_cmd::gate_pay_verify_cs:
			out << "gate_pay_verify_cs"; 
			break;
		case mpe_cmd::gate_pay_verify_sc:
			out << "gate_pay_verify_sc"; 
			break;
		case mpe_cmd::gate_pre_verify_cs:
			out << "gate_pre_verify_cs"; 
			break;
		case mpe_cmd::gate_pre_verify_sc:
			out << "gate_pre_verify_sc"; 
			break;
		case mpe_cmd::gate_promo_verify_cs:
			out << "gate_promo_verify_cs"; 
			break;
		case mpe_cmd::gate_promo_verify_sc:
			out << "gate_promo_verify_sc"; 
			break;
		case mpe_cmd::gate_cash_shop_item_list_cs:
			out << "gate_cash_shop_item_list_cs"; 
			break;
		case mpe_cmd::gate_cash_shop_item_list_sc:
			out << "gate_cash_shop_item_list_sc"; 
			break;
		case mpe_cmd::gate_lobby_character_create_cs:
			out << "gate_lobby_character_create_cs"; 
			break;
		case mpe_cmd::gate_lobby_character_create_sc:
			out << "gate_lobby_character_create_sc"; 
			break;
		case mpe_cmd::gate_lobby_character_delete_cs:
			out << "gate_lobby_character_delete_cs"; 
			break;
		case mpe_cmd::gate_lobby_character_delete_sc:
			out << "gate_lobby_character_delete_sc"; 
			break;
		case mpe_cmd::gate_lobby_character_delete_cancel_cs:
			out << "gate_lobby_character_delete_cancel_cs"; 
			break;
		case mpe_cmd::gate_lobby_character_delete_cancel_sc:
			out << "gate_lobby_character_delete_cancel_sc"; 
			break;
		case mpe_cmd::gate_lobby_character_select_cs:
			out << "gate_lobby_character_select_cs"; 
			break;
		case mpe_cmd::gate_lobby_character_select_sc:
			out << "gate_lobby_character_select_sc"; 
			break;
		case mpe_cmd::gate_lobby_gameplaylogin_cs:
			out << "gate_lobby_gameplaylogin_cs"; 
			break;
		case mpe_cmd::gate_lobby_gameplaylogin_sc:
			out << "gate_lobby_gameplaylogin_sc"; 
			break;
		case mpe_cmd::gate_lobby_gamelogin_await_cancel_cs:
			out << "gate_lobby_gamelogin_await_cancel_cs"; 
			break;
		case mpe_cmd::gate_lobby_gamelogin_await_cancel_sc:
			out << "gate_lobby_gamelogin_await_cancel_sc"; 
			break;
		case mpe_cmd::gate_get_available_font_list_cs:
			out << "gate_get_available_font_list_cs"; 
			break;
		case mpe_cmd::gate_get_available_font_list_sc:
			out << "gate_get_available_font_list_sc"; 
			break;
		case mpe_cmd::gate_channel_status_cs:
			out << "gate_channel_status_cs"; 
			break;
		case mpe_cmd::gate_channel_status_sc:
			out << "gate_channel_status_sc"; 
			break;
		case mpe_cmd::gate_channel_full_check_cs:
			out << "gate_channel_full_check_cs"; 
			break;
		case mpe_cmd::gate_channel_full_check_sc:
			out << "gate_channel_full_check_sc"; 
			break;
		case mpe_cmd::gate_arena_battle_ranking_cs:
			out << "gate_arena_battle_ranking_cs"; 
			break;
		case mpe_cmd::gate_arena_battle_ranking_sc:
			out << "gate_arena_battle_ranking_sc"; 
			break;
		case mpe_cmd::gate_arena_battle_info_cs:
			out << "gate_arena_battle_info_cs"; 
			break;
		case mpe_cmd::gate_arena_battle_info_sc:
			out << "gate_arena_battle_info_sc"; 
			break;
		case mpe_cmd::gate_arena_battle_result_list_cs:
			out << "gate_arena_battle_result_list_cs"; 
			break;
		case mpe_cmd::gate_arena_battle_result_list_sc:
			out << "gate_arena_battle_result_list_sc"; 
			break;
		case mpe_cmd::gate_arena_battle_result_cs:
			out << "gate_arena_battle_result_cs"; 
			break;
		case mpe_cmd::gate_arena_battle_result_sc:
			out << "gate_arena_battle_result_sc"; 
			break;
		case mpe_cmd::gate_guildshipwar_season_reward_cs:
			out << "gate_guildshipwar_season_reward_cs"; 
			break;
		case mpe_cmd::gate_guildshipwar_season_reward_sc:
			out << "gate_guildshipwar_season_reward_sc"; 
			break;
		case mpe_cmd::gate_world_boss_statking_board_info_cs:
			out << "gate_world_boss_statking_board_info_cs"; 
			break;
		case mpe_cmd::gate_world_boss_statking_board_info_sc:
			out << "gate_world_boss_statking_board_info_sc"; 
			break;
		case mpe_cmd::gate_occupationwar_statking_board_info_cs:
			out << "gate_occupationwar_statking_board_info_cs"; 
			break;
		case mpe_cmd::gate_occupationwar_statking_board_info_sc:
			out << "gate_occupationwar_statking_board_info_sc"; 
			break;
		case mpe_cmd::gate_occupationwar_schedule_info_cs:
			out << "gate_occupationwar_schedule_info_cs"; 
			break;
		case mpe_cmd::gate_occupationwar_schedule_info_sc:
			out << "gate_occupationwar_schedule_info_sc"; 
			break;
		case mpe_cmd::gate_world_boss_linked_wallet_info_cs:
			out << "gate_world_boss_linked_wallet_info_cs"; 
			break;
		case mpe_cmd::gate_world_boss_linked_wallet_info_sc:
			out << "gate_world_boss_linked_wallet_info_sc"; 
			break;
		case mpe_cmd::gate_worldboard_guild_league_rank_cs:
			out << "gate_worldboard_guild_league_rank_cs"; 
			break;
		case mpe_cmd::gate_worldboard_guild_league_rank_sc:
			out << "gate_worldboard_guild_league_rank_sc"; 
			break;
		case mpe_cmd::gate_worldboard_shipwar_result_list_cs:
			out << "gate_worldboard_shipwar_result_list_cs"; 
			break;
		case mpe_cmd::gate_worldboard_shipwar_result_list_sc:
			out << "gate_worldboard_shipwar_result_list_sc"; 
			break;
		case mpe_cmd::gate_worldboard_shipwar_result_cs:
			out << "gate_worldboard_shipwar_result_cs"; 
			break;
		case mpe_cmd::gate_worldboard_shipwar_result_sc:
			out << "gate_worldboard_shipwar_result_sc"; 
			break;
		case mpe_cmd::gate_contract_add_exchagne_cs:
			out << "gate_contract_add_exchagne_cs"; 
			break;
		case mpe_cmd::gate_contract_add_exchagne_sc:
			out << "gate_contract_add_exchagne_sc"; 
			break;
		case mpe_cmd::gate_wemix_pay_start_cs:
			out << "gate_wemix_pay_start_cs"; 
			break;
		case mpe_cmd::gate_wemix_pay_start_sc:
			out << "gate_wemix_pay_start_sc"; 
			break;
		case mpe_cmd::gate_wemix_pay_end_cs:
			out << "gate_wemix_pay_end_cs"; 
			break;
		case mpe_cmd::gate_wemix_pay_end_sc:
			out << "gate_wemix_pay_end_sc"; 
			break;
		case mpe_cmd::gate_get_wemix_amount_cs:
			out << "gate_get_wemix_amount_cs"; 
			break;
		case mpe_cmd::gate_get_wemix_amount_sc:
			out << "gate_get_wemix_amount_sc"; 
			break;
		case mpe_cmd::gate_get_wemix_history_cs:
			out << "gate_get_wemix_history_cs"; 
			break;
		case mpe_cmd::gate_get_wemix_history_sc:
			out << "gate_get_wemix_history_sc"; 
			break;
		case mpe_cmd::gate_advertisement_exp_restore_cs:
			out << "gate_advertisement_exp_restore_cs"; 
			break;
		case mpe_cmd::gate_advertisement_exp_restore_sc:
			out << "gate_advertisement_exp_restore_sc"; 
			break;
		case mpe_cmd::gate_advertisement_reward_cs:
			out << "gate_advertisement_reward_cs"; 
			break;
		case mpe_cmd::gate_advertisement_reward_sc:
			out << "gate_advertisement_reward_sc"; 
			break;
		case mpe_cmd::gate_advertisement_event_reward_cs:
			out << "gate_advertisement_event_reward_cs"; 
			break;
		case mpe_cmd::gate_advertisement_event_reward_sc:
			out << "gate_advertisement_event_reward_sc"; 
			break;
		case mpe_cmd::gate_get_all_balance_swap_token_cs:
			out << "gate_get_all_balance_swap_token_cs"; 
			break;
		case mpe_cmd::gate_get_all_balance_swap_token_sc:
			out << "gate_get_all_balance_swap_token_sc"; 
			break;
		case mpe_cmd::gate_advertisement_info_cs:
			out << "gate_advertisement_info_cs"; 
			break;
		case mpe_cmd::gate_advertisement_info_sc:
			out << "gate_advertisement_info_sc"; 
			break;
		case mpe_cmd::gate_community_login_cs:
			out << "gate_community_login_cs"; 
			break;
		case mpe_cmd::gate_community_login_sc:
			out << "gate_community_login_sc"; 
			break;
		case mpe_cmd::gate_chatting_cs:
			out << "gate_chatting_cs"; 
			break;
		case mpe_cmd::gate_chatting_sc:
			out << "gate_chatting_sc"; 
			break;
		case mpe_cmd::gate_chatting_block_cs:
			out << "gate_chatting_block_cs"; 
			break;
		case mpe_cmd::gate_chatting_block_sc:
			out << "gate_chatting_block_sc"; 
			break;
		case mpe_cmd::gate_chatting_block_list_cs:
			out << "gate_chatting_block_list_cs"; 
			break;
		case mpe_cmd::gate_chatting_block_list_sc:
			out << "gate_chatting_block_list_sc"; 
			break;
		case mpe_cmd::gate_private_chatting_state_cs:
			out << "gate_private_chatting_state_cs"; 
			break;
		case mpe_cmd::gate_private_chatting_state_sc:
			out << "gate_private_chatting_state_sc"; 
			break;
		case mpe_cmd::gate_server_relocation_list_cs:
			out << "gate_server_relocation_list_cs"; 
			break;
		case mpe_cmd::gate_server_relocation_list_sc:
			out << "gate_server_relocation_list_sc"; 
			break;
		case mpe_cmd::gate_dogma_pay_start_cs:
			out << "gate_dogma_pay_start_cs"; 
			break;
		case mpe_cmd::gate_dogma_pay_start_sc:
			out << "gate_dogma_pay_start_sc"; 
			break;
		case mpe_cmd::gate_dogma_pay_end_cs:
			out << "gate_dogma_pay_end_cs"; 
			break;
		case mpe_cmd::gate_dogma_pay_end_sc:
			out << "gate_dogma_pay_end_sc"; 
			break;
		case mpe_cmd::gate_dogma_get_oracle_cs:
			out << "gate_dogma_get_oracle_cs"; 
			break;
		case mpe_cmd::gate_dogma_get_oracle_sc:
			out << "gate_dogma_get_oracle_sc"; 
			break;
		case mpe_cmd::gate_dimension_dungeon_schedule_cs:
			out << "gate_dimension_dungeon_schedule_cs"; 
			break;
		case mpe_cmd::gate_dimension_dungeon_schedule_sc:
			out << "gate_dimension_dungeon_schedule_sc"; 
			break;
		case mpe_cmd::gate_lobby_player_character_select_cs:
			out << "gate_lobby_player_character_select_cs"; 
			break;
		case mpe_cmd::gate_lobby_player_character_select_sc:
			out << "gate_lobby_player_character_select_sc"; 
			break;
		case mpe_cmd::gate_lobby_player_character_delete_cs:
			out << "gate_lobby_player_character_delete_cs"; 
			break;
		case mpe_cmd::gate_lobby_player_character_delete_sc:
			out << "gate_lobby_player_character_delete_sc"; 
			break;
		case mpe_cmd::gate_world_exchange_buybag_info_cs:
			out << "gate_world_exchange_buybag_info_cs"; 
			break;
		case mpe_cmd::gate_world_exchange_buybag_info_sc:
			out << "gate_world_exchange_buybag_info_sc"; 
			break;
		case mpe_cmd::gate_world_exchange_history_cs:
			out << "gate_world_exchange_history_cs"; 
			break;
		case mpe_cmd::gate_world_exchange_history_sc:
			out << "gate_world_exchange_history_sc"; 
			break;
		case mpe_cmd::gate_world_exchange_itemcount_all_cs:
			out << "gate_world_exchange_itemcount_all_cs"; 
			break;
		case mpe_cmd::gate_world_exchange_itemcount_all_sc:
			out << "gate_world_exchange_itemcount_all_sc"; 
			break;
		case mpe_cmd::gate_world_exchange_itemcount_type_cs:
			out << "gate_world_exchange_itemcount_type_cs"; 
			break;
		case mpe_cmd::gate_world_exchange_itemcount_type_sc:
			out << "gate_world_exchange_itemcount_type_sc"; 
			break;
		case mpe_cmd::gate_world_exchange_itemid_reg_count_lists_cs:
			out << "gate_world_exchange_itemid_reg_count_lists_cs"; 
			break;
		case mpe_cmd::gate_world_exchange_itemid_reg_count_lists_sc:
			out << "gate_world_exchange_itemid_reg_count_lists_sc"; 
			break;
		case mpe_cmd::gate_world_exchange_itemid_lists_cs:
			out << "gate_world_exchange_itemid_lists_cs"; 
			break;
		case mpe_cmd::gate_world_exchange_itemid_lists_sc:
			out << "gate_world_exchange_itemid_lists_sc"; 
			break;
		case mpe_cmd::gate_world_exchange_itemid_reinforce_count_cs:
			out << "gate_world_exchange_itemid_reinforce_count_cs"; 
			break;
		case mpe_cmd::gate_world_exchange_itemid_reinforce_count_sc:
			out << "gate_world_exchange_itemid_reinforce_count_sc"; 
			break;
		case mpe_cmd::gate_world_exchange_itemid_reinforce_list_cs:
			out << "gate_world_exchange_itemid_reinforce_list_cs"; 
			break;
		case mpe_cmd::gate_world_exchange_itemid_reinforce_list_sc:
			out << "gate_world_exchange_itemid_reinforce_list_sc"; 
			break;
		case mpe_cmd::gate_world_exchange_itemtype_count_cs:
			out << "gate_world_exchange_itemtype_count_cs"; 
			break;
		case mpe_cmd::gate_world_exchange_itemtype_count_sc:
			out << "gate_world_exchange_itemtype_count_sc"; 
			break;
		case mpe_cmd::gate_world_exchange_marketprice_cs:
			out << "gate_world_exchange_marketprice_cs"; 
			break;
		case mpe_cmd::gate_world_exchange_marketprice_sc:
			out << "gate_world_exchange_marketprice_sc"; 
			break;
		case mpe_cmd::gate_world_exchange_registrant_info_cs:
			out << "gate_world_exchange_registrant_info_cs"; 
			break;
		case mpe_cmd::gate_world_exchange_registrant_info_sc:
			out << "gate_world_exchange_registrant_info_sc"; 
			break;
		case mpe_cmd::gate_world_exchange_item_detail_cs:
			out << "gate_world_exchange_item_detail_cs"; 
			break;
		case mpe_cmd::gate_world_exchange_item_detail_sc:
			out << "gate_world_exchange_item_detail_sc"; 
			break;
		case mpe_cmd::gate_blood_dedicate_worldboss_status_cs:
			out << "gate_blood_dedicate_worldboss_status_cs"; 
			break;
		case mpe_cmd::gate_blood_dedicate_worldboss_status_sc:
			out << "gate_blood_dedicate_worldboss_status_sc"; 
			break;
		case mpe_cmd::gate_dungeon_ranking_info_cs:
			out << "gate_dungeon_ranking_info_cs"; 
			break;
		case mpe_cmd::gate_dungeon_ranking_info_sc:
			out << "gate_dungeon_ranking_info_sc"; 
			break;
		case mpe_cmd::cmd_max:
			out << "cmd_max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_good_pos& value)
	{
		switch (value)
		{
		case mpe_good_pos::level:
			out << "level"; 
			break;
		case mpe_good_pos::exp:
			out << "exp"; 
			break;
		case mpe_good_pos::gold:
			out << "gold"; 
			break;
		case mpe_good_pos::cash:
			out << "cash"; 
			break;
		case mpe_good_pos::chao_point:
			out << "chao_point"; 
			break;
		case mpe_good_pos::goldingot:
			out << "goldingot"; 
			break;
		case mpe_good_pos::concentration:
			out << "concentration"; 
			break;
		case mpe_good_pos::condition:
			out << "condition"; 
			break;
		case mpe_good_pos::black_iron:
			out << "black_iron"; 
			break;
		case mpe_good_pos::treasurebox_key:
			out << "treasurebox_key"; 
			break;
		case mpe_good_pos::guild_point:
			out << "guild_point"; 
			break;
		case mpe_good_pos::guid_gold:
			out << "guid_gold"; 
			break;
		case mpe_good_pos::boss_point:
			out << "boss_point"; 
			break;
		case mpe_good_pos::force_exp:
			out << "force_exp"; 
			break;
		case mpe_good_pos::pk_point:
			out << "pk_point"; 
			break;
		case mpe_good_pos::mentor_point:
			out << "mentor_point"; 
			break;
		case mpe_good_pos::seal_tower_coin:
			out << "seal_tower_coin"; 
			break;
		case mpe_good_pos::demon_tower_coin:
			out << "demon_tower_coin"; 
			break;
		case mpe_good_pos::mileage:
			out << "mileage"; 
			break;
		case mpe_good_pos::ancientrelic_key:
			out << "ancientrelic_key"; 
			break;
		case mpe_good_pos::ad_coin:
			out << "ad_coin"; 
			break;
		case mpe_good_pos::dungeon_seal:
			out << "dungeon_seal"; 
			break;
		case mpe_good_pos::blood_stone:
			out << "blood_stone"; 
			break;
		case mpe_good_pos::nelumbo_stone:
			out << "nelumbo_stone"; 
			break;
		case mpe_good_pos::dimension_piece:
			out << "dimension_piece"; 
			break;
		case mpe_good_pos::nelumbo_stone_point:
			out << "nelumbo_stone_point"; 
			break;
		case mpe_good_pos::expert_level:
			out << "expert_level"; 
			break;
		case mpe_good_pos::expert_exp:
			out << "expert_exp"; 
			break;
		case mpe_good_pos::monarch_point:
			out << "monarch_point"; 
			break;
		case mpe_good_pos::goods_29:
			out << "goods_29"; 
			break;
		case mpe_good_pos::goods_30:
			out << "goods_30"; 
			break;
		case mpe_good_pos::goods_31:
			out << "goods_31"; 
			break;
		case mpe_good_pos::goods_32:
			out << "goods_32"; 
			break;
		case mpe_good_pos::goods_33:
			out << "goods_33"; 
			break;
		case mpe_good_pos::goods_34:
			out << "goods_34"; 
			break;
		case mpe_good_pos::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_equip_pos& value)
	{
		switch (value)
		{
		case mpe_equip_pos::weapon:
			out << "weapon"; 
			break;
		case mpe_equip_pos::sub_weapon:
			out << "sub_weapon"; 
			break;
		case mpe_equip_pos::helmet:
			out << "helmet"; 
			break;
		case mpe_equip_pos::armor:
			out << "armor"; 
			break;
		case mpe_equip_pos::necklace:
			out << "necklace"; 
			break;
		case mpe_equip_pos::bracelet_r:
			out << "bracelet_r"; 
			break;
		case mpe_equip_pos::bracelet_l:
			out << "bracelet_l"; 
			break;
		case mpe_equip_pos::ring_r:
			out << "ring_r"; 
			break;
		case mpe_equip_pos::ring_l:
			out << "ring_l"; 
			break;
		case mpe_equip_pos::belt:
			out << "belt"; 
			break;
		case mpe_equip_pos::shoes:
			out << "shoes"; 
			break;
		case mpe_equip_pos::wing:
			out << "wing"; 
			break;
		case mpe_equip_pos::pickaxe:
			out << "pickaxe"; 
			break;
		case mpe_equip_pos::axe:
			out << "axe"; 
			break;
		case mpe_equip_pos::rod:
			out << "rod"; 
			break;
		case mpe_equip_pos::equip_stone:
			out << "equip_stone"; 
			break;
		case mpe_equip_pos::equip_vehicle:
			out << "equip_vehicle"; 
			break;
		case mpe_equip_pos::costume_weapon:
			out << "costume_weapon"; 
			break;
		case mpe_equip_pos::costume_armor:
			out << "costume_armor"; 
			break;
		case mpe_equip_pos::costume_helmet:
			out << "costume_helmet"; 
			break;
		case mpe_equip_pos::costume_weapon_female:
			out << "costume_weapon_female"; 
			break;
		case mpe_equip_pos::costume_armor_female:
			out << "costume_armor_female"; 
			break;
		case mpe_equip_pos::costume_helmet_female:
			out << "costume_helmet_female"; 
			break;
		case mpe_equip_pos::mandala:
			out << "mandala"; 
			break;
		case mpe_equip_pos::brooch:
			out << "brooch"; 
			break;
		case mpe_equip_pos::dragonplate:
			out << "dragonplate"; 
			break;
		case mpe_equip_pos::earring:
			out << "earring"; 
			break;
		case mpe_equip_pos::expert_equipment:
			out << "expert_equipment"; 
			break;
		case mpe_equip_pos::season_mandala:
			out << "season_mandala"; 
			break;
		case mpe_equip_pos::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_equip_flag& value)
	{
		switch (value)
		{
		case mpe_equip_flag::equip:
			out << "equip"; 
			break;
		case mpe_equip_flag::release:
			out << "release"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_daily_content_pos& value)
	{
		switch (value)
		{
		case mpe_daily_content_pos::daily_chao_point:
			out << "daily_chao_point"; 
			break;
		case mpe_daily_content_pos::daily_free_revive_count:
			out << "daily_free_revive_count"; 
			break;
		case mpe_daily_content_pos::daily_max:
			out << "daily_max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_quest_state& value)
	{
		switch (value)
		{
		case mpe_quest_state::qs_none:
			out << "qs_none"; 
			break;
		case mpe_quest_state::qs_accept:
			out << "qs_accept"; 
			break;
		case mpe_quest_state::qs_complete:
			out << "qs_complete"; 
			break;
		case mpe_quest_state::qs_finish:
			out << "qs_finish"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_character_action& value)
	{
		switch (value)
		{
		case mpe_character_action::action_none:
			out << "action_none"; 
			break;
		case mpe_character_action::action_collect:
			out << "action_collect"; 
			break;
		case mpe_character_action::action_skill_action:
			out << "action_skill_action"; 
			break;
		case mpe_character_action::action_fish:
			out << "action_fish"; 
			break;
		case mpe_character_action::action_dead:
			out << "action_dead"; 
			break;
		case mpe_character_action::action_treasure_box_open:
			out << "action_treasure_box_open"; 
			break;
		case mpe_character_action::action_treasure_box_finish:
			out << "action_treasure_box_finish"; 
			break;
		case mpe_character_action::action_teleport_start:
			out << "action_teleport_start"; 
			break;
		case mpe_character_action::action_teleport_arrive:
			out << "action_teleport_arrive"; 
			break;
		case mpe_character_action::action_transform_avatar:
			out << "action_transform_avatar"; 
			break;
		case mpe_character_action::action_seal_device_start:
			out << "action_seal_device_start"; 
			break;
		case mpe_character_action::action_seal_device_finish:
			out << "action_seal_device_finish"; 
			break;
		case mpe_character_action::action_telport_reservation:
			out << "action_telport_reservation"; 
			break;
		case mpe_character_action::action_observer:
			out << "action_observer"; 
			break;
		case mpe_character_action::action_street_stall:
			out << "action_street_stall"; 
			break;
		case mpe_character_action::action_street_stall_wait:
			out << "action_street_stall_wait"; 
			break;
		case mpe_character_action::action_exchange_use:
			out << "action_exchange_use"; 
			break;
		case mpe_character_action::action_post_update_goods:
			out << "action_post_update_goods"; 
			break;
		case mpe_character_action::action_server_relocation:
			out << "action_server_relocation"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_move_type& value)
	{
		switch (value)
		{
		case mpe_move_type::mt_stop:
			out << "mt_stop"; 
			break;
		case mpe_move_type::mt_walk:
			out << "mt_walk"; 
			break;
		case mpe_move_type::mt_run:
			out << "mt_run"; 
			break;
		case mpe_move_type::mt_return:
			out << "mt_return"; 
			break;
		case mpe_move_type::mt_teleport:
			out << "mt_teleport"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_direction& value)
	{
		switch (value)
		{
		case mpe_direction::nn:
			out << "nn"; 
			break;
		case mpe_direction::ne:
			out << "ne"; 
			break;
		case mpe_direction::ee:
			out << "ee"; 
			break;
		case mpe_direction::es:
			out << "es"; 
			break;
		case mpe_direction::ss:
			out << "ss"; 
			break;
		case mpe_direction::sw:
			out << "sw"; 
			break;
		case mpe_direction::ww:
			out << "ww"; 
			break;
		case mpe_direction::wn:
			out << "wn"; 
			break;
		case mpe_direction::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_damage_type& value)
	{
		switch (value)
		{
		case mpe_damage_type::damage_none:
			out << "damage_none"; 
			break;
		case mpe_damage_type::damage_hit:
			out << "damage_hit"; 
			break;
		case mpe_damage_type::damage_miss:
			out << "damage_miss"; 
			break;
		case mpe_damage_type::damage_critical:
			out << "damage_critical"; 
			break;
		case mpe_damage_type::damage_hp:
			out << "damage_hp"; 
			break;
		case mpe_damage_type::damage_mp:
			out << "damage_mp"; 
			break;
		case mpe_damage_type::damage_auto_heal_hp:
			out << "damage_auto_heal_hp"; 
			break;
		case mpe_damage_type::damage_auto_heal_mp:
			out << "damage_auto_heal_mp"; 
			break;
		case mpe_damage_type::damage_perfect:
			out << "damage_perfect"; 
			break;
		case mpe_damage_type::damage_great:
			out << "damage_great"; 
			break;
		case mpe_damage_type::damage_good:
			out << "damage_good"; 
			break;
		case mpe_damage_type::damage_vampiric_hp:
			out << "damage_vampiric_hp"; 
			break;
		case mpe_damage_type::damage_vampiric_mp:
			out << "damage_vampiric_mp"; 
			break;
		case mpe_damage_type::damage_reflection:
			out << "damage_reflection"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_party_loot& value)
	{
		switch (value)
		{
		case mpe_party_loot::turn:
			out << "turn"; 
			break;
		case mpe_party_loot::every:
			out << "every"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_party_join& value)
	{
		switch (value)
		{
		case mpe_party_join::automatic:
			out << "automatic"; 
			break;
		case mpe_party_join::manual:
			out << "manual"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_party_teleport& value)
	{
		switch (value)
		{
		case mpe_party_teleport::owner_teleport:
			out << "owner_teleport"; 
			break;
		case mpe_party_teleport::member_summon:
			out << "member_summon"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_party_vote& value)
	{
		switch (value)
		{
		case mpe_party_vote::none:
			out << "none"; 
			break;
		case mpe_party_vote::owner_ban:
			out << "owner_ban"; 
			break;
		case mpe_party_vote::member_ban:
			out << "member_ban"; 
			break;
		case mpe_party_vote::loot_change:
			out << "loot_change"; 
			break;
		case mpe_party_vote::indun_select:
			out << "indun_select"; 
			break;
		case mpe_party_vote::indun_auto_matching:
			out << "indun_auto_matching"; 
			break;
		case mpe_party_vote::indun_enter_check_for_direct:
			out << "indun_enter_check_for_direct"; 
			break;
		case mpe_party_vote::indun_enter_check_for_auto_matching:
			out << "indun_enter_check_for_auto_matching"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_slot_pos& value)
	{
		switch (value)
		{
		case mpe_slot_pos::slot_hp_one:
			out << "slot_hp_one"; 
			break;
		case mpe_slot_pos::slot_hp_two:
			out << "slot_hp_two"; 
			break;
		case mpe_slot_pos::slot_hp_three:
			out << "slot_hp_three"; 
			break;
		case mpe_slot_pos::slot_mp_one:
			out << "slot_mp_one"; 
			break;
		case mpe_slot_pos::slot_mp_two:
			out << "slot_mp_two"; 
			break;
		case mpe_slot_pos::slot_mp_three:
			out << "slot_mp_three"; 
			break;
		case mpe_slot_pos::slot_max:
			out << "slot_max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_use_type& value)
	{
		switch (value)
		{
		case mpe_use_type::use_none:
			out << "use_none"; 
			break;
		case mpe_use_type::use_grow:
			out << "use_grow"; 
			break;
		case mpe_use_type::use_battle:
			out << "use_battle"; 
			break;
		case mpe_use_type::use_hp_duration:
			out << "use_hp_duration"; 
			break;
		case mpe_use_type::use_hp_instant:
			out << "use_hp_instant"; 
			break;
		case mpe_use_type::use_mp_duration:
			out << "use_mp_duration"; 
			break;
		case mpe_use_type::use_mp_instant:
			out << "use_mp_instant"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_chatting& value)
	{
		switch (value)
		{
		case mpe_chatting::chat_normal:
			out << "chat_normal"; 
			break;
		case mpe_chatting::chat_world:
			out << "chat_world"; 
			break;
		case mpe_chatting::chat_party:
			out << "chat_party"; 
			break;
		case mpe_chatting::chat_guild:
			out << "chat_guild"; 
			break;
		case mpe_chatting::chat_promotion:
			out << "chat_promotion"; 
			break;
		case mpe_chatting::chat_exchange:
			out << "chat_exchange"; 
			break;
		case mpe_chatting::chat_system:
			out << "chat_system"; 
			break;
		case mpe_chatting::chat_private:
			out << "chat_private"; 
			break;
		case mpe_chatting::chat_guild_ally:
			out << "chat_guild_ally"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_notice_type& value)
	{
		switch (value)
		{
		case mpe_notice_type::none:
			out << "none"; 
			break;
		case mpe_notice_type::inspection_force:
			out << "inspection_force"; 
			break;
		case mpe_notice_type::inspection_normal:
			out << "inspection_normal"; 
			break;
		case mpe_notice_type::inspection_60sec:
			out << "inspection_60sec"; 
			break;
		case mpe_notice_type::inspection_30sec:
			out << "inspection_30sec"; 
			break;
		case mpe_notice_type::inspection_10sec:
			out << "inspection_10sec"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_revive& value)
	{
		switch (value)
		{
		case mpe_revive::revive_use_item:
			out << "revive_use_item"; 
			break;
		case mpe_revive::revive_vaillage:
			out << "revive_vaillage"; 
			break;
		case mpe_revive::revive_auto:
			out << "revive_auto"; 
			break;
		case mpe_revive::revive_skill:
			out << "revive_skill"; 
			break;
		case mpe_revive::revive_redirect:
			out << "revive_redirect"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_drop_owner& value)
	{
		switch (value)
		{
		case mpe_drop_owner::drop_owner_none:
			out << "drop_owner_none"; 
			break;
		case mpe_drop_owner::drop_owner_character:
			out << "drop_owner_character"; 
			break;
		case mpe_drop_owner::drop_owner_party:
			out << "drop_owner_party"; 
			break;
		case mpe_drop_owner::drop_owner_server:
			out << "drop_owner_server"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_pk_color& value)
	{
		switch (value)
		{
		case mpe_pk_color::pk_color_white:
			out << "pk_color_white"; 
			break;
		case mpe_pk_color::pk_color_brown:
			out << "pk_color_brown"; 
			break;
		case mpe_pk_color::pk_color_yellow:
			out << "pk_color_yellow"; 
			break;
		case mpe_pk_color::pk_color_red:
			out << "pk_color_red"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_update_type& value)
	{
		switch (value)
		{
		case mpe_update_type::update_type_none:
			out << "update_type_none"; 
			break;
		case mpe_update_type::update_type_protect_slot:
			out << "update_type_protect_slot"; 
			break;
		case mpe_update_type::update_type_inven_expansion:
			out << "update_type_inven_expansion"; 
			break;
		case mpe_update_type::update_type_inven_weight_expansion:
			out << "update_type_inven_weight_expansion"; 
			break;
		case mpe_update_type::update_type_character_revive:
			out << "update_type_character_revive"; 
			break;
		case mpe_update_type::update_type_auto_battle_add_time:
			out << "update_type_auto_battle_add_time"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_luck_reinforce_result& value)
	{
		switch (value)
		{
		case mpe_luck_reinforce_result::reinforce_none:
			out << "reinforce_none"; 
			break;
		case mpe_luck_reinforce_result::reinforce_success:
			out << "reinforce_success"; 
			break;
		case mpe_luck_reinforce_result::reinforce_fail:
			out << "reinforce_fail"; 
			break;
		case mpe_luck_reinforce_result::reinforce_fail_down:
			out << "reinforce_fail_down"; 
			break;
		case mpe_luck_reinforce_result::reinforce_big:
			out << "reinforce_big"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_result_fish& value)
	{
		switch (value)
		{
		case mpe_result_fish::fish_ing:
			out << "fish_ing"; 
			break;
		case mpe_result_fish::fish_fail:
			out << "fish_fail"; 
			break;
		case mpe_result_fish::fish_success:
			out << "fish_success"; 
			break;
		case mpe_result_fish::fish_big:
			out << "fish_big"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_item_reinforce_position& value)
	{
		switch (value)
		{
		case mpe_item_reinforce_position::equip:
			out << "equip"; 
			break;
		case mpe_item_reinforce_position::inventory:
			out << "inventory"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_skill_action_result& value)
	{
		switch (value)
		{
		case mpe_skill_action_result::skill_action_none:
			out << "skill_action_none"; 
			break;
		case mpe_skill_action_result::skill_action_start:
			out << "skill_action_start"; 
			break;
		case mpe_skill_action_result::skill_action_resist:
			out << "skill_action_resist"; 
			break;
		case mpe_skill_action_result::skill_action_immune:
			out << "skill_action_immune"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_guild_member_grade& value)
	{
		switch (value)
		{
		case mpe_guild_member_grade::none:
			out << "none"; 
			break;
		case mpe_guild_member_grade::master:
			out << "master"; 
			break;
		case mpe_guild_member_grade::sub_master:
			out << "sub_master"; 
			break;
		case mpe_guild_member_grade::elder:
			out << "elder"; 
			break;
		case mpe_guild_member_grade::common:
			out << "common"; 
			break;
		case mpe_guild_member_grade::all:
			out << "all"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_profesion& value)
	{
		switch (value)
		{
		case mpe_profesion::profesion_alchemy:
			out << "profesion_alchemy"; 
			break;
		case mpe_profesion::profesion_blacksmith:
			out << "profesion_blacksmith"; 
			break;
		case mpe_profesion::profesion_cooking:
			out << "profesion_cooking"; 
			break;
		case mpe_profesion::profesion_gather:
			out << "profesion_gather"; 
			break;
		case mpe_profesion::profesion_mining:
			out << "profesion_mining"; 
			break;
		case mpe_profesion::profesion_logging:
			out << "profesion_logging"; 
			break;
		case mpe_profesion::profesion_fishing:
			out << "profesion_fishing"; 
			break;
		case mpe_profesion::profesion_max:
			out << "profesion_max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_make_result& value)
	{
		switch (value)
		{
		case mpe_make_result::success:
			out << "success"; 
			break;
		case mpe_make_result::great:
			out << "great"; 
			break;
		case mpe_make_result::fail:
			out << "fail"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_echant_slot& value)
	{
		switch (value)
		{
		case mpe_echant_slot::echant_slot_none:
			out << "echant_slot_none"; 
			break;
		case mpe_echant_slot::echant_slot_slot_1:
			out << "echant_slot_slot_1"; 
			break;
		case mpe_echant_slot::echant_slot_slot_2:
			out << "echant_slot_slot_2"; 
			break;
		case mpe_echant_slot::echant_slot_slot_3:
			out << "echant_slot_slot_3"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_fsm_type& value)
	{
		switch (value)
		{
		case mpe_fsm_type::fsm_none:
			out << "fsm_none"; 
			break;
		case mpe_fsm_type::fsm_appeared:
			out << "fsm_appeared"; 
			break;
		case mpe_fsm_type::fsm_idle:
			out << "fsm_idle"; 
			break;
		case mpe_fsm_type::fsm_move:
			out << "fsm_move"; 
			break;
		case mpe_fsm_type::fsm_battle:
			out << "fsm_battle"; 
			break;
		case mpe_fsm_type::fsm_retraction:
			out << "fsm_retraction"; 
			break;
		case mpe_fsm_type::fsm_dead:
			out << "fsm_dead"; 
			break;
		case mpe_fsm_type::fsm_return:
			out << "fsm_return"; 
			break;
		case mpe_fsm_type::fsm_dummy:
			out << "fsm_dummy"; 
			break;
		case mpe_fsm_type::fsm_delete:
			out << "fsm_delete"; 
			break;
		case mpe_fsm_type::fsm_trace:
			out << "fsm_trace"; 
			break;
		case mpe_fsm_type::fsm_follow:
			out << "fsm_follow"; 
			break;
		case mpe_fsm_type::fsm_siege:
			out << "fsm_siege"; 
			break;
		case mpe_fsm_type::fsm_reverse:
			out << "fsm_reverse"; 
			break;
		case mpe_fsm_type::fsm_change:
			out << "fsm_change"; 
			break;
		case mpe_fsm_type::fsm_one_move:
			out << "fsm_one_move"; 
			break;
		case mpe_fsm_type::fsm_phase_change:
			out << "fsm_phase_change"; 
			break;
		case mpe_fsm_type::fsm_max:
			out << "fsm_max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_mail_type& value)
	{
		switch (value)
		{
		case mpe_mail_type::mail_type_account:
			out << "mail_type_account"; 
			break;
		case mpe_mail_type::mail_type_character:
			out << "mail_type_character"; 
			break;
		case mpe_mail_type::mail_type_server:
			out << "mail_type_server"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_mail_state& value)
	{
		switch (value)
		{
		case mpe_mail_state::mail_none:
			out << "mail_none"; 
			break;
		case mpe_mail_state::mail_opened:
			out << "mail_opened"; 
			break;
		case mpe_mail_state::mail_received_item:
			out << "mail_received_item"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_error& value)
	{
		switch (value)
		{
		case mpe_error::error_none:
			out << "error_none"; 
			break;
		case mpe_error::constSystemTable:
			out << "constSystemTable"; 
			break;
		case mpe_error::collectTable:
			out << "collectTable"; 
			break;
		case mpe_error::dropTable:
			out << "dropTable"; 
			break;
		case mpe_error::not_found_inventory:
			out << "not_found_inventory"; 
			break;
		case mpe_error::channel_is_full:
			out << "channel_is_full"; 
			break;
		case mpe_error::channel_is_not_exist:
			out << "channel_is_not_exist"; 
			break;
		case mpe_error::auth_duplicate_username:
			out << "auth_duplicate_username"; 
			break;
		case mpe_error::auth_unauthorized_user:
			out << "auth_unauthorized_user"; 
			break;
		case mpe_error::auth_wrong_group_number:
			out << "auth_wrong_group_number"; 
			break;
		case mpe_error::select_server_game_empty:
			out << "select_server_game_empty"; 
			break;
		case mpe_error::select_server_lobby_fail:
			out << "select_server_lobby_fail"; 
			break;
		case mpe_error::quick_login_info_empty:
			out << "quick_login_info_empty"; 
			break;
		case mpe_error::large_waiting_list:
			out << "large_waiting_list"; 
			break;
		case mpe_error::duplicate_login_retry:
			out << "duplicate_login_retry"; 
			break;
		case mpe_error::version_is_not_match:
			out << "version_is_not_match"; 
			break;
		case mpe_error::auth_failed_from_password:
			out << "auth_failed_from_password"; 
			break;
		case mpe_error::auth_failed_from_idcard:
			out << "auth_failed_from_idcard"; 
			break;
		case mpe_error::time_over_playingtime:
			out << "time_over_playingtime"; 
			break;
		case mpe_error::time_over_shotdown:
			out << "time_over_shotdown"; 
			break;
		case mpe_error::auth_failed_duplicate_idcard:
			out << "auth_failed_duplicate_idcard"; 
			break;
		case mpe_error::auth_failed_zh_hans:
			out << "auth_failed_zh_hans"; 
			break;
		case mpe_error::auth_failed_chinese:
			out << "auth_failed_chinese"; 
			break;
		case mpe_error::auth_limit_access:
			out << "auth_limit_access"; 
			break;
		case mpe_error::character_waiting_to_be_deleted:
			out << "character_waiting_to_be_deleted"; 
			break;
		case mpe_error::already_character_waiting_to_be_deleted:
			out << "already_character_waiting_to_be_deleted"; 
			break;
		case mpe_error::character_not_waiting_to_be_deleted:
			out << "character_not_waiting_to_be_deleted"; 
			break;
		case mpe_error::character_has_already_been_deleted:
			out << "character_has_already_been_deleted"; 
			break;
		case mpe_error::banned_words:
			out << "banned_words"; 
			break;
		case mpe_error::auth_session_failed:
			out << "auth_session_failed"; 
			break;
		case mpe_error::admin_kick_user:
			out << "admin_kick_user"; 
			break;
		case mpe_error::unknown_packet:
			out << "unknown_packet"; 
			break;
		case mpe_error::integrated_character_select_count:
			out << "integrated_character_select_count"; 
			break;
		case mpe_error::integrated_character_select_play:
			out << "integrated_character_select_play"; 
			break;
		case mpe_error::wmm_api_parameter_error:
			out << "wmm_api_parameter_error"; 
			break;
		case mpe_error::wmm_api_not_search_in_db:
			out << "wmm_api_not_search_in_db"; 
			break;
		case mpe_error::wmm_api_tokenid_expired:
			out << "wmm_api_tokenid_expired"; 
			break;
		case mpe_error::wmm_api_tokenid_is_diff:
			out << "wmm_api_tokenid_is_diff"; 
			break;
		case mpe_error::wmm_api_block_user:
			out << "wmm_api_block_user"; 
			break;
		case mpe_error::wmm_api_country_is_not_accessible:
			out << "wmm_api_country_is_not_accessible"; 
			break;
		case mpe_error::wmm_api_account_creation_ip_block:
			out << "wmm_api_account_creation_ip_block"; 
			break;
		case mpe_error::wmm_api_already_exist_account_id:
			out << "wmm_api_already_exist_account_id"; 
			break;
		case mpe_error::wmm_api_refund_block_user:
			out << "wmm_api_refund_block_user"; 
			break;
		case mpe_error::wmm_api_external_api_unavailable :
			out << "wmm_api_external_api_unavailable "; 
			break;
		case mpe_error::wmm_api_no_pay_data:
			out << "wmm_api_no_pay_data"; 
			break;
		case mpe_error::wmm_api_receipt_check_fail :
			out << "wmm_api_receipt_check_fail "; 
			break;
		case mpe_error::wmm_api_duplicate_receipt:
			out << "wmm_api_duplicate_receipt"; 
			break;
		case mpe_error::wmm_api_already_consume :
			out << "wmm_api_already_consume "; 
			break;
		case mpe_error::wmm_api_cancel_receipt:
			out << "wmm_api_cancel_receipt"; 
			break;
		case mpe_error::wmm_api_db_error :
			out << "wmm_api_db_error "; 
			break;
		case mpe_error::wmm_api_already_paid :
			out << "wmm_api_already_paid "; 
			break;
		case mpe_error::wmm_api_block_contry_code:
			out << "wmm_api_block_contry_code"; 
			break;
		case mpe_error::wmm_api_payment_error :
			out << "wmm_api_payment_error "; 
			break;
		case mpe_error::wmm_api_gameserver_error:
			out << "wmm_api_gameserver_error"; 
			break;
		case mpe_error::wmm_api_already_get_reward :
			out << "wmm_api_already_get_reward "; 
			break;
		case mpe_error::wmm_api_no_promo_product :
			out << "wmm_api_no_promo_product "; 
			break;
		case mpe_error::wmm_api_unknow_error:
			out << "wmm_api_unknow_error"; 
			break;
		case mpe_error::nprotect_api_error:
			out << "nprotect_api_error"; 
			break;
		case mpe_error::nprotect_api_not_yet:
			out << "nprotect_api_not_yet"; 
			break;
		case mpe_error::lobby_enter_waiting:
			out << "lobby_enter_waiting"; 
			break;
		case mpe_error::wmm_event_invalid_coupon:
			out << "wmm_event_invalid_coupon"; 
			break;
		case mpe_error::wmm_event_not_exist_character:
			out << "wmm_event_not_exist_character"; 
			break;
		case mpe_error::wmm_event_already_event_i_used_coupon:
			out << "wmm_event_already_event_i_used_coupon"; 
			break;
		case mpe_error::wmm_event_already_event_other_used_coupon:
			out << "wmm_event_already_event_other_used_coupon"; 
			break;
		case mpe_error::wmm_event_already_used_coupon:
			out << "wmm_event_already_used_coupon"; 
			break;
		case mpe_error::wmm_event_end:
			out << "wmm_event_end"; 
			break;
		case mpe_error::wmm_event_expire_time_coupon:
			out << "wmm_event_expire_time_coupon"; 
			break;
		case mpe_error::wmm_event_receive_all:
			out << "wmm_event_receive_all"; 
			break;
		case mpe_error::wmm_event_coupon_error:
			out << "wmm_event_coupon_error"; 
			break;
		case mpe_error::uncheater_verify_fail:
			out << "uncheater_verify_fail"; 
			break;
		case mpe_error::wmm_api_recover_signature_error:
			out << "wmm_api_recover_signature_error"; 
			break;
		case mpe_error::wmm_api_incorrect_transaction:
			out << "wmm_api_incorrect_transaction"; 
			break;
		case mpe_error::wmm_api_transaction_connect_fail:
			out << "wmm_api_transaction_connect_fail"; 
			break;
		case mpe_error::wmm_api_unknown_wallet_address:
			out << "wmm_api_unknown_wallet_address"; 
			break;
		case mpe_error::wmm_api_make_transaction_fail:
			out << "wmm_api_make_transaction_fail"; 
			break;
		case mpe_error::wmm_api_not_enough_allowance:
			out << "wmm_api_not_enough_allowance"; 
			break;
		case mpe_error::wmm_api_not_enough_token:
			out << "wmm_api_not_enough_token"; 
			break;
		case mpe_error::wmm_api_incorrect_price:
			out << "wmm_api_incorrect_price"; 
			break;
		case mpe_error::wmm_api_incorrect_product_id_price:
			out << "wmm_api_incorrect_product_id_price"; 
			break;
		case mpe_error::server_busy_try_later:
			out << "server_busy_try_later"; 
			break;
		case mpe_error::server_inspection:
			out << "server_inspection"; 
			break;
		case mpe_error::player_key_is_null:
			out << "player_key_is_null"; 
			break;
		case mpe_error::username_is_null:
			out << "username_is_null"; 
			break;
		case mpe_error::lobby_info_is_null:
			out << "lobby_info_is_null"; 
			break;
		case mpe_error::lobby_state_is_off:
			out << "lobby_state_is_off"; 
			break;
		case mpe_error::character_is_locked:
			out << "character_is_locked"; 
			break;
		case mpe_error::select_channel_is_not_exist:
			out << "select_channel_is_not_exist"; 
			break;
		case mpe_error::character_action_teleport_cancel:
			out << "character_action_teleport_cancel"; 
			break;
		case mpe_error::wmm_api_captcha_invalid_parameter:
			out << "wmm_api_captcha_invalid_parameter"; 
			break;
		case mpe_error::wmm_api_captcha_auth_fail:
			out << "wmm_api_captcha_auth_fail"; 
			break;
		case mpe_error::player_info_empty:
			out << "player_info_empty"; 
			break;
		case mpe_error::character_info_empty:
			out << "character_info_empty"; 
			break;
		case mpe_error::already_game_playing:
			out << "already_game_playing"; 
			break;
		case mpe_error::nickname_duplicate:
			out << "nickname_duplicate"; 
			break;
		case mpe_error::classtype_duplicate:
			out << "classtype_duplicate"; 
			break;
		case mpe_error::character_no_empty_slot:
			out << "character_no_empty_slot"; 
			break;
		case mpe_error::character_create_failed:
			out << "character_create_failed"; 
			break;
		case mpe_error::session_timeout:
			out << "session_timeout"; 
			break;
		case mpe_error::session_reconnect:
			out << "session_reconnect"; 
			break;
		case mpe_error::character_low_level:
			out << "character_low_level"; 
			break;
		case mpe_error::character_is_dead:
			out << "character_is_dead"; 
			break;
		case mpe_error::chatting_block_full:
			out << "chatting_block_full"; 
			break;
		case mpe_error::chatting_block_already:
			out << "chatting_block_already"; 
			break;
		case mpe_error::character_private_chatting_disable:
			out << "character_private_chatting_disable"; 
			break;
		case mpe_error::zone_is_null:
			out << "zone_is_null"; 
			break;
		case mpe_error::zone_invalid_pos:
			out << "zone_invalid_pos"; 
			break;
		case mpe_error::zone_invalid_index:
			out << "zone_invalid_index"; 
			break;
		case mpe_error::zone_same_zone_id:
			out << "zone_same_zone_id"; 
			break;
		case mpe_error::zone_failed_change_set:
			out << "zone_failed_change_set"; 
			break;
		case mpe_error::zone_tile_null:
			out << "zone_tile_null"; 
			break;
		case mpe_error::zone_wrong_tile_index:
			out << "zone_wrong_tile_index"; 
			break;
		case mpe_error::zone_invalid_tile:
			out << "zone_invalid_tile"; 
			break;
		case mpe_error::zone_curr_tile_null:
			out << "zone_curr_tile_null"; 
			break;
		case mpe_error::zone_next_tile_null:
			out << "zone_next_tile_null"; 
			break;
		case mpe_error::zone_wrong_next_tile:
			out << "zone_wrong_next_tile"; 
			break;
		case mpe_error::zone_wrong_new_curr_tile:
			out << "zone_wrong_new_curr_tile"; 
			break;
		case mpe_error::zone_new_next_tile_null:
			out << "zone_new_next_tile_null"; 
			break;
		case mpe_error::zone_astar_attribute_false:
			out << "zone_astar_attribute_false"; 
			break;
		case mpe_error::zone_astar_null:
			out << "zone_astar_null"; 
			break;
		case mpe_error::zone_tile_reserved:
			out << "zone_tile_reserved"; 
			break;
		case mpe_error::zone_invalid_tile_player:
			out << "zone_invalid_tile_player"; 
			break;
		case mpe_error::zone_invalid_tile_monster:
			out << "zone_invalid_tile_monster"; 
			break;
		case mpe_error::zone_invalid_tile_npc:
			out << "zone_invalid_tile_npc"; 
			break;
		case mpe_error::zone_object_null:
			out << "zone_object_null"; 
			break;
		case mpe_error::zone_object_type:
			out << "zone_object_type"; 
			break;
		case mpe_error::zone_collect_null:
			out << "zone_collect_null"; 
			break;
		case mpe_error::zone_collect_dist:
			out << "zone_collect_dist"; 
			break;
		case mpe_error::zone_collect_empty:
			out << "zone_collect_empty"; 
			break;
		case mpe_error::zone_collect_status_error:
			out << "zone_collect_status_error"; 
			break;
		case mpe_error::zone_collect_time:
			out << "zone_collect_time"; 
			break;
		case mpe_error::zone_collect_not_info:
			out << "zone_collect_not_info"; 
			break;
		case mpe_error::zone_invalid_character:
			out << "zone_invalid_character"; 
			break;
		case mpe_error::zone_not_ready:
			out << "zone_not_ready"; 
			break;
		case mpe_error::zone_object_create_failed:
			out << "zone_object_create_failed"; 
			break;
		case mpe_error::zone_npc_dist:
			out << "zone_npc_dist"; 
			break;
		case mpe_error::zone_fishing_dist:
			out << "zone_fishing_dist"; 
			break;
		case mpe_error::zone_fishing_time:
			out << "zone_fishing_time"; 
			break;
		case mpe_error::zone_fishing_null:
			out << "zone_fishing_null"; 
			break;
		case mpe_error::zone_fishing_status_error:
			out << "zone_fishing_status_error"; 
			break;
		case mpe_error::zone_vehicle_duplicate:
			out << "zone_vehicle_duplicate"; 
			break;
		case mpe_error::zone_vehicle_notarea:
			out << "zone_vehicle_notarea"; 
			break;
		case mpe_error::zone_daily_update_time:
			out << "zone_daily_update_time"; 
			break;
		case mpe_error::zone_object_not_found_server:
			out << "zone_object_not_found_server"; 
			break;
		case mpe_error::zone_treasure_box_null:
			out << "zone_treasure_box_null"; 
			break;
		case mpe_error::zone_treasure_box_dist:
			out << "zone_treasure_box_dist"; 
			break;
		case mpe_error::zone_treasure_box_info_null:
			out << "zone_treasure_box_info_null"; 
			break;
		case mpe_error::zone_treasure_box_open_time:
			out << "zone_treasure_box_open_time"; 
			break;
		case mpe_error::zone_treasure_box_not_owner:
			out << "zone_treasure_box_not_owner"; 
			break;
		case mpe_error::pickup_not_use_pet:
			out << "pickup_not_use_pet"; 
			break;
		case mpe_error::zone_teleport_untraceable_area:
			out << "zone_teleport_untraceable_area"; 
			break;
		case mpe_error::map_bind_buff_disable:
			out << "map_bind_buff_disable"; 
			break;
		case mpe_error::zone_sealing_device_null:
			out << "zone_sealing_device_null"; 
			break;
		case mpe_error::cannot_be_processed_while_teleporting:
			out << "cannot_be_processed_while_teleporting"; 
			break;
		case mpe_error::shortage_zone_move_required_level:
			out << "shortage_zone_move_required_level"; 
			break;
		case mpe_error::disable_contents:
			out << "disable_contents"; 
			break;
		case mpe_error::not_exist_profession_equip:
			out << "not_exist_profession_equip"; 
			break;
		case mpe_error::villain_not_enter_map:
			out << "villain_not_enter_map"; 
			break;
		case mpe_error::villain_not_stay_map:
			out << "villain_not_stay_map"; 
			break;
		case mpe_error::zone_collect_already_use:
			out << "zone_collect_already_use"; 
			break;
		case mpe_error::zone_already_use_black_iron:
			out << "zone_already_use_black_iron"; 
			break;
		case mpe_error::inventory_no_empty_slot:
			out << "inventory_no_empty_slot"; 
			break;
		case mpe_error::not_exist_item:
			out << "not_exist_item"; 
			break;
		case mpe_error::cannot_equip_item:
			out << "cannot_equip_item"; 
			break;
		case mpe_error::not_sell_item:
			out << "not_sell_item"; 
			break;
		case mpe_error::inventory_already_max:
			out << "inventory_already_max"; 
			break;
		case mpe_error::short_of_good_level:
			out << "short_of_good_level"; 
			break;
		case mpe_error::short_of_good_exp:
			out << "short_of_good_exp"; 
			break;
		case mpe_error::short_of_good_gold:
			out << "short_of_good_gold"; 
			break;
		case mpe_error::short_of_good_cash:
			out << "short_of_good_cash"; 
			break;
		case mpe_error::short_of_good_chao_point:
			out << "short_of_good_chao_point"; 
			break;
		case mpe_error::short_of_good_goldingot:
			out << "short_of_good_goldingot"; 
			break;
		case mpe_error::short_of_good_condition_bag:
			out << "short_of_good_condition_bag"; 
			break;
		case mpe_error::short_of_good_condition:
			out << "short_of_good_condition"; 
			break;
		case mpe_error::short_of_good_blackiron:
			out << "short_of_good_blackiron"; 
			break;
		case mpe_error::short_of_good_dungeon_ticket:
			out << "short_of_good_dungeon_ticket"; 
			break;
		case mpe_error::short_of_good_guild_point:
			out << "short_of_good_guild_point"; 
			break;
		case mpe_error::short_of_good_guild_gold:
			out << "short_of_good_guild_gold"; 
			break;
		case mpe_error::short_of_good_guild_blackiron:
			out << "short_of_good_guild_blackiron"; 
			break;
		case mpe_error::short_of_good_force_exp:
			out << "short_of_good_force_exp"; 
			break;
		case mpe_error::short_of_good_pk_point:
			out << "short_of_good_pk_point"; 
			break;
		case mpe_error::short_of_good_mentor_point:
			out << "short_of_good_mentor_point"; 
			break;
		case mpe_error::short_of_good_reserve_16:
			out << "short_of_good_reserve_16"; 
			break;
		case mpe_error::short_of_good_reserve_17:
			out << "short_of_good_reserve_17"; 
			break;
		case mpe_error::short_of_good_mileage:
			out << "short_of_good_mileage"; 
			break;
		case mpe_error::short_of_good_reserve_19:
			out << "short_of_good_reserve_19"; 
			break;
		case mpe_error::short_of_good_reserve_20:
			out << "short_of_good_reserve_20"; 
			break;
		case mpe_error::short_of_good_reserve_21:
			out << "short_of_good_reserve_21"; 
			break;
		case mpe_error::short_of_good_reserve_22:
			out << "short_of_good_reserve_22"; 
			break;
		case mpe_error::short_of_good_reserve_23:
			out << "short_of_good_reserve_23"; 
			break;
		case mpe_error::short_of_good_reserve_24:
			out << "short_of_good_reserve_24"; 
			break;
		case mpe_error::short_of_item_count:
			out << "short_of_item_count"; 
			break;
		case mpe_error::not_reinforce_item:
			out << "not_reinforce_item"; 
			break;
		case mpe_error::max_of_reinforce:
			out << "max_of_reinforce"; 
			break;
		case mpe_error::not_use_material_item:
			out << "not_use_material_item"; 
			break;
		case mpe_error::max_amount_material_item:
			out << "max_amount_material_item"; 
			break;
		case mpe_error::max_amount_buy_item:
			out << "max_amount_buy_item"; 
			break;
		case mpe_error::max_amount_sell_item:
			out << "max_amount_sell_item"; 
			break;
		case mpe_error::locked_item:
			out << "locked_item"; 
			break;
		case mpe_error::slot_exist_item:
			out << "slot_exist_item"; 
			break;
		case mpe_error::slot_not_signup:
			out << "slot_not_signup"; 
			break;
		case mpe_error::slot_not_exist_item:
			out << "slot_not_exist_item"; 
			break;
		case mpe_error::not_for_sell_npc:
			out << "not_for_sell_npc"; 
			break;
		case mpe_error::not_npc:
			out << "not_npc"; 
			break;
		case mpe_error::invalid_pickup_dist:
			out << "invalid_pickup_dist"; 
			break;
		case mpe_error::wrong_pickup_index:
			out << "wrong_pickup_index"; 
			break;
		case mpe_error::wrong_pickup_item_id:
			out << "wrong_pickup_item_id"; 
			break;
		case mpe_error::not_exist_pickup_item:
			out << "not_exist_pickup_item"; 
			break;
		case mpe_error::reward_item_pool_null:
			out << "reward_item_pool_null"; 
			break;
		case mpe_error::item_incorrect_type:
			out << "item_incorrect_type"; 
			break;
		case mpe_error::pickup_item_wrong_owner:
			out << "pickup_item_wrong_owner"; 
			break;
		case mpe_error::drop_protect_slot:
			out << "drop_protect_slot"; 
			break;
		case mpe_error::weight_already_max:
			out << "weight_already_max"; 
			break;
		case mpe_error::not_destroy_item:
			out << "not_destroy_item"; 
			break;
		case mpe_error::not_decompose_item:
			out << "not_decompose_item"; 
			break;
		case mpe_error::item_already_locked:
			out << "item_already_locked"; 
			break;
		case mpe_error::item_already_unlocked:
			out << "item_already_unlocked"; 
			break;
		case mpe_error::item_can_not_lock:
			out << "item_can_not_lock"; 
			break;
		case mpe_error::short_of_good_guild_goldingot:
			out << "short_of_good_guild_goldingot"; 
			break;
		case mpe_error::item_can_not_lock_indun_prepare:
			out << "item_can_not_lock_indun_prepare"; 
			break;
		case mpe_error::exchagne_no_register_item:
			out << "exchagne_no_register_item"; 
			break;
		case mpe_error::exchagne_no_empty_slot:
			out << "exchagne_no_empty_slot"; 
			break;
		case mpe_error::exchagne_price_wrong:
			out << "exchagne_price_wrong"; 
			break;
		case mpe_error::exchagne_price_low:
			out << "exchagne_price_low"; 
			break;
		case mpe_error::exchagne_reg_cancel_nofound:
			out << "exchagne_reg_cancel_nofound"; 
			break;
		case mpe_error::exchagne_reg_cancel_cannot:
			out << "exchagne_reg_cancel_cannot"; 
			break;
		case mpe_error::exchagne_buy_item_notfound:
			out << "exchagne_buy_item_notfound"; 
			break;
		case mpe_error::exchagne_buy_storage_full:
			out << "exchagne_buy_storage_full"; 
			break;
		case mpe_error::exchagne_buy_count_wrong:
			out << "exchagne_buy_count_wrong"; 
			break;
		case mpe_error::exchagne_buy_price_wrong:
			out << "exchagne_buy_price_wrong"; 
			break;
		case mpe_error::exchagne_buy_expire_over:
			out << "exchagne_buy_expire_over"; 
			break;
		case mpe_error::exchagne_buy_not_state:
			out << "exchagne_buy_not_state"; 
			break;
		case mpe_error::exchagne_buy_same_account:
			out << "exchagne_buy_same_account"; 
			break;
		case mpe_error::exchagne_takeitem_notfound:
			out << "exchagne_takeitem_notfound"; 
			break;
		case mpe_error::exchagne_takeitem_expire:
			out << "exchagne_takeitem_expire"; 
			break;
		case mpe_error::exchagne_takegold_notfound:
			out << "exchagne_takegold_notfound"; 
			break;
		case mpe_error::exchagne_takegold_notgold:
			out << "exchagne_takegold_notgold"; 
			break;
		case mpe_error::cannot_show_costume:
			out << "cannot_show_costume"; 
			break;
		case mpe_error::cash_shop_cart_is_full:
			out << "cash_shop_cart_is_full"; 
			break;
		case mpe_error::gold_is_max:
			out << "gold_is_max"; 
			break;
		case mpe_error::goldingot_is_max:
			out << "goldingot_is_max"; 
			break;
		case mpe_error::cash_is_max:
			out << "cash_is_max"; 
			break;
		case mpe_error::cash_shop_daily_limit_over:
			out << "cash_shop_daily_limit_over"; 
			break;
		case mpe_error::cash_shop_weekly_limit_over:
			out << "cash_shop_weekly_limit_over"; 
			break;
		case mpe_error::cash_shop_monthly_limit_over:
			out << "cash_shop_monthly_limit_over"; 
			break;
		case mpe_error::cash_shop_character_limit_over:
			out << "cash_shop_character_limit_over"; 
			break;
		case mpe_error::cash_shop_account_limit_over:
			out << "cash_shop_account_limit_over"; 
			break;
		case mpe_error::cash_shop_server_limit_over:
			out << "cash_shop_server_limit_over"; 
			break;
		case mpe_error::cash_shop_not_buy_date:
			out << "cash_shop_not_buy_date"; 
			break;
		case mpe_error::cash_shop_not_buy_exchange_product:
			out << "cash_shop_not_buy_exchange_product"; 
			break;
		case mpe_error::cash_shop_remain_date_exchange_reset:
			out << "cash_shop_remain_date_exchange_reset"; 
			break;
		case mpe_error::cash_shop_limit_guild_league:
			out << "cash_shop_limit_guild_league"; 
			break;
		case mpe_error::mileage_is_max:
			out << "mileage_is_max"; 
			break;
		case mpe_error::cash_shop_not_get_daily_item:
			out << "cash_shop_not_get_daily_item"; 
			break;
		case mpe_error::not_make_recipe:
			out << "not_make_recipe"; 
			break;
		case mpe_error::not_profesion_equal_type:
			out << "not_profesion_equal_type"; 
			break;
		case mpe_error::not_profesion_upgrade:
			out << "not_profesion_upgrade"; 
			break;
		case mpe_error::profesion_already_reset:
			out << "profesion_already_reset"; 
			break;
		case mpe_error::short_profesion_level:
			out << "short_profesion_level"; 
			break;
		case mpe_error::profesion_short_item:
			out << "profesion_short_item"; 
			break;
		case mpe_error::blackiron_sell_regist_min_value_low:
			out << "blackiron_sell_regist_min_value_low"; 
			break;
		case mpe_error::blackiron_sell_regist_max_value_over:
			out << "blackiron_sell_regist_max_value_over"; 
			break;
		case mpe_error::blackiron_sell_regist_time_over:
			out << "blackiron_sell_regist_time_over"; 
			break;
		case mpe_error::blackiron_shop_buy_check:
			out << "blackiron_shop_buy_check"; 
			break;
		case mpe_error::blackiron_is_full:
			out << "blackiron_is_full"; 
			break;
		case mpe_error::blackiron_regist_key_is_incorrect:
			out << "blackiron_regist_key_is_incorrect"; 
			break;
		case mpe_error::blackiron_sell_count_shortage:
			out << "blackiron_sell_count_shortage"; 
			break;
		case mpe_error::blackiron_shop_owner_is_null:
			out << "blackiron_shop_owner_is_null"; 
			break;
		case mpe_error::blackiron_shop_list_null:
			out << "blackiron_shop_list_null"; 
			break;
		case mpe_error::auto_battle_max_charge_over:
			out << "auto_battle_max_charge_over"; 
			break;
		case mpe_error::cash_shop_not_step_product:
			out << "cash_shop_not_step_product"; 
			break;
		case mpe_error::item_expiretime:
			out << "item_expiretime"; 
			break;
		case mpe_error::sealtowercoin_is_full:
			out << "sealtowercoin_is_full"; 
			break;
		case mpe_error::demontowercoin_is_full:
			out << "demontowercoin_is_full"; 
			break;
		case mpe_error::recipe_use_all_make_count:
			out << "recipe_use_all_make_count"; 
			break;
		case mpe_error::bloodstone_is_full:
			out << "bloodstone_is_full"; 
			break;
		case mpe_error::meridians_max_level:
			out << "meridians_max_level"; 
			break;
		case mpe_error::acupoints_max_level:
			out << "acupoints_max_level"; 
			break;
		case mpe_error::acupoints_lack_level:
			out << "acupoints_lack_level"; 
			break;
		case mpe_error::already_special_move:
			out << "already_special_move"; 
			break;
		case mpe_error::disable_special_move_slot:
			out << "disable_special_move_slot"; 
			break;
		case mpe_error::is_blank_slot:
			out << "is_blank_slot"; 
			break;
		case mpe_error::special_move_invalid_type:
			out << "special_move_invalid_type"; 
			break;
		case mpe_error::unable_to_raise_level:
			out << "unable_to_raise_level"; 
			break;
		case mpe_error::short_of_meridians:
			out << "short_of_meridians"; 
			break;
		case mpe_error::special_move_slot_max_level:
			out << "special_move_slot_max_level"; 
			break;
		case mpe_error::short_of_special_move_slot_level:
			out << "short_of_special_move_slot_level"; 
			break;
		case mpe_error::special_move_number_of_choices_is_different:
			out << "special_move_number_of_choices_is_different"; 
			break;
		case mpe_error::exchagne_no_register_item_Equipstone:
			out << "exchagne_no_register_item_Equipstone"; 
			break;
		case mpe_error::condition_limit_lack:
			out << "condition_limit_lack"; 
			break;
		case mpe_error::condition_fill_no_more:
			out << "condition_fill_no_more"; 
			break;
		case mpe_error::condition_fill_time_wrong:
			out << "condition_fill_time_wrong"; 
			break;
		case mpe_error::conditionbag_already_full:
			out << "conditionbag_already_full"; 
			break;
		case mpe_error::conditionbag_over_value:
			out << "conditionbag_over_value"; 
			break;
		case mpe_error::equip_stone_inven_not_empty:
			out << "equip_stone_inven_not_empty"; 
			break;
		case mpe_error::essence_inven_not_empty:
			out << "essence_inven_not_empty"; 
			break;
		case mpe_error::map_discovery_already_find_area:
			out << "map_discovery_already_find_area"; 
			break;
		case mpe_error::mail_already_receive_item:
			out << "mail_already_receive_item"; 
			break;
		case mpe_error::receive_item_empty_mail:
			out << "receive_item_empty_mail"; 
			break;
		case mpe_error::not_open_mail:
			out << "not_open_mail"; 
			break;
		case mpe_error::items_not_received:
			out << "items_not_received"; 
			break;
		case mpe_error::mail_max_count_request:
			out << "mail_max_count_request"; 
			break;
		case mpe_error::not_found_mail:
			out << "not_found_mail"; 
			break;
		case mpe_error::mail_max_item_count:
			out << "mail_max_item_count"; 
			break;
		case mpe_error::mail_already_opened:
			out << "mail_already_opened"; 
			break;
		case mpe_error::mail_can_not_receive:
			out << "mail_can_not_receive"; 
			break;
		case mpe_error::mail_can_not_delete:
			out << "mail_can_not_delete"; 
			break;
		case mpe_error::mail_no_available:
			out << "mail_no_available"; 
			break;
		case mpe_error::personal_trade_already:
			out << "personal_trade_already"; 
			break;
		case mpe_error::personal_trade_unable:
			out << "personal_trade_unable"; 
			break;
		case mpe_error::personal_trade_dist:
			out << "personal_trade_dist"; 
			break;
		case mpe_error::personal_trade_zone_invalid:
			out << "personal_trade_zone_invalid"; 
			break;
		case mpe_error::personal_trade_zone_not_peace:
			out << "personal_trade_zone_not_peace"; 
			break;
		case mpe_error::personal_trade_register_max_count:
			out << "personal_trade_register_max_count"; 
			break;
		case mpe_error::randombox_select_over:
			out << "randombox_select_over"; 
			break;
		case mpe_error::once_over_payment:
			out << "once_over_payment"; 
			break;
		case mpe_error::month_over_payment:
			out << "month_over_payment"; 
			break;
		case mpe_error::once_18_over_payment:
			out << "once_18_over_payment"; 
			break;
		case mpe_error::month_18_over_payment:
			out << "month_18_over_payment"; 
			break;
		case mpe_error::once_under_payment:
			out << "once_under_payment"; 
			break;
		case mpe_error::month_16_over_payment:
			out << "month_16_over_payment"; 
			break;
		case mpe_error::once_16_over_payment:
			out << "once_16_over_payment"; 
			break;
		case mpe_error::not_invalid_goods_move:
			out << "not_invalid_goods_move"; 
			break;
		case mpe_error::not_exist_storage_good_type:
			out << "not_exist_storage_good_type"; 
			break;
		case mpe_error::not_invalid_storage_type:
			out << "not_invalid_storage_type"; 
			break;
		case mpe_error::storage_expand_overflow:
			out << "storage_expand_overflow"; 
			break;
		case mpe_error::account_storage_exist:
			out << "account_storage_exist"; 
			break;
		case mpe_error::enchant_stone_exist:
			out << "enchant_stone_exist"; 
			break;
		case mpe_error::enchant_stone_slot_locked:
			out << "enchant_stone_slot_locked"; 
			break;
		case mpe_error::enchant_stone_slot_empty:
			out << "enchant_stone_slot_empty"; 
			break;
		case mpe_error::enchant_stone_slot_imposible:
			out << "enchant_stone_slot_imposible"; 
			break;
		case mpe_error::enchant_stone_slot_already_max:
			out << "enchant_stone_slot_already_max"; 
			break;
		case mpe_error::maximum_count:
			out << "maximum_count"; 
			break;
		case mpe_error::used_all_count_today:
			out << "used_all_count_today"; 
			break;
		case mpe_error::vehicle_duplicate_id:
			out << "vehicle_duplicate_id"; 
			break;
		case mpe_error::vehicle_not_exist:
			out << "vehicle_not_exist"; 
			break;
		case mpe_error::vehicle_not_equip:
			out << "vehicle_not_equip"; 
			break;
		case mpe_error::vehicle_not_get_type:
			out << "vehicle_not_get_type"; 
			break;
		case mpe_error::vehicle_max:
			out << "vehicle_max"; 
			break;
		case mpe_error::vehicle_expire:
			out << "vehicle_expire"; 
			break;
		case mpe_error::vehicle_already_expire:
			out << "vehicle_already_expire"; 
			break;
		case mpe_error::vehicle_remain_date:
			out << "vehicle_remain_date"; 
			break;
		case mpe_error::vehicle_remain_satiety:
			out << "vehicle_remain_satiety"; 
			break;
		case mpe_error::vehicle_level_max:
			out << "vehicle_level_max"; 
			break;
		case mpe_error::vehicle_satiety_max:
			out << "vehicle_satiety_max"; 
			break;
		case mpe_error::title_durability:
			out << "title_durability"; 
			break;
		case mpe_error::not_exists_title:
			out << "not_exists_title"; 
			break;
		case mpe_error::not_complete_title:
			out << "not_complete_title"; 
			break;
		case mpe_error::title_level_max:
			out << "title_level_max"; 
			break;
		case mpe_error::vehicle_satiety_zero:
			out << "vehicle_satiety_zero"; 
			break;
		case mpe_error::title_not_remain:
			out << "title_not_remain"; 
			break;
		case mpe_error::not_exists_dictionary_type:
			out << "not_exists_dictionary_type"; 
			break;
		case mpe_error::dictionary_is_duplicate_item:
			out << "dictionary_is_duplicate_item"; 
			break;
		case mpe_error::npc_intimacy_max:
			out << "npc_intimacy_max"; 
			break;
		case mpe_error::dictionary_remain_date:
			out << "dictionary_remain_date"; 
			break;
		case mpe_error::short_of_npc_intimacy:
			out << "short_of_npc_intimacy"; 
			break;
		case mpe_error::npc_intimacy_already_reward:
			out << "npc_intimacy_already_reward"; 
			break;
		case mpe_error::seasonpass_already_completed:
			out << "seasonpass_already_completed"; 
			break;
		case mpe_error::seasonpass_short_level:
			out << "seasonpass_short_level"; 
			break;
		case mpe_error::seasonpass_already_reward:
			out << "seasonpass_already_reward"; 
			break;
		case mpe_error::seasonpass_short_count:
			out << "seasonpass_short_count"; 
			break;
		case mpe_error::seasonpass_max_level:
			out << "seasonpass_max_level"; 
			break;
		case mpe_error::seasonpass_short_unlock_level:
			out << "seasonpass_short_unlock_level"; 
			break;
		case mpe_error::seasonpass_remain_unlock_time:
			out << "seasonpass_remain_unlock_time"; 
			break;
		case mpe_error::seasonpass_not_buy:
			out << "seasonpass_not_buy"; 
			break;
		case mpe_error::revive_request_invalid:
			out << "revive_request_invalid"; 
			break;
		case mpe_error::revive_request_duplicate:
			out << "revive_request_duplicate"; 
			break;
		case mpe_error::revive_request_already:
			out << "revive_request_already"; 
			break;
		case mpe_error::mandala_node_level_max:
			out << "mandala_node_level_max"; 
			break;
		case mpe_error::mandala_node_impossible:
			out << "mandala_node_impossible"; 
			break;
		case mpe_error::mandala_node_already:
			out << "mandala_node_already"; 
			break;
		case mpe_error::quest_not_found:
			out << "quest_not_found"; 
			break;
		case mpe_error::quest_accept_not_repeated:
			out << "quest_accept_not_repeated"; 
			break;
		case mpe_error::quest_accept_level:
			out << "quest_accept_level"; 
			break;
		case mpe_error::quest_accept_need_quest:
			out << "quest_accept_need_quest"; 
			break;
		case mpe_error::quest_accept_exceeded:
			out << "quest_accept_exceeded"; 
			break;
		case mpe_error::quest_finish_not_complet:
			out << "quest_finish_not_complet"; 
			break;
		case mpe_error::quest_npctalk_notfound_npc:
			out << "quest_npctalk_notfound_npc"; 
			break;
		case mpe_error::quest_complete_failed:
			out << "quest_complete_failed"; 
			break;
		case mpe_error::quest_move_complete_dist:
			out << "quest_move_complete_dist"; 
			break;
		case mpe_error::quest_not_get_object:
			out << "quest_not_get_object"; 
			break;
		case mpe_error::quest_cannot_giveup_main:
			out << "quest_cannot_giveup_main"; 
			break;
		case mpe_error::area_quest_daily_finish_count_over:
			out << "area_quest_daily_finish_count_over"; 
			break;
		case mpe_error::quest_accept_need_item:
			out << "quest_accept_need_item"; 
			break;
		case mpe_error::quest_unacceptable:
			out << "quest_unacceptable"; 
			break;
		case mpe_error::quest_accept_not_match_condition:
			out << "quest_accept_not_match_condition"; 
			break;
		case mpe_error::quest_accept_profession_level_low:
			out << "quest_accept_profession_level_low"; 
			break;
		case mpe_error::quest_not_clear:
			out << "quest_not_clear"; 
			break;
		case mpe_error::quest_not_supported:
			out << "quest_not_supported"; 
			break;
		case mpe_error::repute_quest_chao_point_is_:
			out << "repute_quest_chao_point_is_"; 
			break;
		case mpe_error::repute_quest_is_max:
			out << "repute_quest_is_max"; 
			break;
		case mpe_error::repute_quest_fail_refresh:
			out << "repute_quest_fail_refresh"; 
			break;
		case mpe_error::repute_daily_completion_count_exceeded:
			out << "repute_daily_completion_count_exceeded"; 
			break;
		case mpe_error::repute_quest_daily_reset_count_exceeded:
			out << "repute_quest_daily_reset_count_exceeded"; 
			break;
		case mpe_error::repute_quest_finish_count_not_full:
			out << "repute_quest_finish_count_not_full"; 
			break;
		case mpe_error::repute_quest_not_match_level:
			out << "repute_quest_not_match_level"; 
			break;
		case mpe_error::repute_quest_not_match_chao_point:
			out << "repute_quest_not_match_chao_point"; 
			break;
		case mpe_error::can_not_finish_quest:
			out << "can_not_finish_quest"; 
			break;
		case mpe_error::repute_point_max:
			out << "repute_point_max"; 
			break;
		case mpe_error::guild_is_not:
			out << "guild_is_not"; 
			break;
		case mpe_error::guild_already_joined:
			out << "guild_already_joined"; 
			break;
		case mpe_error::guild_already_join_request:
			out << "guild_already_join_request"; 
			break;
		case mpe_error::guild_full_join_request:
			out << "guild_full_join_request"; 
			break;
		case mpe_error::guild_full_recv_join_reques:
			out << "guild_full_recv_join_reques"; 
			break;
		case mpe_error::guild_not_empty_member_size:
			out << "guild_not_empty_member_size"; 
			break;
		case mpe_error::guild_master_cannot_escape:
			out << "guild_master_cannot_escape"; 
			break;
		case mpe_error::guild_not_exist_member:
			out << "guild_not_exist_member"; 
			break;
		case mpe_error::guild_invalid_auth:
			out << "guild_invalid_auth"; 
			break;
		case mpe_error::guild_nickname_already_in_use:
			out << "guild_nickname_already_in_use"; 
			break;
		case mpe_error::guild_join_low_level:
			out << "guild_join_low_level"; 
			break;
		case mpe_error::guild_not_change_you_infomation:
			out << "guild_not_change_you_infomation"; 
			break;
		case mpe_error::guild_members_remaining:
			out << "guild_members_remaining"; 
			break;
		case mpe_error::guild_have_limit_time_left:
			out << "guild_have_limit_time_left"; 
			break;
		case mpe_error::guild_war_count_max:
			out << "guild_war_count_max"; 
			break;
		case mpe_error::guild_can_not_declare_restart_time:
			out << "guild_can_not_declare_restart_time"; 
			break;
		case mpe_error::enermy_guild_war_count_max:
			out << "enermy_guild_war_count_max"; 
			break;
		case mpe_error::guild_use_all_donations:
			out << "guild_use_all_donations"; 
			break;
		case mpe_error::guild_not_war:
			out << "guild_not_war"; 
			break;
		case mpe_error::guild_war_already_in_progress:
			out << "guild_war_already_in_progress"; 
			break;
		case mpe_error::target_guild_not_exist:
			out << "target_guild_not_exist"; 
			break;
		case mpe_error::target_guild_invalid:
			out << "target_guild_invalid"; 
			break;
		case mpe_error::guild_not_joined:
			out << "guild_not_joined"; 
			break;
		case mpe_error::guild_war_already_negotiating:
			out << "guild_war_already_negotiating"; 
			break;
		case mpe_error::guild_war_minimum_negotiation_gold:
			out << "guild_war_minimum_negotiation_gold"; 
			break;
		case mpe_error::guild_war_not_negotiating:
			out << "guild_war_not_negotiating"; 
			break;
		case mpe_error::guild_max_level:
			out << "guild_max_level"; 
			break;
		case mpe_error::guild_max_skill_level:
			out << "guild_max_skill_level"; 
			break;
		case mpe_error::guild_waiting_rpc_response:
			out << "guild_waiting_rpc_response"; 
			break;
		case mpe_error::guild_low_level:
			out << "guild_low_level"; 
			break;
		case mpe_error::guild_notice_length_too_long:
			out << "guild_notice_length_too_long"; 
			break;
		case mpe_error::guild_skill_not_exist:
			out << "guild_skill_not_exist"; 
			break;
		case mpe_error::guild_skill_point_lack:
			out << "guild_skill_point_lack"; 
			break;
		case mpe_error::guild_skill_invalid_level:
			out << "guild_skill_invalid_level"; 
			break;
		case mpe_error::guild_member_must_in_siege_map:
			out << "guild_member_must_in_siege_map"; 
			break;
		case mpe_error::guild_storage_supply_request_count_full:
			out << "guild_storage_supply_request_count_full"; 
			break;
		case mpe_error::guild_storage_short_of_item_count:
			out << "guild_storage_short_of_item_count"; 
			break;
		case mpe_error::guild_storage_cant_over_max_int:
			out << "guild_storage_cant_over_max_int"; 
			break;
		case mpe_error::guild_storage_is_full:
			out << "guild_storage_is_full"; 
			break;
		case mpe_error::guild_storage_has_max_slot:
			out << "guild_storage_has_max_slot"; 
			break;
		case mpe_error::guild_storage_share_request_count_full:
			out << "guild_storage_share_request_count_full"; 
			break;
		case mpe_error::guild_storage_share_not_exist_request:
			out << "guild_storage_share_not_exist_request"; 
			break;
		case mpe_error::guild_storage_share_not_exist_member:
			out << "guild_storage_share_not_exist_member"; 
			break;
		case mpe_error::guild_storage_share_request_expired:
			out << "guild_storage_share_request_expired"; 
			break;
		case mpe_error::guild_not_have_castle_down:
			out << "guild_not_have_castle_down"; 
			break;
		case mpe_error::guild_storage_treasure_auction_not_exist:
			out << "guild_storage_treasure_auction_not_exist"; 
			break;
		case mpe_error::guild_storage_treasure_auction_expired:
			out << "guild_storage_treasure_auction_expired"; 
			break;
		case mpe_error::guild_storage_treasure_auction_request_count_full:
			out << "guild_storage_treasure_auction_request_count_full"; 
			break;
		case mpe_error::guild_storage_treasure_auction_price_too_low:
			out << "guild_storage_treasure_auction_price_too_low"; 
			break;
		case mpe_error::guild_storage_treasure_auction_already_top:
			out << "guild_storage_treasure_auction_already_top"; 
			break;
		case mpe_error::guild_storage_treasure_auction_in_progress:
			out << "guild_storage_treasure_auction_in_progress"; 
			break;
		case mpe_error::guild_storage_treasure_auction_not_joined:
			out << "guild_storage_treasure_auction_not_joined"; 
			break;
		case mpe_error::guild_level_is_low:
			out << "guild_level_is_low"; 
			break;
		case mpe_error::guild_quest_office_level_is_low:
			out << "guild_quest_office_level_is_low"; 
			break;
		case mpe_error::guild_quest_daily_finish_count_full:
			out << "guild_quest_daily_finish_count_full"; 
			break;
		case mpe_error::guild_office_quest_daily_finish_count_full:
			out << "guild_office_quest_daily_finish_count_full"; 
			break;
		case mpe_error::guild_master_order_quest_already_in_progress:
			out << "guild_master_order_quest_already_in_progress"; 
			break;
		case mpe_error::guild_master_order_quest_expired:
			out << "guild_master_order_quest_expired"; 
			break;
		case mpe_error::guild_master_order_quest_not_found:
			out << "guild_master_order_quest_not_found"; 
			break;
		case mpe_error::guild_already_open_dungeon:
			out << "guild_already_open_dungeon"; 
			break;
		case mpe_error::guild_unfinished_dungeon:
			out << "guild_unfinished_dungeon"; 
			break;
		case mpe_error::guild_use_all_pr_count:
			out << "guild_use_all_pr_count"; 
			break;
		case mpe_error::guild_beginner_cannot_contents:
			out << "guild_beginner_cannot_contents"; 
			break;
		case mpe_error::guild_mark_is_null:
			out << "guild_mark_is_null"; 
			break;
		case mpe_error::guild_mark_use_condition_error:
			out << "guild_mark_use_condition_error"; 
			break;
		case mpe_error::guild_buff_already_buy:
			out << "guild_buff_already_buy"; 
			break;
		case mpe_error::guild_buff_max_count:
			out << "guild_buff_max_count"; 
			break;
		case mpe_error::guild_dungeon_open_count_all_use:
			out << "guild_dungeon_open_count_all_use"; 
			break;
		case mpe_error::guild_time_limit_for_request:
			out << "guild_time_limit_for_request"; 
			break;
		case mpe_error::guild_war_low_level:
			out << "guild_war_low_level"; 
			break;
		case mpe_error::guild_name_is_invalid:
			out << "guild_name_is_invalid"; 
			break;
		case mpe_error::guild_dungeon_open_count_charge_all_use:
			out << "guild_dungeon_open_count_charge_all_use"; 
			break;
		case mpe_error::guild_dungeon_open_count_remain:
			out << "guild_dungeon_open_count_remain"; 
			break;
		case mpe_error::guild_ally_already_alliance:
			out << "guild_ally_already_alliance"; 
			break;
		case mpe_error::guild_ally_really_cooldown:
			out << "guild_ally_really_cooldown"; 
			break;
		case mpe_error::guild_ally_already_requested:
			out << "guild_ally_already_requested"; 
			break;
		case mpe_error::guild_ally_already_received:
			out << "guild_ally_already_received"; 
			break;
		case mpe_error::guild_ally_not_exist_request:
			out << "guild_ally_not_exist_request"; 
			break;
		case mpe_error::guild_ally_target_max_request_recv_limit:
			out << "guild_ally_target_max_request_recv_limit"; 
			break;
		case mpe_error::guild_ally_max_request_send_limit:
			out << "guild_ally_max_request_send_limit"; 
			break;
		case mpe_error::guild_ally_not_allied:
			out << "guild_ally_not_allied"; 
			break;
		case mpe_error::guild_master_change_fail_by_last_connect_time_condition:
			out << "guild_master_change_fail_by_last_connect_time_condition"; 
			break;
		case mpe_error::guild_master_change_fail_by_require_grade:
			out << "guild_master_change_fail_by_require_grade"; 
			break;
		case mpe_error::guild_war_start_fail_target_is_ally:
			out << "guild_war_start_fail_target_is_ally"; 
			break;
		case mpe_error::guild_can_not_deleted_reason_is_ally:
			out << "guild_can_not_deleted_reason_is_ally"; 
			break;
		case mpe_error::guild_ally_permision_deny:
			out << "guild_ally_permision_deny"; 
			break;
		case mpe_error::guild_ally_occupation_war_start:
			out << "guild_ally_occupation_war_start"; 
			break;
		case mpe_error::guild_ally_deny_by_war:
			out << "guild_ally_deny_by_war"; 
			break;
		case mpe_error::siege_warfare_tender_incorect_time:
			out << "siege_warfare_tender_incorect_time"; 
			break;
		case mpe_error::siege_warfare_build_not_first_guild:
			out << "siege_warfare_build_not_first_guild"; 
			break;
		case mpe_error::siege_warfare_build_not_possessed_item:
			out << "siege_warfare_build_not_possessed_item"; 
			break;
		case mpe_error::siege_warfare_no_permission:
			out << "siege_warfare_no_permission"; 
			break;
		case mpe_error::siege_warfare_build_not_owner_guild:
			out << "siege_warfare_build_not_owner_guild"; 
			break;
		case mpe_error::siege_warfare_alliance_max:
			out << "siege_warfare_alliance_max"; 
			break;
		case mpe_error::siege_warfare_prepare_incorect_time:
			out << "siege_warfare_prepare_incorect_time"; 
			break;
		case mpe_error::castle_tax_change_same_day:
			out << "castle_tax_change_same_day"; 
			break;
		case mpe_error::castle_tax_change_same_tax:
			out << "castle_tax_change_same_tax"; 
			break;
		case mpe_error::castle_tax_change_max_tax:
			out << "castle_tax_change_max_tax"; 
			break;
		case mpe_error::siege_warfare_invalid_guild:
			out << "siege_warfare_invalid_guild"; 
			break;
		case mpe_error::siege_warfare_invalid_enter:
			out << "siege_warfare_invalid_enter"; 
			break;
		case mpe_error::siege_tower_gate_not_enable:
			out << "siege_tower_gate_not_enable"; 
			break;
		case mpe_error::siege_warfare_observer_full:
			out << "siege_warfare_observer_full"; 
			break;
		case mpe_error::castle_dungeon_not_changeable_value:
			out << "castle_dungeon_not_changeable_value"; 
			break;
		case mpe_error::castle_dungeon_same_old_entrance_fee:
			out << "castle_dungeon_same_old_entrance_fee"; 
			break;
		case mpe_error::castle_dungeon_configurable_max_value_excess:
			out << "castle_dungeon_configurable_max_value_excess"; 
			break;
		case mpe_error::castle_dungeon_not_found_castle:
			out << "castle_dungeon_not_found_castle"; 
			break;
		case mpe_error::castle_town_work_count_over:
			out << "castle_town_work_count_over"; 
			break;
		case mpe_error::castle_town_already_work:
			out << "castle_town_already_work"; 
			break;
		case mpe_error::castle_town_already_build:
			out << "castle_town_already_build"; 
			break;
		case mpe_error::castle_town_already_not_build:
			out << "castle_town_already_not_build"; 
			break;
		case mpe_error::castle_town_not_level:
			out << "castle_town_not_level"; 
			break;
		case mpe_error::castle_town_already_specialties_work:
			out << "castle_town_already_specialties_work"; 
			break;
		case mpe_error::castle_town_full_specialties_count:
			out << "castle_town_full_specialties_count"; 
			break;
		case mpe_error::castle_town_rental_short_of_guild_ranking:
			out << "castle_town_rental_short_of_guild_ranking"; 
			break;
		case mpe_error::castle_town_already_have:
			out << "castle_town_already_have"; 
			break;
		case mpe_error::castle_tax_not_change_day:
			out << "castle_tax_not_change_day"; 
			break;
		case mpe_error::siege_warface_aliiance_invalid_guild:
			out << "siege_warface_aliiance_invalid_guild"; 
			break;
		case mpe_error::castle_town_specialties_work_start_not_yet:
			out << "castle_town_specialties_work_start_not_yet"; 
			break;
		case mpe_error::siege_build_machine_same_set:
			out << "siege_build_machine_same_set"; 
			break;
		case mpe_error::castle_not_owner_zone:
			out << "castle_not_owner_zone"; 
			break;
		case mpe_error::castle_town_disable_enter:
			out << "castle_town_disable_enter"; 
			break;
		case mpe_error::castle_town_not_my_town:
			out << "castle_town_not_my_town"; 
			break;
		case mpe_error::castle_town_employ_count_over:
			out << "castle_town_employ_count_over"; 
			break;
		case mpe_error::castle_town_not_have:
			out << "castle_town_not_have"; 
			break;
		case mpe_error::castle_town_specialties_delivery_already_start:
			out << "castle_town_specialties_delivery_already_start"; 
			break;
		case mpe_error::castle_town_specialties_delivery_short_of_value:
			out << "castle_town_specialties_delivery_short_of_value"; 
			break;
		case mpe_error::castle_town_dinner_end_not_yet:
			out << "castle_town_dinner_end_not_yet"; 
			break;
		case mpe_error::castle_town_dinner_end_already:
			out << "castle_town_dinner_end_already"; 
			break;
		case mpe_error::castle_town_dinner_already_get_item:
			out << "castle_town_dinner_already_get_item"; 
			break;
		case mpe_error::guild_shipwar_not_request_time:
			out << "guild_shipwar_not_request_time"; 
			break;
		case mpe_error::guild_shipwar_not_request:
			out << "guild_shipwar_not_request"; 
			break;
		case mpe_error::guild_shipwar_request_auth:
			out << "guild_shipwar_request_auth"; 
			break;
		case mpe_error::guild_shipwar_not_matched:
			out << "guild_shipwar_not_matched"; 
			break;
		case mpe_error::guild_shipwar_already_request:
			out << "guild_shipwar_already_request"; 
			break;
		case mpe_error::guild_shipwar_not_match_team:
			out << "guild_shipwar_not_match_team"; 
			break;
		case mpe_error::guild_shipwar_team_member_is_full:
			out << "guild_shipwar_team_member_is_full"; 
			break;
		case mpe_error::lord_worship_count_short:
			out << "lord_worship_count_short"; 
			break;
		case mpe_error::lord_buff_already_use:
			out << "lord_buff_already_use"; 
			break;
		case mpe_error::lord_bless_point_short:
			out << "lord_bless_point_short"; 
			break;
		case mpe_error::lord_bless_auth_lord:
			out << "lord_bless_auth_lord"; 
			break;
		case mpe_error::lord_bless_buff_count_over:
			out << "lord_bless_buff_count_over"; 
			break;
		case mpe_error::illusion_only_owner_guild_allowed_enter:
			out << "illusion_only_owner_guild_allowed_enter"; 
			break;
		case mpe_error::illusion_used_all_the_entrance_time:
			out << "illusion_used_all_the_entrance_time"; 
			break;
		case mpe_error::illusion_can_not_charge_more_time:
			out << "illusion_can_not_charge_more_time"; 
			break;
		case mpe_error::illusion_can_not_enter:
			out << "illusion_can_not_enter"; 
			break;
		case mpe_error::seal_device_is_in_use:
			out << "seal_device_is_in_use"; 
			break;
		case mpe_error::seal_device_is_not_yet_available:
			out << "seal_device_is_not_yet_available"; 
			break;
		case mpe_error::arena_battle_matching_time_is_not:
			out << "arena_battle_matching_time_is_not"; 
			break;
		case mpe_error::arena_battle_matching_already_regist:
			out << "arena_battle_matching_already_regist"; 
			break;
		case mpe_error::arena_battle_matching_not_regist:
			out << "arena_battle_matching_not_regist"; 
			break;
		case mpe_error::arena_battle_not_exist_season_reward:
			out << "arena_battle_not_exist_season_reward"; 
			break;
		case mpe_error::arena_battle_matching_already_play:
			out << "arena_battle_matching_already_play"; 
			break;
		case mpe_error::arena_no_more_revive:
			out << "arena_no_more_revive"; 
			break;
		case mpe_error::illusion_rank_not_match_or_lack:
			out << "illusion_rank_not_match_or_lack"; 
			break;
		case mpe_error::illusion_not_open_time:
			out << "illusion_not_open_time"; 
			break;
		case mpe_error::secretvalley_cannot_teleport_to_playing:
			out << "secretvalley_cannot_teleport_to_playing"; 
			break;
		case mpe_error::secretvalley_cannot_teleport_not_occupation_guild:
			out << "secretvalley_cannot_teleport_not_occupation_guild"; 
			break;
		case mpe_error::secretvalley_blackiron_no_permission:
			out << "secretvalley_blackiron_no_permission"; 
			break;
		case mpe_error::secretvalley_blackiron_pay_minvalue:
			out << "secretvalley_blackiron_pay_minvalue"; 
			break;
		case mpe_error::secretvalley_blackiron_pay_otheruser_not_guildmember:
			out << "secretvalley_blackiron_pay_otheruser_not_guildmember"; 
			break;
		case mpe_error::secretvalley_blackiron_pay_not_enough:
			out << "secretvalley_blackiron_pay_not_enough"; 
			break;
		case mpe_error::secretvalley_blackiron_pay_1day_limit:
			out << "secretvalley_blackiron_pay_1day_limit"; 
			break;
		case mpe_error::secretvalley_not_learn_guild_skill_occupation:
			out << "secretvalley_not_learn_guild_skill_occupation"; 
			break;
		case mpe_error::secretvalley_defenceteam_already_join:
			out << "secretvalley_defenceteam_already_join"; 
			break;
		case mpe_error::secretvalley_configurable_max_value_excess:
			out << "secretvalley_configurable_max_value_excess"; 
			break;
		case mpe_error::secretvalley_storage_cannot_use:
			out << "secretvalley_storage_cannot_use"; 
			break;
		case mpe_error::secretvalley_storage_blackiron_save_max:
			out << "secretvalley_storage_blackiron_save_max"; 
			break;
		case mpe_error::skill_is_null:
			out << "skill_is_null"; 
			break;
		case mpe_error::skill_use_action:
			out << "skill_use_action"; 
			break;
		case mpe_error::skill_cool_time:
			out << "skill_cool_time"; 
			break;
		case mpe_error::skill_invalid_target:
			out << "skill_invalid_target"; 
			break;
		case mpe_error::skill_range_error:
			out << "skill_range_error"; 
			break;
		case mpe_error::skill_hp_lack:
			out << "skill_hp_lack"; 
			break;
		case mpe_error::skill_mp_lack:
			out << "skill_mp_lack"; 
			break;
		case mpe_error::skill_character_not_learn:
			out << "skill_character_not_learn"; 
			break;
		case mpe_error::skill_character_low_level:
			out << "skill_character_low_level"; 
			break;
		case mpe_error::skill_already_learned:
			out << "skill_already_learned"; 
			break;
		case mpe_error::skill_not_learn:
			out << "skill_not_learn"; 
			break;
		case mpe_error::skill_max_level:
			out << "skill_max_level"; 
			break;
		case mpe_error::skill_silence_state:
			out << "skill_silence_state"; 
			break;
		case mpe_error::skill_low_exp:
			out << "skill_low_exp"; 
			break;
		case mpe_error::skill_direction:
			out << "skill_direction"; 
			break;
		case mpe_error::skill_special_move_none:
			out << "skill_special_move_none"; 
			break;
		case mpe_error::skill_use_special_move_action:
			out << "skill_use_special_move_action"; 
			break;
		case mpe_error::skill_special_move_gage_lack:
			out << "skill_special_move_gage_lack"; 
			break;
		case mpe_error::skill_force_max_level:
			out << "skill_force_max_level"; 
			break;
		case mpe_error::skill_force_page_not_found:
			out << "skill_force_page_not_found"; 
			break;
		case mpe_error::skill_ability_fail_on_expand:
			out << "skill_ability_fail_on_expand"; 
			break;
		case mpe_error::skill_fail_add_buff:
			out << "skill_fail_add_buff"; 
			break;
		case mpe_error::db_fail_character_puid:
			out << "db_fail_character_puid"; 
			break;
		case mpe_error::db_fail_party_setup:
			out << "db_fail_party_setup"; 
			break;
		case mpe_error::party_already_joined:
			out << "party_already_joined"; 
			break;
		case mpe_error::party_unfavorable_user:
			out << "party_unfavorable_user"; 
			break;
		case mpe_error::party_not_invited_user:
			out << "party_not_invited_user"; 
			break;
		case mpe_error::party_not_leave_dungeon:
			out << "party_not_leave_dungeon"; 
			break;
		case mpe_error::party_not_disband_dungeon:
			out << "party_not_disband_dungeon"; 
			break;
		case mpe_error::party_not_found:
			out << "party_not_found"; 
			break;
		case mpe_error::party_no_owner_member:
			out << "party_no_owner_member"; 
			break;
		case mpe_error::party_member_full:
			out << "party_member_full"; 
			break;
		case mpe_error::party_vote_owner_cannot:
			out << "party_vote_owner_cannot"; 
			break;
		case mpe_error::party_target_not_owner:
			out << "party_target_not_owner"; 
			break;
		case mpe_error::party_vote_not_enough_member:
			out << "party_vote_not_enough_member"; 
			break;
		case mpe_error::party_already_voting:
			out << "party_already_voting"; 
			break;
		case mpe_error::party_not_voting:
			out << "party_not_voting"; 
			break;
		case mpe_error::party_not_joined:
			out << "party_not_joined"; 
			break;
		case mpe_error::party_already_vote_reply:
			out << "party_already_vote_reply"; 
			break;
		case mpe_error::party_not_joined_target:
			out << "party_not_joined_target"; 
			break;
		case mpe_error::party_owner_offline:
			out << "party_owner_offline"; 
			break;
		case mpe_error::party_owner_cannot_leave:
			out << "party_owner_cannot_leave"; 
			break;
		case mpe_error::party_cannot_join:
			out << "party_cannot_join"; 
			break;
		case mpe_error::party_cannot_change_dungeon_max_15_to_5:
			out << "party_cannot_change_dungeon_max_15_to_5"; 
			break;
		case mpe_error::party_cannot_change_max_15_to_5:
			out << "party_cannot_change_max_15_to_5"; 
			break;
		case mpe_error::party_enter_require_level_lack:
			out << "party_enter_require_level_lack"; 
			break;
		case mpe_error::party_enter_require_level_over:
			out << "party_enter_require_level_over"; 
			break;
		case mpe_error::character_level_higher_than_condition:
			out << "character_level_higher_than_condition"; 
			break;
		case mpe_error::character_level_lower_than_condition:
			out << "character_level_lower_than_condition"; 
			break;
		case mpe_error::nickname_is_too_long:
			out << "nickname_is_too_long"; 
			break;
		case mpe_error::indun_kick_by_lack_ticket:
			out << "indun_kick_by_lack_ticket"; 
			break;
		case mpe_error::not_available_during_dungeon_room:
			out << "not_available_during_dungeon_room"; 
			break;
		case mpe_error::party_member_cannot_room_create:
			out << "party_member_cannot_room_create"; 
			break;
		case mpe_error::party_member_cannot_room_join:
			out << "party_member_cannot_room_join"; 
			break;
		case mpe_error::not_exist_room:
			out << "not_exist_room"; 
			break;
		case mpe_error::room_invalid_auth:
			out << "room_invalid_auth"; 
			break;
		case mpe_error::room_is_full:
			out << "room_is_full"; 
			break;
		case mpe_error::room_already_joined:
			out << "room_already_joined"; 
			break;
		case mpe_error::room_cannot_join_in_party:
			out << "room_cannot_join_in_party"; 
			break;
		case mpe_error::party_teleport_not_area:
			out << "party_teleport_not_area"; 
			break;
		case mpe_error::party_governance_not_ready:
			out << "party_governance_not_ready"; 
			break;
		case mpe_error::party_governance_deny:
			out << "party_governance_deny"; 
			break;
		case mpe_error::party_governance_owner_deny:
			out << "party_governance_owner_deny"; 
			break;
		case mpe_error::party_governance_target_deny:
			out << "party_governance_target_deny"; 
			break;
		case mpe_error::party_governance_invite_owner_deny:
			out << "party_governance_invite_owner_deny"; 
			break;
		case mpe_error::party_governance_indun_prepare_owner_deny:
			out << "party_governance_indun_prepare_owner_deny"; 
			break;
		case mpe_error::db_fail_character_pk_setup:
			out << "db_fail_character_pk_setup"; 
			break;
		case mpe_error::offline_user:
			out << "offline_user"; 
			break;
		case mpe_error::character_is_notfound:
			out << "character_is_notfound"; 
			break;
		case mpe_error::account_is_notfound:
			out << "account_is_notfound"; 
			break;
		case mpe_error::item_not_repairable:
			out << "item_not_repairable"; 
			break;
		case mpe_error::item_not_recoveryable:
			out << "item_not_recoveryable"; 
			break;
		case mpe_error::item_durability_zero:
			out << "item_durability_zero"; 
			break;
		case mpe_error::mentor_already_register:
			out << "mentor_already_register"; 
			break;
		case mpe_error::mentor_not_mentor:
			out << "mentor_not_mentor"; 
			break;
		case mpe_error::mentor_not_in_the_request_list:
			out << "mentor_not_in_the_request_list"; 
			break;
		case mpe_error::mentor_not_in_the_receive_list:
			out << "mentor_not_in_the_receive_list"; 
			break;
		case mpe_error::mentor_already_mentor:
			out << "mentor_already_mentor"; 
			break;
		case mpe_error::mentor_lack_of_level:
			out << "mentor_lack_of_level"; 
			break;
		case mpe_error::mentor_level_over:
			out << "mentor_level_over"; 
			break;
		case mpe_error::mentor_receive_count_exceeded:
			out << "mentor_receive_count_exceeded"; 
			break;
		case mpe_error::mentor_request_count_exceeded:
			out << "mentor_request_count_exceeded"; 
			break;
		case mpe_error::mentor_already_request:
			out << "mentor_already_request"; 
			break;
		case mpe_error::mentor_same_account:
			out << "mentor_same_account"; 
			break;
		case mpe_error::mentor_can_not_apply_for_oneself:
			out << "mentor_can_not_apply_for_oneself"; 
			break;
		case mpe_error::mentor_time_limit_for_request:
			out << "mentor_time_limit_for_request"; 
			break;
		case mpe_error::mentor_excess_of_goods_mentor_point:
			out << "mentor_excess_of_goods_mentor_point"; 
			break;
		case mpe_error::mentor_level_conditions_incorrect:
			out << "mentor_level_conditions_incorrect"; 
			break;
		case mpe_error::mentor_not_found_character:
			out << "mentor_not_found_character"; 
			break;
		case mpe_error::mentor_requested_user_already_mentor:
			out << "mentor_requested_user_already_mentor"; 
			break;
		case mpe_error::mentor_opponent_time_limit_for_request:
			out << "mentor_opponent_time_limit_for_request"; 
			break;
		case mpe_error::expert_require_level_lack:
			out << "expert_require_level_lack"; 
			break;
		case mpe_error::expert_max_level_limited:
			out << "expert_max_level_limited"; 
			break;
		case mpe_error::expert_quest_is_not_completed:
			out << "expert_quest_is_not_completed"; 
			break;
		case mpe_error::expert_level_condition_not_match:
			out << "expert_level_condition_not_match"; 
			break;
		case mpe_error::expert_total_exp_lack:
			out << "expert_total_exp_lack"; 
			break;
		case mpe_error::expert_equipment_already_exist:
			out << "expert_equipment_already_exist"; 
			break;
		case mpe_error::expert_equipment_already_equip:
			out << "expert_equipment_already_equip"; 
			break;
		case mpe_error::expert_equipment_already_unequip:
			out << "expert_equipment_already_unequip"; 
			break;
		case mpe_error::expert_equipment_target_not_exist:
			out << "expert_equipment_target_not_exist"; 
			break;
		case mpe_error::expert_equipment_max_reinforce_lv:
			out << "expert_equipment_max_reinforce_lv"; 
			break;
		case mpe_error::expert_equipment_enchant_stone_already_equip:
			out << "expert_equipment_enchant_stone_already_equip"; 
			break;
		case mpe_error::expert_equipment_enchant_stone_already_unequip:
			out << "expert_equipment_enchant_stone_already_unequip"; 
			break;
		case mpe_error::expert_equipment_invalid_slot:
			out << "expert_equipment_invalid_slot"; 
			break;
		case mpe_error::expert_equipment_not_open_slot:
			out << "expert_equipment_not_open_slot"; 
			break;
		case mpe_error::pet_max_feed:
			out << "pet_max_feed"; 
			break;
		case mpe_error::pet_not_equip_first:
			out << "pet_not_equip_first"; 
			break;
		case mpe_error::pet_summon_duplicate:
			out << "pet_summon_duplicate"; 
			break;
		case mpe_error::friend_aleady_state:
			out << "friend_aleady_state"; 
			break;
		case mpe_error::friend_aleady_request:
			out << "friend_aleady_request"; 
			break;
		case mpe_error::friend_delete_user_not_found:
			out << "friend_delete_user_not_found"; 
			break;
		case mpe_error::friend_mine_max_full:
			out << "friend_mine_max_full"; 
			break;
		case mpe_error::friend_target_max_full:
			out << "friend_target_max_full"; 
			break;
		case mpe_error::friend_req_max_full:
			out << "friend_req_max_full"; 
			break;
		case mpe_error::friend_reqed_max_full:
			out << "friend_reqed_max_full"; 
			break;
		case mpe_error::friend_cannot_request_myself:
			out << "friend_cannot_request_myself"; 
			break;
		case mpe_error::wanted_murder_still_being_processed:
			out << "wanted_murder_still_being_processed"; 
			break;
		case mpe_error::wanted_murder_already_been_rewarded:
			out << "wanted_murder_already_been_rewarded"; 
			break;
		case mpe_error::wanted_murder_not_user_reward:
			out << "wanted_murder_not_user_reward"; 
			break;
		case mpe_error::wanted_murder_not_found:
			out << "wanted_murder_not_found"; 
			break;
		case mpe_error::wanted_murder_already_register:
			out << "wanted_murder_already_register"; 
			break;
		case mpe_error::wanted_murder_already_accept:
			out << "wanted_murder_already_accept"; 
			break;
		case mpe_error::wanted_murder_user_not_register:
			out << "wanted_murder_user_not_register"; 
			break;
		case mpe_error::wanted_murder_user_register:
			out << "wanted_murder_user_register"; 
			break;
		case mpe_error::wanted_murder_already_all_accept:
			out << "wanted_murder_already_all_accept"; 
			break;
		case mpe_error::wanted_murder_use_all_count:
			out << "wanted_murder_use_all_count"; 
			break;
		case mpe_error::wanted_murder_not_found_pk_list:
			out << "wanted_murder_not_found_pk_list"; 
			break;
		case mpe_error::wanted_murder_maximum_register_count:
			out << "wanted_murder_maximum_register_count"; 
			break;
		case mpe_error::wanted_murder_maximum_same_user:
			out << "wanted_murder_maximum_same_user"; 
			break;
		case mpe_error::wanted_murder_less_than_the_minimum:
			out << "wanted_murder_less_than_the_minimum"; 
			break;
		case mpe_error::can_not_auto_battle:
			out << "can_not_auto_battle"; 
			break;
		case mpe_error::event_can_not_get_any_more:
			out << "event_can_not_get_any_more"; 
			break;
		case mpe_error::event_ended:
			out << "event_ended"; 
			break;
		case mpe_error::event_already_reward:
			out << "event_already_reward"; 
			break;
		case mpe_error::event_not_target_in_event:
			out << "event_not_target_in_event"; 
			break;
		case mpe_error::event_invalid_request:
			out << "event_invalid_request"; 
			break;
		case mpe_error::event_that_has_not_been_achieved_yet:
			out << "event_that_has_not_been_achieved_yet"; 
			break;
		case mpe_error::not_found_observer_chracter:
			out << "not_found_observer_chracter"; 
			break;
		case mpe_error::invalid_observer_mode_character_action:
			out << "invalid_observer_mode_character_action"; 
			break;
		case mpe_error::can_not_equip_reflection_for_during_battle_mode :
			out << "can_not_equip_reflection_for_during_battle_mode "; 
			break;
		case mpe_error::can_not_change_it_yet:
			out << "can_not_change_it_yet"; 
			break;
		case mpe_error::not_secretvalley_join_cannot_enter_map:
			out << "not_secretvalley_join_cannot_enter_map"; 
			break;
		case mpe_error::secretvalley_time_cannot_guild_join:
			out << "secretvalley_time_cannot_guild_join"; 
			break;
		case mpe_error::secretvalley_time_cannot_guild_disband:
			out << "secretvalley_time_cannot_guild_disband"; 
			break;
		case mpe_error::secretvalley_time_cannot_guild_member_expulsion:
			out << "secretvalley_time_cannot_guild_member_expulsion"; 
			break;
		case mpe_error::secretvalley_time_cannot_guild_dungeon_open:
			out << "secretvalley_time_cannot_guild_dungeon_open"; 
			break;
		case mpe_error::secretvalley_time_cannot_guild_dungeon_enter:
			out << "secretvalley_time_cannot_guild_dungeon_enter"; 
			break;
		case mpe_error::secretvalley_blackironbox_not_input_time:
			out << "secretvalley_blackironbox_not_input_time"; 
			break;
		case mpe_error::secretvalley_blackironbox_not_output_time:
			out << "secretvalley_blackironbox_not_output_time"; 
			break;
		case mpe_error::secretvalley_blackironbox_not_input_different_item:
			out << "secretvalley_blackironbox_not_input_different_item"; 
			break;
		case mpe_error::governance_not_participation_qualification:
			out << "governance_not_participation_qualification"; 
			break;
		case mpe_error::pk_exhausted_the_number_of_registrations:
			out << "pk_exhausted_the_number_of_registrations"; 
			break;
		case mpe_error::pk_not_found_cuid:
			out << "pk_not_found_cuid"; 
			break;
		case mpe_error::pk_revenge_already_registered:
			out << "pk_revenge_already_registered"; 
			break;
		case mpe_error::pk_not_found_revenge:
			out << "pk_not_found_revenge"; 
			break;
		case mpe_error::street_stall_lack_level:
			out << "street_stall_lack_level"; 
			break;
		case mpe_error::street_stall_lack_rank:
			out << "street_stall_lack_rank"; 
			break;
		case mpe_error::street_stall_lack_use_count:
			out << "street_stall_lack_use_count"; 
			break;
		case mpe_error::street_stall_lack_recipe_count:
			out << "street_stall_lack_recipe_count"; 
			break;
		case mpe_error::street_stall_disable_mandala:
			out << "street_stall_disable_mandala"; 
			break;
		case mpe_error::street_stall_account_character_duplication:
			out << "street_stall_account_character_duplication"; 
			break;
		case mpe_error::street_stall_not_vacancy_place:
			out << "street_stall_not_vacancy_place"; 
			break;
		case mpe_error::duplicate_potion_buff:
			out << "duplicate_potion_buff"; 
			break;
		case mpe_error::global_exchange_item_buy_system_error:
			out << "global_exchange_item_buy_system_error"; 
			break;
		case mpe_error::global_exchange_item_sellstate_not_sell:
			out << "global_exchange_item_sellstate_not_sell"; 
			break;
		case mpe_error::global_exchange_item_buy_result_system_error:
			out << "global_exchange_item_buy_result_system_error"; 
			break;
		case mpe_error::event_restore_not_period:
			out << "event_restore_not_period"; 
			break;
		case mpe_error::event_restore_not_have:
			out << "event_restore_not_have"; 
			break;
		case mpe_error::event_restore_error:
			out << "event_restore_error"; 
			break;
		case mpe_error::event_restore_item_not_have:
			out << "event_restore_item_not_have"; 
			break;
		case mpe_error::equipment_awaken_invalid_awaken_step:
			out << "equipment_awaken_invalid_awaken_step"; 
			break;
		case mpe_error::equipment_awaken_not_enough_character_expert_condition:
			out << "equipment_awaken_not_enough_character_expert_condition"; 
			break;
		case mpe_error::equipment_awaken_cannot_awakend:
			out << "equipment_awaken_cannot_awakend"; 
			break;
		case mpe_error::equipment_awaken_not_material_equip_of_same_parts:
			out << "equipment_awaken_not_material_equip_of_same_parts"; 
			break;
		case mpe_error::equipment_awaken_first_awaken_has_not_been_finished:
			out << "equipment_awaken_first_awaken_has_not_been_finished"; 
			break;
		case mpe_error::equipment_awaken_second_awaken_already_finished:
			out << "equipment_awaken_second_awaken_already_finished"; 
			break;
		case mpe_error::equipment_awaken_not_enough_character_level_cnodition:
			out << "equipment_awaken_not_enough_character_level_cnodition"; 
			break;
		case mpe_error::equipment_awaken_not_enough_equip_reinforce_level_cnodition:
			out << "equipment_awaken_not_enough_equip_reinforce_level_cnodition"; 
			break;
		case mpe_error::equipment_awaken_not_enough_equipment_awaken_goods:
			out << "equipment_awaken_not_enough_equipment_awaken_goods"; 
			break;
		case mpe_error::equipment_awaken_cannot_be_used_material:
			out << "equipment_awaken_cannot_be_used_material"; 
			break;
		case mpe_error::equipment_awaken_cannot_confirmed_option:
			out << "equipment_awaken_cannot_confirmed_option"; 
			break;
		case mpe_error::occupationwar_challenge_unqualified:
			out << "occupationwar_challenge_unqualified"; 
			break;
		case mpe_error::occupationwar_challenge_existence:
			out << "occupationwar_challenge_existence"; 
			break;
		case mpe_error::occupationwar_challenge_never_applied:
			out << "occupationwar_challenge_never_applied"; 
			break;
		case mpe_error::occupationwar_challenge_not_possible_time:
			out << "occupationwar_challenge_not_possible_time"; 
			break;
		case mpe_error::token_history_item_get_failed:
			out << "token_history_item_get_failed"; 
			break;
		case mpe_error::contract_invalid_token:
			out << "contract_invalid_token"; 
			break;
		case mpe_error::contract_invalid_wallet_address:
			out << "contract_invalid_wallet_address"; 
			break;
		case mpe_error::contract_fail_darksteelbox_to_token:
			out << "contract_fail_darksteelbox_to_token"; 
			break;
		case mpe_error::contract_fail_token_to_darksteelbox:
			out << "contract_fail_token_to_darksteelbox"; 
			break;
		case mpe_error::refinery_not_available_no_darksteel_license:
			out << "refinery_not_available_no_darksteel_license"; 
			break;
		case mpe_error::boss_governance_staking_not_available_time:
			out << "boss_governance_staking_not_available_time"; 
			break;
		case mpe_error::boss_governance_unstaking_not_available_time:
			out << "boss_governance_unstaking_not_available_time"; 
			break;
		case mpe_error::boss_governance_not_linked_wallet_account:
			out << "boss_governance_not_linked_wallet_account"; 
			break;
		case mpe_error::boss_governance_staking_server_id_abnormal:
			out << "boss_governance_staking_server_id_abnormal"; 
			break;
		case mpe_error::boss_governance_unstaking_server_id_abnormal:
			out << "boss_governance_unstaking_server_id_abnormal"; 
			break;
		case mpe_error::boss_governance_unstaking_not_available_staking_cooltime:
			out << "boss_governance_unstaking_not_available_staking_cooltime"; 
			break;
		case mpe_error::boss_governance_unstaking_not_available_unstaking_cooltime:
			out << "boss_governance_unstaking_not_available_unstaking_cooltime"; 
			break;
		case mpe_error::boss_governance_staking_success:
			out << "boss_governance_staking_success"; 
			break;
		case mpe_error::boss_governance_unstaking_success:
			out << "boss_governance_unstaking_success"; 
			break;
		case mpe_error::boss_governance_staking_fail:
			out << "boss_governance_staking_fail"; 
			break;
		case mpe_error::boss_governance_unstaking_fail:
			out << "boss_governance_unstaking_fail"; 
			break;
		case mpe_error::divine_staking_staking_transaction_fail:
			out << "divine_staking_staking_transaction_fail"; 
			break;
		case mpe_error::dinvine_staking_claim_transaction_fail:
			out << "dinvine_staking_claim_transaction_fail"; 
			break;
		case mpe_error::trade_darksteel_to_token_transaction_fail:
			out << "trade_darksteel_to_token_transaction_fail"; 
			break;
		case mpe_error::trade_token_to_darksteel_transaction_fail:
			out << "trade_token_to_darksteel_transaction_fail"; 
			break;
		case mpe_error::unstaking_amount_big_error:
			out << "unstaking_amount_big_error"; 
			break;
		case mpe_error::not_linked_wallet_account:
			out << "not_linked_wallet_account"; 
			break;
		case mpe_error::wallet_address_empty_exchange_item:
			out << "wallet_address_empty_exchange_item"; 
			break;
		case mpe_error::wallet_address_different_withdraw_gold:
			out << "wallet_address_different_withdraw_gold"; 
			break;
		case mpe_error::goldexchange_trade_item_does_not_have:
			out << "goldexchange_trade_item_does_not_have"; 
			break;
		case mpe_error::divine_staking_claim_cool_time:
			out << "divine_staking_claim_cool_time"; 
			break;
		case mpe_error::approve_make_fail:
			out << "approve_make_fail"; 
			break;
		case mpe_error::approve_send_fail:
			out << "approve_send_fail"; 
			break;
		case mpe_error::contract_wallet_login_fail:
			out << "contract_wallet_login_fail"; 
			break;
		case mpe_error::contract_wallet_verify_fail:
			out << "contract_wallet_verify_fail"; 
			break;
		case mpe_error::contract_wallet_invalid_address:
			out << "contract_wallet_invalid_address"; 
			break;
		case mpe_error::contract_wallet_duplicate_wallet:
			out << "contract_wallet_duplicate_wallet"; 
			break;
		case mpe_error::exchange_Items_not_available_for_purchase:
			out << "exchange_Items_not_available_for_purchase"; 
			break;
		case mpe_error::governance_sector_info_overlapped:
			out << "governance_sector_info_overlapped"; 
			break;
		case mpe_error::wemix_shop_error:
			out << "wemix_shop_error"; 
			break;
		case mpe_error::wemix_shop_start_error:
			out << "wemix_shop_start_error"; 
			break;
		case mpe_error::wemix_shop_end_error:
			out << "wemix_shop_end_error"; 
			break;
		case mpe_error::wemix_shop_end_api_error:
			out << "wemix_shop_end_api_error"; 
			break;
		case mpe_error::wemix_shop_start_api_error:
			out << "wemix_shop_start_api_error"; 
			break;
		case mpe_error::wemix_shop_end_incorrect_user_address:
			out << "wemix_shop_end_incorrect_user_address"; 
			break;
		case mpe_error::wemix_shop_end_transaction_error:
			out << "wemix_shop_end_transaction_error"; 
			break;
		case mpe_error::wemix_shop_not_buy_date:
			out << "wemix_shop_not_buy_date"; 
			break;
		case mpe_error::wemix_shop_max_amount_buy_item:
			out << "wemix_shop_max_amount_buy_item"; 
			break;
		case mpe_error::wemix_shop_step_package_error:
			out << "wemix_shop_step_package_error"; 
			break;
		case mpe_error::wemix_shop_incorrect_buy_item:
			out << "wemix_shop_incorrect_buy_item"; 
			break;
		case mpe_error::party_governance_not_available_delete_character:
			out << "party_governance_not_available_delete_character"; 
			break;
		case mpe_error::ad_not_ready:
			out << "ad_not_ready"; 
			break;
		case mpe_error::ad_lack_view_count:
			out << "ad_lack_view_count"; 
			break;
		case mpe_error::ad_lack_event_reward:
			out << "ad_lack_event_reward"; 
			break;
		case mpe_error::ad_lack_exp_restore:
			out << "ad_lack_exp_restore"; 
			break;
		case mpe_error::wmm_api_ad_not_found:
			out << "wmm_api_ad_not_found"; 
			break;
		case mpe_error::wmm_api_ad_already_process:
			out << "wmm_api_ad_already_process"; 
			break;
		case mpe_error::account_event_not_comeback_user:
			out << "account_event_not_comeback_user"; 
			break;
		case mpe_error::not_available_charage_subscription_limit_time:
			out << "not_available_charage_subscription_limit_time"; 
			break;
		case mpe_error::not_map_bind_buff:
			out << "not_map_bind_buff"; 
			break;
		case mpe_error::blood_dedicate_complete:
			out << "blood_dedicate_complete"; 
			break;
		case mpe_error::blood_dedicate_complete_unknown_player:
			out << "blood_dedicate_complete_unknown_player"; 
			break;
		case mpe_error::not_enough_goods_to_do_blood_dedicate:
			out << "not_enough_goods_to_do_blood_dedicate"; 
			break;
		case mpe_error::not_blood_dedicate_worldboss_summoned:
			out << "not_blood_dedicate_worldboss_summoned"; 
			break;
		case mpe_error::not_blood_dedicate_worldboss_spawn_zone:
			out << "not_blood_dedicate_worldboss_spawn_zone"; 
			break;
		case mpe_error::blood_stone_point_is_max:
			out << "blood_stone_point_is_max"; 
			break;
		case mpe_error::not_register_blood_dedicate_worldboss:
			out << "not_register_blood_dedicate_worldboss"; 
			break;
		case mpe_error::season_mandala_not_open:
			out << "season_mandala_not_open"; 
			break;
		case mpe_error::season_mandala_is_null_object:
			out << "season_mandala_is_null_object"; 
			break;
		case mpe_error::invalid_mandala_type:
			out << "invalid_mandala_type"; 
			break;
		case mpe_error::season_mandala_not_activate_same_layer_differnet_plate:
			out << "season_mandala_not_activate_same_layer_differnet_plate"; 
			break;
		case mpe_error::season_mandala_expert_type_condition_error:
			out << "season_mandala_expert_type_condition_error"; 
			break;
		case mpe_error::season_mandala_info_condition_error:
			out << "season_mandala_info_condition_error"; 
			break;
		case mpe_error::season_mandala_slotnode_levelup_impossible:
			out << "season_mandala_slotnode_levelup_impossible"; 
			break;
		case mpe_error::season_mandala_season_info_error:
			out << "season_mandala_season_info_error"; 
			break;
		case mpe_error::season_mandala_reward_already_received:
			out << "season_mandala_reward_already_received"; 
			break;
		case mpe_error::indun_create_full:
			out << "indun_create_full"; 
			break;
		case mpe_error::indun_not_exist:
			out << "indun_not_exist"; 
			break;
		case mpe_error::joined_the_party:
			out << "joined_the_party"; 
			break;
		case mpe_error::not_join_the_party:
			out << "not_join_the_party"; 
			break;
		case mpe_error::goods_selection_incorrect:
			out << "goods_selection_incorrect"; 
			break;
		case mpe_error::use_daily_plays_count:
			out << "use_daily_plays_count"; 
			break;
		case mpe_error::can_not_change_pksetup:
			out << "can_not_change_pksetup"; 
			break;
		case mpe_error::users_whose_conditions_not_met:
			out << "users_whose_conditions_not_met"; 
			break;
		case mpe_error::can_not_auto_matching:
			out << "can_not_auto_matching"; 
			break;
		case mpe_error::not_available_during_dungeon_voting:
			out << "not_available_during_dungeon_voting"; 
			break;
		case mpe_error::not_available_during_dungeon_matching:
			out << "not_available_during_dungeon_matching"; 
			break;
		case mpe_error::can_not_use_in_dungeon:
			out << "can_not_use_in_dungeon"; 
			break;
		case mpe_error::indun_enter_vote_cancel:
			out << "indun_enter_vote_cancel"; 
			break;
		case mpe_error::guild_town_boss_already_spawn:
			out << "guild_town_boss_already_spawn"; 
			break;
		case mpe_error::indun_already_clear:
			out << "indun_already_clear"; 
			break;
		case mpe_error::indun_not_time_to_enter:
			out << "indun_not_time_to_enter"; 
			break;
		case mpe_error::can_not_use_in_dungeon_party_member:
			out << "can_not_use_in_dungeon_party_member"; 
			break;
		case mpe_error::contract_fail_darksteelbox_to_token_count:
			out << "contract_fail_darksteelbox_to_token_count"; 
			break;
		case mpe_error::worldserver_cannot_enter:
			out << "worldserver_cannot_enter"; 
			break;
		case mpe_error::worldserver_Contents_lock:
			out << "worldserver_Contents_lock"; 
			break;
		case mpe_error::worldserver_anatherserver_cannot_party:
			out << "worldserver_anatherserver_cannot_party"; 
			break;
		case mpe_error::worldserver_anatherserver_cannot_friend:
			out << "worldserver_anatherserver_cannot_friend"; 
			break;
		case mpe_error::indun_monarch_box_remains:
			out << "indun_monarch_box_remains"; 
			break;
		case mpe_error::redis_system_error:
			out << "redis_system_error"; 
			break;
		case mpe_error::redis_data_nil:
			out << "redis_data_nil"; 
			break;
		case mpe_error::db_system_error:
			out << "db_system_error"; 
			break;
		case mpe_error::db_duplicate_data_save:
			out << "db_duplicate_data_save"; 
			break;
		case mpe_error::invalid_packet:
			out << "invalid_packet"; 
			break;
		case mpe_error::duplicate_login_close:
			out << "duplicate_login_close"; 
			break;
		case mpe_error::notfound_table_info:
			out << "notfound_table_info"; 
			break;
		case mpe_error::system_error_relogin:
			out << "system_error_relogin"; 
			break;
		case mpe_error::system_processing_job:
			out << "system_processing_job"; 
			break;
		case mpe_error::table_data_error:
			out << "table_data_error"; 
			break;
		case mpe_error::permission_denied:
			out << "permission_denied"; 
			break;
		case mpe_error::rpc_notfound_server:
			out << "rpc_notfound_server"; 
			break;
		case mpe_error::rpc_send_system_error:
			out << "rpc_send_system_error"; 
			break;
		case mpe_error::monarch_timespace_season_out:
			out << "monarch_timespace_season_out"; 
			break;
		case mpe_error::invalid_monarch_timespace_item:
			out << "invalid_monarch_timespace_item"; 
			break;
		case mpe_error::short_of_monarch_timespace_level:
			out << "short_of_monarch_timespace_level"; 
			break;
		case mpe_error::not_found_monarch_timespace_ability:
			out << "not_found_monarch_timespace_ability"; 
			break;
		case mpe_error::monarch_timespace_already_max:
			out << "monarch_timespace_already_max"; 
			break;
		case mpe_error::server_relocation_revive_list_is_exists:
			out << "server_relocation_revive_list_is_exists"; 
			break;
		case mpe_error::server_relocation_not_processing_location:
			out << "server_relocation_not_processing_location"; 
			break;
		case mpe_error::server_relocation_is_exist_party:
			out << "server_relocation_is_exist_party"; 
			break;
		case mpe_error::server_relocation_is_exist_cash_shop_cart:
			out << "server_relocation_is_exist_cash_shop_cart"; 
			break;
		case mpe_error::server_relocation_is_exist_mail_box:
			out << "server_relocation_is_exist_mail_box"; 
			break;
		case mpe_error::server_relocation_is_exist_party_governance_staking:
			out << "server_relocation_is_exist_party_governance_staking"; 
			break;
		case mpe_error::server_relocation_lower_level:
			out << "server_relocation_lower_level"; 
			break;
		case mpe_error::server_relocation_is_exist_street_stall:
			out << "server_relocation_is_exist_street_stall"; 
			break;
		case mpe_error::server_relocation_same_gid:
			out << "server_relocation_same_gid"; 
			break;
		case mpe_error::server_relocation_server_is_busy:
			out << "server_relocation_server_is_busy"; 
			break;
		case mpe_error::server_relocation_server_cannot_relocated:
			out << "server_relocation_server_cannot_relocated"; 
			break;
		case mpe_error::server_relocation_server_cannot_execute_time:
			out << "server_relocation_server_cannot_execute_time"; 
			break;
		case mpe_error::server_relocation_server_cool_time:
			out << "server_relocation_server_cool_time"; 
			break;
		case mpe_error::server_relocation_db_data_is_null:
			out << "server_relocation_db_data_is_null"; 
			break;
		case mpe_error::server_relocation_max_user_count:
			out << "server_relocation_max_user_count"; 
			break;
		case mpe_error::gm_server_not_found:
			out << "gm_server_not_found"; 
			break;
		case mpe_error::gm_input_login_info:
			out << "gm_input_login_info"; 
			break;
		case mpe_error::gm_user_login_failed:
			out << "gm_user_login_failed"; 
			break;
		case mpe_error::gm_user_access_wrong:
			out << "gm_user_access_wrong"; 
			break;
		case mpe_error::gm_user_access_timeout:
			out << "gm_user_access_timeout"; 
			break;
		case mpe_error::gm_permission_denied:
			out << "gm_permission_denied"; 
			break;
		case mpe_error::gm_select_server:
			out << "gm_select_server"; 
			break;
		case mpe_error::gm_group_info_wrong:
			out << "gm_group_info_wrong"; 
			break;
		case mpe_error::gm_table_file_notfound:
			out << "gm_table_file_notfound"; 
			break;
		case mpe_error::gm_patch_file_notfound:
			out << "gm_patch_file_notfound"; 
			break;
		case mpe_error::gm_account_name_empty:
			out << "gm_account_name_empty"; 
			break;
		case mpe_error::gm_account_password_empty:
			out << "gm_account_password_empty"; 
			break;
		case mpe_error::gm_account_uid_empty:
			out << "gm_account_uid_empty"; 
			break;
		case mpe_error::gm_username_empty:
			out << "gm_username_empty"; 
			break;
		case mpe_error::gm_warrior_nickname_empty:
			out << "gm_warrior_nickname_empty"; 
			break;
		case mpe_error::gm_taoist_nickname_empty:
			out << "gm_taoist_nickname_empty"; 
			break;
		case mpe_error::gm_wizard_nickname_empty:
			out << "gm_wizard_nickname_empty"; 
			break;
		case mpe_error::gm_warrior_nickname_overlap:
			out << "gm_warrior_nickname_overlap"; 
			break;
		case mpe_error::gm_taoist_nickname_overlap:
			out << "gm_taoist_nickname_overlap"; 
			break;
		case mpe_error::gm_wizard_nickname_overlap:
			out << "gm_wizard_nickname_overlap"; 
			break;
		case mpe_error::gm_not_save_data:
			out << "gm_not_save_data"; 
			break;
		case mpe_error::packet_error:
			out << "packet_error"; 
			break;
		case mpe_error::system_error:
			out << "system_error"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_state& value)
	{
		switch (value)
		{
		case mpe_state::under_maintenance:
			out << "under_maintenance"; 
			break;
		case mpe_state::free:
			out << "free"; 
			break;
		case mpe_state::busy:
			out << "busy"; 
			break;
		case mpe_state::full:
			out << "full"; 
			break;
		case mpe_state::cannot_move:
			out << "cannot_move"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_item_option_enchant& value)
	{
		switch (value)
		{
		case mpe_item_option_enchant::none:
			out << "none"; 
			break;
		case mpe_item_option_enchant::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_item_flag& value)
	{
		switch (value)
		{
		case mpe_item_flag::none:
			out << "none"; 
			break;
		case mpe_item_flag::stone:
			out << "stone"; 
			break;
		case mpe_item_flag::item:
			out << "item"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_item_enchant_option_make_flag& value)
	{
		switch (value)
		{
		case mpe_item_enchant_option_make_flag::make_one:
			out << "make_one"; 
			break;
		case mpe_item_enchant_option_make_flag::make_five:
			out << "make_five"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_object_collect_flag& value)
	{
		switch (value)
		{
		case mpe_object_collect_flag::none:
			out << "none"; 
			break;
		case mpe_object_collect_flag::start:
			out << "start"; 
			break;
		case mpe_object_collect_flag::finish:
			out << "finish"; 
			break;
		case mpe_object_collect_flag::cancel:
			out << "cancel"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_item_add_type& value)
	{
		switch (value)
		{
		case mpe_item_add_type::none:
			out << "none"; 
			break;
		case mpe_item_add_type::buy:
			out << "buy"; 
			break;
		case mpe_item_add_type::drop:
			out << "drop"; 
			break;
		case mpe_item_add_type::option:
			out << "option"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_guild_donation_type& value)
	{
		switch (value)
		{
		case mpe_guild_donation_type::gold:
			out << "gold"; 
			break;
		case mpe_guild_donation_type::blackiron:
			out << "blackiron"; 
			break;
		case mpe_guild_donation_type::goldingot:
			out << "goldingot"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_storage_goods_move& value)
	{
		switch (value)
		{
		case mpe_storage_goods_move::none:
			out << "none"; 
			break;
		case mpe_storage_goods_move::toStorage:
			out << "toStorage"; 
			break;
		case mpe_storage_goods_move::toCharacter:
			out << "toCharacter"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_indun_enter_type& value)
	{
		switch (value)
		{
		case mpe_indun_enter_type::none:
			out << "none"; 
			break;
		case mpe_indun_enter_type::direct:
			out << "direct"; 
			break;
		case mpe_indun_enter_type::auto_matching:
			out << "auto_matching"; 
			break;
		case mpe_indun_enter_type::siege_def_team:
			out << "siege_def_team"; 
			break;
		case mpe_indun_enter_type::siege_atk_team:
			out << "siege_atk_team"; 
			break;
		case mpe_indun_enter_type::siege_observer:
			out << "siege_observer"; 
			break;
		case mpe_indun_enter_type::summon:
			out << "summon"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_personal_trade_state& value)
	{
		switch (value)
		{
		case mpe_personal_trade_state::none:
			out << "none"; 
			break;
		case mpe_personal_trade_state::wait:
			out << "wait"; 
			break;
		case mpe_personal_trade_state::trade:
			out << "trade"; 
			break;
		case mpe_personal_trade_state::trade_lock:
			out << "trade_lock"; 
			break;
		case mpe_personal_trade_state::confirm:
			out << "confirm"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_item_durability_decrement_type& value)
	{
		switch (value)
		{
		case mpe_item_durability_decrement_type::none:
			out << "none"; 
			break;
		case mpe_item_durability_decrement_type::attack:
			out << "attack"; 
			break;
		case mpe_item_durability_decrement_type::hit:
			out << "hit"; 
			break;
		case mpe_item_durability_decrement_type::dead:
			out << "dead"; 
			break;
		case mpe_item_durability_decrement_type::mining:
			out << "mining"; 
			break;
		case mpe_item_durability_decrement_type::logging:
			out << "logging"; 
			break;
		case mpe_item_durability_decrement_type::fishing:
			out << "fishing"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_item_durability_repair_type& value)
	{
		switch (value)
		{
		case mpe_item_durability_repair_type::none:
			out << "none"; 
			break;
		case mpe_item_durability_repair_type::repair:
			out << "repair"; 
			break;
		case mpe_item_durability_repair_type::recovery:
			out << "recovery"; 
			break;
		case mpe_item_durability_repair_type::repair_all:
			out << "repair_all"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_daily_reset_time_type& value)
	{
		switch (value)
		{
		case mpe_daily_reset_time_type::none:
			out << "none"; 
			break;
		case mpe_daily_reset_time_type::repute_quest_finish_count:
			out << "repute_quest_finish_count"; 
			break;
		case mpe_daily_reset_time_type::repute_quest_daily:
			out << "repute_quest_daily"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_db_skill_type& value)
	{
		switch (value)
		{
		case mpe_db_skill_type::none:
			out << "none"; 
			break;
		case mpe_db_skill_type::active:
			out << "active"; 
			break;
		case mpe_db_skill_type::passive_force:
			out << "passive_force"; 
			break;
		case mpe_db_skill_type::special_move:
			out << "special_move"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_guild_war_state& value)
	{
		switch (value)
		{
		case mpe_guild_war_state::in_progress:
			out << "in_progress"; 
			break;
		case mpe_guild_war_state::finished:
			out << "finished"; 
			break;
		case mpe_guild_war_state::negotiating:
			out << "negotiating"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_guild_join_type& value)
	{
		switch (value)
		{
		case mpe_guild_join_type::free_join:
			out << "free_join"; 
			break;
		case mpe_guild_join_type::need_accept:
			out << "need_accept"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_redirect_type& value)
	{
		switch (value)
		{
		case mpe_redirect_type::none:
			out << "none"; 
			break;
		case mpe_redirect_type::zone:
			out << "zone"; 
			break;
		case mpe_redirect_type::indun:
			out << "indun"; 
			break;
		case mpe_redirect_type::party_teleport:
			out << "party_teleport"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_siege_warfare_state& value)
	{
		switch (value)
		{
		case mpe_siege_warfare_state::none:
			out << "none"; 
			break;
		case mpe_siege_warfare_state::wait:
			out << "wait"; 
			break;
		case mpe_siege_warfare_state::tender:
			out << "tender"; 
			break;
		case mpe_siege_warfare_state::tender_finish:
			out << "tender_finish"; 
			break;
		case mpe_siege_warfare_state::prepare:
			out << "prepare"; 
			break;
		case mpe_siege_warfare_state::prepare_finish:
			out << "prepare_finish"; 
			break;
		case mpe_siege_warfare_state::enter:
			out << "enter"; 
			break;
		case mpe_siege_warfare_state::enter_finish:
			out << "enter_finish"; 
			break;
		case mpe_siege_warfare_state::battle:
			out << "battle"; 
			break;
		case mpe_siege_warfare_state::battle_finish:
			out << "battle_finish"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_siege_castle_type& value)
	{
		switch (value)
		{
		case mpe_siege_castle_type::none:
			out << "none"; 
			break;
		case mpe_siege_castle_type::sabuk:
			out << "sabuk"; 
			break;
		case mpe_siege_castle_type::kilung:
			out << "kilung"; 
			break;
		case mpe_siege_castle_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_siege_submit_tender_result& value)
	{
		switch (value)
		{
		case mpe_siege_submit_tender_result::error:
			out << "error"; 
			break;
		case mpe_siege_submit_tender_result::ok:
			out << "ok"; 
			break;
		case mpe_siege_submit_tender_result::change_tender:
			out << "change_tender"; 
			break;
		case mpe_siege_submit_tender_result::lack_money:
			out << "lack_money"; 
			break;
		case mpe_siege_submit_tender_result::no_permission:
			out << "no_permission"; 
			break;
		case mpe_siege_submit_tender_result::already_first:
			out << "already_first"; 
			break;
		case mpe_siege_submit_tender_result::lack_level:
			out << "lack_level"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_siege_alert_type& value)
	{
		switch (value)
		{
		case mpe_siege_alert_type::return_tender:
			out << "return_tender"; 
			break;
		case mpe_siege_alert_type::divide_tender:
			out << "divide_tender"; 
			break;
		case mpe_siege_alert_type::alliance_request:
			out << "alliance_request"; 
			break;
		case mpe_siege_alert_type::alliance_accept:
			out << "alliance_accept"; 
			break;
		case mpe_siege_alert_type::alliance_reject:
			out << "alliance_reject"; 
			break;
		case mpe_siege_alert_type::alliance_kickout:
			out << "alliance_kickout"; 
			break;
		case mpe_siege_alert_type::alliance_withdrawal:
			out << "alliance_withdrawal"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_castle_tax_distribution& value)
	{
		switch (value)
		{
		case mpe_castle_tax_distribution::equal:
			out << "equal"; 
			break;
		case mpe_castle_tax_distribution::differential:
			out << "differential"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_castle_town_detail_pos& value)
	{
		switch (value)
		{
		case mpe_castle_town_detail_pos::home:
			out << "home"; 
			break;
		case mpe_castle_town_detail_pos::dungeon:
			out << "dungeon"; 
			break;
		case mpe_castle_town_detail_pos::storage:
			out << "storage"; 
			break;
		case mpe_castle_town_detail_pos::training_center:
			out << "training_center"; 
			break;
		case mpe_castle_town_detail_pos::quest_office:
			out << "quest_office"; 
			break;
		case mpe_castle_town_detail_pos::blacksmith:
			out << "blacksmith"; 
			break;
		case mpe_castle_town_detail_pos::alchemy:
			out << "alchemy"; 
			break;
		case mpe_castle_town_detail_pos::cooking:
			out << "cooking"; 
			break;
		case mpe_castle_town_detail_pos::arsenal:
			out << "arsenal"; 
			break;
		case mpe_castle_town_detail_pos::orchard:
			out << "orchard"; 
			break;
		case mpe_castle_town_detail_pos::grove:
			out << "grove"; 
			break;
		case mpe_castle_town_detail_pos::farm:
			out << "farm"; 
			break;
		case mpe_castle_town_detail_pos::dinner:
			out << "dinner"; 
			break;
		case mpe_castle_town_detail_pos::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_chat_system& value)
	{
		switch (value)
		{
		case mpe_chat_system::notice_msg:
			out << "notice_msg"; 
			break;
		case mpe_chat_system::get_exp:
			out << "get_exp"; 
			break;
		case mpe_chat_system::get_goods:
			out << "get_goods"; 
			break;
		case mpe_chat_system::pickup_item:
			out << "pickup_item"; 
			break;
		case mpe_chat_system::dead_char:
			out << "dead_char"; 
			break;
		case mpe_chat_system::mentor_on:
			out << "mentor_on"; 
			break;
		case mpe_chat_system::make_item:
			out << "make_item"; 
			break;
		case mpe_chat_system::up_item:
			out << "up_item"; 
			break;
		case mpe_chat_system::bs_item:
			out << "bs_item"; 
			break;
		case mpe_chat_system::get_pet:
			out << "get_pet"; 
			break;
		case mpe_chat_system::get_vehicle:
			out << "get_vehicle"; 
			break;
		case mpe_chat_system::use_box_item:
			out << "use_box_item"; 
			break;
		case mpe_chat_system::wanted_murder_new:
			out << "wanted_murder_new"; 
			break;
		case mpe_chat_system::wanted_murder_change:
			out << "wanted_murder_change"; 
			break;
		case mpe_chat_system::wanted_murder_kill:
			out << "wanted_murder_kill"; 
			break;
		case mpe_chat_system::castle_tax_rate:
			out << "castle_tax_rate"; 
			break;
		case mpe_chat_system::siege_result:
			out << "siege_result"; 
			break;
		case mpe_chat_system::lord_bless:
			out << "lord_bless"; 
			break;
		case mpe_chat_system::secretvalley_noti:
			out << "secretvalley_noti"; 
			break;
		case mpe_chat_system::system_rolling:
			out << "system_rolling"; 
			break;
		case mpe_chat_system::system_rolling_chatting:
			out << "system_rolling_chatting"; 
			break;
		case mpe_chat_system::system_chatting:
			out << "system_chatting"; 
			break;
		case mpe_chat_system::system_world:
			out << "system_world"; 
			break;
		case mpe_chat_system::system_guild:
			out << "system_guild"; 
			break;
		case mpe_chat_system::system_party:
			out << "system_party"; 
			break;
		case mpe_chat_system::reserved_mail:
			out << "reserved_mail"; 
			break;
		case mpe_chat_system::get_pet_mix:
			out << "get_pet_mix"; 
			break;
		case mpe_chat_system::get_reflection:
			out << "get_reflection"; 
			break;
		case mpe_chat_system::get_reflection_mix:
			out << "get_reflection_mix"; 
			break;
		case mpe_chat_system::enchant_stone:
			out << "enchant_stone"; 
			break;
		case mpe_chat_system::world_boss_noti:
			out << "world_boss_noti"; 
			break;
		case mpe_chat_system::siege_noti:
			out << "siege_noti"; 
			break;
		case mpe_chat_system::treasure_box_open:
			out << "treasure_box_open"; 
			break;
		case mpe_chat_system::field_boss_noti:
			out << "field_boss_noti"; 
			break;
		case mpe_chat_system::mentee_dead:
			out << "mentee_dead"; 
			break;
		case mpe_chat_system::mentee_levelup:
			out << "mentee_levelup"; 
			break;
		case mpe_chat_system::mentor_off:
			out << "mentor_off"; 
			break;
		case mpe_chat_system::demon_tower_on:
			out << "demon_tower_on"; 
			break;
		case mpe_chat_system::dimension_dungeon_boss:
			out << "dimension_dungeon_boss"; 
			break;
		case mpe_chat_system::dimension_schedule_notify:
			out << "dimension_schedule_notify"; 
			break;
		case mpe_chat_system::expert_grade_up:
			out << "expert_grade_up"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_siege_warfare_machine_position& value)
	{
		switch (value)
		{
		case mpe_siege_warfare_machine_position::siege_weapon:
			out << "siege_weapon"; 
			break;
		case mpe_siege_warfare_machine_position::castle_guardian:
			out << "castle_guardian"; 
			break;
		case mpe_siege_warfare_machine_position::mercenary:
			out << "mercenary"; 
			break;
		case mpe_siege_warfare_machine_position::barricade:
			out << "barricade"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_siege_warfare_machine_type& value)
	{
		switch (value)
		{
		case mpe_siege_warfare_machine_type::atk_machine:
			out << "atk_machine"; 
			break;
		case mpe_siege_warfare_machine_type::def_machine:
			out << "def_machine"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_castle_town_work_type& value)
	{
		switch (value)
		{
		case mpe_castle_town_work_type::none:
			out << "none"; 
			break;
		case mpe_castle_town_work_type::house_build:
			out << "house_build"; 
			break;
		case mpe_castle_town_work_type::house_build_cancel:
			out << "house_build_cancel"; 
			break;
		case mpe_castle_town_work_type::house_levelup:
			out << "house_levelup"; 
			break;
		case mpe_castle_town_work_type::house_levelup_cancel:
			out << "house_levelup_cancel"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_castle_town_change_rental_fee_state& value)
	{
		switch (value)
		{
		case mpe_castle_town_change_rental_fee_state::none:
			out << "none"; 
			break;
		case mpe_castle_town_change_rental_fee_state::req_castle_owner:
			out << "req_castle_owner"; 
			break;
		case mpe_castle_town_change_rental_fee_state::req_town_owner:
			out << "req_town_owner"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_upgrade_state& value)
	{
		switch (value)
		{
		case mpe_upgrade_state::success:
			out << "success"; 
			break;
		case mpe_upgrade_state::normal:
			out << "normal"; 
			break;
		case mpe_upgrade_state::fail:
			out << "fail"; 
			break;
		case mpe_upgrade_state::destory:
			out << "destory"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_castle_town_specialties_pos& value)
	{
		switch (value)
		{
		case mpe_castle_town_specialties_pos::orchard:
			out << "orchard"; 
			break;
		case mpe_castle_town_specialties_pos::grove:
			out << "grove"; 
			break;
		case mpe_castle_town_specialties_pos::farm:
			out << "farm"; 
			break;
		case mpe_castle_town_specialties_pos::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_object_type& value)
	{
		switch (value)
		{
		case mpe_object_type::character:
			out << "character"; 
			break;
		case mpe_object_type::monster:
			out << "monster"; 
			break;
		case mpe_object_type::drop_item:
			out << "drop_item"; 
			break;
		case mpe_object_type::collect:
			out << "collect"; 
			break;
		case mpe_object_type::npc:
			out << "npc"; 
			break;
		case mpe_object_type::character_minion:
			out << "character_minion"; 
			break;
		case mpe_object_type::siege_weapon:
			out << "siege_weapon"; 
			break;
		case mpe_object_type::fixed_object:
			out << "fixed_object"; 
			break;
		case mpe_object_type::mercenary:
			out << "mercenary"; 
			break;
		case mpe_object_type::treasure_box:
			out << "treasure_box"; 
			break;
		case mpe_object_type::war_flag:
			out << "war_flag"; 
			break;
		case mpe_object_type::lord_statue:
			out << "lord_statue"; 
			break;
		case mpe_object_type::occupation_tower:
			out << "occupation_tower"; 
			break;
		case mpe_object_type::seal_device:
			out << "seal_device"; 
			break;
		case mpe_object_type::demon_summon:
			out << "demon_summon"; 
			break;
		case mpe_object_type::street_stall:
			out << "street_stall"; 
			break;
		case mpe_object_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_siege_team_index& value)
	{
		switch (value)
		{
		case mpe_siege_team_index::def_team:
			out << "def_team"; 
			break;
		case mpe_siege_team_index::atk_team:
			out << "atk_team"; 
			break;
		case mpe_siege_team_index::observer:
			out << "observer"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_pet_pos& value)
	{
		switch (value)
		{
		case mpe_pet_pos::first:
			out << "first"; 
			break;
		case mpe_pet_pos::second:
			out << "second"; 
			break;
		case mpe_pet_pos::third:
			out << "third"; 
			break;
		case mpe_pet_pos::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_vehicle_food_use& value)
	{
		switch (value)
		{
		case mpe_vehicle_food_use::use:
			out << "use"; 
			break;
		case mpe_vehicle_food_use::max_use:
			out << "max_use"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_vehicle_expire_type& value)
	{
		switch (value)
		{
		case mpe_vehicle_expire_type::satiety:
			out << "satiety"; 
			break;
		case mpe_vehicle_expire_type::date:
			out << "date"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_siege_message& value)
	{
		switch (value)
		{
		case mpe_siege_message::none:
			out << "none"; 
			break;
		case mpe_siege_message::siege_warfare_start:
			out << "siege_warfare_start"; 
			break;
		case mpe_siege_message::destroy_left_wall:
			out << "destroy_left_wall"; 
			break;
		case mpe_siege_message::destroy_center_wall:
			out << "destroy_center_wall"; 
			break;
		case mpe_siege_message::destroy_right_wall:
			out << "destroy_right_wall"; 
			break;
		case mpe_siege_message::gate_open_siege_tower:
			out << "gate_open_siege_tower"; 
			break;
		case mpe_siege_message::guard_tower_all_destroy:
			out << "guard_tower_all_destroy"; 
			break;
		case mpe_siege_message::destroy_left_1_guard_tower:
			out << "destroy_left_1_guard_tower"; 
			break;
		case mpe_siege_message::destroy_left_2_guard_tower:
			out << "destroy_left_2_guard_tower"; 
			break;
		case mpe_siege_message::destroy_right_1_guard_tower:
			out << "destroy_right_1_guard_tower"; 
			break;
		case mpe_siege_message::victory_check_start:
			out << "victory_check_start"; 
			break;
		case mpe_siege_message::siege_warfare_endtime_one_minutes:
			out << "siege_warfare_endtime_one_minutes"; 
			break;
		case mpe_siege_message::victory_atk:
			out << "victory_atk"; 
			break;
		case mpe_siege_message::victory_def:
			out << "victory_def"; 
			break;
		case mpe_siege_message::owner_guild_alert:
			out << "owner_guild_alert"; 
			break;
		case mpe_siege_message::victory_time:
			out << "victory_time"; 
			break;
		case mpe_siege_message::destroy_right_2_guard_tower:
			out << "destroy_right_2_guard_tower"; 
			break;
		case mpe_siege_message::destroy_victory_object:
			out << "destroy_victory_object"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_dead_reason& value)
	{
		switch (value)
		{
		case mpe_dead_reason::normal:
			out << "normal"; 
			break;
		case mpe_dead_reason::immediate:
			out << "immediate"; 
			break;
		case mpe_dead_reason::on_the_wall:
			out << "on_the_wall"; 
			break;
		case mpe_dead_reason::trigger_dead:
			out << "trigger_dead"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_pk_revenge_trace& value)
	{
		switch (value)
		{
		case mpe_pk_revenge_trace::not_found:
			out << "not_found"; 
			break;
		case mpe_pk_revenge_trace::connect:
			out << "connect"; 
			break;
		case mpe_pk_revenge_trace::disconnect:
			out << "disconnect"; 
			break;
		case mpe_pk_revenge_trace::is_found:
			out << "is_found"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_friend_type& value)
	{
		switch (value)
		{
		case mpe_friend_type::in_game:
			out << "in_game"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_mentor_type& value)
	{
		switch (value)
		{
		case mpe_mentor_type::mentor:
			out << "mentor"; 
			break;
		case mpe_mentor_type::mentee:
			out << "mentee"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_mentor_request_type& value)
	{
		switch (value)
		{
		case mpe_mentor_request_type::request:
			out << "request"; 
			break;
		case mpe_mentor_request_type::request_accept:
			out << "request_accept"; 
			break;
		case mpe_mentor_request_type::request_cancel:
			out << "request_cancel"; 
			break;
		case mpe_mentor_request_type::request_refusal:
			out << "request_refusal"; 
			break;
		case mpe_mentor_request_type::request_disband:
			out << "request_disband"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_ranking_type& value)
	{
		switch (value)
		{
		case mpe_ranking_type::none:
			out << "none"; 
			break;
		case mpe_ranking_type::personal_power_total:
			out << "personal_power_total"; 
			break;
		case mpe_ranking_type::personal_power_warrior:
			out << "personal_power_warrior"; 
			break;
		case mpe_ranking_type::personal_power_wizard:
			out << "personal_power_wizard"; 
			break;
		case mpe_ranking_type::personal_power_taoist:
			out << "personal_power_taoist"; 
			break;
		case mpe_ranking_type::personal_level_total:
			out << "personal_level_total"; 
			break;
		case mpe_ranking_type::personal_level_warrior:
			out << "personal_level_warrior"; 
			break;
		case mpe_ranking_type::personal_level_wizard:
			out << "personal_level_wizard"; 
			break;
		case mpe_ranking_type::personal_level_taoist:
			out << "personal_level_taoist"; 
			break;
		case mpe_ranking_type::guild_all:
			out << "guild_all"; 
			break;
		case mpe_ranking_type::mining:
			out << "mining"; 
			break;
		case mpe_ranking_type::gather:
			out << "gather"; 
			break;
		case mpe_ranking_type::fishing:
			out << "fishing"; 
			break;
		case mpe_ranking_type::blacksmith:
			out << "blacksmith"; 
			break;
		case mpe_ranking_type::alchemy:
			out << "alchemy"; 
			break;
		case mpe_ranking_type::handwork:
			out << "handwork"; 
			break;
		case mpe_ranking_type::reinforce:
			out << "reinforce"; 
			break;
		case mpe_ranking_type::enchant:
			out << "enchant"; 
			break;
		case mpe_ranking_type::luck:
			out << "luck"; 
			break;
		case mpe_ranking_type::blood_stone_total:
			out << "blood_stone_total"; 
			break;
		case mpe_ranking_type::blood_stone_warrior:
			out << "blood_stone_warrior"; 
			break;
		case mpe_ranking_type::blood_stone_wizard:
			out << "blood_stone_wizard"; 
			break;
		case mpe_ranking_type::blood_stone_taoist:
			out << "blood_stone_taoist"; 
			break;
		case mpe_ranking_type::blood_dedicate_total:
			out << "blood_dedicate_total"; 
			break;
		case mpe_ranking_type::blood_dedicate_warrior:
			out << "blood_dedicate_warrior"; 
			break;
		case mpe_ranking_type::blood_dedicate_wizard:
			out << "blood_dedicate_wizard"; 
			break;
		case mpe_ranking_type::blood_dedicate_taoist:
			out << "blood_dedicate_taoist"; 
			break;
		case mpe_ranking_type::dungeon_clear:
			out << "dungeon_clear"; 
			break;
		case mpe_ranking_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_clinet_platform& value)
	{
		switch (value)
		{
		case mpe_clinet_platform::mobile:
			out << "mobile"; 
			break;
		case mpe_clinet_platform::pc:
			out << "pc"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_dictionary_type& value)
	{
		switch (value)
		{
		case mpe_dictionary_type::none:
			out << "none"; 
			break;
		case mpe_dictionary_type::monster:
			out << "monster"; 
			break;
		case mpe_dictionary_type::item:
			out << "item"; 
			break;
		case mpe_dictionary_type::pet:
			out << "pet"; 
			break;
		case mpe_dictionary_type::localcollect:
			out << "localcollect"; 
			break;
		case mpe_dictionary_type::loststory:
			out << "loststory"; 
			break;
		case mpe_dictionary_type::viewpoint:
			out << "viewpoint"; 
			break;
		case mpe_dictionary_type::npcInmacy:
			out << "npcInmacy"; 
			break;
		case mpe_dictionary_type::first_kill:
			out << "first_kill"; 
			break;
		case mpe_dictionary_type::monster_core:
			out << "monster_core"; 
			break;
		case mpe_dictionary_type::monster_essence:
			out << "monster_essence"; 
			break;
		case mpe_dictionary_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_costume_show& value)
	{
		switch (value)
		{
		case mpe_costume_show::show:
			out << "show"; 
			break;
		case mpe_costume_show::hide:
			out << "hide"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_view_point_tel_type& value)
	{
		switch (value)
		{
		case mpe_view_point_tel_type::auto_hunt:
			out << "auto_hunt"; 
			break;
		case mpe_view_point_tel_type::instand_move:
			out << "instand_move"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_wanted_murder_trace& value)
	{
		switch (value)
		{
		case mpe_wanted_murder_trace::online:
			out << "online"; 
			break;
		case mpe_wanted_murder_trace::offline:
			out << "offline"; 
			break;
		case mpe_wanted_murder_trace::untraceable:
			out << "untraceable"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_teleport_type& value)
	{
		switch (value)
		{
		case mpe_teleport_type::view_point_teleport:
			out << "view_point_teleport"; 
			break;
		case mpe_teleport_type::obj_point_teleport:
			out << "obj_point_teleport"; 
			break;
		case mpe_teleport_type::move_teleport:
			out << "move_teleport"; 
			break;
		case mpe_teleport_type::occupation_tower_teleport:
			out << "occupation_tower_teleport"; 
			break;
		case mpe_teleport_type::mentor_teleport:
			out << "mentor_teleport"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_reinforce_stone_type& value)
	{
		switch (value)
		{
		case mpe_reinforce_stone_type::normal_stone:
			out << "normal_stone"; 
			break;
		case mpe_reinforce_stone_type::bless_stone:
			out << "bless_stone"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_reinforce_result& value)
	{
		switch (value)
		{
		case mpe_reinforce_result::none:
			out << "none"; 
			break;
		case mpe_reinforce_result::reinforce_success:
			out << "reinforce_success"; 
			break;
		case mpe_reinforce_result::reinforce_fail:
			out << "reinforce_fail"; 
			break;
		case mpe_reinforce_result::reinforce_fail_destruction:
			out << "reinforce_fail_destruction"; 
			break;
		case mpe_reinforce_result::reinforce_success_big:
			out << "reinforce_success_big"; 
			break;
		case mpe_reinforce_result::reinforce_success_best:
			out << "reinforce_success_best"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_guild_type& value)
	{
		switch (value)
		{
		case mpe_guild_type::none:
			out << "none"; 
			break;
		case mpe_guild_type::normal:
			out << "normal"; 
			break;
		case mpe_guild_type::beginner:
			out << "beginner"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_adult_grade& value)
	{
		switch (value)
		{
		case mpe_adult_grade::kids:
			out << "kids"; 
			break;
		case mpe_adult_grade::youth:
			out << "youth"; 
			break;
		case mpe_adult_grade::teenager:
			out << "teenager"; 
			break;
		case mpe_adult_grade::adult:
			out << "adult"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_ai_setup_config_pos& value)
	{
		switch (value)
		{
		case mpe_ai_setup_config_pos::hp_potion_buy:
			out << "hp_potion_buy"; 
			break;
		case mpe_ai_setup_config_pos::mp_potion_buy:
			out << "mp_potion_buy"; 
			break;
		case mpe_ai_setup_config_pos::pickup_hp_potion:
			out << "pickup_hp_potion"; 
			break;
		case mpe_ai_setup_config_pos::pickup_mp_potion:
			out << "pickup_mp_potion"; 
			break;
		case mpe_ai_setup_config_pos::pickup_gold:
			out << "pickup_gold"; 
			break;
		case mpe_ai_setup_config_pos::item_decompose:
			out << "item_decompose"; 
			break;
		case mpe_ai_setup_config_pos::item_sell:
			out << "item_sell"; 
			break;
		case mpe_ai_setup_config_pos::item_repair:
			out << "item_repair"; 
			break;
		case mpe_ai_setup_config_pos::townreturn_revive:
			out << "townreturn_revive"; 
			break;
		case mpe_ai_setup_config_pos::townreturn_inven_full:
			out << "townreturn_inven_full"; 
			break;
		case mpe_ai_setup_config_pos::townreturn_need_repair:
			out << "townreturn_need_repair"; 
			break;
		case mpe_ai_setup_config_pos::townreturn_lack_hp:
			out << "townreturn_lack_hp"; 
			break;
		case mpe_ai_setup_config_pos::townreturn_lack_mp:
			out << "townreturn_lack_mp"; 
			break;
		case mpe_ai_setup_config_pos::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_guild_shipwar_state& value)
	{
		switch (value)
		{
		case mpe_guild_shipwar_state::request:
			out << "request"; 
			break;
		case mpe_guild_shipwar_state::match:
			out << "match"; 
			break;
		case mpe_guild_shipwar_state::match_end:
			out << "match_end"; 
			break;
		case mpe_guild_shipwar_state::enter_start:
			out << "enter_start"; 
			break;
		case mpe_guild_shipwar_state::enter_end:
			out << "enter_end"; 
			break;
		case mpe_guild_shipwar_state::indun_complete:
			out << "indun_complete"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_match_state& value)
	{
		switch (value)
		{
		case mpe_match_state::request:
			out << "request"; 
			break;
		case mpe_match_state::unrequest:
			out << "unrequest"; 
			break;
		case mpe_match_state::matching:
			out << "matching"; 
			break;
		case mpe_match_state::ready:
			out << "ready"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_guild_shipwar_character_state& value)
	{
		switch (value)
		{
		case mpe_guild_shipwar_character_state::battle:
			out << "battle"; 
			break;
		case mpe_guild_shipwar_character_state::leave:
			out << "leave"; 
			break;
		case mpe_guild_shipwar_character_state::revival:
			out << "revival"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_shipwar_time_type& value)
	{
		switch (value)
		{
		case mpe_shipwar_time_type::wait_time:
			out << "wait_time"; 
			break;
		case mpe_shipwar_time_type::play_time:
			out << "play_time"; 
			break;
		case mpe_shipwar_time_type::vitory_check_time:
			out << "vitory_check_time"; 
			break;
		case mpe_shipwar_time_type::end_time:
			out << "end_time"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_guild_shipwar_message& value)
	{
		switch (value)
		{
		case mpe_guild_shipwar_message::none:
			out << "none"; 
			break;
		case mpe_guild_shipwar_message::guild_shipwar_start:
			out << "guild_shipwar_start"; 
			break;
		case mpe_guild_shipwar_message::victory_check_start:
			out << "victory_check_start"; 
			break;
		case mpe_guild_shipwar_message::victory_check_stop:
			out << "victory_check_stop"; 
			break;
		case mpe_guild_shipwar_message::guild_shipwar_end:
			out << "guild_shipwar_end"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_guild_shipwar_team& value)
	{
		switch (value)
		{
		case mpe_guild_shipwar_team::none:
			out << "none"; 
			break;
		case mpe_guild_shipwar_team::team_a:
			out << "team_a"; 
			break;
		case mpe_guild_shipwar_team::team_b:
			out << "team_b"; 
			break;
		case mpe_guild_shipwar_team::team_all:
			out << "team_all"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_pickup_item_type& value)
	{
		switch (value)
		{
		case mpe_pickup_item_type::none:
			out << "none"; 
			break;
		case mpe_pickup_item_type::gold:
			out << "gold"; 
			break;
		case mpe_pickup_item_type::exp:
			out << "exp"; 
			break;
		case mpe_pickup_item_type::boss_point:
			out << "boss_point"; 
			break;
		case mpe_pickup_item_type::item:
			out << "item"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_guild_rank_type& value)
	{
		switch (value)
		{
		case mpe_guild_rank_type::shipwar:
			out << "shipwar"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_pet_team& value)
	{
		switch (value)
		{
		case mpe_pet_team::first:
			out << "first"; 
			break;
		case mpe_pet_team::second:
			out << "second"; 
			break;
		case mpe_pet_team::third:
			out << "third"; 
			break;
		case mpe_pet_team::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_challenge_state& value)
	{
		switch (value)
		{
		case mpe_challenge_state::none:
			out << "none"; 
			break;
		case mpe_challenge_state::completed:
			out << "completed"; 
			break;
		case mpe_challenge_state::repeat:
			out << "repeat"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_seasonpass_reward_type& value)
	{
		switch (value)
		{
		case mpe_seasonpass_reward_type::daily:
			out << "daily"; 
			break;
		case mpe_seasonpass_reward_type::free:
			out << "free"; 
			break;
		case mpe_seasonpass_reward_type::pass:
			out << "pass"; 
			break;
		case mpe_seasonpass_reward_type::complete:
			out << "complete"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_avatar_pos& value)
	{
		switch (value)
		{
		case mpe_avatar_pos::none:
			out << "none"; 
			break;
		case mpe_avatar_pos::one:
			out << "one"; 
			break;
		case mpe_avatar_pos::two:
			out << "two"; 
			break;
		case mpe_avatar_pos::three:
			out << "three"; 
			break;
		case mpe_avatar_pos::four:
			out << "four"; 
			break;
		case mpe_avatar_pos::five:
			out << "five"; 
			break;
		case mpe_avatar_pos::six:
			out << "six"; 
			break;
		case mpe_avatar_pos::seven:
			out << "seven"; 
			break;
		case mpe_avatar_pos::eight:
			out << "eight"; 
			break;
		case mpe_avatar_pos::nine:
			out << "nine"; 
			break;
		case mpe_avatar_pos::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_guild_mark_index& value)
	{
		switch (value)
		{
		case mpe_guild_mark_index::mark:
			out << "mark"; 
			break;
		case mpe_guild_mark_index::background:
			out << "background"; 
			break;
		case mpe_guild_mark_index::color:
			out << "color"; 
			break;
		case mpe_guild_mark_index::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_guild_share_storage_log& value)
	{
		switch (value)
		{
		case mpe_guild_share_storage_log::none:
			out << "none"; 
			break;
		case mpe_guild_share_storage_log::town_get:
			out << "town_get"; 
			break;
		case mpe_guild_share_storage_log::town_return:
			out << "town_return"; 
			break;
		case mpe_guild_share_storage_log::item_in_storage:
			out << "item_in_storage"; 
			break;
		case mpe_guild_share_storage_log::item_get_request:
			out << "item_get_request"; 
			break;
		case mpe_guild_share_storage_log::item_get:
			out << "item_get"; 
			break;
		case mpe_guild_share_storage_log::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_secretvalley_state& value)
	{
		switch (value)
		{
		case mpe_secretvalley_state::none:
			out << "none"; 
			break;
		case mpe_secretvalley_state::init:
			out << "init"; 
			break;
		case mpe_secretvalley_state::play:
			out << "play"; 
			break;
		case mpe_secretvalley_state::finish:
			out << "finish"; 
			break;
		case mpe_secretvalley_state::destroy_pre:
			out << "destroy_pre"; 
			break;
		case mpe_secretvalley_state::destroy:
			out << "destroy"; 
			break;
		case mpe_secretvalley_state::destroy_move_pre:
			out << "destroy_move_pre"; 
			break;
		case mpe_secretvalley_state::restart:
			out << "restart"; 
			break;
		case mpe_secretvalley_state::victory:
			out << "victory"; 
			break;
		case mpe_secretvalley_state::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_seal_device_state& value)
	{
		switch (value)
		{
		case mpe_seal_device_state::none:
			out << "none"; 
			break;
		case mpe_seal_device_state::activating:
			out << "activating"; 
			break;
		case mpe_seal_device_state::awaiting:
			out << "awaiting"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_demon_summon_state& value)
	{
		switch (value)
		{
		case mpe_demon_summon_state::none:
			out << "none"; 
			break;
		case mpe_demon_summon_state::activate_start:
			out << "activate_start"; 
			break;
		case mpe_demon_summon_state::activating:
			out << "activating"; 
			break;
		case mpe_demon_summon_state::boss_summon:
			out << "boss_summon"; 
			break;
		case mpe_demon_summon_state::activate_end:
			out << "activate_end"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_occupation_state& value)
	{
		switch (value)
		{
		case mpe_occupation_state::none:
			out << "none"; 
			break;
		case mpe_occupation_state::activating:
			out << "activating"; 
			break;
		case mpe_occupation_state::immune:
			out << "immune"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_arena_battle_alert& value)
	{
		switch (value)
		{
		case mpe_arena_battle_alert::none:
			out << "none"; 
			break;
		case mpe_arena_battle_alert::cutscene:
			out << "cutscene"; 
			break;
		case mpe_arena_battle_alert::battle_start:
			out << "battle_start"; 
			break;
		case mpe_arena_battle_alert::battle_result:
			out << "battle_result"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_character_battle_state& value)
	{
		switch (value)
		{
		case mpe_character_battle_state::none:
			out << "none"; 
			break;
		case mpe_character_battle_state::battle:
			out << "battle"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_indun_monarch_state& value)
	{
		switch (value)
		{
		case mpe_indun_monarch_state::none:
			out << "none"; 
			break;
		case mpe_indun_monarch_state::start_count:
			out << "start_count"; 
			break;
		case mpe_indun_monarch_state::start:
			out << "start"; 
			break;
		case mpe_indun_monarch_state::end:
			out << "end"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_guild_goods& value)
	{
		switch (value)
		{
		case mpe_guild_goods::none:
			out << "none"; 
			break;
		case mpe_guild_goods::gold:
			out << "gold"; 
			break;
		case mpe_guild_goods::exp:
			out << "exp"; 
			break;
		case mpe_guild_goods::black_iron:
			out << "black_iron"; 
			break;
		case mpe_guild_goods::goldingot:
			out << "goldingot"; 
			break;
		case mpe_guild_goods::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_mandala_type& value)
	{
		switch (value)
		{
		case mpe_mandala_type::none:
			out << "none"; 
			break;
		case mpe_mandala_type::character:
			out << "character"; 
			break;
		case mpe_mandala_type::master:
			out << "master"; 
			break;
		case mpe_mandala_type::season:
			out << "season"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_os_type& value)
	{
		switch (value)
		{
		case mpe_os_type::none:
			out << "none"; 
			break;
		case mpe_os_type::os_android:
			out << "os_android"; 
			break;
		case mpe_os_type::os_ios:
			out << "os_ios"; 
			break;
		case mpe_os_type::os_windows:
			out << "os_windows"; 
			break;
		case mpe_os_type::os_dev3d:
			out << "os_dev3d"; 
			break;
		case mpe_os_type::os_all:
			out << "os_all"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_channel_type& value)
	{
		switch (value)
		{
		case mpe_channel_type::none:
			out << "none"; 
			break;
		case mpe_channel_type::guest:
			out << "guest"; 
			break;
		case mpe_channel_type::google:
			out << "google"; 
			break;
		case mpe_channel_type::facebook:
			out << "facebook"; 
			break;
		case mpe_channel_type::apple:
			out << "apple"; 
			break;
		case mpe_channel_type::kakao:
			out << "kakao"; 
			break;
		case mpe_channel_type::stream:
			out << "stream"; 
			break;
		case mpe_channel_type::bot:
			out << "bot"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_store_type& value)
	{
		switch (value)
		{
		case mpe_store_type::none:
			out << "none"; 
			break;
		case mpe_store_type::google_play:
			out << "google_play"; 
			break;
		case mpe_store_type::google_play_12:
			out << "google_play_12"; 
			break;
		case mpe_store_type::apple_store:
			out << "apple_store"; 
			break;
		case mpe_store_type::apple_store_12:
			out << "apple_store_12"; 
			break;
		case mpe_store_type::window:
			out << "window"; 
			break;
		case mpe_store_type::google_play_cbt:
			out << "google_play_cbt"; 
			break;
		case mpe_store_type::google_play_game:
			out << "google_play_game"; 
			break;
		case mpe_store_type::one_store:
			out << "one_store"; 
			break;
		case mpe_store_type::huawei:
			out << "huawei"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_collect_result& value)
	{
		switch (value)
		{
		case mpe_collect_result::none:
			out << "none"; 
			break;
		case mpe_collect_result::success:
			out << "success"; 
			break;
		case mpe_collect_result::great:
			out << "great"; 
			break;
		case mpe_collect_result::fail:
			out << "fail"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_contents_onoff_type& value)
	{
		switch (value)
		{
		case mpe_contents_onoff_type::none:
			out << "none"; 
			break;
		case mpe_contents_onoff_type::field:
			out << "field"; 
			break;
		case mpe_contents_onoff_type::indun:
			out << "indun"; 
			break;
		case mpe_contents_onoff_type::npc_object:
			out << "npc_object"; 
			break;
		case mpe_contents_onoff_type::exchange:
			out << "exchange"; 
			break;
		case mpe_contents_onoff_type::cash_shop:
			out << "cash_shop"; 
			break;
		case mpe_contents_onoff_type::profesion_make:
			out << "profesion_make"; 
			break;
		case mpe_contents_onoff_type::mandala:
			out << "mandala"; 
			break;
		case mpe_contents_onoff_type::matching:
			out << "matching"; 
			break;
		case mpe_contents_onoff_type::dictionary_achieve:
			out << "dictionary_achieve"; 
			break;
		case mpe_contents_onoff_type::cash_shop_category:
			out << "cash_shop_category"; 
			break;
		case mpe_contents_onoff_type::cash_shop_category_detail:
			out << "cash_shop_category_detail"; 
			break;
		case mpe_contents_onoff_type::event_ingame_exp_increase:
			out << "event_ingame_exp_increase"; 
			break;
		case mpe_contents_onoff_type::uncheater_check_mode:
			out << "uncheater_check_mode"; 
			break;
		case mpe_contents_onoff_type::occupationwar:
			out << "occupationwar"; 
			break;
		case mpe_contents_onoff_type::nprotect_check_mode:
			out << "nprotect_check_mode"; 
			break;
		case mpe_contents_onoff_type::dogma_system:
			out << "dogma_system"; 
			break;
		case mpe_contents_onoff_type::global_occupationwar:
			out << "global_occupationwar"; 
			break;
		case mpe_contents_onoff_type::darksteel_storage:
			out << "darksteel_storage"; 
			break;
		case mpe_contents_onoff_type::global_exchange:
			out << "global_exchange"; 
			break;
		case mpe_contents_onoff_type::global_gold_exchange:
			out << "global_gold_exchange"; 
			break;
		case mpe_contents_onoff_type::wemix_doller_shop:
			out << "wemix_doller_shop"; 
			break;
		case mpe_contents_onoff_type::gloabl_party_governance:
			out << "gloabl_party_governance"; 
			break;
		case mpe_contents_onoff_type::advertisement:
			out << "advertisement"; 
			break;
		case mpe_contents_onoff_type::server_relocation:
			out << "server_relocation"; 
			break;
		case mpe_contents_onoff_type::monarch_dungeon:
			out << "monarch_dungeon"; 
			break;
		case mpe_contents_onoff_type::world_game:
			out << "world_game"; 
			break;
		case mpe_contents_onoff_type::season_mandala:
			out << "season_mandala"; 
			break;
		case mpe_contents_onoff_type::restore_event:
			out << "restore_event"; 
			break;
		case mpe_contents_onoff_type::guild_ally:
			out << "guild_ally"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_contents_onoff_restore_event_type& value)
	{
		switch (value)
		{
		case mpe_contents_onoff_restore_event_type::none:
			out << "none"; 
			break;
		case mpe_contents_onoff_restore_event_type::all:
			out << "all"; 
			break;
		case mpe_contents_onoff_restore_event_type::item:
			out << "item"; 
			break;
		case mpe_contents_onoff_restore_event_type::compose:
			out << "compose"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_contents_onoff_match_type& value)
	{
		switch (value)
		{
		case mpe_contents_onoff_match_type::none:
			out << "none"; 
			break;
		case mpe_contents_onoff_match_type::arena_battle:
			out << "arena_battle"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_contents_onoff_occupationwar_type& value)
	{
		switch (value)
		{
		case mpe_contents_onoff_occupationwar_type::none:
			out << "none"; 
			break;
		case mpe_contents_onoff_occupationwar_type::occupationwar_onoff:
			out << "occupationwar_onoff"; 
			break;
		case mpe_contents_onoff_occupationwar_type::darksteel_box_onoff:
			out << "darksteel_box_onoff"; 
			break;
		case mpe_contents_onoff_occupationwar_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_contents_onoff_param_dogma_type& value)
	{
		switch (value)
		{
		case mpe_contents_onoff_param_dogma_type::none:
			out << "none"; 
			break;
		case mpe_contents_onoff_param_dogma_type::all:
			out << "all"; 
			break;
		case mpe_contents_onoff_param_dogma_type::smelt:
			out << "smelt"; 
			break;
		case mpe_contents_onoff_param_dogma_type::divine:
			out << "divine"; 
			break;
		case mpe_contents_onoff_param_dogma_type::boss:
			out << "boss"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_contents_onoff_param_globol_exchange_type& value)
	{
		switch (value)
		{
		case mpe_contents_onoff_param_globol_exchange_type::none:
			out << "none"; 
			break;
		case mpe_contents_onoff_param_globol_exchange_type::all:
			out << "all"; 
			break;
		case mpe_contents_onoff_param_globol_exchange_type::list:
			out << "list"; 
			break;
		case mpe_contents_onoff_param_globol_exchange_type::sales:
			out << "sales"; 
			break;
		case mpe_contents_onoff_param_globol_exchange_type::buy:
			out << "buy"; 
			break;
		case mpe_contents_onoff_param_globol_exchange_type::receive:
			out << "receive"; 
			break;
		case mpe_contents_onoff_param_globol_exchange_type::calculate:
			out << "calculate"; 
			break;
		case mpe_contents_onoff_param_globol_exchange_type::cancel:
			out << "cancel"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_contents_onoff_world_game_type& value)
	{
		switch (value)
		{
		case mpe_contents_onoff_world_game_type::none:
			out << "none"; 
			break;
		case mpe_contents_onoff_world_game_type::enter_map:
			out << "enter_map"; 
			break;
		case mpe_contents_onoff_world_game_type::dimension:
			out << "dimension"; 
			break;
		case mpe_contents_onoff_world_game_type::blood_dedicate:
			out << "blood_dedicate"; 
			break;
		case mpe_contents_onoff_world_game_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_deploy_version& value)
	{
		switch (value)
		{
		case mpe_deploy_version::master:
			out << "master"; 
			break;
		case mpe_deploy_version::qa:
			out << "qa"; 
			break;
		case mpe_deploy_version::alpha:
			out << "alpha"; 
			break;
		case mpe_deploy_version::beta:
			out << "beta"; 
			break;
		case mpe_deploy_version::ios_review:
			out << "ios_review"; 
			break;
		case mpe_deploy_version::google_featured:
			out << "google_featured"; 
			break;
		case mpe_deploy_version::live:
			out << "live"; 
			break;
		case mpe_deploy_version::stage:
			out << "stage"; 
			break;
		case mpe_deploy_version::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_coupon_type& value)
	{
		switch (value)
		{
		case mpe_coupon_type::none:
			out << "none"; 
			break;
		case mpe_coupon_type::internal_coupon:
			out << "internal_coupon"; 
			break;
		case mpe_coupon_type::external_coupon:
			out << "external_coupon"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_cash_exchange_type& value)
	{
		switch (value)
		{
		case mpe_cash_exchange_type::daily:
			out << "daily"; 
			break;
		case mpe_cash_exchange_type::goods:
			out << "goods"; 
			break;
		case mpe_cash_exchange_type::item:
			out << "item"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_recovery_exp_type& value)
	{
		switch (value)
		{
		case mpe_recovery_exp_type::free:
			out << "free"; 
			break;
		case mpe_recovery_exp_type::normal:
			out << "normal"; 
			break;
		case mpe_recovery_exp_type::unique:
			out << "unique"; 
			break;
		case mpe_recovery_exp_type::item:
			out << "item"; 
			break;
		case mpe_recovery_exp_type::advertisement:
			out << "advertisement"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_title_type& value)
	{
		switch (value)
		{
		case mpe_title_type::none:
			out << "none"; 
			break;
		case mpe_title_type::mentor_title:
			out << "mentor_title"; 
			break;
		case mpe_title_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_cash_shop_item_state& value)
	{
		switch (value)
		{
		case mpe_cash_shop_item_state::sale_disable:
			out << "sale_disable"; 
			break;
		case mpe_cash_shop_item_state::sale_enable:
			out << "sale_enable"; 
			break;
		case mpe_cash_shop_item_state::time_enable:
			out << "time_enable"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_event_ingame& value)
	{
		switch (value)
		{
		case mpe_event_ingame::exp_increase:
			out << "exp_increase"; 
			break;
		case mpe_event_ingame::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_item_delete_cause& value)
	{
		switch (value)
		{
		case mpe_item_delete_cause::none:
			out << "none"; 
			break;
		case mpe_item_delete_cause::reinforce:
			out << "reinforce"; 
			break;
		case mpe_item_delete_cause::disassemble:
			out << "disassemble"; 
			break;
		case mpe_item_delete_cause::sell:
			out << "sell"; 
			break;
		case mpe_item_delete_cause::destroy:
			out << "destroy"; 
			break;
		case mpe_item_delete_cause::stall_reinforce:
			out << "stall_reinforce"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_darksteel_storage_good_pos& value)
	{
		switch (value)
		{
		case mpe_darksteel_storage_good_pos::guid:
			out << "guid"; 
			break;
		case mpe_darksteel_storage_good_pos::amount:
			out << "amount"; 
			break;
		case mpe_darksteel_storage_good_pos::income:
			out << "income"; 
			break;
		case mpe_darksteel_storage_good_pos::expense:
			out << "expense"; 
			break;
		case mpe_darksteel_storage_good_pos::darksteel_tax:
			out << "darksteel_tax"; 
			break;
		case mpe_darksteel_storage_good_pos::darksteel_collect:
			out << "darksteel_collect"; 
			break;
		case mpe_darksteel_storage_good_pos::governance_tax:
			out << "governance_tax"; 
			break;
		case mpe_darksteel_storage_good_pos::darksteel_tax_history:
			out << "darksteel_tax_history"; 
			break;
		case mpe_darksteel_storage_good_pos::governance_tax_history:
			out << "governance_tax_history"; 
			break;
		case mpe_darksteel_storage_good_pos::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_darksteel_box_keep_type& value)
	{
		switch (value)
		{
		case mpe_darksteel_box_keep_type::none:
			out << "none"; 
			break;
		case mpe_darksteel_box_keep_type::occupationwar_tender_deposit:
			out << "occupationwar_tender_deposit"; 
			break;
		case mpe_darksteel_box_keep_type::occupationwar_tender_withdraw:
			out << "occupationwar_tender_withdraw"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_occupationwar_map_type& value)
	{
		switch (value)
		{
		case mpe_occupationwar_map_type::none:
			out << "none"; 
			break;
		case mpe_occupationwar_map_type::bicheon:
			out << "bicheon"; 
			break;
		case mpe_occupationwar_map_type::snakevalley:
			out << "snakevalley"; 
			break;
		case mpe_occupationwar_map_type::mongchon:
			out << "mongchon"; 
			break;
		case mpe_occupationwar_map_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_darksteel_storage_pay_type& value)
	{
		switch (value)
		{
		case mpe_darksteel_storage_pay_type::none:
			out << "none"; 
			break;
		case mpe_darksteel_storage_pay_type::income:
			out << "income"; 
			break;
		case mpe_darksteel_storage_pay_type::sell:
			out << "sell"; 
			break;
		case mpe_darksteel_storage_pay_type::pay_guild_owner:
			out << "pay_guild_owner"; 
			break;
		case mpe_darksteel_storage_pay_type::pay_guild_other:
			out << "pay_guild_other"; 
			break;
		case mpe_darksteel_storage_pay_type::pay_user_guild:
			out << "pay_user_guild"; 
			break;
		case mpe_darksteel_storage_pay_type::pay_user_other:
			out << "pay_user_other"; 
			break;
		case mpe_darksteel_storage_pay_type::pay_tax:
			out << "pay_tax"; 
			break;
		case mpe_darksteel_storage_pay_type::get_tax_1:
			out << "get_tax_1"; 
			break;
		case mpe_darksteel_storage_pay_type::get_tax_2:
			out << "get_tax_2"; 
			break;
		case mpe_darksteel_storage_pay_type::get_tax_3:
			out << "get_tax_3"; 
			break;
		case mpe_darksteel_storage_pay_type::get_tax_4:
			out << "get_tax_4"; 
			break;
		case mpe_darksteel_storage_pay_type::system_payment:
			out << "system_payment"; 
			break;
		case mpe_darksteel_storage_pay_type::system_withdraw:
			out << "system_withdraw"; 
			break;
		case mpe_darksteel_storage_pay_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_occupationwar_schedule_type& value)
	{
		switch (value)
		{
		case mpe_occupationwar_schedule_type::none:
			out << "none"; 
			break;
		case mpe_occupationwar_schedule_type::schedule_in_start:
			out << "schedule_in_start"; 
			break;
		case mpe_occupationwar_schedule_type::schedule_in_finish:
			out << "schedule_in_finish"; 
			break;
		case mpe_occupationwar_schedule_type::darksteelbox_deposit_start_1:
			out << "darksteelbox_deposit_start_1"; 
			break;
		case mpe_occupationwar_schedule_type::darksteelbox_deposit_end_1:
			out << "darksteelbox_deposit_end_1"; 
			break;
		case mpe_occupationwar_schedule_type::darksteelbox_deposit_start_2:
			out << "darksteelbox_deposit_start_2"; 
			break;
		case mpe_occupationwar_schedule_type::darksteelbox_deposit_end_2:
			out << "darksteelbox_deposit_end_2"; 
			break;
		case mpe_occupationwar_schedule_type::darksteelbox_withdraw_1_start:
			out << "darksteelbox_withdraw_1_start"; 
			break;
		case mpe_occupationwar_schedule_type::darksteelbox_withdraw_1_end:
			out << "darksteelbox_withdraw_1_end"; 
			break;
		case mpe_occupationwar_schedule_type::darksteelbox_withdraw_2_start:
			out << "darksteelbox_withdraw_2_start"; 
			break;
		case mpe_occupationwar_schedule_type::darksteelbox_withdraw_2_end:
			out << "darksteelbox_withdraw_2_end"; 
			break;
		case mpe_occupationwar_schedule_type::darksteelbox_staking_ranking:
			out << "darksteelbox_staking_ranking"; 
			break;
		case mpe_occupationwar_schedule_type::occupationwar_darkstee_tax:
			out << "occupationwar_darkstee_tax"; 
			break;
		case mpe_occupationwar_schedule_type::occupationwar_challenge_start:
			out << "occupationwar_challenge_start"; 
			break;
		case mpe_occupationwar_schedule_type::occupationwar_challenge_end:
			out << "occupationwar_challenge_end"; 
			break;
		case mpe_occupationwar_schedule_type::occupationwar_war_noti:
			out << "occupationwar_war_noti"; 
			break;
		case mpe_occupationwar_schedule_type::occupationwar_war_start:
			out << "occupationwar_war_start"; 
			break;
		case mpe_occupationwar_schedule_type::occupationwar_war_end:
			out << "occupationwar_war_end"; 
			break;
		case mpe_occupationwar_schedule_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_recipe_type& value)
	{
		switch (value)
		{
		case mpe_recipe_type::none:
			out << "none"; 
			break;
		case mpe_recipe_type::recipe_type_account:
			out << "recipe_type_account"; 
			break;
		case mpe_recipe_type::recipe_type_character:
			out << "recipe_type_character"; 
			break;
		case mpe_recipe_type::recipe_type_server:
			out << "recipe_type_server"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_governance_result& value)
	{
		switch (value)
		{
		case mpe_governance_result::none:
			out << "none"; 
			break;
		case mpe_governance_result::staking_success:
			out << "staking_success"; 
			break;
		case mpe_governance_result::staking_fail:
			out << "staking_fail"; 
			break;
		case mpe_governance_result::unstaking_success:
			out << "unstaking_success"; 
			break;
		case mpe_governance_result::unstaking_fail:
			out << "unstaking_fail"; 
			break;
		case mpe_governance_result::not_choosed_staking_server:
			out << "not_choosed_staking_server"; 
			break;
		case mpe_governance_result::not_choosed_unstaking_server:
			out << "not_choosed_unstaking_server"; 
			break;
		case mpe_governance_result::success_login:
			out << "success_login"; 
			break;
		case mpe_governance_result::success_first_login:
			out << "success_first_login"; 
			break;
		case mpe_governance_result::fail_already_another_connected:
			out << "fail_already_another_connected"; 
			break;
		case mpe_governance_result::fail_login_overlap:
			out << "fail_login_overlap"; 
			break;
		case mpe_governance_result::fail_contract:
			out << "fail_contract"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_governance_contents_type& value)
	{
		switch (value)
		{
		case mpe_governance_contents_type::none:
			out << "none"; 
			break;
		case mpe_governance_contents_type::boss:
			out << "boss"; 
			break;
		case mpe_governance_contents_type::occupationwar:
			out << "occupationwar"; 
			break;
		case mpe_governance_contents_type::siegewar:
			out << "siegewar"; 
			break;
		case mpe_governance_contents_type::party:
			out << "party"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_coin_staking_type& value)
	{
		switch (value)
		{
		case mpe_coin_staking_type::none:
			out << "none"; 
			break;
		case mpe_coin_staking_type::staking:
			out << "staking"; 
			break;
		case mpe_coin_staking_type::unstaking:
			out << "unstaking"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_exchange_type& value)
	{
		switch (value)
		{
		case mpe_exchange_type::server:
			out << "server"; 
			break;
		case mpe_exchange_type::world:
			out << "world"; 
			break;
		case mpe_exchange_type::world_gold:
			out << "world_gold"; 
			break;
		case mpe_exchange_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_token_type& value)
	{
		switch (value)
		{
		case mpe_token_type::none:
			out << "none"; 
			break;
		case mpe_token_type::drone:
			out << "drone"; 
			break;
		case mpe_token_type::hydra:
			out << "hydra"; 
			break;
		case mpe_token_type::dogma:
			out << "dogma"; 
			break;
		case mpe_token_type::wemix_doller:
			out << "wemix_doller"; 
			break;
		case mpe_token_type::swap_range_start:
			out << "swap_range_start"; 
			break;
		case mpe_token_type::w_flero:
			out << "w_flero"; 
			break;
		case mpe_token_type::w_sloco:
			out << "w_sloco"; 
			break;
		case mpe_token_type::w_lordcoin:
			out << "w_lordcoin"; 
			break;
		case mpe_token_type::w_herco:
			out << "w_herco"; 
			break;
		case mpe_token_type::w_gbmilico:
			out << "w_gbmilico"; 
			break;
		case mpe_token_type::w_mco:
			out << "w_mco"; 
			break;
		case mpe_token_type::w_tornado_token:
			out << "w_tornado_token"; 
			break;
		case mpe_token_type::w_tig:
			out << "w_tig"; 
			break;
		case mpe_token_type::w_stc:
			out << "w_stc"; 
			break;
		case mpe_token_type::w_ros_silthereum:
			out << "w_ros_silthereum"; 
			break;
		case mpe_token_type::w_ranaia_ria:
			out << "w_ranaia_ria"; 
			break;
		case mpe_token_type::w_reflect_token:
			out << "w_reflect_token"; 
			break;
		case mpe_token_type::w_wemix_token_away:
			out << "w_wemix_token_away"; 
			break;
		case mpe_token_type::w_four_gods_lux:
			out << "w_four_gods_lux"; 
			break;
		case mpe_token_type::w_incar:
			out << "w_incar"; 
			break;
		case mpe_token_type::w_mir4_hydra:
			out << "w_mir4_hydra"; 
			break;
		case mpe_token_type::w_honco:
			out << "w_honco"; 
			break;
		case mpe_token_type::w_drone:
			out << "w_drone"; 
			break;
		case mpe_token_type::w_mir4_darksteel:
			out << "w_mir4_darksteel"; 
			break;
		case mpe_token_type::w_dogma:
			out << "w_dogma"; 
			break;
		case mpe_token_type::w_darkeden_mdebco:
			out << "w_darkeden_mdebco"; 
			break;
		case mpe_token_type::w_cqb:
			out << "w_cqb"; 
			break;
		case mpe_token_type::w_blz:
			out << "w_blz"; 
			break;
		case mpe_token_type::w_asu_anitas:
			out << "w_asu_anitas"; 
			break;
		case mpe_token_type::w_abyco:
			out << "w_abyco"; 
			break;
		case mpe_token_type::w_myrtle:
			out << "w_myrtle"; 
			break;
		case mpe_token_type::w_bluepaw:
			out << "w_bluepaw"; 
			break;
		case mpe_token_type::w_zuanshi:
			out << "w_zuanshi"; 
			break;
		case mpe_token_type::swap_range_end:
			out << "swap_range_end"; 
			break;
		case mpe_token_type::dogma_shop:
			out << "dogma_shop"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_contract_type& value)
	{
		switch (value)
		{
		case mpe_contract_type::none:
			out << "none"; 
			break;
		case mpe_contract_type::drone:
			out << "drone"; 
			break;
		case mpe_contract_type::hydra:
			out << "hydra"; 
			break;
		case mpe_contract_type::divine:
			out << "divine"; 
			break;
		case mpe_contract_type::governonce:
			out << "governonce"; 
			break;
		case mpe_contract_type::exchange:
			out << "exchange"; 
			break;
		case mpe_contract_type::swap:
			out << "swap"; 
			break;
		case mpe_contract_type::dogma:
			out << "dogma"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_exchange_history_type& value)
	{
		switch (value)
		{
		case mpe_exchange_history_type::sell:
			out << "sell"; 
			break;
		case mpe_exchange_history_type::buy:
			out << "buy"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_token_history_type& value)
	{
		switch (value)
		{
		case mpe_token_history_type::none:
			out << "none"; 
			break;
		case mpe_token_history_type::smelter:
			out << "smelter"; 
			break;
		case mpe_token_history_type::devine_staking:
			out << "devine_staking"; 
			break;
		case mpe_token_history_type::boss_governnance:
			out << "boss_governnance"; 
			break;
		case mpe_token_history_type::occupationwar_governnance:
			out << "occupationwar_governnance"; 
			break;
		case mpe_token_history_type::party_governance:
			out << "party_governance"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_token_history_case& value)
	{
		switch (value)
		{
		case mpe_token_history_case::none:
			out << "none"; 
			break;
		case mpe_token_history_case::smelter_success:
			out << "smelter_success"; 
			break;
		case mpe_token_history_case::smelter_failure:
			out << "smelter_failure"; 
			break;
		case mpe_token_history_case::smelter_exchange_success:
			out << "smelter_exchange_success"; 
			break;
		case mpe_token_history_case::devine_staking_drone:
			out << "devine_staking_drone"; 
			break;
		case mpe_token_history_case::devine_staking_hydra:
			out << "devine_staking_hydra"; 
			break;
		case mpe_token_history_case::devine_staking_dogam:
			out << "devine_staking_dogam"; 
			break;
		case mpe_token_history_case::governnance_vote_success:
			out << "governnance_vote_success"; 
			break;
		case mpe_token_history_case::governnance_vote_failure:
			out << "governnance_vote_failure"; 
			break;
		case mpe_token_history_case::governnance_collect_success:
			out << "governnance_collect_success"; 
			break;
		case mpe_token_history_case::governnance_collect_failure:
			out << "governnance_collect_failure"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_language_type& value)
	{
		switch (value)
		{
		case mpe_language_type::cs:
			out << "cs"; 
			break;
		case mpe_language_type::ct:
			out << "ct"; 
			break;
		case mpe_language_type::DE:
			out << "DE"; 
			break;
		case mpe_language_type::EN:
			out << "EN"; 
			break;
		case mpe_language_type::ESLATAM:
			out << "ESLATAM"; 
			break;
		case mpe_language_type::ID:
			out << "ID"; 
			break;
		case mpe_language_type::JA:
			out << "JA"; 
			break;
		case mpe_language_type::KO:
			out << "KO"; 
			break;
		case mpe_language_type::PTBR:
			out << "PTBR"; 
			break;
		case mpe_language_type::RU:
			out << "RU"; 
			break;
		case mpe_language_type::TH:
			out << "TH"; 
			break;
		case mpe_language_type::VI:
			out << "VI"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_global_party_governance_rank_type& value)
	{
		switch (value)
		{
		case mpe_global_party_governance_rank_type::my:
			out << "my"; 
			break;
		case mpe_global_party_governance_rank_type::now:
			out << "now"; 
			break;
		case mpe_global_party_governance_rank_type::result:
			out << "result"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_gameserver_type& value)
	{
		switch (value)
		{
		case mpe_gameserver_type::game:
			out << "game"; 
			break;
		case mpe_gameserver_type::community:
			out << "community"; 
			break;
		case mpe_gameserver_type::gate:
			out << "gate"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_account_category& value)
	{
		switch (value)
		{
		case mpe_account_category::usual:
			out << "usual"; 
			break;
		case mpe_account_category::comeback:
			out << "comeback"; 
			break;
		case mpe_account_category::newbie:
			out << "newbie"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_server_relocate_type& value)
	{
		switch (value)
		{
		case mpe_server_relocate_type::none:
			out << "none"; 
			break;
		case mpe_server_relocate_type::period:
			out << "period"; 
			break;
		case mpe_server_relocate_type::datetime:
			out << "datetime"; 
			break;
		case mpe_server_relocate_type::level:
			out << "level"; 
			break;
		case mpe_server_relocate_type::location:
			out << "location"; 
			break;
		case mpe_server_relocate_type::party:
			out << "party"; 
			break;
		case mpe_server_relocate_type::guild:
			out << "guild"; 
			break;
		case mpe_server_relocate_type::exchange:
			out << "exchange"; 
			break;
		case mpe_server_relocate_type::store:
			out << "store"; 
			break;
		case mpe_server_relocate_type::governance:
			out << "governance"; 
			break;
		case mpe_server_relocate_type::arena:
			out << "arena"; 
			break;
		case mpe_server_relocate_type::mail:
			out << "mail"; 
			break;
		case mpe_server_relocate_type::street_stall:
			out << "street_stall"; 
			break;
		case mpe_server_relocate_type::death_info:
			out << "death_info"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_dimension_dungeon_gate_state_type& value)
	{
		switch (value)
		{
		case mpe_dimension_dungeon_gate_state_type::none:
			out << "none"; 
			break;
		case mpe_dimension_dungeon_gate_state_type::activate:
			out << "activate"; 
			break;
		case mpe_dimension_dungeon_gate_state_type::boss_summon:
			out << "boss_summon"; 
			break;
		case mpe_dimension_dungeon_gate_state_type::deactivate:
			out << "deactivate"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_dimension_dungeon_schedule_type& value)
	{
		switch (value)
		{
		case mpe_dimension_dungeon_schedule_type::none:
			out << "none"; 
			break;
		case mpe_dimension_dungeon_schedule_type::pre_open:
			out << "pre_open"; 
			break;
		case mpe_dimension_dungeon_schedule_type::open:
			out << "open"; 
			break;
		case mpe_dimension_dungeon_schedule_type::close:
			out << "close"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_blood_dedicate_worldboss_state& value)
	{
		switch (value)
		{
		case mpe_blood_dedicate_worldboss_state::none:
			out << "none"; 
			break;
		case mpe_blood_dedicate_worldboss_state::ready:
			out << "ready"; 
			break;
		case mpe_blood_dedicate_worldboss_state::summon:
			out << "summon"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_gm_blood_dedicate_worldboss_type& value)
	{
		switch (value)
		{
		case mpe_gm_blood_dedicate_worldboss_type::none:
			out << "none"; 
			break;
		case mpe_gm_blood_dedicate_worldboss_type::contribution_increase:
			out << "contribution_increase"; 
			break;
		case mpe_gm_blood_dedicate_worldboss_type::summon:
			out << "summon"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_guild_ally_alert_type& value)
	{
		switch (value)
		{
		case mpe_guild_ally_alert_type::none:
			out << "none"; 
			break;
		case mpe_guild_ally_alert_type::ally:
			out << "ally"; 
			break;
		case mpe_guild_ally_alert_type::ally_cancel:
			out << "ally_cancel"; 
			break;
		case mpe_guild_ally_alert_type::ally_request_received:
			out << "ally_request_received"; 
			break;
		case mpe_guild_ally_alert_type::ally_request_denied:
			out << "ally_request_denied"; 
			break;
		case mpe_guild_ally_alert_type::ally_member_update:
			out << "ally_member_update"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_restore_event_type& value)
	{
		switch (value)
		{
		case mpe_restore_event_type::reflection:
			out << "reflection"; 
			break;
		case mpe_restore_event_type::pet:
			out << "pet"; 
			break;
		case mpe_restore_event_type::weapon:
			out << "weapon"; 
			break;
		case mpe_restore_event_type::armor:
			out << "armor"; 
			break;
		case mpe_restore_event_type::helmet:
			out << "helmet"; 
			break;
		case mpe_restore_event_type::shoes:
			out << "shoes"; 
			break;
		case mpe_restore_event_type::necklace:
			out << "necklace"; 
			break;
		case mpe_restore_event_type::ring:
			out << "ring"; 
			break;
		case mpe_restore_event_type::belt:
			out << "belt"; 
			break;
		case mpe_restore_event_type::bracelet:
			out << "bracelet"; 
			break;
		case mpe_restore_event_type::paid_acc:
			out << "paid_acc"; 
			break;
		case mpe_restore_event_type::max:
			out << "max"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_season_mandala_state& value)
	{
		switch (value)
		{
		case mpe_season_mandala_state::none:
			out << "none"; 
			break;
		case mpe_season_mandala_state::open:
			out << "open"; 
			break;
		case mpe_season_mandala_state::close:
			out << "close"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_contents_onoff_mandala_type& value)
	{
		switch (value)
		{
		case mpe_contents_onoff_mandala_type::none:
			out << "none"; 
			break;
		case mpe_contents_onoff_mandala_type::character_and_master:
			out << "character_and_master"; 
			break;
		case mpe_contents_onoff_mandala_type::season:
			out << "season"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_season_mandala_reward_receive_type& value)
	{
		switch (value)
		{
		case mpe_season_mandala_reward_receive_type::none:
			out << "none"; 
			break;
		case mpe_season_mandala_reward_receive_type::reward_acceptable:
			out << "reward_acceptable"; 
			break;
		case mpe_season_mandala_reward_receive_type::reward_received:
			out << "reward_received"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

	static std::ostream& operator << (std::ostream& out, const mpe_chained_buff_name& value)
	{
		switch (value)
		{
		case mpe_chained_buff_name::none:
			out << "none"; 
			break;
		case mpe_chained_buff_name::expert_buff:
			out << "expert_buff"; 
			break;
		default:
			out << "Unknow";
		}
		return out;
	}

}
