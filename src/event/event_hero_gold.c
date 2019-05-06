/*
** EPITECH PROJECT, 2019
** gold
** File description:
** gold
*/

#include "my_rpg.h"

void cost_gold_hero(data_t *d, float gold_amount)
{
    d->hero.stat.gold += gold_amount;
    if (d->hero.stat.gold < 0)
        d->hero.stat.gold = 0;
    sfText_setString(d->scenes[HUD].txt[6].txt, my_itoa(d->hero.stat.gold));
}

int loose_gold_from_scene(int scene_id, int total_gold_hero, int *pourcent)
{
    switch (scene_id) {
        case LVL_1_F:
            *pourcent = myrand(0, 0);
            return (total_gold_hero * *pourcent / 100);
        case LVL_1_C:
            *pourcent = myrand(5, 20);
            return (total_gold_hero * *pourcent / 100);
        case LVL_2_F:
            *pourcent = myrand(15, 30);
            return (total_gold_hero * *pourcent / 100);
        case LVL_2_C:
            *pourcent = myrand(25, 40);
            return (total_gold_hero * *pourcent / 100);
        case LVL_3_F:
            *pourcent = myrand(35, 50);
            return (total_gold_hero * *pourcent / 100);
        default:
            *pourcent = myrand(45, 60);
            return (total_gold_hero * *pourcent / 100);
    }
}