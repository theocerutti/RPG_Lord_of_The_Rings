/*
** EPITECH PROJECT, 2019
** draw_character
** File description:
** draw_character
*/

#include "my_rpg.h"

void update_bar_character(character_t *ch)
{
    ch->bar.lvl.pos = (sfVector2f){ch->bar.life_bar.pos.x +
    ch->bar.life_bar.width + 10, ch->bar.life_bar.pos.y - 3};
    sfText_setString(ch->bar.lvl.txt, big_strcat(2, "Lvl. ",
    my_itoa(ch->stat.level)));
    sfText_setPosition(ch->bar.lvl.txt, ch->bar.lvl.pos);
    ch->bar.life.pos = (sfVector2f){ch->bar.life_bar.pos.x +
    ch->bar.life_bar.width / 4, ch->bar.life_bar.pos.y - 10};
    sfText_setString(ch->bar.life.txt, big_strcat(3, my_itoa(ch->stat.life),
    " / ", my_itoa(ch->stat.max_life)));
    sfText_setPosition(ch->bar.life.txt, ch->bar.life.pos);
    while ((my_strlen(sfText_getString(ch->bar.life.txt)) *
    sfText_getCharacterSize(ch->bar.life.txt)) > ch->bar.life_bar.width) {
        ch->bar.life.size -= 1;
        sfText_setCharacterSize(ch->bar.life.txt, ch->bar.life.size);
    }
}

void draw_character_obj(character_t *ch, sfRenderWindow *w)
{
    sfRenderWindow_drawSprite(w, ch->obj.s, NULL);
    ch->bar.life_bar.pos = (sfVector2f){ch->obj.pos.x + ch->obj.offset.x / 3,
    ch->obj.pos.y - 9};
    sfSprite_setPosition(ch->bar.life_bar.s, ch->bar.life_bar.pos);
    sfSprite_setPosition(ch->bar.s_bg, ch->bar.life_bar.pos);
    sfRenderWindow_drawSprite(w, ch->bar.s_bg, NULL);
    sfRenderWindow_drawSprite(w, ch->bar.life_bar.s, NULL);
    update_bar_character(ch);
    sfRenderWindow_drawText(w, ch->bar.lvl.txt, NULL);
    sfRenderWindow_drawText(w, ch->bar.life.txt, NULL);
}

void draw_list_character(list_t *list, sfRenderWindow *w)
{
    node_t *tmp = *list;

    while (tmp != NULL) {
        draw_character_obj(&tmp->ch, w);
        tmp = tmp->next;
    }
}