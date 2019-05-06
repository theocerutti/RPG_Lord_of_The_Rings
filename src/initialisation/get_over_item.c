/*
** EPITECH PROJECT, 2019
** get item overview
** File description:
** rpg
*/

#include "my_rpg.h"

game_object_t get_overview_item(void)
{
    game_object_t over = {192, 160, {1, 1}, {32, 32}, {0, 0}, \
    {674, 779}, NULL, NULL, {0, 160, 32, 32}, {}, ITEM_ID};

    init_game_object(&over, "assets/images/items/items.png");
    return (over);
}