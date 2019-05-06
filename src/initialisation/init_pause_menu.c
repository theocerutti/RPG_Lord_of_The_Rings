/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init_menu
*/

#include "my_rpg.h"

void init_pause_menu2(data_t *data)
{
    char const *text_b = "assets/images/menu/button_silver.png";
    button_t b_exit = {NULL, {1600, 950}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &button_exit, {270, 100}, {0}};
    button_t b_setting = {NULL, {1340, 400}, {270, 100}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_setting, {270, 100}, {0}};

    init_button(&b_exit, text_b, "EXIT GAME", "assets/fonts/bebas.ttf");
    init_button(&b_setting, text_b, "SETTING", "assets/fonts/bebas.ttf");
    data->scenes[PAUSE].buttons[3] = b_setting;
    data->scenes[PAUSE].buttons[4] = b_exit;
}

void init_pause_menu(data_t *data)
{
    char const *text_b = "assets/images/menu/button_silver.png";
    button_t b_return_menu = {NULL, {400, 400}, {270, 100}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_return_main_menu, {270, 100}, {0}};
    button_t b_return_game = {NULL, {870, 400}, {270, 100}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_resume, {270, 100}, {0}};
    button_t b_help = {NULL, {20, 950}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &button_print_help_main_menu, {270, 100}, {0}};
    game_object_t bg_pause = {1920, 1080, {1, 1}, {1920, 1080}, {0, 0},
    {0, 0}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};

    init_game_object(&bg_pause, "assets/images/menu/lake.jpg");
    data->scenes[PAUSE].objs[0] = bg_pause;
    init_button(&b_return_menu, text_b, "MENU", "assets/fonts/bebas.ttf");
    init_button(&b_return_game, text_b, "RESUME", "assets/fonts/bebas.ttf");
    init_button(&b_help, text_b, "HELP", "assets/fonts/bebas.ttf");
    data->scenes[PAUSE].buttons[0] = b_return_menu;
    data->scenes[PAUSE].buttons[1] = b_return_game;
    data->scenes[PAUSE].buttons[2] = b_help;
    init_pause_menu2(data);
}