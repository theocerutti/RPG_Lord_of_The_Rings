/*
** EPITECH PROJECT, 2019
** icons overview
** File description:
** rpg
*/

#include "my_rpg.h"

int one_spell_on(data_t *data)
{
    for (int i = 0; i < 4; i++)
        if (data->overview_activate[i] == 1)
            return (1);
    return (0);
}

void set_icon(data_t *data)
{
    sfColor n_black = {255, 255, 255, 100};
    sfColor n_white = {255, 255, 255, 255};

    for (int i = 0; i < 4; i++) {
        if (data->overview_activate[i] == 1 || \
        data->hero.spell[i].stat.mana > data->hero.stat.mana)
            sfSprite_setColor(data->hero.spell[i].spell.s, n_black);
        else
            sfSprite_setColor(data->hero.spell[i].spell.s, n_white);
    }
}