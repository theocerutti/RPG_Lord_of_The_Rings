/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init_menu
*/

#include "my_rpg.h"

void init_game3(data_t *d)
{
    game_object_t map_lvl3f = {4800, 3200, {2, 2}, {4800, 3200},
    {0, 0}, {-6620, -4060}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};
    game_object_t on_map_lvl3f = {4800, 3200, {2, 2}, {4800, 3200},
    {0, 0}, {-6620, -4060}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};
    game_object_t map_lvl3c = {4800, 3200, {2, 2}, {4800, 3200},
    {0, 0}, {-280, -4600}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};
    game_object_t on_map_lvl3c = {4800, 3200, {2, 2}, {4800, 3200},
    {0, 0}, {-280, -4600}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};

    init_game_object(&map_lvl3f, "assets/images/maps/forest_sp_aut-min.png");
    init_game_object(&on_map_lvl3f, "assets/images/maps/forest_sp_aut2.png");
    init_game_object(&map_lvl3c, "assets/images/maps/city_spring-min.png");
    init_game_object(&on_map_lvl3c, "assets/images/maps/city_spring2-min.png");
    d->scenes[LVL_3_F].objs[0] = map_lvl3f;
    d->scenes[LVL_3_F].on_map = on_map_lvl3f;
    d->scenes[LVL_3_C].objs[0] = map_lvl3c;
    d->scenes[LVL_3_C].on_map = on_map_lvl3c;
}

void init_game2(data_t *d)
{
    game_object_t map_lvl2f = {4800, 3200, {2, 2}, {4800, 3200},
    {0, 0}, {-6620, -4060}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};
    game_object_t on_map_lvl2f = {4800, 3200, {2, 2}, {4800, 3200},
    {0, 0}, {-6620, -4060}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};
    game_object_t map_lvl2c = {4800, 3200, {2, 2}, {4800, 3200},
    {0, 0}, {-280, -4600}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};
    game_object_t on_map_lvl2c = {4800, 3200, {2, 2}, {4800, 3200},
    {0, 0}, {-280, -4600}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};

    init_game_object(&map_lvl2f, "assets/images/maps/forest_win_aut-min.png");
    init_game_object(&on_map_lvl2f, "assets/images/maps/forest_win_aut2.png");
    init_game_object(&map_lvl2c, "assets/images/maps/city_autumn-min.png");
    init_game_object(&on_map_lvl2c, "assets/images/maps/city_autumn2-min.png");
    d->scenes[LVL_2_F].objs[0] = map_lvl2f;
    d->scenes[LVL_2_F].on_map = on_map_lvl2f;
    d->scenes[LVL_2_C].objs[0] = map_lvl2c;
    d->scenes[LVL_2_C].on_map = on_map_lvl2c;
    init_game3(d);
}

void init_game(data_t *d)
{
    game_object_t map_lvl1f = {4800, 3200, {2, 2}, {4800, 3200},
    {0, 0}, {-5700, -4000}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};
    game_object_t on_map_lvl1f = {4800, 3200, {2, 2}, {4800, 3200},
    {0, 0}, {-5700, -4000}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};
    game_object_t map_lvl1c = {4800, 3200, {2, 2}, {4800, 3200},
    {0, 0}, {-530, -4560}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};
    game_object_t on_map_lvl1c = {4800, 3200, {2, 2}, {4800, 3200},
    {0, 0}, {-530, -4560}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};

    init_game_object(&map_lvl1f, "assets/images/maps/dark-min.png");
    init_game_object(&on_map_lvl1f, "assets/images/maps/dark2-min.png");
    init_game_object(&map_lvl1c, "assets/images/maps/city_winter-min.png");
    init_game_object(&on_map_lvl1c, "assets/images/maps/city_winter2-min.png");
    d->scenes[LVL_1_F].objs[0] = map_lvl1f;
    d->scenes[LVL_1_F].on_map = on_map_lvl1f;
    d->scenes[LVL_1_C].objs[0] = map_lvl1c;
    d->scenes[LVL_1_C].on_map = on_map_lvl1c;
    init_game2(d);
}

char *get_str_arrows(void)
{
    char *str = " << \t\t\t\t\
    \t\t\t\t\t\t\t\t\t\
    \t\t\t\t\t\t\t\t\t\
    \t\t\t\t\t\t\t\t\t\t\
    \t\t\t\t\t\t\t\t\t\t\
    \t\t\t\t\t\t\t\t\t   >> ";

    return (str);
}

intro_t init_txt_intro_2(intro_t ni, char *str)
{
    init_txt_simple(&ni.txt[3], str,
    "You found a Morgul's sword, and are now going to\n\
    \t\t\t\treforge The One Ring.");
    init_txt_simple(&ni.txt[4], str,
    "You are the stronger one in Dol Guldur, and every man will\n\
    \t\t  follow your lead until King Aragorn's dead...\
    \n\t\t\t\t\
    \t\t\t  Your Quest :\n\t\t\t\t\t\
    \t  Destroy everything.");
    init_txt_simple(&ni.txt[5], str,
    "You will find a note in your inventory. It contains instructions\n\
    \t\t\t\t\t\tto the Ultimate Quest.\
    \n\t\t\t\t\t\
    Be dark, and kill everyone.\n  \t\t\t\t\
    \t\t\tFor Sauron.");
    return (ni);
}