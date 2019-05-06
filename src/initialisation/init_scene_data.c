/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init_menu
*/

#include "my_rpg.h"

void init_all_scenes_data2(data_t *data)
{
    init_merchant(data);
    init_setting_menu(data);
    init_audio_setting_menu(data);
    init_die_menu(data);
    init_fps_setting_menu(data);
    init_full_particle_system_smoke(data, data->scenes[MENU].particle_sys);
    init_full_particle_system_fire(data, data->scenes[LVL_1_F].particle_sys);
    init_full_particle_system_snow(data, data->scenes[LVL_1_C].particle_sys);
    init_full_particle_system_rain(data, data->scenes[LVL_2_F].particle_sys);
    init_full_particle_system_rain(data, data->scenes[LVL_2_C].particle_sys);
}

void init_all_scenes_data(data_t *data)
{
    init_collide(data);
    init_main_menu(data);
    init_new_game_menu(data);
    init_all_credits(data);
    init_pause_menu(data);
    init_hud(data);
    init_game(data);
    for (int scene = LVL_1_F; scene <= LVL_3_C; scene++)
        init_basic_enemy_for_scene(data, scene);
    init_inventory(data);
    init_button_help_c_menu(data);
    init_button_help_m_menu(data);
    init_button_help_i_menu(data);
    init_obj_help_c_menu(data);
    init_obj_help_m_menu(data);
    init_obj_help_i_menu(data);
    init_all_control_menu(data);
    init_all_scenes_data2(data);
    init_end(data);
}