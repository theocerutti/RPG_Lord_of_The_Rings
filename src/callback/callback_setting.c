/*
** EPITECH PROJECT, 2019
** callback_setting
** File description:
** callback_setting
*/

#include "my_rpg.h"

void button_audio_setting(data_t *data)
{
    data->cur = AUDIO_SETTING;
}

void button_control_setting(data_t *data)
{
    data->cur = CONTROL;
}

void button_setting(data_t *data)
{
    data->cur = SETTING;
}

void button_cursor_slider_sound(data_t *data)
{
    sfVector2i pm = sfMouse_getPositionRenderWindow(data->window.w);
    float new_volume = 0;
    game_object_t *obj = &data->scenes[AUDIO_SETTING].objs[1];
    button_t *but = &data->scenes[AUDIO_SETTING].buttons[1];

    obj->pos.x = pm.x;
    if (obj->pos.x < but->pos.x)
        obj->pos.x = but->pos.x;
    else if (obj->pos.x > but->pos.x + but->size.x)
        obj->pos.x = but->pos.x + but->size.x;
    new_volume = (-but->pos.x + obj->pos.x) / 4;
    for (int i = 0; i < data->sfx.nb_sfx; i++) {
        if (data->sfx.sfx[i].type == SOUND) {
            data->sfx.sfx[i].volume = new_volume;
            sfSound_setVolume(data->sfx.sfx[i].sound, data->sfx.sfx[i].volume);
        }
    }
    sfText_setString(data->scenes[AUDIO_SETTING].txt[2].txt,
    my_itoa(new_volume));
    sfSprite_setPosition(obj->s, obj->pos);
}

void button_cursor_slider_music(data_t *data)
{
    sfVector2i pm = sfMouse_getPositionRenderWindow(data->window.w);
    float new_volume = 0;
    game_object_t *obj = &data->scenes[AUDIO_SETTING].objs[2];
    button_t *but = &data->scenes[AUDIO_SETTING].buttons[2];

    obj->pos.x = pm.x;
    if (obj->pos.x < but->pos.x)
        obj->pos.x = but->pos.x;
    else if (obj->pos.x > but->pos.x + but->size.x)
        obj->pos.x = but->pos.x + but->size.x;
    new_volume = (-but->pos.x + obj->pos.x) / 4;
    for (int i = 0; i < data->sfx.nb_sfx; i++) {
        if (data->sfx.sfx[i].type == MUSIC) {
            data->sfx.sfx[i].volume = new_volume;
            sfMusic_setVolume(data->sfx.sfx[i].music, data->sfx.sfx[i].volume);
        }
    }
    sfText_setString(data->scenes[AUDIO_SETTING].txt[3].txt,
    my_itoa(new_volume));
    sfSprite_setPosition(obj->s, obj->pos);
}