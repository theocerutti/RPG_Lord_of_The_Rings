/*
** EPITECH PROJECT, 2019
** smoke particle
** File description:
** smoke particle
*/

#include "my_rpg.h"

particle_t create_game_obj_fire(data_t *d)
{
    sfColor fire_alpha = {myrand(150, 255), myrand(0, 88), myrand(0, 34),
    myrand(25, 255)};
    particle_t particle = {
        .origin = {0, 0}, .rect = NULL, .color = fire_alpha, .texture = NULL,
        .pos = {myrand(0, d->window.size.x + 200), myrand(1080, 2080)},
        .respawn_areax = {0, d->window.size.x + 200},
        .respawn_areay = {1080, 2080},
        .size = {myrand(5, 15), myrand(5, 15)},
        .rotation = 45, .loop_rotating = TRUE, .speed_rotation =
        myrand_float(0, myrand_float(1 * 6, 0.5 * 6)),
        .gravity = {-5 * 6, myrand(-70 * 6, -30 * 6)},
        .grav_limitx = {0, 0}, .grav_limity = {-70 * 6, -30 * 6},
        .shake = {-50 * 6, 50 * 6},
        .limit = myrand(0, 0)
    };

    particle.origin.x = particle.size.x / 2;
    particle.origin.y = particle.size.y / 2;
    init_particle_obj(&particle, NULL);
    return (particle);
}

void init_full_particle_system_fire(data_t *d, particle_system_t *fire_sys)
{
    init_particle_system(fire_sys, 300, 0, TO_TOP);
    set_particle_to_system(d, fire_sys, &create_game_obj_fire);
    fire_sys->update = &default_update_particle;
}