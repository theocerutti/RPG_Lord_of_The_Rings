/*
** EPITECH PROJECT, 2019
** get_info_stat_enemy
** File description:
** get_info_stat_enemy
*/

#include "my_rpg.h"

void set_overview_enemy_hud(game_object_t *overview, game_object_t *obj)
{
    overview->pos = (sfVector2f){58, 856};
    overview->offset = obj->offset;
    overview->width = obj->width;
    overview->height = obj->height;
    overview->rect = obj->rect;
    overview->t = sfTexture_copy(obj->t);
    sfSprite_setPosition(overview->s, overview->pos);
    sfSprite_setTexture(overview->s, overview->t, sfFalse);
    sfSprite_setTextureRect(overview->s, overview->rect);
}

void set_info_to_hud(scene_t *hud, character_t *ch)
{
    sfText_setColor(hud->txt[11].txt, sfGreen);
    sfText_setString(hud->txt[11].txt, "Live");
    sfText_setString(hud->txt[16].txt, my_itoa(ch->stat.speed));
    sfText_setString(hud->txt[17].txt, my_itoa(ch->stat.gold));
    sfText_setString(hud->txt[18].txt, ch->stat.describe);
    sfText_setString(hud->txt[19].txt, ch->stat.name);
    sfText_setString(hud->txt[20].txt, my_itoa(ch->stat.xp));
    sfText_setString(hud->txt[12].txt, my_itoa(ch->stat.level));
    sfText_setString(hud->txt[13].txt, big_strcat(3, my_itoa(ch->stat.life),
    " / ", my_itoa(ch->stat.max_life)));
    sfText_setString(hud->txt[14].txt, my_itoa(ch->stat.attack));
    sfText_setString(hud->txt[15].txt, my_itoa(ch->stat.defense));
    set_overview_enemy_hud(&hud->objs[7], &ch->obj);
}

void reset_state_hud_enemy(list_t *list, sfColor normal_color)
{
    node_t *tmp = *list;

    while (tmp != NULL) {
        tmp->ch.is_clicked_hud = FALSE;
        sfSprite_setColor(tmp->ch.obj.s, normal_color);
        tmp = tmp->next;
    }
}

void get_info_enemy_hud(data_t *d, sfEvent *event)
{
    sfVector2i pm = sfMouse_getPositionRenderWindow(d->window.w);
    sfColor c_normal = {255, 255, 255, 255};
    sfColor c_clicked = {220, 20, 60, 150};
    node_t *tmp = d->scenes[d->cur].list_ch;

    if (d->cur >= LVL_1_F && d->cur <= LVL_3_C && event->type ==
    sfEvtMouseButtonReleased && event->mouseButton.button == sfMouseLeft) {
        while (tmp != NULL) {
            if (is_point_collide(&tmp->ch.obj, pm.x, pm.y)) {
                reset_state_hud_enemy(&d->scenes[d->cur].list_ch, c_normal);
                set_info_to_hud(&d->scenes[HUD], &tmp->ch);
                tmp->ch.is_clicked_hud = TRUE;
                sfSprite_setColor(tmp->ch.obj.s, c_clicked);
            }
            tmp = tmp->next;
        }
    }
}