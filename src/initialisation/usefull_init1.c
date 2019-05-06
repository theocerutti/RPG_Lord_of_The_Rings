/*
** EPITECH PROJECT, 2019
** usefull_init
** File description:
** usefull_init
*/

#include "my_rpg.h"

void set_data_scene(data_t *data, int scene_id, info_scene_t info)
{
    data->scenes[scene_id].have_particle_system = info.have_particle_system;
    data->scenes[scene_id].have_collide_map = info.have_collide_map;
    if (info.have_particle_system)
        data->scenes[scene_id].particle_sys =
        malloc(sizeof(particle_system_t));
    else
        data->scenes[scene_id].particle_sys = NULL;
    data->scenes[scene_id].col = NULL;
    data->scenes[scene_id].list_ch = NULL;
    data->scenes[scene_id].nb_ch = info.nb_character;
    data->scenes[scene_id].nb_but = info.nb_button;
    data->scenes[scene_id].nb_obj = info.nb_obj;
    data->scenes[scene_id].nb_txt = info.nb_txt;
    data->scenes[scene_id].txt = malloc(sizeof(txt_t) * info.nb_txt);
    data->scenes[scene_id].objs = malloc(sizeof(game_object_t) * info.nb_obj);
    data->scenes[scene_id].buttons = malloc(sizeof(button_t) * info.nb_button);
}