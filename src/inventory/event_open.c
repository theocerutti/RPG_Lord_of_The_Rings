/*
** EPITECH PROJECT, 2019
** event open
** File description:
** inventory
*/

#include "my_rpg.h"

void open_inventory(data_t *data)
{
    int e = 0;

    if (sfSound_getStatus(data->sfx.sfx[12].sound) != sfPlaying)
        sfSound_play(data->sfx.sfx[12].sound);
    if (data->cur != INVENTORY) {
        if (data->cur != MERCHANT)
            data->pre_cur = data->cur;
        else
            data->merch.market = 1;
        data->cur = INVENTORY;
    } else {
        e = data->cur;
        data->cur = data->pre_cur;
        data->pre_cur = e;
        data->merch.market = 0;
    }
}