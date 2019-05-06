/*
** EPITECH PROJECT, 2019
** event_enemies
** File description:
** event_enemies
*/

#include "my_rpg.h"

int is_colliding(list_t *l_enemies, game_object_t *ref, int i)
{
    node_t *tmp = *l_enemies;

    for (int j = 0; tmp != NULL; j++) {
        if (j != i && tmp->ch.obj.id == ENEMY_ID) {
            if (is_collide_bottom(ref, &tmp->ch.obj))
                ref->pos.y -= 2;
            if (is_collide_top(ref, &tmp->ch.obj))
                ref->pos.y += 2;
            if (is_collide_left(ref, &tmp->ch.obj))
                ref->pos.x += 2;
            if (is_collide_right(ref, &tmp->ch.obj))
                ref->pos.x -= 2;
        }
        tmp = tmp->next;
    }
    return (0);
}

void chase_enemies_to_hero(data_t *d, character_t *ch, int i)
{
    float dist = 0;
    sfVector2f p = {0, 0};

    p.x = ch->obj.pos.x - d->hero.obj.pos.x;
    p.y = ch->obj.pos.y - d->hero.obj.pos.y;
    dist = hypot(p.x, p.y);
    if (dist != 0 && !is_colliding(&d->scenes[d->cur].list_ch,
    &ch->obj, i)) {
        p.x /= dist;
        p.y /= dist;
        ch->obj.pos.x -= p.x * ch->stat.speed * d->delta_time.s;
        ch->obj.pos.y -= p.y * ch->stat.speed * d->delta_time.s;
        sfSprite_setPosition(ch->obj.s, ch->obj.pos);
    }
}

void chase_enemies_hero_current_scene(data_t *d, int effect)
{
    int save_effect = effect;
    node_t *tmp = d->scenes[d->cur].list_ch;

    for (int i = 0; tmp != NULL; i++, tmp = tmp->next) {
        effect = (tmp->ch.obj.id == BOSS_ID) ? 1200 : save_effect;
        if ((tmp->ch.obj.id == ENEMY_ID || tmp->ch.obj.id == BOSS_ID) &&
        (effect == -1 || is_near(&d->hero.obj, &tmp->ch.obj, effect))) {
            chase_enemies_to_hero(d, &tmp->ch, i);
        }
    }
}

void chase_victim(game_object_t *victim, game_object_t *chaser,
int magnet_area)
{
    float dx = 0;
    float dy = 0;
    float dist = 0;

    if (magnet_area == -1 || is_near(victim, chaser, magnet_area)) {
        dx = chaser->pos.x - victim->pos.x;
        dy = chaser->pos.y - victim->pos.y;
        dist = hypot(dx, dy);
        if (dist != 0) {
            dx = dx / dist;
            dy = dy / dist;
            chaser->pos.x -= dx * victim->v.x;
            chaser->pos.y -= dy * victim->v.y;
            sfSprite_setPosition(chaser->s, chaser->pos);
        }
    }
}