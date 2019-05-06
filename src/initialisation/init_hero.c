/*
** EPITECH PROJECT, 2019
** init_hero
** File description:
** init_hero
*/

#include "my_rpg.h"

void init_hero_data(data_t *d)
{
    character_t hero = {
        .inventory = {NULL, 0, {{0}}, NULL},
        .spell = {},
        .stat = {0, 0, 0, 1, 1, 1, 10, 10, 100, 100, 100, 100, 0, 100, 0,
        0, 0},
        .obj = {461, 799, {1.5, 1.5}, {84, 84}, {650, 650}, {d->window.size.x
        / 2, d->window.size.y / 2}, 0, 0, {0}, {0, {0}, 0}, HERO_ID},
        .bar = {{67, 6, {1, 1}, {67, 12}, {0, 0}, {-1, -1}, 0, 0, {0}, {0,
        {0}, 0}, MISCELLANEOUS_ID}, {0, 0, {0, 0}, sfYellow, 12},
        {0, 0, {0, 0}, sfYellow, 10}, 0, 0, 0},
        .is_attacking = FALSE,
        .clock = {0, {0}, 0}
    };

    init_clock(&hero.clock);
    init_bar_character(&hero);
    init_game_object(&hero.obj,
    "assets/images/character/heroes/hero_sheet_dark.png");
    d->hero = hero;
}