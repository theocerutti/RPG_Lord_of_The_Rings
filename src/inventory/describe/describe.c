/*
** EPITECH PROJECT, 2019
** describe src
** File description:
** rpg
*/

#include "my_rpg.h"

void description_item(data_t *data, int index)
{
    sfSprite_setTextureRect(data->scenes[INVENTORY].objs[33].s, \
    data->item_ref[data->hero.inventory.bag[index][0]].item.rect);
    sfText_setString(data->scenes[INVENTORY].txt[0].txt, \
    data->item_ref[data->hero.inventory.bag[index][0]].stat.name);
    sfText_setString(data->scenes[INVENTORY].txt[1].txt, \
    data->item_ref[data->hero.inventory.bag[index][0]].stat.describe);
    sfText_setString(data->scenes[INVENTORY].txt[2].txt, \
    my_itoa(data->item_ref[data->hero.inventory.bag[index][0]].stat.attack));
    sfText_setString(data->scenes[INVENTORY].txt[3].txt, \
    my_itoa(data->item_ref[data->hero.inventory.bag[index][0]].stat.defense));
    sfText_setString(data->scenes[INVENTORY].txt[4].txt, \
    my_itoa(data->item_ref[data->hero.inventory.bag[index][0]].stat.mana));
    sfText_setString(data->scenes[INVENTORY].txt[5].txt, \
    my_itoa(data->item_ref[data->hero.inventory.bag[index][0]].stat.life));
}