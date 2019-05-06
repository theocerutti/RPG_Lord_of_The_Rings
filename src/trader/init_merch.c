/*
** EPITECH PROJECT, 2019
** init the merch struct
** File description:
** rpg
*/

#include "my_rpg.h"

game_object_t get_use(void)
{
    game_object_t use = {64, 64, {0.5, 0.5}, {64, 64}, {0, 0}, \
    {-1095, -2220}, NULL, NULL, {}, {}, PNJ_ID};

    init_game_object(&use, "assets/images/ui/use.png");
    return (use);
}

merchant_t get_merch(data_t *data)
{
    merchant_t merch;

    merch.t = get_trader(data);
    merch.use = get_use();
    merch.market = 0;
    merch.cur_m = LVL_1_F;
    return (merch);
}