/*
** EPITECH PROJECT, 2019
** delete item in inventory
** File description:
** rpg
*/

#include "my_rpg.h"

void delete_inventory_item(data_t *data, int index)
{
    int stock[3] = {26, 0, 7};

    for (int i = 0; i < 3; i++)
        data->hero.inventory.bag[index][i] = stock[i];
    if (sfSound_getStatus(data->sfx.sfx[12].sound) != sfPlaying)
        sfSound_play(data->sfx.sfx[12].sound);
}