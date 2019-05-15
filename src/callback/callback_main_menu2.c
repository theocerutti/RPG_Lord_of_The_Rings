/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** callback_menu
*/

#include "my_rpg.h"

void button_return_main_menu(data_t *data)
{
    sfMusic_pause(data->sfx.sfx[1].music);
    sfMusic_setPlayingOffset(data->sfx.sfx[1].music, (sfTime){0});
    sfMusic_play(data->sfx.sfx[0].music);
    if (data->pre_cur == END) {
        data->pre_cur = data->cur;
        data->cur = LVL_3_C;
    } else {
        data->cur = MENU;
    }
}

void button_resume(data_t *data)
{
    int save = data->pre_cur;

    data->pre_cur = data->cur;
    data->cur = save;
}

void re_init_bosses(data_t *d)
{
    int save = d->boss.boss;

    d->boss = get_bosses_data();
    if (d->cur != NEW_GAME)
        d->boss.boss = save;
    if (d->boss.boss < 1)
        push(&d->scenes[LVL_1_C].list_ch, d->boss.boss_ch[0]);
    if (d->boss.boss < 2)
        push(&d->scenes[LVL_2_C].list_ch, d->boss.boss_ch[1]);
    if (d->boss.boss < 3)
        push(&d->scenes[LVL_3_C].list_ch, d->boss.boss_ch[2]);
}

void re_init_last_lvl(data_t *d)
{
    for (unsigned int i = LVL_1_C; i <= d->pre_cur + 1; i++) {
        if (i > LVL_3_C)
            break;
        d->scenes[i].objs[0].pos.x = d->posinx[i - 13];
        d->scenes[i].objs[0].pos.y = d->posiny[i - 13];
        d->scenes[i].on_map.pos.x = d->posinx[i - 13];
        d->scenes[i].on_map.pos.y = d->posiny[i - 13];
        sfSprite_setPosition(d->scenes[i].objs[0].s,
        d->scenes[i].objs[0].pos);
        sfSprite_setPosition(d->scenes[i].on_map.s,
        d->scenes[i].on_map.pos);
    }
    re_init_bosses(d);
}

void button_respawn(data_t *d)
{
    if (d->cur == NEW_GAME)
        d->pre_cur = LVL_3_C;
    if (d->pre_cur >= LVL_1_F && d->pre_cur <= LVL_3_C)
        re_init_last_lvl(d);
    if (d->cur == NEW_GAME)
        d->pre_cur = NEW_GAME;
    else
        d->pre_cur = DIE;
    d->cur = LVL_1_F;
    d->scenes[LVL_1_F].objs[0].pos.x = -5700;
    d->scenes[LVL_1_F].objs[0].pos.y = -4000;
    d->scenes[LVL_1_F].on_map.pos.x = -5700;
    d->scenes[LVL_1_F].on_map.pos.y = -4000;
    d->merch.t.obj.pos.x = -1120;
    d->merch.t.obj.pos.y = -2190;
    sfSprite_setPosition(d->merch.t.obj.s,
    d->merch.t.obj.pos);
    d->merch.use.pos.x = -1095;
    d->merch.use.pos.y = -2220;
    sfSprite_setPosition(d->merch.use.s,
    d->merch.use.pos);
    sfSprite_setPosition(d->scenes[LVL_1_F].objs[0].s,
    d->scenes[LVL_1_F].objs[0].pos);
    sfSprite_setPosition(d->scenes[LVL_1_F].on_map.s,
    d->scenes[LVL_1_F].on_map.pos);
}