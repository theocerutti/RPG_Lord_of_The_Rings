/*
** EPITECH PROJECT, 2019
** init_scenes
** File description:
** init_scenes
*/

#include "my_rpg.h"

void init_scenes2(data_t *d)
{
    set_data_scene(d, LVL_1_F, (info_scene_t){0, 1, 0, 0, TRUE, TRUE});
    set_data_scene(d, LVL_1_C, (info_scene_t){0, 1, 0, 30, TRUE, TRUE});
    set_data_scene(d, LVL_2_F, (info_scene_t){0, 1, 0, 30, TRUE, TRUE});
    set_data_scene(d, LVL_2_C, (info_scene_t){0, 1, 0, 30, TRUE, TRUE});
    set_data_scene(d, LVL_3_F, (info_scene_t){0, 1, 0, 30, FALSE, TRUE});
    set_data_scene(d, LVL_3_C, (info_scene_t){0, 1, 0, 30, FALSE, TRUE});
    set_data_scene(d, DIE, (info_scene_t){3, 1, 4, 0, FALSE, FALSE});
    set_data_scene(d, INVENTORY, (info_scene_t){0, 34, 10, 0, FALSE, FALSE});
    set_data_scene(d, MERCHANT, (info_scene_t){0, 26, 10, 0, FALSE, FALSE});
    set_data_scene(d, END, (info_scene_t){1, 1, 0, 0, FALSE, FALSE});
}

void init_scenes1(data_t *d)
{
    set_data_scene(d, MENU, (info_scene_t){6, 1, 0, 0, TRUE, FALSE});
    set_data_scene(d, NEW_GAME, (info_scene_t){3, 3, 1, 0, FALSE, FALSE});
    set_data_scene(d, CREDITS, (info_scene_t){1, 1, 1, 0, FALSE, FALSE});
    set_data_scene(d, PAUSE, (info_scene_t){5, 1, 0, 0, FALSE, FALSE});
    set_data_scene(d, CONTROL, (info_scene_t){7, 1, 6, 0, FALSE, FALSE});
    set_data_scene(d, HUD, (info_scene_t){0, 13, 26, 0, FALSE, FALSE});
    set_data_scene(d, SETTING, (info_scene_t){4, 1, 0, 0, FALSE, FALSE});
    set_data_scene(d, FPS_SETTING, (info_scene_t){6, 1, 6, 0, FALSE, FALSE});
    set_data_scene(d, AUDIO_SETTING, (info_scene_t){3, 3, 4, 0, FALSE, FALSE});
    set_data_scene(d, HELP_C, (info_scene_t){3, 2, 0, 0, FALSE, FALSE});
    set_data_scene(d, HELP_I, (info_scene_t){3, 2, 0, 0, FALSE, FALSE});
    set_data_scene(d, HELP_M, (info_scene_t){3, 2, 0, 0, FALSE, FALSE});
}

void init_all_scenes(data_t *d)
{
    d->scenes = malloc(sizeof(scene_t) * NULL_SCENE);
    init_scenes1(d);
    init_scenes2(d);
    init_all_scenes_data(d);
    d->boss.boss = 0;
    d->next_map = 0;
}