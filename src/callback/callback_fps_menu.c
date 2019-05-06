/*
** EPITECH PROJECT, 2019
** callback_fps_menu
** File description:
** callback_fps_menu
*/

#include "my_rpg.h"

void button_fps_menu(data_t *data)
{
    data->cur = FPS_SETTING;
}

void button_show_fps(data_t *data)
{
    change_state_checkbox(&data->scenes[FPS_SETTING].buttons[1]);
    data->fps.can_draw_fps = (data->fps.can_draw_fps == TRUE) ? FALSE : TRUE;
}

void uncheck_boxes(data_t *data, int n1, int n2, int n3)
{
    data->scenes[FPS_SETTING].buttons[n1].rect.top = 0;
    data->scenes[FPS_SETTING].buttons[n2].rect.top = 0;
    data->scenes[FPS_SETTING].buttons[n3].rect.top = 0;
    sfRectangleShape_setTextureRect(data->scenes[FPS_SETTING].buttons[n1].obj,
    data->scenes[FPS_SETTING].buttons[n1].rect);
    sfRectangleShape_setTextureRect(data->scenes[FPS_SETTING].buttons[n2].obj,
    data->scenes[FPS_SETTING].buttons[n2].rect);
    sfRectangleShape_setTextureRect(data->scenes[FPS_SETTING].buttons[n3].obj,
    data->scenes[FPS_SETTING].buttons[n3].rect);
}