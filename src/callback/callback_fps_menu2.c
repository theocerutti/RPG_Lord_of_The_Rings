/*
** EPITECH PROJECT, 2019
** callback_fps_menu
** File description:
** callback_fps_menu
*/

#include "my_rpg.h"

void change_state_checkbox(button_t *button)
{
    button->rect.top = (button->rect.top == 0) ? button->offset.y : 0;
    sfRectangleShape_setTextureRect(button->obj, button->rect);
}

void button_fps_15(data_t *data)
{
    uncheck_boxes(data, 3, 4, 5);
    change_state_checkbox(&data->scenes[FPS_SETTING].buttons[2]);
    sfRenderWindow_setFramerateLimit(data->window.w, 15);
}

void button_fps_30(data_t *data)
{
    uncheck_boxes(data, 2, 4, 5);
    change_state_checkbox(&data->scenes[FPS_SETTING].buttons[3]);
    sfRenderWindow_setFramerateLimit(data->window.w, 30);
}

void button_fps_60(data_t *data)
{
    uncheck_boxes(data, 2, 3, 5);
    change_state_checkbox(&data->scenes[FPS_SETTING].buttons[4]);
    sfRenderWindow_setFramerateLimit(data->window.w, 60);
}

void button_fps_unlimited(data_t *data)
{
    uncheck_boxes(data, 2, 3, 4);
    change_state_checkbox(&data->scenes[FPS_SETTING].buttons[5]);
    sfRenderWindow_setFramerateLimit(data->window.w, 0);
}