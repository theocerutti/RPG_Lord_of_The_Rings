/*
** EPITECH PROJECT, 2019
** place merchant when boss is defeated
** File description:
** rpg
*/

#include "my_rpg.h"

void place_merchant(data_t *data, character_t boss)
{
    sfVector2f pos_use = sfSprite_getPosition(boss.obj.s);

    pos_use.x += 60;
    pos_use.y -= 35;
    sfSprite_setPosition(data->merch.t.obj.s,
    sfSprite_getPosition(boss.obj.s));
    sfSprite_setPosition(data->merch.use.s, pos_use);
    data->merch.t.obj.pos = sfSprite_getPosition(boss.obj.s);
    data->merch.use.pos = pos_use;
    data->merch.cur_m = data->cur;
}