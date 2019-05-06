/*
** EPITECH PROJECT, 2019
** init_historical_hud
** File description:
** init_historical_hud
*/

#include "my_rpg.h"

void set_item_rect_historical_hud(scene_t *hud, item_t *item_ref)
{
    for (int i = 9; i < 13; i++) {
        hud->objs[i].rect = item_ref[26].item.rect;
        sfSprite_setTextureRect(hud->objs[i].s, hud->objs[i].rect);
    }
}

void init_obj_historical_hud2(data_t *d)
{
    game_object_t item_2 = {100, 100, {1, 1}, {100, 100}, {0, 0},
    {1845, 882}, 0, 0, {0}, {0, {0}, 0}, HUD};
    game_object_t item_3 = {100, 100, {1, 1}, {100, 100}, {0, 0},
    {1845, 816}, 0, 0, {0}, {0, {0}, 0}, HUD};

    init_game_object(&item_2, "assets/images/items/items.png");
    init_game_object(&item_3, "assets/images/items/items.png");
    d->scenes[HUD].objs[11] = item_2;
    d->scenes[HUD].objs[12] = item_3;
}

void init_obj_historical_hud(data_t *d)
{
    game_object_t historical = {248, 286, {1.3, 1.3}, {248, 286}, {0, 0},
    {1600, 741}, 0, 0, {0}, {0, {0}, 0}, HUD};
    game_object_t item_0 = {100, 100, {1, 1}, {100, 100}, {0, 0},
    {1845, 1020}, 0, 0, {0}, {0, {0}, 0}, HUD};
    game_object_t item_1 = {100, 100, {1, 1}, {100, 100}, {0, 0},
    {1845, 950}, 0, 0, {0}, {0, {0}, 0}, HUD};

    init_game_object(&historical, "assets/images/menu/historical.png");
    init_game_object(&item_0, "assets/images/items/items.png");
    init_game_object(&item_1, "assets/images/items/items.png");
    d->scenes[HUD].objs[8] = historical;
    d->scenes[HUD].objs[9] = item_0;
    d->scenes[HUD].objs[10] = item_1;
    init_obj_historical_hud2(d);
    set_item_rect_historical_hud(&d->scenes[HUD], d->item_ref);
}

void init_txt_historical_hud(data_t *d)
{
    sfColor color_yellow = sfColor_fromRGB(227, 158, 21);
    char const *str_font = "assets/fonts/bebas.ttf";
    txt_t txt_0 = {NULL, NULL, {1620, 1017}, color_yellow, 20};
    txt_t txt_1 = {NULL, NULL, {1620, 947}, color_yellow, 20};
    txt_t txt_2 = {NULL, NULL, {1620, 880}, color_yellow, 20};
    txt_t txt_3 = {NULL, NULL, {1620, 811}, color_yellow, 20};
    txt_t last_drop_txt = {NULL, NULL, {1635, 767}, color_yellow, 20};

    init_txt_simple(&txt_0, str_font, "");
    init_txt_simple(&txt_1, str_font, "");
    init_txt_simple(&txt_2, str_font, "");
    init_txt_simple(&txt_3, str_font, "");
    init_txt_simple(&last_drop_txt, str_font, "Last dropped items:");
    d->scenes[HUD].txt[21] = txt_0;
    d->scenes[HUD].txt[22] = txt_1;
    d->scenes[HUD].txt[23] = txt_2;
    d->scenes[HUD].txt[24] = txt_3;
    d->scenes[HUD].txt[25] = last_drop_txt;
}

void init_historical(data_t *data)
{
    init_obj_historical_hud(data);
    init_txt_historical_hud(data);
}