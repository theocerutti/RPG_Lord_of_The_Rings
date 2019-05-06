/*
** EPITECH PROJECT, 2019
** stat hero inventory
** File description:
** rpg
*/

#include "my_rpg.h"

void update_hero_stat(data_t *data)
{
    sfText_setString(data->scenes[INVENTORY].txt[6].txt, \
    my_itoa(data->hero.stat.attack));
    sfText_setString(data->scenes[INVENTORY].txt[7].txt, \
    my_itoa(data->hero.stat.defense));
    sfText_setString(data->scenes[INVENTORY].txt[8].txt, \
    my_itoa(data->hero.stat.mana));
    sfText_setString(data->scenes[INVENTORY].txt[9].txt, \
    my_itoa(data->hero.stat.life));
}