/*
** EPITECH PROJECT, 2019
** draw
** File description:
** draw
*/

#include "my_rpg.h"

void draw_full_scenes(data_t *d, int scene_id)
{
    if (d->scenes[d->cur].have_collide_map == TRUE)
        sfRenderWindow_drawSprite(d->window.w, d->scenes[d->cur].on_map.s,
        NULL);
    draw_objs_scenes(d, scene_id);
    draw_button_scenes(d, scene_id);
    draw_txt_scenes(d, scene_id);
    draw_list_character(&d->scenes[scene_id].list_ch, d->window.w);
    draw_particle_system(d, scene_id);
}

void draw_particle_system(data_t *d, int scene_id)
{
    if (d->scenes[scene_id].have_particle_system) {
        d->scenes[scene_id].particle_sys->update(d,
        d->scenes[scene_id].particle_sys);
        for (int i = 0; i < d->scenes[scene_id].particle_sys->nb_particle;
        i++) {
            sfRenderWindow_drawRectangleShape(d->window.w,
            d->scenes[scene_id].particle_sys->particle[i].rect, NULL);
        }
    }
}

void draw_full_lvl_scene(data_t *d)
{
    if (d->hero.obj.pos.y >= d->merch.t.obj.pos.y && d->cur == d->merch.cur_m)
        draw_merchant(d);
    draw_character_obj(&d->hero, d->window.w);
    draw_full_scenes(d, HUD);
    if (d->hero.obj.pos.y < d->merch.t.obj.pos.y && d->cur == d->merch.cur_m)
        draw_merchant(d);
    draw_spells(d);
    draw_spells_overviews(d);
}

void endgame(data_t *d)
{
    if (d->boss.boss == 3 && d->cur == LVL_3_C) {
        d->cur = END;
        d->boss.boss = 4;
    }
}

void draw(data_t *d)
{
    endgame(d);
    sfRenderWindow_clear(d->window.w, sfBlack);
    if (d->cur == CREDITS) {
        d->scenes[d->cur].txt[0].pos.y -= 1;
        sfText_setPosition(d->scenes[d->cur].txt[0].txt,
        d->scenes[d->cur].txt[0].pos);
    }
    if (d->cur == INVENTORY || d->cur == MERCHANT)
        draw_full_scenes(d, d->pre_cur);
    draw_full_scenes(d, d->cur);
    if (d->cur >= LVL_1_F && d->cur <= LVL_3_C)
        draw_full_lvl_scene(d);
    if (d->fps.can_draw_fps == TRUE)
        draw_fps(d);
    if (d->next_map == 1)
        sfRenderWindow_drawText(d->window.w, d->change_map.txt, NULL);
    draw_cursor(d);
    sfRenderWindow_display(d->window.w);
    d->trans += 1;
}