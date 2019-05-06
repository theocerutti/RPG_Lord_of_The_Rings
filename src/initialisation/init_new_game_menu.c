/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init_menu
*/

#include "my_rpg.h"

void init_txt_new_game_menu(data_t *data)
{
    char const *str_font = "assets/fonts/bebas.ttf";
    txt_t choose_your_hero = {0, 0, {500, 50}, sfYellow, 150};

    init_txt_simple(&choose_your_hero, str_font, "Choose your hero !");
    data->scenes[NEW_GAME].txt[0] = choose_your_hero;
}

void init_button_new_game_menu(data_t *data)
{
    char const *str_font = "assets/fonts/bebas.ttf";
    char const *text_b = "assets/images/menu/button_silver.png";
    button_t b_class_menu_return = {NULL, {1600, 950}, {270, 100}, NULL, {0,
    0, {0, 0}, sfBlack, 40}, &button_return_main_menu, {270, 100}, {0}};
    button_t b_choose_bad_sauron = {NULL, {500, 680}, {270, 100}, NULL, {0, 0,
    {0, 0}, sfBlack, 40}, &button_choose_bad_sauron, {270, 100}, {0}};
    button_t b_choose_good_sauron = {NULL, {1170, 680}, {270, 100}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_choose_good_sauron, {270, 100}, {0}};

    init_button(&b_choose_bad_sauron, text_b, "Sauron", str_font);
    init_button(&b_choose_good_sauron, text_b, "Good Sauron", str_font);
    init_button(&b_class_menu_return, text_b, "MENU", str_font);
    data->scenes[NEW_GAME].buttons[0] = b_choose_bad_sauron;
    data->scenes[NEW_GAME].buttons[1] = b_choose_good_sauron;
    data->scenes[NEW_GAME].buttons[2] = b_class_menu_return;
}

void init_obj_new_game_menu(data_t *data)
{
    game_object_t bg_menu = {1920, 1080, {1, 1}, {1920, 1080}, {0, 0}, {0, 0},
    0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};
    game_object_t overview_good_sauron = {34, 82, {2.5, 2.5}, {34, 82},
    {0, 0}, {1256, 438}, 0, 0, {0}, {0, {0}, 0}, HERO_ID};
    game_object_t overview_bad_sauron = {34, 82, {2.5, 2.5}, {34, 82},
    {0, 0}, {591, 438}, 0, 0, {0}, {0, {0}, 0}, HERO_ID};

    init_game_object(&overview_bad_sauron,
    "assets/images/character/heroes/overview_bad_sauron.png");
    init_game_object(&overview_good_sauron,
    "assets/images/character/heroes/overview_good_sauron.png");
    init_game_object(&bg_menu, "assets/images/menu/ring.jpg");
    data->scenes[NEW_GAME].objs[0] = bg_menu;
    data->scenes[NEW_GAME].objs[1] = overview_bad_sauron;
    data->scenes[NEW_GAME].objs[2] = overview_good_sauron;
}

void init_new_game_menu(data_t *data)
{
    init_obj_new_game_menu(data);
    init_button_new_game_menu(data);
    init_txt_new_game_menu(data);
}