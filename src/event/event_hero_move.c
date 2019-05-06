/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** move_hero
*/

#include "my_rpg.h"

void limit_map(character_t *h, window_t *w)
{
    h->obj.pos.x = (h->obj.pos.x < 0) ? 1 : h->obj.pos.x;
    h->obj.pos.x = (h->obj.pos.x > w->size.x -
    h->obj.rect.width) ? w->size.x - h->obj.rect.width : h->obj.pos.x;
    h->obj.pos.y = (h->obj.pos.y < 0) ? 1 : h->obj.pos.y;
    h->obj.pos.y = (h->obj.pos.y > w->size.y -
    h->obj.rect.height) ? w->size.y - h->obj.rect.height : h->obj.pos.y;
}

void event_hero_move_2(data_t *d, int x, int y)
{
    if (sfKeyboard_isKeyPressed(d->ctrl.key[DOWN_KEY]) &&
    d->scenes[d->cur].col[y + 1][x] != '1') {
        shift_game(d, 0, -d->hero.obj.v.y * d->delta_time.s);
        if (d->hero.is_attacking == FALSE)
            d->hero.obj.rect.top = d->hero.obj.offset.y * 3;
    } else if (sfKeyboard_isKeyPressed(d->ctrl.key[RIGHT_KEY]) &&
    d->scenes[d->cur].col[y][x + 1] != '1') {
        shift_game(d, -d->hero.obj.v.x * d->delta_time.s, 0);
        if (d->hero.is_attacking == FALSE)
            d->hero.obj.rect.top = d->hero.obj.offset.y;
    } else {
        if (d->hero.is_attacking == FALSE)
            d->hero.obj.rect.top = d->hero.obj.offset.y * 4;
    }
}

void event_move_hero(data_t *d)
{
    sfVector2f pos = sfSprite_getPosition(d->scenes[d->cur].objs[0].s);
    int x = 1 + (960 - pos.x) / 64;
    int y = 2 + (540 - pos.y) / 64;

    if (sfKeyboard_isKeyPressed(d->ctrl.key[UP_KEY]) &&
    d->scenes[d->cur].col[y - 1][x] != '1') {
        shift_game(d, 0, d->hero.obj.v.y * d->delta_time.s);
        if (d->hero.is_attacking == FALSE)
            d->hero.obj.rect.top = d->hero.obj.offset.y * 2;
    } else if (sfKeyboard_isKeyPressed(d->ctrl.key[LEFT_KEY]) &&
    d->scenes[d->cur].col[y][x - 1] != '1') {
        shift_game(d, d->hero.obj.v.x * d->delta_time.s, 0);
        if (d->hero.is_attacking == FALSE)
            d->hero.obj.rect.top = 0;
    } else
        event_hero_move_2(d, x, y);
    look_change_map(d, x, y);
    sfSprite_setPosition(d->hero.obj.s, d->hero.obj.pos);
}