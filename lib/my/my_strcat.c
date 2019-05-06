/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char const *dest, char const *src)
{
    int i = 0;
    char *new = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (i = 0; dest[i] != '\0'; i++)
        new[i] = dest[i];
    for (int j = 0; src[j] != '\0'; j++, i++)
        new[i] = src[j];
    new[i] = '\0';
    return (new);
}