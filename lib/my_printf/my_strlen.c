/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}
