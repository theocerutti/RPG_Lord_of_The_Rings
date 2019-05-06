/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** callback_help
*/

#include "my_rpg.h"

void button_left_arrow_i(data_t *d)
{
    if (sfSound_getStatus(d->sfx.sfx[13].sound) != sfPlaying)
        sfSound_play(d->sfx.sfx[13].sound);
    d->cur = HELP_M;
}

void button_back(data_t *d)
{
    d->pre_cur = d->cur;
    d->cur = MENU;
}