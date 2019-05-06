/*
** EPITECH PROJECT, 2019
** handle inventory event
** File description:
** rpg inventory event
*/

#include "my_rpg.h"

int is_item(data_t *data)
{
    sfVector2i get_mouse_pos = sfMouse_getPositionRenderWindow(data->window.w);
    sfVector2f pos_sprite;
    sfVector2f pos_click = {(float)get_mouse_pos.x, (float)get_mouse_pos.y};

    for (int i = 1; i < MAX_BAG + 1; i++) {
        pos_sprite = sfSprite_getPosition(data->scenes[INVENTORY].objs[i].s);
        if (pos_click.x > pos_sprite.x && pos_click.x < pos_sprite.x + 64 \
        && pos_click.y > pos_sprite.y && pos_click.y < pos_sprite.y + 64)
            return (i - 1);
    }
    return (-1);
}

void change_story2(data_t *data)
{
    data->item_ref[9].stat.describe = my_strcpy("You now have two rings. \
    \nOne more to find, and\nit is with the spring Lord, \nwhich is Aragorn. \
    \nThen, reforge The\nOne Ring.");
}

void change_story1(data_t *data)
{
    data->item_ref[9].stat.describe = my_strcpy("You now have one ring. \
    \nTo find the next one, you\nhave to take it from the\nautumn Lord. \
    \nGood luck, he is strong.");
}

void inventory_event(data_t *data)
{
    int index = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && \
    (index = is_item(data)) != -1)
        un_equip_item(data, index);
    if ((index = is_item(data)) != -1) {
        if (data->boss.boss == 1)
            change_story1(data);
        else if (data->boss.boss == 2)
            change_story2(data);
        description_item(data, index);
    }
    if (data->cur == INVENTORY && data->merch.market == 1 && \
    sfMouse_isButtonPressed(sfMouseRight) == sfTrue && \
    (index = is_item(data)) != -1)
        sell_handling(data, index);
    else if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue && \
    (index = is_item(data)) != -1)
        delete_inventory_item(data, index);
}