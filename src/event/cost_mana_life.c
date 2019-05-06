/*
** EPITECH PROJECT, 2019
** mana_life
** File description:
** mana_life
*/

#include "my_rpg.h"

void recalc_raw_damage(character_t *ch, float *raw_damage)
{
    *raw_damage *= 100.0 / (100.0 + ch->stat.defense);
    if (-*raw_damage <= 0)
        *raw_damage = 0;
}

float calc_pourcentage(float cost, float width, float max)
{
    return ((cost * width) / max);
}

void cost_life_little_bar(character_t *ch, float cost, int type)
{
    cost = (type == HEAL) ? cost : -cost;
    if (type == DAMAGE)
        recalc_raw_damage(ch, &cost);
    ch->stat.life += cost;
    if (ch->stat.life <= 0) {
        ch->stat.life = 0;
        ch->bar.life_width = ch->stat.max_life;
    } else if (ch->stat.life >= ch->stat.max_life) {
        ch->stat.life = ch->stat.max_life;
        ch->bar.life_width = 0;
    } else {
        ch->bar.life_width +=
        calc_pourcentage(-cost, ch->bar.life_bar.width, ch->stat.max_life);
    }
    ch->bar.life_bar.rect.left = ch->bar.life_width;
    sfSprite_setTextureRect(ch->bar.life_bar.s, ch->bar.life_bar.rect);
}

void cost_life_hero(data_t *d, float cost, int type)
{
    cost_life_little_bar(&d->hero, cost, type);
    cost = (type == HEAL) ? cost : -cost;
    if (type == DAMAGE)
        recalc_raw_damage(&d->hero, &cost);
    if (d->hero.stat.life <= 0) {
        d->scenes[HUD].objs[2].pos.y = 1070;
    } else if (d->hero.stat.life >= d->hero.stat.max_life) {
        d->hero.stat.life = d->hero.stat.max_life;
        d->scenes[HUD].objs[2].pos.y = 915;
    } else
        d->scenes[HUD].objs[2].pos.y += calc_pourcentage(-cost,
        d->scenes[HUD].objs[2].height, d->hero.stat.max_life);
    sfSprite_setPosition(d->scenes[HUD].objs[2].s, d->scenes[HUD].objs[2].pos);
    sfText_setString(d->scenes[HUD].txt[0].txt, big_strcat(3,
    my_itoa(d->hero.stat.life), " / ", my_itoa(d->hero.stat.max_life)));
    sfText_setString(d->scenes[HUD].txt[3].txt, big_strcat(3,
    "(+", my_itoa(d->hero.stat.regen_life), " / sec)"));
}

void cost_mana_hero(data_t *d, float cost, int type)
{
    cost = (type == HEAL) ? cost : -cost;
    d->hero.stat.mana += cost;
    if (d->hero.stat.mana <= 0) {
        d->hero.stat.mana = 0;
        d->scenes[HUD].objs[3].pos.y = 1070;
    } else if (d->hero.stat.mana >= d->hero.stat.max_mana) {
        d->hero.stat.mana = d->hero.stat.max_mana;
        d->scenes[HUD].objs[3].pos.y = 915;
    }
    if (d->hero.stat.mana < d->hero.stat.max_mana && d->hero.stat.mana > 0)
        d->scenes[HUD].objs[3].pos.y += calc_pourcentage(-cost,
        d->scenes[HUD].objs[3].height, d->hero.stat.max_mana);
    sfSprite_setPosition(d->scenes[HUD].objs[3].s, d->scenes[HUD].objs[3].pos);
    sfText_setString(d->scenes[HUD].txt[1].txt, big_strcat(3,
    my_itoa(d->hero.stat.mana), " / ", my_itoa(d->hero.stat.max_mana)));
    sfText_setString(d->scenes[HUD].txt[4].txt, big_strcat(3,
    "(+", my_itoa(d->hero.stat.regen_mana), " / sec)"));
}