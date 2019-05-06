/*
** EPITECH PROJECT, 2019
** open event rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void merchant_handling(data_t *data)
{
    if (data->cur == MERCHANT) {
        for (int i = 0; i < MAX_MERCHANT; i++) {
            data->scenes[MERCHANT].objs[i + 1].rect.top =
            data->item_ref[data->merch.t.inventory.bag[i][0]].item.rect.top;
            data->scenes[MERCHANT].objs[i + 1].rect.left =
            data->item_ref[data->merch.t.inventory.bag[i][0]].item.rect.left;
            sfSprite_setTextureRect(data->scenes[MERCHANT].objs[i + 1].s, \
            data->scenes[MERCHANT].objs[i + 1].rect);
        }
        sfText_setString(data->scenes[MERCHANT].txt[9].txt,
        my_itoa(data->hero.stat.gold));
    }
}

int can_merch(data_t *data)
{
    sfVector2f pos = {data->merch.t.obj.pos.x - data->hero.obj.pos.x, \
    data->merch.t.obj.pos.y - data->hero.obj.pos.y};

    if (sqrt(pow(pos.x, 2) + pow(pos.y, 2)) <= 350)
        return (1);
    return (0);
}

void open_merchant(data_t *data)
{
    int e = 0;

    if (sfSound_getStatus(data->sfx.sfx[12].sound) != sfPlaying)
        sfSound_play(data->sfx.sfx[12].sound);
    if (data->cur != MERCHANT && data->cur != INVENTORY) {
        data->pre_cur = data->cur;
        data->cur = MERCHANT;
    } else {
        e = data->cur;
        data->cur = data->pre_cur;
        data->pre_cur = e;
    }
}