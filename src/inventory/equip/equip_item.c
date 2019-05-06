/*
** EPITECH PROJECT, 2019
** equip item invent
** File description:
** rpg inventory
*/

#include "my_rpg.h"

void undo_item_stat(data_t *data, int index)
{
    data->hero.stat.attack -=
    data->item_ref[data->hero.inventory.bag[index][0]].stat.attack;
    data->hero.stat.defense -=
    data->item_ref[data->hero.inventory.bag[index][0]].stat.defense;
    data->hero.stat.mana -=
    data->item_ref[data->hero.inventory.bag[index][0]].stat.mana;
    data->hero.stat.life -=
    data->item_ref[data->hero.inventory.bag[index][0]].stat.life;
    update_hero_stat(data);
}

void unequip_item(data_t *data, int index)
{
    int stock[3] = {26, 0, 7};

    for (int i = 0; i < 24; i++)
        if (data->hero.inventory.bag[i][0] == 26) {
            data->hero.inventory.bag[i][0] = \
            data->hero.inventory.bag[index][0];
            data->hero.inventory.bag[i][1] = 0;
            data->hero.inventory.bag[i][2] = \
            data->hero.inventory.bag[index][2];
            for (int i = 0; i < 3; i++)
                data->hero.inventory.bag[index][i] = stock[i];
            if (sfSound_getStatus(data->sfx.sfx[12].sound) != sfPlaying)
                sfSound_play(data->sfx.sfx[12].sound);
            return;
        }
}

void add_item_stat(data_t *data, int index)
{
    data->hero.stat.attack +=
    data->item_ref[data->hero.inventory.bag[index][0]].stat.attack;
    data->hero.stat.defense +=
    data->item_ref[data->hero.inventory.bag[index][0]].stat.defense;
    data->hero.stat.mana +=
    data->item_ref[data->hero.inventory.bag[index][0]].stat.mana;
    data->hero.stat.life +=
    data->item_ref[data->hero.inventory.bag[index][0]].stat.life;
    update_hero_stat(data);
}

void equip_item(data_t *data, int index, int i)
{
    int stock[3] = {0, 0, 0};
    int bag[9] = {25, 24, 26, 27, 28, 29, 30, 0, 31};

    stock[i] = \
    data->hero.inventory.bag[bag[data->hero.inventory.bag[index][2]]][i];
    data->hero.inventory.bag[bag[data->hero.inventory.bag[index][2]]][i]
    = data->hero.inventory.bag[index][i];
    data->hero.inventory.bag[index][i] = stock[i];
    data->hero.inventory.bag[bag[data->hero.inventory.bag[index][2]]][1] = 1;
    if (sfSound_getStatus(data->sfx.sfx[12].sound) != sfPlaying)
        sfSound_play(data->sfx.sfx[12].sound);
}

void un_equip_item(data_t *data, int index)
{
    int bag[9] = {25, 24, 26, 27, 28, 29, 30, 0, 31};

    if (data->hero.inventory.bag[index][1] == 0 && \
    data->hero.inventory.bag[index][2] != 7) {
        add_item_stat(data, index);
        undo_item_stat(data, bag[data->hero.inventory.bag[index][2]]);
        for (int i = 0; i < 3; i++)
            equip_item(data, index, i);
    } else if (data->hero.inventory.bag[index][1] == 1 && \
    data->hero.inventory.bag[index][2] != 7) {
        undo_item_stat(data, index);
        unequip_item(data, index);
    }
    if (data->hero.inventory.bag[index][2] == 7)
        use_item(data, index);
    for (int i = 0; i < 24; i++)
        if (data->hero.inventory.bag[i][1] == 1)
            data->hero.inventory.bag[i][1] = 0;
}