/*
** EPITECH PROJECT, 2019
** merchant events
** File description:
** rpg merchant
*/

#include "my_rpg.h"

void description_item_merch(data_t *data, int index)
{
    sfSprite_setTextureRect(data->scenes[MERCHANT].objs[25].s, \
    data->item_ref[data->merch.t.inventory.bag[index][0]].item.rect);
    sfText_setString(data->scenes[MERCHANT].txt[0].txt, \
    data->item_ref[data->merch.t.inventory.bag[index][0]].stat.name);
    sfText_setString(data->scenes[MERCHANT].txt[1].txt, \
    data->item_ref[data->merch.t.inventory.bag[index][0]].stat.describe);
    sfText_setString(data->scenes[MERCHANT].txt[2].txt, \
    my_itoa(data->item_ref[data->merch.t.inventory.bag[index][0]].stat.attack));
    sfText_setString(data->scenes[MERCHANT].txt[3].txt, \
    my_itoa(
    data->item_ref[data->merch.t.inventory.bag[index][0]].stat.defense));
    sfText_setString(data->scenes[MERCHANT].txt[4].txt, \
    my_itoa(data->item_ref[data->merch.t.inventory.bag[index][0]].stat.mana));
    sfText_setString(data->scenes[MERCHANT].txt[5].txt, \
    my_itoa(data->item_ref[data->merch.t.inventory.bag[index][0]].stat.life));
    sfText_setString(data->scenes[MERCHANT].txt[7].txt, \
    my_itoa(data->item_ref[data->merch.t.inventory.bag[index][0]].stat.gold));
}

int is_item_merch(data_t *data)
{
    sfVector2i get_mouse_pos = sfMouse_getPositionRenderWindow(data->window.w);
    sfVector2f pos_sprite;
    sfVector2f pos_click = {(float)get_mouse_pos.x, (float)get_mouse_pos.y};

    for (int i = 1; i < MAX_MERCHANT + 1; i++) {
        pos_sprite = sfSprite_getPosition(data->scenes[MERCHANT].objs[i].s);
        if (pos_click.x > pos_sprite.x && pos_click.x < pos_sprite.x + 64 \
        && pos_click.y > pos_sprite.y && pos_click.y < pos_sprite.y + 64)
            return (i - 1);
    }
    return (-1);
}

void merchant_event(data_t *data, sfEvent *event)
{
    int index = 0;

    if (event->mouseButton.type == sfEvtMouseButtonReleased && \
    event->mouseButton.button == sfMouseLeft && (index = is_item_merch(data))
    != -1)
        buy_item(data, index);
    if ((index = is_item_merch(data)) != -1) {
        if (data->boss.boss == 1)
            change_story1(data);
        else if (data->boss.boss == 2)
            change_story2(data);
        description_item_merch(data, index);
    }
}