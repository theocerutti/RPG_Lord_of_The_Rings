/*
** EPITECH PROJECT, 2019
** shift_game.c
** File description:
** shift_game.c
*/

#include "my_rpg.h"

void shift_character(data_t *d, float x_off, float y_off)
{
    node_t *tmp = d->scenes[d->cur].list_ch;

    while (tmp != NULL) {
        tmp->ch.obj.pos.x += x_off;
        tmp->ch.obj.pos.y += y_off;
        sfSprite_setPosition(tmp->ch.obj.s, tmp->ch.obj.pos);
        tmp = tmp->next;
    }
}

void shift_obj(data_t *d, float x_off, float y_off)
{
    for (int i = 0; i < d->scenes[d->cur].nb_obj; i++) {
        d->scenes[d->cur].objs[i].pos.x += x_off;
        d->scenes[d->cur].objs[i].pos.y += y_off;
        sfSprite_setPosition(d->scenes[d->cur].objs[i].s,
        d->scenes[d->cur].objs[i].pos);
    }
}

void shift_spell(data_t *d, float x_off, float y_off)
{
    for (int i = 0; i < 4; i++) {
        if (d->overview_activate_anim[i]) {
            for (int j = 0; j < d->overview[i].nb_spell_anim; j++) {
                d->overview[i].spell_anim[j].pos.x += x_off;
                d->overview[i].spell_anim[j].pos.y += y_off;
                sfSprite_setPosition(d->overview[i].spell_anim[j].s,
                d->overview[i].spell_anim[j].pos);
            }
        }
    }
}

void shift_trader(data_t *d, float x_off, float y_off)
{
    if (d->cur == d->merch.cur_m) {
        d->merch.t.obj.pos.x += x_off;
        d->merch.t.obj.pos.y += y_off;
        sfSprite_setPosition(d->merch.t.obj.s, d->merch.t.obj.pos);
        d->merch.use.pos.x += x_off;
        d->merch.use.pos.y += y_off;
        sfSprite_setPosition(d->merch.use.s, d->merch.use.pos);
    }
}

void shift_game(data_t *d, float x_off, float y_off)
{
    sfVector2f pos = {0, 0};

    if (sfSound_getStatus(d->sfx.sfx[4].sound) != sfPlaying)
        sfSound_play(d->sfx.sfx[4].sound);
    shift_obj(d, x_off, y_off);
    pos = sfSprite_getPosition(d->scenes[d->cur].objs[0].s);
    sfSprite_setPosition(d->scenes[d->cur].on_map.s, pos);
    shift_character(d, x_off, y_off);
    shift_spell(d, x_off, y_off);
    shift_trader(d, x_off, y_off);
    shift_bosses(d, x_off, y_off);
}