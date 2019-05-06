/*
** EPITECH PROJECT, 2019
** draw trader
** File description:
** rpg
*/

#include "my_rpg.h"

void draw_merchant(data_t *data)
{
    anim_obj_simple(&data->merch.t.obj, 0.2);
    sfRenderWindow_drawSprite(data->window.w, data->merch.t.obj.s, NULL);
    if (can_merch(data) == 1)
        sfRenderWindow_drawSprite(data->window.w, data->merch.use.s, NULL);
}