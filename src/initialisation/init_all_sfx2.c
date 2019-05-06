/*
** EPITECH PROJECT, 2019
** init_all_sfx
** File description:
** init_all_sfx
*/

#include "my_rpg.h"

void init_sound4(game_sfx_t *sfx)
{
    sfx_t attack1 = {SOUND, 100, 0, 0, 0};
    sfx_t attack2 = {SOUND, 100, 0, 0, 0};
    sfx_t attack3 = {SOUND, 100, 0, 0, 0};
    sfx_t attack4 = {SOUND, 100, 0, 0, 0};

    init_sfx(&attack1, "assets/sound/attack1.ogg");
    init_sfx(&attack2, "assets/sound/attack2.ogg");
    init_sfx(&attack3, "assets/sound/attack3.ogg");
    init_sfx(&attack4, "assets/sound/attack4.ogg");
    sfx->sfx[16] = attack1;
    sfx->sfx[17] = attack2;
    sfx->sfx[18] = attack3;
    sfx->sfx[19] = attack4;
}