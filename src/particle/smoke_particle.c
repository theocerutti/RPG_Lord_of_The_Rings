/*
** EPITECH PROJECT, 2019
** smoke particle
** File description:
** smoke particle
*/

#include "my_rpg.h"

particle_t create_game_obj_smoke(data_t *d)
{
    sfColor white_alpha = {255, 255, 255, myrand(25, 255)};
    particle_t particle = {
        .origin = {0, 0}, .rect = NULL, .color = white_alpha, .texture = NULL,
        .pos = {myrand(0, d->window.size.x), myrand(1080, 2080)},
        .respawn_areax = {0, d->window.size.x},
        .respawn_areay = {1080, 2080},
        .size = {myrand(10, 45), 0},
        .rotation = 45,
        .loop_rotating = TRUE, .speed_rotation = myrand_float(0, 0.01),
        .gravity = {-5, myrand(-170, -130)},
        .grav_limitx = {0, 0}, .grav_limity = {-170, -130},
        .shake = {-150, 150},
        .limit = myrand(0, 0)
    };

    particle.size.y = particle.size.x;
    particle.origin.x = particle.size.x / 2;
    particle.origin.y = particle.size.y / 2;
    init_particle_obj(&particle, "assets/images/particle/smoke.png");
    return (particle);
}

void init_full_particle_system_smoke(data_t *d, particle_system_t *smoke_sys)
{
    init_particle_system(smoke_sys, 300, 0, TO_TOP);
    set_particle_to_system(d, smoke_sys, &create_game_obj_smoke);
    smoke_sys->update = &default_update_particle;
}