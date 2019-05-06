/*
** EPITECH PROJECT, 2019
** send spell event get
** File description:
** rpg
*/

#include "my_rpg.h"

void overview_spell(data_t *data, sfEvent *event)
{
    if ((data->cur >= LVL_1_F && data->cur <= LVL_3_C &&
    event->type == sfEvtKeyPressed &&
    can_throw_spell_anim(data->overview_activate_anim)) || one_spell_on(data)) {
        if ((((event->key.code == sfKeyNum1 || event->key.code == sfKeyNumpad1)
        && can_throw_spell(data, 0))) || data->overview_activate[0])
            set_spell0(data);
        if ((((event->key.code == sfKeyNum2 || event->key.code == sfKeyNumpad2)
        && can_throw_spell(data, 1))) || data->overview_activate[1])
            set_spell1(data);
        if ((((event->key.code == sfKeyNum3 || event->key.code == sfKeyNumpad3)
        && can_throw_spell(data, 2))) || data->overview_activate[2])
            set_spell2(data);
        if ((((event->key.code == sfKeyQuote || event->key.code == sfKeyNumpad4)
        && can_throw_spell(data, 3))) || data->overview_activate[3])
            set_spell3(data);
    }
}

void send_the_spell(data_t *data, sfEvent *event)
{
    if (data->cur >= LVL_1_F && data->cur <= LVL_3_C &&
    event->type == sfEvtKeyReleased) {
        if ((event->key.code == sfKeyNum1 || event->key.code == sfKeyNumpad1)
        && data->overview_activate[0])
            exec_spell0(data);
        if ((event->key.code == sfKeyNum2 || event->key.code == sfKeyNumpad2)
        && data->overview_activate[1])
            exec_spell1(data);
        if ((event->key.code == sfKeyNum3 || event->key.code == sfKeyNumpad3)
        && data->overview_activate[2])
            exec_spell2(data);
        if ((event->key.code == sfKeyQuote || event->key.code == sfKeyNumpad4)
        && data->overview_activate[3])
            exec_spell3(data);
    }
}

void send_spell_anim(data_t *data)
{
    for (int i = 0; i < 4; i++) {
        if (data->overview[i].spell_anim[0].rect.left >
        data->overview[i].spell_anim[0].width -
        data->overview[i].spell_anim[0].offset.x * 2
        && data->overview[i].spell_anim[0].rect.top >
        data->overview[i].spell_anim[0].height -
        data->overview[i].spell_anim[0].offset.y * 2) {
            data->overview[i].spell_anim[0].rect.left = 0;
            data->overview[i].spell_anim[0].rect.top = 0;
            data->overview_activate_anim[i] = 0;
        }
        if (data->overview_activate_anim[i]) {
            for (int j = 0; j < data->overview[i].nb_spell_anim; j++) {
                anim_obj(&data->overview[i].spell_anim[j], 0.01667);
            }
        }
    }
}

void event_spells(data_t *data, sfEvent *event)
{
    overview_spell(data, event);
    send_the_spell(data, event);
    set_icon(data);
}