/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** callback_control
*/

#include "my_rpg.h"

void callback_control_b_down(data_t *data)
{
    sfText_setString(data->scenes[CONTROL].buttons[1].txt.txt, "");
    data->ctrl.check = 1;
    data->ctrl.button = DOWN_KEY;
}

void callback_control_b_right(data_t *data)
{
    sfText_setString(data->scenes[CONTROL].buttons[2].txt.txt, "");
    data->ctrl.check = 1;
    data->ctrl.button = RIGHT_KEY;
}

void callback_control_b_left(data_t *data)
{
    sfText_setString(data->scenes[CONTROL].buttons[3].txt.txt, "");
    data->ctrl.check = 1;
    data->ctrl.button = LEFT_KEY;
}

void callback_control_b_attack(data_t *data)
{
    sfText_setString(data->scenes[CONTROL].buttons[4].txt.txt, "");
    data->ctrl.check = 1;
    data->ctrl.button = ATTACK_KEY;
}

void callback_control_b_inventory(data_t *data)
{
    sfText_setString(data->scenes[CONTROL].buttons[5].txt.txt, "");
    data->ctrl.check = 1;
    data->ctrl.button = INVENTORY_KEY;
}
