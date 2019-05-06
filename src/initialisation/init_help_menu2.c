/*
** EPITECH PROJECT, 2019
** init_help_menu
** File description:
** init_help_menu
*/

#include "my_rpg.h"

void init_obj_help_i_menu(data_t *data)
{
    game_object_t bg_help = {1920, 1080, {1, 1}, {1920, 1080}, {0, 0}, {0, 0},
    0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};
    game_object_t bg_help_inventory = {1600, 900, {1, 1}, {1600, 900}, {0, 0},
    {150, 84}, 0, 0, {0}, {0, {0}, 0}, BACKGROUND_ID};

    init_game_object(&bg_help, "assets/images/menu/help_background.jpg");
    init_game_object(&bg_help_inventory,
    "assets/images/menu/help_inventory.png");
    data->scenes[HELP_I].objs[0] = bg_help;
    data->scenes[HELP_I].objs[1] = bg_help_inventory;
}
