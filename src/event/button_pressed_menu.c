/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** button_pressed_menu
*/

#include "my_rpg.h"

int is_hovered(button_t *b, sfVector2i pm)
{
    if (b->pos.x <= pm.x && b->pos.x + b->size.x >= pm.x
    && b->pos.y <= pm.y && b->pos.y + b->size.y >= pm.y)
        return (1);
    return (0);
}

void hover_button(button_t *button, sfVector2i pm, int continue_game)
{
    if (is_hovered(button, pm) || (button->pressed == button_continue_game &&
    !continue_game)) {
        button->rect.left = button->offset.x;
        sfRectangleShape_setTextureRect(button->obj, button->rect);
    } else {
        button->rect.left = 0;
        sfRectangleShape_setTextureRect(button->obj, button->rect);
    }
}

void button_pressed_menu(data_t *d, sfEvent *event)
{
    sfVector2i pm = sfMouse_getPositionRenderWindow(d->window.w);

    for (int i = 0; i < d->scenes[d->cur].nb_but; i++) {
        hover_button(&d->scenes[d->cur].buttons[i], pm, d->can_continue_game);
        if (event->mouseButton.type == sfEvtMouseButtonReleased &&
        is_hovered(&d->scenes[d->cur].buttons[i], pm)) {
            sfSound_play(d->sfx.sfx[14].sound);
            d->scenes[d->cur].buttons[i].pressed(d);
        }
    }
}