/*
** EPITECH PROJECT, 2019
** init stats merchant inventory
** File description:
** rpg
*/

#include "my_rpg.h"

void init_each_case_m(data_t *data, sfVector2f pos[2], int i, sfTexture *itms)
{
    data->scenes[MERCHANT].objs[i].s = sfSprite_create();
    sfSprite_setTexture(data->scenes[MERCHANT].objs[i].s, itms, sfTrue);
    set_pos_inventory(pos, i);
    sfSprite_setPosition(data->scenes[MERCHANT].objs[i].s, pos[1]);
    sfSprite_scale(data->scenes[MERCHANT].objs[i].s, (sfVector2f){2, 2});
    data->scenes[MERCHANT].objs[i].width = 64;
    data->scenes[MERCHANT].objs[i].height = 64;
    data->scenes[MERCHANT].objs[i].id = ITEM_ID;
    data->scenes[MERCHANT].objs[i].scale = (sfVector2f){1, 1};
    data->scenes[MERCHANT].objs[i].offset = (sfVector2i){32, 32};
    data->scenes[MERCHANT].objs[i].rect = (sfIntRect){160, 0, 32, 32};
    sfSprite_setTextureRect(data->scenes[MERCHANT].objs[i].s, \
    data->scenes[MERCHANT].objs[i].rect);
}

void set_size_price(data_t *data)
{
    data->scenes[MERCHANT].txt[6].size = 40;
    data->scenes[MERCHANT].txt[7].size = 50;
    data->scenes[MERCHANT].txt[8].size = 30;
    data->scenes[MERCHANT].txt[9].size = 40;
}

void set_stat_txt_merch(data_t *data)
{
    sfColor color_text = {255, 213, 0, 255};
    sfVector2f pos[10] = {{715, 785}, {685, 825}, {975, 785}, {975, 820}, \
    {975, 855}, {975, 895}, {1125, 280}, {1060, 350}, {1110, 490}, \
    {1060, 530}};

    for (int i = 0; i < data->scenes[MERCHANT].nb_txt; i++) {
        data->scenes[MERCHANT].txt[i].color = color_text;
        data->scenes[MERCHANT].txt[i].pos = pos[i];
        data->scenes[MERCHANT].txt[i].size = 15;
        set_size_price(data);
        if (i == 0 || i == 1)
            init_txt_simple(&data->scenes[MERCHANT].txt[i], \
            "assets/fonts/inventory.ttf", "No items.");
        else
            init_txt_simple(&data->scenes[MERCHANT].txt[i], \
            "assets/fonts/inventory.ttf", "0");
    }
    sfText_setString(data->scenes[MERCHANT].txt[6].txt, "Price : ");
    sfText_setString(data->scenes[MERCHANT].txt[8].txt, "Your gold : ");
}