/*
** EPITECH PROJECT, 2019
** function in order to print the inventory
** File description:
** rpg inventory
*/

#include "my_rpg.h"

void inventory_handling(data_t *data)
{
    if (data->cur == INVENTORY) {
        for (int i = 0; i < MAX_BAG; i++) {
            data->scenes[INVENTORY].objs[i + 1].rect.top =
            data->item_ref[data->hero.inventory.bag[i][0]].item.rect.top;
            data->scenes[INVENTORY].objs[i + 1].rect.left =
            data->item_ref[data->hero.inventory.bag[i][0]].item.rect.left;
            sfSprite_setTextureRect(data->scenes[INVENTORY].objs[i + 1].s, \
            data->scenes[INVENTORY].objs[i + 1].rect);
        }
        update_hero_stat(data);
    }
}