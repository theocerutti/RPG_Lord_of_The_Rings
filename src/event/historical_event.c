/*
** EPITECH PROJECT, 2019
** historical_event
** File description:
** historical_event
*/

#include "my_rpg.h"

void add_item_to_historical(scene_t *hud, item_t *item_ref, int index_item)
{
    char const *name = NULL;

    for (int i = 3; i >= 0; i--) {
        hud->objs[9 + i].rect = hud->objs[9 + i - 1].rect;
        sfSprite_setTextureRect(hud->objs[9 + i].s, hud->objs[9 + i].rect);
        name = sfText_getString(hud->txt[21 + i - 1].txt);
        sfText_setString(hud->txt[21 + i].txt, name);
    }
    hud->objs[9].rect = item_ref[index_item].item.rect;
    sfSprite_setTextureRect(hud->objs[9].s, hud->objs[9].rect);
    sfText_setString(hud->txt[21].txt, item_ref[index_item].stat.name);
}