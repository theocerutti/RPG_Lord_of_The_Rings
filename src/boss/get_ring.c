/*
** EPITECH PROJECT, 2019
** get ring functions
** File description:
** rpg defeat a boss
*/

#include "my_rpg.h"

void put_ring_in_merch(data_t *data, character_t boss)
{
    int place = -1;

    for (int i = 0; i < MAX_MERCHANT; i++)
        if (data->merch.t.inventory.bag[i][0] == 26) {
            place = i;
            break;
        }
    if (place != -1) {
        data->merch.t.inventory.bag[place][0] = boss.inventory.bag[0][0];
        data->merch.t.inventory.bag[place][1] = 0;
    }
}

void get_the_ring(data_t *data, character_t boss)
{
    int place = -1;

    data->boss.boss += 1;
    place_merchant(data, boss);
    for (int i = 0; i < MAX_MERCHANT; i++)
        if (data->hero.inventory.bag[i][0] == 26) {
            place = i;
            break;
        }
    if (place != -1) {
        data->hero.inventory.bag[place][0] = boss.inventory.bag[0][0];
        data->hero.inventory.bag[place][1] = 0;
        data->hero.inventory.bag[place][2] = \
        data->item_ref[boss.inventory.bag[0][0]].stat.type;
        if (sfSound_getStatus(data->sfx.sfx[6].sound) != sfPlaying)
            sfSound_play(data->sfx.sfx[6].sound);
        add_item_to_historical(&data->scenes[HUD], data->item_ref,
        boss.inventory.bag[0][0]);
    } else
        put_ring_in_merch(data, boss);
}

void other_drop(data_t *data, int item, int place)
{
    if (item >= 26 && item <= 70) {
        data->hero.inventory.bag[place][0] = 20;
        data->hero.inventory.bag[place][1] = 0;
        data->hero.inventory.bag[place][2] = data->item_ref[20].stat.type;
        if (sfSound_getStatus(data->sfx.sfx[6].sound) != sfPlaying)
            sfSound_play(data->sfx.sfx[6].sound);
        add_item_to_historical(&data->scenes[HUD], data->item_ref, 20);
    } else if (item >= 71 && item <= 100) {
        data->hero.inventory.bag[place][0] = 15;
        data->hero.inventory.bag[place][1] = 0;
        data->hero.inventory.bag[place][2] = data->item_ref[15].stat.type;
        if (sfSound_getStatus(data->sfx.sfx[6].sound) != sfPlaying)
            sfSound_play(data->sfx.sfx[6].sound);
        add_item_to_historical(&data->scenes[HUD], data->item_ref, 15);
    }
}

void drop_item(data_t *data, int place, int item)
{
    data->hero.inventory.bag[place][0] = item;
    data->hero.inventory.bag[place][1] = 0;
    data->hero.inventory.bag[place][2] = data->item_ref[item].stat.type;
    if (sfSound_getStatus(data->sfx.sfx[6].sound) != sfPlaying)
        sfSound_play(data->sfx.sfx[6].sound);
    add_item_to_historical(&data->scenes[HUD], data->item_ref, item);
}

void get_drop_item(data_t *data, character_t enemy)
{
    int place = -1;
    int item = -1;

    if (enemy.obj.id != ENEMY_ID)
        return;
    for (int i = 0; i < MAX_MERCHANT; i++)
        if (data->hero.inventory.bag[i][0] == 26) {
            place = i;
            break;
        }
    item = rand() % 500;
    if (item <= 25 && place != -1 && (data->item_ref[item].stat.type == 7 || \
    data->item_ref[item].stat.type <= 3) && item != 9) {
        drop_item(data, place, item);
    } else if (place != -1)
        other_drop(data, item, place);
}