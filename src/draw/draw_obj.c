/*
** EPITECH PROJECT, 2019
** draw_obj
** File description:
** draw_obj
*/

#include "my_rpg.h"

void draw_txt_scenes(data_t *d, int scene_id)
{
    for (int i = 0; i < d->scenes[scene_id].nb_txt; i++) {
        sfRenderWindow_drawText(d->window.w,
        d->scenes[scene_id].txt[i].txt, NULL);
    }
}

void draw_objs_scenes(data_t *d, int scene_id)
{
    for (int i = 0; i < d->scenes[scene_id].nb_obj; i++) {
        sfRenderWindow_drawSprite(d->window.w,
        d->scenes[scene_id].objs[i].s, NULL);
    }
}

void draw_button_scenes(data_t *d, int scene_id)
{
    for (int i = 0; i < d->scenes[scene_id].nb_but; i++) {
        sfRenderWindow_drawRectangleShape(d->window.w,
        d->scenes[scene_id].buttons[i].obj, NULL);
        sfRenderWindow_drawText(d->window.w,
        d->scenes[scene_id].buttons[i].txt.txt, NULL);
    }
}