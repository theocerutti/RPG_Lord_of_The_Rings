/*
** EPITECH PROJECT, 2019
** display_intro
** File description:
** display_intro
*/

#include "my_rpg.h"

txt_t set_txt(txt_t txt, int x, int y, int size)
{
    txt.color = sfWhite;
    txt.font = 0;
    txt.txt = 0;
    txt.pos.x = x;
    txt.pos.y = y;
    txt.size = size;
    return (txt);
}

void init_txt_intro2(intro_t *ni)
{
    ni->txt[0] = set_txt(ni->txt[0], 360, 890, 70);
    ni->txt[1] = set_txt(ni->txt[1], 670, 940, 70);
    ni->txt[2] = set_txt(ni->txt[2], 320, 810, 70);
    ni->txt[3] = set_txt(ni->txt[3], 280, 880, 70);
    ni->txt[4] = set_txt(ni->txt[4], 160, 710, 70);
    ni->txt[5] = set_txt(ni->txt[5], 150, 730, 70);
}

intro_t init_txt_intro(intro_t ni, char *str)
{
    init_txt_intro2(&ni);
    init_txt_simple(&ni.txt[0], str,
    "The last Battle for Middle Earth is finished.\n\
    \t\tSauron has been defeated.");
    init_txt_simple(&ni.txt[1], str, "Aragorn is now King.");
    init_txt_simple(&ni.txt[2], str,
    "But some of Sauron's Henchman are still alive\n \t\t\
    and took back Dol Guldur...\n\t\
    \t\t You are one of them.");
    ni = init_txt_intro_2(ni, str);
    return (ni);
}

char **get_pictures(void)
{
    char **name = malloc(sizeof(char *) * 7);

    name[0] = "assets/intro/1.jpg";
    name[1] = "assets/intro/2.jpg";
    name[2] = "assets/intro/3.jpg";
    name[3] = "assets/intro/4.jpg";
    name[4] = "assets/intro/5.jpg";
    name[5] = "assets/intro/6.jpg";
    return (name);
}

void game_intro(sfRenderWindow *w)
{
    intro_t ni = {0, 0, malloc(sizeof(sfSprite *) * 6), {0, 0, 0, 0}, {1, 1},
    {0, {0}, 0}, {0, {0}, 0}, {0, {0}, 0}, malloc(sizeof(txt_t) * 6)};
    sfTexture **tsp = malloc(sizeof(sfTexture *) * 6);
    char **name = get_pictures();
    txt_t txt = {0, 0, {1550, 25}, sfWhite, 30};
    txt_t tx = {0, 0, {10, 1020}, sfWhite, 30};
    char *str = get_str_arrows();

    init_txt_simple(&tx, "assets/fonts/serif.ttf", str);
    ni = init_txt_intro(ni, "assets/fonts/serif.ttf");
    init_clock(&ni.cl);
    init_clock(&ni.next);
    init_clock(&ni.prev);
    for (int i = 0; i < 6; i++) {
        ni.intro[i] = sfSprite_create();
        tsp[i] = sfTexture_createFromFile(name[i], NULL);
        sfSprite_setTexture(ni.intro[i], tsp[i], sfTrue);
    }
    game_intro2(w, ni, txt, tx);
}