/*
** EPITECH PROJECT, 2019
** hero_level_up
** File description:
** hero_level_up
*/

#include "my_rpg.h"

float next_max_mana_level(int level)
{
    return (round(0.001 * pow(level, 3) + 0.1 * pow(level, 2) + 1 * level));
}

float next_max_xp_level(int level)
{
    return (round(0.1 * pow(level, 3) + 1 * pow(level, 2) + 6 * level));
}

void upgrade_hero_attributes(spell_t *spell, stat_t *stat, float *xp_width,
game_object_t *xp_bar)
{
    float diff_xp = 0;

    diff_xp = stat->xp - stat->max_xp;
    stat->xp = diff_xp;
    stat->level += 1;
    stat->max_xp += next_max_xp_level(stat->level);
    stat->attack += next_attack_level(stat->level);
    stat->defense += next_defense_level(stat->level);
    stat->max_life += next_max_life_level(stat->level);
    stat->max_mana += next_max_mana_level(stat->level);
    stat->regen_life += next_regen_hp_level(stat->level);
    stat->regen_mana += next_regen_mana_level(stat->level);
    *xp_width = (diff_xp * xp_bar->width) / stat->max_xp;
    xp_bar->rect.width = *xp_width;
    spell[0].stat.attack = stat->attack * 2;
    spell[1].stat.attack = stat->attack / 2;
    spell[2].stat.attack = stat->attack * 3;
    spell[3].stat.attack = stat->attack * 4;
}