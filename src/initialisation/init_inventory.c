/*
** EPITECH PROJECT, 2019
** init_scene_inventory
** File description:
** rpg
*/

#include "my_rpg.h"

void set_stat_txt(data_t *data)
{
    sfColor color_text = {255, 213, 0, 255};
    sfVector2f pos[10] = {{715, 785}, {685, 825}, {975, 785}, {975, 820}, \
    {975, 855}, {975, 895}, {1560, 300}, {1560, 335}, {1560, 370}, {1560, 410}};

    for (int i = 0; i < data->scenes[INVENTORY].nb_txt; i++) {
        data->scenes[INVENTORY].txt[i].color = color_text;
        data->scenes[INVENTORY].txt[i].pos = pos[i];
        data->scenes[INVENTORY].txt[i].size = 15;
        if (i == 0 || i == 1)
            init_txt_simple(&data->scenes[INVENTORY].txt[i], \
            "assets/fonts/inventory.ttf", "No items.");
        else
            init_txt_simple(&data->scenes[INVENTORY].txt[i], \
            "assets/fonts/inventory.ttf", "0");
    }
}

void set_first_items(data_t *data)
{
    for (int i = 0; i < MAX_BAG; i++) {
        data->hero.inventory.bag[i][0] = 26;
        data->hero.inventory.bag[i][1] = 0;
        data->hero.inventory.bag[i][2] = 7;
    }
    data->hero.inventory.bag[0][0] = 0;
    data->hero.inventory.bag[0][1] = 0;
    data->hero.inventory.bag[0][2] = 0;
    data->hero.inventory.bag[1][0] = 1;
    data->hero.inventory.bag[1][1] = 0;
    data->hero.inventory.bag[1][2] = 1;
    data->hero.inventory.bag[2][0] = 2;
    data->hero.inventory.bag[2][1] = 0;
    data->hero.inventory.bag[2][2] = 2;
    data->hero.inventory.bag[3][0] = 18;
    data->hero.inventory.bag[3][1] = 0;
    data->hero.inventory.bag[3][2] = 3;
    data->hero.inventory.bag[4][0] = 9;
    data->hero.inventory.bag[4][1] = 0;
    data->hero.inventory.bag[4][2] = 7;
}

void set_pos_inventory(sfVector2f pos[2], int index)
{
    static int pos_pick = 0;
    sfVector2f new_pos[8] = {{1152, 320}, {1152, 384}, {1152, 448}, {1088, 512},
    {1088, 704}, {1152, 704}, {1216, 704}, {1152, 640}};

    if (index < 25) {
        pos[1].x = 704 + pos[0].y * 64;
        pos[1].y = 320 + pos[0].x * 64;
        pos[0].y += 1;
        if (pos[0].y == 4) {
            pos[0].x += 1;
            pos[0].y = 0;
        }
    } else {
        pos[1] = new_pos[pos_pick];
        pos_pick += 1;
    }
}

void init_each_case(data_t *data, sfVector2f pos[2], int i, sfTexture *itms)
{
    data->scenes[INVENTORY].objs[i].s = sfSprite_create();
    sfSprite_setTexture(data->scenes[INVENTORY].objs[i].s, itms, sfTrue);
    set_pos_inventory(pos, i);
    sfSprite_setPosition(data->scenes[INVENTORY].objs[i].s, pos[1]);
    sfSprite_scale(data->scenes[INVENTORY].objs[i].s, (sfVector2f){2, 2});
    data->scenes[INVENTORY].objs[i].width = 64;
    data->scenes[INVENTORY].objs[i].height = 64;
    data->scenes[INVENTORY].objs[i].id = ITEM_ID;
    data->scenes[INVENTORY].objs[i].scale = (sfVector2f){1, 1};
    data->scenes[INVENTORY].objs[i].offset = (sfVector2i){32, 32};
    data->scenes[INVENTORY].objs[i].rect = (sfIntRect){160, 0, 32, 32};
    sfSprite_setTextureRect(data->scenes[INVENTORY].objs[i].s, \
    data->scenes[INVENTORY].objs[i].rect);
}

void init_inventory(data_t *data)
{
    sfTexture *text =
    sfTexture_createFromFile("assets/images/ui/inventory.png", NULL);
    sfTexture *itms =
    sfTexture_createFromFile("assets/images/items/items.png", NULL);
    sfVector2f pos[2] = {{0, 0}, {0, 0}};

    data->scenes[INVENTORY].objs[0].s = sfSprite_create();
    data->scenes[INVENTORY].objs[0].width = 1920;
    data->scenes[INVENTORY].objs[0].height = 1080;
    data->scenes[INVENTORY].objs[0].pos = (sfVector2f){0, 0};
    data->scenes[INVENTORY].objs[0].scale = (sfVector2f){1, 1};
    sfSprite_setTexture(data->scenes[INVENTORY].objs[0].s, text, sfTrue);
    sfSprite_setPosition(data->scenes[INVENTORY].objs[0].s, (sfVector2f){0, 0});
    data->scenes[INVENTORY].objs[0].id = BACKGROUND_ID;
    for (int i = 1; i < 33; i++)
        init_each_case(data, pos, i, itms);
    set_stat_txt(data);
    set_first_items(data);
    data->scenes[INVENTORY].objs[33] = get_overview_item();
}