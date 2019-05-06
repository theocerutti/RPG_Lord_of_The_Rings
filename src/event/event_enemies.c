/*
** EPITECH PROJECT, 2019
** event_enemies
** File description:
** event_enemies
*/

#include "my_rpg.h"

void check_enemy_attack_hero(data_t *d)
{
    node_t *tmp = d->scenes[d->cur].list_ch;

    while (tmp != NULL) {
        if (is_point_collide(&tmp->ch.obj, d->hero.obj.pos.x + 36,
        d->hero.obj.pos.y + 44)) {
            cost_life_hero(d, tmp->ch.stat.attack, DAMAGE);
        }
        tmp = tmp->next;
    }
}

void check_die_enemy(data_t *data)
{
    node_t *tmp = NULL;

    tmp = data->scenes[data->cur].list_ch;
    for (int i = 0; tmp != NULL; i++) {
        if (tmp->ch.stat.life <= 0) {
            if (tmp->ch.obj.id == BOSS_ID)
                get_the_ring(data, tmp->ch);
            get_drop_item(data, tmp->ch);
            sfText_setColor(data->scenes[HUD].txt[11].txt, sfRed);
            sfText_setString(data->scenes[HUD].txt[11].txt, "DIED");
            add_xp_hero(data, tmp->ch.stat.xp);
            cost_gold_hero(data, tmp->ch.stat.gold);
            pop_index(&data->scenes[data->cur].list_ch, i);
            tmp = data->scenes[data->cur].list_ch;
            for (int j = 0; j < i; j++)
                tmp = tmp->next;
            i -= 1;
        } else
            tmp = tmp->next;
    }
}

void turn_enemies_to_hero(data_t *data)
{
    node_t *tmp = data->scenes[data->cur].list_ch;
    game_object_t *enemy;

    while (tmp != NULL) {
        enemy = &tmp->ch.obj;
        if (enemy->pos.x >= 800 && enemy->pos.x <= 1120 &&
        enemy->pos.y <= 540)
            enemy->rect.top = 0;
        if (enemy->pos.x >= 800 && enemy->pos.x <= 1120 &&
        enemy->pos.y >= 540)
            enemy->rect.top = enemy->offset.y * 3;
        if (enemy->pos.x < 800)
            enemy->rect.top = enemy->offset.y * 2;
        if (enemy->pos.x > 1120)
            enemy->rect.top = enemy->offset.y;
        sfSprite_setTextureRect(enemy->s, enemy->rect);
        tmp = tmp->next;
    }
}

void all_event_enemies(data_t *data)
{
    node_t *tmp = data->scenes[data->cur].list_ch;

    while (tmp != NULL) {
        anim_obj_simple(&tmp->ch.obj, 0.1);
        tmp = tmp->next;
    }
    chase_enemies_hero_current_scene(data, -1);
    check_die_enemy(data);
    data->action_tick.time = sfClock_getElapsedTime(data->action_tick.clock);
    data->action_tick.s = data->action_tick.time.microseconds / 1000000.0;
    if (data->action_tick.s > 0.5) {
        turn_enemies_to_hero(data);
        check_enemy_attack_hero(data);
        sfClock_restart(data->action_tick.clock);
    }
}