/*
** EPITECH PROJECT, 2019
** init_die_menu
** File description:
** init_die_menu
*/

#include "my_rpg.h"

void init_txt_die_menu(data_t *data)
{
    char const *str_font = "assets/fonts/diablo_h.ttf";
    txt_t you_lose = {0, 0, {600, 50}, sfWhite, 150};
    txt_t you_lose_gold1 = {0, 0, {710, 350}, sfWhite, 50};
    txt_t you_lose_gold2 = {0, 0, {590, 410}, sfWhite, 50};
    txt_t you_lose_gold3 = {0, 0, {680, 470}, sfWhite, 50};

    init_txt_simple(&you_lose, str_font, "You die!");
    init_txt_simple(&you_lose_gold1, str_font, "You had 0 golds.");
    init_txt_simple(&you_lose_gold2, str_font, "You lose 0 golds for dying.");
    init_txt_simple(&you_lose_gold3, str_font, "Total: 0 golds (-0%)");
    data->scenes[DIE].txt[0] = you_lose;
    data->scenes[DIE].txt[1] = you_lose_gold1;
    data->scenes[DIE].txt[2] = you_lose_gold2;
    data->scenes[DIE].txt[3] = you_lose_gold3;
}

void init_die_menu(data_t *data)
{
    char const *text_b = "assets/images/menu/button_silver.png";
    char const *text_b_gold = "assets/images/menu/button_gold.png";
    button_t b_exit = {NULL, {1600, 950}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &button_exit, {270, 100}, {0}};
    button_t b_respawn = {NULL, {835, 600}, {270, 100}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_respawn, {270, 100}, {0}};
    button_t b_menu = {NULL, {835, 800}, {270, 100}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_return_main_menu, {270, 100}, {0}};
    game_object_t bg = {1920, 1080, {1, 1}, {1920, 1080}, {0, 0}, {0, 0},
    0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};

    init_game_object(&bg, "assets/images/menu/death_menu.jpeg");
    init_button(&b_exit, text_b, "EXIT", "assets/fonts/bebas.ttf");
    init_button(&b_respawn, text_b_gold, "RESPAWN", "assets/fonts/bebas.ttf");
    init_button(&b_menu, text_b, "MENU", "assets/fonts/bebas.ttf");
    data->scenes[DIE].objs[0] = bg;
    data->scenes[DIE].buttons[0] = b_exit;
    data->scenes[DIE].buttons[1] = b_respawn;
    data->scenes[DIE].buttons[2] = b_menu;
    init_txt_die_menu(data);
}

void init_end(data_t *data)
{
    char const *text_b = "assets/images/menu/button_silver.png";
    button_t b_next = {NULL, {1600, 950}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &button_credits, {270, 100}, {0}};
    game_object_t bg = {1920, 1080, {1, 1}, {1920, 1080}, {0, 0}, {0, 0},
    0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};

    init_game_object(&bg, "assets/outro/the_one_ring.png");
    init_button(&b_next, text_b, "NEXT", "assets/fonts/bebas.ttf");
    data->scenes[END].objs[0] = bg;
    data->scenes[END].buttons[0] = b_next;
}