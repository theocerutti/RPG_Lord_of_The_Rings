/*
** EPITECH PROJECT, 2019
** exec spell functions
** File description:
** rpg
*/

#include "my_rpg.h"

void exec_spell0(data_t *data)
{
    node_t *tmp = data->scenes[data->cur].list_ch;

    if (sfSound_getStatus(data->sfx.sfx[3].sound) != sfPlaying)
        sfSound_play(data->sfx.sfx[3].sound);
    while (tmp != NULL) {
        spell0_hit(data, tmp);
        tmp = tmp->next;
    }
    cost_mana_hero(data, data->hero.spell[0].stat.mana, DAMAGE);
    data->overview_activate[0] = 0;
    data->overview_activate_anim[0] = 1;
}

void exec_spell1(data_t *data)
{
    node_t *tmp = data->scenes[data->cur].list_ch;

    if (sfSound_getStatus(data->sfx.sfx[3].sound) != sfPlaying)
        sfSound_play(data->sfx.sfx[3].sound);
    while (tmp != NULL) {
        spell1_hit(data, tmp);
        tmp = tmp->next;
    }
    cost_mana_hero(data, data->hero.spell[1].stat.mana, DAMAGE);
    data->overview_activate[1] = 0;
    data->overview_activate_anim[1] = 1;
}

void exec_spell2(data_t *data)
{
    node_t *tmp = data->scenes[data->cur].list_ch;
    sfVector2i pm = sfMouse_getPositionRenderWindow(data->window.w);

    if (sfSound_getStatus(data->sfx.sfx[9].sound) != sfPlaying)
        sfSound_play(data->sfx.sfx[9].sound);
    while (tmp != NULL) {
        spell2_hit(data, tmp);
        tmp = tmp->next;
    }
    cost_mana_hero(data, data->hero.spell[2].stat.mana, DAMAGE);
    data->overview_activate[2] = 0;
    data->overview_activate_anim[2] = 1;
    data->overview[2].spell_anim[0].pos = (sfVector2f){pm.x - 70, pm.y - 70};
    sfSprite_setPosition(data->overview[2].spell_anim[0].s,
    data->overview[2].spell_anim[0].pos);
}

void exec_spell3(data_t *data)
{
    node_t *tmp = data->scenes[data->cur].list_ch;

    if (sfSound_getStatus(data->sfx.sfx[10].sound) != sfPlaying)
        sfSound_play(data->sfx.sfx[10].sound);
    while (tmp != NULL) {
        spell3_hit(data, tmp);
        tmp = tmp->next;
    }
    cost_mana_hero(data, data->hero.spell[3].stat.mana, DAMAGE);
    data->overview_activate[3] = 0;
    data->overview_activate_anim[3] = 1;
    data->overview[3].spell_anim[0].pos =
    (sfVector2f){data->window.size.x / 2 - 130, data->window.size.y / 2 - 150};
    sfSprite_setPosition(data->overview[3].spell_anim[0].s,
    data->overview[3].spell_anim[0].pos);
}