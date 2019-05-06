/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init_control_menu
*/

#include "my_rpg.h"

void init_control_txt(data_t *d)
{
    txt_t up = {NULL, NULL, {500, 100}, sfWhite, 80};
    txt_t down = {NULL, NULL, {500, 250}, sfWhite, 80};
    txt_t right = {NULL, NULL, {500, 400}, sfWhite, 80};
    txt_t left = {NULL, NULL, {500, 550}, sfWhite, 80};
    txt_t attack = {NULL, NULL, {500, 700}, sfWhite, 80};
    txt_t inventory = {NULL, NULL, {500, 850}, sfWhite, 80};

    init_txt_simple(&up, "assets/fonts/bebas.ttf", "UP");
    init_txt_simple(&down, "assets/fonts/bebas.ttf", "DOWN");
    init_txt_simple(&right, "assets/fonts/bebas.ttf", "RIGHT");
    init_txt_simple(&left, "assets/fonts/bebas.ttf", "LEFT");
    init_txt_simple(&attack, "assets/fonts/bebas.ttf", "ATTACK");
    init_txt_simple(&inventory, "assets/fonts/bebas.ttf", "INVENTORY");
    d->scenes[CONTROL].txt[0] = up;
    d->scenes[CONTROL].txt[1] = down;
    d->scenes[CONTROL].txt[2] = right;
    d->scenes[CONTROL].txt[3] = left;
    d->scenes[CONTROL].txt[4] = attack;
    d->scenes[CONTROL].txt[5] = inventory;
}

void init_button_control_menu2(data_t *data)
{
    char const *text_b = "assets/images/menu/button_silver.png";
    char const *str_font = "assets/fonts/bebas.ttf";
    button_t b_attack = {NULL, {150, 700}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &callback_control_b_attack, {270, 100}, {0}};
    button_t b_inventory = {NULL, {150, 850}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &callback_control_b_inventory, {270, 100}, {0}};
    button_t b_return_menu = {NULL, {1600, 950}, {270, 100}, NULL, {0, 0,
    {0, 0}, sfBlack, 40}, &button_setting, {270, 100}, {0}};

    init_button(&b_attack, text_b, "SPACE", str_font);
    init_button(&b_inventory, text_b, "TAB", str_font);
    init_button(&b_return_menu, text_b, "SETTINGS", str_font);
    data->scenes[CONTROL].buttons[4] = b_attack;
    data->scenes[CONTROL].buttons[5] = b_inventory;
    data->scenes[CONTROL].buttons[6] = b_return_menu;
}

void init_button_control_menu1(data_t *data)
{
    char const *text_b = "assets/images/menu/button_silver.png";
    char const *str_font = "assets/fonts/bebas.ttf";
    button_t b_up = {NULL, {150, 100}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &callback_control_b_up, {270, 100}, {0}};
    button_t b_down = {NULL, {150, 250}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &callback_control_b_down, {270, 100}, {0}};
    button_t b_right = {NULL, {150, 400}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &callback_control_b_right, {270, 100}, {0}};
    button_t b_left = {NULL, {150, 550}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &callback_control_b_left, {270, 100}, {0}};

    init_button(&b_up, text_b, "Z", str_font);
    init_button(&b_down, text_b, "S", str_font);
    init_button(&b_right, text_b, "D", str_font);
    init_button(&b_left, text_b, "Q", str_font);
    data->scenes[CONTROL].buttons[0] = b_up;
    data->scenes[CONTROL].buttons[1] = b_down;
    data->scenes[CONTROL].buttons[2] = b_right;
    data->scenes[CONTROL].buttons[3] = b_left;
}

void init_obj_control_menu(data_t *data)
{
    game_object_t bg_control = {1920, 1080, {1, 1}, {1920, 1080}, {0, 0},
    {0, 0}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};

    init_game_object(&bg_control, "assets/images/menu/ring.jpg");
    data->scenes[CONTROL].objs[0] = bg_control;
}

void init_all_control_menu(data_t *data)
{
    init_obj_control_menu(data);
    init_button_control_menu1(data);
    init_button_control_menu2(data);
    init_control_txt(data);
}