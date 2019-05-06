/*
** EPITECH PROJECT, 2019
** cleanup_obj
** File description:
** cleanup_obj
*/

#include "my_rpg.h"

void free_txt_obj(txt_t *txt)
{
    sfText_destroy(txt->txt);
    sfFont_destroy(txt->font);
}

void free_clock(myclock_t *clock)
{
    sfClock_destroy(clock->clock);
}

void free_button(button_t *button)
{
    sfRectangleShape_destroy(button->obj);
    sfTexture_destroy(button->t);
    free_txt_obj(&button->txt);
}

void free_game_object(game_object_t *obj)
{
    free_sprite_texture(obj->s, obj->t);
    free_clock(&obj->clock);
}

void free_character_obj(character_t *ch)
{
    free_inventory(&ch->inventory);
    free_stat(&ch->stat);
    free_game_object(&ch->obj);
    free_bar(&ch->bar);
}