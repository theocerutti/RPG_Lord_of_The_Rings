/*
** EPITECH PROJECT, 2019
** init_basic_enemy
** File description:
** init_basic_enemy
*/

#include "my_rpg.h"

char *get_real_describe(char *s)
{
    int i = 0;
    char *s2 = malloc(sizeof(char) * (my_strlen(s) + 1));

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '_') {
            s2[i] = ' ';
        } else if (s[i] == '|') {
            s2[i] = '\n';
        } else {
            s2[i] = s[i];
        }
    }
    s2[i] = '\0';
    return (s2);
}

int get_level_enemy_according_to_scene(int scene_id)
{
    switch (scene_id) {
        case LVL_1_F: return (1);
        case LVL_1_C: return (myrand(1, 10));
        case LVL_2_F: return (myrand(10, 20));
        case LVL_2_C: return (myrand(20, 30));
        case LVL_3_F: return (myrand(30, 40));
        default: return (myrand(40, 50));
    }
}

void set_stat_according_to_level(stat_t *stat, int p)
{
    stat->attack += round(0.001 * (pow(p, 3)) + 0.023 * (pow(p, 2)) +
    0.02 * p);
    stat->defense += round(0.001 * (pow(p, 3)) + 0.02 * (pow(p, 2)) +
    0.02 * p);
    stat->speed += round(0.0005 * (pow(p, 3)) + 0.00001 * (pow(p, 2)) + 0.0002 *
    p);
    stat->life += round(0.033 * (pow(p, 3)) + 0.1 * (pow(p, 2)) + 0.2 * p);
    stat->mana += round(0.01 * (pow(p, 3)) + 0.1 * (pow(p, 2)) + 0.2 * p);
    stat->xp += round(0.01 * (pow(p, 3)) + 0.1 * (pow(p, 2)) + 0.2 * p);
    stat->gold += round(0.00006 * (pow(p, 3)) + 0.0001 * (pow(p, 2)) +
    0.0001 * p);
}

char **get_raw_stat_enemy_id(int id_monster)
{
    FILE *fd = fopen("assets/data/stat_enemy", "r");
    size_t n = 0;
    int ret = 0;
    char *line = 0;

    for (int i = 0; i <= id_monster + 1; i++)
        ret = getline(&line, &n, fd);
    if (line[my_strlen(line) - 1] == '\n')
        line[my_strlen(line) - 1] = '\0';
    (void)ret;
    return (my_str_to_word_array(line));
}

stat_t get_stat_enemy(int id_monster, int scene_id)
{
    char **raw_stat = get_raw_stat_enemy_id(id_monster);
    stat_t stat = {
        .type = 0, .regen_life = 0, .regen_mana = 0, .max_xp = 0,
        .max_mana = 0, .max_life = 0, .level = 0, .value = 0, .mana = 0,
        .name = get_real_describe(raw_stat[0]),
        .describe = get_real_describe(raw_stat[1]),
        .attack = my_atoi(raw_stat[2]),
        .defense = my_atoi(raw_stat[3]),
        .life = my_atoi(raw_stat[4]),
        .xp = my_atoi(raw_stat[5]),
        .gold = my_atoi(raw_stat[6]),
        .speed = my_atoi(raw_stat[7])
    };

    stat.level = get_level_enemy_according_to_scene(scene_id);
    set_stat_according_to_level(&stat, stat.level);
    stat.max_life = stat.life;
    stat.max_mana = stat.mana;
    return (stat);
}