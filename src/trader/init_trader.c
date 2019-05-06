/*
** EPITECH PROJECT, 2019
** init the trader obj
** File description:
** rpg
*/

#include "my_rpg.h"

void check_remake_index(int *index, int *type, data_t *data)
{
    int no_next = 0;

    for (int i = *index; i < MAX_ITEM; i++) {
        if (*type <= 3 && data->item_ref[i].stat.type == *type)
            no_next += 1;
        if (*type > 3 && data->item_ref[i].stat.type >= *type)
            no_next += 1;
    }
    if (*index == MAX_ITEM - 1 || no_next == 0) {
        *type += 1;
        *index = 0;
    }
}

void fill_bag(character_t *trader, data_t *data, int index)
{
    static int i = 0;
    static int type = 0;

    for (; i < MAX_ITEM; i++) {
        if (type <= 3 && data->item_ref[i].stat.type == type) {
            trader->inventory.bag[index][0] = i;
            trader->inventory.bag[index][1] = data->item_ref[i].stat.gold;
            i += 1;
            break;
        } else if (type > 3 && data->item_ref[i].stat.type >= type && i != 4 \
        && i != 14 && i != 19 && i != 23 && i != 24 && i != 25 && i != 26) {
            trader->inventory.bag[index][0] = i;
            trader->inventory.bag[index][1] = data->item_ref[i].stat.gold;
            i += 1;
            break;
        }
    }
    check_remake_index(&i, &type, data);
}

void get_merchant_bag(character_t *trader, data_t *data)
{
    for (int i = 0; i < MAX_MERCHANT; i++) {
        trader->inventory.bag[i][0] = 26;
        trader->inventory.bag[i][1] = 0;
    }
    for (int i = 0; i < MAX_MERCHANT; i++)
        fill_bag(trader, data, i);
    for (int i = MAX_MERCHANT - 3; i < MAX_MERCHANT; i++) {
        trader->inventory.bag[i][0] = 26;
        trader->inventory.bag[i][1] = 0;
    }
}

character_t get_trader(data_t *data)
{
    character_t trader;
    game_object_t merchant = {400, 80, {2, 2}, {80, 80}, {0, 0}, \
    {-1150, -2200}, NULL, NULL, {}, {}, PNJ_ID};

    init_game_object(&merchant, "assets/images/character/pnj/merchant.png");
    trader.obj = merchant;
    get_merchant_bag(&trader, data);
    return (trader);
}

void init_merchant(data_t *data)
{
    sfTexture *text =
        sfTexture_createFromFile("assets/images/ui/merchant.png", NULL);
    sfTexture *itms =
        sfTexture_createFromFile("assets/images/items/items.png", NULL);
    sfVector2f pos[2] = {{0, 0}, {0, 0}};

    data->scenes[MERCHANT].objs[0].s = sfSprite_create();
    data->scenes[MERCHANT].objs[0].width = 1920;
    data->scenes[MERCHANT].objs[0].height = 1080;
    data->scenes[MERCHANT].objs[0].pos = (sfVector2f){0, 0};
    data->scenes[MERCHANT].objs[0].scale = (sfVector2f){1, 1};
    sfSprite_setTexture(data->scenes[MERCHANT].objs[0].s, text, sfTrue);
    sfSprite_setPosition(data->scenes[MERCHANT].objs[0].s, (sfVector2f){0, 0});
    data->scenes[MERCHANT].objs[0].id = BACKGROUND_ID;
    for (int i = 1; i < 25; i++)
        init_each_case_m(data, pos, i, itms);
    set_stat_txt_merch(data);
    data->scenes[MERCHANT].objs[25] = get_overview_item();
}