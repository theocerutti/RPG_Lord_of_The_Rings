/*
** EPITECH PROJECT, 2019
** usefull_init
** File description:
** usefull_init
*/

#include "my_rpg.h"

void init_txt_simple(txt_t *t, char const *path_font, char const *str)
{
    t->txt = sfText_create();
    t->font = sfFont_createFromFile(path_font);
    sfText_setString(t->txt, str);
    sfText_setFont(t->txt, t->font);
    sfText_setCharacterSize(t->txt, t->size);
    sfText_setPosition(t->txt, t->pos);
    sfText_setColor(t->txt, t->color);
}

void init_txt(button_t *obj, char const *path_font, char const *str)
{
    obj->txt.txt = sfText_create();
    obj->txt.font = sfFont_createFromFile(path_font);
    sfText_setString(obj->txt.txt, str);
    sfText_setFont(obj->txt.txt, obj->txt.font);
    obj->txt.pos.x = obj->pos.x + obj->size.x / 2 -
    ((float)my_strlen(str) / 4) * sfText_getCharacterSize(obj->txt.txt);
    obj->txt.pos.y = obj->pos.y + obj->size.y / 4;
    sfText_setCharacterSize(obj->txt.txt, obj->txt.size);
    sfText_setPosition(obj->txt.txt, obj->txt.pos);
    sfText_setColor(obj->txt.txt, obj->txt.color);
}

void init_particle_obj(particle_t *obj, char *path)
{
    obj->rect = sfRectangleShape_create();
    if (path) {
        obj->texture = sfTexture_createFromFile(path, NULL);
        sfRectangleShape_setTexture(obj->rect, obj->texture, sfFalse);
    }
    sfRectangleShape_setOrigin(obj->rect, obj->origin);
    sfRectangleShape_setFillColor(obj->rect, obj->color);
    sfRectangleShape_setSize(obj->rect, obj->size);
    sfRectangleShape_setPosition(obj->rect, obj->pos);
    sfRectangleShape_rotate(obj->rect, obj->rotation);
    if (obj->loop_rotating == TRUE)
        obj->rotation = 0;
}

void init_particle_system(particle_system_t *sys, int nb_particle,
float respawn_cycle, int direction)
{
    sys->direction = direction;
    sys->nb_particle = nb_particle;
    sys->clock.clock = NULL;
    sys->clock.s = 0;
    sys->respawn_cycle = respawn_cycle;
    sys->running = FALSE;
    sys->update = NULL;
    init_clock(&sys->clock);
    sys->particle = malloc(sizeof(particle_t) * nb_particle);
}

void set_particle_to_system(data_t *d, particle_system_t *particle_sys,
particle_t (*get_particle_obj)(data_t *))
{
    for (int i = 0; i < particle_sys->nb_particle; i++)
        particle_sys->particle[i] = get_particle_obj(d);
}