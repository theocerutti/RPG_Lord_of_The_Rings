/*
** EPITECH PROJECT, 2019
** rain_particle
** File description:
** rain_particle
*/

#include "my_rpg.h"

particle_t create_game_obj_rain(data_t *d)
{
    sfColor blue_alpha = {255, 255, 255, myrand(25, 255)};
    particle_t particle = {
        .origin = {0, 0}, .rect = NULL, .color = blue_alpha, .texture = NULL,
        .pos = {myrand(0, d->window.size.x), myrand(-200, 0)},
        .respawn_areax = {0, d->window.size.x},
        .respawn_areay = {-200, 0},
        .size = {myrand(2, 4), myrand(40, 70)},
        .rotation = myrand(25, 30),
        .loop_rotating = FALSE, .speed_rotation = myrand_float(0, 0),
        .gravity = {-135, myrand(225, 1125)},
        .grav_limitx = {-135, -135},
        .grav_limity = {225, 1125},
        .shake = {0, 0},
        .limit = myrand(300, d->window.size.y)
    };

    particle.origin.x = particle.size.x / 2;
    particle.origin.y = particle.size.y / 2;
    init_particle_obj(&particle, "assets/images/particle/rain.png");
    return (particle);
}

void init_full_particle_system_rain(data_t *d, particle_system_t *rain_sys)
{
    init_particle_system(rain_sys, 300, 0, TO_BOTTOM);
    set_particle_to_system(d, rain_sys, &create_game_obj_rain);
    rain_sys->update = default_update_particle;
}