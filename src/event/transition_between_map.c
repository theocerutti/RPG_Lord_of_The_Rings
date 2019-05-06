/*
** EPITECH PROJECT, 2019
** transition_map
** File description:
** transition_map
*/

#include "my_rpg.h"

void draw_circle_change_map(data_t *d, float radius,
sfCircleShape *circle, int scene_id)
{
    sfRenderWindow_clear(d->window.w, sfBlack);
    draw_full_scenes(d, scene_id);
    sfCircleShape_setOrigin(circle, (sfVector2f){radius, radius});
    sfCircleShape_setRadius(circle, radius);
    sfRenderWindow_drawCircleShape(d->window.w, circle, NULL);
    sfRenderWindow_display(d->window.w);
}

void draw_change_map(data_t *d)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setFillColor(circle, sfBlack);
    sfCircleShape_setPosition(circle, (sfVector2f){d->window.size.x / 2,
    d->window.size.y / 2});
    float radius = 0;

    while (radius < 1350) {
        radius += 2000.0 * d->delta_time.s;
        draw_circle_change_map(d, radius, circle, d->pre_cur);
    }
    while (radius > 0) {
        radius -= 2000.0 * d->delta_time.s;
        draw_circle_change_map(d, radius, circle, d->cur);
    }
    sfCircleShape_destroy(circle);
}

int change_next_map(data_t *d)
{
    if ((d->cur == LVL_1_C && d->boss.boss < 1) ||
    (d->cur == LVL_2_C && d->boss.boss < 2)) {
        d->next_map = 1;
        d->trans = 1;
        return (1);
    }
    d->pre_cur = d->cur;
    d->cur += 1;
    init_basic_enemy_for_scene(d, d->cur);
    if (d->cur == LVL_3_C)
        d->scenes[d->cur].objs[0].pos.y += 100;
    draw_change_map(d);
    d->scenes[d->cur].objs[0].pos.x += 50;
    sfSprite_setPosition(d->scenes[d->cur].objs[0].s,
    d->scenes[d->cur].objs[0].pos);
    sfSprite_setPosition(d->scenes[d->cur].on_map.s,
    d->scenes[d->cur].objs[0].pos);
    d->trans = 1;
    return (0);
}

void look_change_map(data_t *d, int x, int y)
{
    if (d->scenes[d->cur].col[y][x] == '2') {
        if (change_next_map(d) == 1)
            return;
    } else if (d->scenes[d->cur].col[y][x] == '3') {
        d->pre_cur = d->cur;
        d->cur -= 1;
        init_basic_enemy_for_scene(d, d->cur);
        draw_change_map(d);
        d->scenes[d->cur].objs[0].pos.y -= 50;
        if (d->cur == LVL_3_C || d->cur == LVL_3_F)
            d->scenes[d->cur].objs[0].pos.x -= 50;
        sfSprite_setPosition(d->scenes[d->cur].objs[0].s,
        d->scenes[d->cur].objs[0].pos);
        sfSprite_setPosition(d->scenes[d->cur].on_map.s,
        d->scenes[d->cur].objs[0].pos);
        d->trans = 1;
    }
    d->next_map = 0;
}