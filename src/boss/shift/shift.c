/*
** EPITECH PROJECT, 2019
** shift bosses
** File description:
** rpg
*/

#include "my_rpg.h"

void shift_bosses(data_t *data, int x_off, int y_off)
{
    for (int i = 0; i < 3; i++) {
        if ((unsigned)data->boss.cur_boss[i] == (unsigned)data->cur) {
            data->boss.boss_ch[i].obj.pos.x += x_off;
            data->boss.boss_ch[i].obj.pos.y += y_off;
            sfSprite_setPosition(data->boss.boss_ch[i].obj.s, \
            data->boss.boss_ch[i].obj.pos);
        }
    }
}