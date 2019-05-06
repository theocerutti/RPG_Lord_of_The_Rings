/*
** EPITECH PROJECT, 2019
** init_mis
** File description:
** init_mis
*/

#include "my_rpg.h"

void init_control(data_t *data)
{
    data->ctrl.key[UP_KEY] = sfKeyZ;
    data->ctrl.key[DOWN_KEY] = sfKeyS;
    data->ctrl.key[RIGHT_KEY] = sfKeyD;
    data->ctrl.key[LEFT_KEY] = sfKeyQ;
    data->ctrl.key[ATTACK_KEY] = sfKeySpace;
    data->ctrl.key[INVENTORY_KEY] = sfKeyTab;
    data->ctrl.check = 0;
    data->ctrl.button = 0;
}

void init_fps_counter(data_t *data)
{
    char const *font = "assets/fonts/bebas.ttf";
    fps_t fps = {FALSE, {0, 0, {1800, 20}, sfYellow, 60}, {0}};

    init_clock(&fps.clock);
    init_txt_simple(&fps.txt, font, "0");
    data->fps = fps;
}

void init_cursor(data_t *data)
{
    game_object_t cursor = {24, 25, {1, 1}, {24, 25}, {0, 0}, {0, 0}, 0, 0,
    {0}, {0, {0}, 0}, BACKGROUND_ID};

    init_game_object(&cursor, "assets/images/miscellaneous/cursor.png");
    data->cursor = cursor;
}

void init_miscellaneous(data_t *data)
{
    init_clock(&data->delta_time);
    init_clock(&data->action_tick);
    init_fps_counter(data);
    init_cursor(data);
}