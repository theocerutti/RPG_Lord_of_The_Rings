/*
** EPITECH PROJECT, 2019
** init_scenes
** File description:
** init_scenes
*/

#include "my_rpg.h"

void return_previous_scene(data_t *d)
{
    int scene = d->pre_cur;

    d->pre_cur = d->cur;
    d->cur = scene;
}

void reinit_new_game(data_t *d)
{
    button_respawn(d);
    d->hero.stat = (stat_t){0, 0, 0, 1, 1, 1, 10, 10, 100, 100, 100, 100, 0,
    100, 0, 0, 0};
    d->can_continue_game = TRUE;
    d->scenes[MENU].buttons[2].rect.left = 0;
    d->scenes[HUD].objs[1].rect.width = 0;
    sfSprite_setTextureRect(d->scenes[HUD].objs[1].s,
    d->scenes[HUD].objs[1].rect);
    sfText_setString(d->scenes[HUD].txt[2].txt, "0 / 100");
    sfText_setString(d->scenes[HUD].txt[6].txt, "0");
    sfText_setString(d->scenes[HUD].txt[5].txt, "Level 1");
    set_item_rect_historical_hud(&d->scenes[HUD], d->item_ref);
    sfRectangleShape_setTextureRect(d->scenes[MENU].buttons[2].obj,
    d->scenes[MENU].buttons[2].rect);
    for (int i = 21; i < 25; i++)
        sfText_setString(d->scenes[HUD].txt[i].txt, "");
    button_return_game(d);
    game_intro(d->window.w);
    set_first_items(d);
}

void button_choose_bad_sauron(data_t *d)
{
    sfTexture *text_hero = sfTexture_createFromFile(
    "assets/images/character/heroes/hero_sheet_dark.png", NULL);

    sfSprite_setTexture(d->hero.obj.s, text_hero, sfTrue);
    reinit_new_game(d);
}

void button_choose_good_sauron(data_t *d)
{
    sfTexture *text_hero = sfTexture_createFromFile(
    "assets/images/character/heroes/hero_sheet_white.png", NULL);

    sfSprite_setTexture(d->hero.obj.s, text_hero, sfTrue);
    reinit_new_game(d);
}

void button_return_game(data_t *d)
{
    sfMusic_pause(d->sfx.sfx[0].music);
    sfMusic_setPlayingOffset(d->sfx.sfx[0].music, (sfTime){0});
    sfMusic_play(d->sfx.sfx[1].music);
    d->pre_cur = d->cur;
    d->cur = LVL_1_F;
}