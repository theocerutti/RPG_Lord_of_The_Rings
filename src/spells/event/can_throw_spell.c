/*
** EPITECH PROJECT, 2019
** send spell event get
** File description:
** rpg
*/

#include "my_rpg.h"

int can_throw_spell(data_t *data, int spell)
{
    int one = 0;

    for (int i = 0; i < 4; i++)
        if (data->overview_activate[i] == 1 && i != spell)
            one += 1;
    if (one != 0)
        return (0);
    if (data->hero.spell[spell].stat.mana <= data->hero.stat.mana)
        return (1);
    return (0);
}

int can_throw_spell_anim(int *overview_activate_anim)
{
    for (int i = 0; i < 4; i++) {
        if (overview_activate_anim[i])
            return (0);
    }
    return (1);
}