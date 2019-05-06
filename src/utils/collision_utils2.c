/*
** EPITECH PROJECT, 2019
** collision_utils
** File description:
** collision_utils
*/

#include "my_rpg.h"

int is_collide_left(game_object_t *obj1, game_object_t *obj2)
{
    if (is_point_collide(obj1, obj2->pos.x + obj2->rect.width, obj2->pos.y)
    || is_point_collide(obj1, obj2->pos.x + obj2->rect.width,
    obj2->pos.y + obj2->rect.height / 2)
    || is_point_collide(obj1, obj2->pos.x + obj2->rect.width,
    obj2->pos.y + obj2->rect.height))
        return (1);
    return (0);
}

int is_collide_right(game_object_t *obj1, game_object_t *obj2)
{
    if (is_point_collide(obj1, obj2->pos.x, obj2->pos.y)
    || is_point_collide(obj1, obj2->pos.x, obj2->pos.y + obj2->rect.height / 2)
    || is_point_collide(obj1, obj2->pos.x, obj2->pos.y + obj2->rect.height))
        return (1);
    return (0);
}

int is_collide_top(game_object_t *obj1, game_object_t *obj2)
{
    if (is_point_collide(obj1, obj2->pos.x, obj2->pos.y + obj2->rect.height)
    || is_point_collide(obj1, obj2->pos.x + obj2->rect.width / 2,
    obj2->pos.y + obj2->rect.height)
    || is_point_collide(obj1, obj2->pos.x + obj2->rect.width,
    obj2->pos.y + obj2->rect.height))
        return (1);
    return (0);
}

int is_collide_bottom(game_object_t *obj1, game_object_t *obj2)
{
    if (is_point_collide(obj1, obj2->pos.x, obj2->pos.y)
    || is_point_collide(obj1, obj2->pos.x + obj2->rect.width / 2, obj2->pos.y)
    || is_point_collide(obj1, obj2->pos.x + obj2->rect.width, obj2->pos.y))
        return (1);
    return (0);
}