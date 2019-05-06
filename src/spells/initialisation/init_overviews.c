/*
** EPITECH PROJECT, 2019
** initialize overviews spells
** File description:
** rpg
*/

#include "my_rpg.h"

void init_overview_0(data_t *d)
{
    game_object_t spell_anim = {350, 400, {3, 3}, {50, 50}, {0, 0}, {0, 0},
    0, 0, {0}, {0, {0}, 0}, MISCELLANEOUS_ID};

    init_game_object(&spell_anim, "assets/images/particle/spell0_anim.png");
    d->overview[0].overview_r = malloc(sizeof(sfRectangleShape *));
    d->overview[0].overview_r[0] = sfRectangleShape_create();
    d->overview[0].pos = sfSprite_getPosition(d->hero.obj.s);
    d->overview[0].size = (sfVector2f){100, 400};
    sfRectangleShape_setFillColor(d->overview[0].overview_r[0], \
    (sfColor){255, 0, 0, 100});
    sfRectangleShape_setSize(d->overview[0].overview_r[0], \
    d->overview[0].size);
    sfRectangleShape_setPosition(d->overview[0].overview_r[0], \
    d->overview[0].pos);
    d->overview[0].draw_it = &draw_overview_0;
    d->overview[0].spell_anim = malloc(sizeof(game_object_t));
    d->overview[0].nb_spell_anim = 1;
    d->overview[0].spell_anim[0] = spell_anim;
    d->overview_activate[0] = 0;
    d->overview_activate_anim[0] = 0;
}

void init_overview_1_anim(data_t *d)
{
    game_object_t spell_anim0 = {350, 400, {3, 3}, {50, 50}, {0, 0}, {0, 0},
    0, 0, {0}, {0, {0}, 0}, MISCELLANEOUS_ID};
    game_object_t spell_anim1 = {350, 400, {3, 3}, {50, 50}, {0, 0}, {0, 0},
    0, 0, {0}, {0, {0}, 0}, MISCELLANEOUS_ID};
    game_object_t spell_anim2 = {350, 400, {3, 3}, {50, 50}, {0, 0}, {0, 0},
    0, 0, {0}, {0, {0}, 0}, MISCELLANEOUS_ID};
    game_object_t spell_anim3 = {350, 400, {3, 3}, {50, 50}, {0, 0}, {0, 0},
    0, 0, {0}, {0, {0}, 0}, MISCELLANEOUS_ID};

    init_game_object(&spell_anim0, "assets/images/particle/spell1_anim.png");
    init_game_object(&spell_anim1, "assets/images/particle/spell1_anim.png");
    init_game_object(&spell_anim2, "assets/images/particle/spell1_anim.png");
    init_game_object(&spell_anim3, "assets/images/particle/spell1_anim.png");
    d->overview[1].spell_anim = malloc(sizeof(game_object_t) * 4);
    d->overview[1].spell_anim[0] = spell_anim0;
    d->overview[1].spell_anim[1] = spell_anim1;
    d->overview[1].spell_anim[2] = spell_anim2;
    d->overview[1].spell_anim[3] = spell_anim3;
    d->overview[1].nb_spell_anim = 4;
}

void init_overview_1(data_t *d)
{
    d->overview[1].overview_r = malloc(sizeof(sfRectangleShape *) * 4);
    for (int i = 0; i < 4; i++) {
        d->overview[1].overview_r[i] = sfRectangleShape_create();
        d->overview[1].pos = sfSprite_getPosition(d->hero.obj.s);
        d->overview[1].size = (sfVector2f){100, 400};
        sfRectangleShape_setFillColor(d->overview[1].overview_r[i], \
        (sfColor){255, 0, 0, 100});
        sfRectangleShape_setSize(d->overview[1].overview_r[i], \
        d->overview[1].size);
        sfRectangleShape_setPosition(d->overview[1].overview_r[i], \
        d->overview[1].pos);
    }
    d->overview[1].draw_it = &draw_overview_1;
    d->overview_activate[1] = 0;
    d->overview_activate_anim[1] = 0;
    init_overview_1_anim(d);
}

void init_overview_2(data_t *d)
{
    game_object_t spell_anim = {1000, 900, {1.5, 1.5}, {100, 100},
    {0, 0}, {0, 0}, 0, 0, {0}, {0, {0}, 0}, MISCELLANEOUS_ID};
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(d->window.w);

    init_game_object(&spell_anim, "assets/images/particle/spell2_anim.png");
    d->overview[2].overview_c = sfCircleShape_create();
    d->overview[2].pos.x = (float)pos_mouse.x;
    d->overview[2].pos.y = (float)pos_mouse.y;
    d->overview[2].radius = 100;
    sfCircleShape_setFillColor(d->overview[2].overview_c, \
    (sfColor){255, 0, 0, 100});
    sfCircleShape_setRadius(d->overview[2].overview_c, d->overview[2].radius);
    sfCircleShape_setPosition(d->overview[2].overview_c, d->overview[2].pos);
    d->overview[2].draw_it = &draw_overview_2;
    d->overview[2].spell_anim = malloc(sizeof(game_object_t));
    d->overview[2].nb_spell_anim = 1;
    d->overview[2].spell_anim[0] = spell_anim;
    d->overview_activate[2] = 0;
    d->overview_activate_anim[2] = 0;
}

void init_overview_3(data_t *d)
{
    game_object_t spell_anim = {3200, 3200, {0.9, 0.9}, {3200/8, 3200/8},
    {0, 0}, {0, 0},
    0, 0, {0}, {0, {0}, 0}, MISCELLANEOUS_ID};

    init_game_object(&spell_anim, "assets/images/particle/spell3_anim.png");
    d->overview[3].overview_c = sfCircleShape_create();
    d->overview[3].pos = sfSprite_getPosition(d->hero.obj.s);
    d->overview[3].radius = 175;
    sfCircleShape_setFillColor(d->overview[3].overview_c, \
    (sfColor){255, 0, 0, 100});
    sfCircleShape_setRadius(d->overview[3].overview_c, d->overview[3].radius);
    sfCircleShape_setPosition(d->overview[3].overview_c, d->overview[3].pos);
    d->overview[3].draw_it = &draw_overview_3;
    d->overview[3].spell_anim = malloc(sizeof(game_object_t));
    d->overview[3].nb_spell_anim = 1;
    d->overview[3].spell_anim[0] = spell_anim;
    d->overview_activate[3] = 0;
    d->overview_activate_anim[3] = 0;
}