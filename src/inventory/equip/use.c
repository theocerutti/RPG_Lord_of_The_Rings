/*
** EPITECH PROJECT, 2019
** use item
** File description:
** rpgez
*/

#include "my_rpg.h"

void use_item(data_t *data, int index)
{
    if (data->hero.inventory.bag[index][0] != 9 && \
    data->hero.inventory.bag[index][0] != 22) {
        cost_life_hero(data, \
        data->item_ref[data->hero.inventory.bag[index][0]].stat.life, HEAL);
        delete_inventory_item(data, index);
    } else if (data->hero.inventory.bag[index][0] == 22) {
        cost_mana_hero(data, \
        data->item_ref[data->hero.inventory.bag[index][0]].stat.mana, HEAL);
        delete_inventory_item(data, index);
    }
}