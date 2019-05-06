/*
** EPITECH PROJECT, 2019
** display_intro2
** File description:
** display_intro2
*/

#include "my_rpg.h"

int change_pic(intro_t *ni, sfRenderWindow *w)
{
    if (ni->cl.s > 10) {
        if (ni->tour == 6)
            return (1);
        ni->s = (sfVector2f){1, 1};
        sfRenderWindow_clear(w, sfBlack);
        sfClock_restart(ni->cl.clock);
        ni->color = sfSprite_getColor(ni->intro[ni->tour]);
        ni->color.a = 0;
        ni->tour += 1;
    }
    if (ni->tour != 1) {
        sfRenderWindow_clear(w, sfBlack);
        ni->color.a = ni->trans;
        sfSprite_setColor(ni->intro[ni->tour - 1], ni->color);
        sfText_setColor(ni->txt[ni->tour - 1].txt, ni->color);
        sfSprite_setScale(ni->intro[ni->tour - 1], ni->s);
        sfRenderWindow_drawSprite(w, ni->intro[ni->tour - 1], NULL);
        sfRenderWindow_drawText(w, ni->txt[ni->tour - 1].txt, NULL);
    }
    return (0);
}

void manage_transparence(intro_t *ni)
{
    ni->cl.time = sfClock_getElapsedTime(ni->cl.clock);
    ni->cl.s = ni->cl.time.microseconds / 1000000.0;
    if (ni->cl.s < 2.5) {
        if (ni->trans < 253)
            ni->trans += 2;
        else
            ni->trans = 255;
    } else if (ni->cl.s > 8 && ni->trans >= 0)
        ni->trans -= 2;
    else {
        if (ni->cl.s >= 2.5 && ni->cl.s <= 8)
            ni->trans = 255;
    }
}

void manage_tour_one(intro_t *ni, sfRenderWindow *w)
{
    if (ni->tour == 1) {
        sfRenderWindow_clear(w, sfBlack);
        ni->color.a = ni->trans;
        sfSprite_setColor(ni->intro[0], ni->color);
        sfSprite_setScale(ni->intro[0], ni->s);
        sfText_setColor(ni->txt[0].txt, ni->color);
        sfRenderWindow_drawSprite(w, ni->intro[0], NULL);
        sfRenderWindow_drawText(w, ni->txt[0].txt, NULL);
    }
}

void previous_next(intro_t *ni)
{
    ni->next.time = sfClock_getElapsedTime(ni->next.clock);
    ni->next.s = ni->next.time.microseconds / 1000000.0;
    ni->prev.time = sfClock_getElapsedTime(ni->prev.clock);
    ni->prev.s = ni->prev.time.microseconds / 1000000.0;
    if (sfKeyboard_isKeyPressed(sfKeyRight) && ni->tour != 6 &&
    ni->next.s > 0.3) {
        ni->trans = 255;
        ni->tour += 1;
        sfClock_restart(ni->next.clock);
    } else if (sfKeyboard_isKeyPressed(sfKeyLeft) && ni->tour != 1 &&
    ni->prev.s > 0.3) {
        ni->tour -= 1;
        ni->trans = 255;
        sfClock_restart(ni->prev.clock);
    }
}

void game_intro2(sfRenderWindow *w, intro_t ni, txt_t txt, txt_t tx)
{
    ni.tour = 1;
    init_txt_simple(&txt, "assets/fonts/serif.ttf",
    "(Press space to skip intro)");
    ni.color = sfSprite_getColor(ni.intro[0]);
    while (ni.tour != 7) {
        previous_next(&ni);
        ni.s.x += 0.0001;
        ni.s.y += 0.0001;
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            return;
        manage_transparence(&ni);
        manage_tour_one(&ni, w);
        if (change_pic(&ni, w) == 1)
            return;
        sfRenderWindow_drawText(w, txt.txt, NULL);
        sfRenderWindow_drawText(w, tx.txt, NULL);
        sfRenderWindow_display(w);
    }
}