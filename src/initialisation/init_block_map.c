/*
** EPITECH PROJECT, 2019
** init_data
** File description:
** init_data
*/

#include "my_rpg.h"

void init_map_text(data_t *data)
{
    txt_t txt = {0, 0, {150, 100}, sfRed, 60};
    sfColor color = {191, 22, 15, 255};

    data->change_map = txt;
    init_txt_simple(&data->change_map, "assets/fonts/diablo_h.ttf",
    "Kill this map's Boss to unlock this path.");
    sfText_setColor(data->change_map.txt, color);
}

void init_posinit(data_t *d)
{
    d->posinx = malloc(sizeof(int) * 6);
    d->posiny = malloc(sizeof(int) * 6);
    d->posinx[0] = -5700;
    d->posinx[1] = -530;
    d->posinx[2] = -6620;
    d->posinx[3] = -280;
    d->posinx[4] = -6620;
    d->posinx[5] = -280;
    d->posiny[0] = -4000;
    d->posiny[1] = -4560;
    d->posiny[2] = -4060;
    d->posiny[3] = -4600;
    d->posiny[4] = -4060;
    d->posiny[5] = -4600;
}

void init_block_map(data_t *d)
{
    init_map_text(d);
    init_posinit(d);
}