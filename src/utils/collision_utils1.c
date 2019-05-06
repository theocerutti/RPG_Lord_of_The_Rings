/*
** EPITECH PROJECT, 2019
** collision_utils
** File description:
** collision_utils
*/

#include "my_rpg.h"

int is_near(game_object_t *obj1, game_object_t *obj2, int area_effect)
{
    int xp = obj1->pos.x;
    int yp = obj1->pos.y;
    int xe = obj2->pos.x;
    int ye = obj2->pos.y;
    int d2 = (xp - xe) * (xp - xe) + (yp - ye) * (yp - ye);

    if (d2 < pow(area_effect, 2))
        return (1);
    return (0);
}

int is_collide_simple(game_object_t *obj1, game_object_t *obj2)
{
    if ((obj2->pos.x >= obj1->pos.x + obj1->rect.width)
    || (obj2->pos.x + obj2->rect.width <= obj1->pos.x)
    || (obj2->pos.y >= obj1->pos.y + obj1->rect.height)
    || (obj2->pos.y + obj2->rect.height <= obj1->pos.y))
        return (0);
    return (1);
}

int is_point_collide(game_object_t *obj, int x, int y)
{
    if (x >= obj->pos.x && x <= obj->pos.x + obj->rect.width
    && y >= obj->pos.y && y <= obj->pos.y + obj->rect.height)
        return (1);
    return (0);
}

int collide_triangle(sfVector2f *p, sfVector2i p_ref)
{
    float areaOrig = abs((p[1].x - p[0].x) *
    (p[2].y - p[0].y) - (p[2].x - p[0].x) * (p[1].y - p[0].y));
    float area1 = abs((p[0].x - p_ref.x) *
    (p[1].y - p_ref.y) - (p[1].x - p_ref.x) * (p[0].y - p_ref.y));
    float area2 = abs((p[1].x - p_ref.x) *
    (p[2].y - p_ref.y) - (p[2].x - p_ref.x) * (p[1].y - p_ref.y));
    float area3 = abs((p[2].x - p_ref.x) *
    (p[0].y - p_ref.y) - (p[0].x - p_ref.x) * (p[2].y - p_ref.y));

    if (area1 + area2 + area3 == areaOrig)
        return (1);
    return (0);
}