/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** callback_menu
*/

#include "my_rpg.h"

void button_exit(data_t *data)
{
    sfRenderWindow_close(data->window.w);
}

void button_start_game(data_t *data)
{
    data->pre_cur = data->cur;
    data->cur = NEW_GAME;
}

void button_continue_game(data_t *data)
{
    if (data->can_continue_game)
        data->cur = data->pre_cur;
}

void button_print_help_main_menu(data_t *data)
{
    data->cur = HELP_C;
}

void button_credits(data_t *data)
{
    data->pre_cur = data->cur;
    data->cur = CREDITS;
    data->scenes[data->cur].txt[0].pos.y = 1070;
    data->scenes[data->cur].txt[0].pos.x = 500;
    sfText_setPosition(data->scenes[data->cur].txt[0].txt,
    data->scenes[data->cur].txt[0].pos);
}
