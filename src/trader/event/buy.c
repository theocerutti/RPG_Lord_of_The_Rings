/*
** EPITECH PROJECT, 2019
** buy item merchant
** File description:
** rpg
*/

#include "my_rpg.h"

int can_buy(data_t *data, int index)
{
    int place = -1;

    for (int i = 0; i < MAX_MERCHANT; i++)
        if (data->hero.inventory.bag[i][0] == 26) {
            place = i;
            break;
        }
    if (place != -1 && data->hero.stat.gold >= \
    data->merch.t.inventory.bag[index][1])
        return (place);
    return (-1);
}

void buy_item(data_t *data, int index)
{
    int place = 0;

    if ((place = can_buy(data, index)) != -1) {
        if (sfSound_getStatus(data->sfx.sfx[8].sound) != sfPlaying)
            sfSound_play(data->sfx.sfx[8].sound);
        data->hero.inventory.bag[place][0] =
        data->merch.t.inventory.bag[index][0];
        data->hero.inventory.bag[place][1] = 0;
        data->hero.inventory.bag[place][2] =
        data->item_ref[data->merch.t.inventory.bag[index][0]].stat.type;
        cost_gold_hero(data, \
        -data->item_ref[data->merch.t.inventory.bag[index][0]].stat.gold);
    }
}