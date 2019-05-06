/*
** EPITECH PROJECT, 2019
** usefull_init
** File description:
** usefull_init
*/

#include "my_rpg.h"

void init_bar_character(character_t *ch)
{
    init_txt_simple(&ch->bar.lvl, "assets/fonts/diablolight.ttf", "Lvl. 0");
    init_txt_simple(&ch->bar.life, "assets/fonts/diablolight.ttf", "0 / 0");
    ch->bar.s_bg = sfSprite_create();
    ch->bar.t_bg =
    sfTexture_createFromFile("assets/images/character/enemies/life_bar_bg.png",
    NULL);
    sfSprite_setTexture(ch->bar.s_bg, ch->bar.t_bg, sfTrue);
    sfSprite_setPosition(ch->bar.s_bg,
    (sfVector2f){ch->bar.life_bar.pos.x, ch->bar.life_bar.pos.y});
    init_game_object(&ch->bar.life_bar,
    "assets/images/character/enemies/life_bar.png");
    sfSprite_setPosition(ch->bar.life_bar.s,
    (sfVector2f){ch->obj.pos.x, ch->obj.pos.y});
}

void init_sfx(sfx_t *sfx_obj, char const *path)
{
    if (sfx_obj->type == MUSIC) {
        sfx_obj->music = sfMusic_createFromFile(path);
        sfMusic_setVolume(sfx_obj->music, sfx_obj->volume);
        sfMusic_setLoop(sfx_obj->music, sfTrue);
    } else if (sfx_obj->type == SOUND) {
        sfx_obj->buffer = sfSoundBuffer_createFromFile(path);
        sfx_obj->sound = sfSound_create();
        sfSound_setBuffer(sfx_obj->sound, sfx_obj->buffer);
        sfSound_setVolume(sfx_obj->sound, sfx_obj->volume);
    }
}

void init_clock(myclock_t *clock)
{
    clock->clock = sfClock_create();
    clock->time = sfClock_getElapsedTime(clock->clock);
}

void init_game_object(game_object_t *obj, char const *path)
{
    sfVector2u width_height = {0, 0};

    init_clock(&obj->clock);
    obj->t = sfTexture_createFromFile(path, NULL);
    obj->s = sfSprite_create();
    width_height = sfTexture_getSize(obj->t);
    obj->width = width_height.x;
    obj->height = width_height.y;
    obj->rect.top = (obj->rect.top == 0) ? 0 : obj->rect.top;
    obj->rect.left = (obj->rect.left == 0) ? 0 : obj->rect.left;
    obj->rect.width = obj->offset.x;
    obj->rect.height = obj->offset.y;
    sfSprite_setPosition(obj->s, obj->pos);
    sfSprite_setTexture(obj->s, obj->t, sfTrue);
    sfSprite_setScale(obj->s, obj->scale);
    sfSprite_setTextureRect(obj->s, obj->rect);
}

void init_button(button_t *obj, char const *path, char const *str_txt,
char const *str_font)
{
    obj->obj = sfRectangleShape_create();
    sfRectangleShape_setSize(obj->obj,
    (sfVector2f){obj->offset.x, obj->offset.y});
    sfRectangleShape_setPosition(obj->obj, obj->pos);
    if (str_txt) {
        init_txt(obj, str_font, str_txt);
    }
    obj->t = sfTexture_createFromFile(path, NULL);
    sfRectangleShape_setTexture(obj->obj, obj->t, sfTrue);
    obj->rect.top = 0;
    obj->rect.left = 0;
    obj->rect.width = obj->offset.x;
    obj->rect.height = obj->offset.y;
    sfRectangleShape_setTextureRect(obj->obj, obj->rect);
}