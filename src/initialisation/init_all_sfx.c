/*
** EPITECH PROJECT, 2019
** init_all_sfx
** File description:
** init_all_sfx
*/

#include "my_rpg.h"

void init_music(game_sfx_t *sfx)
{
    sfx_t game_music = {MUSIC, 100, 0, 0, 0};
    sfx_t main_music = {MUSIC, 100, 0, 0, 0};

    init_sfx(&game_music, "assets/music/game_theme.ogg");
    init_sfx(&main_music, "assets/music/main_menu_theme.ogg");
    sfx->sfx[0] = game_music;
    sfx->sfx[1] = main_music;
}

void init_sound3(game_sfx_t *sfx)
{
    sfx_t level_up = {SOUND, 100, 0, 0, 0};
    sfx_t sell_buy_item = {SOUND, 100, 0, 0, 0};
    sfx_t spell_3 = {SOUND, 100, 0, 0, 0};

    init_sfx(&level_up, "assets/sound/level_up.ogg");
    init_sfx(&sell_buy_item, "assets/sound/sell_buy_item.ogg");
    init_sfx(&spell_3, "assets/sound/spell3.ogg");
    sfx->sfx[7] = level_up;
    sfx->sfx[8] = sell_buy_item;
    sfx->sfx[9] = spell_3;
}

void init_sound2(game_sfx_t *sfx)
{
    sfx_t spell_4 = {SOUND, 100, 0, 0, 0};
    sfx_t mana_potion = {SOUND, 100, 0, 0, 0};
    sfx_t open_inventory = {SOUND, 100, 0, 0, 0};
    sfx_t turn_page = {SOUND, 100, 0, 0, 0};
    sfx_t click = {SOUND, 100, 0, 0, 0};
    sfx_t hover = {SOUND, 100, 0, 0, 0};

    init_sfx(&spell_4, "assets/sound/spell4.ogg");
    init_sfx(&mana_potion, "assets/sound/mana_potion.ogg");
    init_sfx(&open_inventory, "assets/sound/open_inventory.ogg");
    init_sfx(&turn_page, "assets/sound/turn_page.ogg");
    init_sfx(&click, "assets/sound/click_button.ogg");
    init_sfx(&hover, "assets/sound/hover_button.ogg");
    sfx->sfx[10] = spell_4;
    sfx->sfx[11] = mana_potion;
    sfx->sfx[12] = open_inventory;
    sfx->sfx[13] = turn_page;
    sfx->sfx[14] = click;
    sfx->sfx[15] = hover;
}

void init_sound(game_sfx_t *sfx)
{
    sfx_t attack1 = {SOUND, 100, 0, 0, 0};
    sfx_t spell1_2 = {SOUND, 100, 0, 0, 0};
    sfx_t footstep = {SOUND, 100, 0, 0, 0};
    sfx_t health_potion = {SOUND, 100, 0, 0, 0};
    sfx_t ring_inventory = {SOUND, 100, 0, 0, 0};

    init_sfx(&attack1, "assets/sound/attack1.ogg");
    init_sfx(&spell1_2, "assets/sound/spell1_2.ogg");
    init_sfx(&footstep, "assets/sound/footstep.ogg");
    init_sfx(&health_potion, "assets/sound/health_potion.ogg");
    init_sfx(&ring_inventory, "assets/sound/ring_inventory.ogg");
    sfx->sfx[2] = attack1;
    sfx->sfx[3] = spell1_2;
    sfx->sfx[4] = footstep;
    sfx->sfx[5] = health_potion;
    sfx->sfx[6] = ring_inventory;
}

void init_all_sfx(game_sfx_t *sfx)
{
    sfx->nb_sfx = 20;
    sfx->sfx = malloc(sizeof(sfx_t) * sfx->nb_sfx);
    init_music(sfx);
    init_sound(sfx);
    init_sound2(sfx);
    init_sound3(sfx);
    init_sound4(sfx);
}