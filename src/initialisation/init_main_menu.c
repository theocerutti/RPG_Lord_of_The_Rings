/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init_menu
*/

#include "my_rpg.h"

void init_button_main_menu2(data_t *data, char const *str_font)
{
    char const *text_b = "assets/images/menu/button_silver.png";
    button_t b_help = {NULL, {835, 600}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &button_print_help_main_menu, {270, 100}, {0}};
    button_t b_option = {NULL, {835, 750}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &button_setting, {270, 100}, {0}};
    button_t b_credits = {NULL, {50, 950}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &button_credits, {270, 100}, {0}};

    init_button(&b_help, text_b, "HELP", str_font);
    init_button(&b_credits, text_b, "CREDITS", str_font);
    init_button(&b_option, text_b, "SETTINGS", str_font);
    data->scenes[MENU].buttons[3] = b_help;
    data->scenes[MENU].buttons[4] = b_credits;
    data->scenes[MENU].buttons[5] = b_option;
}

void init_button_main_menu(data_t *data)
{
    char const *text_b_gold = "assets/images/menu/button_gold.png";
    char const *str_font = "assets/fonts/bebas.ttf";
    button_t b_exit = {NULL, {1600, 950}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &button_exit, {270, 100}, {0}};
    button_t b_start_new_game = {NULL, {835, 300}, {270, 100}, NULL, {0, 0,
    {0, 0}, sfBlack, 40}, &button_start_game, {270, 100}, {0}};
    button_t b_continue = {NULL, {835, 450}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &button_continue_game, {270, 100}, {0}};

    init_button(&b_exit, "assets/images/menu/button_silver.png", "EXIT",
    str_font);
    init_button(&b_start_new_game, text_b_gold, "NEW GAME", str_font);
    init_button(&b_continue, text_b_gold, "CONTINUE", str_font);
    data->scenes[MENU].buttons[0] = b_exit;
    data->scenes[MENU].buttons[1] = b_start_new_game;
    data->scenes[MENU].buttons[2] = b_continue;
    init_button_main_menu2(data, str_font);
}

void init_obj_main_menu(data_t *data)
{
    game_object_t bg_menu = {1920, 1080, {1, 1}, {1920, 1080}, {0, 0}, {0, 0},
    0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};

    init_game_object(&bg_menu, "assets/images/menu/bg1.jpg");
    data->scenes[MENU].objs[0] = bg_menu;
}

void init_main_menu(data_t *data)
{
    init_obj_main_menu(data);
    init_button_main_menu(data);
}