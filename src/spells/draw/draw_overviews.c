/*
** EPITECH PROJECT, 2019
** drawing overviews
** File description:
** rpg
*/

#include "my_rpg.h"

void draw_spells_overviews(data_t *data)
{
    for (int i = 0; i < 4; i++) {
        data->overview[i].draw_it(data);
    }
}

void draw_overview_0(data_t *data)
{
    if (data->overview_activate[0]) {
        sfRenderWindow_drawRectangleShape(data->window.w, \
        data->overview[0].overview_r[0], NULL);
    }
    if (data->overview_activate_anim[0]) {
        sfRenderWindow_drawSprite(data->window.w,
        data->overview[0].spell_anim[0].s, NULL);
    }
}

void draw_overview_1(data_t *data)
{
    if (data->overview_activate[1]) {
        for (int i = 0; i < 4; i++)
            sfRenderWindow_drawRectangleShape(data->window.w, \
            data->overview[1].overview_r[i], NULL);
    }
    if (data->overview_activate_anim[1]) {
        for (int i = 0; i < 4; i++) {
            sfRenderWindow_drawSprite(data->window.w,
            data->overview[1].spell_anim[i].s, NULL);
        }
    }
}

void draw_overview_2(data_t *data)
{
    if (data->overview_activate[2]) {
        sfRenderWindow_drawCircleShape(data->window.w, \
        data->overview[2].overview_c, NULL);
    }
    if (data->overview_activate_anim[2]) {
        sfRenderWindow_drawSprite(data->window.w,
        data->overview[2].spell_anim[0].s, NULL);
    }
}

void draw_overview_3(data_t *data)
{
    if (data->overview_activate[3]) {
        sfRenderWindow_drawCircleShape(data->window.w, \
        data->overview[3].overview_c, NULL);
    }
    if (data->overview_activate_anim[3]) {
        sfRenderWindow_drawSprite(data->window.w,
        data->overview[3].spell_anim[0].s, NULL);
    }
}