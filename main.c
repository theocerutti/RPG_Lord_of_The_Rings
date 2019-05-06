/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void put_the_one_in_merch(data_t *data, int one)
{
    int place = -1;

    for (int i = 0; i < MAX_MERCHANT; i++)
        if (data->merch.t.inventory.bag[i][0] == 26) {
            place = i;
            break;
        }
    if (place != -1) {
        data->merch.t.inventory.bag[place][0] = one;
        data->merch.t.inventory.bag[place][1] = 0;
    }
}

void get_the_one_ring(data_t *data)
{
    int place = -1;

    data->boss.boss = 5;
    for (int i = 0; i < MAX_MERCHANT; i++)
        if (data->hero.inventory.bag[i][0] == 26) {
            place = i;
            break;
        }
    if (place != -1) {
        data->hero.inventory.bag[place][0] = 25;
        data->hero.inventory.bag[place][1] = 0;
        data->hero.inventory.bag[place][2] = data->item_ref[25].stat.type;
        if (sfSound_getStatus(data->sfx.sfx[6].sound) != sfPlaying)
            sfSound_play(data->sfx.sfx[6].sound);
        add_item_to_historical(&data->scenes[HUD], data->item_ref, 25);
    } else
        put_the_one_in_merch(data, 25);
}

void setup_game(data_t *data)
{
    data->cur = MENU;
    sfMusic_play(data->sfx.sfx[0].music);
}

int main(void)
{
    data_t data;
    sfEvent event = {0};

    init_all_data(&data);
    setup_game(&data);
    while (sfRenderWindow_isOpen(data.window.w)) {
        if (data.trans >= 10)
            poll_event(&data, &event);
        draw(&data);
        data.delta_time.time = sfClock_restart(data.delta_time.clock);
        data.delta_time.s = sfTime_asSeconds(data.delta_time.time);
        if (data.trans > 100000)
            data.trans = 15;
        if (data.boss.boss == 4)
            get_the_one_ring(&data);
    }
    cleanup(&data);
    return (0);
}
