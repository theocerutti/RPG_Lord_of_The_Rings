/*
** EPITECH PROJECT, 2019
** spell1 overview setting up
** File description:
** rpg
*/

#include "my_rpg.h"

void set_spell2(data_t *data)
{
    sfVector2i new_pos = sfMouse_getPositionRenderWindow(data->window.w);
    sfVector2f origin = {data->overview[2].radius, data->overview[2].radius};

    data->overview_activate[2] = 1;
    data->overview[2].pos.x = (float)new_pos.x;
    data->overview[2].pos.y = (float)new_pos.y;
    sfCircleShape_setPosition(data->overview[2].overview_c, \
    data->overview[2].pos);
    sfCircleShape_setOrigin(data->overview[2].overview_c, origin);
}

void set_spell3(data_t *data)
{
    sfVector2f size = {
        data->hero.obj.offset.x / 2 + 10,
        data->hero.obj.offset.y / 2
    };
    sfVector2f origin = {
        data->overview[3].radius - size.x,
        data->overview[3].radius - size.y
    };

    data->overview_activate[3] = 1;
    sfCircleShape_setOrigin(data->overview[3].overview_c, origin);
}