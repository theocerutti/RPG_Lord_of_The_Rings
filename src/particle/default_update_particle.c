/*
** EPITECH PROJECT, 2019
** default_particle_update
** File description:
** default_particle_update
*/

#include "my_rpg.h"

void respawn_particle(particle_t *p)
{
    p->pos.x = myrand(p->respawn_areax.x, p->respawn_areax.y);
    p->pos.y = myrand(p->respawn_areay.x, p->respawn_areay.y);
    p->gravity.x = myrand(p->grav_limitx.x, p->grav_limitx.y);
    p->gravity.y = myrand(p->grav_limity.x, p->grav_limity.y);
}

void update_respawn_time(particle_system_t *sys)
{
    sys->clock.time = sfClock_getElapsedTime(sys->clock.clock);
    sys->clock.s = sys->clock.time.microseconds / 1000000.0;
    if (sys->clock.s > sys->respawn_cycle) {
        sys->running = (sys->running == 0) ? 1 : 0;
        sfClock_restart(sys->clock.clock);
    }
}

void update_rotation_particle(particle_t *particle, float delta_time)
{
    if (particle->loop_rotating == TRUE) {
        sfRectangleShape_rotate(particle->rect, particle->rotation);
        particle->rotation += particle->speed_rotation * delta_time;
        if (particle->rotation > 360)
            particle->rotation = 0;
    }
}

void update_pos_particle(particle_t *particle, float delta_time)
{
    particle->pos.x += particle->gravity.x * delta_time;
    particle->pos.y += particle->gravity.y * delta_time;
    particle->pos.x += myrand(particle->shake.x * delta_time,
    particle->shake.y * delta_time);
}

void default_update_particle(data_t *d, particle_system_t *sys)
{
    (void)d;
    update_respawn_time(sys);
    for (int i = 0; i < sys->nb_particle; i++) {
        update_rotation_particle(&sys->particle[i], d->delta_time.s);
        update_pos_particle(&sys->particle[i], d->delta_time.s);
        if (!sys->running && ((sys->particle[i].pos.y >
        sys->particle[i].limit && sys->direction == TO_BOTTOM)
        || (sys->particle[i].pos.y < sys->particle[i].limit &&
        sys->direction == TO_TOP)))
            respawn_particle(&sys->particle[i]);
        sfRectangleShape_setPosition(sys->particle[i].rect,
        sys->particle[i].pos);
    }
}