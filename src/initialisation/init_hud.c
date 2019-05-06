/*
** EPITECH PROJECT, 2019
** init_hud
** File description:
** init_hud
*/

#include "my_rpg.h"

void init_txt_hud2(data_t *data)
{
    sfColor color_yellow = sfColor_fromRGB(227, 158, 21);
    char const *str_font = "assets/fonts/bebas.ttf";
    txt_t txt_regen_mana = {NULL, NULL, {1383, 1015}, sfBlack, 15};
    txt_t txt_level = {0, 0, {1177, 1005}, (sfColor){166, 90, 37, 255}, 35};
    txt_t txt_coin = {0, 0, {120, 50}, color_yellow, 35};

    init_txt_simple(&txt_regen_mana, str_font, "(+0 / sec)");
    init_txt_simple(&txt_level, str_font, "Level 1");
    init_txt_simple(&txt_coin, str_font, "0");
    data->scenes[HUD].txt[4] = txt_regen_mana;
    data->scenes[HUD].txt[5] = txt_level;
    data->scenes[HUD].txt[6] = txt_coin;
    init_txt_hud3(data);
}

void init_txt_hud(data_t *data)
{
    sfColor color_yellow = sfColor_fromRGB(227, 158, 21);
    char const *str_font = "assets/fonts/bebas.ttf";
    txt_t txt_life = {NULL, NULL, {545, 975}, sfBlack, 25};
    txt_t txt_mana = {NULL, NULL, {1373, 975}, sfBlack, 25};
    txt_t txt_regen_life = {NULL, NULL, {560, 1015}, sfBlack, 15};
    txt_t txt_xp = {NULL, NULL, {975, 945}, color_yellow, 20};

    init_txt_simple(&txt_life, str_font, "100 / 100");
    init_txt_simple(&txt_mana, str_font, "100 / 100");
    init_txt_simple(&txt_regen_life, str_font, "(+0 / sec)");
    init_txt_simple(&txt_xp, str_font, "0 / 100");
    data->scenes[HUD].txt[0] = txt_life;
    data->scenes[HUD].txt[1] = txt_mana;
    data->scenes[HUD].txt[2] = txt_xp;
    data->scenes[HUD].txt[3] = txt_regen_life;
    init_txt_hud2(data);
}

void init_hud3(data_t *data)
{
    game_object_t overview_enemy = {100, 100, {1, 1}, {100, 100}, {0, 0},
    {43, 830}, 0, 0, {0}, {0, {0}, 0}, HUD};

    init_game_object(&overview_enemy,
    "assets/images/menu/not_found_stat_enemy.png");
    data->scenes[HUD].objs[7] = overview_enemy;
}

void init_hud2(data_t *data)
{
    game_object_t hud = {1272, 169, {1, 1}, {1272, 169}, {0, 0},
    {360, 911}, 0, 0, {0}, {0, {0}, 0}, HUD};
    game_object_t mana_bar = {150, 170, {1, 1}, {150, 170}, {0, 0},
    {1343, 914}, 0, 0, {0}, {0, {0}, 0}, HUD};
    game_object_t coin = {200, 200, {1, 1}, {50, 50}, {0, 0},
    {50, 45}, 0, 0, {0}, {0, {0}, 0}, HUD};
    game_object_t stat_hud = {365, 289, {1, 1}, {365, 289}, {0, 0},
    {0, 791}, 0, 0, {0}, {0, {0}, 0}, HUD};

    init_game_object(&stat_hud, "assets/images/menu/hud_stat_enemy.png");
    init_game_object(&coin, "assets/images/menu/coin_sheet.png");
    init_game_object(&hud, "assets/images/menu/hud.png");
    init_game_object(&mana_bar, "assets/images/menu/mana_bar.png");
    data->scenes[HUD].objs[3] = mana_bar;
    data->scenes[HUD].objs[4] = hud;
    data->scenes[HUD].objs[5] = coin;
    data->scenes[HUD].objs[6] = stat_hud;
    init_hud3(data);
}

void init_hud(data_t *data)
{
    game_object_t bar = {150, 170, {1, 1}, {150, 170}, {0, 0},
    {500, 915}, 0, 0, {0}, {0, {0}, 0}, HUD};
    game_object_t xp_bar = {676, 7, {1, 1}, {676, 7}, {0, 0},
    {656, 986}, 0, 0, {0}, {0, {0}, 0}, HUD};
    game_object_t xp_bar_bg = {676, 7, {1, 1}, {676, 7}, {0, 0},
    {656, 986}, 0, 0, {0}, {0, {0}, 0}, HUD};

    init_txt_hud(data);
    init_game_object(&bar, "assets/images/menu/life_bar.png");
    init_game_object(&xp_bar, "assets/images/menu/xp_bar.png");
    init_game_object(&xp_bar_bg, "assets/images/menu/xp_bar_bg.png");
    xp_bar.rect.width = 0;
    sfSprite_setTextureRect(xp_bar.s, xp_bar.rect);
    data->scenes[HUD].objs[0] = xp_bar_bg;
    data->scenes[HUD].objs[1] = xp_bar;
    data->scenes[HUD].objs[2] = bar;
    init_hud2(data);
    init_historical(data);
}