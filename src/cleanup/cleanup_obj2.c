/*
** EPITECH PROJECT, 2019
** cleanup_obj
** File description:
** cleanup_obj
*/

#include "my_rpg.h"

void free_stat(stat_t *stat_obj)
{
    free(stat_obj->name);
    free(stat_obj->describe);
}

void free_item(item_t *item)
{
    free_game_object(&item->item);
    free_stat(&item->stat);
}

void free_spell(spell_t *spell)
{
    free_game_object(&spell->spell);
    free_stat(&spell->stat);
}

void free_bar(bar_t *bar)
{
    free_game_object(&bar->life_bar);
    free_sprite_texture(bar->s_bg, bar->t_bg);
}

void free_inventory(inventory_t *inv)
{
    for (int i = 0; i < inv->nb_items; i++)
        free_item(&inv->items[i]);
}