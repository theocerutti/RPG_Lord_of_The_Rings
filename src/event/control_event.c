/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void center_text(button_t *button, char *s)
{
    button->txt.pos.x = button->pos.x + button->size.x / 2 - \
    ((float)my_strlen(s) / 4) * sfText_getCharacterSize(button->txt.txt);
}

void change_text(data_t *data, char *s)
{
    center_text(&data->scenes[CONTROL].buttons[data->ctrl.button], s);
    sfText_setPosition(data->scenes[CONTROL].buttons[data->ctrl.button].txt.txt,
    data->scenes[CONTROL].buttons[data->ctrl.button].txt.pos);
    if ((s[0] <= 'z' && s[0] >= 'a') || my_strcmp("SPACE\0", s) == 0 ||
    my_strcmp("TAB\0", s) == 0 || my_strcmp("ENTER\0", s) == 0) {
        sfText_setString(data->scenes[CONTROL].buttons
        [data->ctrl.button].txt.txt, s);
        data->ctrl.check = 0;
    }
}

char *change_key(char *text, sfKeyCode *code, int offset, data_t *data)
{
    char *s = malloc(100);

    s = my_strcpy(text);
    data->ctrl.key[data->ctrl.button] = *code + offset;
    return (s);
}

void control_event(data_t *data, sfKeyCode *code)
{
    char *s = malloc(100);

    switch (data->ctrl.c) {
        case 32:
            s = change_key("SPACE", code, 25, data);
            break;
        case 9:
            s = change_key("TAB", code, 51, data);
            break;
        case 13:
            s = change_key("ENTER", code, 45, data);
            break;
        default:
            s[0] = data->ctrl.c;
            for (int i = 0; s[i] != '\0'; i++, s[i] = '\0');
            data->ctrl.key[data->ctrl.button] = *code - 'a';
    }
    change_text(data, s);
    free(s);
}