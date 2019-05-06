/*
** EPITECH PROJECT, 2019
** init bosses
** File description:
** rpg bosses
*/

#include "my_rpg.h"

void set_character(character_t boss[3])
{
    char sprite[3][41] = {"assets/images/character/bosses/boss1.png\0", \
    "assets/images/character/bosses/boss2.png\0", \
    "assets/images/character/bosses/boss3.png\0"};

    for (int i = 0, ring = 14; i < 3; i++, ring += 5) {
        init_clock(&boss[i].clock);
        init_bar_character(&boss[i]);
        boss[i].inventory.bag[0][0] = ring;
        init_game_object(&boss[i].obj, sprite[i]);
    }
}

character_t get_char_boss(int index)
{
    character_t boss[3] = {{{}, {}, {0, "Legolas", "The best bowman", 10, 1, 1,
    15, 70, 600, 600, 100, 100, 300, 300, 0, 1000, 220}, {461, 799, {2, 2}, {84,
    84}, {0, 0}, {6410, -3088}, 0, 0, {0}, {0, {0}, 0}, BOSS_ID}, {{67, 6, {1,
    1}, {67, 12}, {0, 0}, {-1, -1}, 0, 0, {0}, {0, {0}, 0}, MISCELLANEOUS_ID},
    {0, 0, {0, 0}, sfYellow, 12}, {0, 0, {0, 0}, sfYellow, 10}, 0, 0, 0}, 0, 0,
    {0, {0}, 0}}, {{}, {}, {0, "Gimlie", "A powerful dwarf", 20, 1, 1, 60, 100,
    2000, 2000, 100, 100, 600, 600, 0, 5000, 220}, {461, 799, {2, 2}, {84, 84},
    {0, 0}, {8100, -390}, 0, 0, {0}, {0, {0}, 0}, BOSS_ID}, {{67, 6, {1, 1},
    {67, 12}, {0, 0}, {-1, -1}, 0, 0, {0}, {0, {0}, 0}, MISCELLANEOUS_ID},
    {0, 0, {0, 0}, sfYellow, 12}, {0, 0, {0, 0}, sfYellow, 10}, 0, 0, 0},
    0, 0, {0, {0}, 0}}, {{}, {}, {0, "Aragorn", "The actual king", 50, 1, 1,
    170, 120, 10000, 10000, 100, 100, 4000, 4000, 0, 10000, 220}, {461, 799, {2,
    2}, {84, 84}, {0, 0}, {6950, 20}, 0, 0, {0}, {0, {0}, 0}, BOSS_ID}, {{67, 6,
    {1, 1}, {67, 12}, {0, 0}, {-1, -1}, 0, 0, {0}, {0, {0}, 0},
    MISCELLANEOUS_ID}, {0, 0, {0, 0}, sfYellow, 12}, {0, 0, {0, 0},
    sfYellow, 10}, 0, 0, 0}, 0, 0, {0, {0}, 0}}};

    set_character(boss);
    return (boss[index]);
}

boss_t get_bosses_data(void)
{
    boss_t bosses;

    for (int i = 0, cur = LVL_1_C; i < 3; i++, cur += 2) {
        bosses.cur_boss[i] = cur;
        bosses.boss_ch[i] = get_char_boss(i);
    }
    bosses.boss = 0;
    return (bosses);
}

void init_all_bosses(data_t *data)
{
    data->boss = get_bosses_data();
    push(&data->scenes[LVL_1_C].list_ch, data->boss.boss_ch[0]);
    push(&data->scenes[LVL_2_C].list_ch, data->boss.boss_ch[1]);
    push(&data->scenes[LVL_3_C].list_ch, data->boss.boss_ch[2]);
}