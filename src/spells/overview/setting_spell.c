/*
** EPITECH PROJECT, 2019
** spell1 overview setting up
** File description:
** rpg
*/

#include "my_rpg.h"

void set_rect_spell0_mouse(data_t *data, int index)
{
    sfVector2f n_size[4] = {{400, 100}, {400, 100}, {100, 400}, {100, 400}};
    sfVector2f pos = sfSprite_getPosition(data->hero.obj.s);
    sfVector2f n_pos[4] = {{0, 0}, {-300, 0}, {0, -300}, {0, 0}};
    sfVector2f new_pos = {0, 0};

    sfRectangleShape_setSize(data->overview[0].overview_r[0], n_size[index]);
    new_pos.x = pos.x + n_pos[index].x;
    new_pos.y = pos.y + n_pos[index].y;
    sfRectangleShape_setPosition(data->overview[0].overview_r[0], new_pos);
    data->overview_activate[0] = 1;
}

void move_spell_anim(game_object_t *hero, game_object_t *spell,
sfVector2f off, float rotation)
{
    spell->pos.x = hero->pos.x + off.x;
    spell->pos.y = hero->pos.y + off.y;
    sfSprite_setPosition(spell->s, spell->pos);
    sfSprite_setRotation(spell->s, rotation);
}

void set_spell0_1(data_t *data, sfVector2i pos_mouse)
{
    sfVector2f p_tab_bot[3] = {{0, 1080}, {1920, 1080}, data->hero.obj.pos};
    sfVector2f p_tab_top[3] = {{0, 0}, {1920, 0}, data->hero.obj.pos};

    if (collide_triangle(p_tab_top, pos_mouse)) {
        move_spell_anim(&data->hero.obj, &data->overview[0].spell_anim[0],
        (sfVector2f){50 / 4 - 35, -68 * 3}, 0);
        set_rect_spell0_mouse(data, 2);
    }
    if (collide_triangle(p_tab_bot, pos_mouse)) {
        move_spell_anim(&data->hero.obj, &data->overview[0].spell_anim[0],
        (sfVector2f){125, 84 + 68 * 3}, 180);
        set_rect_spell0_mouse(data, 3);
    }
}

void set_spell0(data_t *data)
{
    sfVector2f p_tab_right[3] = {{1920, 0}, {1920, 1080}, data->hero.obj.pos};
    sfVector2f p_tab_left[3] = {{0, 0}, {0, 1080}, data->hero.obj.pos};
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(data->window.w);

    if (collide_triangle(p_tab_left, pos_mouse)) {
        move_spell_anim(&data->hero.obj, &data->overview[0].spell_anim[0],
        (sfVector2f){-68 * 3, 125}, 270);
        set_rect_spell0_mouse(data, 1);
    }
    if (collide_triangle(p_tab_right, pos_mouse)) {
        move_spell_anim(&data->hero.obj, &data->overview[0].spell_anim[0],
        (sfVector2f){84 + 68 * 3, 50 / 4 - 35}, 90);
        set_rect_spell0_mouse(data, 0);
    }
    set_spell0_1(data, pos_mouse);
}

void set_spell1(data_t *data)
{
    sfVector2f n_size[3] = {{400, 100}, {400, 100}, {100, 400}};
    sfVector2f pos = sfSprite_getPosition(data->hero.obj.s);
    sfVector2f n_pos[3] = {{0, 0}, {-300, 0}, {0, -300}};
    sfVector2f new_pos = {0, 0};

    move_spell_anim(&data->hero.obj, &data->overview[1].spell_anim[0],
    (sfVector2f){50 / 4 - 35, -68 * 3}, 0);
    move_spell_anim(&data->hero.obj, &data->overview[1].spell_anim[1],
    (sfVector2f){125, 84 + 68 * 3}, 180);
    move_spell_anim(&data->hero.obj, &data->overview[1].spell_anim[2],
    (sfVector2f){-68 * 3, 125}, 270);
    move_spell_anim(&data->hero.obj, &data->overview[1].spell_anim[3],
    (sfVector2f){84 + 68 * 3, 50 / 4 - 35}, 90);
    for (int i = 0; i < 3; i++) {
        sfRectangleShape_setSize(data->overview[1].overview_r[i], n_size[i]);
        new_pos.x = pos.x + n_pos[i].x;
        new_pos.y = pos.y + n_pos[i].y;
        sfRectangleShape_setPosition(data->overview[1].overview_r[i], new_pos);
    }
    data->overview_activate[1] = 1;
}