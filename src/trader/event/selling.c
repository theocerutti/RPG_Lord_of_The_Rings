/*
** EPITECH PROJECT, 2019
** selling item
** File description:
** rpg
*/

#include "my_rpg.h"

void sell_handling(data_t *data, int index)
{
    int gain = 0;

    if (index < MAX_MERCHANT) {
        if (sfSound_getStatus(data->sfx.sfx[8].sound) != sfPlaying)
            sfSound_play(data->sfx.sfx[8].sound);
        gain = \
        data->item_ref[data->hero.inventory.bag[index][0]].stat.gold / 3 * 2;
        cost_gold_hero(data, gain);
        delete_inventory_item(data, index);
    }
}