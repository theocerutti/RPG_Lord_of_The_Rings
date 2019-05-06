/*
** EPITECH PROJECT, 2019
** init_fps_setting_menu
** File description:
** init_fps_setting_menu
*/

#include "my_rpg.h"

void init_txt_fps_setting_menu(data_t *d)
{
    char const *font = "assets/fonts/bebas.ttf";
    txt_t txt_show_fps = {0, 0, {977, 306}, sfWhite, 60};
    txt_t txt_set_limit = {0, 0, {800, 444}, sfWhite, 60};
    txt_t txt_limit_15 = {0, 0, {977, 572}, sfWhite, 60};
    txt_t txt_limit_30 = {0, 0, {977, 700}, sfWhite, 60};
    txt_t txt_limit_60 = {0, 0, {977, 822}, sfWhite, 60};
    txt_t txt_limit_unlimited = {0, 0, {977, 944}, sfWhite, 60};

    init_txt_simple(&txt_set_limit, font, "Set FPS limit:");
    init_txt_simple(&txt_limit_15, font, "15");
    init_txt_simple(&txt_limit_30, font, "30");
    init_txt_simple(&txt_limit_60, font, "60");
    init_txt_simple(&txt_limit_unlimited, font, "Unlimited");
    init_txt_simple(&txt_show_fps, font, "Show FPS");
    d->scenes[FPS_SETTING].txt[0] = txt_set_limit;
    d->scenes[FPS_SETTING].txt[1] = txt_limit_15;
    d->scenes[FPS_SETTING].txt[2] = txt_limit_30;
    d->scenes[FPS_SETTING].txt[3] = txt_limit_60;
    d->scenes[FPS_SETTING].txt[4] = txt_limit_unlimited;
    d->scenes[FPS_SETTING].txt[5] = txt_show_fps;
}

void init_button_fps_setting_menu2(data_t *d)
{
    char const *texture_checkbox = "assets/images/menu/checkbox.png";
    char const *font = "assets/fonts/bebas.ttf";
    button_t b_fps_30 = {NULL, {835, 695}, {77, 78}, NULL, {0, 0, {0, 0},
    sfBlack, 0}, &button_fps_30, {77, 78}, {0}};
    button_t b_fps_60 = {NULL, {835, 820}, {77, 78}, NULL, {0, 0, {0, 0},
    sfBlack, 0}, &button_fps_60, {77, 78}, {0}};
    button_t b_fps_unlimited = {NULL, {835, 945}, {77, 78}, NULL, {0, 0,
    {0, 0}, sfBlack, 0}, &button_fps_unlimited, {77, 78}, {0}};

    init_button(&b_fps_30, texture_checkbox, "NOTHING", font);
    init_button(&b_fps_60, texture_checkbox, "NOTHING", font);
    init_button(&b_fps_unlimited, texture_checkbox, "NOTHING", font);
    d->scenes[FPS_SETTING].buttons[3] = b_fps_30;
    d->scenes[FPS_SETTING].buttons[4] = b_fps_60;
    d->scenes[FPS_SETTING].buttons[5] = b_fps_unlimited;
}

void init_button_fps_setting_menu(data_t *d)
{
    char const *texture_button = "assets/images/menu/button_silver.png";
    char const *texture_checkbox = "assets/images/menu/checkbox.png";
    char const *font = "assets/fonts/bebas.ttf";
    button_t b_return_to_setting = {NULL, {1600, 950}, {270, 100}, NULL,
    {0, 0, {0, 0}, sfBlack, 40}, &button_setting, {270, 100}, {0}};
    button_t b_show_fps = {NULL, {835, 300}, {77, 78}, NULL, {0, 0,
    {0, 0}, sfBlack, 0}, &button_show_fps, {77, 78}, {0}};
    button_t b_fps_15 = {NULL, {835, 570}, {77, 78}, NULL, {0, 0, {0, 0},
    sfBlack, 0}, &button_fps_15, {77, 78}, {0}};

    init_button(&b_show_fps, texture_checkbox, "NOTHING", font);
    init_button(&b_fps_15, texture_checkbox, "NOTHING", font);
    init_button(&b_return_to_setting, texture_button, "SETTINGS", font);
    d->scenes[FPS_SETTING].buttons[0] = b_return_to_setting;
    d->scenes[FPS_SETTING].buttons[1] = b_show_fps;
    d->scenes[FPS_SETTING].buttons[2] = b_fps_15;
}

void init_obj_fps_setting_menu(data_t *d)
{
    game_object_t bg_menu = {1920, 1080, {1, 1}, {1920, 1080}, {0, 0}, {0, 0},
    0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};

    init_game_object(&bg_menu, "assets/images/menu/fps_bg.jpg");
    d->scenes[FPS_SETTING].objs[0] = bg_menu;
}

void init_fps_setting_menu(data_t *d)
{
    init_obj_fps_setting_menu(d);
    init_txt_fps_setting_menu(d);
    init_button_fps_setting_menu(d);
    init_button_fps_setting_menu2(d);
}