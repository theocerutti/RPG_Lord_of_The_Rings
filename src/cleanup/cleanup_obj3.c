/*
** EPITECH PROJECT, 2019
** cleanup_obj
** File description:
** cleanup_obj
*/

#include "my_rpg.h"

void free_sprite_texture(sfSprite *s, sfTexture *t)
{
    if (s)
        sfSprite_destroy(s);
    if (t)
        sfTexture_destroy(t);
}

void free_sfx_object(sfx_t *sfx)
{
    if (sfx->type == MUSIC) {
        sfMusic_destroy(sfx->music);
    } else if (sfx->type == SOUND) {
        sfSound_destroy(sfx->sound);
        sfSoundBuffer_destroy(sfx->buffer);
    }
}