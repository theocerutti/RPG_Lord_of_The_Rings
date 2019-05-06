/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** Day06 - task01
*/

#include <stdlib.h>
#include <stdio.h>

char *my_strcpy(char *src)
{
    char *new = NULL;
    int len = 0;
    int i = 0;

    for (len = 0; src[len] != '\0'; len++);
    new = malloc(len + 1);
    for (; i < len; i++) {
        new[i] = src[i];
    }
    new[i] = '\0';
    return (new);
}
