/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void open_pause_menu(data_t *d)
{
    if (d->cur == PAUSE) {
        d->cur = d->pre_cur;
        d->pre_cur = PAUSE;
    } else if (d->cur >= LVL_1_F && d->cur <= LVL_3_C) {
        d->pre_cur = d->cur;
        d->cur = PAUSE;
    }
}

void poll_event2(data_t *d, sfEvent *event)
{
    if (d->cur == INVENTORY)
        inventory_event(d);
    if (d->cur == MERCHANT)
        merchant_event(d, event);
    button_pressed_menu(d, event);
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyEscape)
        open_pause_menu(d);
    if (event->type == sfEvtKeyReleased && event->key.code ==
    d->ctrl.key[ATTACK_KEY] && d->cur >= LVL_1_F && d->cur <= LVL_3_C) {
        event_attack_hero(d);
        d->hero.is_attacking = TRUE;
    }
    if (event->type == sfEvtKeyReleased && event->key.code == \
    d->ctrl.key[INVENTORY_KEY] && ((d->cur >= LVL_1_F && \
    d->cur <= LVL_3_C) || d->cur == INVENTORY || d->cur == MERCHANT))
        open_inventory(d);
    if (event->type == sfEvtKeyReleased && event->key.code == sfKeyE &&
    ((d->cur >= LVL_1_F && d->cur <= LVL_3_C) ||
    d->cur == MERCHANT) && can_merch(d) == 1)
        open_merchant(d);
}

void all_event_game(data_t *d)
{
    if (d->cur >= LVL_1_F && d->cur <= LVL_3_C) {
        all_event_hero(d);
        all_event_enemies(d);
        anim_obj(&d->scenes[HUD].objs[5], 0.1);
        anim_obj(&d->scenes[HUD].objs[7], 0.2);
        send_spell_anim(d);
    }
}

void poll_event(data_t *d, sfEvent *event)
{
    inventory_handling(d);
    merchant_handling(d);
    all_event_game(d);
    while (d->trans >= 10 && sfRenderWindow_pollEvent(d->window.w, event)) {
        get_info_enemy_hud(d, event);
        event_spells(d, event);
        if (d->ctrl.check == 1 && event->type == sfEvtTextEntered) {
            d->ctrl.c = event->text.unicode;
            control_event(d, &event->key.code);
        }
        poll_event2(d, event);
    }
}