/*
** EPITECH PROJECT, 2019
** clean
** File description:
** clean
*/

#include "my_rpg.h"

void free_all_sfx(game_sfx_t *game_sfx)
{
    for (int i = 0; i < game_sfx->nb_sfx; i++)
        free_sfx_object(&game_sfx->sfx[i]);
}

void free_all_scenes(scene_t *scene)
{
    for (int scenes_id = 0; scenes_id < NULL_SCENE; scenes_id++) {
        for (int j = 0; j < scene[scenes_id].nb_obj; j++) {
            free_game_object(&scene[scenes_id].objs[j]);
        }
        for (int j = 0; j < scene[scenes_id].nb_but; j++) {
            free_button(&scene[scenes_id].buttons[j]);
        }
        for (int j = 0; j < scene[scenes_id].nb_txt; j++) {
            free_txt_obj(&scene[scenes_id].txt[j]);
        }
        delete_list(&scene[scenes_id].list_ch);
    }
    free(scene);
}

void cleanup(data_t *data)
{
    free_game_object(&data->cursor);
    free_character_obj(&data->hero);
    free_all_sfx(&data->sfx);
    sfRenderWindow_destroy(data->window.w);
}