/*
** EPITECH PROJECT, 2019
** init_help_menu
** File description:
** init_help_menu
*/

#include "my_rpg.h"

void init_button_help_c_menu(data_t *data)
{
    char const *str_font = "assets/fonts/bebas.ttf";
    button_t b_help_menu_return = {NULL, {1600, 950}, {270, 100}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_back, {270, 100}, {0}};
    button_t b_help_menu_right_arrow = {NULL, {1600, 540}, {300, 62}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_right_arrow_c, {150, 62}, {0}};
    button_t b_help_menu_left_arrow = {NULL, {150, 540}, {300, 62}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_left_arrow_c, {150, 62}, {0}};

    init_button(&b_help_menu_return,
    "assets/images/menu/button_silver.png", "BACK", str_font);
    init_button(&b_help_menu_right_arrow,
    "assets/images/miscellaneous/arrow_right.png", "", str_font);
    init_button(&b_help_menu_left_arrow,
    "assets/images/miscellaneous/arrow_left.png", "", str_font);
    data->scenes[HELP_C].buttons[0] = b_help_menu_return;
    data->scenes[HELP_C].buttons[1] = b_help_menu_right_arrow;
    data->scenes[HELP_C].buttons[2] = b_help_menu_left_arrow;
}

void init_button_help_m_menu(data_t *data)
{
    char const *str_font = "assets/fonts/bebas.ttf";
    button_t b_help_menu_return = {NULL, {1600, 950}, {270, 100}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_back, {270, 100}, {0}};
    button_t b_help_menu_right_arrow = {NULL, {1600, 540}, {300, 62}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_right_arrow_m, {150, 62}, {0}};
    button_t b_help_menu_left_arrow = {NULL, {150, 540}, {300, 62}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_left_arrow_m, {150, 62}, {0}};

    init_button(&b_help_menu_return,
    "assets/images/menu/button_silver.png", "BACK", str_font);
    init_button(&b_help_menu_right_arrow,
    "assets/images/miscellaneous/arrow_right.png", "", str_font);
    init_button(&b_help_menu_left_arrow,
    "assets/images/miscellaneous/arrow_left.png", "", str_font);
    data->scenes[HELP_M].buttons[0] = b_help_menu_return;
    data->scenes[HELP_M].buttons[1] = b_help_menu_right_arrow;
    data->scenes[HELP_M].buttons[2] = b_help_menu_left_arrow;
}

void init_button_help_i_menu(data_t *data)
{
    char const *str_font = "assets/fonts/bebas.ttf";
    button_t b_help_menu_return = {NULL, {1600, 950}, {270, 100}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_back, {270, 100}, {0}};
    button_t b_help_menu_right_arrow = {NULL, {1600, 540}, {300, 62}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_right_arrow_i, {150, 62}, {0}};
    button_t b_help_menu_left_arrow = {NULL, {150, 540}, {300, 62}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_left_arrow_i, {150, 62}, {0}};

    init_button(&b_help_menu_return,
    "assets/images/menu/button_silver.png", "BACK", str_font);
    init_button(&b_help_menu_right_arrow,
    "assets/images/miscellaneous/arrow_right.png", "", str_font);
    init_button(&b_help_menu_left_arrow,
    "assets/images/miscellaneous/arrow_left.png", "", str_font);
    data->scenes[HELP_I].buttons[0] = b_help_menu_return;
    data->scenes[HELP_I].buttons[1] = b_help_menu_right_arrow;
    data->scenes[HELP_I].buttons[2] = b_help_menu_left_arrow;
}

void init_obj_help_c_menu(data_t *data)
{
    game_object_t bg_help = {1920, 1080, {1, 1}, {1920, 1080}, {0, 0},
    {0, 0}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};
    game_object_t bg_help_combat = {1600, 900, {1, 1}, {1600, 900}, {0, 0},
    {150, 84}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};

    init_game_object(&bg_help, "assets/images/menu/help_background.jpg");
    init_game_object(&bg_help_combat, "assets/images/menu/help_combat.png");
    data->scenes[HELP_C].objs[0] = bg_help;
    data->scenes[HELP_C].objs[1] = bg_help_combat;
}

void init_obj_help_m_menu(data_t *data)
{
    game_object_t bg_help = {1920, 1080, {1, 1}, {1920, 1080}, {0, 0},
    {0, 0}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};
    game_object_t bg_help_movement = {1600, 900, {1, 1}, {1600, 900}, {0, 0},
    {150, 84}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};

    init_game_object(&bg_help, "assets/images/menu/help_background.jpg");
    init_game_object(&bg_help_movement, "assets/images/menu/help_movement.png");
    data->scenes[HELP_M].objs[0] = bg_help;
    data->scenes[HELP_M].objs[1] = bg_help_movement;
}