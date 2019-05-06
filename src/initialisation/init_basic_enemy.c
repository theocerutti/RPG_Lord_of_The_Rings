/*
** EPITECH PROJECT, 2019
** init_basic_enemy
** File description:
** init_basic_enemy
*/

#include "my_rpg.h"

void set_basic_enemy(character_t *ch, char *path[50], int rand_pos, int scene)
{
    init_bar_character(ch);
    init_clock(&ch->clock);
    init_game_object(&ch->obj, my_strcat("assets/images/character/enemies/",
    path[rand_pos]));
    ch->stat = get_stat_enemy(rand_pos, scene);
}

character_t get_random_basic_enemy(data_t *d, char *path[50], int len_tab,
int scene)
{
    character_t ch = {
        .inventory = {NULL, 0, {{0}}, NULL},
        .spell = {},
        .stat = {},
        .obj = {192, 256, {1.3, 1.3}, {64, 64}, {100, 100},
        {myrand(d->scenes[scene].objs[0].pos.x, d->scenes[scene].objs[0].pos.x
        + d->scenes[scene].objs[0].width),
        myrand(d->scenes[scene].objs[0].pos.y, d->scenes[scene].objs[0].pos.y +
        d->scenes[scene].objs[0].height)}, 0, 0, {0}, {0, {0}, 0}, ENEMY_ID},
        .bar = {{67, 6, {1, 1}, {67, 12}, {0, 0}, {-1, -1}, 0, 0, {0},
        {0, {0}, 0}, MISCELLANEOUS_ID}, {0, 0, {0, 0}, sfYellow, 12},
        {0, 0, {0, 0}, sfYellow, 10}, 0, NULL, NULL},
        .is_attacking = FALSE, .clock = {0, {0}, 0}, .is_clicked_hud = FALSE
    };
    int rand_pos = rand() % len_tab;

    if (rand_pos >= 8)
        ch.obj.offset.x = 43;
    set_basic_enemy(&ch, path, rand_pos, scene);
    return (ch);
}

void init_basic_enemy_for_scene(data_t *d, int scene)
{
    char *path[60] = {
    "bat.png", "rat.png", "wasp.png", "spider.png", "scorpion.png",
    "blue_monster.png", "eye_monster.png", "purple_monster.png", "homme.png",
    "fille_rapide.png", "fille_armure.png", "super_garde.png",
    "petit_garde.png", "homme_armure.png", "petit_prince.png", "garde.png",
    NULL
    };
    int nb_enemies = get_size_list(&d->scenes[scene].list_ch);
    int len_tab = 0;

    for (len_tab = 0; path[len_tab] != NULL; len_tab++);
    for (int i = nb_enemies; i < d->scenes[scene].nb_ch; i++) {
        push(&d->scenes[scene].list_ch, get_random_basic_enemy(d, path,
        len_tab, scene));
    }
}