/*
** EPITECH PROJECT, 2019
** init_audio_setting
** File description:
** init_audio_setting
*/

#include "my_rpg.h"

void init_audio_setting_txt(data_t *d)
{
    char const *str_font = "assets/fonts/bebas.ttf";
    txt_t txt_sound = {0, 0, {540, 355}, sfWhite, 60};
    txt_t txt_music = {0, 0, {540, 655}, sfWhite, 60};
    txt_t txt_sound_count = {0, 0, {1280, 355}, sfWhite, 60};
    txt_t txt_music_count = {0, 0, {1280, 655}, sfWhite, 60};

    init_txt_simple(&txt_sound, str_font, "Sound :");
    init_txt_simple(&txt_music, str_font, "Music :");
    init_txt_simple(&txt_sound_count, str_font, "100");
    init_txt_simple(&txt_music_count, str_font, "100");
    d->scenes[AUDIO_SETTING].txt[0] = txt_sound;
    d->scenes[AUDIO_SETTING].txt[1] = txt_music;
    d->scenes[AUDIO_SETTING].txt[2] = txt_sound_count;
    d->scenes[AUDIO_SETTING].txt[3] = txt_music_count;
}

void init_audio_setting_obj(data_t *d)
{
    game_object_t bg_menu = {1920, 1080, {1, 1}, {1920, 1080}, {0, 0}, {0, 0},
    0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};
    game_object_t slider_cursor_sound = {24, 48, {1, 1}, {24, 48}, {0, 0},
    {1158, 366}, 0, 0, {0}, {0, {0}, 0}, MISCELLANEOUS_ID};
    game_object_t slider_cursor_music = {24, 48, {1, 1}, {24, 48}, {0, 0},
    {1158, 665}, 0, 0, {0}, {0, {0}, 0}, MISCELLANEOUS_ID};

    init_game_object(&bg_menu, "assets/images/menu/audio_setting_bg.jpg");
    init_game_object(&slider_cursor_sound,
    "assets/images/menu/slider_cursor.png");
    init_game_object(&slider_cursor_music,
    "assets/images/menu/slider_cursor.png");
    d->scenes[AUDIO_SETTING].objs[0] = bg_menu;
    d->scenes[AUDIO_SETTING].objs[1] = slider_cursor_sound;
    d->scenes[AUDIO_SETTING].objs[2] = slider_cursor_music;
}

void init_audio_setting_button(data_t *d)
{
    char const *str_font = "assets/fonts/bebas.ttf";
    button_t b_ret_setting = {0, {1600, 950}, {270, 100}, 0, {0, 0,
    {0, 0}, sfBlack, 40}, &button_setting, {270, 100}, {0}};
    button_t slider_sound = {0, {758, 376}, {400, 20}, 0, {0, 0,
    {0, 0}, sfBlack, 0}, &button_cursor_slider_sound, {400, 20}, {0}};
    button_t slider_music = {0, {758, 675}, {400, 20}, 0, {0, 0,
    {0, 0}, sfBlack, 0}, &button_cursor_slider_music, {400, 20}, {0}};

    init_button(&b_ret_setting, "assets/images/menu/button_silver.png",
    "SETTINGS", str_font);
    init_button(&slider_sound, "assets/images/menu/slider_bg.png", "NOTHING",
    str_font);
    init_button(&slider_music, "assets/images/menu/slider_bg.png", "NOTHING",
    str_font);
    d->scenes[AUDIO_SETTING].buttons[0] = b_ret_setting;
    d->scenes[AUDIO_SETTING].buttons[1] = slider_sound;
    d->scenes[AUDIO_SETTING].buttons[2] = slider_music;
}

void init_audio_setting_menu(data_t *d)
{
    init_audio_setting_txt(d);
    init_audio_setting_obj(d);
    init_audio_setting_button(d);
}