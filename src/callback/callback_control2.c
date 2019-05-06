/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** callback_control
*/

#include "my_rpg.h"

void callback_control_b_up(data_t *data)
{
    sfText_setString(data->scenes[CONTROL].buttons[0].txt.txt, "");
    data->ctrl.check = 1;
    data->ctrl.button = UP_KEY;
}