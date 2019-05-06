/*
** EPITECH PROJECT, 2019
** draw spells src
** File description:
** rpg
*/

#include "my_rpg.h"

void draw_spells(data_t *data)
{
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(data->window.w, \
        data->hero.spell[i].spell.s, NULL);
}