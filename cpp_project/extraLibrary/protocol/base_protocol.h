#pragma once
#include <network/serialize/serialize_type.h>

namespace mir3d
{
	enum class mpe_cmd	// 패킷인포
	{
		none = 0,
		login_gamelogin_cs = 1,
		login_gamelogin_sc = 2,
		game_login_cs = 3,
		game_login_sc = 4,
		session_certify_cs = 5,
		session_certify_sc = 6,
		session_open_cs = 7,
		session_open_sc = 8,
		zone_enter_cs = 9,
		zone_enter_sc = 10,
		zone_enter_ready_cs = 11,
		zone_enter_ready_sc = 12,
		zone_object_loding_cs = 13,
		zone_object_loding_sc = 14,
		zone_leave_cs = 15,
		zone_leave_sc = 16,
		zone_move_cs = 17,
		zone_move_sc = 18,
		zone_tile_check_cs = 19,
		zone_tile_check_sc = 20,
		zone_object_move_cs = 21,
		zone_object_move_sc = 22,
		skill_start_cs = 23,
		skill_start_sc = 24,
		skill_damage_result_cs = 25,
		skill_damage_result_sc = 26,
		error_message_cs = 27,
		error_message_sc = 28,
		character_behavior_cs = 29,
		character_behavior_sc = 30,
		character_pk_color_cs = 31,
		character_pk_color_sc = 32,
		character_power_cs = 33,
		character_power_sc = 34,
		gameitem_update_cs = 35,
		gameitem_update_sc = 36,
		goods_update_cs = 39,
		goods_update_sc = 40,
		indun_enter_cs = 41,
		indun_enter_sc = 42,
		indun_enter_complete_cs = 43,
		indun_enter_complete_sc = 44,
		inven_expansion_cs = 45,
		inven_expansion_sc = 46,
		inven_weight_expansion_cs = 47,
		inven_weight_expansion_sc = 48,
		item_buy_cs = 49,
		item_buy_sc = 50,
		item_enchant_option_make_cs = 51,
		item_enchant_option_make_sc = 52,
		item_enchant_option_select_cs = 53,
		item_enchant_option_select_sc = 54,
		item_decompose_cs = 61,
		item_decompose_sc = 62,
		item_destroy_cs = 63,
		item_destroy_sc = 64,
		item_enchant_option_cancel_cs = 65,
		item_enchant_option_cancel_sc = 66,
		item_equip_cs = 67,
		item_equip_sc = 68,
		item_luck_reinforce_cs = 69,
		item_luck_reinforce_sc = 70,
		item_make_cs = 71,
		item_make_sc = 72,
		item_reinforce_cs = 73,
		item_reinforce_sc = 74,
		item_sell_cs = 75,
		item_sell_sc = 76,
		item_use_cs = 77,
		item_use_sc = 78,
		map_discovery_info_cs = 79,
		map_discovery_info_sc = 80,
		map_discovery_update_cs = 81,
		map_discovery_update_sc = 82,
		profesion_make_cs = 83,
		profesion_make_sc = 84,
		profesion_reset_cs = 85,
		profesion_reset_sc = 86,
		profesion_upgrade_cs = 87,
		profesion_upgrade_sc = 88,
		redirect_notify_cs = 89,
		redirect_notify_sc = 90,
		redirect_request_cs = 91,
		redirect_request_sc = 92,
		test_game_login_cs = 93,
		test_game_login_sc = 94,
		zone_change_enter_cs = 95,
		zone_change_enter_sc = 96,
		zone_character_drop_cs = 97,
		zone_character_drop_sc = 98,
		zone_character_item_equip_cs = 99,
		zone_character_item_equip_sc = 100,
		zone_character_minion_info_cs = 101,
		zone_character_minion_info_sc = 102,
		zone_collect_info_cs = 103,
		zone_collect_info_sc = 104,
		zone_dropitem_remove_cs = 105,
		zone_dropitem_remove_sc = 106,
		zone_drop_item_info_cs = 107,
		zone_drop_item_info_sc = 108,
		zone_item_pickup_cs = 109,
		zone_item_pickup_sc = 110,
		zone_monster_info_cs = 111,
		zone_monster_info_sc = 112,
		zone_npc_info_cs = 113,
		zone_npc_info_sc = 114,
		zone_object_collect_cs = 115,
		zone_object_collect_sc = 116,
		zone_object_dead_cs = 117,
		zone_object_dead_sc = 118,
		zone_player_info_cs = 119,
		zone_player_info_sc = 120,
		zone_revive_cs = 121,
		zone_revive_sc = 122,
		zone_teleport_cs = 123,
		zone_teleport_sc = 124,
		zone_safety_state_cs = 125,
		zone_safety_state_sc = 126,
		guild_create_cs = 127,
		guild_create_sc = 128,
		guild_join_request_cs = 129,
		guild_join_request_sc = 130,
		guild_accept_member_cs = 131,
		guild_accept_member_sc = 132,
		guild_join_cancel_cs = 133,
		guild_join_cancel_sc = 134,
		guild_recommend_cs = 135,
		guild_recommend_sc = 136,
		guild_request_guild_list_cs = 137,
		guild_request_guild_list_sc = 138,
		guild_add_exp_cs = 139,
		guild_add_exp_sc = 140,
		guild_member_list_cs = 141,
		guild_member_list_sc = 142,
		guild_info_cs = 143,
		guild_info_sc = 144,
		guild_ban_cs = 145,
		guild_ban_sc = 146,
		guild_leave_cs = 147,
		guild_leave_sc = 148,
		guild_search_cs = 149,
		guild_search_sc = 150,
		guild_change_join_condition_cs = 151,
		guild_change_join_condition_sc = 152,
		guild_change_member_grade_cs = 153,
		guild_change_member_grade_sc = 154,
		party_create_cs = 155,
		party_create_sc = 156,
		party_info_cs = 157,
		party_info_sc = 158,
		party_invite_request_cs = 159,
		party_invite_request_sc = 160,
		party_invite_agree_cs = 161,
		party_invite_agree_sc = 162,
		party_invite_cancel_cs = 163,
		party_invite_cancel_sc = 164,
		party_invite_refuse_cs = 165,
		party_invite_refuse_sc = 166,
		party_enter_request_cs = 167,
		party_enter_request_sc = 168,
		party_enter_cancel_cs = 169,
		party_enter_cancel_sc = 170,
		party_enter_agree_sc = 171,
		party_enter_agree_cs = 172,
		party_enter_refuse_cs = 173,
		party_enter_refuse_sc = 174,
		party_destroy_cs = 175,
		party_destroy_sc = 176,
		party_pr_cs = 177,
		party_pr_sc = 178,
		party_leave_cs = 179,
		party_leave_sc = 180,
		party_member_ban_cs = 181,
		party_member_ban_sc = 182,
		party_owner_change_cs = 183,
		party_owner_change_sc = 184,
		party_enter_request_list_cs = 185,
		party_enter_request_list_sc = 186,
		party_enter_requestors_cs = 187,
		party_enter_requestors_sc = 188,
		party_setup_cs = 189,
		party_setup_sc = 190,
		indun_prepare_request_cs = 191,
		indun_prepare_request_sc = 192,
		indun_prepare_enter_cs = 193,
		indun_prepare_enter_sc = 194,
		indun_stage_cs = 195,
		indun_stage_sc = 196,
		indun_leave_cs = 197,
		indun_leave_sc = 198,
		indun_reward_cs = 199,
		indun_reward_sc = 200,
		indun_finish_cs = 201,
		indun_finish_sc = 202,
		indun_stage_count_cs = 203,
		indun_stage_count_sc = 204,
		indun_stage_complete_cs = 205,
		indun_stage_complete_sc = 206,
		zone_object_update_stat_cs = 207,
		zone_object_update_stat_sc = 208,
		zone_delete_buff_debuff_cs = 209,
		zone_delete_buff_debuff_sc = 210,
		zone_vehicle_cs = 211,
		zone_vehicle_sc = 212,
		zone_vehicle_state_cs = 213,
		zone_vehicle_state_sc = 214,
		zone_character_level_up_cs = 215,
		zone_character_level_up_sc = 216,
		zone_character_expert_level_up_cs = 217,
		zone_character_expert_level_up_sc = 218,
		skill_learn_cs = 221,
		skill_learn_sc = 222,
		skill_levelup_cs = 223,
		skill_levelup_sc = 224,
		game_logout_cs = 227,
		game_logout_sc = 228,
		quest_accept_cs = 229,
		quest_accept_sc = 230,
		quest_complete_cs = 231,
		quest_complete_sc = 232,
		quest_giveup_cs = 233,
		quest_giveup_sc = 234,
		quest_finish_cs = 235,
		quest_finish_sc = 236,
		server_change_cs = 237,
		server_change_sc = 238,
		redirect_complete_cs = 239,
		redirect_complete_sc = 240,
		zone_fish_cs = 241,
		zone_fish_sc = 242,
		zone_action_fish_cs = 243,
		zone_action_fish_sc = 244,
		zone_daily_content_cs = 245,
		zone_daily_content_sc = 246,
		zone_action_state_cs = 247,
		zone_action_state_sc = 248,
		zone_fieldboss_info_cs = 249,
		zone_fieldboss_info_sc = 250,
		zone_boss_contribution_cs = 251,
		zone_boss_contribution_sc = 252,
		zone_boss_dead_cs = 253,
		zone_boss_dead_sc = 254,
		zone_trigger_cs = 255,
		zone_trigger_sc = 256,
		game_setup_cs = 257,
		game_setup_sc = 258,
		exchange_register_cs = 259,
		exchange_register_sc = 260,
		exchange_register_cancel_cs = 261,
		exchange_register_cancel_sc = 262,
		exchange_gold_withdraw_cs = 263,
		exchange_gold_withdraw_sc = 264,
		exchange_buy_cs = 265,
		exchange_buy_sc = 266,
		exchange_item_withdraw_cs = 267,
		exchange_item_withdraw_sc = 268,
		chatting_cs = 269,
		chatting_sc = 270,
		pk_setup_cs = 271,
		pk_setup_sc = 272,
		mail_open_cs = 273,
		mail_open_sc = 274,
		mail_receive_item_cs = 275,
		mail_receive_item_sc = 276,
		mail_delete_cs = 277,
		mail_delete_sc = 278,
		mail_send_cs = 279,
		mail_send_sc = 280,
		meridians_levelup_cs = 281,
		meridians_levelup_sc = 282,
		acupoints_levelup_cs = 283,
		acupoints_levelup_sc = 284,
		zone_move_error_cs = 287,
		zone_move_error_sc = 288,
		zone_object_return_cs = 289,
		zone_object_return_sc = 290,
		guild_destroy_cs = 291,
		guild_destroy_sc = 292,
		guild_request_member_list_cs = 293,
		guild_request_member_list_sc = 294,
		guild_donation_cs = 295,
		guild_donation_sc = 296,
		repute_quest_finish_count_reset_cs = 297,
		repute_quest_finish_count_reset_sc = 298,
		guild_start_war_cs = 299,
		guild_start_war_sc = 300,
		guild_try_surrender_cs = 301,
		guild_try_surrender_sc = 302,
		guild_respond_surrender_cs = 303,
		guild_respond_surrender_sc = 304,
		storage_open_cs = 305,
		storage_open_sc = 306,
		storage_move_cs = 307,
		storage_move_sc = 308,
		account_storage_buy_cs = 309,
		account_storage_buy_sc = 310,
		storage_expand_cs = 311,
		storage_expand_sc = 312,
		storage_goods_move_cs = 313,
		storage_goods_move_sc = 314,
		attack_speed_cs = 315,
		attack_speed_sc = 316,
		indun_play_count_request_cs = 317,
		indun_play_count_request_sc = 318,
		indun_auto_matching_complete_cs = 319,
		indun_auto_matching_complete_sc = 320,
		personal_trade_apply_cs = 321,
		personal_trade_apply_sc = 322,
		personal_trade_accept_cs = 323,
		personal_trade_accept_sc = 324,
		personal_trade_refuse_cs = 325,
		personal_trade_refuse_sc = 326,
		personal_trade_start_cs = 327,
		personal_trade_start_sc = 328,
		personal_trade_item_register_cs = 329,
		personal_trade_item_register_sc = 330,
		personal_trade_item_remove_cs = 331,
		personal_trade_item_remove_sc = 332,
		personal_trade_set_lock_cs = 333,
		personal_trade_set_lock_sc = 334,
		personal_trade_cancel_cs = 335,
		personal_trade_cancel_sc = 336,
		personal_trade_confirm_cs = 337,
		personal_trade_confirm_sc = 338,
		party_vote_request_cs = 339,
		party_vote_request_sc = 340,
		party_vote_reply_cs = 341,
		party_vote_reply_sc = 342,
		party_vote_result_cs = 343,
		party_vote_result_sc = 344,
		guild_storage_material_list_cs = 345,
		guild_storage_material_list_sc = 346,
		guild_war_list_cs = 347,
		guild_war_list_sc = 348,
		indun_auto_matching_cancel_cs = 349,
		indun_auto_matching_cancel_sc = 350,
		item_repair_cs = 351,
		item_repair_sc = 352,
		decrement_item_durability_cs = 353,
		decrement_item_durability_sc = 354,
		guild_item_donation_cs = 355,
		guild_item_donation_sc = 356,
		skill_passive_levelup_cs = 357,
		skill_passive_levelup_sc = 358,
		force_recovery_cs = 359,
		force_recovery_sc = 360,
		guild_alert_surrender_cs = 361,
		guild_alert_surrender_sc = 362,
		guild_alert_start_war_cs = 363,
		guild_alert_start_war_sc = 364,
		zone_verify_move_cs = 365,
		zone_verify_move_sc = 366,
		guild_alert_reject_surrender_cs = 367,
		guild_alert_reject_surrender_sc = 368,
		guild_alert_join_request_cs = 369,
		guild_alert_join_request_sc = 370,
		guild_alert_join_request_cancel_cs = 371,
		guild_alert_join_request_cancel_sc = 372,
		guild_alert_join_cs = 373,
		guild_alert_join_sc = 374,
		guild_alert_join_request_result_cs = 375,
		guild_alert_join_request_result_sc = 376,
		guild_alert_leave_cs = 377,
		guild_alert_leave_sc = 378,
		guild_alert_ban_for_member_cs = 379,
		guild_alert_ban_for_member_sc = 380,
		guild_alert_ban_cs = 381,
		guild_alert_ban_sc = 382,
		guild_alert_change_grade_cs = 383,
		guild_alert_change_grade_sc = 384,
		guild_alert_end_war_cs = 385,
		guild_alert_end_war_sc = 386,
		guild_alert_add_exp_cs = 387,
		guild_alert_add_exp_sc = 388,
		condition_refill_cs = 389,
		condition_refill_sc = 390,
		party_teleport_cs = 391,
		party_teleport_sc = 392,
		party_teleport_reply_cs = 393,
		party_teleport_reply_sc = 394,
		check_indun_enter_condition_cs = 395,
		check_indun_enter_condition_sc = 396,
		indun_enter_pay_cs = 397,
		indun_enter_pay_sc = 398,
		summon_recall_cs = 399,
		summon_recall_sc = 400,
		siege_warfare_submit_tender_cs = 401,
		siege_warfare_submit_tender_sc = 402,
		siege_warfare_alert_cs = 403,
		siege_warfare_alert_sc = 404,
		siege_warfare_alliance_request_cs = 405,
		siege_warfare_alliance_request_sc = 406,
		siege_warfare_alliance_cancel_cs = 407,
		siege_warfare_alliance_cancel_sc = 408,
		siege_warfare_alliance_response_cs = 409,
		siege_warfare_alliance_response_sc = 410,
		siege_warfare_alliance_kickout_cs = 411,
		siege_warfare_alliance_kickout_sc = 412,
		siege_warfare_alliance_withdrawal_cs = 413,
		siege_warfare_alliance_withdrawal_sc = 414,
		castle_set_tax_rate_cs = 415,
		castle_set_tax_rate_sc = 416,
		castle_set_tax_distribution_cs = 417,
		castle_set_tax_distribution_sc = 418,
		siege_warfare_atk_build_machine_cs = 419,
		siege_warfare_atk_build_machine_sc = 420,
		siege_warfare_def_build_machine_cs = 421,
		siege_warfare_def_build_machine_sc = 422,
		siege_warfare_atk_release_machine_cs = 423,
		siege_warfare_atk_release_machine_sc = 424,
		siege_warfare_def_release_machine_cs = 425,
		siege_warfare_def_release_machine_sc = 426,
		special_move_set_cs = 427,
		special_move_set_sc = 428,
		skill_use_cs = 429,
		skill_use_sc = 430,
		special_move_start_cs = 431,
		special_move_start_sc = 432,
		guild_change_notice_cs = 433,
		guild_change_notice_sc = 434,
		guild_alert_change_notice_cs = 435,
		guild_alert_change_notice_sc = 436,
		indun_auto_matching_rematch_cs = 437,
		indun_auto_matching_rematch_sc = 438,
		siege_warfare_time_cs = 439,
		siege_warfare_time_sc = 440,
		guild_learn_skill_cs = 441,
		guild_learn_skill_sc = 442,
		guild_reset_skill_cs = 443,
		guild_reset_skill_sc = 444,
		guild_alert_learn_skill_cs = 445,
		guild_alert_learn_skill_sc = 446,
		guild_alert_reset_skill_cs = 447,
		guild_alert_reset_skill_sc = 448,
		guild_skill_list_cs = 449,
		guild_skill_list_sc = 450,
		guild_alert_donation_cs = 451,
		guild_alert_donation_sc = 452,
		indun_stage_start_cs = 453,
		indun_stage_start_sc = 454,
		guild_storage_supply_list_cs = 455,
		guild_storage_supply_list_sc = 456,
		guild_storage_supply_insert_item_cs = 457,
		guild_storage_supply_insert_item_sc = 458,
		guild_storage_supply_get_item_cs = 459,
		guild_storage_supply_get_item_sc = 460,
		chatting_system_cs = 461,
		chatting_system_sc = 462,
		guild_master_change_by_non_connected_cs = 463,	// "장기 미접속 문파장 위임 요청"
		guild_master_change_by_non_connected_sc = 464,	// "장기 미접속 문파장 위임 요청 응답"
		guild_storage_share_list_cs = 465,
		guild_storage_share_list_sc = 466,
		guild_storage_share_insert_item_cs = 467,
		guild_storage_share_insert_item_sc = 468,
		guild_storage_share_request_get_item_cs = 469,
		guild_storage_share_request_get_item_sc = 470,
		guild_storage_share_alert_request_get_item_cs = 471,
		guild_storage_share_alert_request_get_item_sc = 472,
		guild_storage_share_result_get_item_cs = 473,
		guild_storage_share_result_get_item_sc = 474,
		guild_storage_share_extend_cs = 475,
		guild_storage_share_extend_sc = 476,
		guild_storage_share_request_get_item_list_cs = 477,
		guild_storage_share_request_get_item_list_sc = 478,
		guild_storage_share_master_get_item_cs = 479,
		guild_storage_share_master_get_item_sc = 480,
		castle_town_return_cs = 481,
		castle_town_return_sc = 482,
		siege_tower_teleport_cs = 483,
		siege_tower_teleport_sc = 484,
		enchant_stone_slot_open_cs = 485,
		enchant_stone_slot_open_sc = 486,
		enchant_stone_equip_cs = 487,
		enchant_stone_equip_sc = 488,
		enchant_stone_upgrade_cs = 489,
		enchant_stone_upgrade_sc = 490,
		enchant_stone_compose_cs = 491,
		enchant_stone_compose_sc = 492,
		zone_siege_weapon_info_cs = 493,
		zone_siege_weapon_info_sc = 494,
		zone_fixed_object_info_cs = 495,
		zone_fixed_object_info_sc = 496,
		zone_mercenary_info_cs = 497,
		zone_mercenary_info_sc = 498,
		castle_town_work_use_character_item_cs = 499,
		castle_town_work_use_character_item_sc = 500,
		zone_siege_object_all_cs = 503,
		zone_siege_object_all_sc = 504,
		castle_town_work_cs = 505,
		castle_town_work_sc = 506,
		castle_town_house_fire_cs = 507,
		castle_town_house_fire_sc = 508,
		castle_town_arsenal_build_cs = 509,
		castle_town_arsenal_build_sc = 510,
		castle_town_arsenal_build_donate_cs = 511,
		castle_town_arsenal_build_donate_sc = 512,
		guild_storage_treasure_list_cs = 513,
		guild_storage_treasure_list_sc = 514,
		guild_storage_treasure_alert_lost_top_request_cs = 515,
		guild_storage_treasure_alert_lost_top_request_sc = 516,
		guild_storage_treasure_alert_auction_finish_cs = 517,
		guild_storage_treasure_alert_auction_finish_sc = 518,
		guild_storage_treasure_get_auction_cs = 519,
		guild_storage_treasure_get_auction_sc = 520,
		guild_storage_treasure_request_cs = 521,
		guild_storage_treasure_request_sc = 522,
		guild_dungeon_create_cs = 525,
		guild_dungeon_create_sc = 526,
		indun_siege_enter_test_cs = 527,
		indun_siege_enter_test_sc = 528,
		siege_object_phase_cs = 531,
		siege_object_phase_sc = 532,
		castle_town_arsenal_build_work_info_cs = 533,
		castle_town_arsenal_build_work_info_sc = 534,
		castle_town_arsenal_build_end_cs = 535,
		castle_town_arsenal_build_end_sc = 536,
		guild_storage_treasure_confirm_auction_cs = 539,
		guild_storage_treasure_confirm_auction_sc = 540,
		castle_town_start_specialties_cs = 541,
		castle_town_start_specialties_sc = 542,
		castle_town_start_specialties_delivery_cs = 543,
		castle_town_start_specialties_delivery_sc = 544,
		guild_enemy_list_cs = 551,
		guild_enemy_list_sc = 552,
		game_reconnect_cs = 553,
		game_reconnect_sc = 554,
		guild_register_master_order_quest_cs = 555,
		guild_register_master_order_quest_sc = 556,
		guild_alert_register_master_order_quest_cs = 557,
		guild_alert_register_master_order_quest_sc = 558,
		guild_alert_finish_master_order_quest_cs = 559,
		guild_alert_finish_master_order_quest_sc = 560,
		guild_town_boss_summon_cs = 561,
		guild_town_boss_summon_sc = 562,
		zone_treasure_box_info_cs = 563,
		zone_treasure_box_info_sc = 564,
		zone_treasure_box_open_cs = 565,
		zone_treasure_box_open_sc = 566,
		zone_gold_treasure_box_info_cs = 567,
		zone_gold_treasure_box_info_sc = 568,
		castle_town_start_dinner_cs = 569,
		castle_town_start_dinner_sc = 570,
		castle_town_dinner_get_item_cs = 571,
		castle_town_dinner_get_item_sc = 572,
		castle_town_hud_info_cs = 573,
		castle_town_hud_info_sc = 574,
		pet_equip_cs = 575,
		pet_equip_sc = 576,
		pet_feed_cs = 577,
		pet_feed_sc = 578,
		zone_monster_respawn_cs = 579,
		zone_monster_respawn_sc = 580,
		vehicle_add_cs = 581,
		vehicle_add_sc = 582,
		vehicle_equip_cs = 583,
		vehicle_equip_sc = 584,
		vehicle_food_cs = 585,
		vehicle_food_sc = 586,
		vehicle_equip_item_cs = 587,
		vehicle_equip_item_sc = 588,
		vehicle_expire_cs = 589,
		vehicle_expire_sc = 590,
		randombox_open_cs = 591,
		randombox_open_sc = 592,
		zone_sector_move_cs = 593,
		zone_sector_move_sc = 594,
		zone_sector_teleport_cs = 595,
		zone_sector_teleport_sc = 596,
		castle_dungeon_entrance_fee_change_cs = 597,
		castle_dungeon_entrance_fee_change_sc = 598,
		guild_alert_create_dungeon_cs = 599,
		guild_alert_create_dungeon_sc = 600,
		monster_run_away_cs = 601,
		monster_run_away_sc = 602,
		guild_alert_dungeon_enter_cs = 603,
		guild_alert_dungeon_enter_sc = 604,
		title_equip_cs = 605,
		title_equip_sc = 606,
		pet_mix_cs = 607,
		pet_mix_sc = 608,
		castle_town_single_specialties_hud_cs = 609,
		castle_town_single_specialties_hud_sc = 610,
		test_game_server_cs = 611,
		test_game_server_sc = 612,
		pet_equip_broad_cs = 613,
		pet_equip_broad_sc = 614,
		zone_object_return_teleport_cs = 615,
		zone_object_return_teleport_sc = 616,
		guild_office_boss_summon_info_cs = 633,
		guild_office_boss_summon_info_sc = 634,
		siege_warfare_occupation_cs = 635,
		siege_warfare_occupation_sc = 636,
		siege_warfare_play_alert_cs = 637,
		siege_warfare_play_alert_sc = 638,
		pk_revenge_add_cs = 643,
		pk_revenge_add_sc = 644,
		pk_record_delete_cs = 645,
		pk_record_delete_sc = 646,
		pk_revenge_delete_cs = 647,
		pk_revenge_delete_sc = 648,
		pk_revenge_trace_cs = 649,
		pk_revenge_trace_sc = 650,
		pk_record_list_get_cs = 653,
		pk_record_list_get_sc = 654,
		friend_request_cs = 655,
		friend_request_sc = 656,
		friend_delete_cs = 657,
		friend_delete_sc = 658,
		friend_request_response_cs = 659,
		friend_request_response_sc = 660,
		friend_request_response_all_cs = 661,
		friend_request_response_all_sc = 662,
		pet_release_summon_broad_cs = 663,
		pet_release_summon_broad_sc = 664,
		mentor_register_cs = 665,
		mentor_register_sc = 666,
		mentor_request_cs = 667,
		mentor_request_sc = 668,
		mentor_buff_buy_cs = 669,
		mentor_buff_buy_sc = 670,
		mentor_buff_cs = 671,
		mentor_buff_sc = 672,
		mentor_response_cs = 673,
		mentor_response_sc = 674,
		friend_data_set_cs = 675,
		friend_data_set_sc = 676,
		title_add_cs = 677,
		title_add_sc = 678,
		dictionary_add_cs = 681,
		dictionary_add_sc = 682,
		dictionary_get_cs = 683,
		dictionary_get_sc = 684,
		character_expand_stat_add_attribute_cs = 685,
		character_expand_stat_add_attribute_sc = 686,
		wanted_murder_register_cs = 687,
		wanted_murder_register_sc = 688,
		empty1_cs = 689,
		empty1_sc = 690,
		empty2_cs = 691,
		empty2_sc = 692,
		wanted_murder_reward_cs = 693,
		wanted_murder_reward_sc = 694,
		wanted_murder_end_notify_cs = 695,
		wanted_murder_end_notify_sc = 696,
		zone_teleport_save_area_cs = 697,
		zone_teleport_save_area_sc = 698,
		zone_teleport_save_area_delete_cs = 699,
		zone_teleport_save_area_delete_sc = 700,
		zone_teleport_to_saved_area_cs = 701,
		zone_teleport_to_saved_area_sc = 702,
		zone_teleport_fixed_point_cs = 703,
		zone_teleport_fixed_point_sc = 704,
		zone_teleport_view_point_cs = 705,
		zone_teleport_view_point_sc = 706,
		show_costume_cs = 707,
		show_costume_sc = 708,
		pk_revenge_result_cs = 709,
		pk_revenge_result_sc = 710,
		wanted_murder_number_of_uses_cs = 711,
		wanted_murder_number_of_uses_sc = 712,
		guild_change_introduction_cs = 713,
		guild_change_introduction_sc = 714,
		guild_pr_cs = 715,
		guild_pr_sc = 716,
		tutorial_complete_cs = 717,
		tutorial_complete_sc = 718,
		guild_invite_cs = 719,
		guild_invite_sc = 720,
		guild_invite_accept_cs = 721,
		guild_invite_accept_sc = 722,
		guild_invite_refusal_cs = 723,
		guild_invite_refusal_sc = 724,
		guild_pr_notify_cs = 725,
		guild_pr_notify_sc = 726,
		guild_invite_notify_cs = 727,
		guild_invite_notify_sc = 728,
		teleport_arrive_cs = 729,
		teleport_arrive_sc = 730,
		dictionary_reward_get_cs = 731,
		dictionary_reward_get_sc = 732,
		dictionary_achieve_rate_get_cs = 733,
		dictionary_achieve_rate_get_sc = 734,
		dictionary_bookmark_get_cs = 735,
		dictionary_bookmark_get_sc = 736,
		dictionary_per_get_cs = 739,
		dictionary_per_get_sc = 740,
		achieve_get_cs = 741,
		achieve_get_sc = 742,
		dictionary_expire_cs = 743,
		dictionary_expire_sc = 744,
		paid_acc_reinforce_cs = 745,	// "유료 장신구 단일+다중 강화 요청."
		paid_acc_reinforce_sc = 746,	// "유료 장신구 단일+다중 강화 응답."
		ai_game_login_cs = 749,
		ai_game_login_sc = 750,
		ai_service_start_cs = 751,
		ai_service_start_sc = 752,
		community_login_cs = 753,
		community_login_sc = 754,
		zone_teleport_ai_return_cs = 755,
		zone_teleport_ai_return_sc = 756,
		cash_shop_buy_cs = 757,
		cash_shop_buy_sc = 758,
		cash_shop_info_cs = 759,
		cash_shop_info_sc = 760,
		cash_shop_cart_get_cs = 761,
		cash_shop_cart_get_sc = 762,
		server_time_cs = 771,
		server_time_sc = 772,
		ai_setup_config_cs = 773,
		ai_setup_config_sc = 774,
		cash_shop_exchange_reset_cs = 777,
		cash_shop_exchange_reset_sc = 778,
		cash_shop_limited_product_cs = 779,
		cash_shop_limited_product_sc = 780,
		indun_step_skip_cs = 781,
		indun_step_skip_sc = 782,
		indun_alert_skip_cs = 783,
		indun_alert_skip_sc = 784,
		guild_shipwar_info_cs = 785,
		guild_shipwar_info_sc = 786,
		guild_shipwar_request_cs = 787,
		guild_shipwar_request_sc = 788,
		guild_shipwar_flag_notify_cs = 793,
		guild_shipwar_flag_notify_sc = 794,
		guild_shipwar_situation_cs = 795,
		guild_shipwar_situation_sc = 796,
		guild_shipwar_team_info_cs = 797,
		guild_shipwar_team_info_sc = 798,
		guild_shipwar_play_notify_cs = 801,
		guild_shipwar_play_notify_sc = 802,
		red_dot_noti_cs = 805,
		red_dot_noti_sc = 806,
		chatting_block_cs = 807,
		chatting_block_sc = 808,
		chatting_block_list_cs = 809,
		chatting_block_list_sc = 810,
		private_chatting_state_cs = 811,
		private_chatting_state_sc = 812,
		cash_shop_daily_get_cs = 813,
		cash_shop_daily_get_sc = 814,
		town_rental_request_cs = 815,
		town_rental_request_sc = 816,
		town_alert_cs = 817,
		town_alert_sc = 818,
		town_rental_continuation_cs = 819,
		town_rental_continuation_sc = 820,
		schedule_info_list_cs = 821,
		schedule_info_list_sc = 822,
		transform_avatar_cs = 823,
		transform_avatar_sc = 824,
		release_avatar_cs = 825,
		release_avatar_sc = 826,
		mentor_party_buff_cs = 827,
		mentor_party_buff_sc = 828,
		guild_shipwar_match_failed_cs = 829,
		guild_shipwar_match_failed_sc = 830,
		subscription_info_cs = 833,
		subscription_info_sc = 834,
		dictionary_get_all_cs = 835,
		dictionary_get_all_sc = 836,
		npc_intimacy_add_cs = 837,
		npc_intimacy_add_sc = 838,
		reset_treasurebox_owner_cs = 839,
		reset_treasurebox_owner_sc = 840,
		revive_limit_cs = 841,
		revive_limit_sc = 842,
		zone_sector_info_cs = 843,
		zone_sector_info_sc = 844,
		summon_pet_cs = 845,
		summon_pet_sc = 846,
		summon_pet_broad_cs = 847,
		summon_pet_broad_sc = 848,
		ai_setup_config_info_cs = 849,
		ai_setup_config_info_sc = 850,
		empty3_cs = 851,
		empty3_sc = 852,
		zone_teleport_exit_cs = 853,
		zone_teleport_exit_sc = 854,
		siege_warfare_victory_character_info_cs = 855,
		siege_warfare_victory_character_info_sc = 856,
		siege_kill_death_cs = 857,
		siege_kill_death_sc = 858,
		zone_call_point_cs = 859,
		zone_call_point_sc = 860,
		special_move_gage_cs = 861,
		special_move_gage_sc = 862,
		enter_story_dungeon_cs = 863,
		enter_story_dungeon_sc = 864,
		leave_story_dungeon_cs = 865,
		leave_story_dungeon_sc = 866,
		trigger_story_dungeon_cs = 867,
		trigger_story_dungeon_sc = 868,
		move_story_dungeon_cs = 869,
		move_story_dungeon_sc = 870,
		npc_intimacy_reward_cs = 873,
		npc_intimacy_reward_sc = 874,
		skill_start_story_dungeon_cs = 875,
		skill_start_story_dungeon_sc = 876,
		object_state_story_dungeon_cs = 877,
		object_state_story_dungeon_sc = 878,
		zone_teleport_channel_move_cs = 879,
		zone_teleport_channel_move_sc = 880,
		slot_option_make_cs = 881,
		slot_option_make_sc = 882,
		slot_option_select_cs = 883,
		slot_option_select_sc = 884,
		slot_upgrade_cs = 885,
		slot_upgrade_sc = 886,
		npc_intimacy_reward_get_cs = 887,
		npc_intimacy_reward_get_sc = 888,
		friend_teleport_cs = 889,
		friend_teleport_sc = 890,
		treasureboxkey_charge_cs = 891,
		treasureboxkey_charge_sc = 892,
		skill_damage_story_dungeon_cs = 893,
		skill_damage_story_dungeon_sc = 894,
		change_pet_team_cs = 895,
		change_pet_team_sc = 896,
		guild_treasurebox_reward_cs = 897,
		guild_treasurebox_reward_sc = 898,
		wanted_murder_target_cs = 899,
		wanted_murder_target_sc = 900,
		wanted_murder_trace_cs = 901,
		wanted_murder_trace_sc = 902,
		heartbeat_check_cs = 903,
		heartbeat_check_sc = 904,
		seasonpass_change_cs = 905,
		seasonpass_change_sc = 906,
		seasonpass_unlock_cs = 907,
		seasonpass_unlock_sc = 908,
		seasonpass_reward_cs = 909,
		seasonpass_reward_sc = 910,
		seasonpass_challenge_complet_cs = 911,
		seasonpass_challenge_complet_sc = 912,
		seasonpass_challenge_update_cs = 913,
		seasonpass_challenge_update_sc = 914,
		guard_pass_buy_cs = 915,
		guard_pass_buy_sc = 916,
		pk_alert_record_remove_cs = 917,
		pk_alert_record_remove_sc = 918,
		avatar_mix_cs = 921,
		avatar_mix_sc = 922,
		avatar_slot_set_cs = 923,
		avatar_slot_set_sc = 924,
		castle_owner_info_cs = 925,
		castle_owner_info_sc = 926,
		guild_mark_change_cs = 927,
		guild_mark_change_sc = 928,
		guild_alert_change_mark_cs = 929,
		guild_alert_change_mark_sc = 930,
		avatar_cool_time_cs = 931,
		avatar_cool_time_sc = 932,
		guild_buff_buy_cs = 933,
		guild_buff_buy_sc = 934,
		guild_gold_alert_cs = 935,
		guild_gold_alert_sc = 936,
		guild_dungeon_cumulative_damage_cs = 937,
		guild_dungeon_cumulative_damage_sc = 938,
		mail_received_cs = 939,
		mail_received_sc = 940,
		item_lock_cs = 947,
		item_lock_sc = 948,
		lord_bless_info_cs = 949,
		lord_bless_info_sc = 950,
		lord_message_cs = 951,
		lord_message_sc = 952,
		lord_worship_cs = 953,
		lord_worship_sc = 954,
		lord_bless_buff_use_cs = 955,
		lord_bless_buff_use_sc = 956,
		lord_bless_buff_info_cs = 957,
		lord_bless_buff_info_sc = 958,
		illusion_dungeon_time_charge_cs = 961,
		illusion_dungeon_time_charge_sc = 962,
		secretvalley_alert_cs = 963,
		secretvalley_alert_sc = 964,
		secretvalley_info_cs = 965,
		secretvalley_info_sc = 966,
		revive_list_cs = 969,
		revive_list_sc = 970,
		recovery_exp_cs = 971,
		recovery_exp_sc = 972,
		reflection_equip_cs = 975,
		reflection_equip_sc = 976,
		reflection_mix_cs = 977,
		reflection_mix_sc = 978,
		revive_request_cs = 979,
		revive_request_sc = 980,
		lord_bless_end_time_cs = 981,
		lord_bless_end_time_sc = 982,
		zone_seal_device_use_cs = 983,
		zone_seal_device_use_sc = 984,
		zone_seal_device_info_cs = 985,
		zone_seal_device_info_sc = 986,
		blackiron_sell_regist_cs = 989,
		blackiron_sell_regist_sc = 990,
		blackiron_sell_info_cs = 991,
		blackiron_sell_info_sc = 992,
		demon_tower_info_cs = 993,
		demon_tower_info_sc = 994,
		demon_summon_info_cs = 995,
		demon_summon_info_sc = 996,
		customizing_save_cs = 999,
		customizing_save_sc = 1000,
		guild_blackiron_alert_cs = 1001,
		guild_blackiron_alert_sc = 1002,
		illusion_dungeon_time_out_cs = 1003,
		illusion_dungeon_time_out_sc = 1004,
		temp_reflection_change_cs = 1007,
		temp_reflection_change_sc = 1008,
		temp_reflection_confirm_cs = 1009,
		temp_reflection_confirm_sc = 1010,
		temp_reflection_get_cs = 1011,
		temp_reflection_get_sc = 1012,
		monster_phase_change_cs = 1013,
		monster_phase_change_sc = 1014,
		zone_observer_mode_cs = 1015,
		zone_observer_mode_sc = 1016,
		arena_battle_match_regist_cs = 1017,
		arena_battle_match_regist_sc = 1018,
		arena_battle_match_regist_cancel_cs = 1019,
		arena_battle_match_regist_cancel_sc = 1020,
		arena_battle_score_board_cs = 1023,
		arena_battle_score_board_sc = 1024,
		arena_battle_alert_cs = 1025,
		arena_battle_alert_sc = 1026,
		arena_battle_season_reward_cs = 1027,
		arena_battle_season_reward_sc = 1028,
		skill_force_reinforce_cs = 1029,
		skill_force_reinforce_sc = 1030,
		mandala_node_add_cs = 1031,
		mandala_node_add_sc = 1032,
		mandala_rotation_cs = 1033,
		mandala_rotation_sc = 1034,
		mandala_reset_cs = 1035,
		mandala_reset_sc = 1036,
		mandala_node_levelup_cs = 1037,
		mandala_node_levelup_sc = 1038,
		mandala_node_equip_cs = 1039,
		mandala_node_equip_sc = 1040,
		mandala_stone_upgrade_cs = 1041,
		mandala_stone_upgrade_sc = 1042,
		indun_monarch_item_regist_cs = 1043,
		indun_monarch_item_regist_sc = 1044,
		indun_monarch_state_alert_cs = 1045,
		indun_monarch_state_alert_sc = 1046,
		guild_goods_update_cs = 1047,
		guild_goods_update_sc = 1048,
		indun_monarch_spawn_mob_info_cs = 1049,
		indun_monarch_spawn_mob_info_sc = 1050,
		guild_alert_member_contribution_update_cs = 1053,
		guild_alert_member_contribution_update_sc = 1054,
		street_stall_create_cs = 1057,
		street_stall_create_sc = 1058,
		street_stall_create_cancel_cs = 1059,
		street_stall_create_cancel_sc = 1060,
		street_stall_start_cs = 1061,
		street_stall_start_sc = 1062,
		street_stall_start_result_cs = 1063,
		street_stall_start_result_sc = 1064,
		street_stall_stop_cs = 1065,
		street_stall_stop_sc = 1066,
		street_stall_unmanned_cs = 1067,
		street_stall_unmanned_sc = 1068,
		street_stall_info_cs = 1069,
		street_stall_info_sc = 1070,
		guild_mark_alert_cs = 1071,
		guild_mark_alert_sc = 1072,
		party_auto_target_set_cs = 1073,
		party_auto_target_set_sc = 1074,
		party_auto_target_uid_cs = 1075,
		party_auto_target_uid_sc = 1076,
		contents_onoff_info_cs = 1077,
		contents_onoff_info_sc = 1078,
		street_stall_sell_info_cs = 1079,
		street_stall_sell_info_sc = 1080,
		street_stall_enter_info_cs = 1081,
		street_stall_enter_info_sc = 1082,
		illusion_dungeon_info_cs = 1083,
		illusion_dungeon_info_sc = 1084,
		street_stall_buy_open_cs = 1087,
		street_stall_buy_open_sc = 1088,
		street_stall_buy_cs = 1089,
		street_stall_buy_sc = 1090,
		street_stall_get_use_count_cs = 1091,
		street_stall_get_use_count_sc = 1092,
		title_reward_cs = 1093,
		title_reward_sc = 1094,
		update_max_hp_mp_cs = 1095,
		update_max_hp_mp_sc = 1096,
		chat_command_cs = 1097,
		chat_command_sc = 1098,
		illusion_dungeon_info_get_cs = 1099,
		illusion_dungeon_info_get_sc = 1100,
		field_boss_kill_cs = 1101,
		field_boss_kill_sc = 1102,
		character_fixed_battle_cs = 1103,
		character_fixed_battle_sc = 1104,
		auth_check_cs = 1105,
		auth_check_sc = 1106,
		session_auth_cs = 1107,
		session_auth_sc = 1108,
		achieve_add_cs = 1109,
		achieve_add_sc = 1110,
		achieve_reward_cs = 1111,
		achieve_reward_sc = 1112,
		arena_join_cs = 1113,
		arena_join_sc = 1114,
		send_nickname_disable_cs = 1115,
		send_nickname_disable_sc = 1116,
		quest_reward_change_cs = 1117,
		quest_reward_change_sc = 1118,
		arena_battle_matching_count_cs = 1119,
		arena_battle_matching_count_sc = 1120,
		session_type_cs = 1121,
		session_type_sc = 1122,
		item_enchant_option_change_cs = 1123,
		item_enchant_option_change_sc = 1124,
		indun_remaining_time_cs = 1125,
		indun_remaining_time_sc = 1126,
		arena_battle_revive_count_cs = 1127,
		arena_battle_revive_count_sc = 1128,
		guild_goods_exchange_cs = 1129,
		guild_goods_exchange_sc = 1130,
		temp_pet_change_cs = 1131,
		temp_pet_change_sc = 1132,
		temp_pet_confirm_cs = 1133,
		temp_pet_confirm_sc = 1134,
		temp_pet_get_cs = 1135,
		temp_pet_get_sc = 1136,
		zone_client_request_object_info_cs = 1137,
		zone_client_request_object_info_sc = 1138,
		tonic_charge_cs = 1139,
		tonic_charge_sc = 1140,
		inven_size_change_cs = 1141,
		inven_size_change_sc = 1142,
		eclipse_center_cs = 1143,
		eclipse_center_sc = 1144,
		ranking_buff_reset_cs = 1145,
		ranking_buff_reset_sc = 1146,
		mandala_node_reset_cs = 1147,
		mandala_node_reset_sc = 1148,
		street_stall_pr_cs = 1149,
		street_stall_pr_sc = 1150,
		street_stall_teleport_cs = 1151,
		street_stall_teleport_sc = 1152,
		game_login_inven_cs = 1153,
		game_login_inven_sc = 1154,
		game_login_mandala_cs = 1155,
		game_login_mandala_sc = 1156,
		game_login_inven_stone_cs = 1157,
		game_login_inven_stone_sc = 1158,
		npc_shop_open_cs = 1159,
		npc_shop_open_sc = 1160,
		guild_dungeon_enter_charge_cs = 1161,
		guild_dungeon_enter_charge_sc = 1162,
		guild_alert_dungeon_info_cs = 1163,
		guild_alert_dungeon_info_sc = 1164,
		cash_limit_product_noti_cs = 1165,
		cash_limit_product_noti_sc = 1166,
		item_restore_request_cs = 1167,
		item_restore_request_sc = 1168,
		zone_client_request_object_state_info_cs = 1169,
		zone_client_request_object_state_info_sc = 1170,
		zone_client_option_setup_cs = 1171,
		zone_client_option_setup_sc = 1172,
		guild_shipwar_season_reward_cs = 1173,
		guild_shipwar_season_reward_sc = 1174,
		guild_shipwar_unearned_win_alarm_cs = 1175,
		guild_shipwar_unearned_win_alarm_sc = 1176,
		occupationwar_info_cs = 1177,
		occupationwar_info_sc = 1178,
		occupationwar_tender_deposit_cs = 1179,
		occupationwar_tender_deposit_sc = 1180,
		occupationwar_tender_withdraw_cs = 1181,
		occupationwar_tender_withdraw_sc = 1182,
		occupationwar_request_info_cs = 1183,
		occupationwar_request_info_sc = 1184,
		occupationwar_challenge_request_info_cs = 1185,
		occupationwar_challenge_request_info_sc = 1186,
		occupationwar_challenge_request_cs = 1187,
		occupationwar_challenge_request_sc = 1188,
		occupationwar_guild_info_cs = 1189,
		occupationwar_guild_info_sc = 1190,
		darksteel_storage_darksteel_pay_cs = 1191,
		darksteel_storage_darksteel_pay_sc = 1192,
		darksteel_storage_darksteel_sell_cs = 1193,
		darksteel_storage_darksteel_sell_sc = 1194,
		darksteel_storage_darksteel_withdraw_cs = 1195,
		darksteel_storage_darksteel_withdraw_sc = 1196,
		guild_search_custom_cs = 1197,
		guild_search_custom_sc = 1198,
		wallet_login_cs = 1199,
		wallet_login_sc = 1200,
		wallet_linked_account_cs = 1201,
		wallet_linked_account_sc = 1202,
		get_contract_address_cs = 1203,
		get_contract_address_sc = 1204,
		trade_darksteelbox_to_token_cs = 1205,
		trade_darksteelbox_to_token_sc = 1206,
		trade_token_to_darksteelbox_cs = 1207,
		trade_token_to_darksteelbox_sc = 1208,
		approve_make_transaction_cs = 1209,
		approve_make_transaction_sc = 1210,
		approve_send_transaction_cs = 1211,
		approve_send_transaction_sc = 1212,
		global_exchange_register_cs = 1213,
		global_exchange_register_sc = 1214,
		global_exchange_register_cancel_cs = 1215,
		global_exchange_register_cancel_sc = 1216,
		global_exchange_buy_cs = 1217,
		global_exchange_buy_sc = 1218,
		global_exchange_gold_withdraw_cs = 1219,
		global_exchange_gold_withdraw_sc = 1220,
		global_exchange_item_withdraw_cs = 1221,
		global_exchange_item_withdraw_sc = 1222,
		staking_make_tx_cs = 1223,
		staking_make_tx_sc = 1224,
		staking_send_tx_cs = 1225,
		staking_send_tx_sc = 1226,
		claim_make_tx_cs = 1227,
		claim_make_tx_sc = 1228,
		claim_send_tx_cs = 1229,
		claim_send_tx_sc = 1230,
		governance_staking_cs = 1231,
		governance_staking_sc = 1232,
		governance_unstaking_cs = 1233,
		governance_unstaking_sc = 1234,
		token_history_item_get_cs = 1235,
		token_history_item_get_sc = 1236,
		global_party_governance_rank_cs = 1237,
		global_party_governance_rank_sc = 1238,
		is_party_governance_decide_user_cs = 1239,
		is_party_governance_decide_user_sc = 1240,
		global_party_governance_account_staking_cs = 1241,
		global_party_governance_account_staking_sc = 1242,
		check_send_nickname_disable_cs = 1243,
		check_send_nickname_disable_sc = 1244,
		item_use_change_nickname_cs = 1245,
		item_use_change_nickname_sc = 1246,
		check_nickname_cs = 1247,
		check_nickname_sc = 1248,
		guild_alert_change_nickname_cs = 1249,
		guild_alert_change_nickname_sc = 1250,
		guild_change_nickname_cs = 1251,
		guild_change_nickname_sc = 1252,
		enchant_stone_mix_cs = 1263,
		enchant_stone_mix_sc = 1264,
		reward_ad_cs = 1265,
		reward_ad_sc = 1266,
		advertisement_reward_cs = 1267,
		advertisement_reward_sc = 1268,
		game_login_inven_essence_cs = 1269,
		game_login_inven_essence_sc = 1270,
		server_relocation_cs = 1271,
		server_relocation_sc = 1272,
		indun_monarch_giveup_cs = 1275,
		indun_monarch_giveup_sc = 1276,
		dimension_dungeon_piece_cs = 1277,
		dimension_dungeon_piece_sc = 1278,
		dimension_dungeon_info_cs = 1279,
		dimension_dungeon_info_sc = 1280,
		get_character_rank_cs = 1281,	// "캐릭터 랭킹 조회 요청."
		get_character_rank_sc = 1282,	// "캐릭터 랭킹 조회 응답."
		party_member_enter_state_cs = 1283,	// "사용안함."
		party_member_enter_state_sc = 1284,	// "파티원들의 인던입장가능 상태."
		expert_request_cs = 1285,	// "전직(등단) 실행 요청"
		expert_request_sc = 1286,	// "전직(등단) 실행 응답"
		expert_equipment_info_cs = 1287,	// "전직 장비 신기 정보 요청"
		expert_equipment_info_sc = 1288,	// "전직 장비 신기 정보 응답"
		expert_equipment_unlock_cs = 1289,	// "전직 장비 신기 해금 요청"
		expert_equipment_unlock_sc = 1290,	// "전직 장비 신기 해금 응답"
		expert_equipment_equip_cs = 1291,	// "전직 장비 신기 착용 요청"
		expert_equipment_equip_sc = 1292,	// "전직 장비 신기 착용 응답"
		expert_equipment_unequip_cs = 1293,	// "전직 장비 신기 착용 요청"
		expert_equipment_unequip_sc = 1294,	// "전직 장비 신기 착용 응답"
		expert_equipment_reinforce_cs = 1295,	// "전직 장비 신기 강화 요청"
		expert_equipment_reinforce_sc = 1296,	// "전직 장비 신기 강화 응답"
		expert_equipment_enchant_stone_equip_cs = 1297,	// "전직 장비 신기 용령석 착용 요청"
		expert_equipment_enchant_stone_equip_sc = 1298,	// "전직 장비 신기 용령석 착용 응답"
		expert_equipment_enchant_stone_unequip_cs = 1299,	// "전직 장비 신기 용령석 착용 해제 요청"
		expert_equipment_enchant_stone_unequip_sc = 1300,	// "전직 장비 신기 용령석 착용 해제 응답"
		blood_dedicate_reward_change_cs = 1301,
		blood_dedicate_reward_change_sc = 1302,
		blood_dedicate_status_cs = 1303,
		blood_dedicate_status_sc = 1304,
		blood_dedicate_zone_chatting_cs = 1305,
		blood_dedicate_zone_chatting_sc = 1306,
		blood_dedicate_worldboss_notify_cs = 1307,
		blood_dedicate_worldboss_notify_sc = 1308,
		expert_equipment_enchant_stone_upgrade_cs = 1309,	// "전직 장비 신기에 착용된 용령석 업그레이드 요청"
		expert_equipment_enchant_stone_upgrade_sc = 1310,	// "전직 장비 신기에 착용된 용령석 업그레이드 응답"
		boss_dungeon_clear_cs = 1311,
		boss_dungeon_clear_sc = 1312,
		boss_dungeon_record_cs = 1313,
		boss_dungeon_record_sc = 1314,
		mail_list_cs = 1315,
		mail_list_sc = 1316,
		expert_equipment_ability_ready_cs = 1317,	// "신기버프,어빌리티 받을 준비 완료 알림."
		expert_equipment_ability_ready_sc = 1318,	// "사용안함"
		guild_member_pvp_info_cs = 1319,	// 문파원 전투기록 요청
		guild_member_pvp_info_sc = 1320,	// 문파원 전투기록 응답
		guild_ally_request_accept_cs = 1321,	// 문파 동맹 요청 승인
		guild_ally_request_accept_sc = 1322,	// 문파 동맹 요청 승인응답
		boss_dungeon_start_time_cs = 1323,
		boss_dungeon_start_time_sc = 1324,
		guild_ally_request_deny_cs = 1325,	// 문파 동맹 거부
		guild_ally_request_deny_sc = 1326,	// 문파 동맹 거부 응답
		guild_ally_request_regist_cs = 1327,
		guild_ally_request_regist_sc = 1328,	// 문파 동맹 신청 등록 응답
		guild_ally_list_cs = 1329,	// 문파 동맹 목록 요청
		guild_ally_list_sc = 1330,	// 문파 동맹 목록 응답
		guild_ally_request_list_cs = 1331,	// 문파동맹 요청 신청한/받은 목록
		guild_ally_request_list_sc = 1332,	// 문파동맹 요청 신청한/받은 목록
		guild_search_by_guid_cs = 1333,	// 타 문파 정보 요청
		guild_search_by_guid_sc = 1334,	// 타 문파 정보 응답
		guild_ally_cancel_cs = 1335,	// 동맹해제 요청
		guild_ally_cancel_sc = 1336,	// 동맹해제 응답
		guild_ally_alert_cs = 1337,	// 사용안함
		guild_ally_alert_sc = 1338,	// 길드 동맹 알림
		guild_ally_detail_info_cs = 1339,	// 동맹길드의 세부정보 요청
		guild_ally_detail_info_sc = 1340,	// 동맹길드의 세부정보 요청응답
		restore_item_list_cs = 1341,	// 강화 실패 아이템 리스트 조회
		restore_item_list_sc = 1342,	// 강화 실패 아이템 리스트 조회
		restore_compose_list_cs = 1343,	// 합성 실패 정보 조회
		restore_compose_list_sc = 1344,	// 합성 실패 정보 조회
		restore_item_cs = 1345,	// 강화 실패 아이템 복구
		restore_item_sc = 1346,	// 강화 실패 아이템 복구
		restore_compose_cs = 1347,	// 합성 실패 복구
		restore_compose_sc = 1348,	// 합성 실패 복구
		restore_event_noti_cs = 1349,	// 신룡의 축복 noti용
		restore_event_noti_sc = 1350,	// 신룡의 축복 noti용
		season_mandala_info_open_cs = 1351,
		season_mandala_info_open_sc = 1352,
		season_mandala_reward_get_cs = 1353,
		season_mandala_reward_get_sc = 1354,
		season_mandala_reward_notify_cs = 1355,
		season_mandala_reward_notify_sc = 1356,
		guild_member_location_cs = 1357,	// "길드멤버에 내 위치 공유"
		guild_member_location_sc = 1358,	// "길드멤버에 내 위치 공유"
		guild_member_pk_death_alert_cs = 1359,	// "사용안함"
		guild_member_pk_death_alert_sc = 1360,	// "길드멤버가 pk 당함 알림."
		equipment_awaken_cs = 1361,	// 장비 각성 요청
		equipment_awaken_sc = 1362,	// 장비 각성 응답
		equipment_awaken_option_confirmed_cs = 1363,	// 장비 각성 옵션 확정 요청
		equipment_awaken_option_confirmed_sc = 1364,	// 장비 각성 옵션 확정 응답
		party_leave_alert_by_indun_kick_cs = 1365,	// "사용안함"
		party_leave_alert_by_indun_kick_sc = 1366,	// "인던 킥에 의한 파티 나감 알림"
		pet_team_equip_cs = 1367,	// "영물 팀 장착"
		pet_team_equip_sc = 1368,	// "영물 팀 장착"
		gm_fsminfo_cs = 20000,
		gm_fsminfo_sc = 20001,
		gm_invincibility_cs = 20002,
		gm_invincibility_sc = 20003,
		gm_skillopen_cs = 20004,
		gm_skillopen_sc = 20005,
		gm_spawn_monster_cs = 20006,
		gm_spawn_monster_sc = 20007,
		gm_add_exp_cs = 20008,
		gm_add_exp_sc = 20009,
		gm_getitem_cs = 20010,
		gm_getitem_sc = 20011,
		gm_kill_monster_cs = 20012,
		gm_kill_monster_sc = 20013,
		gm_check_attribute_cs = 20014,
		gm_check_attribute_sc = 20015,
		gm_damage_monster_cs = 20016,
		gm_damage_monster_sc = 20017,
		gm_siege_object_spawn_cs = 20018,
		gm_siege_object_spawn_sc = 20019,
		gm_object_skill_start_cs = 20020,
		gm_object_skill_start_sc = 20021,
		gm_siege_warfare_change_state_cs = 20022,
		gm_siege_warfare_change_state_sc = 20023,
		gm_guild_storage_treasure_insert_item_cs = 20024,
		gm_guild_storage_treasure_insert_item_sc = 20025,
		gm_quest_clear_cs = 20026,
		gm_quest_clear_sc = 20027,
		gm_quest_clear_list_cs = 20028,
		gm_quest_clear_list_sc = 20029,
		gm_quest_accept_cs = 20030,
		gm_quest_accept_sc = 20031,
		gm_get_pet_cs = 20032,
		gm_get_pet_sc = 20033,
		gm_siege_indun_create_cs = 20034,
		gm_siege_indun_create_sc = 20035,
		gm_spawn_treasurebox_cs = 20036,
		gm_spawn_treasurebox_sc = 20037,
		gm_title_cs = 20038,
		gm_title_sc = 20039,
		gm_dictionary_add_cs = 20040,
		gm_dictionary_add_sc = 20041,
		gm_quest_initialization_cs = 20042,
		gm_quest_initialization_sc = 20043,
		gm_guild_add_exp_cs = 20044,
		gm_guild_add_exp_sc = 20045,
		gm_achieve_all_get_cs = 20046,
		gm_achieve_all_get_sc = 20047,
		gm_levelup_cs = 20048,
		gm_levelup_sc = 20049,
		gm_story_indun_clear_cs = 20050,
		gm_story_indun_clear_sc = 20051,
		gm_skill_expup_cs = 20052,
		gm_skill_expup_sc = 20053,
		gm_guild_shipwar_state_cs = 20054,
		gm_guild_shipwar_state_sc = 20055,
		gm_siege_state_cs = 20056,
		gm_siege_state_sc = 20057,
		gm_guild_shipwar_indun_create_cs = 20058,
		gm_guild_shipwar_indun_create_sc = 20059,
		gm_super_armor_cs = 20060,
		gm_super_armor_sc = 20061,
		gm_guild_shipwar_play_start_cs = 20062,
		gm_guild_shipwar_play_start_sc = 20063,
		gm_create_bot_cs = 20064,
		gm_create_bot_sc = 20065,
		gm_avatar_get_cs = 20066,
		gm_avatar_get_sc = 20067,
		gm_show_aggro_cs = 20068,
		gm_show_aggro_sc = 20069,
		gm_show_aggro_info_cs = 20070,
		gm_show_aggro_info_sc = 20071,
		gm_speed_attribute_cs = 20072,
		gm_speed_attribute_sc = 20073,
		gm_castle_info_clear_cs = 20074,
		gm_castle_info_clear_sc = 20075,
		gm_secretvalley_state_cs = 20076,
		gm_secretvalley_state_sc = 20077,
		gm_reflection_add_cs = 20078,
		gm_reflection_add_sc = 20079,
		gm_seal_device_reset_cs = 20080,
		gm_seal_device_reset_sc = 20081,
		gm_demon_tower_spawn_cs = 20082,
		gm_demon_tower_spawn_sc = 20083,
		gm_add_guild_goods_cs = 20084,
		gm_add_guild_goods_sc = 20085,
		gm_arena_battle_start_cs = 20086,
		gm_arena_battle_start_sc = 20087,
		gm_zone_all_mode_cs = 20088,
		gm_zone_all_mode_sc = 20089,
		gm_profesion_update_cs = 20090,
		gm_profesion_update_sc = 20091,
		gm_get_vehicle_cs = 20092,
		gm_get_vehicle_sc = 20093,
		gm_add_expert_exp_cs = 20110,	// 전직경험치추가치트
		gm_add_expert_exp_sc = 20111,	// 전직경험치추가치트
		gate_castle_dungeon_info_cs = 21400,
		gate_castle_dungeon_info_sc = 21401,
		gate_castle_view_owner_info_cs = 21402,
		gate_castle_view_owner_info_sc = 21403,
		gate_castle_tax_with_member_info_cs = 21404,
		gate_castle_tax_with_member_info_sc = 21405,
		gate_castle_town_info_by_guild_guid_cs = 21406,
		gate_castle_town_info_by_guild_guid_sc = 21407,
		gate_castle_town_managing_info_cs = 21408,
		gate_castle_town_managing_info_sc = 21409,
		gate_castle_town_single_managing_info_cs = 21410,
		gate_castle_town_single_managing_info_sc = 21411,
		gate_castle_town_save_bag_info_cs = 21412,
		gate_castle_town_save_bag_info_sc = 21413,
		gate_castle_town_log_cs = 21414,
		gate_castle_town_log_sc = 21415,
		gate_character_info_view_cs = 21416,
		gate_character_info_view_sc = 21417,
		gate_token_history_info_get_cs = 21418,
		gate_token_history_info_get_sc = 21419,
		gate_community_server_getinfo_cs = 21420,
		gate_community_server_getinfo_sc = 21421,
		gate_contract_get_nonce_cs = 21422,
		gate_contract_get_nonce_sc = 21423,
		gate_contract_get_address_cs = 21424,
		gate_contract_get_address_sc = 21425,
		gate_contract_get_balance_cs = 21426,
		gate_contract_get_balance_sc = 21427,
		gate_contract_token_allowance_cs = 21428,
		gate_contract_token_allowance_sc = 21429,
		gate_contract_get_limit_cs = 21430,
		gate_contract_get_limit_sc = 21431,
		gate_contract_get_staking_info_cs = 21432,
		gate_contract_get_staking_info_sc = 21433,
		gate_contract_get_balance_to_wdoller_cs = 21434,
		gate_contract_get_balance_to_wdoller_sc = 21435,
		gate_world_boss_statking_player_info_cs = 21436,
		gate_world_boss_statking_player_info_sc = 21437,
		gate_coupon_use_cs = 21438,
		gate_coupon_use_sc = 21439,
		gate_friend_list_cs = 21440,
		gate_friend_list_sc = 21441,
		gate_mentor_position_cs = 21442,
		gate_mentor_position_sc = 21443,
		gate_friend_request_count_cs = 21444,
		gate_friend_request_count_sc = 21445,
		gate_friend_requested_list_cs = 21446,
		gate_friend_requested_list_sc = 21447,
		gate_game_option_save_cs = 21448,
		gate_game_option_save_sc = 21449,
		gate_game_option_select_cs = 21450,
		gate_game_option_select_sc = 21451,
		gate_game_setup_hash_select_cs = 21452,
		gate_game_setup_hash_select_sc = 21453,
		gate_game_setup_save_cs = 21454,
		gate_game_setup_save_sc = 21455,
		gate_game_setup_select_cs = 21456,
		gate_game_setup_select_sc = 21457,
		gate_guild_dungeon_member_damage_cs = 21458,
		gate_guild_dungeon_member_damage_sc = 21459,
		gate_guild_dungeon_goods_cs = 21460,
		gate_guild_dungeon_goods_sc = 21461,
		gate_guild_skill_goods_cs = 21462,
		gate_guild_skill_goods_sc = 21463,
		gate_guild_share_storage_log_cs = 21464,
		gate_guild_share_storage_log_sc = 21465,
		gate_secretvalley_owner_info_cs = 21466,
		gate_secretvalley_owner_info_sc = 21467,
		gate_guild_league_rank_cs = 21468,
		gate_guild_league_rank_sc = 21469,
		gate_guild_storage_history_cs = 21470,
		gate_guild_storage_history_sc = 21471,
		gate_mail_check_cs = 21472,
		gate_mail_check_sc = 21473,
		gate_mail_list_cs = 21474,
		gate_mail_list_sc = 21475,
		gate_mentor_info_cs = 21476,
		gate_mentor_info_sc = 21477,
		gate_mentor_list_cs = 21478,
		gate_mentor_list_sc = 21479,
		gate_mentor_rev_req_list_cs = 21480,
		gate_mentor_rev_req_list_sc = 21481,
		gate_occupationwar_tender_history_cs = 21482,
		gate_occupationwar_tender_history_sc = 21483,
		gate_darksteel_storage_info_cs = 21484,
		gate_darksteel_storage_info_sc = 21485,
		gate_darksteel_storage_history_cs = 21486,
		gate_darksteel_storage_history_sc = 21487,
		gate_darksteel_storage_darksteel_daily_pay_cs = 21488,
		gate_darksteel_storage_darksteel_daily_pay_sc = 21489,
		gate_occupationwar_challenge_request_list_cs = 21490,
		gate_occupationwar_challenge_request_list_sc = 21491,
		gate_ranking_info_cs = 21492,
		gate_ranking_info_sc = 21493,
		gate_ranking_info_new_cs = 21494,
		gate_ranking_info_new_sc = 21495,
		gate_refinery_exchange_limit_check_cs = 21496,
		gate_refinery_exchange_limit_check_sc = 21497,
		gate_search_around_party_cs = 21500,
		gate_search_around_party_sc = 21501,
		gate_search_category_party_cs = 21504,
		gate_search_category_party_sc = 21505,
		gate_search_user_cs = 21506,
		gate_search_user_sc = 21507,
		gate_shipwar_result_list_cs = 21508,
		gate_shipwar_result_list_sc = 21509,
		gate_shipwar_result_cs = 21510,
		gate_shipwar_result_sc = 21511,
		gate_siege_warfare_alliance_list_cs = 21512,
		gate_siege_warfare_alliance_list_sc = 21513,
		gate_siege_warfare_alliance_receive_list_cs = 21514,
		gate_siege_warfare_alliance_receive_list_sc = 21515,
		gate_siege_warfare_atk_machine_info_cs = 21516,
		gate_siege_warfare_atk_machine_info_sc = 21517,
		gate_siege_warfare_guild_search_cs = 21518,
		gate_siege_warfare_guild_search_sc = 21519,
		gate_siegewarfare_observer_count_cs = 21520,
		gate_siegewarfare_observer_count_sc = 21521,
		gate_siege_warfare_tender_info_cs = 21522,
		gate_siege_warfare_tender_info_sc = 21523,
		gate_street_stall_sell_info_cs = 21524,
		gate_street_stall_sell_info_sc = 21525,
		gate_wanted_murder_list_cs = 21526,
		gate_wanted_murder_list_sc = 21527,
		gate_wanted_murder_register_list_cs = 21528,
		gate_wanted_murder_register_list_sc = 21529,
		gate_wanted_murder_reward_list_cs = 21530,
		gate_wanted_murder_reward_list_sc = 21531,
		gate_exchange_buybag_info_cs = 21532,
		gate_exchange_buybag_info_sc = 21533,
		gate_exchange_history_cs = 21534,
		gate_exchange_history_sc = 21535,
		gate_exchange_itemcount_all_cs = 21536,
		gate_exchange_itemcount_all_sc = 21537,
		gate_exchange_itemcount_type_cs = 21538,
		gate_exchange_itemcount_type_sc = 21539,
		gate_exchange_item_detail_cs = 21540,
		gate_exchange_item_detail_sc = 21541,
		gate_exchange_itemid_reg_count_lists_cs = 21542,
		gate_exchange_itemid_reg_count_lists_sc = 21543,
		gate_exchange_itemid_lists_cs = 21544,
		gate_exchange_itemid_lists_sc = 21545,
		gate_exchange_itemid_reinforce_count_cs = 21546,
		gate_exchange_itemid_reinforce_count_sc = 21547,
		gate_exchange_itemid_reinforce_list_cs = 21548,
		gate_exchange_itemid_reinforce_list_sc = 21549,
		gate_exchange_itemtype_count_cs = 21550,
		gate_exchange_itemtype_count_sc = 21551,
		gate_exchange_marketprice_cs = 21552,
		gate_exchange_marketprice_sc = 21553,
		gate_exchange_registrant_info_cs = 21554,
		gate_exchange_registrant_info_sc = 21555,
		gate_field_boss_regist_info_cs = 21556,
		gate_field_boss_regist_info_sc = 21557,
		gate_event_info_cs = 21558,
		gate_event_info_sc = 21559,
		gate_event_reward_cs = 21560,
		gate_event_reward_sc = 21561,
		gate_global_exchange_buybag_info_cs = 21562,
		gate_global_exchange_buybag_info_sc = 21563,
		gate_global_exchange_history_cs = 21564,
		gate_global_exchange_history_sc = 21565,
		gate_global_exchange_itemcount_all_cs = 21566,
		gate_global_exchange_itemcount_all_sc = 21567,
		gate_global_exchange_itemcount_type_cs = 21568,
		gate_global_exchange_itemcount_type_sc = 21569,
		gate_global_exchange_item_detail_cs = 21570,
		gate_global_exchange_item_detail_sc = 21571,
		gate_global_exchange_itemid_reg_count_lists_cs = 21572,
		gate_global_exchange_itemid_reg_count_lists_sc = 21573,
		gate_global_exchange_itemid_lists_cs = 21574,
		gate_global_exchange_itemid_lists_sc = 21575,
		gate_global_exchange_itemid_reinforce_count_cs = 21576,
		gate_global_exchange_itemid_reinforce_count_sc = 21577,
		gate_global_exchange_itemid_reinforce_list_cs = 21578,
		gate_global_exchange_itemid_reinforce_list_sc = 21579,
		gate_global_exchange_itemtype_count_cs = 21580,
		gate_global_exchange_itemtype_count_sc = 21581,
		gate_global_exchange_marketprice_cs = 21582,
		gate_global_exchange_marketprice_sc = 21583,
		gate_global_exchange_registrant_info_cs = 21584,
		gate_global_exchange_registrant_info_sc = 21585,
		gate_cash_shop_info_cs = 21586,
		gate_cash_shop_info_sc = 21587,
		gate_contents_onoff_list_cs = 21588,
		gate_contents_onoff_list_sc = 21589,
		gate_pay_start_cs = 21590,
		gate_pay_start_sc = 21591,
		gate_pay_verify_cs = 21592,
		gate_pay_verify_sc = 21593,
		gate_pre_verify_cs = 21594,
		gate_pre_verify_sc = 21595,
		gate_promo_verify_cs = 21596,
		gate_promo_verify_sc = 21597,
		gate_cash_shop_item_list_cs = 21598,
		gate_cash_shop_item_list_sc = 21599,
		gate_lobby_character_create_cs = 21600,
		gate_lobby_character_create_sc = 21601,
		gate_lobby_character_delete_cs = 21602,
		gate_lobby_character_delete_sc = 21603,
		gate_lobby_character_delete_cancel_cs = 21604,
		gate_lobby_character_delete_cancel_sc = 21605,
		gate_lobby_character_select_cs = 21606,
		gate_lobby_character_select_sc = 21607,
		gate_lobby_gameplaylogin_cs = 21608,
		gate_lobby_gameplaylogin_sc = 21609,
		gate_lobby_gamelogin_await_cancel_cs = 21610,
		gate_lobby_gamelogin_await_cancel_sc = 21611,
		gate_get_available_font_list_cs = 21612,
		gate_get_available_font_list_sc = 21613,
		gate_channel_status_cs = 21614,
		gate_channel_status_sc = 21615,
		gate_channel_full_check_cs = 21616,
		gate_channel_full_check_sc = 21617,
		gate_arena_battle_ranking_cs = 21618,
		gate_arena_battle_ranking_sc = 21619,
		gate_arena_battle_info_cs = 21620,
		gate_arena_battle_info_sc = 21621,
		gate_arena_battle_result_list_cs = 21622,
		gate_arena_battle_result_list_sc = 21623,
		gate_arena_battle_result_cs = 21624,
		gate_arena_battle_result_sc = 21625,
		gate_guildshipwar_season_reward_cs = 21626,
		gate_guildshipwar_season_reward_sc = 21627,
		gate_world_boss_statking_board_info_cs = 21628,
		gate_world_boss_statking_board_info_sc = 21629,
		gate_occupationwar_statking_board_info_cs = 21630,
		gate_occupationwar_statking_board_info_sc = 21631,
		gate_occupationwar_schedule_info_cs = 21632,
		gate_occupationwar_schedule_info_sc = 21633,
		gate_world_boss_linked_wallet_info_cs = 21634,
		gate_world_boss_linked_wallet_info_sc = 21635,
		gate_worldboard_guild_league_rank_cs = 21636,
		gate_worldboard_guild_league_rank_sc = 21637,
		gate_worldboard_shipwar_result_list_cs = 21638,
		gate_worldboard_shipwar_result_list_sc = 21639,
		gate_worldboard_shipwar_result_cs = 21640,
		gate_worldboard_shipwar_result_sc = 21641,
		gate_contract_add_exchagne_cs = 21642,
		gate_contract_add_exchagne_sc = 21643,
		gate_wemix_pay_start_cs = 21644,
		gate_wemix_pay_start_sc = 21645,
		gate_wemix_pay_end_cs = 21646,
		gate_wemix_pay_end_sc = 21647,
		gate_get_wemix_amount_cs = 21648,
		gate_get_wemix_amount_sc = 21649,
		gate_get_wemix_history_cs = 21650,
		gate_get_wemix_history_sc = 21651,
		gate_advertisement_exp_restore_cs = 21652,
		gate_advertisement_exp_restore_sc = 21653,
		gate_advertisement_reward_cs = 21654,
		gate_advertisement_reward_sc = 21655,
		gate_advertisement_event_reward_cs = 21656,
		gate_advertisement_event_reward_sc = 21657,
		gate_get_all_balance_swap_token_cs = 21658,
		gate_get_all_balance_swap_token_sc = 21659,
		gate_advertisement_info_cs = 21660,
		gate_advertisement_info_sc = 21661,
		gate_community_login_cs = 21662,
		gate_community_login_sc = 21663,
		gate_chatting_cs = 21664,
		gate_chatting_sc = 21665,
		gate_chatting_block_cs = 21666,
		gate_chatting_block_sc = 21667,
		gate_chatting_block_list_cs = 21668,
		gate_chatting_block_list_sc = 21669,
		gate_private_chatting_state_cs = 21670,
		gate_private_chatting_state_sc = 21671,
		gate_server_relocation_list_cs = 21672,
		gate_server_relocation_list_sc = 21673,
		gate_dogma_pay_start_cs = 21674,
		gate_dogma_pay_start_sc = 21675,
		gate_dogma_pay_end_cs = 21676,
		gate_dogma_pay_end_sc = 21677,
		gate_dogma_get_oracle_cs = 21678,
		gate_dogma_get_oracle_sc = 21679,
		gate_dimension_dungeon_schedule_cs = 21680,
		gate_dimension_dungeon_schedule_sc = 21681,
		gate_lobby_player_character_select_cs = 21682,
		gate_lobby_player_character_select_sc = 21683,
		gate_lobby_player_character_delete_cs = 21684,
		gate_lobby_player_character_delete_sc = 21685,
		gate_world_exchange_buybag_info_cs = 21688,
		gate_world_exchange_buybag_info_sc = 21689,
		gate_world_exchange_history_cs = 21690,
		gate_world_exchange_history_sc = 21691,
		gate_world_exchange_itemcount_all_cs = 21692,
		gate_world_exchange_itemcount_all_sc = 21693,
		gate_world_exchange_itemcount_type_cs = 21694,
		gate_world_exchange_itemcount_type_sc = 21695,
		gate_world_exchange_itemid_reg_count_lists_cs = 21696,
		gate_world_exchange_itemid_reg_count_lists_sc = 21697,
		gate_world_exchange_itemid_lists_cs = 21698,
		gate_world_exchange_itemid_lists_sc = 21699,
		gate_world_exchange_itemid_reinforce_count_cs = 21700,
		gate_world_exchange_itemid_reinforce_count_sc = 21701,
		gate_world_exchange_itemid_reinforce_list_cs = 21702,
		gate_world_exchange_itemid_reinforce_list_sc = 21703,
		gate_world_exchange_itemtype_count_cs = 21704,
		gate_world_exchange_itemtype_count_sc = 21705,
		gate_world_exchange_marketprice_cs = 21706,
		gate_world_exchange_marketprice_sc = 21707,
		gate_world_exchange_registrant_info_cs = 21708,
		gate_world_exchange_registrant_info_sc = 21709,
		gate_world_exchange_item_detail_cs = 21710,
		gate_world_exchange_item_detail_sc = 21711,
		gate_blood_dedicate_worldboss_status_cs = 21712,
		gate_blood_dedicate_worldboss_status_sc = 21713,
		gate_dungeon_ranking_info_cs = 21714,
		gate_dungeon_ranking_info_sc = 21715,
		cmd_max = 30000,
	};

	enum class mpe_good_pos : uint8_t
	{
		level = 0,	// //캐릭터level
		exp = 1,
		gold = 2,	// //골드
		cash = 3,
		chao_point = 4,	// //죄악도 ( ReputePoint )
		goldingot = 5,	// //원보
		concentration = 6,	// //22.05.28 피로도 주머니 => 집중력 변경
		condition = 7,	// //피로도
		black_iron = 8,	// //08.05 move_point => black_iron (흑철) 변경
		treasurebox_key = 9,	// //보물상자 키
		guild_point = 10,	// //길드 포인트 ( GuildPoint )
		guid_gold = 11,	// //길드 골드 ( GuildGold )
		boss_point = 12,	// 07.09 force_level => boss_point (보스주화) 변경
		force_exp = 13,	// 내공 경험치
		pk_point = 14,	// pk 포인트
		mentor_point = 15,	// 스승 버프 포인트
		seal_tower_coin = 16,	// 고대주화
		demon_tower_coin = 17,	// 사령의조각
		mileage = 18,	// 마일리지
		ancientrelic_key = 19,	// 고대 유물 열쇠
		ad_coin = 20,	// 광고 주화
		dungeon_seal = 21,	// 토벌 인장
		blood_stone = 22,	// 혈석(반야도)
		nelumbo_stone = 23,	// 홍련석(반야도)
		dimension_piece = 24,	// 차원조각(차원비경)
		nelumbo_stone_point = 25,	// 봉혈 랭킹포인트(반야도)
		expert_level = 26,	// 전직(등선)레벨
		expert_exp = 27,	// 전직경험치.몹사냥 지급용으로 사용
		monarch_point = 28,	// 임무 수행 증서
		goods_29 = 29,
		goods_30 = 30,
		goods_31 = 31,
		goods_32 = 32,
		goods_33 = 33,
		goods_34 = 34,
		max = 35,
	};

	enum class mpe_equip_pos : uint8_t
	{
		weapon = 0,	// //무기
		sub_weapon = 1,	// //보조무기
		helmet = 2,	// //투구
		armor = 3,	// //갑옷
		necklace = 4,	// //목걸이
		bracelet_r = 5,	// //팔찌R
		bracelet_l = 6,	// //팔찌L
		ring_r = 7,	// //반지R
		ring_l = 8,	// //반지L
		belt = 9,	// //허리띠
		shoes = 10,	// //신발
		wing = 11,	// //망토->날개 변경
		pickaxe = 12,	// 곡괭이
		axe = 13,	// 도끼
		rod = 14,	// 낚시대
		equip_stone = 15,	// 용령석
		equip_vehicle = 16,	// 탈것 착용
		costume_weapon = 17,	// 코스튬무기
		costume_armor = 18,	// 코스튬갑옷
		costume_helmet = 19,	// 코스튬투구
		costume_weapon_female = 20,	// 여성 코스튬 무기
		costume_armor_female = 21,	// 여성 코스튬 갑옷
		costume_helmet_female = 22,	// 여성 코스튬 투구
		mandala = 23,	// 만다라 노드 장착
		brooch = 24,	// 용안석
		dragonplate = 25,	// 용패
		earring = 26,	// 용루
		expert_equipment = 27,	// "신기"
		season_mandala = 28,	// 시즌 만다라 용령석 장착
		max = 29,
	};

	enum class mpe_equip_flag : uint8_t
	{
		equip = 0,	// //착용
		release = 1,
	};

	enum class mpe_daily_content_pos : uint8_t
	{
		daily_chao_point = 0,	// //카오포인터감소날짜
		daily_free_revive_count = 1,	// //일일 무료 부활 횟수
		daily_max = 2,
	};

	enum class mpe_quest_state : uint8_t
	{
		qs_none = 0,
		qs_accept = 1,	// //수락
		qs_complete = 2,	// //완료
		qs_finish = 3,	// //종료
	};

	enum class mpe_character_action : uint8_t
	{
		action_none = 0,	// //상태없음
		action_collect = 1,	// //채광상태
		action_skill_action = 3,	// //스킬애니메이션상태
		action_fish = 4,	// //낚시상태
		action_dead = 5,
		action_treasure_box_open = 6,	// 보물 상자 오픈 시도 상태
		action_treasure_box_finish = 7,	// 보물 상자 오픈 완료 상태
		action_teleport_start = 8,	// 텔레포트 시작
		action_teleport_arrive = 9,	// 텔레포트 도착
		action_transform_avatar = 10,	// 아바타변신상태
		action_seal_device_start = 11,	// 봉인해제시작
		action_seal_device_finish = 12,	// 봉인해제종료
		action_telport_reservation = 13,	// 예약
		action_observer = 14,	// 캐릭터 관전모드
		action_street_stall = 15,	// 개인노점
		action_street_stall_wait = 16,	// 개인노점 개설 대기 상태(클라 이동)
		action_exchange_use = 17,	// 거래소 거래중
		action_post_update_goods = 18,	// 자원 후 처리
		action_server_relocation = 19,	// 표국 통행 처리 중(서버 이전)
	};

	enum class mpe_move_type : uint8_t
	{
		mt_stop = 0,	// //정지
		mt_walk = 1,	// //걷기
		mt_run = 2,	// //달리기
		mt_return = 3,	// //돌아가기(몬스터)
		mt_teleport = 4,	// //텔레포트
	};

	enum class mpe_direction : uint8_t
	{
		nn = 0,	// "//북북	0"
		ne = 1,	// "//북동	1"
		ee = 2,	// "//동동	2"
		es = 3,	// "//동남	3"
		ss = 4,	// "//남남	4"
		sw = 5,	// "//남서	5"
		ww = 6,	// "//서서	6"
		wn = 7,	// "//서북	7"
		max = 8,
	};

	enum class mpe_damage_type : uint8_t
	{
		damage_none = 0,
		damage_hit = 1,
		damage_miss = 2,
		damage_critical = 3,
		damage_hp = 4,
		damage_mp = 5,
		damage_auto_heal_hp = 6,
		damage_auto_heal_mp = 7,
		damage_perfect = 8,
		damage_great = 9,
		damage_good = 10,
		damage_vampiric_hp = 11,	// // 흡혈 hp
		damage_vampiric_mp = 12,	// // 흡혈 mp
		damage_reflection = 13,	// // 반사
	};

	enum class mpe_party_loot : uint8_t
	{
		turn = 0,
		every = 1,
	};

	enum class mpe_party_join : uint8_t
	{
		automatic = 0,
		manual = 1,
	};

	enum class mpe_party_teleport : uint8_t
	{
		owner_teleport = 0,
		member_summon = 1,
	};

	enum class mpe_party_vote : uint8_t
	{
		none = 0,
		owner_ban = 1,
		member_ban = 2,
		loot_change = 3,
		indun_select = 4,
		indun_auto_matching = 5,
		indun_enter_check_for_direct = 6,
		indun_enter_check_for_auto_matching = 7,
	};

	enum class mpe_slot_pos : uint8_t
	{
		slot_hp_one = 0,
		slot_hp_two = 1,
		slot_hp_three = 2,
		slot_mp_one = 3,
		slot_mp_two = 4,
		slot_mp_three = 5,
		slot_max = 6,
	};

	enum class mpe_use_type : uint8_t
	{
		use_none = 0,
		use_grow = 1,
		use_battle = 2,
		use_hp_duration = 3,
		use_hp_instant = 4,
		use_mp_duration = 5,
		use_mp_instant = 6,
	};

	enum class mpe_chatting : uint8_t
	{
		chat_normal = 0,	// //지역
		chat_world = 1,	// //월드
		chat_party = 2,	// //파티
		chat_guild = 3,	// //문파
		chat_promotion = 4,	// //홍보
		chat_exchange = 5,	// //거래
		chat_system = 6,	// //시스템
		chat_private = 7,	// //개인
		chat_guild_ally = 8,	// //문파동맹
	};

	enum class mpe_notice_type : uint8_t
	{
		none = 0,
		inspection_force = 1,	// 점검공지(긴급)(text 없음)
		inspection_normal = 2,	// 점검공지(text 있음)
		inspection_60sec = 3,	// 점검공지(1분전)
		inspection_30sec = 4,	// 점검공지(30초전)
		inspection_10sec = 5,	// 점검공지(10초전)
	};

	enum class mpe_revive : uint8_t
	{
		revive_use_item = 0,
		revive_vaillage = 1,
		revive_auto = 2,
		revive_skill = 3,
		revive_redirect = 4,
	};

	enum class mpe_drop_owner : uint8_t
	{
		drop_owner_none = 0,
		drop_owner_character = 1,
		drop_owner_party = 2,
		drop_owner_server = 3,
	};

	enum class mpe_pk_color : uint8_t
	{
		pk_color_white = 0,
		pk_color_brown = 1,
		pk_color_yellow = 2,
		pk_color_red = 3,
	};

	enum class mpe_update_type : uint8_t
	{
		update_type_none = 0,
		update_type_protect_slot = 1,
		update_type_inven_expansion = 2,
		update_type_inven_weight_expansion = 3,
		update_type_character_revive = 4,
		update_type_auto_battle_add_time = 5,
	};

	enum class mpe_luck_reinforce_result : uint8_t
	{
		reinforce_none = 0,
		reinforce_success = 1,	// 증가1
		reinforce_fail = 2,	// 변경X
		reinforce_fail_down = 3,	// 하락
		reinforce_big = 4,	// 증가2
	};

	enum class mpe_result_fish : uint8_t
	{
		fish_ing = 0,
		fish_fail = 1,
		fish_success = 2,
		fish_big = 3,
	};

	enum class mpe_item_reinforce_position : uint8_t
	{
		equip = 0,	// //착용
		inventory = 1,	// //인베토리
	};

	enum class mpe_skill_action_result : uint8_t
	{
		skill_action_none = 0,	// //액션이없는스킬
		skill_action_start = 1,	// //액션시작
		skill_action_resist = 2,	// //액션저항
		skill_action_immune = 3,	// //액션면역
	};

	enum class mpe_guild_member_grade : uint8_t
	{
		none = 0,
		master = 1,
		sub_master = 2,
		elder = 3,
		common = 4,
		all = 5,
	};

	enum class mpe_profesion : uint8_t
	{
		profesion_alchemy = 0,
		profesion_blacksmith = 1,
		profesion_cooking = 2,
		profesion_gather = 3,	// //채집
		profesion_mining = 4,	// //채광
		profesion_logging = 5,	// //벌목
		profesion_fishing = 6,	// //낚시
		profesion_max = 7,
	};

	enum class mpe_make_result : uint8_t
	{
		success = 0,
		great = 1,
		fail = 2,
	};

	enum class mpe_echant_slot : uint8_t
	{
		echant_slot_none = 0,
		echant_slot_slot_1 = 1,
		echant_slot_slot_2 = 2,
		echant_slot_slot_3 = 4,
	};

	enum class mpe_fsm_type : uint8_t
	{
		fsm_none = 0,
		fsm_appeared = 1,
		fsm_idle = 2,
		fsm_move = 3,
		fsm_battle = 4,
		fsm_retraction = 5,
		fsm_dead = 6,
		fsm_return = 7,
		fsm_dummy = 8,
		fsm_delete = 9,
		fsm_trace = 10,
		fsm_follow = 11,
		fsm_siege = 12,
		fsm_reverse = 13,
		fsm_change = 14,
		fsm_one_move = 15,
		fsm_phase_change = 16,
		fsm_max = 17,
	};

	enum class mpe_mail_type : uint8_t
	{
		mail_type_account = 0,
		mail_type_character = 1,
		mail_type_server = 2,
	};

	enum class mpe_mail_state : uint8_t
	{
		mail_none = 0,
		mail_opened = 1,
		mail_received_item = 2,
	};

	enum class mpe_error
	{
		error_none = 0,
		constSystemTable = 1000,	// //constSystemTable테이블정보없음
		collectTable = 1001,	// //collectTable테이블정보없음
		dropTable = 1002,	// //dropTable테이블정보없음
		not_found_inventory = 1003,	// 인벤토리를 찾을 수 없습니다
		channel_is_full = 2000,	// //채널이 가득찼습니다
		channel_is_not_exist = 2001,	// //채널이 존재하지 않습니다
		auth_duplicate_username = 10000,	// //계정저장시중복된username일경우
		auth_unauthorized_user = 10001,	// //인증처리되지않은사용자접근시
		auth_wrong_group_number = 10002,	// //서버선택시없는gid일경우
		select_server_game_empty = 10003,	// //로그인하려는게임서버가없을때
		select_server_lobby_fail = 10004,	// //로그인하려는서버군의로비서버와통신이안된다.
		quick_login_info_empty = 10005,	// //퀵로그인을요청했지만캐릭터정보가없는경우
		large_waiting_list = 10006,	// //대기인원이많다.
		duplicate_login_retry = 10007,	// //중복로그인
		version_is_not_match = 10008,	// //버전이맞지않습니다.
		auth_failed_from_password = 10009,	// 비밀번호가 일치하지 않습니다.
		auth_failed_from_idcard = 10010,	// 주민등록번호가 잘못되었습니다.
		time_over_playingtime = 10011,	// 미성년자 일일 제한 시간종료
		time_over_shotdown = 10012,	// 미성년자 접속 제한 시간
		auth_failed_duplicate_idcard = 10013,	// 이미 가입된 주민등록번호
		auth_failed_zh_hans = 10014,	// 이름에 간체가 아닌 글자가 있습니다.
		auth_failed_chinese = 10015,	// 이름에 잘못된 문자가 있습니다.
		auth_limit_access = 10016,	// 접속이 제한된 계정 입니다.
		character_waiting_to_be_deleted = 10017,	// 삭제 대기 중인 캐릭터입니다.
		already_character_waiting_to_be_deleted = 10018,	// 이미 삭제 대기 중인 캐릭터입니다.
		character_not_waiting_to_be_deleted = 10019,	// 삭제 대기 중인 캐릭터가 아닙니다.
		character_has_already_been_deleted = 10020,	// 이미 삭제된 캐릭터입니다.
		banned_words = 10021,	// 부적합 문자가 포함되어 있습니다.
		auth_session_failed = 10022,	// 게임서버 접속 실패.
		admin_kick_user = 10023,	// 관리자에 의해 접속이 종료되었습니다
		unknown_packet = 10024,	// 알수없는 패킷입니다.
		integrated_character_select_count = 10025,	// 선택 가능한 캐릭터는 4개입니다.
		integrated_character_select_play = 10026,	// 플레이할 캐릭터를 선택해주세요.
		wmm_api_parameter_error = 10030,	// 파라메터에러
		wmm_api_not_search_in_db = 10031,	// DB조회안됨
		wmm_api_tokenid_expired = 10032,	// 토큰 시간 만료
		wmm_api_tokenid_is_diff = 10033,	// 저장된 토큰이 다름
		wmm_api_block_user = 10034,	// 블럭유저
		wmm_api_country_is_not_accessible = 10035,	// 접속불가능 국가
		wmm_api_account_creation_ip_block = 10036,	// 계정생성 ip블럭
		wmm_api_already_exist_account_id = 10037,	// 이미생성된 accountid
		wmm_api_refund_block_user = 10038,	// 환불 블럭유저
		wmm_api_external_api_unavailable  = 10039,	// 외부 api연동 불가
		wmm_api_no_pay_data = 10040,	// 결제 정보 없음
		wmm_api_receipt_check_fail  = 10041,	// 영수증 검수 실패
		wmm_api_duplicate_receipt = 10042,	// 중복 영수증
		wmm_api_already_consume  = 10043,	// 이미처리된 영수증
		wmm_api_cancel_receipt = 10044,	// 취소된 영수증
		wmm_api_db_error  = 10045,	// DB처리 오류
		wmm_api_already_paid  = 10046,	// 이미 지급 완료
		wmm_api_block_contry_code = 10047,	// 국가 코드 차단
		wmm_api_payment_error  = 10048,	// 결제수단 오류
		wmm_api_gameserver_error = 10049,	// 게임서버측 오류
		wmm_api_already_get_reward  = 10050,	// 이미 사전예약 보상 받음
		wmm_api_no_promo_product  = 10051,	// 프로모션 상품이 아님
		wmm_api_unknow_error = 10052,	// 알수없는 에러
		nprotect_api_error = 10053,	// nProtect인증 실패
		nprotect_api_not_yet = 10054,	// nProtect인증 진행중
		lobby_enter_waiting = 10055,	// 로비 입장 대기중(대기열)
		wmm_event_invalid_coupon = 10056,	// 유효하지 않은 쿠폰
		wmm_event_not_exist_character = 10057,	// 캐릭정보가 존재하지 않는다
		wmm_event_already_event_i_used_coupon = 10058,	// 이미 내가 사용한 이벤트 쿠폰
		wmm_event_already_event_other_used_coupon = 10059,	// 이미 남이 사용한 이벤트 쿠폰
		wmm_event_already_used_coupon = 10060,	// 이미사용된 그냥 쿠폰
		wmm_event_end = 10061,	// 이벤트 종료
		wmm_event_expire_time_coupon = 10062,	// 사용기간 만료
		wmm_event_receive_all = 10063,	// 구글기프트카드 모두 사용
		wmm_event_coupon_error = 10064,	// 그외 에러들
		uncheater_verify_fail = 10065,	// 언치터검증 실패
		wmm_api_recover_signature_error = 10066,	// recover 에러
		wmm_api_incorrect_transaction = 10067,	// 잘못된 트랜잭션
		wmm_api_transaction_connect_fail = 10068,	// 트랜잭션 호출 실패
		wmm_api_unknown_wallet_address = 10069,	// 지갑정보 없음
		wmm_api_make_transaction_fail = 10070,	// 트랜잭션 생성 실패
		wmm_api_not_enough_allowance = 10071,	// 한도 초과
		wmm_api_not_enough_token = 10072,	// 잔액 부족
		wmm_api_incorrect_price = 10073,	// 가격 불일치
		wmm_api_incorrect_product_id_price = 10074,	// productid 정보 조회 가격 이상
		server_busy_try_later = 10100,	// //서버가바쁘다.나중에다시해라.
		server_inspection = 10101,	// //서버 점검 중
		player_key_is_null = 10102,	// 유저 playerkey 정보가 없다
		username_is_null = 10103,	// 유저네임이 정보가 없다
		lobby_info_is_null = 10104,	// 등록된 로비 정보가 없다
		lobby_state_is_off = 10105,	// 선택한 로비 상태가 꺼져있다
		character_is_locked = 10106,	// 잠김 처리된 캐릭터
		select_channel_is_not_exist = 10107,	// 선택할수 있는 채널이 없다
		character_action_teleport_cancel = 10108,	// 캐릭터가 다른 행동중으로 텔레포트를 사용할 수 없습니다
		wmm_api_captcha_invalid_parameter = 10200,	// //captcha 잘못된 파라미터
		wmm_api_captcha_auth_fail = 10201,	// //captcha 인증 실패
		player_info_empty = 11000,	// //플레이어정보가없다(신규유저)
		character_info_empty = 11001,	// //캐릭터선택시없는캐릭터인경우.
		already_game_playing = 11002,	// //캐릭터선택시-플레이중이정보가있는경우.
		nickname_duplicate = 11003,	// //캐릭터생성시-닉네임중복
		classtype_duplicate = 11004,	// //캐릭터생성시-캐릭터중복
		character_no_empty_slot = 11005,	// //캐릭터생성시-다만들었다.더못만들어.
		character_create_failed = 11006,	// //캐릭터생성시-실패
		session_timeout = 11007,	// //reconnection 시도시 session timeout
		session_reconnect = 11008,	// //reconnection 시도시 성공
		character_low_level = 11009,	// 캐릭터 래밸이 낮다
		character_is_dead = 11010,	// 사망 유저가 있다
		chatting_block_full = 11500,	// 채팅블록인원이 가득참
		chatting_block_already = 11501,	// 이미 블록유저
		character_private_chatting_disable = 11502,	// 귓속말 거부상태
		zone_is_null = 15000,	// //맵정보가없음
		zone_invalid_pos = 15001,	// //잘못된position
		zone_invalid_index = 15002,	// //잘못된섹터인덱스
		zone_same_zone_id = 15003,	// //같은맵으로이동요청을했다.
		zone_failed_change_set = 15004,	// //좌표셋팅실패
		zone_tile_null = 15005,	// //타일정보가없음
		zone_wrong_tile_index = 15006,	// //잘못된타일인덱스
		zone_invalid_tile = 15007,	// //갈수없는타일
		zone_curr_tile_null = 15008,	// //현재 타일 정보 없음
		zone_next_tile_null = 15009,	// //다음 타일 정보 없음
		zone_wrong_next_tile = 15010,	// //다음 타일 정보가 잘못됨
		zone_wrong_new_curr_tile = 15011,	// //이동 할 타일 정보가 잘못됨
		zone_new_next_tile_null = 15012,	// //이동 할 다음 타일 정보가 없음
		zone_astar_attribute_false = 15013,	// //astar CheckAttribute() false
		zone_astar_null = 15014,	// //astar 정보가 없음
		zone_tile_reserved = 15015,	// //예약된 타일이다
		zone_invalid_tile_player = 15016,	// //플레이어가 있다
		zone_invalid_tile_monster = 15017,	// //몬스터가 있다
		zone_invalid_tile_npc = 15018,	// //npc가 있다
		zone_object_null = 15099,	// //오브젝트정보없음
		zone_object_type = 15100,	// //잘못된오브젝트타입
		zone_collect_null = 15101,	// //채광오브젝트없음
		zone_collect_dist = 15102,	// //채광거리안됨
		zone_collect_empty = 15103,	// //채광수량이없다.
		zone_collect_status_error = 15104,	// //잘못된채광패킷이다.
		zone_collect_time = 15105,	// //채광쿨타임안됨
		zone_collect_not_info = 15106,	// //채광정보가잘못되었다.
		zone_invalid_character = 15107,	// //캐릭터정보없음
		zone_not_ready = 15108,	// //존에진입기다리는상태
		zone_object_create_failed = 15109,	// //존에오브젝트생성실패
		zone_npc_dist = 15110,	// //npc와거리안됨
		zone_fishing_dist = 15111,	// //낚시터와거리안됨
		zone_fishing_time = 15112,	// //낚시쿨타임안됨
		zone_fishing_null = 15113,	// //낚시정보없음
		zone_fishing_status_error = 15114,	// //잘못된낚시패킷
		zone_vehicle_duplicate = 15115,	// //중복요청
		zone_vehicle_notarea = 15116,	// //탈것탑승불가맵
		zone_daily_update_time = 15117,	// //아직초기화시간이되지않았다
		zone_object_not_found_server = 15118,	// //서버상에 오브젝트가 존재하지 않음
		zone_treasure_box_null = 15119,	// 보물상자 정보 없음
		zone_treasure_box_dist = 15120,	// 상자 오픈거리 안됨
		zone_treasure_box_info_null = 15121,	// 상자 정보 잘못됨
		zone_treasure_box_open_time = 15122,	// 상자 오픈 시간 잘 못됨
		zone_treasure_box_not_owner = 15123,	// 보물상자 권한이 없다.
		pickup_not_use_pet = 15124,	// 팻이 루팅 할 수 없다.
		zone_teleport_untraceable_area = 15125,	// 추적할 수 없는 지역
		map_bind_buff_disable = 15126,	// 해당 맵에서 활성화되지 않는 버프입니다
		zone_sealing_device_null = 15127,	// 봉인장치가 없습니다
		cannot_be_processed_while_teleporting = 15128,	// 텔레포트 중에는 처리 할 수 없습니다.
		shortage_zone_move_required_level = 15129,	// 맵입장레벨이 부족합니다
		disable_contents = 15130,	// 사용할수 없는 컨텐츠입니다.
		not_exist_profession_equip = 15131,	// 생산 장비를 착용하지 않았습니다.
		villain_not_enter_map = 15132,	// 악인유저는 해당 지역에 입장할 수 없습니다
		villain_not_stay_map = 15133,	// 악인 상태가 되어 해당지역에 머물 수 없습니다
		zone_collect_already_use = 15134,	// //이미 사용중인 유저가 있습니다.
		zone_already_use_black_iron = 15135,	// 흑철 채광이 불가합니다
		inventory_no_empty_slot = 20000,	// //아이템추가시인벤토리에빈칸이없는경우
		not_exist_item = 20001,	// //아이템처리요청시없는아이템인경우.
		cannot_equip_item = 20002,	// //아이템착용시착용할수없는아이템인경우.
		not_sell_item = 20003,	// //아이템판매불가인경우.
		inventory_already_max = 20004,	// //인벤토리확장시이미최대크기인경우.
		short_of_good_level = 20005,	// //재화부족(레벨)
		short_of_good_exp = 20006,	// //재화부족(경험치)
		short_of_good_gold = 20007,	// //재화부족(골드)
		short_of_good_cash = 20008,	// //재화부족(점권)
		short_of_good_chao_point = 20009,	// //재화부족(chao)
		short_of_good_goldingot = 20010,	// //재화부족(원보)
		short_of_good_condition_bag = 20011,	// //재화부족(피로도 주머니)
		short_of_good_condition = 20012,	// //재화부족(피로도)
		short_of_good_blackiron = 20013,	// //재화부족(흑철)
		short_of_good_dungeon_ticket = 20014,	// //재화부족(던전입장권)
		short_of_good_guild_point = 20015,	// //재화부족(길드포인트=공헌도)
		short_of_good_guild_gold = 20016,	// //재화부족(길드골드)
		short_of_good_guild_blackiron = 20017,	// //재화부족(예약)
		short_of_good_force_exp = 20018,	// //재화부족(내공경험치)
		short_of_good_pk_point = 20019,	// //재화부족(pk포인트)
		short_of_good_mentor_point = 20020,	// //재화부족(사제포인트)
		short_of_good_reserve_16 = 20021,	// //재화부족(고대주화)
		short_of_good_reserve_17 = 20022,	// //재화부족(사령의조각)
		short_of_good_mileage = 20023,	// //재화부족(표국주화)
		short_of_good_reserve_19 = 20024,	// //재화부족(예약)
		short_of_good_reserve_20 = 20025,	// //재화부족(예약)
		short_of_good_reserve_21 = 20026,	// //재화부족(예약)
		short_of_good_reserve_22 = 20027,	// //재화부족(예약)
		short_of_good_reserve_23 = 20028,	// //재화부족(예약)
		short_of_good_reserve_24 = 20029,	// //재화부족(예약)
		short_of_item_count = 20030,	// //아이템사용시수량부족
		not_reinforce_item = 20031,	// //강화가능하지않은아이템
		max_of_reinforce = 20032,	// //최대강화도
		not_use_material_item = 20033,	// //강화도사용재료가아닌경우.
		max_amount_material_item = 20034,	// //강화재료개수가초과하였습니다.
		max_amount_buy_item = 20035,	// //구매최대개수가초과하였습니다.
		max_amount_sell_item = 20036,	// "//판매최대개수가초과하였습니다.	"
		locked_item = 20037,	// //아이템이잠겨있는경우
		slot_exist_item = 20038,	// //이미등록된아이템
		slot_not_signup = 20039,	// //퀵슬롯등록불가아이템
		slot_not_exist_item = 20040,	// //퀵슬롯등록되지않은아이템템
		not_for_sell_npc = 20041,	// //판매불가npc
		not_npc = 20042,	// //npc가아님
		invalid_pickup_dist = 20043,	// //아이템루팅할수있는거리초과
		wrong_pickup_index = 20044,	// //잘못된루팅인덱스
		wrong_pickup_item_id = 20045,	// //잘못된루팅itemid
		not_exist_pickup_item = 20046,	// //루팅할아이템이없음
		reward_item_pool_null = 20047,	// //보상아이템풀null
		item_incorrect_type = 20048,	// //사용가능한타입이아님
		pickup_item_wrong_owner = 20049,	// //아이템에대한소유권없다.
		drop_protect_slot = 20050,	// //장비가보호중인slot이다.
		weight_already_max = 20051,	// //무게확장시이미최대크기인경우우
		not_destroy_item = 20052,	// //파괴불가아이템
		not_decompose_item = 20053,	// //분해불가아이템
		item_already_locked = 20054,	// //이미잠금상태입니다.
		item_already_unlocked = 20055,	// //이미잠금해제상태입니다.
		item_can_not_lock = 20056,	// //잠글수없는아이템입니다.
		short_of_good_guild_goldingot = 20057,	// //길드골드부족.
		item_can_not_lock_indun_prepare = 20058,	// //인던시작준비중(투표중)에는 아이템 잠금/해제 불가.
		exchagne_no_register_item = 20060,	// //거래소등록불가아이템
		exchagne_no_empty_slot = 20061,	// //거래소등록시-등록갯수초과
		exchagne_price_wrong = 20062,	// //거래소등록시-가격오류(fixed일경우틀리면)
		exchagne_price_low = 20063,	// //거래소등록시-가격오류(최소가격이하일경우)
		exchagne_reg_cancel_nofound = 20067,	// //거래소등록취소-내역이없다.
		exchagne_reg_cancel_cannot = 20068,	// //거래소등록취소-취소할수없는아이템이다.
		exchagne_buy_item_notfound = 20070,	// //거래소아이템구매시-없는아이템
		exchagne_buy_storage_full = 20071,	// //거래소아이템구매시-보관함꽉참
		exchagne_buy_count_wrong = 20072,	// //거래소아이템구매시-구매아이템개수오류
		exchagne_buy_price_wrong = 20073,	// //거래소아이템구매시-구매아이템가격오류
		exchagne_buy_expire_over = 20074,	// //거래소아이템구매시-등록만료
		exchagne_buy_not_state = 20075,	// //거래소아이템구매시-판매상태가아니다.
		exchagne_buy_same_account = 20076,	// //거래소아이템구매시-같은계정의아이템.
		exchagne_takeitem_notfound = 20080,	// //거래소아이템찾기-구입내역이없다.보관만료시간이지나서자동삭제처리되어없을수도있다.
		exchagne_takeitem_expire = 20081,	// //거래소아이템찾기-보관만료
		exchagne_takegold_notfound = 20090,	// //거래소정산-캐릭터또는아이템정보가없다.
		exchagne_takegold_notgold = 20091,	// //거래소정산-장산받을거없다.
		cannot_show_costume = 20092,	// 코스튬이 아닌 장비에는 사용할 수 없다.
		cash_shop_cart_is_full = 20093,	// 보관함이 가득 찼습니다.
		gold_is_max = 20094,	// 골드 보유량 최대치입니다
		goldingot_is_max = 20095,	// 원보 보유량 최대치입니다
		cash_is_max = 20096,	// 점권 보유량 최대치입니다
		cash_shop_daily_limit_over = 20097,	// 일일 구매 제한을 초과했습니다
		cash_shop_weekly_limit_over = 20098,	// 주간 구매 제한을 초과했습니다
		cash_shop_monthly_limit_over = 20099,	// 월간 구매 제한을 초과했습니다
		cash_shop_character_limit_over = 20100,	// 캐릭터 구매 제한을 초과했습니다
		cash_shop_account_limit_over = 20101,	// 계정 구매 제한을 초과했습니다
		cash_shop_server_limit_over = 20102,	// 서버 구매 제한을 초과했습니다
		cash_shop_not_buy_date = 20103,	// 구매 가능 기간이 아닙니다.
		cash_shop_not_buy_exchange_product = 20104,	// 교환소 구매 가능 아이템이 아닙니다.
		cash_shop_remain_date_exchange_reset = 20105,	// 교환소 리셋 가능 시간이 아닙니다.
		cash_shop_limit_guild_league = 20106,	// 구매 가능 길드 소속리그가 아닙니다.
		mileage_is_max = 20107,	// 표국주화 보유량 최대치입니다.
		cash_shop_not_get_daily_item = 20108,	// 오늘 수령가능한 아이템이 아닙니다.
		not_make_recipe = 20110,	// //제작불가레시피
		not_profesion_equal_type = 20111,	// //대가타입이다른경우
		not_profesion_upgrade = 20112,	// //대가승급불가
		profesion_already_reset = 20113,	// //승급되지않은대가직업은초기화불가
		short_profesion_level = 20114,	// //대가레벨부족
		profesion_short_item = 20115,	// "//대가제작시아이템부족	"
		blackiron_sell_regist_min_value_low = 20116,	// 흑철상점등록-최소값보다작다
		blackiron_sell_regist_max_value_over = 20117,	// 흑철상점등록-최대값보다크다
		blackiron_sell_regist_time_over = 20118,	// 흑철상점-판매가능시간아니다
		blackiron_shop_buy_check = 20119,	// 흑철상점구매시 체크후 처리해야함
		blackiron_is_full = 20120,	// 재화 흑철이 가득참
		blackiron_regist_key_is_incorrect = 20121,	// 흑철상점-상점물품이변경되었습니다.
		blackiron_sell_count_shortage = 20122,	// 흑철상점-판매할흑철이부족합니다
		blackiron_shop_owner_is_null = 20123,	// 흑철상점-비곡주인이없습니다
		blackiron_shop_list_null = 20124,	// 흑철상점-등록된상품이없습니다
		auto_battle_max_charge_over = 20125,	// 비접속자동전투-보유가능한 최대 시간이 초과하여 충전 할 수 없습니다
		cash_shop_not_step_product = 20126,	// 구매 가능 단계상품이 아닙니다.
		item_expiretime = 20127,	// 기간이 만료된 아이템 입니다
		sealtowercoin_is_full = 20128,	// 고대주화가 가득 찼습니다
		demontowercoin_is_full = 20129,	// 사령조각이 가득 찼습니다
		recipe_use_all_make_count = 20130,	// 제작 횟수를 모두 사용했습니다
		bloodstone_is_full = 20131,	// 혈석이 가득 찼습니다
		meridians_max_level = 20200,	// "//경락최대레벨	"
		acupoints_max_level = 20201,	// //혈도최대레벨
		acupoints_lack_level = 20202,	// //혈도레벨부족
		already_special_move = 20203,	// //이미 슬롯에 등록된 스킬
		disable_special_move_slot = 20204,	// //착용할수 없는 스킬스롯
		is_blank_slot = 20205,	// //연타 스킬 중 빈슬롯이 존재할 경우
		special_move_invalid_type = 20206,	// //연타 스킬 타입이 아닙니다
		unable_to_raise_level = 20207,	// //레벨을올릴수없습니다
		short_of_meridians = 20208,	// 경락 레벨 부족
		special_move_slot_max_level = 20209,	// 연타 스킬 슬롯 최대레벨
		short_of_special_move_slot_level = 20210,	// 연타 스킬 레벨 부족
		special_move_number_of_choices_is_different = 20211,	// 필살기 선택이 잘못되었습니다
		exchagne_no_register_item_Equipstone = 20212,	// 용령석이 장착된 장비는 등록할 수 없습니다
		condition_limit_lack = 20250,	// //일일피로도충전부족
		condition_fill_no_more = 20251,	// //피로도충전불가등급
		condition_fill_time_wrong = 20252,	// //안전지대피로도충전시간오류
		conditionbag_already_full = 20253,	// //피로도 가방 최대치
		conditionbag_over_value = 20254,	// //피로도 가방 최대치를 넘을수 없습니다.
		equip_stone_inven_not_empty = 20255,	// 용령석 보관함 공간이 부족합니다
		essence_inven_not_empty = 20256,	// 마석 / 정수 보관함 공간이 부족합니다
		map_discovery_already_find_area = 20300,	// //이미발견한지역이다.
		mail_already_receive_item = 20400,	// //이미아이템을받은메일
		receive_item_empty_mail = 20401,	// //받을아이템이없는메일
		not_open_mail = 20402,	// //확인하지않은우편입니다
		items_not_received = 20403,	// //아이템을받지않은메일
		mail_max_count_request = 20404,	// //요청우편개수초과
		not_found_mail = 20405,	// //우편을찾을수없음
		mail_max_item_count = 20406,	// //우편지급아이템개수초과
		mail_already_opened = 20407,	// 이미확인한우편입니다
		mail_can_not_receive = 20408,	// 받을수없는우편이있습니다
		mail_can_not_delete = 20409,	// 삭제할수없는우편이있습니다
		mail_no_available = 20410,	// 받을 수 있는 우편이 없다
		personal_trade_already = 20500,	// // 거래중 일 경우
		personal_trade_unable = 20501,	// // 거래 불가 상태
		personal_trade_dist = 20502,	// // 거래 가능 범위에 없을 경우
		personal_trade_zone_invalid = 20503,	// // 거래 불가 지역에 있을 경우
		personal_trade_zone_not_peace = 20504,	// // 평화 지역이 아닐 경우
		personal_trade_register_max_count = 20505,	// // 거래 아이템 등록갯수 초과
		randombox_select_over = 20600,	// 선택개수 초과
		once_over_payment = 20700,	// 일회 충전 금액 초과
		month_over_payment = 20701,	// 한달 충전 금액 초과
		once_18_over_payment = 20702,	// 일회 충전 금액 초과(18세)
		month_18_over_payment = 20703,	// 한달 충전 금액 초과(18세)
		once_under_payment = 20704,	// 8세미만 충전불가
		month_16_over_payment = 20705,	// 일회 충전 금액 초과(16세)
		once_16_over_payment = 20706,	// 한달 충전 금액 초과(16세)
		not_invalid_goods_move = 21000,	// 유효하지 않은 이동 타입
		not_exist_storage_good_type = 21001,	// 창고에 없는 재화 타입
		not_invalid_storage_type = 21002,	// 유효하지 않은 창고 타입
		storage_expand_overflow = 21003,	// 창고 최대 사이즈 초과
		account_storage_exist = 21004,	// 계정창고 소유중
		enchant_stone_exist = 21100,	// 용령석 - 존재하지 않는 용령석
		enchant_stone_slot_locked = 21101,	// 용령석 - 해금되지 않은 슬롯
		enchant_stone_slot_empty = 21102,	// 용령석 - 빈 슬롯
		enchant_stone_slot_imposible = 21103,	// 용령석 - 슬롯을 사용할 수 없는 아이템
		enchant_stone_slot_already_max = 21104,	// 용령석 - 슬롯 최대치
		maximum_count = 21200,	// 보물상자 횟수가 남아있음
		used_all_count_today = 21201,	// 보물상자 금일 충전 횟수 모두 사용
		vehicle_duplicate_id = 22000,	// 동일 탈 것
		vehicle_not_exist = 22001,	// 존재하지 않는 탈 것
		vehicle_not_equip = 22002,	// 장착중인 탈 것이 없다
		vehicle_not_get_type = 22003,	// 잘못된 습득 타입(탈것)
		vehicle_max = 22004,	// 더 이상 탈 것을 습득할수 없다.
		vehicle_expire = 22005,	// 탈것 만료
		vehicle_already_expire = 22006,	// 이미 만료된 탈것
		vehicle_remain_date = 22007,	// 기간이 남아있는 탈것
		vehicle_remain_satiety = 22008,	// 만복도가 남아있는 탈것
		vehicle_level_max = 22009,	// 탈것 레벨 최대
		vehicle_satiety_max = 22010,	// 만복도가 최대치인 탈것
		title_durability = 22100,	// 중복된 칭호 장착 요청
		not_exists_title = 22101,	// 존재하지 않는 칭호
		not_complete_title = 22102,	// 완료 하지 않은 칭호
		title_level_max = 22103,	// 칭호 최대레벨
		vehicle_satiety_zero = 22104,	// 만복도가 없는 탈것
		title_not_remain = 22105,	// 사용기간 만료 칭호
		not_exists_dictionary_type = 23000,	// 존재하지 않는 도감
		dictionary_is_duplicate_item = 23001,	// 이미 도감에 등록된 아이템
		npc_intimacy_max = 23002,	// npc 호감도 최대치
		dictionary_remain_date = 23003,	// 만료일이 남은 도감
		short_of_npc_intimacy = 23004,	// npc 호감도 부족
		npc_intimacy_already_reward = 23005,	// 이미 획득한 보상
		seasonpass_already_completed = 24000,	// 시즌패스 - 완료한 도전과제
		seasonpass_short_level = 24001,	// 시즌패스 - 레벨부족
		seasonpass_already_reward = 24002,	// 시즌패스 - 획득한 보상
		seasonpass_short_count = 24003,	// 시즌패스 - 횟수 부족
		seasonpass_max_level = 24004,	// 시즌패스 - 최대 시즌레벨
		seasonpass_short_unlock_level = 24005,	// 시즌패스 - 해금 레벨 부족
		seasonpass_remain_unlock_time = 24006,	// 시즌패스 - 해금 시간 부족
		seasonpass_not_buy = 24007,	// 시즌패스 - 구매하지 않은 시즌패스
		revive_request_invalid = 25000,	// 부활요청 - 요청불가
		revive_request_duplicate = 25001,	// 부활요청 - 중복 요청
		revive_request_already = 25002,	// 부활요청 - 이미 요청된 상태
		mandala_node_level_max = 26000,	// 만다라 - 노드 최대 레벨
		mandala_node_impossible = 26001,	// 만다라 - 노드 습득 불가
		mandala_node_already = 26002,	// 만다라 - 이미 습득한 노드
		quest_not_found = 30001,	// //퀘스트-수락한 퀘스트가 없습니다
		quest_accept_not_repeated = 30002,	// //퀘스트-수락불가능-반복할수없는퀘스트다.
		quest_accept_level = 30003,	// //퀘스트-수락불가능-레벨이낮다.
		quest_accept_need_quest = 30004,	// //퀘스트-수락불가능-요구되는퀘스트가없다.
		quest_accept_exceeded = 30005,	// //퀘스트-수락불가능-동시진행가능한퀘스트초과
		quest_finish_not_complet = 30006,	// //퀘스트-보상요청시-아직완료되지않은퀘스트
		quest_npctalk_notfound_npc = 30007,	// //퀘스트-NPC대화-없는NPC
		quest_complete_failed = 30008,	// //퀘스트-완료요청인데정보가틀려서..
		quest_move_complete_dist = 30009,	// //퀘스트-도착
		quest_not_get_object = 30010,	// //퀘스트-획득한오브젝트가없다.서버내부처리용(퀘스트에먼가일어났지만db처리할게없는경우)
		quest_cannot_giveup_main = 30011,	// //퀘스트-메인퀘는포기할수없다
		area_quest_daily_finish_count_over = 30012,	// //지역퀘스트-완료횟수초과
		quest_accept_need_item = 30013,	// //퀘스트-수락불가능-필요한아이템이없음
		quest_unacceptable = 30014,	// //퀘스트-수락불가능-수락할 수 없는 퀘스트 입니다
		quest_accept_not_match_condition = 30015,	// //퀘스트-수락불가능-수락 조건이 충분하지 않습니다
		quest_accept_profession_level_low = 30016,	// //퀘스트-장인 기술 레벨이 부족해서 퀘스트를 수락할 수 없습니다
		quest_not_clear = 30017,	// //퀘스트-완료가 필요한 퀘스트가 있습니다
		quest_not_supported = 30018,	// //퀘스트-지원하지 않는 퀘스트입니다
		repute_quest_chao_point_is_ = 31001,	// //평판퀘스트-카오상태가아니다
		repute_quest_is_max = 31002,	// //평판퀘스트-가지고있는숫자가최대치
		repute_quest_fail_refresh = 31003,	// //평판퀘스트-갱신할수있는평판퀘스트가없다
		repute_daily_completion_count_exceeded = 31004,	// //평판퀘스트-일일퀘스트완료횟수초과
		repute_quest_daily_reset_count_exceeded = 31005,	// //평판퀘스트-일일초기화횟수초과
		repute_quest_finish_count_not_full = 31006,	// //평판퀘스트-완료횟수채우기전에초기화시도
		repute_quest_not_match_level = 31007,	// 평판퀘스트-레벨조건이맞지않습니다
		repute_quest_not_match_chao_point = 31008,	// 평판퀘스트-평판성향치가조건에맞지않습니다
		can_not_finish_quest = 31009,	// //완료할수없는퀘스트
		repute_point_max = 31010,	// //평판 점수가 최대치입니다
		guild_is_not = 32001,	// //길드-해당길드가없다
		guild_already_joined = 32002,	// //길드-이미길드에가입되어있다.
		guild_already_join_request = 32003,	// //길드-이미가입대기중이다
		guild_full_join_request = 32004,	// //길드-최대가입요청수
		guild_full_recv_join_reques = 32005,	// //길드-최대가입대기자수
		guild_not_empty_member_size = 32006,	// //길드-길드원멤버최대수
		guild_master_cannot_escape = 32007,	// //길드-길드장은탈퇴할수없다.
		guild_not_exist_member = 32008,	// //길드-해당멤버는존재하지않는다.
		guild_invalid_auth = 32009,	// //길드-해당권한이없다.
		guild_nickname_already_in_use = 32010,	// //길드-이미사용중인길드명
		guild_join_low_level = 32011,	// //길드-가입레벨이부족합니다.
		guild_not_change_you_infomation = 32012,	// //길드-자신의정보를변경할수없다
		guild_members_remaining = 32013,	// //길드-길드원이남있습니다.
		guild_have_limit_time_left = 32014,	// //길드-가입제한시간이남았다
		guild_war_count_max = 32015,	// //길드-전쟁선포수가최대치입니다.
		guild_can_not_declare_restart_time = 32016,	// //길드-하루동안전쟁을선포할수없습니다.
		enermy_guild_war_count_max = 32017,	// //길드-적대길드전쟁선포수가최대치입니다.
		guild_use_all_donations = 32018,	// //길드-하루기부횟수모두사용
		guild_not_war = 32019,	// //길드-전쟁중이아닙니다. 
		guild_war_already_in_progress = 32020,	// //길드-이미전쟁중입니다. 
		target_guild_not_exist = 32021,	// //길드-상대길드가없습니다. 
		target_guild_invalid = 32022,	// //길드-상대길드가올바르지않습니다. 
		guild_not_joined = 32023,	// //길드-가입된길드가없습니다. 
		guild_war_already_negotiating = 32024,	// //길드-이미협상중입니다. 
		guild_war_minimum_negotiation_gold = 32025,	// //길드-최소협상금액미달. 
		guild_war_not_negotiating = 32026,	// //길드-협상중이아닙니다. 
		guild_max_level = 32027,	// //길드-최대길드레벨도달. 
		guild_max_skill_level = 32028,	// //길드-최대길드스킬레벨도달. 
		guild_waiting_rpc_response = 32029,	// //길드-공훈령사용처리대기. 
		guild_low_level = 32030,	// //길드-길드레벨이낮습니다. 
		guild_notice_length_too_long = 32031,	// //길드-공지길이초과. 
		guild_skill_not_exist = 32032,	// //길드-해당문파스킬이없습니다. 
		guild_skill_point_lack = 32033,	// //길드-문파스킬포인트부족. 
		guild_skill_invalid_level = 32034,	// //길드-현재배울수없는문파스킬. 
		guild_member_must_in_siege_map = 32035,	// //길드-공성전맵이아닙니다. 
		guild_storage_supply_request_count_full = 32036,	// //길드-보급창고찾기횟수초과. 
		guild_storage_short_of_item_count = 32037,	// //길드-창고내아이템개수부족. 
		guild_storage_cant_over_max_int = 32038,	// //길드-창고에더이상넣을수없습니다. 
		guild_storage_is_full = 32039,	// //길드-창고에빈슬롯이없습니다. 
		guild_storage_has_max_slot = 32040,	// //길드-확장가능한최대슬롯수도달. 
		guild_storage_share_request_count_full = 32041,	// //길드-공유창고찾기요청횟수초과. 
		guild_storage_share_not_exist_request = 32042,	// //길드-존재하지않는공유창고찾기요청. 
		guild_storage_share_not_exist_member = 32043,	// //길드-요청문파원이존재하지않습니다. 
		guild_storage_share_request_expired = 32044,	// //길드-만료된요청입니다. 
		guild_not_have_castle_down = 32045,	// //길드-장원을소유한문파가아닙니다. 
		guild_storage_treasure_auction_not_exist = 32046,	// //길드-보물창고경매정보없음. 
		guild_storage_treasure_auction_expired = 32047,	// //길드-이미종료된경매. 
		guild_storage_treasure_auction_request_count_full = 32048,	// //길드-참여중인경매횟수초과. 
		guild_storage_treasure_auction_price_too_low = 32049,	// //길드-입찰최소금액미달. 
		guild_storage_treasure_auction_already_top = 32050,	// //길드-이미최고가상태입니다. 
		guild_storage_treasure_auction_in_progress = 32051,	// //길드-아직진행중인경매입니다. 
		guild_storage_treasure_auction_not_joined = 32052,	// //길드-입찰기록이없는경매입니다. 
		guild_level_is_low = 32053,	// //길드-문파퀘스트요구레벨미달. 
		guild_quest_office_level_is_low = 32054,	// //길드-문파퀘스트요구장원연락소레벨미달. 
		guild_quest_daily_finish_count_full = 32055,	// //길드-문파퀘스트일일최대완료횟수도달. 
		guild_office_quest_daily_finish_count_full = 32056,	// //길드-장원퀘스트일일최대완료횟수도달. 
		guild_master_order_quest_already_in_progress = 32057,	// //길드-이미문주하달퀘스트가진행중. 
		guild_master_order_quest_expired = 32058,	// //길드-이미문주하달퀘스트가만료됨. 
		guild_master_order_quest_not_found = 32059,	// //길드-문주하달퀘스트가없음. 
		guild_already_open_dungeon = 32060,	// 이미던전이열려있다
		guild_unfinished_dungeon = 32061,	// 완료하지않은던전이있다
		guild_use_all_pr_count = 32062,	// 초대횟수모두사용
		guild_beginner_cannot_contents = 32063,	// 초보문파는 이용할수 없는 컨텐츠입니다
		guild_mark_is_null = 32064,	// 문장을 설정하지 않았습니다
		guild_mark_use_condition_error = 32065,	// 문장 사용조건이 맞지않습니다
		guild_buff_already_buy = 32066,	// 문파-버프 시간만료 후 구매가능합니다
		guild_buff_max_count = 32067,	// 문파-버프 구매 가능 개수를 초과했습니다
		guild_dungeon_open_count_all_use = 32068,	// 문파-던전 오픈 횟수를 모두 사용했습니다
		guild_time_limit_for_request = 32069,	// 문파-재 신청 시간이 남아있습니다
		guild_war_low_level = 32070,	// 문파-문파전쟁 레벨 미달
		guild_name_is_invalid = 32071,	// 문파-이름이 올바르지않습니다.
		guild_dungeon_open_count_charge_all_use = 32072,	// 문파-던전 오픈 충전 횟수를 모두 사용했습니다
		guild_dungeon_open_count_remain = 32073,	// 문파-던전 오픈 횟수가 남아 있습니다
		guild_ally_already_alliance = 32074,	// 이미 동맹 관계.
		guild_ally_really_cooldown = 32075,	// 동맹 다시 신청 쿨타임 제한.
		guild_ally_already_requested = 32076,	// 이미 동맹 신청 되어 있음.
		guild_ally_already_received = 32077,	// 상대방이 이미 동맹 요청 했음.
		guild_ally_not_exist_request = 32078,	// 동맹 요청이 존재 하지 않음.
		guild_ally_target_max_request_recv_limit = 32079,	// 동맹 요청한 대상 길드가 받는 최대 수 제한에 걸림.
		guild_ally_max_request_send_limit = 32080,	// 동맹 요청한 길드가 최대 신청 수 제한에 걸림.
		guild_ally_not_allied = 32081,	// 동맹 맺은 상태가 아님.
		guild_master_change_fail_by_last_connect_time_condition = 32082,	// 문파장 변경 실패 장기미접속자 조건이 안맞음.
		guild_master_change_fail_by_require_grade = 32083,	// 요청 문파원의 권한 없음.
		guild_war_start_fail_target_is_ally = 32084,	// 길드전쟁 실패 대상이 동맹.
		guild_can_not_deleted_reason_is_ally = 32085,	// 동맹이 있으면 길드 삭제 불가.
		guild_ally_permision_deny = 32086,	// 권한 부족으로 길드 동맹 관련 처리 불가..
		guild_ally_occupation_war_start = 32087,	// 비곡점령전중에는 동맹 관련 처리 불가..
		guild_ally_deny_by_war = 32088,	// 전쟁중인 길드와 동맹 불가..
		siege_warfare_tender_incorect_time = 33000,	// 공성전-입찰 가능시간이 아닙니다
		siege_warfare_build_not_first_guild = 33001,	// 공성전-공성 문파만 설치할 수 있습니다
		siege_warfare_build_not_possessed_item = 33002,	// 공성전-보유한 병기가 없습니다
		siege_warfare_no_permission = 33003,	// 공성전-권한이 없습니다
		siege_warfare_build_not_owner_guild = 33004,	// 공성전-수성 문파만 설치할 수 있습니다
		siege_warfare_alliance_max = 33005,	// 공성전-연합 관리는 동시에 2개의 문파만 가능합니다
		siege_warfare_prepare_incorect_time = 33006,	// 공성전-공성 준비기간이 지났습니다
		castle_tax_change_same_day = 33007,	// 성관리-세율은 하루에 한번만 변경 가능 합니다
		castle_tax_change_same_tax = 33008,	// 성관리-이미 적용중인 세율과 동일합니다
		castle_tax_change_max_tax = 33009,	// 성관리-세율 최대치를 초과할 수 없습니다
		siege_warfare_invalid_guild = 33010,	// 공성전-공성전 참여문파가 아닙니다.
		siege_warfare_invalid_enter = 33011,	// 공성전-공성전 입장 가능 시간이 아닙니다.
		siege_tower_gate_not_enable = 33012,	// 공성전-공성탑 게이트가 활성화 되지 않았다.
		siege_warfare_observer_full = 33013,	// 공성전-관전 입장 가능한 자리가 없습니다.
		castle_dungeon_not_changeable_value = 33014,	// 성관할던전-변경가능한값이아닙니다.
		castle_dungeon_same_old_entrance_fee = 33015,	// 성관할던전-기존입장료와같습니다.
		castle_dungeon_configurable_max_value_excess = 33016,	// 성관할던전-설정최대값을초과했습니다.
		castle_dungeon_not_found_castle = 33017,	// 성관할던전-존재하지않는성입니다.
		castle_town_work_count_over = 33018,	// 장원-동시작업수가 부족합니다
		castle_town_already_work = 33019,	// 장원-이미 진행중인 작업 입니다
		castle_town_already_build = 33020,	// 장원-이미 건설된 건물 입니다
		castle_town_already_not_build = 33021,	// 장원-건설된 건물이 아닙니다
		castle_town_not_level = 33022,	// 장원-레벨업이 불가 합니다
		castle_town_already_specialties_work = 33023,	// 장원-이미 특산품 작업 진행중 입니다
		castle_town_full_specialties_count = 33024,	// 장원-수확량이 가득 찼습니다
		castle_town_rental_short_of_guild_ranking = 33025,	// 장원-대여가능랭킹미달
		castle_town_already_have = 33026,	// 장원-이미대여중인장원이있다
		castle_tax_not_change_day = 33027,	// 성관리-세율을 변경할수 없는 날 입니다
		siege_warface_aliiance_invalid_guild = 33028,	// 공성전-연합 참여 길드가 아닙니다.
		castle_town_specialties_work_start_not_yet = 33029,	// 장원-특산품 수확신청이 되지않았습니다.
		siege_build_machine_same_set = 33030,	// 공성전-병기배치가 이전과 동일한 경우
		castle_not_owner_zone = 33031,	// 성관리 - 관할 성 지역이 없습니다.
		castle_town_disable_enter = 33032,	// 장원-입장이 불가능합니다.
		castle_town_not_my_town = 33033,	// 장원-해당장원의 문파원이 아닙니다
		castle_town_employ_count_over = 33034,	// 장원-고용 수가 가득찼습니다
		castle_town_not_have = 33035,	// 장원-대여한장원이없습니다
		castle_town_specialties_delivery_already_start = 33036,	// 장원-이미 납품 진행중입니다.
		castle_town_specialties_delivery_short_of_value = 33037,	// 장원-특산품 수확량이 부족합니다.
		castle_town_dinner_end_not_yet = 33038,	// 장원-진행중인 만찬이 있습니다.
		castle_town_dinner_end_already = 33039,	// 장원-진행중인 만찬이 없습니다.
		castle_town_dinner_already_get_item = 33040,	// 장원-이미 만찬에 참여했습니다.
		guild_shipwar_not_request_time = 33100,	// 전장-신청시간이 아닙니다.
		guild_shipwar_not_request = 33101,	// 전장-전장 신청이 되지 않았습니다.
		guild_shipwar_request_auth = 33102,	// 전장-권한이 없습니다.
		guild_shipwar_not_matched = 33103,	// 전장-매칭 실패
		guild_shipwar_already_request = 33104,	// 전장-이미 신청되었습니다.
		guild_shipwar_not_match_team = 33105,	// 전장-입장할수없습니다
		guild_shipwar_team_member_is_full = 33106,	// 전장-입장가능한자리가없습니다.
		lord_worship_count_short = 33200,	// 경배-경배 횟수 부족
		lord_buff_already_use = 33201,	// 경배-축복이이미걸려있음
		lord_bless_point_short = 33202,	// 경배-축복포인트부족
		lord_bless_auth_lord = 33203,	// 경배-성주만가능
		lord_bless_buff_count_over = 33204,	// 경배-성주축복횟수초과
		illusion_only_owner_guild_allowed_enter = 33300,	// 환상비경-성주 문파만 입장 가능합니다
		illusion_used_all_the_entrance_time = 33301,	// 환상비경-입장 시간을 모두 사용했습니다
		illusion_can_not_charge_more_time = 33302,	// 환상비경-입장 시간을 더 이상 충전할 수 없습니다
		illusion_can_not_enter = 33303,	// 환상비경-입장할 수 없습니다
		seal_device_is_in_use = 33304,	// 환상비경-봉인장치가 사용 중입니다
		seal_device_is_not_yet_available = 33305,	// 환상비경-봉인장치를 사용할 수 없습니다
		arena_battle_matching_time_is_not = 33400,	// 수라전장-입장시간이 아님
		arena_battle_matching_already_regist = 33401,	// 수라전장-이미등록함
		arena_battle_matching_not_regist = 33402,	// 수라전장-등록되지않은유저
		arena_battle_not_exist_season_reward = 33403,	// 수라전장-받을 시즌보상이 없습니다
		arena_battle_matching_already_play = 33404,	// 수라전장-이번회차는 이미 참여했습니다
		arena_no_more_revive = 33405,	// 수라전장 - 더 이상 부활불가
		illusion_rank_not_match_or_lack = 33406,	// 비경-랭킹 부족 또는 조건이 맞지 않아 입장 불가
		illusion_not_open_time = 33407,	// 비경-오픈 시간이 아님
		secretvalley_cannot_teleport_to_playing = 33500,	// 비곡점령전-점령전진행중에는 텔레포트를 할수 없습니다.
		secretvalley_cannot_teleport_not_occupation_guild = 33501,	// 비곡점령전-점령문파가 아니라서 텔레포트를 할수 없습니다.
		secretvalley_blackiron_no_permission = 33503,	// 이용할 수 없는 직책입니다
		secretvalley_blackiron_pay_minvalue = 33504,	// 최소 값보다 적게 지급할 수 없습니다
		secretvalley_blackiron_pay_otheruser_not_guildmember = 33505,	// 타유저 지급시에는 자신의 문파원에게 지급할 수 없습니다.
		secretvalley_blackiron_pay_not_enough = 33506,	// 지급할 흑철이 부족합니다.
		secretvalley_blackiron_pay_1day_limit = 33507,	// 일일 지급 한도가 초과됐습니다.
		secretvalley_not_learn_guild_skill_occupation = 33508,	// [점령] 문파 기술을 습득하지 않았습니다.
		secretvalley_defenceteam_already_join = 33509,	// 수성으로 참가 된 상태입니다
		secretvalley_configurable_max_value_excess = 33510,	//  설정가능한 최대값을 초과했습니다
		secretvalley_storage_cannot_use = 33511,	// 비곡 창고를 이용 할 수 없습니다
		secretvalley_storage_blackiron_save_max = 33512,	// 더 이상 비곡창고에 흑철을 저장할 수 없습니다
		skill_is_null = 40001,	// //스킬-습득하지않은스킬
		skill_use_action = 40002,	// //스킬-다른액션중
		skill_cool_time = 40003,	// //스킬-스킬쿨타임중킬
		skill_invalid_target = 40004,	// //스킬-유효하지않은타겟임음
		skill_range_error = 40005,	// //스킬-사거리범위가아님
		skill_hp_lack = 40006,	// //스킬-hp부족
		skill_mp_lack = 40007,	// //스킬-mp부족
		skill_character_not_learn = 40008,	// "//스킬-캐릭터가배울수없는스킬	"
		skill_character_low_level = 40009,	// //스킬-캐릭터레벨부족으로배울수없음
		skill_already_learned = 40010,	// //스킬-이미배운스킬
		skill_not_learn = 40011,	// //스킬-배우지않은스킬
		skill_max_level = 40012,	// //스킬-최대레벨
		skill_silence_state = 40013,	// //스킬-스킬사용불가(침묵)
		skill_low_exp = 40014,	// //스킬-숙련도부족
		skill_direction = 40015,	// // 스킬-잘못된 방향
		skill_special_move_none = 40016,	// // 연타스킬정보가 없음
		skill_use_special_move_action = 40017,	// // 연타스킬발동중
		skill_special_move_gage_lack = 40018,	// // 연타스킬게이지 부족
		skill_force_max_level = 40019,	// // 내공 최대 레벨입니다
		skill_force_page_not_found = 40020,	// // 내공 정보가 없습니다
		skill_ability_fail_on_expand = 40021,	// // 스킬-어빌리티 확장 적용 실패
		skill_fail_add_buff = 40022,	// // 스킬-버프 적용 실패
		db_fail_character_puid = 45000,	// //파티-가입실패
		db_fail_party_setup = 45001,	// //파티-설정실패
		party_already_joined = 45002,	// //이미파티에가입된유저이거나가입중인유저입니다
		party_unfavorable_user = 45003,	// //가입조건이맞지않은유저입니다
		party_not_invited_user = 45004,	// //파티초대를받을수없는상태의유저입니다.
		party_not_leave_dungeon = 45005,	// //인던에서는파티를탈퇴할수없습니다.
		party_not_disband_dungeon = 45006,	// //인던에파티원이있을경우파티해체를할수없습니다.
		party_not_found = 45007,	// //파티정보가없는경우.
		party_no_owner_member = 45008,	// //파티장이아닌경우.
		party_member_full = 45009,	// //파티가입요청시.만석.
		party_vote_owner_cannot = 45010,	// //파티장은추방투표불가
		party_target_not_owner = 45011,	// //대상이 파티장이 아니다
		party_vote_not_enough_member = 45012,	// //투표 인원이 부족하다
		party_already_voting = 45013,	// //이미 투표 진행중
		party_not_voting = 45014,	// //투표중이 아닙니다
		party_not_joined = 45015,	// //가입되지 않은 캐릭터
		party_already_vote_reply = 45016,	// //이미투표함
		party_not_joined_target = 45017,	// //가입되지 않은 타겟캐릭터
		party_owner_offline = 45018,	// //파티장이 접속 되지 않았습니다.
		party_owner_cannot_leave = 45019,	// //파티장은 위임후 탈퇴할수있습니다.
		party_cannot_join = 45020,	// 더 이상 가입할 수 없는 파티입니다
		party_cannot_change_dungeon_max_15_to_5 = 45021,	// 15인 파티는 던전토벌로 변경 불가.
		party_cannot_change_max_15_to_5 = 45022,	// 15인 파티는 5인파티로 변경 불가.
		party_enter_require_level_lack = 45023,	// 파티 가입 가능 레벨 부족.
		party_enter_require_level_over = 45024,	// 파티 가입 가능 레벨 오버.
		character_level_higher_than_condition = 45025,	// 캐릭터의 레벨이 아이템의 사용 조건보다 높습니다
		character_level_lower_than_condition = 45026,	// 캐릭터의 레벨이 아이템의 사용 조건보다 낮습니다
		nickname_is_too_long = 45027,	// 생성할 수 없는 길이의 닉네임입니다
		indun_kick_by_lack_ticket = 45028,	// "입장권 부족으로 인던에서 킥(파티강제탈퇴)"
		not_available_during_dungeon_room = 45101,	// //15인 수동 매칭 방에 입장해 있는 동안에는 이용불가
		party_member_cannot_room_create = 45102,	// //파티 멤버는 방 생성 불가
		party_member_cannot_room_join = 45103,	// //파티 멤버는 방 입장 불가
		not_exist_room = 45104,	// //방이 존재 하지 않음
		room_invalid_auth = 45105,	// //권한이 없음
		room_is_full = 45106,	// //방인원이 가득참
		room_already_joined = 45107,	// //이미 방에 합류한 유저입니다
		room_cannot_join_in_party = 45108,	// //파티상태에서는 방에 합류할수 없습니다
		party_teleport_not_area = 45109,	// 파티텔레포트 사용 불가지역
		party_governance_not_ready = 45110,	// 시스템준비중입니다(데이터초기화 되지 않음)
		party_governance_deny = 45111,	// 파티거버넌스 권한 없습니다
		party_governance_owner_deny = 45112,	// 파티장이 거버넌스 권한 없습니다
		party_governance_target_deny = 45113,	// 위임 대상이 거버넌스 권한 없습니다
		party_governance_invite_owner_deny = 45114,	// 초대 실패 파티장이 거버넌스 권한 없습니다
		party_governance_indun_prepare_owner_deny = 45115,	// 던전 시작 실패 파티장이 거버넌스 권한 없습니다
		db_fail_character_pk_setup = 46000,	// //pk-설정실패
		offline_user = 46001,	// //오프라인상태의유저입니다
		character_is_notfound = 47000,	// //존재하지않는캐릭터
		account_is_notfound = 47001,	// //존재하지않는계정
		item_not_repairable = 47100,	// //수리가 불가 합니다
		item_not_recoveryable = 47101,	// //복원이 불가 합니다
		item_durability_zero = 47102,	// 아이템 내구도 부족
		mentor_already_register = 48000,	// 이미등록되어있습니다
		mentor_not_mentor = 48001,	// 멘토가아닙니다
		mentor_not_in_the_request_list = 48002,	// 요청목록에없습니다
		mentor_not_in_the_receive_list = 48003,	// 받은목록에없습니다
		mentor_already_mentor = 48004,	// 이미사제입니다
		mentor_lack_of_level = 48005,	// 멘토레벨이부족합니다
		mentor_level_over = 48006,	// 멘티레벨초과
		mentor_receive_count_exceeded = 48007,	// 받은요청수초과하였습니다
		mentor_request_count_exceeded = 48008,	// 신청수초과하였습니다
		mentor_already_request = 48009,	// 이미요청했습니다
		mentor_same_account = 48010,	// 같은계정입니다
		mentor_can_not_apply_for_oneself = 48011,	// 자신을신청할수없습니다
		mentor_time_limit_for_request = 48012,	// 결별 상태로 사제 신청이 불가능합니다
		mentor_excess_of_goods_mentor_point = 48013,	// 재화초과(사제포인트)
		mentor_level_conditions_incorrect = 48014,	// 레벨 조건이 맞지 않습니다
		mentor_not_found_character = 48015,	// 사제 관계를 맺을 수 없는 대상입니다
		mentor_requested_user_already_mentor = 48016,	// 상대방이 이미 사제입니다
		mentor_opponent_time_limit_for_request = 48017,	// 대상이 결별 상태로 사제 신청이 불가능합니다
		expert_require_level_lack = 48100,	// 등선에 필요한 레벨 부족.
		expert_max_level_limited = 48101,	// 최대 등선 레벨 도달.
		expert_quest_is_not_completed = 48102,	// 등선에 필요한 퀘스트 수행 안함.
		expert_level_condition_not_match = 48103,	// "등선 레벨 조건 안맞음. grade 테이블의 upgrade_maxlv 과 일치해야함."
		expert_total_exp_lack = 48104,	// "등선 경험치 부족. upgrade_maxlv 의 totalexp 만큼 달성 필요."
		expert_equipment_already_exist = 48105,	// "이미 보유중인 신기."
		expert_equipment_already_equip = 48106,	// "이미 착용중인 신기."
		expert_equipment_already_unequip = 48107,	// "이미 착용 해제된 신기."
		expert_equipment_target_not_exist = 48108,	// "대상 신기가 존재 하지 않음."
		expert_equipment_max_reinforce_lv = 48109,	// "현재 등급(전직등단)에서 최대 강화 레벨."
		expert_equipment_enchant_stone_already_equip = 48110,	// "이미 착용중인 신기 용령석 슬롯."
		expert_equipment_enchant_stone_already_unequip = 48111,	// "이미 착용해제된 신기 용령석 슬롯."
		expert_equipment_invalid_slot = 48112,	// "신기. 잘못된 슬롯번호."
		expert_equipment_not_open_slot = 48113,	// "신기. 아직 열리지 않은 슬롯번호."
		pet_max_feed = 49000,	// 더 이상 먹이를 먹을 수 없습니다
		pet_not_equip_first = 49001,	// 첫번째 슬롯에 장착된 펫이 없습니다.
		pet_summon_duplicate = 49002,	// 펫 소환 중복 요청입니다.
		friend_aleady_state = 50000,	// 친구-이미 친구 상태
		friend_aleady_request = 50001,	// 친구-이미 친구 요청한 상태
		friend_delete_user_not_found = 50002,	// 친구-삭제할 친구가 없다
		friend_mine_max_full = 50003,	// 친구-내친구가 가득 찼다
		friend_target_max_full = 50004,	// 친구-상대방 친구가 가득 찼다
		friend_req_max_full = 50005,	// 친구-친구 요청수가 가득 찼다
		friend_reqed_max_full = 50006,	// 친구-상대방이 더 이상 친구신청을 받을수없다
		friend_cannot_request_myself = 50007,	// 친구-자신한테는 친구신청할수없다
		wanted_murder_still_being_processed = 51000,	// 아직진행중이다
		wanted_murder_already_been_rewarded = 51001,	// 이미보상받은의뢰이다
		wanted_murder_not_user_reward = 51002,	// 유저보상이아니다
		wanted_murder_not_found = 51003,	// 의뢰가없다
		wanted_murder_already_register = 51004,	// 이미등록되었다
		wanted_murder_already_accept = 51005,	// 이미수락한의뢰다
		wanted_murder_user_not_register = 51006,	// 자신이등록한의뢰가아니다
		wanted_murder_user_register = 51007,	// 자신이등록한의뢰다
		wanted_murder_already_all_accept = 51008,	// 이미모두수락했다
		wanted_murder_use_all_count = 51009,	// 이미횟수모두사용했다
		wanted_murder_not_found_pk_list = 51010,	// PK목록에없다
		wanted_murder_maximum_register_count = 51011,	// 더 이상 수배범을 등록할 수 없습니다
		wanted_murder_maximum_same_user = 51012,	// 동일한 현상수배범을 더 이상 등록할 수 없습니다
		wanted_murder_less_than_the_minimum = 51013,	// 현상금이 최소 현상금보다 작습니다.
		can_not_auto_battle = 51100,	// 자동전투중엔 할수없다
		event_can_not_get_any_more = 51200,	// 더 이상 받을 수 없다
		event_ended = 51201,	// 이벤트가종료되었다
		event_already_reward = 51202,	// 이미보상을받았다
		event_not_target_in_event = 51203,	// 이벤트대상이아니다
		event_invalid_request = 51204,	// 잘못된요청입니다
		event_that_has_not_been_achieved_yet = 51205,	// 아직 달성 못한 이벤트입니다.
		not_found_observer_chracter = 51206,	// 관전모드 유저가 없습니다.
		invalid_observer_mode_character_action = 51207,	// 관전모드를 할수 없는 상태 입니다.
		can_not_equip_reflection_for_during_battle_mode  = 51208,	// 전투상태일 때는 화신을 장착할 수 없습니다.
		can_not_change_it_yet = 51209,	// 화신 - 아직 변경할 수 없습니다
		not_secretvalley_join_cannot_enter_map = 51210,	// 비곡 점령전 참가신청한 문파만 이동 할 수 있습니다
		secretvalley_time_cannot_guild_join = 51211,	// 비곡 점령전 진행중에는 문파가입을 할 수 없습니다
		secretvalley_time_cannot_guild_disband = 51212,	// 비곡 점령전 진행중에는 문파해체를 할 수 없습니다
		secretvalley_time_cannot_guild_member_expulsion = 51213,	// 비곡 점령전 진행중에는 문원을 추방 할 수 없습니다
		secretvalley_time_cannot_guild_dungeon_open = 51214,	// 비곡 점령전 진행중에는 문파 던전을 오픈 할 수 없습니다
		secretvalley_time_cannot_guild_dungeon_enter = 51215,	// 비곡 점령전 진행중에는 문파 던전 입장을 할 수 없습니다
		secretvalley_blackironbox_not_input_time = 51216,	// 흑철상자 입금 가능시간이 아닙니다
		secretvalley_blackironbox_not_output_time = 51217,	// 흑철상자 출금 가능시간이 아닙니다
		secretvalley_blackironbox_not_input_different_item = 51218,	// 투표할 수 있는 아이템이 아닙니다
		governance_not_participation_qualification = 51220,	// 투표할 수 있는 서버가 아닙니다
		pk_exhausted_the_number_of_registrations = 52300,	// 복수-등록 수를 모두 사용했습니다
		pk_not_found_cuid = 52301,	// 복수-일치하는 정보가 목록에 없습니다
		pk_revenge_already_registered = 52302,	// 복수-이미 등록된 유저입니다
		pk_not_found_revenge = 52303,	// 복수-등록된 복수가 없습니다
		street_stall_lack_level = 52000,	// 노점 - 레벨 부족
		street_stall_lack_rank = 52001,	// 노점 - 랭크 부족
		street_stall_lack_use_count = 52002,	// 노점 - 사용 카운트 부족
		street_stall_lack_recipe_count = 52003,	// 노점 - 등록 제품 카운트 부족
		street_stall_disable_mandala = 52004,	// 노점 - 만다라 비활성화
		street_stall_account_character_duplication = 52005,	// 노점 - 동일한 계정의 캐릭터로 대행이 불가능합니다.
		street_stall_not_vacancy_place = 52006,	// 노점 - 노점 - 다른 유저가 해당 위치에 노점을 점유하고 있습니다.
		duplicate_potion_buff = 52100,	// 버프 - 중복 된 버프 물약이 있습니다.
		global_exchange_item_buy_system_error = 52200,	// 표국거래소-아이템구매 등록 실패.
		global_exchange_item_sellstate_not_sell = 52201,	// 표국거래소-아이템구매 가능 상태가 아니다.
		global_exchange_item_buy_result_system_error = 52202,	// 표국거래소-아이템구매 결과 처리 실패.
		event_restore_not_period = 52400,	// 신룡의 축복 기간이 아님
		event_restore_not_have = 52401,	// 복구할 정보없음
		event_restore_error = 52402,	// 신룡의 축복 시스템 에러
		event_restore_item_not_have = 52403,	// 복구할 아이템 정보가 없음
		equipment_awaken_invalid_awaken_step = 52500,	// 잘못된 각성 순서입니다
		equipment_awaken_not_enough_character_expert_condition = 52501,	// 장비 각성 시 캐릭터 조건에 부합하지 않습니다
		equipment_awaken_cannot_awakend = 52502,	// 각성을 진행할 수 없는 장비입니다
		equipment_awaken_not_material_equip_of_same_parts = 52503,	// 동일한 파츠의 재료가 아닙니다
		equipment_awaken_first_awaken_has_not_been_finished = 52504,	// 1차 장비 각성을 하지 않았습니다
		equipment_awaken_second_awaken_already_finished = 52505,	// 2차 장비 각성을 이미 완료했습니다
		equipment_awaken_not_enough_character_level_cnodition = 52506,	// 장비 각성 캐릭터 레벨 조건에 만족하지 않았습니다
		equipment_awaken_not_enough_equip_reinforce_level_cnodition = 52507,	// 장비 강화도 조건에 만족하지 않았습니다
		equipment_awaken_not_enough_equipment_awaken_goods = 52508,	// 장비 각성에 필요한 재화가 부족합니다
		equipment_awaken_cannot_be_used_material = 52509,	// 장비 각성에 사용할 수 없는 재료입니다
		equipment_awaken_cannot_confirmed_option = 52510,	// 장비 각성 옵션 값을 확정 할 수 없는 상태입니다
		occupationwar_challenge_unqualified = 53000,	// 비곡점령전 - 신청시, 신청불가능 서버
		occupationwar_challenge_existence = 53001,	// 비곡점령전 - 신청시, 이미 신청한 문파
		occupationwar_challenge_never_applied = 53002,	// 비곡점령전 - 신청취소, 신청한 적이 없다.
		occupationwar_challenge_not_possible_time = 53003,	// 비곡점령전 - 신청 가능 시간이 아니다
		token_history_item_get_failed = 54000,	// 아이템 회수 실패
		contract_invalid_token = 79000,	// 로그인 토큰이 맞지 않습니다
		contract_invalid_wallet_address = 79001,	// 연동할수 없는 지갑 주소입니다
		contract_fail_darksteelbox_to_token = 79010,	// 흑철상자로 토큰 교환에 실패했습니다
		contract_fail_token_to_darksteelbox = 79011,	// 토큰으로 흑철상자 교환에 실패했습니다
		refinery_not_available_no_darksteel_license = 79012,	// 제련소 이용 불가 - 비곡 채광 자격패가 없습니다
		boss_governance_staking_not_available_time = 79013,	// 보스 거버넌스 - 스테이킹 불가능시간이다
		boss_governance_unstaking_not_available_time = 79014,	// 보스 거버넌스 - 언스테이킹 불가능시간이다
		boss_governance_not_linked_wallet_account = 79015,	// 보스 거버넌스 - 월렛이 연동된 계정이아니다
		boss_governance_staking_server_id_abnormal = 79016,	// 보스 거버넌스 - 잘못된 스테이킹 서버 아이디 선택
		boss_governance_unstaking_server_id_abnormal = 79017,	// 보스 거버넌스 - 잘못된 언스테이킹 서버 아이디 선택
		boss_governance_unstaking_not_available_staking_cooltime = 79018,	// 보스 거버넌스 - 마지막 스테이킹 시점으로부터 시간이 지나지않아 언스테이킹 이용 불가능
		boss_governance_unstaking_not_available_unstaking_cooltime = 79019,	// 보스 거버넌스 - 마지막 언스테이킹 시점으로부터 시간이 지나지않아 언스테이킹 이용 불가능
		boss_governance_staking_success = 79020,	// 보스 거버넌스 - 스테이킹 성공
		boss_governance_unstaking_success = 79021,	// 보스 거버넌스 - 언스테이킹 성공
		boss_governance_staking_fail = 79022,	// 보스 거버넌스 - 스테이킹 실패
		boss_governance_unstaking_fail = 79023,	// 보스 거버넌스 - 언스테이킹 실패
		divine_staking_staking_transaction_fail = 79024,	// 디바인 스테이킹 스테이킹 실패
		dinvine_staking_claim_transaction_fail = 79025,	// 디바인 스테이킹 보상청구 실패
		trade_darksteel_to_token_transaction_fail = 79026,	// 토큰 교환 실패
		trade_token_to_darksteel_transaction_fail = 79027,	// 흑철상자 교환 실패
		unstaking_amount_big_error = 79028,	// 언스테이킹 하려는 양이 보유한 코인양보다 커서 불가
		not_linked_wallet_account = 79029,	// 월렛이 연동된 계정이아니다
		wallet_address_empty_exchange_item = 79030,	// 표국거래소 아이템 판매자 월렛주소가 없다
		wallet_address_different_withdraw_gold = 79031,	// 표국거래소 정산시 월렛 주소가 다르다
		goldexchange_trade_item_does_not_have = 79032,	// 금화 표국거래소 금화거래패 없다.
		divine_staking_claim_cool_time = 79033,	// 디바인 스테이킹 보상청구 쿨타임
		approve_make_fail = 79034,	// approve make 실패
		approve_send_fail = 79035,	// approve send 실패
		contract_wallet_login_fail = 79036,	// 월렛 로그인 실패
		contract_wallet_verify_fail = 79037,	// 디바인 스테이킹 보상청구 쿨타임
		contract_wallet_invalid_address = 79038,	// 연동된 지갑주소와 다른 지갑주소
		contract_wallet_duplicate_wallet = 79039,	// 이미 연동된 지갑 주소
		exchange_Items_not_available_for_purchase = 79040,	// 비정상적으로 등록되어 구매가 불가능합니다.
		governance_sector_info_overlapped = 79041,	// 거버넌스 sector 정보 중복저장 불가
		wemix_shop_error = 79042,
		wemix_shop_start_error = 79043,
		wemix_shop_end_error = 79044,
		wemix_shop_end_api_error = 79045,
		wemix_shop_start_api_error = 79046,
		wemix_shop_end_incorrect_user_address = 79047,
		wemix_shop_end_transaction_error = 79048,
		wemix_shop_not_buy_date = 79049,
		wemix_shop_max_amount_buy_item = 79050,
		wemix_shop_step_package_error = 79051,
		wemix_shop_incorrect_buy_item = 79052,
		party_governance_not_available_delete_character = 79053,	// 파티 던전 거버넌스에 스테이킹한 캐릭터는 삭제할 수 없다
		ad_not_ready = 79101,	// 광고 시청 준비 안됨
		ad_lack_view_count = 79102,	// 광고 시청 횟수 부족
		ad_lack_event_reward = 79103,	// 광고 출석 보상 횟수 부족
		ad_lack_exp_restore = 79104,	// 광고 경험치 복구 횟수 부족
		wmm_api_ad_not_found = 79105,	// 광고를 찾을 수 없습니다
		wmm_api_ad_already_process = 78107,	// 이미 처리된 광고
		account_event_not_comeback_user = 79110,	// 복귀 이벤트 대상자가 아니다
		not_available_charage_subscription_limit_time = 79111,	// 최대 충전 가능 시간을 초과하여 더 이상 충전 할 수 없습니다
		not_map_bind_buff = 79120,	// 사용하려는 스킬 어빌리티가 맵 버프가 아니다
		blood_dedicate_complete = 79130,	// 봉혈하였습니다
		blood_dedicate_complete_unknown_player = 79131,	// 의문의 용사님이 봉혈하였습니다
		not_enough_goods_to_do_blood_dedicate = 79132,	// 봉혈에 필요한 혈석이 부족합니다
		not_blood_dedicate_worldboss_summoned = 79133,	// 보스 출현 중에는 봉혈할 수 없습니다
		not_blood_dedicate_worldboss_spawn_zone = 79134,	// 반야도 월드보스 출현지역이 아닙니다
		blood_stone_point_is_max = 79135,	// 봉혈 랭킹포인트 보유량이 최대치입니다
		not_register_blood_dedicate_worldboss = 79136,	// 봉혈 월드보스 스케줄이 정상 등록되지 않았습니다
		season_mandala_not_open = 79201,	// 아직 새 시즌이 시작되지 않았습니다
		season_mandala_is_null_object = 79202,	// 시즌 만다라 객체가 null이다
		invalid_mandala_type = 79203,	// 적절한 만다라 타입이 아니다
		season_mandala_not_activate_same_layer_differnet_plate = 79204,	// 시즌 만다라 - 동일 레이어 다른 플레이트 활성화 불가
		season_mandala_expert_type_condition_error = 79205,	// 시즌 만다라 - 전직 조건체크 오류
		season_mandala_info_condition_error = 79206,	// 시즌 만다라 - 만다라 정보체크 오류
		season_mandala_slotnode_levelup_impossible = 79207,	// 시즌 만다라 - 슬롯 노드는 레벨업 불가능
		season_mandala_season_info_error = 79208,	// 시즌 만다라 - 시즌 정보 오류
		season_mandala_reward_already_received = 79209,	// 시즌 만다라 - 보상을 이미 수령한 상태
		indun_create_full = 89000,	// //인던-생성요청시-full
		indun_not_exist = 89001,	// //인던-존재하지않는인던.
		joined_the_party = 89002,	// //인던-파티가입상태로진행불가
		not_join_the_party = 89003,	// //인던-파티가입이필요합니다.
		goods_selection_incorrect = 89004,	// //인던-재화선택이잘못되었습니다
		use_daily_plays_count = 89005,	// //인던-일일횟수모두사용
		can_not_change_pksetup = 89006,	// //인던-PK설정변경불가
		users_whose_conditions_not_met = 89007,	// //인던-조건이충족되지않는유저
		can_not_auto_matching = 89008,	// //인던-자동매칭을 신청할수 없는 인던
		not_available_during_dungeon_voting = 89009,	// //인던-던전투표중에는사용할수없음
		not_available_during_dungeon_matching = 89010,	// //인던-던전매칭중에는사용할수없음
		can_not_use_in_dungeon = 89011,	// //인던-던전에서사용할수없음
		indun_enter_vote_cancel = 89012,	// //인던-보스던전 입장 투표 취소
		guild_town_boss_already_spawn = 89013,	// //인던-장원에보스소환이미진행중
		indun_already_clear = 89014,	// 인던-이미완료한던전
		indun_not_time_to_enter = 89015,	// 인던-입장시간이아닙니다
		can_not_use_in_dungeon_party_member = 89018,	// 인던-파티원이 아직 던전에 있습니다.
		contract_fail_darksteelbox_to_token_count = 89019,	// 일일 제련 횟수를 초과하여 제련 할 수 없습니다
		worldserver_cannot_enter = 89020,	// 정복 서버 이용이 제한된 서버입니다
		worldserver_Contents_lock = 89021,	// 정복 서버에서는 이용할 수 없습니다
		worldserver_anatherserver_cannot_party = 89022,
		worldserver_anatherserver_cannot_friend = 89023,	// 다른 서버 유저는 친구 추가할 수 없습니다
		indun_monarch_box_remains = 89024,	// 요마던전 보상박스가 아직 필드에 존재함
		redis_system_error = 90000,	// //redis에러
		redis_data_nil = 90001,	// //redis데이터NULL
		db_system_error = 91000,	// //database에러
		db_duplicate_data_save = 91001,	// //database저장시먼가중복된값을저장할경우.
		invalid_packet = 92000,	// //잘못된패킷
		duplicate_login_close = 92001,	// //중복접속으로더이상게임을할수없다.
		notfound_table_info = 92002,	// //리소스테이블정보가없다.에러
		system_error_relogin = 92003,	// //시스템에러-클라이언트다시로그인해라.
		system_processing_job = 92004,	// //시스템에러-처리중인작업이있다.
		table_data_error = 92005,	// //리소스테이블정보가잘못되었다.
		permission_denied = 93000,	// //adminuser인증실패경우
		rpc_notfound_server = 94000,	// //해당rpc서버를못찾은경우
		rpc_send_system_error = 94001,	// //rpc서버와통신중에러
		monarch_timespace_season_out = 96101,	// //요마 시공 시즌이 아님
		invalid_monarch_timespace_item = 96102,	// //요마 시공에 사용할 수 없는 아이템
		short_of_monarch_timespace_level = 96103,	// //요마 시공 단계 부족
		not_found_monarch_timespace_ability = 96104,	// //존재하지 않는 요마 시공 능력치
		monarch_timespace_already_max = 96105,	// //이미 시공 점수가 최대
		server_relocation_revive_list_is_exists = 94101,	// //서버 이전 에러 캐릭터 사망 복구 리스트가 있다.
		server_relocation_not_processing_location = 94102,	// //서버 이전 에러 실행할 수 없는 지역에 있다.
		server_relocation_is_exist_party = 94103,	// //서버 이전 에러 파티에 참여 중일 경우
		server_relocation_is_exist_cash_shop_cart = 94104,	// //서버 이전 에러 캐시 상점 보관함에 물건이 있을 경우
		server_relocation_is_exist_mail_box = 94105,	// //서버 이전 에러 계정 메일함 제외하고 메일이 있을 경우
		server_relocation_is_exist_party_governance_staking = 94106,	// //서버 이전 에러 파티 거버넌스 스테이킹이 있을 경우
		server_relocation_lower_level = 94107,	// //서버 이전 에러 캐릭터 레벨이 조건에 맞지 않는 경우
		server_relocation_is_exist_street_stall = 94108,	// //서버 이전 에러 개인 노점이 열려있는 경우
		server_relocation_same_gid = 94109,	// //동일한 서버로 이동 시도한 경우
		server_relocation_server_is_busy = 94110,	// //이동할 서버가 혼잡한 경우
		server_relocation_server_cannot_relocated = 94111,	// //이동할 수 없는 서버일 경우
		server_relocation_server_cannot_execute_time = 94112,	// //표국 통행이 불가능한 시간일 경우
		server_relocation_server_cool_time = 94113,	// //표국 통행 쿨타임일 경우
		server_relocation_db_data_is_null = 94114,	// //캐릭터 데이터가 null 일 경우
		server_relocation_max_user_count = 94115,	// //이동 가능 유저 수 제한에 걸렸을 경우
		gm_server_not_found = 98001,	// gm - 서버 찾기 실패
		gm_input_login_info = 98002,	// gm - 로그인 정보 입력 해라
		gm_user_login_failed = 98003,	// gm - 로그인 인증 실패
		gm_user_access_wrong = 98004,	// gm - 잘 못된 접근이다.
		gm_user_access_timeout = 98005,	// gm - 인증만료.
		gm_permission_denied = 98006,	// gm - 권한이 없습니다.
		gm_select_server = 98007,	// gm - 서버를 선택하세요.
		gm_group_info_wrong = 98008,	// gm - 그룹 정보가 잘못 되었습니다.
		gm_table_file_notfound = 98009,	// gm - 테이블 파일을 찾지 못했다.
		gm_patch_file_notfound = 98010,	// gm - 패치할 파일을 찾지 못했다.
		gm_account_name_empty = 98011,	// gm - 계정명을 입력하세요
		gm_account_password_empty = 98012,	// gm - 비밀번호를 입력하세요
		gm_account_uid_empty = 98013,	// gm - 계정이 생성되지 않았습니다(auid)
		gm_username_empty = 98014,	// gm - 계정이 생성되지 않았습니다(username)
		gm_warrior_nickname_empty = 98015,	// gm - 캐릭터명(전사)이 없습니다
		gm_taoist_nickname_empty = 98016,	// gm - 캐릭터명(도사)이 없습니다
		gm_wizard_nickname_empty = 98017,	// gm - 캐릭터명(술사)이 없습니다
		gm_warrior_nickname_overlap = 98018,	// gm - 캐릭터명(전사)이 이미 사용 중입니다
		gm_taoist_nickname_overlap = 98019,	// gm - 캐릭터명(도사)이 이미 사용 중입니다
		gm_wizard_nickname_overlap = 98020,	// gm - 캐릭터명(술사)이 이미 사용 중입니다
		gm_not_save_data = 98021,	// gm - 데이터가 저장되지 않았습니다
		packet_error = 99990,	// //패킷 에러
		system_error = 99999,	// //시스템에러
	};

	enum class mpe_state : uint8_t
	{
		under_maintenance = 0,
		free = 1,
		busy = 2,
		full = 3,
		cannot_move = 4,
	};

	enum class mpe_item_option_enchant : uint8_t
	{
		none = 0,
		max = 5,
	};

	enum class mpe_item_flag : uint8_t
	{
		none = 0,
		stone = 1,
		item = 2,
	};

	enum class mpe_item_enchant_option_make_flag : uint8_t
	{
		make_one = 0,
		make_five = 4,
	};

	enum class mpe_object_collect_flag : uint8_t
	{
		none = 0,
		start = 1,
		finish = 2,
		cancel = 3,
	};

	enum class mpe_item_add_type : uint8_t	// //아이템 생성 타입
	{
		none = 0,	// //일반
		buy = 1,	// //아이템구매
		drop = 2,	// //드랍아이템
		option = 3,	// //옵션이 추가되는 경로
	};

	enum class mpe_guild_donation_type : uint8_t	// 길드기부타입
	{
		gold = 0,
		blackiron = 1,
		goldingot = 2,
	};

	enum class mpe_storage_goods_move : uint8_t
	{
		none = 0,
		toStorage = 1,	// 캐릭터에서 창고로 이동
		toCharacter = 2,	// 창고에서 캐릭터로 이동
	};

	enum class mpe_indun_enter_type : uint8_t	// // 인던 입장 타입
	{
		none = 0,
		direct = 1,	// // 바로입장
		auto_matching = 2,	// // 매칭입장
		siege_def_team = 3,	// // 공성전 수성측
		siege_atk_team = 4,	// // 공성전 공성측
		siege_observer = 5,	// // 공성전 관전
		summon = 6,	// 소환던전관련
	};

	enum class mpe_personal_trade_state : uint8_t	// //거래 상태 타입
	{
		none = 0,
		wait = 1,	// //거래대기중
		trade = 2,	// //거래진행
		trade_lock = 3,	// //lock상태
		confirm = 4,	// //승인상태
	};

	enum class mpe_item_durability_decrement_type : uint8_t
	{
		none = 0,
		attack = 1,	// // 공격
		hit = 2,	// // 피격
		dead = 3,	// // 사망
		mining = 4,	// // 채광
		logging = 5,	// // 벌목
		fishing = 6,	// // 낚시
	};

	enum class mpe_item_durability_repair_type : uint8_t
	{
		none = 0,
		repair = 1,	// // 수리
		recovery = 2,	// // 복구
		repair_all = 3,	// // 착용장비 전체수리
	};

	enum class mpe_daily_reset_time_type : uint8_t
	{
		none = 0,
		repute_quest_finish_count = 1,	// // 평판 퀘스트 완료횟수 초기화 시간
		repute_quest_daily = 2,	// // 평판 퀘스트 재화 리셋 초기화 시간
	};

	enum class mpe_db_skill_type : uint8_t
	{
		none = 0,
		active = 1,	// // 일반스킬
		passive_force = 2,	// // 내공 패시브
		special_move = 3,	// // 필살기
	};

	enum class mpe_guild_war_state : uint8_t	// // 문파 전쟁 상태
	{
		in_progress = 0,	// // 전쟁중
		finished = 1,	// // 전쟁끝
		negotiating = 2,	// // 협상중
	};

	enum class mpe_guild_join_type : uint8_t	// // 문파 가입 방식
	{
		free_join = 0,	// // 자유가입
		need_accept = 1,	// // 승인 후 가입
	};

	enum class mpe_redirect_type : uint8_t
	{
		none = 0,
		zone = 1,
		indun = 2,
		party_teleport = 3,
	};

	enum class mpe_siege_warfare_state : uint8_t
	{
		none = 0,
		wait = 1,	// 공성전기간 아님
		tender = 2,	// 입찰중
		tender_finish = 3,	// 입찰종료
		prepare = 4,	// 준비기간
		prepare_finish = 5,	// 준비기간종료
		enter = 6,	// 공성맵 입장 가능
		enter_finish = 7,	// 공성맵 입장 종료
		battle = 8,	// 공성전 시작
		battle_finish = 9,	// 공성전 종료
	};

	enum class mpe_siege_castle_type : uint8_t
	{
		none = 0,
		sabuk = 1,	// 사북성
		kilung = 2,	// 기륭성
		max = 3,
	};

	enum class mpe_siege_submit_tender_result : uint8_t
	{
		error = 0,	// 에러
		ok = 1,	// 성공
		change_tender = 2,	// 입찰금 변경
		lack_money = 3,	// 입찰금 부족
		no_permission = 4,	// 권한 부족
		already_first = 5,	// 이미 1위길드
		lack_level = 6,	// 레벨 부족
	};

	enum class mpe_siege_alert_type : uint8_t
	{
		return_tender = 0,	// 입찰금반환
		divide_tender = 1,	// 입찰금분배
		alliance_request = 2,	// 문파연합요청
		alliance_accept = 3,	// 문파연합수락
		alliance_reject = 4,	// 문파연합거절
		alliance_kickout = 5,	// 문파연합추방
		alliance_withdrawal = 6,	// 문파연합탈퇴
	};

	enum class mpe_castle_tax_distribution : uint8_t	// 세금 분배 방식
	{
		equal = 0,	// 균등
		differential = 1,	// 차등
	};

	enum class mpe_castle_town_detail_pos : uint8_t
	{
		home = 0,	// 회관
		dungeon = 1,	// 던전
		storage = 2,	// 창고
		training_center = 3,	// 훈련소
		quest_office = 4,	// 연락소
		blacksmith = 5,	// 대장간
		alchemy = 6,	// 제작소
		cooking = 7,	// 푸줏간
		arsenal = 8,	// 병기창
		orchard = 9,	// 과수원
		grove = 10,	// 밭
		farm = 11,	// 목장
		dinner = 12,	// 만찬
		max = 13,
	};

	enum class mpe_chat_system : uint8_t
	{
		notice_msg = 0,	// //전체공지
		get_exp = 1,	// //내경험치
		get_goods = 2,	// //내금전
		pickup_item = 3,	// //내가 아이템획득
		dead_char = 4,	// //사망
		mentor_on = 5,	// //사제 접속
		make_item = 6,	// //제작
		up_item = 7,	// //강화
		bs_item = 8,	// //축복
		get_pet = 9,	// 펫획득
		get_vehicle = 10,	// 탈것획득
		use_box_item = 11,	// 상자에서 아이템획득
		wanted_murder_new = 12,	// 등록
		wanted_murder_change = 13,	// 변경
		wanted_murder_kill = 14,	// 처치
		castle_tax_rate = 15,	// 세금변경
		siege_result = 16,	// 공성결과
		lord_bless = 17,	// 성주 축복
		secretvalley_noti = 18,	// 비곡점령전 전체 알림
		system_rolling = 19,	// 롤링
		system_rolling_chatting = 20,	// 롤링&채팅
		system_chatting = 21,	// 전체 채팅
		system_world = 22,	// 월드 공지
		system_guild = 23,	// 문파 공지
		system_party = 24,	// 파티 공지
		reserved_mail = 25,	// 예약 메일 알림
		get_pet_mix = 26,	// 영물 합성
		get_reflection = 27,	// 화신 소환
		get_reflection_mix = 28,	// 화신 합성
		enchant_stone = 29,	// 용령석 합성
		world_boss_noti = 30,	// 월드보스 알림
		siege_noti = 31,	// 공성전 알림
		treasure_box_open = 32,	// 보물상자 알림
		field_boss_noti = 33,	// 필드보스 알림
		mentee_dead = 34,	// 제자 죽음
		mentee_levelup = 35,	// 제자레벨업
		mentor_off = 36,	// //사제 접속 종료
		demon_tower_on = 37,	// 사령의탑출현
		dimension_dungeon_boss = 38,	// 차원비경 보스 출현
		dimension_schedule_notify = 39,	// "차원비경스케쥴알림 P1:mpe_dimension_dungeon_schedule_type, P2:시작까지남은초 pre_open 일때만 유효"
		expert_grade_up = 40,	// "우화등선 등급 업 알림. P1 해당유저의 등선 등급id."
	};

	enum class mpe_siege_warfare_machine_position : uint8_t
	{
		siege_weapon = 0,	// 공성무기 위치
		castle_guardian = 1,	// 수성 가디언 위치
		mercenary = 2,	// 용병-궁수 위치
		barricade = 3,	// 장애물 위치
	};

	enum class mpe_siege_warfare_machine_type : uint8_t	// 무기타입
	{
		atk_machine = 0,	// 공성용
		def_machine = 1,	// 수성용
	};

	enum class mpe_castle_town_work_type : uint8_t	// 장원 작업 타입
	{
		none = 0,
		house_build = 1,	// 장원 고용
		house_build_cancel = 2,	// 장원 고용 취소
		house_levelup = 3,	// 고용 레벨업
		house_levelup_cancel = 4,	// 고용 레벨업 취소
	};

	enum class mpe_castle_town_change_rental_fee_state : uint8_t	// 장원 유지비 변경 상태
	{
		none = 0,	// 변경상태 아님
		req_castle_owner = 1,	// 성주가 신청
		req_town_owner = 2,	// 장원주인이 신청
	};

	enum class mpe_upgrade_state : uint8_t
	{
		success = 0,	// 증가
		normal = 1,	// 유지
		fail = 2,	// 다운
		destory = 3,	// 파괴
	};

	enum class mpe_castle_town_specialties_pos : uint8_t	// 특산물 작업 
	{
		orchard = 0,	// 과수원
		grove = 1,	// 밭
		farm = 2,	// 목장
		max = 3,
	};

	enum class mpe_object_type : uint8_t	// 오브젝트 타입
	{
		character = 0,	// 캐릭터
		monster = 1,	// 몬스터
		drop_item = 2,	// 드랍아이템
		collect = 3,	// "수집물(채광, 약초, 나무…)"
		npc = 4,	// npc
		character_minion = 5,	// 도사 소환수
		siege_weapon = 6,
		fixed_object = 7,
		mercenary = 8,
		treasure_box = 9,	// 보물상자
		war_flag = 10,	// 깃발
		lord_statue = 11,	// 동상
		occupation_tower = 12,	// 비곡점령전 타워
		seal_device = 13,	// 봉인장치
		demon_summon = 14,	// 사령의기운
		street_stall = 15,	// 개인노점
		max = 16,
	};

	enum class mpe_siege_team_index : uint8_t	// 공성전 팀정보
	{
		def_team = 0,	// 공성전 - 수비팀
		atk_team = 1,	// 공성전 - 공격팀
		observer = 2,	// 공성전 - 관전
	};

	enum class mpe_pet_pos : uint8_t	// 펫위치
	{
		first = 0,
		second = 1,
		third = 2,
		max = 3,	// 창작안함
	};

	enum class mpe_vehicle_food_use : uint8_t
	{
		use = 0,	// 1개씩 사용
		max_use = 1,	// 최대 만복도까지 사용
	};

	enum class mpe_vehicle_expire_type : uint8_t
	{
		satiety = 0,	// 만복도
		date = 1,	// 만료기간
	};

	enum class mpe_siege_message : uint8_t
	{
		none = 0,
		siege_warfare_start = 1,
		destroy_left_wall = 2,
		destroy_center_wall = 3,
		destroy_right_wall = 4,
		gate_open_siege_tower = 5,
		guard_tower_all_destroy = 6,
		destroy_left_1_guard_tower = 7,
		destroy_left_2_guard_tower = 8,
		destroy_right_1_guard_tower = 9,
		victory_check_start = 10,
		siege_warfare_endtime_one_minutes = 11,
		victory_atk = 12,
		victory_def = 13,
		owner_guild_alert = 14,
		victory_time = 15,
		destroy_right_2_guard_tower = 16,
		destroy_victory_object = 17,
	};

	enum class mpe_dead_reason : uint8_t
	{
		normal = 0,	// 일반적인 죽음
		immediate = 1,	// 즉시 죽음
		on_the_wall = 2,	// 성벽위에서 죽음
		trigger_dead = 3,	// 트리거로 제거
	};

	enum class mpe_pk_revenge_trace : uint8_t
	{
		not_found = 0,	// 추적불가
		connect = 1,	// 온라인
		disconnect = 2,	// 오프라인
		is_found = 3,	// 추적완료
	};

	enum class mpe_friend_type : uint8_t
	{
		in_game = 0,	// 게임친구
	};

	enum class mpe_mentor_type : uint8_t
	{
		mentor = 0,	// 스승
		mentee = 1,	// 제자
	};

	enum class mpe_mentor_request_type : uint8_t
	{
		request = 0,	// 요청
		request_accept = 1,	// 수락
		request_cancel = 2,	// 취소
		request_refusal = 3,	// 거절
		request_disband = 4,	// 해체
	};

	enum class mpe_ranking_type : uint8_t
	{
		none = 0,
		personal_power_total = 1,	// 개인 전투력 랭킹(전체)
		personal_power_warrior = 2,	// 개인 전투력 랭킹(전사)
		personal_power_wizard = 3,	// 개인 전투력 랭킹(술사)
		personal_power_taoist = 4,	// 개인 전투력 랭킹(도사)
		personal_level_total = 5,	// 개인 레벨 랭킹(전체)
		personal_level_warrior = 6,	// 개인 레벨 랭킹(전사)
		personal_level_wizard = 7,	// 개인 레벨 랭킹(술사)
		personal_level_taoist = 8,	// 개인 레벨 랭킹(도사)
		guild_all = 9,	// 길드 랭킹
		mining = 10,	// 채광 랭킹
		gather = 11,	// 채집 랭킹
		fishing = 12,	// 낚시 랭킹
		blacksmith = 13,	// 대장 랭킹
		alchemy = 14,	// 연금 랭킹
		handwork = 15,	// 세공 랭킹
		reinforce = 16,	// 강화 랭킹
		enchant = 17,	// 감정 랭킹
		luck = 18,	// 축복 랭킹
		blood_stone_total = 19,	// 혈석 쟁탈 랭킹(전체)
		blood_stone_warrior = 20,	// 혈석 쟁탈 랭킹(전사)
		blood_stone_wizard = 21,	// 혈석 쟁탈 랭킹(술사)
		blood_stone_taoist = 22,	// 혈석 쟁탈 랭킹(도사)
		blood_dedicate_total = 23,	// 봉혈 랭킹(전체)
		blood_dedicate_warrior = 24,	// 봉혈 랭킹(전사)
		blood_dedicate_wizard = 25,	// 봉혈 랭킹(술사)
		blood_dedicate_taoist = 26,	// 봉혈 랭킹(도사)
		dungeon_clear = 27,	// 던전 클리어 랭킹
		max = 28,
	};

	enum class mpe_clinet_platform : uint8_t
	{
		mobile = 0,
		pc = 1,
	};

	enum class mpe_dictionary_type : uint8_t
	{
		none = 0,
		monster = 1,	// 요마 보감
		item = 2,	// 아이템도감
		pet = 3,	// 펫도감
		localcollect = 4,	// 지역수집품
		loststory = 5,	// 숨겨진 이야기
		viewpoint = 6,	// 뷰포인트
		npcInmacy = 7,	// 호감도
		first_kill = 8,	// 몬스터 퍼스트킬
		monster_core = 9,	// 요마 정수 시공
		monster_essence = 10,	// 요마 소환 시공
		max = 11,
	};

	enum class mpe_costume_show : uint8_t
	{
		show = 0,
		hide = 1,
	};

	enum class mpe_view_point_tel_type : uint8_t	// 거점이동 타입
	{
		auto_hunt = 0,	// 자동사냥이동
		instand_move = 1,	// 순간이동
	};

	enum class mpe_wanted_murder_trace : uint8_t
	{
		online = 0,
		offline = 1,
		untraceable = 2,
	};

	enum class mpe_teleport_type : uint8_t	// 텔레포트 타입
	{
		view_point_teleport = 0,	// 거점
		obj_point_teleport = 1,	// 일반
		move_teleport = 2,	// 이동중 텔레포트
		occupation_tower_teleport = 3,	// 비곡점령석 텔레포트
		mentor_teleport = 4,	// 사제텔레포트
	};

	enum class mpe_reinforce_stone_type : uint8_t	// 강화석타입
	{
		normal_stone = 0,	// 일반
		bless_stone = 1,	// 축복
	};

	enum class mpe_reinforce_result : uint8_t
	{
		none = 0,
		reinforce_success = 1,	// 성공
		reinforce_fail = 2,	// 실패
		reinforce_fail_destruction = 3,	// 파괴
		reinforce_success_big = 4,	// 대성공+2
		reinforce_success_best = 5,	// 대성공+3
	};

	enum class mpe_guild_type : uint8_t
	{
		none = 0,	// 문파없음
		normal = 1,	// 일반문파
		beginner = 2,	// 초보문파
	};

	enum class mpe_adult_grade : uint8_t
	{
		kids = 0,
		youth = 1,
		teenager = 2,
		adult = 3,
	};

	enum class mpe_ai_setup_config_pos : uint8_t
	{
		hp_potion_buy = 0,	// hp 포션 구입
		mp_potion_buy = 1,	// mp 포션 구입
		pickup_hp_potion = 2,	// hp 포션 픽업
		pickup_mp_potion = 3,	// mp 포션 픽업
		pickup_gold = 4,	// gold 픽업
		item_decompose = 5,	// 아이템 분해
		item_sell = 6,	// 아이템 판매
		item_repair = 7,	// 아이템 수리
		townreturn_revive = 8,	// 사망후 부활
		townreturn_inven_full = 9,	// 인벤 부족
		townreturn_need_repair = 10,	// 내구도 부족
		townreturn_lack_hp = 11,	// hp 부족
		townreturn_lack_mp = 12,	// mp 부족
		max = 13,
	};

	enum class mpe_guild_shipwar_state : uint8_t
	{
		request = 0,	// 신청기간
		match = 1,	// 매칭중
		match_end = 2,	// 매칭종료
		enter_start = 3,	// 입장시작
		enter_end = 4,	// 입장종료
		indun_complete = 5,	// 인던 생성 완료
	};

	enum class mpe_match_state : uint8_t
	{
		request = 0,	// 신청
		unrequest = 1,	// 미신청
		matching = 2,	// 매칭중
		ready = 3,	// 입장가능
	};

	enum class mpe_guild_shipwar_character_state : uint8_t
	{
		battle = 0,	// 전투중
		leave = 1,	// 퇴장
		revival = 2,	// 부활
	};

	enum class mpe_shipwar_time_type : uint8_t
	{
		wait_time = 0,
		play_time = 1,
		vitory_check_time = 2,
		end_time = 3,
	};

	enum class mpe_guild_shipwar_message : uint8_t
	{
		none = 0,
		guild_shipwar_start = 1,	// 전투시작
		victory_check_start = 2,	// 승리체크
		victory_check_stop = 3,	// 승리체크취소
		guild_shipwar_end = 4,	// 전투종료
	};

	enum class mpe_guild_shipwar_team : uint8_t
	{
		none = 0,
		team_a = 1,
		team_b = 2,
		team_all = 3,
	};

	enum class mpe_pickup_item_type : uint8_t
	{
		none = 0,
		gold = 1,
		exp = 2,
		boss_point = 3,
		item = 4,
	};

	enum class mpe_guild_rank_type : uint8_t
	{
		shipwar = 0,
	};

	enum class mpe_pet_team : uint8_t
	{
		first = 0,
		second = 1,
		third = 2,
		max = 3,
	};

	enum class mpe_challenge_state : uint8_t
	{
		none = 0,	// 진행상태
		completed = 1,	// 보상완료
		repeat = 2,	// 반복
	};

	enum class mpe_seasonpass_reward_type : uint8_t
	{
		daily = 0,	// 일일
		free = 1,	// 무료
		pass = 2,	// 구매
		complete = 3,	// 완료
	};

	enum class mpe_avatar_pos : uint8_t
	{
		none = 0,	// 슬롯장착x
		one = 1,
		two = 2,
		three = 3,
		four = 4,
		five = 5,
		six = 6,
		seven = 7,
		eight = 8,
		nine = 9,
		max = 10,
	};

	enum class mpe_guild_mark_index : uint8_t
	{
		mark = 0,
		background = 1,
		color = 2,
		max = 3,
	};

	enum class mpe_guild_share_storage_log : uint8_t
	{
		none = 0,
		town_get = 1,
		town_return = 2,
		item_in_storage = 3,
		item_get_request = 4,
		item_get = 5,
		max = 6,
	};

	enum class mpe_secretvalley_state : uint8_t
	{
		none = 0,
		init = 1,	// 시작전카운트다운
		play = 2,	// 시작
		finish = 3,	// 종료
		destroy_pre = 4,	// 파괴전알림
		destroy = 5,	// 파괴
		destroy_move_pre = 6,	// 파괴 후 이동 카운트다운 
		restart = 7,	// 파괴 후 다시 시작
		victory = 8,	// 승리
		max = 9,
	};

	enum class mpe_seal_device_state : uint8_t
	{
		none = 0,	// 활성화 가능
		activating = 1,	// 활성화 중
		awaiting = 2,	// 활성화 대기중
	};

	enum class mpe_demon_summon_state : uint8_t
	{
		none = 0,	// 미활성화(상태,알림)
		activate_start = 1,	// 활성화 시작(알림)
		activating = 2,	// 활성화중(상태,알림)
		boss_summon = 3,	// 보스소환(알림)
		activate_end = 4,	// 활성화 종료(알림)
	};

	enum class mpe_occupation_state : uint8_t
	{
		none = 0,	// 비활성
		activating = 1,	// 활성
		immune = 2,	// 무적
	};

	enum class mpe_arena_battle_alert : uint8_t
	{
		none = 0,
		cutscene = 1,
		battle_start = 2,
		battle_result = 3,
	};

	enum class mpe_character_battle_state : uint8_t
	{
		none = 0,	// 상태없음
		battle = 1,	// 전투상태
	};

	enum class mpe_indun_monarch_state : uint8_t
	{
		none = 0,	// 대기
		start_count = 1,	// 시작 카운트
		start = 2,	// 시작
		end = 3,	// 종료
	};

	enum class mpe_guild_goods : uint8_t
	{
		none = 0,
		gold = 1,	// 길드 골드
		exp = 2,	// 길드 경험치
		black_iron = 3,	// 길드 흑철
		goldingot = 4,	// 길드원보
		max = 5,
	};

	enum class mpe_mandala_type : uint8_t
	{
		none = 0,
		character = 1,	// 능력치
		master = 2,	// 장인
		season = 3,	// 시즌
	};

	enum class mpe_os_type : uint8_t
	{
		none = 0,
		os_android = 1,	// 안드로이드
		os_ios = 2,	// IOS
		os_windows = 3,	// 윈도우
		os_dev3d = 4,	// 개발테스트-후에 삭제
		os_all = 5,	// 전체
	};

	enum class mpe_channel_type : uint8_t
	{
		none = 0,
		guest = 1,	// 게스트
		google = 2,	// 구글
		facebook = 3,	// 페이스북
		apple = 4,	// 애플
		kakao = 5,	// 카카오
		stream = 6,	// 스팀
		bot = 7,	// 테스트
	};

	enum class mpe_store_type : uint8_t
	{
		none = 0,
		google_play = 1,
		google_play_12 = 2,
		apple_store = 3,
		apple_store_12 = 4,
		window = 5,
		google_play_cbt = 6,
		google_play_game = 7,
		one_store = 8,
		huawei = 15,
	};

	enum class mpe_collect_result : uint8_t
	{
		none = 0,
		success = 1,	// 성공
		great = 2,	// 대성공
		fail = 3,	// 실패
	};

	enum class mpe_contents_onoff_type : uint8_t
	{
		none = 0,
		field = 1,	// param-map_id
		indun = 2,	// param-dungeon_id
		npc_object = 3,	// param-table->npc_type
		exchange = 4,	// param - 1(서버) / 2(표국) / 3(서버-등록만off) / 4(표국-등록만off) / 5 (글로벌 표국-등록만off) / 6 (글로벌 표국금화-등록만off)
		cash_shop = 5,	// param-cash_shop_table_id
		profesion_make = 6,	// param-1
		mandala = 7,	// param-1
		matching = 8,	// param-mpe_contents_onoff_match_type::arena_battle
		dictionary_achieve = 9,	// param-1
		cash_shop_category = 10,	// 0 (전체상품) / category_table->shop_category (상위 카테고리)
		cash_shop_category_detail = 11,	// category_table->sell_category_id (서브 카테고리)
		event_ingame_exp_increase = 12,	// param-1
		uncheater_check_mode = 13,	// param // 0 : disable, 1 : enable, 2 : enable block
		occupationwar = 14,	//  param // 1 : 비곡점령전 진행 (false 면  off), 2 : 흑철 스테이킹 (false 면 off)
		nprotect_check_mode = 15,	// param // 0 : disable, 1 : enable
		dogma_system = 16,	// param // 1 : 전체기능, 2 : 제련소, 3 : 디바인 스테이킹, 4 : 보스 거버넌스
		global_occupationwar = 17,	//  param // 1 : 비곡점령전 진행 (false 면  off), 2 : 흑철 스테이킹 (false 면 off)
		darksteel_storage = 18,	//  param // 1 : 창고 사용 (false 면  off)
		global_exchange = 19,	//  param // 1 : 전체기능, 2 : 목록, 3 : 판매등록, 4 : 아이템 구매, 5 : 상품수령, 6 : 정산
		global_gold_exchange = 20,	//  param // 1 : 전체기능, 2 : 목록, 3 : 판매등록, 4 : 아이템 구매, 5 : 상품수령, 6 : 정산
		wemix_doller_shop = 21,	// param-1
		gloabl_party_governance = 22,	// param-1
		advertisement = 23,	// param-1
		server_relocation = 24,	// param-1
		monarch_dungeon = 25,	// param // 1:전체기능, 2: 요마소환, 3: 요마보감, 4:요마시공
		world_game = 26,	// param // 1:진입
		season_mandala = 27,	// param // 1:전체기능
		restore_event = 28,	// param // 1:전체기능, 2:장비, 3:화신/영물 
		guild_ally = 29,	// "param // 0:오픈, 1:초대,수락,해제 사용불가"
	};

	enum class mpe_contents_onoff_restore_event_type : uint8_t
	{
		none = 0,
		all = 1,
		item = 2,
		compose = 3,
	};

	enum class mpe_contents_onoff_match_type : uint8_t
	{
		none = 0,
		arena_battle = 1,
	};

	enum class mpe_contents_onoff_occupationwar_type : uint8_t
	{
		none = 0,
		occupationwar_onoff = 1,
		darksteel_box_onoff = 2,
		max = 3,
	};

	enum class mpe_contents_onoff_param_dogma_type : uint8_t
	{
		none = 0,
		all = 1,	// 전체기능
		smelt = 2,	// 제련소
		divine = 3,	// 디바인 스테이킹
		boss = 4,	// 보스 거버넌스
	};

	enum class mpe_contents_onoff_param_globol_exchange_type : uint8_t
	{
		none = 0,
		all = 1,	// 전체기능
		list = 2,	// 목록
		sales = 3,	// 판매등록
		buy = 4,	// 아이템 구매
		receive = 5,	// 상품수령
		calculate = 6,	// 정산
		cancel = 7,	// 취소
	};

	enum class mpe_contents_onoff_world_game_type : uint8_t
	{
		none = 0,
		enter_map = 1,
		dimension = 2,
		blood_dedicate = 3,
		max = 4,
	};

	enum class mpe_deploy_version : uint8_t
	{
		master = 0,
		qa = 1,
		alpha = 2,
		beta = 3,
		ios_review = 4,
		google_featured = 5,
		live = 6,
		stage = 7,
		max = 8,
	};

	enum class mpe_coupon_type : uint8_t
	{
		none = 0,
		internal_coupon = 1,
		external_coupon = 2,
	};

	enum class mpe_cash_exchange_type : uint8_t
	{
		daily = 0,	// 기간
		goods = 1,	// 재화
		item = 2,	// 아이템
	};

	enum class mpe_recovery_exp_type : uint8_t
	{
		free = 0,	// 무료복구
		normal = 1,	// 일반복구
		unique = 2,	// 고급복구
		item = 3,	// 아이템복구
		advertisement = 4,	// 광고 복구
	};

	enum class mpe_title_type : uint8_t
	{
		none = 0,	// // 기존 칭호
		mentor_title = 1,	// // 사제 칭호
		max = 2,
	};

	enum class mpe_cash_shop_item_state : uint8_t
	{
		sale_disable = 0,	// // 비활성
		sale_enable = 1,	// // 활성
		time_enable = 2,	// // 기간제
	};

	enum class mpe_event_ingame : uint8_t
	{
		exp_increase = 0,	// // 경험치 이벤트
		max = 1,
	};

	enum class mpe_item_delete_cause : uint8_t
	{
		none = 0,
		reinforce = 1,	// 강화실패로 삭제
		disassemble = 2,	// 분해로 삭제
		sell = 3,	// 판매 삭제
		destroy = 4,	// 파기로 삭제
		stall_reinforce = 5,	// 노점파기로 삭제
	};

	enum class mpe_darksteel_storage_good_pos : uint8_t
	{
		guid = 0,
		amount = 1,	// 총보관
		income = 2,	// 총수입
		expense = 3,	// 총지출
		darksteel_tax = 4,	// 흑철 일일 채굴 세금
		darksteel_collect = 5,	// 흑철 일일 채광량
		governance_tax = 6,	// 거버넌스 세금
		darksteel_tax_history = 7,	// 흑철 일일 채굴 세금(하루전)
		governance_tax_history = 8,	// 거버넌스 세금(하루전)
		max = 9,
	};

	enum class mpe_darksteel_box_keep_type : uint8_t	// 흑철상장 입/출 내역
	{
		none = 0,
		occupationwar_tender_deposit = 1,	// 점령전 입찰소 입금
		occupationwar_tender_withdraw = 2,	// 점령전 입찰소 출금
	};

	enum class mpe_occupationwar_map_type : uint8_t	// 비곡종류
	{
		none = 0,
		bicheon = 1,	// 비천
		snakevalley = 2,	// 뱀골
		mongchon = 3,	// 몽촌
		max = 4,
	};

	enum class mpe_darksteel_storage_pay_type : uint8_t	// 비곡창고-사용내역-종류
	{
		none = 0,
		income = 1,	// 세금
		sell = 2,	// 판매
		pay_guild_owner = 3,	// 나의 문파 지급
		pay_guild_other = 4,	// 타 문파 지급
		pay_user_guild = 5,	// 개인지급-문파원
		pay_user_other = 6,	// 개인지급-타유저
		pay_tax = 7,	// 지급-조공받침
		get_tax_1 = 8,	// 받음-1위조공받음
		get_tax_2 = 9,	// 받음-2위조공받음
		get_tax_3 = 10,	// 받음-3위조공받음
		get_tax_4 = 11,	// 받음-4조공받음
		system_payment = 12,	// 시스템에서 지급
		system_withdraw = 13,
		max = 14,
	};

	enum class mpe_occupationwar_schedule_type : uint8_t
	{
		none = 0,
		schedule_in_start = 1,	// 스케줄 시작정보
		schedule_in_finish = 2,	// 스케줄 완료정보
		darksteelbox_deposit_start_1 = 3,	// 흑철상자 입금 시작1
		darksteelbox_deposit_end_1 = 4,	// 흑철상자 입금 종료1
		darksteelbox_deposit_start_2 = 5,	// 흑철상자 입금 시작2
		darksteelbox_deposit_end_2 = 6,	// 흑철상자 입금 종료2
		darksteelbox_withdraw_1_start = 7,	// 흑철상자 출금 시작 1
		darksteelbox_withdraw_1_end = 8,	// 흑철상자 출금 종료 1
		darksteelbox_withdraw_2_start = 9,	// 흑철상자 출금 시작 2
		darksteelbox_withdraw_2_end = 10,	// 흑철상자 출금 종료 2
		darksteelbox_staking_ranking = 11,	// 흑철상자 스테이킹 서버결정
		occupationwar_darkstee_tax = 12,	// 비곡점령전 미진행 서버 흑철 조공
		occupationwar_challenge_start = 13,	// 비곡점령전 참가신청 시작
		occupationwar_challenge_end = 14,	// 비곡점령전 참가신청 끝
		occupationwar_war_noti = 15,	// 비곡점령전 전쟁 알림
		occupationwar_war_start = 16,	// 비곡점령전 전쟁 시작
		occupationwar_war_end = 17,	// 비곡점령전 전쟁 끝
		max = 18,
	};

	enum class mpe_recipe_type : uint8_t
	{
		none = 0,
		recipe_type_account = 1,
		recipe_type_character = 2,
		recipe_type_server = 3,
	};

	enum class mpe_governance_result : uint8_t	// 거버넌스 결과
	{
		none = 0,	// 성공
		staking_success = 1,	// 스테이킹 성공
		staking_fail = 2,	// 스테이킹 실패
		unstaking_success = 3,	// 언스테이킹 성공
		unstaking_fail = 4,	// 언스테이킹 실패
		not_choosed_staking_server = 5,	// 스테이킹할 서버 미선택
		not_choosed_unstaking_server = 6,	// 언스테이킹할 서버 미선택
		success_login = 7,	// 월렛 연동 성공
		success_first_login = 8,	// 월렛 첫 연동 성공
		fail_already_another_connected = 9,	// 월렛 연동 실패(다른 월렛이 연동된 상태)
		fail_login_overlap = 10,	// 월렛 연동 실패(중복 로그인)
		fail_contract = 11,	// 월렛 연동 실패(contract 로그인 실패)
	};

	enum class mpe_governance_contents_type : uint8_t	// 거버넌스 콘텐츠 타입
	{
		none = 0,	// 없음
		boss = 1,	// 보스
		occupationwar = 2,	// 비곡점령전
		siegewar = 3,	// 공성전
		party = 4,	// 파티
	};

	enum class mpe_coin_staking_type : uint8_t	// 거버넌스 스테이킹 타입
	{
		none = 0,	// 없음
		staking = 1,	// 스테이킹(입금)
		unstaking = 2,	// 언스테이킹(출금)
	};

	enum class mpe_exchange_type : uint8_t	// 거래소 타입
	{
		server = 0,
		world = 1,
		world_gold = 2,
		max = 3,
	};

	enum class mpe_token_type : uint8_t	// 토큰 타입
	{
		none = 0,
		drone = 1,
		hydra = 2,
		dogma = 3,
		wemix_doller = 4,
		swap_range_start = 5,
		w_flero = 6,
		w_sloco = 7,
		w_lordcoin = 8,
		w_herco = 9,
		w_gbmilico = 10,
		w_mco = 11,	// w는 스왑 토큰
		w_tornado_token = 12,
		w_tig = 13,
		w_stc = 14,
		w_ros_silthereum = 15,
		w_ranaia_ria = 16,
		w_reflect_token = 17,
		w_wemix_token_away = 18,
		w_four_gods_lux = 19,
		w_incar = 20,
		w_mir4_hydra = 21,
		w_honco = 22,
		w_drone = 23,
		w_mir4_darksteel = 24,
		w_dogma = 25,
		w_darkeden_mdebco = 26,
		w_cqb = 27,
		w_blz = 28,
		w_asu_anitas = 29,
		w_abyco = 30,
		w_myrtle = 31,
		w_bluepaw = 32,
		w_zuanshi = 33,
		swap_range_end = 34,
		dogma_shop = 35,
	};

	enum class mpe_contract_type : uint8_t	// 컨트랙트 타입
	{
		none = 0,
		drone = 1,
		hydra = 2,
		divine = 3,
		governonce = 4,
		exchange = 5,
		swap = 6,
		dogma = 7,
	};

	enum class mpe_exchange_history_type : uint8_t
	{
		sell = 0,
		buy = 1,
	};

	enum class mpe_token_history_type : uint8_t
	{
		none = 0,
		smelter = 1,	// 제련소
		devine_staking = 2,	// devine staking
		boss_governnance = 3,	// 보스거버넌스
		occupationwar_governnance = 4,	// 비곡거버넌스
		party_governance = 5,	// 파티거버넌스
	};

	enum class mpe_token_history_case : uint8_t
	{
		none = 0,
		smelter_success = 1,	// 제련소-제련성공
		smelter_failure = 2,	// 제련소-제련실패
		smelter_exchange_success = 3,	// 제련소-교환성공
		devine_staking_drone = 4,	// devine staking - drone 예치성공
		devine_staking_hydra = 5,	// devine staking - hydra 예치성공
		devine_staking_dogam = 6,	// devine staking - dogma 보상청구 성공
		governnance_vote_success = 7,	// 거버넌스-투표성공
		governnance_vote_failure = 8,	// 거버넌스-투표실패
		governnance_collect_success = 9,	// 거버넌스-회수성공
		governnance_collect_failure = 10,	// 거버넌스-회수실패
	};

	enum class mpe_language_type : uint8_t
	{
		cs = 0,
		ct = 1,
		DE = 2,
		EN = 3,
		ESLATAM = 4,
		ID = 5,
		JA = 6,
		KO = 7,
		PTBR = 8,
		RU = 9,
		TH = 10,
		VI = 11,
	};

	enum class mpe_global_party_governance_rank_type : uint8_t
	{
		my = 0,
		now = 1,
		result = 2,
	};

	enum class mpe_gameserver_type : uint8_t
	{
		game = 0,
		community = 1,
		gate = 2,
	};

	enum class mpe_account_category : uint8_t
	{
		usual = 0,
		comeback = 1,
		newbie = 2,
	};

	enum class mpe_server_relocate_type : uint8_t
	{
		none = 0,
		period = 1,
		datetime = 2,
		level = 3,
		location = 4,
		party = 5,
		guild = 6,
		exchange = 7,
		store = 8,
		governance = 9,
		arena = 10,
		mail = 11,
		street_stall = 12,
		death_info = 13,
	};

	enum class mpe_dimension_dungeon_gate_state_type : uint8_t
	{
		none = 0,
		activate = 1,
		boss_summon = 3,
		deactivate = 4,
	};

	enum class mpe_dimension_dungeon_schedule_type : uint8_t
	{
		none = 0,	// 초기 값
		pre_open = 1,	// 시작30분전카운트
		open = 2,	// 시작
		close = 3,	// 종료
	};

	enum class mpe_blood_dedicate_worldboss_state : uint8_t	// 봉혈 시스템 월드보스 상태
	{
		none = 0,	// 보스 미소환 상태
		ready = 1,	// 보스소환 유예시간 진행 중
		summon = 2,	// 보스소환 상태
	};

	enum class mpe_gm_blood_dedicate_worldboss_type : uint8_t	// 치트키 - 봉혈 보스소환 관련 치트타입
	{
		none = 0,	// 초기 값
		contribution_increase = 1,	// 기여도 증가
		summon = 2,	// 즉시 소환
	};

	enum class mpe_guild_ally_alert_type : uint8_t	// 길드 알림 타입 mp_guild_ally_alert_sc로 전달
	{
		none = 0,	// 초기 값
		ally = 1,	// 동맹채결됨
		ally_cancel = 2,	// 동맹해제됨
		ally_request_received = 3,	// 동맹신청받음
		ally_request_denied = 4,	// 동맹신청거절받음
		ally_member_update = 5,	// "동맹멤버갱신(문주,부문주)"
	};

	enum class mpe_restore_event_type : uint8_t	// 신룡의축복 복구 타입
	{
		reflection = 0,	// 화신
		pet = 1,	// 영물
		weapon = 2,	// 무기
		armor = 3,	// 갑옷
		helmet = 4,	// 투구
		shoes = 5,	// 신발
		necklace = 6,	// 목걸이
		ring = 7,	// 반지
		belt = 8,	// 허리띠
		bracelet = 9,	// 팔찌
		paid_acc = 10,	// 유료장신구(신룡의보구)20240206 koansik
		max = 11,
	};

	enum class mpe_season_mandala_state : uint8_t	// 시즌 만다라 - 시즌 상태
	{
		none = 0,	// 초기 값
		open = 1,	// 시즌 오픈
		close = 2,	// 시즌 종료
	};

	enum class mpe_contents_onoff_mandala_type : uint8_t	// 만다라 - 콘텐츠 onoff 타입
	{
		none = 0,	// 초기 값
		character_and_master = 1,	// 전투 및 기술 만다라 전체기능
		season = 2,	// 시즌 만다라 전체기능
	};

	enum class mpe_season_mandala_reward_receive_type : uint8_t	// 시즌 만다라 - 보상수령 타입
	{
		none = 0,	// 초기 값
		reward_acceptable = 1,	// 보상수령 가능
		reward_received = 2,	// 보상수령 완료
	};

	enum class mpe_chained_buff_name : uint8_t	// 일괄 종료될 버프 종류 이름 지정자 - 현재는 신기만
	{
		none = 0,	// 일괄 종료 없음 기본값
		expert_buff = 1,	// 신기 관련 버프
	};

	struct BasePacket
	{
		int32_t len_;
		mpe_cmd command_;
#ifdef _USE_NEW_PACKET_HEADER
		int32_t param_;
#else
		uint8_t flag_;
		uint8_t resv_;
#endif

#ifdef _USE_NEW_PACKET_HEADER
		BasePacket() : len_(0), command_(mpe_cmd::none), param_(0)
#else
		BasePacket() : len_(0), command_(mpe_cmd::none), flag_(0), resv_(0)
#endif
		{
		}
#ifdef _USE_NEW_PACKET_HEADER
		BasePacket(mpe_cmd cmd) : len_(0), command_(cmd), param_(0)
#else
		BasePacket(mpe_cmd cmd) : len_(0), command_(cmd), flag_(0), resv_(0)
#endif
		{
		}
		virtual ~BasePacket()
		{
		}
		template <typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			if (T_BUFFER::cIsWriter)
			{
				pBuffer->Serialize4((int32_t*)&len_);
				pBuffer->Serialize2((uint16_t*)&command_);
#ifdef _USE_NEW_PACKET_HEADER
				pBuffer->Serialize4((int32_t*)&param_);
#endif
			}
#ifdef _USE_NEW_PACKET_HEADER
#else
			pBuffer->Serialize1(&flag_);
			pBuffer->Serialize1(&resv_);
#endif

			pBuffer->SetSerializeCommand(static_cast<uint16_t>(command_));

			/* if (T_BUFFER::cIsWriter)
			{
				pBuffer->Serialize4((int32_t*)&len_);
				pBuffer->Serialize2((uint16_t*)&command_);
			}
			pBuffer->Serialize1(&flag_);
			pBuffer->Serialize1(&resv_); */
		}
		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			if (T_BUFFER::cIsWriter)
			{
				pBuffer->SerializeEnd(length);
			}
		}
	};

	struct WebBasePacket
	{
		uint8_t m_flag;

		WebBasePacket() : m_flag(0)
		{
		}
		virtual ~WebBasePacket()
		{
		}
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			pBuffer->Serialize1(&m_flag);
		}
		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer,int16_t length)
		{
		}
	};
}
