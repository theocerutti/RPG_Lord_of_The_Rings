/*
** EPITECH PROJECT, 2019
** init_data
** File description:
** init_data
*/

#include "my_rpg.h"

window_t init_window(void)
{
    window_t window;
    sfVideoMode vid = {1920, 1080, 32};
    sfRenderWindow *w = sfRenderWindow_create(vid, "LordOfTheRings", \
    sfFullscreen, NULL);
    sfVector2u size = sfRenderWindow_getSize(w);

    sfRenderWindow_setFramerateLimit(w, 60);
    sfRenderWindow_setMouseCursorVisible(w, sfFalse);
    window.w = w;
    window.size.x = size.x;
    window.size.y = size.y;
    return (window);
}

void init_all_data(data_t *data)
{
    data->window = init_window();
    draw_loading(data->window.w);
    data->cur = MENU;
    data->pre_cur = MENU;
    data->item_ref = get_items_ref();
    data->merch = get_merch(data);
    data->can_continue_game = FALSE;
    init_hero_data(data);
    init_control(data);
    init_spells_overview(data);
    set_spells(data);
    init_all_sfx(&data->sfx);
    init_all_scenes(data);
    init_miscellaneous(data);
    init_block_map(data);
    init_all_bosses(data);
    data->trans = 0;
}