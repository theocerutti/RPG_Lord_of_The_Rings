/*
** EPITECH PROJECT, 2019
** init_option
** File description:
** init_option
*/

#include "my_rpg.h"

void init_button_setting_menu2(data_t *d)
{
    char const *text_b = "assets/images/menu/button_silver.png";
    char const *str_font = "assets/fonts/bebas.ttf";
    button_t b_audio = {NULL, {835, 450}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &button_audio_setting, {270, 100}, {0}};
    button_t b_fps = {NULL, {835, 600}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &button_fps_menu, {270, 100}, {0}};

    init_button(&b_fps, text_b, "FPS", str_font);
    init_button(&b_audio, text_b, "AUDIO", str_font);
    d->scenes[SETTING].buttons[2] = b_audio;
    d->scenes[SETTING].buttons[3] = b_fps;
}

void init_button_setting_menu(data_t *d)
{
    char const *text_b = "assets/images/menu/button_silver.png";
    char const *str_font = "assets/fonts/bebas.ttf";
    button_t b_ret_menu = {NULL, {1600, 950}, {270, 100}, NULL, {0, 0, {0, 0},
    sfBlack, 40}, &button_return_main_menu, {270, 100}, {0}};
    button_t b_control = {NULL, {835, 300}, {270, 100}, NULL, {0, 0,
    {0, 0}, sfBlack, 40}, &button_control_setting, {270, 100}, {0}};

    init_button(&b_ret_menu, text_b, "MENU", str_font);
    init_button(&b_control, text_b, "CONTROL", str_font);
    d->scenes[SETTING].buttons[0] = b_ret_menu;
    d->scenes[SETTING].buttons[1] = b_control;
}

void init_setting_menu(data_t *d)
{
    game_object_t bg_menu = {1920, 1080, {1, 1}, {1920, 1080}, {0, 0}, {0, 0},
    0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};

    init_game_object(&bg_menu, "assets/images/menu/option_bg.png");
    d->scenes[SETTING].objs[0] = bg_menu;
    init_button_setting_menu(d);
    init_button_setting_menu2(d);
}