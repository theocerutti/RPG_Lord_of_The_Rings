/*
** EPITECH PROJECT, 2019
** event_attack_hero
** File description:
** event_hero_attack
*/

#include "my_rpg.h"

void check_hero_attack_enemy(data_t *d)
{
    node_t *tmp = d->scenes[d->cur].list_ch;

    while (tmp != NULL) {
        if (is_collide_simple(&d->hero.obj, &tmp->ch.obj) &&
        (tmp->ch.obj.id == ENEMY_ID || tmp->ch.obj.id == BOSS_ID)) {
            cost_life_little_bar(&tmp->ch, d->hero.stat.attack, DAMAGE);
            if (tmp->ch.is_clicked_hud) {
                sfText_setString(d->scenes[HUD].txt[13].txt,
                big_strcat(3, my_itoa(tmp->ch.stat.life), " / ",
                my_itoa(tmp->ch.stat.max_life)));
            }
        }
        tmp = tmp->next;
    }
}

void event_attack_hero(data_t *d)
{
    int id_sound = myrand(16, 19);
    sfVector2f p_tab_right[3] = {{1920, 0}, {1920, 1080}, d->hero.obj.pos};
    sfVector2f p_tab_left[3] = {{0, 0}, {0, 1080}, d->hero.obj.pos};
    sfVector2f p_tab_bot[3] = {{0, 1080}, {1920, 1080}, d->hero.obj.pos};
    sfVector2f p_tab_top[3] = {{0, 0}, {1920, 0}, d->hero.obj.pos};
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(d->window.w);

    if (sfSound_getStatus(d->sfx.sfx[id_sound].sound) != sfPlaying)
        sfSound_play(d->sfx.sfx[id_sound].sound);
    d->hero.obj.rect.left = 0;
    if (collide_triangle(p_tab_left, pos_mouse))
        d->hero.obj.rect.top = 84 * 6;
    if (collide_triangle(p_tab_right, pos_mouse))
        d->hero.obj.rect.top = 84 * 7;
    if (collide_triangle(p_tab_top, pos_mouse))
        d->hero.obj.rect.top = 84 * 5;
    if (collide_triangle(p_tab_bot, pos_mouse))
        d->hero.obj.rect.top = 84 * 8;
    check_hero_attack_enemy(d);
}