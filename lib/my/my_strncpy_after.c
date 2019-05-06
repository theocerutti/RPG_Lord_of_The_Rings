/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** Day06 - task02
*/

#include <stdio.h>

char *my_strncpy_after(char *dest, char const *src, int n)
{
    int i = 0;
    int j = 0;
    int len_src = 0;

    for (len_src = 0; src[len_src] != '\0'; len_src++);
    if (n > len_src)
        return (NULL);
    for (i = n, j = 0; src[i] != '\0'; i++, j++) {
        dest[j] = src[i];
    }
    dest[j] = '\0';
    return (dest);
}
