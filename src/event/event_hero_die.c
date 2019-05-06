/*
** EPITECH PROJECT, 2019
** event_die_hero
** File description:
** event_die_hero
*/

#include "my_rpg.h"

void check_die_hero(data_t *d)
{
    int pourcent = 0;
    int gold_lose = 0;

    if (d->hero.stat.life <= 0) {
        gold_lose = loose_gold_from_scene(d->cur, d->hero.stat.gold, &pourcent);
        sfText_setString(d->scenes[DIE].txt[1].txt, big_strcat(3, "You had ",
        my_itoa(d->hero.stat.gold), " golds."));
        sfText_setString(d->scenes[DIE].txt[2].txt, big_strcat(3, "You lose ",
        my_itoa(gold_lose), " golds for dying."));
        sfText_setString(d->scenes[DIE].txt[3].txt, big_strcat(5, "Total: ",
        my_itoa(d->hero.stat.gold - gold_lose), " golds (-",
        my_itoa(pourcent), "%)"));
        d->hero.stat.gold -= gold_lose;
        sfText_setString(d->scenes[HUD].txt[6].txt,
        my_itoa(d->hero.stat.gold));
        d->pre_cur = d->cur;
        d->cur = DIE;
        cost_life_hero(d, d->hero.stat.max_life, HEAL);
        cost_mana_hero(d, d->hero.stat.max_mana, HEAL);
    }
}