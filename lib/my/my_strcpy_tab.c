/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strcpy_tab
*/

#include <stdio.h>

char *my_strcpy(char *dest, char const *src);

char **my_strcpy_tab(char **dest, char const **src)
{
    int i = 0;

    for (i = 0; src[i] != NULL; i++) {
        dest[i] = my_strcpy(dest[i], src[i]);
    }
    dest[i] = NULL;
    return (dest);
}
