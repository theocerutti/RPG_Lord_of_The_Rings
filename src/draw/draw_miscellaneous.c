/*
** EPITECH PROJECT, 2019
** draw_mis
** File description:
** draw_mis
*/

#include "my_rpg.h"

void draw_loading(sfRenderWindow *w)
{
    sfSprite *s_loading = sfSprite_create();
    sfTexture *t_loading =
    sfTexture_createFromFile("assets/images/menu/loading.png", NULL);

    sfSprite_setTexture(s_loading, t_loading, sfTrue);
    sfRenderWindow_drawSprite(w, s_loading, NULL);
    sfRenderWindow_display(w);
}

void draw_cursor(data_t *d)
{
    sfVector2i p = sfMouse_getPositionRenderWindow(d->window.w);
    sfVector2f pos = {p.x, p.y};

    sfSprite_setPosition(d->cursor.s, pos);
    sfRenderWindow_drawSprite(d->window.w, d->cursor.s, NULL);
}

void draw_fps(data_t *d)
{
    float fps = 0;
    float current_time = 0;

    current_time = sfTime_asSeconds(sfClock_restart(d->fps.clock.clock));
    fps = 1.f / current_time;
    sfText_setString(d->fps.txt.txt, my_itoa(fps));
    sfRenderWindow_drawText(d->window.w, d->fps.txt.txt, NULL);
}