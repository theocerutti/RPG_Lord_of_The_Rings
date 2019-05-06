/*
** EPITECH PROJECT, 2019
** init_hud
** File description:
** init_hud
*/

#include "my_rpg.h"

void init_txt_hud5(data_t *data)
{
    sfColor color_yellow = sfColor_fromRGB(227, 158, 21);
    char const *f = "assets/fonts/bebas.ttf";
    txt_t speed_txt = {0, 0, {233, 899}, color_yellow, 15};
    txt_t gold_drop_txt = {0, 0, {266, 917}, color_yellow, 15};
    txt_t xp_drop_txt = {0, 0, {248, 935}, color_yellow, 15};
    txt_t describe_txt = {0, 0, {37, 991}, color_yellow, 15};
    txt_t name_txt = {0, 0, {67, 937}, color_yellow, 15};

    init_txt_simple(&speed_txt, f, "0");
    init_txt_simple(&gold_drop_txt, f, "0");
    init_txt_simple(&describe_txt, f, "Not found");
    init_txt_simple(&name_txt, f, "Not found");
    init_txt_simple(&xp_drop_txt, f, "0");
    data->scenes[HUD].txt[16] = speed_txt;
    data->scenes[HUD].txt[17] = gold_drop_txt;
    data->scenes[HUD].txt[18] = describe_txt;
    data->scenes[HUD].txt[19] = name_txt;
    data->scenes[HUD].txt[20] = xp_drop_txt;
}

void init_txt_hud4(data_t *data)
{
    sfColor color_yellow = sfColor_fromRGB(227, 158, 21);
    txt_t life_or_die = {0, 0, {66, 819}, (sfColor){49, 165, 41, 255}, 15};
    char const *f = "assets/fonts/bebas.ttf";
    txt_t lvl_txt = {0, 0, {235, 822}, color_yellow, 15};
    txt_t life_txt = {0, 0, {220, 841}, color_yellow, 15};
    txt_t attack_txt = {0, 0, {248, 858}, color_yellow, 15};
    txt_t defense_txt = {0, 0, {251, 880}, color_yellow, 15};

    init_txt_simple(&life_or_die, f, "Not found");
    init_txt_simple(&lvl_txt, f, "0");
    init_txt_simple(&life_txt, f, "0");
    init_txt_simple(&attack_txt, f, "0");
    init_txt_simple(&defense_txt, f, "0");
    data->scenes[HUD].txt[11] = life_or_die;
    data->scenes[HUD].txt[12] = lvl_txt;
    data->scenes[HUD].txt[13] = life_txt;
    data->scenes[HUD].txt[14] = attack_txt;
    data->scenes[HUD].txt[15] = defense_txt;
    init_txt_hud5(data);
}

void init_txt_hud3(data_t *data)
{
    sfColor color_spell_mana_cost = sfColor_fromRGB(65, 105, 225);
    char const *str_font = "assets/fonts/bebas.ttf";
    txt_t txt_spell0 = {0, 0, {670, 1060}, color_spell_mana_cost, 15};
    txt_t txt_spell1 = {0, 0, {733, 1060}, color_spell_mana_cost, 15};
    txt_t txt_spell2 = {0, 0, {801, 1060}, color_spell_mana_cost, 15};
    txt_t txt_spell3 = {0, 0, {868, 1060}, color_spell_mana_cost, 15};

    init_txt_simple(&txt_spell0, str_font,
    my_itoa(data->hero.spell[0].stat.mana));
    init_txt_simple(&txt_spell1, str_font,
    my_itoa(data->hero.spell[1].stat.mana));
    init_txt_simple(&txt_spell2, str_font,
    my_itoa(data->hero.spell[2].stat.mana));
    init_txt_simple(&txt_spell3, str_font,
    my_itoa(data->hero.spell[3].stat.mana));
    data->scenes[HUD].txt[7] = txt_spell0;
    data->scenes[HUD].txt[8] = txt_spell1;
    data->scenes[HUD].txt[9] = txt_spell2;
    data->scenes[HUD].txt[10] = txt_spell3;
    init_txt_hud4(data);
}