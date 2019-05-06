/*
** EPITECH PROJECT, 2019
** init_credits
** File description:
** init_credits
*/

#include "my_rpg.h"

void init_credits_txt(data_t *d)
{
    txt_t credits = {NULL, NULL, {500, 1070}, sfWhite, 80};

    init_txt_simple(&credits, "assets/fonts/serif.ttf",
    "\tLORD OF THE RINGS\n\nWe're glad you played our RPG\
    \n\n\t\t\t\tTEAM\n\
    \n\t    Mathilde Couston\n\t    Antoine Maillard\
    \n\t     Michael Fabrie\n\t      Theo Cerutti\n\n\
    We would like to thank\
    \n\t\t\t TOLKIEN\n\
    for the incredible movies\n\
    \t\t  he made.\n\
    It's thanks to him that we\n\
    \t\t  were able\n\
    \tto make our RPG.\n\
    \t\tTHANK YOU\n\n\
    And thank you for playing!\n\
    \t\tUntil next time!");
    d->scenes[CREDITS].txt[0] = credits;
}

void init_button_credits_menu(data_t *data)
{
    button_t b_return = {NULL, {1600, 950}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &button_return_main_menu, {270, 100}, {0}};

    init_button(&b_return, "assets/images/menu/button_silver.png", "BACK",
    "assets/fonts/bebas.ttf");
    data->scenes[CREDITS].buttons[0] = b_return;
}

void init_obj_credits_menu(data_t *data)
{
    game_object_t bg_credits = {1920, 1170, {1, 1}, {1920, 1170}, {0, 0},
    {0, 0}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};

    init_game_object(&bg_credits, "assets/images/menu/ring.jpg");
    data->scenes[CREDITS].objs[0] = bg_credits;
}

void init_all_credits(data_t *data)
{
    init_credits_txt(data);
    init_obj_credits_menu(data);
    init_button_credits_menu(data);
}