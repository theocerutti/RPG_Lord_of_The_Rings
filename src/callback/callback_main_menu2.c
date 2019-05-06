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
    if (d->boss.boss < 1) {
        d->boss.boss_ch[0].obj.pos.x = 6410;
        d->boss.boss_ch[0].obj.pos.y = -3088;
        sfSprite_setPosition(d->boss.boss_ch[0].obj.s,
        d->boss.boss_ch[0].obj.pos);
    }
    if (d->boss.boss < 2) {
        d->boss.boss_ch[1].obj.pos.x = 8100;
        d->boss.boss_ch[1].obj.pos.y = -390;
        sfSprite_setPosition(d->boss.boss_ch[1].obj.s,
        d->boss.boss_ch[1].obj.pos);
    }
    if (d->boss.boss < 3) {
        d->boss.boss_ch[2].obj.pos.x = 6950;
        d->boss.boss_ch[2].obj.pos.y = 20;
        sfSprite_setPosition(d->boss.boss_ch[2].obj.s,
        d->boss.boss_ch[2].obj.pos);
    }
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
    if (d->pre_cur >= LVL_1_F && d->pre_cur <= LVL_3_C)
        re_init_last_lvl(d);
    d->cur = LVL_1_F;
    d->pre_cur = DIE;
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