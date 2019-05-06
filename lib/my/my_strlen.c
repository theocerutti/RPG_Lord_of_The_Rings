/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** task03
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}
