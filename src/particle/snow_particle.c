/*
** EPITECH PROJECT, 2019
** snow
** File description:
** snow
*/

#include "my_rpg.h"

particle_t create_game_obj_snow(data_t *d)
{
    sfColor white_alpha = {255, 255, 255, myrand(25, 255)};
    particle_t particle = {
        .origin = {0, 0}, .rect = NULL, .color = white_alpha, .texture = NULL,
        .pos = {myrand(0, d->window.size.x + 200), myrand(-300, 0)},
        .respawn_areax = {0, d->window.size.x + 200},
        .respawn_areay = {-200, 0},
        .size = {myrand(10, 25), 0},
        .rotation = 45,
        .loop_rotating = TRUE, .speed_rotation = myrand_float(0, 0.06),
        .gravity = {0, myrand(180, 420)},
        .grav_limitx = {0, 0},
        .grav_limity = {180, 420},
        .shake = {-420, -420},
        .limit = myrand(300, d->window.size.y)
    };

    particle.size.y = particle.size.x;
    particle.origin.x = particle.size.x / 2;
    particle.origin.y = particle.size.y / 2;
    init_particle_obj(&particle, "assets/images/particle/snowflakes.png");
    return (particle);
}

void init_full_particle_system_snow(data_t *d, particle_system_t *snow_sys)
{
    init_particle_system(snow_sys, 300, 0, TO_BOTTOM);
    set_particle_to_system(d, snow_sys, &create_game_obj_snow);
    snow_sys->update = &default_update_particle;
}