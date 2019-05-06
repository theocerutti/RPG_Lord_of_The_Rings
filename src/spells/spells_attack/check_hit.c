/*
** EPITECH PROJECT, 2019
** check if spells hit
** File description:
** rpg
*/

#include "my_rpg.h"

void spell0_hit(data_t *data, node_t *enem)
{
    sfVector2f pos = \
    sfRectangleShape_getPosition(data->overview[0].overview_r[0]);
    sfVector2f s = sfRectangleShape_getSize(data->overview[0].overview_r[0]);
    sfVector2f w_h = {enem->ch.obj.offset.x, enem->ch.obj.offset.y};

    if ((pos.x <= enem->ch.obj.pos.x && pos.y <= enem->ch.obj.pos.y && \
    pos.x + s.x >= enem->ch.obj.pos.x && \
    pos.y + s.y >= enem->ch.obj.pos.y) || \
    (pos.x <= enem->ch.obj.pos.x + w_h.x && pos.y <= enem->ch.obj.pos.y && \
    pos.x + s.x >= enem->ch.obj.pos.x + w_h.x && \
    pos.y + s.y >= enem->ch.obj.pos.y) || \
    (pos.x <= enem->ch.obj.pos.x && pos.y <= enem->ch.obj.pos.y + w_h.y && \
    pos.x + s.x >= enem->ch.obj.pos.x && \
    pos.y + s.y >= enem->ch.obj.pos.y + w_h.y) || \
    (pos.x <= enem->ch.obj.pos.x + w_h.x && pos.y <= enem->ch.obj.pos.y + w_h.y
    && pos.x + s.x >= enem->ch.obj.pos.x + w_h.x && \
    pos.y + s.y >= enem->ch.obj.pos.y + w_h.y)) {
        cost_life_little_bar(&enem->ch, \
        data->hero.spell[0].stat.attack, DAMAGE);
    }
}

void spell1_hit(data_t *data, node_t *enem)
{
    sfVector2f pos;
    sfVector2f size;
    sfVector2f w_h = {enem->ch.obj.offset.x, enem->ch.obj.offset.y};

    for (int i = 0; i < 4; i++) {
        pos = sfRectangleShape_getPosition(data->overview[1].overview_r[i]);
        size = sfRectangleShape_getSize(data->overview[1].overview_r[i]);
        if ((pos.x <= enem->ch.obj.pos.x && pos.y <= enem->ch.obj.pos.y && \
        pos.x + size.x >= enem->ch.obj.pos.x && pos.y + size.y >= \
        enem->ch.obj.pos.y) || (pos.x <= enem->ch.obj.pos.x + w_h.x && pos.y \
        <= enem->ch.obj.pos.y && pos.x + size.x >= enem->ch.obj.pos.x + w_h.x \
        && pos.y + size.y >= enem->ch.obj.pos.y) || (pos.x <= \
        enem->ch.obj.pos.x && pos.y <= enem->ch.obj.pos.y + w_h.y && pos.x + \
        size.x >= enem->ch.obj.pos.x && pos.y + size.y >= enem->ch.obj.pos.y \
        + w_h.y) || (pos.x <= enem->ch.obj.pos.x + w_h.x && pos.y <= \
        enem->ch.obj.pos.y + w_h.y && pos.x + size.x >= enem->ch.obj.pos.x + \
        w_h.x && pos.y + size.y >= enem->ch.obj.pos.y + w_h.y))
            cost_life_little_bar(&enem->ch, \
            data->hero.spell[1].stat.attack, DAMAGE);
    }
}

void spell2_hit(data_t *data, node_t *enem)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(data->window.w);
    sfVector2f w_h = {enem->ch.obj.offset.x, enem->ch.obj.offset.y};
    sfVector2f vector;
    sfVector2f use[4] = {{enem->ch.obj.pos.x - pos.x, enem->ch.obj.pos.y - \
    pos.y}, {enem->ch.obj.pos.x + w_h.x - pos.x, enem->ch.obj.pos.y - pos.y}, \
    {enem->ch.obj.pos.x + w_h.x - pos.x, enem->ch.obj.pos.y + w_h.y - pos.y}, \
    {enem->ch.obj.pos.x - pos.x, enem->ch.obj.pos.y + w_h.y - pos.y}};

    for (int i = 0; i < 4; i++) {
        vector.x = use[i].x;
        vector.y = use[i].y;
        if (sqrt(pow(vector.x, 2) + pow(vector.y, 2)) <= \
        data->overview[2].radius) {
            cost_life_little_bar(&enem->ch, \
            data->hero.spell[2].stat.attack, DAMAGE);
            return;
        }
    }
}

void spell3_hit(data_t *data, node_t *enem)
{
    sfVector2f pos = sfCircleShape_getPosition(data->overview[3].overview_c);
    sfVector2f w_h = {enem->ch.obj.offset.x, enem->ch.obj.offset.y};
    sfVector2f vector;
    sfVector2f use[4] = {{enem->ch.obj.pos.x - pos.x, enem->ch.obj.pos.y - \
    pos.y}, {enem->ch.obj.pos.x + w_h.x - pos.x, enem->ch.obj.pos.y - pos.y}, \
    {enem->ch.obj.pos.x + w_h.x - pos.x, enem->ch.obj.pos.y + w_h.y - pos.y}, \
    {enem->ch.obj.pos.x - pos.x, enem->ch.obj.pos.y + w_h.y - pos.y}};

    for (int i = 0; i < 4; i++) {
        vector.x = use[i].x;
        vector.y = use[i].y;
        if (sqrt(pow(vector.x, 2) + pow(vector.y, 2)) <= \
        data->overview[2].radius) {
            cost_life_little_bar(&enem->ch, \
            data->hero.spell[2].stat.attack, DAMAGE);
            return;
        }
    }
}