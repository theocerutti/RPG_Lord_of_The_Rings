/*
** EPITECH PROJECT, 2019
** hero_level_up
** File description:
** hero_level_up
*/

#include "my_rpg.h"

float next_attack_level(int level)
{
    return (round(0.00001 * pow(level, 3) + 0.03 * pow(level, 2) + 1 * level));
}

float next_regen_hp_level(int level)
{
    return (round(0.00002 * pow(level, 3) + 0.004 * pow(level, 2) + 0.08 *
    level));
}

float next_regen_mana_level(int level)
{
    return (round(0.00001 * pow(level, 3) + 0.001 * pow(level, 2) + 0.08 *
    level));
}

float next_defense_level(int level)
{
    return (round(0.0001 * pow(level, 3) + 0.05 * pow(level, 2) + 1 * level));
}

float next_max_life_level(int level)
{
    return (round(0.0001 * pow(level, 3) + 0.1 * pow(level, 2) + 1 * level));
}
