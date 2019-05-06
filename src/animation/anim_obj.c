/*
** EPITECH PROJECT, 2019
** anim obj
** File description:
** anim obj
*/

#include "my_rpg.h"

void anim_obj_simple(game_object_t *obj, float second)
{
    obj->clock.time = sfClock_getElapsedTime(obj->clock.clock);
    obj->clock.s = obj->clock.time.microseconds / 1000000.0;
    if (obj->clock.s > second) {
        obj->rect.left += obj->offset.x;
        if (obj->rect.left > obj->width - obj->offset.x) {
            obj->rect.left = 0;
        }
        sfSprite_setTextureRect(obj->s, obj->rect);
        sfClock_restart(obj->clock.clock);
    }
}

void anim_obj(game_object_t *obj, float second)
{
    obj->clock.time = sfClock_getElapsedTime(obj->clock.clock);
    obj->clock.s = obj->clock.time.microseconds / 1000000.0;
    if (obj->clock.s > second) {
        obj->rect.left += obj->offset.x;
        if (obj->rect.left > obj->width - obj->offset.x) {
            obj->rect.top += obj->offset.y;
            obj->rect.left = 0;
        }
        if (obj->rect.top > obj->height - obj->offset.y)
            obj->rect.top = 0;
        sfSprite_setTextureRect(obj->s, obj->rect);
        sfClock_restart(obj->clock.clock);
    }
}