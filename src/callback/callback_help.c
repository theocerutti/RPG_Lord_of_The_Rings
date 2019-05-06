/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** callback_help
*/

#include "my_rpg.h"

void button_right_arrow_c(data_t *d)
{
    if (sfSound_getStatus(d->sfx.sfx[13].sound) != sfPlaying)
        sfSound_play(d->sfx.sfx[13].sound);
    d->cur = HELP_M;
}

void button_right_arrow_m(data_t *d)
{
    if (sfSound_getStatus(d->sfx.sfx[13].sound) != sfPlaying)
        sfSound_play(d->sfx.sfx[13].sound);
    d->cur = HELP_I;
}

void button_right_arrow_i(data_t *d)
{
    if (sfSound_getStatus(d->sfx.sfx[13].sound) != sfPlaying)
        sfSound_play(d->sfx.sfx[13].sound);
    d->cur = HELP_C;
}

void button_left_arrow_c(data_t *d)
{
    if (sfSound_getStatus(d->sfx.sfx[13].sound) != sfPlaying)
        sfSound_play(d->sfx.sfx[13].sound);
    d->cur = HELP_I;
}

void button_left_arrow_m(data_t *d)
{
    if (sfSound_getStatus(d->sfx.sfx[13].sound) != sfPlaying)
        sfSound_play(d->sfx.sfx[13].sound);
    d->cur = HELP_C;
}